;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strlen.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/09 19:29:31 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/09 19:29:31 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_strlen

; Both implementations assume that RDI points to the first byte of the string
; to be analyzed.

; Specialized string instructions
; -------------------------------
; mov rcx, -1
;   Sets the RCX register to -1. This is the register in which the
;   REPNE SCASB instruction will update its value, decrementing it
;   by 1 per iteration. The reason why the value is decremented, instead of
;   incremented, is because the REPNE is designed to repeat the instruction
;   while 1. the Zero Flag (ZF) is not set and 2. the value in RCX is not
;   zero. So setting RCX's value to -1 guarantees that REPNE instruction
;   can decrement this register freely, without RCX ever reaching 0, since
;   there will be only negative values.
;
; xor al, al
;   Sets the AL register to 0, by XORing it to itself. This is the register
;   that the SCASB instruction will check to compare the current byte, so we
;   set it to 0, as we want to find the null-termination in the given string.
;
; repne scasb
;   REPNE stands for "Repeat while Not Equal", and is equivalent to the REPNZ
;   instruction, that stands for "Repeat while Not Zero". This instruction
;   will repeat the following instruction until either 1. the Zero Flag (ZF)
;   is set or 2. the value in RCX reaches 0. SCAS stands for "Scan String",
;   and the SCASB variant means it will scan byte by byte. This instruction
;   will scan the string located at the RDI register, byte by byte, searching
;   for the byte specified in the AL register. As we previously set AL to 0,
;   it is effectively looking for the terminating null byte. Once it finds
;   the null character, it will set the ZF, hence interrupting the execution
;   of the REPNE instruction.
;
; not rcx
;   The REPNE SCASB instruction decrements the value in RCX register, so we have
;   to NOT it in order to obtain the two's complement of RCX + 1. Since RCX was
;   initialized to -1, this will give us the number of iterations that were
;   executed, which is the index of the null terminator plus 1.
;
; dec rcx
;   Decrements the value in RCX by 1 to account for the fact that the string
;   length should not include the null terminator.
;
; mov rax, rcx
;   Moves the calculated length into RAX, which is the standard convention for
;   returning values from functions in NASM x64.
;
; ret
;   Returns from the function.

ft_strlen:
    mov rcx, -1
    xor al, al
    repne scasb
    not rcx
    dec rcx
    mov rax, rcx
    ret

; Explicit loop construct
; -----------------------
; xor rax, rax
;   Sets the RAX register to 0, by XORing it to itself. This is the standard
;   register for returning values from functions in NASM x64, and therefore
;   the register used for storing the length counter.
;
; __loop
; ------
; cmp [rdi], byte 0
;   Compares the byte at the memory location pointed to by RDI with a 0 byte,
;   the null terminator. If the comparison evaluates to true, the Zero Flag (ZF)
;   is set.
;
; jz __end
;   Jumps to the `__end` label if the ZF is set, which indicates that the null
;   terminator has been found.
;
; inc rax
;   Increments the value in RAX by 1, effectively counting the number of
;   characters already processed in the string.
;
; inc rdi
;   Increments the value in RDI by 1, moving the pointer to the next character
;   of the string.
;
; jmp __loop
;   Jumps back to the beggining of the `__loop` label to continue processing the
;   string.
;
; __end
; -----
; ret
;   Returns from the function. At this point, RAX contains the length of the
;   string.

ft_strlen2:
    xor rax, rax

__loop:
    cmp [rdi], byte 0
    jz __end

    inc rax
    inc rdi
    jmp __loop

__end:
    ret
