#IA32 data structure
---
##system registers:
 * EFLAGS (`reg`):
![](images/eflags.png)
 * mmregs (`sreg`):
![](images/mmregs.png)
 * cregs (`creg`):
![](images/cregs.png)
 * system instructions:
	 * instructions to manipulate system registers.

##memory management:
 * address transformation:
![](images/address_transform.png)
 * selector:
![](images/selector.png)
	 * RPL (Requested Privilege Level)
	 * TI (Table Index)
 * descriptor:
	 * segment descriptor:
![](images/descriptor.png)
	 * call gate descriptor:
![](images/callgate.png)
	 * (interrupt, trap, task) gate descriptor:
![](images/interrupt.png)
	 * tss descriptor:
![](images/tss_descriptor.png)
 * page_item:
![](images/page_item.png)