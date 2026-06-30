#include <pic.h>
extern unsigned char inb(unsigned short port);
extern void outb(unsigned short port, unsigned char b);
extern void io_wait();

void pic_remap(){
	outb(MASTER, ICW1_INIT | ICW1_ICW4);

	io_wait();
	outb(SLAVE, ICW1_INIT | ICW1_ICW4);
	io_wait();
	//ICW2
	outb(MASTER_DATA, IRQ0);
	io_wait();
	outb(SLAVE_DATA, IRQ8);

	io_wait();
	outb(MASTER_DATA, 0x4); // 001 means IRQ2
	io_wait();
	outb(SLAVE_DATA, 0x2);	

	io_wait();

	outb(MASTER_DATA, ICW4_8086);
	io_wait();
	outb(SLAVE_DATA, ICW4_8086);

	io_wait();


	outb(MASTER_DATA, 0);
	outb(SLAVE_DATA, 0);
}


void	PIC_sendEOI(unsigned char irq) {
	if (irq >= 8)
		outb(SLAVE, PIC_EOI);
	outb(MASTER, PIC_EOI);
}



void	IRQ_clear_mask(unsigned char irq) {
    unsigned short port;
    unsigned char value;

    if(irq < 8) {
        port = MASTER_DATA;
    } else {
        port = SLAVE_DATA;
        irq -= 8;
    }
    value = inb(port) & ~(1 << irq);
    outb(port, value);
}
