#include "init.h"
#include "../arch/x86_64/gdt.h"
#include "../arch/x86_64/idt.h"
#include "../arch/x86_64/paging.h"
#include "../arch/x86_64/vga.h"

void kernel_init() {
    init_gdt();
    init_idt();
    init_paging();
    vga_clear();
    vga_print("AVCOS Kernel Initialized!\n");
}
