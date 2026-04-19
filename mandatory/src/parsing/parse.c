/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:13:18 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 21:33:08 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static bool		validate_tokens(t_data *data, char **tokens);
static t_list	*read_file_to_list(int fd);
static char		**get_text(char *address);
static char		**list_to_array(t_list *lst);

/*
* Parsing logic launcher. By reading the right file type, the function
* checks the format and returns true or false acordingly.
* The errors messages are all managed on Failure.*/
bool	parse(t_data *data, char *doc)
{
	char	**lines;
	char	**tokens;
	int		i;

	i = 0;
	tokens = NULL;
	if (!check_valid_file_type(doc))
		return (printf("Error\nWrong file\n"), false);
	lines = get_text(doc);
	if (!lines)
		return (false);
	if (!check_acl(lines))
		return (free_split(lines),
			printf("Error\nWrong A, C, or L count\n"),
			false);
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

/*
* Helper to run each format checker according to token
* specificator the found in the document line.*/
static bool	validate_tokens(t_data *data, char **tokens)
{
	if (*tokens == NULL)
		return (true);
	if (!ft_strncmp("A", tokens[0], 2))
		return (parse_ambient_light(data, tokens));
	else if (!ft_strncmp("C", tokens[0], 2))
		return (parse_camera(data, tokens));
	else if (!ft_strncmp("L", tokens[0], 2))
		return (parse_light(data, tokens));
	else if (!ft_strncmp("sp", tokens[0], 3))
		return (parse_sphere(data, tokens));
	else if (!ft_strncmp("pl", tokens[0], 3))
		return (parse_plane(data, tokens));
	else if (!ft_strncmp("cy", tokens[0], 3))
		return (parse_cylinder(data, tokens));
	else if (!ft_strncmp("\n", tokens[0], 2))
		return (true);
	return (set_err_num(data, ERR_INVALID_ID), false);
}

/*
* Opens the file, reads it into a list, converts it to a 2D array,
* and trims the newlines. Handles empty files naturally. */
static char	**get_text(char *address)
{
	int		fd;
	t_list	*lst;
	char	**arr;

	fd = open(address, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nNot valid doc address\n"), NULL);
	lst = read_file_to_list(fd);
	close(fd);
	if (!lst)
		return (printf("Error\nEmpty or wrong format doc\n"), NULL);
	arr = list_to_array(lst);
	if (arr)
		trim_newlines(arr);
	return (arr);
}

/*
* Reads the file line by line using GNL and stores
* each line in a linked list. */
static t_list	*read_file_to_list(int fd)
{
	t_list	*lst;
	char	*line;

	lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n' || line[0] == '#')
		{
			free(line);
			continue ;
		}
		ft_lstadd_back(&lst, ft_lstnew(line));
	}
	return (lst);
}

/*
* Allocates the exact array size based on list length.
* Then we copy the contetn of each node and then we free the list.*/
static char	**list_to_array(t_list *lst)
{
	char	**arr;
	int		i;
	t_list	*tmp;

	arr = ft_calloc(sizeof(char *), ft_lstsize(lst) + 1);
	if (!arr)
		return (ft_lstclear(&lst, free), printf("Error\nMalloc\n"), NULL);
	i = 0;
	while (lst)
	{
		arr[i++] = (char *)lst->content;
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (arr);
}
