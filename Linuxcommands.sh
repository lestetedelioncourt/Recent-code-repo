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
 - delete_entry_timer_cb
 - rt_delete_rt_entry
 - rt_find_rt_entry
 - rt_dump_rt_table
	
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
 072a. readelf -a hello.ko     # Display information about ELF files,s.  The options control what particular information to display i.e. -a == all
 072b. readelf -d libfile.so   # will display the necessary dependencies of libfile.so 

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
 109c. apt-get install raspberrypi-kernel-headers -y  # prerequisite for kernel moodules on the Raspberry Pi
 109d. sudo insmod class_create.ko   
		#output: 	KERNEL[11216.875071] add      /class/myclass (class)
					UDEV  [11216.875340] add      /module/class_create (module)
					KERNEL[11216.875402] add      /module/class_create (module)
					:waitsUDEV  [11216.875412] add      /class/myclass (class)
 109e. ls -l /sys/class/myclass
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
  # Sequence Locks give the writer a higher priority when compared to the reader, which means the writer is allowed to modify the shared data, even when there are readers in
	# the critial section. If a write access took place while the data was read, the reader data is invalid and it must be read again. Identification of write accesses is 
	# realised with a counter. If another writer arrives , the writer uses a spinlock for mutual exclusion and hence will not interfere with the other writer.
  # A sequence lock uses a Sequence Counter (integer) and a spin lock. The data structure it uses is called seqlock_t and it is found in <linux/seqlock.h>. It is as follows:
	# typedef struct seqcount {
	# 	unsigned sequence;
	# } seqcount_t;#
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
  136a. make oldconfig V=1   # V=1 turns on verbose output
  136b. make help    # gives a listing of all make targets
  # In order to build the Linux kernel
  137. sudo make -j8  # 8 indicating the number of threads (dependent on number of processsors) to use
  # There are a list of key-codes on the left hand side referring to part of the compilation process. Ome are as follows:
	# CC: - Compiles the C file into a designated object file
	# CC [M]: - CC: means compiling a core part of the kernel, CC [M]: when compiling it into a module
	# LD: - File listed is being linked from a number of object files from the linker (LD
  # The kernel build system allows you to specify a different architecture from teh current system with the ARCH= argument, it also allows you to specify the specific compiler to use
  # for the build by using the CC= argument, or a cross-compile toolchain using th CROSS_COMPILE argument
  138a. sudo ARCH=x86_64 defconfig  # building an x86_64 kernel with default configuration
  138b. sudo make ARCH=arm CROSS_COMPILE=/usr/local/bin/arm-linux  # ARCH=<archictecture|x86_64|arm|etc>, CC=<compiler>|CROSS_COMPILE=<cross compile tollchain>
  139. cd linux_source_directory && make help | less -N   # provides all the targets available for make, states generic targets, which are built on the normal make command such as vmlinux
  # Typical make commands
  140. make defconfig   # creates a .config file with default options from the ARCH supplied defconfig. If for x86 this is for example <source dir>/arch/x86/configs/x86_64_defconfig
						# If for an ARM machine this would be stored in <source dir>/arch/arm/configs/multi_v7_defconfig. For diff architecture then be "make ARCH=arm defconfig"
  141. ls <linux source>/arch/${ARCH}/configs/*defconfig*	# There are quite a range of default configurations within the arm config folder and these can be specified by giving the 
															# full filename of the default configuration file, i.e.e make ARCH=arm imx_v6_v7_defconfig
  142. vi <linux source>/arch/arm/Makefile 					# contains build flags for the generic make command 
          -> KBUILD_DEFCONFIG := multi_v7_defconfig			# specifies the default config to be used for the generic make command
  143. make ARCH=arm imx_v6_v7_defconfig V=1 && vimdiff .config arch/arm/configs/imx_v6_v7_defconfig  	# hghlights difference between defconfig file in source code and .config file
			# and .config file generate from make command, this is because the source code file stores values for all kernel configuration options, whilst the .config file only
			# stores those options which differ from the build machine's default configuration options. If an option isn't mentioned in defconfig, the buil;d system puts that option
			# into .config using it''s default value specified in the corrsponding KBUILD_DEFCONFIG or Kconfig
  144. make config 	# creates text-based configuration, options are prompted one after another, and all options need to be answered - access to former (answered) options not possible
  145. sudo apt install libncurses5-dev -y # necessary for using make menuconfig
  146. make menuconfig	# has a menu drven user interface which allows users to navigate forward and backward directly between features, allows loading and saving of files with
						# names different from .config, it provides a search fesature, and uses the ncurses library for the GUI refresh, if ncurses is not installed the menuconfig 
						# option fails. 
  147. make savedefconfig  # will create a defconfig file within the current working directory. Will only contain values that differ from the default values.	
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
  154a. sudo make O=destir  # a. build, b. configure
  154b. sudo make O=destdir menuconfig 	# The 'O=' option allows you to place the output of your kernel build elsewhere, so that you do not disturb the original source tree
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
  # inserting custom driver into Linux kernel specifially for Raspberry Pi, first on Ubuntu systems   -    'vi arch/arm/tools/syscallnr.sh'    -> Replace: '#!/bin/sh'    with    '#!/bin/bash'
  168a. cp /path/to/CustomLinuxDriver.c /linux-source-code/misc/drivers/
  168b. echo -e "config CUSTOM_LINUX_DRIVER_NAME
        tristate "Custom Linux Driver"
        depends on ARCH_BCM2835
        help
          This driver implements GPIO handling using softirqs
	  
          for the Raspberry Pi.

          If unsure, say N." >> drivers/misc/Kconfig
  168c. echo "obj-$(CUSTOM_LINUX_DRIVER_NAME) += CustomLinuxDriver.o" >> /linux-source-code/misc/drivers/Makefile
  168d. make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig -> Device Drivers -> Misc devices -> "Custom Linux Driver"      # Select it with 'M' (for module) or '*' (for built-in) then "Save and exit"
  169a. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- clean
  169b. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mrproper
  169c. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcmrpi_defconfig 
  169d. cd <source dir> && make ARCH=arm CROSS_COMPILE=arm-linux-arch/arm/tools/syscallnr.shgnueabihf- menuconfig  -> Device Drivers -> Misc devices -> "Custom Linux Driver"      # Select it with 'M' (for module) or '*' (for built-in) then "exit (save and exit)"	
  169e. sed -i "1s,bin/sh,bin/bash," arch/arm/tools/syscallnr.sh    # if on an ubuntu system helps prevent build errors for cross-compilation
  169f. cd <source dir> && make SHELL=/bin/bash ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 # Do not need to define the gcc suffix of the CROSS_COMPILE toolchain, make will append 
  # The kernel image is saved to <source directory>/arch/arm/boot/
    # Image - Uncompressed kernel image.
    # zImage - Compressed kernel image.
    # uImage - U-Boot image (if you have configured for U-Boot).
  # Device tree blobs are saved to arch/arm/boot/dts/ extension directory is broadcom for the Raspberry Pi
# The Raspberry Pi 1 uses an ARMv6 processor, so you need a cross-compiler that supports ARMv6. Toolchain Recommendation: Use the arm-linux-gnueabi- cross-compiler (without the hf suffix). The hf in gnueabihf stands for "hard float," which is typically for ARMv7.
# I am unsure of subsequent steps 170 onward, but I know these work for Raspbberry Pi 1:
  170. cp arch/arm/boot/zImage /path/to/sdcard/boot/<kernel_name>.img
  171. cp arch/arm/boot/dts/*/bcm*dtb /path/to/sdcard/boot/
  172. vi /boot/firmware/config.txt    ->   kernel=<kernel_name).img
# Next step is to mount the kernel  
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
											# can be found in the chipset documentation (Section 9.3 I/O Map). It only lists I/O Ports and regions that have been claimed by the
											# kernel using request_region. It's not the complete list I/O ports/devices available, just those claimed by various drivers.
  # In the case of Intel chips, port I/O access is handled by the Controller Hub (ICH/PCH). The I/O map is divided into Fixed and Variable address ranges. Fixed ranges cannot
	# be moved, but in some cases can be disabled. Variable ranges can be moved (The BIOS and/or other PCI devices or ACPI can adjust these values), and also be disabled.
  180. gcc <timerfile> -o <timerexec> -lrt  # in order to create an executable using posix timer apis must link with rt library via lrt 
  181. sudo chvt N 		# where N represents the terminal number to change terminals
  182. hostnamectl 		# prints Linux system information including architecture i.e. x86-64 or ARM
  # Using 'cscope -d'
  183a. find . -name "*.c" -o -name "*.h" > cscope.files # recursively finds files ending in .c and .h in the current directory and saves their paths to a file named cscope.files
  183b. cscope -b -q -k # -b tells cscope to build the database without launching the cscope interface, -q creates an inverted index for quicker symbol lookup, and -k is used to 
						# prevent cscope from including the standard C library headers. This process will create a cscope.out database file, along with cscope.in.out and 
						# cscope.po.out if you used the -q flag, which can be used by cscope to navigate the source code.
  183c. cscope -d 		# The -d flag tells cscope to use the existing database without re-indexing the source files.
  # The kernel keeps track of I/O ports assigned to each hardware device by means of "resources" (struct resource)
  # To get exclusive access to I/O Ports:
  #   struct resource *request_region(unsigned long first, unsigned long n, const char *name);
  # Header File: #include <linux/ioport.h>
  # Return Value: non-NULL if the allocation succeeds, NULL on failure
  # To release a reserved region one must use the release_region() function
  #   void release_region(unsigned long start, unsigned long n);
  # request_region is a bookkeeping routine, to keep track of which drivers are using which port addresses. A single port doesn't have to be readable and at the same time writeable
  # A port can be read-only or write-only
  
  # ports 70-71 represent the real time clock. This is denoted in /proc/iopots as '0070-0071 : rtc_cmos  - Port 0x70 is the Address port, 0x71 is Data port 
																					0070-0071 : rtc0'
  # This is an integrated circuit that maintains the date and the time of day, even when the computer is switched-off and unplugged
  # In addition it includes allarm functionality and can generate interrupts at specified times of the day, can generate interrupts periodically, and it includes at least 50 
  # non-volatile one-byte registers, which are usually used by the BIOS to store the PC's configuration
  # Each register has an address, some registers are read only and some are read-write. First 10 registers reserved for time related functionality, following 4 reserved for control of the RTC
  # To read/write a register of the RTC requires always:
	# 1. Writing the address of the register to the RTC_ADDR_REG (0x70)
	# 2. Reading/Writing one byte from/to the RTC_DATA_REG (0x71)
  # Here are the first 14 addresses
    #	0x00: Seconds - The current second.
    #	0x01: Seconds Alarm - An alarm setting for seconds.
    #	0x02: Minutes - The current minute.
    #	0x03: Minutes Alarm - An alarm setting for minutes.
    #	0x04: Hours - The current hour.
    #	0x05: Hours Alarm - An alarm setting for hours.
    #	0x06: Day of the Week - The current day of the week (1 to 7).
    #	0x07: Date of the Month - The current date of the month.
    #	0x08: Month - The current month.
    #	0x09: Year - The current year.
    #	0x0A: Register A - Control register for the RTC, including update-in-progress flag.
    #	0x0B: Register B - Control register that can enable the clock, set 24-hour mode, etc.
    #	0x0C: Register C - RTC status register that includes flags for periodic interrupts, alarms, etc.
    #	0x0D: Register D - RTC status register that indicates if the RTC power has been lost.
    #
    #	ADDRESS LOCATION    FUNCTION              DECIMAL RANGE     BINARY DATA MODE RANGE      BCD DATA MODE RANGE
    #	0                   Seconds               0-59              00-3B                      00-59
    #	1                   Seconds Alarm         0-59              00-3B                      00-59
    #	2                   Minutes               0-59              00-3B                      00-59
    #	3                   Minutes Alarm         0-59              00-3B                      00-59
    #	4                   Hours, 12-hour Mode   1-12              01-0CAM, 81-8CPM           01-12AM, 81-92PM
    #						Hours, 24-hour Mode   0-23              00-17                      00-23
    #	5                   Hours Alarm, 12-hour  1-12              01-0CAM, 81-8CPM           01-12AM, 81-92PM
    #						Hours Alarm, 24-hour  0-23              00-17                      00-23
    #	6                   Day of the Week       1-7               01-07                      01-07
    #	7                   Date of the Month     1-31              01-1F                      01-31
    #	8                   Month                 1-12              01-0C                      01-12
    #	9                   Year                  0-99              00-63                      00-99
    #
    #   Status Register B
    #   
    #   Bit Position  | Interpretation
    #   -----------------------------------
    #   7             | Enable Cycle Update
    #   6             | Enable Periodic Interrupt
    #   5             | Enable Alarm Interrupt
    #   4             | Enable Update-End Interrupt
    #   3             | Enable Square Wave Output
    #   2             | Data Mode: 0 - BCD / 1 - Binary
    #   1             | 12/24 Hour Mode: 0 - 12 Hour / 1 - 24 Hour
    #   0             | Daylight saving enabled: 1 enabled / 0 disabled
  184. sudo hwclock --debug  The --debug flag instructs hwclock to provide verbose output, detailing each step it takes to access and read the hardware clock
  #In recent versions of the kernel --debug has been deprecated. Use the --verbose flag instead
  185. sudo hwclock --verbose
		>>hwclock from util-linux 2.37.2
		>>System Time: 1706397205.990811
		>>Trying to open: /dev/rtc0
		>>Using the rtc interface to the clock.
		>>Assuming hardware clock is kept in UTC time.
		>>Waiting for clock tick...
		>>...got clock tick
		>>Time read from Hardware Clock: 2024/01/27 23:13:26
		>>HW clock time : 2024/01/27 23:13:26 = 1706397206 seconds since 1969
		>>Time since last adjustment is 1706397206 seconds
		>>Calculated Hardware Clock drift is 0.000000 seconds
		>>2024-01-27 23:13:25.590523+00:00
  
  # A keyboard consists of a large matrix of keys, monitored by an onboard processor, which monitors which keys are being pressed and sends data to the host, and
  # takes care of all the debouncing. The motherboard contains a keyboard controller in charge of decoding all of the data received from the keyboard and informing
  # software what's going on. An Intel 8042 compatible microcontroller is used as the PC's keyboard controller. In modern PCs is integrated into motherboard's chipset.
  186. dmesg | grep 8042  # no keyboard connected
		>> [    0.751063] i8042: PNP: No PS/2 controller found.
		>> [    0.751066] i8042: Probing ports directly.
		>> [    0.752472] i8042: No controller found
  187. dmesg | grep 8042 # keyboard detected
		>> [    1.897453] i8042: PNP: PS/2 Controller [PNP0303:PS2K,PNP0f03:PS2M] at 0x60,0x64 irq 1,12
		>> [    1.900197] serio: i8042 KBD port at 0x60,0x64 irq 1
		>> [    1.900203] serio: i8042 AUX port at 0x60,0x64 irq 12
		>> [    1.907073] input: AT Translated Set 2 keyboard as /devices/platform/i8042/serio0/input/input2
		>> [    3.287501] input: ImExPS/2 Generic Explorer Mouse as /devices/platform/i8042/serio1/input/input4
  # Keyboard's processor monitors keyboard's matrix of keys, sending "scan codes" separated into "make" (sent when key is pressed or held down) and "break" (sent when a key 
  # is released). Each key is assigned a unique "make" code and "break" code.
  188. showkey --scancodes  # shows the make and break codes for each key press	
  # "Typematic" refers to what occurs after you hold a key down. When you first press a key the character will immediately appear on the screen, after a short delay, a stream
  # of characters will appear in rapid succession until the key is released. The "typematic delay" is the delay between the first and second character. The "typematic rate" is
  # the number of characters that appear on screen per second after the typematic delay. 
  # Typematic delay can range from 0.25 seconds to 1.00 second. Typematic rate can range from 2.0 cps to 30.0 cps
  # When reset keyboards perform a BAT (Basic Assurance Test) and load the following defaults: Typematic delay 500ms, Typematic rate 10.9cps
  # When entering BAT, the keyboard enables its three LED indicators, and turns them off when BAT has completed. Success code (0xAA) or Error (0xFC) then sent to host.
  # The Keyboard has two I/O Ports 0x60 and 0x64. Read and writes may access different internal registers. It has three registers: 
	# 1. The Data Byte is used for reading data received from PS/2, or writing data to a PS/2 device (Read/Write)
	# 2. Command Byte is when the CPU writes to port 0x64 (Write)
	# 3. Status Byte is when CPU reads from port 0x64 (Read)
  # Keyboard controler accepts commands and processes them. To send a command to the controller write the command byte to port 0x64: arguments, if any, must be passed using address 0x60
  # Results are returned on port 0x60. Should always test the Output Buffer Full flag before writing commands or parameters to 8042
	# 0x20 - Sending this data as an instruction indicates to read the Command Byte (Returns Command bBte)
	# 0x60 - Sending this data as an instruction writes the Command Byte, stores parameter as Command Byte
	
		>> AT Compatible
		>> =============
		>> 	MSB					LSB
		>> 	------------------------------------------
		>> 	|- | XLAT | PC | _EN | OVR | SYS | - |INT|
		>> 	------------------------------------------
		>> 
		>> PS/2 Compatible
		>> ==================	
		>> 
		>> 
		>> 	--------------------------------------------
		>> 	|- | XLAT |_EN2 | _EN |    | SYS |INT2 |INT|
		>> 	--------------------------------------------
		>> 
		>> 
		>> 
		>> INT (Input Buffer Full Interrupt) - When set, IRQ 1 is generated when data is available in
		>> the input buffer.
		>> 	0: IBF Interrupt Disabled - You must poll STATUS<IBF> to read input.
		>> 	1: IBF Interrupt Enabled - Keyboard driver at software int 0x09 handles input.
		>> 
		>> SYS (System Flag) - Used to manually set/clear SYS flag in Status register.
		>> 	0: Power-on value - Tells POST to perform power-on tests/initialization.
		>> 	1: BAT code received - Tells POST to perform "warm boot" tests/initiailization.
		>> 
		>> OVR (Inhibit Override) - Overrides keyboard's "inhibit" switch on older motherboards.
		>> 	0:Inhibit switch enabled - Keyboard inhibited if pin P17 is high.
		>> 	1: Inhibit switch disabled - Keyboard not inhibited even if P17 = high.
		>> 
		>> _EN (Disable keyboard) - Disables/enables keyboard interface.
		>> 	0: Enable - Keyboard interface enabled.
		>> 	1: Disable - All keyboard communication is disabled.
		>> 
		>> PC ("PC Mode") - ???Enables keyboard interface somehow???
		>> 	0: Disable - ???
		>> 	1: Enable - ???
		>> 
		>> XLAT (Translate Scan Codes) - Enables/disables translation to set 1 scan codes.
		>> 	0: Translation disabled - Data appears at input buffer exactly as read from keyboard
		>> 	1: Translation enabled - Scan codes translated to set 1 before put in input buffer
		>> 
		>> INT2 (Mouse Input Buffer Full Interrupt) - When set, IRQ 12 is generated when mouse
		>> data is available.
		>> 	0: Auxillary IBF Interrupt Disabled -
		>> 	1: Auxillary IBF Interrupt Enabled -
		>> 
		>> _EN2 (Disable Mouse) - Disables/enables mouse interface.
		>> 	0: Enable - Auxillary PS/2 device interface enabled
		>> 	1: Disable - Auxillary PS/2 device interface disabled
		
		>> Status Register (Read 0x64h)
		>> ==============================
		>> 
		>> Bit	Meaning
		>> 0	Output buffer status 
		>> 	0 = empty -  Okay to write to port 0x60
		>> 	1 = full  - Don't write to port 0x60
		>> 
		>> 1	Input buffer status 
		>> 	0 = empty - No unread input at port 0x60
		>> 	 1 = full - New input can be read from port 0x60
		>> 
		>> 2	System Flag
		>> 	1 =  System has already beed initialized.
		>> 	0 = System is in power-on reset.
		>> 3	Command/data
		>> 	0 = data available at port 60h
		>> 	1 = command available at port 64h
		>> 
		>> 4	Keyboard Active
		>> 	0 = disabled
		>> 	1 = enabled
		>> 
		>> 5	Error Detected
		>> 	0 = No Error
		>> 	1 = Error in transmission
		>> 
		>> 6	Time-out error 
		>> 	0 = no error
		>> 	1 = time-out error
		>> 
		>> 7	Parity error 
		>> 	0 = no error
		>> 	1 = parity error

  # PC-compatible systems have 64K I/O ports, all can be controlled from user space. Before you access any ports, permission to do so. Permission for I/O ports on Linux is controlled by two functions
	# ioperm() - controls access permissions to permissions mentioned in the parameter
	# iopl() - changes I/O privilege level of calling process, allowing among other things, unrestricted access to all ports
  # Only the super-user can invoke both these functions
	# int ioperm(unsigned long from, unsigned long num, int turn_on);
  # ioperm() sets the port access permission bits for the calling thread for num bits starting from portaddress 'from'.
  # if turn_on is nonzero, then permission for the specified bits is enabled. if turn_on is zero, the permission for the specified bits is disabled
	# Example: ioperm(0x200, 3, 1) would give access to ports 0x200 through 0x202 (a total of 3 ports)
  # inb(), outb(), inw() and outw() have macro equivalents inb_p(), outb_p(), inw_p() and outw_p(), but do an additional short  (one microsecond) delay after port access 
  # if user space application does not use ioperm() or iopl() to access I/O ports, it will cause the application to have a segmentation fault
    # int iopl(int level);
  # iopl() changes the I/O privilege level of the caling process, as specified by the two least significant bits in level, the I/O privilege level of a normal process is 0
  # The keyboard controller has a pin which goes to the reset pin of the CPU. A Command Byte of 0xFE means "pulse the reset line down for 6ms"
  
  # 8254 PIT on Keyboard Controller perfoms timing and counting functions using three 16-bit counters. Timer channel 2 of 8254 is assigned to PC Speaker on PCs. Timer chip has 4 I/O Ports
	# Port 0x40: Counter 0
	# Port 0x41: Counter 1
	# Port 0x42: Counter 2
	# Port 0x43: Control Word Register (shared)
  # To program a timer, an instruction must be written in 0x43
	>> outb(0xb6, 0x43);
	# 0xb6 = 10 11 011 0 
	# 10 -> Counter 2
	# 11 -> First LSB then MSB
	# 011 -> Timer Mode (Square Wave)
	# After this write the counter value in 0x42 
  # Another way to access I/O ports is to open() /dev/port for reading and/or writing. Slower han iper/iopl as code flow has to pass through a kernel driver
	
  # Most widely supported form of IO is memory mapped IO. A part of the CPUS address space is interpreted as access to devices. Some architectures define devices to be at a fixed address, but most have some method
  # of discovering devices. The advantage of memory mapped I/O is that it keeps the instruction set small. An I/O address space is created in the CPU because the address space of processors was limited.
  # Total address space is still 64KB, even after moving from 16-bit registers to 64-bit registers.
  # Examples of I/O Memory
	# Holding Video Data
	# Ethernet Packets
	# Device Registers
  # There are functions equivalent to request_region() and release_region(), but for I/O memory
	# struct resource *request_mem_region(unsigned_long_start, unsigned long len, char* name);
	# void release_mem_region(unsigned long start, unsigned long len);
  # request_mem_region: informs kernel that your driver is going to use this range of I/O addresses, and prevents other drivers from using it throught request_mem_region
  # The kernel runs in virtual address space, and like user space the kernel accesses memory through page tables. When the kernel needs to access memory mapped I/O devices, it must set up page table mapping.
	# void *ioremap(unsigned long phys addr, unsigned long size);
	# void iounmap(void *addr);
  # A successful call to ioremap() returns a kernel virtual address corresponding to the start of a requested physical address range - the return address is not meant to be dereferenced directly though for (what
  # are mostly architecture specific regions). Ther are functions to read and write data using memory mapped by ioremap()
	# unsigned int ioread8(void *addr);
	# unsigned int ioread16(void *addr);
	# unsigned int ioread32(void *addr);
	# void iowrite8(u8 value, void *addr);
	# void iowrite16(u16 value, void *addr);
	# void iowrite32(u32 value, void *addr);
  189. sudo cat /proc/iomem  # provides a map of memory ranges used by various devices and drivers in the system
  # Memory mapped IO registers will have side effects so the user must force the compiler to avoid these optimizations by using the 'volatile' keyword, and can also avoid hardware caching by using 'barriers'. ioread 
  # functions internally perform the aforementioned operations. This is why we do not access addresses directly by dereferencing and instead use ioread(). This can be found by using cscope -d on the linux kernel
  
  # The hardware random number generator is a device that generates random numbers from a physical process, the Intel 82802 Firmware Hub chip included a hardware random number generator. The random number generator is 
  # dedicated hardware that uses system thermal noise to generate random and indeterministic alues
  # The hardware status register is used to determine whether or not an RNG device is present on the Firmware Hub and, if so, whether it is enabled for use. Its physical address is 0xFFBC015F
  # It can be bitmasked with the values 0x40, which checks if bit 6 is 1 (read only) which indicates whether an RNG is present on the Firmware Hub device. It can also be bitmasked with the value 0x01 which checks the 0
  # bit to see whether RNG is enabled. If set to 1, the RNG will generate random data.
  # The RNG Status register at physical address 0xFFBC0160 determines whether or not the RNG Data register contains valid random data. The RNG Data register should never be read until the RNG Status register indicates 
  # that the RNG Data register is valid. Each time the RNG Data register is read, the RNG status nit is cleared, and it remains cleared until the RNG Data Register is filled with new random data.
  # Bit Mask								Description
	============================================================================
	0x01									(Bit 0 - read-only) Data Available:
											If this bit is read as 1, the RNG Data register contains valid random data
											If this bit is read as 0, the RNG Data register contains invalid data
	
  # The RNG Data Register is at address 0xFFBC0161, and it contains a byte of random data	

  # The Linux kernel provides the function ioport_map() whcih maps I/O ports and makes them appear as I/O memory. It also contains the unmapping function ioport_unmap()
	# void *ioport_map(unsigned long port, unsigned int count);
	# void ioport_unmap(void *addr);
  # NB: I/O Ports must still be allocated with request_region() before they can be remapped in this way.
	
  # /dev/mem is a character device file that is an image of the main memory of the computer, byte addresses in /dev/mem are interpreted as physical memory addresses, '
  190. man 4 mem    # provides more information.
  191. hexdump -C /dev/mem   # allows analysis of system memory contents (provides direct access to physical memory)
  192. cat /dev/mem | strings  # allows analysis of the strings contained within the binary file
  193. cat /dev/mem | string -n 20    # allows analysis of strings greater than 20 characters
  194. cat /boot/config-`uname -r` | grep CONFIG_STRICT_DEVMEM   # kernel configuration option which limits the areas accesssible via /dev/mem. It is enabled by default on x86 and ARM kernel builds
																 # with this option disabled, the root user from user space can access all kernel and user-space memory through /dev/mem
  # devmem is a small program that reads and writes from physical memory using /dev/mem. Usage: devmem ADDRESS [WIDTH [VALUE]], ADDRESS Address to act upon, WIDTH (8/16/...), VALUE Data to be written
  195. devmem 0x00000000 8     # reads 8 bits from memory location
  # UART0 is mapped to 0x101f1000, the code that emulates the serial port from within qemu implements a subset of the functionalities of the PL011 PrimeICell UART from ARM. 
  # The UARTDR register that is used to transmit (when writing in the register) and receive (when reading) bytes; this regiter is place at offset 0x0
  196. sudo apt install devmem2 -y  # for Ubuntu
  #In order to dump PC BiOS data to a file
  197. grep ROM /proc/iomem s# Starting Address = 0xf0000 = 960KB, Ending Address = 0xfffff = 1024KB
  198. sudo dd if=/dev/mem of=pcbios.bin bs=1k skip=960 count=64
  199. cat pcbios.bin | strings -n 20
  # The System Management BIOS (SMBIOS) is a standard developed by DMTF (Distributed Management Task Force). The purpose of this standard is to allow the operating system to retrieve information about the PC
  # The specification addresses how motherboard and system vendors present management information about their products ina standard format by extending the BIOS interface on Intel Architectures
  # Info such as make, model, serial number, BIOS version, processor, memory configuration, etc.
  # On boot SMBIOS will put a table somewhere in memory. The SMBIOS Entry Point table is located in System ROM, somewhere betweenn addresses 0xF0000 and 0xFFFFF and must be on a 16-byte boundary.
  # To find the specific start of the table it necessary to search that region of memory for the string "_SM_"
  200. hexdump -C /dev/mem | grep "_SM_"  # will find the start of the SMBIOS Entry Point Table
  # The entry point table has the following structure for SMBIOS 2 and below (the structure is different for SMBIOS 3):
		>>  struct SMBIOSEntryPoint {
		>>  	char EntryPointString[4];    //This is _SM_
		>>  	uchar Checksum;              //This value summed with all the values of the table, should be 0 (overflow)
		>>  	uchar Length;                //Length of the Entry Point Table. Since version 2.1 of SMBIOS, this is 0x1F
		>>  	uchar MajorVersion;          //Major Version of SMBIOS
		>>  	uchar MinorVersion;          //Minor Version of SMBIOS
		>>  	ushort MaxStructureSize;     //Maximum size of a SMBIOS Structure (we will se later)
		>>  	uchar EntryPointRevision;    //...
		>>  	char FormattedArea[5];       //...
		>>  	char EntryPointString2[5];   //This is _DMI_
		>>  	uchar Checksum2;             //Checksum for values from EntryPointString2 to the end of table
		>>  	ushort TableLength;          //Length of the Table containing all the structures
		>>  	uint TableAddress;	     //Address of the Table
		>>  	ushort NumberOfStructures;   //Number of structures in the table
		>>  	uchar BCDRevision;           //Unused
		>>  };
  # TableAddress contains the address of the table that contains all the structures with information about the PC.
  # All of the structures are located from [TableAddress] to [TableAddress + TableLength]. 
  # The structures are located directly adjacent to each other in memory, with a new structure beginning as soon as another one ends.
  # Each structure is composed of a header, a structure specific table, and a string table.
  # The format of the header is as follows.
		>> struct SMBIOSHeader {
		>> 	uchar Type;
		>> 	uchar Length;
		>> 	ushort Handle;
		>> };
  # Located at TableAddress is a SMBIOS header. 
  # The value of Type indicates what element the structure contains information about.
  # Length indicates the size of header + data table.
  # The strings are not included in the length.
  # Immediately after the end of the header is the data.
  # At the end of the data table (Address + Length), the strings section starts.
  # Each string is NULL terminated and is limited to 64 characters. 
  # Strings are referenced within tables by using an index into the string table 
  # The first string begins immediately after the data, and the second string begins immediately after that, etc.
  # The string section itself is terminated by two consecutive zero bytes. 
  # The next table begins immediately after the end of the string section.
  # Header types are:
	# Code	Description
	# 0		BIOS Information
	# 1		System Information
	# 2		Mainboard Information
	# 3		Enclosure/Chasis Information
	# 4		Processor Information
	# 7		Cache Information
	# 9		System Slots Information
	# 16	Physical Memory Array
	# 17	Memory Device Information
	# 19	Memory Array Mapped Address
	# 20	Memory Device Mapped Address (optional as of SMBIOS 2.5)
	# 32	System Boot Information
  201. hexdump -C -s 0xe1000 /dev/mem | less  # starts hexdump at location specified
  # dmidecode is a tool for dumping a computer's SMBIOS/DMI table contents in a human-readable format. When you run dmidecode it will try to locate the DMI table. 
  # It will first try to read the DMI table from sysfs. If failed it will try to read memory directly from /dev/mem. If it succeeds in locating a valid DMI table, it'll parse this table and display it
  202a. dmidecode -s bios-version   		# -s, --string KEYWORD
  202b. dmidecode -s bios-vendor			# -s, --string KEYWORD
  202c. dmidecode -s system-manufacturer	# -s, --string KEYWORD
  202d. dmidecode -s system-serial-number	# -s, --string KEYWORD
  203. dmidecode --no-sysfs					# Do not attempt to read DMI data from sysfs files
  204. dmidecode
		>> # dmidecode 3.2
		>> /sys/firmware/dmi/tables/smbios_entry_point: Permission denied
		>> Scanning /dev/mem for entry point.
		>> /dev/mem: Permission denied
  205. sudo hexdump -C /sys/firmware/dmi/tables/smbios_entry_point
		>> 00000000  5f 53 4d 5f 7d 1f 02 05  ff 00 00 00 00 00 00 00  |_SM_}...........|
		>> 00000010  5f 44 4d 49 5f 58 c2 01  00 10 0e 00 0a 00 25     |_DMI_X........%|
		>> 0000001f
  206. sudo dmidecode
		>> # dmidecode 3.2
		>> Getting SMBIOS data from sysfs.
		>> SMBIOS 2.5 present.
		>> 10 structures occupying 450 bytes.
		>> Table at 0x000E1000.
		>> 
		>> Handle 0x0000, DMI type 0, 20 bytes
		>> BIOS Information
		>> 	Vendor: innotek GmbH
		>> 	Version: VirtualBox
		>> 	Release Date: 12/01/2006
		>> 	Address: 0xE0000
		>> 	Runtime Size: 128 kB
		>> 	ROM Size: 128 kB
		>> 	Characteristics:
		>> 		ISA is supported
		>> 		PCI is supported
		>> 		Boot from CD is supported
		>> 		Selectable boot is supported
		>> 		8042 keyboard services are supported (int 9h)
		>> 		CGA/mono video services are supported (int 10h)
		>> 		ACPI is supported
		>> 
		>> Handle 0x0001, DMI type 1, 27 bytes
		>> System Information
		>> 	Manufacturer: innotek GmbH
		>> 	Product Name: VirtualBox
		>> 	Version: 1.2
		>> 	Serial Number: 0
		>> 	UUID: 817774d2-a644-ac4f-b1e3-af0c346decd2
		>> 	Wake-up Type: Power Switch
		>> 	SKU Number: Not Specified
		>> 	Family: Virtual Machine
		>> 
		>> Handle 0x0008, DMI type 2, 15 bytes
		>> Base Board Information
		>> 	Manufacturer: Oracle Corporation
		>> 	Product Name: VirtualBox
		>> 	Version: 1.2
		>> 	Serial Number: 0
		>> 	Asset Tag: Not Specified
		>> 	Features:
		>> 		Board is a hosting board
		>> 	Location In Chassis: Not Specified
		>> 	Chassis Handle: 0x0003
		>> 	Type: Motherboard
		>> 	Contained Object Handles: 0
		>> 
		>> Handle 0x0003, DMI type 3, 13 bytes
		>> Chassis Information
		>> 	Manufacturer: Oracle Corporation
		>> 	Type: Other
		>> 	Lock: Not Present
		>> 	Version: Not Specified
		>> 	Serial Number: Not Specified
		>> 	Asset Tag: Not Specified
		>> 	Boot-up State: Safe
		>> 	Power Supply State: Safe
		>> 	Thermal State: Safe
		>> 	Security Status: None
		>> 
		>> Handle 0x0007, DMI type 126, 42 bytes
		>> Inactive
		>> 
		>> Handle 0x0005, DMI type 126, 15 bytes
		>> Inactive
		>> 
		>> Handle 0x0006, DMI type 126, 28 bytes
		>> Inactive
		>> 
		>> Handle 0x0002, DMI type 11, 7 bytes
		>> OEM Strings
		>> 	String 1: vboxVer_6.1.30
		>> 	String 2: vboxRev_148432
		>> 
		>> Handle 0x0008, DMI type 128, 8 bytes
		>> OEM-specific Type
		>> 	Header and Data:
		>> 		80 08 08 00 F7 15 26 00
		>> 
		>> Handle 0xFEFF, DMI type 127, 4 bytes
		>> End Of Table
  207. sudo dmidecode -s bios-versions
		>> Invalid string keyword: bios-versions
		>> Valid string keywords are:
		>>   bios-vendor
		>>   bios-version
		>>   bios-release-date
		>>   system-masnufacturer
		>>   system-product-name
		>>   system-version
		>>   system-serial-number
		>>   system-uuid
		>>   system-family
		>>   baseboard-manufacturer
		>>   baseboard-product-name
		>>   baseboard-version
		>>   baseboard-serial-number
		>>   baseboard-asset-tag
		>>   chassis-manufacturer
		>>   chassis-type
		>>   chassis-version
		>>   chassis-serial-number
		>>   chassis-asset-tag
		>>   processor-family
		>>   processor-manufacturer
		>>   processor-version
		>>   processor-frequency
  208. sudo biosdecode
		>> # biosdecode 3.2
		>> ACPI 2.0 present.
		>> 	OEM Identifier: VBOX  
		>> 	RSD Table 32-bit Address: 0xDFFF0000
		>> 	XSD Table 64-bit Address: 0x00000000DFFF0030
		>> BIOS32 Service Directory present.
		>> 	Revision: 0
		>> 	Calling Interface Address: 0x000FDA00
		>> PCI Interrupt Routing 1.0 present.
		>> 	Router Device: 00:01.0
		>> 	Exclusive IRQs: None
		>> 	Compatible Router: 8086:7000
		>> 	Device: 00:01, on-board
		>> 	Device: 00:02, slot 1
		>> 	Device: 00:03, slot 2
		>> 	Device: 00:04, slot 3
		>> 	Device: 00:05, slot 4
		>> 	Device: 00:06, slot 5
		>> 	Device: 00:07, slot 6
		>> 	Device: 00:08, slot 7
		>> 	Device: 00:09, slot 8
		>> 	Device: 00:0a, slot 9
		>> 	Device: 00:0b, slot 10
		>> 	Device: 00:0c, slot 11
		>> 	Device: 00:0d, slot 12
		>> 	Device: 00:0e, slot 13
		>> 	Device: 00:0f, slot 14
		>> 	Device: 00:10, slot 15
		>> 	Device: 00:11, slot 16
		>> 	Device: 00:11, slot 16
		>> 	Device: 00:12, slot 17
		>> 	Device: 00:13, slot 18
		>> 	Device: 00:14, slot 19
		>> 	Device: 00:15, slot 20
		>> 	Device: 00:16, slot 21
		>> 	Device: 00:17, slot 22
		>> 	Device: 00:18, slot 23
		>> 	Device: 00:19, slot 24
		>> 	Device: 00:1a, slot 25
		>> 	Device: 00:1b, slot 26
		>> 	Device: 00:1c, slot 27
		>> 	Device: 00:1d, slot 28
		>> 	Device: 00:1e, slot 29
		>> SMBIOS 2.5 present.
		>> 	Structure Table Length: 450 bytes
		>> 	Structure Table Address: 0x000E1000
		>> 	Number Of Structures: 10
		>> 	Maximum Structure Size: 255 bytes
  # Peripheral devices in the early PCs used fixed I/O ports and fixed memory addresses
	# Video memory address-range: 0xA0000-0xBFFFF 
	# Programmable timer i/o-ports:  0x40-0x43
	# Keyboard and mouse i/o-ports:  0x60-0x64
	# Real-Time Clock’s i/o-ports:	0x70-0x71
	# Hard Disk controller’s i/o-ports:  0x01F0-01F7
	# Graphics controller’s i/o-ports:  0x03C0-0x3CF
	# Serial-port controller’s i/o-ports: 0x03F8-0x03FF
	# Parallel-port controller’s i/o-ports: 0x0378-0x037A 
  # Intel introduced a new bus standar PCI in the early 1990s. One of the goals of PCi was to create a flexible scheme for allocating addresses that future peripherals could use
  # A PCI device can have up to three address spaces
	# a) Configuration space: I/O ports 0x0CF8-0x0CFF dedicated to accessing PCI Configuration Space (Required)
	# b) I/O space (optional)
	# c) Memory space (optional)
  # NB: Every PCI device must implement the PCI configuration register dictated by the PCI specification. Otherwise, the device will not be regarded as a valid PCI device
  # Each PCI device is idientified by: Bus Number, Device Number, Function Number. Each Bus hosts up to 32 devices. Each device can have multi-functionality. There are 8 possible functions per device
  # Each PCi device has a set of register referred to as configuration space. Its size is 256 bytes. The first 64 bytes (0x00 - 0x3f) are standardized. The next 192 bytes (0x40 - 0xff) are vendor specific
  # Registers 0x00, 0x01 are defined by PCI spec as vendor ID (16-Bit), Registers 0x02, 0x03 are defined by PCI spec as product ID (16-bit).
  # Vendor ID identifies the manufacturer of the device. Allocated by the PCI SIG to ensure each is unique. Device ID identifies the particular device, set by the vendor
	# +--------------------------------------------------------------+
	# | Bits    | 31-16                 | 15-0                       |
	# +---------+-----------------------+----------------------------+
	# | 00h     | Device ID             | Vendor ID                  |
	# +---------+-----------------------+----------------------------+
	# | 04h     | Status                | Command                    |
	# +---------+-----------------------+----------------------------+
	# | 08h     | Class Code            | Revision ID                |
	# +---------+-----------------------+----------------------------+
	# | 0Ch     | BIST  | Header Type   | Lat. Timer | Cache Line S. |
	# +---------+-----------------------+----------------------------+
	# | 10h     | Base Address Registers                             |
	# +---------+----------------------------------------------------+
	# | 14h     | Base Address Registers                             |
	# +---------+----------------------------------------------------+
	# | 18h     | Base Address Registers                             |
	# +---------+----------------------------------------------------+
	# | 1Ch     | Base Address Registers                             |
	# +---------+----------------------------------------------------+
	# | 20h     | Base Address Registers                             |
	# +---------+----------------------------------------------------+
	# | 24h     | Cardbus CIS Pointer                                |
	# +---------+----------------------------------------------------+
	# | 28h     | Subsystem ID          | Subsystem Vendor ID        |
	# +---------+-----------------------+----------------------------+
	# | 2Ch     | Expansion ROM Base Address                         |
	# +---------+----------------------------------------------------+
	# | 30h     | Reserved                           | Cap. Pointer  |
	# +---------+-----------------------+----------------------------+
	# | 34h     | Reserved                                           |
	# +---------+----------------------------------------------------+
	# | 38h     | Reserved                                           |
	# +---------+----------------------------------------------------+
	# | 3Ch     | Max Lat.|Interrupt Pin | Min Gnt.  |Interrupt Line |
	# +---------+----------------------------------------------------+
  # How do you access registers present in the Configuration space? Accessiing these registers is like accessing RTC(CMOS) memory. PCI Index Port - 0xCF8, PCI Data Port 0xCFC
	# PCI Index Port (0xCF8)
	# ============================
	# 	31									                                      0
	# 	---------------------------------------------------------------------------
	# 	| |Reserved |Bus Number |Device Number|Function Number|Register Number|0|0|
	# 	---------------------------------------------------------------------------
	# 			       B	        D		     F		         Offset
	# Bit 31 when set, all reads and writes to CONFIG_DATA are PCI Configuration transactions
	# Bits 30:24 are read-only and must return 0 when read - Reserved - 
	# Bits 23:16 select a specific Bus in the system (up to 256 buses) - Bus Number -  
	# Bits 15:11 specify a Device on the given Bus (up to 32 devices) - Device Number -  
	# Bits 10:8 Specify the function of a device (up to 8 devices) - Function Number - 
	# Bits 7:0 Select an offset within the Configuration Space (256 bytes) - Register Number - 
	# Addresses are often given in B/D/F, Offset notation (also written as B:D:F, Offset) 
	# PCI Data Port (0xCFC)
	# ======================
	# Read and Write to 0xCFC with Bit 31 enabled in 0xCF8 results in PCI configuration transaction.
	# If the Bit 31 is not enabled, according to PCI Spec, transaction is forwarded out as Port I/O
  209. sudo cat /proc/ioports
		>> 0cf8-0cff : PCI conf1
  210. lspci  # Used to find Bus, Device and Function of a PCI Device. Each line st7arts with the PCI bus address formatted as bus:slot.function
		>> 00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
		>> 00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
		>> 00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
		>> 00:02.0 VGA compatible controller: VMware SVGA II Adapter
		>> 00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
		>> 00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
		>> 00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
		>> 00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
  211. lspci -n # Displays PCI vendor code, and the device code only as numbers (i.e. teensy: vendor ID VID_16C0 and product ID PID_0483, 16C0:0483)
		>> 00:00.0 0600: 8086:1237 (rev 02)
		>> 00:01.0 0601: 8086:7000
		>> 00:01.1 0101: 8086:7111 (rev 01)
		>> 00:02.0 0300: 15ad:0405
		>> 00:04.0 0880: 80ee:cafe
		>> 00:05.0 0401: 8086:2415 (rev 01)
		>> 00:06.0 0c03: 106b:003f
		>> 00:07.0 0680: 8086:7113 (rev 08)
		>> 00:08.0 0200: 8086:100e (rev 02)
		>> 00:0d.0 0106: 8086:2829 (rev 02)
  212. lspci -nn  # displays both the description and the number
		>> 00:00.0 Host bridge [0600]: Intel Corporation 440FX - 82441FX PMC [Natoma] [8086:1237] (rev 02)
		>> 00:01.0 ISA bridge [0601]: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II] [8086:7000]
		>> 00:01.1 IDE interface [0101]: Intel Corporation 82371AB/EB/MB PIIX4 IDE [8086:7111] (rev 01)
		>> 00:02.0 VGA compatible controller [0300]: VMware SVGA II Adapter [15ad:0405]
		>> 00:04.0 System peripheral [0880]: InnoTek Systemberatung GmbH VirtualBox Guest Service [80ee:cafe]
		>> 00:05.0 Multimedia audio controller [0401]: Intel Corporation 82801AA AC'97 Audio Controller [8086:2415] (rev 01)
		>> 00:06.0 USB controller [0c03]: Apple Inc. KeyLargo/Intrepid USB [106b:003f]
		>> 00:07.0 Bridge [0680]: Intel Corporation 82371AB/EB/MB PIIX4 ACPI [8086:7113] (rev 08)
		>> 00:08.0 Ethernet controller [0200]: Intel Corporation 82540EM Gigabit Ethernet Controller [8086:100e] (rev 02)
		>> 00:0d.0 SATA controller [0106]: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] [8086:2829] (rev 02)
  213. lspci -k # displays the name of the kernel driver
		>> 00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
		>> 00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
		>> 00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
		>> 	Kernel driver in use: ata_piix
		>> 	Kernel modules: pata_acpi
		>> 00:02.0 VGA compatible controller: VMware SVGA II Adapter
		>> 	Subsystem: VMware SVGA II Adapter
		>> 	Kernel driver in use: vmwgfx
		>> 	Kernel modules: vmwgfx
		>> 00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
		>> 	Kernel driver in use: vboxguest
		>> 	Kernel modules: vboxguest
		>> 00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
		>> 	Subsystem: Dell 82801AA AC'97 Audio Controller
		>> 	Kernel driver in use: snd_intel8x0
		>> 	Kernel modules: snd_intel8x0
		>> 00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
		>> 	Kernel driver in use: ohci-pci
		>> 00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
		>> 	Kernel driver in use: piix4_smbus
		>> 	Kernel modules: i2c_piix4
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 	Subsystem: Intel Corporation PRO/1000 MT Desktop Adapter
		>> 	Kernel driver in use: e1000
		>> 	Kernel modules: e1000
		>> 00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
		>> 	Kernel driver in use: ahci
		>> 	Kernel modules: ahci
  214. lspci -x # Display configuration space
		>> 00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
		>> 00: 86 80 37 12 00 00 00 00 02 00 00 06 00 00 00 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
		>> 00: 86 80 00 70 07 00 00 02 00 00 01 06 00 00 80 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
		>> 00: 86 80 11 71 07 00 00 00 01 8a 01 01 00 40 00 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 01 d0 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:02.0 VGA compatible controller: VMware SVGA II Adapter
		>> 00: ad 15 05 04 07 00 00 00 00 00 00 03 00 40 00 00
		>> 10: 11 d0 00 00 08 00 00 e0 00 00 00 f0 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 ad 15 05 04
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0a 01 00 00
		>> 
		>> 00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
		>> 00: ee 80 fe ca 03 00 00 00 00 00 80 08 00 00 00 00
		>> 10: 21 d0 00 00 00 00 40 f0 08 00 80 f0 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0b 01 00 00
		>> 
		>> 00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
		>> 00: 86 80 15 24 05 00 80 02 01 00 01 04 00 40 00 00
		>> 10: 01 d1 00 00 01 d2 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 28 10 77 01
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0b 01 00 00
		>> 
		>> 00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
		>> 00: 6b 10 3f 00 06 00 10 00 00 10 03 0c 00 40 00 00
		>> 10: 00 40 80 f0 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0a 01 00 00
		>> 
		>> 00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
		>> 00: 86 80 13 71 01 00 80 02 08 00 80 06 00 00 80 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 09 01 00 00
		>> 
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 00: 86 80 0e 10 07 00 30 02 02 00 00 02 00 40 00 00
		>> 10: 00 00 82 f0 00 00 00 00 41 d2 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 86 80 1e 00
		>> 30: 00 00 00 00 dc 00 00 00 00 00 00 00 0b 01 ff 00
		>> 
		>> 00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
		>> 00: 86 80 29 28 07 00 10 00 02 01 06 01 00 40 00 00
		>> 10: 49 d2 00 00 51 d2 00 00 59 d2 00 00 61 d2 00 00
		>> 20: 71 d2 00 00 00 00 84 f0 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 70 00 00 00 00 00 00 00 0b 01 00 00
  215. lspci -v
		>> 00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
		>> 	Flags: fast devsel
		>> 
		>> 00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
		>> 	Flags: bus master, medium devsel, latency 0
		>> 
		>> 00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01) (prog-if 8a [ISA Compatibility mode controller, supports both channels switched to PCI native mode, supports bus mastering])
		>> 	Flags: bus master, fast devsel, latency 64
		>> 	Memory at 000001f0 (32-bit, non-prefetchable) [virtual] [size=8]
		>> 	Memory at 000003f0 (type 3, non-prefetchable) [virtual]
		>> 	Memory at 00000170 (32-bit, non-prefetchable) [virtual] [size=8]
		>> 	Memory at 00000370 (type 3, non-prefetchable) [virtual]
		>> 	I/O ports at d000 [virtual] [size=16]
		>> 	Kernel driver in use: ata_piix
		>> 	Kernel modules: pata_acpi
		>> 
		>> 00:02.0 VGA compatible controller: VMware SVGA II Adapter (prog-if 00 [VGA controller])
		>> 	Subsystem: VMware SVGA II Adapter
		>> 	Flags: bus master, fast devsel, latency 64, IRQ 18
		>> 	I/O ports at d010 [size=16]
		>> 	Memory at e0000000 (32-bit, prefetchable) [size=128M]
		>> 	Memory at f0000000 (32-bit, non-prefetchable) [size=2M]
		>> 	Expansion ROM at 000c0000 [virtual] [disabled] [size=128K]
		>> 	Kernel driver in use: vmwgfx
		>> 	Kernel modules: vmwgfx
		>> 
		>> 00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
		>> 	Flags: fast devsel, IRQ 20
		>> 	I/O ports at d020 [size=32]
		>> 	Memory at f0400000 (32-bit, non-prefetchable) [size=4M]
		>> 	Memory at f0800000 (32-bit, prefetchable) [size=16K]
		>> 	Kernel driver in use: vboxguest
		>> 	Kernel modules: vboxguest
		>> 
		>> 00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
		>> 	Subsystem: Dell 82801AA AC'97 Audio Controller
		>> 	Flags: bus master, medium devsel, latency 64, IRQ 21
		>> 	I/O ports at d100 [size=256]
		>> 	I/O ports at d200 [size=64]
		>> 	Kernel driver in use: snd_intel8x0
		>> 	Kernel modules: snd_intel8x0
		>> 
		>> 00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB (prog-if 10 [OHCI])
		>> 	Flags: bus master, fast devsel, latency 64, IRQ 22
		>> 	Memory at f0804000 (32-bit, non-prefetchable) [size=4K]
		>> 	Kernel driver in use: ohci-pci
		>> 
		>> 00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
		>> 	Flags: medium devsel, IRQ 9
		>> 	Kernel driver in use: piix4_smbus
		>> 	Kernel modules: i2c_piix4
		>> 
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 	Subsystem: Intel Corporation PRO/1000 MT Desktop Adapter
		>> 	Flags: bus master, 66MHz, medium devsel, latency 64, IRQ 16
		>> 	Memory at f0820000 (32-bit, non-prefetchable) [size=128K]
		>> 	I/O ports at d240 [size=8]
		>> 	Capabilities: <access denied>
		>> 	Kernel driver in use: e1000
		>> 	Kernel modules: e1000
		>> 
		>> 00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02) (prog-if 01 [AHCI 1.0])
		>> 	Flags: bus master, fast devsel, latency 64, IRQ 21
		>> 	I/O ports at d248 [size=8]
		>> 	I/O ports at d250 [size=4]
		>> 	I/O ports at d258 [size=8]
		>> 	I/O ports at d260 [size=4]
		>> 	I/O ports at d270 [size=16]
		>> 	Memory at f0840000 (32-bit, non-prefetchable) [size=8K]
		>> 	Capabilities: <access denied>
		>> 	Kernel driver in use: ahci
		>> 	Kernel modules: ahci
  216. lspci -vvxxx
		>> 00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
		>> 	Control: I/O- Mem- BusMaster- SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 00: 86 80 37 12 00 00 00 00 02 00 00 06 00 00 00 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
		>> 	Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B- ParErr- DEVSEL=medium >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 0
		>> 00: 86 80 00 70 07 00 00 02 00 00 01 06 00 00 80 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01) (prog-if 8a [ISA Compatibility mode controller, supports both channels switched to PCI native mode, supports bus mastering])
		>> 	Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64
		>> 	Region 0: Memory at 000001f0 (32-bit, non-prefetchable) [virtual] [size=8]
		>> 	Region 1: Memory at 000003f0 (type 3, non-prefetchable) [virtual]
		>> 	Region 2: Memory at 00000170 (32-bit, non-prefetchable) [virtual] [size=8]
		>> 	Region 3: Memory at 00000370 (type 3, non-prefetchable) [virtual]
		>> 	Region 4: I/O ports at d000 [virtual] [size=16]
		>> 	Kernel driver in use: ata_piix
		>> 	Kernel modules: pata_acpi
		>> 00: 86 80 11 71 07 00 00 00 01 8a 01 01 00 40 00 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 01 d0 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 
		>> 00:02.0 VGA compatible controller: VMware SVGA II Adapter (prog-if 00 [VGA controller])
		>> 	Subsystem: VMware SVGA II Adapter
		>> 	Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64
		>> 	Interrupt: pin A routed to IRQ 18
		>> 	Region 0: I/O ports at d010 [size=16]
		>> 	Region 1: Memory at e0000000 (32-bit, prefetchable) [size=128M]
		>> 	Region 2: Memory at f0000000 (32-bit, non-prefetchable) [size=2M]
		>> 	Expansion ROM at 000c0000 [virtual] [disabled] [size=128K]
		>> 	Kernel driver in use: vmwgfx
		>> 	Kernel modules: vmwgfx
		>> 00: ad 15 05 04 07 00 00 00 00 00 00 03 00 40 00 00
		>> 10: 11 d0 00 00 08 00 00 e0 00 00 00 f0 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 ad 15 05 04
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0a 01 00 00
		>> 
		>> 00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
		>> 	Control: I/O+ Mem+ BusMaster- SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Interrupt: pin A routed to IRQ 20
		>> 	Region 0: I/O ports at d020 [size=32]
		>> 	Region 1: Memory at f0400000 (32-bit, non-prefetchable) [size=4M]
		>> 	Region 2: Memory at f0800000 (32-bit, prefetchable) [size=16K]
		>> 	Kernel driver in use: vboxguest
		>> 	Kernel modules: vboxguest
		>> 00: ee 80 fe ca 03 00 00 00 00 00 80 08 00 00 00 00
		>> 10: 21 d0 00 00 00 00 40 f0 08 00 80 f0 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0b 01 00 00
		>> 
		>> 00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
		>> 	Subsystem: Dell 82801AA AC'97 Audio Controller
		>> 	Control: I/O+ Mem- BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B+ ParErr- DEVSEL=medium >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64
		>> 	Interrupt: pin A routed to IRQ 21
		>> 	Region 0: I/O ports at d100 [size=256]
		>> 	Region 1: I/O ports at d200 [size=64]
		>> 	Kernel driver in use: snd_intel8x0
		>> 	Kernel modules: snd_intel8x0
		>> 00: 86 80 15 24 05 00 80 02 01 00 01 04 00 40 00 00
		>> 10: 01 d1 00 00 01 d2 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 28 10 77 01
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0b 01 00 00
		>> 
		>> 00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB (prog-if 10 [OHCI])
		>> 	Control: I/O- Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap+ 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64
		>> 	Interrupt: pin A routed to IRQ 22
		>> 	Region 0: Memory at f0804000 (32-bit, non-prefetchable) [size=4K]
		>> 	Kernel driver in use: ohci-pci
		>> 00: 6b 10 3f 00 06 00 10 00 00 10 03 0c 00 40 00 00
		>> 10: 00 40 80 f0 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 0a 01 00 00
		>> 
		>> 00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
		>> 	Control: I/O+ Mem- BusMaster- SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap- 66MHz- UDF- FastB2B+ ParErr- DEVSEL=medium >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Interrupt: pin A routed to IRQ 9
		>> 	Kernel driver in use: piix4_smbus
		>> 	Kernel modules: i2c_piix4
		>> 00: 86 80 13 71 01 00 80 02 08 00 80 06 00 00 80 00
		>> 10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 00 00 00 00 00 00 00 00 09 01 00 00
		>> 
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 	Subsystem: Intel Corporation PRO/1000 MT Desktop Adapter
		>> 	Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap+ 66MHz+ UDF- FastB2B- ParErr- DEVSEL=medium >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64 (63750ns min)
		>> 	Interrupt: pin A routed to IRQ 16
		>> 	Region 0: Memory at f0820000 (32-bit, non-prefetchable) [size=128K]
		>> 	Region 2: I/O ports at d240 [size=8]
		>> 	Capabilities: <access denied>
		>> 	Kernel driver in use: e1000
		>> 	Kernel modules: e1000
		>> 00: 86 80 0e 10 07 00 30 02 02 00 00 02 00 40 00 00
		>> 10: 00 00 82 f0 00 00 00 00 41 d2 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 86 80 1e 00
		>> 30: 00 00 00 00 dc 00 00 00 00 00 00 00 0b 01 ff 00
		>> 
		>> 00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02) (prog-if 01 [AHCI 1.0])
		>> 	Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- FastB2B- DisINTx-
		>> 	Status: Cap+ 66MHz- UDF- FastB2B- ParErr- DEVSEL=fast >TAbort- <TAbort- <MAbort- >SERR- <PERR- INTx-
		>> 	Latency: 64
		>> 	Interrupt: pin A routed to IRQ 21
		>> 	Region 0: I/O ports at d248 [size=8]
		>> 	Region 1: I/O ports at d250 [size=4]
		>> 	Region 2: I/O ports at d258 [size=8]
		>> 	Region 3: I/O ports at d260 [size=4]
		>> 	Region 4: I/O ports at d270 [size=16]
		>> 	Region 5: Memory at f0840000 (32-bit, non-prefetchable) [size=8K]
		>> 	Capabilities: <access denied>
		>> 	Kernel driver in use: ahci
		>> 	Kernel modules: ahci
		>> 00: 86 80 29 28 07 00 10 00 02 01 06 01 00 40 00 00
		>> 10: 49 d2 00 00 51 d2 00 00 59 d2 00 00 61 d2 00 00
		>> 20: 71 d2 00 00 00 00 84 f0 00 00 00 00 00 00 00 00
		>> 30: 00 00 00 00 70 00 00 00 00 00 00 00 0b 01 00 00
  217. lspci -s 00:08.0 -kvx
		>> 00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
		>> 	Subsystem: Intel Corporation PRO/1000 MT Desktop Adapter
		>> 	Flags: bus master, 66MHz, medium devsel, latency 64, IRQ 16
		>> 	Memory at f0820000 (32-bit, non-prefetchable) [size=128K]
		>> 	I/O ports at d240 [size=8]
		>> 	Capabilities: <access denied>
		>> 	Kernel driver in use: e1000
		>> 	Kernel modules: e1000
		>> 00: 86 80 0e 10 07 00 30 02 02 00 00 02 00 40 00 00
		>> 10: 00 00 82 f0 00 00 00 00 41 d2 00 00 00 00 00 00
		>> 20: 00 00 00 00 00 00 00 00 00 00 00 00 86 80 1e 00
		>> 30: 00 00 00 00 dc 00 00 00 00 00 00 00 0b 01 ff 00
  # when configuration accessattempts to select a device that does not exist, the host bridge will access without error, dropping all data on writes and returning all ones on reads
  218. lspci -h # returns available commands  
  # Base Address Registers (BARs) hold the memory addresses used by the device. PCI Configuration Registers provide space for jupt to 6 BARs. Each BAR is 32-bits wide to support 32-bit address space locations. 
  # Concatenating two 32-bit BARs provides 64-bit adddressing capability. Each region consists of either memory or I/O locations. To identify whether an address is I/O or memory mapped, check the value of the lowest bit:
	# Lowest Bit = 0 --> Memory Mapped
	# Lowest Bit = 1 --> I/O Mapped
  # Memory Space BAR
  # ===============
	# 	31 - 4			 3		2-1    0
	# ---------------------------------------------------------------
	# |16-BYTE  Aligned Base Address | Prefetchable |Type   |Always 0|
	# ----------------------------------------------------------------
    # Type Field: 0x00	BAR is 32-bit wide and can be mapped into 32-bit address space
    # Type Field: 0x02	BAR is 64-bit wide and can be mapped into 64-bit address space
  # IO Space BAR 
  # ============
	# 	31-2			            1	         0
	# ------------------------------------------------------
	# |4 BYTE Aligned Base Address | Reserved |  Always 1  |
	# ------------------------------------------------------
  # When you want to retrieve the actual base address of a BAR, be sure to mask the lower bits. For 32-bit Memory Space BARs, you calculate (BAR[x] & 0xFFFFFFF0), 
  # For 64-Bit Memory Space BARs you calculate (BAR[x] & 0xFFFFFFF0) + ((BAR[x+1] & 0xFFFFFFFF) << 32)). For I/O Space BARs, you calculate (BAR[x] & 0xFFFFFFFC)
  # A Base Address is half the information that's needed - we need to get the size of the device. 
	# 1. you must save the original value of the BAR
	# 2. write a value of all 1's to the register
	# 3. then read it back
	# 4. restore the original value
  # The amount of memory can then be determined by masking the information bits, performing a bitwise NOT ('~' in C) and incrementing the value by 1
  # The PCI Express bus extends the Configuration Space from 256 bytes to 4096 bytes. This extended configuration space *cannot* be accessed using the legacy PCI method (through ports 0xCF8 and 0xCFC)
  # The enhanced configuration mechanism makes use of memoy mapped address space range(s) to access PCI configuration space. On x86 and x64 platforms, the addtess of each memory area is determined by the ACPI 'MCFG' table
  219. sudo hexdump -C /sys/firmware/acpi/tables/MCFG 
  220. ls -l /sys/firmware/acpi/tables/  # On VirtualBox no MCFG present
		>> total 0
		>> drwxr-xr-x 4 root root    0 Feb 10 17:58 ./
		>> drwxr-xr-x 5 root root    0 Feb 10 17:58 ../
		>> -r-------- 1 root root  108 Feb 10 18:51 APIC
		>> drwxr-xr-x 2 root root    0 Feb 10 18:51 data/
		>> -r-------- 1 root root 8997 Feb 10 18:51 DSDT
		>> drwxr-xr-x 2 root root    0 Feb 10 18:51 dynamic/
		>> -r-------- 1 root root  244 Feb 10 17:59 FACP
		>> -r-------- 1 root root   64 Feb 10 18:51 FACS
		>> -r-------- 1 root root  460 Feb 10 18:51 SSDT

  # An interrupt is a signal sent to the processor by hardware peripherals when they need processor attention. An example is wanting to perform an action with an incoming packet from the network card as soon as it arrives
  # To not waste processor time by continuously queying the network card, you can use an external hardware interrupt IRQ. The interrupt line from a device should be connected to the INTR line of the CPU 
  # After each packet is received the network card will make a signal over this line. The CPU will sense this signal and know the network card has information for it, then only afterwards will read the incoming packet.
  # Types of Interrupt are:
	# Hardware/Asynchronous:
		# Generated by hardware devices
		# Occurs at arbitrary times (asynchronously) with respect to clock signals
		# Examples: Pressing a key on theb keyboard, mouse movement, timer fired, Network cards report the arrival of a packet with an interrupt.
	# Software/Synchronous:
		# Generated by executing instructions
		# Occurs synchronously with respect to processor clock
		# Also called as exceptions/traps
		# Examples: Divide-by-zero, system call, page fault
  # Exceptions are classified as faults, traps and abort, depending on the way they are reported and whether the instruction that caused the exception can be restarted without loss of the program.
  # 'Traps' increment the instruction pointer, 'Faults' do not and 'Aborts' explode.
	# Faults: Can be corrected and the program may continue as if nothing happened, e.g. page fault
	# Traps: Traps are reported immediately after the execution of the trapping instruction. e.g. int instruction
	# Aborts: Some sever onrecoverable error: e.g. hardware failure
  # A General Protection Fault may occur for various reasons. The most common are:
	# Segment error (privilege, type, limit, read/write rights)
	# Executing a privileged instruction while CPL (Current Privilege Level) != 0
	# Writing a 1 in a reserved register field
	# Referencing or accessing a null-descriptors
	# Trying to access an unimplemented register (like: mov cr6, eax)
	# The saved indtruction pointer points to the instruction which caused the exception,
  # To implement breakpoints on the x86 architecture, softwre interrupts (also known as "traps") are used. Breakpoints are implemented on the CPU by a special trap called int 3. 
  # int is x86 jargon for "trap instruction" - a call to a predefined interrupt handler. x86 supports the int instruction with a 8-bit operand specifying the number of the interrupt that occurred
  # Each interrupt signal input is designed to be triggered either by a logical signal level or a particular signal edge (level transition)
	# Level Triggered:
		# Interrupt is requested by holding the interrupt signal at its paticular (high or low) active logic level. Level triggered interrupts happen as long as the interrupt line is held at active level
		# As long as the line is active, you will get an iteerupt. When you serve the interrupt and return, if the interrupt line is still active , you get the interrupt again immediately.
		# Level-triggered inputs allow multiple devices to share a common interrupt signal via wired-OR connections
	# Edge Triggered:
		# Interrupt is requested by a level transition on the interrupt line	
			# Falling Edge (High to Low)
			# Rising Edge (Low to High)
		# These interrupts are issued per transition and not repeated, e.g. in networking when the packet queue goes from empty to non-empty. 
		# This makes it critical to never miss an edge triggered interrupt, because failure to handle one interrupt may result in stopping further interrupts from happening. 
  # Processors typically have an internal interrupt mask register. This allows selective enabling and disabling of hardware interrupts. Each interrupt signal is associated with a bit in the mask register.
	# Bit = 1, Interrupt Enabled
	# Bit = 0, Interrupt Disabled
  # When the interrupt is disabled, the associated interrupt signal will be ignored by the processor.
	# Maskable Interrupts: Interrupts which can be enabled/disabled.
	# NonMaskable Interrupts: Interrupts which cannot be disabled, e.g. NMI, timeout signal from watchdog timer
  # The 8086 processor has two hardware interrupt signals.
	# NMI - non-maskable interrupt
	# INTR Interrupt request (maskable interrupt)
  # In order to support more than two interrupts it would be unproductive to make a ton of INTR pins on the CPU for all of them. To solve this problem a special chip called an interrupt controller was created.
  # The 8259 Programmable Interrupt Controller (PIC) is one of the most important chips making up the x86 architecture. It Allows for multiplexing the single INT line on the x86 processor to multiple interrupt lines.
  # Interrupt lines can be assigned various hardware priority levels, as well as programmable interrupt masking.
  # Each PIC has 8 interrupt lines called Interrupt Request (IRQ), numbered from 0 to 7. PIC has one output line which connects to the INTR line of the CPU. 
  # A device supporting interrupts has an output pin used for signalling an Interrupt ReQuest (IRQ). When one of PIC IRQ lines goes high, the 8259 will make a signal over the INTR line
  # CPU will know that some device requires its immediate attention, and the processor will ask the PIC which of the 8 input lines (IRQx) was the source of this interrupt
  # Peripheral devices cannot directly force interrupts has to request them via the PIC, we call them IRQ or Interrupt Requests   
  # Soon 8 lines weren't enough - to increase the total number of interrupt lines two 8259 controllers (master and slave) were connected in a cascade (Dual PIC)
	# IRQs from 0 to 7 are processed with the first Intel 8259 PIC (master)
	# IRQs from 8 to 15 are processed with the second Intel 8259 PIC (slave)
  # Only the master is connected to the CPU and can signal about the coming interrupts.
  # If there's an interrupt on lines 8-15, the second PIC (slave) will signal the master on line iRQ2, then the master signals the CPU. This takes away 1 of the 16 lines, but makes for a total of 15 interrupts for external devices
  # There are two separate dedicated ports in the x86 IO-Port space for each connected PIC
	# Master PIC - 0x20, 0x21
	# Slave  PIC - 0xA0, 0xA1
    # Master PIC
    	# IRQ 0 — system timer
    	# IRQ 1 — keyboard controller
    	# IRQ 2 — cascade (interrupt from slave controller)
    	# IRQ 3 — serial port COM2
    	# IRQ 4 — serial port COM1
    	# IRQ 5 — parallel port 2 and 3 or sound card
    	# IRQ 6 — floppy controller
    	# IRQ 7 — parallel port 1  
    # Slave PIC
    	# IRQ 8 — RTC timer
    	# IRQ 9 — ACPI
    	# IRQ 10 — open/SCSI/NIC
    	# IRQ 11 — open/SCSI/NIC
    	# IRQ 12 — mouse controller
    	# IRQ 13 — math co-processor
    	# IRQ 14 — ATA channel 1
    	# IRQ 15 — ATA channel 2
  # Initially the x86 used ISA Bus. The PCI bus later replaced the ISA bus. Unfortunately the number of devices began to exceed the number 15, also instead of the static ISA bus, devices in the PCI bus can be added to the system dynamically.
  # Interrupts in the PCI bus can be shared, so it is possible to connect many devices to one interrupt line IRQ
  # In the end, to solve the problem of the lack of interrupt lines, it was decided to group interrupts from all of the PCI devices to PIRQ lines (Programmable Interrupt Request)
  # For example, suppose we have 4 free interrupt lines on the PIC controller and 20 PCI devices - we can combine interrupts from 5 devices into one PIRQx line, and connect these PIRQx lines to the PIC controller
  # In this case if there is an interrupt on one of the PIRQx lines, the processor will have to ask all the devices connected to this line about the interrupt to know who is responsible for it, but in the end it solves the problem.
  # The device that connects PCI interrupt lines to PIRQ lines is often caled a PIR router - this method ensures PIRQx lines don't connect to lines with ISA interrupts (causes conflicts).
  # System software, such as the BIOS or operating system is responsible for programming the interrupt router.  
  # The PIC method only works for single processor systems. It can only send interrupts to one CPU, and in a multiprocessor system it is desirable to load CPUs in a balanced way. The solution to this is the APIC interface (Advanced PIC)
  # The APIC interface consists of two components:
	# IOAPIC (IO APIC)  - Interfaces with Devices (lines 0-23)
		# Connects to devices to allow device interrupt requests to be routed to LAPICs
		# There can be one or more IO-APIC in the system
		# Each IO-APIC has 24 interrupt lines
		# It receives interrupt requests from devices and sends them to LAPICs based on redirection table entries (RTE) programmed in the IOAPIC
	# LAPIC (Local APIC) - Interfaces with CPU 
  `		# Each processor in a multiprocessor system has one LAPIC (local APIC). It is reponsible for:
			# Receiving various interrupt requests and delivering them to the processor
			# Handling prioritization of interrupts
			# Sending interrupts to other processors (known as inter-processor interrupts or IPIs)
		# LAPIC can be connected directly to I/O devices via local interrupt timers (timer, thermal sensor) or through IO-APIC via external interrupt inputs
		# LAPIC can generate interrupts due to interrupt requests received from various sources
			# IPIs received from other processors
			# Interrupts coming from LINT (local interrupts) or EXTINT (external interrupts)
	# To maintain backwards compatibility, APIC emulates 8259 PIC
	# The CPUID.0h:EDX[bit 9] flag specifies whether a CPU has a built-in local APIC/
  # CPUID is an x86 opcode which stands for CPU Identification.
  # The CPUID instruction can be used to retrieve various amounts of information about your cpu
	# Vendor string
	# Model Number
	# Size of internal caches
	# List of CPU features
	
 221. man 4 cpuid  # CPUID provides an interface for querying information about the x86 CPU
 # The cpuid driver is not auto-loaded. On modular kernels you might need to use the following command to load it explicitly before use
 222. modprobe cpuid  
 # Most of the information in cpuid is reported by the kernel in cooked form either in /proc/cpuinfo
 223. cat /proc/cpuinfo | grep -i apicid # apicid: A unique ID given to each logical processor upon startup
 # When there is an interrupt
	# Device Asserts IRQ of I/O APIC
	# I/O APIC transfer interrupt to LAPIC
	# LAPIC asserts CPU interrrupts
	# After current instruction completes CPU senses interrupt line and obtains IRQ number from LAPIC
	# Jumps to interrupt handler
  # The hardware finds the interrupt handler via
	# The Interrupt Vector
		# On x86 each interrupt or exception is identified by a number between 0 and 255. Intel calls this number a vector.
		# The interrupt vector is used by the interrupt handling mechanism to locate the system-software service routine assigned to the exception or interrupt
		# Up to 256 unique interrupt vectors are available in x86
		# The number of interrupt vectors or entry points supported by a CPU differs based on the CPU architecture
		# The first 32 vectors are reserved for predefined exception and interrupt conditions
		# Look into arch/x86/include/asm/traps.h
	# Interrupt Descriptor Table
		# The IDT is a linear table of 256 entries which associates an interrupt handler with each interrupt vector
		# When an interrupt is fired, the CPU looks at the IDT table and finds what method needs to be called
		# Each descriptor is of size 8 bytes (on x86) and 16 bytes (on x86_64)
		# During early boot, the architecture-specific branch of the kernel code sets up the IDT in memory and programs the IDTR register (special x86 register) of the processor with the physical start address and length of the IDT
  # Whenever an interrupt occurs, assembly instructions in linux kernel are executed which locates relevant vector descriptor by multiplying reported vector number by size of vector(8/16) and adding the result to the base address of IDT
	# common_interrupt: arch/x86/entry/entry_64.s:
		# a. saves the context of the running process
		# b. This includes instruction pointer (IP), stack pointer and other registers needed to resume the process again
		# c. This context is usually saved on the stack.
		# d. Then the context is changed to interrupt stack
	# Finally it arrives at do_IRQ(). do_IRQ() is the common function for all hardware interrupts	
		# arch/x86/kernel/irq.c
	# Finds IRQ number in saved %EAX register
	# Calls handle_irq which will finally call our registered interrupt handler
  224. cat /proc/interrupts  # contains statistics related to interrupts on the system
		>>            CPU0       CPU1       CPU2       CPU3       
		>>   0:         36          0          0          0   IO-APIC   2-edge      timer
		>>   1:          0          0       1850          0   IO-APIC   1-edge      i8042
		>>   8:          0          0          0          0   IO-APIC   8-edge      rtc0
		>>   9:          0          0          0          0   IO-APIC   9-fasteoi   acpi
		>>  12:          0       5630          0          0   IO-APIC  12-edge      i8042
		>>  14:          0          0          0          0   IO-APIC  14-edge      ata_piix
		>>  15:          0          0          0       6999   IO-APIC  15-edge      ata_piix
		>>  16:          0          0          0     209347   IO-APIC  16-fasteoi   enp0s8
		>>  18:          0     215229        335          0   IO-APIC  18-fasteoi   vmwgfx
		>>  20:          0     176122          0          0   IO-APIC  20-fasteoi   vboxguest
		>>  21:      19392          0      74256          0   IO-APIC  21-fasteoi   ahci[0000:00:0d.0], snd_intel8x0
		>>  22:         28          0          0          0   IO-APIC  22-fasteoi   ohci_hcd:usb1
		>> NMI:          0          0          0          0   Non-maskable interrupts
		>> LOC:    1297097    1447024    1353213    1270984   Local timer interrupts
		>> SPU:          0          0          0          0   Spurious interrupts
		>> PMI:          0          0          0          0   Performance monitoring interrupts
		>> IWI:          0          0          0          9   IRQ work interrupts
		>> RTR:          0          0          0          0   APIC ICR read retries
		>> RES:       1548       3618       5291       6362   Rescheduling interrupts
		>> CAL:    3733338    3608168    3803116    3519717   Function call interrupts
		>> TLB:     344406     313993     369698     317643   TLB shootdowns
		>> TRM:          0          0          0          0   Thermal event interrupts
		>> THR:          0          0          0          0   Threshold APIC interrupts
		>> DFR:          0          0          0          0   Deferred Error APIC interrupts
		>> MCE:          0          0          0          0   Machine check exceptions
		>> MCP:         23         23         23         23   Machine check polls
		>> ERR:          0
		>> MIS:       1511
		>> PIN:          0          0          0          0   Posted-interrupt notification event
		>> NPI:          0          0          0          0   Nested posted-interrupt event
		>> PIW:          0          0          0          0   Posted-interrupt wakeup event
  
	# First column - IRQ number - only shows interrupts corresponding to installed handlers
	# CPU columns - have a counter showing the nummber of interrupts received.
	# Penultimate columns -  Device that handles the interrupt and type of interrupt
	# Last column - Device associated with this interrupt
  # Differnce between fasteoi and edge isn
	# fasteoi (End of Interrupt - eoi) are level interrupts triggered until interrupt event is acknowledged in the PIC
	# edge are edge triggered interrupts
  225. watch -n1 "cat /proc/interrupts"  # The watch command executes another command periodically, -n1 says execute every second 
  226. watch -n 0.1 -d 'cat /proc/interrupts'  # -d option highlights the differences between successive updates
  227. watch -n 0.1 -d --no-title 'cat /proc/interrupts'  # --no-title (-t) option of watch turns off header showing interval, command and current time at top of the display, as well as the following blank line
  # Interrupt handlers are the responsibility of the driver managing the hardware - if the device uses interrupts, then the driver must register one interrupt handler
  # Registering an interrupt handler
	  # Header File: <linux/interrupt.h>
	  # int request_irq(unsigned int irq,
	  #         irq_handler_t handler,
	  #         unsigned long flags,
	  #         const char *name,
	  #         void *dev);
  # Parameters:
	  # irq     --> The interrupt number being requested
	  #             For some devices,for example legacy PC devices such as the system timer or keyboard, this value is typically hard-coded.
	  #             For most other devices, it is probed or otherwise determined programmatically and dynamically.
	  # handler   --> function pointer to the actual interrupt handler that services this interrupt.
	  #               invoked whenever the operating system receives the interrupt
	  #               typedef irqreturn_t (*irq_handler_t)(int, void *);
	  # flags     --> bitmask of options related to interrupt management.
	  # name      --> Name to be displayed in /proc/interrupts
	  # dev       --> Used for shared Interrupt Lines
  # Return Value:
	  # Success  -->    Returns Zero
	  # Failure  -->    Non-Zero Value
  # When a key is pressed, the keyboard controller informs the PIC to cause an interrupt. IRQ #1 is the keyboard interrupt, so when a key is pressed IRQ 1 is sent to the PIC. The PIC tells the CPU an interrupt occurred.
  # When the CPU acknowledges the "interrupt occurred" signal, the PIC chip sends the interrupt number (00h to FFh, or 0 to 255) to the CPU. Each key pressed on the keyboard generates two interrupts (pressed/released)
  # A keyboard generates two scan codes for each key typed on the system, one scan code for press and the other for release. Release scan code is 128 (80h) plus the press scan code
  228. ping -i 0.3 8.8.8.8  # makes ping request every 0.3 seconds
  # Interrupt handlers return an irqreturn_t value.
	# IRQ_NONE - interrupt was not from this device or was not handled
	# IRQ_HANDLED - interrupt was handled by this device
  # The third parameter of request_irq() is an interrupt flag. Interrupt flags are:
	# IRQF_TIMER - specifies that this handler processes interrupts for the system timer
	# IRQF_PERCPU - Interrupt is per cpu
	# IRQF_PROBE_SHARED - set by callers when they expect sharing mismatches to occur 
	# IRQF_NOBALANCING 	
		# Flag to exclude this interrupt from IRQ balancing
		# The purpose of IRQ balancing is to distribute hardware interrupts across processors on a multiprocessor system to improve performance
		# Setting this flag forbids setting any CPU affinity for the requested interrupt handler
  # Starting with the 2.4 kernel, Linux has gained the ability to assign certain IRQs to specific processors (or groups of processors). This is known as SMP IRQ affinity
  # The interrupt affinity value for a particular IRQ numbber is stored in the associated /proc/irq/IRQ_NUMBER/smp_affinity file, which can be viewed and modified by the root user
  # The value stored in this fie is a hexadecimal bit-mask representing alll CPU cores in the system /proc/irq/irq_number/smp_affinity_list contains cpu list
  229. sudo cat /proc/irq/1/smp_affinity
  230. while (( count < 32 )) ; do
  > cat /proc/irq/${count}/smp_affinity
  > (( ++ count ))
  > sleep 1
  > done
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> 8
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> f
  	 >> 8
  	 >> cat: /proc/irq/17/smp_affinity: No such file or directory
  	 >> 2
  	 >> cat: /proc/irq/19/smp_affinity: No such file or directory
  	 >> f
  	 >> 4
  	 >> 1
  	 >> cat: /proc/irq/23/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/24/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/25/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/26/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/27/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/28/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/29/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/30/smp_affinity: No such file or directory
  	 >> cat: /proc/irq/31/smp_affinity: No such file or directory
  # All devices that offer interrupt support have a status register that can be read in the handling routine to see if the interrupt was or was not generated by the device
  # Example: For 8250 serial port, this status register is IIR - Interrupt Information Register
  # Enable/Disable interrupt is contained in the Header File <linux/irqflags.h>
	# local_irq_disable(); // disables all interrupts on the currennt processor
	# local_irq_enable(); // Enable all interrupts on the current processor
	# On x86, local_irq_disable() is a simple cli and local_irq_enable() is a simple sti instruction
	# cli and sti are the assembly calls to clear and set the allow interrupts flag respectively
  # By disabling interrupts, you can guarantee that an interrupt handler will not preempt your current code, 
  # It also disables kernel preemption, however this does not provide protection from concurrent access by another processor. Use locks to prevent another process from accessing shared data simultaneously
	# local_irq_disable() routine is dangerous if some interrupts were already disabled prior to its invocation
	# The corresponding call to local_irq_enable() unconditionally enables interrupts, despite the fact that they were off to begin with 
	# local_irq_save(flags); saves the interrupt state on flags and disables interrupt on that processor
	# local_irq_restore(flags); restores the previous interrupt state and enables interrupt on that processor
  # Disabling a specific interrupt line is also called masking out an interrupt line. An example is ypu might want to disable delivery of a device's interrupts before manipulating its state
	# void disable_irq(unsigned int irq); // Disables a given interrupt line in interrupt controller. this disables delivery of the given interrupt to all processors in the system
	# void enable_irq(unsigned int irq);
	# Note: disable_irq does not return until any executing handler completes. Callers are asssured that
		# a) new interrupts will not be delivered on the given line
		# b) any already executing handlers have exited
	# void disable_irq_nosync(unsigned int irq); // this functiondoes not wait for current handlers to complete
	# void synchronize_irq(unsigned int irq); // this function waits for a specific interrupt handler to exit, if it is executing, before returning
		# synchronize_irq() spins until no interrupt hanlder is running fir the given IRQ
	# For each call to disable_irq() or disable_irq_nosync(), a corresponding call to enable_irq() is required(). Only on the last call will the interrupt line actually be enabled
  # Disabling an interrupt line shared amongst multiple interrupt handlers disables delivery for all devices on the line, therefore driver for newer devices tend not to use these interfaces.
  # PCI devices have to support interrupt line sharing by specification so should ot use these interfaces at all.
	# disable_irq() and related functions are thus generaly found in drivers for legacy devices, such as the PC parallel port
	# The macro irqs_disabled(), returns nonzero if the interrupt system on the local processor is disabled. Header File: <linux/irqflags.h>
  # When executing an interrupt handler, the kernel is in interrupt context. We know process context is the mode of operation the kernel is in while it is executing on behalf of a process e.g. executing a system call
  # As interrupt context is not backed with process, you cannot sleep in interrupt context. If a function sleeps, you cannot use it from your interrupt handler
  # To ifnd out hwether running in interrupt context or process context:
	# in_interrupt() returns non-zero if the kernel is performing any type of interrupt handling
	# in_interrupt() returns zero if the kernel is in process context
  # Interrupt handlers only execute a small amount of code and defer the rest of the work to a later point in time. This is because:
	# Interrupt handlers are exected in hard-interrupt context - CPU-local interrupts remain disabled
	# The handler of an interrupt must execute quickly, long running handlers can slow down the system and may also lead to losing interrupts. 
	# The faster the handler returns, the lower the interrupt latencies in the kernel, which is especially important for real-time systems
	# Locking is undesirable and sleeping must be avoided.
	# A large amount of work cannot be performed in the interrupt handler
  # The handling of interrupts is divided into two parts:
	# Top Half (Hard IRQ)
		# Acknowledge the interrupt
		# Copy the necessary stuff from the device
		# Schedule the bottom half
	# Bottom Half (Soft IRQ)
		# Remaining pending work
  # The Network Card on reception of packets from the network issues an interrupt, kernel responds to it by executing the handler
	# Top Half (Interrupt Handler):
		# -> Acknowledges the interrupt
		# -> copies the new networking packets into main memory
		# -> pushes it up to the protocol layer
		# -> readies the network card for more packets
		# -> schedules the bottom half
	# Bottom Half:
		# Rest of the processing and handling of the packets
		# Various mechanisms available: Soft IRQ, Tasklets, Workqueue
  # An alternative to using formal bottom-half mechanisms is threaded interrupt handlers - these seek to reduce the time spent with interrupts disabled to bare minimum, pushinng the rest of the proocessing out into kernel threads
  # With threaded IRQs, the way you register an interrupt handler is simplified, you do not have to schedule the bottom half yourself, the core does that for us. The bottom half is then executed in a dedicated kernel thread
	# int request_threaded_irq(unsigned int irq, irq_handler_t handler, irq_handler_t thread_fn, unsigned long irqflags, const char *devname, void *dev_id);
    # request_threaded_irq() breaks handler code into two parts, handler and thread function
		# The threaded handler function will only be executed when the handler function returns IRQ_WAKE_THREAD
		# The kthread associated with this bottom half will be scheduled, invoking the thread_fn
		# The thread_fn must return IRQ_HANDLED when complete
		# After being executed the kthread will not be rescheduled again until the IRQ is triggered again and the hard-IRQ returns IRQ_WAKE_THREAD
  	>> <interrupt.h>
  	>>  static inline int __must_check
  	>>  request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,
  	>>          const char *name, void *dev)
  	>>  {
  	>>      return request_threaded_irq(irq, handler, NULL, flags, name, dev);
  	>>  }
	# the request_irq() function calls request_threaded_irq under the surface, but passes in a NULL value for the thread function.
    # IRQF_ONESHOT is a flag ensuring the interrupt is not reenabled after the IRQ handler finishes - it's required for threaded interrupts which need to keep the interrupt line disabled until the threaded handler has run
 	# Specifying this flag is mandatory if the primary handler is set to NULL. The default primary handler does nothing except return IRQ_WAKE_THREAD to wake up a kernel thread to execite the thread in the IRQ handler
	>> <kernel/irq/manage.c>
  	>>  /*cd ..
  	>>   * Default primary interrupt handler for threaded interrupts. Is
  	>>   * assigned as primary handler when request_threaded_irq is called
  	>>   * with handler == NULL. Useful for oneshot interrupts.
  	>>   */
  	>>  static irqreturn_t irq_default_primary_handler(int irq, void *dev_id)
  	>>  {
  	>>      return IRQ_WAKE_THREAD;
  	>>  }
  # Softirqs are bottom halves that run at a high priority, but with hardware interrupts enabled
	# They are representend by rhe softirq_action structure
	>> struct softirq_action
	>> {
	>>         void    (*action)(struct softirq_action *);
	>> };
	# A 10 entry array softirq_action softirq_vec[NR_SOFTIRQS];  //NR_SOFTIRQS=10(dec) in kernel code
	# two for tasklet processing (HI_SOFTIRQ and TASKLET_SOFTIRQ)
	# two for send and receive operations in networking (NET_TX_SOFTIRQ and NET_RX_SOFTIRQ)
	# two for the block layer (asynchronous request completions)
	# two for timers, and
	# one each for the scheduler and
	# read-copy-update processing
  231. cat /proc/softirqs	# Shows Per CPU statistics 
  # Software interrupts must be registered before the kernel can execute them. open_softirq is used for associating the softirq instance with the corresponding bottom half routine
	>> void open_softirq(int nr, void (*action)(struct softirq_action *))
	>> {
	>>         softirq_vec[nr].action = action;
	>> }
    # An example of where it is called is in the network subsystem
	<net/core/dev.c>
	>> open_softirq(NET_TX_SOFTIRQ, net_tx_action);
	>> open_softirq(NET_RX_SOFTIRQ, net_rx_action);
    # The kernel maintains a per-CPU bitmask indicating which softirqs need processing at any given time
    >> irq_stat[smp_processor_id].__softirq_pending
    # Drivers can signal the execution of soft_irq handlers using a function:
		>> raise_softirq(). 
	# This function takes the index of the softirq as argument
  	>> void raise_softirq(unsigned int nr)
  	>> {
  	>>         unsigned long flags;
  	>> 
  	>>         local_irq_save(flags);
  	>>         raise_softirq_irqoff(nr);
  	>>         local_irq_restore(flags);
  	>> }
	# local_irq_save 		--> Disables interrupts on the current processor where code is running
	# raise_softirq_irqoff 	--> sets the corresponding bit in the local CPUs softirq bitmask to mark the specified softirq as pending
	# local_irq_restore	--> Enables the interrupts
	# raise_softirq_irqoff if executed in non-interrupt context, will invoke wakeup_softirqd(), to wake up, if necessary the ksoftirqd kernel thread of that local CPU
  # softirqs are declared statically at compile time via an enum in <linux/interrupt.h>. Creating a new softirq includes adding a new entry to this enum - the index is used by the kerneel as priority.
  # softirqs with the lowest numerical priority (enum index) execute before those with a higher numerical priority. Insert the new entry dependng on the priority you want to give it
    # soft irq is registered at runtime via open_softirq(). It takes two parameters:
		# a) Index
		# b) Handler Function
  # To mark it pending, so it is run at the next invocation of do_softirq(), call raise_softirq(). Softirqs are most often raised from within interrupt handlers
    # Softirq handlers run with interrupys enabled and cannot sleep
	# While a handler runs, softirqs on the current processor are disabled, another processor however can execute another softirq
	# If the same softirq is raised again while it is executing, another processor can run it simultaneously, which means any shared data needs proper locking
 	# most softirq handlers resort to per-processor data (data unique to each processor and thus not requiring locking), and other tricks to avoid explicit locking and provide excellent scalability

# GPIO debugging
 232. vcdbg log msg  # shows gpioman log details
 233. cat /boot/config-`uname -r` | grep GPIO   # shows gpio config optons
  # Software interrupts must be registered before the kernel can execute them. open_softirq is used for associating the softirq instance with the corresponding bottom half routine
	>> void open_softirq(int nr, void (*action)(struct softirq_action *))
	>> {
	>>         softirq_vec[nr].action = action;
	>> }
    # An example of where it is called is in the network subsystem
	<net/core/dev.c>
	>> open_softirq(NET_TX_SOFTIRQ, net_tx_action);
	>> open_softirq(NET_RX_SOFTIRQ, net_rx_action);
    # The kernel maintains a per-CPU bitmask indicating which softirqs need processing at any given time
    >> irq_stat[smp_processor_id].__softirq_pending
    # Drivers can signal the execution of soft_irq handlers using a function:
		>> raise_softirq(). 
	# This function takes the index of the softirq as argument
  	>> void raise_softirq(unsigned int nr)
  	>> {
  	>>         unsigned long flags;
  	>> 
  	>>         local_irq_save(flags);
  	>>         raise_softirq_irqoff(nr);
  	>>         local_irq_restore(flags);
  	>> }
	# local_irq_save 		--> Disables interrupts on the current processor where code is running
	# raise_softirq_irqoff 	--> sets the corresponding bit in the local CPUs softirq bitmask to mark the specified softirq as pending
	# local_irq_restore	--> Enables the interrupts
	# raise_softirq_irqoff if executed in non-interrupt context, will invoke wakeup_softirqd(), to wake up, if necessary the ksoftirqd kernel thread of that local CPU
  # softirqs are declared statically at compile time via an enum in <linux/interrupt.h>. Creating a new softirq includes adding a new entry to this enum - the index is used by the kerneel as priority.
  # softirqs with the lowest numerical priority (enum index) execute before those with a higher numerical priority. Insert the new entry dependng on the priority you want to give it
    # soft irq is registered at runtime via open_softirq(). It takes two parameters:
		# a) Index
		# b) Handler Function
  # To mark it pending, so it is run at the next invocation of do_softirq(), call raise_softirq(). Softirqs are most often raised from within interrupt handlers
    # Softirq handlers run with interrupys enabled and cannot sleep
	# While a handler runs, softirqs on the current processor are disabled, another processor however can execute another softirq
	# If the same softirq is raised again while it is executing, another processor can run it simultaneously, which means any shared data needs proper locking
 	# most softirq handlers resort to per-processor data (data unique to each processor and thus not requiring locking), and other tricks to avoid explicit locking and provide excellent scalability

# GPIO debugging
 232. vcdbg log msg  # shows gpioman log details
 233. cat /boot/config-`uname -r` | grep GPIO   # shows gpio config optons
 
 #  Important Points related to softirqs
 # -------------------------------------
 # 1. Compile Time:
 # 	Declared at compile time in an enumerator
 # 	Not suitable for linux kernel modules
 # 2. Execution:
 # 	Executed as early as possible
 # 		After return of a top handler and before return to a system call
 # 	This is achieved by giving a high priority to the executed softirq handlers
 # 3. Parallel:
 # 	Softirqs can run in parallel
 # 	Each processor has its own softirq bitmap
 # 	One softirq cannot be scheduled twice on the same processor
 # 	One softirq may run in parallel on other
 # 4. Priority:
 # 	Kernel iterates over the softirq bitmap, least significant bit (LSB) first, and execute the associated
 # 	softirq handlers
 # 	
 # ksoftirqd
 # ============
 # Softirqs are executed as long as the processor-local softirq bitmap is set.
 # Since softirqs are bottom halves and thus remain interruptible during execution, 
 # the system can find itself in a state where it does nothing else than 
 # 	serving interrupts and 
 # 	softirqs
 # incoming interrupts may schedule softirqs what leads to another iteration over the bitmap.
 # Such processor-time monopolization by softirqs is acceptable under high workloads (e.g., high IO or network traffic), but it is generally undesirable for a longer period of time since (user) processes cannot be executed.
 # 
 # Solution to above problem by kernel
 # ======================================
 # After the tenth iteration(MAX_SOFTIRQ_RESTART) over the softirq bitmap, the kernel schedules the so-called ksoftirqd kernel thread, which takes control over the execution of softirqs.
 # Each processor has its own kernel thread called ksoftirqd/n, where n is the number of the processor
 # This processor-local kernel thread then executes softirqs as long as any bit in the softirq bitmap is set.
 # The aforementioned processor-monopolization is thus avoided by deferring softirq execution into process context (i.e., kernel thread), so that the ksoftirqd can be preempted by any other (user) process.
 235. ps -ef | grep ksoftirqd
 # The spawn_ksoftirqd function starts these threads.
 # It is called early in the boot process.
 # 
 # > static __init int spawn_ksoftirqd(void)
 # > {
 # >         cpuhp_setup_state_nocalls(CPUHP_SOFTIRQ_DEAD, "softirq:dead", NULL,
 # >                                   takeover_tasklets);
 # >         BUG_ON(smpboot_register_percpu_thread(&softirq_threads));
 # > 
 # >         return 0;
 # > }
 # > early_initcall(spawn_ksoftirqd);
 #  
 # File: kernel/softirq.c
 # Each ksoftirqd/n kernel thread runs the run_ksoftirqd()
 #  
 # > static void run_ksoftirqd(unsigned int cpu)
 # > {
 # >         local_irq_disable();
 # >         if (local_softirq_pending()) {
 # >                 /*
 # >                  * We can safely run softirq on inline stack, as we are not deep
 # >                  * in the task stack here.
 # >                  */
 # >                 __do_softirq();
 # >                 local_irq_enable();
 # >                 cond_resched();
 # >                 return;
 # >         }
 # >         local_irq_enable();
 # > }

 # If a softirq shares data with user context, you have two problems.
	# the current user context can be interrupted by a softirq
	# the critical region could be entered from another CPU
 # The solution to the first problem is a function void local_bh_disable() which disables softirq and tasklet processing on the local processor. void local_bh_enable() reverses this action, but these 
 # calls can be nested and only the final call to local_bh_enable() will enable bottom halves, thus the two functions have to be called an equal number of times.
 # In terms of locking between the user context and softirqs, spin_lock_bh() disables softirqs on the cpu then grabs the lock, spin_unlock_bh() release lockk and enable softirqs

 # Tasklets are a boottom half mechanism built on top of softirqs. Handlers of tasklets are executed by softirqs. They are implemented on top of softirqs and are represented by two softirqs, "HI_SOFTIRQ"
 # and TASKLET_SOFTIRQ. The only difference between these types is that HI_SOFTIRQ tasklets, run prior to the TASKLET_SOFTIRQ based tasklets. The state field of the tasklet_struct can be either zero
 # TASKLET_STATE_SCHED or TASKLET_STATE_RUN. TASKLET_STATE_SCHED indicates a tasklet that is scheduled to run, and TASKLET_STATE_RUN indicates a tasklet that is running. TASKLET_STATE_RUN is only
 # used on multiprocessor machines to protect tasks from being run concurrently on different processors. the "count" field of tasklet_struct is used as a reference count for the tasklet. if it
 # is non-zero the tasklet is disabled and cannot run. If it is zero the tasklet is enable and can run if pending. Tasklets can be ddeclared by either static initialization via the macros
   # DECLARE_TASKLET(name, func, data)
   # DECLARE_TASKLET_DISABLED(name, func, data)
   ^^^ The above macros have been changed to 
   # DECLARE_TASKLET(name, callback)
   # DECALRE_TASKLET_DISABLED(name, callback)
   and
   # DECLARE_TASKLET_OLD(name, func)
   # DECLARE_TASKLET_DISABLED_OLD(name, func)
   This change has been made to improve type safety as there was no proper type-checking for casting within the callback function, an to mitigate potential buffer overflow attacks, which could
   overwrite the callback pointer or the data field.
   
 # Both of the above macros create a struct tasklet_struct with the given name. When the tasklet is scheduled, the given function func is executed and passed data as a reference count. The main difference
 # between the initialised structs is the initial reference count (^^^see above). A tasklet can also be initialized dynamicall with the function tasklet_init:
   # void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data);
 # The kernel mains two per-CPU linked lists for scheduling tasklets, both can be found in ernel/softirq.c and are linked lists of tasklet_struct structures, they are initialised with
 # either tasklet_vec or tasklet_hi_vec as the 2nd parameter and tasklet_head as the first parameter. tasklet_hi_vec repreesents high priority tasklets run by HI_SOFTIRQ and regular tasklets run 
 # by TASKLET_SOFTIRQ. Tasklets are scheduled via tasklet_schedule() and tasklet_hi_schedule(), which operate in the same way, the difference being using either tasklet_vec or tasklet_hi_vec and using
 # TASKLET_SOFTIRQ and HI_SOFTIRQ. Thes steps performed are:
   # Check whether tasklet's state is TASKLET_STATE_SCHED. If it is, taskle is already scheduled to run and the function can immediately return
   # Call __tasklet_schedule()
   # Save the state of the interrupt system, then disable local interrupts (including softirqs) by calling local_irq_save.
   # Add tasklet to tasklet_vec or tasklet_hi_vec linked list, which is unique for ech processor in the system
   # Raise TASKLET_SOFTIRQ or HI_SOFTIRQ so do_sofgtirq() executes the tasklet in the near future
   # Restore interrupts to their previous state and return
 # softirq_init function calls open_softirq with tasklet_action/tasklet_hi_action args. Steps performed by tasklet softirq handlers tasklet_action() & tasklet_hi_action() are (in tasklet_action_common):
   # Diswable local interrupt delivery and stores the tasklet_vec or tasklet_hi_vec for the processor in a local variable
   # Clears the list for the processor by setting it to NULL
   # Enable loal interrup delivery
   # loops over every pendingt tasklet in the stored list
   # Checks for a zero count value to ensure the tasklet is not disabled, if disabled skip to next tasklet
   # Run the tasklet handler function/callback
   # Repeat for nex pending tasklet until no more tasklets left to run
 # the kernel avoids running the same tasklet on multiple processor sby using the functions tasklet_trylock and tasklet_unlock. trylock will check whether TASKLET_STATE_RUN is set or not, and set it
 # if not, and tasklet_unlock will clear the TASKLET_STATE_RUN bit if it is set. You cannot sleep in the tasklet handler function
 # softirqs are allocated at compile time, whereas tasklets can be dynamically registered. Softirqs can be run on different processors, whereas the same tasklet will not be scheduled on different procesors.
 # workwqueues allow kernel functions to be activated and later executed by special kernel threads called worker threads. These run in process context. It's the only choice when you need to sleep in
 # your bottom half, i.e. I?O data, mutexes/semaphores and all other functions that internally sleep. implementation is found in kernel/workqueue.c, documentation is found in Documentation/core-api/workqueue.rst
 # A work queue conssists of:
   # work item: struct which holds the pointer to the fucntion to be executed asynchronously
   # work queue: a queue of work items
 # Drivers add work items onto the work queue. And worker threads are special purpose threads that execute functions from the queeue, one after the other. If no work is queued, the worker threads 
 # become idle. Can be found via:
 236. ps -ef | grep kworker
 # Worker Pools: A thread pool that is used to manage the worker threads. There are two work pools, one for normal work items, the other for high-priority ones, extra worker-pools to serve
 # work items queued on unbound workqueues
 # create_worker is the function where kthreads are created. Legacy workqueues had dedicated threads associated with them. In new workqueues there are no threads dedicated to any specific workqueue
 # Instead there is a global pool of threads (worker pool) attached to each CPU in the system. When a work item is queued, it will be passed to one of the global threads at the right time.
 # Important data structures are: 
   # workqueue -- struct workqueue_struct 
   # work items -- struct work_struct
   # > struct work_struct{
     >   atomic_long_t data;   
     >   struct list_head entry;
	 >   work_func_t func;
	 > };
   # 'func' here is a pointer that takes the address of the deferred routine -
   # typedef void (*work_func_t)(struct work_struct *work);
 # Initialization of Work Items. The header file is: <linux/workqueue.h>, 
 # Static initialization: declare and initialize a work item
   # DECLARE_WORK(name, void (*function)(void *), void *data);
 # Dynamic initialization: initialize an already declared work item  
   # INIT_WORK(struct work_struct *work, void(*function)(struct work_struct*)); 
 # API's to queue work : This function enqeues the given work item on the local CPU workqueue, but does not guarantee its exectution on it,
   # > bool queue_work(struct workqueue_struct *wq, struct work_struct *work);
 # Once queued, the function associated with the work item is executed on any of the available CPUs by the relevant kworker thread. To queue on a specific CPU:
   # > bool queue_work_on(int cpu, struct workqueue_struct *wq, struct work_struct *work)  # where cpu: CPU number to execute work on. This returns false if work is already on a queue, true otherwise
 # Workqueue API provides two types of function interfaces to
   # a) Create own workqueue
   # b) Use System Workqueue 
          > extern struct workqueue_struct *system_wq;  # located in header file <linux/workqueue.h>, the system workqueue is shared by all kernel subsystems and services 
 # There are inline functions associated witjh workqueues:
   # schedule_work - puts work task in a global workqueue
   # > static inline bool schedule_work(struct work_struct *work)
   # > {
   # >    return queue_work(system_wq, work);
   # > }
   # schedule_work_on - puts work task on a specific cpu
   # > static inline bool schedule_work_on(int cpu, struct work_struct *work)
   # > {
   # >     return queue_work_on(cpu, system_wq, work);
   # > }
 # Usually work is enclosed in a large structure (for driver private data)
 # If you want your bottom half to run in the process context, there is only one option which is workqueues
 # Work items cannot be enabled/disabled, but they can be canceled by calling cancel_work-sync()
   # bool cancel_work_sync(struct work-sturuct *work0;
 # The call only stops the subsequent execution of the work item. If the work item is already running at the time of the call, it will continue to run. returns true - if the work was pending, and false otherwise
 # In order to flush_work:
   # > bool flush_work(struct work_struct *work)  - waits for work to finish executing the last queueing instance. returns true if waited for the work to finish execution, false if already idle
 # The workqueue API allows you to queue work tasks whose execution is guaranteed to be delayed at least until a specified timeout. This is achieved by binding a work task with a timer, which
 # can be initialized with an expiruy timeout, until which the work task is not scheduled into thequeue
 # > struct delayed_work {
 # >     struct work_struct work;
 # >     struct timer_list timer;
 # >
 # >     /* target workqueue and CPU ->timer uses to queue ->work */
 # >     struct workqueue_struct *wq;
 # >     int cpu;
 # > };
   # timer is an instance of a dynamic work descriptor, which is initialized with the expiry interval and armed when scheduling a work task
 # Initialization methods are either static or dynamic
   # Ststaic - DECLARE_DELAYED_WORK(name, void(*function)(struct work_struct*));
   # Dynamic - INIT_DELAYED_WORK(struct delayed_work *work, void(*function)(struct work_struct*));
 # Scheduling is done via either:
   # bool schedule_delayed_work(struct delayed_work *dwork, unsigned long delay);
   # bool schedule_delayed_work_on(int cpu, struct delayed_work *dwork, unsigned long delay);
     # the delay in each case needs to be provided in jiffies
 # To cancel the delayed timer and queue any pending work for immediate execution:
   # bool flus_delayed_work(struct dealyed_work *dwork);
 # To cancel delayed work the function prototype is:
   # bool cance;l_delayed_work(struct delayed_work *dwork);
 # Differences between Tasklets, softirqs and Workqueues
 # ========================================================
 #                 ------------------------------------------------------------------------------
 #                 Softirqs                        Tasklets                        Workqueues
 #                 -----------------------------------------------------------------------------
 # Execution       Interrupt context               Interrupt Context               Process Context
 # Context
 # ----------------------------------------------------------------------------------------------------------------
 # Reentrancy      Yes(can run simultaneously      Cannot run same tasklets        Yes (can run simultaneously
 #                 on different CPUs)              on different CPUs. Different    on different CPUs)
 #                                                 CPUs can run different tasklets
 # --------------------------------------------------------------------------------------------------------------
 # Sleep           Cannot sleep                    Cannot Sleep                    Can Sleep
 # --------------------------------------------------------------------------------------------------------------
 # Preemption      Cannot be preempted/scheduled   Cannot be preempted/scheduled   May be preempted/scheduled
 # -----------------------------------------------------------------------------------------------------------
 # Ease of use     Not easy to use                 Easy to use                     Easy to use
 # -------------------------------------------------------------------------------------------------------------
 # When to use     If deferred work will not       If deferred work will not go    If deferred work needs to sleep
 #                 go to sleep and have crucial    to sleep
 #                 scalability or speed
 #                 requirements
 # ----------------------------------------------------------------------------------------------------------------
 # kworker processes are kernel worker processses, found in 'Documentation/admin-guide/kernel-per-CPU-kthreads.txt', Naming convention: kworker/%u:%d%s (cpu, id, priority). Theyb can be of two types:
   # CPU Bound  : It is named as kworker/<corenumber>:<id.
   # CPU Unbound: It is named as kworker/u,Poolnumber>:<id>
 237. ps -ef | grep kworker
		> root           8       2  0 15:54 ?        00:00:00 [kworker/0:0H-kblockd]  -> running on CPU0 and threadID 0 andd is high priority bounded
		> root          24       2  0 15:54 ?        00:00:00 [kworker/1:0H-events_highpri]
		> root          30       2  0 15:54 ?        00:00:00 [kworker/2:0H-events_highpri]
		> root          36       2  0 15:54 ?        00:00:00 [kworker/3:0H-kblockd]
		> root          54       2  0 15:54 ?        00:00:00 [kworker/2:1-events]
		> root         104       2  0 15:54 ?        00:00:00 [kworker/2:1H-kblockd]
		> root         111       2  0 15:54 ?        00:00:00 [kworker/u8:2-events_power_efficient] 
		> root         116       2  0 15:54 ?        00:00:00 [kworker/u8:3-events_unbound] -> u designates a spedcial CPU, the unbound cu, meaning that the kthread is currently unbound, runs on any cpu
		> root         119       2  0 15:54 ?        00:00:00 [kworker/1:1H-kblockd]
		> root         124       2  0 15:54 ?        00:00:00 [kworker/3:1H-kblockd]
		> root         125       2  0 15:54 ?        00:00:01 [kworker/2:2-events]
		> root         137       2  0 15:54 ?        00:00:00 [kworker/u9:0]
		> root         197       2  0 15:54 ?        00:00:00 [kworker/0:2-events]
		> root         198       2  0 15:54 ?        00:00:00 [kworker/0:1H-kblockd]
		> root         801       2  0 15:54 ?        00:00:00 [kworker/0:3-cgroup_destroy]
		> root        3191       2  0 16:00 ?        00:00:00 [kworker/3:0-events]
		> root        3203       2  0 16:00 ?        00:00:00 [kworker/1:0]
		> root        4411       2  0 16:12 ?        00:00:00 [kworker/3:1-events]
		> root        4412       2  0 16:12 ?        00:00:00 [kworker/1:1-events]
		> root        4413       2  0 16:13 ?        00:00:00 [kworker/u8:0-ext4-rsv-conversion]
		> root        5866       2  0 16:31 ?        00:00:00 [kworker/0:0]
 # taskset is used to set or retrieve the CPU affinity of a running process given its PID or to launch a new COMMAND with a given CPU affinity
 238. taskset -p 104 # is in hex, 
       #cpu0=bitmask 0x1/0b00000001, cpu1=bitmask 0x2/0b00000010,cpu2=bitmask 0x4/0b00000100, cpu3 = biitmask 0x8//0b00001000, cpu4 = bitmask 0x10/0b00010000, cpu5 = bitmask 0x20/0b00100000, etc...
        > pid 104's current affinity mask: 4
 # For a 4 core system, unbounded kthread affinity mask is f. For a 6 core cpu, unbvounded ktrhread affinity mask is 3f
 239. cat /proc/$(pid_of_kworker)/stack   # will return what any kworker is doing
 # Timig of the execution of work items scheduled onto the global workqueue is not predictable.. one log-running work item can always cause indefinite delays for the rest. 
 # Alternatively the workqueue framework allows the allocatiion of dedicated workqueues
   # struct workqueue_struct *alloc_workqueue(const char *fmt, unsigned int flags, int max_active, ...);  -> this function allocates a workqueu
     # The Paramteers are: 
	   # fmt: printf format for the name of the workqueue
	   # flags: control how work items are assigned execeution resources, scheduled and executed
	   # max_active: This parameter klimits the number of work items which can be executed simultaneously from this workwueue on any given CPU
	   # ... == (remaining args): args for @fmt
 # destroy a workqueue	
 # Dedicated workqueues - Timing of the execution of work items scheduled onto the global workqueue is not predictable, on long-running work-item can cause delays for the rest.
 # lternatively the workqueue framework allows for the allocation of dedicated workqueues
   # > struct workqueue_struct* alloc_workwqueue(const char *fmt, unsigned int flags, int max_active, ...);  # This function allocates a workqueue, returns workqueue_struct*
   # The paraameters in the above function are:
     # fmt: printf format for the name of the workqueue/
     # flags: control how work items are asigned execution resources, scheduled and sorted
     # max_active: This parameter limits the number of work items which can be executed simultaneously from this workqueue on any given CPU
     # remaining args: args for @fmt
 # destroying a workqueue	 
   # > void destroy_workqueue(struct workqueue_struct *wg);  # function to safely terminate a workkqueue; all work currently pending will be done first
 # WQ_UNBOUND is a flag that can be passed in to alloc_workqueue. Workqueues created with this flag are managed by kworker-pools that are not bound to any specific CPU.
   # Scheduled work items to this queue can be run on any processor, and work-items in this pool are executed as soon as possible by kworker pools
 # WQ_HIGHPRI is a flag used to mark a workqueue as high priority. It is queued to the high-pri worker-pool of the target cpu. Highpri worker-pools are served by worker threads with wlevated nice level
 # Nice value ranges from -20 (highest priority level) to 19 (lowest priority level). The default value is 0. T check the nice value
 240. ps ax -o pid,ni,cmd  # prints output of pid, nice value and process name.
 # The definition on the inline to_delayed_work function can be found in the header file <linux/workqueue.h>, and is as follows:
 # > static inline struct delayed_work *to_delayed_work(struct work_struct *work)
 # > {
 # >     return container_of(work, struct delayed_work, work);
 # > }
 # To perform tasks periodically, can requeue the work from the work function itself (recursive call, at the end of the function, discarding previous stack frame)
 # A given workqueue can be made visible in the sysfs filesystem by passing the WQ_SYSFS to that wokqueue's alloc_workqueue()
 241. ls /sys/devices/virtual/workqueue
   > drwxr-xr-x 3 root root    0 Apr  2 11:05 blkcg_punt_bio
   > -rw-r--r-- 1 root root 4096 Apr  2 16:47 cpumask
   > drwxr-xr-x 2 root root    0 Apr  2 16:47 power
   > drwxr-xr-x 3 root root    0 Apr  2 11:05 scsi_tmf_0
   > drwxr-xr-x 3 root root    0 Apr  2 11:05 scsi_tmf_1
   > drwxr-xr-x 3 root root    0 Apr  2 11:05 scsi_tmf_2
   > -rw-r--r-- 1 root root 4096 Apr  2 11:05 uevent
   > drwxr-xr-x 3 root root    0 Apr  2 11:05 writeback
 242. cat /sys/devices/virtual/workqueue/cpumask
   > f  # this means workqueues can execute on any cpu as this mask covers all cpus (on the current system)
 243. echo 1 > /sys/devices/virtual/workqueue/cpumask   # will only execute on cpu0
 # WQ_SYSFS flag causes "my_queue" to show at "ls /sys/devices/virtual/workqueue/" if used in "my_queue = alloc_workqueue("my_queue", WQ_UNBOUND | WQ_SYSFS, 1);"
 244. ls /sys/devices/virtual/workqueue/my_queue
   > cpumask  max_active  nice  numa  per_cpu  pool_ids  power  subsystem  uevent
 245. cat /sys/devices/virtual/workqueue/my_queue/cpumask # WQ_UNBOUND flag or a mask covering all processors
   > f  
 # queue inherits mask from /sys/devices/virtual/workqueue/cpumask so if cpumask there set to 1, despite WQ_UNBOUND is bound to cpu0
 246. cat /sys/devices/virtual/workqueue/my_queue/nice   # using WQ_UNBOUND flag, set nice level to 0
   > 0
 247. cat /sys/devices/virtual/workqueue/my_queue/pool_ids    # current->comm == kworker/u10:0
   > 0:10
 # Other flags that can be passed to alloc_workqueue() are: 
   # WQ_FREEZABLE: A freezable wq participates in the freeze phase of the system suspend operations. This flag can be used in the context of power management and file systems, and is especially important
     # for creating the system image in the suspend phase. Workqueues which can run tasks as part of the suspend/resume process should not have this flag set. 
	 # You can find more information abour this topic in Documentation/power/freezing-of-tasks.txt
   # WQ_MEM_RECLAIM: All workqueues which might be used in the memory reclaim paths must have this flag set. The workqueue is guaranteed to have at least one worker, a so-called rescuer thread, regardless
     # of memory pressure. If we have the following scenario where 
	   # Workqueue W has 3 items A, B and C:
       # A does some work and then waits until C has finished some work.
       # Afterwards, B does some GFP_KERNEL allocations and blocks as there is not enough memory available.
       # As a result, C cannot run since B still occupies W's worker
	   # Another worker cannot be created because there is not enough memory
	   # A pre-allocated rescuer thread can resolve this problem, by executing C, which then wakes up A
	   # B will continue as soon as there is enough available memory to allocate
   # WQ_CPU_INTENSIVE: Tasks on this workqueue can be expected to use a fair amount of CPU time. In other words, runnable CPU intensive work items will not prevent other work items in the same worker pool
     # from starting execution
  # void flush_workqueue(struct workqueue_struct *wq);  -  this functions sleeps until all work items were queued on entry have been finished, is typically used in driver shutdown handlers.
  # WQ_MAX_UNBOUND_PER_CPU - number of unbound workqueues that can be associated with a cpu
  # WQ_UNBOUND_MAX_ACTIVE - total number of unbound workqueues
  # "#define alloc_ordered_workqueue(fmt, flags, args...) - allocates an ordered workqueue, which executes at most one work item at any given time queued order. They are implemented as unbound workqueues
  # with max_active of one
	   
	
