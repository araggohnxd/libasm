/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:12 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/29 16:45:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_list_size_empty_list(void) {
  t_list *list = NULL;

  TEST_ASSERT_EQUAL_INT(0, ft_list_size(list));
}

void test_ft_list_size_one_element(void) {
  t_list *list = malloc(sizeof(t_list));
  list->data = "Hello";
  list->next = NULL;

  TEST_ASSERT_EQUAL_INT(1, ft_list_size(list));

  free(list);
}

void test_ft_list_size_two_elements(void) {
  t_list *list = malloc(sizeof(t_list));
  list->data = "Hello";
  list->next = malloc(sizeof(t_list));
  list->next->data = "World";
  list->next->next = NULL;

  TEST_ASSERT_EQUAL_INT(2, ft_list_size(list));

  free(list->next);
  free(list);
}

void test_ft_list_size(void) {
  RUN_TEST(test_ft_list_size_empty_list);
  RUN_TEST(test_ft_list_size_one_element);
  RUN_TEST(test_ft_list_size_two_elements);
}
