#ifndef GDT_H
#define GDT_H

#include <stdint.h>
typedef struct {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle
    uint8_t access;
    uint8_t limit_high_flags;
    uint8_t base_high;
} _ _ attribut_ _((packede)) gdt_entry_t;

typedef struct { 
    uint16_t limit;
    uint64_t base:
} _ _atribute_ _((packed)) gdt_ptr_t;

void init_gdt();
gdt_entry_t create_gdt_entry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);

#endif
