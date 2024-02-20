;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strcmp.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/19 14:18:01 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/19 14:18:01 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_strcmp

ft_strcmp:
    xor rcx, rcx

__loop:
    mov dh, [rdi + rcx]
    mov dl, [rsi + rcx]
    inc rcx
    cmp dl, 0
    je __end0
    cmp dl, dh
    je __loop
    jl __end1
    jg __end2

__end0:
    cmp dh, 0
    jne __end1
    xor rax, rax
    ret

__end1:
    mov rax, 1
    ret

__end2:
    mov rax, -1
    ret
