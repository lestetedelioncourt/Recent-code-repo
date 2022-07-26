-- perldoc.perl.org -- Perl 5 documentation, has search bar and all documentation on 'use' modules i.e. IO::File, or keywords such as 'print'
- 'perldoc $arg1' i.e. 'perldoc IO::File' can be run from the command line and will return the documentation on the website in 'man' page format  
- 'perldoc -f $arg1' i.e. 'perldoc -f print' the -f flag is used for functions 

Includes
- ' use ' is a keyword along the lines of include to include modules and pragma
- ' use warnings; ' a pragma a.k.a a compiler directive, data embedded in source code by programmers to indicate some intention to the compiler

Keywords and syntax
- Many Perl built-in functions can be found at perldoc.perl.org/index-functions-by-cat.html
- ' say "string" ' is a keyword and prints the statement followed by a new line character
- ' print("string $newstring"); ' is a function that prints out the string variables passed in as an argument 
- ' my ' is a keyword which declares the variable to be lexically scoped in enclosing block or file (making the variable local to the block or file currently in) 
  - if run without a 'my' initializing a variable, the script run will produce an error message
- ' $ ' sign before a variable makes it a scalar
- ' @ ' sign before variable makes it an array
- ' % ' sign before a variable is used to refer to key/value pairs
- ' $rarray = \@array ' is used for the reference to an array
- ' $rhash = \%hash ' is used forthe reference to a hash
- ' scalar ' keyword returns the size of an array
- ' or ' keyword is another type of logical or 
- ' foreach ' keyword runs a for loop through the elements of an array
- ' ${var1} ' curly braces can be used around a variable inside a string a la Bash scripting
- Characters such as quotation marks are escaped within strings as per usual i.e. ' \" ' will output , ' \\ ' will give single backslash 
- ' qq(String "Quote"); ' double q interpolation quote operator allows the use of non-escaped special characters in a string for assignment.
  - Curly braces or square brackets can also can also be used as the opening and enclosing characters denoting the string.
- ' qw( one two three ); ' quote word list, will intialise a list of word-strings
- ' <STDIN> ' equivalent to cin (C++)
- ' local ' keyword functions similarly to 'my' in most circumstances, however it temporarily assigns a new value to an existing global variable instead (rarely used - don't use)
- ' state ' keyword functions like 'static' in C++. 'state $n = 10;' is now a static variable whose lifespan extends beyond that of the block it is in. If Perl < ersion 5.16.0 will need to include " use feature 'state'; " as a pragma
- ' die ' keyword raises an exception
- ' join ' keyword takes two arguments, joining the members of the second argument (Array/list/hash(?)) using the first argument as a separator to produce a scalar
- ' chomp ' keyword will remove the line endings from any lines, removes both Windows (carriage return/line feed) and Unix (new line character)
- ' exit; ' keyword will end the script
- ' length ' keyword is a function that returns the length of the value passed to it, i.e. string/array/hash, etc.
- ' substr ' keyword will obtain a substring of  given string
- ' lc ' keyword will change all letters in a given string to lower case
- ' uc ' keyword will change all letters in a given string to upper case
- ' ucfirst ' keyword will only change first letters in a given string to upper case
- ' abs ' keyword will return an unsigned result
- ' atan2(1,1) *4 ' arctan function can be used to return the value of PI
- ' sqrt() ' keyword for square root
- ' ** ' for power 
- hex, oct are also keywords and will return hexadecimal and octal representatuions of the number given
- ' rand ' with no arguments or seed will return a random number between 0 and 1 (based on system entropy seed) 
- ' rand 100 ' rand with an argument will return a random number bween 0 and 1, multiplied by the value passed as an argument, 'int rand 100' to return an integer 
- ' grep ' keyword functions similarly to grep at the command line

Assignments
- ' my @array = (1, 2, 3); say foreach @array; ' have now created an array and will print "1\n", "2\n", "3\n"
- ' for each my $x ( $alpha, $beta, $charlie ) { say $x; } ' if $alpha, $beta, $charlie have been defined, will say each in turn 
- ' my $count = @array ; ' assigning an array variable to a scalar will return the number of elements in the array. Following from the previous assignment print("$count"); would output '3'
- ' my ( $x, $y, $z ) = ( 1, 2, 3 ); ' assigns values of 1, 2 and 3 individually to the variables x, y and z

Main
- ' main(@ARGV); ' is the call of main followed by declaration "sub main { line1; line2; line3;}" 
  - ' @ARGV ' is a special array predefined by Perl to contain the parameters passed from the command line when the script was invoked
  - ' shift ' keyword reads in arguments from the command line after "main(@ARGV)" call
  - ' my $filename = shift || "linesfile.txt"; ' will first attempt to read in arguments from the command line then if not will read in "linesfile.txt" 

File Operations 
- ' open(FH, $filename); ' calls open on a file , does not need any extra 'use' statements
- ' my @lines = <FH>; ' reads in the whole file, stores the lines as an array, does not require any extra 'use' statements
- ' close(FH); ' closes the file, does not require any extra use statements
- ' use IO::File; ' includes IO::File module which is an object oriented file handling library
  - ' my $fh = IO::File->new( $filename, "r" ); ' opens afile with simple error reporting, will return false if file did not open can check with "if (! $fh) 
  - ' while ( $fh->getline() ) { $count++; } ' getline is a function accessible to file object that returns true for each line in the file.
  - ' $fh->close; ' Once object is out of scope the file will close automatically, but good idea to close explicitly

File I/O 
- ' open(my $fh, '<', $filename) or die "Cannot open file: $!"; print while <$fh>; close $fh; ' 
  - First argument is the file handle, it is being declared here, but is accessible elsewhere in the perl script
  - Second argument the '<' indicates that the file is being opened to be read, 
    - '>' opening a file for writing
    - '+<' to open a file for both read and write 
    - '+>' clobbers/overwrites file first
  - Third argument is the filename itself
  - ' open(my $fh, "< $filename") or die "Cannot open file: $!"; ' 2nd and 3rd arguments can be combined into a single string, and will stil be run in the same way
  - ' print while <$fh>; ' print with default variable and postfix while conditional, if carriage returns/new lines are contained in file will output lines as new lines.
  - File handle 
- ' while (my $line = <$fh>) { chomp $line; } ' chomp removes line endings (new line character, etc.) from the lines in the file when being read in
- ' open(my $fh, "> $filename"); ' use of the '>' (write) command means it will empty a file first for writing and then begin overwriting the file - will create the file if it doesn't exist. 
- ' open(my $fh, ">> $filename"); ' use of the '>>' command means it will append to a file (add lines to the end) 
- ' open(FH, '<', $filename) or die "Cannot open file: $!"; print while <FH>; close FH; ' traditional use of capital letters to create the file handle, creates a global variable, the letters 'FH' form a special variable used for the purpose of creating a file handle only. Archaic usage, should use scoped scalar variable such as 'my $fh' instead for new code
- ' print $fh2 $line; ' syntax is (PRINT FILEHANDLE LIST). If file has been opened for writing will write to the file specified by the filehandle.  
- ' my $fh = IO::File->new( "< $filename" ); ' 
  - ' IO:: ' == IO namespace
  - ' IO::File->new() ' use of the dereference arrow operator -> allows access to methods and properties inside a class or object (class = IO::File, new() = constructor) 
  - IO::File inherits from IO::Handle, Documentation can be found under 'perldoc IO::Handle'
- copyfile-working.pl shows the alterations that need to be made to compensate for a property of Windows based systems, to see a line feed from a file it interprets as a text file and immediately append a carriage return character. Thus the file handles have the accessible method binmode.
  - ' $fh->binmode(); ' changes the file read to binary mode, to stop the windows carriage return being added.

Functions and Subroutines
- ' sub ' keyword used to specify a function. A function is also referred to as a subroutine in Perl
- In other languages a function is defined as returning a value, whilst a subroutine is not. This distinction is not made in Perl.
- Whitespace is required between the word 'sub' and the function
- ' hello(); sub hello { say "This is the hello function."; } ' Standard syntax, function call 'hello()' function body 'sub hello{statement1; etc..}'
- ' say hello(); sub hello { return "This is the hello function."; } ' Standard syntax, function call with return statement
- ' say foreach func(); sub func { return (1, 2, 3, 4, 5); } ' Standard syntax, function call with return statement
- ' my $count = countlines( $filename ); ' function argument passed in at function call.
  - ' sub countlines { line 1; line 2; etcs... } ' function declaration, does not need to specify arguments here 
  - ' my $filename = shift; ' shift keyword returns first scalar from the default array variable '@_' and removes it from the front of the array
  - ' error("countlines: missing filename") unless $filename; ' this is termed a post-fix conditional, unless filename is defined will print this error message
    - "error" is not a keyword so the subroutine has to be defined for this function r
    - ' sub error { my $e = shift || "unknown error"; say "$0: $e"; exit 0; ' 
    - ' $0 ' is a builtin variable that returns the full path of our perl script
    - ' exit 0 ' gives a return code of zero and exits script 
  - ' my $fh = IO::File->new( $filename, "r" ) or error("Cannot open $filename ($!)\n"); ' being used so user knows if unable to initialize $fh file object
- Arguments are passed into functions using a special array variable '@_'
- ' func1('one', 'two', 'three'); sub func1 { say foreach @_; } ' '@_' Will return every argument passed into the function as an array initialized from a list. It is the equivalent of the default scalar variable above, except for arrays
- ' func1('one', 'two', 'three'); sub func1 { my ($a, $b, $c) = @_; say "$a $b $c"; } ' can assign values from default array to scalar variables 
- ' func1('one', 'two', 'three'); sub func1 { my $a = shift; my $b = shift; my $c = shift; say "$a $b $c" } ' keyword 'shift' by default uses the default array variable
- ' my @array = qw(on two three); func1('uno', 'dos', 'tres', @array, 'ein'); sub func1 { say foreach @_; } ' passing @array in as a function argument will simply append it to the end of the default array variable i.e. @_[0] = 'uno', @_[1] = 'dos', @_[2] = 'tres', @_[3] = 'one', @_[4] = 'two', @_[5] = 'three', @_[6] = 'ein'
- ' func(); func(); func(); sub func { state $n = 10; say $++n; } ' static variable $n declared with '$state n' will lead to output 11, 12, 13
- ' use subs qw( func ); func; sub func { say "That func"; } ' The 'use subs' pragma takes a list of the names of functions, allowing function calls w/o parentheses like the Perl built-ins
- ' use subs qw( func ); func 'foo', 'bar', 'baz'; sub func { say foreach @_; } ' Can still pass parameters, normal operation as the built-ins

Lists, Arrays, Associative Arrays
- ' say (1, 2, 3); ' Will print 123 with no endline characters between values as figures in brackets separated by commas are in Perl defined as the elements of a list
- ' say foreach (1, 2, 3); ' Will print the elements of a list separated by new line characters
- ' say foreach qw( one two three) ' will print the elements of a quote word list
- ' say qw( one two three )[1]; ' will print the second element in the quote word list
- ' my @array = (1, 2, 3); say foreach @array; ' will print out elements in the array, first statement initializes the array from a list
- ' my @array = qw( one two three ); say foreach @array; say $array[1]; ' last statement accesses a scalar within the array
- ' push @array, qw( four five six ); ' will push the list elements onto the end of the array
- ' my $x = pop @array; ' will remove an element from the end of an array, and return it, allowing the element to be assigned to a new variable
- ' my $x = shift @array; ' shift will remove an element from the front of an array, and return it, allowing the element to be assigned to a new variable
- ' unshift @array, qw( some new elemenets); ' unshift statement will add new elements to the beginning of an array
- ' say foreach @array[3,7,8,2]; ' will print an "array slice", that is a subset of the array. The elements will be printed in the order they are listed
- ' say foreach @array[1..5]; ' will print the array elements from 1 to 5
- ' my @a2 = @array[5,2,9]; ' will initialise a new array with the elements specified.
- ' my %hash = (tom =>"cat", frido=>"dog", etc); ' will initialise an associative array with keys and values
  - '$hash{perky} = "parrot"; '  
  - Hash array so termed because it uses a hash table to associate a key to an index
- ' while( my ($k, $v) = each %hash ) { say "$k -> $v"; } ' will print out the keys and values as $k and $v, hash is not stored in any particular order and will output randomly
- ' foreach my $k ( sort(keys %hash) ) { my $v = $hash{$k}; say "$k -> $v"; } ' will sort the keys and then output the result
- ' my @a = qw( one two three four five ); say foreach grep /t/, @a; ' will output any array member that contains the letter t
  - ' my @a = qw( one two three four five ); say foreach grep !/t/, @a; ' will output the array members that do not contain the letter t
  - ' my @a = qw( one two three four five ); say foreach grep { /t/ } @a; ' alternative syntax for grep includes a block where more processing can be undertaken. 
- ' my @a = (1, 2, 3, 4, 5); say foreach map { $_ * 7 } @a; ' the 'map' keyword passes each element of the array into the default scalar variable, allowing them to be edited directly  

Constants
- ' use constant PI => 3.14159; ' Perl doesn't include constants in definition of the language, but does have a pragma for this purpose in standard distribution.
- ' sub PI { 3.14159; } ' use constant pragmas are implemented as functions without arguments, as such it is common to initialise a constant value as a function with a single line return statement. this is the same method the 'use constant' pragma uses to initialise constants.
- ' use constant { TRUE => 1, FALSE => '', PI => 3.14159 }; ' can initialise several constants at once via the use of curly braces and commas
   
Conditionals
- ' if ( $x == 47 ) { statement1; statement2; etc } ' Usual C/C++ syntax for if blocks
- ' elsif ($x == 5 _ {statement1; statement2; etc } ' keyword is elsif, otherwise normal C/C++ syntax for else if blocks
- ' else { statement1; statement2; etc } ' Usual C/C++ syntax for else blocks 
- ' unless ( $x == 1 ) { statement1; statement2; etc } ' 'unless' keyword unique to Perl. Will run code block unless the condition is met
- ' say "true" if $x == 1; ' Post-fix conditional, unique to perl, parentheses are not required around the condition, but can be given, cannot be used with 'else' or 'else if' statements
- ' say "these are different" unless $x == $y; ' Post-fix conditionals can also be used with the unless keyword
- Switch statements use the keywords 'given', 'when' and 'default;. They are highly experimental introduced in Perl version 5.10 and will likely break any code in which they are used
  - ' my $x = 1; my $y = 2; my $z = 3; my $v = $x; '
  - ' given ($v) { when ($x) { say "x"; } when ($y) { say "y"; } when ($z) { say "z"; } default {say "default"; } ' example code structure for switch statement
  - ' given ($v) { say 'x' when $x; say 'y' when $y; say 'z' when $z; } ' when conditional can also be structured as a post-fix conditional 
- Usual way of creating a switch-type statement using the pre-existing syntax. Perl is optimized to search hashes, so not slower or more expensive than using an ordinary switch statement
  - ' my $x = 1; my $y = 2; my $z = 3; my $v = $x; '
  - ' my %hash = ( $x => "x", $y => "y", $z => "z" ); ' - creates an associative array with key values equivalent to the variable $x, $y, $z
  - ' if ( $hash{$v} ) { say $hash{$v}; } else { say 'default'; } ' - Uses hash as a lookup table. Outputs result if the variable $v is equal to one of the hash key values.
- ' say $x > $y ? 'x' : 'y'; ' - Also uses the ternary conditional from C++  
- ' say $x == $y ? 'equal' : $x > $y ? 'x' : 'y'; ' Can also chain ternary operators together to form the equivalent of nested conditionals

Loops
- ' while (@array) { say shift @array; } ' in this context array will evaluate true until empty. 'shift' will remove and return the first element of the array. Otherwise C/C++ syntax
- ' until (scalar @array == 0) { say shift @array; } ' scalar takes the size of the array. 'until' will run block of code until condition evaluates as true 
- ' say shift @array while @array; ' 'while' keyword can also be used as a post-fix conditional
- ' say shift @array until scalar @array == 0; ' 'until' keyword can also be used as a post-fix conditional  
- ' for ( my $i = 0; $array[$i]; ++$i ) { say $array[$i]; } ' syntax of for loop is equivalent to C/C++ syntax
- ' foreach my $s ( @array ) { say $s; } ' foreach is the iterative form of the for loop, equivalent to previous for loop, requires parentheses around argument
- ' foreach my $s ( @array ) { $s .= "-foo"; } ' the variable $s is pointing to the element of the array, editing $s will also alter the element of the array it is pointing to
- ' say foreach @array; ' postfix version of the 'foreach' loop, 'say' uses default value variable
- ' next if $x eq $y; ' keyword 'next' will stop it executing the current code block if condition is met, it will then go back to the while condition and continue the next iteration if true
- ' last if $x eq $y; ' keyword last' will act as a break command if the condition is met, i.e. will stop processing the loop
- ' while ($array[$count]) { say "$count: $array[$count]"; } continue { ++$count; } ' continue is a flow statement - this is equivalent to a for loop

Default Variable
- ' foreach (@array) { say; } ' keyword 'say' in this instance uses the default value variable and will output the variable conatined in the array
- ' say foreach @array; ' in this postfix version of the 'foreach' loop, 'say' also uses the default value variable or default variable
- Builtin Functions 'abs alarm chomp chop chr chroot cos defined eval evalbytes exp fc glob hex int lc lcfirst length log lstat mkdir oct ord pos print printf quotemeta readlink readpipe ref require reverse rmdir say sin split sqrt stat study uc ucfirst unlink unpack' - these will all use the default value variable if no value is specified

Autoflush variable'
- Output buffer holds the output. If for example the user specifies a prompt, the prompt information may be held in the output buffer, and not appear on the screen until it has received input. It may then be flushed out of the buffer all at once, causing the prompt prior to output only after the user has enetered input 
  - ' my $num = <STDIN>; ' equivalent to cin statement (C++)
  - ' $| = 1; ' this enables the autoflush variable which means that the output buffer is flushed after every read operation, which is less efficient for running code, but will ensure that any prompt is displayed before the user has to enter any input

System Error variable 
- ' if (-e $filename ) { say 'found!'; } else { say "error: $!"; } ' will give error return code, this will usually be output as a string, i.e. "error: No such file or directory"
- ' if (-e $filename ) { say 'found!'; } else { my $errnum = $! + 0; say "error: $errnum"; } ' error output can be changed by duck-typing as such

Special variables
- ' for my $k ( sort keys %ENV ) { say "$k = $ENV{$k}"; ' keyword 'ENV' is a special variable, this loop will show the environment variables sorted by key, 'sort' 'keys' also keywords
- ' say $^O; ' will output the name of the operating system (this is a capital letter O - NOT a zero)
- ' say $^V; ' will output the version of Perl that is currently running

Operators
- Duck typing means that different operators are required to specify the type of variable(s) being operated upon. Normal operator precedence applies (operator precedence table in Ch08)
- Division operations in Perl will return a float by default for integer division 'int($x / $y)'
- There can be some errors in rounding because perl by default uses floating point. Can use module (downloaded from CPAN) to handle fixed point number and arithmetic, (dollars.pl in Ch08 shows an example of how to sanitize a function output and avoid rounding errors)
- Compound assignment works also with modulus "%=" as well as normal arithmetical operators, and the string concatenation operator
- ' ==, !=, <=, etc.' for numeric variable comparison  
- ' eq, ge, gt, le, lt, etc.' for string variable comparison
- ' if ( $a == $c and $b == $d) { statement1; etc } ' 'and' keyword for &&, 'or' keyword for ||, 'xor' keyword for "exclusive or", normal &&, || operators etcs.  
- ' if (-e $filename) { statement1; etcs } ' file test operator '-e' is used to check if a file exists on the system 
- ' if (-r $filename) { statement1; etcs } ' file test operator '-r' is used to check if a file can be read
- ' if (-w $filename) { statement1; etcs } ' file test operator '-w' is used to check if a file can be written to
- ' if (-z $filename) { statement1; etcs } ' file test operator '-z' is used to check if a file has zero length
- ' if (-s $filename) { statement1; etcs } ' file test operator '-s' is used to check if a file is not empty 
- ' if (-f $filename) { statement1; etcs } ' file test operator '-f' is used to check if a file is a plain file
- ' if (-d $filename) { statement1; etcs } ' file test operator '-w' is used to check if a file is a directory
- All file operators can be found at perldoc.perl.org/functions/-X.html or "perldoc -f -X" 
- ' foreach my $i ('a' .. 'z') { print "$i "; } ' range operator '..' can be used to traverse a range of values sequentially  
- ' my @array = (0 .. 9, 'a' .. 'f'); ' range operator returns a list, so it can be used to initialize an array. this will initialize to 16 hexadecimal digits
- ' say q(Hello, World!); ' quote operator 'q()' will function just like quotation marks around a string 
- ' say q(Hello, \n"World"!); ' can use quotation marks or new line character '\n' within 'q()' without escaping the characters and they will output to the console as normal characters  
- ' say qq(Hello, \n"World"!); ' this is the double quote interpolation operator and the newline character will function as normal, interpolating any following as a new line
- Perldoc has more information on the quote operators "perldoc -f q" at command line

Regular Expressions
- ' my $s = "This is a line";  if ($s ~= /line/){ say "True";} else { say "False";} ' binding operator '=~' used to find matches for regular expressions
- ' my $re = qr/line/; say $s =~ $re ? 'True : 'False'; ' binding operator '~=' can also be used in a ternary conditional statement, 'qr{}' is quote operator for regular expressions
- ' my $s = "This is a LINE";  if ($s ~= /line/i){ say "True";} else { say "False";} ' modifier 'i' following will ignore case when looking for a matching instance
- ' say foreach $s =~ /i/g; ' global modifier 'g' will return all instances  
- ' $s = "text\nmore text"; my $re = qr/t.m/s; say $s =~ $re ? 'True : 'False'; ' modifier 's' allows it to search the whole string, without it the search would not find any instances of a match as it would search only to the end of the line
- ' $s = "text\nmore text"; my $re = qr/^m/m; say $s =~ $re ? 'True : 'False'; ' modifier 'm' allows it to treat the string as multi-line, this allows it to return True in this instance (the 's' modifier or modifier being left blank would not work in this case)
- ' $s = "text\nmore text"; my $re = qr/^m  .*  text/mx; say $s =~ $re ? 'True : 'False'; ' modifier 'x' causes regex to ignore white space in the regular expression which can make it more human readable
- Modifiers found via "https://perldoc.perl.org/perlre.html#Modifiers"
- ' my $s = "This is a line"; my $re = qr/(line)/; say $s =~ $re ? "match is $1" : "False"; ' the use of parentheses allows for variable capture a la sed capture
- ' my @array = $s =~ /i(.)/g; say foreach @array; ' the matches will be captured as a list which can be used to intialize an array. This can capture a list of matches
- ' $s = "This is aaa line"; my $re = qr/a{3}/; say $s =~ $re ? "True" : "False"; ' The number in curly braces specifies repeat instances of the match criteria
- ' "[A-Z]{1,2}[0-9]{1,2}[A-Z]?\s[0-9][A-Z]{2}\b"; ' match criteria for a UK postcode based on above rules. {1,2} denotes match based on either one or two characters
- ' $s = "This is aaaaa line"; my $re = qr/(a{3,})/; say $s =~ $re ? "match is: $1" : "False"; ' The '{3,}' specifies 3 or more, so capture will capture a string all five a's
- ' my $re = qr/t.xt/; ' the dot indicates any character can be in this position
- ' my $re = qr/(t+)/; ' the + indicates matching one or more instances of the preceding character
- ' my $re = qr/(lin*)/; ' the * indicates 0 or more matches of the preceding character, will thus capture 'li' 'lin' or 'linnnnn' 
- ' my $re = qr/line (.*)/; ' the (.*) captures everything up until the end of the string (or line) given.
- ' my $s = "This is a line of text"; my $re = qr/(l.*e)/; ' the (.*) wildcard is naturally greedy will capture everything up until the last 'e' in (in text). $1 = "line of te" 
- ' my $s = "This is a line of text"; my $re = qr/(l.*?e)/; ' the (.*?) specifies not to be greedy and capture will stop at the first 'e'. $1 = "line"
- '\s' will match any whitespace character including spaces, tabs and new lines, form feeds and vertical tabs. '\S' will match anything that's not whitespace 
- ' my $s = "This is a line"; if ( my @a = $s =~ /(\S)/g ) { say foreach @a; } else { say "False"; } ' will store individual letters as scalars the array
- ' my $s = "This is a line"; if ( my @a = $s =~ /([a-zA-Z]+)/g ) { say foreach @a; } else { say "False"; } ' would capture all strings only composed of upper and lowercase letters (words) as scalars in the array
- ' my $s = "This (is a) line"; if ( $s =~ /(\(.*\)/g ) { say "Match is: $1"; } else { say "False"; } ' escaping the parentheses does the opposite to sed capture, allows parentheses to be matched/captured in the regex input. this would output 'Match is: (is a)'
- ' { } [ ] ( ) ^ $ . | * + ? \ ' regex meta characters all need to be escaped (single backslash) if they are going to be used within a pattern match
- ' my $s = "This is a line"; $s =~ s/line/string/; say $s; ' substitution command, will output "This is a string"
- ' my $s = "This is a line"; $s =~ s/(l\w+)/$1 $1 $1/; say $s; ' Uses word matching class "\w" == "[a-zA-Z]" will output "This is a line line line"
- ' my $n = 1234567890; while ( $n =~ s/^(-?\d+)(\d{3})/$1 $2/ ) {}; say $n; ' wilFsl run a while loop until it finds unbroken last 4 digits of a numerical string, then will insert a comma between the last 4 digits and former digits 
- ' my $s = "This is a line"; my @a = split(/\s+/, $s); say foreach @a; ' keyword 'split()' splits the strings on the delimiter given within the regex, delimiter can be multi-character and anything that can be put into a regular expression
- ' my $s = "This is a line"; say foreach split(/\s+/, $s); ' same code written in a different way

References
- ' $refs = \$scalar; ', ' $refa = \@array; ', ' $refh = \%hash; ', ' $reff = \&function; ' To obtain memory addresses for all of the following types. 
- ' ${$refs} ', ' @{$refa} ', ' %{$refh} ', ' &{reff} ' To dereference and obtain the value stored in a reference, must use appropriate symbol and dereference operator '{}'
- ' $refa->[1] ', ' $refh->{key} ', ' $reff->() ' The dereference arrow operator is used to dereference and access structure members 
- ' my @array  = qw( one two three ); my $refa = \@array; say foreach @{refa}; ' storage of array address and use of dereference operator to access the values. In fact in many cases the curly braces can be omitted and it is enough to specify the type of data stored in the reference to access the value i.e. 'say foreach @refa;' However in ambiguous cases, the curly braces are needed, so should be used in standard practice
  - ' push @{refa} ' can dereference to access normal array/hash functions of the reference 
- ' my $refa = [ qw( one two three ) ]; say foreach @{$refa}; ' Reference can be initialised from an anonymous array. The square brackets around the list initializes a list as an anonymous array. However a reference cannot be created directly from a list.
- ' my $refa = [1, 2, 3 ]; ${$refa}[0] = "one"; say foreach @{$refa}; ' Reference again being initialised from an anonymous array, first position being altered 
- ' my %hash = ( one => "uno", two => "dos" ); my $ref = \%hash; foreach my $k( sort keys %{ref}) { say "$k : ${$ref}{$k}"; } ' Reference pointing to hash, use of dereference operator
  - ' ${ref}{one} = 1; ' uses dereference operator and key to alter the contents of the hash lookup table
  - ' $ref->{one} = 1; ' uses dereference arrow operator and key to alter the contents of the hash lookup table 
- ' my $ref = \&func; &{$ref}(); sub func { say "That func."; } ' ampersand (&) used to reference a function (called func), function call by dereference operator
  - ' $ref->(); ' function call by use of dereference arrow operator
- ' my $ref = sub { say "No name func"; }; $ref->(); ' initialisation with an anonymous function, call by dereference arrow operator
- ' my $ref = func(); $ref->func(); sub func { return sub { say "Anonymous func."; } ; } ' anonymous functions can be passed like scalars and so this function can return an anonymous function which is used to initialise the reference. Conditionals could be added within this function call to initialise different anonymous functions to the reference based on different conditions.
- See Ch11/closure.pl for more on the return of anonymous functions and potential use-cases. 
- 'ref' is a keyword which will display the type of structure currently being pointed to by the reference
  - ' my $refa = [1, 2, 3]; say "ref($refa)"; ' will print 'ARRAY'
  - ' my $refh = { one=>1, two=>2 } ; say "ref($refh)"; ' will print 'HASH'
- References allow the mixing of different types of data in one data structure. See the mixed.pl and mixed-working.pl files in Ch11. As another example
  - ' my $musicians = []; ' creates a reference using an anonymous array
    - ' push @{$musicians}, { name => 'Jimi H', instrument => 'Guitar'}; ' - Pushes an anonymous hash into the anonymous array.
      - ' foreach my $m ( @{$musicians} ) { say "$m->{name}: $m->{instrument}" } ' - dereferences array, then accesses hash via use of dereference arrow operator 
    - ' push @{$musicians}, { name => 'Sonny Boy W', instrument => ['Harmonica', 'Vocal'] }; ' - can also place anonymous array as value of hash, creating larged branched data structure
      - ' foreach my $m ( @{$musicians} ) { my $inst = ref($m->{instrument}) eq 'ARRAY' ? join('/', @{$m->{instrument}}) : $m->{instrument}; say "$m->{name}: $inst"; '
        - The command 'my $inst = ref($m->{instrument}) eq 'ARRAY' ? join('/', @{$m->{instrument}}) : $m->{instrument}; ' 
          - first uses ref() to get the type of value held in the key (e.g. 'ARRAY', 'HASH')
          - then uses a ternary conditional operator to check if it is an ARRAY 
          - if an array it uses join(), which takes two arguments, the 2nd argument being the anonymous array obtained by reference. 
          - It joins them using the first argument as a separator to return a scalar. 
          - If not an array my $inst is set to the value in $m->instrument
        - The scalar $inst therefore replaces the value of the hash in the output statement.
- ' my $self = {}; ' initializes variable as a reference 

Built-In Functions
- ' my @a = (1, 2, 3); say @a; ' will output a '123', with the newline character at the end of the array  
  - ' $, =  ', '; my @a = (1, 2, 3); say @a; ' can introduce a separator with use of the "$, =" command, separator for variables in this case will be ", "  
  - ' $, =  ', '; my @a = (1, 2, 3); my %h = (one => 1, two => 2, three => 3); say @a, %h; ' will then output all members of array and hash in turn, with separator
  - ' my @a = (1, 2, 3); my %h = (one => 1, two => 2, three => 3); say join ', ', @a, %h; ' will output the same result as that above, joining all members into a scalar, separated by ", " 
  - The 'join' verrsion above as it only changes the output of one function whilst the $, is the equivalent of bash $IFS and will be output by all other 'print' and 'say' functions
- ' say STDOUT "Hello, World!"; ' standard output, is the default output stream
- ' say STDERR "Hello, World!"; ' standard error output - output text highlight in red 
- ' my $cond = 0; if ($cond) { say "True"; } else { die "False."; } ' die command throws an exception and stops the script, returning script and line number of the failure (+ message)
- ' my $string = "This string has a bunch of useful characters in it."; substr($string, 5, 10, "foo"); say $string; ' see perldoc -f substr
  - ' say index $string, "in", 10; ' will return the offset position (index) that the substr has been found at (last argument is starting position in string)
  - ' say rindex $string, "in", 10; ' same command as above but will serch from right-to-left from starting position as opposed to left-to-right.
  - ' say scalar reverse($string); ' will reverse the input scalar, in this case will reverse the letters of the string given
  - ' say reverse(1, 2, 3); ' The usual version of reverse will not reverse the elements of a scalar but will reverse elements in a list or array
  - Also see: perldoc.perl.org/index-functions-by-cat.html
- Time functions are inherited from the underlying C standard library that Perl is built from
  - ' time(); ' returns current time in seconds
  - ' localtime(); ' returns the time in standard UNIX format for time strings. argument is any integer variable, will return date format (with 0 == Thu Jan  1 01:00:00 1970) 
  - See time.pl for manipulation of date format
  - ' use POSIX qw( strftime ); my $time_now = strftime("%A, %B %d, %Y, %H:%M:%S", localtime()); say $time_now; ' prints international ISO standard, 'strftime' formats date and time 
- ' undef $x; ' assigns an undefined value to a variable (essentially NULL), can also be " $x = undef; "

Modules 
- Modules are generally available on CPAN (Comprehensive Perl Archive Network)
- ' package BW::Simple ' used to declare a module, will search directory tree structure for folders, in this case would look in local folder as no path has been specified (found in Ch14 folder)
  - Module files suffixed with .pm instead of .pl (seen in /Ch14/BW/ )
  - Simple.pm/Better.pm provide a way of generating object-oriented programming structures and functions
    - ' sub new { my $inv = shift; ... } ' new() function to set up data structure for the object/class.
    - ' ... my $inv = shift; my $class = ref(inv) || $inv; ... ' When a constructor is called the name of the class is passed to it as the first argument, shift reads this 
    - ' ... my $self = {}; ... ' creates a reference 
    - ' my $inv = shift; my $class = ref(inv) || $inv; my $self = {}; bless($self, $class); ' bless takes reference 1st and classname 2nd. Creates ref as object of classsname, returns ref
      - See perldoc -f bless 
      - ' ... bless($self, $class); $self->{number} = shift || 0; ' most objects use a hash to store their object data, this second shift obtains the actual argument passed to new(47) 
- ' use Carp; ' default installation contains flexible error reporting module called Carp
  - ' carp "Error message"; ' provides a little more information than the die() function, returns stack trace with function calls, but does not raise assertion
  - ' croak "Error message"; ' returns the samestack trace information as carp function but raises an assertion and ends script as 'die' keyword.


