/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:37:27 by danz              #+#    #+#             */
/*   Updated: 2025/10/05 14:02:41 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strjoin2(char *str1, char *str2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif