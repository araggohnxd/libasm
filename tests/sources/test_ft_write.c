/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:56 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 20:25:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

const char str[] = "hello, world!";
size_t len = sizeof(str) - 1;

void test_ft_write_against_write1(void) {
  int fd_sys, fd_ft;
  ssize_t ret_sys, ret_ft;
  char *buf_sys, *buf_ft;

  fd_sys = open(SYS_WRITE_OUT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  ret_sys = write(fd_sys, str, len);
  buf_sys = read_whole_file(SYS_WRITE_OUT);
  close(fd_sys);

  fd_ft = open(FT_WRITE_OUT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  ret_ft = ft_write(fd_ft, str, len);
  buf_ft = read_whole_file(FT_WRITE_OUT);
  close(fd_ft);

  TEST_ASSERT_EQUAL_INT(ret_sys, ret_ft);
  TEST_ASSERT_EQUAL_STRING(buf_sys, buf_ft);

  free(buf_sys);
  free(buf_ft);
}

void test_ft_write_against_write2(void) {
  int fd_sys, fd_ft;
  ssize_t ret_sys, ret_ft;
  char *buf_sys, *buf_ft;

  fd_sys = open(SYS_WRITE_OUT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  ret_sys = write(fd_sys, str, (len / 2));
  buf_sys = read_whole_file(SYS_WRITE_OUT);
  close(fd_sys);

  fd_ft = open(FT_WRITE_OUT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  ret_ft = ft_write(fd_ft, str, (len / 2));
  buf_ft = read_whole_file(FT_WRITE_OUT);
  close(fd_ft);

  TEST_ASSERT_EQUAL_INT(ret_sys, ret_ft);
  TEST_ASSERT_EQUAL_STRING(buf_sys, buf_ft);

  free(buf_sys);
  free(buf_ft);
}

void test_ft_write_errno_value(void) {
  TEST_ASSERT_EQUAL_INT(-1, ft_write(-1, str, len));
  TEST_ASSERT_EQUAL_INT(EBADF, errno);
}

void test_ft_write(void) {
  RUN_TEST(test_ft_write_against_write1);
  RUN_TEST(test_ft_write_against_write2);
  RUN_TEST(test_ft_write_errno_value);

  unlink(SYS_WRITE_OUT);
  unlink(FT_WRITE_OUT);
}
