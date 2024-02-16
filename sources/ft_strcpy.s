;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/02/15 17:47:20 by maolivei          #+#    #+#             ;;
;;   Updated: 2024/02/15 17:47:20 by maolivei         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

section .text
global ft_strcpy
global ft_strcpy2
extern ft_strlen

; Both implementations assume that RDI points to the first byte of destination
; and RSI points to the first byte of source.

; Explicit loop construct
; -----------------------
; mov rax, rdi
;   Saves in RAX the initial value of RDI, which points to the first byte in the
;   destination memory address, so it can be later returned.
;
; __loop
; ------
; cmp [rsi], byte 0
;   Checks the current byte in RSI to see if its null. If it is, the Zero Flag
;   will be set.
;
; jz __end
;   If the Zero Flag is set, jump to `__end` label.
;
; mov dl, [rsi]
;   Moves the current value pointed to by RSI to DL. The reason why this step is
;   necessary is because memory-to-memory moves are not allowed in Assembly, and
;   therefore, something like `mov [rdi], [rsi]` is not possible. Instead, we
;   need to store the value in an arbitrary scratch register first, and then
;   store it in the desired register in a separate instruction.
;
; mov [rdi], dl
;   Moves the current value in DL to the current byte in RDI, completing the
;   process started by the previous instruction.
;
; inc rsi
;   Increments the value in RSI by 1, moving the pointer to the next byte.
;
; inc rdi
;   Increments the value in RDI by 1, moving the pointer to the next byte.
;
; jmp __loop
;   Jumps back to the beggining of the `__loop` label to continue processing the
;   string.
;
; __end
; -----
; mov [rdi], byte 0
;   Properly sets the terminating null byte in RDI, the destination string.
;
; ret
;   Returns from the function. At this point, RSI points to the null terminator
;   in the source string, and RDI points to the recently added null byte too.
;   Since we saved the initial position of RDI in RAX previously, it is safe to
;   return.

ft_strcpy:
    mov rax, rdi

__loop:
    cmp [rsi], byte 0
    jz __end
    mov dl, [rsi]
    mov [rdi], dl
    inc rsi
    inc rdi
    jmp __loop

__end:
    mov [rdi], byte 0
    ret

; Specialized string instructions
; -------------------------------
; push rdi
;   Pushes the value in RDI onto the stack, preserving it for future usage. This
;   step is necessary because currently, the value stored in RDI is the first
;   argument of the function (the destination memory address). But in order to
;   use `ft_strlen` to calculate the length of the source string, we need to
;   move the value in RSI (currently containing the source string) into RDI.
;
; mov rdi, rsi
;   Moves the value in RSI to RDI, effectively setting RDI to be the source
;   string.
;
; call ft_strlen
;   Calls `ft_strlen` with the source string as argument to calculate its size.
;
; pop rdi
;   Loads the value from the top of the stack to the RDI register. In this case,
;   the only pushed value is the old RDI value - the destination string -, so it
;   will get back to its original state.
;
; mov rcx, rax
;   Moves the value in RAX to RCX. RAX now contains the return of `ft_strlen`,
;   that is, the length of the source string. We need to move it to RCX because
;   is the value that the REP instruction will use in order to know when to stop
;   looping, as it will decrement RCX after each iteration, and stop once it
;   reaches 0.
;
; mov rax, rdi
;   Moves the value in RDI to RAX. RAX is the standard register for returning
;   values in functions, so we save the initial position of the destination
;   pointer in it, as it is what we need to return.
;
; rep movsb
;   REP stands for "Repeat", and MOVS for "Move data from String to string". REP
;   will execute the following instruction while the value in RCX is note equal
;   to 0, while MOVS will copy the string stored in RSI into the memory in RDI.
;   the MOVSB variant states that the copy must be performed one byte at a time.
;   Internally, this is essentially looping through the string and decrementing
;   RCX (currently containing the source string length) with each iteration.
;   This method is considerably slow, as we need to traverse the string once to
;   calculate its value, and then again to copy it to the destination memory.
;
; mov [rdi], byte 0
;   Moves the immediate value 0 into the memory pointed to by RDI. This adds
;   the null terminator in the destination string.
;
; ret
;   Returns from the function. Since we saved the initial position of RDI in RAX
;   previously, it is safe to return;
;

ft_strcpy2:
    push rdi
    mov rdi, rsi
    call ft_strlen
    pop rdi
    mov rcx, rax
    mov rax, rdi
    rep movsb
    mov [rdi], byte 0
    ret
