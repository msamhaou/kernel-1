#include <vga.h>

unsigned char set_color(unsigned char bg, unsigned char fg){
    return (bg << 4 | fg);
}

void put_char(char c, int x, int y){
    volatile unsigned short *vga = (unsigned short *)VGA_MEMORY;
    unsigned char color = set_color(WHITE, BLACK);
    vga[ y * VGA_WIDTH + x ] = color << 8 | c;
}

void print_string(const char *s){
    volatile unsigned char *vp = (unsigned char *)VGA_MEMORY;
}
