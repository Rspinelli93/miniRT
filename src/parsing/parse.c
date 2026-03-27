/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:13:18 by rick              #+#    #+#             */
/*   Updated: 2026/03/27 21:26:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/* bool	parse(t_data *data, char **doc)
{
	
} */
int	get_size(char *adress);

/*
Function to save the text of the document in an array of strings.*/
char	**get_text(char *address)
{
	int		fd;
	int		size;
	char	**arr;
	int		i;

	i = 0;
	size = get_size(address);
	if (size == 0)
		return (perror("File not valid\n"), NULL);
	arr = ft_calloc(sizeof(char *), size + 1);
	if (!arr)
		return (perror("Malloc"), NULL);
	fd = open(address, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i <= size)
		arr[i++] = get_next_line(fd);
	arr[i] = NULL;
	return (arr);
}

/*
Function to get the amount of lines in the document.
Opens the documents and reads byte by byte checking 
for new lines incrementing the size value.
If size is 0 at the end of read iteration the file is empty
and the error is printed.
Finally it closes the file and returns the value of size.*/
int	get_size(char *adress)
{
	int		fd;
	char	c;
	int		size;

	size = 0;
	c = '\0';
	fd = open(adress, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			size++;
	}
	close(fd);
	return (size);
}
