#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

/*-------------------------------DONNÉ-----------------------------*/
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}
/*-----------------------------------------------------------------*/

typedef struct s_client
{
	int		id;
	char*	msg;
}t_client;

void putstr(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void err(char *msg)
{
	putstr(2, msg);
	exit(1);
}

void	send_broadcast(int send_fd, int maxfd, fd_set* write_set, const char* send_buffer)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, write_set) && fd != send_fd)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err("Fatal error\n");
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		err("Wrong number of arguments\n");

	int	max_msg_size = 1000000;
	int	max_clients = 1024;

	t_client clients[max_clients];

	int current_id = 0;
	int maxfd = 0;

	fd_set read_set;
	fd_set write_set;
	fd_set current;

	char	send_buffer[max_msg_size];
	char	recv_buffer[max_msg_size];

	int sockfd, connfd;//donné mais on retire len
	struct sockaddr_in servaddr; //donné mais on retire cli

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //donné
	if (sockfd == -1)
		err("Fatal error\n");
	bzero(&servaddr, sizeof(servaddr)); //donné

	FD_ZERO(&current); /*ici on nettoie le set current*/
	FD_SET(sockfd, &current); /*ici on ajoute sockfd au set current*/
	maxfd = sockfd;
	
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; //donné
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 //donné
	servaddr.sin_port = htons(atoi(av[1])); //donné mais sans le atoi(av[1])
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)//donné
		err("Fatal error\n");

	if (listen(sockfd, 10) != 0)//donné
		err("Fatal error\n");

	while (1)
	{
		read_set = write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
			err("Fatal error\n");
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				/*un client se connecte*/
				if (fd == sockfd)
				{
					struct sockaddr_in cli;
					bzero(&cli, sizeof(cli));
					socklen_t len = sizeof(cli);//donné sans le type
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);//donné
					if (connfd < 0)
						err("Fatal error\n");
					if (connfd > maxfd)
						maxfd = connfd;
					clients[connfd].id = current_id;
					current_id++;
					clients[connfd].msg = NULL;
					FD_SET(connfd, &current);
					FD_SET(connfd, &write_set);
					sprintf(send_buffer, "server: client %d just arrived\n", clients[connfd].id);
					send_broadcast(connfd, maxfd, &write_set, send_buffer);
				}
				/*un client a qqchose à dire*/
				else
				{
					int ret = recv(fd, recv_buffer, max_msg_size, 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_broadcast(fd, maxfd, &write_set, send_buffer);
						if (clients[fd].msg)
							free(clients[fd].msg);
						FD_CLR(fd, &current);
						close(fd);
					}
					else
					{
						if (ret >= max_msg_size)
							ret = max_msg_size - 1;
						recv_buffer[ret] = '\0';
						clients[fd].msg = str_join(clients[fd].msg, recv_buffer);
						if (clients[fd].msg == NULL)
							err("Fatal error\n");
						char	*msg;
						int		extract_ret;
						while ((extract_ret = extract_message(&(clients[fd].msg), &msg)) == 1)
						{
							sprintf(send_buffer, "client %d: %s", clients[fd].id, msg);
							send_broadcast(fd, maxfd, &write_set, send_buffer);
							free(msg);
						}
						if (extract_ret == -1)
							err("Fatal error\n");
					}
				}
			}
		
		}
	}
	
}