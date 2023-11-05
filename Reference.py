Keywords and syntax (all double quotation marks can be replaced with single quotes):
- ' type(a) ' returns the type assigned to variable a ' print(type(a)) ' to display the result
- ' a = 16; a = 16.0 ' will automatically reassign type from int to float 
- ' len("string") ' returns the character length of a string
- ' mystring = "hello"; mystring[3] ' returns the character at index position 3
- ' mystring[3:6] ' returns the characters at index positions 3, 4 and 5 (not 6)
- ' mystring ' returns all index positions from beginning to end
- ' mystring[::2] ' returns all index positions from beginning to end with stepsize 2
- ' mystring[2:10:2] ' returns all index positions from 2 to (not including) 10 with stepsize 2
- ' mystring[::-1] ' returns characters in reverse order
- ' mystring[1:] ' returns all index positions from 1 to end 
- ' mystring = "no " + "way" '  the '+' operator acts as a string concatenator
- ' mystring.upper ' returns the details of the function, in this case returning name and memory address
- ' mystring.upper() ' converts to lower case
- ' mystring.split() ' splits string on default field separator in this case a space
- ' mystring.split("o") ' splits string on the field separator specified in the argument
- ' mylist = ['a'.'b'.'c']; ''.join(mylist) ' output 'abc'
- ' mylist = ['a'.'b'.'c']; ' '.join(mylist) ' output 'a b c'
- ' myname = "Jose"; print("Hello" + myname) '  string interpolation for printing
  The format() method shown below is useful for string interpolation
- ' print("This {} was {} via string {}".format("string","created","interpolation")
- ' print("The {2} {1} {0}".format("fox","brown","quick")) '  
- ' print("The {0} (0} {0}".format("fox","brown","quick")) '
- ' print("The {q} (b} {f}".format(f="fox",b="brown",q="quick")) ' can be indexed and accessed via key
  The format() method also allows to pass a float as an argument following "{value:width.precision f}"
- ' result = 100/7; print("The result was {}".format(result)) ' can interpolate floats into string
- ' print("The result was {r:10.3f}".format(r=result)) ' width=column width, .3f = number of d.p
- ' print("The result was {r:10.3}".format(r=result)) ' width=column width, .3 = sig fig
  Using an f-string or 'formatted string literal' can pass an argument directly into the string itself
- ' name = "Jose"; age = 10; print(f"Hello {name}, you are {age} years old.") '  
  Pass !r to get the string representation
- ' name = 'Fred'; print(f"He said his name is {name!r}") ' He said his name is 'Fred'
- ' print("I'm going to inject %s here." %'something') ' You can use %s to inject strings into your print 
statements. The modulo % is referred to as a "string formatting operator
- ' print("I'm going to inject %s text here, and %s text here." %('some','more')) ' You can pass multiple items 
by placing them inside a tuple after the `%` operator.
- ' x, y = 'some', 'more' print("Inject %s text here, and %s text here."%(x,y)) ' can also pass variable names
  %s and %r convert any python object to a string using two separate methods: str() and repr(). We'll learn more 
  about these functions later on in the course, but you should note that %r and repr() deliver the string 
  representation of the object, including quotation marks and any escape characters.
- ' print('He said his name was %s.' %'Fred') ' He said his name was Fred. 
- ' print('He said his name was %r.' %'Fred') ' He said his name was 'Fred'.
- ' print('I once caught a fish %s.' %'this \tbig') ' I once caught a fish this 	big.
- ' print('I once caught a fish %r.' %'this \tbig') ' I once caught a fish 'this \tbig'.
  %s operator converts whatever it sees into a string, including integers and floats. The %d operator converts 
  numbers to integers first, without rounding.
- ' print('I wrote %s programs today.' %3.75) ' I wrote 3.75 programs today.
- ' print('I wrote %d programs today.' %3.75) ' I wrote 3 programs today.
  Floating point numbers use the format %5.2f. Here, 5 is the minimum number of characters the string should 
  contain; these may be padded with whitespace if the number does not have this many digits. Next to this, 
  .2f stands for how many numbers to show past the decimal point.
- ' print('Floating point numbers: %5.2f' %(13.144)) ' Floating point numbers: 13.14
- ' print('Floating point numbers: %1.0f' %(13.144)) ' Floating point numbers: 13
- ' print('Floating point numbers: %1.5f' %(13.144)) ' Floating point numbers: 13.14400
- ' print('Floating point numbers: %10.2f' %(13.144)) ' Floating point numbers:      13.14
- ' print('Floating point numbers: %25.2f' %(13.144)) ' Floating point numbers:                     13.14
- ' print('First: %s, Second: %5.2f, Third: %r' %('hi!',3.1415,'bye!')) ' First: hi!, Second:  3.14, Third: 'bye!'
  By default .format() aligns text to the left, numbers to the right. You can pass an optional <,^, or > to set a left, center or right alignment
- ' print('{0:8} | {1:9}'.format('Fruit', 'Quantity')); print('{0:8} | {1:9}'.format('Apples', 3.)); print('{0:8} | {1:9}'.format('Oranges', 10)) '
		Fruit    | Quantity 
		Apples   |       3.0
		Oranges  |        10
- ' print('{0:<8} | {1:^8} | {2:>8}'.format('Left','Center','Right')); print('{0:<8} | {1:^8} | {2:>8}'.format(11,22,33)) '
		Left     |  Center  |    Right
		11       |    22    |       33
- ' print('{0:=<8} | {1:-^8} | {2:.>8}'.format('Left','Center','Right')); print('{0:=<8} | {1:-^8} | {2:.>8}'.format(11,22,33) '
		Left==== | -Center- | ...Right
		11====== | ---22--- | ......33		
- ' print('This is my ten-character, two-decimal number:%10.2f' %13.579) ' This is my ten-character, two-decimal number:     13.58
- ' print('This is my ten-character, two-decimal number:{0:10.2f}'.format(13.579)) ' This is my ten-character, two-decimal number:     13.58
  with f-strings, *precision* refers to the total number of digits, not just those following the decimal. f-strings do not pad to the right of the
  decimal, even if precision allows it
- ' num = 23.45678; print("My 10 character, four decimal number is:{0:10.4f}".format(num)) ' My 10 character, four decimal number is:   23.4568
- ' num = 23.45678; print(f"My 10 character, four decimal number is:{num:{10}.{6}}") ' My 10 character, four decimal number is:   23.4568
  you can always use .format() method syntax inside an f-string
- ' num = 23.45; print("My 10 character, four decimal number is:{0:10.4f}".format(num))) ' My 10 character, four decimal number is:   23.4500
- ' num = 23.45; print(f"My 10 character, four decimal number is:{num:{10}.{6}}") ' My 10 character, four decimal number is:     23.45
  Lists are ordered types that can hold a variety of objects 
- ' my_list = [1,2,3] ' regular list of integers
- ' my_list = ['String',100,23.2] ' can have a list of mixed data types where first is a string, second an int, and third a float
  same array accessor operators as a string
- ' my_list = ['String',100,23.2]; my_list[0] = 'new' ' will change/mutate the data in element 0 to 'new'
- ' my_list.append('ten') ' will append the new element to the last posuition in the list
- ' popped item = my_list.pop() ' .pop() will remove the last element in the list, returns the element removed
- ' popped.item = my_list.pop(1) ' pop() accepts an argument of index position, will remove element at index position 1, returns element removed 
- ' my_list = [1,2,3]; my_list + ['new_item'] ' '+' operator will concatenate lists as it does with strings, usd variable or list object directly
- ' my_list * 2 ' will duplicate the items in a list and concatenate the two lists i.e. [1,2,3] => [1,2,3,1,2,3]
- ' num_list = [4,1,8,3]; num_list.sort() ' unlike most methods does not return any value(s)
- ' lst_1=[1,2,3]; lst_2=[4,5,6]; lst_3=[7,8,9]; matrix = [lst_1,lst_2,lst_3]; print(matrix) ' [[1, 2, 3], [4, 5, 6], [7, 8, 9]] creates 3x3 matrix
actually arranges in form [0][0] = 1, [0][1] = 2, [0][2] = 3 therefore 1,2,3 = col 1, 1,4,7 = row 1
C1 C2 C3
1  4  7  R1  
2  5  8  R2
3  6  9  R3
- ' print(matrix[0]); print(matrix[0][0]) ' typical accessors for multidimensional lists
- ' print([el[0] for el in matrix]) ' where el is a variable asssigned to hold the columns of the matrix
pyt- ' print(matrix[0:][1]) ' prints 2nd row of matrix (R2 above)
- ' print(type(num_list.sort())) ' will return type NoneType
- ' None ' appears to be python equivalent of null
  Dictionaries are like perl hashes - like unordered lists indexed by key, use curly braces instead of square brackets
- ' my_dict = {'key1':'value1','key2':'value2'} '  
- ' prices_lookup = {'apple':2.99,'oranges':1.99,'milk':5.80}; print(prices_lookup['apple']) ' will output 2.99, accessor uses array operator square brackets 
- ' my_dict = {'k1':123,'k2':['a','b','c'],'k3':{'insideKey':100}}; print(my_dict['k3']['insideKey']); print(my_dict['k2'][1]) ' will output 100 
- ' print(my_dict.keys()) ' dict_keys(['k1', 'k2', 'k3']) is the output from the command
- ' my_dict['key1'] = my_dict['key1'] - 123 ' does arithmetic logic on the value in my_dict['k1']
- ' my_dict['key1'] -= 123 ' does arithmetic logic on the value
- ' d = {} ' 
``- ' d = {'key1':{'nestkey':{'subnestkey':'value'}}}; print(d['key1']['nestkey']['subnestkey']) ' 
- ' d = {'key1':1,'key2':2,'key3':3} ' 
- ' d.keys() ' 
- ' d.values() '
- ' d.items() '
  Tuples are similar to lists with a key difference being immutability. Once an element is inside a tuple it can't be reassigned, they use parenthesis (1,2,3) 
- ' t = (1,2,3); print(type(t)) ' will print the type as a tuple
- ' t = ('one',2,3,4); print(t[-1]) ' will return last element of the array. otherwise usual array accessors i.e print(t[1]) outputs 2  
- ' t = ('one',2,3,4); t[0] = 'change'; t.append('grow'); ' both of the operations following instantiation are invalid, tuples are immutable  
- ' t.count('one') ' 
  Sets are unordered collection of unique elements 
- ' myset = set(); myset.add(2); myset.add(1); myset.add(2); print(myset) ' .add() adds to set outputs {1, 2}  
- ' mylist = [1,1,1,1,2,2,2,2,3,3,3,3,3]; set(mylist) ' outputs {1, 2, 3}
  Booleans or True/False variables are capitalised in python
- ' print(type(1 < 2)) ' returns bool
- ' print(1 < 2) ' returns True
  Reading and writing to a file
- ' my_file = open('newfile.txt','w+') ' opens a file, w+ argument means write over the file
- ' my_file = open('newfile.txt','a+') ' opens a file, a+ argument means append to the file
- ' my_file = open('newfile.txt') ' opens a file for reading
- ' my_file.seek(0); print(my_file.read()); my_file.close() ' sets cursor to start of file for reading, reads lines, closes file
- ' my_file.seek(0); lines = my_file.readlines(); my_file.close() ' 
   open(file, mode='r', buffering=-1, encoding=None, errors=None, newline=None, closefd=True, opener=None) ' defaults when open is called, possible arguments
- ' with open('myfile.txt',mode='r') as myfile:
        contents = myfile.read() '
- ' with open('myfile.txt',mode='a') as f:
        f.write('\nFOUR ON FOURTH') '
  'and', 'or' 'not' are keywords reserved for logical 'and' 'or' 'not'		
- ' print(1 < 2 and 2 < 3) ' 'and' is a keyword = logical 'and' will output True 
  if, elif, else syntax followed by colon i.e.
- ' if hungry == True:
        print('feed me') '
  for loops can use variable assignement i.e.
- ' for item_name in my_list:   
        print(item_name) '
- ' mylist = [(1,2),(3,4),(5,6),(7,8)]; len(mylist) ' will output 4, then prints tuples
    for (a,b) in mylist:
	    print(a)
		print(b)  ' doesn't necessarily need paranthesis in for statement  
    loops use the same syntax as if/elif statements, and can pair else statements
- ' while x < 5:
        print(f'The current value of x is {x}'}
		x += 1 
	else:
	    print("x is not less than 5") ' 
  break, continue, and pass statements  add additional functionality for various cases
  break: Breaks out of the current closest enclosing loop.
  continue: Goes to the top of the closest enclosing loop.
  pass: Does nothing at all.
- ' mystring = 'Sammy' 
    for letter in mystring:
        if letter == 'a':
		    continue  
	    print(letter)  ' will output 'S' 'm' 'm' 'y'
- ' while x < 5:
        print(x); x+= 1	'	
  range syntax is 'range(stop)' -> range object, range(start, stop[, step]) -> range object
- ' for num in range(10):
        print(num) ' will output 0 1 2 3 4 5 6 7 8 9  		
- ' for num in range (3,10):
        print(num) ' will output 3 4 5 6 7 8 9		
- ' for num in range(0,11,2):
        print(num) ' will output 0 2 4 6 8 10
- ' print(range(0,11,2)) ' will output ' range(0, 11, 2) as is a generator
- ' print(list(range(0,11,2))) ' will output [0, 2, 4, 6, 8, 10]
- ' index_count = 0
    for letter in 'abcde':
	    print('At index {} the letter is {}'.format(index_count,letter)) '
- ' word = 'abcde'
    for index_count in enumerate(word):
        print(word[index_count])
        index_count += 1 '
- ' word = 'abcde'
    for index,letter in enumerate(word):
        print(index)
        print(letter)
        print('\n')	
- ' mylist1 = [1,2,3]; mylist2 = ['a','b','c']; print(zip(mylist1,mylist2)) '
- ' print(zip(mylist1,mylist2)) '
- ' for item in zip(mylist1,mylist2):
        print(item) '
- ' list(zip(mylist1,mylist2)) '
- ' print('x' in [1,2,3]) ' returns False
- ' print('x' in ['x','y','z']) ' returns True
- ' print('a' in 'a world ') ' returns True
- ' print('mykey' in {'mykey':345})
- ' d = {'mykey':345}; print(345 in d.keys()) ' returns False
- ' mylist = [10,20,30,40,100]; min(mylist); max(mylist) '
- ' from random import shuffle as _shuffle; mylist = [1,2,3,4,5]; _shuffle(mylist); print(mylist) '  
- ' from random import *; mylist = [1,2,3,4,5]; shuffle(mylist); print(mylist) '  
- ' print(randint(0,100)) '
- ' input('Enter a number: ') '
- ' result = int(input('Enter a number: ')); print(type(result)) '
- ' result = float(input('Enter a number: ')); print(type(result)) '
- ' result = input('Enter a number: '); print(type(result)) '
- ' mystring = 'hello'; mylist = []
    for letter in mystring:
	    mylist.append(letter); print(mylist) ' output: ['h', 'e', 'l', 'l', 'o']
- ' mystring = 'hello'; mylist = [letter for letter in mystring]; print(mylist) '	
- ' mylist = [num**2 for range(0,11); print(mylist) ' [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
- ' celsius = [0,10,20,34.5]; fahrenheit = [((9/5)*temp + 32) for temp in celsius]; print(farenheit) ' [32.0,50.0,68.0,94.1] 
- ' results = [ x if x%2==0 else 'ODD' for x in range(0,11)]; print(results) ' 
- ' mylist = []
    for x in [2,4,6]:
	    for y in [1,10,1000]:
		    mylist.append(x*y)
    print(mylist)			' 
- ' mylist = [x*y for x in [2,4,6] for y in [1,10,1000]] '	 
  Methods and Functions, built in objects have a variety of methods you can use 
- ' help([].insert) ' will bring up a help page a la a man page for a method, best used at command line not in script  
  http://docs.python.org/3/library/index.html - Python standard library documentation has a list of variable types, methods  
  and functions that can be used woth the python library
- ' def namef_of_function():
        ""
        Docstring explains the purpose of the function
		""
		print("Hello") # function's purpose
	
	name_of_function() '  #  calls the function in the main script, generally uses snake-casing, words separated by underscore
- ' def name_function():
        '''
        DOCSTRING: Information about the function   
        INPUT: No input...
        OUTPUT: prints hello
        '''

        print('hello')

    >>> from file import name_function
	>>> name_function()    # function call
    >>>	help(name_function)   # will show function help text defined in script file '
- ' def myfunc(*args):    # keyword args can be replaced with any keyword one wishes, but is an arbitrary choice
        print(args)   # appears as a tuple
        return sum(args) * 0.05	
		
	myfunc(40,60,100,1,34) '  The number of args specified is unlimited
- ' def myfunc(**kwargs):    #assumes keyword args is passed in as a dict
        print(kwargs)
		if 'fruit' in kwargs:
		    print('My fruit of choice is {}'.format(kwargs['fruit']))
		else:
		    print('I did not find any fruit here')   
			
	myfunc(fruit='apple',veggie = 'lettuce') '  #
- ' def myfunc(*args,**kwargs):
        print(args)
		print(kwargs)
        print('I would like {} {}'.format(args[0],kwargs['food']))
		
	myfunc(10,20,30,fruit='orange',food='eggs',animal='dog')  ' 
- ' abs(num) ' returns the absolute value of a number	
  Lambda expressions map and filter
  map(func, *iterables) --> map object. Makes an iterator that computes the function using arguments from each of the
  iterables. Stops when the shortest iterable is exhausted.
- ' def square(num):
        return num**2
    my_nums = [1,2,3,4,5]
    print(map(square,my_nums))   #	shows info <map at 0x2a6368cad> (memory address)
	for item in map(square,my_nums):
	    print(item) '   will output 1\n 4\n 9\n 16\n 25\n
- ' print(list(map(square,my_nums))) ' will output list [1, 4, 9, 16, 25]
  filter(function or None, iterable) --> filter object. Return an iterator yielding those items of iterable for which
  function(item) is true. If function is None, return the items that are true
- ' def check_even(num):
        return num%2 == 0
	mynums = [1,2,3,4,5,6]
	print(list(filter(check_even,mynums))) ' output: [2, 4, 6]
- ' for n in filter(check_even, mynums):
		print(n)	' output 2\n 4\n 6\n
- ' square = lambda num: num ** 2; square(3) ' lambda functions are anonymous functions which can be assigned as shown
- ' mynums = [1,2,3,4,5,6]; print(list(map(lambda num:num**2,mynums))) '  more common use of lambda function
     output: [1, 4, 9, 16, 25, 36] 
- ' mynums = [1,2,3,4,5,6]; print(list(filter(lambda num:num%2 == 0,mynums))) ' output: [2, 4, 6]
- ' names = ['Ben', 'Adam', 'Sally']; print(list(map(lambda x:x[::-1],names))) '
  Local vs. Global scoping
- ' x = 50
    def func(x):
	    print(f'X is {x}')
		
		# LOCAL REASSIGNMENT
		x = 200 
		print(f'I JUST LOCALLY CHANGED X TO {x}')		
	func(x)    # output here shows x in the local scope of the function as 200
	print(x) ' # output here shows x at the global scope remains unchanged and outputs 50
- ' x = 50a
    def func():
	    global x
	    print(f'X is {x}')
		
		# LOCAL REASSIGNMENT
		x = 200 
		print(f'I JUST LOCALLY CHANGED X TO {x}')		
	func()     # output here shows x in the local scope of the function as 200
	print(x) ' # output here shows x at the global scope has changed and outputs 200
  Python supports OOP and can be used to instantiate objects such as classes
- ' class NameOfClass:
        def __init__(self,param1,param2):
		    self.param1 = param1
			self.param2 = param2
			
		def some_method(self):
		    # perform some action
			print(self.param) '   # typical class syntax in python
- ' class Sample():
        pass
		
	my_sample = Sample()
	print(type(my_sample)) '  # outputs " <class '__main__.Sample'> "
- ' class Dog():        
		species = 'mammal'
		
        def __init__(self,mybreed,myname,myspots):
            self.breed = mybreed 
	        self.name  = myname
			
			#Expect boolean True/False
			self.myspots
			
		# OPERATIONS/Actions ---> Methods
		def bark(self,age):
		    print("WOOF! My name is {} breed is {} and age is {}".format(self.name,self.breed,age))
		
	my_dog = Dog(mybreed='Lab',myname='Rex',myspots=True)
	print(type(my_dog))   # outputs " <class '__main__.Dog'> "
	print(mydog.breed) '  # outputs " 'Lab' "
  Inheritance and polymorphism represents a way to create new classes based on classes already defined  
- ' class Animal():
        def __init__(self):
		    print("ANIMAL CREATED")
		def who_am_i(self):
		    print("I am an animal")
		def eat(self):
		    print("I am eating")
			
	class Dog(Animal):
	    def __init__(self):
		    Animal.__init__(self)
            print("Dog Created")
			
	mydog = Dog()
    mydog.eat()
    mydog.who_am_i()	'  
- ' class Animal():
	    def __init__(self,name):
            self.name  = myname	
	
	    def speak(self):
            raise NotImplementedError("Subclass must implement this abstract method")

	class Dog(Animal):
	    def __init__(self):
		    Animal.__init__(self)
			
	    def speak(self):
		    return self.name + " says woof!"
			
	class Cat(Animal):
	    def __init__(self):
		    Animal.__init__(self)

	    def speak(self):
		    return self.name + " says woof!"
            
    fido = Dog("Fido")
    bast = Cat("Bast") 	'    
  Function overloading in class
- ' class Book():
        def __init__(self,title,author,pages):
            self.title = title
			self.author = author
			self.pages = pages 
			
	b = Book('Python rocks','Jose',200)
	print(b)  # output: <__main__.Book object at 0x0000025F50CBC888>
	str(b)  ' # output: <__main__.Book object at 0x0000025F50CBC888>
- ' class Book():
        def __init__(self,title,author,pages):
            self.title = title
			self.author = author
			self.pages = pages 
		def __str__(self):
		    return f"{self.title} by {self.author} at {self.pages} pages"
		def __len__(self):
		    return f"{self.pages}
		def __del__(self):   # object destructor	
			"A book object has been deleted"
			
	b = Book('Python rocks','Jose',200)	
    print(b)  # output: Python rocks by Jose at 200 pages 
	str(b)  ' # output: 'Python rocks by Jose at 200 pages' 
    len(b)  ' # output: 200
	del(b)  ' # output: A book object has been deleted        
  pip is a command line/command prompt/terminal utility
- ' pip install requests   # allows to request information from websiates 	
    pip install colorama   # allows to clorize text at the command promp/commandline
	pip install openpyxl   # python library ro read/write xlsx/xlsm files
- ' python  
    >>> from colorama import init()
	>>> init()
	>>> print(Fore.RED + "some red text")
	>>> print(Fore.GREEN + "some green text")
	>>> help()     # screen to interactive help on all commands, modules
  Can create own modules and packages, modules are .py scripts that you call in another .py
  script, whilst packages are a collection of modules
- ' cat mymodule.py
    >>#!/usr/bin/python3.6
	>>
	>>def my_func():
	>>    print("This is my function")
	cat myimport.py	
    >>#!/usr/bin/python3.6
	>>
	>>from mymodule import my_func
	>>
	>>my_func()
	./myimp* ' #will call function from mymodule if has rx permission
- ' mkdir mainpackage 
    mkdir mainpackage/subpackage 
	touch mainpackage/__init__.py
	touch mainpackage/subpackage/__init__.py   # these empty __init__.py files tell python 
	the directory is now a package and allows the user to run/import it
	vi mainpackage/some_main_script.py
	vi mainpackage/subpackage/mysubscript.py
	cat mainpackage/some_main_script.py	
    >>#!/usr/bin/python3.6
	>>
	>>def report_main():
	>>    print("Hey I am in some_main_script in main package.")
	cat mainpackage/subpackage/mysubscript.py    
	>>#!/usr/bin/python3.6
	>>
	>>def sub_report():
	>>    print("Hey Im a function inside mysubscript")
	cat myimport.py	
    >>#!/usr/bin/python3.6
	>>
	>>from mymodule import my_func
	>>from mainpackage import some_main_script
	>>from mainpackage.subpackage import mysubscript
	>>
	>>my_func()
	>>some_main_script.report_main()
	>>mysubscript.sub_report()
	./myimp* ' #will call functions if has rx permission
  if __name__ == "__main___": is an often used but confusing piece of python code, this is
  used to determine whether a module's function is being used as an import or if you are
  using the original .py file of that module.	
- ' cat one.py
    >>#!/usr/bin/python3.6
    >>
    >>def func():
    >>    print("FUNC() IN ONE.PY")
    >>
    >>print('TOP LEVEL IN ONE.PY')
    >>
    >>if __name__ == '__main__':
    >>    print('ONE.PY is being run directly!')
    >>else:
    >>    print('ONE.PY has been imported!')	
    cat two.py
    >>#!/usr/bin/python3.6
    >>
    >>import one
    >>
    >>print('TOP LEVEL IN TWO.PY')
    >>
    >>one.func()
    >>
    >>if __name__ == '__main__':
    >>    print('TWO.PY is being run directly!')
    >>else:
    >>    print('TWO.PY has been imported!')  '
	./one.py
	./two.py
	# the if __name__ == "__main___": output here shows if code is an import or not
  Exception handling is used to deal with errors when they occur within the code. 'try'
  'except', and 'finally' are used for exception handling in python
- ' def ask_for_int():
        try:
		    result = int(input("Please provide number: "))
		except:
		    print("Whoops! That is not a number")
		else:
		    print("Number entered successfully")
			print(result)
		finally:
		    print("End of try/except/finally")
	# typical structure od a try/except/finally block
- ' try:
        f = open('testfile','w')
		f.write("Write a test line")
	except TypeError:
	    print("There was a type error!")
	except OSError:
	    print("There was an OS error!")
	except:
	    print("All other exceptions!")
  'pylint' and 'unittest' are tools used for checking code. An example pylint output is given below
- # Contents of file simple1.py 
    >>a = 1
    >>b = 2
    >>print(a)
    >>print(B)
    C:\Users\Letetedelioncourt\Documents>pylint simple1.py

     ' ************* Module simple1
    simple1.py:4:0: C0304: Final newline missing (missing-final-newline)
    simple1.py:1:0: C0114: Missing module docstring (missing-module-docstring)
    simple1.py:1:0: C0103: Constant name "a" doesn't conform to UPPER_CASE naming style (invalid-name)
    simple1.py:2:0: C0103: Constant name "b" doesn't conform to UPPER_CASE naming style (invalid-name)
    simple1.py:4:6: E0602: Undefined variable 'B' (undefined-variable)

    -------------------------------------
    Your code has been rated at -12.50/10
  pylint will report back any possible issues and allow the user to fix them before going further
- ' def hello():
        return "Hello!"

    greet = hello 
    hello()    # returns the string 	
	hello 	   # returns memory address 
    greet()    # returns same string
    greet      # returns same memory address 

    del(hello) # appears to remove the association of the name with the memory space

    greet()    # returns the same string
    greet      # returns the same memory address
    hello()    # returns NameError: name 'hello' is not defined
    hello 	   # returns NameError: name 'hello' is not defined
  Functions can be defined inside of functions
- ' def hello(name='Jose'):
        print('The hello() function has been executed!')
     
        def greet():
            return '\t This is the greet() func inside hello!'
			
	    def welcome():
		    return '\t This is the welcome() function inside hello' 

        print(greet())
        print(welcome())
		print('This is the end of the hello function') '
- ' def hello(name='Jose'):
        print('The hello() function has been executed!')
     
        def greet():
            return '\t This is the greet() func inside hello!'
			
	    def welcome():
		    return '\t This is the welcome() function inside hello' 

        if name == 'Jose':
            return greet
        else:
            return welcome		
	my_new_func = hello('Jose') ' # output: The hello() function has been executed!
	print(my_new_func()) ' # output:        This is the greet() func inside hello!
- ' def cool():
        def super_cool():
		    return 'I am very cool!'
		return super_cool 
	some_func = cool()
	print(some_func) ' # output: function cool.<locals>.super_cool at 0x00000252...
- ' def hello():
        print('Hi Jose!')
    def other(some_def_func):
        print('Other code runs here!')
        print(some_def_func())
    other(hello)	' ' # output: Other code runs here!
                                  Hi Jose!	
- ' def new_decorator(original_func):
        def wrap_func():
		    print('Some extra code between the original function')
			original_func()
			print('Some extra code, after the original function!')
		return wrap_func
	def func_needs_decorator():
        print("I want to be decorated!!") 
	func_needs_decorator() 
	decorated_func = new_decorator(func_needs_decorator)
	decorated_func() ' # output: Some extra code between the original function
	                             I want to be decorated!!
								 Some extra code, after the original function!
- ' def new_decorator(original_func):
        def wrap_func():
		    print('Some extra code between the original function')
			original_func()
			print('Some extra code, after the original function!')
		return wrap_func		
	@new_decorator	
	def func_needs_decorator():
        print("I want to be decorated!!") 
	func_needs_decorator() ' # output: Some extra code between the original function
	                                   I want to be decorated!!
								       Some extra code, after the original function! 
  Generator functions allow us to write a function that can send back a value and then later resume to pick up
  where it left off. It acts as a generator in python allowing to generate a sequence of values
  over time. The main difference in syntax is the use of a yield statement. 
  When a generator function is compiled it becomes an object that supports an iteration
  protocol. So when they are called in your code they don't avctually return a value 
  then exit, thus instead of having to compute an entire series of values up front, the
  generator computes one value, waits until the next value is called for. The range()
  function for instance de=oesn't produce a list of numbers simply remembers the last number
  and the step size.
- ' def create_cubes(n):
        for x in range(n):     # generator function
		    return (x**3)	   # non-generator function
			
	for x in create_cubes(10):
	    print(x)   '
- ' def create_cubes(n):        
        for x in range(n):     # generator function
		    yield (x**3)       # generator function uses yield keyword as opposed to return
	for x in create_cubes(10):
	    print(x) '
- ' def gen_fibon(n):
        a = 1
        b = 1
		output = []
        for i in range(n):
            output.append(a)
            a,b = b,a+b
        return output '
- ' def simple_gen():
        for x in range(3):
		    yield x
			
	for number in simple_gen():   # old syntax
	    print(number)
	
    g = simple_gen()	
	print(next(g)) 	 #will yield/print 0
	print(next(g)) 	 #will yield/print 1	
	print(next(g)) 	 #will yield/print 2
    print(next(g)) ' #print: 
- ' for letter in s:
        print(letter)		
	next(s)    # will return a TypeError need to return an iterator to the string first
	s_iter = iter(s)
	next(s_iter)
	next(s_iter)
	next(s_iter)
  Collections is a built-in module that implements specialized container datatypes providing
  alternatives to Python's builtin containers.
  Counter is a dict subclass which helps count hashable objects. Elements are stored as dictionary
  keys and the counts of the objects are stored as the value.
- ' from collections import Counter
    x = [1,2,2,2,2,3,3,3,1,2,1,12,3,2,32,1,21,1,223,1]
	Counter(x)  # output: returns Counter({1: 6, 2: 6, 3: 4, 12: 1, 32: 1, 21: 1, 223: 1})
- ' s = "How many times does each word show up in this sentence word word show up up"
    words = s.split()
	Counter(words)   # output: Counter({'word': 3, 'up': 3, 'show': 2, 'How': 1, 'many': 1, 'times': 1, 'does': 1,
	'each': 1, 'in': 1, 'this': 1, 'sentence': 1})
	c.most_common(3) # output: [('word', 3), ('up', 3), ('show', 2)]
	sum(c.values())					# total of all counts
	c.clear()						# reset all counts
	list(c)							# list unique elements
	set(c)							# convert to a set
	dict(c)							# convert to a regular dictionary
	c.items()						# convert to a list of (elem, cnt) pairs
	Counter(dict(list_of_pairs))	# convert from a list of (elem, cnt) pairs
	c.most_common()[:-n-1:-1]		# n-least common elements
	c += Counter()					# remove zero and negative counts
  defaultdict is a dictionary like object which provides all methods provided by dictionary 
  but takes first argument (default_factory) as default data type for the dictionary. Using
  defaultdict is faster than doing the same using dict.set_default method - a defaultdict never 
  raises a KeyError. Any key that does not exist gets the value returned by the default factory.
- ' from collections import defaultdict
    d = {'k1':1}
	d['k1']      # output: 1
 	d['k2']      # output: KeyError: 'k2'
	d = defaultdict(object)
	d['k2']      # output: <object object at 0x00000252AFACF7B0>
- ' d = defaultdict(lambda: 0)
    d['one']     # output: 0
	d['two'] = 2 # output: 2
	d            # output: defaultdict(<function <lambda> at 0x00000252AFE88288>, {'one': 0, 'two': 2})
  An OrderedDict is a dictionary subclass that remembers the order in which its contents are added  
- ' from collections import OrderedDict.
    d = OrderedDict()
    d['e'] = 1	
    d['b'] = 2
    d['c'] = 3
    d['d'] = 4
    d['a'] = 5   # output:  e 1
							b 2
							c 3
							d 4
							a 5

- ' d1 = {}
    d1['a'] = 1
	d1['b'] = 2
	
	d2 = {}
    d2['b'] = 2
	d2['a'] = 1
	
	print(d1==d2) # output: True
	
	d1 = OrderedDict()
    d1['a'] = 1
	d1['b'] = 2
	
	d2 = OrderedDict()
    d2['b'] = 2
	d2['a'] = 1
	
	print(d1==d2) # output: False '
  A namedtuple assignd names as well as using a numerical index to accesss its members
- ' t = (1,2,3)
    t[0]
	from collections import namedtuple
	Dog = namedtuple('Dog','age breed name')
	tim = Dog(age=2,breed='Lab',name='Sammy')
	print(sam.age)   # output: 2
	print(sam[0])    # output: 2
  user can extract information from the datetime module
- ' import datetime
    t = datetime.time(5,25,1)
	print(t)                  # output: 05:25:01
	print(t.minute)           # output: 25
	print(datetime.time.min)  # output: 00:00:00
	print(datetime.time.max)  # output: 23:59:59.9999999
	print(datetime.time.resolution)  # output: 0:00:00.000001
	today = datetime.date.today()    
	print(today)              # output: 2020-04-25
	today.timetuple()         # output: time.struct_time(tm_year=2020, tm_mon=4, tm_mday=25, 
	tm_hour=0, tm_min=0, tm_sec=0, tm_wday=5, tm_yday=116, tm_isdst=-1)
	today.year                # output: 
	today.month               # output: 
	today.day                 # output:
	print(datetime.date.resolution) # output: 1 day, 0:00:00
	d1 = datetime.date(2015,3,11)    
	print d1						# output: 2015-03-11
	d2 = d1.replace(year=1990)      # output: 1990-03-11
	d1-d2   # output: datetime.timedelta(9131)
	print('ctime:', today.ctime())
	print('tuple:', today.timetuple())
	print('ordinal:', today.toordinal())
	print('Year:', today.year ())
	print('Mon:', today.month())
	print('ct', today.day())
  pdb is an interactive debugging environement use via cmdprompt ala gdb
- ' #!/usr/bin/python3.6
    import pdb
	
	x = [1,3,4]
	y = 2
	z = 3
	
	result = y+z
	print(result)
	
	pdb.set_trace()    # this activates pdb interactive trace
	    (Pdb) x     # returns variable value
        [1, 3, 4]
        (Pdb) y+z   # returns sum 		
        5
        (Pdb) x**2  # returns sum 		
        *** TypeError: unsupported operand type(s) for ** or pow(): 'list' and 'int'
        (Pdb) x+y		
        *** TypeError: can only concatenate list (not "int") to list						 
	result2 = y+x
	print(result2) '
  The timeit module provides a way to time small bits of Python code, has a CLI and a callable
  interface
- ' print("-".join([str(n) for n in range(100)]))
    timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)  # 0.25017623599887884
    timeit.timeit('"-".join([str(n) for n in range(100)])', number=10000)  # 0.20959569700062275
	timeit.timeit('"-".join(map(str, range(100)))', number=10000)  # 0.18049929100016016
  Regular Expressions are often used in Pythonyh 	
#A bloom filter is  lightweight version of a hash table. It allows for
#efficient insertions and lookups. It is more space efficient than a hash
#table, but comes at the cost of having "false positives" for entry lookup

#It is used when someone wants a data structure for fast lookups and insertion
#And also dont care if it sometimes indicates an item is present when it is not

#An example of this is running a website and wanting to keep track of Ip addresses that
#are blocked. Don't particularly care if a blocked IP address is occassionally able to
#access the website, but care if someone not on the blocked list is unable to access

#This implementation of a pokedex may give false positives, i.e. saying you have seen
#a pokemon before when you haven't

import pyhash

#A bloom filter has two components a bit vector, as implemented below
#And a non-cryptographic hash function (implemented by pyhash). It is basically a black
#box which will take in a pokemon and spit out  number we can use which will specify 
#where to turn on bits in the bit vector

bit_vector = [0] * 20
print(bit_vector)

# Non cryptographic hash functions (Murmur and FNV)
fnv = pyhash.fnv1_32()
murmur = pyhash.murmur3_32()

# Calculate the output of FNV and Murmur hash functions for Pikachu and Charmander.
fnv_pika = fnv("Pikachu") % 20
murmur_pika = murmur("Pikachu") % 20
fnv_char = fnv("Charmander") % 20
murmur_char = murmur("Chrmander") % 20

print(fnv_pika)
print(murmur_pika)
print(fnv_char)
print(murmur_char)

bit_vector[fnv_pika] = 1
bit_vector[murmur_pika] = 1
bit_vector[fnv_char] = 1
bit_vector[murmur_char] = 1

print(bit_vector)
----------------------
#Using a stack to determine whether a string has a balanced use of parentheses

#import class Stack() from file stack.py
from stack import Stack 

def is_match(p1, p2):
	if p1 == "(" and p2 == ")":
		return True
	elif p1 == "{" and p2 == "}":
		return True
	elif p1 == "[" and p2 == "]":
		return True

def is_paren_balanced(paren_string):
	s = Stack()
	is_balanced = True
	index = 0

	while index < len(paren_string) and is_balanced:
		paren = paren_string[index]
		if paren in "([{":
			s.push(paren)
		elif s.is_empty():
			is_balanced = False
		elif top := s.pop():
			if not is_match(top, paren):
				is_balanced = False
		index+=1
	
	if s.is_empty() and is_balanced:
		return True
	else:
		return False

print(is_paren_balanced("{({[]})}"))
print(is_paren_balanced("{({[]}){}}"))
print(is_paren_balanced("{({([]}){}})"))

-------------------------------------
#From stack.py file import Stack() class
from stack import Stack

#Using a stack data structure to convert integer values to binary

def div_by_2(dec_num):
	s = Stack()

	while dec_num > 0:
		remainder = dec_num % 2
		s.push(remainder)
		dec_num = dec_num // 2

	bin_num = ""
	while not s.is_empty():
		bin_num += str(s.pop())

	return bin_num

print(div_by_2(242))
-----------------------------------------
class Stack():
	def __init__(self):
		self.items = [] 

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def is_empty(self):
		return self.items == []

	def peek(self):
		if not self.is_empty():
			return self.items[-1] #last item in list

	def get_stack(self):
		return self.items

#s = Stack()
#print(s.is_empty())
#s.push('A')
#s.push('B')
#print(s.get_stack())
#s.push('C')
#print(s.get_stack())
#s.pop()
#print(s.get_stack())
#print(s.is_empty())

==> imperfecttictactoe.py <==
#!/usr/bin/python3.8
#Personal challenge: Using knowledge of python, produce a tictactoe game and a.i in less than 100 lines of code
from random import shuffle

play = True
def display_board(board):
    print(board[1]+'|'+board[2]+'|'+board[3])
    print(board[4]+'|'+board[5]+'|'+board[6])
    print(board[7]+'|'+board[8]+'|'+board[9])
    
def human_move(board):
    move = 100
    while move < 1 or move > 9:
        try:
            move = int(input('Enter a number [1-9]: '))
        except ValueError:
            move = 100
        if (move >= 1 and move <= 9 and board[move] == ' '):
            board[move] = 'x'
        else:
            print('Invalid move. Try again')
    add_to_paths(move,0)
    
def add_to_paths(move,player):
    global win_paths
    global best_move
    global assess_move
    for path in paths[move]:
        win_paths[player][path] += 1
        for x in (0,2):
            if (win_paths[x][path] > 0 and win_paths[x+1][path] > 0):
                win_paths[x][path] = -1
                win_paths[x+1][path] = -1
    for path in (1,2,3,4,5,6,7,8):
        if (win_paths[3][path] == 3):
            assess_move[0] += 1024
        if (win_paths[0][path] == 2 and win_paths[2][path] == -1):
            assess_move[0] += 64
        if (win_paths[3][path] == 2):
            assess_move[0] += 16
        if (win_paths[0][path] == 1 and win_paths[2][path] == -1):
            assess_move[0] += 4
        if (win_paths[3][path] == 1):
            assess_move[0] += 1            
        win_paths[3][path] = win_paths[1][path]
        win_paths[2][path] = win_paths[0][path] 
    if (assess_move[0] > assess_move[1]):
        assess_move[1] = assess_move[0]  
        best_move = [move]
    elif (assess_move[0] == assess_move[1]):
        best_move += [move]
    assess_move[0] = 0    
    
def computer_move(board):
    global best_move
    global assess_move
    for move in (1,2,3,4,5,6,7,8,9):
        if (board[move] == ' '):
            add_to_paths(move,3)
    shuffle(best_move)
    board[best_move[0]] = 'o'
    add_to_paths(best_move[0],1)
    assess_move = [0,0]
    
def game_over():
    space = 0
    for path in (1,2,3,4,5,6,7,8):
        if (win_paths[0][path] == 3):
            who_won[1] = True
        elif (win_paths[1][path] == 3):
            who_won[2] = True
        if (test_board[path] == ' '):
            space += 1
    if (space == 0 and test_board[9] != ' '):
        who_won[0] = True
    for x in (0,1,2):
        if (who_won[x] == True):
            print(f'{x}p won')
            return True
            
if (play == True):
    best_move = [0]
    assess_move = [0,0]
    paths = ['#',(1,4,7),(1,5),(1,6,8),(2,4),(2,5,7,8),(2,6),(3,4,8),(3,5),(3,6,7)] 
    test_board = ['#'] + [' '] * 9
    win_paths = [['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0]]#
#    wins = [['#'] + [0] *8] *4    # alternate syntax experiment
#    print(win_paths)
#    print(wins)
    display_board(test_board)
    who_won = [False,False,False]
    while (game_over() != True):
        human_move(test_board)
        if (game_over() == True):
            display_board(test_board)
            break
        computer_move(test_board)0
        display_board(test_board)
    play = input('Play again? (Y or N): ') == 'Y'       

==> nephewcoding-ataribreakout.py <==
from tkinter import *
import tkinter.messagebox
import time

window = Tk()
window.title("Atari Breakout")
canvas_width = 600
canvas_height = 500

def new_game():
    canvas = Canvas(window, width=canvas_width, height=canvas_height, )
    canvas.pack()
    
    puck = canvas.create_rectangle(170, 200, 180, 210, fill="green")
    paddle = canvas.create_rectangle(260, 470, 340, 480, fill="orange")
    
    def you_won():
        active = False
        canvas.destroy()
        PlayAgain = tkinter.messagebox.askyesno ("You Won!", "Do you want to play again?" )
        if PlayAgain:
            new_game()
        else:
            window.destroy()
            raise SystemExit()
            
    def game_over():
        active = False
        canvas.destroy()
        PlayAgain = tkinter.messagebox.askyesno("Game Over", "Do you want to play again?" )
        if PlayAgain:
            new_game()
        else:
            window.destroy()
            raise SystemExit()
            
    def hit_paddle(pos):
        paddle_pos = canvas.coords(paddle)
        if pos[2] >= paddle_pos[0] and pos[0] <= paddle_pos[2]:
            if pos[3] >= paddle_pos[1] and pos[3] <= paddle_pos[3]:
                return True
        return False
    
    def hit_brick(pos):
        for brick in bricks:
            brick_pos = canvas.coords(brick)
            if pos[2] >= brick_pos[0] and pos[0] <= brick_pos[2]:
                if pos[3]  >= brick_pos[1] and pos[1] <= brick_pos[3]:
                    canvas.delete(brick)
                    bricks.remove(brick)
                    return True
        return False
    
    def move_left(evt):
        pos = canvas.coords(paddle)
        if pos[0] > 0:
            canvas.move(paddle, -10, 0)
            
    def move_right(evt):
        pos = canvas.coords(paddle)
        if pos[2] < canvas_width:
            canvas.move(paddle, 10, 0)
            
    bricks = []
    
    for i in range(16):
        brick_top = 50
        brick_left = 60+30*i
        brick = canvas.create_rectangle(brick_left, brick_top, brick_left+20, brick_top+20, fill="red")
        bricks.append(brick)
    
    for i in range(10):
        brick_top = 90
        brick_left = 150+30*i
        brick = canvas.create_rectangle(brick_left, brick_top, brick_left+20, brick_top+20, fill="red")
        bricks.append(brick)
    
    for i in range(16):
        brick_top = 130
        brick_left = 60+30*i
        brick = canvas.create_rectangle(brick_left, brick_top, brick_left+20, brick_top+20, fill="red")
        bricks.append(brick)
        
    for i in range(10):
        brick_top = 170
        brick_left = 150+30*i
        brick = canvas.create_rectangle(brick_left, brick_top, brick_left+20, brick_top+20, fill="red")
        bricks.append(brick)
              
    canvas.bind_all("<KeyPress-Left>", move_left)
    canvas.bind_all("<KeyPress-Right>", move_right)
    
    px = 1
    py = 1
    active = True
    while active:
        canvas.move(puck, px, py)
        pos = canvas.coords(puck)
        if pos[1] <= 0: # if puck hits top of screen
            py = 4
        elif pos[3] >= canvas_height: #if puck hits bottom of screen
            active = False
        if pos[0] <=0:
            px = 4
        elif pos[2] >= canvas_width:
            px = -4
        
        if hit_paddle(pos):
            py = -4
           
        if hit_brick(pos):
            py = -py
            if (len(bricks) == 0):
                active = False
        
        window.update()
        time.sleep(.015)
            
new_game()

==> nephewcoding-shootergame.py <==
from tkinter import *
import tkinter.messagebox
import time
import random
import winsound

window = Tk()
window.title("Space Shooter")

img1 = PhotoImage(file="ship.png")
img2 = PhotoImage(file="missle_purple.png")
img3 = PhotoImage(file="missle_red.png")

points = 0
speed = 0.1

def play_shoot():
    winsound.PlaySound("shoot.wav", 1)
    
def play_boom():
    winsound.PlaySound("explosion.wav", 1)
    
def play_launch():
    winsound.PlaySound("launch.wav", 1)
    
def new_game():
    active = True
    global points
    global speed
    points = 0
    speed = 0.5
    play_launch()
    canvas = Canvas(window, width = 800, height = 650)
    canvas.pack()
    ship = canvas.create_image(360, 550, anchor=NW, image=img1)
    rand_left = random.randint(50,750)
    rand_top = random.randint(100,700)
    missile1 = canvas.create_image(rand_left, -rand_top, anchor=NW, image=img2)
    rand_left = random.randint(50,750)
    rand_top = random.randint(100,700)
    missile2 = canvas.create_image( rand_left, -rand_top, anchor=NW, image=img3)
    score = Label(window, text="Score: 0")
    score.config(font=("Courier", 24))
    score.pack()
    
    
    def game_over():
        play_boom()
        active = False
        canvas.destroy()
        score.destroy()
        global points
        PlayAgain = tkinter.messagebox.askyesno("Game Over", "Your score is %i! \r\rDo you want to play again?"  % points)
        if PlayAgain:
            new_game()
        else:
            window.destroy()
            raise SystemExit
            
    
    def update_score():
        global points
        score.config(text=  " Score: %i" % points)
        score.update_idletasks()
        
    shots = []
    
    def shoot(evt):
        pos = canvas.coords(ship)
        shot = canvas.create_rectangle(pos[0]+35, 530, pos[0]+40, 540, fill="yellow")
        shots.append(shot)
        play_shoot()
        
    def move_shots():
        for shot in shots:
            canvas.move(shot, 0, -5)
            pos = canvas.coords(shot)
            m1_pos = canvas.coords(missile1)
            m2_pos = canvas.coords(missile2)
            if pos[1] <=0:
                canvas.delete(shot)
                shots.remove(shot)
            elif pos[1] <= m1_pos[1]+257 and pos[1] > m1_pos[1]:
                if pos[0] >= m1_pos[0]+5 and pos[0] <= m1_pos[0]+67:
                   reset_missile1()
                   canvas.delete(shot)
                   shots.remove(shot)
            elif pos[1] <= m2_pos[1]+257 and pos[1] > m2_pos[1]:
                if pos[0] >= m2_pos[0]+5 and pos[0] <= m2_pos[0]+67:
                    reset_missile2()
                    canvas.delete(shot)
                    shots.remove(shot)
                
    def move_missiles():
        global speed
        canvas.move(missile1, 0, speed)
        pos = canvas.coords(missile1)
        ship_pos = canvas.coords(ship)
        if pos[1]+257 >= 650: 
            game_over()
        elif pos[1]+257 >= 550 and pos[0]+67 >= ship_pos[0] and pos[0] <= ship_pos[0]+76:
            game_over()
        canvas.move(missile2, 0, speed)
        pos = canvas.coords(missile2)
        ship_pos = canvas.coords(ship)
        if pos[1]+257 >= 650:
            game_over()
        elif pos[1]+257 >= 550 and pos[0]+67 >= ship_pos[0] and pos[0] <= ship_pos[0]+76:
            game_over()
             
    def reset_missile1():
        rand_left = random.randint(50,750)
        rand_top = random.randint(100,700)
        canvas.coords(missile1, rand_left, -rand_top)
        play_boom()
        global points
        global speed
        points +=10
        speed += 0.1
        update_score()
        
    def reset_missile2():
        rand_left = random.randint(50,750)
        rand_top = random.randint(100,700)
        canvas.coords(missile2, rand_left, -rand_top)
        play_boom()
        global points
        global speed
        points +=10 
        speed += 0.1
        update_score()
    
    def move_left(evt):
        pos = canvas.coords(ship)
        if pos[0] > 0:
            canvas.move(ship, -15, 0)
            
    def move_right(evt):
        pos = canvas.coords(ship)
        if pos[0] < 730:
            canvas.move(ship, 15, 0)
            
    canvas.bind_all("<KeyPress-Left>", move_left)
    canvas.bind_all("<KeyPress-Right>", move_right)
    canvas.bind_all("<space>", shoot)
    
    while active:
        move_missiles()
        move_shots()
        window.update()
        time.sleep(.015)
        
new_game()

***ALL CREDIT FOR BELOW CODE TO ANDREJ KARPATHY THIS IS JUST FOR MY OWN REFERENCE***

==> micrograd/visualize_graph.py <==
#!/usr/bin/python3.8

import math
import numpy as np
import matplotlib.pyplot as plt

#def f(x):
#	return 3*x**2 - 4*x + 5
#
#print(f(3.0))
#
#xs = np.arange(-5, 5, 0.25)
#ys = f(xs)
#plt.plot(xs, ys)
#plt.show()

plt.plot(np.arange(-5,5,0.2), np.tanh(np.arange(-5,5,0.2)))
plt.grid()
plt.show()

==> micrograd/bkpropusingpytorch.py <==
#!/usr/bin/python3.8
import torch

x1 = torch.Tensor([2.0]).double()
print(x1.dtype) # by default Tensor uses float32. Casting it to double means it uses float64
x1.requires_grad = True
x2 = torch.Tensor([0.0]).double()
x2.requires_grad = True
w1 = torch.Tensor([-3.0]).double()
w1.requires_grad = True
w2 = torch.Tensor([1.0]).double()
w2.requires_grad = True
b = torch.Tensor([6.8813735870195432]).double()
b.requires_grad = True
n = x1*w1 + x2*w2 + b
o = torch.tanh(n)

print(o.data.item()) #.item() takes a single tensor of one element and returns that element
o.backward()

print('---')
print('x2', x2.grad.item())
print('w2', w2.grad.item())
print('x1', x1.grad.item())
print('w1', w1.grad.item())

# tensors are n-dimensional arrays of scalars i.e. torch.Tensor([[1, 2, 3,], [4, 5, 6]])
a1 = torch.Tensor([[1, 2, 3,], [4, 5, 6]])
print(a1)


==> makemore1/broadcastingsemantics.py <==
#!/usr/bin/python3.8

import torch

#a = torch.tensor([2,3,4])
#b = torch.tensor([5,6,7])
#
#print(a)
#print()
#print(b)
#print()
#print(a+b)
#print()
#print(a.shape)
#print(b.shape)

# The above example works because both tensors are the samee shape

# Broadcasting: allows one to perform arithmetic operations on tensors with different shapes

tensor1 = torch.tensor([[1,2,3]])
tensor2 = torch.tensor([[4], [5], [6]])
# equivalent to:
# tensor2 = torch.tensor([[4], 
#				   		  [5], 
#						  [6]])
print(tensor1.shape) # (1,3)
print(tensor2.shape) # (3,1)

# Broadcasting:
# Under broadcasting, result of op on tensor1 and tensor2 would be 3x3 tensor. To do
# this both tensors are transformed until represented by 3x3 tensors. 
#
# This is because under broadcasting both tensors are aligned from right to left
# The max dimension in each case is then taken, and used to form the result Tensor.
# i.e. if two tensors.shape are (3,1) (2), result tensor will be (3,2)
#
# [[1,2,3]] --> [[1,2,3],
#				 [1,2,3],
#				 [1,2,3]]
#
# [[4], [5], [6]] -->  [[4,4,4],
#						[5,5,5],
#						[6,6,6]]
#
# This basically copies values so shape iss the same as resulting tensor. If 
# KeepDims=False which is default setting
# tensor1 + tensor2 --> [[5,6,7],
#						 [6,7,8],
#						 [7,8,9]]


# Test:
#
# Tensors are compatible via arihmetic operation if corresponding dimensioms are
# 1a. Equal to each other
# 1b. A corresponding dimension is equal to one
# 1c. A corresponding dimension is empty (equal to zero)
# 1d. Rules of matrix multiplication(dot product)/addition/division/arithmetic if 
#     KeepDims=True




==> makemore1/keepdims=True.py <==
#!/usr/bin/python3.8

import numpy as np

a=np.array(((0,1,2,3),(4,5,6,7),(8,9,10,11)))
print(a)       # [[ 0  1  2  3]
				# [ 4  5  6  7]
				# [ 8  9 10 11]]
print(a.ndim)  # 2  -- 2 dimensions
print(a.shape) # (3,4) -- 3 rows, 4 columns
print()

a1=a.sum(axis=0)
print(a1)       # [12 15 18 21]
print(a1.ndim)  # 1  -- 1 dimension
print(a1.shape) # (4,) -- 4 columns
print()

b=a.sum(axis=1)
print(b)       # [6 22 38]
print(b.ndim)  # 1  -- 1 dimension
print(b.shape) # (3,) -- 3 columns
print()

c=a.sum(axis=1,keepdims=True)
print(c)       # [[6] 
				# [22] 
				# [38]]
print(c.ndim)  # 2  -- 2 dimensions
print(c.shape) # (3,1) -- 3 rows, 1 column
print()

b0=b[:]
print(b0)       # [6 22 38]
print(b0.ndim)  # 1  -- 1 dimension
print(b0.shape) # (3) -- 3 columns
print()

b1=b[:,None]
print(b1)       # [6 22 38]
# [[6] 
# [22] 
# [38]]
print(b1.ndim)  # 1  -- 1 dimension
print(b1.shape) # (3,1) -- 3 rows, 1 column
print()

c0=c[:]
print(c0)       
# [[ 6]
#  [22]
#  [38]]
print(c0.ndim)  # 2 -- 2 dimensions
print(c0.shape) # (3,1) -- 
print()

c1=c[:,None]
print(c1)       
# [[[ 6]]
# 
#  [[22]]
# 
#  [[38]]]
#print(c1.ndim)  # 3  -- 3 dimensions
#print(c1.shape) # (3,1,1) -- 
#print()

print(a-b1)		# [[ -6  -5  -4  -3]
				#  [-18 -17 -16 -15]
				#  [-30 -29 -28 -27]]
print()
print(a-c1)		
print((a-c1).shape)		
# [[[ -6  -5  -4  -3]
#   [ -2  -1   0   1]
#   [  2   3   4   5]]
# 
#  [[-22 -21 -20 -19]
#   [-18 -17 -16 -15]
#   [-14 -13 -12 -11]]
# 
#  [[-38 -37 -36 -35]
#   [-34 -33 -32 -31]
#   [-30 -29 -28 -27]]]


==> micrograd/engine.py <==
#!/usr/bin/python3.8

from graphviz import Digraph

class Value:
	def __init__(self, data, _children=(), _op='', label=''):
		self.data = data
		self.grad = 0
		self._prev = set(_children)
		self._op = _op
		self.label = label

	def __repr__(self):
		return f"Value(data={self.data})"

	def __add__(self, other):
		out = Value(self.data + other.data, (self, other), '+')
		return out

	def __mul__(self, other):
		out = Value(self.data * other.data, (self, other), '*')
		return out

def trace(root):
	# builds a set of all nodes and edges in a graph
	nodes, edges = set(), set()
	
	def build(v):
		if v not in nodes:
			nodes.add(v)
			for child in v._prev:
				edges.add((child, v))
				build(child)
	build(root)
	return nodes, edges

def draw_dot(root):
	dot = Digraph(format='svg', graph_attr={'rankdir': 'LR'}) #LR = left to right
	
	nodes, edges = trace(root)
	for n in nodes:
		uid = str(id(n))
		# for any value in the graph, create a rectangular ('record') node for it
		dot.node(name = uid, label = "{ %s | data %.4f | grad %.4f }" % (n.label, n.data, n.grad), shape='record')
		if n._op:
			# if this value is a result of some operation, create an op node for it
			dot.node(name = uid + n._op, label = n._op)
			# and connect this node to it
			dot.edge(uid + n._op, uid)

	for n1, n2 in edges:
		# connect n1 to the op node of n2
		dot.edge(str(id(n1)), str(id(n2)) + n2._op)

	return dot

a = Value(2.0, label = 'a')
b = Value(-3.0, label = 'b')
c = Value(10.0, label = 'c')
e = a*b
e.label = 'e'
d = e + c 
d.label = 'd'
f = Value(-2.0, label = 'f')
L = d * f
L.label = 'L'
L.grad = 1.0  # dL/dL
f.grad= 4.0   # dL/df
d.grad = -2.0 # dL/dd
e.grad = -2.0 # dL/de == dL/dd * dd/de
c.grad = -2.0 # dL/dc == dL/dd * dd/dc
a.grad = 6.0  # dL/da == dL/dd * dd/de * de/da
b.grad = -4.0 # dL/db == dL/dd * dd/de * de/db

def lol():
	h = 0.0001 

	a = Value(2.0, label = 'a')
	b = Value(-3.0, label = 'b')
	c = Value(10.0, label = 'c')
	e = a*b
	e.label = 'e'
	d = e + c 
	d.label = 'd'
	f = Value(-2.0, label = 'f')
	L = d * f
	L.label = 'L'
	L1 = L.data
	
	a = Value(2.0 + h, label = 'a')
	b = Value(-3.0, label = 'b')
	c = Value(10.0, label = 'c')
	e = a*b
	e.label = 'e'
	d = e + c 
	d.label = 'd'
	f = Value(-2.0, label = 'f')
	L = d * f
	L.label = 'L'
	L2 = L.data

	print((L2 - L1)/h)

#print(a)
#print(b)
#print(c)
#print(d)

dot = draw_dot(L)
dot.view()

a.data += 0.01 * a.grad

e = a * b
d = e + c
L = d * f
print(L.data)

==> micrograd/verysimplebackprop.py <==
#!/usr/bin/python3.8

import math
import numpy as np
import matplotlib.pyplot as plt
from graphviz import Digraph

class Value:
	def __init__(self, data, _children=(), _op='', label=''):
		self.data = data
		self.grad = 0
		self._prev = set(_children)
		self._backward = lambda: None
		self._op = _op
		self.label = label

	def __repr__(self):
		return f"Value(data={self.data})"

	def __add__(self, other):
		out = Value(self.data + other.data, (self, other), '+')

		def _backward():
			self.grad = 1.0 * out.grad #local derivative with chain rule
			other.grad = 1.0 * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __mul__(self, other):
		out = Value(self.data * other.data, (self, other), '*')

		def _backward():
			self.grad = other.data * out.grad #local derivative with chain rule
			other.grad = self.data * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def tanh(self):
		n = self.data
		t = (math.exp(2*n) - 1)/(math.exp(2*n) + 1)
		out = Value(t, (self, ), 'tanh')

		def _backward():
			self.grad = (1 - t**2) * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def backward(self):
		topo = []
		visited = set()
		def build_topo(v):
			if v not in visited:
				visited.add(v)
				for child in v._prev:
					build_topo(child)
				topo.append(v)
		
		self.grad = 1.0
		build_topo(self)
		
		for node in reversed(topo):
			node._backward()

def trace(root):
	# builds a set of all nodes and edges in a graph
	nodes, edges = set(), set()
	
	def build(v):
		if v not in nodes:
			nodes.add(v)
			for child in v._prev:
				edges.add((child, v))
				build(child)
	build(root)
	return nodes, edges

def draw_dot(root):
	dot = Digraph(format='svg', graph_attr={'rankdir': 'LR'}) #LR = left to right
	
	nodes, edges = trace(root)
	for n in nodes:
		uid = str(id(n))
		# for any value in the graph, create a rectangular ('record') node for it
		dot.node(name = uid, label = "{ %s | data %.4f | grad %.4f }" % (n.label, n.data, n.grad), shape='record')
		if n._op:
			# if this value is a result of some operation, create an op node for it
			dot.node(name = uid + n._op, label = n._op)
			# and connect this node to it
			dot.edge(uid + n._op, uid)

	for n1, n2 in edges:
		# connect n1 to the op node of n2
		dot.edge(str(id(n1)), str(id(n2)) + n2._op)

	return dot

# inputs x1,x2
x1 = Value(2.0, label='x1')
x2 = Value(0.0, label='x2')
# weights w1,w2
w1 = Value(-3.0, label='w1')
w2 = Value(1.0, label='w2')
# bias of the neuron
b = Value(6.8813725870195432, label='b')
# x1w1 + x2w2 + b
x1w1 = x1 * w1
x1w1.label = 'x1w1'
x1w1._op = '*'
x2w2 = x2 * w2
x2w2.label = 'x2w2'
x2w2._op = '*'
x1w1x2w2 = x1w1 + x2w2
x1w1x2w2.label = 'x1w1 + x2w2'
x1w1x2w2._op = '+'
n = x1w1x2w2 + b
n.label = 'n'
n._op = '+'
o = n.tanh()
o.label = 'o'
o._op = 'tanh'
o.backward()
#o.grad = 1.0

# Manual calculation of derivatives represented by .grad
# o = tanh(n)
# do/dn = 1 - tanh**2(n) == 1 - tanh(n)**2 == 1 - o**2
#n.grad = 1 - o.data**2
#b.grad = n.grad  				# do/db == do/dn * dn/db
#x1w1x2w2.grad = n.grad 		# do/dx1w1x2w2 == do/dn * dn/dx1w1x2w2 
#x1w1.grad = x1w1x2w2.grad 		# do/dx1w1 == do/dn * dn/dx1w1x2w1 * dx1w1x2w2/dx1w1
#x2w2.grad = x1w1x2w2.grad		# do/dx2w2 == do/dn * dn/dx1w1x2w2 * dx1w1x2w2/dx2w2 
#x2.grad = w2.data * x2w2.grad  # do/dx2 == do/dn * dn/dx1w1x2w2 * dx1w1x2w2/dx2w2 * dx2w2/dx2 
#x1.grad = w1.data * x1w1.grad  # do/dx1 == do/dn * dn/dx1w1x2w2 * dx1w1x2w2/dx1w1 * dx1w1/dx1
#w1.grad = x1.data * x1w1.grad  # do/dw1 == do/dn * dn/dx1w1x2w2 * dx1w1x2w2/dx1w1 * dx1w1/dw1
#w2.grad = x2.data * x2w2.grad  # do/dw2 == do/dn * dn/dx1w1x2w2 * dx1w1x2w2/dx2w2 * dx2w2/dw2

# Calling backward() function to calculate derivatives
#o._backward()
#n._backward()
#b._backward() #nothing happens as leaf node
#x1w1x2w2._backward()
#x1w1._backward()
#x2w2._backward()

dot1 = draw_dot(o)
dot1.view()

#highlights bug where current impelmentation doesn't factor in for neuron output affecting multiple nodes (inputs)
a1 = Value(-2.0, label='a')
b1 = Value(3.0, label='b')
d1 = a1 * b1
d1.label = 'd'
e1 = a1 + b1
e1.label = 'e'
f1 = d1 * e1
f1.label = 'f'
f1.backward() # current implementation doesn't factor in for
dot2 = draw_dot(f1)
dot2.view()

#reveals bug which current implementation doesn't factor in for.
def localfunc:
	aa = Value(3.0, label='a')
	bb = aa + aa #dbb/daa should be 2, but current implementation calculates as 1
	bb.label = 'b'
	bb.backward()
	dot3 = draw_dot(bb)
	dot3.view()


==> makemore2/makemoremlp.py <==
#!/usr/bin/python3.8

import random
import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt 

# read in all words
words = open('names.txt', 'r').read().splitlines()
words = list(set(words))
print(words[:8])
print(len(words))

chars = sorted(list(set(''.join(words))))
print(len(chars))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
print(itos)

# training split, dev/validation split, test split: 80%, 10%, 10%

def build_dataset(words):
# build the dataset
	block_size = 3 # context length: how many characters do we take to predict the next one?
	X, Y = [], []
	for w in words:
		#print(w)
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			#print(''.join(itos[i] for i in context), '--->', itos[ix])
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtr, Ytr = build_dataset(words[:n1])
Xdev, Ydev = build_dataset(words[n1:n2])
Xte, Yte = build_dataset(words[n2:])

#print(X.dtype)
#print(Y.dtype)
#
#print(X) # individual eaxamples of contexts
#print(Y) # labels

g = torch.Generator().manual_seed(2147483647)
#lookup table, 27 characters and 10-dimensional embedding
C = torch.randn((27, 10), generator=g)

#print(C)
#print(C[5])
#
#print(F.one_hot(torch.tensor(5), num_classes=27).float() @ C)
#
#print(C[X].shape) # prints (36, 3, 10)
#print(C[X]) # takes original (36.3), and replaces every integer key with corresponding 10-dimensional embedding.
#print(C[x][1,3]) # prints embeddng for 'a'

#emb = C[Xtr]

W1 = torch.randn((30, 108), generator=g)
b1 = torch.randn(108, generator=g)

W2 = torch.randn((108,27), generator=g)
b2 = torch.randn(27, generator=g)
parameters = [C, W1, b1, W2, b2]

#In order to do the dot product here, need to convert our 36,3,10 to a 36,30 matrix
# emb[:, 0, :].shape # == 36,10
#newemb1 = torch.cat([emb[:, 0, :], emb[:, 1, :], emb[:, 2, :]], 1) # concatenates along dimension 36, 3, 10 == torch.cat([a,b], [c,d], [e,f])
#print(newemb1.shape) # result is 36,6 however code does not generalise if want to change block size

#torch.unbind(emb, 1) #unbind removes a tensor dimension, and returns a tuple of all slices along the given dimension. torch.unbind(emb, 1) == emb[:, 0, :], emb[:, 1, :], emb[:, 2, :]
#newemb2 = torch.cat(torch.unbind(emb, 1), 1) # with tuple does not need array operators, however very inefficient
#print(newemb2.shape) # returns 36, 30

#a = torch.arange(18)
#a.view(3,3,2) # will rearrange tensor shape into 3,3,2

# print(emb.storage()) # every tensor has underlying flat storage which makes view() operation highly efficient
#newemb3 = emb.view(36, 30) # restructures array as 36,30
#print(newemb3.shape) #has same effect as previous two operatons

#h = torch.tanh(emb.view(-1, 30) @ W1 + b1) # h == hidden layer, using -1 here pytorch will derive the number of elements that should be here to make this structure sensible, i.e. in this case 36
#print(h.shape)

#print(sum(p.nelement() for p in parameters)) # number of parameters in total

#logits = h @ W2 + b2
#print(logits.shape)

#counts = logits.exp()
#prob = counts / counts.sum(1, keepdims=True) # normalize probability distribution
#print(prob.shape)
#print(prob[torch.arange(36), Ytr].shape) #gets value at Y (output character)
#loss = -prob[torch.arange(36), Y].log().mean()

#loss = F.cross_entropy(logits, Y) # This is equivalent to the above three lines
#print(loss)
#Under the hood F.cross_entropy is numerically "better behavd" an example is illustrated below
#logits1 = torch.tensor([-100, -3, 0, 100])
#counts = logits1.exp()
#probs = counts /counts.sum()
#print(probs) # returns tensor([0., 0., 0., nan])
#this creates problems because the lage number creates a afloating point error when takin its exponent. F.cross-entropy counteracts that by finding the largest number and subtarcting it, so all values are negative. This means that can get very small number, but no inf/Nan returns

#can determine learning rate to use
lre = torch.linspace(-3, 0, 30000) # learning rate exponent 0.001 to 1
lrs = 10**lre #learning rate spaced exponenetially (1000 spaces) between 0.001 to 1

lri = []
lossi = []
stepi = []

for p in parameters:
	p.requires_grad = True

for i in range(15000):
	# minibatch construct
	ix = torch.randint(0, Xtr.shape[0], (256,)) #takes random sampling, gets approximaate gradient

	# forward pass
	emb = C[Xtr[ix]] 
	h = torch.tanh(emb.view(-1, 30) @ W1 + b1)
	logits = h @ W2 + b2
	if i == 0:
		print("logits.shape")
		print(logits.shape)
		
	loss = F.cross_entropy(logits, Ytr[ix])
	#backward pass
	for p in parameters:
		p.grad = None
	loss.backward()
	# update
	lr = 0.05
	for p in parameters:
		p.data += -lr * p.grad
		#p.data += -0.2 * p.grad
	
	# track stats
	#lri.append()
	stepi.append(i)
	lossi.append(loss.log10().item())

print(loss.item())
plt.plot(stepi, lossi)
plt.show()

emb = C[Xdev] # (32, 3, 10)
h = torch.tanh(emb.view(-1, 30) @ W1 + b1)
logits = h @ W2 + b2 # (32, 27)
loss = F.cross_entropy(logits, Ydev)
print(loss.item())

for tx in range(20):
	block_size = 3
	out = []
	context = [0] * block_size # initialize with all ...
	while True:
		emb = C[torch.tensor([context])] # (1,block_size,d)
		h = torch.tanh(emb.view(1, -1) @ W1 + b1)
		logits = h @ W2 + b2
		probs = F.softmax(logits, dim=1) #very similar to cross_entropy with extra step for ultimately generating nll.
		ix = torch.multinomial(probs, num_samples=1, generator=g).item()
		context = context[1:] + [ix]
		out.append(ix)
		if tx == 0 and ix == 0:
			print("emb.shape")
			print(emb.shape)
			print("emb.view(1, -1).shape")
			print(emb.view(1, -1).shape)
			print("h.shape")
			print(h.shape)
			print("logits.shape")
			print(logits.shape)
			print("probs.shape")
			print(probs.shape)
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))

#plt.figure(figsize=(8,8))
#plt.scatter(C[:,0].data, C[:,1].data, s=200)
#for i in range(C.shape[0]):
#	plt.text(C[i,0].item(), C[i,1].item(), itos[i], ha="center", va="center", color='white')
#plt.grid('minor')
#plt.show()

==> micrograd/backpropfix.py <==
#!/usr/bin/python3.8

import math
import numpy as np
import matplotlib.pyplot as plt
from graphviz import Digraph

class Value:
	def __init__(self, data, _children=(), _op='', label=''):
		self.data = data
		self.grad = 0
		self._prev = set(_children)
		self._backward = lambda: None
		self._op = _op
		self.label = label

	def __repr__(self):
		return f"Value(data={self.data})"

	# have to sum for chain rule with multiple variables
	def __add__(self, other):
		other = other if isinstance(other, Value) else Value(other) # will allow for a + 2
		out = Value(self.data + other.data, (self, other), '+')

		def _backward():
			self.grad += 1.0 * out.grad #local derivative with chain rule
			other.grad += 1.0 * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __radd__(self, other): # Will allow for 2 + a (if python cannot evaluate this expression it wiil check for an radd)
		return self + other

	def __mul__(self, other):
		other = other if isinstance(other, Value) else Value(other) # will allow for a * 2
		out = Value(self.data * other.data, (self, other), '*')

		def _backward():
			self.grad += other.data * out.grad #local derivative with chain rule
			other.grad += self.data * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __rmul__(self, other): # Will allow for 2 * a (if python cannot evaluate this expression it will check for an rmul)
		return self * other

	def __pow__(self, other):
		assert isinstance(other, (int, float)), "only supporting int/float powers for now"
		out = Value(self.data**other, (self,), f"**{other}")

		def _backward():
			self.grad += other * self.data**(other - 1) * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __neg__(self):
		return self * -1

	def __sub__(self, other):
		return self + (-other)

	def __truediv__(self, other): # self / other
		return self * other**-1

	def tanh(self):
		n = self.data
		t = (math.exp(2*n) - 1)/(math.exp(2*n) + 1)
		out = Value(t, (self, ), 'tanh')

		def _backward():
			self.grad += (1 - t**2) * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def exp(self):
		x = self.data
		out = Value(math.exp(x), (self, ), 'exp')

		def _backward():
			self.grad = out.data * out.grad
		
		out._backward = _backward
		return out

	def backward(self):
		topo = []
		visited = set()
		def build_topo(v):
			if v not in visited:
				visited.add(v)
				for child in v._prev:
					build_topo(child)
				topo.append(v)
		
		self.grad = 1.0
		build_topo(self)
		
		for node in reversed(topo):
			node._backward()

def trace(root):
	# builds a set of all nodes and edges in a graph
	nodes, edges = set(), set()
	
	def build(v):
		if v not in nodes:
			nodes.add(v)
			for child in v._prev:
				edges.add((child, v))
				build(child)
	build(root)
	return nodes, edges

def draw_dot(root):
	dot = Digraph(format='svg', graph_attr={'rankdir': 'LR'}) #LR = left to right
	
	nodes, edges = trace(root)
	for n in nodes:
		uid = str(id(n))
		# for any value in the graph, create a rectangular ('record') node for it
		dot.node(name = uid, label = "{ %s | data %.4f | grad %.4f }" % (n.label, n.data, n.grad), shape='record')
		if n._op:
			# if this value is a result of some operation, create an op node for it
			dot.node(name = uid + n._op, label = n._op)
			# and connect this node to it
			dot.edge(uid + n._op, uid)

	for n1, n2 in edges:
		# connect n1 to the op node of n2
		dot.edge(str(id(n1)), str(id(n2)) + n2._op)

	return dot

# inputs x1,x2
x1 = Value(2.0, label='x1')
x2 = Value(0.0, label='x2')
# weights w1,w2
w1 = Value(-3.0, label='w1')
w2 = Value(1.0, label='w2')
# bias of the neuron
b = Value(6.8813725870195432, label='b')
# x1w1 +x2w2 + b
x1w1 = x1*w1
x1w1.label = 'x1w1'
x2w2 = x2*w2
x2w2.label = 'x2w2'
x1w1x2w2 = x1w1 + x2w2
x1w1x2w2.label = 'x1w1 + x2w2'
n = x1w1x2w2 + b
n.label = 'n'
e = (2*n).exp()
o = (e - 1)/(e + 1) # o = n.tanh()
o.label = 'o'
o.backward()
dot1 =  draw_dot(o)
dot1.view()

#o.grad = 1.0

# Manual calculation of derivatives represented by .grad
# o = tanh(n)
# do/dn = 1 - tanh**2(n) == 1 - tanh(n)**2 == 1 - o**2
#n.grad = 1 - o.data**2
#b.grad = n.grad
#x1w1x2w2.grad = n.grad
#x1w1.grad = x1w1x2w2.grad
#x2w2.grad = x1w1x2w2.grad
#x2.grad = w2.data * x2w2.grad
#x1.grad = w1.data * x1w1.grad
#w1.grad = x1.data * x1w1.grad
#w2.grad = x2.data * x2w2.grad

# Calling backward() function to calculate derivatives
#o._backward()
#n._backward()
#b._backward() #nothing happens as leaf node
#x1w1x2w2._backward()
#x1w1._backward()
#x2w2._backward()

#dot1 =  draw_dot(o)
#dot1.view()

#a2 = Value (3.0, label='a')
#b2 = a2 + a2 #db/da should be 2, but current implementation calculates as 1
#b2.label = 'b'
#b2.backward()
#dot2 = draw_dot(b2)
#dot2.view()

#a1 = Value(-2.0, label='a')
#b1 = Value(3.0, label='b')
#d1 = a1 * b1
#d1.label = 'd'
#e1 = a1 + b1
#e1.label = 'e'
#f1 = d1 * e1
#f1.label = 'f'
#f1.backward() # current implementation doesn't factor in for
#dot = draw_dot(f1)
#dot.view()


==> makemore5/initial.py <==
#!/usr/bin/python3.8

import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random

#read in all the words
words = open('names.txt', 'r').read().splitlines()
#print(len(words))
#print(max(len(w) for w in words))
#print(words[:8])

chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)
#print(itos)
#print(vocab_size)

#shuffle up the words
random.seed(42)
random.shuffle(words)

#build the dataset
block_size = 3 # contex length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []

	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append

	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))
Xtr,  Ytr  = build_dataset(words[:n1])
Xdev, Ydev = build_dataset(words[n1:n2])
Xte,  Yte  = build_dataset(words[n2:])

for x,y in zip(Xtr[:20], Ytr[:20]):
	print(''.join(itos[ix.item()] for ix in x), '-->', itos[y.item()])

#-------------------------------------------------------------------------
class Linear:
	def __init__(self, fan_in, fan_out, bias=True):
		self.weight = torch.randn((fan_in, fan_out)) / fan_in**0.5 # note: kaiming init
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#-------------------------------------------------------------------------
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		#parameters (trained with backprop)
		self.gamma = torch.ones(dim)
		self.beta = torch.zeros(dim)
		#buffers (trained with a running 'momentum update - exponential moving average')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) # batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta
		#Update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

#-------------------------------------------------------------------------
class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	
	def parameters(self):
		return []

torch.manual_seed(42) # seed rng for reproducibility

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 200 # the number of neurons in the hidden layer of the MLP

C = torch.randn((vocab_size, n_embd))
layers = [
	Linear(n_embd * block_size, n_hidden, bias=False), 
	BatchNorm1d(n_hidden), 
	Tanh(),
	Linear(n_hidden, vocab_size),
]

# parameter init
with torch.no_grad():
	layers[-1].weight *= 0.1 # last layer make less confident

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time
max_steps = 200000
batch_size = 32
lossi = []

for i in range(max_steps):
	#minibatch construct
	ix = torch.randint(0, Xtr.shape[0], (batch_size,)) #torch.randint(low, high, size)
	Xb, Yb = Xtr[ix], Ytr[ix] # batch X,Y

	# forward pass
	emb = C[Xb] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, Yb)

	# backward pass
	for p in parameters:
		p.grad = None
	loss.backward()

	#update: simple stochastic gradient descent (SGD)
	lr = 0.1 if i < 150000 else 0.01
	for p in parameters:
		p.data += -lr * p.grad

	#track stats
	if i % 1000 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

plt.plot(lossi)
plt.show()

# put layers into eval mode (needed for batchnorm especially)
for layer in layers:
	layer.training = False

# evaluate the loss
@torch.no_grad()
def split_loss(split):
	x,y = {
		'train': (Xtr, Ytr),
		'val': (Xdev, Ydev),
		'test': (Xte, Yte),
	}[split]
	emb = C[x] # (N, block_size, n_embd)
	x = emb.view(emb.shape[0], -1)
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, y)
	print(split, loss.item())

split_loss('train')
split_loss('val')

for _ in range(20):
	out = []
	context = [0] * block_size # initialize with all '...'s
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size,n_embd)
		x = emb.view(emb.shape[0], -1) # concatenate the vectors
		for layer in layers:
			x = layer(x)
		logits = x
		probs = F.softmax(logits, dim=1)
		# sample from the distribution
		ix = torch.multinomial(probs, num_samples=1).item()
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if character is the special '.' token, break
		if ix == 0:
			break

	print(''.join(itos[i] for i in out)) # decode and print the generated word

==> makemore1/makemorebigram.py <==
#!/usr/bin/python3.8

#look up pytorch broadcasting semantics
import torch
import matplotlib.pyplot as plt
import torch.nn.functional as F

words = open('names.txt', 'r').read().splitlines()
#print(words[:10])
#print(min(len(w) for w in words))

#for w in words[:1]: #first word in array
#	for ch1, ch2 in zip(w, w[1:]): # w[1:] == 'mma', for loop creates two iterators over both arrays, stops when it reaches the end of an array
#		print(ch1,ch2)

chars = sorted(set(''.join(words))) # creates a set of 26 chars 'a' - 'z'
stoi = {s:i+1 for i,s in enumerate(chars)} # creates map of char to int representation (as an enum)
stoi['.'] = 0
#stoi['<S>'] = 26
#stoi['<E>'] = 27
#print(stoi)

itos = {i:s for s,i in stoi.items()} # creates map of int to char representation (as an enum)
#itos[26] = '<S>'
#itos[27] = '<E>'

N = torch.zeros((27, 27), dtype=torch.int32) #default tensor type is float32

b = {}
for w in words: 
	#chs = ['<S>'] + list(w) + ['<E>'] #appends start and end "characters"
	chs = ['.'] + list(w) + ['.'] #appends start and end "characters"
	for ch1, ch2 in zip(chs, chs[1:]): # w[1:] == 'mma', for loop creates two iterators over both arrays, stops when it reaches the end of an array
#		bigram = (ch1,ch2)
#		b[bigram] = b.get(bigram, 0) + 1
		ix1 = stoi[ch1]
		ix2 = stoi[ch2]
		N[ix1, ix2] += 1

#print(sorted(b.items(), key = lambda kv: -kv[1]))

plt.figure(figsize=(16,16))
plt.imshow(N)
for i in range(27):
	for j in range(27):
		chstr = itos[i] + itos[j]
		plt.text(j, i, chstr, ha="center", va="bottom", color='gray')
		plt.text(j, i, N[i, j].item(), ha="center", va="top", color='gray')
plt.axis('off')
#plt.show()

#print(N[0])
#p = N[0].float()
#p = p / p.sum() # changed to probability distibution where p.sum() == 1

g = torch.Generator().manual_seed(2147483647)
p = torch.rand(3, generator=g) # probability distribution where p.sum() == 1
p = p / p.sum()
#print(p) # tensor([0.6064, 0.3033, 0.0903]) means probability of 1st number '0' coming up is 60%, '1' coming up is '30%' and '2' coming up is 10%
print(torch.multinomial(p, num_samples=20, replacement=True, generator=g))
#result of print tensor([1, 1, 2, 0, 0, 2, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1])

#print(N[0])
p = N[0].float()
p = p / p.sum() # changed to probability distribution where p.sum() == 1 based on N[0]
g = torch.Generator().manual_seed(2147483647)
ix = torch.multinomial(p, num_samples=1, replacement=True, generator=g).item() #Uses probability distribution of N[0] to pick an index (ix). has picked the letter 'j'
#print(ix) # has picked index 10 which is letter 'j'
#print(itos[ix])

P = (N+1).float() # model smoothing prevents -(inf) for log(0), float conversion for neural network calculations
# In this case summing along rows or along columns is identical, due to mirror effect.

#print(P.sum(1, keepdim=True)) #  read pytorch api documentation, specifically documentation for torch.sum(), 1 represents dimension, is 2nd argument

#print(P.sum(0, keepdim=True).shape) # using 0 as an argument will produce a [1,27] row vector 
#print(P.sum(1, keepdim=True).shape) # using 1 as an argument will produce a [27,1] column vector

P /= P.sum(1, keepdim=True)

# P.sum(1,keepdim=True) returns a [27,1] array where every value is the sum of every row. It then does an element-wise division where every value in the row is divided my the equivalent row value in the column vector, in order to produce a normalised probability distribution where P[row].sum() == 1. Does this by stretching out every row in the column direction (under the hood)

ix = 0
while True:
#	p = N[ix].float()
#	p = p/p.sum()
# These two steps have been condensed into the below operation
	p = P[ix]
	ix = torch.multinomial(p, num_samples=1, replacement=True, generator=g).item()
	print(itos[ix])
	if ix == 0:
		break

# the above code uses the bigram technique, which is a pretty inefficient in terms of NLP techniques

#in order to measure the effectiveness of the algorithm, to measure quality of model, will need to get the likelihood, which would be the product of the probabilities (in a word). For a good model, the product of the possibilities should be as high as possible. Since this is normalized, will be quite low, and as such uses the log probability, see log of numbers between 0 and 1, closer to one tends towards zero, closer to zero tends towards neg infinity
# log(a*b*c) = log(a) + log(b) + log(c) 
log_likelihood = 0.0 # in order to minimize the loss function we use negative log likelihood.
n = 0 # in order to have a normalised log_likelihood, we keep a running count
for w in words: # [:3]: for print statement
	chs = ['.'] + list(w) + ['.'] #appends start and end "characters"
	for ch1, ch2 in zip(chs, chs[1:]): 
		ix1 = stoi[ch1]
		ix2 = stoi[ch2]
		prob = P[ix1, ix2]
		logprob = torch.log(prob)
		log_likelihood += logprob
		n += 1
		#print(f'{ch1}{ch2}: {prob:.4f} {logprob:.4f}')

nll = -(log_likelihood)
print(f'{log_likelihood=}') #log_likelihood=tensor(-38.7856)
print(f'{nll=}') 
print(f'{nll/n}') # this average nll now constitutes a loss function for our neural network, we can now use gradient optimization on the bigram model

#our goal is to maximise probabilities with respect to the model parameters
xs, ys = [], []

for w in words:
	chs = ['.'] + list(w) + ['.'] #appends start and end "characters"
	for ch1, ch2 in zip(chs, chs[1:]): 
		ix1 = stoi[ch1]
		ix2 = stoi[ch2]
		xs.append(ix1)
		ys.append(ix2)

# there is a difference between torch.tensor (lowercase) and torch.Tensor (uppercase). torch.tensor infers the dtype automatically, while torch.Tensor returns a torch.FloatTensor. torch.tensor does not allow dtype to be passed as an argument if you want to change the type, so must be cast.
xs = torch.tensor(xs)
ys = torch.tensor(ys)
num = xs.nelement()
print('number of examples: ', num)
g = torch.Generator().manual_seed(9877483647)

# A commmon way of feeding integers into neural nets is one-hot encoding.

# forward pass
xenc = F.one_hot(xs, num_classes=27).float() # creates vector representations of integers stored as floats
#print(xenc)
#print(xenc.shape) # is 5, 27
#plt.imshow(xenc)
#plt.show()

#W = torch.randn(27, 1) # column vector of 27,1
#print((xenc @ W).shape) # returns column vector of 5,27 . 27,1 == 5,1, matrix multiplication, dot-product rules

W = torch.randn((27, 27), generator=g, requires_grad=True)
# print(xenc @ W) # returns vector of 5, 1, uses dot product matrix multiplication
# interpret these random numbers returned in xenc @ W as log of (traditional bigram stats) count and therefore exponentiate them, to return them as positive numbers
logits = xenc @ W # log-counts
print("logits.shape")
print(logits.shape)
counts = logits.exp() # equivalent N
probs = counts/counts.sum(1, keepdims=True) # probabilities for next character
#
#nlls = torch.zeros(5)
#for i in range(5):
	# i-th bigram:
#	x = xs[i].item() # input character index
#	y = ys[i].item() # input character index
#	print('---------------')
#	print('bigram example {i+1}: {itos[x]}{itos[y]} (indexes {x},{y})')
#	print('input to the neural net:', x)
#	print('output probabilities from the neural net:', probs[i])
#	print('label (actual next character):', y)
#	p = probs[i, y]
#	print('probability assigned by the net to the correct character:', p.item())
#	logp = torch.log(p)
#	print('log likelihood:', logp.item())
#	nll = -logp
#	print('negative log likelihood:', nll.item())
#	nlls[i] = nll
#
#print('---------------')
#print('average log likelihood, i.e. loss =', nlls.mean().item())
#
# torch.arange(5) # returns tensor([0, 1, 2, 3, 4])
#print(probs[torch.arange(5), ys])
#
#loss = -probs[torch.arange(5), ys].log().mean()
#print(loss)
#
#backward pass
#W.grad = None # set gradient to zero
#loss.backward()
#print(W.grad)
#print(W.shape)

for k in range(100):
	#forward pass
	xenc = F.one_hot(xs, num_classes=27).float()
	logits = xenc @ W # predict log-counts, random initialization
	counts = logits.exp() # exponentiates random numbers interpreted as log counts, makes them all positive so can be interpreted as counts, equivalent to N
	probs = counts / counts.sum(1, keepdims=True) # Normalizes "counts", interpreted as probabilities for next character in bigram, can optimize via backprop
	loss = -probs[torch.arange(num), ys].log().mean() + 0.01*(W**2).mean() #the 2nd term is near equivalent to the +1 in P = (N+1).float(), evens out distribution 
	print(loss.item())

	# backward pass
	W.grad = None # reset to zero the gradient
	loss.backward()

	W.data += -50 * W.grad # eventually loss matches the value gained by counting traditiional bigram statistics which is around 2.46

for i in range(20):
	out = []
	ix = 0
	while True:
		#-----------------
		# BEFORE:
		#p = P[ix]
		# ----------------
		# NOW:
		xenc = F.one_hot(torch.tensor([ix]), num_classes=27).float()

		logits = xenc @ W # predict log-counts
		counts = logits.exp() # counts, equivalent to N
		p = counts / counts.sum(1, keepdims=True) # probabilities for next character
		# ----------------
		
		ix = torch.multinomial(p, num_samples=1, replacement=True, generator=g).item()
		out.append(itos[ix])

		if i == 0 and ix == 0:
			print("xenc.shape")
			print(xenc.shape)
			print("W.shape")
			print(W.shape)
			print(xenc)
			print(W)
			print(logits)
		if ix == 0:
			break
	print(''.join(out))

==> micrograd/twolayerperceptron.py <==
#!/usr/bin/python3.8
import torch
import random
import math
import numpy as np
import matplotlib.pyplot as plt
from graphviz import Digraph

class Value:
	def __init__(self, data, _children=(), _op='', label=''):
		self.data = data
		self.grad = 0
		self._prev = set(_children)
		self._backward = lambda: None
		self._op = _op
		self.label = label

	def __repr__(self):
		return f"Value(data={self.data})"

	# have to sum for chain rule with multiple variables
	def __add__(self, other):
		other = other if isinstance(other, Value) else Value(other) # will allow for a + 2
		out = Value(self.data + other.data, (self, other), '+')

		def _backward():
			self.grad += 1.0 * out.grad #local derivative with chain rule
			other.grad += 1.0 * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __radd__(self, other): # Will allow for 2 + a (if python cannot evaluate this expression it wiil check for an radd
		return self + other

	def __mul__(self, other):
		other = other if isinstance(other, Value) else Value(other) # will allow for a * 2
		out = Value(self.data * other.data, (self, other), '*')

		def _backward():
			self.grad += other.data * out.grad #local derivative with chain rule
			other.grad += self.data * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __rmul__(self, other): # Will allow for 2 * a (if python cannot evaluate this expression it wiil check for an rmul
		return self * other

	def __pow__(self, other):
		assert isinstance(other, (int, float)), "only supporting int/float powers for now"
		out = Value(self.data**other, (self,), f"**{other}")

		def _backward():
			self.grad += other * self.data**(other - 1) * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def __neg__(self):
		return self * -1

	def __sub__(self, other):
		return self + (-other)

	def __truediv__(self, other): # self / other
		return self * other**-1

	def tanh(self):
		n = self.data
		t = (math.exp(2*n) - 1)/(math.exp(2*n) + 1)
		out = Value(t, (self, ), 'tanh')

		def _backward():
			self.grad += (1 - t**2) * out.grad #local derivative with chain rule

		out._backward = _backward
		return out

	def exp(self):
		x = self.data
		out = Value(math.exp(x), (self, ), 'exp')

		def _backward():
			self.grad = out.data * out.grad
		
		out._backward = _backward
		return out

	def backward(self):
		topo = []
		visited = set()
		def build_topo(v):
			if v not in visited:
				visited.add(v)
				for child in v._prev:
					build_topo(child)
				topo.append(v)
		
		self.grad = 1.0
		build_topo(self)
		
		for node in reversed(topo):
			node._backward()

def trace(root):
	# builds a set of all nodes and edges in a graph
	nodes, edges = set(), set()
	
	def build(v):
		if v not in nodes:
			nodes.add(v)
			for child in v._prev:
				edges.add((child, v))
				build(child)
	build(root)
	return nodes, edges

def draw_dot(root):
	dot = Digraph(format='svg', graph_attr={'rankdir': 'LR'}) #LR = left to right
	
	nodes, edges = trace(root)
	for n in nodes:
		uid = str(id(n))
		# for any value in the graph, create a rectangular ('record') node for it
		dot.node(name = uid, label = "{ %s | data %.4f | grad %.4f }" % (n.label, n.data, n.grad), shape='record')
		if n._op:
			# if this value is a result of some operation, create an op node for it
			dot.node(name = uid + n._op, label = n._op)
			# and connect this node to it
			dot.edge(uid + n._op, uid)

	for n1, n2 in edges:
		# connect n1 to the op node of n2
		dot.edge(str(id(n1)), str(id(n2)) + n2._op)

	return dot

class Neuron:
	def __init__(self, nin):
		self.w = [Value(random.uniform(-1,1)) for _ in range(nin)]
		self.b = Value(random.uniform(-1,1))

	def __call__(self, x):
		# w * x + b
		#sum takes second argument which is an initial value to sum on top of
		act = sum(wi*xi for wi, xi in zip(self.w, x)) + self.b #total activation
		out = act.tanh()
		#print(list(zip(self.w, x))) # takes two iterators and creates new iterator which iterates over tuples
		return out

	def parameters(self):
		return self.w + [self.b]

class Layer:
	def __init__(self, nin, nout):
		self.neurons = [Neuron(nin) for _ in range(nout)]

	def __call__(self, x):
		outs = [n(x) for n in self.neurons]
		return outs[0] if len(outs) == 1 else outs
	
	def parameters(self):
		return[p for neuron in self.neurons for p in neuron.parameters()] # equivalent to below code
#		params = []
#		for neuron in self.neurons:
#			ps = neuron.parameters()
#			params.extend(ps)
#		return params

#Multi-layer Perceptron
class MLP:
	def __init__(self, nin, nouts):
		sz = [nin] + nouts
		self.layers = [Layer(sz[i], sz[i+1]) for i in range(len(nouts))]

	def __call__(self, x):
		for layer in self.layers:
			x = layer(x)
		return x
	
	def parameters(self):
		return[p for layer in self.layers for p in layer.parameters()] # equivalent to below code
#		params = []
#		for layer in self.layers:
#			ps = layer.parameters()
#			params.extend(ps)
#		return params

n = MLP(3, [4,4,1])
#x = [2.0, 3.0, -1.0]
#n(x)
#print(len(n.parameters()))
#output = n(x).data
#print(output[-1])
#dot = draw_dot(n(x))
#dot.view()

xs = [
	[2.0, 3.0, -1.0],
	[3.0, -1.0, 0.5],
	[0.5, 1.0, 1.0],
	[1.0, 1.0, -1.0]
]
ys = [1.0, -1.0, -1.0, 1.0] #desired targets

#ygt = y ground truth i.e. actual true values of a dataset. It represents the real-world, 
#correct labels or values that a model is trying to predict. The ground truth is often 
#used to evaluate the performance of a machine learning model, by comparing the model's 
#predicted values against the actual ground truth values. The accuracy of a model can be 
#measured by comparing the number of correct predictions against the total number of 
#predictions made by the model on a given dataset. The ground truth is an important concept 
#in machine learning as it helps to train and evaluate models accurately.

for k in range(5000):
	# forward pass
	ypred = [n(x) for x in xs]
	loss = sum([(yout - ygt)**2 for ygt, yout in zip(ys, ypred)])
	print(loss)
	
	# backward pass - if grad not reset to zero, grads will accumulate
	for p in n.parameters():
		p.grad = 0.0 
	loss.backward()
	
	#update
	for p in n.parameters():
		p.data -= 0.05 * p.grad

print(ypred)

#dot = draw_dot(loss)
#dot.view()

==> makemore5/8charMLP.py <==
#!/usr/bin/python3.8

import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random

#read in all the words
words = open('names.txt', 'r').read().splitlines()
#print(len(words))
#print(max(len(w) for w in words))
#print(words[:8])

chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)
#print(itos)
#print(vocab_size)

#shuffle up the words
random.seed(42)
random.shuffle(words)

#build the dataset
block_size = 8 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []

	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append

	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))
Xtr,  Ytr  = build_dataset(words[:n1])
Xdev, Ydev = build_dataset(words[n1:n2])
Xte,  Yte  = build_dataset(words[n2:])

for x,y in zip(Xtr[:20], Ytr[:20]):
	print(''.join(itos[ix.item()] for ix in x), '-->', itos[y.item()])

#-------------------------------------------------------------------------
class Linear:
	def __init__(self, fan_in, fan_out, bias=True):
		self.weight = torch.randn((fan_in, fan_out)) / fan_in**0.5 # note: kaiming init
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#-------------------------------------------------------------------------
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		#parameters (trained with backprop)
		self.gamma = torch.ones(dim)
		self.beta = torch.zeros(dim)
		#buffers (trained with a running 'momentum update - exponential moving average')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) # batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta
		#Update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

#-------------------------------------------------------------------------
class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	
	def parameters(self):
		return []

#-------------------------------------------------------------------------
class Embedding:
	def __init__(self, num_embeddings, embedding_dim):
		self.weight = torch.randn((num_embeddings, embedding_dim)) #Generates a num_embeddingsxembedding_dim tensor

	def __call__(self, IX):
		self.out = self.weight[IX]
		return self.out

	def parameters(self):
		return [self.weight]

#-------------------------------------------------------------------------
class Flatten:
	def __call__(self, x):
		self.out = x.view(x.shape[0], -1)
		return self.out

	def parameters(self):
		return []

#-------------------------------------------------------------------------
class Sequential:
	def __init__(self, layers):
		self.layers = layers

	def __call__(self, x):
		for layer in self.layers:
			x = layer(x)
		self.out = x
		return self.out

	def parameters(self):
		# get parameters of all layers and stretch them out into one list
		return [p for layer in self.layers for p in layer.parameters()]

torch.manual_seed(42) # seed rng for reproducibility

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 200 # the number of neurons in the hidden layer of the MLP

model = Sequential([ # replaces layers = [ for ... x=layer(x), etcs.
	Embedding(vocab_size, n_embd), # replaces C = torch.randn((vocab_size, n_embd))
	Flatten(), #replaces emb.view(emb.shape[0], -1)
	Linear(n_embd * block_size, n_hidden, bias=False), 
	BatchNorm1d(n_hidden), 
	Tanh(),
	Linear(n_hidden, vocab_size),
])

# parameter init
with torch.no_grad():
	model.layers[-1].weight *= 0.1 # last layer make less confident

parameters = model.parameters() # replaces [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time
max_steps = 200000
batch_size = 32
lossi = []

##LOOKING AT A BATCH OF 4 EXAMPLES
#ix = torch.randint(0, Xtr.shape[0], (4,))
#Xb, Yb = Xtr[ix], Ytr[ix]
#logits = model(Xb)
#print(Xb.shape) # torch.Size([4,8])
#Xb #tensor([[ 2, 23, 19, 11,  5,  3, 20, 17],
## 	       	 [ 3, 14,  8, 20,  5,  3, 21, 10],
##   	     [16, 18, 12, 19, 25,  2,  9, 20],
##       	 [17, 13, 19, 18,  8,  3,  8, 23]])
#model.layers[0].out.shape # output of Embedding layer - torch.Size([4, 8, 10])
#model.layers[1].out.shape # output of Flatten layer - torch.Size([4, 80])
#model.layers[2].out.shape # output of Linear layer - torch.Size([4, 200])
##WHAT HAPPENS INSIDE THE LINEAR LAYER IS AS FOLLOWS
##torch.Size([4, 80]) @ torch.Size([80, 200] + torch.Size([200]) == torch.Size([4, 200])

for i in range(max_steps):
	#minibatch construct
	ix = torch.randint(0, Xtr.shape[0], (batch_size,)) #torch.randint(low, high, size)
	Xb, Yb = Xtr[ix], Ytr[ix] # batch X,Y

	# forward pass
	logits = model(Xb)
	#OLD WAY BELOW:
#	x = Xb # replaces emb = C[Xb]; x = emb.view(emb.shape[0], -1)
#	for layer in layers:
#		x =  layer(x)
	loss = F.cross_entropy(logits, Yb)

	# backward pass
	for p in parameters:
		p.grad = None
	loss.backward()

	#update: simple stochastic gradient descent (SGD)
	lr = 0.1 if i < 150000 else 0.01
	for p in parameters:
		p.data += -lr * p.grad

	#track stats
	if i % 1000 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

# torch.arange(10) # tensor([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
# torch.arange(10).view(2,5)
# tensor([[0, 1, 2, 3, 4],
#         [5, 6, 7, 8, 9]])
# torch.arange(10).view(5,2)
# tensor([[0, 1],
#         [2, 3],
#         [4, 5],
#         [6, 7],
#         [8, 9]])
# will autoocalculate shape if -1 is specified in place of one of the dimensions
#torch.arange(10).view(5,-1)
#tensor([[0, 1],
#        [2, 3],
#        [4, 5],
#        [6, 7],
#        [8, 9]])
#torch.arange(10).view(-1,2)
#tensor([[0, 1],
#        [2, 3],
#        [4, 5],
#        [6, 7],
#        [8, 9]])
#  

#torch.tensor(lossi).view(-1, 1000).shape # torch.Size([200, 1000])
#torch.tensor(lossi).view(-1, 1000).mean(1).shape #calculates mean along dimension 1 == torch.Size([200])
plt.plot(torch.tensor(lossi).view(-1, 1000).mean(1))
plt.show()

# put layers into eval mode (needed for batchnorm especially), else will cause prediction layer to fail as samples variance of 1 number which is 'nan'
for layer in model.layers:
	layer.training = False

# evaluate the loss
@torch.no_grad() #decorator that does the same as with torch.no_grad():
def split_loss(split):
	x,y = {
		'train': (Xtr, Ytr),
		'val': (Xdev, Ydev),
		'test': (Xte, Yte),
	}[split]
	logits = model(x)
	#OLD METHOD BELOW:
#	emb = C[x] # (N, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1)
#	for layer in model.layers:
#		x = layer(x)
	loss = F.cross_entropy(logits, y)
	print(split, loss.item())

split_loss('train')
split_loss('val')

for _ in range(20):
	out = []
	context = [0] * block_size # initialize with all '...'s
	while True:
		logits = model(torch.tensor([context]))
		#OLD METHOD BELOW:
		# forward pass the neural net
##		emb = C[torch.tensor([context])] # (1,block_size,n_embd)
##		x = emb.view(emb.shape[0], -1) # concatenate the vectors
##		for layer in layers:
##			x = layer(x)
##		logits = x
		probs = F.softmax(logits, dim=1)
		# sample from the distribution
		ix = torch.multinomial(probs, num_samples=1).item() # torch.multinomial(input, num_samples)
		# returns a tensor where each row contains num_samples 'indices' sampled from the multinomial distribution located in the corresponding row of the tensor 'input'
		context = context[1:] + [ix]
		# shift the context window and track the samples
		out.append(ix)
		# if character is the special '.' token, break
		if ix == 0:
			break

	print(''.join(itos[i] for i in out)) # decode and print the generated word

==> makemore3/nninitializationpytorch.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
#	Linear(n_embd * block_size, n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	#layers[-1].weight *= 0.1 # without batch normalization layer
	layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())
	with torch.no_grad():
		ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2:
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	if p.ndim == 2:
		plt.plot([ud[j][i] for j in range(len(ud))])
		legends.append('param %d' % i)
plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()
# around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 

@torch.no_grad() # this decorator disables gradient tracking
def split_loss(split):
	x, y = {
		'train': (Xtra, Ytra),
		'val': (Xdev, Ydev),
		'test': (Xtes, Ytes),
	}[split]
	emb = C[x] # (W, block_size, n_embd)
	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, y)
	print(split, loss.item())

# put layers into eval mode
for layer in layers:
	layer.training = False
split_loss('train')
split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchlineartanhsandwichinitstdgain.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
#ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	break

	#with torch.no_grad():
	#	ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2:
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	if p.ndim == 2:
#		plt.plot([ud[j][i] for j in range(len(ud))])
#		legends.append('param %d' % i)
#plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()
## around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 
#
#@torch.no_grad() # this decorator disables gradient tracking
#def split_loss(split):
#	x, y = {
#		'train': (Xtra, Ytra),
#		'val': (Xdev, Ydev),
#		'test': (Xtes, Ytes),
#	}[split]
#	emb = C[x] # (W, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
#	for layer in layers:
#		x = layer(x)
#	loss = F.cross_entropy(x, y)
#	print(split, loss.item())
#
## put layers into eval mode
#for layer in layers:
#	layer.training = False
#split_loss('train')
#split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchudratio.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	#lr = 0.001 #too low, results in a very low ud (update-data ratio), around 10E-4, training too slow
	#lr = 10 #too high, results in very high ud (update-data ratio), may lead to large instability
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())
	with torch.no_grad():
		ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters]) 
		#divides learning rate * stddev of gradient by stddev of data, log10 to look at exponents of division,, and .item() to pop out float 

	if i >= 1000:
		break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2: #parameters constrained to just Linear layer weights.
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	if p.ndim == 2: #parameters constrained to just Linear layer weights
		plt.plot([ud[j][i] for j in range(len(ud))])
		legends.append('param %d' % i)
plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()
# around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 

@torch.no_grad() # this decorator disables gradient tracking
def split_loss(split):
	x, y = {
		'train': (Xtra, Ytra),
		'val': (Xdev, Ydev),
		'test': (Xtes, Ytes),
	}[split]
	emb = C[x] # (W, block_size, n_embd)
	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, y)
	print(split, loss.item())

# put layers into eval mode
for layer in layers:
	layer.training = False
split_loss('train')
split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchlinearstacktanhgain.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
#ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	break

	#with torch.no_grad():
	#	ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
print('gain now causes std dev to grow, because no tanh squashing function. more saturation and dead neurons at each layer')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Linear):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
print('gradient now diminishes at each layer in the graph statistics. dead neurons.')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Linear):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer
#
##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	t = p.grad
#	if p.ndim == 2:
#		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
#		hy, hx = torch.histogram(t, density=True)
#		plt.plot(hx[:-1].detach(), hy.detach())
#		legends.append(f'layer {i} ({layer.__class__.__name__}')
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()

##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	if p.ndim == 2:
#		plt.plot([ud[j][i] for j in range(len(ud))])
#		legends.append('param %d' % i)
#plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()
## around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 
#
#@torch.no_grad() # this decorator disables gradient tracking
#def split_loss(split):
#	x, y = {
#		'train': (Xtra, Ytra),
#		'val': (Xdev, Ydev),
#		'test': (Xtes, Ytes),
#	}[split]
#	emb = C[x] # (W, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
#	for layer in layers:
#		x = layer(x)
#	loss = F.cross_entropy(x, y)
#	print(split, loss.item())
#
## put layers into eval mode
#for layer in layers:
#	layer.training = False
#split_loss('train')
#split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchlineartanhsandwichinitnogain.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 1 #100/63
			# Now no gain is set 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
#ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	break

	#with torch.no_grad():
	#	ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('std dev shrinks. no gain to balance out tanh squashinng function')
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('gradients on graph beginning to shrink. will shrink faster, the lower the gain')
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2:
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	if p.ndim == 2:
#		plt.plot([ud[j][i] for j in range(len(ud))])
#		legends.append('param %d' % i)
#plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()
## around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 

@torch.no_grad() # this decorator disables gradient tracking
def split_loss(split):
	x, y = {
		'train': (Xtra, Ytra),
		'val': (Xdev, Ydev),
		'test': (Xtes, Ytes),
	}[split]
	emb = C[x] # (W, block_size, n_embd)
	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, y)
	print(split, loss.item())

# put layers into eval mode
for layer in layers:
	layer.training = False
split_loss('train')
split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchlineartanhsandwichinittoomuchgain.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 3 #100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
#ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	break

	#with torch.no_grad():
	#	ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('High saturation, more dead neurons')
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('gradients on graph beginning to increase. will increase faster, the higher the gain. Some assymetry')
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2:
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	if p.ndim == 2:
#		plt.plot([ud[j][i] for j in range(len(ud))])
#		legends.append('param %d' % i)
#plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()
## around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 
#
#@torch.no_grad() # this decorator disables gradient tracking
#def split_loss(split):
#	x, y = {
#		'train': (Xtra, Ytra),
#		'val': (Xdev, Ydev),
#		'test': (Xtes, Ytes),
#	}[split]
#	emb = C[x] # (W, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
#	for layer in layers:
#		x = layer(x)
#	loss = F.cross_entropy(x, y)
#	print(split, loss.item())
#
## put layers into eval mode
#for layer in layers:
#	layer.training = False
#split_loss('train')
#split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

#In context of deep learning the logits layer means the layer that feeds in to softmax (or other such normalization). 
#The output of the softmax are the probabilities for the classification task and its input is logits layer. The 
#logits layer typically produces values from -infinity to +infinity and the softmax layer transforms it to values 
#from 0 to 1.

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchlinearstacknogain.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) / fan_in**0.5
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

# Without tannh non-linearity in fwd pass essentially collapses to single linear layer. .e. sum(wx + b) == Wx + B. bkprop slightly different because of chain rule.
C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, n_hidden), #Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 1 #100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
#ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	break

	#with torch.no_grad():
	#	ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters])

	#if i >= 1000:
	#	break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
print('no gain now causes std dev to remain constant, because no tanh squashing function. saturation roughly constant, but quite high')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Linear):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
print('gradient now remains roughly constant at each layer in the graph statistics.')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Linear):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer
#
##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	t = p.grad
#	if p.ndim == 2:
#		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
#		hy, hx = torch.histogram(t, density=True)
#		plt.plot(hx[:-1].detach(), hy.detach())
#		legends.append(f'layer {i} ({layer.__class__.__name__}')
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()

##visualise histograms
#plt.figure(figsize=(20,4)) # width and height of the plot
#legends = []
#for i,p in enumerate(parameters): # note: exclude the output layer
#	if p.ndim == 2:
#		plt.plot([ud[j][i] for j in range(len(ud))])
#		legends.append('param %d' % i)
#plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
#plt.legend(legends)
#plt.title('weights gradient distribution')
#plt.show()
## around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 
#
#@torch.no_grad() # this decorator disables gradient tracking
#def split_loss(split):
#	x, y = {
#		'train': (Xtra, Ytra),
#		'val': (Xdev, Ydev),
#		'test': (Xtes, Ytes),
#	}[split]
#	emb = C[x] # (W, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
#	for layer in layers:
#		x = layer(x)
#	loss = F.cross_entropy(x, y)
#	print(split, loss.item())
#
## put layers into eval mode
#for layer in layers:
#	layer.training = False
#split_loss('train')
#split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitializationpytorchnokaimingnormalinit.py <==
#!/usr/bin/python3.8

import torch as torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#Let's train a deeper network

#Default parameters:
# 	bias=True, 		means layer will learn an additive bias
#	device=None 	default == CPU, can be CPU or GPU
#	dtype=None, 	default == float32
#torch.nn.Linear(in_features,out_features,bias=True,device=None,dtype=None)
class Linear:
	def __init__(self, fan_in, fan_out, bias=True): 		
		self.weight = torch.randn((fan_in, fan_out), generator=g) # / fan_in**0.5 no kaiming normal init for linear layer
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#Default parameters:
# 	dim = 			dimensionality (no default)
#	eps=1e-05, 		the epsilon is used in the division to normalize unit variance to avoid division by zero
#	momentum=0.1,   running mean and variance are updated at each batch using an exponential moving 
#					average with the momentum parameter as the smoothing factor. This means that the
#					running mean and variance are not updated immediately based on the current batch
#					statistics, but rather their values are slowly adjusted to be closer to the true
#					mean and variance over multiple batches. It is represented by 0.001 in the code below
#
#	with torch.no_grad():
#		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
#		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi
#
#					The momentum parameter typically has a value between 0 and 1, where a larger 
#					value means a faster update of the running mean and variance. However with a 
#					small batch size (such as 32) bnmeani and bnstdi in the equation above might 
#					not be close to to the true bnmean and bnstd, which would result in instability
#					for a large momentum value such as 0.1
# 	affine=True, 	default uses a Gamma and Beta after initialization 
#	track_running_stats=True, will keep track of running_mean and a running_variance, some extra compute
#					time involved in adjusting bnmean_running and bnstd_running, so may want to set false
#	device=None 	default == CPU, other choice is GPU
#	dtype=None, 	default == float32
#torch.nn.BatchNorm1d(num_features,eps=1e-05,momentum=0.1,affine=True,track_runningstats=True,device=None,dtype=None)
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			xmean = x.mean(0, keepdim=True) #batch mean
			xvar = x.var(0, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		# update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	def parameters(self):
		return []

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 100 # the number of neurons in the hidden layer of the MLP
g = torch.Generator().manual_seed(2147483647) # for reproducibility

C = torch.randn((vocab_size, n_embd), generator=g)
layers = [
	Linear(n_embd * block_size, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, n_hidden), Tanh(),
	Linear(n_hidden, vocab_size),
# Above Used for visualising histograms and the way changes impact them
# Usual init includes batch_normalization step between linear layer and non-linear transform
#	Linear(n_embd * block_size, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, n_hidden), BatchNorm1d(n_hidden), Tanh(),
#	Linear(n_hidden, vocab_size), BatchNorm1d(vocab_size),
]

with torch.no_grad():
	# last layer: make less confident
	layers[-1].weight *= 0.1 # without batch normalization layer
	#layers[-1].gamma *= 0.1 # with batch normalization, gamma is multiplicatively tied to output 
	# all other layers: apply gain
	for layer in layers[:-1]:
		if isinstance(layer, Linear):
			layer.weight *= 100/63
			# this is necessary as the tanh is a squashing function, will tend towards zero 

parameters = [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time 
max_steps = 20000
batch_size = 32
lossi = []
ud = []  #update to data ratio (amount data is shifting comparative to value)

for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g) #returns a tensor, 1st parameter bottom of range, 2nd top of range, 3rd size, generator=seed 
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	x = emb.view(emb.shape[0], -1) # concatenate the vectors
	for layer in layers:
		x = layer(x) # getting final output
	loss = F.cross_entropy(x, Ybat) # loss function
	
	#backward pass
	for layer in layers:
		layer.out.retain_grad() # AFTER_DEBUG: would take out retain_grad
	for p in parameters:
		p.grad = None
	loss.backward()

	# update
	#lr = 0.001 #too low, results in a very low ud (update-data ratio), around 10E-4, training too slow
	#lr = 10 #too high, results in very high ud (update-data ratio), may lead to large instability
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats for visualizations further down
	if i % 100 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())
	with torch.no_grad():
		ud.append([(lr*p.grad.std() /p.data.std()).log10().item() for p in parameters]) 
		#divides learning rate * stddev of gradient by stddev of data, log10 to look at exponents of division,, and .item() to pop out float 

	if i >= 1000:
		break # AFTER_DEBUG: would take out obviously to run full optimization

#visualize histograms
plt.figure(figsize=(20, 4)) # width and height of the plot
legends = []
print('too much saturation without kaiming normalization. A lot of dead neurons')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out
		print('layer %d (%10s): mean %+.3f, std %.2f, saturated: %.2f%%' % (i, layer.__class__.__name__, t.mean(), t.std(), (t.abs() > 0.97).float().mean()*100))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('activation distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
print('Messed up, no unit gaussian distributions')
for i, layer in enumerate(layers[:-1]): # note: exclude the output layer
	if isinstance(layer, Tanh):
		t = layer.out.grad
		print('layer %d (%10s): mean %+f, std %e' %  (i, layer.__class__.__name__, t.mean(), t.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('gradient distribution')
plt.show()
# will notice if you change the 5/3 gain factor that the gradients and stddev of histograms will
# vary by layer

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
print('Messed up gradient-data ratio')
for i,p in enumerate(parameters): # note: exclude the output layer
	t = p.grad
	if p.ndim == 2: #parameters constrained to just Linear layer weights.
		print('weight %10s | mean %+f | std %e | grad:data ratio %e' % (tuple(p.shape), t.mean(), t.std(), t.std()/p.std()))
		hy, hx = torch.histogram(t, density=True)
		plt.plot(hx[:-1].detach(), hy.detach())
		legends.append(f'layer {i} ({layer.__class__.__name__}')
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()

#visualise histograms
plt.figure(figsize=(20,4)) # width and height of the plot
legends = []
print('Messed up ud update-data ratio. No consistency between layers')
for i,p in enumerate(parameters): # note: exclude the output layer
	if p.ndim == 2: #parameters constrained to just Linear layer weights
		plt.plot([ud[j][i] for j in range(len(ud))])
		legends.append('param %d' % i)
plt.plot([0, len(ud)], [-3, -3], 'k') # these ratios should be ~le-3, indicative line on plot
plt.legend(legends)
plt.title('weights gradient distribution')
plt.show()
# around 10**(-3) is about right for update-data ratio in this case. 10**(-1)ish too high, 10**(-5)ish too low 

@torch.no_grad() # this decorator disables gradient tracking
def split_loss(split):
	x, y = {
		'train': (Xtra, Ytra),
		'val': (Xdev, Ydev),
		'test': (Xtes, Ytes),
	}[split]
	emb = C[x] # (W, block_size, n_embd)
	x = emb.view(emb.shape[0], -1) # concat into (W, block_size * n_embd)
	for layer in layers:
		x = layer(x)
	loss = F.cross_entropy(x, y)
	print(split, loss.item())

# put layers into eval mode
for layer in layers:
	layer.training = False
split_loss('train')
split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(2147483647 + 10)

for _ in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = emb.view(emb.shape[0], -1)

		#for i,p in enumerate(parameters):
		#	if p.ndim == 2:
		#		print(p.shape)

		for layer in layers:
			x = layer(x)

		logits = x
		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item() # 1st para(tensor) == input, 2nd para(num_samples). Returns tensor where each 
		# row contains 'num_samples' indices sampled from the multinomial probability distribution in the corresponding row of tensor 'input'
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)
		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))


==> makemore3/nninitialization.py <==
#!/usr/bin/python3.8

import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random 

##### Simple network training results 
# train		 - 2.12
# validation - 2.16
#
# fix softmax confidently wrong i.e. minimize weight distribution by W2 * 0.01, b2 * 0.1
# train		 - 2.07
# validation - 2.13
#
# fix tanh layer too saturated at init i.e. W1 * 0.1, b1 * 0
# train		 - 2.04
# validation - 2.10
#
# with single layer batch norm (not so effective on single-layer network)
# train		 - 2.06
# validation - 2.10
#

words = open('names.txt', 'r').read().splitlines()
#print(words[:8])
#print(len(words))

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)
print(itos)
print(vocab_size)

# build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []
	
	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append
	
	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))

Xtra, Ytra = build_dataset(words[:n1])		# 80%
Xdev, Ydev = build_dataset(words[n1:n2])	# 10%
Xtes, Ytes = build_dataset(words[n2:])		# 10%

#MLP revisited
n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 300 # the number of neurons in the hidden layer of the MLP

g = torch.Generator().manual_seed(2147483647) # for reproducibility
C = torch.randn((vocab_size, n_embd), generator=g)
# At initialization large values lead to many neurons in the hidden layer being
# initialized as dead in either the 1 or -1 regions of the tanh graph, which means
# they will no longer have an effect on backpropagation or improving the error 
# minimization. This is minimized by multiplying by a small scalar such as 0.1 
#W1 = torch.randn((n_embd * block_size, n_hidden), generator=g) * 0.1

# stddev = gain/sqrt(fan_in) 
# gain for tanh is 5/3, fan_in in this case is 30 (n_embd * block_size), opposes the 'squashing' property of the tanh funnction
# For ReLU it discards half of the distribution by clamping at zero so in that case gain is sqrt(2)
# these muliplicative gain factors renormalise the gaussian distribution to unit stddev i.e. (1 * stddev)

#In order to optimize initialization for potentially complex multi-layered network:
# We equalise the stddev of input and output gaussian distributions, to prevent dead neurons being generated. in the case of tanh fan_in is the number of input elements, which in this case is 30 i.e sqrt(fan_in) == 30**2. This is based on the initialization derived in Kaiming et. al (2015), which has become the most common way of initializing neural networks
#torch.nn.init.kaiming_normal_(tensor,a=0,mode='fan_in',nonlinearity='leaky_relu')

#the recommended gain value for a given nonlinearity function can be returned from  the torch api guide under torch.nn.init. This gain is a result of the 'tanh' squashing function, and is needed to renormalise the distribution to unit stddev. 
# 5/3 gain in the tanh comes from the average value of tanh^2(x) where x is distributed as a Gaussian, i.e. integrate (tanh x)^2*exp(-x^2/2)/sqrt(2*pi) from -inf to inf ~= 0.39. The square root of this value is how much the tanh squeezes the variance of the incoming variable: 0.39 ** .5 ~= 0.63 ~= 3/5 (hence 5/3 is an approximation).
# We then multiply by the gain to keep the output variance 1.

#fan_in = n_embd * block_size
#fan_out = n_hidden
W1 = torch.randn((n_embd * block_size, n_hidden), generator=g) * (100/63) / ((n_embd * block_size) ** 0.5)
#W1 = torch.randn((n_embd * block_size, n_hidden), generator=g) * (100/63) / (30 ** 0.5)
def old_bias():
	# can now get rid of this bias due to batch normalization, as bn removes this bias, then adds its own bias
	b1 = torch.randn((n_hidden), generator=g) * 0.01 
	
#At initialization randn() means certain letters have random probablilities of occurence which result in high loss - to minimize this we add * 0 to the bias here and * 0.01 to the weights. This is before bn, and is done empirically. We do not want to set this to exactly zero
W2 = torch.randn((n_hidden, vocab_size), generator=g) * 0.01
b2 = torch.randn((vocab_size), generator=g) * 0.1

# In batch normalization, "scale" and "shift" refer to learnable parameters that are used to adjust the normalized values before they are passed through the activation function. "Scale" parameter is used to adjust the normalized values' magnitude, while "shift" parameter is used to adjust their mean. These parameters help to reintroduce non-linearity into the model and make it more expressive, which can improve its performance.

#Actually, in batch normalization, the terms "scale" and "shift" refer to additional learnable parameters that are used to transform the normalized values, not to adjust their magnitude or mean.

#During the batch normalization process, the input values are normalized by subtracting the batch mean and dividing by the batch standard deviation. After normalization, the transformed values are obtained by scaling and shifting them using the "scale" and "shift" parameters, respectively. These parameters are learned during the training process and allow the model to adaptively adjust the normalized values to better fit the desired output.

#The "scale" parameter is responsible for scaling the normalized values. It helps to control the magnitude of the output and allows the model to learn different scaling factors for each feature or channel. By scaling the normalized values, the model can amplify or diminish certain features as needed.

#The "shift" parameter, also known as the "bias" parameter, is responsible for shifting the normalized values. It helps to reintroduce the mean information that was initially subtracted during normalization. By shifting the normalized values, the model can restore the original mean and allow the network to learn a new mean specific to the task.

#By using the "scale" and "shift" parameters, batch normalization introduces additional flexibility and expressiveness to the model, enabling it to learn more complex relationships between the input and output. This can lead to improved performance and faster convergence during training.

# these will be trained along with the rest of the neural network through backpropagation
# n_hidden = fan_out (n outputs) from linear layer preceding, fan_in (n inputs) for next layer
bngain = torch.ones((1, n_hidden)) # scale
bnbias = torch.zeros((1, n_hidden)) # shift

# these are altered without backpropagation within the forward pass
bnmean_running = torch.zeros((1, n_hidden))
bnstd_running = torch.ones((1, n_hidden))

parameters = [C, W1, W2, b2, bngain, bnbias]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

# same optimization as last time
max_steps = 200000
batch_size = 64
lossi = []

# Follows pattern: Linear Layer->Batch Normalization Layer(1D)->Non-Linearity(tanh). This is a repeated pattern 
# in Neural networks. Similar can be seen in resnet (which is neural network used for image classification)
# pattern where there is: Convolutional Layer->Batch Normalization Layer(2D)->Non-Linearity(ReLU)
for i in range(max_steps):
	# minibatch construct
	ix = torch.randint(0, Xtra.shape[0], (batch_size,), generator=g)
	Xbat, Ybat = Xtra[ix], Ytra[ix] # batch X,Y

	# forward pass
	emb = C[Xbat] # embed the characters into vectors
	embcat = emb.view(emb.shape[0], -1) # concatenate the vectors
	
	## Linear Layer ##
	hlpreact = embcat@ W1 #+ b1 # hidden layer pre-activation
	
	if i == 0:
		print(hlpreact.mean(0, keepdim=True).shape) # torch.Size([1, 200])
		print(hlpreact.std(0, keepdim=True).shape) # torch.Size([1, 200])

	# batch normalization normalizes the inputs to each layer to unit Gaussian. This is
	# achieved by computing the mean and variance of the inputs over a mini-batch of 
	# training examples and using the statistics to normalize the inputs. This step
	# helps to stabilize the distribution of inputs to each layer, which can accelerate
	# the training process by reducing the vanishing gradient problem and allowing for 
	# use of higher learning rates. Additionally, Batch Normalization can have a 
	# regularization effect by reducing the generalization error of the model	
	
	## Batch Normalization Layer ##
	bnmeani = hlpreact.mean(0, keepdim=True)
	bnstdi = hlpreact.std(0, keepdim=True)

	def batchnormalizeatinitialization():
		# normalizes batch, makes unit gaussian distribution, but needs edit to allow backprop to afect weights
		# do not want this to be forced to be completelly gaussian all of the time
		hlpreact = bngain * hlpreact / bnstdi

	# adds shift and gain to normalized layer to allow backprop to alter the batchnorm layer's output
	hlpreact = bngain * (hlpreact - bnmeani) / bnstdi + bnbias 

	with torch.no_grad():
		bnmean_running = 0.999 * bnmean_running + 0.001 * bnmeani
		bnstd_running = 0.999 * bnstd_running + 0.001 * bnstdi

	# because of the use of mean and stddev individual weights are affected by every example in the batch
	# which tends to prevent overfitting, and has a 'regularizing' effect
	
	## Non-linearity ##
	hl = torch.tanh(hlpreact) # hidden layer
	logits = hl @ W2 + b2 # output layer
	if i == 0:
		print("logits.shape")
		print(logits.shape)

	loss = F.cross_entropy(logits, Ybat) # loss function
	
	if i == 1:
		print("Ybat.shape = ")
		print(Ybat.shape)

	# no changes to the original initialization of the hidden layer i.e
	#	hlpreact = embcat@ W1 + b1 # hidden layer pre-activation
	#	hl = torch.tanh(hlpreact) # hidden layer
	# leads to most values in the hidden layer being initialised as either 1 or -1 
	# (shown in the histogram below). This is a potential issue
	#
	if i == 0:
		plt.hist(hl.view(-1).tolist(), 50)
		plt.show()
	#
	# the tanh function squashes weights and biases into the region between 1 and -1
	# if anything is too positive or negative they end up by default in the 'flat' 
	# region of the tanh curve. When backprop occurs, can when attempting to alter
	# the gradient, it can still end up in the 1 or -1 region and therefore have no
	# effect on the neural network see backward() function for tanh in micrograd
	# 
	# def tanh(self):
	# 	n = self.data
	# 	t = (math.exp(2*n) - 1)/(math.exp(2*n) + 1)
	# 	out = Value(t, (self, ), 'tanh')
	#
	# 	def _backward():
	# 		self.grad += (1 - t**2) * out.grad 
	# 
	# Can visualise which neuronal paths are susceptible to this by examining the
	# below plot (white sections):
	#
	##if i % 10000 == 0:
	##	plt.figure(figsize=(20,10))
	##	plt.imshow(hl.abs() > 0.99, cmap='gray', interpolation='nearest')
	##	plt.show()
	#
	# These neurons which always fire 1 or -1 are 'dead' neurons as they will not
	# actually affect the backpropagation. Any activation function with a flat part
	# i.e. tanh, sigmoid, ReLU and ELU can all suffer from 'dead' neurons, which are
	# in the flat part of the graph and never activate. Leaky ReLU doesn't suffer 
	# from this issue. By multiplying W1 and b1 by 0.1 and 0.01 respectively to reduce 
	# the stddev/variance, and those 'extreme' values that are squashed to 1 and -1 we 
	# can alleviate this issue. This is an empirical way of doing it and batch normalization
	# and other normalization techniques are more of a 'scientific' way of acheiving the same result. 

	## Backward Pass ##
	for p in parameters:
		p.grad = None 	#reset gradients
	loss.backward()

	## Update ##
	lr = 0.1 if i < 100000 else 0.01 # learning rate decay
	for p in parameters:
		p.data += -lr * p.grad

	# track stats
	if i % 10000 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

plt.plot(lossi)
plt.show()

@torch.no_grad()  # this decorator disables gradient tracking (i.e. assumes it never requires a gradient) - can also use a context manager with torch.no_grad()
def split_loss(split):
	x, y = {
		'train': (Xtra, Ytra),	# training
		'val':	 (Xdev, Ydev),	# validation
		'test':	 (Xtes, Ytes),	# test
	}[split]
	emb = C[x] # (N, block_size, n_embd)
	embcat = emb.view(emb.shape[0], -1) # concat into (N, block_size * n_embd)
	h = embcat @ W1 #+ b1 # (N, n_hidden)
	h = bngain * (h - bnmean_running)/bnstd_running + bnbias
	h = torch.tanh(h)
	logits = h @ W2 + b2 # (N, vocab_size)
	loss = F.cross_entropy(logits, y)
	print(split, loss.item())

split_loss('train')
split_loss('val')

# sample from the model
g = torch.Generator().manual_seed(42)

for tx in range(20):
	out = []
	context = [0] * block_size # intialize with all ...
	while True:
		# forward pass the neural net
		emb = C[torch.tensor([context])] # (1,block_size, n_embd) == (1, 3, 10)
		x = torch.tanh(emb.view(1, -1) @ W1) # (1,30) @ (30, 200) == (1,200)
		logits = x @ W2 + b2 # (1, 200) @ (200, 27) == (1, 27)

		probs = F.softmax(logits, dim=1) # normalize (1, 27)
		ix = torch.multinomial(probs, num_samples=1, generator=g).item()
		if tx == 0 and ix == 0:
			print("emb.view(1,-1)..shape")
			print(emb.view(1, -1).shape)
			print("W1.shape")
			print(W1.shape)
			print("x.shape")
			print(x.shape)
			print("W2.shape")
			print(W2.shape)
			print("logits.shape")
			print(logits.shape)
			print("probs.shape")
			print(probs.shape)
		# sample from the distribution
		# shift the context window and track the samples
		context = context[1:] + [ix]
		out.append(ix)

		# if we sample the special '.' token, break 
		if ix == 0:
			break

	print(''.join(itos[i] for i in out))

#In order to optimize initialization for potentially complex multi-layered network:
# If no changes are made the  gaussian distribution of yt has expanded by around 3, as evidenced by standard dev. The actual scalar to be used to equalise the input
#and output gaussian distiributions in this case is roughly equal to the sqrt of the number of input elements, which in this case is 10 i.e * 10**0.5. This is based on the initialization derived in Kaiming et. al (2015), whiich has become the most common way of initializing neural networks
# found in 
#torch.nn.init.kaiming_normal_(tensor,a=0,mode='fan_in',nonlinearity='leaky_relu')

def showhistogramspreading():
	xt = torch.randn(1000, 10) # normal (gaussian) distribution
	w1 = torch.randn(10, 100) 
	y1 = xt @ w1 # obtains pre-activation values for neurons
	# non-linearities tend to change gaussian distribution range, want to combat either it spreading
	# to infinity or collapsing to zero.
	print(xt.mean(), xt.std()) 	# tensor(-0.0099) tensor(0.9861), roughly mean == 0, stddev == 1 (unit gaussian)
	print(y1.mean(), y1.std()) 	# tensor(-0.0003) tensor(3.0996), mean still at zero but stddev incrrease to 3
	# above shows histogram's range (gaussian distribution range) spreading which can lead to dead
	# neurons. to fix this divide by sqrt(fan_in)
	plt.figure(figsize=(20, 5))
	plt.subplot(121)
	plt.hist(xt.view(-1).tolist(), 50, density=True)
	plt.subplot(122)
	plt.hist(y1.view(-1).tolist(), 50, density=True)
	plt.show()
	
	wt = torch.randn(10, 100) / 10**0.5 # fixed normal gaussian distribution by dividing by sqrt(fan_in)
	yt = xt @ wt # obtains pre-activation values for neurons

# Under the documentation for torch.nn there is a batch normalization procedure which has both 1D
# And 2D initialization for Batch normalization. There are many different types of normalization
# such as group normalization, layer normalization, distance normalization, etc. which have become
# used more often in newer types of deep-learning, and avoid some of the issues associated with batch
# normalization caused by the 'group-effect' of batch parameters by use of mean and standard deviation for the batch.

==> makemore5/wavenet.py <==
#!/usr/bin/python3.8

import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
import random

#read in all the words
words = open('names.txt', 'r').read().splitlines()
#print(len(words))
#print(max(len(w) for w in words))
#print(words[:8])

chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)
#print(itos)
#print(vocab_size)

#shuffle up the words
random.seed(42)
random.shuffle(words)

#build the dataset
block_size = 8 # context length: how many characters do we take to predict the next one

def build_dataset(words):
	X, Y = [], []

	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append

	X = torch.tensor(X)
	Y = torch.tensor(Y)
	print(X.shape, Y.shape)
	return X, Y

n1 = int(0.8 * len(words))
n2 = int(0.9 * len(words))
Xtr,  Ytr  = build_dataset(words[:n1])
Xdev, Ydev = build_dataset(words[n1:n2])
Xte,  Yte  = build_dataset(words[n2:])

for x,y in zip(Xtr[:20], Ytr[:20]):
	print(''.join(itos[ix.item()] for ix in x), '-->', itos[y.item()])

#THE MATRIX MULTIPLICATION OPERATOR CAN ALSO ACT ON N-DIMENSIONAL MATRICES i.e.
#torch.Size([4, 5, 6, 80]) @ torch.Size([80, 200]) + torch.Size([200]) == torch.Size([4, 5, 6, 200])

#we now want to group the 8 characters coming in as follows: (1 2) (3 4) (5 6) (7 8)
#so we now want to change the flatten layer so it outputs a torch.Size([4, 4, 20])
#we also need to change our linear layer so it now expects 20 inputs i.e. torch.Size([20, 200]
#so now it should be:
#torch.Size([4, 4, 20]) @ torch.Size([20, 200]) + torch.Size([200]) == torch.Size([4, 4, 200])

#list(range(10))[0::2]
#[0, 2, 4, 6, 8]
#list(range(10))[1::2]
#[1, 3, 5, 7, 9]

#e = torch.randn(4, 8, 10) # goal: want this to be torch.Size([4, 4, 20]) where consecutive 10-d vectors get concatenated
#explicit = torch.cat([e[:, ::2, :], e[:, 1::2, :]], dim=2).shape. #will concatenate the two lists of alternating 10-d vectors into a (4, 4, 20)
#(e.view(4, 4, 20) == explicit).all() # will return True, view operation also concatenates consecutive vectors

#previous iteration of BatchNorm layer assumed n was 2-dimensional, so only deduced mean and variance over dimesion==0
#as x has become 3-dimensional BatchNorm needs to be rewritten. Appears to work, because of Broadcasting, what's really happening is if:
# e = torch.randn(32, 4, 68)
# emean = e.mean(0, keepdim=True) ## ==(1, 4, 68) only takes mean of dimension == 0
# evar = e.var(0, keepdim=True) ## ==(1, 4, 68) only takes variance of dimension == 0
# ehat = (e - emean) / torch.sqrt(evar + 1e-5) ## ==(32, 4, 68), broadcasting makes everything look as if it is working correctly

# model.layers[3].running_mean.shape ## result is torch.Size([1, 4, 68]) for prev iteration of BatchNorm
# model.layers[3].running_var.shape ## result is torch.Size([1, 4, 68]) for prev iteration of BatchNorm
# for each we should only have 68 examples of mean and variance i.e. (1, 1, 68) instead of treating 4 channels separately
# torch.mean can either take an int or a tuple of ints  (which specifies dimension(s) to take mean on)
# emean = e.mean((0, 1), keepdim=True) ## (1, 1, 68) only takes mean of dimensions == 0 and 1
# evar = e.var((0, 1), keepdim=True) ## (1, 1, 68) only takes variance of dimension == 0 and 1

#-------------------------------------------------------------------------
class Linear:
	def __init__(self, fan_in, fan_out, bias=True):
		self.weight = torch.randn((fan_in, fan_out)) / fan_in**0.5 # note: kaiming init
		self.bias = torch.zeros(fan_out) if bias else None

	def __call__(self, x):
		self.out = x @ self.weight
		if self.bias is not None:
			self.out += self.bias
		return self.out

	def parameters(self):
		return [self.weight] + ([] if self.bias is None else [self.bias])

#-------------------------------------------------------------------------
class BatchNorm1d:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		self.momentum = momentum
		self.training = True
		#parameters (trained with backprop)
		self.gamma = torch.ones(dim)
		self.beta = torch.zeros(dim)
		#buffers (trained with a running 'momentum update - exponential moving average')
		self.running_mean = torch.zeros(dim)
		self.running_var = torch.ones(dim)

	def __call__(self, x):
		#calculate the forward pass
		if self.training:
			if x.ndim == 2:
				dim = 0
			elif x.ndim == 3:
				dim = (0,1)
			xmean = x.mean(dim, keepdim=True) # batch mean
			xvar = x.var(dim, keepdim=True) # batch variance
		else:
			xmean = self.running_mean
			xvar = self.running_var
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance i.e. var == 1
		self.out = self.gamma * xhat + self.beta
		#Update the buffers
		if self.training:
			with torch.no_grad():
				self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * xmean
				self.running_var = (1 - self.momentum) * self.running_var + self.momentum * xvar
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

#-------------------------------------------------------------------------
class Tanh:
	def __call__(self, x):
		self.out = torch.tanh(x)
		return self.out
	
	def parameters(self):
		return []

#-------------------------------------------------------------------------
class Embedding:
	def __init__(self, num_embeddings, embedding_dim):
		self.weight = torch.randn((num_embeddings, embedding_dim)) #Generates a num_embeddings*embedding_dim tensor

	def __call__(self, IX):
		self.out = self.weight[IX]
		return self.out

	def parameters(self):
		return [self.weight]

#-------------------------------------------------------------------------
#NOW ALTERED FROM ITS ORIGINAL IMPLEMENTATION
class FlattenConsecutive:
	def __init__(self, n): # n == number of elements to concatenate in last dimension of output
		self.n = n

	def __call__(self, x):
		B, T, C = x.shape # In initial toy example B is 4, T is 8 and C is 10
		x = x.view(B, T//self.n, C*self.n) # where C*n is number of consecutive elements to concatenate in last dimension. 
		# T//n is an integer division (// == special symbol)
		if x.shape[1] == 1: #where dim==1 is T//self.n
			x = x.squeeze(1)
		self.out = x
		return self.out

	def parameters(self):
		return []

#-------------------------------------------------------------------------
class Sequential:
	def __init__(self, layers):
		self.layers = layers

	def __call__(self, x):
		for layer in self.layers:
			x = layer(x)
		self.out = x
		return self.out

	def parameters(self):
		# get parameters of all layers and stretch them out into one list
		return [p for layer in self.layers for p in layer.parameters()]

torch.manual_seed(42) # seed rng for reproducibility

n_embd = 24 # the dimensionality of the character embedding vectors
#n_hidden = 68 # the number of neurons in the hidden layer of the MLP, changed to maintain total parameters
n_hidden = 200 # the number of neurons in the hidden layer of the MLP

model = Sequential([ # replaces layers = [
	# replaces C = torch.randn((vocab_size, n_embd)
	Embedding(vocab_size, n_embd), # Embedding : (4, 8, 10)
	FlattenConsecutive(2), # FlattenConsecutive : (4, 4, 20)
	Linear(n_embd * 2, n_hidden, bias=False), # Linear : (4, 4, 200)
	BatchNorm1d(n_hidden), # BatchNorm1d : (4, 4, 200)
	Tanh(), # Tanh : (4, 4, 200)
	FlattenConsecutive(2), # FlattenConsecutive : (4, 2, 400)
	Linear(n_hidden * 2, n_hidden, bias=False), # Linear : (4, 2, 200)
	BatchNorm1d(n_hidden), # BatchNorm1d: 4, 2, 200
	Tanh(), # Tanh : 4, 2, 200
	FlattenConsecutive(2), # FlattenConsecutive : (4, 400)
	Linear(n_hidden * 2, n_hidden, bias=False), # Linear: (4, 200)
	BatchNorm1d(n_hidden), # BatchNorm1d : (4, 200)
	Tanh(), # Tanh : (4, 200)
	Linear(n_hidden, vocab_size), # Linear : (4, 27)
])

# parameter init
with torch.no_grad():
	model.layers[-1].weight *= 0.1 # last layer make less confident

parameters = model.parameters() # replaces [C] + [p for layer in layers for p in layer.parameters()]
print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

#same optimization as last time
max_steps = 200000
batch_size = 32
lossi = []

##LOOKING AT A BATCH OF 4 EXAMPLES
#ix = torch.randint(0, Xtr.shape[0], (4,))
#Xb, Yb = Xtr[ix], Ytr[ix]
#logits = model(Xb)
#print(Xb.shape) # torch.Size([4,8])
#Xb #tensor([[ 2, 23, 19, 11,  5,  3, 20, 17],
## 	       	 [ 3, 14,  8, 20,  5,  3, 21, 10],
##   	     [16, 18, 12, 19, 25,  2,  9, 20],
##       	 [17, 13, 19, 18,  8,  3,  8, 23]])
#model.layers[0].out.shape # output of Embedding layer - torch.Size([4, 8, 10])
#model.layers[1].out.shape # output of Flatten layer - torch.Size([4, 80])
#model.layers[2].out.shape # output of Linear layer - torch.Size([4, 200])
##WHAT HAPPENS INSIDE THE LINEAR LAYER IS AS FOLLOWS
##torch.Size([4, 80]) @ torch.Size([80, 200] + torch.Size([200]) == torch.Size([4, 200])

##WITH OLD CHANGES
#ix = torch.randint(0, Xtr.shape[0], (4,))
#Xb, Yb = Xtr[ix], Ytr[ix]
#logits = model(Xb)
#print(Xb.shape) # torch.Size([4,8])
#Xb #tensor([[ 2, 23, 19, 11,  5,  3, 20, 17],
## 	       	 [ 3, 14,  8, 20,  5,  3, 21, 10],
##   	     [16, 18, 12, 19, 25,  2,  9, 20],
##       	 [17, 13, 19, 18,  8,  3,  8, 23]])
#
# for layer in model.layers:
#	print(layer.__class__.__name__, ':', tuple(layer.out.shape))
#RESULT:Embedding : (4, 8, 10)
#		Flatten : (4, 80)
#		Linear : (4, 200)
#		BatchNorm1d : (4, 200)
#		Tanh : (4, 200)
#		Linear : (4, 27)

for i in range(max_steps):
	#minibatch construct
	ix = torch.randint(0, Xtr.shape[0], (batch_size,)) #torch.randint(low, high, size)
	Xb, Yb = Xtr[ix], Ytr[ix] # batch X,Y

	# forward pass
	logits = model(Xb)
	#OLD WAY BELOW:
#	x = Xb # replaces emb = C[Xb]; x = emb.view(emb.shape[0], -1)
#	for layer in layers:
#		x =  layer(x)
	loss = F.cross_entropy(logits, Yb)

	# backward pass
	for p in parameters:
		p.grad = None
	loss.backward()

	#update: simple stochastic gradient descent (SGD)
	lr = 0.1 if i < 150000 else 0.01
	for p in parameters:
		p.data += -lr * p.grad

	#track stats
	if i % 1000 == 0:
		print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

# torch.arange(10) # tensor([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
# torch.arange(10).view(2,5)
# tensor([[0, 1, 2, 3, 4],
#         [5, 6, 7, 8, 9]])
# torch.arange(10).view(5,2)
# tensor([[0, 1],
#         [2, 3],
#         [4, 5],
#         [6, 7],
#         [8, 9]])
# will autoocalculate shape if -1 is specified in place of one of the dimensions
#torch.arange(10).view(5,-1)
#tensor([[0, 1],
#        [2, 3],
#        [4, 5],
#        [6, 7],
#        [8, 9]])
#torch.arange(10).view(-1,2)
#tensor([[0, 1],
#        [2, 3],
#        [4, 5],
#        [6, 7],
#        [8, 9]])
#  

#torch.tensor(lossi).view(-1, 1000).shape # torch.Size([200, 1000])
#torch.tensor(lossi).view(-1, 1000).mean(1).shape #calculates mean along dimension 1 == torch.Size([200])
plt.plot(torch.tensor(lossi).view(-1, 1000).mean(1))
plt.show()

# put layers into eval mode (needed for batchnorm especially), else will cause prediction layer to fail as samples variance of 1 number which is 'nan'
for layer in model.layers:
	layer.training = False

# evaluate the loss
@torch.no_grad() #decorator that does the same as "with torch.no_grad():"
def split_loss(split):
	x,y = {
		'train': (Xtr, Ytr),
		'val': (Xdev, Ydev),
		'test': (Xte, Yte),
	}[split]
	logits = model(x)
	#OLD METHOD BELOW:
#	emb = C[x] # (N, block_size, n_embd)
#	x = emb.view(emb.shape[0], -1)
#	for layer in model.layers:
#		x = layer(x)
	loss = F.cross_entropy(logits, y)
	print(split, loss.item())

split_loss('train')
split_loss('val')

for _ in range(20):
	out = []
	context = [0] * block_size # initialize with all '...'s
	while True:
		logits = model(torch.tensor([context]))
		#OLD METHOD BELOW:
		# forward pass the neural net
##		emb = C[torch.tensor([context])] # (1,block_size,n_embd)
##		x = emb.view(emb.shape[0], -1) # concatenate the vectors
##		for layer in layers:
##			x = layer(x)
##		logits = x
		probs = F.softmax(logits, dim=1)
		# sample from the distribution
		ix = torch.multinomial(probs, num_samples=1).item() # torch.multinomial(input, num_samples)
		# returns a tensor where each row contains num_samples 'indices' sampled from the multinomial distribution located in the corresponding row of the tensor 'input'
		context = context[1:] + [ix]
		# shift the context window and track the samples
		out.append(ix)
		# if character is the special '.' token, break
		if ix == 0:
			break

	print(''.join(itos[i] for i in out)) # decode and print the generated word

==> makemore4/makemorebackprop.py <==
#!/usr/bin/python3.8

import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt 
import random

# read in all the words
words = open('names.txt', 'r').read().splitlines()
#print(len(words))
#print(max(len(w) for w in words))
#print(words[:8])

# build the vocabulary of characters and mappings to/from integers
chars = sorted(list(set(''.join(words))))
stoi = {s:i+1 for i,s in enumerate(chars)}
stoi['.'] = 0
itos = {i:s for s,i in stoi.items()}
vocab_size = len(itos)
#print(itos)
#print(vocab_size)

#build the dataset
block_size = 3 # context length: how many characters do we take to predict the next one?

def build_dataset(words):
	X, Y = [], []

	for w in words:
		context = [0] * block_size
		for ch in w + '.':
			ix = stoi[ch]
			X.append(context)
			Y.append(ix)
			context = context[1:] + [ix] # crop and append

	X = torch.tensor(X)
	Y = torch.tensor(Y)
	#print(X.shape, Y.shape)
	return X, Y

random.seed(42)
random.shuffle(words)
n1 = int(0.8*len(words))
n2 = int(0.9*len(words))

Xtr, Ytr = build_dataset(words[:n1]) # 80%
Xdev, Ydev = build_dataset(words[n1:n2]) # 10%
Xte, Yte = build_dataset(words[n2:]) # 10%

#utility function we will use later when comparing manual gradients to PyTorch gradients
def cmp(s, dt, t):
	ex = torch.all(dt == t.grad).item() # Returns True or False
	app = torch.allclose(dt, t.grad) # Returns True or False
	maxdiff = (dt - t.grad).abs().max().item()
	print(f'{s:15s} | exact: {str(ex):5s} | approximate: {str(app):5s} | maxdiff: {maxdiff}')

n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 64 # the number of neurons in the hidden layer of the MLP

g = torch.Generator().manual_seed(2147483647) # for reproducibility
C = torch.randn((vocab_size, n_embd), generator=g)
# Layer 1
W1 = torch.randn((n_embd * block_size, n_hidden), generator=g) * (5/3)/((n_embd * block_size)**0.5)
b1 = torch.randn(n_hidden, generator=g) * 0.1 #using b1 for traceability of gradients. b1 usually useless because batch normalization adds own bias, offsets it
# Layer 2
W2 = torch.randn((n_hidden, vocab_size), generator=g) * 0.1
b2 = torch.randn(vocab_size, generator=g) * 0.1 
# BatchNorm parameters
bngain = torch.randn((1, n_hidden)) * 0.1 + 1.0
bnbias = torch.randn((1, n_hidden)) * 0.1

# Note: I am initializing many of these parameters in non-standard ways because
# sometimes initializing with e.g. all zeros could mask an incorrect implementation
# of the backward pass

parameters = [C, W1, b1, W2, b2, bngain, bnbias]
#print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True # retains gradient for traceability

batch_size = 32
n = batch_size # a shorter variable for convenience
# construct a minibatch
ix = torch.randint(0, Xtr.shape[0], (batch_size,), generator=g)
Xb, Yb = Xtr[ix], Ytr[ix] # batch X,Y

# forward pass, "chunked" into smaller steps that are possible to backward one at a time
#longer than usual forward pass 
emb = C[Xb] # embed the characters into vectors
embcat = emb.view(emb.shape[0], -1) # concatenate the vectors
# Linear layer 1
hprebn = embcat @ W1 + b1 # hidden layer pre-batchnorm
# BatchNorm layer
bnmeani = 1/n+hprebn.sum(0, keepdim=True)
bndiff = hprebn - bnmeani
bndiff2 = bndiff**2
bnvar = 1/(n-1)*(bndiff2).sum(0, keepdim=True) # note: Bessel's correction (dviding by n-1, not n)
bnvar_inv = (bnvar + 1e-5)**-0.5
bnraw = bndiff * bnvar_inv
hpreact = bngain * bnraw + bnbias # hidden layer pre-activation
# Non-linearity
h = torch.tanh(hpreact) # hidden layer
# Linear layer 2
logits = h @ W2 + b2 # output layer
# cross entropy loss (same as F.cross_entropy(logits, Yb))
logit_maxes = logits.max(1, keepdim=True).values
norm_logits = logits - logit_maxes # subtract max for numerical stability, no 'inf'/'Nan', highest number is zero
counts = norm_logits.exp()
counts_sum = counts.sum(1, keepdims=True)
counts_sum_inv = counts_sum**-1 # if I use (1.0/counts_sum) instead then can't get backprop to be bit exact...
probs = counts * counts_sum_inv
logprobs = probs.log()
loss = -logprobs[range(n), Yb].mean() #Here range(n) is an iterator, Yb is a tensor of torch.Size([32]) containing indices 0-26, logprobs[range(n), Yb], pulls out 
#the log prob of the correct next character with respect to the character sequence (assigned at random at initiallization), then the mean takes the avg to calculate
#the loss which it minimizes by back-propagation. 

# PyTorch backward pass
for p in parameters:
	p.grad = None

for t in [logprobs, probs, counts, counts_sum, counts_sum_inv, norm_logits, logit_maxes, logits, h, hpreact, bnraw, bnvar_inv, bnvar, bndiff2, bndiff, hprebn, bnmeani, embcat, emb]:
	t.retain_grad()

loss.backward()

#===========================================================================

# Exercise 1: backprop through the whole thing manually, backpropagating through 
# exactly all the variables as they are defined in the fwd pass above, one by one

# =========================
# YOUR CODE HERE :)
# =========================

# all the 'd' variables below represent the differenials for loss with respect to the gradient for that value calculated in the backward pass manually
# we will check for 'correctness' with reference to what Pytorch says.. 

#loss = -logprobs[range(n), Yb].mean()
print(loss.shape) # torch.Size([])
print(logprobs.shape) # torch.Size([32, 27])
print(Yb.shape) # torch.size([32])
print(Yb) # index of correct next character for every batch example
# loss == -(a + b + c)/3 == (a + b + c) * -1/3 therefore dloss/da == -1/3 therefore dloss/dgeneral == -1/n 
# dlogprobs is of the same shape as logprobs i.e. torch.Size([32,27]). Only one element from each of the 32 rows affects the loss, (indices in Yb; torch.size([32])
# every other element in (d/dx) of this array is therefore 0, as if we were to change these numbers loss doesn't change (dy/dx == 0)
dlogprobs = torch.zeros_like(logprobs) # dlogprobs = torch.zeros([32,27])
#loss = -logprobs[range(n), Yb].mean() #Here range(n) is an iterator, Yb is a tensor of torch.Size([32]) containing indices 0-26, logprobs[range(n), Yb], pulls out 
#elements in logprobs, using every example in our batch i.e. rows in range(n) (1-32). Then at each row (1-32), the index specified in Yb (1-27), represents
#the correct next character with respect to the character sequence preceding it, so our loss is calculated on the probability of the next correct character only.
dlogprobs[range(n), Yb] = -1.0/n # sets locations to 1/batch_size at indices that are correct next letter, i.e. wherever they are affecting the loss function
# because we are using the negative mean -(1.0/n), every cell in dlogprobs[range(n), Yb] affects the loss equally by -(1.0/n), (d/da)ab == b
cmp('logprobs', dlogprobs, logprobs)

#logprobs = probs.log()
print(probs.shape) # torch.Size([32, 27])
dprobs = probs ** -1 # (d/dx)log(x) == 1/x
dprobs *= dlogprobs # Chain rule
cmp('probs', dprobs, probs)

#probs = counts * counts_sum_inv
print(counts_sum_inv.shape) # torch.Size([32, 1])
print(counts.shape) # torch.Size([32, 27])
dcounts = counts_sum_inv * dprobs # Chain rule && (d/da)ab == b
dcounts_sum_inv = (counts * dprobs).sum(1, keepdims=True) # Chain rule && (d/da)ab == b && sum of fan_in to maintain dimensionality
cmp('counts_sum_inv', dcounts_sum_inv, counts_sum_inv)

#counts_sum_inv = counts_sum**-1 # if I use (1.0/counts_sum) instead then I can't get backprop to be bit exact...
print(counts_sum.shape) # torch.Size([32, 1])
dcounts_sum = -(counts_sum ** -2) * dcounts_sum_inv # Chain rule && (d/da)a**b == ba**(b-1)
cmp('counts_sum', dcounts_sum, counts_sum)

#counts_sum = counts.sum(1, keepdims=True)
print((torch.ones_like(counts) * dcounts_sum).shape) # torch.Size([32, 1])
dcounts += torch.ones_like(counts) * dcounts_sum # Chain rule && (d/da)a+b == 1 && broadcasting maintains dimensionality
cmp('counts', dcounts, counts)

#counts = norm_logits.exp()
print(norm_logits.shape)
dnorm_logits = counts * dcounts # Chain rule && (d/dx)e**x == e**x
cmp('norm_logits', dnorm_logits, norm_logits)

#norm_logits = logits - logit_maxes # subtract max for numerical stability
#c11 c12 c13 = a11 a12 a13 - b1 #(broadcast)
#c21 c22 c23 = a21 a22 a23 - b2 #(broadcast)
#c31 c32 c33 = a31 a32 a33 - b3 #(broadcast)
#norm_logits represented by c, logits represented by a, logit_maxes represented by b therefore requires a negative
print(logits.shape)
print(logit_maxes.shape)
dlogit_maxes = (-dnorm_logits).sum(1, keepdim=True) # Chain rule, (d/db)a-b == -1  maintains negative sign and sum of fan_in to maintain dimensionality   
dlogits = dnorm_logits.clone() # Chain rule, (d/da)(a-b) == 1, maintains postive sign   
cmp('logit_maxes', dlogit_maxes, logit_maxes)
#logit_maxes doesn't impact final loss, it is simply done to ensure numerical stability during softmax function. Therefore dlogit_maxes should be zero
#or because of floating point inaccuracies, very close to zero.

#logit_maxes = logits.max(1, keepdim=True).values
print(logits.max(1))
#max returns values and indices where maxes occur. in backward pass indices are useful. dlogit_maxes should be scattered to the correct position from which the
#logits_max came in the original logits tensor. Can be done in the same way dlogprobs was populated i.e. dlogprobs[range(n), Yb] = -1.0/n, or done in the
#way it is below, by using one hot encoding. local derivative should be one for the appropriate max. should then be multiplied by dlogit_maxes
plt.imshow(F.one_hot(logits.max(1).indices, num_classes=logits.shape[1]))
plt.show()
dlogits += F.one_hot(logits.max(1).indices, num_classes=logits.shape[1]) * dlogit_maxes # Chain rule && what is mentioned above && other effect of logits on loss
cmp('logits', dlogits, logits)

#logits = h @ W2 + b2 # output layer
# SHAPES: ([32,27]) = ([32, 64]) @ ([64, 27]) + ([27]) # where @ represent dot product matrix multiplication (rows * columns)
# In broadcasting the bias column vector ([27]) will first become a row vector ([1,27]) then be broadcast vertically to match the shape of the dot product ([32,27])
# MATRIX MULTIPLICATION AND ADDITION
# d = a @ b + c
# _     _     _     _  _     _       _   _
#|d11 d12|  =|a11 a12||b11 b12|  +  |c1 c2|
#|d21 d22|   |a21 a22||b21 b22|     |c1 c2|
#--     --   --    --  --   --      --   --
# Therefore:
# d11 = a11*b11 + a12*b21 + c1
# d12 = a11*b12 + a12*b22 + c2
# d21 = a21*b11 + a22*b21 + c1
# d22 = a21*b12 + a22*b22 + c2
# Therefore now have differentiable operations. We already know (dL/dd) for each case:
# (dL/da)a11 = (dL/dd)d11*b11 + (dL/dd)d12*b12 # deriving derivative of loss with respect to a11. uses (d/da)ab == b && chain rule && summing partial derivatives
# (dL/da)a12 = (dL/dd)d11*b21 + (dL/dd)d12*b22 # deriving derivative of loss with respect to a12. uses (d/da)ab == b && chain rule && summing partial derivatives
# (dL/da)a21 = (dL/dd)d21*b11 + (dL/dd)d22*b12 # deriving derivative of loss with respect to a21. uses (d/da)ab == b && chain rule && summing partial derivatives
# (dL/da)a22 = (dL/dd)d21*b21 + (dL/dd)d22*b22 # deriving derivative of loss with respect to a22. uses (d/da)ab == b && chain rule && summing partial derivatives
# This can then be expressed as the matrix multipcation dL/dd @ b.transpose (which is written as b.T)
# _                   _  _     _
#|(dL/dd)d11 (dL/dd)d12||b11 b21|
#|(dL/dd)d21 (dL/dd)d22||b12 b22|
#--                   ----     --
# This rule can be generalised to our initial expression: logits = h @ W2 + b2 where we already know dlogits
print(h.shape)
print(W2.shape)
print(b2.shape)
dh = dlogits @ W2.T #Chain rule, and whats mentioned above
dW2 = h.T @ dlogits #Chain rule, and whats mentioned above
db2 = dlogits.sum(0) #Chain rule, and whats mentioned above
cmp('h', dh, h)
cmp('W2', dW2, W2)
cmp('b2', db2, b2)

#h = torch.tanh(hpreact) # hidden layer
print(hpreact.shape)
dhpreact = (1 - h**2) * dh # Chain rule && (d/dx)tanh(x) where tanh(x) == o differentiates to 1 - o**2 
cmp('hpreact', dhpreact, hpreact)

#hpreact = bngain * bnraw + bnbias
print(bngain.shape)
print(bnbias.shape)
print(bnraw.shape)
dbngain = (bnraw * dhpreact).sum(0, keepdim=True) # (d/da)ab == b && chain rule && summing partial derivatives (sum of fan_out to maintain dimensionality)
dbnbias = dhpreact.sum(0, keepdim=True) # Chain rule && (d/da)a+b == 1 && summing partial derivatives (sum of fan_out to maintain dimensionality)
dbnraw = bngain * dhpreact # Chain rule && (d/da)ab == b
cmp('bngain', dbngain, bngain)
cmp('bnbias', dbnbias, bnbias)
cmp('bnraw', dbnraw, bnraw)

#bnraw = bndiff * bnvar_inv
print(bnvar_inv.shape)
print(bndiff.shape)
dbnvar_inv = (bndiff *dbnraw).sum(0, keepdim=True) # (d/da)ab == b && chain rule && summing partial derivatives (sum of fan_out to maintain dimensionality)
dbndiff = dbnraw * bnvar_inv # Chain rule && (d/da)ab == b
cmp('bnvar_inv', dbnvar_inv, bnvar_inv)

#bnvar_inv = (bnvar + 1e-5)**-0.5
print(bnvar.shape)
dbnvar = (-0.5 * (bnvar + 1e-5)**-1.5) * dbnvar_inv  # Chain rule && (d/da)a**b == ba**(b-1)
cmp('bnvar', dbnvar, bnvar)

#bnvar = 1/(n-1)*(bndiff2).sum(0, keepdim=True) # note: Bessel's correction (dviding by n-1, not n)
#initial batchnorm paper did not use bessel's correction for training, instead used n, then used n-1 at test time. During training for each mini-batch, since the
#variance is used to normalize the activations immediately, and the process is end-to-end differentiable, there's no need for Bessel's correction. The training
#process will learn the appropriate weights regardless of the bias. At test time however BN uses running mean and variance, which are not subject to backpropagation
#Applying Bessel's correction can provide a more accurate estimate of the population variance, particularly when sample sizes are very small. 
# any time you have a sum in the forward pass, it turns into broadcasting in the backwd pass, along the same dimension
# FWD PASS:
# VECTOR: a11 a12   =>  b1 b2    b1 = 1/(n-1) * (a11 + a21)     &&      b2 = 1/(n-1) * (a12 + a22)
#         a21 a22              
# BKWD PASS:
# VECTOR: a11 a12   =>  c1 c2    c1 = 1/(n-1) * [a11 a21]     &&      c2 = 1/(n-1) * [a12 a22]
#         a21 a22              
# Therefore derivitaive with respect to a is 1/(n-1) * [1 1] for every value in  the matrix a
print(bndiff2.shape) # any time you have a sum in the forward pass, it turns into broadcasting in the backwd pass, along the same dimension
dbndiff2 = 1/(n-1) * torch.ones_like(bndiff2) * dbnvar # Chain rule && (d/da)ab == b && broadcasting maintains dimensionality
cmp('bndiff2', dbndiff2, bndiff2)

#bndiff2 = bndiff**2
print(bndiff.shape)
dbndiff += 2 * bndiff * dbndiff2  # Chain rule && (d/da)a**b == ba**(b-1)
cmp('bndiff', dbndiff, bndiff)

#bndiff = hprebn - bnmeani
print(bnmeani.shape)
print(hprebn.shape)
dbnmeani = (-(torch.ones_like(bnmeani)) * dbndiff).sum(0, keepdim=True) # Chain rule, (d/db)a-b == -1 maintains negative && sum maintains dimensionality
dhprebn = torch.ones_like(hprebn) * dbndiff # Chain rule, (d/da)a-b == 1  maintains postive sign && broadcasting maintains dimensionality

cmp('bnmeani', dbnmeani, bnmeani)

#bnmeani = 1/n+hprebn.sum(0, keepdim=True)
dhprebn += torch.ones_like(hprebn) * dbnmeani # Chain rule, (d/da)a+b == 1 
cmp('hprebn', dhprebn, hprebn)

#hprebn = embcat @ W1 + b1 # hidden layer pre-activation
print(embcat.shape)
print(W1.shape)
print(b1.shape)
dembcat = dhprebn @ W1.T
dW1 = embcat.T @ dhprebn
db1 = dhprebn.sum(0)
cmp('embcat', dembcat, embcat)
cmp('W1', dW1, W1)
cmp('b1', db1, b1)

#embcat = emb.view(emb.shape[0], -1) # concatenate the vectors
print(emb.shape)
demb = dembcat.view(emb.shape) #changes dembcat to original shape of emb
cmp('emb', demb, emb)

#emb = C[Xb] # embed the characters into vectors
print(C.shape) # 27 characters with 10-dimensional embeddings for each character
print(Xb.shape) # 32 examples of 3 character sequences
print(Xb[:5]) # indices for first 5 '3 character sequence' examples
# we have demb, so for every one of these 32, 3 character, 10-dimensional embeddings we have their gradient, so we need to reroute in order to find out which
# row of C these gradients came from, then we need to deposit them into dC.
dC = torch.zeros_like(C)
#the below code can also be written as a vectorized version using PyTorch
#indices = Xb.view(-1) #Flattens Xb to get a 1D tensor of indices
#values = demb.view(-1, demb.size(-1)) #Reshapes demb to [32*3,10] to match flattened Xb
#dC.index_add_(0, indices, values) #accumulates values from demb into dC based on indices from flattened Xb
for k in range(Xb.shape[0]):
	for j in range(Xb.shape[1]):
		index = Xb[k,j] #In fwd pass we took row at C[index] and deposited it into emb[k,j], so to reverse deposit 
		dC[index] += demb[k, j]  # += because there could be more than one instance, need to sum gradients 

cmp('C', dC, C)


#===========================================================================

# Exercise 2: backprop through cros_entropy but all in one go
# to complete this challenge look at the mathematical expression of the loss
# take the derivative, simplify the expression, and just write it out

# forward pass - below 'before' have broken up the loss to its low-level composites

# before:
# logit_maxes = logits,max(1, keppdim=True).values
# norm_logits = logits - logits.maxes # subtract max for numerical stability
# counts = norm_logits.exp()
# counts_sum = counts.sum(1, keepdims=True)
# counts_sum_inv = counts_sum**-1 # if I use (1.0/ counts_sum) instead then i can't get backprop to be bit exact.
# probs = counts * counts_sum_inv
# logprobs = probs.log()
# loss = -logprobs[range(n), yb].mean()

# forward pass - below 'now' - collapses the loss into a single cross_entropy call,
# will then analytically derive the loss using pencil/paper, and implement 

# now: 
loss_fast = F.cross_entropy(logits, Yb)
print(loss_fast.item(), 'diff:', (loss_fast - loss).item())

#backward pass

dlogitsnew = F.softmax(logits, 1)
dlogitsnew[range(n), Yb] -= 1
dlogitsnew /= n

# =========================
# YOUR CODE HERE :)
# =========================

cmp('logits', dlogitsnew, logits) # I can only get approx to be true, maxdiff is 6e-9

#===========================================================================

# Exercise 3: backprop through batchnorm but all in one go
# to complete this challenge look  at the mathematical expression of the output of batchnorm
# take the derivative w.r.t its input, simplify the expression, and write it out

#forward pass

# before:
# bmeani = 1/n*hprebn.sum(0, keepdim=True)
# bndiff = hprebn - bnmeani 
# bndiff2 = bndiff**2
# bnvar = 1/(n-1)*(bndiff2).sum(0, keepdim=True) # note: Bessel's correction (dividing by n-1, not n)
# bnvar_inv = (bnvar + 1e-5)**-0.5
# bnraw = bndiff * bnvar_inv
# hpreact = bngain * bnraw + bnbias

# now:
# batch_norm uses biased variance, so sadly just calling this doesn't work:
# hpreact2 = F.bbatch_norm(hprebn, None, NOne, bngain, bnbia, training=True)
# sadly unresolved, apparently: https://github.com/pytorch/pytorch/issues/199902
# so instead of, implementing the correct forward pass here explicitly, but on one line, using true bngain and true bnmean

hpreact_fast = bngain * hprebn - hprebn.mean(0, keepdim=True) / torch.sqrt(hprebn.var(0, keepdim=True, unbiased=True))
#print(hpreact_fast, 'max_diff:', (hpreact_fast - hpreact).abs().max())

#will also use pen, paper and calculus to derive the gradients for the bn layer, 
#will calculate the backward pass for the batch norm layer in a more efficient 
#expression 

#dhprebnnew = (dhpreact*bngain*bnvar_inv)+(2/hprebn.shape[0]*bndiff*(-0.5*(dhpreact*bngain*bndiff*(bnvar+1e-5)**-1.5).sum(0,keepdim=True)))+(-1/hprebn.shape[0]*(dhpreact*bngain*bnvar_inv).sum(0, keepdim=True))
#dhprebnnew = bngain * bnvar_inv * (dhpreact - dhpreact.sum(0)/n - bnraw * (dhpreact * bnraw).sum(0)) 
dhprebnnew = bngain * bnvar_inv/n * (n * dhpreact - dhpreact.sum(0) - bnraw * (dhpreact * bnraw).sum(0)) 
#dL/dxi=gamma * 1/(sigma**2 + epsilon)/n * (n * dL/dyi - sum(dL/dyj) - n/(n-1) * xi^ * sum(dL/dyj * xj^))
cmp('hprebn', dhprebn, hprebn) # I can only get approx to be true, maxdiff is 6e-9

#===========================================================================

# Exercise 4: putting it all together!
# train the MLP neural net with your own backward pass

# init
n_embd = 10 # the dimensionality of the character embedding vectors
n_hidden = 200 # the number of neurons in the hidden layer of the MLP

g = torch.Generator().manual_seed(2147483647) # for reroducibility
C = torch.randn((vocab_size, n_embd), generator=g)
# Layer 1
W1 = torch.randn((n_embd * block_size, n_hidden), generator=g) * (5/3)/((n_embd * block_size)**0.5)
b1 = torch.randn(n_hidden, generator=g) * 0.1
# Layer 2
W2 = torch.randn((n_hidden, vocab_size), generator=g) * 0.1
b2 = torch.randn(vocab_size, generator=g) * 0.1
# BatchNorm parameters
bngain = torch.randn((1, n_hidden)) * 0.1 + 1.0
bnbias = torch.randn((1, n_hidden)) * 0.1

parameters = [C, W1, b1, W2, b2, bngain, bnbias]
#print(sum(p.nelement() for p in parameters)) # number of parameters in total
for p in parameters:
	p.requires_grad = True

# same optimization as last time
max_steps = 2000
batch_size = 32
n = batch_size # convenience
lossi = []

# use this context manager for efficiency eonce your backward pass is written (TODO)
#with torch.no_grad

#kick off optimization
for i in range(max_steps):
	#minibatch construct
	ix = torch.randint(0, Xtr.shape[0], (batch_size,), generator=g)
	Xb, Yb = Xtr[ix], Ytr[ix] # batch X, Y

	# forward pass
	emb = C[Xb] # embed the characters into vectors
	embcat = emb.view(emb.shape[0], -1) # concatenate into vectors
	# Linear layer
	hprebn = embcat @ W1 + b1 # hideen layer pre-activation
	# batchNorm layer
	# ==========================================================================
	bnmean = hprebn.mean(0, keepdim=True)
	bnvar = hprebn.var(0, keepdim=True, unbiased=False)
	bnvar_inv = (bnvar + 1e-5)**-0.5
	bnraw = (hprebn - bnmean) * bnvar_inv
	hpreact = bngain * bnraw + bnbias
	# ==========================================================================
	# Non-linearity
	h = torch.tanh(hpreact) # hidden layer
	logits = h @ W2 + b2 # output layer
	loss = F.cross_entropy(logits, Yb) # loss function

	# backward pass
	for p in parameters:
		p.grad = None
	loss.backward() # use this for correctness comparisons, delete it later!

	# mannual backprop! - will be taking out loss.backward and introducing the manual backprop
	#==========================================================================
	# YOUR CODE HERE :)
	dlogits = F.softmax(logits, 1)
	dlogits[range(n), Yb] -= 1
	dlogits /= n
	# 2nd layer backprop
	dh = dlogits @ W2.T
	dW2 = h.T @ dlogits
	db2 = dlogits.sum(0)
	# tanh
	dhpreact = (1.0 - h**2) * dh
	#batchnorm backprop
	dbngain = (bnraw * dhpreact).sum(0, keepdim=True)
	dbnbias = dhpreact.sum(0, keepdim=True)
	dhprebn = bngain * bnvar_inv/n * (n * dhpreact - dhpreact.sum(0) - bnraw * (dhpreact * bnraw).sum(0)) 
	dembcat = dhprebn @ W1.T
	dW1 = embcat.T @ dhprebn
	db1 = dhprebn.sum(0)
	# embedding
	demb = dembcat.view(emb.shape)
	indices = Xb.view(-1) #Flattens Xb to get a 1D tensor of indices
	values = demb.view(-1, demb.size(-1)) #Reshapes demb to [32*3,10] to match flattened Xb
	dC = torch.zeros_like(C)
	for k in range(Xb.shape[0]):
		for j in range(Xb.shape[1]):
			index = Xb[k,j] #In fwd pass we took row at C[index] and deposited it into emb[k,j], so to reverse deposit 
			dC[index] += demb[k, j]  # += because there could be more than one instance, need to sum gradients 
#	dC.index_add_(0, indices, values) #accumulates values from demb into dC based on indices from flattened Xb

	#dC, dW1, db1, dW2, db2, dbngain, dbnbias = None, None, None, None, None, None, None
	#parameters = [C, W1, b1, W2, b2, bngain, bnbias]
	grads = [dC, dW1, db1, dW2, db2, dbngain, dbnbias]
	#==========================================================================

	#update 
	lr = 0.1 if i < 100000 else 0.01 # step learning rate decay
	for p, grad in zip(parameters, grads):
		p.data += -lr * p.grad # old way of cheems doge (using PyTorch grad from .backward()
		#p.data += -lr * grad # new way of swole doge TODO: enable

	# track stats
	#if i % 1000 == 0:
		#print(f'{i:7d}/{max_steps:7d}: {loss.item():.4f}')
	lossi.append(loss.log10().item())

	if i >= 100: # TODO: delete early break when ready to train the full net
		for p,g in zip(parameters, grads):
			cmp(str(tuple(p.shape)), g, p)
		break


# calibrate the batch norm at the end of training
with torch.no_grad():
	#pass the training set through
	emb = C[Xtr]
	embcat = emb.view(emb.shape[0], -1)
	hpreact = embcat @ W1 + b1
	# measure the mean/variance over the entire training set
	bnmean = hpreact.mean(0, keepdim=True)
	bnvar = hpreact.var(0, keepdim=True, unbiased=True)

# evaluate training and validation loss
def split_loss(split):
	x,y = {
		'train': (Xtr, Ytr),
		'val': (Xdev, Ydev),
		'test': (Xte, Yte),
	}[split]
	emb = C[x] # (N, block_size, n_embd)
	embcat = emb.view(emb.shape[0], -1) # concat into (N, block_size * n_embd)
	hpreact = embcat @ W1 + b1
	hpreact = bngain * (hpreact - bnmean) * (bnvar + 1e-5)**0.5 + bnbias
	h = torch.tanh(hpreact) # (N, n_hidden)
	logits = h @ W2 + b2 # (N, vocab_size)
	loss = F.cross_entropy(logits, y)
	print(split, loss.item())

split_loss('train')
split_loss('val')

==> layernorm.py <==
#!/usr/bin/python3.8

class LayerNorm:
	def __init__(self, dim, eps=1e-5, momentum=0.1):
		self.eps = eps
		# parameters (trained with backprop)
		self.gamma = torch.ones(dim) #scale
		self.beta = torch.zeros(dim) #shift
		# buffers (trained with a running 'momentum update')

	def __call__(self, x):
		#calculate the forward pass
		xmean = x.mean(1, keepdim=True) #batch mean
		xvar = x.var(1, keepdim=True) # batch variance
		xhat = (x - xmean) / torch.sqrt(xvar + self.eps) # normalize to unit variance
		self.out = self.gamma * xhat + self.beta 
		return self.out

	def parameters(self):
		return [self.gamma, self.beta]

==> bigram-developed.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 32 # how many independent sequences will we process in parallel?
block_size = 8 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 500
learning_rate = 1e-2
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, vocab_size) # thin wrapper around tensor of shape vocab_size * vocab_size
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings : number of rows in the embedding table
			#embedding_dim == the size of each embedding vector : number of columns in embedding table

	def forward(self, idx, targets=None):
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		logits = self.token_embedding_table(idx) # (B,T,C), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in ssequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			# get the predictions
			logits, loss = self(idx)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

==> single-self-attention-head.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 32 # how many independent sequences will we process in parallel?
block_size = 8 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 500
learning_rate = 1e-3 #decrease of learning rate for self-attention block
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
n_embd = 32
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class Head(nn.Module):
	""" one head of self-attention """

	def __init__(self, head_size):
		super().__init__()
		self.key = nn.Linear(n_embd, head_size, bias=False)
		self.query = nn.Linear(n_embd, head_size, bias=False)
		self.value = nn.Linear(n_embd, head_size, bias=False)
		#nn.Linear(features_in, features out, bias=True) features_in == number of input neurons, features_out == number of output neurons
		self.register_buffer('tril', torch.tril(torch.ones(block_size, block_size)))
		#as tril is not a parameter in pytorch naming convention it is called a buffer, so is thus assigned

	def forward(self, x):
		B,T,C = x.shape
		k = self.key(x)		# (B, T, C)
		q = self.query(x) 	# (B, T, C)
		# compute attention scores ("affinities")
		wei = q @ k.transpose(-2,-1) * C**-0.5 # (B, T, C) @ (B, C, T) => (B, T, T)
		# in Pytorch -1 refers to the last dimension on the right, -2 to previous. So -2, -1 refer to the 2nd to last and last dimension
		wei = wei.masked_fill(self.tril[:T, :T] ==0, float('-inf')) # B, T, T
		wei = F.softmax(wei, dim=-1) # (B, T, T)
		# perform the weighted aggregation of the values
		v = self.value(x) # (B, T, C)
		out = wei @ v # (B, T, T) @ (B, T, C) => (B, T, C)
		return out

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, n_embd) # thin wrapper around tensor of shape vocab_size * n_embd
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings - number of rows in the embedding table
			#embedding_dim == the size of each embedding vector - number of columns in embedding table
		self.position_embedding_table = nn.Embedding(block_size, n_embd) #Also encodes positions into an embedding table
		self.sa_head = Head(n_embd) # sa_head == self-attention head
		self.lm_head = nn.Linear(n_embd, vocab_size) # lm_head == language modelling head

	def forward(self, idx, targets=None):
		B, T = idx.shape
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		tok_emb = self.token_embedding_table(idx) # (B,T,C==n_embd), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		pos_emb = self.position_embedding_table(torch.arange(T, device=device)) #(T,C), integers from 0 to T-1 are embedded through the table
		x = tok_emb + pos_emb # (B, T, C) == (B, T, C) + (T,C): (T,C) gets right-aligned, new dimension is added, and it is broadcast along batch dimension
		x = self.sa_head(x)
		logits = self.lm_head(x) # (B,T,vocab_size)
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in ssequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			#crop idx to the last block_size tokens
			idx_cond = idx[:, -block_size:]
			# get the predictions
			logits, loss = self(idx_cond)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

==> multi-self-attention-head.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 32 # how many independent sequences will we process in parallel?
block_size = 8 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 500
learning_rate = 1e-3 #decrease of learning rate for self-attention block
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
n_embd = 32
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class Head(nn.Module):
	""" one head of self-attention """

	def __init__(self, head_size):
		super().__init__()
		self.key = nn.Linear(n_embd, head_size, bias=False)
		self.query = nn.Linear(n_embd, head_size, bias=False)
		self.value = nn.Linear(n_embd, head_size, bias=False)
		#nn.Linear(features_in, features out, bias=True) features_in == number of input neurons, features_out == number of output neurons
		self.register_buffer('tril', torch.tril(torch.ones(block_size, block_size)))
		#as tril is not a parameter in pytorch naming convention it is called a buffer, so is thus assigned

	def forward(self, x):
		B,T,C = x.shape
		k = self.key(x)		# (B, T, C)
		q = self.query(x) 	# (B, T, C)
		# compute attention scores ("affinities")
		wei = q @ k.transpose(-2,-1) * C**-0.5 # (B, T, C) @ (B, C, T) => (B, T, T)
		# in Pytorch -1 refers to the last dimension on the right, -2 to previous. So -2, -1 refer to the 2nd to last and last dimension
		wei = wei.masked_fill(self.tril[:T, :T] ==0, float('-inf')) # B, T, T
		wei = F.softmax(wei, dim=-1) # (B, T, T)
		# perform the weighted aggregation of the values
		v = self.value(x) # (B, T, C)
		out = wei @ v # (B, T, T) @ (B, T, C) => (B, T, C)
		return out

class MultiHeadAttention(nn.Module):
	""" multiple heads of self-attention in parallel """

	def __init__(self, num_heads, head_size):
		super().__init__()
		self.heads = nn.ModuleList((Head(head_size) for _ in range(num_heads)))
		#ModuleList registers the modules it contains as sub-modules, making sure their parameters are included when you call methods like
		#.parameters() or .to(device) on a module. It can be indexed like a regular list. It's similar to torch.nn.Sequential which not
		#only stores modules but invokes them sequentially during a forward pass. However sequential can cause problems defining custom fwd behaviours

	def forward(self, x):
		return torch.cat([h(x) for h in self.heads], dim=-1)

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, n_embd) # thin wrapper around tensor of shape vocab_size * n_embd
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings - number of rows in the embedding table
			#embedding_dim == the size of each embedding vector - number of columns in embedding table
		self.position_embedding_table = nn.Embedding(block_size, n_embd) #Also encodes positions into an embedding table
		self.sa_heads = MultiHeadAttention(4, n_embd//4) # 4 heads of 8-dimensional self-attention
		self.lm_head = nn.Linear(n_embd, vocab_size) # lm_head == language modelling head

	def forward(self, idx, targets=None):
		B, T = idx.shape
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		tok_emb = self.token_embedding_table(idx) # (B,T,C==n_embd), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		pos_emb = self.position_embedding_table(torch.arange(T, device=device)) #(T,C), integers from 0 to T-1 are embedded through the table
		x = tok_emb + pos_emb # (B, T, C) == (B, T, C) + (T,C): (T,C) gets right-aligned, new dimension is added, and it is broadcast along batch dimension
		x = self.sa_heads(x)
		logits = self.lm_head(x) # (B,T,vocab_size)
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in ssequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			#crop idx to the last block_size tokens
			idx_cond = idx[:, -block_size:]
			# get the predictions
			logits, loss = self(idx_cond)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

==> feed-fwd+multi-head.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 32 # how many independent sequences will we process in parallel?
block_size = 8 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 500
learning_rate = 1e-3 #decrease of learning rate for self-attention block
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
n_embd = 32
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class Head(nn.Module):
	""" one head of self-attention """

	def __init__(self, head_size):
		super().__init__()
		self.key = nn.Linear(n_embd, head_size, bias=False)
		self.query = nn.Linear(n_embd, head_size, bias=False)
		self.value = nn.Linear(n_embd, head_size, bias=False)
		#nn.Linear(features_in, features out, bias=True) features_in == number of input neurons, features_out == number of output neurons
		self.register_buffer('tril', torch.tril(torch.ones(block_size, block_size)))
		#as tril is not a parameter in pytorch naming convention it is called a buffer, so is thus assigned

	def forward(self, x):
		B,T,C = x.shape
		k = self.key(x)		# (B, T, C)
		q = self.query(x) 	# (B, T, C)
		# compute attention scores ("affinities")
		wei = q @ k.transpose(-2,-1) * C**-0.5 # (B, T, C) @ (B, C, T) => (B, T, T)
		# in Pytorch -1 refers to the last dimension on the right, -2 to previous. So -2, -1 refer to the 2nd to last and last dimension
		wei = wei.masked_fill(self.tril[:T, :T] ==0, float('-inf')) # B, T, T
		wei = F.softmax(wei, dim=-1) # (B, T, T)
		# perform the weighted aggregation of the values
		v = self.value(x) # (B, T, C)
		out = wei @ v # (B, T, T) @ (B, T, C) => (B, T, C)
		return out

class MultiHeadAttention(nn.Module):
	""" multiple heads of self-attention in parallel """

	def __init__(self, num_heads, head_size):
		super().__init__()
		self.heads = nn.ModuleList((Head(head_size) for _ in range(num_heads)))
		#ModuleList registers the modules it contains as sub-modules, making sure their parameters are included when you call methods like
		#.parameters() or .to(device) on a module. It can be indexed like a regular list. It's similar to torch.nn.Sequential which not
		#only stores modules but invokes them sequentially during a forward pass. However sequential can cause problems defining custom fwd behaviours

	def forward(self, x):
		return torch.cat([h(x) for h in self.heads], dim=-1)

class FeedForward(nn.Module):
	""" a simple linear layer followed by a non-linearity """

	def __init__(self, n_embd):
		super().__init__()
		self.net = nn.Sequential(
			nn.Linear(n_embd, n_embd),
			nn.ReLU(),
		)

	def forward(self, x):
		return self.net(x)

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, n_embd) # thin wrapper around tensor of shape vocab_size * n_embd
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings - number of rows in the embedding table
			#embedding_dim == the size of each embedding vector - number of columns in embedding table
		self.position_embedding_table = nn.Embedding(block_size, n_embd) #Also encodes positions into an embedding table
		self.sa_heads = MultiHeadAttention(4, n_embd//4) # 4 heads of 8-dimensional self-attention
		self.ffwd = FeedForward(n_embd)
		self.lm_head = nn.Linear(n_embd, vocab_size) # lm_head == language modelling head

	def forward(self, idx, targets=None):
		B, T = idx.shape
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		tok_emb = self.token_embedding_table(idx) # (B,T,C==n_embd), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		pos_emb = self.position_embedding_table(torch.arange(T, device=device)) #(T,C), integers from 0 to T-1 are embedded through the table
		x = tok_emb + pos_emb # (B, T, C) == (B, T, C) + (T,C): (T,C) gets right-aligned, new dimension is added, and it is broadcast along batch dimension
		x = self.sa_heads(x)
		x = self.ffwd(x)
		logits = self.lm_head(x) # (B,T,vocab_size)
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in sequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			#crop idx to the last block_size tokens
			idx_cond = idx[:, -block_size:]
			# get the predictions
			logits, loss = self(idx_cond)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

==> bigram.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

print("length of dataset in characters: ", len(text))

#let's look at the first 200 characters
#print(text[:200])
torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
#print(''.join(chars))
#print(vocab_size)

stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

#print(encode("hii there"))
#print(decode(encode("hii there")))

data = torch.tensor(encode(text), dtype=torch.long)
print(data.shape, data.dtype)

# Let's now split the data into train and validation sets
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]
# can use validation data to determine to which extent the model is overfitting

block_size = 8
#print(train_data[:block_size+1])

x = train_data[:block_size]
y = train_data[1:block_size+1]
for t in range(block_size):
	context = x[:t+1]
	target = y[t]
	#print(f"{t}: When input is {context} the target is: {target}")
	#OUTPUT BELOW:
#When input is tensor([18]) the target is: 47
#When input is tensor([18, 47]) the target is: 56
#When input is tensor([18, 47, 56]) the target is: 57
#When input is tensor([18, 47, 56, 57]) the target is: 58
#When input is tensor([18, 47, 56, 57, 58]) the target is: 1
#When input is tensor([18, 47, 56, 57, 58,  1]) the target is: 15
#When input is tensor([18, 47, 56, 57, 58,  1, 15]) the target is: 47
#When input is tensor([18, 47, 56, 57, 58,  1, 15, 47]) the target is: 58

batch_size = 4 # how many independent sequences will we process in parallel?

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

xb, yb = get_batch('train')
#print('inputs:')
#print(xb.shape) #torch.Size([4, 8])
#print(xb) # OUTPUT:
# #tensor([[24, 43, 58,  5, 57,  1, 46, 43],
# #        [44, 53, 56,  1, 58, 46, 39, 58],
# #        [52, 58,  1, 58, 46, 39, 58,  1],
# #        [25, 17, 27, 10,  0, 21,  1, 54]])
#print('targets:')
#print(yb.shape) #torch.Size([4, 8])
#print(yb) # OUTPUT:
# #tensor([[43, 58,  5, 57,  1, 46, 43, 39],
# #        [53, 56,  1, 58, 46, 39, 58,  1],
# #        [58,  1, 58, 46, 39, 58,  1, 46],
# #        [17, 27, 10,  0, 21,  1, 54, 39]])

print('----')

for b in range(batch_size): #batch dimension
	for t in range(block_size): #time dimension
		context = xb[b, :t+1] # selects from original tensor up to context length
		target = yb[b,t] # selects from output tensor at the position of the next character, will be used by transformer to crete the loss function
		#print(f"when input is {context.tolist()} the target is: {target}")
		# OUTPUT:
		 # when input is [24] the target is: 43
		 # when input is [24, 43] the target is: 58
		 # when input is [24, 43, 58] the target is: 5
		 # when input is [24, 43, 58, 5] the target is: 57
		 # when input is [24, 43, 58, 5, 57] the target is: 1
		 # when input is [24, 43, 58, 5, 57, 1] the target is: 46
		 # when input is [24, 43, 58, 5, 57, 1, 46] the target is: 43
		 # when input is [24, 43, 58, 5, 57, 1, 46, 43] the target is: 39
		 # when input is [44] the target is: 53
		 # when input is [44, 53] the target is: 56
		 # when input is [44, 53, 56] the target is: 1
		 # when input is [44, 53, 56, 1] the target is: 58
		 # when input is [44, 53, 56, 1, 58] the target is: 46
		 # when input is [44, 53, 56, 1, 58, 46] the target is: 39
		 # when input is [44, 53, 56, 1, 58, 46, 39] the target is: 58
		 # when input is [44, 53, 56, 1, 58, 46, 39, 58] the target is: 1
		 # when input is [52] the target is: 58
		 # when input is [52, 58] the target is: 1
		 # when input is [52, 58, 1] the target is: 58
		 # when input is [52, 58, 1, 58] the target is: 46
		 # when input is [52, 58, 1, 58, 46] the target is: 39
		 # when input is [52, 58, 1, 58, 46, 39] the target is: 58
		 # when input is [52, 58, 1, 58, 46, 39, 58] the target is: 1
		 # when input is [52, 58, 1, 58, 46, 39, 58, 1] the target is: 46
		 # when input is [25] the target is: 17
		 # when input is [25, 17] the target is: 27
		 # when input is [25, 17, 27] the target is: 10
		 # when input is [25, 17, 27, 10] the target is: 0
		 # when input is [25, 17, 27, 10, 0] the target is: 21
		 # when input is [25, 17, 27, 10, 0, 21] the target is: 1
		 # when input is [25, 17, 27, 10, 0, 21, 1] the target is: 54
		 # when input is [25, 17, 27, 10, 0, 21, 1, 54] the target is: 39

		# The transformer will simultaneously process all of these examples (batch_size==4) and work out the next integer to predict from tensor yb

class BigramLanguageModel(nn.Module):
	def __init__(self, vocab_size):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, vocab_size) # thin wrapper around tensor of shape vocab_size * vocab_size
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings : number of rows in the embedding table
			#embedding_dim == the size of each embedding vector : number of columns in embedding table

	def forward(self, idx, targets=None):
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		logits = self.token_embedding_table(idx) # (B,T,C), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in sequence (of 65).
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point

		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			# get the predictions
			logits, loss = self(idx)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C)
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx
	
m = BigramLanguageModel(vocab_size) # calling it
logits, loss = m(xb, yb) # passing in inputs and targets
print(logits.shape) # is (4, 8, 65) and is interpreted as logits for each of the 4 x 8 positions
print(loss) # since negative log likelihood expecting around -ln(1/65) == 4.174

print(decode(m.generate(idx = torch.zeros((1, 1), dtype=torch.long), max_new_tokens=100)[0].tolist()))

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

batch_size = 32
for steps in range(10000):
	#sample a batch of data
	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

print('')
print(loss.item())
print(decode(m.generate(idx = torch.zeros((1, 1), dtype=torch.long), max_new_tokens=100)[0].tolist()))

==> self-attention-preview.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

#The mathematical trick in self-attention
# We want x[b,t] = mean_{i<=t} x[b,i] as easiest way to get info from all elements preceding is to take the mean

#VERSION 1:
torch.manual_seed(1337)
B,T,C = 4,8,2
x = torch.randn(4,8,2)
#print(x.shape) ##torch.Size([4, 8, 2])

xbow = torch.zeros((B,T,C)) # bow here stands for 'bag of words'
for b in range(B):
	for t in range(T):
		xprev = x[b,:t+1] # returns in form (t,C) - all previous takes current batch dimension b and everything up to and including t :t+1
		xbow[b,t] = torch.mean(xprev, 0) # returns C 1-dimensional vector, using dimension 0 only
#inefficient non-vectorized method

#RESULT:
#print(x[0])
#tensor([[ 0.1808, -0.0700],
#        [-0.3596, -0.9152],
#        [ 0.6258,  0.0255],
#        [ 0.9545,  0.0643],
#        [ 0.3612,  1.1679],
#        [-1.3499, -0.5102],
#        [ 0.2360, -0.2398],
#        [-0.9211,  1.5433]])
#print(xbow[0])
#tensor([[ 0.1808, -0.0700],
#        [-0.0894, -0.4926], avg of -0.3596,0.1808, avg of -0.0700,-0.9152
#        [ 0.1490, -0.3199], avg of 0.6258,-0.3596,0.1808, avg of 0.0255,-0.9152,-.0.0700
#        [ 0.3504, -0.2238], etcs.
#        [ 0.3525,  0.0545], ...
#        [ 0.0688, -0.0396], ...
#        [ 0.0927, -0.0682], ...
#        [-0.0341,  0.1332]]) ...

#Can be more efficient about this operation as follows
torch.manual_seed(42)
a = torch.ones(3, 3)
#tensor([[1., 1., 1.],
#        [1., 1., 1.],
#        [1., 1., 1.]])
b = torch.randint(0,10,(3,2,)).float() # torch.randint(low, high, size)
#tensor([[2., 7.],
#        [6., 4.],
#        [6., 5.]])
c = a @ b # matrix multiplication (1*2)+(1*6)+(1*6)=14, (1*7)+(1*4)+(1*5)=16 
#tensor([[14., 16.],
#        [14., 16.],
#        [14., 16.]])

a=torch.tril(torch.ones(3,3)) # tril == torch.triangle function
#tensor([[1., 0., 0.],
#        [1., 1., 0.],
#        [1., 1., 1.]])
c=a@b
#tensor([[ 2.,  7.], (1*2)+(0*6)+(0*6)=2, (1*7)+(0*4)+(0*5)=7 
#        [ 8., 11.], (1*2)+(1*6)+(0*6)=8, (1*7)+(1*4)+(0*5)=11 
#        [14., 16.]]) (1*2)+(1*6)+(1*6)=14, (1*7)+(1*4)+(1*5)=16 

a /= torch.sum(a, 1, keepdim=True) 
#tensor([[1.0000, 0.0000, 0.0000],
#        [0.5000, 0.5000, 0.0000],
#        [0.3333, 0.3333, 0.3333]])
c=a@b
#tensor([[2.0000, 7.0000], (1*2)+(0*6)+(0*6)=2, (1*7)+(0*4)+(0*5)=7 
#        [4.0000, 5.5000], (0.5*2)+(0.5*6)+(0*6)=4, (0.5*7)+(0.5*4)+(0*5)=5.5
#        [4.6667, 5.3333]]) (0.33*2)+(0.33*6)+(0.33*6)=4.67, (0.33*7)+(0.33*4)+(0.33*5)=5.33

# VERSION 2: we can use this technique multiplied with any corresponding matrix to get the means
wei = torch.tril(torch.ones(T, T))
wei /= wei.sum(1, keepdim=True) # this represents our a, its an 8x8 matrix
xbow2 = wei @ x # (T, T) @ (B, T, C) ==> will create a batch dimension in (T, T) matrix so
				# (B, T, T) @ (B, T, C) ==> (B, T, C) this gives a resultant matrix with the same values as original xbow, therefore
#print(torch.allclose(xbow, xbow2)) ## returns 'True'
#print(xbow2[0])
#tensor([[ 0.1808, -0.0700],
#        [-0.0894, -0.4926], avg of -0.3596,0.1808, avg of -0.0700,-0.9152
#        [ 0.1490, -0.3199], avg of 0.6258,-0.3596,0.1808, avg of 0.0255,-0.9152,-.0.0700
#        [ 0.3504, -0.2238], etcs.
#        [ 0.3525,  0.0545], ...
#        [ 0.0688, -0.0396], ...
#        [ 0.0927, -0.0682], ...
#        [-0.0341,  0.1332]]) ...

#VERSION 3: USING SOFTMAX
tril = torch.tril(torch.ones(T,T))
#tensor([[1., 0., 0., 0., 0., 0., 0., 0.],
#       [1., 1., 0., 0., 0., 0., 0., 0.],
#       [1., 1., 1., 0., 0., 0., 0., 0.],
#       [1., 1., 1., 1., 0., 0., 0., 0.],
#       [1., 1., 1., 1., 1., 0., 0., 0.],
#       [1., 1., 1., 1., 1., 1., 0., 0.],
#       [1., 1., 1., 1., 1., 1., 1., 0.],
#       [1., 1., 1., 1., 1., 1., 1., 1.]])
wei = torch.zeros(T,T)
#tensor([[0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.],
#       [0., 0., 0., 0., 0., 0., 0., 0.]])
wei = wei.masked_fill(tril == 0, float('-inf')) # replaces all zeros with '-inf' in wei where tril ==0 
#tensor([[0., -inf, -inf, -inf, -inf, -inf, -inf, -inf],
#       [0., 0., -inf, -inf, -inf, -inf, -inf, -inf],
#       [0., 0., 0., -inf, -inf, -inf, -inf, -inf],
#       [0., 0., 0., 0., -inf, -inf, -inf, -inf],
#       [0., 0., 0., 0., 0., -inf, -inf, -inf],
#       [0., 0., 0., 0., 0., 0., -inf, -inf],
#       [0., 0., 0., 0., 0., 0., 0., -inf],
#       [0., 0., 0., 0., 0., 0., 0., 0.]])
wei = F.softmax(wei, dim=1) # in softmax we exponentiate every single element, and then normalize
#tensor([[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.5000, 0.5000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.3333, 0.3333, 0.3333, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.2500, 0.2500, 0.2500, 0.2500, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.2000, 0.2000, 0.2000, 0.2000, 0.2000, 0.0000, 0.0000, 0.0000],
#        [0.1667, 0.1667, 0.1667, 0.1667, 0.1667, 0.1667, 0.0000, 0.0000],
#        [0.1429, 0.1429, 0.1429, 0.1429, 0.1429, 0.1429, 0.1429, 0.0000],
#        [0.1250, 0.1250, 0.1250, 0.1250, 0.1250, 0.1250, 0.1250, 0.1250]])
xbow3 = wei @ x
#print(torch.allclose(xbow, xbow3)) ## returns 'True'
# this is more flexible than the other methods for different weights so is going to be the method we use.

#VERSION 4: Self-attention!
#Want to gather info from the past in a data-dependent way i.e. a vowel may look for consonants
#Every token at each position emits two vectors, a query, and a key, query vector is "what am I looking for", key is "what do I contain?"
#dot product between queries and keys to generate weights, if key and query are aligned they'll interact to a high amount and it will learn more about that token

torch.manual_seed(1337)
B,T,C = 4,8,32 # batch,time,channels
x = torch.randn(B,T,C)

# let's see a single Head perform self-attention
head_size = 16
key = nn.Linear(C, head_size, bias=False)
query = nn.Linear(C, head_size, bias=False)
value = nn.Linear(C, head_size, bias=False)
k = key(x) # (B, T, 16)
q = query(x) # (B, T, 16)
wei = q @ k.transpose(-2, -1) # (B, T, 16) @ (B, 16, T) ==> (B, T, T)
#print(wei[0])
#tensor([[-1.7629, -1.3011,  0.5652,  2.1616, -1.0674,  1.9632,  1.0765, -0.4530],
#        [-3.3334, -1.6556,  0.1040,  3.3782, -2.1825,  1.0415, -0.0557,  0.2927],
#        [-1.0226, -1.2606,  0.0762, -0.3813, -0.9843, -1.4303,  0.0749, -0.9547],
#        [ 0.7836, -0.8014, -0.3368, -0.8496, -0.5602, -1.1701, -1.2927, -1.0260],
#        [-1.2566,  0.0187, -0.7880, -1.3204,  2.0363,  0.8638,  0.3719,  0.9258],
#        [-0.3126,  2.4152, -0.1106, -0.9931,  3.3449, -2.5229,  1.4187,  1.2196],
#        [ 1.0876,  1.9652, -0.2621, -0.3158,  0.6091,  1.2616, -0.5484,  0.8048],
#        [-1.8044, -0.4126, -0.8306,  0.5898, -0.7987, -0.5856,  0.6433,  0.6303]],

tril = torch.tril(torch.ones(T, T))
#wei = torch.zeros((T, T))
wei = wei.masked_fill(tril == 0, float('-inf'))
wei = F.softmax(wei, dim=-1)
#print(wei[0])
#tensor([[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.1574, 0.8426, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.2088, 0.1646, 0.6266, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.5792, 0.1187, 0.1889, 0.1131, 0.0000, 0.0000, 0.0000, 0.0000],
#        [0.0294, 0.1052, 0.0469, 0.0276, 0.7909, 0.0000, 0.0000, 0.0000],
#        [0.0176, 0.2689, 0.0215, 0.0089, 0.6812, 0.0019, 0.0000, 0.0000],
#        [0.1691, 0.4066, 0.0438, 0.0416, 0.1048, 0.2012, 0.0329, 0.0000],
#        [0.0210, 0.0843, 0.0555, 0.2297, 0.0573, 0.0709, 0.2423, 0.2391]],

v = value(x)a # (B, T, 16)
#OLD WAY: out = wei @ x, NEW WAY:
out = wei @ v # (B, T, T) @ (B, T, 16) == (B, T, 16)
#print(out.shape) ## (4, 8, 16)

#Attention is a communication mechanism. Can be seen as nodes in a directed graph (each containing vectors of information) looking at each other and aggregating 
#wth a weighted sum from all nodes that point to them (all nodes point in the same direction), wih data-dependent weights
#It can be applied to any arbitrary directed graph
#In an encoder attention block just need to delete the line that does the masking with 'tril', allowing all tokens to communicate
#A decoder attention block has triangular masking, and is usually used in autoregressive settings, like language modelling
#"self-attention" means that keys and values are produced from the same source as queries. In "cross-attention" the queries
#are produced by "x" but keys and values come from some other external source (e.g. an "encoder" module)
#"Scaled" attention additionally multiplies wei by 1/sqrt(head_size). This it makes so when q and k are at unit variance, wei will be at unit
#variance too, and the softmax will remain diffuse and not vary too much. if this is not done the variance for wei will be on the order
#of head size. The more positive and negative the values get, the more wei will tend towards one-hot vectors. this is illustrated below:

#torch.softmax(torch.tensor([0.1, -0.2, 0.3, -0.2, 0.5]), dim=-1)
#OUTPUT: tensor([0.1925, 0.1426, 0.2351, 0.1426, 0.2872])

#torch.softmax(torch.tensor([0.1, -0.2, 0.3, -0.2, 0.5])*8, dim=-1)
#OUTPUT: tensor([0.0326, 0.0030, 0.1615, 0.0030, 0.8000])

#torch.softmax(torch.tensor([0.1, -0.2, 0.3, -0.2, 0.5])*80, dim=-1)
#OUTPUT: tensor([1.2664e-14, 4.7809e-25, 1.1254e-07, 4.7809e-25, 1.0000e+00])

#As can be seen above the values start to "sharpen" towards the maximum, as the values become more extreme



==> communication-computation-interspersed.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 32 # how many independent sequences will we process in parallel?
block_size = 8 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 10
learning_rate = 1e-3 #decrease of learning rate for self-attention block
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
n_embd = 32
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class Head(nn.Module):
	""" one head of self-attention """

	def __init__(self, head_size):
		super().__init__()
		self.key = nn.Linear(n_embd, head_size, bias=False)
		self.query = nn.Linear(n_embd, head_size, bias=False)
		self.value = nn.Linear(n_embd, head_size, bias=False)
		#nn.Linear(features_in, features out, bias=True) features_in == number of input neurons, features_out == number of output neurons
		self.register_buffer('tril', torch.tril(torch.ones(block_size, block_size)))
		#as tril is not a parameter in pytorch naming convention it is called a buffer, so is thus assigned

	def forward(self, x):
		B,T,C = x.shape
		k = self.key(x)		# (B, T, C)
		q = self.query(x) 	# (B, T, C)
		# compute attention scores ("affinities")
		wei = q @ k.transpose(-2,-1) * C**-0.5 # (B, T, C) @ (B, C, T) => (B, T, T)
		# in Pytorch -1 refers to the last dimension on the right, -2 to previous. So -2, -1 refer to the 2nd to last and last dimension
		wei = wei.masked_fill(self.tril[:T, :T] ==0, float('-inf')) # B, T, T
		wei = F.softmax(wei, dim=-1) # (B, T, T)
		# perform the weighted aggregation of the values
		v = self.value(x) # (B, T, C)
		out = wei @ v # (B, T, T) @ (B, T, C) => (B, T, C)
		return out

class MultiHeadAttention(nn.Module):
	""" multiple heads of self-attention in parallel """

	def __init__(self, num_heads, head_size):
		super().__init__()
		self.heads = nn.ModuleList((Head(head_size) for _ in range(num_heads)))
		#ModuleList registers the modules it contains as sub-modules, making sure their parameters are included when you call methods like
		#.parameters() or .to(device) on a module. It can be indexed like a regular list. It's similar to torch.nn.Sequential which not
		#only stores modules but invokes them sequentially during a forward pass. However sequential can cause problems defining custom fwd behaviours
		self.proj = nn.Linear(n_embd, n_embd)
		#proj also result of 'Residual connection' (Add operation in AIAYN paper)

	def forward(self, x):
		out = torch.cat([h(x) for h in self.heads], dim=-1)
		out = self.proj(out) # Linear transformation of outcome of above layer
		return out

class FeedForward(nn.Module):
	""" a simple linear layer followed by a non-linearity """

	def __init__(self, n_embd):
		super().__init__()
		self.net = nn.Sequential(
			nn.Linear(n_embd, 4 * n_embd),
			nn.ReLU(),
			nn.Linear(4 * n_embd, n_embd), #projection layer going back into the residual pathway
		)

	def forward(self, x):
		return self.net(x)

class Block(nn.Module):
	""" Transformer block: communication followed by computation """

	def __init__(self, n_embd, n_head):
		# n_embd: embedding dimension, n_head: the number of heads we'd like
		super().__init__()
		head_size = n_embd // n_head
		self.sa = MultiHeadAttention(n_head, head_size)
		self.ffwd = FeedForward(n_embd)
		self.ln1 = nn.LayerNorm(n_embd)
		self.ln2 = nn.LayerNorm(n_embd)

	#use of residual connection ('skip' connection) == x + (Add in AIAYN paper)
	def forward(self, x):
		x = x + self.sa(self.ln1(x))
		x = x + self.ffwd(self.ln2(x))
		return x

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, n_embd) # thin wrapper around tensor of shape vocab_size * n_embd
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings - number of rows in the embedding table
			#embedding_dim == the size of each embedding vector - number of columns in embedding table
		self.position_embedding_table = nn.Embedding(block_size, n_embd) #Also encodes positions into an embedding table
		self.blocks = nn.Sequential(
			Block(n_embd, n_head=4),
			Block(n_embd, n_head=4),
			Block(n_embd, n_head=4),
			nn.LayerNorm(n_embd),
		)
		self.lm_head = nn.Linear(n_embd, vocab_size) # lm_head == language modelling head

	def forward(self, idx, targets=None):
		B, T = idx.shape
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		tok_emb = self.token_embedding_table(idx) # (B,T,C==n_embd), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		pos_emb = self.position_embedding_table(torch.arange(T, device=device)) #(T,C), integers from 0 to T-1 are embedded through the table
		x = tok_emb + pos_emb # (B, T, C) == (B, T, C) + (T,C): (T,C) gets right-aligned, new dimension is added, and it is broadcast along batch dimension
		x = self.blocks(x)
		logits = self.lm_head(x) # (B,T,vocab_size)
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in ssequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			#crop idx to the last block_size tokens
			idx_cond = idx[:, -block_size:]
			# get the predictions
			logits, loss = self(idx_cond)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)
print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

==> gpt-dev.py <==
#!/usr/bin/python3.8

import torch
import torch.nn as nn
from torch.nn import functional as F

with open('input.txt', 'r', encoding='utf-8') as f:
	text = f.read()

# hyperparameters
batch_size = 64 # how many independent sequences will we process in parallel?
block_size = 256 # what is the maximum context length for predictions
max_iters = 5000
eval_interval = 1
learning_rate = 3e-4 #decrease of learning rate for self-attention block
device = 'cuda' if torch.cuda.is_available() else 'cpu'
eval_iters = 200
n_embd = 384
n_head = 6
n_layer = 6
dropout = 0.2 #randomly switch some neurons off during calculation
# -----------------

torch.manual_seed(1337)

chars = sorted(list(set(text)))
vocab_size = len(chars)
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }
encode = lambda s: [stoi[c] for c in s] #encoder: take a string, output a list of integers
decode = lambda l: ''.join([itos[i] for i in l]) #decoder: take a list of integers, output a string

data = torch.tensor(encode(text), dtype=torch.long)
n = int(0.9*len(data)) # first 90% will be train, rest val
train_data = data[:n]
val_data = data[n:]

def get_batch(split):
	#generate a small batch of data of inputs x and targets y
	data = train_data if split == 'train' else val_data
	ix = torch.randint(len(data) - block_size, (batch_size,)) #torch.randint(low=0, high, size) i.e. torch.randint(high, size)
	#Generates batch_size (i.e. 4) number of random offsets between 0 and len(data) - block_size
	x = torch.stack([data[i:i+block_size] for i in ix])
	y = torch.stack([data[i+1:i+block_size+1] for i in ix]) # torch.stack(tensors, dim=0, out=None)
	#torch.stack stacks sequences of tensors(that must have the same shape) along a new dimension. The default is 0
	#Therefore 1D tensors become rows in a new 2D tensor
	return x,y

@torch.no_grad()
def estimate_loss():
	out = {}
	model.eval()
	for split in ['train', 'val']:
		losses = torch.zeros(eval_iters)
		for k in range(eval_iters):
			X, Y = get_batch(split)
			logits, loss = model(X, Y)
			losses[k] = loss.item()
		out[split] = losses.mean()
	model.train()
	return out

class Head(nn.Module):
	""" one head of self-attention """

	def __init__(self, head_size):
		super().__init__()
		self.key = nn.Linear(n_embd, head_size, bias=False)
		self.query = nn.Linear(n_embd, head_size, bias=False)
		self.value = nn.Linear(n_embd, head_size, bias=False)
		#nn.Linear(features_in, features out, bias=True) features_in == number of input neurons, features_out == number of output neurons
		self.register_buffer('tril', torch.tril(torch.ones(block_size, block_size)))
		#as tril is not a parameter in pytorch naming convention it is called a buffer, so is thus assigned

		self.dropout = nn.Dropout(dropout)

	def forward(self, x):
		B,T,C = x.shape
		k = self.key(x)		# (B, T, C)
		q = self.query(x) 	# (B, T, C)
		# compute attention scores ("affinities")
		wei = q @ k.transpose(-2,-1) * C**-0.5 # (B, T, C) @ (B, C, T) => (B, T, T)
		# in Pytorch -1 refers to the last dimension on the right, -2 to previous. So -2, -1 refer to the 2nd to last and last dimension
		wei = wei.masked_fill(self.tril[:T, :T] ==0, float('-inf')) # B, T, T
		wei = F.softmax(wei, dim=-1) # (B, T, T)
		wei = self.dropout(wei)
		# perform the weighted aggregation of the values
		v = self.value(x) # (B, T, C)
		out = wei @ v # (B, T, T) @ (B, T, C) => (B, T, C)
		return out

class MultiHeadAttention(nn.Module):
	""" multiple heads of self-attention in parallel """

	def __init__(self, num_heads, head_size):
		super().__init__()
		self.heads = nn.ModuleList((Head(head_size) for _ in range(num_heads)))
		#ModuleList registers the modules it contains as sub-modules, making sure their parameters are included when you call methods like
		#.parameters() or .to(device) on a module. It can be indexed like a regular list. It's similar to torch.nn.Sequential which not
		#only stores modules but invokes them sequentially during a forward pass. However sequential can cause problems defining custom fwd behaviours
		self.proj = nn.Linear(n_embd, n_embd)
		#proj also result of 'Residual connection' (Add operation in AIAYN paper)
		self.dropout = nn.Dropout(dropout)

	def forward(self, x):
		out = torch.cat([h(x) for h in self.heads], dim=-1)
		out = self.dropout(self.proj(out)) # Linear transformation of outcome of above layer
		return out

class FeedForward(nn.Module):
	""" a simple linear layer followed by a non-linearity """

	def __init__(self, n_embd):
		super().__init__()
		self.net = nn.Sequential(
			nn.Linear(n_embd, 4 * n_embd),
			nn.ReLU(),
			nn.Linear(4 * n_embd, n_embd), #projection layer going back into the residual pathway
			nn.Dropout(dropout)
		)

	def forward(self, x):
		return self.net(x)

class Block(nn.Module):
	""" Transformer block: communication followed by computation """

	def __init__(self, n_embd, n_head):
		# n_embd: embedding dimension, n_head: the number of heads we'd like
		super().__init__()
		head_size = n_embd // n_head
		self.sa = MultiHeadAttention(n_head, head_size)
		self.ffwd = FeedForward(n_embd)
		self.ln1 = nn.LayerNorm(n_embd)
		self.ln2 = nn.LayerNorm(n_embd)

	#use of residual connection ('skip' connection) == x + (Add in AIAYN paper)
	def forward(self, x):
		x = x + self.sa(self.ln1(x))
		x = x + self.ffwd(self.ln2(x))
		return x

class BigramLanguageModel(nn.Module):
	def __init__(self):
		super().__init__()
		# each token directly reads off the logits for the next token from a lookup table
		self.token_embedding_table = nn.Embedding(vocab_size, n_embd) # thin wrapper around tensor of shape vocab_size * n_embd
		#torch.nn.Embedding(num_embeddings, embedding_dim)
			#num_embeddings == Size of the dictionary of embeddings - number of rows in the embedding table
			#embedding_dim == the size of each embedding vector - number of columns in embedding table
		self.position_embedding_table = nn.Embedding(block_size, n_embd) #Also encodes positions into an embedding table
		self.blocks = nn.Sequential(*[Block(n_embd, n_head=n_head) for _ in range(n_layer)])
		self.ln_f = nn.LayerNorm(n_embd) # final layer norm
		self.lm_head = nn.Linear(n_embd, vocab_size) # lm_head == language modelling head

	def forward(self, idx, targets=None):
		B, T = idx.shape
		# idx and targets are both tensors of integers of torch.Size([B, T])

		# passing inputs (referred to as idx) into token embedding table
		tok_emb = self.token_embedding_table(idx) # (B,T,C==n_embd), pytorch plucks out rows from idx tensor, arranges into batch * time * channel table
		pos_emb = self.position_embedding_table(torch.arange(T, device=device)) #(T,C), integers from 0 to T-1 are embedded through the table
		x = tok_emb + pos_emb # (B, T, C) == (B, T, C) + (T,C): (T,C) gets right-aligned, new dimension is added, and it is broadcast along batch dimension
		x = self.blocks(x)
		x = self.ln_f(x)
		logits = self.lm_head(x) # (B,T,vocab_size)
		# where batch == 4, time == 8, and channel == 65. Will interpret this arrangement as logits which are scores for next character in ssequence.
		
		if targets is None:
			loss = None
		else:
			B, T, C = logits.shape
			logits = logits.view(B*T, C) # implementation of negative log likelihood, expects C as 2nd dimension
			targets = targets.view(B*T)
			loss = F.cross_entropy(logits, targets) # F.cross_entropy(input, target) 	
			# input = Tensor of size (N, C), where C is the number of classes
			# target = Tensor of size N which contains the indices of the true classes for every data point
		return logits, loss

	def generate(self, idx, max_new_tokens):
		# idx is (B, T) array of indices in the current context
		for _ in range(max_new_tokens):
			#crop idx to the last block_size tokens
			idx_cond = idx[:, -block_size:]
			# get the predictions
			logits, loss = self(idx_cond)
			# focus only on the last time step, as that is prediction for what comes next
			logits = logits[:, -1, :] # becomes (B, C)
			# apply softmax to get probabilities
			probs = F.softmax(logits, dim=-1) # (B, C) # -1 means softmax will be applied to last dimension of input tensor
			# sample from the distribution, in each batch dimension only a single prediction for which sample comes next
			idx_next = torch.multinomial(probs, num_samples=1) # (B, 1)
			# torch.multinomial(input, num_samples)
				# input == input tensor containing probabilities to be used for sampling
				# num_samples == number of samples to be drawn from each distribution
			# append sampled index to the running sequence
			idx = torch.cat((idx, idx_next), dim=1) # (B, T+1)
		return idx

model = BigramLanguageModel() # calling it
m = model.to(device) # will move model to whatever device is set to, 'cuda' device or 'cpu'

# Creates a pytorch optimizer. AdamW more efficent than stochastic gradient descent (accessed via SGD)
optimizer = torch.optim.AdamW(m.parameters(), lr=1e-3)

for iter in range(max_iters):
	# every once in a while evaluate the loss on train and val sets
	if iter % eval_interval == 0:
		losses = estimate_loss()
		print(f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}")

	xb, yb = get_batch('train')

	#evaluate the loss
	logits, loss = m(xb, yb)
	optimizer.zero_grad(set_to_none=True)
	loss.backward()
	optimizer.step()

context = torch.zeros((1, 1), dtype=torch.long, device=device)

==>00_fundamentals.py<==

#!/usr/bin/python3.8

import torch
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

print(torch.__version__)

## Introduction to Tensors

#tensors are a way to represent multidimensional numeric data
# scalar
scalar = torch.tensor(7)
print(scalar) ## tensor(7)
print(scalar.ndim) ## 0
print(scalar.item()) ## 7 - returns as a python int

vector = torch.tensor([7,7])
print(vector) ## tensor([7,7])
print(vector.ndim) ## 1
print(vector.shape) ## torch.Size([2])

matrix = torch.tensor([[7, 8],
					   [9,10]])
print(matrix) ## tensor([[  7,  8],
#						 [  9, 10]])
print(matrix.ndim) ## 2
print(matrix[0]) ## tensor([ 7, 8])
print(matrix[1]) ## tensor([ 9, 10])
print(matrix.shape) ## torch.Size([2, 2])

tensor = torch.tensor([[[1,2,3],
						[3,6,9],
						[2,4,5]]])
print(tensor) # tensor([[[1, 2, 3],
#						 [3, 6, 9],
#						 [2, 4, 5]]])
print(tensor.ndim) # 3
print(tensor.shape) ## torch.Size([1,3,3])
print(tensor[0]) ## tensor([[1, 2, 3],
#							[3, 6, 9],
#							[2, 4, 5]])
print(tensor[0,0]) ## tensor([1, 2, 3])
print(tensor[0,1]) ## tensor([3, 6, 9])
print(tensor[0,2]) ## tensor([2, 4, 5])
print(tensor[0,:,0]) ## tensor([1, 3, 2])
print(tensor[0,:,1]) ## tensor([2, 6, 4])
print(tensor[0,:,2]) ## tensor([3, 9, 5])

##Random Tensors

random_tensor = torch.rand(3, 4)
print(random_tensor) # RESULT:
#tensor([[0.8390, 0.4004, 0.6413, 0.0766],
#        [0.3097, 0.4058, 0.0821, 0.9595],
#        [0.4169, 0.5951, 0.9291, 0.3680]])
print(random_tensor.ndim) # 2
print(random_tensor.dtype) # torch.float32

#Tensors are often initialized with zeroes or ones
zeros = torch.zeros(3,4)
print(zeros) # RESULT:
#tensor([[0., 0., 0., 0.],
#        [0., 0., 0., 0.],
#        [0., 0., 0., 0.]])

ones = torch.ones(3,4)
print(ones) # RESULT:
#tensor([[1., 1., 1., 1.],
#        [1., 1., 1., 1.],
#        [1., 1., 1., 1.]])

print(torch.arange(10)) # tensor([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
print(torch.arange(start=0,end=30,step=4)) #tensor([ 0,  4,  8, 12, 16, 20, 24, 28])
print(torch.zeros_like(torch.arange(10)))  # tensor([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])

#torch data types can be fund at pytorch.org/docs/table/tensors.html

float_32_tensor = torch.tensor([3.0, 6.0, 9.0])
float_16_tensor = float_32_tensor.type(torch.half) # casts to a float16 tensor
#float_16_tensor = float_32_tensor.type(torch.float16) # casts to a float16 tensor

float_16_tensor * float_32_tensor #will stil work
int_32_tensor = torch.tensor([3, 6, 9], dtype=torch.int32)
float_16_tensor * int_32_tensor #will also work

print(int_32_tensor.dtype) # wll return the dtype of the tensor
print(int_32_tensor.device) # wll return the device of the tensor

#Tensor operations include addition, subtraction, multiplication, division, matrix multiplication
newtensor = torch.tensor([1,2,3])
print(newtensor + 10) # broadcasting turns this operation [1,2,3] + [10,10,10]
print(newtensor * 10) # broadcasting turns this operation [1,2,3] * [10,10,10]
print(newtensor - 10) # broadcasting turns this operation [1,2,3] - [10,10,10]
print(newtensor * newtensor) # [1*1,2*2,3*3], element-wise multiply

#There are two main rules for performing matrix multiplication
#1. The inner dimensions must match i.e.
#	torch.Size(3, 2) @ torch.Size(3,2) won't work
#	torch.Size(2, 3) @ torch.Size(3,2) will work == torch.Size(2,2)
#	torch.Size(3, 2) @ torch.Size(2,3) will work == torch.Size(3,3)
#2. The resulting matrix has the shape of the outer dimensions

#there are other ways of matrix multiplication in pytorch
#torch.matmul(tensorA, tensorB) or torch.mm(tensorA, tensorB)

#Can use the transpose operation to alter shape of matrices

tensorA = torch.rand(2,3)
tensorB = torch.rand(2,3)
print(tensorA @ tensorB.T) # Now this will work
print(tensorA.T @ tensorB) # Now this will work
print((tensorA @ tensorB.T).shape) # New shape
print((tensorA.T @ tensorB).shape) # New shape

# Create a tensor
x = torch.arange(0, 100, 10)
print(f"x: {x}")
print(f"Min: {x.min()}")
print(f"Max: {x.max()}")
#print(f"Mean: {x.mean()}") ##will throw an error because dtype is int not float
print(f"Mean: {x.type(torch.float32).mean()}") #needs to be cast to float
print(f"sum: {x.sum()}")
print(f"Position of min: [{x.argmin()}]")
print(f"Position of max: [{x.argmax()}]")

## Reshaping, stacking, squeezing and unnsqueezing tensors

#Stacking - This is similar to concatenation, but stacks tensors along a new dimension instead of an existing one, increasing the dimensionality of the new tensor. It also requires tensors to be of the same shape.
#Squeezing - 'Squeezes' out (eliminates) all '1' dimensions from a tensor
#Unsqueeze - Adds a '1' dimension to a target tensor
#Permute - returns a view of the input tensor with dimensions permuted.

y = torch.rand(2, 5, 4) # dimensions 0, 1, 2
# torch.permute(*dims) -desired ordering of dimensions
print((y.permute(1,2,0)).shape) # returns torch.Size([5, 4, 2])

z1 = y.reshape(4,2,5) # reshapes to torch.Size([4, 2, 5])
z2 = y.view(4,10) # reshapes to torch.Size([6, 4])
#difference between reshape and view is that view shares the same memory space as the original tensor, so anything done to the result of a .view() operation is done to the original tensor, whereas .reshape() 'may' create a new object in a different memory location to the original tensor. 

z1[0,0] = 5.0
print(z1[0,0,0] == y[0,0,0])
z2[0,0] = 6.5
print(z2[0,0] == y[0,0,0])
#In the example above,  both return true as were in same memory location as original tensor

print((torch.stack([y, y, y], dim=0)).shape)
print((torch.stack([y, y, y], dim=1)).shape)
print((torch.stack([y, y, y], dim=2)).shape)
print((torch.stack([y, y, y], dim=3)).shape)

z3 = y.reshape(1,40)
print(z3.shape)
print(z3.squeeze().shape)
print(z3.unsqueeze(dim=0).shape)
print(z3.unsqueeze(dim=1).shape)
print(z3.unsqueeze(dim=2).shape)

#Numpy is a scientific numerical python computing library
#pytorch has functionality to interact with numPy and in fact requires numpy for installation.
#Data may be in NumPy array, want in a pytorch tensor => torch.from_numpy(ndarray)
#or the reverse from pytorch tensor to numpy => torch.Tensor.numpy()

array = np.arange(1.0, 8.0)
torchtensor = torch.from_numpy(array)
print(array)
print(array.dtype) # numpy default data type is float64
print(torchtensor) # will now use numpy data type

#torchtensor = torch.from_numpy(array).type(float32) ## will cast to float32

torchtensor1 = torch.ones(7)
numpy_array = torchtensor1.numpy()
print(numpy_array)
print(numpy_array.dtype) # numpy data type is now float32
print(f"{torchtensor1}, dtype={torchtensor1.dtype}") 

#if want reproducibility, may need generator seeds or random seeds
RANDOM_SEED = 42
torch.manual_seed(RANDOM_SEED)
random_tensor_A = torch.rand(3,4)
random_tensor_B = torch.rand(3,4)

print(random_tensor_A == random_tensor_B) #will return majority or all false

torch.manual_seed(RANDOM_SEED)
random_tensor_C = torch.rand(3,4)
torch.manual_seed(RANDOM_SEED)
random_tensor_D = torch.rand(3,4)

print(random_tensor_C == random_tensor_D) #will return all true

#as shown above, the random seed has to be set every time the rand() method is called

print(decode(m.generate(context, max_new_tokens=500)[0].tolist()))

# To setup device agnostic code (all below is device agnostic)
device = "cuda" if torch.cuda.is_available() else "cpu"

print(torch.cuda.device_count())

#Create a tensor (default is on the CPU)
cputensor = torch.tensor([1,2,3])
print(cputensor, cputensor.device)

#Move tensor to GPU (if available)
gputensor = cputensor.to(device)
print(gputensor) # if gpu available, returns tensor([1, 2, 3], device='cuda:0')

#Numpy only works with the CPU, so may want to move tensors to CPU

gputensor.numpy() # If cuda TypeError: can't convert cuda:0 device type tensor to numpy. Use Tensor.cpu() to copy the tensor to host memory first

newcputensor = gputensor.cpu().numpy() # will convert back to numpy array

#Methods which mutate a tensor are marked with an underscore suffix. For example, torch.FloatTensor.abs_() computes the absolute value in-place and returns the modified tensor, while torch.FloatTensor.abs() computes the result in a new tensor.

#Each tensor has an associated torch.Storage, which holds its data. The tensor class also provides multi-dimensional, strided view of a storage and defines numeric operations on it

#tensor access
acctensor = torch.ones(4,4)
print(f"First row: {acctensor[0]}")
print(f"First column: {acctensor[:, 0]}")
print(f"Last column: {acctensor[..., -1]}")
acctensor[:,1] = 0 # 2nd column
print(acctensor)

print(torch.cat([acctensor, acctensor, acctensor])) #dim=0
print(torch.cat([acctensor, acctensor, acctensor], dim=1)) 

#In-place operations Operations that store the result into the operand are called in-place. They are denoted by a _ suffix. For example: x.copy_(y), x.t_(), will change x

acctensor.add_(3)
print(acctensor)

==> torch_quickstart.py <==
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 21:19:27 2023

@author: leslietetteh
"""

import torch
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor

#PyTorch offers domain-specific libraries such as TorchText, TorchVision, and 
#TorchAudio, all of which include datasets. For this tutorial, we will be using 
#a TorchVision dataset.
#The torchvision.datasets module contains Dataset objects for many real-world 
#vision data like CIFAR, COCO (full list here). In this tutorial, we use the 
#FashionMNIST dataset. Every TorchVision Dataset includes two arguments:  
#transform and target_transform to modify the samples and labels respectively.

# Download training data from open datasets
training_data = datasets.FashionMNIST(
    root="data",
    train=True,
    download=True,
    transform=ToTensor(),    
)

#Download test data from open datasets.
test_data = datasets.FashionMNIST(
    root="data",
    train=False,
    download=True,
    transform=ToTensor(),    
)

#We pass the Dataset as an argument to DataLoader. This wraps an iterable over 
#our dataset, and supports automatic batching, sampling, shuffling and 
#multiprocess data loading. Here we define a batch size of 64, i.e. each element 
#in the dataloader iterable will return a batch of 64 features and labels.

batch_size = 64

# Create data loaders
train_dataloader = DataLoader(training_data, batch_size=batch_size)
test_dataloader = DataLoader(test_data, batch_size=batch_size)

for X, y in test_dataloader:
    print(f"Shape of X [N, C, H, W]: {X.shape}")
    print(f"Shape of y: {y.shape} {y.dtype}")
    break

# Get cpu, gpu or mps device for training
device = (
    "cuda"
    if torch.cuda.is_available()
    else "mps"
    if torch.backends.mps.is_available()
    else "cpu"    
)
print(f"Using {device} device")

#To define a neural network in PyTorch, we create a class that inherits from 
#nn.Module. We define the layers of the network in the __init__ function and 
#specify how data will pass through the network in the forward function. To 
#accelerate operations in the neural network, we move it to the GPU or MPS if available.

#Define model
class NeuralNetwork(nn.Module):
    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        self.linear_relu_stack = nn.Sequential(
            nn.Linear(28*28, 512),
            nn.ReLU(),
            nn.Linear(512, 512),
            nn.ReLU(),
            nn.Linear(512, 10)
        )
        
    def forward(self, x):
        x = self.flatten(x)
        logits = self.linear_relu_stack(x)
        return logits
    
model = NeuralNetwork().to(device)
print(model)
    
#To train a model, we need a loss function and an optimizer.

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=1e-3) #stochastic gradient descent

#In a single training loop, the model makes predictions on the training dataset 
#(fed to it in batches), and backpropagates the prediction error to adjust the 
#model’s parameters.   

def train(dataloader, model, loss_fn, optimizer):
    size = len(dataloader.dataset)
    model.train()
    for batch, (X, y) in enumerate(dataloader):
        X, y = X.to(device), y.to(device)
        
        # Compute prediction error
        pred = model(X)
        loss = loss_fn(pred, y)
        
        # Backpropagation
        loss.backward()
        optimizer.step()
        optimizer.zero_grad()
        
        if batch % 100 == 0:
            loss, current = loss.item(), (batch + 1) * len(X)
            print(f"loss: {loss:>7f} [{current:>5d}/{size:>5d}]")
            
#We also check the model''s performance against the test dataset to ensure its learning

def test(dataloader, model, loss_fn):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    model.eval()
    test_loss, correct = 0, 0
    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.to(device), y.to(device)
            pred = model(X)
            test_loss += loss_fn(pred, y).item()
            correct += (pred.argmax(1) == y).type(torch.float).sum().item()
    test_loss /= num_batches
    correct /= size
    print(f"Test Error: \n Accuracy {(100*correct):>0.1f}%, AVg loss{test_loss:>8f}\n")

#The training process is conducted over several iterations (epochs). During each 
#epoch, the model learns parameters to make better predictions. We print the 
#model’s accuracy and loss at each epoch; we’d like to see the accuracy increase 
#and the loss decrease with every epoch.

epochs = 5
for t in range(epochs):
    print(f"Epoch {t+1}\n-----------------------------")
    train(train_dataloader, model, loss_fn, optimizer)
    test(test_dataloader, model, loss_fn)
    
#A common way to save a model is to serialize the internal state dictionary 
#(containing the model parameters).

torch.save(model.state_dict(), "model.pth")
print("Saved PyTorch Model State to model.pth")

==> torch_quickstart2.py <==

# -*- coding: utf-8 -*-
"""
Created on Sat Oct 21 12:20:34 2023

@author: leslietetteh
"""

import torch
from torch import nn
from torchvision import datasets
from torchvision.transforms import ToTensor

#Setup code

test_data = datasets.FashionMNIST(
    root="data",
    train=False,
    download=True,
    transform=ToTensor(),
)

class NeuralNetwork(nn.Module):
    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        self.linear_relu_stack = nn.Sequential(
            nn.Linear(28*28, 512),
            nn.ReLU(),
            nn.Linear(512, 512),
            nn.ReLU(),
       ++     nn.Linear(512, 10)
        )
        
    def forward(self, x):
        x = self.flatten(x)
        logits = self.linear_relu_stack(x)
        return logits

device = (
    "cuda" 
    if torch.cuda.is_available()
    else "mps"
    if torch.backends.mps.is_available()
    else "cpu"
)

#The process for loading a model includes re-creating the model structure and 
#loading the state dictionary into it

model = NeuralNetwork().to(device)
model.load_state_dict(torch.load("model.pth"))

classes = [
    "T-shirt/top",
    "Trouser",
    "Pullover",
    "Dress",
    "Coat",
    "Sandal",
    "Shirt",
    "Sneaker",
    "Bag",
    "Ankle boot",    
]

model.eval()
x, y = test_data[0][0], test_data[0][1]
with torch.no_grad():
    x = x.to(device)
    pred = model(x)
    predicted, actual = classes[pred[0].argmax(0)], classes[y]
    print(f'Predicted: "{predicted}", Actual: "{actual}"')
          
==> pytorch_workflow0load.py <==
#!/usr/bin/python3.8

import torch
from torch import nn # nn contains all of PyTorch's building blocks for graphs
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

print(torch.__version__)

class LinearRegressionModel(nn.Module):
	def __init__(self):
		super().__init__()
		self.weights = nn.Parameter(torch.rand(1))
		self.bias = nn.Parameter(torch.rand(1))

		def forward(self, x: torch.Tensor) -> torch.Tensor:
			return self.weights * x + self.bias

loaded_model_0 = LinearRegressionModel()

MODEL_PATH = Path("models")
MODEL_NAME = "01_pytorch_workflow_model_0.pth"
MODEL_SAVE_PATH = MODEL_PATH / MODEL_NAME

loaded_model_0.load_state_dict(torch.load(f=MODEL_SAVE_PATH))
print(loaded_model_0.state_dict())

==> pytorch_workflow0save.py <==
#!/usr/bin/python3.8

import torch
from torch import nn # nn contains all of PyTorch's building blocks for graphs
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

print(torch.__version__)

#Data (preparing and loading)

#Using linear regression formula (Y= ax + b) to make straight line with known parameters
weight = 0.7 #a
bias = 0.3   #b

start = 0
end = 1
step = 0.02
X = torch.arange(start, end, step).unsqueeze(dim=1)
y = weight * X + bias

print(f"{X[:10]}")
print(f"{y[:10]}")
print(f"{len(X)}")
print(f"{len(y)}")

#purpose of machine learning is to learn a representation of input and how it maps to output

train_split = int(0.8 * len(X))
X_train, y_train = X[:train_split], y[:train_split] #Before train_split
X_test, y_test = X[train_split:], y[train_split:] #After train_split

print(f"{len(X_train)}, {len(y_train)}, {len(X_test)}, {len(y_test)}")

#To visualize the data
def plot_predictions(train_data=X_train,
					 train_labels=y_train,
					 test_data=X_test,
					 test_labels=y_test,
					 predictions=None):
	plt.figure(figsize=(10,7))
	# Plot training data in blue
	plt.scatter(train_data, train_labels, c="b", s=4, label="Training data")

	# Plot test data in green
	plt.scatter(test_data, test_labels, c="g", s=4, label="Testing data")

	#Are there predictions?
	if predictions is not None:
		#Plot the predictions if they exist
		plt.scatter(test_data, predictions, c="r", s=4, label="Predictions")

	#Show the legend
	plt.legend(prop={"size": 14})
	plt.show()

plot_predictions()

#Create LinearRegressionModel class
class LinearRegressionModel(nn.Module):
	def __init__(self):
		super().__init__()
		self.weights = nn.Parameter(torch.rand(1,requires_grad=True,dtype=torch.float))
		self.bias = nn.Parameter(torch.randn(1,requires_grad=True,dtype=torch.float))
		
	#forward() defines the forward computation in the model
	#any subclass of nn.Module (inheriting) needs to override forward()
	def forward(self, x: torch.Tensor) -> torch.Tensor: #x is the input data
		return self.weights * x + self.bias # this is the linear regression formula
		
#the model starts with random values, looks at trainng data and adjust the random values
#to get closer to the real data. Does this through gradient descent and backpropagation

torch.manual_seed(42)

model_0 = LinearRegressionModel()

print(list(model_0.parameters())) # prints values for self.weights & self.bias
print(list(model_0.state_dict())) # returns 'weights' and 'bias'

#initializes with requires_grad=True and therefore not optiized for predictions
y_preds_not_optimized = model_0(X_test)

#making a prediction using 'torch.inference_mode()', sets requires_grad to False and
#has other features that give it an advantage over using torch.no_grad()
with torch.inference_mode():
	y_preds = model_0(X_test)

print(y_preds_not_optimized) # can see the gradient object
print(y_preds)
print(y_test)
plot_predictions(predictions=y_preds)

#loss function can also be called 'cost function' or 'criterion'. It measures how 
#wrong your model's output are compared to the actual data. It can do this through
#the 'mean absolute error'.It then uses an optimizer to adjust the model parameters
#to minimize the loss function output.

#Mean Absolute Error is referred to as nn.L1Loss and is usually used for regression problems
#nn.MSELoss, (mean squared error, known as L2 loss) is similarly used for regression, while
#cross-entropy loss is usually used for classification problems. read pytorch loss functions

#Loss function:
loss_fn = nn.L1Loss()

#Optimizer:
optimizer = torch.optim.SGD(params=model_0.parameters(), lr=0.01)
# Stochastic (uses random subset of data in each iteration to find minimum of function),
# instead of using the whole dataset
#lr (learning rate) is possibly the most important hyperparameter, hyperparameter refers to
#any parameter which is set manually by the user

#Necessary steps in a training loop
#0. Loop through data
#1. Perform forward pass (move through model forward() function) to make predictions on data
#2. Calculate the loss (compare fwd pass predictions to ground truth labels)
#3. Optimizer zero grad
#4. loss.backward() - calculate gradients of parameters with respect to the loss
#5. Optimize - use optimizer to adjust model's parameters to try and improve loss

#An epoch is one loop through all the data (also a hyperparameter, because set by user)
epochs = 400

#Track different values
epoch_count = []
loss_values = []
test_loss_values = []

#Training
for epoch in range(epochs):
	#set the model to training mode
	model_0.train() # sets requires_grad to true for parameters that require gradients
	#1. Forward pass
	y_pred = model_0(X_train)
	#2. Calculate the loss
	loss = loss_fn(y_pred, y_train)
	#3. Optimizer zero grad
	optimizer.zero_grad()
	#4. Backpropagation on loss with respect to model paramenters
	loss.backward()
	#5. Step the optimizer (perform gradient descent)
	optimizer.step()
	
	#Testing
	if epoch % 10 == 0:
		model_0.eval() #must call model.eval() to set dropout and batch norm layers
		#to evaluation mode before running inference. Failing to do this will yield
		#inconsistent inference results.

		with torch.inference_mode():
			y_preds = model_0(X_test)
			test_loss = loss_fn(y_preds, y_test)
		#plot_predictions(predictions=y_preds)
		
		epoch_count.append(epoch)
		loss_values.append(loss.item())
		test_loss_values.append(test_loss)
		#print(f"Epoch: {epoch} | Loss: {loss} | Test loss: {test_loss}")
		#print(f"{list(model_0.parameters())}") # prints values for weights & bias

	#by default optimizer grad will accumulate over multiple loops. Needs zero_grad
	#operation on each iteration of the loop, before performing backpropagation

#if appending loss instead off loss.item()
#plt.plot(epoch_count, torch.tensor(loss_values).numpy(), label="Train loss")
plt.plot(epoch_count, loss_values, label="Train loss")
plt.plot(epoch_count, test_loss_values, label="Test loss")
plt.title("Training and test loss curves")
plt.ylabel("Loss")
plt.xlabel("Epochs")
plt.legend()
plt.show()

#Three main methods need to know about saving and loading a model in PyTorch
#1. 'torch.save()' -saves a pytorch object in python's pickle format
#2. 'torch.load()' -allows you to load a saved PyTorch object
#3. 'torch.nn.Module.load_state_dict()' -this allows to load a model's parameters
#(its saved state dictionary)

# 1. Create models directory
MODEL_PATH = Path("models")
MODEL_PATH.mkdir(parents=True, exist_ok=True) # if already exists wont throw error

# 2. Create Model save path
MODEL_NAME = "01_pytorch_workflow_model_0.pth"
MODEL_SAVE_PATH = MODEL_PATH / MODEL_NAME

print(MODEL_SAVE_PATH)

# 3. Save the model state dict
print(f"Saving model to: {MODEL_SAVE_PATH}")
torch.save(obj=model_0.state_dict(), f=MODEL_SAVE_PATH)

==> pytorch_workflow1.py <==
#!/usr/bin/python3.8

import torch
from torch import nn
import matplotlib.pyplot as plt
from pathlib import Path

print(torch.__version__)

device = "cuda" if torch.cuda.is_available() else "cpu"
print(f"Using device: {device}")

weight = 0.7
bias = 0.3
amin = 0
amax = 1
step = 0.02

X = torch.arange(amin, amax, step).unsqueeze(dim=1)
y = weight * X + bias

train_split = int(0.8 * len(X))
X_train, y_train = X[:train_split], y[:train_split]
X_test, y_test = X[train_split:], y[train_split:]

def plot_predictions(train_data=X_train,
					 train_labels=y_train,
					 test_data=X_test,
					 test_labels=y_test,
					 predictions=None):
	plt.figure(figsize=(10,7))
	plt.scatter(train_data, train_labels, c="b", s=4, label="Training data")
	plt.scatter(test_data, test_labels, c="g", s=4, label="Test data")

	if predictions is not None:
		plt.scatter(test_data, predictions, c="r", s=4, label="Predictions")

	plt.legend(prop={"size": 14})
	plt.show()

plot_predictions()

#Build model
class LinearRegressionModel1(nn.Module):
	def __init__(self):
		super().__init__()

		#Use nn.Linear for creating model parameters, instead of explicitly stating
		self.linear_layer = nn.Linear(in_features=1, out_features=1) #1 input, 1 output
	
	def forward(self, x: torch.Tensor) -> torch.Tensor:
		return self.linear_layer(x)
		
torch.manual_seed(42)
model_1 = LinearRegressionModel1()
print(model_1)
print(model_1.state_dict())

model_1.to(device)

#Loss function
loss_fn = nn.L1Loss()

#Optimizer
optimizer = torch.optim.SGD(params=model_1.parameters(), lr=0.005)

#training loop
torch.manual_seed(42)

epochs = 300

#Put data on target device (device agnostic code for data)
X_train = X_train.to(device) 
y_train = y_train.to(device)
X_test = X_test.to(device)
y_test = y_test.to(device)

for epoch in range(epochs):
	model_1.train()

	#Forward pass
	y_pred = model_1(X_train)

	#calculate loss
	loss = loss_fn(y_pred, y_train)

	#optimizer zero grad
	optimizer.zero_grad()

	#perform backpropagation
	loss.backward()

	#Optimizer Step
	optimizer.step()

	#
	model_1.eval()
	with torch.inference_mode():
		test_pred= model_1(X_test)

		test_loss= loss_fn(test_pred, y_test)
	
		if epoch % 10 == 0:
			print(f"Epoch: {epoch} | Loss: {loss} | Test Loss: {test_loss}")
			#plot_predictions(predictions=test_pred)

print(model_1.state_dict())

MODEL_PATH = Path("models")
MODEL_PATH.mkdir(parents=True, exist_ok=True)

MODEL_NAME = "01_pytorch_workflow_model_1.pth"
MODEL_SAVE_PATH = MODEL_PATH / MODEL_NAME

print(f"Saving model to: {MODEL_SAVE_PATH}")
torch.save(obj=model_1.state_dict(), f=MODEL_SAVE_PATH)

model_1loaded = LinearRegressionModel1()
model_1loaded.load_state_dict(torch.load(MODEL_SAVE_PATH))

model_1loaded.to(device)
print(model_1loaded)
print(model_1loaded.state_dict())

==> nn_tutorial0.py <==
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 22 19:13:00 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

try:
    import google.colab
except ImportError:
    pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

#Let’s first create a model using nothing but PyTorch tensor 
#operations. We’re assuming you’re already familiar with the 
#basics of neural networks. (If you’re not, you can learn them at 
#course.fast.ai).

#PyTorch provides methods to create random or zero-filled tensors, 
#which we will use to create our weights and bias for a simple 
#linear model. These are just regular tensors, with one very 
#special addition: we tell PyTorch that they require a gradient. 
#This causes PyTorch to record all of the operations done on the 
#tensor, so that it can calculate the gradient during back-propagation

#For the weights, we set requires_grad after the initialization, 
#since we don’t want that step included in the gradient. (Note the 
#trailing _ in PyTorch signifies that the operation is performed 
#in-place.)

#NOTE: We are initializing the weights here with Xavier 
#initialisation (by multiplying with 1/sqrt(n)).

import math

weights = torch.randn(784, 10) / math.sqrt(784)
weights.requires_grad_()
bias = torch.zeros(10, requires_grad=True)

#Thanks to PyTorch’s ability to calculate gradients automatically, 
#we can use any standard Python function (or callable object) as a 
#model! So let’s just write a plain matrix multiplication and 
#broadcasted addition to create a simple linear model. We also 
#need an activation function, so we’ll write log_softmax and use 
#it. Remember: although PyTorch provides lots of prewritten loss 
#functions, activation functions, and so forth, you can easily 
#write your own using plain python. PyTorch will even create fast 
#GPU or vectorized CPU code for your function automatically.

def log_softmax(x):
    return x - x.exp().sum(-1).log().unsqueeze(-1)

def model(xb):
    return log_softmax(xb @ weights + bias)

#In the above, the @ stands for the matrix multiplication 
#operation. We will call our function on one batch of data (in 
#this case, 64 images). This is one forward pass. Note that our 
#predictions won’t be any better than random at this stage, since 
#we start with random weights.

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s implement negative log-likelihood to use as the loss 
#function (again, we can just use standard Python):
    
def nll(input, target):
    return -input[range(target.shape[0]), target].mean()

loss_func = nll

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

for epoch in range(epochs):
    for i in range((n - 1) // bs + 1):
        #set_trace()
        start_i = i * bs
        end_i = start_i + bs
        xb = x_train[start_i:end_i]
        yb = y_train[start_i:end_i]
        pred = model(xb)
        loss = loss_func(pred, yb)
        
        loss.backward()
        with torch.no_grad():
            weights -= weights.grad * lr
            bias -= bias.grad * lr
            weights.grad.zero_()
            bias.grad.zero_()
            
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial1.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 16:06:39 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

try:
    import google.colab
except ImportError:
    pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

#Let’s first create a model using nothing but PyTorch tensor 
#operations. We’re assuming you’re already familiar with the 
#basics of neural networks. (If you’re not, you can learn them at 
#course.fast.ai).

#PyTorch provides methods to create random or zero-filled tensors, 
#which we will use to create our weights and bias for a simple 
#linear model. These are just regular tensors, with one very 
#special addition: we tell PyTorch that they require a gradient. 
#This causes PyTorch to record all of the operations done on the 
#tensor, so that it can calculate the gradient during back-propagation

#For the weights, we set requires_grad after the initialization, 
#since we don’t want that step included in the gradient. (Note the 
#trailing _ in PyTorch signifies that the operation is performed 
#in-place.)

#NOTE: We are initializing the weights here with Xavier 
#initialisation (by multiplying with 1/sqrt(n)).

import math

weights = torch.randn(784, 10) / math.sqrt(784)
weights.requires_grad_()
bias = torch.zeros(10, requires_grad=True)

# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll

#Using torch.nn.functional

#We will now refactor our code, so that it does the same thing as 
#before, only we’ll start taking advantage of PyTorch’s nn classes 
#to make it more concise and flexible. At each step from here, we 
#should be making our code one or more of: shorter, more 
#understandable, and/or more flexible.

#The first and easiest step is to make our code shorter by 
#replacing our hand-written activation and loss functions with 
#those from torch.nn.functional (which is generally imported into 
#the namespace F by convention). This module contains all the 
#functions in the torch.nn library (whereas other parts of the 
#library contain classes). As well as a wide range of loss and 
#activation functions, you’ll also find here some convenient 
#functions for creating neural nets, such as pooling functions. 
#(There are also functions for doing convolutions, linear layers, 
#etc, but as we’ll see, these are usually better handled using 
#other parts of the library.)

import torch.nn.functional as F

loss_func = F.cross_entropy

def model(xb):
    return xb @ weights + bias

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.


#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

for epoch in range(epochs):
    for i in range((n - 1) // bs + 1):
        #set_trace()
        start_i = i * bs
        end_i = start_i + bs
        xb = x_train[start_i:end_i]
        yb = y_train[start_i:end_i]
        pred = model(xb)
        loss = loss_func(pred, yb)
        
        loss.backward()
        with torch.no_grad():
            weights -= weights.grad * lr
            bias -= bias.grad * lr
            weights.grad.zero_()
            bias.grad.zero_()
            
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial2.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 16:22:00 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

try:
    import google.colab
except ImportError:
    pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.

import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
        self.bias = nn.Parameter(torch.zeros(10))
        
    def forward(self, xb):
        return xb @ self.weights + self.bias

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

model = Mnist_Logistic()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.


#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

#We’ll wrap the training loop in a fit function to run it again later.

def fit():
    for epoch in range(epochs):
        for i in range((n - 1) // bs + 1):
            #set_trace()
            start_i = i * bs
            end_i = start_i + bs
            xb = x_train[start_i:end_i]
            yb = y_train[start_i:end_i]
            pred = model(xb)
            loss = loss_func(pred, yb)
            
            loss.backward()
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    #Previously for our training loop we had to update the values for 
    #each parameter by name, and manually zero out the grads for each 
    #parameter separately, (above)
    
    #Now we can take advantage of model.parameters() and model.zero_grad() 
    #(which are both defined by PyTorch for nn.Module) to make those steps 
    #more concise and less prone to the error of forgetting some of our 
    #parameters, particularly if we had a more complicated model:
            with torch.no_grad():
                for p in model.parameters():
                    p -= p.grad * lr
                model.zero_grad()

fit()
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial3.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 17:12:16 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

try:
    import google.colab
except ImportError:
    pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    model = Mnist_Logistic()
    return model, optim.SGD(model.parameters(), lr=lr)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

#We’ll wrap the training loop in a fit function to run it again later.

def fit():
    for epoch in range(epochs):
        for i in range((n - 1) // bs + 1):
            #set_trace()
            start_i = i * bs
            end_i = start_i + bs
            xb = x_train[start_i:end_i]
            yb = y_train[start_i:end_i]
            pred = model(xb)
            loss = loss_func(pred, yb)
            
            loss.backward()
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.

    #This will let us replace the code above:
            opt.step()
            opt.zero_grad()
fit()
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial4.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 17:42:56 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

try:
    import google.colab
except ImportError:
    pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    model = Mnist_Logistic()
    return model, optim.SGD(model.parameters(), lr=lr)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#We’ll wrap the training loop in a fit function to run it again later.

def fit():
    for epoch in range(epochs):
        for i in range((n - 1) // bs + 1):
            #set_trace()
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            #Previously, we had to iterate through minibatches of x 
            #and y vals separately. Now, we do these 2 steps together:
            xb,yb = train_ds[i*bs : i*bs + bs]
            pred = model(xb)
            loss = loss_func(pred, yb)
            
            loss.backward()
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.

    #This will let us replace the code above:
            opt.step()
            opt.zero_grad()
fit()
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial5.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 17:58:07 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
# #import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")

pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

# #import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    model = Mnist_Logistic()
    return model, optim.SGD(model.parameters(), lr=lr)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#Refactor using DataLoader

#PyTorch’s DataLoader is responsible for managing batches. You can 
#create a DataLoader from any Dataset. DataLoader makes it easier to 
#iterate over batches. Rather than using train_ds[i*bs : i*bs+bs], 
#the DataLoader gives us each minibatch automatically.

from torch.utils.data import DataLoader

train_dl = DataLoader(train_ds, batch_size=bs, shuffle=True)

#Add validation

#Shuffling (above) training data is important to prevent correlation 
#between batches and overfitting. On the other hand, the validation 
#loss will be identical whether we shuffle the validation set or not. 
#Since shuffling takes extra time, it makes no sense to shuffle the 
#validation data.

#We’ll use a batch size for the validation set that is twice as large 
#as that for the training set. This is because the validation set does 
#not need backpropagation and thus takes less memory (it doesn’t need 
#to store the gradients). We take advantage of this to use a larger 
#batch size and compute the loss more quickly

valid_ds = TensorDataset(x_valid, y_valid)
valid_dl = DataLoader(valid_ds, batch_size=bs * 2)

#We will calculate and print validation loss at the end of each epoch.

#Note: we always call model.train() before training, and model.eval() 
#before inference, because these are used by layers such as 
#nn.BatchNorm2d and nn.Dropout to ensure appropriate behavior for 
#these different phases.)

#We’ll wrap the training loop in a fit function to run it again later.

def fit():
    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            pred = model(xb)
            loss = loss_func(pred, yb)
            loss.backward()
            
        # #for i in range((n - 1) // bs + 1):
            # #set_trace()
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            # #Previously, we had to iterate through minibatches of x 
            # #and y vals separately. Now, we do these 2 steps together:
            # #xb,yb = train_ds[i*bs : i*bs + bs]
            # #pred = model(xb)
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.

    #This will let us replace the code above:
            
            opt.step()
            opt.zero_grad()
        
        model.eval()
        with torch.no_grad():
            valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)
        print(f"Epoch: {epoch}, valid_loss: {valid_loss / len(valid_dl)}")
fit()
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial6.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 18:39:56 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.5 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")
pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

# #import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    model = Mnist_Logistic()
    return model, optim.SGD(model.parameters(), lr=lr)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#Add validation

#Shuffling (above) training data is important to prevent correlation 
#between batches and overfitting. On the other hand, the validation 
#loss will be identical whether we shuffle the validation set or not. 
#Since shuffling takes extra time, it makes no sense to shuffle the 
#validation data.

#We’ll use a batch size for the validation set that is twice as large 
#as that for the training set. This is because the validation set does 
#not need backpropagation and thus takes less memory (it doesn’t need 
#to store the gradients). We take advantage of this to use a larger 
#batch size and compute the loss more quickly

valid_ds = TensorDataset(x_valid, y_valid)

#Refactor using DataLoader

#PyTorch’s DataLoader is responsible for managing batches. You can 
#create a DataLoader from any Dataset. DataLoader makes it easier to 
#iterate over batches. Rather than using train_ds[i*bs : i*bs+bs], 
#the DataLoader gives us each minibatch automatically.

from torch.utils.data import DataLoader

def get_data(train_ds, valid_ds, bs):
    return(
        DataLoader(train_ds, batch_size=bs, shuffle=True),
        DataLoader(valid_ds, batch_size=bs * 2),
    )

train_dl, valid_dl = get_data(train_ds, valid_ds, bs)

#We will calculate and print validation loss at the end of each epoch.

#Note: we always call model.train() before training, and model.eval() 
#before inference, because these are used by layers such as 
#nn.BatchNorm2d and nn.Dropout to ensure appropriate behavior for 
#these different phases.)

#We’ll now do a little refactoring of our own. Since we go through a 
#similar process twice of calculating the loss for both the training 
#set and the validation set, let’s make that into its own function, 
#loss_batch, which computes the loss for one batch.

#We pass an optimizer in for the training set, and use it to perform 
#backprop. For the validation set, we don’t pass an optimizer, so the 
#method doesn’t perform backprop.

def loss_batch(model, loss_func, xb, yb, opt=None):
    loss = loss_func(model(xb), yb)
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.
    if opt is not None:
        loss.backward()
        opt.step()
        opt.zero_grad()
        
    return loss.item(), len(xb)

#We’ll wrap the training loop in a fit() function to run again later.

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

def fit(epochs, model, loss_func, opt, train_dl, valid_dl):
    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            #set_trace()
            loss_batch(model, loss_func, xb, yb, opt)
            
            # #pred = model(xb)
            # #loss = loss_func(pred, yb)
            # #loss.backward()
        # #for i in range((n - 1) // bs + 1):
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            # #Previously, we had to iterate through minibatches of x 
            # #and y vals separately. Now, we do these 2 steps together:
            # #xb,yb = train_ds[i*bs : i*bs + bs]
            # #pred = model(xb)
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    # #This will let us replace the code above:
        
        model.eval()
        with torch.no_grad():
            losses, nums = zip(
                *[loss_batch(model, loss_func, xb, yb) for xb, yb in valid_dl]    
            )
            # #valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)
        # #print(f"Epoch: {epoch}, valid_loss: {valid_loss / len(valid_dl)}")
        val_loss = np.sum(np.multiply(losses, nums)) / np.sum(nums)
        print(f"Epoch: {epoch}, val loss: {val_loss}")

fit(epochs, model, loss_func, opt, train_dl, valid_dl)
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial7.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 19:34:08 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.1 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")
pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

# #import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#Switch to CNN

#We are going to build a neural network with three convolutional 
#layers. Because none of the functions in the previous section 
#assume anything about the model form, we’ll be able to use them to 
#train a CNN without any modification.

#We will use PyTorch’s predefined Conv2d class as our convolutional 
#layer, defining a CNN with 3 convolutional layers. Each convolution 
#is followed by a ReLU. At the end, we perform an average pooling. 
#(Note that view is PyTorch’s version of Numpy’s reshape)

class Mnist_CNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=3, stride=2, padding=1)
        self.conv2 = nn.Conv2d(16, 16, kernel_size=3, stride=2, padding=1)
        self.conv3 = nn.Conv2d(16, 10, kernel_size=3, stride=2, padding=1)

    def forward(self, xb):
        xb = xb.view(-1, 1, 28, 28)
        xb = F.relu(self.conv1(xb))
        xb = F.relu(self.conv2(xb))
        xb = F.relu(self.conv3(xb))
        xb = F.avg_pool2d(xb, 4)
        return xb.view(-1, xb.size(1))    

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    # #model = Mnist_Logistic()
    model = Mnist_CNN()
    return model, optim.SGD(model.parameters(), lr=lr)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#Add validation

#Shuffling (above) training data is important to prevent correlation 
#between batches and overfitting. On the other hand, the validation 
#loss will be identical whether we shuffle the validation set or not. 
#Since shuffling takes extra time, it makes no sense to shuffle the 
#validation data.

#We’ll use a batch size for the validation set that is twice as large 
#as that for the training set. This is because the validation set does 
#not need backpropagation and thus takes less memory (it doesn’t need 
#to store the gradients). We take advantage of this to use a larger 
#batch size and compute the loss more quickly

valid_ds = TensorDataset(x_valid, y_valid)

#Refactor using DataLoader

#PyTorch’s DataLoader is responsible for managing batches. You can 
#create a DataLoader from any Dataset. DataLoader makes it easier to 
#iterate over batches. Rather than using train_ds[i*bs : i*bs+bs], 
#the DataLoader gives us each minibatch automatically.

from torch.utils.data import DataLoader

def get_data(train_ds, valid_ds, bs):
    return(
        DataLoader(train_ds, batch_size=bs, shuffle=True),
        DataLoader(valid_ds, batch_size=bs * 2),
    )

train_dl, valid_dl = get_data(train_ds, valid_ds, bs)

#We will calculate and print validation loss at the end of each epoch.

#Note: we always call model.train() before training, and model.eval() 
#before inference, because these are used by layers such as 
#nn.BatchNorm2d and nn.Dropout to ensure appropriate behavior for 
#these different phases.)

#We’ll now do a little refactoring of our own. Since we go through a 
#similar process twice of calculating the loss for both the training 
#set and the validation set, let’s make that into its own function, 
#loss_batch, which computes the loss for one batch.

#We pass an optimizer in for the training set, and use it to perform 
#backprop. For the validation set, we don’t pass an optimizer, so the 
#method doesn’t perform backprop.

def loss_batch(model, loss_func, xb, yb, opt=None):
    loss = loss_func(model(xb), yb)
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.
    if opt is not None:
        loss.backward()
        opt.step()
        opt.zero_grad()
        
    return loss.item(), len(xb)

#We’ll wrap the training loop in a fit() function to run again later.

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

def fit(epochs, model, loss_func, opt, train_dl, valid_dl):
    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            #set_trace()
            loss_batch(model, loss_func, xb, yb, opt)
            
            # #pred = model(xb)
            # #loss = loss_func(pred, yb)
            # #loss.backward()
        # #for i in range((n - 1) // bs + 1):
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            # #Previously, we had to iterate through minibatches of x 
            # #and y vals separately. Now, we do these 2 steps together:
            # #xb,yb = train_ds[i*bs : i*bs + bs]
            # #pred = model(xb)
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    # #This will let us replace the code above:
        
        model.eval()
        with torch.no_grad():
            losses, nums = zip(
                *[loss_batch(model, loss_func, xb, yb) for xb, yb in valid_dl]    
            )
            # #valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)
        # #print(f"Epoch: {epoch}, valid_loss: {valid_loss / len(valid_dl)}")
        val_loss = np.sum(np.multiply(losses, nums)) / np.sum(nums)
        print(f"Epoch: {epoch}, val loss: {val_loss}")

fit(epochs, model, loss_func, opt, train_dl, valid_dl)
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial8.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 20:23:16 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.1 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")
pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

# #import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#Switch to CNN

#We are going to build a neural network with three convolutional 
#layers. Because none of the functions in the previous section 
#assume anything about the model form, we’ll be able to use them to 
#train a CNN without any modification.

#We will use PyTorch’s predefined Conv2d class as our convolutional 
#layer, defining a CNN with 3 convolutional layers. Each convolution 
#is followed by a ReLU. At the end, we perform an average pooling. 
#(Note that view is PyTorch’s version of Numpy’s reshape)

class Mnist_CNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=3, stride=2, padding=1)
        self.conv2 = nn.Conv2d(16, 16, kernel_size=3, stride=2, padding=1)
        self.conv3 = nn.Conv2d(16, 10, kernel_size=3, stride=2, padding=1)

    def forward(self, xb):
        xb = xb.view(-1, 1, 28, 28)
        xb = F.relu(self.conv1(xb))
        xb = F.relu(self.conv2(xb))
        xb = F.relu(self.conv3(xb))
        xb = F.avg_pool2d(xb, 4)
        return xb.view(-1, xb.size(1))    

#Using nn.Sequential

#torch.nn has another handy class we can use to simplify our code: 
#Sequential . A Sequential object runs each of the modules contained 
#within it, in a sequential manner. This is a simpler way of writing 
#our neural network.

#To take advantage of this, we need to be able to easily define a 
#custom layer from a given function. For instance, PyTorch doesn’t 
#have a view layer, and we need to create one for our network. Lambda 
#will create a layer that we can then use when defining a network 
#with Sequential.

class Lambda(nn.Module):
    def __init__(self, func):
        super().__init__()
        self.func = func
        
    def forward(self, x):
        return self.func(x)
    
def preprocess(x):
    return x.view(-1, 1, 28, 28)

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    # #model = Mnist_Logistic()
    # #model = Mnist_CNN()
    #The model created with Sequential is simple:
    model = nn.Sequential(
     Lambda(preprocess),
     nn.Conv2d(1, 16, kernel_size=3, stride=2,padding=1),
     nn.ReLU(),
     nn.Conv2d(16, 16, kernel_size=3, stride=2,padding=1),
     nn.ReLU(),
     nn.Conv2d(16, 10, kernel_size=3, stride=2,padding=1),
     nn.ReLU(),
     nn.AvgPool2d(4),
     Lambda(lambda x: x.view(x.size(0), -1)),
    )
    return model, optim.SGD(model.parameters(), lr=lr, momentum=0.9)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

xb = x_train[0:bs] # a mini-batch size
preds = model(xb)
preds[0], preds.shape
print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

yb = y_train[0:bs]
print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#Add validation

#Shuffling (above) training data is important to prevent correlation 
#between batches and overfitting. On the other hand, the validation 
#loss will be identical whether we shuffle the validation set or not. 
#Since shuffling takes extra time, it makes no sense to shuffle the 
#validation data.

#We’ll use a batch size for the validation set that is twice as large 
#as that for the training set. This is because the validation set does 
#not need backpropagation and thus takes less memory (it doesn’t need 
#to store the gradients). We take advantage of this to use a larger 
#batch size and compute the loss more quickly

valid_ds = TensorDataset(x_valid, y_valid)

#Refactor using DataLoader

#PyTorch’s DataLoader is responsible for managing batches. You can 
#create a DataLoader from any Dataset. DataLoader makes it easier to 
#iterate over batches. Rather than using train_ds[i*bs : i*bs+bs], 
#the DataLoader gives us each minibatch automatically.

from torch.utils.data import DataLoader

def get_data(train_ds, valid_ds, bs):
    return(
        DataLoader(train_ds, batch_size=bs, shuffle=True),
        DataLoader(valid_ds, batch_size=bs * 2),
    )

train_dl, valid_dl = get_data(train_ds, valid_ds, bs)

#We will calculate and print validation loss at the end of each epoch.

#Note: we always call model.train() before training, and model.eval() 
#before inference, because these are used by layers such as 
#nn.BatchNorm2d and nn.Dropout to ensure appropriate behavior for 
#these different phases.)

#We’ll now do a little refactoring of our own. Since we go through a 
#similar process twice of calculating the loss for both the training 
#set and the validation set, let’s make that into its own function, 
#loss_batch, which computes the loss for one batch.

#We pass an optimizer in for the training set, and use it to perform 
#backprop. For the validation set, we don’t pass an optimizer, so the 
#method doesn’t perform backprop.

def loss_batch(model, loss_func, xb, yb, opt=None):
    loss = loss_func(model(xb), yb)
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.
    if opt is not None:
        loss.backward()
        opt.step()
        opt.zero_grad()
        
    return loss.item(), len(xb)

#We’ll wrap the training loop in a fit() function to run again later.

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

def fit(epochs, model, loss_func, opt, train_dl, valid_dl):
    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            #set_trace()
            loss_batch(model, loss_func, xb, yb, opt)
            
            # #pred = model(xb)
            # #loss = loss_func(pred, yb)
            # #loss.backward()
        # #for i in range((n - 1) // bs + 1):
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            # #Previously, we had to iterate through minibatches of x 
            # #and y vals separately. Now, we do these 2 steps together:
            # #xb,yb = train_ds[i*bs : i*bs + bs]
            # #pred = model(xb)
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    # #This will let us replace the code above:
        
        model.eval()
        with torch.no_grad():
            losses, nums = zip(
                *[loss_batch(model, loss_func, xb, yb) for xb, yb in valid_dl]    
            )
            # #valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)
        # #print(f"Epoch: {epoch}, valid_loss: {valid_loss / len(valid_dl)}")
        val_loss = np.sum(np.multiply(losses, nums)) / np.sum(nums)
        print(f"Epoch: {epoch}, val loss: {val_loss}")

fit(epochs, model, loss_func, opt, train_dl, valid_dl)
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

#Let’s check the loss and accuracy and compare those to what we 
#got earlier. We expect that the loss will have decreased and 
#accuracy to have increased, and they have.

print(f"LOSS1: {loss_func(model(xb), yb)}")
print(f"ACCURACY1: {accuracy(model(xb), yb)}")
==> nn_tutorial9.py <==
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 21:11:14 2023

@author: leslietetteh
"""

#We will use the classic MNIST dataset, which consists of 
#black-and-white images of hand-drawn digits (between 0 and 9).

#We will use pathlib for dealing with paths (part of the Python 3 
#standard library), and will download the dataset using requests. 
#We will only import modules when we use them, so you can see 
#exactly what’s being used at each point.

lr = 0.1 # learning rate
epochs = 2 # how many epochs to train for

from pathlib import Path
import requests

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"

PATH.mkdir(parents=True, exist_ok=True)

URL = "https://github.com/pytorch/tutorials/raw/main/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists():
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    
#This dataset is in numpy array format, and has been stored using 
#pickle, a python-specific format for serializing data.    

import pickle
import gzip

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
    
#Each image is 28 x 28, and is being stored as a flattened row of 
#length 784 (=28x28). Let’s take a look at one; we need to reshape
#it to 2d first.

from matplotlib import pyplot
import numpy as np

pyplot.imshow(x_train[0].reshape((28,28)), cmap="gray")
pyplot.show()
print(x_train.shape)

#PyTorch uses torch.tensor, rather than numpy arrays, so we need 
#to convert our data.

import torch

dev = torch.device(
    "cuda") if torch.cuda.is_available() else torch.device("cpu")

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)    
)
n,c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())

# #Let’s first create a model using nothing but PyTorch tensor 
# #operations. We’re assuming you’re already familiar with the 
# #basics of neural networks. (If you’re not, you can learn them at 
# #course.fast.ai).
# #
# #PyTorch provides methods to create random or zero-filled tensors, 
# #which we will use to create our weights and bias for a simple 
# #linear model. These are just regular tensors, with one very 
# #special addition: we tell PyTorch that they require a gradient. 
# #This causes PyTorch to record all of the operations done on the 
# #tensor, so that it can calculate the gradient during back-propagation
# #
# #For the weights, we set requires_grad after the initialization, 
# #since we don’t want that step included in the gradient. (Note the 
# #trailing _ in PyTorch signifies that the operation is performed 
# #in-place.)
# #
# #NOTE: We are initializing the weights here with Xavier 
# #initialisation (by multiplying with 1/sqrt(n)).
# #
# #
# #weights = torch.randn(784, 10) / math.sqrt(784)
# #weights.requires_grad_()
# #bias = torch.zeros(10, requires_grad=True)
# #
# #Thanks to PyTorch’s ability to calculate gradients automatically, 
# #we can use any standard Python function (or callable object) as a 
# #model! So let’s just write a plain matrix multiplication and 
# #broadcasted addition to create a simple linear model. We also 
# #need an activation function, so we’ll write log_softmax and use 
# #it. Remember: although PyTorch provides lots of prewritten loss 
# #functions, activation functions, and so forth, you can easily 
# #write your own using plain python. PyTorch will even create fast 
# #GPU or vectorized CPU code for your function automatically.
# #
# #def log_softmax(x):
# #    return x - x.exp().sum(-1).log().unsqueeze(-1)
# #
# #def model(xb):
# #   return log_softmax(xb @ weights + bias)
# #
# #In the above, the @ stands for the matrix multiplication 
# #operation. We will call our function on one batch of data (in 
# #this case, 64 images). This is one forward pass. Note that our 
# #predictions won’t be any better than random at this stage, since 
# #we start with random weights.
# #
# #Let’s implement negative log-likelihood to use as the loss 
# #function (again, we can just use standard Python):
# #    
# #def nll(input, target):
# #    return -input[range(target.shape[0]), target].mean()
# #
# #loss_func = nll
# #
# #Using torch.nn.functional
# #
# #We will now refactor our code, so that it does the same thing as 
# #before, only we’ll start taking advantage of PyTorch’s nn classes 
# #to make it more concise and flexible. At each step from here, we 
# #should be making our code one or more of: shorter, more 
# #understandable, and/or more flexible.
# #
# #The first and easiest step is to make our code shorter by 
# #replacing our hand-written activation and loss functions with 
# #those from torch.nn.functional (which is generally imported into 
# #the namespace F by convention). This module contains all the 
# #functions in the torch.nn library (whereas other parts of the 
# #library contain classes). As well as a wide range of loss and 
# #activation functions, you’ll also find here some convenient 
# #functions for creating neural nets, such as pooling functions. 
# #(There are also functions for doing convolutions, linear layers, 
# #etc, but as we’ll see, these are usually better handled using 
# #other parts of the library.)
# #def model(xb):
# #    return xb @ weights + bias
# #

#Refactor using nn.Module

#Next up, we’ll use nn.Module and nn.Parameter, for a clearer and 
#more concise training loop. We subclass nn.Module (which itself is 
#a class and able to keep track of state). In this case, we want to 
#create a class that holds our weights, bias, and method for the 
#forward step. nn.Module has a number of attributes and methods 
#(such as .parameters() and .zero_grad()) which we will be using.


#Refactor using nn.Linear

#We continue to refactor our code. Instead of manually defining and 
#initializing self.weights and self.bias, and calculating 
#xb  @ self.weights + self.bias, we will instead use the Pytorch
#class nn.Linear for a linear layer, which does all that for us. 
#Pytorch has many types of predefined layers that can greatly 
#simplify our code, and often makes it faster too.

# #import math
from torch import nn

class Mnist_Logistic(nn.Module):
    def __init__(self):
        super().__init__()
# #        self.weights = nn.Parameter(torch.randn(784, 10) / math.sqrt(784))
# #        self.bias = nn.Parameter(torch.zeros(10))
        self.lin = nn.Linear(784, 10)
        
    def forward(self, xb):
# #        return xb @ self.weights + self.bias
        return self.lin(xb)

#NOTE:nn.Module (uppercase M) is a PyTorch specific concept, and is 
#a class we’ll be using a lot. nn.Module is not to be confused with 
#the Python concept of a (lowercase m) module, which is a file of 
#Python code that can be imported.

#Switch to CNN

#We are going to build a neural network with three convolutional 
#layers. Because none of the functions in the previous section 
#assume anything about the model form, we’ll be able to use them to 
#train a CNN without any modification.

#We will use PyTorch’s predefined Conv2d class as our convolutional 
#layer, defining a CNN with 3 convolutional layers. Each convolution 
#is followed by a ReLU. At the end, we perform an average pooling. 
#(Note that view is PyTorch’s version of Numpy’s reshape)

class Mnist_CNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=3, stride=2, padding=1)
        self.conv2 = nn.Conv2d(16, 16, kernel_size=3, stride=2, padding=1)
        self.conv3 = nn.Conv2d(16, 10, kernel_size=3, stride=2, padding=1)

    def forward(self, xb):
        xb = xb.view(-1, 1, 28, 28)
        xb = F.relu(self.conv1(xb))
        xb = F.relu(self.conv2(xb))
        xb = F.relu(self.conv3(xb))
        xb = F.avg_pool2d(xb, 4)
        return xb.view(-1, xb.size(1))    

#Using nn.Sequential

#torch.nn has another handy class we can use to simplify our code: 
#Sequential . A Sequential object runs each of the modules contained 
#within it, in a sequential manner. This is a simpler way of writing 
#our neural network.

#To take advantage of this, we need to be able to easily define a 
#custom layer from a given function. For instance, PyTorch doesn’t 
#have a view layer, and we need to create one for our network. Lambda 
#will create a layer that we can then use when defining a network 
#with Sequential.

class Lambda(nn.Module):
    def __init__(self, func):
        super().__init__()
        self.func = func
        
    def forward(self, x):
        return self.func(x)
    
def preprocess(x):
    return x.view(-1, 1, 28, 28)

#We’ll define a little function to create our model and optimizer so 
#we can reuse it in the future.

from torch import optim

def get_model():
    # #model = Mnist_Logistic()
    # #model = Mnist_CNN()
    #The model created with Sequential is simple:
    model = nn.Sequential(
        nn.Conv2d(1, 16, kernel_size=3, stride=2, padding=1),
        nn.ReLU(),
        nn.Conv2d(16, 16, kernel_size=3, stride=2, padding=1),
        nn.ReLU(),
        nn.Conv2d(16, 10, kernel_size=3, stride=2, padding=1),
        nn.ReLU(),
        nn.AdaptiveAvgPool2d(1),
        Lambda(lambda x: x.view(x.size(0), -1)),
    )
    model = model.to(dev)
    # #model = nn.Sequential(
    # # Lambda(preprocess),
    # # nn.Conv2d(1, 16, kernel_size=3, stride=2,padding=1),
    # # nn.ReLU(),
    # # nn.Conv2d(16, 16, kernel_size=3, stride=2,padding=1),
    # # nn.ReLU(),
    # # nn.Conv2d(16, 10, kernel_size=3, stride=2,padding=1),
    # # nn.ReLU(),
    # # nn.AvgPool2d(4),
    # # Lambda(lambda x: x.view(x.size(0), -1)),
    # #)
    return model, optim.SGD(model.parameters(), lr=lr, momentum=0.9)

model, opt = get_model()

#Since we’re now using an object instead of just using a function, we 
#first have to instantiate our model:

import torch.nn.functional as F

loss_func = F.cross_entropy

#If you’re using negative log likelihood loss and log softmax 
#activation, then Pytorch provides a single function 
#F.cross_entropy that combines the two. So we can even remove the 
#activation function from our model (above).

bs = 64 # batch size

#xb = x_train[0:bs] # a mini-batch size
#preds = model(xb)
#preds[0], preds.shape
#print(preds[0], preds.shape)

#As you see, the preds tensor contains not only the tensor values, 
#but also a gradient function. We’ll use this later to do backprop.

#Let’s check our loss with our random model, so we can see if we 
#improve after a backprop pass later.

#yb = y_train[0:bs]
#print(f"LOSS0: {loss_func(preds, yb)}")

#Let’s also implement a function to calculate the accuracy of our 
#model. For each prediction, if the index with the largest value 
#matches the target value, then the prediction was correct

def accuracy(out, yb):
    preds = torch.argmax(out, dim=1)
    return (preds == yb).float().mean()

#Let’s check the accuracy of our random model, so we can see if 
#our accuracy improves as our loss improves.

#print(f"ACCURACY0: {accuracy(preds, yb)}")

#We can now run a training loop. For each iteration, we will:

#select a mini-batch of data (of size bs)
#use the model to make predictions
#calculate the loss
#loss.backward() updates the gradients of the model, in this 
#case, weights and bias.

#We now use these gradients to update the weights and bias. We do 
#this within the torch.no_grad() context manager, because we do 
#not want these actions to be recorded for our next calculation 
#of the gradient. You can read more about how PyTorch’s Autograd 
#records operations here.

#We then set the gradients to zero, so that we are ready for the 
#next loop. Otherwise, our gradients would record a running tally 
#of all the operations that had happened (i.e. loss.backward() 
#adds the gradients to whatever is already stored, rather than 
#replacing them).

#Refactor using Dataset

#PyTorch has an abstract Dataset class. A Dataset can be anything that 
#has a __len__ function (called by Python’s standard len function) 
#and a __getitem__ function as a way of indexing into it.

#PyTorch’s TensorDataset is a Dataset wrapping tensors. By defining a 
#length and way of indexing, this also gives us a way to iterate, 
#index, and slice along the first dimension of a tensor. This will 
#make it easier to access both the independent and dependent variables 
#in the same line as we train.

from torch.utils.data import TensorDataset

#Both x_train and y_train can be combined in a single TensorDataset, 
#which will be easier to iterate over and slice.

train_ds = TensorDataset(x_train, y_train)

#Add validation

#Shuffling (above) training data is important to prevent correlation 
#between batches and overfitting. On the other hand, the validation 
#loss will be identical whether we shuffle the validation set or not. 
#Since shuffling takes extra time, it makes no sense to shuffle the 
#validation data.

#We’ll use a batch size for the validation set that is twice as large 
#as that for the training set. This is because the validation set does 
#not need backpropagation and thus takes less memory (it doesn’t need 
#to store the gradients). We take advantage of this to use a larger 
#batch size and compute the loss more quickly

valid_ds = TensorDataset(x_valid, y_valid)

#Refactor using DataLoader

#PyTorch’s DataLoader is responsible for managing batches. You can 
#create a DataLoader from any Dataset. DataLoader makes it easier to 
#iterate over batches. Rather than using train_ds[i*bs : i*bs+bs], 
#the DataLoader gives us each minibatch automatically.

from torch.utils.data import DataLoader

def get_data(train_ds, valid_ds, bs):
    return(
        DataLoader(train_ds, batch_size=bs, shuffle=True),
        DataLoader(valid_ds, batch_size=bs * 2),
    )

def preprocess(x, y):
    return x.view(-1, 1, 28, 28).to(dev), y.to(dev)

class WrappedDataLoader:
    def __init__(self, dl, func):
        self.dl = dl
        self.func = func

    def __len__(self):
        return len(self.dl)

    def __iter__(self):
        for b in self.dl:
            yield (self.func(*b))

train_dl, valid_dl = get_data(train_ds, valid_ds, bs)
train_dl = WrappedDataLoader(train_dl, preprocess)
valid_dl = WrappedDataLoader(valid_dl, preprocess)

#We will calculate and print validation loss at the end of each epoch.

#Note: we always call model.train() before training, and model.eval() 
#before inference, because these are used by layers such as 
#nn.BatchNorm2d and nn.Dropout to ensure appropriate behavior for 
#these different phases.)

#We’ll now do a little refactoring of our own. Since we go through a 
#similar process twice of calculating the loss for both the training 
#set and the validation set, let’s make that into its own function, 
#loss_batch, which computes the loss for one batch.

#We pass an optimizer in for the training set, and use it to perform 
#backprop. For the validation set, we don’t pass an optimizer, so the 
#method doesn’t perform backprop.

def loss_batch(model, loss_func, xb, yb, opt=None):
    loss = loss_func(model(xb), yb)
    
    #Refactor using torch.optim
    
    #Pytorch also has a package with various optimization algorithms,
    #torch.optim. We can use the step method from our optimizer to 
    #take a forward step, instead of manually updating each parameter.
    if opt is not None:
        loss.backward()
        opt.step()
        opt.zero_grad()
        
    return loss.item(), len(xb)

#We’ll wrap the training loop in a fit() function to run again later.

#TIP: You can use the standard python debugger to step through 
#PyTorch code, allowing you to check the various variable values 
#at each step. Uncomment set_trace() below to try it out

from IPython.core.debugger import set_trace

def fit(epochs, model, loss_func, opt, train_dl, valid_dl):
    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            #set_trace()
            loss_batch(model, loss_func, xb, yb, opt)
            
            # #pred = model(xb)
            # #loss = loss_func(pred, yb)
            # #loss.backward()
        # #for i in range((n - 1) // bs + 1):
            # #start_i = i * bs
            # #end_i = start_i + bs
            # #xb = x_train[start_i:end_i]
            # #yb = y_train[start_i:end_i]
            
            # #Previously, we had to iterate through minibatches of x 
            # #and y vals separately. Now, we do these 2 steps together:
            # #xb,yb = train_ds[i*bs : i*bs + bs]
            # #pred = model(xb)
    # #        with torch.no_grad():
    # #            weights -= weights.grad * lr
    # #            bias -= bias.grad * lr
    # #            weights.grad.zero_()
    # #            bias.grad.zero_()
    # #Previously for our training loop we had to update the values for 
    # #each parameter by name, and manually zero out the grads for each 
    # #parameter separately, (above)
    
    # #Now we can take advantage of model.parameters() and model.zero_grad() 
    # #(which are both defined by PyTorch for nn.Module) to make those steps 
    # #more concise and less prone to the error of forgetting some of our 
    # #parameters, particularly if we had a more complicated model:
    # #        with torch.no_grad():
    # #            for p in model.parameters():
    # #                p -= p.grad * lr
    # #            model.zero_grad()
    # #This will let us replace the code above:
        
        model.eval()
        with torch.no_grad():
            losses, nums = zip(
                *[loss_batch(model, loss_func, xb, yb) for xb, yb in valid_dl]    
            )
            # #valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)
        # #print(f"Epoch: {epoch}, valid_loss: {valid_loss / len(valid_dl)}")
        val_loss = np.sum(np.multiply(losses, nums)) / np.sum(nums)
        print(f"Epoch: {epoch}, val loss: {val_loss}")

fit(epochs, model, loss_func, opt, train_dl, valid_dl)
                
#That’s it: we’ve created and trained a minimal neural network 
#(in this case, a logistic regression, since we have no hidden 
#layers) entirely from scratch!

# #Let’s check the loss and accuracy and compare those to what we 
# #got earlier. We expect that the loss will have decreased and 
# #accuracy to have increased, and they have.

# #print(f"LOSS1: {loss_func(model(xb), yb)}")

==> 02_pytorch_binary_classifiation <==
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 24 15:04:11 2023

@author: leslietetteh
"""

#scikitlearn
import sklearn
from sklearn.datasets import make_circles

# Make 1000 samples
n_samples = 1000

# Create circles (from scikitlearn)
#https://scikit-learn.org/stable/datasets/loading_other_datasets.html
X, y = make_circles(n_samples, noise =0.03, random_state=42)

print(f"len X: len(X), len y: len(y)")
print(f"First 5 samples of X:\n {X[:5]}")
print(f"First 5 samples of y:\n {y[:5]}")

import pandas as pd
circles = pd.DataFrame({"X1": X[:, 0],
                        "X2": X[:, 1],
                        "label": y})
print(circles)

import matplotlib.pyplot as plt

plt.scatter(x=X[:, 0],
            y=X[:, 1],
            c=y,
            cmap=plt.cm.RdYlBu);
plt.show()

# Check input and output shapes
print(f"X: {X.shape}, y: {y.shape}")
#X = 1000 samples, 2 features, y = 1000 sample, 0 features

X_sample = X[0]
y_sample = y[0]

print(f"Values for one sample of X {X[0]} and same for y [{y[0]}]")

import torch

print(f"X type: {type(X)}, {X.dtype}")

#turn data into tensors, casts to torch.float32
X = torch.from_numpy(X).type(torch.float)
y = torch.from_numpy(y).type(torch.float)

print(f"X type: {type(X)}, {X.dtype}")

from sklearn.model_selection import train_test_split
#splits arrrays or matrices into random train/test subsets

X_train, X_test, y_train, y_test = train_test_split(X,
                                                    y,
                                                    test_size=0.2,
                                                    random_state=42) #20% data is test

print(f"train: {len(X_train)}, test: {len(X_test)}")

#2. Building a model
#We will:
    #1.Setup device agnostic code 
    #2.Construct a model (by subclassing 'nn.Module')
    #3.Define a loss function and optimizer
    #4.Create a training and test loop
    
from torch import nn

device = "cuda" if torch.cuda.is_available() else "cpu"

class CircleModelV0(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=5) #takes in 2 feature upscales to 5 features
        self.layer_2 = nn.Linear(in_features=5, out_features=1) #takes in 5 features, returns single feature (same shape as y)
        
    def forward(self, x):
        return self.layer_2(self.layer_1(x)) # x -> lay1 -> lay2 -> out
    
model_0a = CircleModelV0().to(device)

model_0b = nn.Sequential(
    nn.Linear(in_features=2, out_features=5),
    nn.Linear(in_features=5, out_features=1)
).to(device)

#model 0a and 0b are identical in structure
#print("STATE DICTIONARY:")
#print(model_0a.state_dict())
#print("STATE DICTIONARY:")
#print(model_0b.state_dict()) 

with torch.inference_mode():
    untrained_preds = model_0b(X_test.to(device))
print(f"Length of predictions: {len(untrained_preds)}, Shape: {untrained_preds.shape}")
print(f"Length of test labels: {len(y_test)}, Shape: {y_test.shape}") 
print(f"\nFirst 10 predictions:\n{untrained_preds[:10]}")
print(f"\nFirst 10 labels:\n{y_test[:10]}")

#In terms of picking a loss function for regression, might use MAE or MSE
#(mean absolute/squared error), however for a classification problem CE
#Cross Entropy would be appropriate. For binary classification, binary
#cross-entropy (BCE) would be ideal as a loss function

loss_fn = nn.BCEWithLogitsLoss() # sigmoid aactivation function built-in
#nn.BCELoss() requires inputs to go through the sigmoid activation 
#function prior to use, BCEWithLogitsLoss is mre numerically stable

#In context of deep learning the logits layer means the layer that feeds 
#into softmax (or other such normalization). The output of the softmax are 
#the probabilities for the classification task and its input is logits 
#layer. The logits layer typically produces values from -infinity to 
#+infinity and the softmax layer transforms it to values from 0 to 1.

optimizer = torch.optim.SGD(params=model_0b.parameters(), lr=0.1)

def accuracy_fn(y_true, y_pred):
    correct = torch.eq(y_true, y_pred).sum().item()
    acc = (correct/len(y_pred)) * 100
    return acc

#Going from raw logits -> prediction probabilities -> prediction labels

#Our model outputs are going to be raw logits. We can convert these logits
#into prediction probabilities by passing them to an activation function
#e.g. sigmoid for binary classification, softmax for multiclass classification

#We can convert the model's prediction probabilities to prediction labels
#by either rounding them or taking the 'argmax()' (index of max)

torch.manual_seed(42)
torch.cuda.manual_seed(42)

epochs = 100

X_train, y_train = X_train.to(device), y_train.to(device)
X_test, y_test = X_test.to(device), y_test.to(device)

#Build training and evaluation loop
for epoch in range(epochs):
    model_0b.train() # sets training mode
    
    #1. Forward pass
    y_logits = model_0b(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    # 2. Calculate loss - BCEWithLogitsLoss expects raw logits as input
    loss = loss_fn(y_logits, y_train) 
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)
    
    #3. Optimizer zero grad
    optimizer.zero_grad()
    
    #4. Backpropagation
    loss.backward()
    
    #5. Optimizer step (Update parameter, gradient descent)
    optimizer.step()
    
    #Testing
    model_0b.eval()
    with torch.inference_mode():
        #1. Forward pass
        test_logits = model_0b(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        
        #2. Calculate test loss / acc
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_true=y_test, y_pred=test_pred)
        
    #printout
    if epoch % 10 == 0:
        print(f"Epoch: {epoch} | Loss: {loss:.5f}, Acc: {acc:.2f}%")
        print(f"Epoch: {epoch} | Test Loss: {test_loss:.5f}, Test Acc: {test_acc:.2f}%")
        
import requests
from pathlib import Path

#Download helper function from Learn Pytorch repo (if not present)
if Path("helper_functions.py").is_file():
    print("Skipping download")
else:
    print("Downloading helper_functions.py")
    request = requests.get("https://raw.githubusercontent.com/mrdbourke/pytorch-deep-learning/main/helper_functions.py")
    with open("helper_functions.py", "wb") as f:
        f.write(request.content)

from helper_functions import plot_predictions, plot_decision_boundary 

plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1)
plt.title("Train")
plot_decision_boundary(model_0b, X_train, y_train)
plt.subplot(1, 2, 2)
plt.title("Test")
plot_decision_boundary(model_0b, X_test, y_test)
plt.show()  

#Failed attempt to improve model
class CircleModelV1(nn.Module):
    def __init__(self):
        super().__init__()
        #Increase number of hidden units, & number of layers
        self.layer_1 = nn.Linear(in_features=2, out_features=10)
        self.layer_2 = nn.Linear(in_features=10, out_features=10)
        self.layer_3 = nn.Linear(in_features=10, out_features=1)
        #bad way to improve network should alter hyperparameters oone at a time
        
    def forward(self, x):
        z = self.layer_1(x)
        z = self.layer_2(z)
        z = self.layer_3(z)
        #Above code is inefficient, below leverages speedups
        return self.layer_3(self.layer_2(self.layer_1(x)))
    
model_1 = CircleModelV1().to(device)
print(model_1)

loss_fn1 = nn.BCEWithLogitsLoss()

optimizer = torch.optim.SGD(params=model_1.parameters(), lr=0.1)
torch.manual_seed(42)
torch.cuda.manual_seed(42)

#train for longer
epochs = 1000

X_train, y_train = X_train.to(device), y_train.to(device)
X_test, y_test = X_test.to(device), y_test.to(device)

for epoch in range(epochs):
    model_1.train() # place in training mode
    #Fwd pass
    y_logits = model_1(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    #Calculate loss/acc
    loss = loss_fn(y_logits, y_train)
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)
    
    #Optimizer zero grad
    optimizer.zero_grad()
    
    #Loss backward (backprop)
    loss.backward()
    
    #Optimizer step (Gradient descent)
    optimizer.step()

    #Testing
    model_1.eval()
    with torch.inference_mode():
        #Fwd pass
        test_logits = model_1(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        #Calculate loss/acc
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_true=y_test, y_pred=test_pred)
        
        if epoch % 100 == 0:
            print(f"Epoch: {epoch} | Loss: {loss:.5f} | Acc: {acc:.2f}%")
            print(f"Test Loss: {test_loss:.5f} | Test Acc: {test_acc:.2f}%")

#Plot the decision boundary
plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1)
plt.title("Train")
plot_decision_boundary(model_1, X_train, y_train)
plt.subplot(1, 2, 2)
plt.title("Test")
plot_decision_boundary(model_1, X_test, y_test)
plt.show()  
#As model is linear, cannot resolve non-linear relationship

#Building a model with non-linear activation functions
class CircleModelV2(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=10)
        self.layer_2 = nn.Linear(in_features=10, out_features=10)
        self.layer_3 = nn.Linear(in_features=10, out_features=1)
        self.relu = nn.ReLU()
        
    def forward(self, x):
        # Where should we put our non-linear activation functions
        return self.layer_3(self.relu(self.layer_2(self.relu(self.layer_1(x)))))
        
model_2 = CircleModelV2().to(device)
print(model_2)

loss_fn = nn.BCEWithLogitsLoss()
optimizer = torch.optim.SGD(model_2.parameters(), lr=0.02)
torch.manual_seed(42)
torch.cuda.manual_seed(42)

epochs = 8000

for epoch in range(epochs):
    #Training
    model_2.train()
    
    #Forward pass
    y_logits = model_2(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    #Calculate loss
    loss = loss_fn(y_logits, y_train)
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)

    #Optimizer zero grad
    optimizer.zero_grad()
    
    #Loss backward
    loss.backward()
    
    #SGD
    optimizer.step()
    
    #Test
    model_2.eval()
    
    with torch.inference_mode():
        test_logits = model_2(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_test, test_pred)
        
        if epoch % 100 == 0:
            print(f"Epoch: {epoch} | Loss: {loss:.5f} | Accuracy: {acc:.2f}%")
            print(f"Test Loss: {test_loss:.5f} | Test Accuracy: {test_acc:.2f}")
            
#Make predictions
model_2.eval()
with torch.inference_mode():
    y_preds = torch.round(torch.sigmoid(model_2(X_test))).squeeze()
print(y_preds[:10])
print(y_test[:10])

#Plot the decision boundary
plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1) #number of rows, no. of columns, index
plt.title("Train")
plot_decision_boundary(model_2, X_train, y_train)
plt.subplot(1, 2, 2) #number of rows, no. of columns, index
plt.title("Test")
plot_decision_boundary(model_2, X_test, y_test)
plt.show()  
#As model is linear, cannot resolve non-linear relationship

==> helper_functions <==
"""
A series of helper functions used throughout the course.

If a function gets defined once and could be used over and over, it'll go in here.
"""
import torch
import matplotlib.pyplot as plt
import numpy as np

from torch import nn

import os
import zipfile

from pathlib import Path

import requests

# Walk through an image classification directory and find out how many files (images)
# are in each subdirectory.
import os

def walk_through_dir(dir_path):
    """
    Walks through dir_path returning its contents.
    Args:
    dir_path (str): target directory

    Returns:
    A print out of:
      number of subdiretories in dir_path
      number of images (files) in each subdirectory
      name of each subdirectory
    """
    for dirpath, dirnames, filenames in os.walk(dir_path):
        print(f"There are {len(dirnames)} directories and {len(filenames)} images in '{dirpath}'.")

def plot_decision_boundary(model: torch.nn.Module, X: torch.Tensor, y: torch.Tensor):
    """Plots decision boundaries of model predicting on X in comparison to y.

    Source - https://madewithml.com/courses/foundations/neural-networks/ (with modifications)
    """
    # Put everything to CPU (works better with NumPy + Matplotlib)
    model.to("cpu")
    X, y = X.to("cpu"), y.to("cpu")

    # Setup prediction boundaries and grid
    x_min, x_max = X[:, 0].min() - 0.1, X[:, 0].max() + 0.1
    y_min, y_max = X[:, 1].min() - 0.1, X[:, 1].max() + 0.1
    xx, yy = np.meshgrid(np.linspace(x_min, x_max, 101), np.linspace(y_min, y_max, 101))

    # Make features
    X_to_pred_on = torch.from_numpy(np.column_stack((xx.ravel(), yy.ravel()))).float()

    # Make predictions
    model.eval()
    with torch.inference_mode():
        y_logits = model(X_to_pred_on)

    # Test for multi-class or binary and adjust logits to prediction labels
    if len(torch.unique(y)) > 2:
        y_pred = torch.softmax(y_logits, dim=1).argmax(dim=1)  # mutli-class
    else:
        y_pred = torch.round(torch.sigmoid(y_logits))  # binary

    # Reshape preds and plot
    y_pred = y_pred.reshape(xx.shape).detach().numpy()
    plt.contourf(xx, yy, y_pred, cmap=plt.cm.RdYlBu, alpha=0.7)
    plt.scatter(X[:, 0], X[:, 1], c=y, s=40, cmap=plt.cm.RdYlBu)
    plt.xlim(xx.min(), xx.max())
    plt.ylim(yy.min(), yy.max())


# Plot linear data or training and test and predictions (optional)
def plot_predictions(
    train_data, train_labels, test_data, test_labels, predictions=None
):
    """
  Plots linear training data and test data and compares predictions.
  """
    plt.figure(figsize=(10, 7))

    # Plot training data in blue
    plt.scatter(train_data, train_labels, c="b", s=4, label="Training data")

    # Plot test data in green
    plt.scatter(test_data, test_labels, c="g", s=4, label="Testing data")

    if predictions is not None:
        # Plot the predictions in red (predictions were made on the test data)
        plt.scatter(test_data, predictions, c="r", s=4, label="Predictions")

    # Show the legend
    plt.legend(prop={"size": 14})


# Calculate accuracy (a classification metric)
def accuracy_fn(y_true, y_pred):
    """Calculates accuracy between truth labels and predictions.

    Args:
        y_true (torch.Tensor): Truth labels for predictions.
        y_pred (torch.Tensor): Predictions to be compared to predictions.

    Returns:
        [torch.float]: Accuracy value between y_true and y_pred, e.g. 78.45
    """
    correct = torch.eq(y_true, y_pred).sum().item()
    acc = (correct / len(y_pred)) * 100
    return acc


def print_train_time(start, end, device=None):
    """Prints difference between start and end time.

    Args:
        start (float): Start time of computation (preferred in timeit format). 
        end (float): End time of computation.
        device ([type], optional): Device that compute is running on. Defaults to None.

    Returns:
        float: time between start and end in seconds (higher is longer).
    """
    total_time = end - start
    print(f"\nTrain time on {device}: {total_time:.3f} seconds")
    return total_time


# Plot loss curves of a model
def plot_loss_curves(results):
    """Plots training curves of a results dictionary.

    Args:
        results (dict): dictionary containing list of values, e.g.
            {"train_loss": [...],
             "train_acc": [...],
             "test_loss": [...],
             "test_acc": [...]}
    """
    loss = results["train_loss"]
    test_loss = results["test_loss"]

    accuracy = results["train_acc"]
    test_accuracy = results["test_acc"]

    epochs = range(len(results["train_loss"]))

    plt.figure(figsize=(15, 7))

    # Plot loss
    plt.subplot(1, 2, 1)
    plt.plot(epochs, loss, label="train_loss")
    plt.plot(epochs, test_loss, label="test_loss")
    plt.title("Loss")
    plt.xlabel("Epochs")
    plt.legend()

    # Plot accuracy
    plt.subplot(1, 2, 2)
    plt.plot(epochs, accuracy, label="train_accuracy")
    plt.plot(epochs, test_accuracy, label="test_accuracy")
    plt.title("Accuracy")
    plt.xlabel("Epochs")
    plt.legend()


# Pred and plot image function from notebook 04
# See creation: https://www.learnpytorch.io/04_pytorch_custom_datasets/#113-putting-custom-image-prediction-together-building-a-function
from typing import List
import torchvision


def pred_and_plot_image(
    model: torch.nn.Module,
    image_path: str,
    class_names: List[str] = None,
    transform=None,
    device: torch.device = "cuda" if torch.cuda.is_available() else "cpu",
):
    """Makes a prediction on a target image with a trained model and plots the image.

    Args:
        model (torch.nn.Module): trained PyTorch image classification model.
        image_path (str): filepath to target image.
        class_names (List[str], optional): different class names for target image. Defaults to None.
        transform (_type_, optional): transform of target image. Defaults to None.
        device (torch.device, optional): target device to compute on. Defaults to "cuda" if torch.cuda.is_available() else "cpu".
    
    Returns:
        Matplotlib plot of target image and model prediction as title.

    Example usage:
        pred_and_plot_image(model=model,
                            image="some_image.jpeg",
                            class_names=["class_1", "class_2", "class_3"],
                            transform=torchvision.transforms.ToTensor(),
                            device=device)
    """

    # 1. Load in image and convert the tensor values to float32
    target_image = torchvision.io.read_image(str(image_path)).type(torch.float32)

    # 2. Divide the image pixel values by 255 to get them between [0, 1]
    target_image = target_image / 255.0

    # 3. Transform if necessary
    if transform:
        target_image = transform(target_image)

    # 4. Make sure the model is on the target device
    model.to(device)

    # 5. Turn on model evaluation mode and inference mode
    model.eval()
    with torch.inference_mode():
        # Add an extra dimension to the image
        target_image = target_image.unsqueeze(dim=0)

        # Make a prediction on image with an extra dimension and send it to the target device
        target_image_pred = model(target_image.to(device))

    # 6. Convert logits -> prediction probabilities (using torch.softmax() for multi-class classification)
    target_image_pred_probs = torch.softmax(target_image_pred, dim=1)

    # 7. Convert prediction probabilities -> prediction labels
    target_image_pred_label = torch.argmax(target_image_pred_probs, dim=1)

    # 8. Plot the image alongside the prediction and prediction probability
    plt.imshow(
        target_image.squeeze().permute(1, 2, 0)
    )  # make sure it's the right size for matplotlib
    if class_names:
        title = f"Pred: {class_names[target_image_pred_label.cpu()]} | Prob: {target_image_pred_probs.max().cpu():.3f}"
    else:
        title = f"Pred: {target_image_pred_label} | Prob: {target_image_pred_probs.max().cpu():.3f}"
    plt.title(title)
    plt.axis(False)

def set_seeds(seed: int=42):
    """Sets random sets for torch operations.

    Args:
        seed (int, optional): Random seed to set. Defaults to 42.
    """
    # Set the seed for general torch operations
    torch.manual_seed(seed)
    # Set the seed for CUDA torch operations (ones that happen on the GPU)
    torch.cuda.manual_seed(seed)

def download_data(source: str, 
                  destination: str,
                  remove_source: bool = True) -> Path:
    """Downloads a zipped dataset from source and unzips to destination.

    Args:
        source (str): A link to a zipped file containing data.
        destination (str): A target directory to unzip data to.
        remove_source (bool): Whether to remove the source after downloading and extracting.
    
    Returns:
        pathlib.Path to downloaded data.
    
    Example usage:
        download_data(source="https://github.com/mrdbourke/pytorch-deep-learning/raw/main/data/pizza_steak_sushi.zip",
                      destination="pizza_steak_sushi")
    """
    # Setup path to data folder
    data_path = Path("data/")
    image_path = data_path / destination

    # If the image folder doesn't exist, download it and prepare it... 
    if image_path.is_dir():
        print(f"[INFO] {image_path} directory exists, skipping download.")
    else:
        print(f"[INFO] Did not find {image_path} directory, creating one...")
        image_path.mkdir(parents=True, exist_ok=True)
        
        # Download pizza, steak, sushi data
        target_file = Path(source).name
        with open(data_path / target_file, "wb") as f:
            request = requests.get(source)
            print(f"[INFO] Downloading {target_file} from {source}...")
            f.write(request.content)

        # Unzip pizza, steak, sushi data
        with zipfile.ZipFile(data_path / target_file, "r") as zip_ref:
            print(f"[INFO] Unzipping {target_file} data...") 
            zip_ref.extractall(image_path)

        # Remove .zip file
        if remove_source:
            os.remove(data_path / target_file)
    
    return image_path

==> 02_non-linear_activation_functions <==
import torch
import matplotlib.pyplot as plt
import torch.nn as nn

A = torch.arange(-10, 10, 1, dtype=torch.float32) 
#if initialized with int step size, min max, will default to int64

plt.plot(A)
plt.show()
plt.plot(torch.relu(A))
plt.show()

def relu(x: torch.Tensor) -> torch.Tensor:
    return torch.maximum(torch.tensor(0), x)

plt.plot(relu(A))
plt.show()

def sigmoid(x):
    return 1 / (1 + torch.exp(-x))

plt.plot(torch.sigmoid(A))
plt.show()
plt.plot(sigmoid(A))
plt.show()

# -*- coding: utf-8 -*-
"""
Created on Tue Oct 24 15:04:11 2023

@author: leslietetteh
"""

#scikitlearn
import sklearn
from sklearn.datasets import make_circles

# Make 1000 samples
n_samples = 1000

# Create circles (from scikitlearn)
#https://scikit-learn.org/stable/datasets/loading_other_datasets.html
X, y = make_circles(n_samples, noise =0.03, random_state=42)

print(f"len X: len(X), len y: len(y)")
print(f"First 5 samples of X:\n {X[:5]}")
print(f"First 5 samples of y:\n {y[:5]}")

import pandas as pd
circles = pd.DataFrame({"X1": X[:, 0],
                        "X2": X[:, 1],
                        "label": y})
print(circles)

import matplotlib.pyplot as plt

plt.scatter(x=X[:, 0],
            y=X[:, 1],
            c=y,
            cmap=plt.cm.RdYlBu);
plt.show()

# Check input and output shapes
print(f"X: {X.shape}, y: {y.shape}")
#X = 1000 samples, 2 features, y = 1000 sample, 0 features

X_sample = X[0]
y_sample = y[0]

print(f"Values for one sample of X {X[0]} and same for y [{y[0]}]")

import torch

print(f"X type: {type(X)}, {X.dtype}")

#turn data into tensors, casts to torch.float32
X = torch.from_numpy(X).type(torch.float)
y = torch.from_numpy(y).type(torch.float)

print(f"X type: {type(X)}, {X.dtype}")

from sklearn.model_selection import train_test_split
#splits arrrays or matrices into random train/test subsets

X_train, X_test, y_train, y_test = train_test_split(X,
                                                    y,
                                                    test_size=0.2,
                                                    random_state=42) #20% data is test

print(f"train: {len(X_train)}, test: {len(X_test)}")

#2. Building a model
#We will:
    #1.Setup device agnostic code 
    #2.Construct a model (by subclassing 'nn.Module')
    #3.Define a loss function and optimizer
    #4.Create a training and test loop
    
from torch import nn

device = "cuda" if torch.cuda.is_available() else "cpu"

class CircleModelV0(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=5) #takes in 2 feature upscales to 5 features
        self.layer_2 = nn.Linear(in_features=5, out_features=1) #takes in 5 features, returns single feature (same shape as y)
        
    def forward(self, x):
        return self.layer_2(self.layer_1(x)) # x -> lay1 -> lay2 -> out
    
model_0a = CircleModelV0().to(device)

model_0b = nn.Sequential(
    nn.Linear(in_features=2, out_features=5),
    nn.Linear(in_features=5, out_features=1)
).to(device)

#model 0a and 0b are identical in structure
#print("STATE DICTIONARY:")
#print(model_0a.state_dict())
#print("STATE DICTIONARY:")
#print(model_0b.state_dict()) 

with torch.inference_mode():
    untrained_preds = model_0b(X_test.to(device))
print(f"Length of predictions: {len(untrained_preds)}, Shape: {untrained_preds.shape}")
print(f"Length of test labels: {len(y_test)}, Shape: {y_test.shape}") 
print(f"\nFirst 10 predictions:\n{untrained_preds[:10]}")
print(f"\nFirst 10 labels:\n{y_test[:10]}")

#In terms of picking a loss function for regression, might use MAE or MSE
#(mean absolute/squared error), however for a classification problem CE
#Cross Entropy would be appropriate. For binary classification, binary
#cross-entropy (BCE) would be ideal as a loss function

loss_fn = nn.BCEWithLogitsLoss() # sigmoid aactivation function built-in
#nn.BCELoss() requires inputs to go through the sigmoid activation 
#function prior to use, BCEWithLogitsLoss is mre numerically stable

#In context of deep learning the logits layer means the layer that feeds 
#into softmax (or other such normalization). The output of the softmax are 
#the probabilities for the classification task and its input is logits 
#layer. The logits layer typically produces values from -infinity to 
#+infinity and the softmax layer transforms it to values from 0 to 1.

optimizer = torch.optim.SGD(params=model_0b.parameters(), lr=0.1)

def accuracy_fn(y_true, y_pred):
    correct = torch.eq(y_true, y_pred).sum().item()
    acc = (correct/len(y_pred)) * 100
    return acc

#Going from raw logits -> prediction probabilities -> prediction labels

#Our model outputs are going to be raw logits. We can convert these logits
#into prediction probabilities by passing them to an activation function
#e.g. sigmoid for binary classification, softmax for multiclass classification

#We can convert the model's prediction probabilities to prediction labels
#by either rounding them or taking the 'argmax()' (index of max)

torch.manual_seed(42)
torch.cuda.manual_seed(42)

epochs = 100

X_train, y_train = X_train.to(device), y_train.to(device)
X_test, y_test = X_test.to(device), y_test.to(device)

#Build training and evaluation loop
for epoch in range(epochs):
    model_0b.train() # sets training mode
    
    #1. Forward pass
    y_logits = model_0b(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    # 2. Calculate loss - BCEWithLogitsLoss expects raw logits as input
    loss = loss_fn(y_logits, y_train) 
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)
    
    #3. Optimizer zero grad
    optimizer.zero_grad()
    
    #4. Backpropagation
    loss.backward()
    
    #5. Optimizer step (Update parameter, gradient descent)
    optimizer.step()
    
    #Testing
    model_0b.eval()
    with torch.inference_mode():
        #1. Forward pass
        test_logits = model_0b(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        
        #2. Calculate test loss / acc
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_true=y_test, y_pred=test_pred)
        
    #printout
    if epoch % 10 == 0:
        print(f"Epoch: {epoch} | Loss: {loss:.5f}, Acc: {acc:.2f}%")
        print(f"Epoch: {epoch} | Test Loss: {test_loss:.5f}, Test Acc: {test_acc:.2f}%")
        
import requests
from pathlib import Path

#Download helper function from Learn Pytorch repo (if not present)
if Path("helper_functions.py").is_file():
    print("Skipping download")
else:
    print("Downloading helper_functions.py")
    request = requests.get("https://raw.githubusercontent.com/mrdbourke/pytorch-deep-learning/main/helper_functions.py")
    with open("helper_functions.py", "wb") as f:
        f.write(request.content)

from helper_functions import plot_predictions, plot_decision_boundary 

plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1)
plt.title("Train")
plot_decision_boundary(model_0b, X_train, y_train)
plt.subplot(1, 2, 2)
plt.title("Test")
plot_decision_boundary(model_0b, X_test, y_test)
plt.show()  

#Failed attempt to improve model
class CircleModelV1(nn.Module):
    def __init__(self):
        super().__init__()
        #Increase number of hidden units, & number of layers
        self.layer_1 = nn.Linear(in_features=2, out_features=10)
        self.layer_2 = nn.Linear(in_features=10, out_features=10)
        self.layer_3 = nn.Linear(in_features=10, out_features=1)
        #bad way to improve network should alter hyperparameters oone at a time
        
    def forward(self, x):
        z = self.layer_1(x)
        z = self.layer_2(z)
        z = self.layer_3(z)
        #Above code is inefficient, below leverages speedups
        return self.layer_3(self.layer_2(self.layer_1(x)))
    
model_1 = CircleModelV1().to(device)
print(model_1)

loss_fn1 = nn.BCEWithLogitsLoss()

optimizer = torch.optim.SGD(params=model_1.parameters(), lr=0.1)
torch.manual_seed(42)
torch.cuda.manual_seed(42)

#train for longer
epochs = 1000

X_train, y_train = X_train.to(device), y_train.to(device)
X_test, y_test = X_test.to(device), y_test.to(device)

for epoch in range(epochs):
    model_1.train() # place in training mode
    #Fwd pass
    y_logits = model_1(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    #Calculate loss/acc
    loss = loss_fn(y_logits, y_train)
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)
    
    #Optimizer zero grad
    optimizer.zero_grad()
    
    #Loss backward (backprop)
    loss.backward()
    
    #Optimizer step (Gradient descent)
    optimizer.step()

    #Testing
    model_1.eval()
    with torch.inference_mode():
        #Fwd pass
        test_logits = model_1(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        #Calculate loss/acc
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_true=y_test, y_pred=test_pred)
        
        if epoch % 100 == 0:
            print(f"Epoch: {epoch} | Loss: {loss:.5f} | Acc: {acc:.2f}%")
            print(f"Test Loss: {test_loss:.5f} | Test Acc: {test_acc:.2f}%")

#Plot the decision boundary
plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1)
plt.title("Train")
plot_decision_boundary(model_1, X_train, y_train)
plt.subplot(1, 2, 2)
plt.title("Test")
plot_decision_boundary(model_1, X_test, y_test)
plt.show()  
#As model is linear, cannot resolve non-linear relationship

#Building a model with non-linear activation functions
class CircleModelV2(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=10)
        self.layer_2 = nn.Linear(in_features=10, out_features=10)
        self.layer_3 = nn.Linear(in_features=10, out_features=1)
        self.relu = nn.ReLU()
        
    def forward(self, x):
        # Where should we put our non-linear activation functions
        return self.layer_3(self.relu(self.layer_2(self.relu(self.layer_1(x)))))
        
model_2 = CircleModelV2().to(device)
print(model_2)

loss_fn = nn.BCEWithLogitsLoss()
optimizer = torch.optim.SGD(model_2.parameters(), lr=0.02)
torch.manual_seed(42)
torch.cuda.manual_seed(42)

epochs = 8000

for epoch in range(epochs):
    #Training
    model_2.train()
    
    #Forward pass
    y_logits = model_2(X_train).squeeze()
    y_pred = torch.round(torch.sigmoid(y_logits))
    
    #Calculate loss
    loss = loss_fn(y_logits, y_train)
    acc = accuracy_fn(y_true=y_train, y_pred=y_pred)

    #Optimizer zero grad
    optimizer.zero_grad()
    
    #Loss backward
    loss.backward()
    
    #SGD
    optimizer.step()
    
    #Test
    model_2.eval()
    
    with torch.inference_mode():
        test_logits = model_2(X_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits))
        
        test_loss = loss_fn(test_logits, y_test)
        test_acc = accuracy_fn(y_test, test_pred)
        
        if epoch % 100 == 0:
            print(f"Epoch: {epoch} | Loss: {loss:.5f} | Accuracy: {acc:.2f}%")
            print(f"Test Loss: {test_loss:.5f} | Test Accuracy: {test_acc:.2f}")
            
#Make predictions
model_2.eval()
with torch.inference_mode():
    y_preds = torch.round(torch.sigmoid(model_2(X_test))).squeeze()
print(y_preds[:10])
print(y_test[:10])

#Plot the decision boundary
plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1) #number of rows, no. of columns, index
plt.title("Train")
plot_decision_boundary(model_2, X_train, y_train)
plt.subplot(1, 2, 2) #number of rows, no. of columns, index
plt.title("Test")
plot_decision_boundary(model_2, X_test, y_test)
plt.show()  
#As model is linear, cannot resolve non-linear relationship

==>02_pytorch_multiclass_classification<==
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 26 18:52:41 2023

@author: leslietetteh
"""

import torch
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
import torch.nn as nn


#Set hyperparameters for data creation'
NUM_CLASSES = 4
NUM_FEATURES = 2
RANDOM_SEED = 42

# Create multiclass data
X_blob, y_blob = make_blobs(n_samples=1000,
                            n_features=NUM_FEATURES,
                            centers=NUM_CLASSES,
                            cluster_std=1.5, #std-deviation
                            random_state=RANDOM_SEED)

# Turn data into tensors
X_blob = torch.from_numpy(X_blob).type(torch.float)
y_blob = torch.from_numpy(y_blob).type(torch.int64)

#Split into train/test
X_blob_train, X_blob_test, y_blob_train, y_blob_test = train_test_split(X_blob,
                                                                        y_blob,
                                                                        test_size=0.2,
                                                                        random_state=RANDOM_SEED)

#Plot data
plt.figure(figsize=(10,7))
plt.scatter(X_blob[:, 0], X_blob[:, 1], c=y_blob, cmap=plt.cm.RdYlBu)
plt.show()

#create device agnostic code

device = "cuda" if torch.cuda.is_available() else "cpu"

X_blob_train = X_blob_train.to(device) 
X_blob_test = X_blob_test.to(device) 
y_blob_train = y_blob_train.to(device) 
y_blob_test = y_blob_test.to(device)

#Build multi-class classification model
class BlobModel(nn.Module):
    def __init__(self, input_features, output_features, hidden_units=8):
        #python docstring below (see google)
        """Initializes multi-class classification model
        
        Args:
            input_features (int): Number of input features to the model
            output_features (int): Number of output features (number of output classes)
            hidden_units (int): Number of hidden units between layers, default 8
            
        Returns:
            
        Example:
        """
        super().__init__()
        self.linear_layer_stack = nn.Sequential(
            nn.Linear(in_features=input_features, out_features=hidden_units),
            #nn.ReLU(),
            nn.Linear(in_features=hidden_units, out_features=hidden_units),
            #nn.ReLU(),
            nn.Linear(in_features=hidden_units, out_features=output_features),
        )
        
    def forward(self, x):
        return self.linear_layer_stack(x)
   
print(f"X_blob_train: {X_blob_train.shape}")
print(f"y_blob_train: {y_blob_train.shape}")
print(f"y_blob_train: {y_blob_train[:5]}")
print(f"torch.unique(y_blob_train): {torch.unique(y_blob_train)}")

model_3 = BlobModel(input_features=2, output_features=4).to(device)
print(model_3)

#accuracy function
def accuracy_fn(y_true, y_pred):
    correct = torch.eq(y_true, y_pred).sum().item()
    acc = (correct/len(y_pred)) * 100
    return acc

#create loss fn for multi-class classification
loss_fn = nn.CrossEntropyLoss()

optimizer = torch.optim.SGD(params=model_3.parameters(), lr=0.1)

model_3.eval()
with torch.inference_mode():
    y_logits = model_3(X_blob_test)
    
print(y_logits[:10]) # raw logits, need to convert    
# raw logits -> prediction probabilities -> prediction labels

y_pred_probs = torch.softmax(y_logits, dim=1)
print(y_pred_probs[:5]) #prediction probabilities
y_preds = torch.argmax(y_pred_probs, dim=1)
print(y_preds) # prediction labels

torch.manual_seed(RANDOM_SEED)
torch.cuda.manual_seed(RANDOM_SEED)

# Set number of epochs
epochs = 100

for epoch in range(epochs):
    model_3.train() # set training mode
    y_logits = model_3(X_blob_train)
    y_pred_probs = torch.softmax(y_logits, dim=1).argmax(dim=1).type(torch.float)
    loss = loss_fn(y_logits, y_blob_train)
    acc = accuracy_fn(y_true=y_blob_train, y_pred=y_pred_probs)
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    
    #Testing
    model_3.eval()
    with torch.inference_mode():
        test_logits = model_3(X_blob_test)
        test_pred_probs = torch.softmax(test_logits, dim=1).argmax(dim=1).type(torch.float)
        test_loss = loss_fn(test_logits, y_blob_test)
        test_acc = accuracy_fn(y_blob_test, test_pred_probs)
        
        if epoch % 10 == 0:
            print(f"Epoch: {epoch}, Loss: {loss:.5f}, accuracy: {acc:.2f}%")
            print(f"Test Loss: {test_loss:.5f}, Test accuracy: {test_acc:.2f}%")

from helper_functions import plot_predictions, plot_decision_boundary
            
model_3.eval()
with torch.inference_mode():
    y_logits = model_3(X_blob_test) #raw logits
    y_pred_probs= torch.softmax(y_logits, dim=1)
    y_preds = torch.argmax(y_pred_probs, dim=1) #can also be y_pred_probs.argmax()
    
plt.figure(figsize=(12,6))
plt.subplot(1, 2, 1)
plt.title("Train")
plot_decision_boundary(model_3, X_blob_train, y_blob_train)
plt.subplot(1, 2, 2)
plt.title("Test")
plot_decision_boundary(model_3, X_blob_test, y_blob_test)
#For this particular case the noon-linearities were not needed

#Other classification metrics are
#Precision
#Recall
#F1-score
#Confusion matrix
#Classification report

#are available under torchmetrics which can be installed as pip or conda package
from torchmetrics import Accuracy

#setup metric 
torchmetric_accuracy = Accuracy(task="multiclass", num_classes=4)

#Calculate accuracy
print(torchmetric_accuracy(y_preds, y_blob_test).item())

==>EXERCISES<=

# Code for creating a spiral dataset from CS231n
import numpy as np
N = 100 # number of points per class
D = 2 # dimensionality
K = 3 # number of classes
X = np.zeros((N*K,D)) # data matrix (each row = single example)
y = np.zeros(N*K, dtype='uint8') # class labels
for j in range(K):
  ix = range(N*j,N*(j+1))
  #r,t == polar co-ordinates
  r = np.linspace(0.0,1,N) # radius
  t = np.linspace(j*4,(j+1)*4,N) + np.random.randn(N)*0.2 # theta
  X[ix] = np.c_[r*np.sin(t), r*np.cos(t)]
  #formula for converting polar co-ordinates to cartesian co-ordinates (above)
  y[ix] = j
  # lets visualize the data
  plt.scatter(X[:, 0], X[:, 1], c=y, s=40, cmap=plt.cm.Spectral)
  plt.show()

==>03_pytorch_computer_vision_fashionmnist<==
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 28 17:13:17 2023

@author: leslietetteh
"""
# Computer vision libraries in pytorch:
from pathlib import Path
import requests
from torch.utils.data import DataLoader
# torchvision
# torchvision.datasets, get datasets and data loading funcs for computer vision
# torchvision.models, pretrained computer visioon models, which can be leveraged
# torchvision.transforms, functions for manipulating image data to be suitabe with ML model
# torch.utils.data.Dataset # Base dataset class for pytorch
# torch.utils.data.Dataset # Creates python iterable over a dataset

import torch
from torch import nn

import torchvision
from torchvision import datasets
from torchvision import transforms
from torchvision.transforms import ToTensor
import matplotlib.pyplot as plt

print(torch.__version__)
print(torchvision.__version__)

# Getting a dataset (FashionMNIST)
train_data = datasets.FashionMNIST(
    root="data",  # where to download data to
    train=True,  # do we wat the training dataset?
    download=True,  # do we want to download?
    transform=torchvision.transforms.ToTensor(),  # how do we transform the data?
    target_transform=None  # how do we want to transform the labels/targets?
)

test_data = datasets.FashionMNIST(
    root="data",
    train=False,
    download=True,
    transform=ToTensor(),
    target_transform=None
)

print(len(train_data))
print(len(test_data))

image, label = train_data[0]
# print(image)
print(f"Image shape: {image.shape}")
print(f"label: {label}")

class_names = train_data.classes
class_to_idx = train_data.class_to_idx
print(class_to_idx)

plt.imshow(image.squeeze(), cmap="gray")
plt.show()

torch.manual_seed(42)
fig = plt.figure(figsize=(9, 9))
rows, cols = 4, 4
for i in range(1, rows*cols+1):
    random_idx = torch.randint(0, len(train_data), size=[1]).item()
    img, label = train_data[random_idx]
    # print(random_idx)
    fig.add_subplot(rows, cols, i)
    plt.imshow(img.squeeze(), cmap="gray")
    plt.title(class_names[label])
    plt.axis(False)

print(train_data)  # is in the form of python dataset
print(test_data)  # same form

# want to turn our dataset into a dataloader. A dataloader
# turns our dataset into a Python iterable

# Turning data into batches (or mini-batches) is more computationally
# efficient, and it gives our neural network more chances to update
# its gradients per epoch


# serts batch size hyperprameter
BATCH_SIZE = 32

train_dataloader = DataLoader(dataset=train_data,
                              batch_size=BATCH_SIZE,
                              shuffle=True)

test_dataloader = DataLoader(dataset=test_data,
                             batch_size=BATCH_SIZE,
                             shuffle=False)

print(
    f"Length of train_dataloader: {len(train_dataloader)} batches of {BATCH_SIZE}")
print(
    f"Length of test_dataloader: {len(test_dataloader)} batches of {BATCH_SIZE}")

# check out whats inside the training dataloader
train_features_batch, train_labels_batch = next(iter(train_dataloader))
print(train_features_batch.shape)  # torch.Size([32, 1, 28, 28])
print(train_labels_batch.shape)  # torch.Size([32])

torch.manual_seed(42)
random_idx = torch.randint(0, len(train_features_batch), size=[1]).item()
img, label = train_features_batch[random_idx], train_labels_batch[random_idx]
plt.imshow(img.squeeze(), cmap="gray")
plt.title(class_names[label])
plt.axis(False)
plt.show()
print(f"Image size: {img.shape}")

# Build a baseline model, best to start with baseline model

# Create a flatten layer
flatten_model = nn.Flatten()

# Get a single sample
x = train_features_batch[0]
print(x.shape)  # torch.Size([32, 1, 28, 28])

# Flatten the sample
output = flatten_model(x)
print(output.shape)  # torch.Size([1, 784])


class FashionMNISTModelV0(nn.Module):
    def __init__(self,
                 input_shape: int,
                 hidden_units: int,
                 output_shape: int):
        super().__init__()
        self.layer_stack = nn.Sequential(
            nn.Flatten(),
            nn.Linear(in_features=input_shape, out_features=hidden_units),
            nn.Linear(in_features=hidden_units, out_features=output_shape),
        )

    def forward(self, x):
        return self.layer_stack(x)


torch.manual_seed(42)

model_0 = FashionMNISTModelV0(input_shape=784,
                              hidden_units=10,
                              output_shape=len(class_names))

dummy_x = torch.rand([1, 1, 28, 28])
print(model_0(dummy_x))
# returns 10 raw logits. If not for flatten layer, and input shape was
# 28 result of matrix multiplication leaves (1, 28, 10) shape tensor
# for model's final output

# setup loss, optimizer and evaluation metrics

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(params=model_0.parameters(), lr=0.01)

# Download
if Path("helper_functions.py").is_file():
    print("Skipping dowload...")
else:
    print("Downloading helper_functions.py")
    request = requests.get("https://raw.githubusercontent.com/mrdbourke/pytorch-deep-learning/main/helper_functions.py")
    with open("helper_functions.py", "wb") as f:
        f.write(request.content)
        
from helper_functions import accuracy_fn

#Creating a function to time experiments
from timeit import default_timer as timer

def print_train_time(start: float,
                     end: float,
                     device: torch.device = None):
    """Prints difference between start and end time."""
    total_time = end - start
    print(f"Train time on {device}: {total_time:.3f} seconds")
    return total_time

# import tqdm for a progress bar (tqdm.auto gives a different
#progress bar based on the environment you're running in)
from tqdm.auto import tqdm

device = "cuda" if torch.cuda.is_available() else "cpu"

torch.manual_seed(42)

start_time = timer()

epochs=3

#for tqdm to work just wrap iterator with tqdm
for epoch in tqdm(range(epochs)):
    print(f"Epoch: {epoch}\n")
    train_loss = 0
    #Loop for training batches
    for batch, (X, y) in enumerate(train_dataloader):
        model_0.train()
        #Forward pass
        y_pred = model_0(X)
        loss = loss_fn(y_pred, y)
        train_loss += loss #accumulate train_loss
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
        if batch % 400 == 0:
            print(f"Looked at {batch * len(X)}/{len(train_dataloader.dataset)} samples")
    
    #Divide total train loss by length of train_dataloader
    train_loss /= len(train_dataloader)
    
    #Testing
    test_loss, test_acc = 0,0
    model_0.eval()
    with torch.inference_mode():
        for X_test, y_test in test_dataloader:
            test_pred = model_0(X_test)
            #Calculate loss/acc cumulatively
            test_loss += loss_fn(test_pred, y_test)
            test_acc += accuracy_fn(y_true=y_test, y_pred=test_pred.argmax(dim=1))
            
        test_loss /= len(test_dataloader)
        test_acc /= len(test_dataloader)
    
    print(f"\nTrain loss: {train_loss:.4f} | Test loss: {test_loss:.4f}, Test acc: {test_acc:.2f}%")
            
#calculate training time    
end_time = timer()
total_train_time_0 = print_train_time(start=start_time, end=end_time, device="cpu")

torch.manual_seed(42)
def eval_model(model: torch.nn.Module,
               data_loader: torch.utils.data.DataLoader,
               loss_fn: torch.nn.Module,
               accuracy_fn,
               device=device):
    """Returns a dictionary containing the results of model predicting on data_loader"""
    loss, acc = 0, 0
    model.eval()
    with torch.inference_mode():
        for X, y in data_loader:
            X, y = X.to(device), y.to(device)
            #Make predictions
            y_pred = model(X)
            
            #Accumulate loss and acc pre batch
            loss += loss_fn(y_pred, y)
            acc += accuracy_fn(y_true=y, y_pred=y_pred.argmax(dim=1))
        
        #Scale loss and acc to find averages
        loss /= len(data_loader)
        acc /= len(data_loader)
    
    return {"model_name": model.__class__.__name__, #only works when model was created with a class
            "model_loss": loss.item(),
            "model_acc": acc}

#Calculate model_0 results on test dataset
model_0_results = eval_model(model=model_0,
                             data_loader=test_dataloader,
                             loss_fn=loss_fn,
                             accuracy_fn=accuracy_fn)
print(model_0_results)

#Building a better model with non-linearity

class FashionMNISTModelV1(nn.Module):
    def __init__(self,
                 input_shape: int,
                 hidden_units: int,
                 output_shape: int):
        super().__init__()
        self.layer_stack = nn.Sequential(
            nn.Flatten(), #
            nn.Linear(in_features=input_shape, out_features=hidden_units),
            nn.ReLU(),
            nn.Linear(in_features=hidden_units, out_features=output_shape),
            nn.ReLU()
        )
        
    def forward(self, x: torch.Tensor):
        return self.layer_stack(x)
    
torch.manual_seed(42)
model_1 = FashionMNISTModelV1(input_shape=784, hidden_units=10, output_shape=len(class_names)).to(device)
#print(model_1.parameters().device)

from helper_functions import accuracy_fn

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(params=model_1.parameters(),
                            lr=0.1)

#functionizisng training/testing loops
def train_step(model: nn.Module, 
               data_loader: torch.utils.data.DataLoader,
               loss_fn: nn.Module,
               optimizer: torch.optim.Optimizer,
               accuracy_fn,
               device: torch.device = device):
    """Performs training with a model trying to learn on data_loader."""
    train_loss, train_acc = 0, 0
    
    model.train()
    
    for batch, (X, y) in enumerate(data_loader):    
        X, y = X.to(device), y.to(device)
    
        y_pred = model(X).squeeze()
        
        loss = loss_fn(y_pred, y)
        train_loss += loss
        train_acc += accuracy_fn(y_true=y, y_pred=y_pred.argmax(dim=1))
        
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
        if batch % 400 == 0:
            print(f"Looked at {batch * len(X)}/{len(data_loader.dataset)} samples")
        
    train_loss /= len(data_loader)
    train_acc /= len(data_loader)
    print(f"Train loss: {train_loss:.5f} | Train acc: {train_acc:.2f}%")
    
def test_step(model: nn.Module,
              data_loader: torch.utils.data.DataLoader,
              loss_fn: nn.Module,
              accuracy_fn,
              device: torch.device = device):
    test_loss, test_acc = 0, 0
    
    model.eval()
    
    with torch.inference_mode():
        for X, y in data_loader:
            X, y = X.to(device), y.to(device)
            
            test_pred = model(X).squeeze()
            
            test_loss += loss_fn(test_pred, y)
            test_acc += accuracy_fn(y_true=y, y_pred = test_pred.argmax(dim=1))
            
        test_loss /= len(data_loader)
        test_acc /= len(data_loader)
        print(f"Test loss: {test_loss:.5f} | Test acc: {test_acc:.2f}%")
        
torch.manual_seed(42)

train_time_start = timer()

epochs = 3

for epoch in tqdm(range(epochs)):
    print(f"Epoch: {epoch}")
    train_step(model_1,
               train_dataloader,
               loss_fn,
               optimizer,
               accuracy_fn,
               device)
    
    test_step(model_1,
              test_dataloader,
              loss_fn,
              accuracy_fn,
              device)
    
train_time_end = timer()
total_train_time_1 = print_train_time(train_time_start, train_time_end)

model_1_results = eval_model(model_1, 
                             test_dataloader, 
                             loss_fn, 
                             accuracy_fn,
                             device) 

#Building a Convolutional Neural Network (CNN)
class FashionMNISTModelV2(nn.Module):
    """Model architecture that replicates the TinyVGG model from CNN Explainer website"""
    def __init__(self, 
                 input_shape: int, 
                 hidden_units: int,
                 output_shape: int):
        super().__init__()
        self.conv_block1 = nn.Sequential(
            nn.Conv2d(in_channels=input_shape, 
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.Conv2d(in_channels=hidden_units, 
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2)
        )
        self.conv_block2 = nn.Sequential(
            nn.Conv2d(in_channels=hidden_units, 
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.Conv2d(in_channels=hidden_units, 
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2)
        )
        self.classifier = nn.Sequential(
            nn.Flatten(),
            nn.Linear(in_features=hidden_units * 49,# *0==placeholder
                      out_features=output_shape)
        )
    
    def forward(self, x):
        x = self.conv_block1(x)
        #print(x.shape)
        x = self.conv_block2(x)
        #print(x.shape)
        x = self.classifier(x)
        #print(x.shape)
        return x      
    
torch.manual_seed(42)
model_2 = FashionMNISTModelV2(input_shape=1, hidden_units=10, output_shape=len(class_names))

model_2(image.unsqueeze(0).to(device))

optimizer = torch.optim.SGD(params=model_2.parameters(), lr=0.1)

torch.manual_seed(42)
torch.cuda.manual_seed(42)

start_model2_time = timer()

epochs=3
for epoch in tqdm(range(epochs)):
    print(f"Epoch: {epoch}")
    train_step(model_2, 
               train_dataloader, 
               loss_fn, 
               optimizer, 
               accuracy_fn,
               device)
    
    test_step(model_2, 
              test_dataloader, 
              loss_fn, 
              accuracy_fn,
              device)

end_model2_time = timer()

total_train_time_2 = print_train_time(start_model2_time, end_model2_time)


model_2_results = eval_model(model_2, 
                             test_dataloader, 
                             loss_fn, 
                             accuracy_fn,
                             device) 

import pandas as pd
compare_results = pd.DataFrame([model_0_results,
                                model_1_results,
                                model_2_results])
print(compare_results)

compare_results["training_time"] = [total_train_time_0,
                                    total_train_time_1,
                                    total_train_time_2]
print(compare_results)

#Visualize model results
compare_results.set_index("model_name")["model_acc"].plot(kind="barh")
plt.xlabel("accuracy (%)")
plt.ylabel("model")
plt.show()

def make_predictions(model: nn.Module,
                     data: list,
                     device: torch.device = device):
    pred_probs = []
    model.eval()
    with torch.inference_mode():
        for sample in data:
            sample = torch.unsqueeze(sample, dim=0).to(device)
            
            pred_logit = model(sample)
            
            pred_prob = torch.softmax(pred_logit.squeeze(), dim=0)
            
            pred_probs.append(pred_prob.cpu()) #move to cpu      
            
    return torch.stack(pred_probs)

import random
random.seed(42)
test_samples = []
test_labels = []
for sample, label in random.sample(list(test_data), k=9):
    test_samples.append(sample)
    test_labels.append(label)
    
    #view firs sample shape
print(test_samples[0].shape)
plt.imshow(test_samples[0].squeeze(), cmap="gray")
plt.title(class_names[test_labels[0]])
plt.show()
    
pred_probs = make_predictions(model=model_2, data=test_samples)
pred_labels = pred_probs.argmax(dim=1)

#plot predictions
plt.figure(figsize=(9,9)) 
nrows = 3
ncols = 3
for i, sample in enumerate(test_samples):
    plt.subplot(nrows, ncols, i+1)
    plt.imshow(sample.squeeze(), cmap="gray")
    pred_label = class_names[pred_labels[i]]
    
    truth_label = class_names[test_labels[i]]
    
    title_text = f"Pred: {pred_label} | Truth: {truth_label}"
    
    if pred_label == truth_label:
        plt.title(title_text, fontsize=10, c="g")
    else:
        plt.title(title_text, fontsize=10, c="r")
    plt.axis(False)
    plt.show()
    
#Making a confusion matrix for further prediction evaluation

y_preds = []
model_2.eval()
with torch.inference_mode():
    for X, y in tqdm(test_dataloader, desc="Making predictions..."):
        X, y = X.to(device), y.to(device)
        y_logit = model_2(X)
        # logits -> prediction probabilities -> pred labels
        y_pred = torch.softmax(y_logit.squeeze(), dim=0).argmax(dim=1)
        y_preds.append(y_pred.cpu())
        
#concatenate list of predictions into a tensor
y_pred_tensor = torch.cat(y_preds)
print(len(y_pred_tensor)) # should be 10000
        
try:
    import torchmetrics, mlxtend
    assert int(mlxtend.__version__.split(".")[1]) >= 19,"mlxtend should be version 0.19.0 or higher"
except:
    print("Oh noes") 
    
from torchmetrics import ConfusionMatrix
from mlxtend.plotting import plot_confusion_matrix

# Setup confusion matrix instance
confmat = ConfusionMatrix(task="multiclass", num_classes=len(class_names))
confmat_tensor = confmat(preds=y_pred_tensor, target=test_data.targets)

fig, ax = plot_confusion_matrix(
    conf_mat=confmat_tensor.numpy(),
    class_names=class_names,
    figsize=(10,7)
)

from pathlib import Path

MODEL_PATH = Path("models")
MODEL_PATH.mkdir(parents=True, exist_ok=True)
MODEL_NAME = "03_pytorch_computer_vision_model_2.pth"
MODEL_SAVE_PATH = MODEL_PATH / MODEL_NAME

print(f"Saving model")
torch.save(obj=model_2.state_dict(), f=MODEL_SAVE_PATH)

loaded_model_2 = FashionMNISTModelV2(input_shape=1, 
                                     hidden_units=10, 
                                     output_shape=len(class_names))

loaded_model_2.load_state_dict(torch.load(f=MODEL_SAVE_PATH))

loaded_model_2.to(device)

torch.manual_seed(42)

loaded_model_2_results = eval_model(loaded_model_2,
                                    test_dataloader,
                                    loss_fn,
                                    accuracy_fn)

print(loaded_model_2_results)

torch.isclose(torch.tensor(model_2_results["model_loss"]), 
              torch.tensor(loaded_model_2_results["model_loss"]),
              atol=1e-02)

==>conv2d-step-by-step<==
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 31 17:58:21 2023

@author: leslietetteh
"""

#see nn.conv2d documentation

import torch
import torch.nn as nn

torch.manual_seed(42)

#create a batch of images
images = torch.randn(size=(32, 3, 64, 64))
test_image = images[0]

print(f"Image batch shape: {images.shape}")
print(f"Single image shape: {test_image.shape}") #torch.Size([3, 64, 64]) 
#print(f"Test image:\n {test_image}")

torch.manual_seed(42)

conv_layer = nn.Conv2d(in_channels=3, 
                       out_channels=10, 
                       kernel_size=3,
                       stride=1,
                       padding=1) #if have info at edges, use padding
  
conv_output = conv_layer(test_image)
print(conv_output.shape) # torch.Size([10, 62, 62]) for padding = 0
#torch.Size([10, 64, 64]) for padding=1 "CNN Explainer"

#Stepping through nn.MaxPool2d

max_pool_layer = nn.MaxPool2d(kernel_size=2)

#Pass data through max pool layer

max_pool_output = max_pool_layer(conv_output)

print(max_pool_output.shape) # torch.Size([10, 32, 32])

==>04_custom_dataset.py<==
# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 20:41:40 2023

@author: leslietetteh
"""

import torch
from torch import nn

#Domain libraries exist in torchvision, torchaudio, torchtext, torchrec,
#which have existing data loading functions and customizable data
#loading functions.

device = "cuda" if torch.cuda.is_available() else "cpu"

#Get data (our data is a subset of the Food101 dataset, which contains
#101 classes, and 101000 images. Our training set starts with 3 classes
#of food and 10% of images ~75 training, ~25 testing)

import requests     
import zipfile
from pathlib import Path

#setup path to data folder
data_path = Path("data/")
image_path = data_path / "pizza_steak_sushi"

if image_path.is_dir():
    print(f"Skipping download...")
else:
    print(f"Creating {image_path}")
    image_path.mkdir(parents=True, exist_ok=True)
        
    #download data
    with open(data_path / "pizza_steak_sushi.zip", "wb") as f:
        print(f"Downloading pizza_sushi_steak.zip...")
        request = requests.get("https://github.com/mrdbourke/pytorch-deep-learning/raw/main/data/pizza_steak_sushi.zip")
        f.write(request.content)
        
    #Unzip data
    with zipfile.ZipFile(data_path / "pizza_steak_sushi.zip", "r") as zip_ref:
        print(f"Unzipping pizza_sushi_steak.zip...")
        zip_ref.extractall(image_path)
        
# data preparation and data exploration

import os

def walk_through_dir(dir_path):
    """Walks through dir_path returning its contents."""
    for dirpath, dirnames, filenames in os.walk(dir_path):
        print(f"There are {len(dirnames)} directories and {len(filenames)} images in '{dirpath}'")
        
#walk_through_dir(image_path)

#setup traing and test paths
train_dir = image_path / "train"
test_dir = image_path / "test"

#1. Get all of the image paths
#2. Pick a random image path
#3. Get the image class name using 'pathlib.Path.parent.stem'
#4. Open image with python PIL (Python Imaging Library)
#5. Show the image and print metadata

import random
from PIL import Image

random.seed(42)

#1.
image_path_list = list(image_path.glob("*/*/*.jpg"))
#print(image_path_list)

#2.
random_image_path = random.choice(image_path_list)
#print(random_image_path)

#3.
image_class = random_image_path.parent.stem
#print(image_class)

#4.
img = Image.open(random_image_path)

#5.
print(f"Random image path: {random_image_path}")
print(f"Image class: {image_class}")        
print(f"Image height: {img.height}")
print(f"Image width: {img.width}")

#6. turn img into numpy array

import numpy as np
import matplotlib.pyplot as plt

img_as_array = np.asarray(img)

#7. Show with matplotlib

plt.figure(figsize=(10,7))
plt.imshow(img_as_array)
plt.title(f"Image class: {image_class} | Image shape: {img_as_array.shape} -> [height, width, color_channels]")
plt.axis(False)
plt.show()

#before we can use image data with pytorch, it needs to be turned into
#tensors, then turned into a DataSet, then to a DataLoader

from torch.utils.data import DataLoader
from torchvision import datasets, transforms

data_transform = transforms.Compose([
    # Resize our images to 64 x 64
    transforms.Resize(size=(64, 64)),
    # Flip the images randomly on the horizontal axis
    transforms.RandomHorizontalFlip(p=0.5),
    #Turn the image into a torch.Tensor
    transforms.ToTensor()
])

#below requires a PIL image as input
print(data_transform(img).shape) #torch.Size([3, 64, 64])
print(data_transform(img).dtype)

def plot_transformed_images(image_paths, transform, n=3, seed=42):
    """
    Selects random images from a path of images and loads/transforms 
    them then plots the original vs the transformed version.

    Parameters
    ----------
    image_paths : list
        DESCRIPTION. List of Image paths
    transform : TYPE
        DESCRIPTION.
    n : int, optional
        DESCRIPTION. The default is 3.
    seed : int, optional
        DESCRIPTION. The default is 42.

    Returns
    -------
    None.

    """
    random.seed(seed)
    
    random_image_paths = random.sample(image_paths, k=n)
    
    for image_path in random_image_paths:
        with Image.open(image_path) as f:
            fig, ax = plt.subplots(nrows=1, ncols=2)
            ax[0].imshow(f)
            ax[0].set_title(f"Original\nSize: {f.size}")
            ax[0].axis(False)
            
            #transform and plot target image
            transformed_image = transform(f).permute(1,2,0) 
            #note we need to change shape for matplotlb as it prefers 
            #(colour_channels,height,width) instead of (h,w,c)
            ax[1].imshow(transformed_image)
            ax[1].set_title(f"Transformed\nSize: {transformed_image.shape}")
            ax[1].axis("off")
            
            fig.suptitle(f"Class: {image_path.parent.stem}", fontsize=16)
            
plot_transformed_images(image_paths=image_path_list, 
                        transform=data_transform)  

#Use ImageFolder() to create dataset(s)
train_data = datasets.ImageFolder(root=train_dir,
                                  transform=data_transform, #a transform for the data
                                  target_transform=None) # a transform for the label/target          

test_data = datasets.ImageFolder(root=test_dir,
                                 transform=data_transform)

#print(train_data)
#print(test_data)
class_names = train_data.classes
print(class_names)
class_dict = train_data.class_to_idx
#print(class_dict)
print(f"{len(train_data)}, {len(test_data)}")
print(train_data.samples[0])

img, label = train_data[0][0], train_data[0][1]
print(img.shape) # in tensor form
print(img.dtype)
print(f"{label}: {class_names[label]}")

img_permute = img.permute(1, 2, 0)
plt.figure(figsize=(10, 7))
plt.imshow(img_permute)
plt.axis(False)
plt.title(class_names[label], fontsize=14)

#a DataLoader helps turn a DataSet into iterables, and allows batch_size
#to be customized so the model can see batch_size images at a time.

BATCH_SIZE=32
train_dataloader = DataLoader(dataset=train_data,
                              batch_size=BATCH_SIZE,
                              #num_workers=os.cpu_count(),
                              shuffle=True)

test_dataloader = DataLoader(dataset=test_data,
                             batch_size=BATCH_SIZE,
                             #num_workers=os.cpu_count(),
                             shuffle=False)

img, label = next(iter(train_dataloader))

print(f"Image shape: {img.shape} -> (batch_size, color_channels, height, width)")

# Option 2: Loading Image Data with a Custom 'Dataset'
#Custom datasets often subclass (inherit from) torch.utils.data.DataSet

from typing import Tuple, Dict, List

#We will get Class names using os.scandir() to traverse a target directory
#Raise an error if class naes are not found
#Turn the class_names into a dict and return them

target_directory = train_dir
print(f"Target dir: {target_directory}")

class_names_found = sorted([entry.name for entry in list(os.scandir(target_directory))])
print(class_names_found)
print(list(os.scandir(target_directory)))

def find_classes(directory:str) -> Tuple[List[str], Dict[str, int]]:
    """Finds the class folder names in a target directory."""
    classes = sorted(entry.name for entry in os.scandir(directory) if entry.is_dir())
    
    if not classes:
        raise FileNotFoundError(f"Couldn't find any classes in {directory}.. please check file structure")
    
    class_to_idx = {class_name: i for i, class_name in enumerate(classes)}
    
    return classes, class_to_idx

print(find_classes(target_directory))

from torch.utils.data import Dataset

class ImageFolderCustom(Dataset):
    def __init__(self, targ_dir: str, transform=None):
        self.paths = list(Path(targ_dir).glob("*/*.jpg"))
        self.transform = transform
        self.classes, self.class_to_idx = find_classes(targ_dir)
        
    def load_image(self, index: int) -> Image.Image:
        """Opens an image via a path and returns it"""
        image_path = self.paths[index]
        return Image.open(image_path)
    
    # required?
    def __len__(self) -> int:
        """Returns the total number of samples"""
        return len(self.paths)
    
    #required
    def __getitem__(self, index: int) -> Tuple[torch.Tensor, int]:
        """Re
        turns one sample of data and label (X, y)"""
        img = self.load_image(index)
        class_name = self.paths[index].parent.name #expects directory strucure
        class_idx = self.class_to_idx[class_name]
        
        #transform if necessary
        if self.transform:
            return self.transform(img), class_idx #return data, label(X, y)
        else:
            return img, class_idx
        
#Create a transform
train_transforms = transforms.Compose([transforms.Resize(size=(64,64)),
                                       transforms.RandomHorizontalFlip(p=0.5),
                                       transforms.ToTensor()])

test_transforms = transforms.Compose([transforms.Resize(size=(64,64)),
                                      transforms.ToTensor()])

train_data_custom = ImageFolderCustom(targ_dir=train_dir,
                                      transform=train_transforms)

test_data_custom = ImageFolderCustom(targ_dir=test_dir,
                                     transform=test_transforms)

print(f"{len(train_data_custom)}, {len(test_data_custom)}")
print(f"{train_data_custom.classes}, {train_data_custom.class_to_idx}")

#function to display random images
def display_random_images(dataset: torch.utils.data.Dataset,
                          classes: List[str] = None,
                          n: int = 10,
                          display_shape: bool = True,
                          seed: int = None):
    if n > 10:
        n = 10
        display_shape = False
        print(f"For display n shouldn't be greater than 10")
        
    if seed:
        random.seed(seed)
        
    random_samples_idx = random.sample(range(len(dataset)), k = n)
    # returns list of integers (indices)
    
    plt.figure(figsize=(16,8))
    
    for i, targ_sample in enumerate(random_samples_idx):
        targ_image, targ_label = dataset[targ_sample][0], dataset[targ_sample][1]
        
        targ_image_adjust = targ_image.permute(1, 2, 0) # H,W,C -> C,H,W
        
        plt.subplot(1, n, i+1)
        plt.imshow(targ_image_adjust)
        plt.axis(False)
        
        if classes:
            title = f"Class: {classes[targ_label]}"
            if display_shape:
                title = title + f"\nshape: {targ_image_adjust.shape}"
        plt.title(title)
        
display_random_images(train_data,
                      n=3,
                      classes=class_names,
                      seed=42)

train_dataloader_custom = DataLoader(dataset=train_data_custom,
                                     batch_size=BATCH_SIZE,
                                     shuffle=True)

test_dataloader_custom = DataLoader(dataset=test_data_custom,
                                    batch_size=BATCH_SIZE)

img_custom, label_custom = next(iter(train_dataloader_custom))

print(f"{img_custom.shape}, {label_custom.shape}")

#other forms of transforms, data augmentation, which involves looking at
#the same image from a different perspective, i.e. rotations, scale,
#shift, zoom, operations. Hopefully result in a model more generalizable
#to unseen data

train_transform = transforms.Compose([transforms.Resize(size=(224, 224)),
                                      transforms.TrivialAugmentWide(num_magnitude_bins=31),
                                      transforms.ToTensor()])

test_transform = transforms.Compose([transforms.Resize(size=(224, 224)),
                                     transforms.ToTensor()])

#plot random transformed images (other types of transforms)

plot_transformed_images(image_paths=image_path_list,
                        transform=train_transform,
                        n=3,
                        seed=42)

#Model 0 TinyVGG without data augmentation

simple_transform = transforms.Compose([transforms.Resize(size=(64,64)),
                                       transforms.ToTensor()])

train_data_simple = datasets.ImageFolder(root=train_dir,
                                         transform=simple_transform)

test_data_simple = datasets.ImageFolder(root=test_dir,
                                        transform=simple_transform)
 
#NUM_WORKERS = os.cpu_count()

train_dataloader_simple = DataLoader(dataset=train_data_simple,
                                     batch_size=BATCH_SIZE,
                                     shuffle=True)

test_dataloader_simple = DataLoader(dataset=test_data_simple,
                                    batch_size=BATCH_SIZE,
                                    shuffle=False)

class TinyVGG(nn.Module):
    """Model architecture copying TinyVGG from CNNExplainer"""
    def __init__(self, 
                 input_shape: int,
                 hidden_units: int,
                 output_shape: int) -> None:
        super().__init__()
        self.conv_block1 = nn.Sequential(
            nn.Conv2d(in_channels=input_shape,
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.Conv2d(in_channels=hidden_units,
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2,
                         stride=2))
        self.conv_block2 = nn.Sequential(
            nn.Conv2d(in_channels=hidden_units,
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.Conv2d(in_channels=hidden_units,
                      out_channels=hidden_units,
                      kernel_size=3,
                      stride=1,
                      padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2,
                         stride=2))
        self.classifier = nn.Sequential(nn.Flatten(),
                                        nn.Linear(in_features=hidden_units*16*16,
                                                  out_features=output_shape)
                                        )
        
    def forward(self, x):
        x = self.conv_block1(x)
        #print(x.shape)
        x = self.conv_block2(x)
        #print(x.shape)
        x = self.classifier(x)
        #print(x.shape)
        return x
        #return self.classifier(self.conv_block2(self.conv_block1(x))) 
        #benefirsts from operator fusion, optimzation in deep learning
        
model_0 = TinyVGG(input_shape=3, hidden_units=16, output_shape=len(class_names)).to(device)
        
#dummy forward pass
image_batch, label_batch = next(iter(train_dataloader_simple))
#model_0(image_batch.to(device))        

#Using torchinfo to get idea of shapes going through model - pip install torchinfo

from torchinfo import summary

print(summary(model_0, input_size=[1, 3, 64, 64]))

def train_step(model: nn.Module,
               dataloader: torch.utils.data.DataLoader,
               loss_fn: nn.Module,
               optimizer: torch.optim.Optimizer,
               device: torch.device = device):
    #put model in train mode
    model.train()
    
    train_loss, train_acc = 0, 0
    
    for batch, (X, y) in enumerate(dataloader):
        X, y = X.to(device), y.to(device)
        
        y_pred = model(X)
        
        loss = loss_fn(y_pred, y)
        train_loss += loss.item()
        
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
        y_pred_class = torch.argmax(torch.softmax(y_pred, dim=1), dim=1)
        train_acc += (y_pred_class==y).sum().item()/len(y_pred)
        
    train_loss = train_loss / len(dataloader)
    train_acc = train_acc / len(dataloader)
        
    return train_loss, train_acc
    
def test_step(model: nn.Module,
              dataloader: torch.utils.data.DataLoader,
              loss_fn: nn.Module,
              device: torch.device = device):
    #put model in eval mode
    model.eval()
    
    test_loss, test_acc = 0, 0
    
    with torch.inference_mode():
        for batch, (X, y) in enumerate(dataloader):
            X, y = X.to(device), y.to(device)
            
            test_pred_logits = model(X)
            
            loss = loss_fn(test_pred_logits, y)
            test_loss += loss.item()
            
            test_pred_labels = test_pred_logits.argmax(dim=1) 
            #softmax only used to return probabilities, can just use argmax
            
            test_acc += (test_pred_labels == y).sum().item()/len(test_pred_labels)
            
    test_loss = test_loss / len(dataloader)
    test_acc = test_acc / len(dataloader)
    return test_loss, test_acc
            
#creating train() function to combine train_step() and test_step()

from tqdm.auto import tqdm

def train(model: nn.Module,
          train_dataloader: torch.utils.data.DataLoader,
          test_dataloader: torch.utils.data.DataLoader,
          optimizer: torch.optim.Optimizer,
          loss_fn: nn.Module = nn.CrossEntropyLoss(),
          epochs: int = 5,
          device:torch.device = device):
    #create empty results dictionary
    results = {"train_loss": [],
              "train_acc": [],
              "test_loss": [],
              "test_acc": []}

    for epoch in tqdm(range(epochs)):
        train_loss, train_acc = train_step(model=model,
                                           dataloader=train_dataloader,
                                           loss_fn=loss_fn,
                                           optimizer=optimizer)
        
        test_loss, test_acc = test_step(model=model,
                                        dataloader=test_dataloader,
                                        loss_fn=loss_fn)
        
        print(f"Epoch: {epoch} | Train Loss: {train_loss} | Train Acc: {train_acc} | Test Loss: {test_loss} | Test Acc: {test_acc}")

        results["train_loss"].append(train_loss)
        results["train_acc"].append(train_acc)
        results["test_loss"].append(test_loss)
        results["test_acc"].append(test_acc)
        
    return results

torch.manual_seed(42)
torch.cuda.manual_seed(42)

optimizer = torch.optim.Adam(params=model_0.parameters(), lr=0.001)

from timeit import default_timer as timer

start_time = timer()

model_0_results = train(model=model_0,
                        train_dataloader=train_dataloader_custom,
                        test_dataloader=test_dataloader_custom,
                        optimizer=optimizer)

end_time = timer()

print(f"Total training time: {end_time-start_time:.3f} seconds")

#plotting model_0's loss curve

def plot_loss_curves(results: Dict[str, List[float]]):
    """Plots training curves of a results dictionary"""
    
    loss = results["train_loss"]
    test_loss = results["test_loss"]
    
    accuracy = results["train_acc"]
    test_accuracy = results["test_acc"]
    
    epochs = range(len(results["train_loss"]))
    
    plt.figure(figsize=(15, 7))
    
    plt.subplot(1, 2, 1)
    plt.plot(epochs, loss, label="train_loss")
    plt.plot(epochs, test_loss, label="test_loss")
    plt.title("Loss")
    plt.xlabel("Epochs")
    plt.legend()
    
    plt.subplot(1, 2, 2)
    plt.plot(epochs, accuracy, label="train_accuracy")
    plt.plot(epochs, test_accuracy, label="test_accuracy")
    plt.title("Accuracy")
    plt.xlabel("Epoch")
    plt.legend()
    
plot_loss_curves(model_0_results)

# model 1 TinyVGG with Data Augmentation

train_transform_trivial = transforms.Compose([transforms.Resize(size=(64,64)),
                                              transforms.TrivialAugmentWide(num_magnitude_bins=31),
                                              transforms.ToTensor()])

test_transform_trivial = transforms.Compose([transforms.Resize(size=(64,64)),
                                             transforms.ToTensor()])

train_data_augmented = datasets.ImageFolder(root=train_dir,
                                            transform=train_transform_trivial)

test_data_trivial = datasets.ImageFolder(root=test_dir,
                                         transform=test_transform_trivial)

torch.manual_seed(42)
train_dataloader_augmented = DataLoader(train_data_augmented,
                                        batch_size=BATCH_SIZE,
                                        shuffle=True)

test_dataloader_trivial = DataLoader(test_data_trivial,
                                     batch_size=BATCH_SIZE,
                                     shuffle=False)

torch.manual_seed(42)
model_1 = TinyVGG(input_shape=3,
                  hidden_units=10,
                  output_shape=len(train_data_augmented.classes)).to(device)

torch.manual_seed(42)
torch.cuda.manual_seed(42)

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(params=model_1.parameters(), lr = 0.001)

starttime = timer()

model_1_results = train(model=model_1,
                        train_dataloader=train_dataloader_augmented,
                        test_dataloader=test_dataloader_trivial,
                        optimizer=optimizer)

endtime = timer()
print(f"Total training time for model_1: {endtime-starttime:.3f} seconds")

plot_loss_curves(model_1_results)

#comparing model results
import pandas as pd

#can create dataframe for moel results because they
#are in the form of a Dictionary
model_0_df = pd.DataFrame(model_0_results)
model_1_df = pd.DataFrame(model_1_results)
print(model_0_df)
print()
print(model_1_df)

plt.figure(figsize=(15,10))

epochs = range(len(model_0_df))

plt.subplot(2, 2, 1)
plt.plot(epochs, model_0_df["train_loss"], label="Model 0")
plt.plot(epochs, model_1_df["train_loss"], label="Model 1")
plt.title("Train Loss")
plt.xlabel("Epochs")
plt.legend()

plt.subplot(2, 2, 2)
plt.plot(epochs, model_0_df["test_loss"], label="Model 0")
plt.plot(epochs, model_1_df["test_loss"], label="Model 1")
plt.title("Test Loss")
plt.xlabel("Epochs")
plt.legend()


plt.subplot(2, 2, 3)
plt.plot(epochs, model_0_df["train_acc"], label="Model 0")
plt.plot(epochs, model_1_df["train_acc"], label="Model 1")
plt.title("Train Acc")
plt.xlabel("Epochs")
plt.legend()

plt.subplot(2, 2, 4)
plt.plot(epochs, model_0_df["test_acc"], label="Model 0")
plt.plot(epochs, model_1_df["test_acc"], label="Model 1")
plt.title("Test Acc")
plt.xlabel("Epochs")
plt.legend()

plt.show()

#Loading in a custom image with pytorch

custom_image_path = data_path / "04-pizza-dad.jpeg"

#download image (if it doesn't exist)
if not custom_image_path.is_file():
    with open(custom_image_path, "wb") as f:
        print(f"Downloading {custom_image_path}...")
        request = requests.get("https://raw.githubusercontent.com/mrdbourke/pytorch-deep-learning/main/images/04-pizza-dad.jpeg")
        f.write(request.content)
else:
    print(f"{custom_image_path} exists. Skiping download")        

import torchvision

custom_image_uint8 = torchvision.io.read_image(str(custom_image_path))
custom_image = custom_image_uint8.type(torch.float32) / 255
#custom_image_path is stored as a POSIX file path, needs to be converted to string

plt.imshow(custom_image_uint8.permute(1, 2, 0))
plt.show()
plt.imshow(custom_image.permute(1, 2, 0))
plt.show()

#create transform pipeline to resize image
custom_image_transform = transforms.Compose([transforms.Resize(size=(64,64))])

#Transform target image
custom_image_transformed = custom_image_transform(custom_image)
plt.imshow(custom_image_transformed.permute(1,2,0))
plt.show()

#Add batch dimension
custom_image_batch = custom_image_transformed.unsqueeze(0)

model_1.eval()
with torch.inference_mode():
    #send image to device
    custom_image_logits = model_1(custom_image_batch.to(device))
    print(class_names[custom_image_logits.argmax(dim=1)])
    
# Will build a function to do all of the above
def pred_and_plot_image(model: nn.Module,
                        image_path: str,
                        class_names: List[str] = None,
                        transform=None,
                        device = device):
    """Makes prediction on image and plots image and prediction"""
    
    target_image = torchvision.io.read_image(str(image_path)).type(torch.float32)
    target_image /= 255
    
    if transform:
        target_image = transform(target_image)
        
    model = model.to(device)
    
    model.eval()
    with torch.inference_mode():
        target_image = target_image.unsqueeze(0)
        
        target_image_logits = model(target_image.to(device))
        
    # Conver logits -> probabilities
    target_image_pred_probs = target_image_logits.softmax(dim=1)
    target_image_pred_label = target_image_pred_probs.argmax(dim=1)
    
    plt.imshow(target_image.squeeze().permute(1, 2, 0))
    if class_names:
        title = f"Pred: {class_names[target_image_pred_label.cpu()]} | Prob: {target_image_pred_probs.max().cpu():.3f}"
    else:
        title = f"Pred: {target_image_pred_label} | Prob {target_image_pred_probs.max().cpu():.3f}"
    plt.title(title)
    plt.axis(False)
    plt.show()
    
pred_and_plot_image(model=model_0, 
                    image_path=custom_image_path,
                    class_names=class_names,
                    transform=custom_image_transform,
                    device=device)
