/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:31:52 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/09 20:37:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

static void test_ft_strlen2_against_constants(void) {
  TEST_ASSERT_EQUAL(13, ft_strlen2("Hello, World!"));
  TEST_ASSERT_EQUAL(13, ft_strlen2("Hello, World!\0"));
  TEST_ASSERT_EQUAL(6, ft_strlen2("Hello,\0World!"));
  TEST_ASSERT_EQUAL(0, ft_strlen2(""));
  TEST_ASSERT_EQUAL(0, ft_strlen2("\0"));
  TEST_ASSERT_EQUAL(1, ft_strlen2("a"));
  TEST_ASSERT_EQUAL(1, ft_strlen2(" "));
  TEST_ASSERT_EQUAL(1, ft_strlen2("\n"));
}

static void test_ft_strlen2_against_strlen(void) {
  TEST_ASSERT_EQUAL(strlen("Hello, World!"), ft_strlen2("Hello, World!"));
  TEST_ASSERT_EQUAL(strlen("Hello, World!\0"), ft_strlen2("Hello, World!\0"));
  TEST_ASSERT_EQUAL(strlen("Hello,\0World!"), ft_strlen2("Hello,\0World!"));
  TEST_ASSERT_EQUAL(strlen(""), ft_strlen2(""));
  TEST_ASSERT_EQUAL(strlen("\0"), ft_strlen2("\0"));
  TEST_ASSERT_EQUAL(strlen("a"), ft_strlen2("a"));
  TEST_ASSERT_EQUAL(strlen(" "), ft_strlen2(" "));
  TEST_ASSERT_EQUAL(strlen("\n"), ft_strlen2("\n"));
}

void test_ft_strlen2(void) {
  RUN_TEST(test_ft_strlen2_against_constants);
  RUN_TEST(test_ft_strlen2_against_strlen);
}
