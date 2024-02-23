/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:25:51 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 16:51:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBASM_H
#define LIBASM_H

#include <sys/types.h>

size_t ft_strlen(const char *s);
size_t ft_strlen2(const char *s);
char *ft_strcpy(char *restrict dst, const char *restrict src);
char *ft_strcpy2(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
int ft_strcmp2(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

#endif /* LIBASM_H */
