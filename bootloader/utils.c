#include "config.h"

void clear_screen() {
    char *video = (char*) VIDEO_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i++) {
        video[i] = 0; 
    }
}

void print(const char *str) {
    char *video = (char*) VIDEO_MEMORY;
    while (*str) {
        *video++ = *str++;
        *video++ = 0x07; 
    }
}
