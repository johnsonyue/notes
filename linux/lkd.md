## Unix:
 * Unix V6: first widely used version.
	 * MIT XV6
 * descendants and clones include: BSD by UCB, 
	 * (`vi` in 2BSD released in 1978)
	 * 1994 released official final BSD -- 4.4BSD
	 * FreeBSD, Darwin(Macos kernel), based on 4.4BSD.
 * Customized Unix: mostly based on BSD or AT&T System V. Including: Solaris by Sun
 * Linux is not unix, doesn't use Unix code. but borrows unix's mechanism.

 * [Philosophies of Unix]() (in 张洁 book):
	 * "The Unix Philosiphy" by [LINFO](http://www.linfo.org/unix_philosophy.html)
		 * original design goal: to create an operating system that was as simple and efficient as possible
		 * one word: modularity
		 * longer: Design programs to do only a single thing, but to do it well
	 * Unix's laziness (Own thought):
      * Keeps old habbits.
      * Do one thing and do well.
      * As long as it runs.
	 * “四大笨”：万般皆文本，四处用脚本，规律无处寻，配置乱生根。
		 * PS：文本固然好，编码真烦人
		 * why plain text:
			 * flexible, concise.(comparing to GUI)
			 * human readable, transparency, universality.(comparing to binary)  
			 (worst case, if program fails to handle the text IO stream, at least you can resort to 'bio-computer', that is, to read it by yourself)
			 * program.pipeline.file.(comparing to versatility)  
			 (building block, efficient way for simple tasks)

		 * why script:
			 * laziness of programer
			 * super glue:
		 * Separate policy from mechanism  
		 (mentioned in the art of unix programming by ESR):
			 * 机制是what（目标功能），策略是how（实现方法）。
			 * 机制与策略分离导致了“规律无处寻”，即解决问题没有标准答案。
		 * Configs everywhere:
			 * 源于机制与策略分离，定制性强。
			 * Difference in Linux: make configurable **when needed**.
			 * where not needed:
				 * Autodetect: cpu cores, etc.
				 * Test pads: stats for nerds, debug for programmers, optimization switch, etc.
				 * Redundant: `ls` doesn't need a paging option bc you can simply do that by `ls | less`
	 * GrandMaster quotes: 
		 * Doug Mcllroy (inventor of pipeline):
			 * Design programs to do only a single thing, but to do it well, 
			 * and to work together well with other programs
		 * Rob Pike (C expert):
		 * ESR:
		 * Robert Love (Author of "LKD")  
			 Unix 5 strengths:
			 * concise, less syscall, clear design goal: modularity.
			 * object abstracted as file
			 * written in C, great portability
			 * fork syscall, fast process creation.
			 * simple but stable IPC