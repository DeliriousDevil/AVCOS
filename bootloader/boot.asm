[org 0x7c00]
BITS 16

start:
    cli                   ; Disable interrupts
    xor ax, ax
    mov ds, ax            ; set data segment to 0
    mov ss, ax            ; set stack segment to 0
    mov sp, 0x7c00        ; set stack pointer

    mov si, msg
    call print_string

    ; Load second stage (loader)
    mov ax, 0x0201
    mov bx, 0x1000        ; Load address for loader
    mov dl, 0x00          ; Boot drive
    int 0x13

    jmp 0x1000:0000       ;Jump to loader

msg db "AVCOS Bootloader is Loading (x86_64)...", 0

print_string:
    mov ah, 0x0E
.print_next_char:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .print_next_char
.done:
    ret

times 510-($-$$) db 0
dw 0xAA55
