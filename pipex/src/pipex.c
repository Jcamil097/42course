/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:16:45 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/10 14:05:29 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
	inicializa la estructura
*/
static void	init_cmd(t_cmd *c, int f)
{
	c->f = f;
	c->path = 0;
	c->cmd = 0;
	c->args[0] = 0;
}

/*
	libera las estructuras
*/
static void	free_all(t_cmd *c, t_cmd *d)
{
	free_struct(c);
	free_struct(d);
}

/*
Este código define una función get_path que devuelve una matriz de cadenas que representa el valor de la variable de entorno PATH.
El argumento ep es un puntero a una matriz de cadenas que contiene todas las variables de entorno.
La función busca la cadena "PATH=" dentro de ep utilizando ft_strncmp para comparar los primeros caracteres de cada cadena y determinar si son iguales. Si se encuentra la cadena "PATH=", la función extrae el valor de la variable de entorno utilizando ft_substr. El valor de la variable de entorno es una cadena que contiene una lista de rutas de búsqueda separadas por dos puntos (:).
La función utiliza ft_splitpath para dividir la cadena en una matriz de cadenas, utilizando los dos puntos como delimitador. Si la división tiene éxito, la función devuelve la matriz de cadenas ret.
Si ocurre algún error durante el proceso de extracción de la variable de entorno o la división de la cadena, se libera cualquier memoria asignada dinámicamente y la función devuelve NULL.
*/
static char **get_path(char **ep)
{
    char **ret;
    char *env;
    int i;

    i = -1;
    while (ep[++i]) // Recorre todas las cadenas en la matriz de cadenas de entorno
    {
        if (!ft_strncmp(ep[i], "PATH=", PATH)) // Busca la cadena que empieza con "PATH="
        {
            // Extrae el valor de la variable de entorno
            env = ft_substr(ep[i], START, ft_strlen(ep[i]));
            if (!env)
                return (NULL); // Si la extracción falla, devuelve NULL
            // Divide la cadena en una matriz de cadenas usando ':' como delimitador
            ret = ft_splitpath(env, ':');
            if (!ret)
            {
                free(env);
                return (NULL);
            }
            free(env);
            return (ret); // Devuelve la matriz de cadenas si la división es exitosa
        }
    }
    return (NULL); // Devuelve NULL si no se encuentra la variable de entorno "PATH"
}

/*
    *Primero, se inicializan las variables i y tmp. i se inicializa en -1 porque la primera entrada en la matriz tmp será el comando, no un argumento.
    *Se llama a get_path(ep) para obtener la ruta del directorio de búsqueda para el comando. Si esta llamada devuelve NULL, la función retorna 0.
    *Se llama a ft_splitpath(cmd, ' ') para separar la cadena del comando y sus argumentos en una matriz de cadenas utilizando el espacio en blanco como delimitador. Si esta llamada devuelve NULL, la función retorna 0.
    *Se utiliza ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]) - 1) para obtener el comando principal (la segunda entrada en la matriz tmp) y asignarlo a la estructura de comando c->cmd. Si esta llamada devuelve NULL, la función libera la memoria asignada a la matriz tmp y retorna 0.
    *A continuación, se recorre la matriz tmp y se utiliza ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1) para obtener cada argumento y asignarlo a la estructura de comando c->args[i]. Si esta llamada devuelve NULL, la función libera la memoria asignada a la matriz c->args y la matriz tmp, y retorna 0.
    *Se asigna un puntero nulo a c->args[i] para marcar el final de la lista de argumentos.
    *Finalmente, se libera la memoria asignada a tmp y se retorna 1 para indicar que la función se ejecutó correctamente.
*/
static int get_cmd(char **ep, t_cmd *c, char *cmd)
{
    int     i;
    char    **tmp;

    i = -1;   
    // Obtener la ruta del directorio de búsqueda para el comando
    c->path = get_path(ep);
    if (!c->path)
        return (0);  
    // Separar la cadena de comando y sus argumentos en una matriz de cadenas
    tmp = ft_splitpath(cmd, ' ');
    if (!tmp)
        return (0);   
    // Obtener el comando principal de la matriz y asignarlo a la estructura de comando
    c->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]) - 1);
    if (!c->cmd)
        return (free_arr(tmp));   
    // Obtener los argumentos restantes de la matriz y asignarlos a la estructura de comando
    while (tmp[++i])
    {
        c->args[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1);
        if (!c->args[i])
        {
            free_arr(c->args);
            return (free_arr(tmp));
        }
    }
    c->args[i] = 0;
    // Liberar la memoria asignada a la matriz temporal
    free_arr(tmp);
    return (1);
}

void	pipex(int f1, int f2, char **ag, char **envp)
{
	// Inicializar dos estructuras de comando con sus respectivos descriptores de archivo
	t_cmd	cmd1;
	t_cmd	cmd2;
	init_cmd(&cmd1, f1);
	init_cmd(&cmd2, f2);
	
	// Comprobar si los comandos dados son válidos y llenar los miembros correspondientes de sus estructuras
	if (!get_cmd(envp, &cmd1, ag[2]) || !get_cmd(envp, &cmd2, ag[3]))
		return (free_all(&cmd1, &cmd2)); // Si no son válidos, liberar la memoria y salir de la función
	if (!check_cmd(&cmd1) || !check_cmd(&cmd2))
		return (free_all(&cmd1, &cmd2)); // Si no pasan la validación, liberar la memoria y salir de la función
	
	// Ejecutar los comandos y redirigir la entrada y salida estándar entre ellos
	exec_cmd(&cmd1, &cmd2, envp);
	
	// Liberar la memoria asignada a las estructuras de comando
	free_struct(&cmd1);
	free_struct(&cmd2);
}