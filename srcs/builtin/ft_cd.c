/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:02:24 by ahocine           #+#    #+#             */
/*   Updated: 2022/07/24 16:11:09 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

void	ft_add_new_env(char *new_name, char *new_value)
{
	t_env	**env;
	t_env	*tmp;

	env = ft_get_env();
	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env_name, new_name, ft_strlen(tmp->env_name)))
			return (tmp->value = new_value, (void)1);
		tmp = tmp->next;
	}
}

void	ft_cd(t_lexer *lexer)
{
	char	*path;
	char	*str;

	str = lexer->cmd;
	if (!str || *str == '~')
	{
		// set HOME. If not home, print error (HOME NOT SET);
	}
	path = (char *)getcwd(NULL, 1000);
	printf("str = %s\n", str);
	if (!path || !ft_add_trash((void *)path))
		return (ft_empty_trash());
	ft_strlcat(path, "/", 1000);
	ft_strlcat(path, str, 1000);
	printf("path = %s\n", path);
	ft_add_new_env("OLDPWD", path);
	if (chdir(path) == -1)
		return (ft_putstr_fd("Folder does not exist.\n", _STD_ERR), (void)0);
	path = getcwd(NULL, 0);
	if (!path || !ft_add_trash((void *)path))
		return (ft_empty_trash());
	ft_add_new_env("PWD", path);
}
