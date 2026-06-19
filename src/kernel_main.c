#include <vga.h>

int main(void) {
    put_char('4', MAX_CHAR_VGA / 2, MAX_CHAR_VGA/2); 
    put_char('2', MAX_CHAR_VGA / 2 + 1, MAX_CHAR_VGA/2); 
}
