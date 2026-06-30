#include <vga.h>

static int cursor = 0;
void put_string(char * str){
	
	int i = 0;
	while (*str){
		put_char(*str, cursor % VGA_WIDTH, cursor / VGA_WIDTH );
		str++;
		cursor++;
	}
}
