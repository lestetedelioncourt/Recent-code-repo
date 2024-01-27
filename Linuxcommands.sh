#gdb commands
 - b 7 				# creates breakpoint at line &
 - b main 			# creates breakpoint at function main
 - info breakpoints # will list all breakpoints created so far
 - delete 2 		# would delete the 2nd breakpoint
 - step             # will execute the next line of code, but will step into function
 - next 			# will execute the next line of code, but step over the function
 - r arg1 arg2      # will run the program with command line arguments
 - bt 				# or backtrace provides the stack trace, will list last call at each stack frame
 - frame 3 			# will switch the context to stack frame 3
 - list 10 			# will list the code present on line 10 (of current context stack frame)
 - p buf			# will print value of variable provided
 - p (int*) i 		# will print address of int
 - p sizeof(i)		# will print size of i 
 - p sizeof(&i)		# will print size of i's address (8 bytes in 64-bit machine)
 - p /o i			# will print in octal
 - p /x i 			# will print in hexadecimal
 - help x 			# will return the various formats available for print commands i.e. /t for binary
 - x /x &i 			# will return value at address of i in hexadecimal format (x stands for examine)
 - x/4xb &i 		# will examine 4 vlues formatted as hex numerals, returned one byte at a time, Intel returns in little endian, least significant byte to most
 - ptype i 			# will print the type of the variable
 - ptype s          # returns char[13]
 - x/s msg			# will print the string value of s 
 - set msg="Hello"	# set command will change the value of the msg variable within the gdb debugger
 - bt 				# backtrace can provide a list of stack frames during program execution allowing you to switchh frame context and look at variables in each frame
 - info frame 0		# will provide
 - info variables 	# will list all library variables
 - info locals 		# will list all the local variables in the current stack frame context
 - info args		# will list all the arguments give to the current stack frame context
 - info registers  	# will list all the values currently contained in the registers (3 columns, name of register, value of registe in hexadecimal, value in decimal)
 - i r rbx 			# gives the value stored in a particular register
 - b 22 if i==5		# conditional breakpoint
 - i b 				# returns numbered list of breakpoints and watchpoints
 - cond 2 i==4 		# adds a condition to breakpoint number 2 in the list
 - watch x			# adds a watchpoint which breaks if the value of the variable x on the local stack frame has changed
 - rwatch x			# adds a watchpoint with breaks if there is a read on local variable x
 - awatch x			# adds a watchpoint which breaks if there is a read or write on local variable x
 - CTRL+x CTRL+a 	# boots text user interface if booted gdb without tui enabled
 - list ${lineno.}	# will navigate to the correct line of the text user interface
 - set logging on 	# will save all output from this point into a file called gdb.txt
 - set logging off 	# will turn off logging
 - set logging file filename	# will save all output into the filename specified
 - shell ps aux     # shell allows you access to shell commands
 - attach pid		# will attach gdb to a running process
 - disassemble main # shows assembly language instructions for main function
 - start			# starts the program and places automatic breakpoint on the first line of main (equivalent of 'b main' and 'run') 
 - where			# show where the program crashed.
 - attach <pid>		# following commands will generate a coredump file called core.<pid>
   generate-core-file
   detach
 - 
	
 From command line 
 001. gdb --args ./binaryfile 3  	# allows the passing in of commandline arguments
 002. gdbtui ./binaryfile 			# for text user interface
 003. gdb --tui ./binaryfile 		# for text user interface
 004. man setrlimit 				# each process has various limits associated with it
 005. ulimit -a 					# lists all default limits on the machine
 006. ulimit -c unlimited			# specifies the size of the coredump file to be unlimited (is initially 0, which means no coredumps)
 007. gdb binaryfile corefile		# to look at a coredump
 008. kill -s SIGABRT <pid>			# will also generate a coredump if not caught by signal handler (or the user can call abort() from within the program itself)
 
 Valgrind commands
 009. sudo apt install -y valgrind
 010. valgrind --tool=memcheck --leak-check=yes binaryfile 							# will summarise where leaks are being lost 
 011. valgrind --tool=memcheck --leak-check=yes --track-origins=yes binaryfile 		# will show where uninitialised values come from
 
 strace
 012. strace program_name 			# ex. strace ls - writes to stderr not stdout, to redirect output use 2>
 013. strace -p <pid>				# attaches strace to a running process
 014. gcc 1.c -o 1 --static 		# causes executable to only use static libraries, not dynamic (will not use map C libraries into memory, i.e. MMAP/READ OPERATIONS)
 015. ldd ./1						# ldd prints the shared objects (shared libraries) required by each program or shared object on the command line.
 016. strace -o output program		# prints the strace output directly to a file
 017. vimdiff outfile1 outfile2		# shows side by side diff comparison of two files 
 018. strace -c program 			# will show a table of system calls, along with how long each took, and percentage of time used 
 019. strace -C program 			# will show the above output along with the normal output of an strace call 
 020. strace -t program				# will show timestamp in seconds
 021. strace -tt program			# will increase resolution to microseconds
 022. strace -ttt program 			# will show number of seconds since 1 Jan 1970
 023. strace -T program 			# The amount of time spent on each system call
 024. strace -f fork				# will also track child processes 
 025a. ./program &
 025b. fg 											# running fg after running a program in the background causes it to come to the foreground
 026. strace -e trace=openat,close program_name 	# will only trace the specific calls listed, in this case open and close
 027. strace -e trace=ipc							# Following track call by system group, track communication between processes  
	  strace -e trace=memory						# Track memory syscalls
	  strace -e trace=network						# Track network syscalls
	  strace -e trace=process						# Track process syscalls (like forke, exec, etc.)
	  strace -e trace=signal						# Track process signal handling (like HUP, exit)
	  strace -e trace=file							# For syscalls that mention filenames
	  strace -e trace=desc							# For read() and write() and friends, which mention file descriptors
 028. strace -e keyword program						# More or less greps the output for the term defined after -e
 029. strace -s 80 program							# will print first 80 characters of every string as opposed to default(32) 
 030. ltrace ./exec <params>						# 
 031. ltrace -e malloc ./exec						# -e will grep output for search term 
 032. sudo dmesg -c 								# will output all kernel messages sent to the log files since the kernel booted
 033a. cd /lib/modules/<v.0>/kernel 				# directory containing kernel files
 033b. find -name "*.ko" -type "f"  				# will find all kernel object files (kernel modules) | wc -l to get a line count
 034. cd /boot
	  cat config-`uname -r`	| less					# contents of config file presenly loaded 
      cat config-`uname -r` | grep "CONFIG_MODULES"	# kernel modules
 035a. cd kernelmoduledirectory && cat Makefile		# ls /lib/modules/`uname -r`/build/Makefile looks for this makefile which defines it as a kernel modules
						- obj-m := hello.o			# defines hello.o as a kernel module (obj-y for one built into the kernel itself)
 035b. make -C /lib/modules/`uname -r`/build M=${PWD} modules 		# make command for kernel module which uses makefile defined in kernel module directory  
 035c. ls 											# should now show a variety of files including a .ko kernell object file
 035d. modinfo ./hello.ko							# will show modinfo on kernel 
 035e. sudo insmod ./hello.ko						# insmod is a simple program to load a module into the kernel, doesn't calculate or load dependencies
 035f. lsmod | less 								# last loaded module will be first present in list
 035g. ls /sys/module/hello							# should now be present
 035h. su rmmod hello								# removes the module
 035i. dmesg										# dmesg should show printk() statements from initialization and exit functions
 035j. make -C /lib/modules/`uname -r`/build M=${PWD} clean 		# will remove all the files which were generated
 036. make ARCH=arm CROSS_COMPILE=arm-buildroot-linux-uclibcgnueabi- -C /pathtolinuxkernelsourecode M=${PWD} modules		# command for building for ARM
 037. cat Makefile 									# in order to change the output file use filename-objs := as a rule. file.c is compiled to file.o - file.mod.o
		-> obj-m := linux.o							  contains information about the module, file.o and file.mod.o are linked together by modpost to create file.ko
		-> linux-objs := hello.o					  file.symvers will also be output and contains external symbols defined in your module, not present in module.symvers
		->											  of the kernel. file.order will list out the order in which the compilation and creation of .ko takes
		-> all:
		->     make -C /lib/modules/`uname -r`/build M=$(PWD) modules
		-> clean:
		->     make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
 038. cat Makefile 									# in order to change the output file  
		-> obj-m := newlinux.o							
		-> newlinux-objs := hello.o func.o				# Using multiple C files for a kernel module
		-> 
		-> all:
		->     make -C /lib/modules/`uname -r`/build M=$(PWD) modules
		-> clean:
		->     make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
 038. cat Makefile 									# in order to change the output file (doesn't work with newlinux.o as obj-m argument ) 
		-> obj-m := hello1.o							 
		-> obj-m += hello2.o						# Produces two kernel objects from a single Makefile (can only load one module at a time -insmod)
 038. cat Makefile 									
		-> obj-m := hello1.o hello2.o				# Produces two kernel objects from a single Makefile (can remove two modules at a time -rmmod)	
 039. dmesg -c 										# will clear the ring buffer, output to stdout, boot logs stored in kernel ring buffer until syslog daemon collects and stores in /var/log/dmesg
 040. dmesg -C 										# will clear the ring buffer, but no output to console
 041. dmesg -t  									# will not print timestamps
 042. dmesg -l err,warn								# will restrict kernel messages to those with log level err and warn (alert, warn, crit, err, segfault - see man dmesg)
 043. dmesg -T 										# print human readable timestamp
 044. dmesg -xT										# -x adds log level to output. 
 045. dmesg -w 										# similar to tail -f, will track ring buffer
      # if no exit module in kernel code, will be able to build using make and load using insmod but cannot use rmmod to unload the module,
	  # if no init module in kernel code, will be able to build using make and loading with insmod will not throw an error, lsmod will reveal the module is loaded
	    can then be unloaded using rmmod, thus completely fine to have a module with no init function
	  # with no init and exit functions will still be able to load and unload the module. No errors will be thrown
 046. man modprobe  								# modprobe only loads modules in /lib/module`uname -r`. 
 047. man depmod   									# It calculates then loads dependencies using depmod tool which generates module.dep and map files
 048. cd /lib/modules/`uname -r` && vi modules.dep 	# will show modules and their dependencies, thus depmod loads from right to left
 049. depmod -a 									# Can reload modules.dep file by using depmod -a
 050. cat arguments.c
      > #include <linux/kernel.h>
      > #include <linux/module.h>
      > 
      > /*	We can add parameters using module_param macro declared in moduleparam.h file
      > 	#define module_param(name, type, perm)
      > 		 module_param_named(name, name, type, perm)
      > 
      > 	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
      > 	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort  
      > 	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
      > 	You can also use numeric values like 0644 for permission entry
      > */
      > 
      > MODULE_LICENSE("GPL");
      > char *name = "Embedded";
      > int loop_count = 1;
      > module_param(name, charp, S_IRUGO);
      > module_param(loop_count, int, S_IRUGO);
      > 
      > static int test_arguments_init(void)
      > {
      >     int i;
      > 	printk(KERN_INFO"%s: In init\n", __func__);
      > 	printk(KERN_INFO"%s: Loop Count:%d\n", __func__, loop_count);
      > 	for (i = 0; i < loop_count; i++)
      > 		printk(KERN_INFO"%s: Hi %s\n", __func__, name);
      > 	return 0;
      > }
      > 
      > static void test_arguments_exit(void)
      > {
      > 	printk(KERN_INFO"%s: In exit\n", __func__);
      > }
      > 
      > module_init(test_arguments_init);
      > module_exit(test_arguments_exit);
      > MODULE_AUTHOR("LESLIE");
      > MODULE_DESCRIPTION("Argument Passing Example");
 051. cat arguments.c
      > #include <linux/kernel.h>
      > #include <linux/module.h>
      > 
      > /*	We can add parameters using module_param macro declared in moduleparam.h file
      > 	#define module_param(name, type, perm)
      > 		 module_param_named(name, name, type, perm)
      > 
      > 	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
      > 	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort  
      > 	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
      > 	You can also use numeric values like 0644 for permission entry
      > */
      > 
      > MODULE_LICENSE("GPL");
      > char *name = "Embedded";
      > int loop_count = 1;
      > module_param(name, charp, S_IRUGO);
      > module_param(loop_count, int, S_IRUGO);
      > 
      > static int test_arguments_init(void)
      > {
      >     int i;
      > 	printk(KERN_INFO"%s: In init\n", __func__);
      > 	printk(KERN_INFO"%s: Loop Count:%d\n", __func__, loop_count);
      > 	for (i = 0; i < loop_count; i++)
      > 		printk(KERN_INFO"%s: Hi %s\n", __func__, name);
      > 	return 0;
      > }
      > 
      > static void test_arguments_exit(void)
      > {
      > 	printk(KERN_INFO"%s: In exit\n", __func__);
      > }
      > 
      > module_init(test_arguments_init);
      > module_exit(test_arguments_exit);
      > MODULE_AUTHOR("LESLIE");
      > MODULE_DESCRIPTION("Argument Passing Example");
 052. cat arguments.c
      > #include <linux/kernel.h>
      > #include <linux/module.h>
      > 
      > /*	We can add parameters using module_param macro declared in moduleparam.h file
      > 	#define module_param(name, type, perm)
      > 		 module_param_named(name, name, type, perm)
      > 
      > 	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
      > 	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort  
      > 	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
      > 	You can also use numeric values like 0644 for permission entry
      > */
      > 
      > MODULE_LICENSE("GPL");
      > char *name = "Embedded";
      > int loop_count = 1;
      > module_param(name, charp, S_IRUGO);
      > module_param(loop_count, int, S_IRUGO);
      > 
      > static int test_arguments_init(void)
      > {
      >     int i;
      > 	printk(KERN_INFO"%s: In init\n", __func__);
      > 	printk(KERN_INFO"%s: Loop Count:%d\n", __func__, loop_count);
      > 	for (i = 0; i < loop_count; i++)
      > 		printk(KERN_INFO"%s: Hi %s\n", __func__, name);
      > 	return 0;
      > }
      > 
      > static void test_arguments_exit(void)
      > {
      > 	printk(KERN_INFO"%s: In exit\n", __func__);
      > }
      > 
      > module_init(test_arguments_init);
      > module_exit(test_arguments_exit);
      > MODULE_AUTHOR("LESLIE");
      > MODULE_DESCRIPTION("Argument Passing Example");
 052. sudo insmod ./arguments.ko loop_count=5 name="Linux"	# will insert module with new definitions for arguments (away from default ones already defined)
 053. ls /lib/module/arguments/parameters					# will return files name and loop_count which represent variables, and are reead only to all users (S_IRUGO)
 054. cat /lib/module/arguments/parameters/loop_count		# will return 5
 # if you pass incorrect types will not insert the module correctly and will return an error
 # if parameter has the right permissions, you can see it via the command
 055. <module_name>.<parameter_name>=value					# will set param to value
 056. ls -l /sys/module/*/parameters						# will list parameters present
 # In order to pass in a multiword string such as "Hello World" as a parameter must first use sing then double quotes, i.e name='"Hello World"'
 057. cat array_arguments.c
       > #include <linux/kernel.h>
       > #include <linux/module.h>
       > #include <linux/moduleparam.h>
       > 
       > /*	We can add multiple parameters using module_param_array macro declared in moduleparam.h file
       > 	#define module_param_array(name, type, nump, perm)
       > 		 module_param_named(name, name, type, perm)
       > 
       > 	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
       > 	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort
       > 	nump: optional pointer filled in with the number written
       > 	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
       > 	You can also use numeric values like 0644 for permission entry
       > */
       > 
       > MODULE_LICENSE("GPL");
       > int param_array[4];
       > static int argc_count = 0;
       > module_param_array(param_array, int, &argc_count, S_IWUSR|S_IRUSR);
       > 
       > static int test_arguments_init(void)
       > {
       >     int i = 0;
       > 	printk(KERN_INFO"%s\n", __func__);
       > 	printk(KERN_INFO"%s: argc Count:%d\n", __func__, argc_count);
       > 	for (i = 0; i < sizeof(param_array)/sizeof(param_array[i]); i++)
       > 		printk(KERN_INFO"%d: %d\n", i, param_array[i]);
       > 	return 0;
       > }
       > 
       > static void test_arguments_exit(void)
       > {
       > 	printk(KERN_INFO"%s: In exit\n", __func__);
       > }
       > 
       > module_init(test_arguments_init);
       > module_exit(test_arguments_exit);
       > MODULE_AUTHOR("LESLIE");
       > MODULE_DESCRIPTION("Argument Passing Example");
 # A symbol refers to either data (in the form of a variable) or a functio
 058. cd /boot/ && sudo cat -n System.map-`uname -r`	# outputs symbol mapping (kernel symbol table) for linux image, always present in /boot/System.map-<linux_version>
 # In order to export a symbol to be used by any kerlnel module use EXPORT_SYMBOL or EXPORT_SYMBOL_GPL which allows it to be used only by GPL licensed code
 059. sudo cat -n /proc/kallsyms						# also outputs symbol table, appears to have more entries that previous command (#58)
 # /boot/System.map-`uname -r` is generated when kernel is compiled, /proc/kallsyms is dynamic and is updated with the symbols of dynamically loaded modules
 # Module stacking uses symbols exported by old modules, an example is the MS-DOS filesystem which relies on symbols exported by the FAT module
 # Parallel port printer driver (lp) relies on symbols exported by generic parallel port driver (parport)
 060. cat module1.c
       > #include <linux/kernel.h>
       > #include <linux/module.h>
       > 
       > MODULE_LICENSE("GPL");
       > 
       > int myadd(int a, int b)
       > {
       > 	pr_info("%s: Adding: %d\ with %d\t Result:%d\n", __func__, a, b, a+b);
       > 	return a+b;
       > }
       > 
       > EXPORT_SYMBOL(myadd);
       > static int module1_init(void)
       > {
       > 	pr_info("%s: In init\n", __func__);
       > 	return 0;
       > }
       > 
       > static void module1_exit(void)
       > {
       > 	pr_info("%s: In exit\n", __func__);
       > }
       > 
       > module_init(module1_init);
       > module_exit(module1_exit);
 061. cat module2.c
       > #include <linux/kernel.h>
       > #include <linux/module.h>
       > 
       > MODULE_LICENSE("GPL");
       > 
       > extern int myadd(int a, int b);
       > 
       > static int module2_init(void)
       > {
       > 	pr_info("%s: In init\n", __func__);
       > 	pr_info("%s: Add:%d\n", __func__, myadd(3, 5));
       > 	return 0;
       > }
       > 
       > static void module2_exit(void)
       > {
       > 	pr_info("%s: In exit\n", __func__);
       > }
       > 
       > module_init(module2_init);
       > module_exit(module2_exit);
 062. cat Makefile 
		> obj-m := module2.o
		> obj-m += module1.o
 063. sudo insmod ./module2.ko									# stderr= insmod: ERROR: could not insert module ./module2.ko: Unknown symbol in module 
 063a. sudo insmod ./module1.ko && sudo insmod ./module2.ko		
 # In order to use modprobe (loads dependecies) must create symbolic (soft) links to the modules in question
 064a. sudo ln -s ${PWD}/module1.ko /lib/modules/`uname -r`/kernel/drivers/misc
 064b. sudo ln -s ${PWD}/module2.ko /lib/modules/`uname -r`/kernel/drivers/misc
 064c. sudo depmod -a															# will create entries for module2.ko and module1.ko in /lib/modules/`uname -r`/modules.dep (dependencies file) 
 064d. sudo modprobe module2 
 064e. lsmod | grep module   --OR--  dmesg  									# either should show that module1 was automatically loaded as a dependency of module2
 065. sudo modprobe -r module2													# will remove both modules from module dependencies file /lib/modules/`uname -r`/modules.dep
 # Vermagic is a magic string present in the Linux Kernel and added into the .modinfo section of the Linux Kernel Modules, verifies whether kernel module was compiled for specific kernel version
 # 'VERMAGIC_STRING is a macro generated by the kernel configuration
 # Building a linux module without a license results in a build error, specifig that the module license was unspecified
 # If usuing an older version of the kernel, loading a kernel module without a license results in a tainted kernel, that is a state not supported by the community.
 # If using a newer version of linux can taint the kernel by providing an arbitrary string in the MODULE_LICENSE() macro
 066. cat /proc/sys/kernel/tainted     											# Example output 12288  = G           OE   see https://kernel.org/doc/html/latest/admin-guide/tainted-kernels.html
																				# Example output 12289  = P           OE 
 067. make V=1 																	# provides more verbose information in the make output
 068. cat Module.symvers														# Provides all the symbols exported from the module, and related information
		> 0xfc05b364	myadd	/home/generic/KernelModulesDeviceDrivers/nonGPL-GPLaccess/module1	EXPORT_SYMBOL
 069. modinfo ./name.ko 														# vermagic string will give the version of the kernel this module was built for
 # Module metadata can be added using the macros MODULE_DESCRIPTION, MODULE_AUTHOR, MODULE_VERSION, can be seen by using modinfo on the ko file
 # retpoline is also present and was introduced as a solution to the Spectre bug (which affected intel chips), Y indicates it is enabled
 # srcversion is an MD4 hash of the source code used to compile tjhe kernel module. It is calculate automatically at build time from the modpost script, and verifies which ko file you are using
 # intree is also contained in the modinfo output and is only present for intree modules
 # vermagic is checked when loading a module. If the strings contained in vermagic do not match will get an error and module will not load
 # the MODULE_ALIAS macro makes a call to MODULE_INFO in the kernel source code. Any generic information can be generated and accessed via modinfo by using the MODULE_INFO macro
 # The first parameter passed to the MODULE_INFO macro is the tag you wish to use for the information, and the second is it's value i.e. MODULE_INFO(OS, Linux)
 070. file ./hello.ko				# ko files are generated as ELF files (Electronic Linkable Format)
		> ./hello.ko: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), BuildID[sha1]=30361e0a85963318730fbbd5ab9194a040d707d2, with debug_info, not stripped
 071. objdump --section-headers ./hello.ko			# An ELF file consists of several named sections, some of them are basic parts of an object file, for example the .text contains executable code that a loader loads   
 072. objdump --section-headers --section=.modinfo ./hello.ko		# will dump the section specified
 # printk is initialised using a ring uffer with a size of __LOG_BUF_LEN bytes which is (1 << CONFIG_LOG_BUF_SHIFT) this can be found via
 073. cat /boot/config-`uname -r` | grep CONFIG_LOG_BUF_SHIFT		# output in this case is "CONFIG_LOG_BUF_SHIFT=18"
 # To increase the buffer size 
 074. log_buf_len=4M				# Would increase ring buffer size for Kernel to 4MB, updates the bootloader options, does not require kkernel to be recompiled
 # There are eight possible loglevel strings, defined in the header <linux/kern_levels.h> :
	#define KERN_SOH "\001"  /* ASCII Start Of Header */
	#define KERN_SOH_ASCII '\001'

	#define KERN_EMERG KERN_SOH "0" /* system is unusable */
	#define KERN_ALERT KERN_SOH "1" /* action must be taken immediately */
	#define KERN_CRIT KERN_SOH "2" /* critical conditions */
	#define KERN_ERR KERN_SOH "3" /* error conditions */
	#define KERN_WARNING KERN_SOH "4" /* warning conditions */
	#define KERN_NOTICE KERN_SOH "5" /* normal but significant condition */
	#define KERN_INFO KERN_SOH "6" /* informational */
	#define KERN_DEBUG KERN_SOH "7" /* debug-level messages */
	#define KERN_DEFAULT KERN_SOH "d" /* the default kernel loglevel */
	
	thus entering "\001""6""<string>" is equivalent of KERN_INFO_STRING
 075. cat /proc/sys/kernel/printk		# any message above console log level 4, i.e. warning, error, crit, etc. will be displayed on the console
      > 4	4	1	7					# output: console_log_level, default_log_level, minimum log level, maximum log level
 076. echo 8 > /proc/sys/kernel/printk  # will change the default log level
 # Graphical mode is implemented in Linux user space by a process called X server, not by the kernel
 # CTRL+ALT+F4 switches to Kernel mode, CTRL+ALT+F2 switches back to GUI
 # There are other functions that we can use in place of printk() in order to have more efficient messages and compact and readable code:
	#define pr_emerg(fmt, ...) \
	>	printk(KERN_EMERG pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_alert(fmt, ...) \
    >    printk(KERN_ALERT pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_crit(fmt, ...) \
    >    printk(KERN_CRIT pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_err(fmt, ...) \
    >    printk(KERN_ERR pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_warning(fmt, ...) \
    >    printk(KERN_WARNING pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_warn pr_warning
	#define pr_notice(fmt, ...) \
    >    printk(KERN_NOTICE pr_fmt(fmt), ##__VA_ARGS__)
	#define pr_info(fmt, ...) \
    >    printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)
 # pr_debug depends on having either a CONFIG_DYNAMIC_DEBUG or DEBUG macro defined or passed in as a command line flag to GCC 
 # It can also be defined in the Makefile using the line "ccflags-y := -DDEBUG"
 # Floating point numbers cannot be called with printk. Using %f will return an error. Floating point mode being off saves time as FPU states and registers 
 # don't need to be saved. If a userspace program attempts to use a floating point operation, it "traps" into the kernel (send to kernel), then kernel will
 # transition to floating point mode.
 077. cat /proc/sys/kernel/printk_ratelimit_burst   # shows the number of times printk can be called, before printk_ratelimit returns 0
 #By default usually returns 1. Once the limit for printk has been raced usually starts returning 0.
 078. cat /proc/sys/kernel/printk_ratelimit			# shows the number of seconds until the rate of traffic will be disbabled until it is re-enabled.
 # printk_once() will only print once and never again 
 079. cat hex_dump.c
 //void print_hex_dump(const char *level, const char *prefix_str, int prefix_type, int     rowsize, int groupsize, const void *buf, size_t len, bool ascii);
		> print_hex_dump(KERN_ALERT, "buf: ", DUMP_PREFIX_ADDRESS, 16, 1, buffer, sizeof(buffer), 1);
		> print_hex_dump(KERN_INFO, "buf: ", DUMP_PREFIX_OFFSET, 16, 1, buffer, sizeof(buffer), 0);
 # Also a shorter form of print_hex_dump which follows: void print_hex_dump_bytes(const char *prefix_str, int prefix_type, const void *buf, size_t len)
 # Has a log level of KERN_DEBUG, rowsize of 16, groupsize of 1, and ASCII output included

 # Dynamic debugging was introduced to allow kernel code to be dynamically enabled/disabled. This allows pr_debug()/print_hexdump_bytes() calls to be enabled per callsite
 # If CONFIG_DYNAMIC_DEBUG is set the behaviour of pr_debug()/dev_dbg()/print_hexdump_bytes()/print_hexdump_debug() is controlled by writing to a control file in the debugfs filesystem
 080. sudo mount -t debugfs none /sys/kernel/debug		# will mount the debugfs
 081. cat /boot/config-`uname -r` | grep CONFIG_DYNAMIC_DEBUG		# will show whether dynamic debug is enabled
 082. mount | grep debugfs  							# will show whether debugfs is currently mounted
 083. sudo -s && cd /sys/kernel/debug					# will navigate to mounted debugfs filesystem (sudo -s allows use of current user password to up permissions to superuser)
 084. cd dynamic_debug && cat control | less -N 		# will show currntly printed messages
 085. echo -n '+p' > control 							# will enable all debug messages
 086. echo -n '-p' > control 							# will disable all debug messages
 087. echo -n 'func svc_process +p' > control			# will enable all debug messages in the function svc_process()
 088. echo -n 'file svcsock.c line 1603 +p' > control	# will enable printing from line 1603 in file svcsock.c
 089. echo -n 'file svcsock.c +p' > control				# will enable printing of all debug in svcsock.c
 090. echo -n '*usb* +p' > control						# will enable printing of debug in all files wich have usb in the file path
 091. echo -n 'file /path/to/* +p' > control 
 092. echo -n 'module e1000 +p' > control				# will enable for modules

 # dump_stack() can be called in order to dump a stack trace to the dmesg output
 # A kernel panic is caused by a hardware or software issue which causes the kernel to immediately stop running to avoid data loss and other damage. It call the panic() function which
 # dumps useful debug information about the state of the system, and depending on configuration reboots/stops the system. By default it does not reboot the system upon kernel panic
 093. sudo echo panic=N >> /proc/cmdline 				# Adding to the kernel command line causes the kernel to reboot after N seconds
 094. sudo echo N > /proc/sys/kernel/panic				# Will acheive the same goal as above, however this setting is not persistent on reboot
 # An Oops is similar to a segfault in user space, system throws an oops when an exception is encountered in the kernel code, but the system is not frozen or rebooted afterwards, it simply
 # kills teh offending process. Locks or structures may not be cleaned up after an oops message, so the system should not be trusted. 
 # An oops message will contain: Processor status, Contents of CPU registers, Stack trace, Call trace.
 # BUG() macro will print the contents of the registers, a stack trace and current process dies, cannot remove a module after a busg or an oops.
 095. cat /proc/cpuinfo 								# for system information including the number of processors
 # the kernel library function num_online_cpus(), also acheives the same result programmatically.
 
 # Linux internally refers processes as tasks, it stores the list of proes a macro by the name "current" which always returns  pointer to the task_struct of the current process, must include <asm/current.h>
 # Process memory map is contained in struct mm_struct, contains a vm_area_struct which points to the head of the list of memory region objects, and another which points to the last referenced memory region object
 # Linux implements a memory region by use of vm_area_struct, this contains a pointer to the mm_struct that is the owner of the region
 
 # A kernel thread is a linux task running only in kernel mode, cannot be created by fork() or clone() system calls
 096. ps -ef 				# Anything surrounded by square brackets is a kernel thread, normal processes do not have these brackets
 # Kernel threads and User threads are both represented by task_struct. main difference is there is no address space in Kernel threads, mm variable is set to NULL
 # struct task_struct *kthread_create(int (*threadfn)(void *data), void *data, const char name[], ...) For creating a kernel thread
 # need to call wake_up_process() with the return value of kthread_create as an argument to the wake_up_process for the thread function to run, however Linux provides a single API kthread_run, which creates and calls wake_up_process
 # struct task_struct * kthread_run(int (*threadfn)(void *data), void *data, const char name[], ...)
 # int kthread_stop(struct task_struct *k); to stop a kernel thread
 # kthread_stop is a blocking call, it waits until the function executed by thread exits. kthread_stop() flag sets a variable in the task_struct variable which the function running in while(1) should check in each of its loop.
 # int threadfunc(void *data){while(!kthread_should_stop()){//perform operations here}return 0;} //if not stopped in module exit funcytion will get an oops message
 # It is possible to crete a new kthread with the same thread name as an already running kernel thread
 # If calling kthread_stop() on a thread that is already exited, will get a warning/oops message
 # smp_processor_id() is used to return the current version of the processor

 # LINUX_VERSION_CODE is a macro that expands to a binary representation of the kernel version, with one byte for each part of the version release number
 # KERNEL_VERSION is a macro which builds an integer code from the version numbers, is also a binary representation
 097. make -C /lib/modules/`uname -r`/build M=$(pwd) hello.i 	# will give preprocessor output, passing --save-temps to ccflags will also save all temp files
 # The __init macro causes the init function to be discarded after the initialisation code has been run, otherwise it is usually stored as a symbol, this saves on memory
 # The __exit macro can only be used with builtin modules and causes the __exit section to be discarded as it is not needed, will not work for loadbale modules
 # __initdata and __exitdata are used for variables can only be used with __init macro 
 098. sudo cat /proc/kallsyms | grep module_name 				# will return the symbols table for the loaded kernel module, will be missing init function and data if macros used
 099. grep -rn module_name /lib/modules/`uname -r`/modules.builtin 		# will list all builtin kernel modules	
 100. sudo cat /etc/modules			# contains a list of kernel modules to load at boot time
 #In order to have a kernel module load from startup
 101a. sudo ln -s $(pwd)/module.ko /lib/modules/`uname -r`/kernel/drivers/misc	# will add symbolic link to kernel drivers folder
 101b. sudo depmod -a			# find and index dependencies 
 101c. sudo echo "module" >> /etc/modules 
 # Blacklisting is a mechanism to prevent a kernel module from loading, need to create a .conf file in /etc/modprobe.d/ and add blacklist <modulename> for each module to blacklist, then rebuild initramfs
 102a. lsmod | grep e1000 			# blacklisting the ethernet driver
 102b. cd /etc/modprobe.d/
 102c. touch les.conf
 102d. echo "blacklist e1000" >> les.conf	
 102e. sudo update-initramfs -u 
 102f. sudo reboot
 # Can also blacklist using kernel command line (if system is broken)
 103a. sudo vi /etc/default/grub		#sets command line options i.e. cat /proc/cmdline
			-> GRUB_CMDLINE_LINUX=module_blacklist=e1000,module_name2"
 103b. sudo update-grub
 103c. sudo reboot
 # To pass parameters to modules which are automatically loaded using modprobe
 104a. cd /etc/modprobe.d/ && grep -rn options 		# example of syntax used in existing conf files <options module_name Param_name=value>
 
 # In linux everything is considered a file, even hardware devices. There are two categories of device file, character and block. Character device files are slower and manage a small amount of data, these 
	# include keyboard, mouse, serial port, and joysticks. In general operations on these devices are performed sequentially byte-by-byte. 
 # The second category includes devices where data volume is very large or speed of data transfer required is large
	# Devices that fall into this category are generally hard drives, disk drives, ram disks, cd-roms, magnetic tape drives, etc.  
 105. ls -l /dev | grep "^c"		#list all character device files in /dev, "^d" indicates that it is a directory, "^b" indicates that it is block device file
 # There are 3 steps in creating a character device driver, 
	# 1. Assign a device number dynamically or statically (dev_t)
	# 2. Initialize the character device with its file operations (struct cdev, struct file_operations)
	# 3. Registering the character device with Linux Kernel (cdev_add)
 # Device consists of major/minor number. Major identifies the device type (IDE disk, SCSII disk, serial port, etc.) whilst Minor identifies the device (1st BUS, 2nd BUS, etc.)
 106. 	# print major and minor numbers of device files in /dev
 # Certain major identifiers are assigned statically to devices (in Documentation/admin-guide/devices.txt in kernel source), 
 # Can either assign device number statically (choose unique number) or dynamically (kernel provides device number). represented by 32-bit dev_t (12-bit major, 20-bit minor number)
 # To obtain the major and minor parts of dev_t use macros MAJOR(dev_t dev) and MINOR(dev_t dev) %d
 107. cat /proc/devices 		# shows devices present on the system, outputs the major number and then the name of the device 
 # In order to statically assign a device number int register_chrdev_regiion(dev_t from, unsigned count, const char* name) will register a range of device numbers, from: first, count: how many - will appear in /proc/devices
 # CHRDEV_MAJOR_MAX is set to 512 in linux/fs.h, so max major number is 511
 # In order to dynamically allocate major number (recommended method) requires int alloc_chrdev_region(dev_t* dev, unsigned baseminor, unsigned count, const char* name)
 108. sudo mknod -m 0644 /dev/mydevice c 250 10		# mknod -m manually creates a device file, mknod - m <permissons> <name> <device type(char|block)> <major> <minor>, does not appear in cat /proc/devices
 # udev can also create device nodes, it makes use of the class_create function static struct class* class_create(struct module *owner, const char name). Can use THIS_MODULE macro to reference module *owner
 # udevadm can then be used to monitor class. Once class_create is used appears in /sys/class/<name>
 109a. cat class_create.c
        > #include <linux/kernel.h>
       > #include <linux/module.h>
       > #include <linux/delay.h>
       > #include <linux/device.h>
       > 
       > MODULE_LICENSE("GPL");
       > static struct class *class;
       > 
       > static int test_device_init(void)
       > {
       > 	class = class_create(THIS_MODULE, "myclass");
       > 	return 0;
       > }
       > 
       > static void test_device_exit(void)
       > {
       > 	class_destroy(class);
       > }
       > 
       > module_init(test_device_init);
       > module_exit(test_device_exit);
 109b. udevadm monitor &
 109c. sudo insmod class_create.ko   
		#output: 	KERNEL[11216.875071] add      /class/myclass (class)
					UDEV  [11216.875340] add      /module/class_create (module)
					KERNEL[11216.875402] add      /module/class_create (module)
					:waitsUDEV  [11216.875412] add      /class/myclass (class)
 109d. ls -l /sys/class/myclass
 # class_create does not create a dev node. In order to create a dev node must use device_create, device_destroy
 # struct device* device_create(struct class* class, struct device *parent, dev_t devt, void *drv_data, const char* fmt, ...);    void device_destroy(struct class *class, dev_t devt);
 110a. udevadm monitor &
 110b. sudo insmod device_create.ko
 
 # struct file_operations is defined in linux/fs.h and holds pointers to functions defined by the driver that perform various operations on the device.
 # functions can be assigned to the pointeers in file_operations such as ioctl
 # In the kernel each character device is represented by the structure cdev, contained in the header file linux/cdev.h
 struct cdev {
        struct kobject kobj;
        struct module *owner;
        const struct file_operations *ops;
        struct list_head list;
        dev_t dev;
        unsigned int count;
} __randomize_layout;
 # the functions associated with cdev are cdev_init (intialize a cdev structure), cdev_alloc (allocates and returns a cdev), cdev _add (adds a char device to system), and cdev_del (removes it)
 # fork() will not create a new file structure, when writing to a device file, fs.h contains an atomic_long_t f_count, and device_release is only called when that returns to zero.
 # a struct file is a kernel struct that never appears in user space programs and is different to the C library's FILE, every open file on the system 
   # has an associated struct file in kernel space, it is created by the kernel on open, and is passed to any function that operates on the file until 
   # the last close, an open file is different from a disk file represented by the struct inode. Important fields of struct file are:
   # struct file { fmode_t f_mode; /*identifies file as readable or writable*/ loff_t f_pos /*current reading or writing position 64-bit value*/
				 unsigned int f_flags; /*file flags such as O_RDONLY, O_NONBLOCK, O_SYNC*/ struct file_operations *f_op; /*operations associated with file*/
				 void *private_data; /*useful resource for preserving state information across system calls*/ };
 # the inode structure is used by the kernel internally to represent files, and uniquely identifies a file ina file system
   # struct inode { umode_t i_mode;  kuid_t i_uid;  kgid_t i_gid;  unsigned long i_ino; //inode number  dev_t i_rdev;  
				  struct cdev *i_cdev; //kernel representation of char device } 
 111. stat file 	# will return file statistics/status, including its unique inode number identifier 
 # Some functions exist for copying data from the user space into kernel space. copy_from_user copies a block of data from user space into the kernel buffer
   # it accepts a destination buffer (in kernel space), a source buffer (in user space), a length defined in bytes, returns zero on success 
 # In Linux jiffies is a global variable tkhat stores the number of clock ticks since boot. It is contained in <linux/jiffies.h>
 # To read simple variable from user space, use the get_user function thi works for types such as char and int, but for larger structs, should use the copy_from_user function
 # It is possible to copy from either the stack to the kernel, or from the heap to the kernel, but if a struct contains members on both the stack and the
   # heap the copy_from_user command will not be completed and it will freeze the kernel, and all demsg output. This is resolved by reboot 
 # print_dev_t(buffer, dev) and format_dev_t(buffer, dev) defined in kdev_t.h will both populate a charcter buffer with the device number separated as major
   # and minor numbers. format_dev_t returns the buffer, whilst print_dev_t returns the result of the sprintf() function, buffer should be >20 bytes
 # strlen() is implemented in kernel_space as well as the user_space. on older distributions of linus strn_len should be called from kernel space for user variables
 # The offset_position (*offp) should be updated after each data transfer to represent the current file position after succesful completion of the system call 
 # container_of() is a macro frequently used in Linux driver code. Given a structure with many members, conatiner_of will return the base address of the structure when
   # you pass in the address of a member variable of the structure. It is defined as
   # #define container_of(ptr, type, member) ({ \
   #		const typeof( ((type *)0)->member) *__mptr =m (ptr); \
   #			(type *)( (char *)__mptr - offsetof(type, member) );})
 # When the userspace calls a write into device file i.e. "echo "hello" > /dev/msg, it calls th GLibC write call which calls the system write call. It is
   # present in <linux source code>/fs/read_write.c, in which there is a ksys_write function. This is the call executed when the user calls "write". The fd passed by user
   # is a struct with two members, One one struct file* pointer, and an unsigned int for the flags. ksys_write then calls vfs_write which stands for virtual file system
   # this then calls the device_drier's write function from the file_operations in struct file
 # IOCTL stands for input output control, some operations such as changing the baud rate of a serial port, adjusting volume, reading or writing device registers cannot be done
  # with simple read/write functions. System call ioctl() is provided for device specific custom commands. it is in the form 
  # int ioctl(int fd, unsigned long request, ...); 
  # man 2 ioctl_list provides a list of ioctl request calls.
 # picking an arbitrary number for ioctl commands can have catstrophic cosequences including damage to hardware, two device nodesmay have the same major number,
  # and an application could open more than one device and mix up file descriptors. thereby sending the right command to the wrong device  
  # linux-sourc-code/Documentation/ioctl/ioctl-number.txt. tg ioctl command is divided into four parts. These four parts (bitfileds) are type, number, direction, and size
    1. The 'code' column listed in this file is the device type/magic number and is 8-bit wide, these are already being used. Best not to use what is already present in this File
	2. The 'number' column is 8-bits wide and is the sequential number you assign to the command
	3. The 'direction' colum is one of 4 values (2-bits wide) _IOC_NONE, _IOC_READ, _IOC_WRITE, _IOC_READ|_IOC_WRITE
	4. The 'size' column is a 13/14-bit number, can find size for specific architecture by using macro _IOC_SIZEBITS
  # Header file fo these is linux/ioctl.h. This header file defines a macro which can be used to generate a command.
    #_IO(type, nr) for a command with no argument  - generates 16-bit hex value as command 
	#_IOR(type, nr, datatype) for reading data from the driver - generates 32-bit hex value as command 
	#_IOW(type, nr, datatype) for writing data to the driver - generates 32-bit hex value as command 
	#_IOWR(type, nr, datatype) for bidirectional data transfer - generates 32-bit hex value as command 
  # Macros to decode the ioctl command
    # _IOC_TYPE(cmd) //gets the magic number of the device this command targets
	# _IOC_NR(cmd) //gets the sequential number of the command within your device
	# _IOC_SIZE(cmd) //gets the size of the data structure
	# _IOC_DIR(cmd) // gets the direction of data transfer
  # copy_from_user, and copy_to_user, are used to transfer data betwen user and kernel space put_user/get_user are used for smaller data items, 
  # to verify address withouit transferring data can use access_ok which is a macro of type
	# int access_ok(int type, void *addr, unsigned long size) where type = VERIFY_READ/VERIFY_WRITE, addr -> user space address, size -> depends on ioctl command
	# for read/write use VERIFY_WRITE as it is a superset of VERIFY_READ, return typ is 1 for success and 0 for failure
  # compat_ioctl is called when a 32-bit process calls ioctl()
  # The function for sending a signal from a module to a process is: 
    # int send_sig(int signal, struct task_struct *task, int priv);
  # POSIX Capabilities divides root privileges into a set of privileges. man capablilities provdies more information on te capabilities list
 112. getcap <filename>  # 	# To find the capabilities for a particular file use 
 113. setcap cap_sys_boot+ep /path/to/executable   # each capability is implemented as a bit in each of the bitmap, and can be set or unset 
												   # CAP_SYS_BOOT capabilities are defined in the man capabilities entry, this sets CAP_SYS_BOOT
												   # capabilities in both the extended and permitted bitmap (see below)
  # Each process has three sets of capabilities: 1. Permitted: capabilities the process can possibly have 
												 2. Effective: capabilities the process actually has
												 3. Inheritable: capabilities the process can pass to a child process
  # capabilities are implemented on Linux using extended attributes in the security namespace, all major filesytems on Linux support extended attributes
    # ext2, ext3, ext4, JFS, XFS, etc. If a process tries to perform a privileged operation, kernel checks whether potential capability is set in the effective capability bitmap
  # CAP_DAC_OVERRIDE: Allows a non-root user full file system access. Bypasses file read, write and execute permission check.
  114. sudo setcap cap_dac_override+ep userapp  # DAC stands for 'discretionary access control'
  114a. cat userapp.c  # ll/etc/shadow shoul reveal this file has most group permissions
  			> #include <stdio.h>
			> #include <sys/fcntl.h>
			>
			> int main()
			> {
			>  	int fd;
			> 
			> 	fd = open("/etc/shadow", O_RDONLY);
			> 	perror("fd");  //returns sucess when cap_dac_override set, permission denied when cap_dac_ovverride removed
			> 	return 0;
			> }
  115. getcap userapp  # returns userapp = cap_dac_module++ep
  116. sudo setcap cap_dac_override-ep init_module
  # CAP_SYS_MODULE alllow s non-root process the ability to load or remove kernel modules.
  117. sudo setcap cap_sys_module+ep ./init_module
			 >#define _GNU_SOURCE
			 >#include <fcntl.h>
			 >#include <stdio.h>
			 >#include <sys/stat.h>
			 >#include <sys/stat.h>
			 >#include <sys/syscall.h>
			 >#include <sys/types.h>
			 >#include <unistd.h>
			 >#include <stdlib.h>
			 >
			 >// init_module is called by the insmod function. this bypasses the wrapped and calls the systemcall directly using a hash define
			 >#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)
			 >
			 >int main(int argc, char **argv) {
			 >	const char *params = "";
			 >	int fd, use_finit;
			 >	size_t image_size;
			 >	struct stat st;
			 >	void *image;
			 >
			 >	fd = open(argv[1], O_RDONLY);
			 >	fstat(fd, &st);
			 >	image_size = st.st_size;
			 >	image = malloc(image_size);
			 >	read(fd, image, image_size);
			 >	close(fd);
			 >	if (init_module(image, image_size, params) != 0) {
			 >		perror("init_module");
			 >		return EXIT_FAILURE;
			 >	}
			 >	free(image);
			 >	return EXIT_SUCCESS;
			 >}
  # CAP_SYS_ADMIN allows the abiliyty to perform all of the system administration operations. Almost near to root. Before performing the privileged operation a device driver
	 # should check that the calling process has the appropriate capablity. Capabilities checks are performed with t	he capable function, which is located in the header <linux/sched.h> 
     # int capable(int capability);
  # if a process terminates without a user callingg close() from the user space, the release function will still be called.
  # Misc drivers are simple char drivers that share certain common charcateristics. The kernel abstracts these commonalities into an API (drivers/char/misc.c) which simplifies
	# the way these drivers are initialized. All misc drivers are assigned a major number of 10, but each can choose a single minor number. If your char driver needs to support
	# multiple devices it's not a candidate for being a misc driver.
  # static struct miscdevice misc_dev = {
		.minor = 10,  //can iitialize this with MISC_DYNAMIC MINOR
		.name = MYDEV_NAME,
		.fops = &mycdrv_fops, 
	};
	misc_register(&misc_dev);
  # Physical memory mapping on Linux can be acccessed via the /proc/iomem file. Higher level permissions are needed to view the contents of this file. 
  118. sudo cat /proc/iomem
  119 uname -a  # will print all system information, i686 indicates a 32-bit machine
  120. free -m   # Returns the amount of RAM and swap space present on the machine.
  121. cat /proc/meminfo   # will also return information on RAM the system has present as well as swap information etc.
  # On Linux, every memory address is virtual. They do not point to any address in the RAM directly. Whenever you access a memory location, a translation mechanism is performed
	# in order to match corresponding physical memory. Size of the virtual address space is 4GB on 32-bit systems, which is divided into an area for app;ications called user space
	# and an area for the kernel, called kernel space. The split between the two is se by a kernel configuration parameter called PAGE_OFFSET. Is usually a 3G/1G split on 32-bit 
  # User address space is allocated per process, such that each proess runs in a sandbox, separated from others
  # The kernel address space is the same for all processes. This is because every process uses system calls, which will involve the kernel. And also it avoids context switching
	# Mapping the kernel's virtual memory address into each process virtual address space allows to avoid the cost of switching out memory address space on each entry to and exit
	# from the kernel.
  # Virtual memory for a 64-bit system is allocated 128 TB worth of address space, as is  the kernnel-space virtual memory. Full documentation is found for this in the Linux
    # source code under path Documentation/x86/x86_64/mm.rst which shows exactly where memory is allocated for addresses i.e. EFI mapping, etc.
  # Kernel and user space work with virtual addresses, they are mapped to physical addresses by memory management hardware (MMU), some macros exist in #include <asm/io.h>
    # phys_addr = virt_to_phys(virt_addr)    and     virt_addr = phys_to_virt(phys_addr)
  # printk format needed for a specific data type is specified in the kernel source code under Documentation/core-api/printk-formats.rst
  # Virtual address space is divided into pages of 4096 bytes (4KB) on ARM and x86 processors.
  # Memory Page/Virtual Page/Page : refers to a fixed length contiguous block of virtual memory, kernel data structure to represent a memory/virtual page is struct page
  # Frame/PageFrame : Refers to a fixed length contiguous block of physical memory in top of which the OS maps a memory page. Each page frame is give a page frame number (PFN)
	# There are page_to_pfn and pfn_to_page macros for translating between them
  # Page Table: kernel and architecture data structure which stores the mapping between virtual and physical addesses, each entry describes a key pair page/frame
  122 getconf PAGESIZE  # returns the page size to stdout
  # The header file contatining the struct page that the kernel uses to represent virtual pages is found in <linux/mmtypes.h>
	# struct page {
	#	unsigned long flags;  	//Flags : Status of the page: Dirty, locked in memory. Values: <linux/page-flags.h>
	#	atomic_t _count;		//_count : Usage count of the page. how many references are to this page. When page is free _count is negative one
	#	void *virtual;			//virtual : Page's virtual address
	#	...
	# };
  # The size of struct page is 64 bytes so around 64MB is used to store all available pages 4GB/4KB (for 32-bit memory)
  # Kernel memory is managed in a straightforward way. It is not demand-paged , meaning that for every allocationusing kmalloc() or similar, there is real physical memory
	# Kernel memory is never discarded or paged out. 
  # User space allocation is done via lazy allocation, only mapping pages of memory when the program accesses it.. Allocating a buffer of 1MB with malloc(3) returns a pointer	
	# to a block of memory addresses, but no actual physical memory. 
  # If attempting read/write access, but the page is not present within the memory, it raises a page fault.
  123. cat /proc/self/maps   # will give a memory map for the user space of the program in question (stack) (heap) (variables, etc.) - self can be replaced with the pid
  # The maximum amount of physical mmeory that could be mapped to the kernel. was a little under 1GB , which traditionally led to the virtual adress space of the kernel being
	# mapped out into two parts. A LOWMEM (Low memory section) which represents the first 896MB and HIGHMEM (High memory) which represents 128MB
  # Early in the boot process the first 896MB of kernel address space is physically mapped. Addresses that result from this mapping are called logical addoresses. They are virtual
    # addresses, but can be translated into physical addresses by subtractig a fixed offset, since the mapping is permanent and known in advance. A logical address can be
	# converted into  aphysical address by using the __pa(address) macro and reverted using the __va(address) macro. LOWMEM addresses match with the lower bounds pf physical 
	# addresses. Kernel memory is then divided into three differenet zones to serve different purposes (On a 512MB system there will be no ZONE_HIGHMEM, simply 16MB for ZONE_DMA,
	# and 496MB for ZONE_NORRMAL)x
	  # ZONE_DMA: This contains page frames of memory below 16MB and is reserved for Direct Memory Accessn (DMA)
	  # ZONE_NORMAL: This contains page frames of memory above 16 MB and below 896 MB, for normal use
	  # ZONE_HIGHMEM: This contains page frames of memory at and above 896MB and is the top 128Mb of the kernel address space. it is used by the kernel to temporarily map physical
		memory above 1GB. When Physical memory above 896MB needs to be accesses, the kernel uses those 128MB to create a temporary mapping to its virtual address space, thus
		achieving the goal of being able to access all physical pages. Mapping to access high memory is created on the fly by the kernel and destroyed when done making access slower
	# These concepts do not exist on 64-bit systems, due to the huge address range (2^64), where the 3G/1G split doesn't make sense anymore.
  # kmalloc() and vmalloc() are used to allocate memory in the kernel spac. A kernel module has direct access to kamlloc, vmalloc, page allocator, and slab allocater 
  124. sudo cat /proc/slabinfo   # contains info on slab allocators
  # Memory returned by kmalloc is contiguous in physical memory and in virtual memory. It is the general higher-level allocator in the kernel, and relies on SLAB allocator
  # It will generally return a kernel logical address as it is allocated from the LOW_MEM region, and the header file is #include <linux/slab.h>
	# void *kmalloc(size_t size, int flags);
	# 	size: specifies the size of the memory to be allocated (in bytes)
	#	flags: determines how and where memory should be allocated
	#			Available flags are the same as the page allocator (GFP_KERNEL, GFP_ATOMIC, GFP_DMA, and so on)
	# Return Value: On Success, returns the virtual address of the cjhunk allocated, which is guaranteed to be physically contiguous. On error, it returns NULL
	# kmalloc flags - 	GFP_KERNEL : Is the standard flag. Cannot use flag in an interrupt handler as code may sleep. returns memory from LOW_MEM zone (hence a logical address)
	#	 				GFP_ATOMIC: This guarantees the atmoicity o the allocaction. Only flag to use in the interrupt/signal interrupt context
	#					GFP_USER: Allocates memory to user space process. Memory is distinct and separate from that allocated to the kernel
	#					GFP_HIGHUSER: This allocates memory from the HIGH_MEMORY zone
	#					GFP_DMA: This allocates memory from the DMA ZONE
  # The kfree function is used to free the memory allocated by kmallloc()
	# void kfree(const void* ptr) // Memory corruption can happen: On a block of memory that already has been freed, on a pointer that is not an address returned from kmalloc
  # The Linux kernel divides physical RAM into a number of different regions: 64-bit: DMA, DMA32, Normal || 32-Bit: DMA, Normal, Highmem
	# Direct Memory Access (DMA) : On 32-bit machines this is the low 16MBytes of memory, 
	# Direct Memory Access (DMA32): Exists only on 64-Bit machines, this is the 2nd zone in addition to DMA is DMA32; this is from 16MBytes to the low 4 GBytes of memory.
	# Normal zone: On 64-bit machines it's all RAMfrom 4GB or so upwards, on 32-bit machines it's all RAM from 16MB to 896MB
	# HighMem: Exists only on 32-bit Linux, all RAM above 896MB, including RAM above 4GB on sufficiently complex machines.
  125. cat /proc/buddyinfo  # will list the memory zones, split into 11 columns,  depending on the system's architecture and amount of RAM
  # Within each zone, Linux uses a buddy-system allocator to allocate and free physical memory
  # Buddy System Allocator : Memory is broken up into large blocks of pages where each block a is 'power of two' i.e. 2^n number of pages. All free pages are split into 11 lists
    # All free pages are split into 11 (MAX_ORDER) lists , each containing 2^order pages (up to 11), this is why cat proc/buddyinfo returns 11 columns.when a request is made 
	# for an allocation of a certain size, the buddy system looks into the appropriate list for a free block and returns its address if available. if not it moves to check in
	# the next higher order list for a larger block, and splits the higher order block into two equal parys called buddies, returning one for the allocator, and queues the second
	# onto a lower-order list. When both buddy blocks become free at some future time, they are coalesced to create a larger block. i.e. first block size 2^0 x 4KB (block size)
	# second block size 2^1 x 4KB (block size)  .. last block 2^10 x 4KB block size
  126. grep -A 10 "memory"   # finds the term then includes the next 10 lines after the term within the search results
  # If memory allocated by kmalloc is not freed, the memory is not returned to the kernel once we have removed the kernel module. Memory leak will remain after process has finished
  127. watch './userapp'  # with no parameters wathc will run the command every 2 seconds
  128. watch -n 0.1 './userapp'  # will run loop every 100 ms
  # kmalloc allocates bytes by calling other functions like kmalloc-8 kmalloc-16, etc.. up to kmalloc-8k. thus it issues memory in the form of blocks. 
  129. sudo cat /proc/slabinfo   # returns information on the number of bytes allocated by the kmalloc command
  # kzalloc works like kmalloc, but also zeroes the memory   -   void* kzalloc(size_t size, gfp_t flags);
  # krealloc works like realloc, and can resize the allocated memory    -  void* krealloc(const void *p, size_t new_size, gfp_t flags);
  # memory returned by vmalloc is only contiguous in virtual and not physical memory, uses vfree(const void *ptr) rather than kfree, doesn't require flags to initialize
  # Differences between vmalloc and kmalloc:
		# kmalloc  -  guarantees pages are physicaly and virtually contiguous,    vmalloc - pages are virtually contiguous, not necessarily physically contiguous
		# kmalloc  -  returns from Low Memory,   vmalloc  -  returns from High Memory (32-bit)
		# kmalloc  -  Memory returned can be used by hardware devices(DMA, PCI),   vmalloc  -  Memory returned cannot be used by hardware devices
		# kmalloc  -  Can be used in intterrupt context with GFP_ATOMIC,	  vmalloc  -  Cannot be used in interrupt context
		# kmalloc  -  Uses slab allocator, which in turn uses Page Allocator,   vmalloc  -  Directly uses page allocator
		# kmalloc  -  less overhead,   vmalloc  -  moreoverhead, requires page table changes and a translation look aside buffer invalidation
		# kmalloc  -  Cannot give large memory,   vmalloc  -  useful for allocating large memory with no requirement of physically contiguoos regions.   
  # kmalloc(0) returns a special ZERO_SIZE_PTR value. It is a non-NULL value that looks like a legitimate pointer, but which cauuse a fault on any attempt at dereferencing it
    # Any attempt to call kfree with this special value will free the memory, and not return a fault.  A vmalloc(0) fails and does not allocate any memory 
  # The user space stack was initially afforded a large dynamically growing stack, whilst the kernel space stack was usually small and fixed. This was mitigated via the use of
	# interrupt statcks, whereupon any interrupts use their own stacks which saved on the space traditional interrupt handler would take up of the kernel stack.
  # The linux model of multiprocessing is SMP (symmetric multi-processors). In this one copy of the OS is in memory and any CPU can run it, potential problem in two CPUs
	# trying to claim the same resource (i.e. page, or run the same process. This was mitigated by use of a lock, or mutual exclusion. This led to splitting the OS into 
	# "critical regions which can only be accessed by one CPU at a time via the use of mutex.
  # Preemption means - forcefully taking away the processor form one process and allocating it to another process. Switching from one process t'other is known as a context switch.
    # This is implemented by initialising a timer, and calling the scheduler after each timer interrrupt. This then determines what process to run based on priority, time elapsed, etc
	# The context_switch() function is called in the kernel 
  # Under Linux, user-space programs have always been pre-emptible, teh kernel interrupts user-space programs to switch to other threads, using the regular clock tick. It doesn't
	# wait for user-space programs to explicitly release the processor, which means an infinite loop in user space cannot block the system.
  # Kernel pre-emption was introduced after kernel 2.6 and can be enable or disble using CONFIG_PREEMPT. If enabled it can be pre-empted anywhere, except when code has disabled
	# local interrupts
  # Kernel preemption can occur: returning to kernel space from an interrupt handler; when kernel code becomes pre-emptible again; if task in kernel explicitly calls schedule()
	# if a task in the kernel blocks, resulting in a call to schedule. 
	# It reduces the dispatch latency of User Mode processes, reducing the time between them becoming runnable and when they actually start running
  # A kernel control path is the sequence of instructions executed by the kernel to handle a system call, an exception, or an interrupt.
  # The Linux Kernel is reentrant, which means several processes may be executing in Kernel mode at the same time. On uniprocessor systems, one process can progress, but many
	# can be blocked in Kernel mode when waiting for the CPU or the completion of some I/O operation. An example is issuing a read to a disk on behalf of a processs, then letting
	# the disk controller handle it as it resumes executing other processes.
  # Reentrancy is acheived by having two types of functions. 	Reentrant functions: that don't use/modify global structures
																Non-reentrant functions : Modify global structures but use locking mechanisms
  # Any section of code that should be finished, before another process begins executing the same piece of code is known as a critical region.
  # Causes of concurrrency are: Interrupts: An interrupt can occur asynchronously at any time; interrupting the currently executing code
											Softirqs and tasklets: The kernel can raise or schedule a softirq or tasklet at any time.
											Kernel preemption: Because the kernel is premptive, one task in the kernel can preempt another
											Sleeping/synchronization with user space: task in the kernel can sleep and thus invoke the scheduler, resulting in running a new process
											Symmetrical multiprocessor: Two or more processors can execute kernel code at exactly the same time
  130. nproc   # returns the number of CPUS
  131. cat /proc/cpuinfo | grep ^processor   # will return the processors
  132. grep NR_CPUS /boot/config-`uname -r`  # returns the maximum number of processors an SMP kernel could support, passing in the 'nr_cpus=12' in the bootloader command line
  # The simplest and most efficient synchronization technique consists of declaring kernel variables as per-CPU variables. a per  CPU variable is an array of data structures
	# one element per each CPU in the sysstem. A CPU should not access elements of the array correspnding to another CPU, but it can freely read and modify its own element
	# without fear of race conditions because it is the only CPU entitled to do so. The elements o teh per CPU  array are aligned in main memory so each structure falls on a 
	# different line of the hardware cache.
  # percpu() on top of returning the current processor number also disables kernel premption. put_cpu() enables kernel preemption
  # if a kernel control path for example got the address of its local copy of a per-CPU variable, it could be preempted and moved to another CPU, whilst the address still refers
	# to an element of the previous CPU
  # To create a per-CPU variable at compile time the macro DEFINE_PER_CPU(type, name) i.e DEFINE_PER_CPU(int, i) DEFINE_PER_CPU(int[3], my_array), can manipulate the variables
    # with get_cpu_var() and put_cpu_var() routines, get_cpu_var() returns an lvalue and disables preemption, put_cpu_var() reenables preemption
  # An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address)
  # You can access another processor's copy of the varible with 'per_cpu(variable, int cpu_id);'
  # per-CPU variables provide protection against concurrent accesses from several CPUs, but they do not provide protection against accesses from asynchronous functions such as
	# interrupt handlers and deferrable functions. Additional synchronization primitives are required in this case
  # Problems can occur with shared access, due to read-modify-write instructions post assembly. These can cause 'race-conditions' whereby two threads attempt to modify the
	# original value of the variable, and place it back into the register holding the original value. This can be mitigated by the use of atomic variables and atomic operations
	# which are present in most CPU instruction sets, to ensure these are carried out in as an atomic read-modify-write or in a single instruction.
  # The Linux kernel provides a special atomic_t type (atomically accessible counter) and some spcial functions and macros that act on atomic_t variables. As atomic data types
	# are ultimately implemented with normal C data types, the kernel encapsulates standard variables in a structure that cannot be processed with normal operators.
  # Atomic operations are generally found in linux-source-code/asm-generic/atomic.h or <asm/atomic.h> (the header asm statds for architectur specific, each architecture implements
	# its own implementation. The non-atomic forms of these operations behave identially to their atomic counterparts and are prefixed with a double-underscore, otherwise identical
  # Atomic instructions have a problem in that they can only work with structures of CPU word and doubleword size, whereas critical regions often comprise more than one line
	# As these code paths must execute atomically to avoid a race condition, to ensure atomicity, locks are used. 
  # The spin lock is the most common lock in the Linux kernel and is ussed to protect short code sections taht comprise just a few C statements and are quickly executed and exited.
	# It is not recommended to use spin locks for larger critical sections, and it can be held by at most one thread of execution. When a CPU tries to acquire a lock that is 
	# already held, it busy spins/loops waiting for the lock to become available. When avavilable it acquires the lcok and continues.
  # Header file <linux/spinlock.h>    Data structure: spinlock_t      Methods are
	# DEFINE_SPINLOCK(my_lock);  //this creates the equivalent of   spinlock_t my_lock = __SPIN_LOCK_UNLOCKED(my_lock);
	# void spin_lock(spinlock_t *lock);   // To lock a spin lock
	# void spin_unlock(spinlock_t *lock);   // To unlock a spin lock 
	# void spin_lock_init(spinlock_t *lock);  // To initialize the spin lock at run time
  # Unlike other spinlock implementations, Linux kernel spinlocks are not recursive and do not return a value, which means if you try to acquire a lock you already hold, the
	# thread will simply keep spinning and because you are busy spinning and cannot release the lock, you will encounter a deadlock situation, 
  # If a driver is executing and has taken a lock, if the device the driver is handling issues an interrupt and the interrupt handler obtains the same lock, the interrupt
	# handler will spin forever, as the non interrupt code will not be ale to run and release the lock. In order to prevent this interrupts should be disabled before acquiring
	# the spin lock, and re-enabled after releasing the spin lock. The kernel provides an api for this in the form of
	# spin_lock_irqsave(&my_lock, flags);  // flags are passed in to save the current state of interrupts, so they can be returned to their previous state. 
	# /* critical region ... */
	# spin_unlock_irqrestore(&my_lock, flags);  // flags here, return the interrupt to their previous state
	# if interrupts were previously enabled, there is no need to restore their previous state
	# spin_lock_irq(&my_lock);
	# /* critical region ... */
	# spin_unlock-irq(&my_lock);
  # Any time the kernel holds a spinlock, preemption is disabled on the current processor, Lock/Unlock disable/enable preemption
  # If a lock is acquired but not released, the system is rendered unusable. All processors including the one that acquired the lock sooner or later must enter the critical
	# region. They start spinning waiting for lock release, but this never happens and deadlocks. Thus all processors waitin for lock release are no longer available for
	# other productive tasks. Code that is protected by spinlocks must not go to sleep, nor any of the functions in a critical region. e.g. kmalloc with GFP_KERNEL, which can 
	# go to sleep if memory is not available.
  # On a uniprocessor system if CONFIG_PREEMPT is disable spin_lock and spin_unlock are ampty operations, otherewise they trigger prempt enable and preempt disable.
  # A spinlock is a mutual exclusion device that can have only two values, Locked/unlocked, it is implemented as a single bit in an integer value, code must test the relevant bit,
    # and set it in an atomic manner so that only on thread can obtain the lock. They are built on top of hardware specific atomic instructions.
  # Semaphores in Linux are sleeping locks. When a semaphore is unavailable it places a task onto a wait queue and puts the task to sleep, processor is then free to execute
	# other code. After semaphore is available one of the tasks on the wait queue becomes awake so it can acquire the semaphore.
  # A semaphore is implemented as a single integer value combine with a pair of functions called P() (Proberen/test) and V() (Verhogen/increment). A process wishing to enter
	# the critical section will call P() on the relevant semaphore. If the semaphore's value is greater than zero that value is decremented by one and the process continues
	# If it's value is zero or less the process must wait until someone else released the semaphore. When exiting the critical section it increments the value of the semaphore 
	# by calling V() and wakes up processes that are waiting (if necessary).
  # Spin locks only allow one task to hold the lock at a time, whereas with semaphores the number of tasks to hold the lock at a time can be specified during initialization
	# and is known as usage count, or simply count. If count=1, its known as a binary semaphore and is used for mutual exclusion. If count > 1 its known as a counting semaphore.
    # Couning semaphores are not used to enforce mutual exclusion, becuase they allow multiple threads of execution in the critical region at once. They are used to enforce
	# limits in certain code and are not used much in the kernel.
  # The data structure for a semaphore can be found in <linux/semaphore.h>. It is as follows:
	# struct semaphore {
	#	raw_spinlock_t 		lock;       //this lock is used to provide serial access to the wait_list, rather than for the critical section
	#	unsigned int		count;
	#	struct list_head	wait_list;  //all processes placed on a wait queue to access the critical section are present here
	# };
	# Initialization can be Dynamic  -  void sema_init(struct semaphore *sem, int val);		Static  -  	DEFINE_SEMAPHORE(name)
  # Semaphores are suited to locks that are held for a long time as the tasks trying to acquire the lock sleep if it is not available. They re not suied to locks held for a
	# short time due to the overheads of sleeping, maintaining the wait queue and waking back up. This time total can easily overweight the lock hold time.
  # Semaphores also cannot be used in the interrupt context s it sleep if the lock is not available (save special functions). They also do not disable kernel preemption
	# so code holding a semaphore can be preempted. As it's not busy looping or 'spinning' whilst waiting however it is more efficient in terms of processor utilization.
  # Most semaphores were used as binary for mutual exclusion, but it produced an unnecessary overhead. Thus a new interface mutexes were produced. Mutex subsystem
	# The mutex subsystem checks and enforces the following rules:
		- Only one task can hold the mutex at a time
		- Whoever locked a mutex must unlock it
		- That is you cannot lock a mutex in one context and unlock in another
		- Recursive locks and unlocks are not allowed (a spinlock recursive lock attempt can cause a deadlock)
	 	- Process cannot exit while holding a m+rrupt handler
	# When acquiring a mutex, three possible paths can be taken
		- Fast Path: Taken when no process has acquired the mutex
		- Mid Path: When the mutex is not available, but only one process has acquired it, it goes for the mid-path - optimistic spinning. The process uses MCS lock to optimistically
					spin hoping the owner will release the mutex soon which avoids an expensive context switch
		- Slow path: There is more than one task waiting, or the owner of the mutex is not running. It acts like a semaphore alock and adds the task to the wait queue, which then
					sleeps until woken up by the unlock path.
		(for further information see Linux-source-code/Documentation/locking/mutex-design.rst)
  # Mutex implementation is found in Linux-source-code/kernel/locking/mutex.c and the header file is <linux/mutex.h>, The structure of a mutex is:
	# struct mutex {
	#	atomic_long_t	owner; 		//used both for holding the lock state and referencing the owner who acquired it.
	#	spinlock_t		wait_lock;	//used for atomic updating wait_list
	#	struct list_head wait_list;	//
	# };
	# Has static initialization: 	DEFINE_MUTEX(name)  	and Dynamic initialization: 	mutex(init);
	# LOCK: 	void mutex_lock(struct mutex *lock)		UNLOCK:void mutex_unlock(struct mutex *lock)
  # Spinlocks vs Mutexes - Requirements -
		- Low overhead locking 	- 	Spinlock
		- Short lock hold time 	-	Spinlock
		- Long lock hold time 	- 	Mutex
		- Lock from interrupt context 	- Spinlock
		- Sleep holding lock	- 	Mutex
  # A problem with existing mutexes is that they do not allow multiple reads from different programs, they do not differentiate between situations in which data structures
	# are read, and data structures are actively updates. Read access can be provided to multiple tasks concurrently, write access should be provided to one task at a time
  # rwlock offers a solution to this problem, it has static initialization: 	DEFINE_RWLOCK(name)  	and Dynamic initialization: 	rwlock_init(lock);
	# Readers: read_lock(&my_rwlock); /*crit section */; read_unlock(&my_rwlock);	Writers: write_lock(&my_rwlock0; /* crit section */; write_unlock(&my_rwlock);
  # rwsemaphores are mutexes that enforce mutual exclusion as binary semaphores for writers, but not for readers.  Implementation is found in kernel/locking/rwsem.c
	# Has static initialization:	DEFINE_RWSEM(name)		and Dynamic initialization:		init_rwsem(struct rw_semaphore *sem)
	# down_read_trylock(struct rw_semaphore *sem)   and    down_write_trylock(struct rw_semaphore *sem)  are both part of the api for this type
	# Reader-writer semaphores have a unique method, not usually present in reader-writer spinlocks. This function atomatcally converts and an acquired write lock to a read
	# lock. This is used in situations where the writer-lock is needed for a quick change, followed by a longer period of read-only access
  # There is an issue with the read-writer lock in that it allows concurrent access for reader, but if there is at least one reader process, which has acquired a lock, the
	# writer process cannot acquire one, which may mean long wait processes - this is known as 'writer starvation'
  # Effort has been put into developing synchronization primitives that avoid locks. Lock free and wait synchronization plays a mjaor role in RTOS where time guarantees must
	# be given. The new synchronization mechanisms in 2.6 kernel are Sequence Lock, and Read Copy Update (RCU)
  # Sequence Locks give the writer a higher priority when compared to the reader, which means the writer is allowed to modify the shared data, even when thre are readers in
	# the critial section. If a write access took place while the data was read, the reader data is invalid and it must be read again. Identification of write accesses is 
	# realised with a counter. If another writer arrives , the writer uses a spinlock for mutual exclusion and hence will not interfere with the other writer.
  # A sequence lock uses a S equence Counter 9integer) and a spin lock. The data structure it uses is called seqlock_t and it is found in <linux/seqlock.h>. It is as follows:
	# typedef struct seqcount {
	# 	unsigned sequence;
	# } seqcount_t;
	#
	# typedef struct {
	# 	struct seqcount seqcount;
	# 	spinlock_t lock;
	# } seqlock_t;
	#
	# seqcount 	-> sequence counter
	# lock		-> lock to atomic update in case of writers
	# Has static initialization:	DEFINE_SEQLOCK(name)		and Dynamic initialization:		seqlock_init(struct seqlock_t *lock)
  # Each reader must read the sequence number twice, before reading the data, and after reading the data, to determine if there was any write access. If no writer, then the
	# sequence number will be the same. If a writer is still operating the value will be odd, and if the writer has operated but has finished it will be changed and even
	# kernel premption is disable for seqlock in terms of a write operation as it acquires a spinlock, but not for a read operation
  # Seqlocks cna be used with normal data variables, but not with pointers, which may already be freed during a write operation, leading to invalid access during a read 
	# operation in which an attempt is made to dereference a null pointer which would cause a kernel oops
  # Seqlocks have variants which can be used in interrupts
	# write_seqlock_irq(seqlock_t *sl);			write_sequnlock_irq(seqlock_t *sl);			write_seqlock_irqsave(seqlock_t *sl, unsigned long flags);	
	# write_sequnlock_irqrestore:(seqlock_t *sl, unsigned long flags); //flags to restore the state of interrupts (wrappers for spinloc_irq functions)
  # "Read Copy Update" (RCU) also supports concurrency between a single updater/write and multiple readers. It's often used to update lonked lists which are used all over the
    # kernel. It is useful in a scenario where there are a lot of reads, rare writes, and write should have priority compared to read. It is however expensive as it uses an
	# atomic increment/decrement for the reader count.
  # RCU solves the problem with using pointers in seq locks, by having pointers as a shared resource. It also doesn't require the reader to retry an operation or to use locks
    # The constraints of RCU are access to a shared resource should be mostly read and very rarely write, you cannot sleep into a region protected by RCU, and the protected
	# reesource should only be accessed via pointer. No locking is required for read operations, but locking is required for write operations. This allows read operations to
	# happen concurrently with write updates. However RCU cannot block readers or force them to retry their acceses like seqlocks. The Virtual File System and Networking
	# i.e. Routing Tables are examples of the use of RCU within the kernel code.
  # In RCU writers have to apply all their changes in a single atomic operation as the readers do not check if the data they read is consistent. 
  # RCU keeps track of all the pointers to the shared data structure. When a shared data structue is going to change, it 
	#	- First creates a copy of the structure  
	# 	- Performs the change
	# 	- After all the readers have finished reading on the old copy, pointer is updated to the new structure
	# The three steps above are the reason for the name "Read Copy Update", as it describes this mechanism
  # The Core of RCU is based around two primitives; 
		- RCU Read-side critical sections : rcu_read_lock/rcu_write_lock
		- RCU Synchronization : synchronize_rcu/call_rcu()
	Using these developers can build data structures which allow concurrent reading during updates. The following interfaces are found in <linux/rcupdate.h>
		a.	rcu_read_lock()
		b.	rcu_read_unlock()
		c.	synchronize_rcu() / call_rcu()
		d.	rcu_assign_pointer()
		e.	rcu_dereference()
  # When writing to RCU directly assigning a new pointer to a pointer protected by RCU is forbidden, you have to use the rcu_assign_pointer() function  
	# struct my_data  //example structure
	# {
	#	int key;
	#	int val;
	# }
	# struct my_data *global = NULL;  //global pointer pointing to null
	#
	# To perform a write operation with the example detailed above.	This ensures lock-free access and concurrent reads.
	# struct my_data *new_ptr;
	# new_ptr = kmalloc(sizeof(struct my_data), GFP_KERNEL);
	# new_ptr->key = 1;
	# new_ptr->val = 1234;
	# rcu_assign_pointer(global, new_ptr); // 	this is used to avoid Compiler optimizations which can alter the order of code instructions, memory barriers/compiler directives
	# 											are used to avoid this
  # When reading from RCU it is also not possible to directly dereference the pointer. You need to use the rcu_dereference() function. Additionally the code that dereferences
	# the pointer and uses the calls needs to be braced by rcu_read_lock() and rcu_read_unlock() to mark the beginning and end of an RCU read-side critical section. Example
	# struct my_data  //example structure
	# {
	#	int key;
	#	int val;
	# }
	# struct my_data *global = NULL;  //global pointer pointing to null
	# 
	# global = kmalloc(sizeof(struct my_data), GFP_KERNEL);
	#
	# To perorm a read operation with the example detailed above, use
	# struct my_data *tmp;
	# rcu_read_lock(); //this des not do  any actual locking such as spin locks, etc. It only marks the beginning of an RCU read-side critical section
	# tmp = rcu_dereference(global);
	# pr_info("key:%d\t val:%d\n", tmp->key, tmp->val);
	# rcu_read_unlock()
  # RCU should free after waiting for pre-existing RCU-Readers to complete, RCU should split updates/writes into two phases, removal & reclamation
	# Removal - replaces references to data items with the latest
	# Reclamation - fress the old reference
  # synchronize_rcu() does this by blocking until all reads on the old data are completed. It is calle in the write function and only fafter all reads using the old data
    # are completed does it unblock and allow a kfree() to be called. It knows this as preeemption is disabled during the critical section, and it unblocks once all of the
	# CPUs involved in the read process have completed one context switch, as by then it knows preemption is once again active and the read process is finished
  # A way to avoid a blocking call uis to register a callback which will be called when all the read-side critical sections using the old data are completed. 
	# void call_rcu(struct rcu_head *head, rcu_callback_t func);
	# This requires that an instance of rcu_head is embedded in the data structure
  # RCUs have a lot of benefits in terms of performance, Deadlock immunity, as they do not use locks, and real time latency for the aforementioned reason
  
  # There is a new release of the Linux kernel everey 2-3 months. Releases are time-based rather than feature based, so releases are not held up for features.
  # There are mainitaininers (indiviiduals) in charge of specific parts of the kernel such 
  s memory management, networking, scheduling, usb, pci. There's a file called MAINTAINERS
	# in the kernel source which lists the Linux maintainers
  # The Linux kernel source-tree is a directory that contains all of the kernel source. Using the kenrnel source-tree could build a new kernel, install and reboot machine to use new
	# kernel. Each subsystem maintainer has a kernel source-tree (see: https://git.kernel.org/pub/scm/linux/kernel/git)
  # Kernel are usually released evry 2-3 months. A new release candidate is released every week until the kernel is considered stable, after the next kernel is released the previous 
	# version is no longer supported. Long-trem kernels are dubbed (LTS - Long Term Support), and the last kernel of the year is selected as LTS. Older versions are supported for around 6 years
	# but current newer versions are only supported for around 2 years.
  # https://kernelnewbies.org/LinuxVersions - Kernel release dates by version number along with changes present. 
  # Kernel to use (according to priority)
	1. Supported kernel from your favourite Linux distribution
	2. Latest stable release
	3. Latest LTS release
	4. Older LTS release that is still being maintained
  # All the source code for the Linux kernel can be found on kernel.org - Linus tree is present at https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
  133a. mkdir ~/linux_mainline && cd ~/linux_mainline 
  133b. git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git   # To fetch the mainline source
  134a. mkdir ~/linux_stable && cd ~/linux_stable 
  134b. git clone https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git # To fetch the latest stable source
  # Many Linux distributions provide their own "longterm maintenance" kernels that may or may not be based on those maintained by kernel developers. Generally unless you have downloaded
	# compiled and installed your own version of kernel from kernel.org, you are running a distribution kernel.
  # The process of building the kernel has two parts - Configuring the kernel options, building the source with those options. Kernel config is kept in a file called .config at the top
	# of the kernel source tree. This file is not present in the downloaded Linux source code and needs to be created. It can be created from scratch, or by default configuration from
	# a running kernel version. Copying the configuration file of your present Linux distribution is the safest approach for the very first kernel install on any system.
  135. cat /boot/config-`uname -r` | less -N  # Contains the your current distro's configuration (For Ubuntu 20.04 is 11,242 lines long!)
  # Running the following command will generate a kernel configration file based on the current configuration of your Linux distribution:
  136. make oldconfig V=1   # V=1 turns on verbose output
  # In order to build the Linux kernel
  137. sudo make -j8  # 8 indicating the number of threads (dependent on number of processsors) to use
  # There are a list of key-codes on the left hand side referring to part of the compilation process. Ome are as follows:
	# CC: - Compiles the C file into a designated object file
	# CC [M]: - CC: means compiling a core part of the kernel, CC [M]: when compiling it into a module
	# LD: - File listed is being linked from a numbe`r of object files from the linker (LD
  138. sudo make ARCH=arm CROSS_COMPILE=/usr/local/bin/arm-linux  # ARCH=<archictecture|x86_64|arm|etc>, CC=<compiler>|CROSS_COMPILE=<cross compile tollchain>
  139. cd linux_source_directory && make help | less -N   # provides all the targets available for make, states generic targets, which are built on the normal make command such as vmlinux
  # Typical make commands
  140. make defconfig   # creates a .config file with default options from the ARCH supplied defconfig. If on x86 this is for example <source dir>/arch/x86/configs/x86_64_defconfig
						# If on an ARM machine this would be stored in <source dir>/arch/arm/configs/multi_v7_defconfig. For diff architecture then be "make ARCH=arm defconfig"
  141. ls <linux source>/arch/${ARCH}/configs/*defconfig*	# There are quite a range of default configurations within the arm config folder and these can be specified by giving the 
															# full filename of the default configuration file, i.e.e make ARCH=arm imx_v6_v7_defconfig
  142. vi <linux source>/arch/arm/Makefile 					# contains build flags for the generic make command 
          -> KBUILD_DEFCONFIG := multi_v7_defconfig			# specifies the default config to be used for the generic make command
  143. make ARCH=arm imx_v6_v7_defconfig V=1 && vimdiff .config arch/arm/configs/imx_v6_v7_defconfig  	# hghlights difference between defconfig file in source code and .config file
			# and .config file generate from make command, this is because the source code file stores values for all kernel configuration options, whilst the .config file only
			# stores those options which differ from the build machine's default configuration options. If an option isn't mentioned in defconfig, the buil;d system puts that option
			# into .config using it''s default value specified in the corrsponding KBUILD_DEFCONFIG or Kconfig
  144. make config 	# creates text-based configuration, options are prompted one after another, and all options need to be answered - access to former (answered) options not possible
  145. make menuconfig	# has a menu drven user interface which allows users to navigate forward and backward directly between features, allows loading and saving of files with
						# names different from .config, it provides a search fesature, and uses the ncurses library for the GUI refresh, if ncurses is not installed the menuconfig 
						# option fails. 
  146. sudo apt install libncurses5-dev  # install ncurses library
  147. make savedefconfig  # with create a defconfig file within the current working directory. Will only contain values that differ from the default values.	
  148. ./scripts/diffconfig <file1>  <file2>  # a diffing tool, built as a script within the source directory for the working code.
  149. ls -a | grep config.old   # generated when a new configuration file is genrated. Former configuration file is renamed to config.old
  150. sudo make clean    # will clean all folders and remove the System map, kallsyms an dtmp_vmlinux System.map and vmlinux and the vm linux object. However does not remove
				 # The configuration files, or some support for some of the Makefile build options. removes most generated files, keeps config, build support external modules
  151. sudo make mrproper  # will remove all generated files, keeps the config, and has enough support to build external modules. Runs clean on the scripts folder, which was not 
					  # happening before. 
  152. sudo make tags 	  # generates tag files for editors
  153. sudo distclean # performs all the operation of make mrproper, deletes temporary code navigation files: tags, cscope*, deletes files generated as a side-effect of working
					  # with patches: *.orig, *.rej, *.bak, deletes core dump files
  153. sudo make modules_install 	# will install the new kernel modules in place. will first verify the kernel has been successfully built properly. Then will install the 
									# static kernel into the /boot directory and name it based on the kernel version. Any needed ramdisk images wil be automatically created					 
									# using the modules that have just been installed during the modules_install phase. After this the kernel is succesfully installed and you 
									# safely reboot and try out your new kernel image.
  154. sudo make O=destdir menuconfig 	# The 'O=' option allows you to place the output of your kernel build elsewhere, so that you do not disturb the original source tree
  # The advantage of the above technique is that several users can be sharing the same kernel source tree. Even if there is only one user, that user can be working with 
	# multiple configurations, perhaps even multiple architectures, simultaneously. This approach leaves your source tree clear to, perhaps, continue searching for strings or
	# phrases without having to wade through all of the object files that are generated as part of a build. All make commands must be run from the top of the source tree.
  155. make drivers/pci 	# The kernel build system allows you to easily build a portion of the kernel.  This will allow you to build the files in drivers/pci
  156. make M=drivers/pci 	# This command will allow you to build the modules in that directory as the above command (155) will not build the modules 
  157. make drivers/usb/serial/usb-serial.ko	# This command will allow you to build a singular driver as a kernel object
  # The build system will build all the files needed for the usb-serial.ko kernel module, and do the final link to create the module.
  # After installing the kernel, in the /lib/modules/ folder the kernel you have just installed should be present under its build number a 'sudo make install' command, if the
    # kernel build is the latest, the image generated will be inserted into the /boot folder and inserted into the bootloader.
  158. sudo dd if=<OS_name>.img of=/dev/sdb bs=4096 && sync		# in order to write an OS image onto a form of bootable media such as an SD card or USB stick
  # SSH is by default disable on some kernel images. To enable ssh, create an empty file name 'ssh.txt' in the boot partition of the SD card.
  159. sudo mount -o rw /dev/sdb1 /media 
  160. sudo touch /media/ssh 
  161. sudo umount /media 
  # Connect SD card to Raspberry Pi and Ethernet cable and boot. you can get the IP Address of Raspberry PI from your Router Admin Page
  162. ssh pi@<ip address>  # if netstat is available can check that ssh is listening, and also can check from systemctl whether ssh.service is running
  # To build a kernel for the Raspberry Pi
  163. sudo apt install git bison flex libssl-dev -y
  164. mkdir ~/raspberry && cd ~/raspberry
  165. git clone https://github.com/raspberrypi/tools.git --depth=1 # Raspberry Pi provides a ready-to-use toolchain on their github repository. The "--depth=1" is here to tell
																	# tell got we only want the last revision, and not the whole history to be cloned
  166. echo PATH=$PATH:~raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin >> ~/.bashrc && source ~/.bashrc 	# updates the PATH variable 
  167. git clone --depth=1 https://github.com/raspberrypi/Linux 	# Retrieves the Linux source code
  168. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2709_defconfig  # bcm2709_defconfig is a configuration defined for raspberry Pi 3 
  169. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j8 # Do not need to define the gcc suffix of the CROSS_COMPILE toolchain, make will append 												
  # Next step is to mount the kernel image and the device tree blobs onto the SD card
  170. sudo mount /dev/sdb1 /media	
  171. sudo cp /media/kernel7.img /media/kernel7-backup.img	
  172. sudo cp arch/arm/boot/zImage /media/kernel7.img
  173. sudo cp arch/arm/boot/dts/overlays/*.dtb* /media/overlays/
  174. sudo cp arch/arm/boot/dts/overlays/README /media/overlays/
  # The next step is to copy the modules into a folder
  175. sudo mount /dev/sdb2 /mnt
  176. make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=/mnt modules_install   # INSTALL_MOD_PATH is used to set the alternate path for module installation
  # Finally plug the card into the Pi device and boot it.
  # In order to cross-compile a kernel module to load onto the Raspberry Pi  
  177. sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C ~/raspberrypi/linux/ M=${PWD} modules
	
  # Communiction with peripherals are referred to as I/O operations. Memory mapped I/O and Port mapped I/O are two methods of performing I/O between the CPU and peripherals.
		1. Memory Mapped I/O:
		# Uses the same address bus to address both memory and I/O devices
		# When an address is accessed by the CPU, it may refer to a portion of the physical RAM, or to the memory of the I/O device
		# The same CPU instuctions used to access the memory can also be used for accessing devices
		# Example: ARM Processors
		2. Port Mapped I/O:
		# Different address spaces for memory and I/O devices (can be achieved by the processor having an extra I/O pin, or might have an entire separate bus for I/P)
		# Accomplished by an extra "I/O" pin on the CPU's physical interface, or an entire bus dedicate to I/O
		# Uses a special class of CPU instructions to access I/O devices (IN and OUT) - separate to CPU instructions used to access memory
		# Example: Intel Processors
	# X86 systems employ both types of I/O
  # All peripheral I/O devices are controlled by writing and reading its registers. Most of the time a device has several registers, and ther are accessed at consecutive
	# addresses, either in the memory address space or the I/O address space. Each I/O device has at minimum the registers below:
		1. A data register (either readable or writable, depending on whether it is an input or output device)
		2. A control register (writable, for controlling device operations)
		3. A status register (readable, for determining device status -- in particular, whether it is ready to receive or provide data)
  # More complex devices (e.g. disks) will have multiple control and status registers.
  # Within the CPU, the physical RAM, and the I/O device, there are several buses, which are collecively referred to as the system bus. These are:
		1. Address Bus: Identifies the source or destination of data.
		2. Control Bus: control and timing information (Read/Write, clock signals)
		3. Data Bus: Carries data
    # How memory works is that the CPU puts the address of memory on the address bus, control bus will carry information on whether it is a read or write operation the memory 
	# itself is placed on the data bus. These steps can be formalised as:
		1. CPU puts the address of memory on the address bus
		2. Sends the control signal indicating a read or write operation
		3. Data is placed by the corresponding memory chip on the data bus
  # Nowadays this is handled by the memory controller. CPU communicates with the memory controller, which will do all of these operations 
  # We also have I/O devices:
		1. Serial Port
		2. Parallel Port
		3. Keyboard
		4. Mouse
  # On X86 we have a separate pin IO/M. If the pin is high its accessing the device, that means the memory won't respond and the I/O chip does. If it is 
	# low it is accessing memory from the RAM, so the memory rsponds, and the I/O devices stay put of communication.
  # X86 I/O Architecture:
	# I/O Bus: Data path connecting a CPU to an I/O device. 
	# I/O Ports: - Every device connected to an I/O Bus has its own set of I/O Addresses, also called I/O Ports. In the IBM architecture, I/O address space has 
		up to 2^16 8-bit I/O Ports (65536 8-bit I/O Ports)
				 - Two consecutive 8-bit ports may be regarded as a single 16-bit port, starting at an even address
				 - Two consecutive 16-bit ports may be regarded as a single 32-bit port, starting at an address divisible by 4
  # Since physical ports are differentiated by the number of bits, (8, 16 or 32 bits), there are different port access functions depending on their size
	# unsigned inb(int port)						: reads one byte (8 bits) from port
	# void outb(unsigned char byte, int port)		: writes one byte (8 bits) to port
	# unsigned inw(int port)						: reads two bytes (16-bit) ports
	# void outw(unsigned short word)				: writes (two bytes (16 bits to port)
	# unsigned inl(int port)						: reads four bytes (32-bits) from port
	# void outl(unsigned long word, int port)		: writes four bytes to port
  # These functions are found in linux/io.h
  # Some devices may have problems when the processor is trying to traansfer data too fast to and from the device. There are functions which add a delay by internally executing
    # a dummy instruction. These functions end with _p e.g. inb_p, outb_p, inw_p, outw_p, inl_p, outl_p
  178. cscope -R	# A command line interface for interactively examining a C program, -R symbol means recursively
  # Accessing I/O ports is relatively simple, however detecting which I/O ports may have been assigned to I/O devices may not be easy. Often a device driver must blindly
	# write into some I/O port to probe the hardware device. If this I/O port is used by some other hardware device, a system crash may occur. To prevent such situations
	# the kernel keeps track of I/O ports assigned to ecah hardware device by means of a struct resource. To get exclusive access to the I/O ports:
			# struct resource*request_region(unsigned long first,   /* first port/base port (as a hex value)*/
											  unsigned long n,       /* How many consecutive ports */
											  const char *name); 	 /* Which name you wish to give the struct resource */
    # This returns a struct resource pointer. The header file struct resource is contained in is <linux/ioport.h>
  # The return value is a struct resource pointer if the allocation succeeds, and NULL on failure. To release a reserved region one must use the release_region() function:
			# void release_region(unsigned long start,
								  unsigned long n);
  179. sudo cat /proc/ioports | less -N		# will provide info about all the I/O addresses currently assigned to I/O devices. This will not list all the X86 I/O Ports which
											# can be found in the chipset documentation (Section 9.3 I/O Map). 
  # In the case of Intel chips, port I/O access is handled by the Controller Hub (ICH/PCH). The I/O map is divided into Fixed and Variable address ranges. Fixed ranges cannot
	# be moved, but in some cases can be disabled. Variable ranges can be moved (The BIOS and/or other PCI devices or ACPI can adjust these values), and also be disabled.
  180. gcc <timerfile> -o <timerexec> -lrt  # in order to create an executable using posix timer apis must link with rt library via lrt 
  181. sudo chvt N 		# where N represents the terminal number to change terminals
  182. hostnamectl 		# prints Linux system information including architecture i.e. x86-64 or ARM
  # Using 'cscope -d'
  183-a. find . -name "*.c" -o -name "*.h" > cscope.files # recursively finds files ending in .c and .h in the current directory and saves their paths to a file named cscope.files
  183-b. cscope -b -q -k # -b tells cscope to build the database without launching the cscope interface, -q creates an inverted index for quicker symbol lookup, and -k is used to 
						# prevent cscope from including the standard C library headers. This process will create a cscope.out database file, along with cscope.in.out and 
						# cscope.po.out if you used the -q flag, which can be used by cscope to navigate the source code.
  183-c. cscope -d 		# The -d flag tells cscope to use the existing database without re-indexing the source files.
  # The kernel keeps track of I/O ports assigned to each hardware device by means of "resources" (struct resource)
  # To get exclusive access to I/O Ports:
  #   struct resource *request_region(unsigned long first, unsigned long n, const char *name);
  # Header File: #include <linux/ioport.h>
  # Return Value: non-NULL if the allocation succeeds, NULL on failure
  # To release a reserved region one must use the release_region() function
  #   void release_region(unsigned long start, unsigned long n);
  # request_region is a bookkeeping routine, to keep track of which drivers are using which port addresses. A single port doesn't have to be readable and at the same time writeable
  # A port can be read-only or write-only
  
  
  
