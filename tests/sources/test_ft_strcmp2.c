/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:02 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 16:01:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_strcmp2_against_constants(void) {
  TEST_ASSERT_EQUAL(1, ft_strcmp2("bbc", "abc"));
  TEST_ASSERT_EQUAL(0, ft_strcmp2("abc", "abc"));
  TEST_ASSERT_EQUAL(-1, ft_strcmp2("abb", "abc"));
  TEST_ASSERT_EQUAL(1, ft_strcmp2("abd", "abc"));
  TEST_ASSERT_EQUAL(1, ft_strcmp2("abc", "abb"));
  TEST_ASSERT_EQUAL(-1, ft_strcmp2("abc", "abd"));
}

void test_ft_strcmp2_against_strcmp(void) {
  char buffer[] = {"foo bar"};
  int ret;

  TEST_ASSERT_EQUAL(strcmp("abc", "abc"), ft_strcmp2("abc", "abc"));
  TEST_ASSERT_EQUAL(strcmp("abb", "abc"), ft_strcmp2("abb", "abc"));
  TEST_ASSERT_EQUAL(strcmp("abd", "abc"), ft_strcmp2("abd", "abc"));
  TEST_ASSERT_EQUAL(strcmp("abc", "abb"), ft_strcmp2("abc", "abb"));
  TEST_ASSERT_EQUAL(strcmp("abc", "abd"), ft_strcmp2("abc", "abd"));
  TEST_ASSERT_EQUAL(strcmp("abc", ""), ft_strcmp2("abc", ""));
  TEST_ASSERT_EQUAL(strcmp("", "abc"), ft_strcmp2("", "abc"));
  TEST_ASSERT_EQUAL(strcmp("a b", "a\0b"), ft_strcmp2("a b", "a\0b"));
  TEST_ASSERT_EQUAL(strcmp("a\0b", "a b"), ft_strcmp2("a\0b", "a b"));
  TEST_ASSERT_EQUAL(strcmp("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02"),
                    ft_strcmp2("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02"));
  TEST_ASSERT_EQUAL(strcmp("abc", "abcdef"), ft_strcmp2("abc", "abcdef"));
  TEST_ASSERT_EQUAL(strcmp("abcdef", "abc"), ft_strcmp2("abcdef", "abc"));

  for (int i = 0; i < 512; i++) {
    buffer[3] = i;

    ret = strcmp(buffer, "foo bar");
    if (ret != 0)
      ret = (ret >= 1) ? 1 : -1;
    TEST_ASSERT_EQUAL(ret, ft_strcmp2(buffer, "foo bar"));

    ret = strcmp("foo bar", buffer);
    if (ret != 0)
      ret = (ret >= 1) ? 1 : -1;
    TEST_ASSERT_EQUAL(ret, ft_strcmp2("foo bar", buffer));
  }
}

void test_ft_strcmp2(void) {
  RUN_TEST(test_ft_strcmp2_against_constants);
  RUN_TEST(test_ft_strcmp2_against_strcmp);
}
