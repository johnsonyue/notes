extern inline int strncmp(const char* cs, const char* ct, int count){
	register int _res;
	_asm_("cls\n"
	      "1:\tdecl %3\n\t"
	      "js 2f\n\t"
	      "lodsb\n\t"
	      "scasb\n\t"
	      "jne 3f\n\t"
	      "testb %%al, %%al\n\t"
	      "jne 1b\n"
	      "2:\txor1 %%eax,%eax\n\t"
	      "jmp 4f\n"
	      "3:\tmovl $1, %%eax\n\t"
	      "jl 4f\n\t"
	      "negl %%eax\n"
	      "4:"
	      :"=a" (_res):"D" (cs),"S" (ct),"c" (count):"si","di","cx");
	return _res;

int main(){
	printf ("%x\n",strncmp("hello", "hallo", 4));
	return 0;
}
