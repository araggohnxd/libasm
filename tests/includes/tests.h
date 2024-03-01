/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:33:30 by maolivei          #+#    #+#             */
/*   Updated: 2024/03/01 14:10:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TESTS_H
#define TESTS_H

#include "libasm.h"
#include "unity.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SYS_WRITE_OUT "sys_write.output"
#define FT_WRITE_OUT "ft_write.output"
#define READ_IN "./data/read.txt"

void test_ft_strlen(void);
void test_ft_strlen2(void);
void test_ft_strcpy(void);
void test_ft_strcpy2(void);
void test_ft_strcmp(void);
void test_ft_strcmp2(void);
void test_ft_write(void);
void test_ft_read(void);
void test_ft_strdup(void);

void test_ft_list_push_front(void);
void test_ft_list_size(void);
void test_ft_list_remove_if(void);

char *read_whole_file(const char *filename);

#endif /* TESTS_H */
