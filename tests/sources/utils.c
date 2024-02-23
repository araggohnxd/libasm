/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:51:52 by maolivei          #+#    #+#             */
/*   Updated: 2024/02/23 18:55:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

char *read_whole_file(const char *fname) {
  FILE *f;
  long fsize;
  char *str;

  f = fopen(fname, "rb");
  fseek(f, 0, SEEK_END);
  fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  str = malloc(fsize + 1);
  fread(str, fsize, 1, f);
  str[fsize] = 0;
  fclose(f);

  return (str);
}
