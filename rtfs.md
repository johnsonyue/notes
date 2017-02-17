##boot.s & head.s
 * mm image:
![](images/boot&head.jpg)
 * [PIT chip](http://wiki.osdev.org/Programmable_Interval_Timer) (8253):
	 * The PIT chip uses the following I/O ports:


			I/O port     Usage
			0x40         Channel 0 data port (read/write)
			0x41         Channel 1 data port (read/write)
			0x42         Channel 2 data port (read/write)
			0x43         Mode/Command register (write only, a read is ignored)

	 * The Mode/Command register at I/O address 0x43 contains the following:


			Bits         Usage
			6 and 7      Select channel :
			             0 0 = Channel 0
			             0 1 = Channel 1
			             1 0 = Channel 2
			             1 1 = Read-back command (8254 only)
			4 and 5      Access mode :
			             0 0 = Latch count value command
			             0 1 = Access mode: lobyte only
			             1 0 = Access mode: hibyte only
			             1 1 = Access mode: lobyte/hibyte
			1 to 3       Operating mode :
			             0 0 0 = Mode 0 (interrupt on terminal count)
			             0 0 1 = Mode 1 (hardware re-triggerable one-shot)
			             0 1 0 = Mode 2 (rate generator)
			             0 1 1 = Mode 3 (square wave generator)
			             1 0 0 = Mode 4 (software triggered strobe)
			             1 0 1 = Mode 5 (hardware triggered strobe)
			             1 1 0 = Mode 2 (rate generator, same as 010b)
			             1 1 1 = Mode 3 (square wave generator, same as 011b)
			0            BCD/Binary mode: 0 = 16-bit binary, 1 = four-digit BCD

		 * For the "lobyte/hibyte" mode, 16 bits are always transferred as a pair, with the lowest 8 bits followed by the highest 8 bits (both 8 bit transfers are to the same IO port, sequentially -- a word transfer will not work).

 * code in head.s:
	 * TS (task switching) scenarios:
		 * call/jmp (tss descriptor)
		 * call/jmp (task gate)
		 * interrupt (task gate)
		 * iret NT
	 * constrol transfer in head.s:
		 1. kernel --> user task0 (task switching):

				NT <- $0
				TR <- $TSS0_SEL
				LDTR <- $LDT0_SEL
				push 0x17:$init_stack
				push 0x0f:$task0
				iret
			 * iret requires stack switching, hence push 0x17:$init_stack,
			 * init_stack serves as usr_stk0
		 2. user task0/1 --> timer_interrupt (interrupting):
			 * cpl=3 < dpl=0, requires stack switching
			 * swtiches to krn_stk0 provided by tss0.
			 ![](images/interrupt_stack.png)
			 (**processor automatically**) pushes ss:esp, eflags, and cs:eip.
			 * because task switching in "1." is done by `iret`, **processor automatically** resets nt in eflags.
		 3. timer_interrupt --> user task1/0 (normal interrupt returning):
			 * for reasons described in "2.", nt=0,
			 * `iret` in timer_interrupt simply returns without switching task.