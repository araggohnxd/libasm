;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_list_sort.s                                     :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/29 16:50:15 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/29 16:50:15 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_list_sort
extern malloc
extern free

; typedef struct s_list {
;   void *data;
;   struct t_list *next;
; } t_list;
;
; void ft_list_sort(t_list **begin_list, int (*cmp)());
;
; RDI = begin_list: pointer to the list's head
; RSI = cmp: pointer to function for comparison

ft_list_merge:
    ; save function arguments in stack pointer
    push rbp
    mov rbp, rsp
    sub rsp, 48
    mov [rbp - 24], rdi ; head
    mov [rbp - 32], rsi ; left
    mov [rbp - 40], rdx ; right
    mov [rbp - 48], rcx ; cmp

    ; tail and tmp
    mov rdi, 16
    call malloc wrt ..plt
    test rax, rax
    je __end
    mov [rbp - 8], rax  ; tail
    mov [rbp - 16], rax ; tmp

__merge_loop:
    ; check left and right
    cmp qword [rbp - 32], 0
    je __set_tail
    cmp qword [rbp - 40], 0
    je __set_tail

    ; setup cmp
    mov rdi, [rbp - 32]
    mov rdi, [rdi]
    mov rsi, [rbp - 40]
    mov rsi, [rsi]
    mov rcx, [rbp - 48]
    call rcx

    ; check cmp return
    shr eax, 31
    test al, al
    je __cmp_gte_zero

    ; tail->next = left
    mov rax, [rbp - 8]
    mov rdx, [rbp - 32]
    mov [rax + 8], rdx

    ; left = left->next
    mov rax, [rbp - 32]
    mov rax, [rax + 8]
    mov [rbp - 32], rax

    jmp __loop_callback

__cmp_gte_zero:
    ; tail->next = right
    mov rax, [rbp - 8]
    mov rdx, [rbp - 40]
    mov [rax + 8], rdx

    ; right = right->next
    mov rax, [rbp - 40]
    mov rax, [rax + 8]
    mov [rbp - 40], rax

__loop_callback:
    ; tail = tail->next
    mov rax, [rbp - 8]
    mov rax, [rax + 8]
    mov [rbp - 8], rax
    jmp __merge_loop

__set_tail:
    cmp qword [rbp - 32], 0
    je __set_tail_right ; if left is NULL, set tail right
    mov rax, [rbp - 32] ; else, set tail left
    jmp __finish_merge

__set_tail_right:
    mov rax, [rbp - 40]

__finish_merge:
    ; set tail
    mov rdx, [rbp - 8]
    mov [rdx + 8], rax

    ; head = tmp->next
    mov rdx, [rbp - 16]
    mov rdx, [rdx + 8]
    mov rax, [rbp - 24]
    mov [rax], rdx

    ; setup free
    mov rdi, [rbp - 16]
    call free wrt ..plt

    jmp __end

ft_list_get_middle:
    ; save function arguments in stack pointer
    push rbp
    mov rbp, rsp
    sub rsp, 24
    mov [rbp - 24], rdi ; head

    ; setup pointers
    mov rax, [rbp - 24]
    mov [rbp - 8], rax  ; slow
    mov rax, [rax + 8]
    mov [rbp - 16], rax ; fast

__pointers_loop:
    ; check fast and fast->next
    cmp qword [rbp - 16], 0
    je __return_slow
    mov rax, [rbp - 16]
    mov rax, [rax + 8]
    test rax, rax
    je __return_slow

    ; slow = slow->next
    mov rax, [rbp - 8]
    mov rax, [rax + 8]
    mov [rbp - 8], rax

    ; fast = fast->next->next
    mov rax, [rbp - 16]
    mov rax, [rax + 8]
    mov rax, [rax + 8]
    mov [rbp - 16], rax

    jmp __pointers_loop

__return_slow:
    mov rax, [rbp - 8]
    jmp __end

ft_list_sort:
    ; save function arguments in stack pointer
    push rbp
    mov rbp, rsp
    sub rsp, 48
    mov [rbp - 40], rdi ; begin_list
    mov [rbp - 48], rsi ; cmp

    ; save list head
    mov rax, [rbp - 40]
    mov rax, [rax]
    mov [rbp - 8], rax ; head

    ; check head and head->next
    test rax, rax
    je __end
    mov rax, [rax + 8]
    test rax, rax
    je __end

    ; setup right pointer
    mov rdi, [rbp - 8]
    call ft_list_get_middle
    mov [rbp - 32], rax ; right
    mov rax, [rax + 8]
    mov [rbp - 16], rax ; tmp
    mov rax, [rbp - 32]
    mov qword [rax + 8], 0
    mov rax, [rbp - 16]
    mov [rbp - 32], rax
    lea rdi, [rbp - 32]
    mov rsi, [rbp - 48]
    call ft_list_sort

    ; setup left pointer
    lea rdi, [rbp - 8]
    mov rsi, [rbp - 48]
    call ft_list_sort

    ; setup merge
    mov rdi, [rbp - 40]
    mov rsi, [rbp - 8]
    mov rdx, [rbp - 16]
    mov rcx, [rbp - 48]
    call ft_list_merge

__end:
    leave
    ret
