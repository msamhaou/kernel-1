#include <vga.h>

void put_char(char c, int x, int y){
    volatile unsigned char *vga = (unsigned char *)VGA_MEMORY;
    *(vga++) = c;
    unsigned char color = 0xff;
    *vga = (color << 4) + 0x0;
}

void print_string(const char *s){
    volatile unsigned char *vp = (unsigned char *)VGA_MEMORY;
}
