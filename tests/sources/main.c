/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:30:04 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 19:00:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

int main(void) {
  UNITY_BEGIN();

  test_ft_strlen();
  test_ft_strlen2();
  test_ft_strcpy();
  test_ft_strcpy2();
  test_ft_strcmp();
  test_ft_strcmp2();
  test_ft_write();

  return (UNITY_END());
}
