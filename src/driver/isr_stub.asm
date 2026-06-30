global irq_table
extern interrupt_handler

%macro isr_stub 1
isr_stub_%+%1:
	push %1
	call interrupt_handler
	add esp, 4
	iret
%endmacro

%assign i 0
%rep 48
	isr_stub i
%assign i i+1
%endrep

irq_table :
%assign i 0
%rep 48
    dd isr_stub_%+i
%assign i i+1
%endrep

