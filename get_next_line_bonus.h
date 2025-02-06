/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:17:26 by tmarcos           #+#    #+#             */
/*   Updated: 2025/01/24 13:55:37 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char *str, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
int		ft_find_newline(const char *str);
char	*ft_extract_line(char *keep);
char	*ft_update_keep(char *keep);
char	*ft_read_file(int fd, char *keep);
char	*get_next_line(int fd);

#endif
