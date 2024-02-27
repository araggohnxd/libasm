/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:31 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/27 18:43:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void test_ft_strdup_against_constants(void) {
  char *str, *ret;

  str = "";
  ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(str, ret);
  free(ret);

  str = "hello, world!";
  ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(str, ret);
  free(ret);

  str =
      "Voila! In view, a humble vaudevillian veteran, cast vicariously as both "
      "victim and villain by the vicissitudes of Fate. This visage, no mere "
      "veneer of vanity, is a vestige of the vox populi, now vacant, vanished. "
      "However, this valorous visitation of a by-gone vexation, stands "
      "vivified and has vowed to vanquish these venal and virulent vermin "
      "vanguarding vice and vouchsafing the violently vicious and voracious "
      "violation of volition. The only verdict is vengeance; a vendetta, held "
      "as a votive, not in vain, for the value and veracity of such shall one "
      "day vindicate the vigilant and the virtuous. Verily, this vichyssoise "
      "of verbiage veers most verbose, so let me simply add that it's my very "
      "good honor to meet you and you may call me V.";
  ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(str, ret);
  free(ret);
}

void test_ft_strdup_against_strdup(void) {
  char *str, *og_ret, *ft_ret;

  str = "";
  og_ret = strdup(str);
  ft_ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(og_ret, ft_ret);
  free(ft_ret);
  free(og_ret);

  str = "hello, world!";
  og_ret = strdup(str);
  ft_ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(og_ret, ft_ret);
  free(ft_ret);
  free(og_ret);

  str =
      "Voila! In view, a humble vaudevillian veteran, cast vicariously as both "
      "victim and villain by the vicissitudes of Fate. This visage, no mere "
      "veneer of vanity, is a vestige of the vox populi, now vacant, vanished. "
      "However, this valorous visitation of a by-gone vexation, stands "
      "vivified and has vowed to vanquish these venal and virulent vermin "
      "vanguarding vice and vouchsafing the violently vicious and voracious "
      "violation of volition. The only verdict is vengeance; a vendetta, held "
      "as a votive, not in vain, for the value and veracity of such shall one "
      "day vindicate the vigilant and the virtuous. Verily, this vichyssoise "
      "of verbiage veers most verbose, so let me simply add that it's my very "
      "good honor to meet you and you may call me V.";
  og_ret = strdup(str);
  ft_ret = ft_strdup(str);
  TEST_ASSERT_EQUAL_STRING(og_ret, ft_ret);
  free(ft_ret);
  free(og_ret);
}

void test_ft_strdup(void) {
  RUN_TEST(test_ft_strdup_against_constants);
  RUN_TEST(test_ft_strdup_against_strdup);
}
