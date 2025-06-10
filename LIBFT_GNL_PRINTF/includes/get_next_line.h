/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:22:02 by tsemenov          #+#    #+#             */
/*   Updated: 2025/01/03 16:22:03 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_to_line(int fd, char *buffer, char *line);
char	*update_str(char *line);
//utils:
size_t	ft_strlen_t(const char *str);
void	clean_after_gnl(void);
void	free_null(char **str);
//char	*clean_return(char *left_str);
//char	*ft_strjoin(const char *s1, const char *s2);
//char	*ft_strdup(const char *s1);
//char	*ft_strchr(const char *s, int c);s
//char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
