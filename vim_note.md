#vim
---
##repeat:
	var a=1
	var b=1
	var c=1
	...
	var z=1

 * To append semicolon at the end, use `A;`instead of `$a;`
 * To repeat across the range, use `:'<,'> normal A;`
 * `:%normal A;` does change to entire file. `%` == whole file.
 * `f<c>` jumps to a character, `;` jumps to next.
 * `*` to search word under cursor.

##normal mode:
 * _Much of the power of Normal mode stems from the way that operator commands can be combined with motions._
 * **_Normal mode as default explained_**: pause with your brush off the canvas.
 * **_Undo_**: undoable chunks include change in normal mode, i{insert some text}esc. best practice is to chunk insert.
 * **_cursor_**: as illustrated on terminal, begins at the left side of its underlying character. It affects motion, e.g. `db` does not delete the character under the cursor, `de` behaves otherwise.
 * **_repeatable_**: e.g. to delete the word `hig|n`, use: `daw` instead of  `dbx` or `bdw`. Reason: daw is the most repeatable combination. (dot command will only repeat the latest change, and as in `dbx` the change is `x`, and in `bdw` `dw`
 * **_arithmetic_**: `<CR>-a` increment number under cursor or next number of current line.
 * **_custom_**: check out `:h map-operator` and `:h omap-info`, to read about how to create custom operators and  motions.

##vimhistory:
 * vim is the golden child of vi family.q