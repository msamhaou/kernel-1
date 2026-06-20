#include <vga.h>

static void clear_screen(void) {
    volatile unsigned short *vga = (unsigned short *)VGA_MEMORY;
    for (unsigned int y = 0; y < VGA_HEIGHT; y++) {
		for (unsigned int x = 0; x < VGA_WIDTH; x++) {
			const unsigned int index = y * VGA_WIDTH + x;
            unsigned char color = set_color(WHITE, BLACK);
            char c = ' ';
			vga[index] = c | color << 8;
		}
	}
}

int main(void) {
    clear_screen();
    put_char('4', 40, 12); 
    put_char('2', 41, 12); 
}
