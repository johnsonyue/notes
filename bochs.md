#bochs setup:
---
##compile on Mac OS X:
 * `configure` generates Makefile as input of `make`  
   `make` does selective compile, i.e. it does not compile unchanged code again.  
   `make clean-all` deletes all '.o' files in $install_dir including subdirs. `make clean` excludes subdirs.

 * compile:
		
		#export CLICOLOR=1 to enable terminal color.
		john$ gunzip -c bochs-2.6.8.tar.gz | tar xvf -
		john$ cd bochs-2.6.8/
		john$ brew install sdl
		john$ ./configure --enable-ne2000 \
            --enable-all-optimizations \
            --enable-cpu-level=6 \
            --enable-x86-64 \
            --enable-vmx=2 \
            --enable-pci \
            --enable-usb \
            --enable-usb-ohci \
            --enable-e1000 \
            --enable-debugger \
            --enable-disasm \
            --disable-debugger-gui \
            --with-sdl \
            --prefix=$HOME/opt/bochs
		#export BXSHARE="$HOME/opt/bochs/share/bochs"
		#export PATH="$PATH:$HOME/opt/bochs/bin"

##hello, bochs:
 * using book's tinix:

		john$ cd $TINIX/chapter1/b/
		john$ bochs -f bochsrc.bxrc
		
		#on debug console:

		========================================================================
		                       Bochs x86 Emulator 2.6.8
		                Built from SVN snapshot on May 3, 2015
		                  Compiled on Jan 20 2017 at 01:34:54
		========================================================================
		00000000000i[      ] BXSHARE is set to '/Users/john/opt/bochs/share/bochs'
		00000000000i[      ] reading configuration from bochsrc.bxrc
		------------------------------
		Bochs Configuration: Main Menu
		------------------------------
		
		This is the Bochs Configuration Interface, where you can describe the
		machine that you want to simulate.  Bochs has already searched for a
		configuration file (typically called bochsrc.txt) and loaded it if it
		could be found.  When you are satisfied with the configuration, go
		ahead and start the simulation.
		
		You can also start bochs with the -q option to skip these menus.
		
		1. Restore factory default configuration
		2. Read options from...
		3. Edit options
		4. Save options to...
		5. Restore the Bochs state from...
		6. Begin simulation
		7. Quit now
		
		Please choose one: [6] 6
		00000000000i[      ] installing sdl module as the Bochs GUI
		00000000000i[SDL   ] maximum host resolution: x=2560 y=1600
		
		00000000000i[      ] using log file bochsout.txt
		Next at t=0
		(0) [0x0000fffffff0] f000:fff0 (unk. ctxt): jmpf 0xf000:e05b          ; ea5be000f0
		<bochs:1>
		
		#press c to continue.
		
	=
		#meanwhile on sdl window:
	![hellobochs](images/hellobochs.png)
* see the Red "Hello"? it works!