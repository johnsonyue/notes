#node.js
---
##hello
 * REPL:
	 * REPL stands for **R**ead, **E**val, **P**rint, **L**oop
	 * its a shell for node interpreter.
			
			john$ node
			> .exit
			john$ 
			
			#node cmd gives you a prompt '>' indicating it's a shell.

 * NPM:
	 * NPM stands for **N**ode **P**ackage **M**anager.
	 * install:
		 * by default, `npm install <package-name>` performs **local** install, i.e. package content are stored in `pwd/node_modules/<package-name>`
		 * `-g` option allows you to install package **globally**
		 * **package reference**
			 * local package, use `require`,
			 * global pacage, cannot be imported using `require`, can be used in CLI directly.
	 * publish your own package.