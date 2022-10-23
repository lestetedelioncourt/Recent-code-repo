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
    win_paths = [['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0]]
    wins = [['#'] + [0] *8] *4
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
