# lab-eval


Copy the question provided through test portal
include irvine32.inc

.data
array SWORD -3, -6, -1, -10, 10, 30, 40, 4    ; Example array with both positive and negative values
msg1 byte "Sum of all positive values is: ", 0
msg2 byte "No positive values found in the array!", 0
sum DWORD 0                                   ; Variable to store the sum of positive values

.code
main proc
    call clrscr

    mov esi, OFFSET array        ; Moving array to source index
    mov ecx, LENGTHOF array      ; ECX = length of the array
    mov eax, 0                   ; Initialize sum to 0 (eax will store the sum)

next:
    cmp WORD PTR [esi], 0        ; Compare current array element with 0
    jle not_positive             ; Jump if less than or equal to 0 (i.e., not positive)

    ; If the number is positive, add it to sum
    add eax, WORD PTR [esi]      ; Add current positive number to sum (eax)
    
not_positive:
    add esi, TYPE array          ; Move to the next element in the array
    loop next                    ; Loop through the array

    ; After looping, check if the sum is non-zero (meaning positive values were found)
    cmp eax, 0                   ; Compare sum with 0
    je no_positive               ; Jump if no positive values were found (sum is 0)

    ; If there are positive values, print the sum
    mov edx, OFFSET msg1
    call WriteString
    call WriteInt
    call crlf
    jmp quit

no_positive:
    ; If no positive value was found
    mov edx, OFFSET msg2
    call WriteString
    call crlf

quit:
    exit
main endp
end main


