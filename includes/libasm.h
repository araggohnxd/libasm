/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:25:51 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/19 14:35:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBASM_H
#define LIBASM_H

#include <stddef.h>

size_t ft_strlen(const char *s);
size_t ft_strlen2(const char *s);
char *ft_strcpy(char *restrict dst, const char *restrict src);
char *ft_strcpy2(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);

#endif /* LIBASM_H */
