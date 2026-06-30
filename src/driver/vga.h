#ifndef VGA_H
#define VGA_H

#define BLACK         0X0
#define BLUE          0X1
#define GREEN         0x2
#define CYAN          0x3
#define RED           0x4
#define MAGENTA       0x5
#define BROWN         0x6
#define GRAY          0x7
#define DARK_GREY     0x8
#define LIGHT_BLUE    0x9
#define LIGHT_GREEN   0xa
#define LIGHT_CYAN    0xb
#define LIGHT_RED     0xc
#define LIGHT_MAGENTA 0xd
#define YELLOW        0xe
#define WHITE         0xf

#define VGA_MEMORY    0xB8000
#define VGA_HEIGHT    25
#define VGA_WIDTH     80
#define MAX_CHAR_VGA    4000

void put_char(char c, int x, int y);
unsigned char set_color(unsigned char bg, unsigned char fg);
#endif // !VGA_H
