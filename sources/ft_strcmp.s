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

; Both implementations assume that RDI points to the first byte of `s1`
; and RSI points to the first byte of `s2`.

; Explicit loop construct
; -----------------------
; xor rcx, rcx
;   Sets RCX to 0, by XORing it to itself. It needs to be zeroed since it will
;   be used as counter to traverse the strings being compared.
;
; __loop
; ------
; mov dh, [rdi + rcx]
;   Moves the byte located in RDI plus the RCX offset to the DH register. This
;   register will be used to store the current byte of the RDI string `s1`.
;
; mov dl, [rsi + rcx]
;   Moves the byte located in RSI plus the RCX offset to the DL register. This
;   register will be used to store the current byte of the RSI string `s2`.
;
; inc rcx
;   Increase the value in RCX, moving the string offset by one.
;
; cmp dl, 0
;   Compare the byte in DL to 0 to check for the null terminator.
;
; je __eq
;   Jump to `__eq` if the result of the previous comparison is equal.
;
; cmp dl, dh
;   Compares the byte in DL to the byte in DH, effectively comparing the current
;   byte of both strings.
;
; je __loop
;   Jump back to the beggining of `__loop` if the result of the previous
;   comparison is equal.
;
; jb __lt
;   Jump to `__lt` if the result of the previous comparison was below. The
;   difference between JB and JL, is that the former assumes that the result
;   of the previous comparison, which is essentially a subtraction, is unsigned.
;   The latter (Jump short if Less) assumes signedness. Since the original
;   `strcmp` assumes unsignedness, JB is more appropriate.
;
; ja __gt
;   Jump to `__gt` if the result of the previous comparison was above. The
;   difference between JA and JG, is that the former assumes that the result
;   of the previous comparison, which is essentially a subtraction, is unsigned.
;   The latter (Jump short if Greater) assumes signedness. Since the original
;   `strcmp` assumes unsignedness, JA is more appropriate.
;
; __eq
; ----
; cmp dh, 0
;   Compares the byte in DH to 0 to check for the null terminator. The only way
;   to reach this label is by checking if the byte in DL is also null, so if the
;   result of this comparison is equal, it means that both strings reach EOS.
;
; jne __lt
;   Jump to `__lt` if the result of the previous comparsion is not equal. This
;   means that `s2` reached EOS, but `s1` did not.
;
; xor rax, rax
;   Sets RAX to 0, by XORing it to itself. At this point, it is certain that
;   both strings reached EOS, and therefore, are equal to each other, so the
;   return should be 0.
;
; ret
;   Returns from the function.
;
; __lt
; ----
; mov rax, 1
;   Sets RAX to 1. This label marks the end of the function if `s2` is lesser
;   than `s1`, so the result should be greater than 0.
;
; ret
;   Returns from the function.
;
; __gt
; ----
; mov rax, -1
;   Sets RAX to -1. This label marks the end of the function if `s2` is greater
;   than `s1`, so the result should be lesser than 0.
;
; ret
;   Returns from the function.

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

; Specialized string instructions
; -------------------------------
; push rdi
;   Pushes the value in RDI onto the stack, preserving it for future usage. This
;   step is necessary because `ft_strlen` will perform changes on the RDI memory
;   space, so we need to save it.
;
; call ft_strlen
;   Calls `ft_strlen` with the source string as argument to calculate its size.
;
; pop rdi
;   Loads the value from the top of the stack to the RDI register. In this case,
;   the only pushed value is the old RDI value, so it will get back to its
;   original state.
;
; mov rcx, rax
;   Moves the value in RAX to RCX. RAX now contains the return of `ft_strlen`,
;   that is, the length of `s1`. We need to move it to RCX because us the value
;   that the REP instruction will use in order to know when to stop looping, as
;   it will decrement RCX after each iteration, and stop once it reaches 0.
;
; inc rcx
;   Increases the value in RCX, to make sure that the REPE CMPSB instruction
;   will be executed at least once, even if the length of `s1` is 0.
;
; repe cmpsb
;   REPE stands for "Repeat while Equal", and is equivalent to the REPZ
;   instruction, that stands for "Repeat while Zero". This instruction will
;   repeat the following instruction until either 1. the Zero Flag (ZF) is unset
;   or 2. the value in RCX reaches 0. CMPS stands for "Compare String", and the
;   CMPSB variant means it will compare byte by byte. This instructions is
;   effectively looping through the strings in RDI and RSI while they are equal,
;   and once it finds a difference or RCX reaches 0, it stops.
;
; jb __lt2
;   Jump to `__lt2` if the result of the previous comparison was below. The
;   difference between JB and JL, is that the former assumes that the result
;   of the previous comparison, which is essentially a subtraction, is unsigned.
;   The latter (Jump short if Less) assumes signedness. Since the original
;   `strcmp` assumes unsignedness, JB is more appropriate.
;
; ja __gt2
;   Jump to `__gt2` if the result of the previous comparison was above. The
;   difference between JA and JG, is that the former assumes that the result
;   of the previous comparison, which is essentially a subtraction, is unsigned.
;   The latter (Jump short if Greater) assumes signedness. Since the original
;   `strcmp` assumes unsignedness, JA is more appropriate.
;
; je __eq2
;   Jump to `__eq2` if the result of the previous comparison was equal.
;
; __eq2
; -----
; xor rax, rax
;   Sets RAX to 0, by XORing it to itself. This label marks the end of the
;   function if both the strings are equal, so the return should be 0.
;
; ret
;   Returns from the function.
;
; __lt2
; -----
; mov rax, 1
;   Sets RAX to 1. This label marks the end of the function if `s2` is lesser
;   than `s1`, so the result should be greater than 0.
;
; ret
;   Returns from the function.
;
; __gt2
; -----
; mov rax, -1
;   Sets RAX to -1. This label marks the end of the function if `s2` is greater
;   than `s1`, so the result should be lesser than 0.
;
; ret
;   Returns from the function.

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
