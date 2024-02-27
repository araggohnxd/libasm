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

; push rdi
;   Pushes the value in RDI onto the stack, preserving it for future usage. This
;   step is necessary because `ft_strlen` will perform changes on the RDI memory
;   space, so we need to save it.
;
; call ft_strlen
;   Calls `ft_strlen` with the source string as argument to calculate its size.
;
; inc rax
;   Increments the value in RAX by 1. `ft_strlen` will return the size of the
;   string, excluding the null terminator. In order to allocate the correct
;   amount of memory, we need to calculate `ft_strlen`+1.
;
; mov rdi, rax
;   Moves the value in RAX to RDI. The next instruction will call MALLOC, so RDI
;   needs to be set to the size of the memory block we want to allocate.
;
; call malloc wrt ..plt
;   Call MALLOC with the value returned by `ft_strlen` + 1 as argument.
;
; cmp rax, 0
;   Compare the value in 0 to the value in RAX. Checks if the value returned by
;   MALLOC is a null pointer, indicating failure.
;
; je __end
;   Jump to `__end` if the result of the last comparison is equal. This means
;   an error occured with MALLOC and the memory could not be allocated.
;
; mov rdi, rax
;   Moves the value in RAX to RDI. Soon `ft_strcpy` will be called, so the RDI
;   register needs to be set to the destination string, that is, the memory
;   block returned by MALLOC.
;
; pop rsi
;   Loads the value from the top of the stack to the RSI register. In this case,
;   the only pushed value is the old RDI value, containing the source string.
;
; call ft_strcpy
;   Calls `ft_strcpy` to copy the string in RSI to the memory location in RDI,
;   provided by MALLOC.
;
; ret
;   Returns from the function. No need to move any more registers since
;   `ft_strcpy` already returns the destination string by default.
;
; __end
; -----
; ret
;   Returns from the function. At this point, RAX contains 0, returning a null
;   pointer

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc wrt ..plt
    cmp rax, 0
    je __end
    mov rdi, rax
    pop rsi
    call ft_strcpy
    ret

__end:
    ret
