#include<utils.h>
#include<vga.h>


extern unsigned char inb(unsigned short port);

static const char low_case[] = {0,0, '1', '2', '3','4','5','6','7','8','9','0'};

void keyboard_scan();
