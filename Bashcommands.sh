   44  #netstat -an | grep 3389
   45  zip -r ../foodvision_big.zip * -x "*.pyc" "*.ipynb" "*__pycache__*" "*ipynb_checkpoints*"
   46  sed -i '1573,1588{/^[ ]*$/d}' Linuxcommands.txt
   47  sed -i '/^[[:space:]]*$/{N;/^\n[[:space:]]*$/d;}' Geminiconversation.txt  #delete consecutive blank lines and lines only containing whitespace
   	# {N;/^\n[[:space:]]*$/d;}: This is a block of commands that gets executed when the pattern /^[[:space:]]*$/ is matched.
   		# 'N': Adds a newline to the pattern space (i.e., the working buffer), then appends the next line of input to the pattern space. If there is no more input, N does nothing.
    		# '/^\n[[:space:]]*$/': After the N command, this pattern matches if the pattern space consists of a single newline character (meaning the current line being processed is empty and was followed by another empty line).
      		# 'd': Deletes the pattern space; since the pattern space is output by default, deleting it effectively removes the matched lines from the output.
   48  your_command | sed 's/\x1b\[[0-9;]*m//g' > output.txt  
   	# removes formatting from stdout output being written to file, i.e $PS1 formatting, colour formatting
    		# '\x1b': Represents the escape character in hexadecimal, 
      		# '\[[0-9;]*m': Matches the sequence of characters typically used for formatting.  
   49 while (( line > 0 )) ; do   # line length formatter command 
      > length=$(sed -n "${line}p" oceanwires.txt | wc -c | awk '{print $1}'); 
      > segments=$(( length / 160 )); 
      > while (( length > 180 )) ; do 
      > sed -i "${line}s/\([^$]\{$(( segments * 160 ))\}[0-9A-z\"\'()]\+\b[,. ]*\)/\1\n/" oceanwires.txt ; 
      > (( -- segments )); 
      > length=$(sed -n "${line}p" oceanwires.txt | wc -c | awk '{print $1}'); 
      > done; 
      > (( -- line )); 
      > done
#Updating JAVA
   50  sudo update-java-alternatives --set java-1.11.0-openjdk-amd64
       export JAVA_HOME=/path/to/jdk
       export PATH=$JAVA_HOME/bin:$PATH
       sudo ln -sfn /path/to/jdk /usr/lib/jvm/default-java
   51 du -sh * | sort -hr | head -n 10  # lists top 10 largest files from the current directory
   52 host 185.125.190.83   # will resolve hostname information from an ip address
       # 83.190.125.185.in-addr.arpa domain name pointer ubuntu-mirror-3.ps5.canonical.com.
   53 ps aux --sort -rss   # sorts the output of the ps aux command by memory usage
  207  (php -S 0.0.0.0:4321 &) && sleep 2 && curl -G http://0.0.0.0:4321/Africa006.jpg    # chains commands and runs first command as a background process   
  208  chmod g+x u+x /home/ltetteh     #plus will add permissions     
  208  chmod g-rx u-wx /home/ltetteh   #minus will remove permissions
  208  chmod u=rwx, g=rx, o= /home/ltetteh  #equal rewrites permissions can also be group ug=rwx, or ug+rx
  209  wget -q https://github.com/ShivamShrirao/diffusers/raw/main/scripts/convert_diffusers_to_original_stable_diffusion.py
  758  sudo mv# /etc/sysconfig/network-scripts/ifcfg-eno1temp /etc/sysconfig/network-scripts/ifcfg-eno1
 1009 !c #runs last command beginningw with letter(s) specified after !1008 runs history command
 1010 !$ #runs last argument 
 1011 !?etc # would run last command that contains etc anywhere
 1012 ctrl+r+esc #reverse search for editing
 1013 history -c # clears history
 1014 history -r # reads
 1015 cat -vet "filename" # will place $ symbol at the end of each line
 1016 tac #displays lines in reverse order
 #winSCP, bash utility
 1020 yum whatprovides */dig        # usr/bin/dig == */dig 
 1021 ls /proc                      # where all process id files are stored along with version info etc.
 1022 cat /proc/version             # shows linux version/distro info, how it was compiled,, cross-compiler etc.
 1023 cat /proc/mounts              # if file systems are mounted, shows the file systems available to the user at that moment, is stored in memeory not on disc, near equivalent to windows looking at registry and control set i.e. regedit. Within the mounts file can see devices/disks and THE directories to which they are mounted.
 1024 cat /proc/sys/net/ipv4/ip_forward  # ip version for forwarding, returns 1 if routing/ip  forwarding enabled
 1025 vi /etc/passwd                # stores user account details
 1026 less /etc/services	    # less file viewer with text search and page-by-page view, /etc/services displays port numbers and services mapped to those ports, :85G example to go to line 85, q to quit
 1027 cut -f1,3 -d":" /etc/passwd | tail -n 3    # displays 1st and 3rd field, where delimiter -d is ":", tail must be piped will have no effect if included before /etc/passwd as input to cut command
 1028 sort /etc/passwd              # displays lines in the file in alphabetical order
 1029 sort -r /etc/passwd           # reverse sort
 1030 sort -k4 -t":" /etc/passwd    # sorts by 4th column/field with -t specifying the delimiter, -n for numeric sort
 1031 cut -f1,f6 -d":" /etc/passwd | sort -u -k2 -t":" | sed "s/:"/ - /g"    #pipes commands, displays first and 6th fields, sorts by second field of cut output, replaces colon with sapce and hyphen
 1032 cp/mv -i -R -a                # -R means recursive so mives contents of directory, -a maintains all original permissions and properties, -i creates a prompt
 1033 ls -lt                        # orders by datewhat
 1034 fdisk -l                      # shows mounted disk images/drive partitions      --- allows creationn and manipulation of partition tables. Understands GPT, MBR, Sun, SGI and BSD partition tables
 1036 rsync -av /home/ /backup      # -a maintains permissions/archives, v for verbose, rsync synchronizes directories, so will find only differences before copying to path
 1037 useradd -m bob                # creates new user 
 1038 tar -cvf downloads.tar ~/Downloads/   # -c create -v verbose -f filename, then directory to make tar (tape archive)
 1038a tar -caf downloads.tar.gz ~/Downloads/   # -a tells tar to work out what compression algorithm to use for the file type 
 1039 tar -cvzf downloads.tgz ~/Downloads/  # -z zips with gzed, creates tgz file
 1040 time $!          grep             # prov-ides time taken for command
 1041 tar -cjvf downloads.tar.bz2 ~/Downloads   # -j uses stronger compression algorithm, yields time tar.bz2, zips with bzip2
 1042 file downloads.tar.bz2        # provides file information, compression information
 1043 tar -tjf downloads.tar.bz2    # will show contents without expanding the file
 1044 tar -xjvC ~/Downloads2 -f downloads.tar.bz2  # will unzip contents of file to dest folder
      unzip $filename   # unzips zip files
 1045 find -newer downloads.tar.bz2 -type f -delete  # will find files modified more recently than the file stated and delete them
 1046 find -name "*.png" -exec ls -lh {} \;   # -exec will run commands on find results {} \; needed to end -exec command
 1047 2>&1                          # specifies stream 2 is being sent to the same location as stream 1
 1048 man set                       #list bash builtins incluidng set
 1049 set -o                        #list set -o options
 1050 set -o noclobber              #means that file cannot be overwritten via > command
 1051 ls >| file.txt                #means that file can be overwritten when noclobber option is set
 1052 df -h                         #report filesystem disk space usage, -h for human readable format
 1053 mkfifo /tmp/temppipe          #creates a named pipe
 1054 ls -l /tmp/temppipe           #returns type p for pipe
 1055 ls > /tmp/temppipe            # stores command, not data
 1056 wc l < /tmp/temppipe          # another user in another terminal can run command from pipe file, using it Fseda piped command
 1057 ls | tee myfile               # tee outputs to screen and writes to file at same time 
 1058 jobs                          # shows any running commands 
 1059 bg                            # if a command has been run and stopped with ctrl+z, can then be shifted into the background
 1060 fg 1                          # can be used with job numer, e.g 1 or 2 and will bring the job into the foreground
# default kill signal is kill -15 which can be written as -term -sigterm
# stone-dead kill signal is kill -9, -kill, -sigkill
 1061 ps -l                         # long listing
 1062 pkill sleep                   # will send a -sigterm signal to all processes called sleep
 1063 top                           # displays active running processes sorted by CPU usage, refreshes indefiniitely
 1064 top -n 3                      # will display 3 refreshes of the top processes table, l toggles load averages on/off, t toggles tasks on/off, m to toggle through memory information, 
 1065 pgrep chrome   #returns process id           (vertical list)
 1065 pidof chrome   #returns processid of process (horizontal list)
# f to toggle to field select tab, s to choose sort values within field select tab, r allows for renice command, k send a signal to kill
 1065 renice +1 987 -u daemon root -p 32   # The following command would change the priority of the processes with PIDs 987 and 32, plus all processes owned by the users daemon and root, increasing 'nice value' chooses a lower priority
 1066 uptime                        # shows uptime and load averages 
 1067 killall                       # man for op:tions
 1068 grep '\bword\b' ${file}       # \b defines word boundaries so wouldn't find "words" or "keyword", assume use of $IFS, can use ^, $, *, etc.
 1069 grep -v 'word' ${file}        # -v returns lines excluding search
 1070 grep -e 'word' -e 'turn' ${file}   # -e allows more than one expression
 1071 grep -ve 'word' -ve '^$' ${file}        # '^$' empty lines
 1072 sed -i '/^#/d;/^$/d'${file}  # will remove all empty lines and commented lines from the file in question, remember semicolon separator for doubled expressions
# egrep == grep -E, both are interchangeable, enhanced regular expression
 1073 grep -E '[A-Z]{1,2}[0-9]{1,2}[A-Z]?\s[0-9][A-Z]{2}\b' ${file}   # search for postcode [A-Z]{1,2} A to Z for 1 or 2 letters [0-9]{1,2} 0 to 9 for 1 or 2 digits [A-Z]? optional extra letter \s is space [0-9] 0 to 9 for 1 digit [A-Z]{2} A to Z for 2 letters, \b word boundary
 1074 vi +127 /etc/services        # will go to 127th line of the document, set nohlsearch/set hlsearch 
 1075 vi +/DocumentRoot /etc/httpd/httpd.conf   # will go to line containing phrase 
# within vi :r ${filename} will append Ccontents of ${filename} to current file position, 
#:line1,line2w ${filename} will write to a file in whatever directory the user was in before opening
#:r! hostname, :r! id , :r! date, etc. (bash globals)
#:%s/IANA/cabbage/ sed replace, % specifies whole file but can put line numbers here, i.e 1,3. /word will search for word
# system wide configuration file for vim is /etc/vimrc/ personal is in ~/.vimrc, overrides  
 1076  ls -aR /etc/ | grep 'rc$'   #configuration files for various s and utilities
 1077 nmap <C-N> :set invnumber <CR> #<C-N>==Ctrl+n <CR>== carriage return
 1078 chown asterisk:asterisk /home/opus/recordings/   # gives asterisk permission to write to directory
 1079 chmod 775 /home/opus/recordings   # code which gives read,write, execute access to all, users, groups, binary code .e. 7=4+2+1, 5=4+1
 1080 sed "N;s/\n//;"  #:qqmerges every two lines
 1081 bash   # opens new terminal window/subshell, can use exit to return to previous terminal
 1082 type set   # functions similarly to which returning path to binary, but also returns builtins, in this case returns "set is a shell builtin"
 1083 set FRUIT=apple  # now in variable list
 1083 set   #returns a list of local and global variables that have been set
 1084 env  #returns only global variables
 1085 export FRUIT  #makes local variable into global, accessible from new terminal window/subshell for example if 'bash' command is used   
 1086 set -o  #returns a list of shell options and their current state
 1087 set -o allexport  # any new variable created will be a global variable for all subshells of the session
 1088 set -o ignoreeof  #disable ctrl+d (other functions?)
 1089 type ls   #returns ls is ed to 'ls --color=auto' (which returns binary path and alias information)
 1090 \ls   #runs ls command without the alias - no color option
 1091 alias   #returns the aliases currently present and accessible from the curent terminal/command window, can set from command window as well as .bashrc file
 1092 unalias varname   #unalias any alias previously set with the alias command
 1093 PROMPT_RED="\[\033[1;31m\][\u@\h \w]$\[\033[0m\] "     # \033=ESC-key 1;31=color m=marks the end, next square bracket=signals the start of the normal prompt \u@\h=username@hostname \w=signals long path to the directory $=presents a standard user \[=escapes the square bracket \033=ESC-key  0m=resets the color after the username
 1094 PROMPT_BLUE="\[\033[1;34m\][\u@\h \w]$\[\033[0m\] "     # \033=ESC-key 1;34=color m=marks the end, next square bracket=signals the start of the normal prompt \u@\h=username@hostname \w=signals long path to the directory $=presents a standard user \[=escapes the square bracket \033=ESC-key  0m=resets the color after the username, or after escpe key wherever it is
 1095 function do prompt { if [[ $1 == 'red' ]] ; then ; export PS1=$PROMPT_RED ; else echo $PS1; export PS1=$PROMPT_BLUE ; fi }   #will open up some lines for multi-line input
# two in built scripts .bash_profile appends to $PATH and .bashrc which runs each time a shell is launched
 1096 vi .bash_profile   # shows PATH variable, and script loading bashrc
 1097 source ~/.bashrc   #reloads bashrc
 1098 bash -x <scriptname>  #for script debugging, shebang 
 1099 read     # within script command will pause script execution on a line #!/bin/bash -x in header will also provide debugging
 1100 for u in $*   #will iterate through all input arguments $1,$2,$3, etc.
 1101 echo -e "hello \c"   # each echo -e "\c" command will be printed on the same line   
 1102 sed -i.bak "14i\configure \"   #each \ will signify a new line, for use in scripts use "14i\\configure \\", .bak creates a backup
# pid 1 is /usr/lib/systemd/systemd system initialization daemon. systemctl commands applied   
 1103 systemctl get-default   #returns graphical.target
#traditional runlevels, runlevel=3 being text environment, runlevel=5 being graphical environment
 1105 systemctl set-default   # can set different default target, will boot to target at different runlevel if selected i.e. runlevel 3
 1106 startx   #starts up graphical environment from the command line
 1107 ps -l 1   #loads process with pid of 1, /usr/lib/systemd/systemd#
# cat OPUSTest/scripts/mos_audio_rtp.txt | grep "Audio in RTP" | cut -f8 -d" " | sed "s/$/,/g" | sed "N;s/\n//;s/,$//g"| tail | cut -f2 -d","
 1108 ls /etc/X11    # contains some config files/directories
 1109 ls /boot    # contains some config files
 1110 cd /etc/dconf/db/gdm.d/   # display manager folder, once with can create new file/directory which manages the locks to display manager
 1111 vi 00-login-screen { [/org/gnome/login-screen] ; disable-user-list=true}    # config file for gdm lock screen, number at the front priority value
 1112 dconf update    # updates settings
 1113 cat /etc/X11/xorg.conf.d/00-keyboard.conf   # returns keyboard settings, has Section *** EndSection layout for different elements. 
 1114 fc-cache -f -v   #searches through certain directories in order to cache new fonts. #/.fonts iFs one such directory to add new fonts into, -f -v shows feed and verbose
# gnome has settinsgs available under ur profile in top-right-hand corner
 1115 id   #returns uid, gid, and groups
 1116 useradd -D   #returns user defaults, GROUP, HOME (directory), INACTIVE, EXPIRE (expriy date), SHELL, SKEL, CREATE_MAIL_SPOOL stored at /etc/default/useradd
 1117 useradd -m accountname   #creates a home directory 
 1118 :r! sed -n 147,227p /path/to/foo/foo.c   #reads in specific suabset of lines/range of lines
 1119 showkey -a  #returns hexadecimal representation of key sequence
 1120 [lindex $argv n]    # within bash script it specifies the position of arguments passed to the script, beginning at n=0, but is also related to expect statement (research further)
 1121 yum search expect   # /usr/bin/expect allows expect calls for interactive programming
 1122 passwd -l $username # locks user account for specified username (expires passsword)
 1123 passwd -u $username # unlocks user account  
 1124 /etc/shadow  # displays password info, i.e. encryption method ($6 specifies sha255), if there is an exclamation mark user account is locked and the integer variable following will detail how many days ago the password was last changed (i.e. when it was expired)   
 1125 date --date "16 days ago"   # returns date in Day Mon Date Time Timezone Year format
 1126 usermod bob -c "Bob Smith"  # adds a comment to the /etc/passwd file (as field after username) 
 1127 userdel -r bob   # will remove account plus home directory and mail spool
# groupadd, groupmod, groupdel, /etc/group, /etc/gshadow gpasswd newgrp grpconv/grpunconv man 5 gshadow
 1128 /etc/group   # returns 4 fields groupname:password:gid:user list, comma separated
 1129 /etc/gshadow  # returns 4 fields groupname:encryptedpwd:Adminlist:Members
 1130 /etc/login.defs  # returns config file options for shadow-utils (essentially behaviour for groups and user accounts)
# if within config file USERGROUPS_ENAB is set to no/off users will join  default group, otherwise they an be assigned to a private group
 1132 useradd -m -g users leslie   # -g flag specifies the group, which in this case is users
 1133 usermod -G ssh_keys ltetteh  # can add secondary group association for user. however group ownership of created items belong to primary group id (can be changed)
 1133 usermod -a -G tcpdump opus   # appends user to supplementary group (without removing other group associations e.g. sudo) 
     1133a sudo usermod -a -G dialout your-username
	   sudo usermod -a -G tty your-username
    # commands above needed to allow a user to query a serial port (at least on Ubuntu 22.04 LTS default configuration)
 1134 useradd -N -m user  # creates with no individual group, simply the one defined by -g option or created as the default. -m defines home directory
 1136 man 5 gshadow  # manual entry for /etc/gshadow
 1137 man 5 group  # manual entry for /etc/groups
# private goups if enabled will ad a user to a roup with the same name as the user - defaullt file 
 1138 /etc/login.defs  # login defaults file
 1139 gpasswd -M user,user2,user3  groupname  # 
 1141 gpasswd $groupname  #change password for shoes
 1142 newgrp $groupname   #if in user account will add user to group
# user cron jobs stored in /var/spool/cron/<user>
# system cron jobs stored in/etc/cron.d
 1143 vi /etc/crontab  (example output)  5 20 * * 1-5 root /usr/sbin/backup.sh   #system cron job format command, 7 fields; minute(0-59), hour(0-23), day of month(0-31), month(1-12), day of week(0-7), user(root), command(backup.sh)
*/5 8-16 * * 1 ls /tmp  #creates user crons in /var/spool/cron/crontabs/ 6 fields; minute(0-59), hour(0-23), day of month(0-31), month(1-12), day of week(0-7), command (user is always user who ran cron tab; */5=every 5 minutes, 8-16 between 8am-4pm, every day of month, every month, on Mondays , commmand ls /tmp
* 23 * * 1-5 ls /tmp       # first field * = every minute
15,45 23 * * 1-5 ls /tmp   # first field 15,45 = 23:15, 23:45
1-59/3 23 * * 1-5 ls /tmp  # first field = step through range every 3 minutes
 1145 ls /etc/cron*   # lists all files in /etc folder beginning with cron, returns /etc/ccrontab, /etc/cron/d is the extension directory, and is the extension directory, extension of original crontab file, idf systat or php installed can drop cron file ino cron.d without worrying about editing. files in cron.daily run daily, but will all run at the same time leading to potential problems.
#creating own cron job
 1146B vi daily-backup   #cron job as opposed to script, does not need to be made into an executable
 1146C (within vi)  30 20 * * 1-5 root /root/back.sh    #adds script to cron jobs
# 
 1147 kill -5 psid   # sigtrap kill, produces output to  abrt-cli list
### files allowing or denying access to users (must edit as root)
### /etc/at.allow
### /etc/cron.allow
### /etc/at.deny
### /etc/cron.deny
 1148 vi /etc/cron.d/cron.deny  # deny cron access to certain users, add usernames one line at a time
 1149 vi /etc/cron.d/cron.allow  # deny cron access to certain users, add usernames one line at a time
# cron time-dependent, if system is off jobs can be missed, highest possible frequency is once a minute, can be run many times a day
# anacron time-independent, jobs missed run on restart, can set a delay time certain number of minutes after startup to check if job has been run or not, highest frequency is daily
 1150 vi /etc/anacrontab  (example output)  1 15 daily.backup /usr/sbin/backup.sh  #4 fields; period in days or macro, delay: minutes after startup for job to run, job identifier used to name timestamp file in /var/spool/anacron indicating when job was last run, and job command
 1151 at 11 am june 26   # one off-command would run job at 11am on june 26th, will run when load average < 0.8 - man at
       at> mkdir ~/Document.bak    # at> interactive prompt opens up allowing commands to be entered
       at> rsync -a ~/Documents/ ~/Documents.bak     #rsync backs up the Documents folder
       at> Ctrl+D   # ends the prompts session, will return <EOT>
#different at formats
 1152 atq    # lists current jobs, with job id (starting at 1) - which atq
 1152i at -c 1   # shows contents of the job including shell environment  
 1153 atrm job-number  # will remove jobs from at queue
 1154 service atd status  # returns status of atd.service, which atd
 1156 batch    #opens another interactive prompt this time any added jobs execute as soon as the system is not busy = load average < 0.8
       at> Ctrl+D   #returning <EOT>
# if /etc/at.deny||cron.deny and no .allow file then all users allowed to schedule jobs except those in deny file
 1157 date +%x  # displays year date in local format
 1158 locale   # returns all config settings in locale
 1159 LC_TIME=en_US.utf8   #can set locale variable/config option at the command line, runnig subsequent date +%x comman presents the date in the US format
 1160 cat /etc/locale.conf  #returns LANG variable, can set all other variables through LANG variable at the command line
 1161 locale -a   # list of available locales | grep GB shows available character sets for locale
#for example default is utf-8, but puTTy client uses ISO8859... so the output of command like pstree returns a very strange output, can change via client or via locale if the issue occurs
 1162 pstree   # return a process tree showing child/parent process/process hierarchy structure
 1163 timedatectl  # returns all time/date/timezone information
 1164 timedatectl set-time 2012-07-26  #sets time info based on input, does not return information 
 1165 localectl  #returns locale and some system i.e. X11 information
 1166 ss -lt   #ss=show socket , -l shows listening ports -t shows tcp ports
 1167 man ss  #manual page for ss
 1168 grep string $filename  # will search within the file for matching regex
 1169 declare   # declares all variables, declare -f declares functions, declare -F shows only function names/potential arguments to declare -f
 1170 declare -F | grep '^[a-z_]'  # begins with lower case characte or underscore, shows system functions
 1171 sed --version   # -- versiion can be used with utilities such as sed, man and many others to return the version information
 1172 awk ' { print } ' audiotestcopy.sh    # simple awc command to output contents of file to the screen
 1173 awk ' BEGIN { print "audiotestcopy.sh" } { print } END { print NR } ' audiotestcopy.sh   #BEGIN and END blocks, print string "audiotestcopy.sh", then output of file then NR=number of rows/lines
 1174 awk ' BEGIN { print "audiotestcopy.sh" } { print NR, $0 } END { print NR } ' audiotestcopy.sh   # prints NR row/line number and $0 being the input i.e. the row/line itself 
 1175 ifconfig eno1 | awk -F":" '/ether/{print $0 }'    # will print entire line containing /$string/ ala grep   - equiv of ifconfig eno1 | grep ether
 1176 ifconfig eno1 | awk -F":" '/ether/{print $3 $4 $5 }'    # will print 3rd, 4th and 5th element using ":" as a field seperator   - equiv of ifconfig eno1 | grep ether | cut -f3,5 -d":" 
 1177 ifconfig eno1 | awk -F":" '/txqueue/{print toupper($3 $4 $5 )}'    # converts characters to upper case before printing
 1178 ifconfig   # displays onnection information along with number of packets sent/received RX: received, TX: transmitted
 1179 grep pam_nologin /etc/pam.d/*  # can search multiple files by using *, in this case modules that include the option pam_nologin, in the pluggable authentication modules
 1180 grep -c name /proc/cpuinfo  # will return number of instances in file, in this case in cpuinfo, the number of cores
 1181 ls /proc   # system information
 1182  parsecsv.sh products.csv | grep -A2 Bench   # returns the next two lines after the line containing search term
 1183 while read product price quantity  # will read input to three variables product, price, quantity, using whatever is defined as the internal field separator $IFS
 1184 echo -e "\e[1;33m$product ===================\e[0m\n\   #colours the product field yellow \e[1;33m before changing back to black \e[0m
 1185 \b[Cc]olou?r\b  #  \b are word boundaries, matches Colour/colour/Color/color  
 1186 grep ^server /etc/ntp.conf  # returns ntp servers in config file1188
 1187 grep '4$' /etc/logrotate.d/*  # returns files with string 'logrotate 4' which specifies that keep 4 backups when a log is rotated
# [A-Za-z] - any letter, [0-9] - any digit; [a-z_] any lower case or underscore; [349], matches 3, 4 or 9; \s represents white space, \b represents a boundary (characters like - , . as well as spaces)
 1188 grep 'rotate [^4]$' /etc/logrotate.d/*  # returns all lines from files which have the phrase but don't have a 4 in that position
 1189 grep 'server\s' /etc/ntp.conf  # returns any singular server with white space at the end
 1190 grep 'server\S' /etc/ntp.conf  # returns any servers plural without white space at the end (capital letter reverses the meaning)
 1191 grep 'pop\B' /etc/services  # returns any servers plural without word boundary at the end (capital letter reverses the meaning)
# 'u*' matches u zero or more times, 'u?' matches u zero or once, 'u+' matches one or more occurence of u, 'u{3}' matches exactly three occurrences
 1192 grep -E '[a-z]{2}[0-9]{1,2}' greplines  # -E tag or egrep allows for enhanced regexp 
 1193 sed -n '14p;18p' $file   # prints lines 14 + 18
 1194 sed -n '14,18p' $file   # prints lines 14-18
 1195 sed -n '$p'  $file    #prints first + last line, no ^p, 1p
 1196 sed -n '/^a[0-9]/p' $file   # will print line starting with a followed by number
 1197 sed -n '/^leslie/s,/bin/bash,/bin/zsh,p ' /etc/passwd    # can pass regex as parameter to s, replaces lines with matching term in output to screen
 1198 sed -n '/eslie/s,/bin/bash,/bin/zsh,p ' /etc/passwd    # can pass regex as parameter to s, replaces lines with matching term in output to screen
 1199 sed '/^server 3/ a server ntp.example.com' /etc/ntp.conf   # will append  new line after a line in the configuration file outputexit"
 1200 sed '/^server 3/ i server ntp.example.com' /etc/ntp.conf   # will insert a new line before a line in the configuration file output
 1201 sed '/^server\s[0-9]\.centos/d' /etc/ntp.conf   # will delete lines from a file output \s==space \.==.
      echo "/^server\s[0-9]\.centos/d" >> ntp.sed    # .sed files can be created with sed arguments for use with the sed -f option
 1203 sed -f ntp.sed /etc/ntp.conf   # will call up previous sed arguments for use of ntp.conf file
 1205 ssh -t ltetteh@10.102.0.128 sed -f /home/ltetteh/ntp.sed /etc/ntp.conf  # -t creates sudo terminal, (unnecessary in all instances, used for some screen commands)
 1206 echo hellohellohello | sed 's/h\(e\)\(llo\)/jam\2/2'   # \(e\)=\1, \(llo\)=\2, the 2 at the end specifies which instances of the sed match to replace 
 1206 sed 's@\([^,]*\)@\U\1@' ~/Downloads/employees.csv   # @ used for sed separator, \([^,]*\)=\1, every until a comma is a variable, \U=uppercase, 
 1207 sed 's@\([^,]*\),\([^,]*\)@\1,\U\2@' ~/Downloads/employees.csv   # uppercases the second name, fed in as a second field using the sed match criteria
 1208 sed 's@\([^,]*\),\([^,]*\)@\1,\U\2@2' ~/Downloads/employees.csv   # finds second case of matched criteria, in this case 3rd and 4th fields of a csv will be \1 and \2
 1209 sed 's@\([^,]*\),\([^,]*\)@\U\1,\L\2@' ~/Downloads/employees.csv    # first variable will be upper case second variable will be lower case
 1210 sed 's@\([^,]*\),\([^,]*\)@\U\1,\l\2@' ~/Downloads/employees.csv    # first variable will be upper case, first letter ofgdbsecond variable will be lower case
 1211 sed "s/\(^\|[^0-9.]\)\([0-9]\+\)\([0-9]\{3\}\)/\1\2,\3/g" ${file}    # adds a comma before the last
 1213 sed "s/^/ls -l /e" file.list   # e after sed command executes  the command so will return the long listing of the files specified in the file.list file, == ls -l $(cat file.list)
 1214 sed "s/^/stat /e" file.list # == stat $(cat file.list)
 1215 sed "s/^/sudo useradd /e" user.list  # will add potential usernames in user.list file
 1216 sed "s/^/sudo userdel -r /e" user.list  # will delete username, -r tag allowing to check for spool and home directory
 1217 cat /proc/asound/cards   # returns the sound cards currently on the device
 1218 lsmod   #shows the status of modules in the linux kernel
 1219 lsmod | grep snd   # returns the sound modules 
 1220 grep -rn SND_PCM_FORMAT_DSD /usr/include/alsa    # https://www.alsa-project.org/alsa-doc/alsa-lib/pcm.html
 # in recipe files i.e. gateway.ing or pjproject_2.8.bb :  INHIBIT_PACKAGE_STRIP= "1", INHIBIT_PPACKAGE_DEBUG_SPLIT 
 1228 gdb -p `pidof radioGateway`    # ` = backtick, not an apostrophe ', backtock means evaluate expression, return result
#building and transfering roip image
#bash commands
 1232 sed "s/^/ls -l /e " ~/file.list    #executes lines of file as read, in this case with the substitution ls -l
 1233 sed "s/^/stat /e " ~/file.list    #executes lines of file as read, in this case with the substitution stat
# any command that can be run from the command line can be accesed with the sed /e option such as useradd, userdel 
 1234 sed "/^f/s/^/tar -rf catalog.tar /e " cat.list   #selects filenames beginning with f and adds them to catalog.tar
https://www.pjsip.org/pjlib/docs/html/errno_8h.htm   #list of some possible return values for pj_status_t
 1238 awk -F":" -f users0.awk /etc/passwd     #cat users0.awk {print $1} -F specifies delimiter
 1239 awk -f users0.awk /etc/passwd     #cat users0.awk {print $1}  delimiter is default
 1243 lastlog -u root   # man lastlog
            # Other directives here
          # Other directives here
          # Other directives here
          # Other directives here
 1250 sed ' /^\s*$/d ' virtualhost.conf   # deletes blank lines from output
 1251 sed ' /^\s*$/d;/^<\/Virt/a\ ' vh.conf   # appends new line after closing tag
1260a cd /etc/vocality/config    # config files
        #!/bin/bash
1266 ln -sf /sbin/iwconfig ${D}/home/vocadmin/bin/iwconfig  # creates symbolic llink
#if VOCALITY_CO_TYPE = "branch"
#VOCALITY_BRANCH ?= "trunk"
1267 echo $DISPLAY   #:15.0
#run all grunt commands from ui/node
1276 awk ' { print $9 } ' access.log  # will print the 9th column field i.e. access code
1277 awk ' $9 == 404 { print $0 } ' access.log  # will print the whole line where 9th field is equal to status code
          }           #array named ip is creaated which stores a key for each ip address, value of the key is incremented each time the ip address is found
                      #example ip[192.168.0.1]3
1289 sudo iptables -L | less   # list all rules in a selected
1291 yum search openssh-server   #install ssh allows remote client-server connection
1291 vi /etc/ssh/sshd_config   #configuration for ssh server (d stands for daemon as constantly ssh server software constantly runs in background)
                               #in order to make changes to default parameters, uncomment line
          PermitRootLogin no   #standard practice to not allow logins as root and elevate accessonce connected with authorised user
          PubkeyAuthentication yes   #allows logins with a public key as opposed to a password (usually .ssh/authorized_keys) 
          UsePAM yes           #allows use of pluggable authentication modules (to deal with logins LDAP)
          X11 forwarding       #allow dragging of GUI which are on client and run on server 
          PrintMotd no         #Display message of the day
1293 ps aux | grep sshd        #finds ssh daemon
1294 vi /etc/ssh/ssh_config    #configuration for ssh client
1295 ssh-keygen                #generates a key pair, will install in ~/.ssh/name  ~/.ssh/name.pub (public)  
1296 cat .ssh/name.pub         # will allow public key to be copied and pasted
1298 vi .ssh/authorized_keys/  #paste public key
1300 ssh -Y hostname@target    # allows X11 forwarding so graphical applications can now be run on (if xfce4 installed on local machine)
1301 vi ~/eclipse/cpp-photon/eclipse/eclipse.ini   # config options including setting location for JRE or JDK path. In this case: /usr/lib/jvm/java-1.8.0-openjdk-1.8.0.212.b04-0.el7_6.x86_64-debug/jre/bin
1302 tail /var/log/vocality/nodeUI.log   # on dev machine (for localhost ui logging)
1303 tail /var/log/messages   # on dev machine (for localhost ui logging)
1304 grep -rn "[^_]create_stream" $(grep -rn "pjmedia_aud_dev_factory" | grep -v "svn" | grep -v "Binary" | cut -f1 -d":" | sort | uniq)   # combination of sort and uniq allows for list of unique filenames
1305 hexdump -C train-station.jpg | less     # outputs bit content of binary file in hex (man hexdump)
1306 sudo iptables -n -L -t nat    # allows to look at nat rules in iptables/routing rules (Network address translation tables)
1307 brctl show     # shows all bridges on the system
 1005 set      # show shell variables 
 1006 set -o      #see which variables are enabled
 1007 cd -   # previous directory
 1008 ls ~/Downloads  ->   cd !*   #will run cd ~/Downloads
 1009 cat /etc/shadow  -> sudo !!    # will run sudo cat /etc/shadow
 1010 export HISTCONTROL=ignorespace   #will stop any command preceded with a space from being shown in the history, can be used for privacy from the terminal
 1011 export HISTCONTROL=ignoredups    #will ignore duplicate entries in the history output
 1015 pushd ~/eclipse-workspace/SendDTMF/   #will push directories onto the directory stack
 1016 cd ~1, cd ~0   # will switch between the elements on the directory stack
 1017 popd +1    #removes directories from the directory stack
 1018 echo s{pe,pi}ll   # output = spell spill
 1019 mkfifo named_pipe   #creates a named pipe  
 1020 ls | tee lsout.txt   #send output to file and to screen
 1021 ps -e   # shows every process with no options
 1022 ps -eH   #shows all processes and hierarchy
 1023 ps -eHf   #shows all processes and hierarchy along with parentprocess ID, CPU usage and start time,  -l adds long format
# ps comman also takes -- tags which are GNU tags 
 1024 ps -e --format uid,pid,ppid%cpu,cmd --sort %cpu   #formats the output of the ps command sorts by cpu use least to greatest
 1025 ps -e --format uid,pid,ppid%cpu,cmd --sort -%cpu   #formats the output of the ps command sorts by cpu use  greatest to smallest
 1026 ps -U ltetteh --format %mem   # lists memory usage of all individual processes run by user
 1027 ps -U ltetteh --format %mem | awk '{memory +=$1};END {print memory}'   #uses awk command to compile total process cpu then print the result
 1028 kill -l    #list of kill options
 1029 SIGHUB   # generally causes a process to reread its configuration file
 1030 make | tee out  -> /Failure   #shows first instance of failed test 
 1031 watch ps -C dd --format       # watch executes a command every two seconds unit terminated (ps -C selects by command name)
#### http://www.columbia.edu/kermit/ckututor.html
 1036 truncate -s 0 /var/log/vocality/radioGateway.log    # truncates file allowing for new logging to start 
 1037 pgrep rsyslog   # returns proxessid of iprocess specified
#########Configuring Secure SIP on Asterisk PBX.
   1040 ast_tls_cert -C 10.102.0.162 -O "   # code available on online repository
   1042 chmod -R 775 /dir/    # -R flag adds recursive option
 1102 svn co svn+ssh://vptbld@10.102.0.221/mnt/share/VOS_svn/VPT/trunk VPTtrunk   # will prompt for password, but allows access to online SVN repository
 1103 sed -i "s/[ ]\+$//g; s/^[ ]\+$//g" $file  #removes all blank spaces atthe end or on empty lines
 1107 cat serial_profiles/usb0       # set modem none; set line /dev/ttyUSB0; set baud 115200; set parity none; set flow-control none; set carrier-watch off; set key \128 \8; set key \8 \127; log session usb0_kermit.log; connect
 1108 service nodeManager stop|start|restart    # on Centos machines use this command instead of running nodeManagaer bina
######### login shell process -> /etc/profile -> /etc/profile.d/*.sh ->   ~/.bash_profile    -> ~    ~/.bashrc    ->     /etc/bashrc    ->    ~/.bashrc
 # [:digit:] [:upper:] [:lower:] [:alpha:] [:alnum:] [:space:] [:graph:] [:print:]  [:punct:]   [:cntrl:]     [:xdigit:]    #character classes
 # file[0-9].txt == file[[:digit:]].txt     # file[![:digit:][:spaces:]].txt    # have to place character classes within a set c
 # if using globs, use a + inside brackes to ensure matching one occurence of the pattern
 # file?.txt = file[a-z, etc.].txt # will match any character but only a single occurence
 # for hyphen matching must put - at start of regex expression i.e. [-A-Z]
 # [!0-9]    # will negate a match and will find all characters apart from 0-9
 # if {*.jpg,*.gif,*.png}  # curly braces needed for multiple matchees  
 # shopt -s extglob   # bash allows extended globs as an option, the -s flag allows it to be set (for the session, enable persistence in bashrc)
 # file?(abc).txt     # will match 0 or 1 occurence of the match i.e. will return file.txt and fileabc.txt
 # file+(abc).txt     # will match 1 or more occurence of a match i.e. will return fileabc.txt and fileabcabc.txt 
 # file+(*.jpg|*.gif)     # will match 1 or the other pattern 
 # (+(photo|file)*+(.jpg|.gif))     # will match files beginning with photo/file and ending in jpg/gif
 #  
#system sevices are started by the OS at boot, called daemons, current standard is systemd for CentOS 7, stemd uses systemctl for management of processes
#systemd also manages other objects i.e. devices, system timers, targets (systemd equiv of run l{{evels), systemd objects are callled units and each has a unit file for configuration
 1032 systemctl list-unit-files  # shows all unit files
 1033 systemctl list-unit-files -t service  # -t service shows all enabled service unit files (configured for automatic start up, static - not enabled, nor provisioned to be enabled)
 1034 systemctl list-unit-files -at service # -a shows both enabled and disabled service unit files
 1035 systemctl list-units   # by default shows enabled running units
 1036 systemctl list-units -a  # will show all units
 1037 systemctl list-units -at service  # shows all services
 1038 systemctl list-units -t service   # shows all enabled/running services 
 1039 systemctl list-units -t service --state running   #show all running services
 1040 systemctl cat rsyslog      # will provide unit-file information providing an idea of services operation
 1041 systemctl status atd   # will provide status of rsyslog 
 1042 sudo systemctl stop atd    # service stop command
 1043 sudo systemctl start atd   # service start command
 1044 sudo systemctl restart atd # service restart command
 1045 systemctl is-active atd    # service is active return
 1046 sudo systemctl mask atd    # "masks" service, makes service address a symlink to /dev/null, prevents service from being started(manually or automatically) but not stopped
 1047 sudo systemctl unmask atd  # "unmasks" service, removes symlink 
 1048 sudo systemctl disable atd # will disable service, removes symlink from systemctl targets, does not render service inactive straight away su -
 1049 systemctl is-enabled atd   # return staus of service (enabled/disabled/static) 
 1050 systemctl status atd       # returns status of process and logging information
 1051 echo 1 > /proc/sys/kernel/core_uses_pid     # http://man7.org/linux/man-pages/man5/core.5.html 
 1052 echo "/home/ltetteh/core-%e-%s-%u-%g-%p-%t" > /proc/sys/kernel/core_pattern     # http://man7.org/linux/man-pages/man5/core.5.html 
 1054 sudo yum groupinstall "Development Tools"   # includes C compiler and source code, which allows to compile kernel drivers
 1055 sudo yum update -y   #update local packages
 1064 svn diff -r 13460:13608 source/Radio/Gateway/SipAccount.cpp    #will display diff between specific files on svn revision numbers
 1066 ls --help # --help option afterwards will show usage with possible options
 1067 apropos "list" #will return a list of commands, and their descriptions for text you provide as an argument, if they contain the word passed in as an argument 
 1068 file file.txt  # will return the type of file OPUS123
      # virtual filesystems #
 1074 #less shortcuts - space -page down, f/b for forwards/backwards 
 1075 grep -E "\w{6,}" filename   # will return all words with a length longer than 6 letters
 1076 vi .bash_profile #stores PATH variable and other user specific environment and startup programs
 1077 ls -lah /etc/*release    # files listed will contain current distro information
 1078 cat /etc/os-release    # on this filesystem example contains distro information
 1079 uname -a    # shows type of system, host name, version of kernel, and when it was built
 1080 df -h   # df lists file system disk space usage, -h human readable  
 1081 sudo du / -hd1  # estimate file space usage -h human readable -d1 depth=1
 1083 sudo lshw | less   # list hardware information about current machine
 1084 # output from ls -l, first character #
      # drwxr-xr-x  - d = directory 
      # lrwxr-xr-x  - l = symbolic link 
      # crwxr-xr-x  - c = character device file -inputs or outputs characters /dev/random outputs random characters
      # brwxr-xr-x  - b = block device file 
      # srw-rw-rw-  - s = socket file 
      # prw-------  - p = named pipe file aka FIFO (first in first out)
      # -rwxr-xr-x  - - = normal file
      # ls /proc/    #contains virtual files with 0 bytes, data can be read but have a file size of 0 bytes, these are attributes and information
      # Third column is user owner, Fourth column is group owner, e.g. chown ltetteh:root somefile.txt ltetteh=user owner, root=group owner
 1085 # Three major types of extended attributes: Extended security attributes, Extended system attributes, Extended user attributes
 1086 ls -Z /etc/passwd  # show SELinux security attributes in fifth column 
#ACLS are turned on by default in CentOS (in OS part of file partition system)
      ls -l   # will return -rw-rwxr--+ , + symbol after permissions showss it has some extended file attributes (ACL file)
 1088 getfacl -t aclfile.txt   # returns standard linux permissions and ownership -t option to return in tabular form (without flag -t for normal return)
      # Extended system attributes store access control lists, these provide an additional layer of discretionary permissions, 
      # allow administrators to set permissions for multiple users/groups on a file, and also to inheritance user/group permissions
      # Extended user attributes 
           # Append only   # Auto compress files   # Make files immutable   # Auto backup on single files
 1088b getfacl -R /../${dir} > file-attrs.txt    # will return all file attributes (including extended) for files in folder -R for recursive
 1089 touch afile.txt -> sudo chattr +i afile.txt     # sets an immutable flag
 1090 lsattr afiile.txt   # retrieves extended attributes, outputs to console
 1091 shopt   # Toggle the values of variables controlling optional shell behavior.  With no options, or with the -p option, a list of all settable options is displayed
 1092 ln file.txt filelink.txt  # second file will be created as a hard link to the first file, for all intents and purposes they are the same file
           ls -lrt | filelink.txt   # as in the case of the original file will return an inode number of 2, (column after permissions) the number of 
           stat filelink.txt        # will return the same info as stat file.txt, the number 
                                    # hard links cannot link to directories, cannot link across filesystems (different partitions), and can be hard to identify 
                                    # however they take up virtually no space, don't break when the target is deleted, opposite of all above conditions for symlink
 # possible to alias cp/rm/mv to "cp -i", "rm -i", "mv -i" via .bashrc file
 # moving a file on the same filesystem only updates the nodes listing the path to the file so it's very fast
 # touch command purpose is to update timestamps on files, however will cerate a file if there is not one
 1093 umask 0022   # last three digits of umask are subtracted from the maximum pemission level given to a newly created file or directory, this is 777 for a directory and 666 for a file
                   # thus a directory created in this case would have initial permissions, 775, and a file would be 644. can be added to bashrc file                     
 1094 sudo vi /etc/profile.d/umask.sh   # would create a script which could be used to define different umask levelel for root and regular users
          if [ "$UID" -ge 1000 ] ; then umask 022; fi    #will apply the umaask to users with id >=1000
 1095 ls -l /usr/bin/su     # will return a filename highlighted red and in the user execute position there is a special symbol s, this means that the SUID bit is set, if it is lowercase
                            # then execute is also set, if S is uppercase then execute permissions are also set. when SUID bit is set and regular users execute it, their privileges get escalated
                            # to that of the userowner, which in the case of /usr/bin/su is root
 1096 chmod 4755            # extra column at front refers to SUID permission; SUID = 4 : u+s, SGID = 2 : g+s, Sticky = 1 : o+s -> total = 7 : ugo+s
 1097 ls -l /usr/bin/screen # will return the SGID set, and the file is blocked yellow
 1098 chmod u+s           # sets SUID bit as per normal, when group SUID bit is set escalates privileges on use to group owner privileges, SGID and Sticky are special bits for Directories
 1099 chmod 1777 /home/stickydir          # although other users may have rwx permissions on the files in the directory, the sticky bit will prevent from moving, copying and deleting files
      sudo mkdir accounting               #creates new directory called accounting
      sudo groupadd accounting            #creates group accounting
      sudo chown :accounting accounting   #sets groupowner of directory as accounting
      sudo chmod 2770 accounting -> ls-l  #sets SGID bit (with execute permissions), lower case tells that accounting group has execute permissions. The SGID bit represents the only inheritance
                             \+            #in standard Linux permissions and ownership, all files and directories created within the directory will inherit the groupowner
      sudo useradd -G accounting bob      #will add a user called bob and place it in the accounting group
      sudo passwd bob                     #sets password for new user bob
### cat /etc/passwd to see users, cat /etc/groups to see groups
      cd /accounting -> touch file.txt    #will inherit groupowner as accounting
 1101 sudo setfacl -m user:bob,rwx,group:accounting:rx file.txt || sudo setfacl u:bob:rwx,g:accounting:rw file.txt  # comma is used to separate arguments, will set both user and group using ACLs
         getfacl -t file.txt    # will return 
		# file: file.txt
 1102 sudo setfacl -R -m u:bob:rwx ~/aclexercise   #will set ACLs recursively in the folder specified, setting an ACl for each file in dir
 1103 sudo setfacl -d -m u:bob:rwx #/aclexercise/dir1  # creates a default ACL ensures any new file or directory created in this folder will inherit the ACL
           cd dir1 -> touch newaclfile.txt -> ls -lrt # will return 
	   getfacl newaclfile.txt #will return
		# file: newaclfile.txt
		# owner: ltetteh
		# group: opus
		user:bob:rwx			#effective:rw-
		group::r-x			#effective:r--
           getfacl -t newaclfile.txt # will return 
		# file: newaclfile.txt
	getfacl acldeldir # will return
		# file: acldeldir
		# owner: ltetteh
		# group: opus
		# file: acldeldir
# setfacl, -x remove specific acl, -k remove all default acls, -b "blank" remove all acls
 1105 setfacl -x user:root acldeldir || setfacl -x root acldeldir    # both previous commands do the same thing, if only a name is given setfacl interprets it as the user) 
 1106 setfacl -x default:user:root acldeldir   # will remove a specific default acl, default is specified here in option
 1107 setfacl -x group:root acldeldir   # will remove a group acl
 1108 setfacl -k acldeldir   # will remove all default acls 
 1109 setfacl -b -R acldeldir   # will remove all acls, -R option for recursive   
 1110 touch dir1/file{1,2}.txt  #will create two files dir1/file1.txt and dir1/file2.txt
 1111 getfacl file1.txt | setfacl --set-file=- file2.txt   #reads acl of file1.txt pipes it to setfacl and uses it to set fill attributes on file2.txt
 1112 getfacl -c file1.txt > acls.txt   # -c option used to save acl data to file, omits header so command only returns acl data.
 1113 setfacl -M acls.txt file2.txt    # can use -M option with save acl data to set acl on other files
 1114 getfacl -R dir1 > dir1tree.facl   # will store filetree atrributes
 1115 setfacl --restore dir1tree.facl   # can be used to restore all acls to files in a directory
 1116 getfacl dir1 | setfacl -d -M- dir1   # if acl is set and we would likeit to be inherited can be set to default through piped command (-M- is necessary)
 1117 setfacl -m mask::- dir1   # sets a mask (mask is the maximum permissions allowed) this will set an empty mask
## yum uses rpm to install packages on red hat-like distributions, resolves dependencies automatically, has concept of software package groups, contain rpm software packages, client maintains local list of repositories & maintains local list of all available software
#yum client basic function is to contact a list of repositories, get a list of software packages from those repositories, then cache these locally and update during install operations, yum calculates dependencies (i.e. any software packages required by selected software package))
# yum groups contain multiple software packages, all software in group can be installed at once, all software removed at once, contain optional software
 1118 sudo yum -y remove package-name   # will remove an installed package and associated files, but won't remove installed dependencies and configuration files(s)
 1119 sudo yum autoremove package-name   # will remove a package and its dependencies (recommended not to use -y option, could try to remove entire OS)
 1120 package-cleanup --leaves   # will return a list of packages no longer needed (require yum-utils to be installed)
 1121 yum group list    # will list all yum groups, yum has package groups: pre-configured group of packages that can be added or removed at any time
 1122 yum group list ids   # will list all yum groups followed by the group ID in parentheses (more useful for command line, doesn't require double quotes - shown below)
 1123 sudo yum group install "Security Tools" || yum group install security-tools || yum install @"Security Tools" || yum install @security-tools   # all return the same yum group install command, '@' prefix denotes a group
 1124 sudo yum autoremove @security-tools   # use of @ prefix will remove security tools and the associated dependencies (there is no "group autoremove" ) 
 1126 sudo yum group install system-admin-tools  # will return message saying does not have any packages to install
 1127 yum group info system-admin-tools   # lists information on group, if installed 
# prefixes: -, package was not installed and won't be installed as part of the group
# may list some optional packages (which are not installed by default on CentOS). To install mandatory, default and optional packages need to make a change to configuration in /etc/yum.conf file, else:
 1128 sudo yum group install system-admin-tools --setopt=group_package_types=mandatory,default,optional   # --setopt command will allow yum to now download optional packages, packages can be managed via groups option if installed via groups command, otherwise "yum groups mark" command 
 1129 yum --showduplicates list samba-test-libs  # yum list shows all packages --showduplicates to show multple versions
 1130 yum list installed    ## will return as middle column epoch:name-version-release.arch i.e. 2:svn15878.1.4-43.el7, packages highlighted in red do not exist in yum repositories, bold means there's an update in the repository, bold and underlined means it is the currently installed kernel, if name is yellow means it is newer than that available in the repositories 
 1131 yum list updates   # shows all the updates available for installed packages 
 1132 yum list available    # shows all software packages available that haven't been installed, blue means upgrade to installed package, cyan means downgrade to installed package, green and underlined means current version of installed package and is only returned if --showduplicates option is passed (CentOS 7)
 1133 yum list | yum list all  #returns all packages 
 1134 yum list available --showduplicates   # list all packages (including installed and current versions)
 1135 yum info package-name   # shows more information on a specific package (same colour code)
 1136 yum deplist package-name   # use to get a dependencyies list for a package
 1137 yum group list hidden   # show environmental groups/initial installation & configuration groups that are usually hidden by default
 1138 yum group info development   # lists information on group, if installed 2
# prefixes: -, package was not installed and won't be installed as part of the group
# A number of packages under the Development Tools group are not managed as part of that yum group. In order to do so, use following two commands: 
# All default and mandatory packages should now return prefixed with an equals sign, showing they will be managed as part of the group from now on. 
 1140 yum check-update   # used to check for updates to the OS, will return list of packages which can be updated.
 1141 yum update package-name   # when returning the prompt y/d/n the d option allows the package to be updated and installed later
#yum versionlock plugin required to permanently prevent a package from being upgraded
 1142 sudo yum -y install yum-plugin-versionlock   # will enable versionlock to be used
 1143 sudo yum versionlock cups  # will versionlock a package
 1144 yum versionlock   # will return a list of version locked packages 
 1145 sudo yum versionlock delete 1:libuv-1.30.1-1.el7.*    # argument is given in the format returned by the yum versionlock command
 1146 sudo yum versionlock clear    # will clear all versionlocks
 1147 sudo yum update --security   # will only update packages which have security updates in them to the very latest version
 1148 sudo yum update-minimal --security   # will only update packages with security updates in them to latest security patched version
# if configuration file for updated package is not forward compatible, it will be renamed /etc/name.rpmsave
# if it is configurable newly installed config file may be renamed with a .rpmnew extension 
# will return a message during the package update which treads along the lines of "saving /etc/config.conf as /etc/config.rpmsave"
# changelog is useful for knowing what has been changed during a package update, requires installing yum changelog plugin 
 1149 sudo yum -y install yum-plugin-changelog   # 
 1150 yum changelog recent   # will show recently changed packages 
 1151 yum changelog updates   # will show changelogs only for packages to be updated
 1152 yum changelog package-name    # will give the changelog for a specific package
# Install yum extender package for yum package management using GUI
 1153 sudo yum -y install yumex    # requires epel-release
 1154 ls /etc/yum/repos.d/    # list of yum repositories
 1155 sudo yum history list   # returns a list of actions without specifying package names (but with user info)
 1156 sudo yum history info   # returns recently changed packages (updated, deleted, installed) in human readable format
# --downloadonly can be used to download packages without installing them, requires plugin
 1159 sudo yum localinstall /path/to/package   # will then install any packages downloaded locally
 1160 sudo yum reinstall package-name    # will reinstall a new package over the old one
 1161 cat /etc/yum.conf     # comments have been post-added to describe the configuration properties
        keepcache=0                 # means yum won't keep downloaded headers or package files, 1 would keep them, generally not needed after install so set to zero
        logfile=/var/log/yum.log    # yum logfile location, can be handy for troubleshooting yum
        gpgcheck=1                  # set to zero to turn off GPG signature checking on packages, (a setting of 1 is needed)
        plugins=1                   # global setting which allows yum plugins to be used
        distroverpkg=centos-release # name of package which defnes the version of CentOS we are using
 1162 rpm -qi centos-release   # to show which version of centos we are currently using
 1163 cd /etc/yum/.repos.d/  # list of yum repositories, all repo files have to end with .repo suffix 
 1164 cat CentOS-Base.repo   # file contains 4 repositories with repository details, each repository name in square brackets, 3rd line below is a list of mirrors mirrorlist= ,if just using a static url then this line would be baseurl=http://... in this case it is commented out, 5th line is gpgcheck boolean, last line is the location of the gpgkey, to disable repository add another line with enabled=0, centosplus is disabled unless command passed to yum to turn it on temporarily. 
 1165 yum repolist enabled | yum repolist disabled    # returns a list of enabled or disabled repositories
# installing nux-dextop repository: web brower -> li.nux.ro/repos.html
 1166 sudo rpm -Uvh http://li.nux.ro/download/nux/dextop/el7/x86_64/nux-dextop-release-0-5.el7.nux.noarch.rpm   # 
 1167 sudo yum --disablerepo="*" --enablerepo="centosplus" list available   # will temporarily (within command) disable other repos and enable a disable repo "centosplus" to allow new packages to be installed.
 1168 sudo yum --disablerepo="*" --enablerepo="centosplus" install package-name    # will install a package from a temporarily enabled repo file 
 1169 yum install --skip-broken package-name   # will skip broken package files (may be missing dependencies, etc.) and install waht it can
 1170 install --disablerepo=repo package-name   # will temporarily disable a problematic yum repo when installing new software
 1171 yum clean expire-cache|packages|header|metadata|dbcache|rpmdb|plugins|all    # if yum cache gets corrupted or out of sync "yum clean" command allows easy cleannig of old cache
 1172 rpm -qa    # -q option is query and -a for all packages
 1173 rpm -qi bash   # -qi option will show information about a package, returns a field "Group: System Environment/Shells", can pass as a parameter to rpm -qa
 1174 rpm -qa "Group=System Environment/Shells"  # will show packages within the group System EnvironmentShells
 1175 rpm -qa --last   # will show when a package was installed
 1176 rpm -ql yum   # shows location of files installed from the package 
 1177 rpm -qd yum   # show only documentation files
 1178 rpm -qc yum   # show only configuration files
 1179 rpm -qf /bin/bash   # used to query files, will return the package they came from
 1180 rpm -qdf /bin/bash   # -f option can be combined with other options so that the argumen passed in is simply the file itself
 1181 rpm -q --provides bash   # --provides shows what a package provides (in terms of executables)
 1182 rpm -q --requires telnet   # --requires shows what is required for a package 
 1183 rpm -q --changelog bash   # will show all of the changes that have happened to the package
 1184 rpm -qip /tmp/packages/whois-5.1.1-2.el7.x86_64.rpm   # to query a package the -p option is added
 1185 rpm -qlp /tmp/packages/whois-5.1.1-2.el7.x86_64.rpm   # all other commands can be used with e -p option such as -l
 1186 rpm --querytags   # all packages have tags that can be shown or hidden, returns a list of all tags available in terminal
 1187 rpm -qa --queryformat "%{NAME} %{VERSION}\n"    # uses some of the available query tags returned from the --querytags flag
 1188 rpm -qa --queryformat "%-30{NAME} %-10{VERSION}\n"   # number provided after the % sign indicates column width, will both be left aligned
 1189 rpm -qa --queryformat "%-30{NAME} %10{VERSION}\n"   # missing hyphen before column width now means column will be right-aligned   
 1190 rpm -q --queryformat "%{FILENAMES}\n" bash   # will only return the first item in the array
 1191 rpm -q --queryformat "[%{FILENAMES}\n]" bash   # use of [] will now return all items in the array
 1192 rpm -q --queryformat "[%-50{FILENAMES} %{FILESIZES}\n]" bash   # use with multiple tags and formatting
 1193 rpm -q --queryformat "%{NAME} %{INSTALLTIME}\n" bash    # returns install time in epoch time (seconds since 1 Jan 1970)
 1194 rpm -q --queryformat "%{NAME} %{INSTALLTIME:date}\n" bash    # returns in humabn readable date format
 1195 rpm -q --queryformat ".[%{FILEMODES} %{FILENAMES}\n]" bash    # returns file modes in not very human readable format 
 1196 rpm -q --queryformat ".[%{FILEMODES:perms} %{FILENAMES}\n]" bash   # will now return filemodes as readable permissions, similar to ls -l
 1197 man rpm -> /QUERY OPTIONS   # for a list of query options
 1198 sudo rpm -ivh vsqlite++-0.3.13-3.el7.x86_64.rpm   # -i = install, -v = verbose, -h = hashes (progress bar)
 1199 yum list installed   # returns list of installed packages, packages in bold can be upgraded 
 1199a sudo yum install --downloadonly --downloaddir=/tmp/packages php-xml.x86_64   # downloadonly for package marked in bold
 1200 sudo rpm -ivh php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # package downloaded as part of localinstall, will nt install package due to conflicts with existing package  
 1201 sudo rpm -Uvh php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # -U option indicates upgrade as opposed to install, will work generally but fail if package requires dependencies not present
# attempting to upgrade may cause dependency issues, which can lead to a recurring cycle of packages needing upgrades. Best/recommended/correct solution is to uninstall the old package and install new package, otherwise can pass GNU flag --nodeps i.e.
 1202 sudo rpm -Uvh --nodeps php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # will ignore dependencies warnings and upgrade the package without the new dependencies (needs to be run on all dependencies)
 1203 sudo rpm -F php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # -F option for force also will install files and ignore dependencies warnings
 1204 sudo rpm -ivh --force php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # will force reinstall/upgrade of a package and safely overwrites package and installed files
 1205 rpm -qcp php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # -q query, -c configuration files -p package
# rpm2cpio command used to extract configuration files from a package, once it is a cpio archive, can then use cpio command to access files within the archive
 1206 rmp2cpio php-xml-5.4.16-46.1.el7_7.x86_64.rpm | cpio -id    # rpm2cpio command used to extract package files, creates folder(s) within the directory containing package efiles such as configuration files and shared object (.so) files
# SM5DLUGTC c   where S = size, M = file permission mode, 5 = file digest (checksum/md5), D = device major/minor number, L = link path, U = user ownership, G = group ownership, T = last modify time, C = capabilities, c = file type (returned using rpm verify)
# File types - (C)onfiguration file, (D)ocumentation file, (G)host file, (L)icense file, (R)eadme file
 1207 rpm -V yum    # -V = verify. if you verify a package and attributes haven't changed it won't return anything otherwise, will return changed attributes. 
# In the case where the /etc/yum.conf file was altered to add a few lines to the end, returns    S.5....T.  c
# In the case where the lines where then removed from the file it returns    .......T.  c   
 1208 rpm -V wget    # since no files were changed returns nothing
 1209 rpm -Vv wget    # -v for verbose mode, will return all file attributes associated with package whether changed or not, in case where fles have been changed it will show where the specific file has been changed
 1210 sudo rpm -Va     # -V -a will verify the entire OS, and list changed attributes
# A package may be checked for integrity and credibility after it has been copied to the local disk
 1211 rpm -K --nosignature php-xml-5.4.16-46.1.el7_7.x86_64.rpm     # returns "php-xml-5.4.16-46.1.el7_7.x86_64.rpm: sha1 md5 OK" OK verifies that the package is free from corruption (checksum for bit corruption)
# Checking GPG key signature ensures the credibility of the package
 1212 rpm -K php-xml-5.4.16-46.1.el7_7.x86_64.rpm   # returns "php-xml-5.4.16-46.1.el7_7.x86_64.rpm: rsa sha1 (md5) pgp md5 OK" has pgp md5 ok which trumps GPG signature check and checksum
 1213 rpm -q gpg-pubkey   # returns GPG public key(s) on machine 
 1214 rpm -qi gpg-pubkey-f4a80eb5-53a7ff4b    # will return more information on any public keys listed
# if adding a new repository or downloading packages manually from the internet, you will want to import that project's public key
 1215 sudo rpm --import https://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-7    # imports EPEL repository key using rpm
# in browser navigate to epel repository https://dl.fedoraproject.org/pub/epel/7/x86_64/Packages/a/ and download package manually, in this case abc-1.01-9.hg20160905.el7.x86_64.rpm
 1216 rpm -K abc-1.01-9.hg20160905.el7.x86_64.rpm   # check key signature of package 
 1217 rpm -q gpg-pubkey --qf "%{name}-%{version}-%{release} --> %{summary}\n"    # uses name, version, release and summary tags in listing public keys on the machine
# may occassionally get a corrupted rpm database and need to restore it
 1218 sudo tar -czvpf rpmdb.tar.gz /var/lib/rpm   # /var/lib/rpm folder contains rpm database files, creates a backup of rpm database files
 1219 sudo rm rpm/__db*    # will delete deatabase files
 1220 sudo rpm --rebuilddb    # should restore database files, otherwise will have to restore from a backup, otherwise system won't recognize any software as being installed 
 1222 sudo rpm --setperms wget   # should restore permission to package files (may not work)
 1223 sudo rpm --setugids rpm    # restores user/group ownerships 
# ifconfig is currently obsolete as standard network practice. usually now 'iproute' of 'ip' for making temporrary changes to network config  
# Network manager is the other primary tool for interacting with network settings (command line 'nmcli', 'nmtui', 'nm-connection-editor') for making permanent changes 
 1224 ip addr   # returns network devices, and their particular information: mac addresses, ip addresses, netmask, broadcast address, etc. If dynamic is listed then connection set up with DHCP rather than predefined static information, and will have info on how much times is left on the 'lease'.  First listed lo: is a loopback interface 
 1225 ip -4 addr    # will return only ipv4 info
 1226 ip -6 addr    # will return only ip6 info
# enp2s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000  ---- etherenet info returned by ip addr comand show UP,LOWER_UP and state UP variables,'link' keyword can be used to change state of interface to UP or DOWN
## LOWER UP refers to whether the network devisce considers itself able to handle traffic, usually if network device can detect it's connected to a network and can detect a device on the other end, corresponds with state UP or state DOWN within the same line output, if interface is disconnected or cable unplugged 'LOWER UP' will vanish, and 'state UP' will switch to 'state DOWN' i.e.
# enp2s0: <BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000 
 1227 sudo ip link set enp2s0 down    # will set the specified interface to state DOWN effectively unplugging the interface, conversely replacing the word 'down' with 'up' will reset the interface to state UP
 1228 ethtoo enp2s0   # will return interface information for example spported link modes, active speed and duplex of ethernet connection 
# Device names: en0, eth0, eno1 ; original numbering scheme based on order in which network adapters are discovered
# Device names: systemD created new device naming, enp0s3 where en = ethernet || wl = wireless lan; p(0) = PCI bus (zero) || u(num) = usb (num); s(3) = slot (3) 
# Can explore system Buses with lspci or lsusb, writeup on predictable interface names at www.freedesktop.org
 1229 sudo systemctl status NetworkManager   # checks status of NetworManager service, comes by default on newer distros, usually automatically manages each connection by default (unless specified otherwise)
 1230 nmcli device || nmcli -d     # shows if devices are being managed with NetworkManager (will return DEVICE TYPE STATE CONNECTION and under STATE will show connected/disconnected/unmanaged)
# Inside interface configuration file for each device
 1231 ls /etc/system-config/network-scripts/  # On CentOS, Fedora, Redhat, Network manager wil default to managing any interface found within this configuration folder, to change this add the line "NM_CONTROLLED=no" i.e.
 1232 vi /etc/system-config/network-scripts/ifcfg-enp2s0 -> NM_CONTROLLED=no    # adding line will prevent automatic management by NetworkManager
 1233 sudo systemctl restart network    # will restart Network Manager (to effect changes in configuration files, now running the nmcli device command should show configured interface as being unmanaged)
# Unmanaged by default in Ubuntu 
 1234 sudo vi /etc/Networkmanager/networkManager.con -> managed=false -> managed=true   # will change configuration to enable NetworkManager in Ubuntu to manage devices 
 1235 nm-connection-editor   # launches a GUI to handle device/interface management 
 1236 nmcli    # commanfd line interface for running network manager, will return a usage list 
# Device: Network hardware i.e. Wifi adapter, ethernet port, cellular modem, etc.
# Connnection: Collection of settings that can apply to a device (connection profile can have same name as device, is usually named as devicename by default)
 1237 nmcli connection show enp2s0   # returns a list of information for the connection profile given, first section with first column connection.(property) lists specific information about the connection profile
     ## connection.id: - this can be changed 
     ## connection.uuid:  - unique identifier, useful way of referring to a connection
     ## connection.etcs...
#info about the device
     ## 802-3-ethernet.port:
     ## 802-3-ethernet.speed: 
     ## 802-3-ethernet.etcs...
#ipv4/ipv6 information, usually preconfigured by NetworkManager
     ## ipv4.method: 
     ## ipv4.etcs...
     ## ipv6.method:
     ## ipv6.etcs...
 1238 nmcli connection edit enp2s0 || nmcli -c -e enp2s0   # configure a connection profile, brings up an interactive command line interface, can use '?' or 'help' for available commands 
          nmcli> print connection     # will return all connection.(property) paramteters
          nmcli> describe connection.id    # will return information about connection parameters
          nmcli> set connection.id MyEthernet   # will set the connection id (& other configurable parameters)
          nmcli> save     # will save any configuration changes, will prompt yes/no
          nmcli> quit    # to exit the cli
 1239 nmcli c   # will list connections by NAME(ID)   UUID   TYPE   DEVICE
### To configure a dynamic address using DHCP using Network Manager gui - choose connection profile -> Edit -> IPv4 Settings -> Method: Automatic (DHCP)
 1240 nmcli con show MyEthernet    # after configuring settings, will return properties/configuration such as DNS information and other configuration settings con||-c||connection interchangeable
### To configure a dynamic address using DHCP using Network Manager cli
 1241 nmcli connection edit MyEthernet || nmcli -c -e MyEthernet   # configure a connection profile, brings up an interactive command line interface, can use '?' or 'help' for available commands 
          nmcli> print ipv4     # will return all ipv4.method: auto, following gui interaction
          nmcli> set ipv4.method auto   # same as GUI command above
 1243 nmcli con up MyEthernet   # previous two commands will refresh Network Manager connection (if autoconnect is not set)
 1244 nmcli con add con-name OtherNet ifname enp0s3 type ethernet    # can add new connections from command line, defaults ipv4 mode as automatic 
### Configuring a static Ethernet Client via Network Manager GUI  - choose connection profile -> Edit -> IPv4 Settings -> Method: Manual 
### Configuring a static Ethernet Client via Network Manager CLI
          nmcli> set ipv4.address 10.0.2.8/24   # will prompt for ipv4 method to be set to manual (yes)
 1247 nmcli con up MyEthernet   # previous two commands will refresh Network Manager connection (if autoconnect is not set)
### Configuring a static Ethernet Client via command line
 1248 nmcli con mod MyEthernet ipv4.address 10.0.2.8/24 ipv4.gateway 10.0.2.1 ipv4.dns 10.0.2.1   # same effect as 1245   
### Configuring a wifi client via Network Manager GUI -> add -> choose connection type (Wifi) -> 
 1249 nmcli d wifi list   # will return a list of available wifi networks, find network name to open a connection to
 1250 nmcli con add con-name MyWifi ifname wlp3s0 type wifi ssid 'My Network'   # where wlp3s0 is the device name, 'My Network' is the name returned from command 1249, MyWifi is the new connection profile name, and 'wifi is the type; 'con-name', 'ifname', 'type' and 'ssid' are all keywords
 1251 nmcli con mod MyWifi wifi-sec.key-mgmt wpa-psk wifi-sec.psk 'Password!'        # wifi-sec.key-mgmt wpa-psk sets key management to WPA pre-shared key, and allows key to be entered 
##### Configuring Networking manually on Ubuntu and Debian ######
 1252 cat /etc/network/interfaces   # interfaces used by Ubuntu and debian distributions
### Configuring a dynamic address using dhcp
        -> auto enp0s3 || allow-hotplug enp0s3    # allow-hotplug roughly interchangeable with auto in this case, means bring up connection automatically  
        -> iface enp0s3 inet dhcp                 # tells enp0s3 interface to use dhcp with ipv4 (inet==ipv4) (should be only one iface line per device)
 1254 sudo ifup enp0s3    # will bring up connection, should then be configured with DHCP settings
### Configuring a static client
 1255 sudo ifdown enp0s3   # brings connection down for modifying
        -> allow-hotplug enp0s3                   # allow-hotplug roughly interchangeable with auto in this case, means bring up connection automatically 
        -> iface enp0s3 inet static               # tells enp0s3 interface to use dhcp with ipv4 (inet==ipv4) (should be only one iface line per device)
### Configure Wi-fi
        -> allow-hotplug wlp3s0                   # allow-hotplug roughly interchangeable with auto in this case, means bring up connection automatically 
        -> wpa-psk "Password!"                    # can use a hexadecimal character representation (doesn't require double quotes)
##### Configuring Networking manually on CentOS and Redhat ###### 
        -> BOOTPROTO=dhcp                                 # Configuration protocol to be used at boot could be set to dhcp||none||BOOTP
         # HWADDR=08:00:27:90:3f:5e                       # Setting HWADDR here ensures that interface connects to the right device, doesn't change mac address of the interface
         # MACADDR=00:00:00:00:00:00                      # Changing MAC address here will change the MAC address of the interface
        -> DEFROUTE=yes                                   # yes means that the device provides the default route       
        -> NAME=enp2s0                                   # Interface(connection) name, by default same name as the device, can be changed (as above)
        -> UUID=9f1387a2-df1c-49c6-bc93-64ee00b948f1     # universal unique identifier for the connection (can have more than one connection per device)
        -> DEVICE=enp2s0                                 # Shows which device interface is using
        -> ONBOOT=yes                                    # yes = Configuration will be read at boot and system will try to bring it online
      # Interface is set to dynamic right now, would show IP address, DNS, gateway, etcs. if not  
### Configuring a dynamic address -> Add BOOTPROTO=dhcp, remove any IPADDR, DNS, etc lines from the file   
### Configuring a static address
        >> BOOTPROTO=none                                 # Setting for a statically configured client 
         # HWADDR=08:00:27:90:3f:5e                       
         # MACADDR=00:00:00:00:00:00                      
        >> IPADDR=10.0.2.29                              # Sets ipv4 address
        >> PREFIX=24                                     # sets netmask (can also be 255.255.255.0)
        >> GATEWAY=10.0.2.1                              # Sets default gateway
        >> DNS1=10.0.2.1                                 # Sets DNS server
### Setting system hostname
 1262 sudo nmcli general hostname server-1   # Will rename the hostname of the system as server-1
 1263 nmcli general hostname    # Will return the system hostname 
 1264 hostnamectl    # will return system hostname 
 1265 hostnamectl set-hostname localhost.localdomain   # will set system hostname (Static hostname)
### Firewall configuration with iptables, manages access through a series of rules called chains, INPUT/OUTPUT to define what happens to packets entering/leaving, FORWARD if configured as a router, rules of the chain are interpreted from top to bottom, first to last for every packet coming in through the firewall   
 1266 sudo iptables -L   # show all iptables rules
 1267 sudo iptables-save > rules-backup   # saves current set of iptables chains/rules
#  use netcat to start listening on specified port
 1268a nc -l 4545             # set up on new instance of terminal
 1268b nc 10.102.0.128 4545   # set up on second instance of terminal (ip addr of current machine)
# Can now set up iptables rule to block traffic on port 4545
 1269 sudo iptables -A INPUT -p tcp --dport 4545 -j REJECT   # -A append a rule, -p protocol (tcp for packets), --dport specifies destination port, -j = jump can be followed by DROP (drop packets into firewall, still allow connections) or REJECT (reject completely any connections)
 1270 nc 10.102.0.128 4545   # now returns Ncat: Connection refused
 1271 sudo iptables -A INPUT -p tcp --dport 4545 -j ACCEPT    # will have no effect as packets hit the previous rule first
 1272 sudo iptables -F   # flushes newly all appended rules and restores original state of iptables chains
 1273 sudo iptables-restore rules-backup   # restores the previous rules which were saved
### Firewall configuration with firewalld
 1274a nc -l 5454             # set up on new instance of terminal
 1274b nc 10.102.0.128 5454   # set up on second instance of terminal (ip addr of current machine) (should not work by default)
 1275 sudo firewall-cmd --    # pressing tab will return a list of options (same with iptables and generally other binaries that take gnu flags)
 1276 sudo firewall-cmd --zone=public --add-port=5454/tcp --permanent   # --permanent flag allows rule to persist throough a reboot or any changes made are temporary, adds access to port 5454
 1277 sudo firewall-cmd --reload   # reloads firewalld with new rules
 1278 sudo firewall-cmd --zone=public --remove-port=5454/tcp --permanent   # removes port 5454 from firewalld rules
### Monitor network port activity (sockets)
# Socket is defined as a connection that has and address and a port on each end, along with a particular protocol to describe how the data flows between the end points 
 1280 man ss   # ss replaces older  netstat command (see earlier)
 1281 ss    # returns mostly system sockets
 1282 ss -t   # will just look at tcp sockets 
 1283 ss -lt    # returns tcp sockets currently listening (with establishied connections)
 1283s nc -l 4545   # in new terminal window
 1284 ss -lt   # will default associate service which uses port to the port specified. In this case 4545 is a service called worldscores
 1285 ss -tln   # will now return port numbers instead of services   (same -tulpn flags as netstat)
 1286 sudo firewall-cmd --zone=public --add-port=4545/tcp --permanent    #  
 1288 nc 10.102.0.128 4545   # on new terminal
 1289 ss -tn   # shows an established connection on port 4545
 1290 ss -tna   # a flag shows both listening and receiving sockets
 1291 ss -pant   # -p flag shows process (and pid)
### Routing lab overview
## Setup: Set static addresses on each interface; Create static route from 10.0.2.7 to 192.168.0.0/24; Create static route from 192.168.0.7 to 10.0.2.0/24; Configure firewall on the router for forwarding (NAT); 
### Machine to be used as the router
 1292 ip -4 a    # should return some interfaces enp0s3 and enp0s8
 1293 nmcli c   # will return connection list
 1294 nmcli con del enp0s3    # unused connection profile for device enp0s3
 1295 nmcli con mod MyEthernet connection.id 10-net ipv4.method manual ipv4.addresses 10.0.2.6/24 ipv4.dns 10.0.2.1 ipv4.gateway 10.0.2.1   # rename/set up connection for device enp0s3
 1296 nmcli con mod Wired\ connection\ 1 connection.id 192-net ipv4.method manual ipv4.addresses 192.168.0.6/24 ipv4.dns 192.168.0.1 ipv4.gateway 192.168.0.1   # rename/set up connection for device enp0s8
 1297 sudo hostnamectl set-hostname router   # sets hostname as router
 1301 sudo nmcli con up 192-net  # refresh connections
 1302 ip -4 a   # should show new configurations
### Machine to be used as the 10-client
 1303 nmcli c    # should return same connection names (MyEthernet, etcs.)
 1304 nmcli con mod MyEthernet connection.id MyEtherenet ipv4.method manual ipv4.addresses 10.0.2.7/24 ipv4.dns 10.0.2.1 ipv4.gateway 10.0.2.1   # rename/set up connection for device enp0s3
 1307 ip -4 a   # should show new configurations
 1308 sudo hostnamectl set-hostname 10-client   # sets hostname as 10-client 
### Machine to be used as 192-client 
 1309 nmcli c    # should return same connection names (MyEthernet, etcs.)
 1310 nmcli con mod MyEthernet connection.id MyEtherenet ipv4.method manual ipv4.addresses 192.168.0.7/24 ipv4.dns 192.168.0.1 ipv4.gateway 192.168.0.1   # rename/set up connection for device enp0s3
 1313 ip -4 a   # should show new configurations 
 1314 sudo hostnamectl set-hostname 10-client   # sets hostname as 192-client 
### Configure a static route - can be done via NetworkManager, Manually and Temporarily  
 # On 10-client machine 
 1315 nmcli con mod MyEthernet ipv4.routes "192.168.0.0/24 10.0.2.6"   # NetworkManager (sets network and gateway)
 1316 vi /etc/sysconfig/network-scripts/routes-enp0s3   # CentOS
 1317 nano /etc/network/interfaces    # Ubuntu
 1318 sudo ip route add 192.168.0.0/24 via 10.0.2.6 dev enp0s3    # Temporary
 1319 ip route show    # will show the currently configured routes on the machine, on m current dev machine this returns
 # On 192-client machine 
 1320 nmcli con mod MyEthernet ipv4.routes "10.0.2.0/24 192.168.0.6"   # NetworkManager
 # On router machine
            -> net.ipv4.ip_forward=1    #
 1323 sudo sysctl -p    # updates new configuration options  
 # On 10-client machine
 1324 ping 192.168.0.7   # should now receive a response showing it can ping the ipof 192-client machine
### Route traffic between networks with NAT
 # On router machine
 # We want to set a rule that sets outgoing packets to masquerade, meaning the firewall will obscure the real source of the packet, pretends packets came from a router on the same network where the packets are to be delivered, translates packets back so can be delivered on the original network
 # Then add a forward rule to the chain telling the firewall to accept any packets from th internal interface going out, in this case enp0s3, the 10-network, going out through the outside interface enp0s8
 # Add a rule accepting any packets from the outside interface coming in, but only if associated with outgoing traffic (i.e. web server response)
 1325 sudo firewall-cmd --direct --add-rule ipv4 nat POSTROUTING 0 -o enp0s8 -j MASQUERADE     # --direct flag means write the rule directly to iptables, POSTROUTING 0 makes this the rule at the top of the POSTROUTING chain, -o then outside adapter enp0s8, -l MASQUERADE : rewrite the packet so it looks like it came from the machine routing traffic
 1327 sudo firewwall-cmd --direct --add-rule ipv4 filter FORWARD 0 -i enp0s3 -o enp0s8 -j ACCEPT   # add this rule to the top of the FORWARD chain, -i and internal adapter enp0s3, -o and exeternal adapter enp0s8 => accept anythinng from the inside and forward it to the outside
 1328 sudo firewall-cmd --direct --add-rule ipv4 filter FORWARD 0 -i enp0s8 -o enp0s3 -m state --state RELATED,ESTABLISHED -j ACCEPT    # adds this rule to top of FORWARD chain, -m state --state RELATED,ESTABLISHED means anything coming from the poutside if from an esatblished connection or related to a packet output from the file.
 1329 sudo firewall-cmd --reload    # reloads firewall with new settings
 # On 10-client machine
 1330 ssh username@192.168.0.7    # test out firewall changes by SSHing from one client to another
 1331 wall hello    # wall command sends a message to everybody's terminal, should be able to see message on other (non-SSH) terminal window
### Allow internet access through the router
 # On 10-client    # internet access still going through gateway for the 10 network, can be verified using MTR tool "My Trace Route" 
 1332 mtr google.com    # will show you which route traffic is taking 
 # On router machine   # two routes that it can take to connect to internet has, when NetworkManager brings up nterfaces it has to select a priority for those routes
 1336 ip route show    # in this listing it has the word metric followed by a number i.e. "169.254.0.0/16 dev enp2s0 scope link metric 1002". the lower the number following the higher the priority
 1337 nmcli con edit 192-net   # to bring up CLI
        nmcli> set ipv4.route-metric 1    # can be set to any number, lowest possible value is 0
### Convert the router to forward DNS
 # On router machine 
 # Domain Name System (DNS) gives human readable names to IP addresses, program is BIND (runs most DNS on the internet) uses name daemon "named"
 #Will use a "forwarding DNS server", sends request for DNS information to other DNS servers i.e. "example.com?" (DNS query) would go to 10.0.2.6, which would then forward tonext DNS server in the chain
 1339 sudo yum install -y bind bind-utils   # Installs the bind program and utilities 
 1340 sudo vi /etc/named.conf    #  changes below
            >> acl allowed { 192.168.0.0/24; 10.0.2.0/24; };     # sets up an access control list 
            -> listen-on port 53 { 127.0.0.1; }; => listen-on port 53 { any; };  # now listening for any ip address
            -> listen-on-v6 port 53 { ::1; }; => listen-on-v6 port 53 { any; };  # ipv6 version
            -> allow-query { localhost; }; => allow-query { allowed; };  # allow dns queries to anything in the allowed list
            >> forwarders { 192.168.0.1; }; # list of servers to forward request to
            >> forward only;  # forward only = don't act on traffic simply send request to dns server
 1341 sudo systemctl enable named   # enable the name daemon
 1342 sudo systemctly start named   # start the name daemon
 1343 sudo firewall-cmd --permanent --zone=public --add-service=dns    # --add-service allows user to specify services by name, rather than port+protocol, nedds this to open up port 53 tcp to allow dns queries to go through
 # On 10-client machine, test if names can be resolved through the new service
 1345 nslookup linkedin.com 10.0.2.6   # nslookup tool, 2nd argument is ip address of router, will resolve 
### Sync system time with a network peer
 # NTPlookup (Network time protocol) generally used for setting the time on linux machines, can set up own time server (in this case on the router machine to give the same time to all clients, for event and data logging, services, etc.) Cann configure the server to run the chrony NTP daemon, allow access through the firewall and configure chrony on the client to point to the router to get time information (synchronize the system clocks) 
 1346 chronyc    # launches chronyc cli
 # On router machine
            -> # Allow NTP client access from local network.
            -> #allow 192.168.0.0/16
 1348 sudo systemctl status ntpd    # older ntp daemon has to be stopped before starting chronyd service
 1349 sudo systemctl status chronyd    # check status of chronyd services 
 1350 sudo systemctl restart chronyd   # update with configuration changes
 1351 sudo firewall-cmd --permanent --zone=public --add-service=ntp   # firewall will open port 123 for udp to allow ntp
# On 10-client machine
            >> server 10.0.2.6 prefer # tells chrony to prefer this server over internet servers
 1354 chrocnyc sources     # returns a list fo servers that chrony is using
 1355 chronyc tracking     # tells user how far off the system time is off sytem time
 1356 timedatectl set-time 00:00    # timedatectl allows user to set their systemn time
 1357 timedatectl   # returns the system time and config values
 1358 timedatectl set-ntp 1   # enables ntp and ntp synchronization
### Tunnels
 # Tunnels are another way of sending network traffic, are set up from one interface to another and act as a pipe for other connection, transporting rather than translating. doesn't change packet headers. IP-IP tunnel type or GRE (General Routing Encapsulation) which transmits other protocols in addition, can also setup SSH tunnels, they are a way to create a connection between different networks
 # router-2 set up with 192.168.0.10 enp0s3, 192.168.2.10 enp0s8 
 # New client set up with 192.168.2.7 ip, 192.168.2.0/24 network, 
 # Only routers currently needed for following, clients can be turned off, to set up a tunnel, create new adapter on each router with information about the other route
 # On router-1
 1359 sudo vi /etc/sysconfig/network-scripts/ifcfg-tun0   # creates new file
            >> DEVICE=tun0      # New device name
            >> BOOTPROTO=none   # do not automatically startup
            >> ONBOOT=no        # do not automatically startup
 # On router-2
 1360 sudo vi /etc/sysconfig/network-scripts/ifcfg-tun0   # creates new file
            >> DEVICE=tun0      # New device name
            >> BOOTPROTO=none   # do not automatically startup
            >> ONBOOT=no        # do not automatically startup
 1361 sudo ifup tun0   # parses network-scripts folder for name
 # On router-1
 1363 ipa ||ip addr   # should now show the tunnel connection, however firewalld still needs to be stopped to allow to ping through to the other side of the tunnel (
 1364 sudo sytemctl stop firewalld   # (on both machines)
 # tunnel is unencrypted, should use secure protocols like ssh to communicate
### Troubleshooting
 1366 sudo arping -I enp0s3   # Allows to check for duplicate IP assignment (use from another machine on the same network),  
 # If can ping extrenal IPs but not domains, its usually a DNS problem, check DNS server settings, then check DNS server can resolve names, "nslookup example.com 10.0.2.6"
 # If route not working: Check for typos, check route priority, if using NetworkManager check ifcfg file, and rememebr "ip" command only makes temporary routes
 # If traffic not flowing to a service or host: Check firewall rules, disable firewall if safe to test, "sudo systemctl stop firewalld", tunnel establishes a connection between two interfaces but still needs to have a route which connects the
##### LInux: User and Group management #####
 1267 cat /etc/passwd  # 
         -> root:x:0:0:root:/root:/bin/bash    # 7 colon-separate columns follow below
      # username (case-sensitive): 
      # encoded password/password encoding type (if using shadow suite will be an x telling us encoded password is in /etc/shadow file): 
      # UID (numeric, new non system-admin UIDs start at 1000 - configuration setting in /etc/login.defs):  
      # GID (numeric - is in /etc/groups
      # Comment field (store user information -if you wish)
      # User home directory (default /home/username, but can be configured in /etc/default/useradd, or by using useradd with -D)
      # Default login shell ( can be configured in /etc/default/useradd or by using useradd with -D)
         -> root:$6$7omfGkTuyahYb6tk$hXMVzm8byeyoOaITOgfb59/DWhv3UeBWpKD6nZjWtQlzb0GCP22PfigFfZ/XMYSzjArVzXlnsKR/DVnMw0oB6.::0:99999:7:::  # 9 colon separated column definitions follow below
      # username (must match /etc/passwd file)
      # hashed password (or characters to indicate password hasn't been set, one or more exclamation points if password hasn't been set or account is locked - redhat based: Centos, etc.). 
      # number of days since the password was last changed
      # number of days before a password can be changed with 0 indicating that the password can be changed at any time
      # number of days until a password must be changed 
      # number of days prior to password expiry before password miust be changed
      # number of days after password expires before account is disabled
      # number of days since Jan 1st 1970 that an account has been disabled
      # reserved for future use
 1269 cat /etc/group    # 4 columns
      # group name 
      # encoded password/password encoding type (if using shadow suite will be an x telling us encoded password is in /etc/gshadow file): 
      # GID (numeric - new/non system-admin GIDs start at 1000 - configuration setting in /etc/login.defs, any under 1000 generally a system service or belong to the root user)
      # user which belong to the group
 # group passwords allow users to gain the privileges of the group by using the 'group' command
         -> accounting:!::bob   # has four columns
      # group name (has to match name in /etc/group)
      # Hashed password, or exclamation mark which means user cannot change to this group by using the group command
      # comma-separated list of administrators (can chnage group password, add members)
      # comma-separated list of users (don't have to type in group password when using the newgrp' command. If file is created after changing groups, the file will be owned by the user and
### Convert to shadow suite
 # most Linux systems use SHA512 for generating a one-way hash, which is more secure than earlier algorithms such as md5, which generates a much shorter hash, and sufferd from a collision 
 # One-way hashes are not reversible and you cannot generate plain text from the hash
 # Has can be cracked by taking words from the dictionary and hashing them one at a time and comparing the output to the hashed password to see if they match. 
 # Linux has additional protections called a 'salt', which is a set of random charcters appended to the password before it is hashed, the salt is stored in the password files along with the hash
 # In a system which doesn't use the shadow suite, these files can be read by anyone, however using the shadow suite, require root user access to read the /etc/shadow and /etc/gshadow files
 1271 sudo yum -y install shadow-utils   # if shadow utils is not installed, shadow-utils is the package to install
 # Commands in the shadow suite allow you to convert a password from the shadow suite back to the previous method 'pwunconv'/'pwconv and 'grpunconv'/'grpconv'  
 1272 sudo pwunconv    # will unconvert passwords in /etc/shadow file, passwords will now be in /etc/passwd
 1273 sudo groupadd testgroup    # adds new group
 1274 sudo gpasswd testgroup     # adds password for group
 1275 sudo grpunconv   # will unconvert passwords in /etc/gshadow file, passwords will now be in /etc/group
### Increase password hash strength 
 1276 cat /etc/login.defs   # Check encryption method if not SHA512, will need to be changed to line below 
 1277 sudo chage -d 0 username # will force user to change their password at the next login (to update user passwords to using the new hash)
 1278 sudo vi /etc/security/pwquality.conf   # password policy (number of required uppercase, lowercase, character types, password length, etc.) 
 # changing anything in the /etc/login.defs file only affects new users, not existing users, to modify existing users requires 'change' command (see 1277),but can change global user account 
 # chage argument flags: -I number of days of inactivity before a user account expires, -d number of days since password was last changed, setting to 0 meaans password hasn't been changed and 
 1279 chage -l ltetteh   # returns password expiration variables
 1280 sudo chage -E ltetteh 2020-02-02   # changes expiration date of account
 1281 sudo chage -M 90 user   # changes password expiration date to 90 days after the current date
 1282 sudo chage -I 10 user   # set account inactivity to 10 days before the account is locked
 1283 sudo chage -I -1 -m 0 -M 99999 -E -1 user   # sets account to never expire on inactivity; minimum days between password changes to zero, max to 99999, and the account to have no expiration date 
 # usermod option flags: -l change user's login name, -L lock account, -U unlock account, -m move home directory, -g change gid, -u change uid  
 1284 sudo usermod -L user   # locks account
 1284a cat /etc/shadow   # first character of encoded password is now an exclamation point showing that the account is locked
 1285 sudo usermod -U user   # unlocks accout
 # passwd option flags: -d delete password, -e expires password, -l locks password, -u unlocks password, -S outputs password status
 1286 sudo passwd -l user   # locks user account
 1287 cat /etc/shadow    # first character of encoded password is now two exclamation points showing that the account is locked, only locks password, user could still login with SSH keys
 1288 sudo chage -E 0 user   # Expires user account, fully locks account  
 1289 whoami   # command returns user login name
 1290 logname   # command returns logname: no login name, from direct output from terminal machine, however
 1292 whoami   # returns root   - returns current user
 1293 logname   # returns opus  - returns who logged in initially
 1294 echo $PATH   # returns the path of the initial user (in this case opus) even though privileges have been escalated to that of the superuser
 # if su - is used (su followed by hyphen, will switch the PATH variable to that of the current user, but logname will still return opus)
 1296 whoami   # returns root   - returns current user
 1297 logname   # returns opus  - returns who logged in initially
 1298 echo $PATH   # returns the environment path of the superuser
         -> wheel:x:10:opus    # the wheel group usually defines hich users can use the sudo and su commands to elavate privileges to that of the superuser 
 1301 gcc -g sigaction-handling2.c -o sigaction-handling2 -std=gnu99   # std=gnu99 for posix-reliant applications
 1302 gcc -g creating_a_thread.c -o threadcreate -std=gnu99 -lpthread  # library for pthreads
#### Converting pcap to wav ####
##########################################################################################################################################
##### rebuild and reinstall PJSIP: ####
##########################################################################################################################################
#### Setting up a test server on OVP Verification platform steps ####
 1103 vi /etc/sysconfig/selinux -> SELINUX=disabled                      # Disable SELinux
      reboot                                                             # reboot 
      service NetworkManager stop  | systemctl stop NetworkManager       # Disable NetworkManager
      service iptables stop        | systemctl stop firewalld            # Disable the server firewall
      vi /etc/sysconfig/network-scripts/ifcfg-eth0 -> BOOTPROT=dhcp      # Identify the interface that will connect to the dev network (in case of src05 is eth0), edit config file 
      yum -y install deltarpm epel-release yum-presto yum-utils          # Should be installed before installing any other packages
      yum update                                                         # Run a yum update
      yum -y install ksh libssh nfs-utils ntp openssh-clients            # Install following packages on all servers
      yum -y install bind-utils dnsmasq httpd tftp-server                # Install following packages on traffic sink/source servers
   ## To install asterisk on CentOS 6 traffic generators and sinks ##
   ## Novatech Mini-ITX Systems - Black Towers in lab downstairs: src05, sink03, etcs. ##
      ## Two onboard network adaptors: Bottom-most adaptor is Intel NIC (supported by Centos 6/7). 
      ## Topmost adaptor is a Qualcomm Atheros NIC that requires the alx kernel module to be installed - only available from ElRepo CentOS repository
      rpm -Uvh http://www.elrepo.org/elrepo-release-6-6.el6.elrepo.noarch.rpm      # Install the alx repository
      yum -y install kmod-alx                                                      # Install the kmod-alx package
      modprobe alx                                                                 # Once module installed, can be loaded by running
   ## User Configuration ##
      useradd opus                        # Create an opus user
      passwd opus                         # Set password for new user
      usermod -aG wheel opus              # add opus user to wheel group
      usermod -aG asterisk opus           # add opus user to asterisk group
    %wheel  ALL=(ALL)       NOPASSWD: ALL # (uncomment)
    %wheel  ALL=(ALL)       ALL           # (comment out)
    Defaults    requiretty                # (comment out)
   ## User/Group IDs ## 
      usermod -u 500 opus                 # changes user ID to 500
      groupmod -g 500 opus                # changes group ID to 500
      find / -user <old-UID> -exec chown -h 500 {} \;    # find files/folders that used to belong to old uid, make new owner UID 500 ?
      find / -group <old-GID> -exec chgrp -h 500 {} \;   # find files/folders that used to belong to old uid, make new owner GID 500 ?
      usermod -g 500 opus                 # add opus user to group with id 500 ?
   ## Management Server Exports (ovpmgmt01) ## 
      cat /etc/exports ->                 # should output following info 
   ## Test Server Imports ##
      ## Directories to be mounted are read from the /etc/fstab file  
            ovpmgmt01.development:/home/opus/testdata[ABC] /home/opus/testdata[ABC] nfs4 defaults,noac,noatime,nodiratime 0 0   # (individual lines for A|B|C)
            ovpmgmt01.development:/testcode/vpt/CentOS[67] /usr/local/vpt nfs4 defaults 0 0   # Change to required 
   ## Paths ##
      ## PATH must be updated in /home/opus/.bashrc on all servers 
  ## VPT Scripts, Data & Software ##
     ## VPT scripts/files sttored at http://opussvn/svn/OVP/trunk  runs from /home/opus/OPUSTest (symlink at /root/OPUSTest)
     ## On ovpmgmt01 software stored at /testcode/vpt/CentOS[67] 
     ln -s /testcode/vpt/CentOS6 /usr/local/vpt   # or appropriate platform (i.e. CentOS7)
     ## On remote machines 
     mkdir -p /usr/local/vpt              # creates direcory
     mount ovpmgmt01:/testcode/vpt/ /usr/local/vpt   #mounts directory as /usr/local/vpt
  ## VPT Server Configuration ##
     cat /etc/vpt/vpt.conf                # on ovpmgmt01
     ## Each testcase has a field called Addr mode which can be none, ip or serial corresponding to the nochannel, subnet, serial  
     cat /home/opus/testdata[ABC]/vpt.tcl # on ovpmgmt01   -   built from a combination of /usr/local/vpt/data/vpt_network_configs.xml and /etc/vpt/vpt.conf      
#######################################################################                                                         
#### installing linux (req, 1GB RAM, 5-10GB HDD space, Network card, 64-bit Intel or AMD CPU, CentOS ISO image
#### distrowatch.com  Debian (APT) -> Ubuntu, Mint, Kali    RedHat (RPM) ->  CentOS (Yum), Fedora, Mandriva
#### https://virtualbox.org (Host key for windows is right Ctrl (+t for snapshot saves state of virtual machine, all installed programs and all running programs, can make multiple snapshots)
####### VirtualBox extensions provide support for faster USB drives --- Below: setting up a Virtual image
####### VirtualBox -- File -- Preferences -- Input -- VirtualBox Managerhistory
#######                                            -- Virtual Machine
#######            -> Machine -> Add, Settings, Remove, Clone, Show Log, Refresh, etc.
#######            >> New >> Name (Any), Type (Linux), Version (Red Hat 64-bit) if CentOS >> Memory 1.5-2GB >> VDI >> Dynamically >> (Defaults ok unless folder name) >> OK
#######       Name -> Settings -> System -> Motherboard -> Enable I/O APIC (runs faster if RedHat), 
#######                                   > Processor ->> Processor(s) (Number of CPUs)       > Acceleration ->> Enable VT, Enable Nested (both on), Paravirtualization (Hyper-V = Windows) 
#######                        -> Display -> Screen -> Video Memory (increase: e.g. 70MB), Enable 3d Acceleration (required - not 2D), 
#######                        -> Storage -> Controller: SATA
#######                        -> Network -> Enable Network Adapter -> Attached to: NAT (allows machine to connect to internet, doesn't allow remote login -to it)
#######                                                                           : Bridged Adapter (allows remote logifn to virtual machine) 
#### After Virtual Machine setup download CentOS, DVD ISO ~ 4.0GB, Everything ISO ~ 9GB, will then need to Full clone Virtual machine, and if require a DNS server will also want to clone for DNS server
#### After clicking image, select start and select ISO download. Right Ctrl + F for full screen mode. Diff installs available (minimal default).
#### via centos.org can also install netinstall version (install from network)
#### through gnome-desktop can access Application installer and Software Update aplications, useful for updates and installations (Admin-level privileges/user, network connectivity)
#### sudo yum groupinstall "Development Tools"   # includes C compiler and source code, which allows to compile kernel drivers
#### gnome-desktop window >> bottom of screen (virtualBox popup menu) >> Devices >> Insert Guest Addition CD >> Run (will then compile new kernel module for "Development Tools" requires reboot)
#### configuring gnome-desktop -- Applications -- Tools -- Settings
#### configuring gnome-desktop -- Applications -- Utilities -- Tweak Tool   (to use "update extensions" - sudo yum install gnome-shell-browser-plugin) 
#### https://www.linode.com/docs/development/java/install-java-on-centos/
#### CentosOS -> Applications Menu -> Settings -> Notifications,etc. -> 
#### pressing the windows button (right Ctrl) on virtual box CentOS will allow to switch between workspaces and overview of all workspaces 
#### Applications -> Favorites -> Hel    #for GNOME systems
# Windows subsystem for linux available on Windows 10
# cloud providers of linux systems: Azure, AWS, GCP DigitalOcean, Linode, etc.
gcc simple_n.c fwd_propgation_main.c -o n_fwd -std=c99 -lm  # for math.h library
gcc simple_n.o fwd_propgation_main.c -o n_fwd -std=c99 -l math  # for math.h library
gcc -c simple_n.c -o simple.o -std=c99 # used to create a .o filea
gcc -Wall simple_n.o fwd_propgation_main.c -o n_fwd -std=c99 -lm  # -Wall gives all warnings
gcc -E main.c | less -N  # show preprocessing output
gcc -S main.c -o main.s  # show assembly code
gcc -g main.c  # debugging info
gcc -v main.c  # verbose
gcc -Wall -ansi main.c  # ISO C89 standard
gcc -Wall -funsigned-char main.c  #  char c = -10 << 246
gcc -Wall -fsigned-char main.c  # char c = -10 << -10
gcc -D MY_MACRO main.c  # defines macro
gcc -Wall -Werror main.c  # converts wanrnings to errors
nm main.o  # shows all functions included on output file
ldd main.o  # shows all of external liraries linked 
gcc -g main.c -o main -ldl -std=c99   # for dynami loadig of libraries
gcc -pg main.c -o main  # debugging info, and profiling info
./main   # generates a file called gmon.out
gcc test.c @opt_file  #can put options in opt_file and pass it to gcc 
#two step process for creating shared object (.so) files
gcc -c -Wall -fPIC main.c  # fPIC for position independent code
#process for creating and linking shared object (.so) files
gcc -g -fPIC libnew.c libtwo.c -shared -o -libnew.so   # fPIC = position independent code
gcc -o main main.o -L ../dynamiclibraries/ -l new   # omit the lib prefix and .so extenion for the libnew.so file, so is just "new"
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH  # need to export to LD_LIBRARY_PATH for linker to find files
#process for creating and linking shared object (.so) files
gcc -g -c -fPIC doublelinkedlist.c -o -doublelinkedlist.o   # fPIC = position independent code
gcc -g -c -fPIC doublelinkedlistutil.c -o -doublelinkedlistutil.o   # fPIC = position independent code
gcc -o main main.o -L ../dynamiclibraries/ -l new   # omit the lib prefix and .so extenion for the libnew.so file, so is just "new"
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH  # need to export to LD_LIBRARY_PATH for linker to find files
#in cygwin
gcc -g -fPIC libnew.c -shared -o -libnew.dll   # -
gcc -o main main.o -L ../dynamiclibraries/ -l libnew   # omit the lib prefix and .so extenion for the libnew.so file, so is just "new"
export PATH=$(pwd):$PATH  # need to export to LD_LIBRARY_PATH for linker to find files
# assembly compilation iinstrucions
#for programs calling main
# for compiling with gdb
#creating static librarires
gcc -c cipher_encode.c   # create .o files
ar -crs libcipher.a cipher_encode.o cipher_decode.o  # creates .a file
ar -t libcipher.a        # -t table option lists modules in .a file
gcc main.c lib.a -o main   # include header(s) in .c file
