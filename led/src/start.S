.section ".text.boot"

.global _start


_start:
	b reset
	ldr pc, _undefined_instruction
	ldr pc, _software_interrupt 
	ldr pc, _prefetch_abort
	ldr pc, _data_abort
	ldr pc, _not_used
	ldr pc, _irq
	ldr pc, _fiq

_undefined_instruction: .word undefined_instruction 
_software_interrupt: .word software_interrupt
_prefetch_abort: .word prefetch_abort
_data_abort: .word data_abort
_not_used: .word not_used
_irq: .word irq
_fiq: .word fiq



reset:
	bl clear_bss
	ldr sp, =_estack
	bl main
	

clear_bss:
	ldr r0, = __bss_start
	ldr r1, = __bss_end
	mov r2, #0x00000000
clbss_l:cmp     r0, r1
	strlo   r2, [r0]
	addlo   r0, r0, #4
	blo     clbss_l
	mov pc,lr
	
