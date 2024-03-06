/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:51:52 by maolivei          #+#    #+#             */
/*   Updated: 2024/03/05 19:14:53 by maolivei         ###   ########.fr       */
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

int *intdup(int value) {
  int *ptr = malloc(sizeof(int));

  if (!ptr)
    return (NULL);

  *ptr = value;
  return (ptr);
}

int intcmp(int *a, int *b) { return (*a - *b); }

void ft_list_clear(t_list *head, void (*free_fct)(void *)) {
  t_list *tmp;

  while (head) {
    tmp = head;
    head = head->next;
    if (free_fct)
      free_fct(tmp->data);
    free(tmp);
  }
}
