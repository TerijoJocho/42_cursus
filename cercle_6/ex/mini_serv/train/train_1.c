#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

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

typedef struct  s_client
{
    int     id;
    char    *msg;
}   t_client;

void    putstr(int fd, char* str)
{
    if (str)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            write(fd, &str[i], 1);
            i++;
        }
    }
}

void    print_error(char* str)
{
    putstr(2, str);
    exit(1);
}

void    send_broadcast(int send_fd, int maxfd, fd_set* write_set, const char* send_buffer)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, write_set) && fd != send_fd)
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
                print_error("Fatal error\n");
    }
}

int main(int argc, char** argv) 
{
    /*--------on rajoute------*/
    if (argc != 2)
        print_error("Wrong number of arguments\n");
    /*------------------------*/

	int sockfd, connfd;
	struct sockaddr_in servaddr; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
        print_error("Fatal error\n");
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        print_error("Fatal error\n");

	if (listen(sockfd, 10) != 0)
        print_error("Fatal error\n");

    /*--------on rajoute------*/
    //taille max des msg
    int max_msg_size = 1000000;
    //maximum de clients
    int max_clients = 1024;
    //tableau de clients
    t_client    clients[max_clients];
    for (int i = 0; i < max_clients; i++)
        clients[i].id = -1;
    //id des clients
    int current_id = 0;
    //nb max de fd
    int maxfd = 0;
    //set de fd
    fd_set  read_set;
    fd_set  write_set;
    fd_set  current_set;
    //buffer d'envoie
    char    send_buffer[max_msg_size];
    //buffer de lecture
    char    recv_buffer[max_msg_size];

    //on nettoie le current_set
    FD_ZERO(&current_set);
    //on ajoute sockfd au current_set
    FD_SET(sockfd, &current_set);
    //on maj le nb de fd max
    maxfd = sockfd;

    //boucle true
    while (1)
    {
        //on maj tout les set avant qu'ils soient modif par select
        read_set = write_set = current_set;
        //on utilise select pour voir si un fd est ready a etre read ou write
        if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
            print_error("Fatal error\n");
        //on boucle sur tout les fd
        for (int fd = 0; fd <= maxfd; fd++)
        {
            //si on peut lire qqchose sur le fd
            if (FD_ISSET(fd, &read_set))
            {
                //cas où un cli se connect
                if (fd == sockfd)
                {
	                //on creer une addr pour le nouveau cli
                    struct sockaddr_in cli; 
                    //on l'initialise
                    bzero(&cli, sizeof(cli));
                    //on copie la ligne len (on ajoute le type) et accept ici
	                socklen_t   len = sizeof(cli);
                    connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	                if (connfd < 0)
                        print_error("Fatal error\n");
                    // si le fd retourné est plus grand que maxfd alors on maj
                    if (connfd > maxfd)
                        maxfd = connfd;
                    //on donne un id a ce cli
                    clients[connfd].id = current_id;
                    //on maj l'id pour le prochain cli
                    current_id++;
                    //on initialise le msg du cli
                    clients[connfd].msg = NULL;
                    //on ajoute le fd du cli aux set current et write
                    FD_SET(connfd, &write_set);
                    FD_SET(connfd, &current_set);
                    //on creer le message de bienvenu
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[connfd].id);
                    //on broadcast
                    send_broadcast(connfd, maxfd, &write_set, send_buffer);
                }
                //in cli a qqchose à dire
                else
                {
                    //on recupère ce que le cli a ecrit
                    int ret = recv(fd, recv_buffer, max_msg_size, 0);
                    //si il y a une erreur ou le client s'est deco
                    if (ret <= 0)
                    {
                        //on construit le msg
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        //on envoie a tout les autres cli
                        send_broadcast(fd, maxfd, &write_set, send_buffer);
                        //si le cli avait un msg on free
                        if (clients[fd].msg)
                            free(clients[fd].msg);
                        clients[fd].id = -1;
                        //on retire ce fd (cli) du set current
                        FD_CLR(fd, &current_set);
                        //et on ferme le fd
                        close(fd);
                    }
                    //le cli a envoyé un message
                    else
                    {
                        //si ret atteint la limite alors on -1 pour ecire le nullbyte
                        if (ret >= max_msg_size)
                            ret = max_msg_size - 1;
                        //on nullbyte le msg
                        recv_buffer[ret] = '\0';
                        //on join ce qu'il y avait deja dans le buffer du cli
                        clients[fd].msg = str_join(clients[fd].msg, recv_buffer);
                        if (clients[fd].msg == NULL)
                            print_error("Fatal error\n");
                        //le message extracted
                        char    *extract_msg;
                        //le resultat de le fonction
                        int     extract_ret;
                        //boucle pour extraire le message du cli jusqu'à '\n'
                        while ((extract_ret = extract_message(&(clients[fd].msg), &extract_msg)) == 1)
                        {
                            //on creer le msg
                            sprintf(send_buffer, "client %d: %s", clients[fd].id, extract_msg);
                            //on broadcast
                            send_broadcast(fd, maxfd, &write_set, send_buffer);
                            //on free le extract_msg
                            free(extract_msg);
                        }
                        //derniere verif, si on a eu une erreur dans extract_message
                        if (extract_ret == -1)
                            print_error("Fatal error\n");
                    }
                }
            }
        }
    }
    return (0);
}
