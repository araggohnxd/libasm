;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strdup.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/27 17:01:27 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/27 17:01:27 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_strdup
extern ft_strlen
extern ft_strcpy
extern __errno_location
extern malloc

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc wrt ..plt
    cmp rax, 0
    je __error
    mov rdi, rax
    pop rsi
    call ft_strcpy
    ret

__error:
    neg rax
    mov rdx, rax
    call __errno_location wrt ..plt
    mov [rax], rdx
    mov rax, 0
    ret
