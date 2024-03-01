;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_list_remove_if.s                                :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/29 20:17:16 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/29 20:17:16 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_list_remove_if
extern free

; typedef struct s_list {
;   void *data;
;   struct t_list *next;
; } t_list;
;
; void ft_list_remove_if(
;   t_list **begin_list,
;   void *data_ref,
;   int (*cmp)(),
;   void (*free_fct)(void *)
; );
;
; RDI = begin_list: pointer to the list's head
; RSI = data_ref: data to be compared to
; RDX = cmp: pointer to function for comparison
; RCX = free_fct: pointer to function for freeing memory

ft_list_remove_if:
    ; save function arguments in stack pointer
    push rbp
    mov rbp, rsp
    sub rsp, 48
    mov [rbp - 24], rdi
    mov [rbp - 32], rsi
    mov [rbp - 40], rdx
    mov [rbp - 48], rcx

    ; test begin_list
    cmp qword [rbp - 24], 0
    je __end

    ; test *begin_list
    mov rax, [rbp - 24]
    mov rax, [rax]
    test rax, rax
    je __end

    ; setup cmp
    mov rdi, [rax]
    call rdx

    ; if cmp returned nonzero, skip node
    test rax, rax
    jne __cmp_nonzero

    ; save next node
    mov rax, [rbp - 24]
    mov rax, [rax]
    mov rax, [rax + 8]
    mov [rbp - 8], rax

    ; setup free_fct
    mov rax, [rbp - 24]
    mov rax, [rax]
    mov rdi, [rax]
    mov rcx, [rbp - 48]
    call rcx

    ; setup free
    mov rax, [rbp - 24]
    mov rdi, [rax]
    call free wrt ..plt

    ; set head to saved node
    mov rax, [rbp - 24]
    mov rdx, [rbp - 8]
    mov [rax], rdx

    ; setup recursive call
    mov rdi, [rbp - 24]
    mov rsi, [rbp - 32]
    mov rdx, [rbp - 40]
    mov rcx, [rbp - 48]
    call ft_list_remove_if
    jmp __end

__cmp_nonzero:
    ; setup recursive call with begin_list->next
    mov rax, [rbp - 24]
    mov rax, [rax]
    lea rdi, [rax + 8]
    mov rsi, [rbp - 32]
    mov rdx, [rbp - 40]
    mov rcx, [rbp - 48]
    call ft_list_remove_if

__end:
    leave
    ret
