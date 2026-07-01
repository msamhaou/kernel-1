#include <vga.h>
#include <utils.h>
void put_string(char * str){
	
	int i = 0;
	while (*str){
		put_char(*str, cursor % VGA_WIDTH, cursor / VGA_WIDTH );
		str++;
		cursor++;
	}
}
