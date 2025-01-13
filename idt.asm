[BITS 64]

section .bss
idt_start resb 256 * 16

section .text
load_idt:
    lidt [idt_descriptor]
    ret

idt_descriptor:
    dw 256 * 16 - 1
    dq idt_start