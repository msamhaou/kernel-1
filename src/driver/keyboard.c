#include <keyboard.h>

void keyboard_scan(){
	unsigned char scan_code = inb(0x60);

	put_char(low_case[scan_code], cursor % VGA_WIDTH, cursor / VGA_WIDTH);
	cursor++;	
}
