[BITS 64]

section .data
gdt_start:
    dq 0
    dq 0x00AF9A000000FFFF
    dq 0x00AF92000000FFFF
gdt_end:

section .text
load_gdt:
    lgdt [gdt_descriptor]
    ret

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dq gdt_start
