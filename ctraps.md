#C Traps and Pitfalls:
---
## organization:
 * compiler:
	 * lexical
	 * syntactic
	 * semantic
 * preprocessor
 * linkage
 * libs
 * portability

## intro:
 * Traps focus on technically correct problems, i.e. **programming errors**.
	 * That is, Code which can compile but not working as intended, 
	 * Program which departs from the programmer's mental model.
 * example #1:
		
		//program will go into a infinite loop,
		//on some C implementations.
		#define N 20

		void loop(){
		        int i;
		        int a[N];
		
		        for (i = 0; i <= N; i++){
		                a[i] = 0;
		        }
		}
		
		int main(){
		        loop();
		
		        return 0;
		}

##lexical:
 * lexical analysis in C compiler:
	 * analyer scans stream, convert text into **tokens** (tokens to program is like words to Natural language)
	 * greedy lexical strategy:
		 * while scanning always take the longest possible token each time.
 * example #3:
	 * nested comment:

			#take a look at the statement:
			/*/*/0*/**/1
			
			#evals rules:
			#always use greedy lexical strategy
			#if using nested comment:
			#   texts after open comment token /*,
			#   even /* itself are ignored.
			#else:
			#   /* is not ignored, hence "nested comment"
			
			#if nested, statement evals to:
			/* /* /0 */ * */ 1
			#which evals to:
			1
			
			#if not nested, statement evals to:
			/* / */ 0 * /* */ 1
			#which evals to 0*1, which is:
			0
			
 * example #2:
	 * `""` vs `''`:

		//wrong:
		printf('\n')
		//character enclosed in single quote <==> int ascii value
		//string enclosed in double quote <==> pointer to a nameless char array

##syntactic:
 * syntactic analysis in C compiler:
	 * declaration:
		 * two parts: (1) a type, and (2) a list of declarators.
		 * connotation:
			 * a declarators is in the form of a expression, 
			 * declaration `float f,g` indicates that the "expression" `f` and `g` when evaluated, will be of type `float`
	 * cast:
		 * to cast some value into desired type,
		 * simply remove the variable name from the declarator
			
 * function call:
	 * common functions calls `func();`, 
	 * are actually **abbreviations**, which is short for `(*func)()`,
	 * essentially, `func` is the pointer to the function, `(*func)` is the function itself (yes, function is a type!!), parenthesis `()` is the way to invoke the function.
 * example #5:

		//call a routine at address 0.
		(*(void(*)())0)();
		
		//to devise such a statement in two stages.
		//step 1, function call.
		(*0)();
		
		//step 2, cast.
		//casting is necessary, because \
		//(1) caller must be a function pointer, \
		//(2) * operator must operate on a pointer.
		//The cast should be (void (*)())
		(* (void (*)()) 0)()
		
		//a equivalent form using typedef.
		typedef void (*void_func_ptr)();
		(*(void_func_ptr)0)();

 * a **semicolon** `;` is compulsory at the end of a **struct definition**.
 * **switch statement**:  
	 * will flow in next case without `break;` statement.