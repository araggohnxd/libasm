;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_list_push_front.s                               :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/28 18:07:18 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/28 18:07:18 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_list_push_front
extern malloc

; typedef struct s_list {
;   void *data;
;   struct t_list *next;
; } t_list;
;
; void ft_list_push_front(t_list **begin_list, void *data);
;
; RDI = begin_list: pointer to the list's head
; RSI = data: data to be inserted

ft_list_push_front:
    push rdi
    push rsi
    mov rdi, 16
    call malloc wrt ..plt
    cmp rax, 0
    je __end
    pop rsi
    mov [rax], rsi
    pop rdi
    mov rdx, [rdi]
    mov [rax + 8], rdx
    mov [rdi], rax

__end:
    ret
