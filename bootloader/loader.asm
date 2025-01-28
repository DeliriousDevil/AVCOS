[BITS 16]

section .text
start:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp 0x08:protected_mode_entry 

[BITS 32]
protected_mode_entry:
    mov ax, 0x10 
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call enable_long_mode
    jmp 0x28:long_mode_entry

enable_long_mode:
    mov ecx, 0xC0000080
    rdmsr
    or eax, 0x100
    wrmsr
    ret

[BITS 64]
long_mode_entry:
    mov ax, 0x30
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov rsp 0x90000
    call kernel_main

halt:
    hlt
    jmp halt

section .data
gdt: 
    dq 0
    dq 0x00AF9A000000FFFF
    dq 0x00AF92000000FFFF
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt - 1
    dq gdt
