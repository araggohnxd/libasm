/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:23:46 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/28 21:55:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_list_push_front_root_is_null(void) {
  t_list *root = NULL;

  ft_list_push_front(&root, "hello, world!");

  TEST_ASSERT_EQUAL_STRING("hello, world!", root->data);
  TEST_ASSERT_NULL(root->next);

  free(root);
}

void test_ft_list_push_front_root_exists_with_data_foo(void) {
  t_list *root = malloc(sizeof(t_list));

  root->data = "foo";
  root->next = NULL;

  ft_list_push_front(&root, "hello, world!");

  TEST_ASSERT_EQUAL_STRING("hello, world!", root->data);
  TEST_ASSERT_EQUAL_STRING("foo", root->next->data);
  TEST_ASSERT_NULL(root->next->next);

  free(root->next);
  free(root);
}

void test_ft_list_push_front_exists_with_another_list(void) {
  t_list *root = NULL;
  t_list *other = malloc(sizeof(t_list));

  other->data = "foo";
  other->next = NULL;

  ft_list_push_front(&root, other);

  t_list *tmp = root->data;
  TEST_ASSERT_EQUAL_PTR(other, root->data);
  TEST_ASSERT_EQUAL_STRING(other->data, tmp->data);
  TEST_ASSERT_EQUAL_STRING("foo", tmp->data);
  TEST_ASSERT_NULL(root->next);

  free(other);
  free(root);
}

void test_ft_list_push_front(void) {
  RUN_TEST(test_ft_list_push_front_root_is_null);
  RUN_TEST(test_ft_list_push_front_root_exists_with_data_foo);
  RUN_TEST(test_ft_list_push_front_exists_with_another_list);
}
