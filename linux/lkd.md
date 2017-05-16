## Unix:
 * Unix V6: first widely used version.
	 * MIT XV6
 * variants include: BSD by UCB, 
	 * (`vi` in 2BSD released in 1978)
	 * 1994 released official final BSD -- 4.4BSD
	 * FreeBSD, Darwin(Macos kernel), based on 4.4BSD.
 * Customized Unix: mostly based on BSD or AT&T System V. Including: Solaris by Sun

 * [Philosophies of Unix]() (in 张洁 book):
	 * Unix's laziness:
      * Keeps old habbits.
      * Do one thing at a time and do well.
      * As long as it runs.
	 * “四大笨”：万般皆文本，四处用脚本，规律无处寻，配置乱生根。
		 * PS：文本固然好，编码真烦人
		 * why text:
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
		 * Rob Pike (C expert):
		 * ESR: