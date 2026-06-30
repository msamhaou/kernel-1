
section .text
global outb
global inb
global io_wait


outb:
	push ebp
	mov ebp, esp
	mov edx, [ebp + 8]
	mov eax, [ebp + 12]
	out dx, al
	
	pop ebp
	ret

inb:
	push ebp
	mov ebp, esp
	mov edx, [ebp + 8]
	xor eax, eax
	in al, dx
	pop ebp
	ret


io_wait:
    push ebp
    mov ebp, esp
    xor eax, eax  
    mov edx, 0x80 
    out dx, al    
    pop ebp
    ret
