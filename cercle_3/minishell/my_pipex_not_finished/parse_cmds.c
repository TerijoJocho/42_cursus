#include "pipex.h"

char	*get_path(t_pipex *data, char **argv, char **envp)
{
	int	i;
	char	*path_envp;

	i = 0;
	path_envp = NULL;
	(void)data;
	(void)argv;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_envp = envp[i] + 5;
		}
		i++;
	}
	if (path_envp == NULL)
	{
		perror("PATH not found in environment");
		exit(EXIT_FAILURE);
	}
	return (path_envp);
}

void	ft_parse_cmds(t_pipex *data, char **argv, char **envp)
{
	char	*path_envp;
	char	**path_dir;

	path_envp = get_path(data, argv, envp);
	path_dir = ft_split(path_envp, ':');
	data->cmd_paths = path_dir;
	if (!data->cmd_paths)
	{
		//free_cmd_paths(data->cmd_paths);
		perror("Malloc cmd_paths");
		exit(EXIT_FAILURE);
	}
	/*VERIF------------*/
	int k;
	k = 0;
	while (data->cmd_paths[k])
	{
		ft_printf("cmd_path[%d]= %s\n", k, data->cmd_paths[k]);
		k++;
	}
	/*-----------------*/
}

// /*CHATGPT------------------------------------------------*/
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include "pipex.h" // Ajoutez les définitions des structs ici

// // Fonction qui concatène un répertoire et un nom de commande pour créer un chemin complet
// static char	*ft_join_path(char *dir, char *cmd)
// {
// 	char	*temp;
// 	char	*full_path;

// 	temp = ft_strjoin(dir, "/");
// 	if (!temp)
// 		return (NULL);
// 	full_path = ft_strjoin(temp, cmd);
// 	free(temp);
// 	return (full_path);
// }

// // Fonction principale pour récupérer les chemins complets des commandes
// void	ft_parse_cmds(t_pipex *data, char **argv, char **envp)
// {
// 	int		i;
// 	int		j;
// 	char	**path_dirs;

// 	// Trouver et découper la variable PATH de l'environnement
// 	char *path_env = NULL;
// 	for (i = 0; envp[i]; i++)
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 			path_env = envp[i] + 5; // Obtenir tout après "PATH="

// 	if (!path_env)
// 	{
// 		perror("PATH not found in environment");
// 		exit(EXIT_FAILURE);
// 	}
// 	path_dirs = ft_split(path_env, ':'); // Découper les chemins dans PATH

// 	// Allouer de la mémoire pour les cmd_paths
// 	data->cmd_paths = malloc(sizeof(char *) * (data->cmd_count));
// 	if (!data->cmd_paths)
// 	{
// 		perror("Malloc cmd_paths");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Récupérer les chemins complets pour chaque commande
// 	j = 0;
// 	i = (data->here_doc == 0) ? 2 : 3; // Sauter infile et here_doc si nécessaire
// 	while (j < data->cmd_count - 1)
// 	{
// 		int	found = 0;
// 		for (int k = 0; path_dirs[k]; k++)
// 		{
// 			char *full_path = ft_join_path(path_dirs[k], argv[i]);
// 			if (access(full_path, X_OK) == 0) // Si le chemin est exécutable
// 			{
// 				data->cmd_paths[j] = full_path;
// 				found = 1;
// 				break;
// 			}
// 			free(full_path);
// 		}
// 		if (!found)
// 		{
// 			ft_printf("Command not found: %s\n", argv[i]);
// 			data->cmd_paths[j] = NULL; // Si aucun chemin n'est trouvé
// 		}
// 		i++;
// 		j++;
// 	}
// 	data->cmd_paths[j] = NULL; // Terminer le tableau par NULL

// 	// Libérer les chemins de PATH
// 	for (i = 0; path_dirs[i]; i++)
// 		free(path_dirs[i]);
// 	free(path_dirs);
// }
/*-----------------------------------------------*/
