;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_list_size.s                                     :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/29 16:35:52 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/29 16:35:52 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_list_size

; typedef struct s_list {
;   void *data;
;   struct t_list *next;
; } t_list;
;
; int ft_list_size(t_list *begin_list);
;
; RDI = begin_list: pointer to list

ft_list_size:
    xor rax, rax

__loop:
    cmp rdi, 0
    je __end
    inc rax
    mov rdi, [rdi + 8]
    jmp __loop

__end:
    ret
