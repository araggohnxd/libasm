/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:33:30 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 19:09:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TESTS_H
#define TESTS_H

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libasm.h"
#include "unity.h"

#define SYS_WRITE_OUT "sys_write.output"
#define FT_WRITE_OUT "ft_write.output"

void test_ft_strlen(void);
void test_ft_strlen2(void);
void test_ft_strcpy(void);
void test_ft_strcpy2(void);
void test_ft_strcmp(void);
void test_ft_strcmp2(void);
void test_ft_write(void);

char *read_whole_file(const char *filename);

#endif /* TESTS_H */
