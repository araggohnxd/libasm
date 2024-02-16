/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:51:49 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/15 21:01:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_strcpy2_against_constants(void)
{
  char buffer[32];

  TEST_ASSERT_EQUAL_STRING("Hello", ft_strcpy2(buffer, "Hello"));
  TEST_ASSERT_EQUAL_STRING("Hello", buffer);
  TEST_ASSERT_EQUAL_STRING("Hello, World!", ft_strcpy2(buffer, "Hello, World!"));
  TEST_ASSERT_EQUAL_STRING("Hello, World!", buffer);
  TEST_ASSERT_EQUAL_STRING("Hello, World!\0", ft_strcpy2(buffer, "Hello, World!\0"));
  TEST_ASSERT_EQUAL_STRING("Hello, World!\0", buffer);
  TEST_ASSERT_EQUAL_STRING("Hello,\0World!", ft_strcpy2(buffer, "Hello,\0World!"));
  TEST_ASSERT_EQUAL_STRING("Hello,\0World!", buffer);
  TEST_ASSERT_EQUAL_STRING("", ft_strcpy2(buffer, ""));
  TEST_ASSERT_EQUAL_STRING("", buffer);
  TEST_ASSERT_EQUAL_STRING("\0", ft_strcpy2(buffer, "\0"));
  TEST_ASSERT_EQUAL_STRING("\0", buffer);
  TEST_ASSERT_EQUAL_STRING("a", ft_strcpy2(buffer, "a"));
  TEST_ASSERT_EQUAL_STRING("a", buffer);
  TEST_ASSERT_EQUAL_STRING(" ", ft_strcpy2(buffer, " "));
  TEST_ASSERT_EQUAL_STRING(" ", buffer);
  TEST_ASSERT_EQUAL_STRING("\n", ft_strcpy2(buffer, "\n"));
  TEST_ASSERT_EQUAL_STRING("\n", buffer);
}

void test_ft_strcpy2_against_strcpy(void)
{
  char buffer1[32];
  char buffer2[32];

  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "Hello"), ft_strcpy2(buffer2, "Hello"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "Hello, World!"), ft_strcpy2(buffer2, "Hello, World!"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "Hello, World!\0"), ft_strcpy2(buffer2, "Hello, World!\0"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "Hello,\0World!"), ft_strcpy2(buffer2, "Hello,\0World!"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, ""), ft_strcpy2(buffer2, ""));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "\0"), ft_strcpy2(buffer2, "\0"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "a"), ft_strcpy2(buffer2, "a"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, " "), ft_strcpy2(buffer2, " "));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
  TEST_ASSERT_EQUAL_STRING(strcpy(buffer1, "\n"), ft_strcpy2(buffer2, "\n"));
  TEST_ASSERT_EQUAL_STRING(buffer1, buffer2);
}

void test_ft_strcpy2(void)
{
  RUN_TEST(test_ft_strcpy2_against_constants);
  RUN_TEST(test_ft_strcpy2_against_strcpy);
}
