#ifndef PIC_H
	#define PIC_H

#define MASTER 			0x20
#define SLAVE    		0xA0
#define MASTER_COMMAND    MASTER
#define MASTER_DATA       (MASTER + 1)
#define SLAVE_COMMAND    SLAVE
#define SLAVE_DATA       (SLAVE + 1)

#define ICW1_ICW4		0x01		/* Indicates that ICW4 will be present */
#define ICW1_SINGLE		0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL		0x08		/* Level triggered (edge) mode */
#define ICW1_INIT		0x10		/* Initialization - required! */

#define ICW4_8086		0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO		0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM		0x10		/* Special fully nested (not) */

#define	IRQ0			0X20
#define IRQ8			IRQ0 + 8
#define CASCADE_IRQ		2

#define PIC_EOI		0x20

extern unsigned char inb(unsigned short port);          
extern void outb(unsigned short port, unsigned char b); 
extern void io_wait();                                  

void pic_remap();
void	PIC_sendEOI(unsigned char irq);
void	IRQ_clear_mask(unsigned char irq);
#endif // !PIC_
