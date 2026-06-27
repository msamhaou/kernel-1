


irq_table :
%assign i 32
%rep 16
    dd isr_stub_%+i
%assign i i+1
%endrep

