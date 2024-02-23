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
global ft_strcmp2
extern ft_strlen

ft_strcmp:
    xor rcx, rcx

__loop:
    mov dh, [rdi + rcx]
    mov dl, [rsi + rcx]
    inc rcx
    cmp dl, 0
    je __eq
    cmp dl, dh
    je __loop
    jb __lt
    ja __gt

__eq:
    cmp dh, 0
    jne __lt
    xor rax, rax
    ret

__lt:
    mov rax, 1
    ret

__gt:
    mov rax, -1
    ret

ft_strcmp2:
    push rdi
    call ft_strlen
    pop rdi
    mov rcx, rax
    inc rcx
    repe cmpsb
    jb __lt2
    ja __gt2
    je __eq2

__eq2:
    xor rax, rax
    ret

__lt2:
    mov rax, 1
    ret

__gt2:
    mov rax, -1
    ret
