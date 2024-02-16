/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:25:51 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/15 19:41:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBASM_H
#define LIBASM_H

#include <stddef.h>
#include <string.h>

size_t ft_strlen(const char *s);
size_t ft_strlen2(const char *s);
char *ft_strcpy(char *restrict dst, const char *restrict src);
char *ft_strcpy2(char *restrict dst, const char *restrict src);

#endif /* LIBASM_H */
