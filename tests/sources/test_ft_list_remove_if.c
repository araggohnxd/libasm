/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:24:08 by maolivei          #+#    #+#             */
/*   Updated: 2024/03/01 14:12:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_list_remove_if_two_elements_with_no_equal_strings(void) {
    t_list *list = malloc(sizeof(t_list));
    list->data = strdup("Hello");
    list->next = malloc(sizeof(t_list));
    list->next->data = strdup("World");
    list->next->next = NULL;

    ft_list_remove_if(&list, "42", strcmp, free);

    TEST_ASSERT_EQUAL_STRING("Hello", list->data);
    TEST_ASSERT_EQUAL_STRING("World", list->next->data);
    TEST_ASSERT_NULL(list->next->next);

    free(list->data);
    free(list->next->data);
    free(list->next);
    free(list);
}

void test_ft_list_remove_if_two_elements_with_one_equal_string(void) {
    t_list *list = malloc(sizeof(t_list));
    list->data = strdup("Hello");
    list->next = malloc(sizeof(t_list));
    list->next->data = strdup("World");
    list->next->next = NULL;

    ft_list_remove_if(&list, "Hello", strcmp, free);

    TEST_ASSERT_EQUAL_STRING("World", list->data);
    TEST_ASSERT_NULL(list->next);

    free(list->data);
    free(list);
}

void test_ft_list_remove_if_two_elements_with_two_equal_strings(void) {
    t_list *list = malloc(sizeof(t_list));
    list->data = strdup("Hello");
    list->next = malloc(sizeof(t_list));
    list->next->data = strdup("Hello");
    list->next->next = NULL;

    ft_list_remove_if(&list, "Hello", strcmp, free);

    TEST_ASSERT_NULL(list);
}

void test_ft_list_remove_if_empty_list(void) {
    t_list *list = NULL;

    ft_list_remove_if(&list, "Hello", strcmp, free);

    TEST_ASSERT_NULL(list);
}

void test_ft_list_remove_if(void) {
    RUN_TEST(test_ft_list_remove_if_two_elements_with_no_equal_strings);
    RUN_TEST(test_ft_list_remove_if_two_elements_with_one_equal_string);
    RUN_TEST(test_ft_list_remove_if_two_elements_with_two_equal_strings);
    RUN_TEST(test_ft_list_remove_if_empty_list);
}
