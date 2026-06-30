#ifndef IDT_H
	#define IDT_H

#define IDT_MAX_INTS 256

#define PRESENT		0X1
#define DPL			0x00
#define	GATE_SIZE	0x0
#define GATE_TYPE	0xE
#define CS          0x08
#define INTERRUPT_GATE	PRESENT << 7 | DPL << 5 | GATE_SIZE << 4 | GATE_TYPE

struct idt_entry {
    unsigned short	base_low;
    unsigned short	selector;
    unsigned char reserved;
    unsigned char	flags;
    unsigned short	base_high;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short	limit;   
    unsigned int	base;
}__attribute__((packed));

static struct idt_entry _idt[256];

static struct idt_ptr idt_p =
{
	.limit = (sizeof(struct idt_entry) * IDT_MAX_INTS) - 1,
	.base = (unsigned int)(&_idt[0])
};

void idt_init();
void interrupt_handler(unsigned int num);
static unsigned short	get_current_code_segment(void);
#endif

