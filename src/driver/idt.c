#include <idt.h>


void add_irq(int irq_num, unsigned short base, unsigned char flag){
    if (irq_num < 0 || irq_num > IDT_MAX_INTS)
        return -1;
    _idt[irq_num].base_low = base & 0xFFFF;
    _idt[irq_num].base_high = ((base) >> 16) & 0xFFFF;
    _idt[irq_num].reserved = 0;
    _idt[irq_num].flags = flag;
    _idt[irq_num].selector = CS
}

extern void *  irq_table[];
void idt_init(){
    for (int i = 32; i < 16; i++)
        add_irq(i, irq_table[i], INTERRUPT_GATE);
}