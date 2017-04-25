##UDP or ICMP?
 * ctags how-to:
	 * ubuntu ships with the exuberant ctags,
	 * to generate ctags for cwd, run `ctags -R .`
	 * while browsing with vim, 

<table border="1" class="docutils">
<colgroup>
<col width="31%">
<col width="69%">
</colgroup>
<thead valign="bottom">
<tr><th class="head"><p class="first last">Keyboard command</p>
</th>
<th class="head"><p class="first last">Action</p>
</th>
</tr>
</thead>
<tbody valign="top">
<tr><td><p class="first last"><tt class="docutils literal"><span class="pre">Ctrl-]</span></tt></p>
</td>
<td><p class="first last">Jump to the tag underneath the cursor</p>
</td>
</tr>
<tr><td><p class="first last"><tt class="docutils literal">:ts &lt;tag&gt; &lt;RET&gt;</tt></p>
</td>
<td><p class="first last">Search for a particular tag</p>
</td>
</tr>
<tr><td><p class="first last"><tt class="docutils literal">:tn</tt></p>
</td>
<td><p class="first last">Go to the next definition for the last tag</p>
</td>
</tr>
<tr><td><p class="first last"><tt class="docutils literal">:tp</tt></p>
</td>
<td><p class="first last">Go to the previous definition for the last tag</p>
</td>
</tr>
<tr><td><p class="first last"><tt class="docutils literal">:ts</tt></p>
</td>
<td><p class="first last">List all of the definitions of the last tag</p>
</td>
</tr>
<tr><td><p class="first last"><tt class="docutils literal"><span class="pre">Ctrl-t</span></tt></p>
</td>
<td><p class="first last">Jump back up in the tag stack</p>
</td>
</tr>
</tbody>
</table>

 * navigate using `ctags`, debug with `gdb`:  
found the TYPE macro
 ![](images/probe.png)
 defintion of the macro (in scamper_trace.h):
 ![](images/snippet.png)
 (from the definition of the macro, the type is actually in the trace->type field)  
//////////////////////////////////////////////////
 
 (From further digging, we learn that trace is actually produced by `scamper_task_getdata` which takes a `scamper_task_t` pointer as argument)  
 (that is, task->data determines the trace type!)
 ![](images/invoke.png)
 //////////////////////////////////////////////////

 (And "where is the task?" you may ask, just need to find where the `do_trace_probe` is actually called)  
 ![](images/called.png)
 (the task->funcs->probe actually points to `do_trace_probe`: scamper_task.c 679)
 ![](images/snippet2.png)
  //////////////////////////////////////////////////

 (task initialized here: scamper.c 1348)
 ![](images/snippet3.png)
 //////////////////////////////////////////////////
 
 (anyway found dat madafaka: trace/scamper_trace.h 60)
 ![](images/gdbtrace.png)
 ![](images/snippet4.png)
 it's actually using Paris traceroute by defaut,
 (which makes perfect sense).
 //////////////////////////////////////////////////
 
 * A few gdb how-to s:
	 * To enter the execution flow:  
	 `(gdb) break scamper_task_probe`  
	 `(gdb) run`
	 * [The gdb cheatsheet](books/gdbcheatsheet.pdf):
		 * use `print` to inspect variables
		 * use `x/nfu` to inspect memory.
			 * n stands for number,
			 * f, format (x(hex), d(decimal), c(character))
			 * u, unit (w(double word), h(half word)), omit u when f is 'c')
			 * e.g. : `x/32c string`,`x/32xw hexvar`

 * The dst address:
 ![](images/dst.png)
 `int 1920103026` is actually the ip `114.114.114.114`.
   
 ![](images/cast.png)
 pwn!