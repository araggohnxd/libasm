/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:22:39 by maolivei          #+#    #+#             */
/*   Updated: 2024/03/05 23:54:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void ft_test_list_sort_five_elements_string(void) {
  t_list *list = malloc(sizeof(t_list));
  t_list *tmp = list;

  list->data = "3";
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = "5";
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = "4";
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = "1";
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = "2";
  list->next = NULL;

  ft_list_sort(&tmp, strcmp);
  t_list *head = tmp;

  TEST_ASSERT_EQUAL_STRING("1", tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_STRING("2", tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_STRING("3", tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_STRING("4", tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_STRING("5", tmp->data);

  ft_list_clear(head, NULL);
}

void ft_test_list_sort_five_elements_integer(void) {
  t_list *list = malloc(sizeof(t_list));
  t_list *tmp = list;

  list->data = intdup(56);
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = intdup(909);
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = intdup(344);
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = intdup(817);
  list->next = malloc(sizeof(t_list));
  list = list->next;
  list->data = intdup(869);
  list->next = NULL;

  ft_list_sort(&tmp, intcmp);
  t_list *head = tmp;

  TEST_ASSERT_EQUAL_INT(56, *(int *)tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_INT(344, *(int *)tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_INT(817, *(int *)tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_INT(869, *(int *)tmp->data);
  tmp = tmp->next;
  TEST_ASSERT_EQUAL_INT(909, *(int *)tmp->data);

  ft_list_clear(head, free);
}

void ft_test_list_sort(void) {
  RUN_TEST(ft_test_list_sort_five_elements_string);
  RUN_TEST(ft_test_list_sort_five_elements_integer);
}
