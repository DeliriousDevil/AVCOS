#include "gdt.h"
#include "../io.h"

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;

void init_gdt() {
    gdt_ptr.limit = sizeof(gdt_entries) - 1;
    gdt_ptr.base = (uint64_t)&gdt_entries;

    gdt_entries[0] = (gdt_entry_t){0, 0, 0, 0, 0, 0};              // Null descriptor
    gdt_entries[1] = create_gdt_entry(0, 0xFFFFFFFF, 0x9A, 0xA0); // Code segment
    gdt_entries[2] = create_gdt_entry(0, 0xFFFFFFFF, 0x92, 0xA0); // Data segment

    load_gdt(&gdt_ptr);
}

gdt_entry_t create_gdt_entry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
    gdt_entry_t entry;
    entry.limit_low = limit & 0xFFFF;
    entry.base_low = base & 0xFFFF;
    entry.base_middle = (base >> 16) & 0xFF;
    entry.access = access;
    entry.limit_high_flags = (limit >> 16) & 0x0F | (flags << 4);
    entry.base_high = (base >> 24) & 0xFF;
    return entry;
}