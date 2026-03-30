/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:13:18 by rick              #+#    #+#             */
/*   Updated: 2026/03/30 21:15:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static int	get_size(char *adress);
static bool	validate_tokens(t_data *data, char **tokens);

bool	parse(t_data *data, char *doc)
{
	char	**lines;
	char	**tokens;
	int		i;

	i = 0;
	tokens = NULL;
	lines = get_text(doc);
	if (!lines)
		return (false);
	while (lines && lines[i])
	{
		tokens = ft_split(lines[i], ' ');
		if (!validate_tokens(data, tokens))
			return (free_split(tokens), free_split(lines), false);
		free_split(tokens);
		i++;
	}
	free_split(lines);
	return (true);
}

static bool	validate_tokens(t_data *data, char **tokens)
{
	if (!ft_strncmp("A", tokens[0], 2))
		return (printf("ambiant light\n"), parse_ambient_light(data, tokens));
	else if (!ft_strncmp("C", tokens[0], 2))
		return (printf("camera\n"), parse_camera(data, tokens));
	else if (!ft_strncmp("L", tokens[0], 2))
		return (printf("light\n"), parse_light(data, tokens));
	else if (!ft_strncmp("pl", tokens[0], 3))
		return (printf("Success: sp\n"), true);
	else if (!ft_strncmp("sp", tokens[0], 3))
		return (printf("Success: cl\n"), true);
	else if (!ft_strncmp("cy", tokens[0], 3))
		return (printf("Success: cy\n"), true);
	else if (!ft_strncmp("\n", tokens[0], 2))
		return (true);
	return (perror("Wrong data format"), false);
}

/*
Function to save the text of the document in an array of strings.*/
char	**get_text(char *address)
{
	int		fd;
	int		size;
	char	**arr;
	int		i;

	i = 0;
	size = 0;
	fd = 0;
	size = get_size(address);
	if (size == 0)
		return (NULL);
	arr = ft_calloc(sizeof(char *), size + 1);
	if (!arr)
		return (perror("Malloc"), NULL);
	fd = open(address, O_RDONLY);
	if (fd < 0)
		return (perror("Not valid doc address"), NULL);
	while (i < size - 1)
	{
		arr[i] = get_next_line(fd);
		if (!arr[i])
			return (perror("GNL Err"), NULL);
		printf("%s\n", arr[i]);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	printf("here ok \n");
	return (arr);
}

/*
Function to get the amount of lines in the document.
Opens the documents and reads byte by byte checking
for new lines incrementing the size value.
If size is 0 at the end of read iteration the file is empty
and the error is printed.
Finally it closes the file and returns the value of size.*/
static int	get_size(char *adress)
{
	int		fd;
	char	c;
	int		size;
	int		ret;

	size = 1;
	c = '\0';
	fd = open(adress, O_RDONLY);
	if (fd < 0)
		return (perror("Not valid doc address"), 0);
	ret = read(fd, &c, 1);
	if (ret <= 0)
		return (perror("Wrong format doc."), 0) ;
	while (ret > 0)
	{
		if (c == '\n')
			size++;
		ret = read(fd, &c, 1);
	}
	close(fd);
	return (size);
}
