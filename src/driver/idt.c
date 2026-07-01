#include <idt.h>
#include <utils.h>
#include <pic.h>

int add_irq(int irq_num, unsigned int base, unsigned char flag){
    _idt[irq_num].base_low = base & 0xFFFF;
    _idt[irq_num].selector = get_current_code_segment();
    _idt[irq_num].reserved = 0;
    _idt[irq_num].flags = flag;
	_idt[irq_num].base_high = ((base) >> 16) & 0xFFFF;

}

extern void *  irq_table[];
void idt_init(){
    for (int i = 0; i < 48; i++)
        add_irq(i, (unsigned int)irq_table[i], INTERRUPT_GATE);
	IRQ_clear_mask(0);
    IRQ_clear_mask(1);

	__asm__ volatile ("lidt %0" : : "m"(idt_p));    
    __asm__ volatile ("sti");

}


static unsigned short	get_current_code_segment(void) {
	unsigned short	cs;
	__asm__ volatile("mov %%cs, %0" : "=r"(cs));
	return cs;
}

void interrupt_handler(unsigned int irq){
	if (irq == 32)
	{
		PIC_sendEOI(0);
	}else if (irq == 33){
		keyboard_scan();
		PIC_sendEOI(1);
	}
	return;
}
