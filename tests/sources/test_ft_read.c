/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:50:35 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/27 16:35:02 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

int sys_read_errno;
int ft_read_errno;

void test_ft_read_against_read1(void) {
  int fd_sys, fd_ft;
  ssize_t ret_sys, ret_ft;
  char buf_sys[32] = {}, buf_ft[32] = {};

  fd_sys = open(READ_IN, O_RDONLY);
  ret_sys = read(fd_sys, buf_sys, 16);
  close(fd_sys);

  fd_ft = open(READ_IN, O_RDONLY);
  ret_ft = ft_read(fd_ft, buf_ft, 16);
  close(fd_ft);

  TEST_ASSERT_EQUAL_INT(ret_sys, ret_ft);
  TEST_ASSERT_EQUAL_STRING(buf_sys, buf_ft);
  TEST_ASSERT_EQUAL_STRING("Lorem ipsum dolo", buf_ft);
}

void test_ft_read_against_read2(void) {
  int fd_sys, fd_ft;
  ssize_t ret_sys, ret_ft;
  char buf_sys[32] = {}, buf_ft[32] = {};

  fd_sys = open(READ_IN, O_RDONLY);
  ret_sys = read(fd_sys, buf_sys, 0);
  close(fd_sys);

  fd_ft = open(READ_IN, O_RDONLY);
  ret_ft = ft_read(fd_ft, buf_ft, 0);
  close(fd_ft);

  TEST_ASSERT_EQUAL_INT(ret_sys, ret_ft);
  TEST_ASSERT_EQUAL_STRING(buf_sys, buf_ft);
  TEST_ASSERT_EQUAL_STRING("", buf_ft);
}

void test_ft_read_errno_value(void) {
  char buffer[16];

  TEST_ASSERT_EQUAL_INT(-1, ft_read(-1, buffer, 1));
  TEST_ASSERT_EQUAL_INT(EBADF, errno);
}

void test_ft_read(void) {
  RUN_TEST(test_ft_read_against_read1);
  RUN_TEST(test_ft_read_against_read2);
  RUN_TEST(test_ft_read_errno_value);
}
