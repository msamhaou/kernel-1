#include <pic.h>
extern unsigned char inb(unsigned short port);
extern void outb(unsigned short port, unsigned char b);
extern void io_wait();

void pic_remap(){
	outb(MASTER, ICW1_INIT | ICW1_ICW4);
	outb(SLAVE, ICW1_INIT, | ICW1_ICW4);
	io_wait();
	//ICW2
	outb(MASTER_DATA, IRQ1);
	outb(SLAVE_DATA, IRQ8);

	io_wait();
	outb(MASTER_DATA, 0x4); // 001 means IRQ2
	outb(SLAVE_DATA, 0x2);	

	io_wait();

	outb(MASTER_DATA, ICW4_8086);
	outb(SLAVE_DATA, ICW4_8086);

	io_wait();
}
