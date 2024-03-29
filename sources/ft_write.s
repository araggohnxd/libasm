;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_write.s                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/23 16:44:20 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/23 16:44:20 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_write
extern __errno_location

; mov rax, 1
;   Set RAX to 1. This is the value used to indicate SYS_WRITE as the system
;   call.
;
; syscall
;   Execute the system call.
;
; cmp rax, 0
;   Compare the return of SYS_WRITE to 0. This is useful because any value below
;   zero indicates that an error occured.
;
; jl __error
;   Jumps to the `__error` label if the previous comparison result shows that
;   the function return value was lesser than 0.
;
; ret
;   Return from the function.
;
; __error
; -------
; neg rax
;   Negate RAX. The error code will be negative, for example, -9 for EBADF. In
;   order to have the correct ERRNO value, RAX is negated.
;
; mov rdx, rax
;   Moves RAX value into RDX to save it for future usage. This step is necessary
;   as `__errno_location` function will be called on the next instruction,
;   effectively overwriting the ERRNO code we need to set.
;
; call __errno_location wrt ..plt
;   Get the ERRNO variable. WRT ..PLT stands for "with respect to Procedure
;   Linkage Table". PLT is a mechanism used in dynamic linking to allow
;   functions to be called indirectly, and it's commonly used when calling
;   functions from shared libraries. The PLT ensures that the correct address
;   of the function is resolved at runtime. Since is part of the C library, its
;   address might need to be resolved dynamically.
;
; mov [rax], rdx
;   Moves the value in RDX to the memory pointed to by RAX, which at this point
;   contains a reference to the ERRNO variable.
;
; mov rax, -1
;   Sets RAX to -1 to indicate an error occured during SYS_WRITE execution.
;
; ret
;   Returns from the function.

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl __error
    ret

__error:
    neg rax
    mov rdx, rax
    call __errno_location wrt ..plt
    mov [rax], rdx
    mov rax, -1
    ret
