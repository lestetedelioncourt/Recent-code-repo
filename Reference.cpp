==> ./Projects/02 - C++ const and functions/02 - C++ const and functions/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

// const used with functions
class Dog{
	int age;
	string name;
public:
	Dog(){ age = 3; name = "dummy"; }
	void setAge(const int &a) {cout << "const function called\n"; age = a;} //a++ will not compile
	void setAge(int &a) { cout << "function called\n"; age = a; }
	
	/*void setAge(const int a) {age = a;} - const useless as a is passed by value
	  void setAge(int a) {age = a;} 
	cannot overload the function as the caller sees them as the same function*/

	//const return value
	const string& getName() { return name; } //const return improves efficiency of program

	//const function
	void printDogname() const { cout << name << " const" <<endl; }
	//const function cannot call any function except a const function in its scope
	void printDogname() { cout << name << " non-const" << endl; } //overloaded 
};

int main(){
	Dog d;
	const Dog d2;

	d.printDogname(); //calls normal function
	d2.printDogname(); // calls const function

	const int i = 9;
	int i2 = 9;
	d.setAge(i);
	d.setAge(i2);
	
	cout << "Age is " << i << endl;

	const string& n = d.getName();
	return 0;
}
==> ./Projects/127 generic programming/127 generic programming/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

template <typename myType> void display(myType x){
	cout << x << " passed to display function\n";
}

template <class MyClass> MyClass sumconcat(MyClass x, MyClass y);

template <typename myType> void display(myType x, int y);

template <typename T1, typename T2> void display(T1 x, T2 y, int z);

int main(){
	display(21);
	display(10.9);
	display("leslie");

	string x = "leslie ";
	string y = "tetteh";
	cout << sumconcat(2, 3) << endl;
	cout << sumconcat(x, y) << endl;

	return 0;
}

template <class MyClass> MyClass sumconcat(MyClass x, MyClass y){
	return x + y;
}

template <typename myType> void display(myType x, int y){
	for (int i = 0; i < y; i++){
		cout << x << endl;
	}
}

template <typename T1, typename T2> void display(T1 x, T2 y, int z){
	for (int i = 0; i < z; i++){
		cout << x << " and " << y << endl;
	}
}

==> ./Projects/136 overloading generic class/136 overloading generic class/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

template <typename Type1> class MyClass{
	Type1 t1;
public:
	MyClass(Type1 t1){
		this->t1 = t1;
	}

	void display(){
		cout << "\nparameter passed was not int\nt1 : " << t1 << endl;
	}
};

template <> class MyClass < int > {
	int t1;
public:
	MyClass(int t1){
		this->t1 = t1;
	}

	void display(){
		cout << "\nint parameter was passed\nt1 : " << t1 << endl;
	}
};

int main(){
	MyClass <string> leslie("leslie");
	leslie.display();

	MyClass <int> john(15);
	john.display();

	return 0;
}

==> ./Projects/137 c++ namespaces/137 c++ namespaces/file_one.cpp <==
#include <iostream>

using namespace std;

namespace one{
	int x = 10;

	void display(){
		cout << "display from namespace one\n";
	}
}


==> ./Projects/137 c++ namespaces/137 c++ namespaces/file_two.cpp <==
#include <iostream>

using namespace std;

namespace two{
	int x = 20;

	void display(){
		cout << "display from namespace two\n";
	}
}
==> ./Projects/137 c++ namespaces/137 c++ namespaces/Source.cpp <==
#include <iostream>
#include "file_two.cpp"
#include "file_one.cpp"

using namespace std;
 //will make available all the variables from namespace one

int main(){
	
	using namespace two;
	display();
	cout << x << "\n\n";

	//if two namespace possess same variables/functions "using" keyword will 
	//create conflict. insted use name of namespace and scope resolution operator

	one::display();

	return 0;
}

==> ./Projects/137 namespacess/137 namespacess/file_one.h <==
#include <iostream>

using namespace std;

namespace one{
	int x = 10;

	void display(){
		cout << "display from file one\n";
	}
}
==> ./Projects/137 namespacess/137 namespacess/file_two.h <==
#include <iostream>

using namespace std;

namespace two{
	int x = 20;

	void display(){
		cout << "display from file two\n";
	}
}
==> ./Projects/137 namespacess/137 namespacess/main.cpp <==
#include <iostream>
#include "file_one.h"
#include "file_two.h"

using namespace std;
using namespace one; // all functions from namespace one now available

/*using namespace two; since there are functions/variables with the same name
there would be conflict and program would crash*/

int main(){
	cout << "hello world\n";
	display();
	cout << "file 1: x = " << x << endl;

	//can use scope resolution operator to access members of a namespace
	two::display();
	cout << "file 2: x = " << two::x << endl;
	return 0;
}
==> ./Projects/137 using namespaces/137 using namespaces/file_one.cpp <==
#include <iostream>

using namespace std;

namespace one{
	int x = 10;
	void display(){
		cout << "display from namespace one\n";
	}
}
==> ./Projects/137 using namespaces/137 using namespaces/Source.cpp <==
#include <iostream>
#include "file_one.cpp"

using namespace std;
using namespace one;

int main(){
	cout << "hello world\n";
	return 0;
}
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/checking.cpp <==

==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/checking.h <==
#ifndef CHECKING_H
#define CHECKING_H

#include "triangle.h"




#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/equilateral.cpp <==
#include "Equilateral.h"

Equilateral::Equilateral(){}

Equilateral::Equilateral(double newbase, double newheight)
	: Triangle(newbase, newheight){
	cout << "Equilateral Triangle created.\n\n";
}

double Equilateral::getePerimeter() const{
	return getBase() * 3;
}
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/equilateral.h <==
#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include "Triangle.h"
#include <iostream>
using namespace std;

class Equilateral : virtual public Triangle{
public:
	//default constructor
	Equilateral();

	//overloaded constructor
	Equilateral(double, double);
	//Equilateral - creates triangle with parameters of side length & height
	//@param double - side length to be set
	//@param double - height to be set

	double getePerimeter() const;
};

#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/externalfunctions.cpp <==
#include "externalfunctions.h"

vector<TriangleV> newTriangles;

static int counter = 0;

void mainScreen(){
	int choice;
	do{
		cout << "What type of triangle would you like to create ?\n\n";
		cout << "1: Scalene\n2: Equilateral\n3: Isoceles\n4: Print Set\n5: Exit\n";
		cout << "\nPlease enter your option : ";
		cin >> choice;
		if (choice < 1 || choice > 5){
			cout << "\nPlease choose a valid option\n\n";
		}
	} while (choice < 1 || choice > 5);

	switch (choice){
	case 1: setScalene(newTriangles); break;
	case 2: setEquilateral(newTriangles); break;
	case 3: setIsoceles(newTriangles); break;
	case 4: printSet(newTriangles); break;
	case 5: cout << "\nThank you for using this program\n\n";
	}
}

void setScalene(vector<TriangleV>& newTriangles){
	double base, height, side1, side2, test, calcS1, calcS2;
	int choice;
	do{
		cout << "\nPlease enter the base in cm : ";
		cin >> base;
		cout << "Please enter side1 in cm : ";
		cin >> side1;
		cout << "Please enter side2 in cm : ";
		cin >> side2;
		cout << "Please enter height in cm : ";
		cin >> height;

		calcS2 = sqrt(side2*side2 - height*height);
		calcS1 = sqrt(side1*side1 - height*height);

		if ((height == side1)&&(height < side2)) {
			test = base - calcS2;
		}
		else if ((height == side2)&&(height < side1)){
			test = base - calcS1;
		}
		else if ((height > side1) || (height > side2)){
			test = 2;
		}
		else if ((side1 > side2) && (calcS1 > base)){
			test = base + calcS2 - calcS1;
		}
		else if ((side2 > side1) && (calcS2 > base)){
			test = base + calcS1 - calcS2;
		}
		else{
			test =
				base - calcS1 - calcS2;
		}

		do{
			if ((test > 0.1) || (test < -0.1)){
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			}
			else {
				choice = 2;
				cout << "\nNow creating triangle...\n";
			}
		} while ((choice < 1) || (choice > 2));
	} while (((test > 0.1) || (test < -0.1)) && (choice == 1));

	if ((test <= 0.1) && (test >= -0.1)){
		TriangleV newScalene(base, side1, side2, height);
		counter++; cout << "counter = " << counter;
		newTriangles.push_back(newScalene);
		cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
		cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
		cout << "Perimeter : " << newTriangles[counter-1].getsPerimeter() << "\n\n";
		cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	}
	mainScreen();
}

void setEquilateral(vector<TriangleV>& newTriangles){
	double side, height;
	cout << "Please enter the length of a side in cm : ";
	cin >> side;

	height = sqrt(side*side - 0.25*side*side);
	TriangleV newEquilateral(side, height);
	counter++;
	newTriangles.push_back(newEquilateral);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getePerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void setIsoceles(vector<TriangleV>& newTriangles){
	double base, side, height;
	int choice;
	do{
		cout << "Please enter the length of your base in cm : ";
		cin >> base;
		cout << "Please enter a side length in cm : ";
		cin >> side;
		if (side <= 0.5*base){
			do {
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			} while ((choice < 1) || (choice > 2));
		}
	} while (side <= 0.5*base);


	height = sqrt(side*side - 0.25*base*base);
	TriangleV newIsoceles(base, side, height);
	counter++;
	newTriangles.push_back(newIsoceles);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getiPerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void printSet(const vector<TriangleV>& newTriangles){
	unsigned int size = newTriangles.size();
	if (size == 0){
		cout << "\nThere are no triangles in this array\n";
	}
	else{
		cout << "\n";
		for (unsigned int i = 0; i < size; i++){
			cout << "Triangle " << i + 1 << "\n";
			cout << "Height : " << newTriangles[i].getHeight() << "\n";
			cout << "Base : " << newTriangles[i].getBase() << "\n";
			cout << "Perimeter : " << newTriangles[i].getsPerimeter() << "\n";
			cout << "Area : " << newTriangles[i].getArea() << "\n";
		}
	}
	mainScreen();
}
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/externalfunctions.h <==
#ifndef EXTERNALFUNCTIONS_H
#define EXTERNALFUNCTIONS_H

#include <iostream>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "vector.h"

using namespace std;

void mainScreen();
void setScalene(vector<TriangleV>&);
void setEquilateral(vector<TriangleV>&);
void setIsoceles(vector<TriangleV>&);
void printSet(const vector<TriangleV>&);

#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/isoceles.cpp <==
#include "isoceles.h"

Isoceles::Isoceles(){}

Isoceles::Isoceles(double newBase, double newequalSide, double newHeight) 
	: Triangle(newBase, newHeight){
	equalside = newequalSide;
	cout << "Isoceles Triangle created.\n\n";
}

double Isoceles::getiPerimeter() const{
	return getBase() + equalside * 2;
}



==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/isoceles.h <==
#ifndef ISOCELES_H
#define ISOCELES_H

#include <iostream>
#include "triangle.h"
using namespace std;

class Isoceles : virtual public Triangle{
private:
	//member variables
	double equalside;
public:
	//default constructor
	Isoceles();

	Isoceles(double base, double equalside, double height);
	//Isoceles - creates Isoceles triangle with base, height, and equal side
	//@param double - base to be set 
	//@param double - equal sides to be set
	//@param double - height to be set

	virtual double getiPerimeter() const;
	//getPerimeter - returns Perimeter of triangle
	//@param double - base to be used in calculation
	//@param double - equal sides to be used in calculation
	//@return double - perimeter to be returned 

};

#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/main.cpp <==
#include <iostream>
#include <vector>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "externalfunctions.h"

using namespace std;

int main(){
	
	mainScreen();

	return 0;
}


==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/scalene.cpp <==
#include "scalene.h"

Scalene::Scalene(){}

Scalene::Scalene(double ibase, double newSide1, double newSide2, double height)
	: Triangle(ibase, height){
	base = ibase;
	side1 = newSide1;
	side2 = newSide2;
	cout << "Scalene Triangle created.\n\n";
}

double Scalene::getsPerimeter() const{
	return side1 + side2 + base;
}


==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/scalene.h <==
#ifndef SCALENE_H
#define SCALENE_H

#include "triangle.h"
#include <iostream>
using namespace std;

class Scalene : virtual public Triangle{
private:
	//member variables
	double base, side1, side2;
public:
	//default constructor
	Scalene();

	//overloaded constructor
	Scalene(double base, double side1, double side2, double height);
	//Scalene - creates Scalene object with base, side1, side2 and height

	virtual double getsPerimeter() const;
};

#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/triangle.cpp <==
#include "triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(double newBase, double newHeight){
	base = newBase;
	height = newHeight;
}

double Triangle::getHeight() const{
	return height;
}

double Triangle::getBase() const{
	return base;
}

void Triangle::setHeight(double newHeight){
	height = newHeight;
}

void Triangle::setBase(double ibase){
	base = ibase;
}

double Triangle::getArea() const{
	return 0.5 * height * base;
}
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/triangle.h <==
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
using namespace std;

class Triangle{
private:
	//member variables
	double height;
	double base;

public:
	//default constructor
	Triangle();

	//overloaded constructor
	Triangle(double, double);
	//Triangle - creates triangle with parameter of height
	//@param int - height to be set

	double Triangle::getBase() const;

	//Mutator function
	void setHeight(double);
	//setHeight - sets the triangle's height
	//@param int - height to be set

	//Mutator function
	void setBase(double);
	//setBase - sets the triangle's base length
	//@param int - base length to be set

	//Accessor function
	double getHeight() const;
	//getHeight - returns the triasngle's height
	//@return int - height to be returned

	double getArea() const;
	//getArea - returns the area of the triangle
	//@param int - base to be used in calculation
	//@return int - area to be returned


};

#endif
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/Vector.cpp <==
#include "vector.h"

TriangleV::TriangleV(){}

TriangleV::TriangleV(double ibase, double iside1, double iside2, double iheight)
	: Scalene(ibase, iside1, iside2, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double isides, double iheight)
	: Isoceles(ibase, isides, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double iheight)
	: Equilateral(ibase , iheight){
	setBase(ibase);
	setHeight(iheight);
}
	
==> ./Projects/137 using namespaces/Triangultion program/c++ 24 inheritance/vector.h <==
#ifndef TRIANGLEV_H
#define TRIANGLEV_H

#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include <vector>

class TriangleV : virtual public Isoceles, virtual public Equilateral, virtual public Scalene{
public:
	//default constructor
	TriangleV();

	//overloaded Scalene constructor
	TriangleV(double base, double side1, double side2, double height);

	//overloaded Isoceles constructor
	TriangleV(double base, double sides, double height);

	//overloaded Equilateral constructor
	TriangleV(double base, double height);

};



#endif
==> ./Projects/138 nested namespaces/138 nested namespaces/Source.cpp <==
#include <iostream>

using namespace std;

namespace one{
	int i;
	namespace two{
		int k; //namespace can be nested
	}
	inline namespace three{
		int l; //members can be accessed directly from umbrella namespace if inline
	}
}

namespace one{
	int j;
} //same namespace can be declared multiple times across different files and all
//declared members will be members of that namespace 

int main(){
	one::i = 10;
	one::j = 20;
	one::two::k = 30;
	one::l = 40; //inline function

	using namespace one;
	using namespace two;
	
	cout << "i = " << i << "\nj = " << j << "\nk = " << k << endl;

	return 0;
}
==> ./Projects/25++ pointer logic/25++ pointer logic/main.cpp <==
#include <iostream>

using namespace std;

int main(){
	int num1 = 15;
	int num2 = 45;

	//two integer pointers for storing memory addresses of integer variables
	//pointer can be initialised in one of two ways
	int *p1 = &num1; //(1)
	int *p2; 
	p2 = &num2; //(2)

	cout << "Values of two integer variables\n";
	cout << "num1 = " << num1 << "\t\tnum2 = " << num2 << endl;
	
	cout << "\nValues contained in memory addresses stored in pointers\n";
	cout << "*p1 = " << *p1 << "\t\t*p2 = " << *p2 << endl;

	cout << "\nMemory addresses of two integer variables\n";
	cout << "&num1 = " << &num1 << "\t&num2 = " << &num2 << endl;

	cout << "\nMemory addresses stored in pointers\n";
	cout << "p1 = " << p1 << "\t\tp2 = " << p2 << endl;
	
	cout << "\nMemory addresses of pointers\n";
	cout << "&p1 = " << &p1 << "\t\t&p2 = " << &p2 << endl;
	
	p1 = p2;

	cout << "\nIf p1 = p2\n";
	cout << "\nValues of two integer variables\n";
	cout << "num1 = " << num1 << "\t\tnum2 = " << num2 << endl;

	cout << "\nValues contained in memory addresses stored in pointers\n";
	cout << "*p1 = " << *p1 << "\t\t*p2 = " << *p2 << endl;

	cout << "\nMemory addresses of two integer variables\n";
	cout << "&num1 = " << &num1 << "\t&num2 = " << &num2 << endl;

	cout << "\nMemory addresses stored in pointers\n";
	cout << "p1 = " << p1 << "\t\tp2 = " << p2 << endl;

	cout << "\nMemory addresses of pointers\n";
	cout << "&p1 = " << &p1 << "\t\t&p2 = " << &p2 << endl;

	p1 = &num1;
	*p1 = *p2;
	cout << "\nIf *p1 = *p2\n";
	cout << "\nValues of two integer variables\n";
	cout << "num1 = " << num1 << "\t\tnum2 = " << num2 << endl;

	cout << "\nValues contained in memory addresses stored in pointers\n";
	cout << "*p1 = " << *p1 << "\t\t*p2 = " << *p2 << endl;

	cout << "\nMemory addresses of two integer variables\n";
	cout << "&num1 = " << &num1 << "\t&num2 = " << &num2 << endl;

	cout << "\nMemory addresses stored in pointers\n";
	cout << "p1 = " << p1 << "\t\tp2 = " << p2 << endl;

	cout << "\nMemory addresses of pointers\n";
	cout << "&p1 = " << &p1 << "\t\t&p2 = " << &p2 << endl << endl;
	return 0;
}
==> ./Projects/2d array to function (c code)/2d array to function (c code)/Source.c <==
/*When passing multi-dimensional array to function we need to declare the size of all dimensions, except thje first
In the case of a 2d array we must declare the number of elements in each row*/

#include <stdio.h>

//2d array, followed by two int variables repesenting no. oof  rows and no. of clumns
void display(int[][10], int, int); 

main()
{
	int numb[10][10];
	int i, j, no_row, no_col;

	printf("How many rows and colums do you wish to generate : ");
	scanf("%d %d", &no_row, &no_col);

	for (i = 0; i < no_row; i++)
	{
		for (j = 0; j < no_col; j++)
		{
			printf("\nPlease enter element[%d][%d] : ", i, j);
			scanf("%d", &numb[i][j]);
		}
	}

	display(numb, no_row, no_col);
}

void display(int numb2d[][10], int row, int column)
{
	int sum, i, j;
	sum = 0;
	putchar('\n');
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
			printf("%3d", numb2d[i][j]);
		putchar('\n');
	}
	printf("\n");
}
==> ./Projects/2d rotation matrix/2d rotation matrix/Source.c <==
#include <stdio.h>
#include <math.h>

void rotate2d(float x, float y, float theta);

main()
{
	float x, y, theta;
	int answer;

	printf("Please enter your value for x co-ordinates : ");
	scanf("%f", &x);
	printf("\nPlease enter your value for y co-ordinates : ");
	scanf("%f", &y);
	do
	{
		printf("\nWould you like to rotate clockwise or anti-clockwise?");
		printf("\n\nOption 1: Clockwise    Option 2: Anti-clockwise\n\nPlease enter your choice (1 or 2) : ");
		scanf("%d", &answer);
		if ((answer < 1) || (answer > 2))
			printf("\nPlease choose either option 1 or 2\n");
	} while ((answer < 1) || (answer > 2));
	printf("\nPlease enter your value for the angle of rotation (in degrees) : ");
	scanf("%f", &theta);

	theta = theta / (180 / 3.14159);

	rotate2d(x, y, theta, answer);

}

void rotate2d(float x, float y, float theta, int answer)
{
	float rotmatrix[2][2] = { cos(theta), -(sin(theta)), sin(theta), cos(theta) };
	
	float x1, y1;

	if (answer == 2)
	{
		x1 = x * rotmatrix[0][0] + y * rotmatrix[0][1];
		y1 = x * rotmatrix[1][0] + y * rotmatrix[1][1];
	}
	else
	{
		x1 = x * rotmatrix[0][0] + y * rotmatrix[1][0];
		y1 = x * rotmatrix[0][1] + y * rotmatrix[1][1];
	}

	printf("\nx' = %2.2f\ny' = %2.2f\n\n", x1, y1);
}
==> ./Projects/3d rotation matrix/3d rotation matrix/Source.c <==
#include <stdio.h>
#include <math.h>

void rot3dmatrix(float x, float y, float z, int choice, float theta);

main()
{
	float x, y, z, theta;
	int choice, choice1;
	
	do
	{
		printf("Select the axis about which you would like to carry out your rotation : ");
		printf("\n\n*Option 1: x-axis*   *Option 2: y-axis*   *Option 3: z-axis*");
		printf("\n\nPlease enter your choice (1, 2 or 3) : ");
		scanf("%d", &choice);
		if ((choice < 1) || (choice > 3))
			printf("\nInvalid choice. Please choose option 1, 2 or 3\n\n");
	} while ((choice < 1) || (choice > 3));

	printf("\nPlease enter the x co-ordinate : ");
	scanf("%f", &x); 
	printf("\nPlease enter the y co-ordinate : ");
	scanf("%f", &y);
	printf("\nPlease enter the z co-ordinate : ");
	scanf("%f", &z);
	do
	{
		printf("\nWould you like to rotate clockwise or anti-clockwise : ");
		printf("\n\n*Option 1: Clockwise*    *Option 2: Anti-clockwise*");
		printf("\n\nPlease enter your choice (1 or 2) : ");
		scanf("%d", &choice1);
		if ((choice1 < 1) || (choice1 > 2))
			printf("\nInvalid choice. Please choose option 1 or 2\n\n");
	} while ((choice1 < 1) || (choice1 > 2));

	printf("\nPlease enter the angle you would like to rotate by (in degrees) : ");
	scanf("%f", &theta);
	if (choice1 == 1)
		theta = 360 - theta;
	theta = theta / (180 / 3.14159);
	rot3dmatrix(x, y, z, choice, theta);
}

void rot3dmatrix(float x, float y, float z, int choice, float theta)
{
	float A = sin(theta), B = cos(theta);
	if (choice == 1)
	{
		float matrix3d[3][3] = { 1, 0, 0, 0, B, -A, 0, A, B };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
	}
	else if (choice == 2)
	{
		float matrix3d[3][3] = { B, 0, A, 0, 1, 0, -A, 0, B };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
	}
	else if (choice == 3)
	{
		float matrix3d[3][3] = { B, -A, 0, A, B, 0, 0, 0, 1 };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
	}
}
==> ./Projects/a03 logic constness bitwise constness/a03 logic constness bitwise constness/Source.cpp <==
#include <iostream>
#include <vector>

using namespace std;

class BigArray{
	vector<int> v; //huge vector large memory space
	mutable int accessCounter;
	int demonumber2;

	int* v2;  //another large int array
public:
	/*as v is the primary data concerned with, v is not changed so logic is const, 
	const is used as makes function faster. however counter is not const, therefore 
	'mutable' keyword used to allow use in const function*/
	
	int getItem(int index) const{
		accessCounter++; //mutable
		const_cast<BigArray*>(this)->demonumber2++; //const_cast last resort
		return v[index];
	}

	const int* const fun(const int* const x) const;
	//returns const int with const memory address
	//uses const int with const memory address
	//const function, display and return function
	//function prototype

	void setV2Item(int index, int x){
		*(v2 + index) = x;
	}
	/*even though setting value in large array can be defined as inst. Though
	none of variables have been changed directly, not logic -wise a const*/
};


const int* const fun(const int* const x); //function ok outside
//const int* const fun(const int* const x) const; - cannot use type qualifier

int main(){
	BigArray b;
}
==> ./Projects/a04 compiler generated functions/a04 compiler generated functions/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

/*
Compiler silently writes 4 functions if not explicitly declared
1. Copy constructor
2. CopyAssignment Operator (= operator overload)
3. Destructor
4. Default constructor
*/

//class dog{};

/*equivalent to*/ 

/*class dog{
public:
	dog(const dog& rhs){  }; //Member by member initialization (1)

	dog& operator=(const dog& rhs){ }; // Member by member copying (2)

	dog() { }; // 1. Call base class's default constructor; (3)
			   // 2. Call data member's default constructor

	~dog() { }; //1. Call base class's destructor; (4)
				//2. Call data member's destructor;
};*/

/*if any of these cannot be generated i.e. const, or reference for copy assignment
Compiler will not generate the function.

1. They are public and inline.
2. They are generated only if they are needed.
*/ 

class Dog{
public:
	string m_name;

	Dog(string name = "Bob") { m_name = name; cout << name << " is born.\n"; }
	~Dog() { cout << m_name << " is destroyed\n"; }
};

int main(){
	Dog dog1("Henry"); //(4)
	Dog dog2;
	dog2 = dog1; //(2)
	Dog dog3(dog2); //(1)
	return 0; //(3)

	//1. Copy constructor - Used (Auto)
	//2. CopyAssignment Operator(= operator overload) - Used (auto)
	//3. Destructor - User defined
	//4. Default constructor - User defined
}

/*default constructor for doggy will not work as will call up default constructor 
for data member collar which requires an input variable of type std::string*/

class collar{
public:
	collar(string colour){ cout << "collar is born \n"; }
	string &name; /* m_name would be constucted but not initialized, which violates 
c++ standard and the code won't run. Class reference variables must be initialized*/
};


class doggy{
	doggy() = default; //way to use default constructor and overload it
	collar m_collar;
};
==> ./Projects/a05 Disallow function/a05 Disallow function/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

/* Compiler silently wries 4 functions if not written
1. Copy Constructor
2. Copys Assignment operator
3. Default Constructor
4. Default Destructor - these functions ccan sometimes be generated*/

class OpenFile{
};

class OpenFile1{
public:
	OpenFile1(string filename) { cout << "Open a file" << endl; }
	OpenFile1(OpenFile1 &rhs) = delete; 
	//stops copy constructor being generated by the compiler
};

class OpenFile2{
public:
	//g(OpenFile2 &f) {OpenFile2 f2(f);}
	OpenFile2(){
		cout << "hello\n";
	}
	void destroyMe(){delete this;}
private:
/*declaring but not defining copy constructor as a private member stops it being
generated by the compiler - the same with all compiler genrated functions. Always
fail because functions are declared and not defined, even inside class*/
	OpenFile2(OpenFile &rhs); //(1)		
	OpenFile2 & operator=(const OpenFile &rhs); //(2)
	//body should always be declard for destructor or build will fail
	~OpenFile2(){ cout << "File is destroyed\n"; }
};

int main(){
	OpenFile f; //default constructor called
	//Openfile1 f1; //default consructor not generated - useless not harmful
	
	OpenFile1 f1(string("hello"));
	//OpenFile1 f2(f1); - Copy constructor would allow 2 to write to same file

	//OpenFile2 f2; 
	//f2.destroyMe();
/*destructor is private won't compile. f2 stored on stack as it is on scope main.
when stack unwinds will be destructed, but destructor can't be called as its private.
destroyMe() function won't work as still on stack, private destructor still called*/

	OpenFile2 *f3 = new OpenFile2();
	f3->destroyMe();
/*therefore class with private destructor can only be stored on the heap, not on the
stack. In embedded programming stack size is small and can result in overflow.
So large classes better to store on heap. private destructor ensures only can be
stored on heap - nead to define destructor function with void fun{delete this:}*/

	return 0;
}

==> ./Projects/a06 virtual smart destructor/a06 virtual smart destructor/Source.cpp <==
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class MDog{
public:
	~MDog() { cout << "MDog destroyed" << endl; }
	/*function not virtual so classes inheriting destructor won't be called when 
	value assigned to pointer of base class type - not good!*/
};

class DDog{
public:
	virtual ~DDog() { cout << "DDog destroyed" << endl; }
	//function virtual so inheritred class destructor will run first.
};

class CDog{
public:
	~CDog() { cout << "CDog destroyed" << endl; }
};

class Yellowdog : public MDog{
public:
	~Yellowdog() { cout << "\nYellow dog destroyed" << endl; } // destructor not called 
};

class yellowdog: public DDog{
public:
	~yellowdog() { cout << "\nyellow dog destroyed" << endl; }
};

class yellodog : public CDog{
public:
	~yellodog() { cout << "\nyello dog destroyed" << endl; }
};

class DogFactory{
public:
	static MDog* createYellowDog() { return (new Yellowdog()); }
	static DDog* createyellowDog() { return (new yellowdog()); }
	static shared_ptr<CDog> createyellodog(){
		return shared_ptr < yellodog > (new yellodog());
		}
};

int main(){
	MDog *heapdog = DogFactory::createYellowDog(); //Yellowdog destructor not called
	DDog *hotdog = DogFactory::createyellowDog(); //yellowdog destructor called
	shared_ptr<CDog> memdog = DogFactory::createyellodog(); 
	//requires <memory> header. doesn't require delete  afterwards
	delete hotdog;
	delete heapdog;
	return 0;
}

/*if classes intended to be used polymorphically, use virtual destructor to ensure 
inherited class destructor is invoked. any virtual functions mean class will be used
polymorphically and wiill require virtual destructor*/

==> ./Projects/a07 Exceptions in Destructors/a07 Exceptions in Destructors/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Dog{
public:
	string name;
	Dog(string name){
		this->name = name;
		cout << this->name << " has been created\n";
	}
	~Dog() { cout << name << " is destroyed\n"; //throw 20; 
	} //program will not executed if exceptyion is thrown in destructor - Problem!
	void bark(){ cout << name << " barks\n"; }
};

class Dog1{
public:
	string name;
	Dog1(string name){
		this->name = name;
		cout << this->name << " has been created\n";
	}
	//Solution 1: Destructor swallows the exception
	~Dog1() {
		try {
			cout << name << " is destroyed\n";
			throw 20;
		}
		catch (int e){
			cout << e << " has been caught\n";
		}
		catch (...){
			cout << "Exception has occured\n";
		}//2nd catch will not specify type of exception
		//in all cases dog's client will not be aware exception has occured
	} 
	void bark(){ cout << name << " barks\n"; }
};

class Dog2{
public:
	string name;
	Dog2(string name){
		this->name = name;
		cout << this->name << " has been created\n";
	}
	//Solution 2 Move exception prone code to a different function
	void preDestroy(){
		try{
			cout << "pre-destruction code\n";
			throw 20;
		}
		catch (int e){
			cout << e << " has been caught\n";
		} // client becomes aware of error - more API needed
	}
	~Dog2() {
		cout << name << " is destroyed\n";  
	} 
	void bark(){ cout << name << " barks\n"; }
};

int main(){
	try{
		Dog dog1("henry");
		Dog dog2("Bob");
		throw 20;
		dog1.bark();
		dog2.bark();
	}
	catch (int e){
		cout << e << " is caught" << endl;
	}

	Dog1 dog1("steve");
	Dog1 dog2("mike");

	Dog2 doggy1("fred");
	Dog2 doggy2("michelle");
	doggy1.preDestroy();
	doggy2.preDestroy();
	//exception will be caught after stack has unwound, and dog1 and dog2 have been destroyed 
	return 0;
}

==> ./Projects/a08 virtual funct constructor-destructor/a08 virtual funct constructor-destructor/Source.cpp <==

==> ./Projects/add 2 vectors/add 2 vectors/Source.cpp <==
//Addvectors.cpp

#include <iostream>
#include <iomanip>
#define N 4

using namespace std;
double A[N] = { 1, 2, 3, 4 };
double B[N] = { 10, 11 };
double C[N];

int main(){
	for (int ind = 0; ind < N; ind++)
		C[ind] = A[ind] + B[ind];
	for (int ind = 0; ind < N; ind++){
		cout << "A[" << ind << "]=" << setw(5) << A[ind] << '\t';
		cout << "B[" << ind << "]=" << setw(5) << B[ind] << '\t';
		cout << "C[" << ind << "]=" << setw(5) << C[ind] << '\n';
	}
}
==> ./Projects/Add matrices/Add matrices/Source.cpp <==
#include <iostream>
#include <iomanip>
#define N_row 2
#define N_col 4 
using namespace std;

double A[N_row][N_col] = { 1, 2, 3, 4, 5, 6, 7, 8 };

double B[N_row][N_col] = { -2, 3, 3, 4, 10, 11, 12, 20 };

double C[N_row][N_col];

int main(){
	int n, k;
	double D[3][4];
	cout << "C=\n";
	for (n = 0; n < N_row; n++){
		for (k = 0; k < N_col; k++){
			C[n][k] = A[n][k] + B[n][k];
			cout << setw(6) << C[n][k];
		}
		cout << endl;
	}
}


==> ./Projects/AddSub/AddSub/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	char OperatorCode;
	int value1, value2, answer;

	cout << "Input a letter and two integer values." << endl;
	cout << "If the letter is an A, the values are added." << endl;
	cout << "If the letter is an S," << " the second value is subtracted from the first." << endl;
	cin >> OperatorCode;
	cin >> value1 >> value2;

	if (OperatorCode == 'A'){
		answer = value1 + value2;
		cout << value1 << " plus " << value2 << " is " << answer << endl;
	}
	else{
		answer = value1 - value2;
		cout << value1 << " minus " << value2 << " is " << answer << endl;
	}
	return 0;
}
==> ./Projects/adjoint of matrix (3x3)/adjoint of matrix (3x3)/Source.c <==
#include <stdio.h>

void swap(int *a, int *b);
void permuteB(int *A, int *B, int l, int r, int **matrix);
void permuteA(int *A, int *B, int l, int r, int **matrix);
void creatematrix();
void createadjoint(int val, int *B, int count);
void inversematrix(int **matrix);

int count = 0;
int x, y;
int Adj[3][3];

main()
{
	creatematrix();
}

void swap(int * a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permuteB(int *A, int *B, int l, int r, int **matrix)
{
	int i;
	if (l == r)
	{
		int val = matrix[B[1]][A[1]] * matrix[B[2]][A[2]];;
		int coordinates[] = { A[0], B[0] };
		count++;
		createadjoint(val, coordinates, count);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			if ((l == 0) && (i == 1))
				break;
			else if (((A[0] == 0) && (A[1] == 2) && (l == 0)) || 
				((A[0] == 1) && (A[1] == 2) && (l == 0)) ||
				((A[0] == 2) && (A[1] == 0) && (l == 0)))
				i = 2;
			swap((B + l), (B + i));
			permuteB(A, B, (l + 1), 2, matrix);
			swap((B + 1), (B + i));
		}
	}
}

void permuteA(int *A, int *B, int l, int r, int **matrix)
{
	int i;
	if (l == r)
		l = r;
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((A + l), (A + i));
			if (l == 0)
			{
				B[0] = 0; B[1] = 1; B[2] = 2;
			}
			permuteB(A, B, 0, 2, matrix);
			permuteA(A, B, (l + 1), 2, matrix);
			swap((A + l), (A + i));
		}
	}
}

void creatematrix()
{
	int **matrix1;

	matrix1 = malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++)
		matrix1[i] = malloc(3 * sizeof(int));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("[%d][%d] = ", i, j);
			scanf("%d", &matrix1[i][j]);
		}
	}

	int A[] = { 0, 1, 2 };
	int B[] = { 0, 1, 2 };

	permuteA(A, B, 0, 2, matrix1, Adj);

	printf("\nAdjoint of matrix is :\n\n");
	
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
			printf("%4d", Adj[j][k]);
		printf("\n");
	}

	inversematrix(matrix1);
}

void createadjoint(int val, int *B, int count)
{	
	int a;
	if (count % 2)
		x = val;
	else
	{
		y = val;
		int r = 2 + B[0] + B[1];
		if (B[0] == 2)
		{
			if (r % 2)
				a = 1;
			else
				a = -1;
		}
		else
		{
			if (r % 2)
				a = -1;
			else
				a = 1;
		}
		Adj[B[0]][B[1]] = a * (x - y);
	}
}

void inversematrix(int **matrix)
{
	int det = 0; int inv[3][3];
	for (int i = 0; i < 3; i++)
	{
		det = det + (Adj[i][0] * matrix[0][i]);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inv[i][j] = Adj[i][j] / det;
		}
	}

	printf("\nInverse of matrix is :\n\n");
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%4d", inv[i][j]);
		printf("\n");
	}
}
==> ./Projects/animal database/animal database/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

struct AnimalType
{	long	id;
	string	name;
	string	genus;
	string	species;
	string	country;
	int		age;
	float	weight;
};

AnimalType Animal1;
AnimalType Animal2;
AnimalType BiggestAnimal;

void WriteOutRec(AnimalType A);
void ChangeAge(AnimalType &A);
AnimalType GetAnimalData();
AnimalType Biggest(AnimalType A, AnimalType B);

int main()
{	Animal1.age = 18;
	Animal1.id = 2037581;
	Animal1.genus = "Ailuropoda";
	Animal1.country = "China";
	cout << "Please enter Animal 1's weight (kg): ";
	cin >> Animal1.weight;
	cout << "\nPlease enter Animal 1's species : ";
	getline(cin, Animal1.species); getline(cin, Animal1.species);
	Animal1.name = "Giant Panda";
	Animal1.age++;
	//struct variables work like normal, but have more complicated identifiers
	
	/*Aggregate operation is an operation on a data structure as a whole
	
	Aggregate struct operations allowed include:
	-Assignment to another struct variable of same type: Animal1 = Animal2
	-Pass to a function as an argument (by value or reference)
	-Return as value of a function*/

	WriteOutRec(Animal1);
	ChangeAge(Animal1);
	Animal2 = GetAnimalData();
	BiggestAnimal = Biggest(Animal1, Animal2);
	cout << "\nThe Biggest Animal is " << BiggestAnimal.name << endl << endl;
	return 0;
}

void WriteOutRec(AnimalType A)
{	cout << "\nID # " << A.id << endl;
	cout << A.name << endl;
	cout << A.genus << endl;
	cout << A.species << endl;
	cout << A.country << endl;
	cout << A.age << " years\n";
	cout << A.weight << " lbs.\n";
}

//Pass a struct type by Reference

void ChangeAge(AnimalType &A)
{	A.age++;	}

AnimalType GetAnimalData()
{	AnimalType thisAnimal; //local variable
	cout << "\nEnter id please : ";
	cin >> thisAnimal.id;
	cout << "Enter name please : ";
	getline(cin, thisAnimal.name); getline(cin, thisAnimal.name);
	cout << "Enter genus please : ";
	getline(cin, thisAnimal.genus);
	cout << "Enter species please : ";
	getline(cin, thisAnimal.species);
	cout << "Enter country please : ";
	getline(cin, thisAnimal.country);
	cout << "Enter age please : ";
	cin >> thisAnimal.age;
	cout << "Enter weight please : ";
	cin >> thisAnimal.weight;
	return thisAnimal;
}

AnimalType Biggest(AnimalType A, AnimalType B)
{
	if (A.weight > B.weight)
		return A;
	else
	
==> ./Projects/anum/anum/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int anum;

	cout << "Enter a number, or press 9999 to end: ";
	cin >> anum;
	while (anum != 9999){
		cout << "Square is " << anum*anum << endl;
		cout << "Cube is " << anum*anum*anum << endl;
		//cout << "Enter a number, or press 9999 to end: ";
		//cin >> anum;
		//missing line
	}
	return 0;
}
==> ./Projects/area-circumference/area-circumference/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	float r, area, circumference;
	const float Pi = 3.14159;

	cout << "Please enter a value for the radius : ";
	cin >> r;
	cout << " \n";

	circumference = 2 * Pi * r;
	area = Pi * r * r;

	cout << "Circumference of the circle is : " << circumference << endl;
	cout << " \n";
	cout << "Area of the circle is : " << area << endl;
	cout << " \n";
	return 0;
}
==> ./Projects/array/array/Source.cpp <==
#include <iostream>

using namespace std;

#define MaxNumber 100
#define MinHeight 140
#define MaxHeight 230

int main(){
	unsigned height[MaxNumber], NoStudents, Tallest(0), n;
	do
	{
		cout << "Enter the number of students N = "; cin >> NoStudents;
	} while (NoStudents > MaxNumber);
	for (n = 0; n < NoStudents; n++){
		do{
			cout << "Enter the height of student no " << n + 1 << endl;
			cin >> height[n];
		} while (height[n] < MinHeight || height[n] > MaxHeight);
	}
	for (n = 0; n < NoStudents; n++){
		Tallest = Tallest < height[n] ? height[n] : Tallest;
	}
	cout << "\nThe tallest student is " << Tallest << " cm tall\n";
	return 0;
}

==> ./Projects/arrays and pointers/arrays and pointers/Source.cpp <==
//the name of an array can be treated in the same way as a constant pointer

#include <iostream>
#include <iomanip>

using namespace std;

double A[] = { 100, 200, 300, 400, 500, 600, 700 };

int main(){
	sizeof(A); //sizeof operator returns the size of the object in bytes;
	int const N = sizeof(A) / sizeof(A[0]); 
	for (int k = 0; k < N; k++){
		cout << *(A + k) << endl;
	}
	return 0;
}
==> ./Projects/arrays as parameters/arrays as parameters/Source.cpp <==
#include <iostream>

using namespace std;

void inputScores(int[], int&);
//creates array of student scores
//@param int[] - array for holdig student scores
//@param int& - number of elements in array

void printScores(const int[], int);
//prints array of student scores
//@param int[] - array of student scores
//@param int - number of elements in array

const int CAPACITY = 39;
//maximum number of students in class

int main(){
	int studentscores[CAPACITY];
	int noOfStudents = 0;

	inputScores(studentscores, noOfStudents);
	printScores(studentscores, noOfStudents);

	return 0;
}

void inputScores(int stscores[], int& noOfElements){
	int i = 0;
	cout << "Please enter students score (input -1 to stop) : ";
	cin >> stscores[i];

	while ((i <= CAPACITY) && (stscores[i] != -1)){
		cout << endl;
		noOfElements++;
		i++;
		cout << "Please enter students score (input -1 to stop) : ";
		cin >> stscores[i];
	}
}

void printScores(const int stscores[], int noOfStudents){
	for (int i = 0; i < noOfStudents; i++){
		cout << stscores[i] << " ";
	}
}
==> ./Projects/arrays of pointers (c code)/arrays of pointers (c code)/Source.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char *ptr[2]; //declare array which will hold 2 elements, each element will be a pointer
	ptr[0] = (char*)malloc(6); //malloc allocates 6-byte length address to 1st element of array	
	ptr[1] = (char*)malloc(4); //malloc allocates 4-byte length address to 2nd element of array
	
	strcpy(ptr[0], "hello"); //allocate string "hello" to base address stored in ptr[0]
	strcpy(ptr[1], "bye"); //allocate string bye to base address stored in ptr[1]
	
	/*4 lines of code above ca be replaced with 
	ptr[0] = "hello";
	ptr[1] = "bye";*/

	printf("%s\n", ptr[0]); //print string from address found at ptr[0]
	
	printf("%p\t %p\n", ptr, &ptr[0]); //print base address of array ptr, print address of ptr[0]

	printf("%p\t %c\n", ptr[0], *ptr[0]); //print address stored in ptr[0], print character stired in ptr[0] 
	
	printf("%p\t %c\n", ptr[0] + 1, *(ptr[0] + 1)); //print address stored in first element of array + 1 char
	//print character stored at 1st element of array + 1 char

	printf("%p\n", &ptr[1]); //print address of ptr[1]

	printf("%p\n", ptr[1]); //print address stored at ptr[1]
	
	printf("%c\n", *(ptr[1]+1)); //print char stored at ptr[1] + 1 char
	return;
}
==> ./Projects/arrays of pointers/arrays of pointers/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

char* pstr[] =
{
	"Robert Redford\n\n",
	"Hopalong Cassidy\n\n",
	"Lassie\n\n",
	"Slim Pickens\n\n",
	"Boris Karloff\n\n",
	"Oliver Hardy\n\n"
};

char* txt1 = "Pick a lucky star! Enter a number between 1 and 6: ";
char* txt2 = "Your lucky star is ";
char* txt3 = "You failed to choose a number between 1 and 6\n";

int dice(0);
int main(){
	for (int n = 0; n < 3; n++){
		cout << txt1;
		cin >> dice;
		if (dice >= 1 && dice <= 6){
			cout << txt2 << pstr[dice - 1];
			return 0;
		}
	}
	cout << txt3;
	return 0;
}

==> ./Projects/Arrays of struct/Arrays of struct/Source.cpp <==
#include <iostream>

using namespace std;

struct Address{
	char StreetName[20];
	unsigned Housenumber;
	char town[10];
	char postcode[10];
};

struct a_Person{
	char Firstname[10];
	char Surname[15];
	unsigned age;
	unsigned height;
	unsigned weight;
	bool Employed;
	Address Postaddress;
};

a_Person People[10];

int main(){
	strcpy_s(People[0].Firstname, "Leslie");
	strcpy_s(People[1].Firstname, "Andrzej");
	People[1].Postaddress.Housenumber = 245;
	People[2].Postaddress.StreetName[3] = 'z';
	return 0;
}
==> ./Projects/arrays/arrays/Source.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int T[3000]; // 3000 place array
	int total, i;
	double average, SD;

	// work out average
	total = 0;
	for (i = 0; i < 3000; i++){
		total = total + T[i];
	}
	average = total / 3000;

	//work out SD
	SD = 0;
	for (i = 0; i < 3000; i++){
		SD = SD + (T[i] - average)*(T[i] - average);
	}
	SD = SD / 3000;
	SD = sqrt(SD);

	cout << "T[0]: " << T[6]<< endl;
	cout << " " << endl;

	
	return 0;
}
==> ./Projects/ASCII code/ASCII code/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int i;

	for (int i = 0; i < 255; i++){
		cout << i << " " << (char)i << endl;
	}
	cout << "\n";
	return 0;
}
==> ./Projects/assignment statement syntax/assignment statement syntax/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double a, b;
	//value in brackets is calculated first
	a = (b = 4) * 3;
	cout << "b = " << b << "\na= " << a << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/assignment to self assignment operator/assignment to self assignment operator/main.cpp <==
#include <iostream>
#include <exception>
#include <string>

using namespace std;

/*handle self-assignment in operator overload functions

possibility of using dogs[i] = dogs[j] operator overload*/

class collar{
};

class Dog1{
public:
	collar* pCollar;
	Dog1(){
		pCollar = new collar();
	}
	void introduce(){
		cout << "I'm a Dog1. I have a " << pCollar << endl;
	}
	Dog1& operator=(const Dog1& rhs){
		if (this == &rhs){
			return *this; //if not here would delete this.pCollar object
		}
		/*
		delete pCollar;
		pCollar = new collar(*rhs.pCollar);
		return *this;
		*/
		collar* pOrigCollar = pCollar;
		try{
			pCollar = new collar(*rhs.pCollar);
			delete pOrigCollar;
			return *this;
		}
		catch (exception x){
			collar* pCollar = pOrigCollar;
			return *this;
		}
	}
};

class Dog2{
public:
	Dog2(){
		pCollar = new collar();
		cout << "I'm a Dog2. I have a " << pCollar << endl;
	}
	collar* pCollar;
	Dog2& operator=(const Dog2& rhs){ //const stops changing rhs Dog2
		*pCollar = *rhs.pCollar;
		return *this; 
	}
};

int main(){
	Dog1 rex;
	Dog1 tex;
	Dog2 rover;
	Dog2 regius;

	rex.introduce();
	tex.introduce();

	rex = tex;

	rex.introduce();
	tex.introduce();
}
==> ./Projects/binary error/binary error/Source.cpp <==
// Computer uses binary to represent numbers. Not all numbers can be represented in binary.
// Computers effort to represent numbers can cause roundoff errors

#include <iostream>

using namespace std;

int main() {
	double x = 4.35;
	int n = x * 100;
	cout << n << endl;
	return 0;
}

//displays 434 not 435
//other difficulties are numbers like 1/3
==> ./Projects/binary to array (somenumbers)/binary to array (somenumbers)/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	unsigned char buffer[3000];
	int n = 0;
	ifstream fin;
	fin.open("SomeNumbers.bin", ios::in | ios::binary);
	while (!fin.eof()){ //if not at the end of file
		fin.read((char*)(&buffer[0]), 30);
		cout << (int)buffer[n++] << " ";
	}
	fin.close();
	return 0;
}
==> ./Projects/binary to dex/binary to dex/main.cpp <==
#include <iostream>
#include <string>
#include <deque>

using namespace std;

void dectobinary();
void bintodecimal();
void menuScreen();

int main(){
	cin.exceptions(ios_base::failbit);
	menuScreen();

	system("PAUSE");
	return 0;
}

void menuScreen(){
	int choice = 0;
	do{
		cout << "Choose one of the options below:\n";
		cout << "1. Convert decimal to binary\n2. Convert binary to decimal\n3. Exit\n";
		cout << "Please enter your choice : ";
		try{
			cin >> choice;
		}
		catch (exception ex){
			cout << "Invalid choice\n";
			cin.clear();
			cin.ignore(100, '\n');
			choice = 0;
		}
	} while ((choice < 1) || (choice > 3));

	cout << endl;
	switch (choice){
	case 1: dectobinary(); break;
	case 2: bintodecimal(); break;
	case 3: cout << "Thank you for using this program\n"; break;
	}
}

void dectobinary(){
	int number = 0;
	do{
		cout << "Please enter a denary integer : ";
		try{
			cin >> number;
			cout << endl;
		}
		catch (exception x){
			cout << "Input error\n";
			cin.clear();
			cin.ignore(100, '\n');
			number = 0;
		}
	} while (number == 0);
	
	cin.clear();
	cin.ignore(100, '\n');
	deque<int> binary;

	while ((number >= 1) || (number <= -1)){
		binary.push_front(number % 2);
		number = number / 2;
	}

	cout << "Binary : ";
	for (auto i : binary){
		cout << i;
	}
	cout << endl << endl;
	menuScreen();
}

void bintodecimal(){
	string binary;
	do{
		cout << "Please enter a binary number : ";
		cin >> binary;
		cout << endl;
		for (int i = 0; i < binary.length(); i++){
			if ((binary.at(i) != '1') && (binary.at(i) != '0')){
				binary = "Nah";
				cout << "This is not a binary number\n";
				break;
			}
		}
	} while (binary == "Nah");
	
	cin.clear();
	cin.ignore(100, '\n');
	deque<int> b1nary1;
	int scalar = 1;

	for (int i = 0; i < binary.length(); i++){
		b1nary1.push_back(static_cast<int>(binary[i] - '0'));
		scalar *= 2;
	}

	int number = 0;

	for (int i = 0; i < binary.length(); i++){
		scalar /= 2;
		number += scalar * b1nary1[i];
	}

	cout << "Decimal : " << number << endl;
	cout << endl;
	menuScreen();
}
==> ./Projects/bitwise operators/bitwise operators/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a(0xf001);
	short b(0xff);
	cout << hex << "a & b = " << (a&b);
	cout << "\n";
	cout << hex << "\na | b =" << (a | b);
	cout << "\n";
	cout << hex << "\na ^ b = " << (a ^ b);
	cout << "\n";
	cout << hex << "\n~a = " << ~a;
	cout << "\n";
	cout << hex << "\na << 4 = " << (a << 4);
	cout << "\n";
	cout << hex << "\na >> 5 = " << (a >> 5);
	cout << "\n";
	cout << "\n";
	return 0;
}
==> ./Projects/bitwise operators2/bitwise operators2/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	unsigned s = 555;
	//s = 1000101011
	int i = (s >> 4) & (~(~0 << 3));
	// s >> 4 = 100010, (~(~0 << 3)) = 000111
	// so int i = 010, so int i = 2
	cout << "s >> 4 = " << (s >> 4) << endl;
	cout << "s >> 3 = " << (s >> 3) << endl;
	cout << "s >> 2 = " << (s >> 2) << endl;
	cout << "s >> 1 = " << (s >> 1) << endl;
	cout << "s >> 0 = " << (s >> 0) << endl;
	cout << "s << 1 = " << (s << 1) << endl;
	cout << "34 >> 3 = " << (34 >> 3) << endl;
	cout << "(~(~0 << 3) = " << ((~(~0 << 3))) << endl;
	cout << "(~(~0 << 2) = " << ((~(~0 << 2))) << endl;
	cout << "(~(~0 << 1) = " << ((~(~0 << 1))) << endl;
	cout << "(~(~0 << 0) = " << ((~(~0 << 0))) << endl;
	cout << "(~(~0 >> 1) = " << ((~(~0 >> 1))) << endl;
	cout << "(~(~0 >> 10) = " << ((~(~0 >> 10))) << endl;

	cout << "(-1 << 3) = " << ((-1 << 3)) << endl;
	cout << "(-1 << 2) = " << ((-1 << 2)) << endl;
	cout << "(-1 << 1) = " << ((-1 << 1)) << endl;
	cout << "(-1 << 0) = " << ((-1 << 0)) << endl;
	cout << "(~0 >> 1) = " << ((-1 >> 1)) << endl;
	cout << "(~0 >> 2) = " << ((-1 >> 2)) << endl;
	cout << "(s >> 4) & (~(~0 << 8)) = " << ((s >> 4) & (~(~0 << 8))) << endl;
	cout << "(s >> 4) & (~(~0 << 7)) = " << ((s >> 4) & (~(~0 << 7))) << endl;
	cout << "(s >> 4) & (~(~0 << 6)) = " << ((s >> 4) & (~(~0 << 6))) << endl;
	cout << "(s >> 4) & (~(~0 << 5)) = " << ((s >> 4) & (~(~0 << 5))) << endl;
	cout << "(s >> 4) & (~(~0 << 4)) = " << ((s >> 4) & (~(~0 << 4))) << endl;
	cout << "(s >> 4) & (~(~0 << 3)) = " << ((s >> 4) & (~(~0 << 3))) << endl;
	cout << "(s >> 4) & (~(~0 << 2)) = " << ((s >> 4) & (~(~0 << 2))) << endl;
	cout << "(s >> 4) & (~(~0 << 1)) = " << ((s >> 4) & (~(~0 << 1))) << endl;
	cout << "(s >> 4) & (~0 << 1) = " << ((s >> 4) & (~0 << 1)) << endl;
	cout << "(s >> 4) & (~0 << 2) = " << ((s >> 4) & (~0 << 2)) << endl;
	cout << "(s >> 4) & (~0 << 6) = " << ((s >> 4) & (~0 << 6)) << endl;
	cout << "(s >> 4) & (~0 >> 7) = " << ((s >> 4) & (~0 >> 7)) << endl;
	cout << "(s >> 4) & (~0 >> 2) = " << ((s >> 4) & (~0 >> 2)) << endl;
	cout << "(s >> 4) & (~0 >> 1) = " << ((s >> 4) & (~0 >> 3)) << endl;

	cout << (~(~0 << 0)) << endl;
	cout << (~(~0 << 1)) << " and " << (~1 << 1) << endl;
	cout << (~(~0 << 2)) << " and " << (~1 << 2) << endl;
	cout << (~(~0 << 3)) << " and " << (~1 << 3) << endl;

	cout << (~0) << endl;
	cout << (~1) << endl;
	cout << (~2) << endl;
	cout << (~3) << endl;
	cout << (~4) << endl;
	cout << (~5) << endl;
	cout << (0 << 6) << endl;
	cout << (~(~1)) << endl;
	cout << (~(~2)) << endl;
	cout << " \n";
	cout << i << endl;
	cout << " \n";
	return 0;
}
==> ./Projects/blood pressure for/blood pressure for/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int BP;
	int i;
	int dangerous;

	dangerous = 0;

	for (i = 1; i <= 10; i++){
		cout << "Enter BP number " << endl;
		cin >> BP;
		cout << " " << endl;
		cout << "You entered " << BP << endl;
		if ((BP < 30) || (BP > 70)){
			dangerous++;
			cout << "Blood pressure at dangerous levels." << endl;
			cout << " " << endl;
		}
		else{
			cout << "Blood pressure normal." << endl;
			cout << " " << endl;
		}
	}
	cout << "Patient count = " << i - 1 << endl;
	cout << " " << endl;
	cout << "Patients with dangerous levels of blood pressure = " << dangerous << endl;
	cout << " " << endl;
	cout << "Done" << endl;
	cout << " " << endl;
	return 0;
}
==> ./Projects/bloodpressure/bloodpressure/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int BP;
	int i;

	i = 1;

	while (i <= 10){
		cout << "Enter BP number ";
		cin >> BP;
		cout << "You entered " << BP << endl;
		i++;
	}
	cout << "count = " << i - 1 << endl;
	cout << "Done" << endl;
	return 0;
}
==> ./Projects/booltry/booltry/Source.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const double GunRange = 50.0;
	double X1, Y1, X2, Y2, distance, Charge;
	bool InRange; // true if Imp is in range of gun
	bool IsCharged; //true if gun gauge is greater or equal to 100
	bool CanShoot; //true if In and IsCharged
 
	cout << "Please enter Space Ninja's X co-ordinates ";
	cin >> X1; '\n';
	cout << "Please enter Space Ninja's Y co-ordinates ";
	cin >> Y1; '\n';
	cout << "Please enter Space Imp's X co-ordinates ";
	cin >> X2; '\n';
	cout << "Please enter Space Imp's Y co-ordinates ";
	cin >> Y2; '\n';
	cout << "What's the reading on your gun gauge Ninja? ";
	cin >> Charge; cout << " amps"; '\n';

	distance = sqrt((Y2 - Y1) * (Y2 - Y1) + (X2 - X1) * (X2 - X1));

	cout << "Space Ninja's co-ordinates are: " << X1 << ", " << Y1 << '\n';
	cout << "Space Imps's co-ordinates are: " << X2 << ", " << Y2 << '\n';
	cout << "Distance to target is " << distance << " metres" << '\n';

	if (distance <= GunRange){
		InRange = true;
		cout << "Target is in range!" << endl;
	}
	else{
		InRange = false;
		cout << "He's too far away!" << endl;
}
	if (Charge >= 100){
		IsCharged = true;
		cout << "Gun meter fully charged" << endl;
	}
	else{
		IsCharged = false;
		cout << "I'm out of charge!" << endl;
	}

	if (InRange && IsCharged){
		CanShoot = true;
		cout << "Feuer frei!" << endl;
	}
	else{
		CanShoot = false;
		if (InRange){
			cout << "Retreat!" << endl;
		}
		else if (IsCharged){
			cout << "I need to get closer!" << endl;
		}
		else {
			cout << "Bollocks!" << endl;
		}
	}
	return 0;
}

==> ./Projects/break statement - while loop/break statement - while loop/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int j = 40;
	while (j < 80)
	{
		j = j + 10;
		if (j == 60)
		{
			break;
		}
		cout << "j is " << j << endl;
	}
	cout << "We are out of the loop.\n";
	return 0;
}
==> ./Projects/c code (embedded functions)/c code (embedded functions)/Source.c <==
#include <stdio.h>

int count;

main()
{
	void func1(void); //function declaration
	count = 100;
	func1(); //function call
}

void func1(void)
{
	void func2(void); //function declaration
	func2(); //function call
	printf("count is %d\n\n", count); //count declared in main
	return;
}

void func2(void)
{
	int count;
	for (count = 1; count <= 10; count++)
		printf(".");
	return;
}
==> ./Projects/c code (functions)/c code (functions)/Source.c <==
#include <stdio.h>

main()
{
	char lower, upper;
	
	char low_to_up(char lower); //function declaration

	printf("Please enter a lower case char : ");

	scanf("%c", &lower);

	upper = low_to_up(lower); //call of function, returns character

	printf("\nThe upper case character is : %c\n\n", upper);

	return;
}

char low_to_up(char c1)
{
	char c2;
	c2 = (c1 >= 'a' && c1 <= 'z') ? ('A' + c1 - 'a') : c1;
	return(c2);
}
==> ./Projects/c code (n factorial function/c code (n factorial function/Source.c <==
#include <stdio.h>

long int factorial(n)
{
	int i;
	long int  prod = 1;
	if (n > 1)
		for (i = 2; i <= n; ++i)
			prod *= i;
	return(prod);
}

main()
{
	int n;
	long int factorial(int n1);
	printf("\n n = ");
	scanf("%d", &n);
	printf("\n n!= %1d\n\n", factorial(n));
	return 0;
}
==> ./Projects/c code to read single line of text/c code to read single line of text/Source.c <==

==> ./Projects/c project/c project/Source.c <==
#include<stdio.h>
#include<conio.h>
void main()
{
	int a, b, c;
	printf("Enter any two numbers : \n");
	scanf("%d%d", &a, &b);
	c = a + b;
	printf("\nSum is : %d", c);
	getch();
}

==> ./Projects/c++ 22 arrays of vectors/arrays of vectors/main.cpp <==
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
	string name;
	char grade;
public:
	Student(string name, char grade){
		this->name = name;
		this->grade = grade;
	}

	//const identifier needed as will be used with a const variable
	void getName() const{
		cout << name << endl;
	}
	void getGrade() const{
		cout << grade << endl;
	}
};

void enterStudents(vector<Student>&);
//enterStudents - allows user to enter students names and grades
//@param vector<int>>& - vector which will hold Student objects

void printStudents(const vector<Student>&);
//printStudents - prints Students names and grades
//@param const vector<int>& - vector which holds Student objects

int main(){
	vector<Student> myStudents;

	enterStudents(myStudents);
	printStudents(myStudents);
	return 0;
}

void enterStudents(vector<Student>& myStudents){
	string name;
	char grade;
	int classSize;
	cout << "Please enter the class size : ";
	cin >> classSize;
	cout << endl;
	for (int i = 0; i < classSize; i++){
		cout << "Please enter Student " << i + 1 << "'s name : ";
		cin >> name;
		cout << "Please enter Student " << i + 1 << "'s grade : ";
		cin >> grade;
		Student myStudent(name, grade);
		myStudents.push_back(myStudent);
		cout << endl;
	}
	cout << endl;
}

void printStudents(const vector<Student>& myNStudents){
	unsigned int size = myNStudents.size();
	for (unsigned int i = 0; i < size; i++){
		cout << "Student " << i + 1 << "'s name : ";
		myNStudents[i].getName();
		cout << "Student " << i + 1 << "'s grade : ";
		myNStudents[i].getGrade();
		cout << endl;
	}
}

==> ./Projects/c++ 23 static member variables/c++ 23 static member variables/Array.cpp <==
#include "Array.h"

void enterAccounts(vector<Bank>& newAccountsarray){
	string name1;
	string name2;
	int accountNumber;
	double balance;
	int noofAccounts;
	cout << "How many accounts would you like to add : ";
	cin >> noofAccounts;
	cout << endl;
	for (int i = 0; i < noofAccounts; i++){
		cout << endl << "What is the account holder's name? ";
		cin >> name1 >> name2;
		name1 += " " + name2;
		cout << "What is the account number? ";
		cin >> accountNumber;
		cout << "What is the starting balance? ";
		cin >> balance;
		Bank tempstore(name1, accountNumber, balance);
		newAccountsarray.push_back(tempstore);
	}
}


void printAccounts(const vector<Bank>& newAccountsarray){
	unsigned int size = newAccountsarray.size();
	cout << "\nThere are " << size << " account details on this system :\n\n";
	for (unsigned int i = 0; i < size; i++){
		cout << "Account name : " << newAccountsarray[i].getName() << endl;
		cout << "Account number : " << newAccountsarray[i].getAccountNumber() << endl;
		cout << "Account balance : " << newAccountsarray[i].getBalance() << "\n\n";
	}
}
==> ./Projects/c++ 23 static member variables/c++ 23 static member variables/Array.h <==
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"

using namespace std;

void enterAccounts(vector<Bank>&);
//enterAccounts - allows user to enter new account details
//@param vector<Bank>& - array where account details to be stored

void printAccounts(const vector<Bank>&);
//printAccounts - allows user to print account details
//@param const vector<Bank>& - account details to be printed

#endif
==> ./Projects/c++ 23 static member variables/c++ 23 static member variables/Bank.cpp <==
#include "Bank.h"

int Bank::numberofAccounts = 0;
double Bank::bankBalance = 10000.0;

Bank::Bank(string newName, int newAccountNumber, double newBalance){
	name = newName;
	accountNumber = newAccountNumber;
	balance = newBalance;
	numberofAccounts++;
	bankBalance += balance;
}

Bank::~Bank(){
	bankBalance -= balance;
	numberofAccounts--;
}

//Accessor functions
int Bank::getAccountNumber() const{
	return accountNumber;
}

string Bank::getName() const{
	return name;
}

double Bank::getBalance() const{
	return balance;
}

//Mutator functions
void Bank::withdraw(double money){
	balance -= money;
	bankBalance -= money;
}

void Bank::deposit(double money){
	balance += money;
	bankBalance += money;
}

//Print function
void Bank::printBankInfo(){
	cout << "Bank balance is : " << bankBalance << endl;
	cout << "Number of accounts is : " << numberofAccounts << endl;
}


==> ./Projects/c++ 23 static member variables/c++ 23 static member variables/Bank.h <==
//#ifndef (if not defined) #define, #endif syntax is a preprocessor technique which 
//prevents a header file from being included multiple times. if not used, potential
//error at compile time as it could lead to redefining the same variable twice.
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

using namespace std;

class Bank{
private:
	//member variables
	string name;
	int accountNumber;
	double balance;

	static int numberofAccounts;
	static double bankBalance;
	//static member variables cannot be initialised in header file
public:
	//Constructor
	Bank(string, int, double);

	//Destructor
	~Bank();

	string getName() const;
	//getName - prints account holders name
	//@return string - name of account holder

	double getBalance() const;
	//getBalance - prints balance of account
	//@return double - balance of account holder

	int getAccountNumber() const;
	//getAccountNUmber - prints account number
	//@return int - account number of account holder

	void withdraw(double);
	//withdraw - withdraws set amount from bank account of user
	//@param double - amount to be withdrawn

	void deposit(double);
	//deposit - deposits set ammount from bank account of account holder
	//@param double - amount to be deposited

	static void printBankInfo();
	//prinkBankInfo - prints number of accounts and total bank balance
	//@print static int - number of accounts in bank
	//@print static double - total bank balance
};

#endif
==> ./Projects/c++ 23 static member variables/c++ 23 static member variables/main.cpp <==
#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"
#include "Array.h"

using namespace std;

int main(){
	Bank::printBankInfo();

	vector<Bank> newAccounts;
	enterAccounts(newAccounts);
	printAccounts(newAccounts);
	return 0;
}



==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/checking.cpp <==

==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/checking.h <==
#ifndef CHECKING_H
#define CHECKING_H

#include "triangle.h"




#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/equilateral.cpp <==
#include "Equilateral.h"

Equilateral::Equilateral(){}

Equilateral::Equilateral(double newbase, double newheight)
	: Triangle(newbase, newheight){
	cout << "Equilateral Triangle created.\n\n";
}

double Equilateral::getePerimeter() const{
	return getBase() * 3;
}
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/equilateral.h <==
#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include "Triangle.h"
#include <iostream>
using namespace std;

class Equilateral : virtual public Triangle{
public:
	//default constructor
	Equilateral();

	//overloaded constructor
	Equilateral(double, double);
	//Equilateral - creates triangle with parameters of side length & height
	//@param double - side length to be set
	//@param double - height to be set

	double getePerimeter() const;
};

#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/externalfunctions.cpp <==
#include "externalfunctions.h"

vector<TriangleV> newTriangles;

static int counter = 0;

void mainScreen(){
	int choice;
	do{
		cout << "What type of triangle would you like to create ?\n\n";
		cout << "1: Scalene\n2: Equilateral\n3: Isoceles\n4: Print Set\n5: Exit\n";
		cout << "\nPlease enter your option : ";
		cin >> choice;
		if (choice < 1 || choice > 5){
			cout << "\nPlease choose a valid option\n\n";
		}
	} while (choice < 1 || choice > 5);

	switch (choice){
	case 1: setScalene(newTriangles); break;
	case 2: setEquilateral(newTriangles); break;
	case 3: setIsoceles(newTriangles); break;
	case 4: printSet(newTriangles); break;
	case 5: cout << "\nThank you for using this program\n\n";
	}
}

void setScalene(vector<TriangleV>& newTriangles){
	double base, height, side1, side2, test, calcS1, calcS2;
	int choice;
	do{
		cout << "\nPlease enter the base in cm : ";
		cin >> base;
		cout << "Please enter side1 in cm : ";
		cin >> side1;
		cout << "Please enter side2 in cm : ";
		cin >> side2;
		cout << "Please enter height in cm : ";
		cin >> height;

		calcS2 = sqrt(side2*side2 - height*height);
		calcS1 = sqrt(side1*side1 - height*height);

		if ((height == side1)&&(height < side2)) {
			test = base - calcS2;
		}
		else if ((height == side2)&&(height < side1)){
			test = base - calcS1;
		}
		else if ((height > side1) || (height > side2)){
			test = 2;
		}
		else if ((side1 > side2) && (calcS1 > base)){
			test = base + calcS2 - calcS1;
		}
		else if ((side2 > side1) && (calcS2 > base)){
			test = base + calcS1 - calcS2;
		}
		else{
			test =
				base - calcS1 - calcS2;
		}

		do{
			if ((test > 0.1) || (test < -0.1)){
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			}
			else {
				choice = 2;
				cout << "\nNow creating triangle...\n";
			}
		} while ((choice < 1) || (choice > 2));
	} while (((test > 0.1) || (test < -0.1)) && (choice == 1));

	if ((test <= 0.1) && (test >= -0.1)){
		TriangleV newScalene(base, side1, side2, height);
		counter++; cout << "counter = " << counter;
		newTriangles.push_back(newScalene);
		cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
		cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
		cout << "Perimeter : " << newTriangles[counter-1].getsPerimeter() << "\n\n";
		cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	}
	mainScreen();
}

void setEquilateral(vector<TriangleV>& newTriangles){
	double side, height;
	cout << "Please enter the length of a side in cm : ";
	cin >> side;

	height = sqrt(side*side - 0.25*side*side);
	TriangleV newEquilateral(side, height);
	counter++;
	newTriangles.push_back(newEquilateral);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getePerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void setIsoceles(vector<TriangleV>& newTriangles){
	double base, side, height;
	int choice;
	do{
		cout << "Please enter the length of your base in cm : ";
		cin >> base;
		cout << "Please enter a side length in cm : ";
		cin >> side;
		if (side <= 0.5*base){
			do {
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			} while ((choice < 1) || (choice > 2));
		}
	} while (side <= 0.5*base);


	height = sqrt(side*side - 0.25*base*base);
	TriangleV newIsoceles(base, side, height);
	counter++;
	newTriangles.push_back(newIsoceles);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getiPerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void printSet(const vector<TriangleV>& newTriangles){
	unsigned int size = newTriangles.size();
	if (size == 0){
		cout << "\nThere are no triangles in this array\n";
	}
	else{
		cout << "\n";
		for (unsigned int i = 0; i < size; i++){
			cout << "Triangle " << i + 1 << "\n";
			cout << "Height : " << newTriangles[i].getHeight() << "\n";
			cout << "Base : " << newTriangles[i].getBase() << "\n";
			cout << "Perimeter : " << newTriangles[i].getsPerimeter() << "\n";
			cout << "Area : " << newTriangles[i].getArea() << "\n";
		}
	}
	mainScreen();
}
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/externalfunctions.h <==
#ifndef EXTERNALFUNCTIONS_H
#define EXTERNALFUNCTIONS_H

#include <iostream>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "vector.h"

using namespace std;

void mainScreen();
void setScalene(vector<TriangleV>&);
void setEquilateral(vector<TriangleV>&);
void setIsoceles(vector<TriangleV>&);
void printSet(const vector<TriangleV>&);

#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/isoceles.cpp <==
#include "isoceles.h"

Isoceles::Isoceles(){}

Isoceles::Isoceles(double newBase, double newequalSide, double newHeight) 
	: Triangle(newBase, newHeight){
	equalside = newequalSide;
	cout << "Isoceles Triangle created.\n\n";
}

double Isoceles::getiPerimeter() const{
	return getBase() + equalside * 2;
}



==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/isoceles.h <==
#ifndef ISOCELES_H
#define ISOCELES_H

#include <iostream>
#include "triangle.h"
using namespace std;

class Isoceles : virtual public Triangle{
private:
	//member variables
	double equalside;
public:
	//default constructor
	Isoceles();

	Isoceles(double base, double equalside, double height);
	//Isoceles - creates Isoceles triangle with base, height, and equal side
	//@param double - base to be set 
	//@param double - equal sides to be set
	//@param double - height to be set

	virtual double getiPerimeter() const;
	//getPerimeter - returns Perimeter of triangle
	//@param double - base to be used in calculation
	//@param double - equal sides to be used in calculation
	//@return double - perimeter to be returned 

};

#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/main.cpp <==
#include <iostream>
#include <vector>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "externalfunctions.h"

using namespace std;

int main(){
	
	mainScreen();

	return 0;
}


==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/scalene.cpp <==
#include "scalene.h"

Scalene::Scalene(){}

Scalene::Scalene(double ibase, double newSide1, double newSide2, double height)
	: Triangle(ibase, height){
	base = ibase;
	side1 = newSide1;
	side2 = newSide2;
	cout << "Scalene Triangle created.\n\n";
}

double Scalene::getsPerimeter() const{
	return side1 + side2 + base;
}


==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/scalene.h <==
#ifndef SCALENE_H
#define SCALENE_H

#include "triangle.h"
#include <iostream>
using namespace std;

class Scalene : virtual public Triangle{
private:
	//member variables
	double base, side1, side2;
public:
	//default constructor
	Scalene();

	//overloaded constructor
	Scalene(double base, double side1, double side2, double height);
	//Scalene - creates Scalene object with base, side1, side2 and height

	virtual double getsPerimeter() const;
};

#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/triangle.cpp <==
#include "triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(double newBase, double newHeight){
	base = newBase;
	height = newHeight;
}

double Triangle::getHeight() const{
	return height;
}

double Triangle::getBase() const{
	return base;
}

void Triangle::setHeight(double newHeight){
	height = newHeight;
}

void Triangle::setBase(double ibase){
	base = ibase;
}

double Triangle::getArea() const{
	return 0.5 * height * base;
}
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/triangle.h <==
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
using namespace std;

class Triangle{
private:
	//member variables
	double height;
	double base;

public:
	//default constructor
	Triangle();

	//overloaded constructor
	Triangle(double, double);
	//Triangle - creates triangle with parameter of height
	//@param int - height to be set

	double Triangle::getBase() const;

	//Mutator function
	void setHeight(double);
	//setHeight - sets the triangle's height
	//@param int - height to be set

	//Mutator function
	void setBase(double);
	//setBase - sets the triangle's base length
	//@param int - base length to be set

	//Accessor function
	double getHeight() const;
	//getHeight - returns the triasngle's height
	//@return int - height to be returned

	double getArea() const;
	//getArea - returns the area of the triangle
	//@param int - base to be used in calculation
	//@return int - area to be returned


};

#endif
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/Vector.cpp <==
#include "vector.h"

TriangleV::TriangleV(){}

TriangleV::TriangleV(double ibase, double iside1, double iside2, double iheight)
	: Scalene(ibase, iside1, iside2, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double isides, double iheight)
	: Isoceles(ibase, isides, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double iheight)
	: Equilateral(ibase , iheight){
	setBase(ibase);
	setHeight(iheight);
}
	
==> ./Projects/c++ 24 inheritance/c++ 24 inheritance/vector.h <==
#ifndef TRIANGLEV_H
#define TRIANGLEV_H

#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include <vector>

class TriangleV : virtual public Isoceles, virtual public Equilateral, virtual public Scalene{
public:
	//default constructor
	TriangleV();

	//overloaded Scalene constructor
	TriangleV(double base, double side1, double side2, double height);

	//overloaded Isoceles constructor
	TriangleV(double base, double sides, double height);

	//overloaded Equilateral constructor
	TriangleV(double base, double height);

};



#endif
==> ./Projects/c++ int 49 deck of cards/c++ int 49 deck of cards/Card.h <==
#ifndef H_card
#define H_card
#include <string>
#include <iostream>

using namespace std;

class Card{
	string face;
	string suit;
public: 
	Card(string cardface, string cardsuit){
		face = cardface;
		suit = cardsuit;
	}
	string print() const{
		return face + " of " + suit;
	}
	Card(){
		face = "none";
		suit = "none";
	}
	
};


#endif
==> ./Projects/c++ int 49 deck of cards/c++ int 49 deck of cards/DeckofCards.h <==
#ifndef H_DECKOFCARDS
#define H_DECKOFCARDS
#include "Card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int CARDS_PER_DECK = 52;

class deckOfCards{
	Card *deck;
	int currentCard;
public:
	deckOfCards(){
		string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Jack", "Queen", "King" };
		string suits[] = {"Hearts", "Spades", "Clubs", "Diamonds"};
		deck = new Card[CARDS_PER_DECK];
		currentCard = 0;
		for (int count = 0; count < CARDS_PER_DECK; count++){
			deck[count] = Card(faces[count % 13], suits[count / 13]);
		}
	}
	void shuffle(){
		currentCard = 0;
		for (int i = 0; i < 3; i++){
			for (int first = 0; first < CARDS_PER_DECK; first++){
				int second = (rand() + time(0)) % CARDS_PER_DECK;
				Card temp = deck[first];
				deck[first] = deck[second];
				deck[second] = temp;
			}
		}
	}
	Card dealCard(){
		if (currentCard > CARDS_PER_DECK){
			shuffle();
		}
		if (currentCard < CARDS_PER_DECK){
			return deck[currentCard++];
		}
		return deck[0];
	}
	void printDeck() const{
		cout << left;
		for (int i = 0; i < CARDS_PER_DECK; i++){
			cout << setw(19) << deck[i].print();
			if ((i+1) % 4 == 0){
				cout << endl;
			}
		}
	}
};

#endif
==> ./Projects/c++ int 49 deck of cards/c++ int 49 deck of cards/main.cpp <==
#include <iostream>
#include "DeckofCards.h"
#include <stdexcept>

using namespace std;

class Player{
	Card *hand;
public:
	Player(Card one, Card two){
		hand = new Card[2];
		hand[0] = one;
		hand[1] = two;
	}
	void printHand(){
		int i = 0;
		for(int i =0; i < 2; i++){
			cout << hand[i].print() << " ";
		}
	}

};

void menu();


int main(){
	//menu();

	deckOfCards newDeck;
	newDeck.shuffle();
	Card river[5];
	cout << "Dealing hands\n";
	newDeck.dealCard();
	Player human(newDeck.dealCard(), newDeck.dealCard());
	Player Computer(newDeck.dealCard(), newDeck.dealCard());

	for (int i = 0; i < 5; i++){
		river[i] = newDeck.dealCard();
		cout << river[i].print() << " ";
	}
	
	cout << "\n\nPlayer's hand : "; human.printHand();
	cout << "\nComputers hand : ";  Computer.printHand();
	cout << endl << endl;

	return 0;
}

/*void menu(){
	int choice;
	do{
		cout << "What game would you like to play?\n";
		cout << "1. Texas hold'em\n2. Omaha high stakes\n3. Five card stud\n4. Exit\n";
		cout << "\nPlease enter your choice: ";
		try{
			cin >> choice;
			cin.exceptions(ios_base::failbit);
		}
		catch (exception e){
			cout << "\nYou did not enter an integer\n";
			cin.clear();
			cin.ignore(100, '\n');
			choice = 0;
		}
		if ((choice < 1) || (choice > 4)){
			cout << "\nPlease enter a choice between 1 and 4\n\n";
		}
	} while ((choice < 1) || (choice > 4));

	switch (choice){
	case 1:
	case 2:
	case 3:
	case 4:
	default:
	}
}*/
==> ./Projects/c++ int 96 binary to dex recursive/c++ int 96 binary to dex recursive/main.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

void toDecimal(int, int&, int&);
void toBinary(int, int);

int main(){
	int menuchoice;
	int decimalNum = 0, bitWeight = 0, binaryNum, base = 2;
	do{
		cout << "To convert a binary number to decimal, enter 1\n";
		cout << "To convert a decimal number to binary, enter 2\n";
		cout << "To exit, enter 3" << endl;
		cin >> menuchoice;
		cout << endl;
		switch (menuchoice){
		case 1: 
			cout << "Enter binary number: ";
			cin >> binaryNum;
			cout << endl;
			toDecimal(binaryNum, decimalNum, bitWeight);
			cout << "Binary " << binaryNum << " = " << decimalNum << endl << endl;
			break;
		case 2: 
			cout << "Enter decimal number: ";
			cin >> decimalNum;
			cout << "\nDecimal " << decimalNum << " = ";
			toBinary(decimalNum, base);
			cout << "\n\n";
			break;
		}
	} while (menuchoice != 3);

	system("PAUSE");
	return 0;
}

void toDecimal(int number, int &decimal, int &weight){
	int bit;
	if (number > 0){
		bit = number % 10;
		decimal = decimal + bit * pow(2, weight);
		number = number / 10;
		weight++;
		toDecimal(number, decimal, weight);
	}

	/*
	101001 converted to decimal ->
	(1 * 2^0) + (0 * 2^1) + (0 * 2^2) + (1 * 2^3) + (0 * 2^4) + (1 * 2^5)->
	1 + 0 + 0 + 8 + 0 + 32 = 41

	toDecimal()
	decimal = decimal 101001 % 10 * (2 ^ weight)
	101001 / 10 = 10100; weight++;
	10100 % 10 * (2 ^ weight)
	etc...
	*/
}

void toBinary(int num, int base){
	if (num > 0){
		toBinary(num / base, base);
		cout << num % base;
	}

	//outputs in reverse as is recursive function
}
==> ./Projects/c++ int(l) 03 stream commands and iomanip/c++ int(l) 03 stream commands and iomanip/main.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	//for getting all possible 
	char ch1, ch2;
	int num1;

	cout << "Input \"A 25\" : ";
	cin >> ch1 >> ch2 >> num1; //input 'A 25'
	cin.ignore(100, '\n');
	cout << "ch1 : " << ch1 << " ch2 : " << ch2 << " num1 : " << num1 << endl;
	/*cin.ignore() takes 2 parameters, the two inputs speciy that all inputs should
	be ignored for the first 100 characters or until a newline character appears*/
	
	cout << "\nInput \"A 25\" : ";
	cin.get(ch1); cin.get(ch2); cin >> (num1); //input 'A 25'
	cout << "ch1 : " << ch1 << " ch2 : " << ch2 << " num1 : " << num1 << endl;
	cin.ignore(100, '\n');
	/*cin.get() recognizes escape characters, in this case including the newline 
	escape character which breaks the previous input stream. If the previous 
	cin.ignore() was ot used ch1 would be equal to the newline escape sequence*/

	cout << "\nPlease enter \"RULE\" : ";
	cin.get(ch1);
	cout << "\n1st cin.get(ch1), ch1 : " << ch1;
	cin.get(ch1);
	cout << "\n2nd cin.get(ch1), ch1 : " << ch1;
	cin.putback(ch1);
	cin.get(ch1);
	cout << "\ncin.putback(ch1), ch1 : " << ch1;
	ch1 = cin.peek();
	cout << "\ncin.peek() : " << ch1;
	cin.get(ch1);
	cout << "\n3rd cin.get(ch1), ch1 : " << ch1;
	cin.clear(); //clears all input
	cin.ignore(100, '\n'); //allows for fresh input

	cout << endl;
	cin.get(ch1);
	cout << ch1;

	double x = 123.45, y = 67.543, z = 9.8504;
	cout << fixed << showpoint;
	for (int i = 2; i < 5; i++){
		cout << setprecision(i);
		cout  << left << "x : " << setw(8) << x << "\ty : " << setw(8) << y << "\tz : " <<
			setw(8) << z << endl;
	}

	system("PAUSE"); //allows pause before end of program in debugging mode
	return 0;
}

==> ./Projects/c++ int126/c++ int126/main.cpp <==

==> ./Projects/c++ intermediate 01/c++ intermediate 01/main.cpp <==
#include <iostream>
#include <string>
#include <cmath> //mathematical operations

using namespace std;

int main(){
	int x = 5, y = 5;

	cout << "x : " << x << " y : " << y << endl;
	cout << "x++ + y = " << x++ + y << endl;
	cout << "\nx : " << x << " y : " << y << endl;
	cout << "++x + y = " << ++x + y << endl;
	cout << "\nx : " << x << " y : " << y << endl;
	cout << "x + y-- = " << x + y-- << endl;
	cout << "\nx : " << x << " y : " << y << endl;
	cout << "x + --y = " << x + --y << endl;

	cout << static_cast<int>(5.6) << endl;  // 5.6 -> 5
	cout << static_cast<double>(5) << endl; // 5 -> 5.0
	cout << static_cast<char>(63) << endl; // relevant ascii code character
	cout << static_cast<int>('A') << endl; //relevant ascii code number
	return 0;
}

==> ./Projects/c++ intermediate 02/c++ intermediate 02/main.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	char a, b;

	cin >> a; //input 'BAR' 
	cout << endl << "a : " << a << endl; // a = B, A and R held in input stream
	cin >> a >> b; //a now becomes A, b becomes R
	cout << endl << "a : " << a << " b : " << b << endl;
}
==> ./Projects/c++11 standard - tips, tricks2/c++11 standard - tips, tricks2/main.cpp <==
#include <iostream>
#include <vector>

using namespace std;

/*9 KEYWORD 'override' FOR VIRTUAL FUNCTION
To avoid inadvertently creating a new function in derived classes*/

//C++ 03
class Dog{
public:
	virtual void A(int x){
		cout << "\nA int = " << x << endl;
	}
	virtual void B() const{
		cout << "\nDog B\n";
	}
};

class Yellowdog : public Dog{
public:
	virtual void A(float x){
		cout << "\nA float = " << x << endl;
	}//created new function
	virtual void B(){
		cout << "\nYellowdog B\n";
	} //created new function

	//will not override Dog function A and B, will be functions of their own 
	//polymorphism will not occur: see main()
};

//C++ 11
class Dog1{
public:
	virtual void A(int);
	virtual void B() const;
	void C();
};

class Yellowdog1 : public Dog1{
public:
	//virtual void A(float) override; //Error: no function to override
	//virtual void B() override; //Error: no function to override
	//void C() override; //Error: no function to override - no virtual funxtction
};

/*10. KEYWORD 'final' (FOR VIRTUAL FUNCTION AND FOR CLASS)*/

class dog final{ //no class can be derived from dog
};

class dog1{
	virtual void bark() final; // no child class function can override bark()
};

/*11. COMPILER GENERATED DEFAULT CONSTRUCTOR*/

//C++ 03
class doggy{
public:
	doggy(int age);
}; // see main for error

//C++ 11
class doggy1{
public:
	doggy1(int age){}
	doggy1() = default; //Force compiler to generate default constructor
};

/*12. KEYWORD 'delete'*/

//C++ 03
class doggo{
	int age;
public:
	doggo(int age){
		cout << "\nHello doggo\n";
		this->age = age;
	}

	int getAge() const{
		return age;
	}
};

//C++ 11
class doggo1{
	int age;
public:
	doggo1(int age){
		cout << "\nHello big doggo\n";
		this->age = age;
	}

	doggo1(double) = delete; //function has been deleted

	doggo1& operator=(const doggo1&) = delete; //operator has been deleted
	
	int getAge() const{
		return age;
	}
};

/*13. KEYWORD 'constexpr' */

//C++ 03
//int arr[6]; //OK
//constexpr const int A(){
//	return 3;
//}
//int arra[A() + 3]; //compiler error - compiler does not know function will always 
//return a constant

//C++ 11
//constexpr int AB(); // constexpr not appearing for me in std library

const int cubed(int);

/*14. NEW STRING LITERALS*/

//char* aa = u8"hello";
//char16_t* a = u"hello";
//char32_t b = U"hello";
//char* bb = R"hello \\";

//none of the above work for some reason

/*15. LAMBDA FUNCTION*/

template <typename func>
void greaterThan(func f, vector<int> ein){
	unsigned int size = ein.size();
	for (unsigned int i = 0; i < size; i++){
		if (f(ein[i])){
			cout << ein[i] << endl;
		}
	}
	for (auto i : ein){ // makes i crawl through array - essentially vector.at();
		if (f(i)){
			cout << i << endl;
		}
	}
}

int main(){
	Yellowdog Alan;

	int x = 5;

	Alan.A(x);
	Alan.A(5.0); 
	Alan.B();

	//doggy dalan; //Error: compiler will not generate default constructor 
	doggy1 dalan;

	doggo dalek(2);
	doggo dalek2(5.6); //converted from float to int

	cout << "\ndalek age = " << dalek.getAge() << endl;
	cout << "\ndalek2 age = " << dalek2.getAge() << endl;

	dalek = dalek2;

	doggo1 henry(3);
	//doggo1 henrythesecond(5.6); //Error; use of float in constructor
	//constructor with float has been deleted
	doggo1 henrythethird(2);

	//henry = henrythethird; //Error: operator overload with 'delete' keyword

	//int arra[AB()+3];
	
	int y1 = cubed(7);
	cout << endl << y1 << endl;

	//int beg[cubed(3)];

	/*15. LAMBDA FUCTION*/

	//allows use of anonymous function, for example as parameter
	cout << [](int X, int Y){return X + Y; }(3,4) << endl;
	auto f = [](int x, int y){return x + y; };
	cout << "\nf = " << f(5, 6) << endl;
	cout << "\nf = " << f(7, 8) << endl;

	vector<int> v = { 5, 2, 3, 4, 5, 6 };

	greaterThan([](int x){return (x > 3); } , v);

	greaterThan([](int x){return ((x > 3) && (x < 6)); }, v);

	int y = 4;
	greaterThan([&](int x){return (x > y); }, v);
	//[&] tells compiler we want variable capture

	return 0;
}

const int cubed(int x){
	return x * x * x;
}
==> ./Projects/C++11 standard tips, tricks/C++11 standard tips, tricks/main.cpp <==
#include <iostream>
#include <vector>
#include <initializer_list> //iniializer list constructor header

using namespace std;

//Define your own initializer list constructor

class boVector{
	//member variables
	vector<int> vec;
	int num;
public:
	//initializer list constructor
	boVector(const initializer_list<int>& v, int inum){
		for (initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr){
			vec.push_back(*itr);
		}
		num = inum;
	}
	//boVector - initializes vector<int> vec using initializer_list<int>&
	//@param initializer_list<int>& - initializer list fed into member variable vec
	//@param int - integer to be fed into member variable num
};

class Dog{
public:
	int age; //3rd choice

	Dog(int a){ //2nd choice
		age = a;
	}

	Dog(const initializer_list<int> &a){ //1st choice
		age = *(a.begin());
	}
};

//nullptr demonstration functions
void foo(int i);
void foo(char *a);
void seven();
int main(){

	/*1. INITIALIZER LISTS*/

	int arr[4] = { 1, 2, 3, 4 };
	//array initializer list

	vector<int> v = { 1, 2, 3, 4 };
	//vector initializer list constructor

	boVector me({ 4, 5, 6, 7 }, 2); //class constructor using initializer list

	/*2. UNIFORM INITIALIZATION*/

	boVector me1 = { { 4, 5, 6, 7 }, 6 };
	boVector me2{ { 4, 5, 6, 7 }, 2 };

	Dog rover{6};
	/*Uniform initializor list search order
	1. Initializer_list constructor
	2. Regular constructor that takes the appropriate parameters
	3. Aggregate initializer*/

	cout << rover.age << endl;

	/*3. AUTO TYPE*/
	std::vector<int> vec1 = { 1, 2, 3, 4 };
	std::vector<int> vec2;

	//C++ 03
	for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it){
		vec2.push_back(*it);
	}

	//C++ 11
	for (auto it = vec1.begin(); it != vec1.end(); ++it){
		vec2.push_back(*it);
	} //infers data type from rhand value, more examples below:

	auto a = 6; //int
	auto b = 9.6; //double
	auto c = a; //int

	/*4. FOR EACH*/
	
	//C++ 03
	for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it){
		cout << (*it) << " ";
	}
	cout << "\n\n";
	
	//C++ 11
	for (auto &i : vec1){
		i++; //chnges the values in vec1
	}

	for (int i : vec1){ //works on any class that has begin() and end()
		cout << i << " ";
	}
	cout << "\n\n";

	/*5. NULLPTR*/

	foo(NULL); //C++03 possible ambiguity, resolved by nullptr
	foo(nullptr);

	/*6. ENUM CLASS*/
	
	//C++ 03
	enum apple{ green_a, red_a };
	enum orange{ big_o, small_o };
	apple dapp = green_a;
	orange jodie = big_o;

	if (dapp == jodie){//essentially read as integers green_a = 1, big_o = 1 
		cout << "Green apple and big orange are the same\n\n";
	}
	else{
		cout << "Green apple and big orange are not the same\n\n";
	}

	//C++ 11
	enum class Apple{ green_a, red_a };
	enum class Orange{ big_o, small_o };
	Apple d_app = Apple::green_a;
	Orange jodiem = Orange::big_o;

	//all above code will work without bottom portion of code

	if (d_app == jodiem){
		cout << "Green apple and big orange are the same\n\n";
	}
	else{
		cout << "Green apple and big orange are not the same\n\n";
	}

	//No longer return as the same since are different class members
	//above if-else compile would fail because haven't defined ==(Apple, Orange)
	//as overloaded class operator

	/*7. STATIC_ASSERT*/

	//C++ 03 run-time assert
	assert(a != NULL);

	//C++ 11 compile time assert
	static_assert(sizeof(int) == 4); 
	//condition for following code, will not work if int size != 4

	/*8. DELEGATING CONSTRUCTOR*/

	class dog(){
	public:
		dog() { ...; }
		dog(int a){ dog(); doOtherThings(); }
	} //works in java, will not work in C++03, double initialization of dog object

	//C++ 03 solution
	class dog(){
		void init(){ ...; }
	public:
		dog(){ init(); }
		dog(int a){ init(); doOtherThings(); }
	}//Negative: cumbersome code, init() can be invoked by other functions

	//C++ 11 solution
	class dog(){
		int age = 9; // can now be initialized in class
	public:
		dog(){ ...; }
		dog(int a) : dog() { doOtherThings(); }
	}//dog default constructor now called, must be called before other functions
}

void foo(int i){ cout << "foo_int\n\n"; }
void foo(char *a){ cout << "foo_char\n\n"; }]

void seven(){

}
==> ./Projects/c++27 dynamic arrays/c++27 dynamic arrays/main.cpp <==
#include <iostream>

using namespace std;

int main(){
	int *dArray;

	dArray = new int[5];

	dArray[0] = 4;
	dArray[1] = 3;
	dArray[2] = 2;
	dArray[3] = 1;

	for (int i = 0; i < 4; i++){
		cout << dArray[i] << "... ";
	}

	delete []dArray;
	cout << endl << dArray << endl;

	dArray = NULL; //destroys remnant trace integer
	cout << endl << dArray << endl;
}


==> ./Projects/c++28 recursion/c++28 recursion/main.cpp <==
#include <iostream>

using namespace std;

void counter(int);
//counter - increments/decrements up to/downfrom a variable greater than one
//@param int - variable to be deremented/incremented to

int factorial(int);
//factorial - returns factorial of input
//@param int - input number to be used for factorial
//@return int - factorial of input integer

int main(){
	counter(7);
	cout << endl << "factorial: " << factorial(7) << endl;
	return 0;
}

void counter(int count){
	if (count >= 1){
		cout << count << " "; //decrement 
		counter(count - 1);
	}
	cout << count << " "; //increment
}

int factorial(int fact){
	if (fact > 1){
		return fact * factorial(fact - 1);
	}
	else{
		return 1;
	}
}
==> ./Projects/Change Due/Change Due/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/char array to string/char array to string/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	char Myarray[] = "Leslie is an awesome fellow... CoæÆôöol, 'eloquÑent', 1well-read, tall, tall, knows how to dress e3nd.";
	string *Word;
	string *Word2;
	int *Money;
	int *Money2;
	int Array = 1;

	Money = new int[Array];
	Money2 = new int[Array];

	for (int x = 0; x < Array; x++){
		Money[x] = 0;
		Money2[x] = 0;
	}
	
	Word = new string[Array];
	Word2 = new string[Array];
	int n = 0;
	int d = 0;
	int a = 0;

	for (n = 0; n < Array; n++){
		Word = new string[Array];
		Money = new int[Array];
		for (int x = 0; x < Array; x++){
			Money[x] = 0;
		}
		for (int k = 0; k < n; k++){
			Word[k] = Word2[k];
			Money[k] = Money2[k];
		}
		while (a < 130){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case (char)39:
				int b = 0;
				int c = 0;
				if ((Myarray[a - 1] >= 'A') && (Myarray[a - 1] <= 'z')){
					do{
						if ((Myarray[d] >= 'A') && (Myarray[d] <= 'z')){
							for (b = d; b < a; b++){
								Word[n] = Word[n] + Myarray[b];
							}
						}
						else d++;
					} while (b < a);
					d = a + 1;
					if (Word[n] == "s"){
						Word[n].clear();
					}
					else{
						cout << "Word [" << n << "] = " << Word[n] << endl;
					}
					for (c = 0; c < n; c++){
						if (Word[n] == Word[c]){
							Word[n].clear();
							Money[c]++;
							c = n + 1;
							n--;
						}
					}
					if (c == n){
						Money[n] = Money[n] + 1;
					}
				}
				if (b > 0){
					a = 131;
					Array++;
				}
			}
		}
		a = d;
		n++;
		Word2 = new string[Array];
		Money2 = new int[Array];
		for (int x = 0; x < Array; x++){
			Money2[x] = 0;
		}
		for (int k = 0; k < n; k++){
			Word2[k] = Word[k];
			Money2[k] = Money[k];
		}
		while (a < 130){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case (char)39:
				int b = 0;
				int c = 0;
				if ((Myarray[a - 1] >= 'A') && (Myarray[a - 1] <= 'z')){
					do{
						if ((Myarray[d] >= 'A') && (Myarray[d] <= 'z')){							
							for (b = d; b < a; b++){
								Word2[n] = Word2[n] + Myarray[b];
							}
						}
						else {
							d++;
						}
					} while (b < a);
					d = a + 1;
					if (Word2[n] == "s"){
						Word2[n].clear();
					}
					else{
						cout << "Word [" << n << "] = " << Word2[n] << endl;
					}
					for (c = 0; c < n; c++){
						if (Word2[n] == Word2[c]){
							Word2[n].clear();
							Money2[c]++;
							c = n + 1;
							n--;
						}
					}
					if (c == n){
						Money2[n] = Money2[n] + 1;
					}
				}
				if (b > 0){
					a = 131;
					Array++;
				}
			}
		}
		a = d;
	}
			
	return 0;
}


		
			
		
	

	/*Array--;

	if (n % 2){
		for (int x = 0; x < Array; x++){
			cout << Word[x];
		}
	}
	else{
		for (int x = 0; x < Array; x++){
			cout << Word2[x] << " ";
		}
	}

	
	/*while (a < 115){
		a++;
		switch (Myarray[a]){
		case ' ':
		case '?':
		case '!':
		case ',':
		case '.':
		case '"':
		case '-':
		case (char)39:
			int b = 0;
			int c = 0;
			if ((Myarray[a - 1] >= 'A') && (Myarray[a - 1] <= 'z')){
				do{
					if ((Myarray[d] >= 'A') && (Myarray[d] <= 'z')){
						for (b = d; b < a; b++){
							Word[n] = Word[n] + Myarray[b];
						}
					}
					else d++;
				} while (b < a);
				d = a + 1;
				a = b;
				if (Word[n] == "s"){
					Word[n].clear();
				}
				else{
					cout << "Word [" << n << "] = " << Word[n] << endl;
				}
				for (c = 0; c < n; c++){
					if (Word[n] == Word[c]){
						Word[n].clear();
						Money[c]++;
						c = n + 1;
					}
				}
				if (c == n){
				Money[n] = Money[n] + 1;
				n++;
				}
			}
			
		}
	}

	cout << "Money[9] = " << Money[9] << endl;

	
	int M[18];
	int Most = 0;

	for (int a = 0; a < 18; a++){
		M[a] = -1;
	}

	for (int a = 0; a < 18; a++){
		if (Money[a] >= Most){
			Most = Money[a];
			if (a != 0){
				for (int b = a; b > 0; b--){
					M[b] = M[b - 1];
				}
			}
			M[0] = Most;
		}
		else{
			for (int b = 0; b < a; b++){
				if (Money[a] >= M[b]){
					for (int c = a; c > b; c--){
						M[c] = M[c - 1];
					}
					M[b] = Money[a];
					b = 18;
				}
			}
		}
	}

	/*cout << "\nThe ordered matrix is now :\n";
	for (int a = 0; a < 18; a++){
		cout << M[a] << " ";
	}*/

	//cout << "n = " << n << endl;
	/*for (int n = 0; n < 7; n++){
		if ((Myarray[n] >= 'A') && (Myarray[n] <= 'z')){
		Myarray1 = Myarray1 + Myarray[n];
		cout << Myarray1 << endl;
		}
		}*/

	
==> ./Projects/char array to string/Vector descending orde/Vector descending orde/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N[18];
	int M[18];
	int Most = 0;

	for (int a = 0; a < 18; a++){
		cout << "Please enter value for N [" << a << "] : ";
		cin >> N[a];
		M[a] = -1;
	}

	for (int a = 0; a < 18; a++){
		if (N[a] >= Most){
			Most = N[a];
			if (a != 0){
				for (int b = a; b > 0; b--){
					M[b] = M[b - 1];
				}
			}
			M[0] = Most;
		}
		else{
			for (int b= 0; b < a; b++){
				if (N[a] >= M[b]){
					for (int c = a; c > b; c--){
						M[c] = M[c - 1];
					}
					M[b] = N[a];
					b = 18;
				}
			}
		}
	}

	cout << "\nThe ordered matrix is now :\n";
	for (int a = 0; a < 18; a++){
		cout << M[a] << " ";
	}

	return 0;
}
==> ./Projects/char -test/char -test/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	char A;
	double count1, count2, count3, count4, i, B, totalcount;
	int count1a, count2a, count3a, count4a, B1, B2, total;
	A = '*';
	i = 0;
	count1 = 0;
	count1a = 0;
	count2 = 0;
	count2a = 0;
	count3 = 0;
	count3a = 0;
	count4 = 0;
	count4a = 0;

	cout << "At the prompt please enter a students grade between 0 and 100. Press enter." << endl;
	cout << "Entering a mark greater than 100 will end the program" << endl;
	cout << " " << endl;
	cout << "Please enter student's grade (0-100): ";
	cin >> B;
	B1 = 0;
	B2 = 100;
	total = 0;

	while (B < 100){
		if ((B >= 0) && (B < 30)){
			count1++;
			total = total + B;
		}
		else if ((B >= 30) && (B < 40)){
			count2++;
			total = total + B;
		}
		else if ((B >= 40) && (B < 70)){
			count3++;
			total = total + B;
		}
		else if (B >= 70){
			count4++;
			total = total + B;
		}
		cout << endl;
		if (B > B1){
			B1 = 0 + B;
		}
		if (B < B2){
			B2 = 0 + B;
		}
		cout << "Please enter student's grade (0-100): ";
		cin >> B;		
		cout << endl;
	}

	if (B > 100){
		cout << "0-29:   ";
		while (count1a < count1){
			cout << A;
			count1a++;
		}
		cout << " " << endl;
		cout << "30-39:  ";
		while (count2a < count2){
			cout << A;
			count2a++;
		}
		cout << " " << endl;
		cout << "40-69:  ";
		while (count3a < count3){
			cout << A;
			count3a++;
		}
		cout << " " << endl;
		cout << "70-100: ";
		while (count4a < count4){
			cout << A;
			count4a++;
		}
		cout << " " << endl;
		totalcount = count1 + count2 + count3 + count4;
		cout << totalcount << " students total." << endl;
		cout << " " << endl;
		cout << "Average mark = " << fixed << setprecision(1) << total / totalcount << endl;
		cout << " " << endl;
		cout << "Number of students passing = " << count3a + count4a << endl;
		cout << " " << endl;
		cout << "Highest mark = " << B1 << endl;
		cout << " " << endl;
		cout << "Lowest mark = " << B2 << endl;
		cout << " " << endl;
	}

	return 0;
}
==> ./Projects/character arrays and string handling/character arrays and string handling/Source.cpp <==
#include <iostream>

using namespace std;

char str[] = { 'a', 'b', 'c', 0, 'e', '\n', 'g', 'h', 0 };

int main(){
	cout << str;
	char abc[3] = { 'd' };
	cout << endl << endl << str;
	return 0;
}
==> ./Projects/Coliterals/Coliterals/Source.cpp <==
#include <iostream>

using namespace std;

int main() {
	cout << "The sum of one plus three is " << 1 + 3 << '\n'; //integer literal
	cout << "First letter of the alphabet is " << 'A' << '\n'; //char literal
	cout << "one point one plus three point two is " << 1.1 + 3.2 << '\n'; //floating point literal, defined as either 'float' or 'double'
	return 0; 
}
==> ./Projects/collaborating programmes/collaborating programmes/Source.cpp <==
/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	double *Data;
	ofstream MyFile;
	char FileName[100];
	int N, k;
	cout << "The name of the file: ";
	cin.getline(FileName, 100, '\n');
	MyFile.open(FileName, ios::binary);
	if (!MyFile.is_open()){
		cout << "Could not open this file\n";
		return 1;
	}
	do{
		cout << "The length of array N = ";
		cin >> N;
	} while (N < 1);
	Data = new double[N];
	for (k = 0; k < N; k++){
		cout << "Data[" << k << "]= "; 
		cin >> Data[k];
	}
	MyFile.write(reinterpret_cast<char *>(Data), N*sizeof(double));
	MyFile.close();
	delete[] Data;
	Data = nullptr;
	return 0;
}*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double *Data;
	ifstream MyFile;
	char FileName[100];
	int N, k;
	streamoff Start, Fin; //stream offset position (found in <fstream>)
	cout << "The name of the file";
	cin.getline(FileName, 100, '\n');
	MyFile.open(FileName, ios::binary);
	if (!MyFile.is_open()){
		cout << "Could not open this file\n";
		return 1;
	}
	MyFile.seekg(0, ios::end); //Finds stream offset position for end of file
	Fin = MyFile.tellg(); //defines variable "Fin" as stream offset position for end of file
	MyFile.seekg(ios::beg);
	Start = MyFile.tellg();
	N = (Fin - Start) / sizeof(double);
	Data = new double[N];
	MyFile.read(reinterpret_cast<char *>(Data), N*sizeof(double));
	MyFile.close();
	for (k = 0; k < N; k++){
		cout << "Data[" << k << "]= " << Data[k] << endl;
	}
	delete[] Data;
	Data = nullptr;
	return 0;
}
==> ./Projects/collaborating programmes/collaborating programmes/Source1.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double *Data;
	ifstream MyFile;
	char FileName[100];
	int N, k;
	streamoff Start, Fin; //stream offset position (found in <fstream>)
	cout << "The name of the file";
	cin.getline(FileName, 100, '\n');
	MyFile.open(FileName, ios::binary);
	if (!MyFile.is_open()){
		cout << "Could not open this file\n";
		return 1;
	}
	MyFile.seekg(0, ios::end); //Finds stream offset position for end of file
	Fin = MyFile.tellg(); //defines variable "Fin" as stream offset position for end of file
	MyFile.seekg(ios::beg);
	Start = MyFile.tellg();
	N = (Fin - Start) / sizeof(double);
	Data = new double[N];
	MyFile.read(reinterpret_cast<char *>(Data), N*sizeof(double));
	MyFile.close();
	for (k = 0; k < N; k++){
		cout << "Data[" << k << "]= " << Data[k] << endl;
	}
	delete[] Data;
	Data = nullptr;
	return 0;
}
==> ./Projects/collaborating programmes1/collaborating programmes1/Source.cpp <==
/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
double *Data;
ofstream MyFile;
char FileName[100];
int N, k;
cout << "The name of the file : ";
cin.getline(FileName, 100, '\n');
MyFile.open(FileName, ios::binary);
if (!MyFile.is_open()){
cout << "Could not open this file\n";
return 1;
}
do{
cout << "The length of array N = ";
cin >> N;
} while (N < 1);
Data = new double[N];
for (k = 0; k < N; k++){
cout << "Data[" << k << "]= ";
cin >> Data[k];
}
MyFile.write(reinterpret_cast<char *>(Data), N*sizeof(double));
MyFile.close();
delete[] Data;
Data = nullptr;
return 0;
}*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double *Data;
	ifstream MyFile;
	char FileName[100];
	int N, k;
	streamoff Start, Fin; //stream offset position (found in <fstream>)
	cout << "The name of the file : ";
	cin.getline(FileName, 100, '\n'); //input name of the file
	MyFile.open(FileName, ios::binary);
	if (!MyFile.is_open()){
		cout << "Could not open this file\n";
		return 1;
	}
	MyFile.seekg(0, ios::end); //Finds stream offset position for end of file
	Fin = MyFile.tellg(); //defines variable "Fin" as stream offset position for end of file
	MyFile.seekg(ios::beg);
	Start = MyFile.tellg();
	N = (Fin - Start) / sizeof(double);
	Data = new double[N];
	MyFile.read(reinterpret_cast<char *>(Data), N*sizeof(double)); //stores file read in contents in double array Data
	MyFile.close();
	for (k = 0; k < N; k++){
		cout << "Data[" << k << "]= " << Data[k] << endl;
	}
	delete[] Data;
	Data = nullptr;
	return 0;
}


==> ./Projects/comma operator/comma operator/Source.cpp <==
//if there is a need to put two or more expressions where the last one returns the
//value to be used in the operation, these can be separated by commas rather than semicolons

res = (a = 1, b = 2, c = 20);

//is equivalent to

a = 1; b = 2; c = 20; res = c;

//however

res = (a = 1; b = 2; c = 20);
//is incorrect and will result in a compiler error

==> ./Projects/comparing null-terminated strings/comparing null-terminated strings/Source.cpp <==
//Any two strings can be compared using strcmp() function//The function returns :
//A negative int number if the first string is smaller than the second one;
//Zero int number if both strings are identical
//A positive int number if the first string is larger than the second one.

#include <iostream>

char String1[] = "abc";
char String2[] = "ABC";
char String3[] = "ABCD";

using namespace std;

int main(){
	cout << "The ASCII code for 'a' is " << static_cast<int>('a') << endl;
	cout << "The ASCII code for 'A' is " << static_cast<int>('A') << endl;
	cout << "Comparing " << String1 << " with " << String2 << ".  Result:\t" << strcmp(String1, String2) << endl;
	cout << "Comparing " << String1 << " with " << String1 << ".  Result:\t" << strcmp(String1, String1) << endl;
	cout << "Comparing " << String2 << " with " << String2 << ".  Result:\t" << strcmp(String2, String2) << endl;
	cout << "Comparing " << String3 << " with " << String2 << ". Result:\t" << strcmp(String3, String2) << endl;
	cout << "Comparing " << String1 << " with " << String3 << ". Result:\t" << strcmp(String1, String3) << endl;
	return 0;
}
==> ./Projects/conditional operator/conditional operator/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int a(4), b(5), Biggernumber;

	//conditional operator consists one boolean expression separated with a question mark
	//followed by two rvalues separated by a colon
	
	Biggernumber = a > b ? a : b;

	//equiv to 
	//if (a>b)
	//		{Biggernumber = a;}
	//else
	//      {Biggernumber = b;}


	cout << Biggernumber << endl;
	return 0;
}
==> ./Projects/conditional operator1/conditional operator1/Source.cpp <==
#include <iostream>

using namespace std;

//conditional operator:
//statement 1 ? statement 2 : statement 3
//if statement 1 is true execute statement 2
//if statement 1 is false execute statement 3

int main()
{
	int x = 10, y;

	y = x > 9 ? 100 : 200;
	cout << "y1 = " << y << endl;

	y = x < 9 ? 100 : 200;
	cout << "y2 = " << y << endl;

	return 0;
}
==> ./Projects/ConsoleApplication1/ConsoleApplication1/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/ConsoleApplication10/ConsoleApplication10/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

int main(){
	string FirstName = "Bob";
	string LastName = "Smith";
	char Middle = 'K';

	cout << FirstName + " " + Middle + " " + LastName << '\n';
	cout << LastName + " " + FirstName + " " + Middle << '\n';
	return 0;

}
==> ./Projects/ConsoleApplication11/ConsoleApplication11/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int count;
	int number;
	int number1;
	int number2;
	
	for (count = 0; count < 5; count++) {
		cout << "Please input number " << '\n';
		cin >> number;
		number1 = number++ - 2; //number incremented after it's used in expression
		number--; //number restored to original value
		number2 = ++number - 2; //number incremented before used in expression 

		cout << "number 1 is " << number1 << '\n';
		cout << "number 2 is " << number2 << '\n';
	}
	return 0;
}
==> ./Projects/ConsoleApplication11/ConsoleApplication11/Source1.cpp <==

==> ./Projects/ConsoleApplication11/ConsoleApplication11/Source2.cpp <==
#include <iostream>

using namespace std;

int main(){
	cout << "remaihnder of ten divided by two is " << 10 / 2 << '\n';
	cout << "remainder of ten divided by three is " << 10 / 3 << '\n';
	return 0;
}
==> ./Projects/ConsoleApplication12/ConsoleApplication12/shell1.cpp <==
// Program Shell1 prints appropriate messages based on a grade read from the keyboard.

#include <iostream>

using namespace std;
int main() {
	int grade;
	cout << "Enter an integer grade between 50 and 100. Press return. " << '\n';
	cin >> grade; '\n';

	if (grade >= 80) 
		cout << "Congratulations!" << endl;
	else if (70 <= grade < 80)
		cout << "Not bad..." << endl;
	else  
		cout << "Try harder" << endl;
	return 0;
}
==> ./Projects/ConsoleApplication12/ConsoleApplication12/Source.cpp <==
// Program Shell1 prints appropriate messages based on a grade read from the keyboard.

#include <iostream>

using namespace std;
int main() {
	int grade;
	cout << "Enter an integer grade between 50 and 100. Press return. " << '\n';
	cin >> grade; '\n';

	if (grade >= 80) 
		cout << "Congratulations!" << endl;
	else if (70 <= grade < 80)
		cout << "Not bad..." << endl;
	else  
		cout << "Try harder" << endl;
	return 0;
}
==> ./Projects/ConsoleApplication13/ConsoleApplication13/Source.cpp <==
#include <iostream>

using namespace std;
int main() {
	int grade;
	cout << "Enter an integer grade between 50 and 100. Press return. " << '\n';
	cin >> grade; '\n';

	if (grade >= 80){
		cout << "Congratulations!" << endl;
	}
	else if ((grade >= 70) && (grade < 80)){
		cout << "Not bad..." << endl;
	}
	else
	{
		cout << "Try harder!" << endl;
	}
	return 0;
}
==> ./Projects/ConsoleApplication14/ConsoleApplication14/Source.cpp <==
//prints appropriate messages based on a pressure reading input from the keyboard 

#include <iostream>

using namespace std;

int main() {
	int pressure;

	cout << "enter an integer pressure reading." << '\n';
	cin >> pressure;


}
==> ./Projects/ConsoleApplication15/ConsoleApplication15/Source.cpp <==
//prints appropriate messages based on a pressure reading input from the keyboard

#include <iostream>

using namespace std;

int main() {
	int pressure;

	cout << "Enter an integer pressure reading: " << endl;
	cin >> pressure;
	if (pressure > 100){
		cout << "Warning!! Pressure reading above the danger limit." << endl;
	}
	else if ((pressure > 5) && (pressure <= 100)){
		cout << "Everything seems normal. " << endl;
	}
	return 0;
	}
==> ./Projects/ConsoleApplication16/ConsoleApplication16/Source.cpp <==
//Shell3 calculates a person's percentage of calories from fat
//and prints an appropriate message.

#include <iostream>
#include <string>

using namespace std;

int main(){
	string foodItem;
	int GramsOfFat, Calories, CalfromFat;
	float FatCalPercent;
	string yourchoice;

	cout << "Enter the name of a food item. Press return. " << endl;
	getline(cin, foodItem);
	cout << " " << endl;

	cout << "Enter the grams of fat: " << endl;
	cin >> GramsOfFat;
	cout << " " << endl;

	cout << "Enter the number of calories: " << endl;
	cin >> Calories;
	cout << " " << endl;

	CalfromFat = GramsOfFat * 9;
	FatCalPercent = 100 * CalfromFat / Calories;

	cout << "Number of calories that came from fat: " << endl;
	cout << CalfromFat << " calories" << endl;
	cout << " " << endl;

	cout << "Percentage of calories that come from fat: " << endl;
	cout << FatCalPercent << "%" << endl;
	cout << " " << endl;

//If curly braces are ommitted following if statement compile error occurs as "if clause"
//considered to be the single line/statement following the "if".
//Braces can be ommitted if each clause is a single statement.

	if (FatCalPercent > 30){
		cout << "This item is NOT heart healthy!!" << endl; 
		cout << " " << endl;
	}
	else{
		cout << "This item is heart healthy! " << endl;
		cout << " " << endl;
	}

//within if statement use == instead of =, = means expression has non-zero value (true)
//expression has value zero is false

	if (GramsOfFat == 1){
		cout << "Was your item tuna? Please enter Yes/No" << endl;
		cin >> yourchoice;
		cout << " " << endl;
		if ((yourchoice == "Yes") || (yourchoice == "Y") || (yourchoice == "YES") || (yourchoice == "yes")) {
			cout << "I knew it!" << endl;
			cout << " " << endl;
		}
		else{
				cout << "You lie!" << endl;
				cout << " " << endl;
			}

//putting a null statement in an if command ";" means if does nothing
// if (GramsOfFat == 1);
//		cout << "Was your item tuna?" << endl
//
//"cout" function will always execute, disregarding the if command

		}
	return 0;	
}

==> ./Projects/ConsoleApplication17/ConsoleApplication17/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double x, y, A, S, M, D, Q;
	char W;

	cout << "Please enter variable x : ";
	cin >> x;
	cout << " " << endl;

	cout << "Please enter variable y : ";
	cin >> y;
	cout << " " << endl;

	A = x + y;
	S = x - y;
	M = x * y;
	D = x / y;

	cout << "Please choose your option." << endl;
	cout << " " << endl;
	cout << "For addition please type 'A'. " << endl;
	cout << "For subtraction please type 'S'. " << endl;
	cout << "For multplication please type 'M'. " << endl;
	cout << "For division please type 'D'. " << endl;
	cout << "If you wish to quit this program please type 'Q'. Please press return. " << endl;
	cout << " " << endl;
	cin >> W;
	cout << " " << endl;

	if ((W == 'A')||(W=='a')){
		cout << "You have selected addition" << endl;
		cout << " " << endl;
		cout << "Your result is : " << A << endl;
		cout << " " << endl;
		cout << "Now closing program" << endl;
		cout << " " << endl;
	}
	else if ((W == 'S')||(W=='s')){
		cout << "You have selected subtraction" << endl;
		cout << " " << endl;
		cout << "Your result is : " << S << endl;
		cout << " " << endl;
		cout << "Now closing program" << endl;
		cout << " " << endl;
	}
	else if ((W == 'M')||(W=='m')){
		cout << "You have selected multiplication" << endl;
		cout << " " << endl;
		cout << "Your result is : " << M << endl;
		cout << " " << endl;
		cout << "Now closing program" << endl;
		cout << " " << endl;
	}
	else if ((W == 'D')||(W=='d')){
		cout << "You have selected division" << endl;
		cout << " " << endl;
		cout << "Your result is : " << D << endl;
		cout << " " << endl;
		cout << "Now closing program" << endl;
		cout << " " << endl;
	}
	else{
		cout << "Now closing program" << endl;
		cout << " " << endl;
	}
	return 0;
	}






==> ./Projects/ConsoleApplication18/ConsoleApplication18/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int i;

	for (i = 3; i <= 10; i++){
		cout << "i = " << i << endl;
	}
	return 0;
}
==> ./Projects/ConsoleApplication19/ConsoleApplication19/Source.cpp <==

==> ./Projects/ConsoleApplication2/ConsoleApplication2/Source.cpp <==
#include <iostream>

#include <string>

using namespace std;

int main() {
	string WarningMessage;
	string MyName;
	MyName = "Leslie";
	WarningMessage = "A Vampire is coming; Run!";
	
	cout << MyName << endl;

	cout << WarningMessage << '\n'; //Can I write anything here?
	
	return 0; //Yes
}
==> ./Projects/ConsoleApplication20/ConsoleApplication20/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double A, S, D, M, X1, X2;
	char answer, tool;
	bool isMoreToProcess;

	tool = 'E';
	
	if (tool == 'E'){
		isMoreToProcess = true;
	}

	else{
		isMoreToProcess = false;
	}

	while (isMoreToProcess == true){
		cout << "What would you like to do? \n";
		cout << " \n";
		cout << "To add two numbers type 'A' \n";
		cout << "To subtract two number type 'S' \n";
		cout << "To multiply two numbers type 'M' \n";
		cout << "To divide two numbers type 'D' \n";
		cout << " \n";
		cout << "To quit, press any other key. \n";
		cout << " \n";
		cout << "Please key in your choice : ";
		cin >> answer;
		cout << " \n";

		if (answer == 'A'){
			cout << "You have chosen addition. \n";
			cout << " \n";
			cout << "Please enter your first number : ";
			cin >> X1;
			cout << " \n";
			cout << "Please enter your second number : ";
			cin >> X2;
			cout << " \n";
			A = X1 + X2;
			cout << "The result of " << X1 << " + " << X2 << " = " << A << endl;
			cout << " \n";
		}

		else if (answer == 'S'){
			cout << "You have chosen subtraction. \n";
			cout << " \n";
			cout << "Please enter your first number : ";
			cin >> X1;
			cout << " \n";
			cout << "Please enter your second number : ";
			cin >> X2;
			cout << " \n";
			S = X1 - X2;
			cout << "The result of " << X1 << " - " << X2 << " = " << S << endl;
			cout << " \n";
		}

		else if (answer == 'M'){
			cout << "You have chosen multiplication. \n";
			cout << " \n";
			cout << "Please enter your first number : ";
			cin >> X1;
			cout << " \n";
			cout << "Please enter your second number : ";
			cin >> X2;
			cout << " \n";
			M = X1 * X2;
			cout << "The result of " << X1 << " * " << X2 << " = " << M << endl;
			cout << " \n";
		}

		else if (answer == 'D'){
			cout << "You have chosen division. \n";
			cout << " \n";
			cout << "Please enter your first number : ";
			cin >> X1;
			cout << " \n";
			cout << "Please enter your second number : ";
			cin >> X2;
			cout << " \n";
			D = X1 / X2;
			cout << "The result of " << X1 << " / " << X2 << " = " << D << endl;
			cout << " \n";
		}

		else {
			cout << "Thank you for using this program \n";
			isMoreToProcess = false;
			cout << " \n";
		}
	}

	return 0;
}
==> ./Projects/ConsoleApplication21/ConsoleApplication21/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	long const int i = 11111111111;
	int a = 2;
	int k = 0;
	int j = i % a;
	for (a = 2; a < 6000; a++){
		int j = i%a;
		if (j = 0){
			cout << a << " is a factor of 11111" << a << endl;
			k++;
		}
	}
	if (k == 0){
		cout <<  i << " is a prime number" << endl;
	}
	return 0;
}
==> ./Projects/ConsoleApplication22/ConsoleApplication22/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
private:
	int age;
	string name;
public:
	Human(){
		cout << "You have created an object of type Human \n";
		name = "noname";
		age = 0;
	}
	void setAge(int n){
		age = n;
	}
	void setName(string s){
		name = s;
	}
	void display(){
		cout << "Name is " << name << endl;
		cout << "Age is " << age << "\n\n";
	}
};

int main(){
	Human leslie;
	leslie.display();
	leslie.setAge(29);
	leslie.display();
	leslie.setName("Leslie");
	leslie.display();
	return 0;
}
==> ./Projects/ConsoleApplication3/ConsoleApplication3/Source.cpp <==
# include <iostream>

using namespace std;

int main() {
	double NormalRate;
	double NormalHours;
	double OvertimeRate;
	double HoursWorked;
	double Wages;
	double OvertimeHours;

	NormalHours = 40.0;
	NormalRate = 5.00;
	OvertimeRate = 8.00;
	cin >> HoursWorked;
	OvertimeHours = HoursWorked - NormalHours;

		//IF HoursWorked > NormalHours then:
		//Wages = NormalHours * NormalRate + (HoursWorked - NormalHours) * OvertimeRate;
		//ELSE:
		//Wages = HoursWorked * NormalRate

	cout << OvertimeHours << '\n';
IF: 
	HoursWorked > NormalHours;
	Wages = (OvertimeHours * OvertimeRate) + (NormalHours * NormalRate);
ELSE:
	Wages = HoursWorked * NormalRate;
	
cout << "Wages = " << Wages << '\n';
	return 0;

}
==> ./Projects/ConsoleApplication4/ConsoleApplication4/Source.cpp <==
#include <iostream>
using namespace std;
int main(){
	int howmany, count, value;

	cout << "Enter how many numbers to process: ";
	cin >> howmany; //howmany = Fixed-value

	for (count = 0; count < howmany; count++){ //count = Stepper
		cout << "Enter value: ";
		cin >> value; // value = Most-Recent-Holder
		cout << "Two times " << value << " is " << 2 * value << '\n';
	}
	return 0;
}

//loop repeatedly asks user to enter
//a number that is stored in variable value
//until the numbers entered equal
//the value stored in howmany
==> ./Projects/ConsoleApplication5/ConsoleApplication5/Source.cpp <==
#include <iostream>

using namespace std;

int main(){

	int n;

	n = 6;
	cout << n << " cube is " << n*n*n << endl;
	return 0;
}
==> ./Projects/ConsoleApplication6/ConsoleApplication6/Source.cpp <==
//sumprod program 
#include <iostream>

using namespace std;

const int INT1 = 20;
const int INT2 = 8;

int main() {
	cout << "The sum of " << INT1 << " and " << INT2 << " is " << INT1 + INT2 << endl;
	return 0;
}
==> ./Projects/ConsoleApplication7/ConsoleApplication7/Source.cpp <==

==> ./Projects/ConsoleApplication8/ConsoleApplication8/Source.cpp <==

==> ./Projects/ConsoleApplication9/ConsoleApplication9/Source.cpp <==

==> ./Projects/constant pointer to constant/constant pointer to constant/Source.cpp <==
//When both the pointer is constant and the variable pointed to is also constant none of these can be changed

#include <iostream>
#include <iomanip>

using namespace std;

const char* const ptrA = "Hello World!";

int main(){
	int k(0);
	while (ptrA[k]){
		cout << ptrA[k++];
	}
	cout << endl << ptrA;
	return 0;
}
==> ./Projects/constants+variables/constants+variables/Source.cpp <==
#include <iostream>

using namespace std;

int main() {

	const double Pi = 3.142;
	double radius;
	double Area, Circumference;

	cin >> radius;
	Area = Pi * radius * radius;
	Circumference = 2 * Pi * radius;
	

	cout << "Area is " << Area << '\n';
	cout << "Circumference is " << Circumference << '\n';
	return 0;
}

//rules for creating constant 
// const double radius = 2
// const <type> <identifier> = <value>;

//some c++ compilers recognize only first 32 characters of an identifier
==> ./Projects/continue statement while loop/continue statement while loop/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int j = 40;
	while (j < 80)
	{
		j = j + 10;
		if (j == 60)
		{
			continue;
		}
		cout << "j is " << j << endl;
	}
	cout << "We are out of the loop.\n";
	return 0;
}
==> ./Projects/control statements in C (while loop)/control statements in C (while loop)/Source.c <==
#include <stdio.h>
#include <ctype.h>
#define EOL '\n'

main()
{
	char letter[80];
	int tag, count = 0;

	/* read in the lowercase text*/

	while ((letter[count] = getchar()) != EOL)++count;

	tag = count;

	/* write out the uppercase text */

	count = 0;

	while (count < tag) putchar(toupper(letter[count++]));
	printf("\n\n");
}
==> ./Projects/copying null-terminated strings/copying null-terminated strings/Source.cpp <==
//function has two arguments, first is the destination string, 2nd is the source
//space allocated to 1st string must be big enough to accomodate 2nd string and terminating zero

#include <iostream>

char String1[] = "To be or not to be ...";
char *String2;

using namespace std;

int main(){
	int N = strlen(String1);
	String2 = new char[N + 1];
	strcpy(String2, String1);//function strcpy_s() copies null-terminated strings
	cout << String2;
	delete[]String2;
	return 0;
}
==> ./Projects/Cotaxable-salary/Cotaxable-salary/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	float salary, incometax, NItax, grosstax, finalsalary;

	cout << "Please input your annual earnings (before tax) : ";
	cout << char(156);
	cin >> salary;
	cout << " \n";

	incometax = 0.3 * salary;
	NItax = 0.09 * salary;
	grosstax = incometax + NItax;
	finalsalary = salary - grosstax;

	cout << "Tax breakdown as follows \n";
	cout << " \n";
	cout << "                          +         - \n";
	cout << " \n";
	cout << "GROSS SALARY          : " << char(156) << salary << endl;
	cout << " \n";
	cout << "GROSS TAX             :           " << char(156) << grosstax << endl;
	cout << "  INCOME TAX          :           " << char(156) << incometax << endl;
	cout << "  N.I CONTRIBUTION    :           " << char(156) << NItax << endl;
	cout << " \n";
	cout << "EARNINGS AFTER TAX    : " << char(156) << finalsalary << endl;
	cout << " \n";
	return 0;
}
==> ./Projects/count number characters words + sentences/count number characters words + sentences/Source.cpp <==
// wordCount1.cpp

#include <iostream>

using namespace std;

char Text[120];

int main(){
	cout << "A word is a sequence of characters terminated with a\n";
	cout << "space, tab, comma, full stop or a new line\n";
	cout << "A full sentence is a sequence of words terminated with a full stop or ";
	cout << "new line \n";
	cout << "Type the text to analyse and press enter\n\n";
	cin.getline(Text, 120, '\n');

	int K(0);
	int Chrno(0), Wrdno(0), Sntno(0);
	bool WordTerminator = true;
	bool SentenceTerminator = true;
	char ch;
	while (ch = Text[K++]){
		Chrno++;
		switch (ch)
		{
		case ' ':
		case '\t':
		case ',':
			if (!WordTerminator) Wrdno++;
			WordTerminator = true;
			break;
		case'.':
		case'!':
		case'?':
			if (!SentenceTerminator) Sntno++;
			if (!WordTerminator) Wrdno++;
			SentenceTerminator = true;
			WordTerminator = true;
			break;
		default:
			SentenceTerminator = false;
			WordTerminator = false;
		}
	}
	if (!SentenceTerminator) Sntno++;
	if (!WordTerminator) Wrdno++;
	cout << "\n\n" << "this text comprises\n";
	cout << Chrno << " characters\n";
	cout << Wrdno << " words, and\n";
	cout << Sntno << " sentences\n";
	return 0;
}
==> ./Projects/creating a file (c code)/creating a file (c code)/Source.c <==
#include <stdio.h>

int gline(char*, int);

main()
{
	/*we need to specify a buffer area where data will temporarily be stored while being
	transferred between the computers memory and the ASCII file.
	
	To define the pointer that will use store the address we will use the following statement*/
	
	FILE *fp; //FILE is a type name, *fp is the pointer label that will hold the base address for file

	//syntax ptrvar = fopen(filename, mode);
	/*valid options for mode are:
	- "w": open a new file for writing to only - if filename exists will overwrite old file:
	- "r": open existing file read only
	- "a": append an existing file at the end - note if filename doesn't exist a new file will be created*/
	
	fp = fopen("data.txt", "w");

	/*fopen will return a NULL if it cannot open a file*/

	/*if ((fp = fopen("filename", "r")) == NULL)
		puts("Cannot open file \n");*/

	putc('A', fp); //writes single character to file

	/*getc(fp) reads a single character from file, if encounters end of file or ther is error will return EOF
	using the the condition that getc will return EOF when it reaches EOF We can write the following command*/

	/*char ch;

	do
	{
		ch = getc(fp);
	} while (ch != EOF);*/

	/*fgets Reads a string from a file including the newline
	Syntax: fgets(variable-string, length(integer), File-address);*/

	char C[80];
	int i = 80;

	/*do
	{
		fgets(C, i, fp);
		printf("%s", C);
	} while (fgets(C, i, fp) != NULL);*/
	
	fclose(fp); 
	
	/*function fclose breaks connection between file pointer and filename established by fopen
	This frees up the pointer for another file. It also clears the buffer used by putc*/

	return;
}

/*int gline(char * str, int bsize)
{
	if (fgets(str, bsize, fptr) == NULL)
		return 0;
	else
		return(strlen(str));
}*/
==> ./Projects/creating a file 2 (c code)/creating a file 2 (c code)/Source.c <==
#include <stdio.h>

main()
{
	FILE *ptr; //declare a pointer of type FILE
	char line[80] = "Hello, this is a test \n"; //declare array and assign the string
	ptr = fopen("data.txt", "a"); //use fopen to open file preserving existing data for appending - "a"
	fputs(line, ptr); //place string labelled line to the end of file ptr
	fclose(ptr); //close FILE ptr, releasing buffer area for another file
	return;
}
==> ./Projects/Current Account/Current Account/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	const float initialamount = 3950;
	float withdrawal, deposit, newamount;
	int b;

	cout << "Your current bank account balace is : " << char(156) << initialamount << endl;
	cout << " \n";
	cout << "Select option 1 for withdrawal, 2 for deposit and 3 to end this transaction. \n";
	cout << " \n";
	cout << "Please enter your choice : ";
	cin >> b;
	cout << " \n";

	if (b == 1){
		cout << "How much would you like to withdraw?" << endl;
		cout << char(156);
		cin >> withdrawal;
		cout << " \n";
		newamount = initialamount - withdrawal;
		cout << "Your new balance is : " << char (156) <<  newamount << endl;
		cout << " \n";
		cout << "Thank you for using this service \n";
		cout << " \n";
	}

	else if (b == 2){
		cout << "How much would you like to deposit?" << endl;
		cout << char(156);
		cin >> deposit;
		cout << " \n";
		newamount = initialamount + deposit;
		cout << "Your new balance is : " << char(156) << newamount << endl;
		cout << " \n";
		cout << "Thank you for using this service \n";
		cout << " \n";
	}

	else{
		cout << "Thank you for using this service \n";
		cout << " \n";
	}
	return 0;
}
==> ./Projects/curses/curses/Source.cpp <==

==> ./Projects/curses/curses/Source1.cpp <==
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main()
{	string insultA[100];
	string insultB[100];
	string insultC[100];
	ifstream fin;
	int i;
	int index1, index2, index3;
	int nItems;

	srand(time(NULL));

	fin.open("curses.txt");

	//load arrays
	i = 0;
	fin >> insultA[i] >> insultB[i] >> insultC[i];

	while (!fin.fail())
	{	i++;
		fin >> insultA[i] >> insultB[i] >> insultC[i];
	}
	//save the number of items stored
	nItems = i;

	//Randomly selects three indexes : 0 to nItems-1
	index1 = rand() % nItems;
	index2 = rand() % nItems;
	index3 = rand() % nItems;

	cout << "Thou " << insultA[index1] << " " << insultB[index2] << " " << insultC[index3] << "\n\n";
	return 0;
}
==> ./Projects/danceofthehours/danceofthehours/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	const double NormalHours = 40.0;
	const double NormalRate = 5.00;
	const double OvertimeRate = 8.0;
	double HoursWorked;
	double Wages;

	cin >> HoursWorked;
	if (HoursWorked > NormalHours){
		Wages = NormalHours * NormalRate + (HoursWorked - NormalHours) * OvertimeRate;
	}
	else{
		Wages = HoursWorked * NormalRate;

		cout << "Wages: " << Wages << '\n';
	}

	return 0;

}
==> ./Projects/Dangling pointer/Dangling pointer/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int *ptr1;
	int *ptr2;
	ptr2 = new int;
	*ptr2 = -5;
	ptr1 = ptr2;
	delete ptr2; //ptr1 is left dangling
	ptr2 = NULL;

	return 0;
}
==> ./Projects/data variables calculations example 1/data variables calculations example 1/Source.cpp <==
#include <iostream>

namespace Tom{
	double a;
}

namespace Carl{
	double a;
	double A;
	double b;
}
int main(){
	Tom::a = 4;
	Carl::a = 5;
	Carl::b = Tom::a / Carl::a;
	std::cout << "The Value of a in Tom namespace is " << Tom::a << std::endl;
	std::cout << "The Value of a in Carl namespace is " << Carl::a << std::endl;
	std::cout << "The Value of b in Carl namespace is " << Carl::b << std::endl;
	return 0;
}


==> ./Projects/datatest/datatest/Source.cpp <==
#include <iostream> #include <fstream> 
using namespace std;
int main()
{
	int k;
	fstream myfile;
	myfile.open("example2.txt", ios::out | ios::in);
	for (k = 42; k < 50; k++)
		myfile.write(reinterpret_cast<char *>(&k), sizeof(k));
	myfile.seekg(ios::beg);
	k = 0;
	char MyChar;
	while (myfile.read(&MyChar, 1), myfile.good())
		cout << k++ << '\t' << MyChar << '\t' << static_cast<int>(MyChar);
	cout << endl;
	return 0;
}
==> ./Projects/DAYSPENDER/DAYSPENDER/Source.cpp <==
//program tells you how to spend your day
#include <iostream>

using namespace std;

int main(){
	int day;
	char raining;

	cout << "Enter day (use 1 for Monday): " << endl;
	cin >> day;
	cout << " " << endl;

	cout << "Is it raining? (Y/N)";
	cin >> raining;
	cout << " " << endl;

	if ((day == 6) || (day == 7)){
		if (raining == 'Y'){
			cout << "Stay in bed" << endl;
			cout << " " << endl;
		}
		else{
			cout << "Play outside!" << endl;
			cout << " " << endl;
		}
	}
	else{
		cout << "Go to class.";
		if (raining == 'Y'){
			cout << " And take an umbrella";
			
		}
	}
	return 0;
}
==> ./Projects/declaring a struct variable/declaring a struct variable/Source.cpp <==
#include <iostream>

using namespace std;

struct a_person{
	char Firstname[10];
	char Surname[15];
	unsigned Age;
	unsigned Height;
	unsigned Weight;
	bool Employed;
};

struct Address{
	char StreetName[20];
	unsigned HouseNumber;
	char town[10];
	char postcode[10];
};

int main(){
	a_person MyNeighbour =
	{
		"John",
		"Bloggs",
		32,
		175,
		79,
		true,
	};

	cout << "My next door neighbour is " << MyNeighbour.Firstname;
	cout << " " << MyNeighbour.Surname;
	cout << "\nHe is " << MyNeighbour.Age << " years old, ";
	cout << MyNeighbour.Height;
	cout << "cm tall, and weighs " << MyNeighbour.Weight << "kg.\n";
	cout << "He is " << (MyNeighbour.Employed ? "employed" : "unemployed");//conditional operator -
	//comprises one boolean expression separated with a question mark, followed by two rvalues separated by a colon
	cout << ".\n\n";
	return 0;
}
==> ./Projects/Declaring Multidimensional Arrays/Declaring Multidimensional Arrays/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	const int NUM_DEPTS = 5; //mens, womens, childrens, electronics, furniture
	const int NUM_MONTHS = 12;
	const int NUM_STORES = 3; //M&S, HARRODS, NEXT

	int monthlySales[NUM_DEPTS][NUM_MONTHS][NUM_STORES];
}
==> ./Projects/diceroll program/diceroll program/Source.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int myrand(int);

int main()
{
	int dicethrow, i;
	for (i = 0; i < 10; i++)
	{
		dicethrow = myrand(6);
		cout << dicethrow << endl;
	}
	return 0;
}

int myrand(int n){
	unsigned int t;
	t = unsigned(time(0));
	srand(t);
	return rand() % n + 1;
}
//problem - every time program is called it uses the same seed
==> ./Projects/diceroll program2/diceroll program2/Source.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int myrand(int n);

int main()
{
	fstream Newfile;
	int myarray[56];
	Newfile.open("numbers.txt", ios::in | ios::out | ios::trunc);
	int dicethrow, i;
	for (i = 0; i < 55; i++){
		myarray[i] = 0;
	}
	for (i = 0; i < 144; i++)
	{
		dicethrow = myrand(55);
		cout << dicethrow << endl;
		myarray[dicethrow]++;
	}
	for (i = 0; i < 55; i++){
		Newfile << myarray[i] << endl;
	}
	Newfile.close();

	return 0;
}

int myrand(int n)
{
	unsigned int t;
	static int x = 2; //use static local variable initialised to false
	if (x == 2) 
	{
		t = unsigned(time(0));
		srand(t);
		x = 3;// call srand, then change variable
	}
	return rand() % n + 1; // return random number
}

/*problem - every time call function uses the same seed
int myrand(int n){
	unsigned int t;
	t = unsigned(time(0));
	srand(t);
	return rand() % n + 1;
}*/
==> ./Projects/Dinner/Dinner/Source.cpp <==
// Program Dinner prints out a dinner menu              // 1

#include <iostream>
#include <string>

using namespace std;

const string SALAD = "Green Salad";                            // 2
const string MEAT = "Chicken Marsala";                         // 3
const string VEGGIE = "Carrots with lemon butter";             // 4
const string STARCH = "Mashed potatoes";                       // 5
const string DESSERT = "Cake + Custard";

int main()                                                // 6
{
	string mainCourse;                                  // 7

	cout << "First course: " << SALAD << endl;       // 8
	mainCourse = MEAT + " with " + VEGGIE + " and "          // 9
		+ STARCH;                                       // 10
	cout << "Main course: " << mainCourse << endl;   // 11
	cout << "Dessert: " << DESSERT << endl;                   // 12
	cout << " \n";
	return 0;
}                                                       // 13
==> ./Projects/discovering type/discovering type/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	unsigned long long a(10);
	long long b(20);
	//type of variable or expression can be discovered using typeiD operator
	cout << typeid(a + b).name() << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/displaymenu function/displaymenu function/Source.cpp <==
#include <iostream>

using namespace std;

void DisplayMenu();
void GetChoice(int &r);

int main(){
	int choice;

	DisplayMenu();
	GetChoice(choice);
	switch (choice){
	case 1: cout << "\nHa!\n";
		break;
	case 2: cout << "\nHa!\n";
		break;
	case 3: cout << "\nV_V\n";
		break;
	case 4: cout << "\nGood choice\n";
		break;
	default: cout << "\nIncorrect choice\n";
	}

	return 0;
}

void GetChoice(int &r){
	cout << "Enter your choice, (1, 2, 3 or 4 to quit) : ";
	cin >> r;
}

void DisplayMenu(){
	cout << "**************** MENU ***************" << endl << endl;
	cout << "1.    Man United" << endl;
	cout << "2.    Chelsea" << endl;
	cout << "3.    Arsenal" << endl;
	cout << "4.    Quit" << endl << endl;
}
==> ./Projects/do-while function/do-while function/Source.cpp <==
#include <iostream>

using namespace std;

void GetYesOrNo(char &r)
{
	do
	{
		cin >> r;
		if (!((r == 'y') || (r == 'n')))
		{
			cout << "Please type y or n : ";
		}
	} while (!((r == 'y') || (r == 'n')));
}
==> ./Projects/do-while loop (C code)/do-while loop (C code)/Source.c <==
#include <stdio.h>

main()
{
	int num;
	do
	{
		scanf("%d", &num);
	} while (num < 100);

	printf("\n");

	int digit;
	for (digit = 1; digit <= 10; ++digit)
		printf("%d\n", digit);
	
	printf("\n");

	/*in the for loop we can have more than one loop control variables
	The following program prints out 0 to 8 in twos*/
	int x, y;

	for (x = 0, y = 0; x + y < 10; ++x, ++y)
		printf("%d\n", x + y);

	printf("\n");

	char ch;

	for (;;) //no initialisation, no condition, no increment
		//will cause infinite for loop
	{
		ch = getchar();
		if ((ch == 'X') || (ch = 'x')) break;
	} //if ch has value 'x' or 'X' breaks the for loop

	printf("\n");
}

==> ./Projects/do-while loop/do-while loop/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int Number;

	do {
		cout << "Enter an even integer N=";
		cin >> Number;
	} while (Number % 2); {
		cout << "You have entered N =" << Number << endl;
	}
	return 0;
}
==> ./Projects/driver program/driver program/Source.cpp <==
#include <iostream>

using namespace std;

int Max(int x, int y);

//function main DRIVER for function Max define just enough to test interface
int main(){
	int n1, n2;
	
	cout << "Enter number 1 : ";
	cin >> n1;
	cout << "\nEnter number 2 : ";
	cin >> n2;

	cout << "The maximum of " << n1 << " and " << n2 << " is " << Max(n1, n2) << "\n\n";
	return 0;
}

int Max(int x, int y)
{
	if (x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
==> ./Projects/dynamic matrix addition example/dynamic matrix addition example/Source.cpp <==
#include <iostream>
#include <iomanip>
using namespace std;

double **A;
double **B;
double **C;
int NRows, NCols;
int main()
{
	int row, col;
	do
	{
		cout << "Specify the number of rows\nNRows=";
		cin >> NRows;
	} while (NRows < 1);
	// Start allocating memory
	A = new double *[NRows];
	B = new double *[NRows];
	C = new double *[NRows];
	do
	{
		cout << "Specify the number of columns\nNCols=";
		cin >> NCols;
	} while (NCols < 1);
	for (row = 0; row < NRows; row++)
	{
		A[row] = new double[NCols];
		B[row] = new double[NCols];
		C[row] = new double[NCols];
	}
	// End of allocating memory
	cout << "Enter matrix A row by row\n";
	for (row = 0; row < NRows; row++)
	{
		cout << "Row no " << row << endl;
		for (col = 0; col < NCols; col++)
			cin >> A[row][col];
	}
	cout << "Enter matrix B row by row\n";
	for (row = 0; row < NRows; row++)
	{
		cout << "Row no " << row << endl;
		for (col = 0; col < NCols; col++)
			cin >> B[row][col];
	}
	// Add Matrices
	for (row = 0; row < NRows; row++)
		for (col = 0; col < NCols; col++)
			C[row][col] = A[row][col] + B[row][col];
	// Print results
	cout << "The matrix C is:\n";
	for (row = 0; row < NRows; row++)
	{
		for (col = 0; col < NCols; col++)
			cout << setw(5) << C[row][col];
		cout << endl;
	}
	for (row = 0; row < NRows; row++)
	{
		delete[] A[row];
		delete[] B[row];
		delete[] C[row];
	}
	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}

==> ./Projects/dynamic matrix addition/dynamic matrix addition/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double **M1, **M2, **M3 = nullptr;
	char Answer, Answer2;
	int x, y;

	cout << "Welcome to the matrix addition program\n";
	do{
		do{
			cout << "\nPlease enter the number of rows : "; cin >> x;
			cout << "Please enter the number of columns : "; cin >> y;
			cout << "You have chosen a matrix " << x << " x " << y << "\n";
			cout << "\nIs this correct? Please input (Y/N) : "; cin >> Answer;
		} while ((Answer == 'N') || (Answer == 'n'));

		M1 = new double *[x];
		M2 = new double *[x];
		M3 = new double *[x];

		for (int n = 0; n < x; n++){
			M1[n] = new double[y];
			M2[n] = new double[y];
			M3[n] = new double[y];
		}

		cout << "\nPlease enter Matrix 1  : \n\n";
		for (int n = 0; n < x; n++){
			cout << "Row number = " << n << endl;
			for (int k = 0; k < y; k++){
				cout << "Position [" << n << "][" << k << "] : ";
				cin >> M1[n][k];
			}
		}
		cout << "\n Please enter Matrix 2 : \n\n";
		for (int n = 0; n < x; n++){
			cout << "Row number = " << n << endl;
			for (int k = 0; k < y; k++){
				cout << "Position [" << n << "][" << k << "] : ";
				cin >> M2[n][k];
			}
		}

		cout << "\nMatrix 3 : ";

		for (int n = 0; n < x; n++){
			cout << "\n";
			for (int k = 0; k < y; k++){
				M3[n][k] = M1[n][k] + M2[n][k];
				cout << setw(3) << M3[n][k];
			}
		}

		delete M1, M2, M3;
		cout << "\n\nWould you to perform another calculation - please enter (Y/N) : "; cin >> Answer2;
	} while ((Answer2 == 'Y') || (Answer2 == 'y'));

	cout << "\nThank you for using this program!\n\n";

	return 0;
}
==> ./Projects/dynamic memory allocation for struct/dynamic memory allocation for struct/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

struct Box{
	double Sizes[3];
	char Contents[10];
	bool is_Full;
};

Box *MyBox;
Box *MyCollection;

int main(){
	int N = 10;
	MyBox = new Box;
	MyCollection = new Box[N];
	MyBox->Sizes[0] = 2;
	MyBox->Sizes[1] = 3;
	MyBox->Sizes[2] = 5;
	strcpy(MyBox->Contents, "Sweets");
	MyBox->is_Full = true;
	memcpy(MyCollection + 2, MyBox, sizeof(Box));
	cout << "The sizes are: "
		<< setw(3) << MyCollection[2].Sizes[0]
		<< setw(3) << MyCollection[2].Sizes[1]
		<< setw(3) << MyCollection[2].Sizes[2];
	cout << "\nThe content is: " <<
		MyCollection[2].Contents;
	cout << "\nThe box is full: "
		<< boolalpha << MyCollection[2].is_Full << endl;
	delete MyBox;
	delete[] MyCollection;
	MyCollection = nullptr;
	MyBox = nullptr;
	return 0;
}
==> ./Projects/Dynamic Structure Allocation/Dynamic Structure Allocation/Source.cpp <==
#include <iostream>

using namespace std;

struct myDataType 
{
	char name[20];
	char phoneNo[15];
	float balance;
};

myDataType *obj;

//special syntax required for dynamic structs and classes
//The "Arrow" operator -> (minus key + greater than key)

int main()
{
	obj = new myDataType;
	
	cout << "Please enter name : ";
	//cin >> obj.name doesn't work, instead
	cin >> obj->name;
	cout << "\nPlease enter phone number : ";
	//cin >> obj.phoneNo doesn't work, instead
	cin >> obj->phoneNo;
	cout << "\nPlease enter balance : ";
	//cin >> obj.balance doesn't work, instead
	cin >> obj->balance;

	return 0;
}
==> ./Projects/dynamic vector addition/dynamic vector addition/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double *Pdbl, *Pdb, *Pd(nullptr);
	int x, y;
	char Answer, Answer2;

	cout << "Welcome to the vector addition program\n";

	do{
		cout << "\nHow long do you want vector 1 to be : ";  cin >> x;
		cout << "Vector 1 is " << x << " places long, is this correct - please enter (Y/N) : "; cin >> Answer;
	} while ((Answer == 'N') || (Answer == 'n')); 
		
	do {
			cout << "\nHow long do you want vector 2 to be : ";  cin >> y;
			cout << "Vector 2 is " << y << " places long, is this correct - please enter (Y/N) : "; cin >> Answer2;
		} while ((Answer2 == 'N') || (Answer2 == 'n')); 
	
	Pdbl = new double[x];
	Pdb = new double[y];

	cout << "\nPlease enter vector 1 :\n";
	for (int n = 0; n < x; n++){
		cout << "N [" << n << "] : "; cin >> Pdbl[n];
	}
	cout << "\nPlease enter vector 2 :\n";
	for (int n = 0; n < y; n++){
		cout << "M [" << n << "] : "; cin >> Pdb[n];
	}

	cout << "\nVector 1 is : ";
	for (int n = 0; n < x; n++){
		cout << Pdbl[n] << " ";
	}

	cout << "\nVector 2 is : ";
	for (int n = 0; n < y; n++){
		cout << Pdb[n] << " ";
	}

	cout << "\n\nThe result of vector addition is \n" << "Vector 3 : ";
	if (x > y){
		Pd = new double[x];
		for (int n = 0; n < y; n++){
			Pd[n] = Pdbl[n] + Pdb[n];
			cout << Pd[n] << " ";
		}
		for (int n = y; n < x; n++){
			Pd[n] = Pdbl[n];
			cout << Pd[n] << " ";
			}
		}
	else if (y > x){
		Pd = new double[y];
		for (int n = 0; n < x; n++){
			Pd[n] = Pdbl[n] + Pdb[n];
			cout << Pd[n] << " ";
		}
		for (int n = x; n < y; n++){
			Pd[n] = Pdb[n];
			cout << Pd[n] << " ";
			}
		}
	else if (y == x){
		Pd = new double[x];
		for (int n = 0; n < x; n++){
			Pd[n] = Pdbl[n] + Pdb[n];
			cout << Pd[n] << " ";
		}
	}
	cout << endl << endl;
	delete Pd; delete Pdbl; delete Pdb;
	return 0;
}

==> ./Projects/dynamically allocated array of structures/dynamically allocated array of structures/Source.cpp <==
#include <iostream>

using namespace std;

struct mydatatype
{
	char Name[20];
	char PhoneNo[15];
	float Balance;
};

mydatatype *obj;

int main()
{
	obj = new mydatatype[5];

	//if array of struictures created dynamically, normal syntax used

	cout << "Please enter 1st name : ";
	cin >> obj[0].Name;
	cout << "\nPlease enter 1st phone number : ";
	cin >> obj[0].PhoneNo;
	cout << "\nPlease enter 1st balance : ";
	cin >> obj[0].Balance;

	cout << "\nPlease enter 2nd name : ";
	cin >> obj[1].Name;
	cout << "\nPlease enter 2nd phone number : ";
	cin >> obj[1].PhoneNo;
	cout << "\nPlease enter 2nd balance : ";
	cin >> obj[1].Balance;

	return 0;
}
==> ./Projects/enum types/enum types/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{	enum MonthType { JAN, FEB, MAR, APR, MAY, JUN,
		JUL, AUG, SEP, OCT, NOV, DEC};
	//JAN stored as 0, FEB stored as 1, DEC stored as 11. 
	MonthType thisMonth;
	MonthType lastMonth;

	lastMonth = AUG;
	thisMonth = SEP;
	cout << thisMonth << endl; // outputs as numeric value

	lastMonth = thisMonth;
	thisMonth = DEC;
	cout << thisMonth << endl;

	//thisMonth = thisMonth++ -> compile error
	thisMonth = MonthType(1); //uses type cast
	cout << thisMonth << endl;

	//enum type can be used in a switch statemen
	/*using insertion '<<' and extraction '>>' operators not defined for enumeration type
	functions can be written for this purpose*/
	//relation operators < greater than, < less than, == etc can be used with enum
	//enum can be return type of a value returning function in C++

	return 0;
}
==> ./Projects/enumeration/enumeration/Source.cpp <==

==> ./Projects/ep101 overloadin new and delete/ep101 overloadin new and delete/Source.cpp <==
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

using namespace std;

class Student : public exception{
	int age;
	string name;
public:
	Student(){
		name = "noname";
		age = 0;
	}
	Student(string name, int age){
		this->name = name;
		this->age = age;
	}
	void getName(){
		cout << "Name is " << name << endl;
	}
	void getAge(){
		cout << "Age is " << age << endl;
	}

	//requires void pointer to memory location as return type, size_t class needed for input
	void* operator new(size_t size){ 
		void *memspace = malloc(size);
		cout << "overloaed new\nsize is " << size << endl;
		if (!memspace){
			bad_alloc ba;
			throw ba;
		}
		return memspace;
	}

	void operator delete(void *memspace){ //requires void pointer to memory location as input
		cout << "overloaded delete\n";
		free(memspace);
	}
};

int main(){
	Student *leslieptr;
	try{
		leslieptr = new Student("Leslie", 29);
		leslieptr->getName();
		leslieptr->getAge();
		delete leslieptr;
	}
	catch (bad_alloc ba){
		cout << "bad memory allocation\n";
	}
}
==> ./Projects/ep102 overload input + output/ep102 overload input + output/Source.cpp <==
##include <iostream>
#include <string>

using namespace std;

class Person{
	string name;
	int age;
public:
	Person(){
		name = "noname";
		age = 0;
	}
	
	friend ostream &operator <<(ostream &output, Person &p);
	friend istream &operator >>(istream &input1, Person &p);
};

ostream &operator << (ostream &output, Person &p){
	output << "Here's my overloaded output operator\n";
	output << "Name is " << p.name << " age is " << p.age << endl;
	return output;
}

istream &operator >> (istream &input1, Person &p){
	cout << "Please enter the name and age\n";
	input1 >> p.name >> p.age;
	return input1;
}

int main(){
	Person leslie;
	cin >> leslie;
	cout << leslie;
	return 0;
}

==> ./Projects/ep102 overload inputoutput/ep102 overload inputoutput/Source.cpp <==
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Person{
	string name;
	int age;
public:
	Person(){
		name = "noname";
		age = 0;
	}

	friend ostream &operator <<(ostream &output, Person &p);
	friend istream &operator >>(istream &input1, Person &p);
};

ostream &operator << (ostream &output, Person &p){
	output << "Here's my overloaded output operator\n";
	output << "Name is " << p.name << " Age is " << p.age << endl;
	return output;
}

istream &operator >> (istream &input1, Person &p){
	cout << "Please enter the name and age\n";
	input1 >> p.name >> p.age;
	return input1;
}

int main(){
	Person leslie;
	cin >> leslie;
	cout << leslie;
	return 0;
}
==> ./Projects/ep103 copy constructor/ep103 copy constructor/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Person{
	int age;
	string *name; 
public:
	Person(int age, string name){
		cout << "Constructor called:\n";
		this->name = new string(name);
		this->age = age;
	}

	/*without this overloaded constructor a duplicate of an object of type Person
	would have the same memory address for name as it would inherit the pointer
	to the memory address and not the value stored within it*/
	Person(Person &p){
		cout << "Copy constructor called:\n";
		name = new string(*p.name);
		this->age = p.age;
	}

	void setNameandAge(string name, int age){
		*(this->name) = name;
		this->age = age;
	}

	void display(){
		cout << "My name is " << *name << " and I am " << age << " years old.\n";
	}
};

int main(){
	Person leslie(29, "Leslie");
	leslie.display();
	Person leslie2 = leslie;
	leslie2.display();
	
	leslie.setNameandAge("Leslie Tetteh", 29);
	leslie.display();
	leslie2.display(); /*had copy constructor not been defined, field "name" would 
					   store the memory adress stored in original object, and
					   *name would point to the value in that address, so would
					   also change*/
	return 0;
}
==> ./Projects/ep105 set and unset format flags/ep105 set and unset format flags/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	cout.setf(ios::showpos | ios::showpoint); //needs or symbol to execute both flags
	cout << 89.4 << endl;
	cout.unsetf(ios::showpos);
	cout << 89.4 << endl;
	auto flas = ios::showbase | ios::showpoint | ios::showpos;
	cout.flags(flas);
	cout << 1.6 << endl;
	return 0;
}

==> ./Projects/ep106 io bool as true + false/ep106 io bool as true + false/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	bool tf1;

	/*can usually be input or output only via 0 or 1*/
	//cout.setf(ios::boolalpha);

	for (int i = 0; i < 2; i++){
		cout << "Input bool value : ";
		cin >> tf1;
		cout << "Bool value is " << tf1 << endl;
	}

	cout << "Now setting boolalpha flags\n";
	cout.setf(ios::boolalpha);

	cin.setf(ios::boolalpha);

	/*can now be input and will output as true or false*/
	for (int i = 0; i < 2; i++){
		cout << "Input bool value : ";
		cin >> tf1;
		cout << "Bool value is " << tf1 << endl;
	}

	return 0;
}
==> ./Projects/ep107 precision, width, fiil/ep107 precision, width, fiil/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	cout << 4 << endl;
	cout.precision(4);
	cout << 123.456 << endl;
	
	cout.width(10);
	cout.fill('o');
	cout << "hello\n";
	cout.width(10);
	cout << "oi\n";
	cout.setf(ios::left);
	cout.width(10);
	cout.fill('o');
	cout << "hello" << endl;
	cout.setf(ios::left);
	cout.width(10);
	cout.fill('o');
	cout << "hello\n";
	cout.setf(ios::left);
	cout.width(10);
	cout << "oi\n";

	return 0;
}
==> ./Projects/ep112 file handling + opening/ep112 file handling + opening/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	fstream myfile;

	myfile.open("leslie.txt", ios::in | ios::out | ios::trunc);
	if (!myfile.is_open()){
		cout << "error opening myfile\n";
	}
	else{
		cout << "MyFile is now open\n";
		myfile.close();
	}

	ofstream newfile;

	newfile.open("newone.txt"); //default is ios::out |ios::trunc

	if (!newfile.is_open()){
		cout << "error opening newfile\n";
	}
	else{
		newfile << "I am now writing into" << endl;
		newfile << "This file, I assume the escape\n sequence will not operate.\n";
		newfile << "I was wrong.\n";
		newfile.close();
		cout << "message successfully written to newfile\n\n";
	}

	ifstream altfile;
	string line;
	altfile.open("newone.txt");

	if (!altfile.is_open()){
		cout << "error opening altfile\n";
	}
	else{
		while (altfile.good()){
			getline(altfile, line);
			cout << line << endl;
		}
		altfile.close();
	}
	
	fstream myfile1;

	myfile1.open("newone.txt", ios::out | ios::in | ios::app);
	if (!myfile1.is_open()){
		cout << "Error opening myfile\n";
	}
	else{
		cout << "myfile1 is open\n";
		myfile1 << "This is added through the append function" << endl;
		cout << "position is " << myfile1.tellg() << endl; //get function
		myfile1.seekg(0); //sends cursor to beginning of file
		cout << "position is " << myfile1.tellp() << endl; //put function 
		/*both tellp() and tellg(), retur same result, put for input and get
		for output. 
		seekg(3, ios::beg); offsets 3 from beginning of file and 
		seeks(3, ios::end); offsets 3 from end of file
		seekg(3, ios::current) offsets 3 from current position*/
		while (myfile1.good()){
			getline(myfile1, line);
			cout << line << endl;
		}
		cout << endl;
		myfile1.close();
	}

	return 0;
}
==> ./Projects/ep117 binary files/ep117 binary files/Source.cpp <==
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	char input[100];
	strcpy(input, "I am just a humble writer");

	fstream newfile("leslie.bin", ios::binary | ios::out | ios::in | ios::trunc);

	if (!newfile.is_open()){
		cout << "error opening newfile\n";
	}
	else{
		int length = strlen(input);
		for (int i = 0; i < length; i++){
			newfile.put(input[i]);
		}
		newfile.seekg(0);
		char ch;
		while (newfile.good()){
			newfile.get(ch);
			cout << ch;
		}
		newfile.close();
	}
	
	return 0;
}
==> ./Projects/ep117/ep117/Source.cpp <==
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

int main(){
	char input[100];
	//strcpy_s(input, "I am just a humble writer");

	/*Source.cpp: In function ‘int main()’:
    Source.cpp:10:9: error: ‘strcpy_s’ was not declared in this scope; did you mean ‘strcpy’?
       10 |         strcpy_s(input, "I am just a humble writer");
          |         ^~~~~~~~
          |         strcpy
	 *
	 * The error youre encountering is due to strcpy_s not being available in the standard C++ library when compiling with 
	 * g++. This function is specific to Microsofts implementation and is not part of the C++ standard
	 *
	 * If you need to use C-style strings and want a safer alternative, consider using strncpy*/

    #ifdef _MSC_VER
        strcpy_s(input, sizeof(input), "I am just a humble writer\n");
    #else
        strncpy(input, "I am just a humble writer\n", sizeof(input) - 1);
        input[sizeof(input) - 1] = '\0';
    #endif


	fstream newfile("leslie.bin", ios::binary | ios::out | ios::in | ios::trunc);

	if (!newfile.is_open()){
		cout << "error opening newfile\n";
	}
	else{
		int length = strlen(input);
		for (int i = 0; i < length; i++){
			newfile.put(input[i]);
		}
		newfile.seekg(0);
		char ch;
		while (newfile.good()){
			newfile.get(ch);
			cout << ch;
		}
		newfile.close();
	}

	return 0;
}

==> ./Projects/ep118 writing data to binary/ep118 writing data to binary/Source.cpp <==
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Person{
	char name[10];
	int age;
public:
	Person(){
		strcpy_s(name, "noname");
		age = 0;
	}
	Person(char *name, int age){
		strcpy_s(this->name, name);
		this->age = age;
	}
	void display(){
		cout << "Name is " << name << " age is " << age << endl;
	}
	void changeDetails(char *name, int age){
		strcpy_s(this->name, name);
		this->age = age;
	}
};

int main(){
	Person leslie("Leslie", 29);
	Person duplicateleslie;

	fstream newfile;
	newfile.open("peeps.bin", ios::binary | ios::in | ios::out | ios::trunc);
	if (!newfile.is_open()){
		cout << "cannot open newfile\n";
	}
	else{
		newfile.write((char *)&leslie, sizeof(Person)); 
		//type-cast into char array for write operation
		newfile.seekg(0);
		newfile.read((char *)&duplicateleslie, sizeof(Person));
		//type-cast into char arrray for write operation
		leslie.display();
		duplicateleslie.display();
		leslie.changeDetails("Tetteh", 10000);
		leslie.display();
		duplicateleslie.display();
	}

	return 0;
}
==> ./Projects/ep131 explicit specialization/ep131 explicit specialization/Source.cpp <==
#include <iostream>

using namespace std;

template <typename myType> void display(myType);
void display(int x);
template <> void display<char>(char x);
template <typename T1, typename T2> void display(T1, T2);

int main(){
	display("leslie");
	display(20);
	display('t');
	display(35.56);
	display("LESLIE", 317537);
	return 0;
}

template <typename myType> void display(myType x){
	cout << "Generic function called, x = " << x << endl;
}

void display(int x){
	cout << "int function called, x = " << x << endl;
}

/*Although above syntax can be used, below syntax allows reader to know explicit
specialization is being performed aka explicit overloading of a generic function*/
template <> void display<char>(char x){
	cout << "char function called, x = " << x << endl;
}

template <typename T1, typename T2> void display(T1 x, T2 y){
	cout << "Generic function parameter 1: " << x << endl;
	cout << "Generic function parameter 2: " << y << endl;
}

==> ./Projects/ep44 union shared memory/ep44 union shared memory/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int *pointer;
	int age = 24;

	pointer = new int;

	*pointer = 10;

	cout << *pointer << endl;

	delete pointer;

	pointer = &age;

	cout << *pointer << endl;

	return 0;
}
==> ./Projects/ep56 scope resolution operator/ep56 scope resolution operator/ep56 scope resolution operator.cpp <==
#include <iostream>
#include <string>

using namespace std;

class HumanBeing{
public : 
	string name;
	void introduce(); //function prototype must be in main body
};

void HumanBeing::introduce(){
	cout << "Hello " << name << endl;
}

int main(){
	HumanBeing leslie;
	leslie.name = "Leslie";
	leslie.introduce();

	return 0;
}
==> ./Projects/ep56 scope resolution operator/ep56 scope resolution operator/stdafx.cpp <==
// stdafx.cpp : source file that includes just the standard includes
// ep56 scope resolution operator.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

==> ./Projects/ep56 scope resolution operator/ep56 scope resolution operator/stdafx.h <==
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

==> ./Projects/ep56 scope resolution operator/ep56 scope resolution operator/targetver.h <==
#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>

==> ./Projects/ep57 - private access specifier/ep57 - private access specifier/Source.cpp <==
#include <iostream>

using namespace std;

class Human{
private :
	int age;
	int getAge(){
		return age-5;
	}
public :
	void setAge(int v){
		age = v;
	}
	void displayAge(){
		cout << "Age is " << getAge() << endl;
	}
};

int main(){
	Human leslie;
	//leslie.age = 29 cannot be setin main window
	leslie.setAge(29);
	leslie.displayAge();
	return 0;
}
==> ./Projects/ep59 Overloading class constructors/ep59 Overloading class constructors/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class HumanBeing{
private:
	string name;
	int age;
public:
	HumanBeing(string s){
		name = s;
		age = 0;
		cout << "You have created an object of type HumanBeing\nName is " << name << endl;
		cout << "Age is " << age << "\n\n";
 	}
	HumanBeing(string s, int n){
		name = s;
		age = n;
		cout << "You have created an object of type HumanBeing\nName is " << name << endl;
		cout << "Age is " << age << "\n\n";
	}
	/*Because class constructor requires arguments HumanBeing objects cannot 
	be created without arguments (input parameters)*/
};

class Human{
private:
	int age;
	string name;
public:
	Human(string s = "noname", int n = 0){
		name = s;
		age = n;
		cout << "You have created an object of type Human\nName is " << name << endl;
		cout << "Age is " << age << "\n\n";
	}
	/*Because default values for arguments have been given Human object can be 
	created without one or more of the arguments*/
	~Human(){
		cout << "Destructor called\n\n";
	}
	/*Destructor is a special member function of no return type called when
	object of type Human is deleted*/
};

int main(){
	//HumanBeing Leslie cannot be created without input parameters
	HumanBeing leslie("Leslie");
	
	HumanBeing henry("Henry", 28);
	
	Human terry(); 
	
	Human *li;
	li = new Human();
	delete li;
	
	return 0;
}
==> ./Projects/ep63 static variables and class members/ep63 static variables and class members/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

void display();

class Human{
public:
	static int counter;
	/*static class, only one regardless of copies of function*/
	Human(){
		++counter;
	}
	void display1(){
		cout << "There have been " << counter << " humans created\n\n";
	}
	static void counter1(){
		cout << "There have been " << counter << " humans created\n\n";
	}
	/*can only use static variables, no matter how many human objects are created only one
	version of static function is ever created. called using scope resolution operator*/
};

int Human::counter = 0;
/*static class member must be initialised outside of class using the scope resolution operator.*/

int main(){

	for (int i = 0; i<4; i++){
		display();
	}

	cout << "\n" << Human::counter << "\n\n";
	/*variable can be called directly using class name and scope resolution operator even if no
	member of the class has been created */

	Human leslie;
	//leslie.display1();
	
	Human john;
	Human clive;

	cout << "This is accessed via the :: scope resolution operator : " << Human::counter << "\n\n";

	Human::counter1();
	//scope resolution operator calls static function

	return 0;
}

void display(){
	static int count = 0;
	cout << "display has been called " << ++count << " times\n";
}
/*static variable stored on the heap. Does not initialize as 0 with each function call,
variable from before passed to the function.*/

==> ./Projects/ep65 friend function/ep65 friend function/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
	int age;
	string name;
	/*By default if there is no identifier for variables/functions, they remain private*/
public:
	Human(string s, int n){
		name = s;
		age = n;
	}

	friend void display(Human h);
	/*friend function can use private members of class*/
	friend class Register;
	/*friend class can use members of class*/
};

void display(Human h){
	cout << "Human's name is " << h.name << "\nHuman's age is " << h.age << "\n\n";
}

int main(){

	Human leslie("Leslie", 29);
	display(leslie);

	return 0;
}


==> ./Projects/ep66 inheritance/ep66 inheritance/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

//Human is base class
class Human{
private:
	float height;
	/*private members not available in sub-class*/
protected:
	string name;
	/*protected members accessible in sub-classes, otherwise functions like a private
	class and is not accessible in main i.e. Human leslie; leslie.name = "Leslie"; not allowed*/
public:
	int age;
	void setAge(int n){
		age = n;
	}
	void setName(string s){
		name = s;
	}
};

//Student is sub-class
class Student : public Human{
	/*colon signifies inheritance, will inherit all public/protected, and set public methods as public*/
public:
	int id;
	void setId(int n){
		id = n;
	}
	void display(){
		cout << "Student's name is " << name << "\nStudent's age is " << age << " years old\n";
			cout << "Student's ID is " << id << endl;
	}
};

int main(){
	Student leslie;

	leslie.setAge(29);
	leslie.setName("Leslie");
	leslie.setId(1111);
	leslie.display();
	return 0;
}
==> ./Projects/ep70 protected inheritance/ep70 protected inheritance/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
protected:
	int age;
	string name;
public:
	float gpa;
	void setName(string s){
		name = s;
	}
	void setAge(int n){
		age = n;
	}
};

/*Human public members become protected members of Student sub-class. i.e.
available in class, but not outside of class Student, available to subclasses of class Student*/
class Student : protected Human{
public:
	void setStudentName(string s){
		name = s;
	}
	void setStudentAge(int n){
		age = n;
	}

	friend void display(Student s);
};

void display(Student s){
	cout << s.name << endl << s.age << endl;
}

//protected members of Student can be used in class
class GStudent : public Student{
	void setGPA(int n){
		gpa = n;
	}
};

int main(){
	Student leslie;
	//leslie.setName("Leslie") not available outside of class
	leslie.setStudentName("Leslie");
	leslie.setStudentAge(29);
	display(leslie);
	return 0;
}
==> ./Projects/ep71 private multiple inheritance/ep71 private multiple inheritance/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
protected:
	int age;
	string name;
public:
	void setAge(int n){
		age = n;
	}
	void setName(string s){
		name = s;
	}
};

class Form_Year{
protected:
	string form_name;
	int yeargroup;
public:
	void setForm(string s){
		form_name = s;
	}
	void setYearGroup(int n){
		yeargroup = n;
	}
};

/*all members of Human become private members of student all public members of Form_Year
become public members of student*/
class Student : private Human, public Form_Year{
public:
	// can use scope resolution operator to define inheritance for specific variables and functions
	Human::name;
	Human::setName; //function does not need curly brackets when being defined here

	void setStudentAge(int n){
		age = n; //int age can be used within student class
	}
};

class GStudent : public Student{
public:
	/*void setGStudentAge(int n){age = n;} - not possible as int age is now private member of Student class*/
	void setGStudentAge(int n){
		setStudentAge(n);
	}
};

int main(){

	GStudent leslie;
	//leslie.setStudentAge not possible as int age is private member of class Student
	leslie.setGStudentAge(29);
	leslie.setName("Leslie");
	cout << "Can access name via GStudent object : " << leslie.name << endl;
	//cout << "Cannot accces age via Gstudent object - " << leslie.age;

	return 0;
}
==> ./Projects/ep83 diamond problem in oops/ep83 diamond problem in oops/Source.cpp <==
#include <iostream>

using namespace std;

class Animal{
public:
	int weight;
	void walk(){
		cout << "animal walks\n";
	}
};

class Lion : virtual public Animal{
};

class Tiger : virtual public Animal{
};

class Liger : public Lion, public Tiger{
	int weight = 0;
};

int main(){
	Liger terry;
	terry.walk(); //without virtual inheritance walk()command is ambiguous. There will be one Animal object
	//For each of the two classes Lion and Tiger and ambiguity will result leading to runtime error
	//virtual inheritance solves that problem 

	return 0;
}
==> ./Projects/ep84 nested classes/ep84 nested classes/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
public:
	string name = "no name";

	class Address{
	public:
		int houseno = 0;
		string stname = "no street";
		string town = "no town";
	};

	Address addr;

	void display(){
		cout << name << endl << addr.houseno + " " + addr.stname << endl << addr.town << endl;
	}

};

int main(){
	Human leslie;

	Human::Address ad; //new address object created viia use of scope resolution operator
	ad.town = "Croydon";


	leslie.name = "Leslie";
	leslie.addr.houseno = 14;
	leslie.addr.stname = "Bute Road";
	leslie.addr.town = "Croydon";

	leslie.display();

	return 0;
}
==> ./Projects/ep85 local classes/ep85 local classes/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

void display();

int main(){
	display();

	//no Student objects can be created in the main window as they are a local class 
	return 0;
}

void display(){
	class Student{
	public:
		int age;
		string name;
		void display1(){
			cout << "Name is " << name << "\nAge is " << age << endl;
		}
	};

	Student leslie;
	leslie.name = "Leslie";
	leslie.age = 29;
	leslie.display1();
}
==> ./Projects/ep86 operator overloading/ep86 operator overloading/Source.cpp <==
#include <iostream>

using namespace std;

class Marks{
private:
	int intmarks;
	int extmarks;
public:
	Marks(){
		intmarks = 0;
		extmarks = 0;
	}
	Marks(int im, int em){
		intmarks = im;
		extmarks = em;
	}

	Marks operator+(Marks m){
		/*use of operator keyword and operator symbol +,-,*,/ used to create operator overloading function
		parameter used immediately before operator symbol taking as a given, so only define second parameter
		to be used as an argument*/
		Marks temp;
		temp.intmarks = intmarks + m.intmarks;
		temp.extmarks = extmarks + m.extmarks;

		return temp;
	}

	Marks operator-(Marks m);
	void display(){
		cout << "internal marks are " << intmarks << "\nexternal marks are " << extmarks << endl;
	}

};

Marks Marks::operator-(Marks m){
	// return type|class|scope resolution operator|operator keyword|operator symbol|parameter(s) 
	Marks temp;
	temp.intmarks = intmarks - m.intmarks;
	temp.extmarks = extmarks - m.extmarks;
	return temp;
}

int main(){
	Marks m1(16, 18);
	Marks m2(15, 19);

	Marks m3 = m1 + m2;
	Marks m4 = m1 - m2;

	m3.display();
	m4.display();
	return 0;
}
==> ./Projects/ep88 shorthand operator overloading/ep88 shorthand operator overloading/Source.cpp <==
#include <iostream>

using namespace std;

class Marks{
private:
	int mark;
public:
	Marks(){
		mark = 0;
	}
	Marks(int m){
		mark = m;
	}

	void operator+=(int bmark){
		mark += bmark; //mark = mark + bmark
	}

	friend void operator-=(Marks &m, int pmark);

	void display(){
		cout << "Mark is " << mark << endl;
	}

	/*Two functions below defined for when ++, -- used as a prefix ONLY*/

	friend void operator++(Marks &); //prefix form

	friend Marks operator++(Marks &, int); //postfix form

	Marks operator--(){ //prefix form
		mark -= 1;
		return *this; //returns this object (Marks object)
	}

	Marks operator--(int m){
		Marks any(*this);
		mark -= 1;
		return any;
	}
};

void operator++(Marks &m){
	++m.mark;
}

Marks operator++(Marks &m, int x){
	Marks any(m);
	m.mark += 1;
	return any;
}


void operator-=(Marks &m, int pmark){
	m.mark -= pmark;
}

int main(){
	Marks lenny(20);
	int x = 10;
	int y = 20;

	lenny += x;
	lenny.display();

	lenny -= y;
	lenny.display();

	++lenny;
	lenny.display();

	--lenny;
	lenny.display();

	lenny++;
	lenny.display();

	lenny++;
	lenny.display();

	lenny--;
	lenny--;
	lenny.display();

	return 0;
}
==> ./Projects/ep90 operator overload ++ and -- post/ep90 operator overload ++ and -- post/Source.cpp <==

==> ./Projects/ep90 operator overload ++ and -- post/source.cpp <==
#include <iostream>

using namespace std;

class Marks{
	int mark;
public:
	Marks(){
		mark = 0;
	}
	Marks(int m){
		mark = m;
	}
	void display(){
		cout << "Your mark is " << mark << endl;
	}
	
	Marks operator++(int x){
		Marks any(*this);
		mark += 1;
		return any;
	}
	
	friend Marks operator--(Marks &m, int);
};

Marks operator--(Marks &m, int x){
	Marks any(m);
	m.mark -= 1;
	return any;
}

int main(){
	Marks leslie(10);

	leslie.display();
	(leslie++).display();
	leslie.display();

	cout << "\n";
	leslie.display();
	(leslie--).display();
	leslie.display();
}

==> ./Projects/ep90 operator overload/ep90 operator overload/Source.cpp <==
#include <iostream>

using namespace std;

class Marks{
	int mark;
public:
	Marks(){
		mark = 0;
	}
	Marks(int m){
		mark = m;
	}
	void display(){
		cout << "Your mark is " << mark << endl;
	}

	Marks operator++(){ //prefix requires no int;
		mark += 1;
		return *this;
	}

	Marks operator++(int x){ //postfix requires use of int
		Marks any(*this);
		mark += 1;
		return any;
	}

	friend Marks operator--(Marks &m, int x);
	
	friend Marks operator--(Marks &m); 
};

Marks operator--(Marks &m){ //prefix uses no int
	m.mark -= 1;
	return m;
}

Marks operator--(Marks &m, int x){ //postfix operator requires use of int
	Marks any(m);
	m.mark -= 1;
	return any;
}

int main(){
	Marks leslie(10);
	leslie.display();

	cout << "\n";

	cout << "Postfix: leslie++\n";
	(leslie++).display();
	leslie.display();

	cout << "\n";

	cout << "Postfix: leslie--\n";
	(leslie--).display();
	leslie.display();

	cout << "\n";
	
	cout << "Prefix: ++leslie\n";
	(++leslie).display();
	leslie.display();

	cout << "\n";
	cout << "Prefix: --leslie\n";
	(--leslie).display();
	leslie.display();
	return 0;
}
==> ./Projects/ep91 array operator overloading/ep91 array operator overloading/Source.cpp <==
#include <iostream>

using namespace std;

class Marks{
	int mark[3];
public:
	Marks(int sub1, int sub2, int sub3){
		mark[0] = sub1;
		mark[1] = sub2;
		mark[2] = sub3;
	}

	int operator[](int position){
		return mark[position];
	}

};

int main(){
	Marks leslie(21, 34, 55);
	cout << leslie[0] << endl;
	cout << leslie[1] << endl;
	cout << leslie[2] << endl;

	int john[2][3] = {{ 1, 2, 3}, { 4, 5, 6 }};


	return 0;
}
==> ./Projects/ep95 exception handling/ep95 exception handling/Source.cpp <==
#include <iostream>
#include <exception>

using namespace std;

int main(){
	int a = 10, b = 0;

	int c;

	try{
		if (b == 0){
			throw "Cannot divide by zero"; //string referred to by const char *e
		}
		c = a / b;
		cout << "c = " << c << endl;
	}
	catch (const char *e){ //refers to string
		cout << "An exception has occurred\n\n" << e << endl;
	}

	return 0;
}
==> ./Projects/ep96 standard exception classes/ep96 standard exception classes/Source.cpp <==
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	int a = 10, b = 0, c;

	try{
		if (b == 0){
			throw runtime_error("Divide by zero has occured\n");
		}
		c = a / b;
		cout << c << endl;
	}
	catch (runtime_error &e){
		cout << "Error has occured \n\n" << e.what();
	}
	return 0;
} 
==> ./Projects/ep97 multiple catch statements/ep97 multiple catch statements/Source.cpp <==
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	int a = 10, b = 6, c = 3;
	try{
		if (a == 11){
			throw "first exception has occurred\n";
		}
		if (b != 6){
			throw runtime_error("second exception has occured");
		}
		if (c == 30){
			throw 20;
		}
		throw 26.56;
	}
	catch (const char *e){
		cout << "This should be the first exception\n" << e;
	}
	catch (int x){
		cout << "Ten + ten = " << x << endl;
	}
	catch (runtime_error x){
		cout << "This should be the second exception\n" << x.what() << endl;
	}
	catch (...){
		cout << "This occurs with all other errors\n";
	}
	return 0;
}
==> ./Projects/ep98b function throw exceptions/ep98b function throw exceptions/Source.cpp <==
#include <iostream>
#include <stdexcept>

using namespace std;

void test() throw(int, char, runtime_error){
	int a = 10, b = 6, c = 3;
	if (a != 10){
		throw 20;
	}
	if (b == 6){
		throw "Hmm...";
	}
	if (c != 3){
		throw runtime_error("Hell no");
	}
	throw 25.6;
}

int main(){
	try{
		test();
	} catch (int x){
			cout << "ok\n" << x << endl;
	}
	catch (char *x){
		cout << "alright\n" << x << endl;
	}
	catch (runtime_error x){
		cout << "fine then\n" << x.what() << endl;
	}
	catch (...){
		cout << "Right..." <<  endl;
	}
	return 0;
}
==> ./Projects/ep99 nested try catch blocks/ep99 nested try catch blocks/Source.cpp <==
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	try{
		try{
			try{
				throw "Leslie";
			}
			catch (const char *e){
				cout << "char type exception in inner block: " << e << endl;
				throw; //- will result in catch (1)
			}
			catch (...){
				cout << "Unexpected exception in inner block\n";
			}  
			//throw runtime_error("ninw"); //results in catch block (2)
		}
		catch (const char *e){
			cout << "char type exception in middle block: " << e << endl; // (1)
		}
		catch (...){
			cout << "Unexpected exception in the middle block\n"; // (2)
		}
		cout << "ok" << endl;
	}
	catch (const char *e){
		cout << "char type exception in outer block: " << e << endl; // (1)
	}
	catch (...){
		cout << "Unexpected exception in the outer block\n"; // (2)
	}

	return 0;
}

==> ./Projects/escape sequences/escape sequences/Source.cpp <==
//Esacape sequences are a sequence of two characters where the first is a backslash \
//and the second clarifies which special character is entered

\n - new line
\" - double qutation mark
\\ - backslash
\t - tab
\a - beep
\' - single quotation mark
\b - backspace
\r - carriage return

//Can be used in double and single quotation marks
==> ./Projects/example c program/example c program/Source.cpp <==

==> ./Projects/example c program/example c program/Source1.c <==
#include <stdio.h> //pre-processor instruction which begins with #
//stdio.h contains declarations for the functions getchar and putchar

#include <ctype.h>

main()
/*read an uppercase char and print out its lower case equivalent*/
{
	int lower, upper;

	upper = getchar(); //No arguments for getchar tells compiler to obtain input from the keyboard
	//resultant charcter assigned to variable upper
	
	lower = tolower(upper); //function tolower() is called, we pass "upper" value to function
	//function will then return a value of type int

	putchar(lower); //function putchar() is called. To which we pass as a parameter the int value of lower
	//putchar will display a single character on the screen
}
==> ./Projects/Example of a simple data base/Example of a simple data base/GlobalVar.h <==
#ifndef BLOBAL_VAR_H
#define BLOBAL_VAR_H

extern Record MyFriends[MaxNoRecords];
extern unsigned short NumRecords;

#endif

==> ./Projects/Example of a simple data base/Example of a simple data base/Header.h <==

==> ./Projects/Example of a simple data base/Example of a simple data base/Prog5.h <==
#ifndef PROG5_H
#define PROG5_H

struct Record
{
	char FirstName[20];
	char LastName[20];
	char TelNo[20];
	unsigned short Height;
};

#define MaxNoRecords 100

bool ReadData(char *FileName);
bool WriteData(char *FileName);
bool EnterRecord(unsigned short RecNo);
void PrintRecord(Record *Friend);
void CopyRecord(Record *Destination, Record *Source);
bool DeleteRecord(unsigned short RecNo);
extern Record MyFriends[MaxNoRecords];
extern unsigned short NumRecords;

#endif
==> ./Projects/Example of a simple data base/Example of a simple data base/Prog5a.cpp <==
#include <fstream>
#include "Prog5.h"
#include "GlobalVar.h"

bool ReadData(char *FileName)
{
	std::ifstream DataFile;
	DataFile.open(FileName);
	if (!DataFile.is_open())
		return false;
	for (NumRecords = 0; NumRecords < MaxNoRecords; NumRecords++){
		DataFile.read(reinterpret_cast<char *>(MyFriends + NumRecords), sizeof(Record));
		if (!DataFile.good())
			break;
	}
	DataFile.close();
	return true;
}

bool WriteData(char *FileName){
	std::ofstream DataFile;
	DataFile.open(FileName);
	if (!DataFile.is_open())
		return false;
	DataFile.write(reinterpret_cast<char *>(MyFriends), sizeof(Record)*NumRecords);
	bool Result = DataFile.good();
	DataFile.close();
	return Result;
}

==> ./Projects/Example of a simple data base/Example of a simple data base/Prog5c.cpp <==
#include <cstring>
#include "Prog5.h"
#include "GlobalVar.h"

#if defined(_MSC_VER)
    // If compiling with Visual Studio, use strcpy_s
    #define SSTRCPY(dest, src) \
        do { \
            strcpy_s((dest), sizeof(dest), (src)); \
        } while (0)
#else
    // Otherwise, use strncpy + manual null termination
    #define SSTRCPY(dest, src) \
        do { \
            strncpy((dest), (src), sizeof(dest) - 1); \
            (dest)[sizeof(dest) - 1] = '\0'; \
        } while (0)
#endif

void CopyRecord(Record* Destination, Record* Source){
	SSTRCPY(Destination->FirstName, Source->FirstName);
	SSTRCPY(Destination->LastName, Source->LastName);
	SSTRCPY(Destination->TelNo, Source->TelNo);
	Destination->Height = Source->Height;
}

bool DeleteRecord(unsigned short RecNo){
	if (RecNo >= NumRecords)
		return false;
	while (++RecNo < NumRecords)
		CopyRecord(MyFriends + RecNo - 1, MyFriends + RecNo);
	NumRecords--;
	return true;
}



==> ./Projects/Example of a simple data base/Example of a simple data base/Prog5d.cpp <==
#include <iostream>
#include "Prog5.h"
#include "GlobalVar.h"

using namespace std;

bool EnterRecord(unsigned short RecNo){
	if (RecNo > NumRecords || RecNo == MaxNoRecords)
		return false;
	if (RecNo == NumRecords)
		NumRecords++;
	cout << "First name: ";
	cin >> MyFriends[RecNo].FirstName;
	cout << "Surname: ";
	cin >> MyFriends[RecNo].LastName;
	cout << "Telephone number: ";
	cin >> MyFriends[RecNo].TelNo;
	cout << "Height: ";
	cin >> MyFriends[RecNo].Height;
	return true;
}

void PrintRecord(Record* Friend){
	cout << "\nFirst name: " << Friend->FirstName;
	cout << "\nSurname: " << Friend->LastName;
	cout << "\nTelephone number: " << Friend->TelNo;
	cout << "\nHeight: " << Friend->Height << endl;
	return;
}

==> ./Projects/Example of a simple data base/Example of a simple data base/Source.cpp <==
#include <iostream>
#include <iomanip>
#include "Prog5.h"

using namespace std;

Record MyFriends[MaxNoRecords];
unsigned short NumRecords(0);

int main(){
	char Cmnd;
	char FileName[30];
	unsigned short RecNo;
	while (true)
	{
		cout << "\nD - download data" << endl
			<< "U - upload data" << endl
			<< "E - enter a record" << endl
			<< "P - print a selected record" << endl
			<< "A - print all records" << endl
			<< "Q - quit" << endl
			<< "R - remove record\n\n"
			<< "Select option: ";
		cin >> Cmnd;
		switch (toupper(Cmnd))
		{
		case 'D':
			cout << "File name: ";
			cin >> FileName;
			if (ReadData(FileName))
				cout << "Data downloaded" << endl;
			else
				cout << "Error: Data not downloaded" << endl;
			break;
		case 'U':
			cout << "File name: ";
			cin >> FileName;
			if (WriteData(FileName))
				cout << "Data uploaded" << endl;
			else
				cout << "Error: Data not uploaded" << endl;
			break;
		case 'E':
			RecNo = NumRecords;
			cout << "Record number: " << RecNo << endl;
			if (EnterRecord(RecNo))
				cout << "Data updated" << endl;
			else
				cout << "Failed to update data" << endl;
			break;
		case 'P':
			cout << "Record number: ";
			cin >> RecNo;
			if (RecNo >= NumRecords)
				cout << "Use numbers between 0 and " << NumRecords - 1 << endl;
			else
				PrintRecord(MyFriends + RecNo);
			break;
		case 'A':
			for (RecNo = 0; RecNo < NumRecords; RecNo++){
				cout << "\n\nRecord number " << RecNo;
				PrintRecord(MyFriends + RecNo);
			}
			break;
		case 'Q':
			return 0;
		case 'R':
			cout << "Record number: ";
			cin >> RecNo;
			if (DeleteRecord(RecNo))
				cout << "Record removed successfully" << endl;
			else
				cout << "Cannot remove the record" << endl;
			break;
		default:
			break;
		}
	}
}


==> ./Projects/Example of a simple data base/Example of a simple data base/Source1.cpp <==

==> ./Projects/Example of a simple data base/Example of a simple data base/Source2.cpp <==

==> ./Projects/Example of a simple data base/Example of a simple data base/Source3.cpp <==

==> ./Projects/Example of a simple data base/Example of a simple data base/Source4.cpp <==

==> ./Projects/exams BASIC (Booleans)/exams BASIC (Booleans)/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/file position commands/file position commands/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream Myfile;
	for (int x = 0; x < 3; x++){
		Myfile.open("Test.txt", ios::out | ios::app);
		Myfile << "Hello World! ";

		//Letter p in the names of the tell/seek functions stands for put and the functions ending with it refer to output streams
		//Letter g in the names of the tell/seek functions stands for get and the functions ending with it refer to input streams

		int End = Myfile.tellp(); //tellp() and tellg() functions return current position in the file

		cout << "End = " << End << endl << endl;

		Myfile.seekp(ios::beg); //seekp() and seekg() functions set the positions.
		//Can either be seekp/seekg(position) or seekp/seekg(offset, direction) 

		//ios::beg - offset counted from the beginning of the stream
		//ios::cur - offset counted from the current position
		//ios::end - offset counted from the end of the stream

		int Beg = Myfile.tellp();

		cout << "The size of the file is ";
		cout << End - Beg << " bytes.\n\n";

		Myfile.close();
	}
	return 0;
}
==> ./Projects/file position functions2/file position functions2/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream myfile;
	char C, A[100];
	int N(0);
	myfile.open("Test.txt", ios::in);
	while (myfile.read(&C, 1), myfile.good()){
		A[N++] = C;
		myfile.seekg(2, ios::cur); //increase position by 2
	}
	A[N] = '\0';
	cout << '\"' << A << '\"';
	return 0;
}
==> ./Projects/flag-controlled loops/flag-controlled loops/Source.cpp <==
//A flag is a Boolean variable that is used to indicate the state of your program
//You intialize a flag (to true or false). Then condition in the loop body
//Changes the value of the flag. Then test for flag in loop test expression with an if statement

#include <iostream>

using namespace std;

int main(){
	int BP, TotalBP, i;
	char reply;
	bool isMoreToProcess; // declare Boolean flag

	BP = 0;
	TotalBP = 0;
	i = 0;

	cout << "Do you want to enter a BP? y/n: ";
	cin >> reply;
	cout << " " << endl;
	if (reply == 'n'){
		isMoreToProcess = false; // initialise flag value
	}
	else{
		isMoreToProcess = true; // initialise flag value
	}

	while (isMoreToProcess){
		cout << "Enter a blood pressure " << endl;
		cin >> BP;
		cout << " " << endl;
		i++;
		TotalBP = TotalBP + BP;
		
		cout << "Do you want to enter another BP? y/n: ";
		cin >> reply;
		cout << " " << endl;
		if (reply == 'n'){
			isMoreToProcess = false;
		}
	}
	cout << "Total blood pressure is " << TotalBP << endl;
	cout << " " << endl;
	cout << "Total entries are " << i << endl;
	cout << " " << endl;
	return 0;
}
==> ./Projects/float near equality/float near equality/Source.cpp <==
//compare float algorithm. It's dangerous to use equalities
//so instead float or double values are compared for near-equality
//within a set tolerance

#include <iostream>
#include <cmath>
//cmath toolbox includes functions such as sqrt(), fabs()

using namespace std;

int main(){
	float Num1, Num2;

	cin >> Num1;
	cin >> Num2;

//fabs() used to find absolute difference between two numbers (ignores the sign)
	if (fabs(Num1 - Num2) < 0.00001) {
		cout << "They are close enough!" << endl;
	}
	return 0;
}


==> ./Projects/for loop BASIC/for loop BASIC/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/fprintf and fscanf/fprintf and fscanf/Source.c <==
/*Syntax:- 
fprintf(File-pointer, Control string, Argument list);
fscanf(File-pointer, Control string, Argument list)*/

#include <stdio.h>

main()
{
	char name[80];
	FILE *ptr;
	printf("Please type in your name \n");
	gets(name); //read in string from keyboard
	if ((ptr = fopen("Test1.txt", "w")) == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}
	fprintf(ptr, "%s", name); //print string which is at base address represented by ptr 
	fclose(ptr);
	return;
}
==> ./Projects/function stub/function stub/Source.cpp <==
#include <iostream>

using namespace std;

int Max(int x, int y);

int main()
{
	int maxnum, currentnum;
	bool isProcessing = true;

	cout << "Enter a number or -999 to stop : ";
	cin >> currentnum;
	maxnum = currentnum;
	while (isProcessing)
	{
		maxnum = Max(maxnum, currentnum);
		cout << "Enter a number or -999 to stop : ";
		cin >> currentnum;
		if (currentnum == -999)
		{
			isProcessing = false;
		}
	}
	cout << maxnum << endl;
	return 0;
}

//function stub define just enough to test interface
int Max(int x, int y){
	cout << "Max called with arguments " << x << " and " << y << endl;
	return 1;
}
==> ./Projects/function stubs write file/function stubs write file/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void OpenFile(ifstream &In, string fname);
void ReadLine(ifstream &Int, double &n1, double &n2);
void DisplayResults(double n1, double n2);

int main()
{	ifstream fin;
	int counter;
	double num1, num2; //to store current values read from file
	double sum1, sum2; //two accumulators

	OpenFile(fin, "myfile.dat"); //establish connection to file
	sum1 = 0; sum2 = 0; // initialise accumulators
	counter = 0;
	while (counter < 10) // repeat 10 times
	{	ReadLine(fin, num1, num2); //read a line of data from file
		sum1 = sum1 + num1;
		sum2 = sum2 + num2; //update accumulators
		counter++; //update loop control variaqble
	}
	DisplayResults(sum1, sum2);
	return 0;
}

void OpenFile(ifstream &In, string str)
{	cout << str << endl;
	cout << "OpenFile called" << endl;
}

void ReadLine(ifstream &Int, double &n1, double &n2)
{
	cout << "ReadLine called\n";
	n1 = 1; n2 = 2;
}

void DisplayResults(double n1, double n2)
{
	cout << "DisplayResults called\n";
}
==> ./Projects/functioncall/functioncall/Source.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

double AddNumbers(double A, double B);

int main(){
	double x = 3;
	double y = 4;
	cout << "The sum of the numbers is: " << AddNumbers(x, y) << endl;
	cout << " \n";
	return 0;
}

double AddNumbers(double A, double B){
	double r;

	r = A + B;
	
	return r; //value of r is returned, requires same data type as function
	// tells function which value to send back to the calling function
	// note void functions do not need a return
}


==> ./Projects/getchar + putchar/getchar + putchar/Source.c <==
#include <stdio.h>

main()
{
	char ch1;
	ch1 = getchar(); //reads single character from keyboard
	putchar(ch1); //displays a single character on screen
	printf("\n\n");
}
==> ./Projects/gets + puts (string functions)/gets + puts (string functions)/Source.c <==
#include <stdio.h>

main()
{
	char *string1 = "George", string2[10];
	gets(string2);
	puts(string1);
	puts(string2);
}
==> ./Projects/global vs local variables/global vs local variables/Source.cpp <==
#include <iostream>

using namespace std;

const float TAX_RATE = 0.05; //Global constant
float TipRate; //Global variable
int x = 3; // Gloabal variable

void Handle(int, float);

void test(int &a){
	static int x = 50;//static local x - not constant 
	//retains its previous value from call to call of test	
}

int main(){
	int age; float bill; // age and bill local to this block

	//TAX_RATE and TipRate can be used here
	handle(age, bill);
	return 0;
}

void handle(int a, float b){
	float Tax; //a, b and tax local to this block
	int x = 7;
	
	//TAX_RATE and TipRate can be used here, retain value from call to call
}

==> ./Projects/Greet/Greet/Source.cpp <==
//Program Greet prints a greeting on the screen

#include <iostream>
#include <string>

using namespace std;

int main(){
	const string FIRST_NAME = "Leslie";
	const string LAST_NAME = "Tetteh";
	string message;
	string name;

	name = FIRST_NAME + ' ' + LAST_NAME;
	message = "Good morning " + name;
	cout << message << endl;
	return 0;
}
==> ./Projects/guessing game 5/guessing game 5/Source.cpp <==
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	int i, var, A, count;
	double total, all;
	char answer;

	i = 0; total = 0; all = 0; count = 0;

	srand((unsigned int)time(NULL));

	cout << "In this program the user attempts a guess, the computer will then generate 3 \n";
	cout << "random rolls of two diceand the user can see if their guess was correct. \n";
	cout << " \n";
	cout << "Would you like to play this game, please enter Y/N: ";
	cin >> answer;
	cout << " \n";

	if (answer == 'Y'){
		cout << "Please enter a number between 2 and 12. Press return. ";
		cin >> A;
	}

	else{
		cout << "Thanks for playing. ^_^ \n";
		cout << " \n";
		A = -1;
	}

	while (((A < 2) || (A > 12)) && (A != -1)){
		cout << "Value entered was invalid! \n";
		cout << " \n";
		cout << "Please enter a value between 2 and 12. Press Return. ";
		cin >> A;
	}

	while ((A >= 2) && (A <= 12)){
		if (count < 5) {
			count++;
			for (i >= 0; i < 3; i++){
				var = rand() % 11 + 2;
				cout << "Computer rolls a " << var << endl;
				if (var == A){
					cout << "User's guess was successful! \n";
					cout << " \n";
					total++;
					all++;
				}
				else{
					cout << "User's guess was unsuccessful. \n";
					cout << " \n";
					all++;
				}
			}
		}
		if (count >= 5){
			cout << "Total number of guesses " << count << endl;
			cout << " \n";
			cout << "Total correct guesses " << total << endl;
			cout << " \n";
			cout << "Percentage of correct guesses was " << total / all * 100 << "% \n";
			cout << " \n";
			A = -1;
		}
		else{
			cout << "Would you like to play this game, please enter Y/N: ";
			cin >> answer;
			cout << " \n";
			i = 0;
			if (answer == 'Y'){
				cout << "Please enter a number between 2 and 12. Press return. ";
				cin >> A;
			}
			else {
				cout << "Total number of guesses " << count << endl;
				cout << " \n";
				cout << "Total correct guesses " << total << endl;
				cout << " \n";
				cout << "Percentage of correct guesses was " << total / all * 100 << "% \n";
				cout << " \n";
				cout << "Thanks for playing. ^_^ \n";
				cout << " \n";
				A = -1;
			}
		}
		while (((A < 2) || (A > 12)) && (A != -1)){
			cout << "Value entered was invalid! \n";
			cout << " \n";
			cout << "Please enter a value between 2 and 12. Press Return. ";
			cin >> A;
		}
	}

	return 0;
}
==> ./Projects/guessing game 5b/guessing game 5b/Source.cpp <==
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	int i, i1, var, var1, var2, A, A1, count, count1;
	double total, all, total1, all1, perc, perc1;
	char answer;
	string p1name, p2name;

	i = 0; total = 0; all = 0; count = 0; i1 = 0, total1 = 0; all1 = 0; count1 = 0; A1 = -1;

	srand((unsigned int)time(NULL));

	cout << "In this program two users attempt a guess, the computer will then generate 3 \n";
	cout << "random rolls of two dice - the users compete to see if their guess was correct. \n";
	cout << " \n";
	cout << "Would you like to play this game, please enter Y/N: ";
	cin >> answer;
	cout << " \n";
	

	if ((answer == 'Y') || (answer == 'y')){
		cout << "PLAYER-1 please enter your name : ";
		cin >> p1name;
		cout << " \n";
		cout << "PLAYER-2 please enter your name : ";
		cin >> p2name;
		cout << " \n";
		cout << p1name << " please enter a number between 2 and 12. Press return. ";
		cin >> A;
	}

	else{
		cout << "Thanks for playing. ^_^ \n";
		cout << " \n";
		A = -1;
	}

	while (((A < 2) || (A > 12)) && (A != -1)){
		cout << "Value entered was invalid! \n";
		cout << " \n";
		cout << "Please enter a value between 2 and 12. Press Return. ";
		cin >> A;
	}

	while ((A >= 2) && (A <= 12)){
		if (count < 5) {
			count++;
			for (i >= 0; i < 3; i++){
				var1 = rand() % 6 + 1;
				var2 = rand() % 6 + 1;
				var = var1 + var2;
				cout << "Computer rolls a " << var << endl;
				if (var == A){
					cout << p1name << "'s guess was successful! \n";
					cout << " \n";
					total++;
					all++;
				}
				else{
					cout << p1name << "'s guess was unsuccessful. \n";
					cout << " \n";
					all++;
				}
			}
			i1 = 0;
			cout << p2name << " please enter a number between 2 and 12. Press return. ";
			cin >> A1;
			while (((A1 < 2) || (A1 > 12)) && (A1 != -1)){
				cout << "Value entered was invalid! \n";
				cout << " \n";
				cout << "Please enter a value between 2 and 12. Press Return. ";
				cin >> A1;
			}

			while ((A1 >= 2) && (A1 <= 12)){
				if (count1 < 5) {
					count1++;
					for (i1 >= 0; i1 < 3; i1++){
						var1 = rand() % 6 + 1;
						var2 = rand() % 6 + 1;
						var = var1 + var2;
						cout << "Computer rolls a " << var << endl;
						if (var == A1){
							cout << p2name << "'s guess was successful! \n";
							cout << " \n";
							total1++;
							all1++;
						}
						else{
							cout << p2name << "'s guess was unsuccessful. \n";
							cout << " \n";
							all1++;
						}
					}
					if (count1 >= 5){
						cout << "Total number of guesses " << p1name << " : " << count << endl;
						cout << " \n";
						cout << "Total correct guesses " << p1name << " : " << total << " out of " << all << " rolls." << endl;
						cout << " \n";
						perc1 = (total1 / all1) * 100;
						perc = (total / all) * 100;
						if (perc > 0){
							cout << fixed << setprecision(2) << "Percentage of correct guesses for " << p1name << " : " << perc << "% \n";
						}
						else{
							cout << "Percentage of correct guesses for " << p1name << " : " << 0 << "% \n";
						}
						cout << " \n";
						cout << " \n";
						cout << "Total number of guesses " << p2name << " : " << count1 << endl;
						cout << " \n";
						cout << fixed << setprecision(0) << "Total correct guesses " << p2name << " : " << total1 << " out of " << all1 << " rolls." << endl;
						cout << " \n";
						if (perc1 > 0){
							cout << fixed << setprecision(2) << "Percentage of correct guesses for " << p2name << " : " << perc1 << "% \n";
						}
						else{
							cout << "Percentage of correct guesses for " << p2name << " : " << 0 << "% \n";
						}
						cout << " \n";
						cout << " \n";
						if (perc > perc1){
							cout << p1name << " wins \n";
							cout << " \n";
						}
						else if (perc1 > perc){
							cout << p2name << " wins \n";
							cout << " \n";
						}
						else{
							cout << "It's a draw! \n";
							cout << " \n";
						}
						cout << "Thanks for playing. ^_^ \n";
						cout << " \n";
						A = -1;
						A1 = -1;
					}
					else{
						cout << "Would you like to continue this game, please enter Y/N: ";
						cin >> answer;
						cout << " \n";
						i = 0;
						A1 = -1;
						if ((answer == 'Y')||(answer == 'y')){
							cout << p1name << " please enter a number between 2 and 12. Press return. ";
							cin >> A;
						}
						else {
							cout << "Total number of guesses " << p1name << " : " << count << endl;
							cout << " \n";
							cout << "Total correct guesses " << p1name << " : " << total << " out of " << all << " rolls." << endl;
							cout << " \n";
							perc1 = (total1 / all1) * 100;
							perc = (total / all) * 100;
							if (perc > 0){
								cout << fixed << setprecision(2) << "Percentage of correct guesses for " << p1name << " : " << perc << "% \n";
							}
							else{
								cout << "Percentage of correct guesses for " << p1name << " : " << 0 << "% \n";
							}
							cout << " \n";
							cout << " \n";
							cout << "Total number of guesses " << p2name << " : " << count1 << endl;
							cout << " \n";
							cout << fixed << setprecision(0) << "Total correct guesses " << p2name << " : " << total1 << " out of " << all1 << " rolls." << endl;
							cout << " \n";
							if (perc1 > 0){
								cout << fixed << setprecision(2) << "Percentage of correct guesses for " << p2name << " : " << perc1 << "% \n";
							}
							else{
								cout << "Percentage of correct guesses for " << p2name << " : " << 0 << "% \n";
							}
							cout << " \n";
							cout << " \n";
							if (perc > perc1){
								cout << p1name << " wins \n";
								cout << " \n";
							}
							else if (perc1 > perc){
								cout << p2name << " wins \n";
								cout << " \n";
							}
							else{
								cout << "It's a draw! \n";
								cout << " \n";
							}
							cout << "Thanks for playing. ^_^ \n";
							cout << " \n";
							A = -1;
						}
					}
					while (((A < 2) || (A > 12)) && (A != -1)){
						cout << "Value entered was invalid! \n";
						cout << " \n";
						cout << "Please enter a value between 2 and 12. Press Return. ";
						cin >> A;
					}
				}
				}
			}	
	}
	
	return 0;
}
==> ./Projects/guessing games/guessing games/Source.cpp <==
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	int i, var, A;
	double total, all, perc;

	i = 0; total = 0; all = 0;

	srand((unsigned int)time(NULL));

	cout << "In this program the user attempts a guess, the computer will then generate 3 \n";
	cout << "random rolls of two diceand the user can see if their guess was correct. \n";
	cout << " \n";
	cout << "Entering a value of -1 will terminate this program. \n";
	cout << " \n";
	cout << "Please enter a number between 2 and 12. Press return. ";
	cin >> A;

	if (A == -1){
		cout << "Total correct guesses " << total << endl;
		cout << " \n";
	}

	while (((A < 2) || (A > 12)) && (A != -1)){
		cout << "Value entered was invalid! \n";
		cout << " \n";
		cout << "Please enter a value between 2 and 12. Press Return.";
		cin >> A;
	}

	while ((A >= 2) && (A <= 12)){
		for (i >= 0; i < 3; i++){
			var = rand() % 11 + 2;
			cout << "Computer rolls a " << var << endl;
			if (var == A){
				cout << "User's guess was successful! \n";
				cout << " \n";
				total++;
				all++;
			}
			else{
				cout << "User's guess was unsuccesful. \n";
				cout << " \n";
				all++;
			}
		}
		cout << "Please enter a number between 2 and 12. Press return. ";
		cin >> A;
		i = 0;
		if (A == -1){
			cout << "Total correct guesses " << total << endl;
			cout << " \n";
			cout << "Percentage of correct guesses was " << total / all * 100 << "% \n";
			cout << " \n";
		}
		while (((A < 2) || (A > 12)) && (A != -1)){
			cout << "Value entered was invalid! \n";
			cout << " \n";
			cout << "Please enter a value between 2 and 12. Press Return.";
			cin >> A;
		}
	}
	
	return 0;
}
==> ./Projects/guessinggame/guessinggame/Source.cpp <==
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	int i, var, A;

	i = 0; 

	srand((unsigned int)time(NULL));

	cout << "In this program the user attempts a guess, the computer will then generate 3 \n";
	cout << "random rolls of two diceand the user can see if their guess was correct. \n"; 
	cout << " \n";
	cout << "Please enter a number between 2 and 12. Press return. ";
	cin >> A;

	while ((A < 2) || (A > 12)){
		cout << "Value entered was invalid! \n";
		cout << " \n";
		cout << "Please enter a value between 2 and 12. Press Return.";
		cin >> A;
	}

	if ((A >= 2) && (A <= 12)){
		cout << " \n";
		cout << "Lets see if your guess was correct. \n";
		cout << " \n";
		for (i >= 0; i < 3; i++){
			var = rand() % 11 + 2;
			cout << "Computer rolls a " << var << endl;
			if (var == A){
				cout << "User's guess was successful! \n";
				cout << " \n";
			}
			else{
				cout << "User's guess was unsuccesful. \n";
				cout << " \n";
			}
		}

	}
	
	return 0;
}
==> ./Projects/hello world function (returns true value)/hello world function (returns true value)/Source.cpp <==
#include <iostream>

using namespace std;

//Test now done inside Myprint() function. It is now type bool as it has to return a true/false
//value. Returned value will be xdasused by main function to decide whether or not to repeat atttempt
bool MyPrint(int Numb){
	if ((Numb <= 0) || (Numb > 10)){
		return false; //function must return bool type value i.e. true/false
	}
	while (Numb--){
		cout << endl << "*******************";
		cout << endl << "*                 *";
		cout << endl << "*   Hello World!  *";
		cout << endl << "*                 *";
		cout << endl << "*******************" << endl;
	}
	return true;
}

int main(){
	int N, Counter;
	for (Counter = 0; Counter < 3; Counter++){
		cout << "How many printouts (up to 10) : ";
		cin >> N;
		if (MyPrint(N)){
			return 0;
		}
	}
	return -1;
}
==> ./Projects/hello world function (with int argument)/hello world function (with int argument)/Source.cpp <==
#include <iostream>

using namespace std;

//function header now contains argument of int type
void MyPrint(int Numb){ 
//function body has argument controlling how many times text is printed.
	while (Numb--){
		cout << endl << "************************";
		cout << endl << "*                      *";
		cout << endl << "*     Hello World!     *";
		cout << endl << "*                      *";
		cout << endl << "************************" << endl;
	}
	return;
}

int main(){
	int N;
	int Counter;
	for (Counter = 0; Counter < 3; Counter++){
		cout << "How many printouts (up to 10) : ";
		cin >> N;
		if ((N>0) && (N <= 10)){
			MyPrint(N);
			return 0;
		}
	}
	return -1;
}
==> ./Projects/hello world function declaration/hello world function declaration/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N, Counter;
	bool MyPrint(int); //function declaration

	for (Counter = 0; Counter < 3; Counter++){
		cout << "How many printouts (up to 10) : ";
		cin >> N;
		if (MyPrint(N)){
			return 0;
		}
	}
	return -1;
}

bool MyPrint(int Numb){
	if ((Numb <= 0) || (Numb > 10)){
		return false;
	}
	while (Numb--){
		cout << endl << "*******************************";
		cout << endl << "*                             *";
		cout << endl << "*        Hello World!         *";
		cout << endl << "*                             *";
		cout << endl << "*******************************" << endl;
	}
	return true;
}
==> ./Projects/hello world function/hello world function/Source.cpp <==
#include <iostream>

using namespace std;

//First void informs that the function does not return any value, unlike main which has to return an int
void MyPrint(void){ // Function header
//Second void informs explicitly that the function has no arguments. Another possibility is to omit the
//second void as in the main() function - an implicit declaration that the function does not take arguments
	cout << endl << "******************************";
	cout << endl << "*                            *";
	cout << endl << "*       Hello world!         *";
	cout << endl << "*                            *";
	cout << endl << "******************************" << endl;
	return; //return statement has no value attached
}

int main(){
	int N;
	int Counter;
	for (Counter = 0; Counter < 3; Counter++){
		cout << "How many printouts (up to 10) : ";
		cin >> N;
		if ((N > 0) && (N <= 10)){
			while (N--){
				MyPrint();
			}
			return 0; // An int value is needed in the return statement in the main function
		}
	}
	return -1; // An int value is needed in the return statement in the main function
}
==> ./Projects/hello world functiona/hello world functiona/Source.cpp <==
// function put into separate file

#include <iostream>

using namespace std;

bool MyPrint(int);

int main(){
	int N, Counter;
	for (Counter = 0; Counter < 3; Counter++){
		cout << "How many printouts (up to 10) : ";
		cin >> N;
		if (MyPrint(N)){
			return 0;
		}
	}
	return -1;
}
==> ./Projects/hello world functiona/hello world functiona/Source1.cpp <==
#include <iostream>

using namespace std;

bool MyPrint(int Numb){
	if ((Numb <= 0) || (Numb > 10)){
		return false;
	}
	while (Numb--){
		cout << endl << "**********************";
		cout << endl << "*                    *";
		cout << endl << "*    Hello World!    *"; 
		cout << endl << "*                    *";
		cout << endl << "**********************" << endl;
	}
	return true;
}
==> ./Projects/How binary affects newline character/How binary affects newline character/Source.cpp <==
/*
 *This code demonstrates the difference between writing to a file in binary mode versus text mode, particularly focusing on how newline characters are handled. Here's a breakdown of what the code does:

1. It defines a string `Str` containing newline characters.

2. It runs a loop twice, asking the user each time whether to open the file in binary mode or not.

3. Based on the user's input, it opens a file named "test.txt" either in binary mode or text mode.

4. It writes the contents of `Str` to the file.

5. It then reopens the file in binary mode for reading.

6. It reads the file character by character, outputting each character's position, the character itself, and its ASCII value.

7. This process is repeated twice to show the difference between binary and text mode.

The key difference you'd observe is:
- In text mode (non-binary), on Windows systems, `\n` might be converted to `\r\n` when writing to the file.
- In binary mode, `\n` is written as-is, without any conversion.

This demonstrates how opening a file in binary mode can affect how newline characters are handled, which can be crucial for maintaining exact file contents across different operating systems.
 *
 *
 */


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	int k(0);
	char MyChar, Answer;
	char Str[] = "New\nLine\nEnd"; //String literal i.e. character array.
	fstream myfile;
	for (int x = 0; x < 2; x++){
		cout << "Open in binary mode? Y/N : ";
		cin >> Answer;
		if ((Answer == 'y') || (Answer == 'Y')){
			myfile.open("test.txt", ios::out | ios::binary);
		}
		else{
			myfile.open("test.txt", ios::out);
		}
		myfile.write(Str, strlen(Str));
		myfile.close();
		myfile.open("test.txt", ios::in | ios::binary);
		while (myfile.read(&MyChar, 1), myfile.good()){
			cout << k++ << '\t' << MyChar << '\t' << static_cast<int>(MyChar) << endl;
		}
		myfile.close();
	}
	return 0;
}

==> ./Projects/if enemy/if enemy/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>true</MySubMain>
  <MainForm>Form1</MainForm>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>0</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/if-else basic/if-else basic/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/if-else basic2/if-else basic2/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/if-else test/if-else test/Source.cpp <==
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void bubbleSort(eType[], int);

template <typename eType>
void print(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:" << endl;
	print(intList, 100);
	cout << "\n\n";
	bubbleSort(intList, 100);
	cout << "intList after bubble sort:" << endl;
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void bubbleSort(eType list[], int length) {
	for (int i = 1; i < length; i++) {
		for (int index = 0; index < length - i; index++) {
			if (list[index] > list[index + 1]) {
				eType temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}
}

//my earlier version of sorting algorithm
/*for (int i = 1; i < 100; i++) {
for (int a = 0; a < i; a++) {
if (list[i] < list[a]) {
temp = list[i];
for (int b = i; b > a; b--) {
list[b] = list[b - 1];
}
list[a] = temp;
break;
}
}
}*/

template <typename eType>
void print(eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}
==> ./Projects/if-else/if-else/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	unsigned long numb;
	char ans;
lesmadethis:
	cout << "Enter a non-negative integer" << endl;
	cin >> numb;
	cout << "\n";

	if (numb % 2){
		cout << "You entered an odd number\n";
	}
	else {
		cout << "You entered an even number\n";
	}
	cout << "\n";
	cout << "Would you like to continue [y/n]";
	cin >> ans;
	cout << "\n";

	if (ans == 'y'){
		goto lesmadethis; //goto instruction directs execution back to the label start
	}
	return 0;
}
==> ./Projects/increment operator/increment operator/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int count;
	int number;
	int number1;
	int number2;

	for (count = 0; count < 5; count++) {
		cout << "Please input number " << '\n';
		cin >> number;
		number1 = number++ - 2; //number incremented after it's used in expression
		number--; //number restored to original value
		number2 = ++number - 2; //number incremented before used in expression 

		cout << "number 1 is " << number1 << '\n';
		cout << "number 2 is " << number2 << '\n';
	}
	return 0;
}
==> ./Projects/infinite for loop + break - fixed table/infinite for loop + break - fixed table/Source.cpp <==
//programme endless prints ASCII characters + numerical values

#include <iostream> 

using namespace std;

int main(){
	unsigned char c;
	//some or all of the initialisation expression, test expression, or change expression can be missed in the for statement
	// make sure to use semicolons to mark where the missing expressions are empty statements
	for (c = 0;; c++){
		if (c == 7 || //produces beep every time ASCII code is printed
			c == 9 ||  //produces new tab misaligning the code
			c == 10){   //produces new line
			cout << "Character not printed\n";
			continue;
		}
		int a = static_cast<int>(c);
		cout << c << '\t' << dec << a << '\t' << oct << a << '\t' << hex << a << endl;
		
		if (c==255){
			  break;}
	}
	return 0;
}

//Neglecting Test_expression results in indefinite loop since loop will not be tested for stop condition in the for statement
==> ./Projects/infinite for loop + break/infinite for loop + break/Source.cpp <==
//programme endless prints ASCII characters + numerical values

#include <iostream> 

using namespace std;

int main(){
	unsigned char c;
	//some or all of the initialisation expression, test expression, or change expression can be missed in the for statement
	// make sure to use semicolons to mark where the missing expressions are empty statements
	for (c = 0;; c++){
		int a = static_cast<int>(c);
		cout << c << '\t' <<dec << a << '\t' << oct << a << '\t' << hex << a << endl;
		//next command will break infinite loop at c=255
		
		//if (c==255){
		//	  break;}
	}
	return 0;
}

//Neglecting Test_expression results in indefinite loop since loop will not be tested for stop condition in the for statement
==> ./Projects/infinite for loop test/infinite for loop test/Source.c <==
#include <stdio.h>

main()
{
	char ch;
	for (;;)//no initialisation, no condition, no increment
		//will cause infinite for loop
	{
		ch = getchar();
		if ((ch == 'x') || (ch == 'X')) break;
	}//if ch has either the value x or X will break for loop
}
==> ./Projects/input output files/input output files/Source.cpp <==
#include <iostream>
#include <fstream> //type library

using namespace std;

int main(){
	ofstream myfile; //used to write into files
	ifstream myfile; // used to read from files
	fstream myfile; // to read and write to + from files
}
==> ./Projects/inserting header files/inserting header files/Month.h <==
enum MonthType {JAN, FEB, MAR, APR, MAY,
JUN, JUL, AUG, SEP, OCT, NOV, DEC};

==> ./Projects/inserting header files/inserting header files/Source.cpp <==
#include <iostream>
#include "Month.h"

using namespace std;

int main()
{
	MonthType BirthMonth;
	MonthType DeathMonth;

	BirthMonth = JAN;
	DeathMonth = AUG;

	return 0;
}
==> ./Projects/integer sort/integer sort/Source.cpp <==
#include <iostream>

using namespace std;

bool Sort(int &a, int &b, int &c);

int main(){
	int a, b, c;
	
	cout << "Please enter your 1st integer : ";
	cin >> a;
	cout << "Please enter your 2nd integer : ";
	cin >> b;
	cout << "Please enter your 3rd integer : ";
	cin >> c;

	Sort(a, b, c);

	cout << "The values in descending order are : ";
	cout << a << " " << b << " " << c << "\n\n";

	return 0;
}

bool Sort(int &a, int &b, int &c){
	int A[3] = { 0, 0, 0 };
	A[0] = a;
	if (b > a){
		A[1] = a;
		A[0] = b;
		if (c > a){
			A[2] = A[1];
			if (c > b){
				A[1] = A[0];
				A[0] = c;
			}
			else{
				A[1] = c;
			}
		}
		else{
			A[2] = c;
		}
	}
	else{
		A[1] = b;
		if (c > b){
			A[2] = A[1];
			if (c > a){
				A[1] = A[0];
				A[0] = c;
			}
			else{
				A[1] = c;
			}
		}
		else{
			A[2] = c;
		}
	}
	a = A[0];
	b = A[1];
	c = A[2];

	if ((A[0] != A[1]) && (A[1] != A[2]) && (A[0] != A[2])){
		return true;
	}
	else{
		return false;
	}
}



==> ./Projects/iomanip commands/iomanip commands/Source.cpp <==
//Output formatting manipulators are defined in iomanip file
#include <iomanip>

//selected manipulators

setw(n) //sets the width of the next field printed
left //justify left
right //justify right
dec //use decimal base
hex // use hexidecimal base
oct //use octal base
boolalpha // alphanumeric bool values
showbase // show numerical base prefixes
showpoint // show decimal point, and trailing zeroes
showpos // show positive sign
fixed // use fixed dloating point notation
scientific //use scientific notation

==> ./Projects/is open function/is open function/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int k;
	ofstream myfile;

	cout << "We have not attempted opening the file. And the effect is ";

	if (myfile.is_open()){ //is_open() function allows checking if a specific file is open.
		cout << "the file is open"; //The function returns true if the file is open 
	}
	else {
		cout << "the file is closed"; //or false if it is not open (even if opening was attempted but failed)
	}

	myfile.open("test.txt");

	cout << "\n\nNow we have attempted opening the file. And the effect is ";

	if (myfile.is_open()){ //is_open() function allows checking if a specific file is open.
		cout << "the file is open"; //The function returns true if the file is open 
	}
	else {
		cout << "the file is closed"; //or false if it is not open (even if opening was attempted but failed)
	}

	myfile.close();

	cout << "\n\nNow we attempted closing the file. And the effect is ";
	if (myfile.is_open()){
		cout << "the file is open\n\n";
	}
	else cout << "the file is closed\n\n";
	return 0;
}
==> ./Projects/joining null-terminated strings/joining null-terminated strings/Source.cpp <==
#include <iostream>
#include <cstring>

#if defined(_MSC_VER)
    // If compiling with Visual Studio, use strcpy_s
    #define SSTRCAT(dest, src) \
        do { \
            strcat_s(dest, src); \
        } while (0)
#else
    // Otherwise, use strlcat + manual null termination
    #define SSTRCAT(dest, src) \
        do { \
            strncat((dest), (src), sizeof(dest) - strlen(dest) - 1); \
            (dest)[sizeof(dest) - 1] = '\0'; \
        } while (0)
#endif


char String1[13] = "ABCDEFGH";
char String2[] = "IJKL";

// length of string one at 13 sufficient for concatenation

using namespace std;

int main(){
	cout << "Before concatenation\nString1= " << String1;
	cout << "\nString2= " << String2;
	SSTRCAT(String1, String2); //Function strcat_s() concatenates two null-terminated strings
	cout << "\n\nAfter concatenation\nString1= " << String1;
	cout << "\nString2= " << String2 << endl << endl;
	return 0;
}
==> ./Projects/length of null-terminated string/length of null-terminated string/Source.cpp <==
#include <iostream>

char MyString[] = "ABCDEFGH";

using namespace std;

int main(){
	int n;
	n = strlen(MyString); //function strlen finds the number of characters in the string + null terminator
	cout << "The length of the string \"" << MyString << "\" is " << n << endl << endl;
	return 0;
}
==> ./Projects/library functions for strings/library functions for strings/Source.cpp <==
//end of the string literal is recognised by 0, therefore changing Mystring[3] to 0 shortens string

#include <iostream>

char MyString[] = "ABCDEFGH";
using namespace std;

int main(){
	cout << "Original string\n" << MyString << endl;
	cout << MyString[7] << endl;
	cout << static_cast<int>(MyString[8]) << endl << endl;
	MyString[3] = 0;
	cout << "Modified string\n" << MyString << endl << endl;
	return 0;
}
==> ./Projects/Linear program Videos/Linear program Videos/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/linked lists (c code)/linked lists (c code)/Source.c <==
/*dynamic linked list is a set of nodes which contain both data values and also pointers
we use pointers to create data structure such that each node will point to another node*/

#include <stdio.h>

/*create a record containing two elements, 
1. allocation for space for data, 2. allocation for space for a pointer*/

struct record
{
	char name[30];
	struct record *link; //pointer that will point to location in memory
	//location will itself have 30 chars and a pointer that points to node of the same type
};

typedef struct record node;

/*C allows us to define our own data types using keyword typedef.
we define our new type and "node" represents the label of our new type*/

main()
{
	node *ptr_to_first;
	
	ptr_to_first = malloc(sizeof(node));
	strcpy((*ptr_to_first).name, "George");
	(*ptr_to_first).link = malloc(sizeof(node));

	node *ptr_to_2nd;
	
	ptr_to_2nd = (*ptr_to_first).link;
	strcpy((*ptr_to_2nd).name, "Jonathan");
	(*ptr_to_2nd).link = malloc(sizeof(node));

	node *ptr_to_3rd;

	ptr_to_3rd = (*ptr_to_2nd).link;
	strcpy((*ptr_to_3rd).name, "Leslie");
	(*ptr_to_3rd).link = NULL;

	printf("%s \n", (*ptr_to_first).name);
	printf("%s \n", (*ptr_to_2nd).name);
	printf("%s \n\n", (*ptr_to_3rd).name);

	return;
}
==> ./Projects/Llist2/Llist2/Source.cpp <==
#include <iostream>

using namespace std;

struct Node{
	int AValue;
	Node *Next; //pointer variable to struct
};

typedef struct Node *NodePtr;

NodePtr AddList(NodePtr List, int Val); // prototype

void PrintList(NodePtr List); // prototype

int main()
{
	int InputValue; //Used to hold data
	NodePtr FirstNode = NULL; //Node pointer initiall points to nothing
	cout << "Enter a number (0 to stop) : ";
	cin >> InputValue; //read in first value
	while (InputValue != 0){
		FirstNode = AddList(FirstNode, InputValue); 
		cout << "Enter a number (0 to stop) : ";
		cin >> InputValue; //read in first value
	} //add on new item to list when input != 0
	PrintList(FirstNode);
	return 0;
}

NodePtr AddList(NodePtr First, int Val) //returns pointer to Node
{
	NodePtr NewNode = NULL; //Node pointer used to add Node to list
	NodePtr LookPtr = NULL; //LookPointer used to traverse list
	if (First == NULL)
	{
		cout << "List is empty so adding" << endl;
		NewNode = new(Node);
		NewNode->Next = NULL;  //new record points nowhere
		NewNode->AValue = Val; //give a value to the record
		return NewNode; //return address of NewNode
	}
	else
	{ //something else is already in list so traverse to a new Node
		LookPtr = First;
		cout << "list needs traversing" << endl;
		while (LookPtr->Next != NULL) {
			LookPtr = LookPtr->Next;
		}
		NewNode = new(Node);
		LookPtr->Next = NewNode;
		NewNode->Next = NULL;
		NewNode->AValue = Val;
		return First;
	}
}

void PrintList(NodePtr List){
	NodePtr LookPtr = List;
	while (LookPtr != NULL){
		cout << LookPtr->AValue << endl;
		LookPtr = LookPtr->Next;
	}
}


==> ./Projects/Llist2/Llist2/stdafx.h <==

==> ./Projects/Loop Basics/Loop Basics/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int i;
	int sum;

	i = 4;
	sum = 0;

	while (i >= 1){
		if (i > 2){
			sum = sum + i;
		}
		cout << i;
		i--;
	}
	cout << endl;
	cout << sum << endl;
	return 0;
}
==> ./Projects/Lunch/Lunch/Source.cpp <==
// Program Lunch writes out trhe contents of a sandwich

#include <iostream>
#include <string>

using namespace std;

const string HAM = "Ham";
const string CHEESE = "cheese";
const string LETTUCE = "lettuce";
const string BREAD = "bread";

int main(){
	int SandwichNumber = 10;
	string filling;
	string sandwich;

	filling = HAM + " and " + CHEESE + " with " + LETTUCE;
	sandwich = filling + " on white " + BREAD + '-';
	cout << SandwichNumber << " Sandwiches Please" << endl;
	cout << "Filling : " << filling << endl;
	cout << "Sandwich : " << sandwich << endl;
	return 0;
}
==> ./Projects/lvalue + rvalue/lvalue + rvalue/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

//output
//10
//10
//5
//10

int main(){
	int a(10);
	cout << a << endl; {
		cout << a << endl;
		int a(5);
		cout << a << endl;
		//scope for internal a, only within coding block a = 5
	}
	cout << a << endl;
	// external a remains unchanged, a = 10
	return 0;
}
==> ./Projects/matrix addition (c code)/matrix addition (c code)/adjoint.c <==
#include <stdio.h>

void permuteB(int *A, int *B, int l, int r, int **matrix);
void permuteA(int *A, int *B, int l, int r, int **matrix);
void creatematrix(int choice);
void createadjoint(int val, int *B, int count);
void inversematrix(int **matrix, int choice);

int count = 0;
int x, y;
int Adj[3][3];

void creatematrix(int choice)
{
	int **matrix1;

	matrix1 = malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++)
		matrix1[i] = malloc(3 * sizeof(int));

	printf("\nPlease enter co-ordinates for 3x3 matrix : \n\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("[%d][%d] = ", i, j);
			scanf("%d", &matrix1[i][j]);
		}
	}

	int A[] = { 0, 1, 2 };
	int B[] = { 0, 1, 2 };

	permuteA(A, B, 0, 2, matrix1, Adj);

	if (choice == 5)
	{
		printf("\nAdjoint of matrix is :\n\n");

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
				printf("%4d", Adj[j][k]);
			printf("\n");
		}
		printf("\n");
		displaymenu();
	}
	else if ((choice == 6) || (choice == 7))
		inversematrix(matrix1, choice);
}


void permuteB(int *A, int *B, int l, int r, int **matrix)
{
	int i;
	if (l == r)
	{
		int val = matrix[B[1]][A[1]] * matrix[B[2]][A[2]];;
		int coordinates[] = { A[0], B[0] };
		count++;
		createadjoint(val, coordinates, count);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			if ((l == 0) && (i == 1))
				break;
			else if (((A[0] == 0) && (A[1] == 2) && (l == 0)) ||
				((A[0] == 1) && (A[1] == 2) && (l == 0)) ||
				((A[0] == 2) && (A[1] == 0) && (l == 0)))
				i = 2;
			swap((B + l), (B + i));
			permuteB(A, B, (l + 1), 2, matrix);
			swap((B + 1), (B + i));
		}
	}
}

void permuteA(int *A, int *B, int l, int r, int **matrix)
{
	int i;
	if (l == r)
		l = r;
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((A + l), (A + i));
			if (l == 0)
			{
				B[0] = 0; B[1] = 1; B[2] = 2;
			}
			permuteB(A, B, 0, 2, matrix);
			permuteA(A, B, (l + 1), 2, matrix);
			swap((A + l), (A + i));
		}
	}
}

void createadjoint(int val, int *B, int count)
{
	int a;
	if (count % 2)
		x = val;
	else
	{
		y = val;
		int r = 2 + B[0] + B[1];
		if (B[0] == 2)
		{
			if (r % 2)
				a = 1;
			else
				a = -1;
		}
		else
		{
			if (r % 2)
				a = -1;
			else
				a = 1;
		}
		Adj[B[0]][B[1]] = a * (x - y);
	}
}

void inversematrix(int **matrix, int choice)
{
	double det = 0; double inv[3][3];
	for (int i = 0; i < 3; i++)
	{
		det = det + (Adj[i][0] * matrix[0][i]);
	}

	if (choice == 6)
		printf("\ndet = %.2f\n\n", det);
	else if (choice == 7)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inv[i][j] = Adj[i][j] / det;
			}
		}

		printf("\nInverse of matrix is :\n\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%7.2f", inv[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	displaymenu();
}
==> ./Projects/matrix addition (c code)/matrix addition (c code)/displaymenu.c <==

==> ./Projects/matrix addition (c code)/matrix addition (c code)/function 4.cpp <==

==> ./Projects/matrix addition (c code)/matrix addition (c code)/functions 1, 2, 3.c <==

==> ./Projects/matrix addition (c code)/matrix addition (c code)/rotation.c <==
#include <stdio.h>
#include <math.h>

void rot3dmatrix(float x, float y, float z, int choice, float theta, int c2);
void rotationtype(int c2);

void rotationtype(int c2)
{
	float x, y, z, theta;
	int choice, choice1;
	
	if (c2 == 9)
	{
		do
		{
			printf("\nSelect the axis about which you would like to carry out your rotation : ");
			printf("\n\n1: Rotate about x-axis\n2: Rotate about y-axis\n3: Rotate about z-axis");
			printf("\n\nPlease enter your choice (1, 2 or 3) : ");
			scanf("%d", &choice);
			if ((choice < 1) || (choice > 3))
				printf("\nInvalid choice. Please choose option 1, 2 or 3\n");
		} while ((choice < 1) || (choice > 3));
	}
	else
		choice = 3;

	printf("\nPlease enter the x co-ordinate : ");
	scanf("%f", &x);
	printf("\nPlease enter the y co-ordinate : ");
	scanf("%f", &y);
	if (c2 == 9)
	{
		printf("\nPlease enter the z co-ordinate : ");
		scanf("%f", &z);
	}
	else
		z = 0;
	do
	{
		printf("\nWould you like to rotate clockwise or anti-clockwise : ");
		printf("\n\n1: Clockwise\n2: Anti-clockwise");
		printf("\n\nPlease enter your choice (1 or 2) : ");
		scanf("%d", &choice1);
		if ((choice1 < 1) || (choice1 > 2))
			printf("\nInvalid choice. Please choose option 1 or 2\n\n");
	} while ((choice1 < 1) || (choice1 > 2));

	printf("\nPlease enter the angle you would like to rotate by (in degrees) : ");
	scanf("%f", &theta);
	if (choice1 == 1)
		theta = 360 - theta;
	theta = theta / (180 / 3.14159);
	rot3dmatrix(x, y, z, choice, theta, c2);
}

void rot3dmatrix(float x, float y, float z, int choice, float theta, int c2)
{
	float A = sin(theta), B = cos(theta);

	printf("\nCalculating new co-ordinates...\n");
	if (choice == 1)
	{
		float matrix3d[3][3] = { 1, 0, 0, 0, B, -A, 0, A, B };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
	}
	else if (choice == 2)
	{
		float matrix3d[3][3] = { B, 0, A, 0, 1, 0, -A, 0, B };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
	}
	else if (choice == 3)
	{
		float matrix3d[3][3] = { B, -A, 0, A, B, 0, 0, 0, 1 };
		float x1 = x * matrix3d[0][0] + y * matrix3d[0][1] + z * matrix3d[0][2];
		float y1 = x * matrix3d[1][0] + y * matrix3d[1][1] + z * matrix3d[1][2];
		float z1 = x * matrix3d[2][0] + y * matrix3d[2][1] + z * matrix3d[2][2];
		if (c2 == 9)
			printf("\nx' = %2.2f\ny' = %2.2f\nz' = %2.2f\n\n", x1, y1, z1);
		else
			printf("\nx' = %2.2f\ny' = %2.2f\n\n", x1, y1);

	}
	displaymenu();
}
==> ./Projects/matrix addition (c code)/matrix addition (c code)/Source.c <==
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void displaymenu();

void creatematrices(int); //choice 1, 2 or 3
void addmatrices(int **Myarray, int **Myarray2, int row, int col); //choice 1
void submatrices(int **Myarray, int **Myarray2, int row, int col); //choice 2
void prodmatrices(int **Myarray, int **Myarray2, int row, int col); //choice 3

void genpermutaions(); //choice 4
void swap(char *x, char *y); 
void permute(char *a, int l, int r);

main()
{
	displaymenu();
}

void displaymenu()
{
	int choice = 0;
	int i = 0;
	do
	{
		printf("What would you like to do?\n\n");
		printf("1. Add two matrices\n");
		printf("2. Subtract two matrices\n");
		printf("3. Multiply two matrices\n");
		printf("4. Generate all possible permutations of a set of characters (max 6)\n");
		printf("5. Adjoint of a matrix (size 3x3)\n");
		printf("6. Determinant of a matrix (size 3x3)\n");
		printf("7. Inverse of a matrix (size 3x3)\n");
		printf("8. Apply rotation matrix onto 2d geometric structure\n");
		printf("9. Apply rotation matrix onto 3d geometric structure\n");
		printf("10. Exit program\n\n");

		printf("Please enter your choice : ");
		scanf(" %i", &choice);

		if ((choice == 1) || (choice == 2) || (choice == 3))
		{
			creatematrices(choice);
		}
		else if (choice == 4)
		{
			genpermutaions();
		}
		else if ((choice == 5) || (choice == 6) || (choice == 7))
		{
			creatematrix(choice);
		}
		else if ((choice == 8) || (choice == 9))
		{
			rotationtype(choice);
		}
		else if (choice == 10)
		{
			printf("\nThank you for using this program.\n\n");
		}
		else
		{
			printf("\nPlease make a valid choice\n\n");
		}
		i++;
	} while (((choice > 10) || (choice <= 0)) && (i < 3));

	if (i >= 3)
	{
		printf("Too many invalid choices. Goodbye !\n\n");
	}
}

void creatematrices(int choice)
{	
	int row, col, count1, count2;	
	printf("\nPlease enter the dimensions for your matrix/matrices\n");
	printf("\nDimension 1 : ");
	scanf("%i", &row);
	printf("\nDimension 2 : ");
	scanf("%i", &col);
	printf("\n");
	
	int **Myarray, **Myarray2;

	Myarray = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		Myarray[i] = malloc(col * sizeof(int));
	}
	
	Myarray2 = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		Myarray2[i] = malloc(col * sizeof(int));
	}

	printf("\nPlease enter the values for your first matrix\n");
	for (count1 = 0; count1 < row; count1++)
	{
		for (count2 = 0; count2 < col; count2++)
		{
			printf("[%i][%i] = ", count1, count2);
			scanf("%i", &Myarray[count1][count2]);
		}
	}

	count1 = 0; count2 = 0;
	printf("\n\nPlease enter the values for your second matrix\n");
	for (count1 = 0; count1 < row; count1++)
	{
		for (count2 = 0; count2 < col; count2++)
		{
			printf("[%i][%i] = ", count1, count2);
			scanf("%i", &Myarray2[count1][count2]);
		}
	}

	switch (choice)
	{
	case 1: addmatrices(Myarray, Myarray2, row, col); break;
	case 2: submatrices(Myarray, Myarray2, row, col); break;
	case 3: prodmatrices(Myarray, Myarray2, row, col); break;
	}	
}

void addmatrices(int **Myarray, int **Myarray2)
{
	int i, j;
	int **Newarray;

	Newarray = malloc(2*sizeof(int*));
	for (i = 0; i < 2; i++)
	{
		Newarray[i] = malloc(2*sizeof(int));
	}
	
	printf("\nMatrix 1 :  \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%4d", Myarray[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 2 :  \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%4d", Myarray2[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 1 + Matrix 2 : \n");
	
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			Newarray[i][j] = Myarray[i][j] + Myarray2[i][j];
			printf("%4d", Newarray[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	displaymenu();
}

void submatrices(int **Myarray, int **Myarray2, int row, int col)
{
	int i, j;
	int **Newarray;

	Newarray = malloc(row*sizeof(int*));
	for (i = 0; i < row; i++)
	{
		Newarray[i] = malloc(col*sizeof(int));
	}

	printf("\nMatrix 1 :  \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", Myarray[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 2 :  \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", Myarray2[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 1 - Matrix 2 : \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Newarray[i][j] = Myarray[i][j] - Myarray2[i][j];
			printf("%4d", Newarray[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	displaymenu();
}


void prodmatrices(int **Myarray, int **Myarray2, int row, int col)
{
	int i, j;
	int **Newarray;

	Newarray = malloc(row*sizeof(int*));
	for (i = 0; i < row; i++)
	{
		Newarray[i] = malloc(col*sizeof(int));
	}

	printf("\nMatrix 1 :  \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", Myarray[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 2 :  \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", Myarray2[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 1 x Matrix 2 : \n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Newarray[i][j] = Myarray[i][j] * Myarray2[i][j];
			printf("%4d", Newarray[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	displaymenu();
}

void swap(char *x, char *y)
{
	char temp; //creates new character
	temp = *x; //stores value for x in temp
	*x = *y; //puts old value of y in storage space for x
	*y = temp; //puts old value of x in the storage space for y
}

void permute(char *a, int l, int r)
{
	//recursive function, swaps all characters in string;
	int i;
	if (l == r)
	{
		printf("%s \n", a);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, (l + 1), r);
			swap((a + l), (a + i));
		}
	}
}

void genpermutaions()
{
	char *str;
	int answer;
	int i = 0;
	do{
		i++; //i < 2 condition breaks program if a character other than an integer is input
		printf("\nHow many characters would you like to enter : ");
		scanf("%d", &answer);

		if (answer > 6)
		{
			printf("\nPlease enter a number less than 6 and greater than 0.\n");
		}
		else if (answer <= 0)
		{
			printf("\nPlease enter a positive number less than 6.\n");
		}
	} while (((answer <= 0) || (answer > 6)) && (i < 3));

	str = malloc(sizeof(char) * (answer -1));
	printf("\nPlease enter your string : ");
	scanf("%s", str);
	printf("\nGenerating permutations...\n\n");
	permute(str, 0, (answer -1));
	printf("\n");
	displaymenu();
}

==> ./Projects/matrix addition (c code)/matrix addition (c code)/Source.cpp <==

==> ./Projects/matrix test/matrix test/Source.cpp <==
#include <iostream>
#include <string>

using namespace std; 

int main(){
	string N[3];

	N[0] = "Hi ";
	N[1] = "there ";
	N[2] = "world\n\n";

	for (int n = 0; n < 3; n++){
		cout << N[n];
	}
	return 0;
}
==> ./Projects/memory leak/memory leak/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int *ptr = new int;
	*ptr = 3;

	ptr = new int;
	*ptr = 4;

	//changes value of ptr creating an inaccessible object, because there is no longer a pointer to it causing memory leak
	//A memory leak is the loss of available memory space that occurs when dynamic data is allocated but never deallocated.

	//other ways of creating memory leaks

	int *ptr1 = new int;
	*ptr1 = 8;
	int* ptr2 = new int;
	*ptr2 = -5;

	ptr1 = ptr2; //here 8 becomes inaccessible
}
==> ./Projects/Modern C++ 05 - user defined literals/Modern C++ 05 - user defined literals/main.cpp <==
/*User defined literals

C++ has 4 kinds of literals

integer int
floating point float
character char
string char*

suffix specifies type

45; int
45u; unsigned int
45l; long int

user defined literals allows us to define our own suffix which is subsequently 
treated as anew type of literal
*/

#include <iostream>

using namespace std;

//User defined literals

constexpr long double operator"" _m(long double x){ return x * 1000; }
long double operator"" _cm(long double x){ return x * 10; }
long double operator"" _m(long double x){ return x; }

int main(){

}
==> ./Projects/Modern C++03 Rvalue reference/Modern C++03 Rvalue reference/main.cpp <==
#include <iostream>
#include <utility>  // Just for demonstration (if we want to compare to std::forward)

using namespace std;

// 1) Basic demonstration: lvalue/rvalue reference overloading
void printInt(int& x){
    cout << "lvalue reference : " << x << endl;
}
void printInt(int&& x){
    cout << "rvalue reference : " << x << endl;
}

// 2) Simple BoVector class (to test moves/copies)
class BoVector{
    int size;
    double *arr_;
public:
    BoVector(int i, double x[]){
        size = i;
        arr_ = new double[size];
        for (int j = 0; j < size; j++){
            arr_[j] = x[j];
        }
    }
    // Copy constructor
    BoVector(const BoVector& rhs){
        cout << "\ncopy constructor called\n";
        size = rhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++){
            arr_[i] = rhs.arr_[i];
        }
    }
    // Default constructor
    BoVector() {
		size = 0;
		arr_ = nullptr;
	}
    // Move constructor
    BoVector(BoVector&& rhs){
        cout << "\nmove constructor called\n";
        size = rhs.size;
        arr_ = rhs.arr_;
        rhs.arr_ = nullptr;
    }

    void printArray() const {
        for (int i = 0; i < size; i++){
            cout << arr_[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    ~BoVector(){
        delete[] arr_;
    }
};

// Helper function to take BoVector by value (invokes copy or move)
void printBv(BoVector bv){
    bv.printArray();
}


// Return a default-constructed BoVector (size=0)
BoVector createEmptyBoVector(){
    BoVector bv; // size=0
    return bv;   // copies or moves the empty vector
}

// Return a 3-element BoVector
BoVector createBoVector(){
    double arr[3] = {1.0, 2.0, 3.0};
    BoVector bv(3, arr);
    return bv; 
}

// 3) Simple template function (by value)
template <typename T>
void relay(T arg){
    printBv(arg);
}

// 4) Perfect forwarding using standard library forward
template <typename T>
void relay1(T&& arg){
    printBv(std::forward<T>(arg));
}

// ----------------------------------------------------------------
// 5) Manually implement remove_reference and a custom forward
//    This mimics the idea of std::remove_reference and std::forward
// ----------------------------------------------------------------

// remove_reference<U> yields U
template<typename U> 
struct MyRemoveReference {
    using type = U;
};

// remove_reference<U&> yields U
template<typename U>
struct MyRemoveReference<U&> {
    using type = U;
};

// remove_reference<U&&> yields U
template<typename U>
struct MyRemoveReference<U&&> {
    using type = U;
};

// myForward - a toy version of std::forward
// Note the function parameter is:
//   (typename MyRemoveReference<U>::type & arg)
// Uhat is the "stripped" type as lvalue reference.
template<typename U>
constexpr U&& myForward(typename MyRemoveReference<U>::type& arg){
    return static_cast<U&&>(arg);
}

// 6) Now use our custom forward in relay2
template<typename T>
void relay2(T&& arg){
    // Instead of std::forward<T>(arg), we do:
    printBv(myForward<T>(arg));
}

// --------------------------------------------------

int main(){
    int a = 5;
    printInt(a);  // calls printInt(int& x) - lvalue
    printInt(5);  // calls printInt(int&& x) - rvalue

    // test creating an empty BoVector
    BoVector emptyVec = createEmptyBoVector(); 
    printBv(emptyVec); // prints nothing (size=0)

    // Test BoVector
    BoVector reusable = createBoVector(); 
    printBv(reusable);           // copy constructor
    printBv(createBoVector());   // move constructor if available
    printBv(std::move(reusable));// move constructor

    // Testing relay (by-value) - copy or move
    relay(emptyVec);             // copy
    relay(createBoVector());     // move

    // Testing relay1 (std::forward)
    relay1(emptyVec);            // lvalue => copy
    relay1(createBoVector());    // rvalue => move

    // Testing relay2 (our custom myForward)
    relay2(emptyVec);            // lvalue => copy
    relay2(createBoVector());    // rvalue => move

    return 0;
}
==> ./Projects/modified word count programme/modified word count programme/Source.cpp <==
#include <iostream>

using namespace std;

char Text[120];
char *MyCh(Text);

int main(){
	cout << "A word is a sequence of characters terminated with a\n";
	cout << "space, tab, comma, full stop or newline. \n\n";
	cout << "A full sentence is a sequence of words terminated with\na full stop";
	cout << ", question mark or exclamation mark.\n\n";
	cout << "Type the text to analyse and press Enter\n\n";
	cin.getline(Text, 120, '\n');

	int Chrno(0), Wrdno(0), Sntno(0);
	bool WordTerminator = true;
	bool SentenceTerminator = true;
	
	do{
		Chrno++;
		switch (*MyCh){
		case ' ':
		case '\t':
		case ',':
			if (!WordTerminator) Wrdno++;
			WordTerminator = true;
			break;
		case '.':
		case '?':
		case '!':
			if (!SentenceTerminator) Sntno++;
			if (!WordTerminator) Wrdno++;
			SentenceTerminator = true;
			WordTerminator = true;
			break;
		default:
			SentenceTerminator = false;
			WordTerminator = false;
		}
	} while (*++MyCh);
	if (!SentenceTerminator) Sntno++;
	if (!WordTerminator) Wrdno++;
	cout << "\n\n" << "This text comprises\n" << Chrno << " characters\n";
	cout << Wrdno << " words, and\n" << Sntno << " sentences\n";
	return 0;
}

==> ./Projects/modifying a variable/modifying a variable/Source.cpp <==
//operators which can be used to modify a variable

%= remainder
<<= shift left
>>= shift right
&= bitwise and
|= bitwise or
^= bitwise exclusive or


==> ./Projects/modulus operator/modulus operator/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	cout << "remainder of ten divided by two is " << 10 % 2 << '\n';
	cout << "remainder of ten divided by three is " << 10 % 3 << '\n';
	return 0;
}
==> ./Projects/more-loops/more-loops/Source.cpp <==
// Program accumulate prompts for, reads, echo prints, and sums a
// fixed number of integer values. The sum is printed.

#include <iostream>

using namespace std;

int main(){
	int i; //loop-control variable
	int sum; //accumulator variable
	int digit;

	cout << "Enter a one-digit number; press return. \n";
	cin >> digit;

	i = 0;
	sum = 0;

	while (digit != -99){
		while (i <= digit){
			sum = sum + i;
			i++;
		}
		cout << "Sum of digits between 0 and " << digit << " is " << sum << endl;
		cout << " \n";
		cout << "Enter a one-digit number; press return. \n";
		cin >> digit;
		cout << " \n";
		i = 0;
		sum = 0;
	}


	cout << "Sum of digits between 0 and " << digit << " is " << sum << endl;

	return 0;
}
==> ./Projects/most-heavy least-heavy/most-heavy least-heavy/Source.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double Most = 0, Most2 = 0, Least = 9999, Least2 = 9999, Average, Weight, N[100], M[100];
	double Sum = 0, Sum_stand = 0, Stand;
	int i = 0, n = 0;
	char Answer;

	cout << "Welcome to the weight calculation program\n";

	while (i < 100){
		cout << "\nWould you like to enter a weight? Please enter Y/N : "; cin >> Answer;
		if ((Answer == 'Y')||(Answer =='y')){
			cout << "\nPlease input your Weight (kg) : "; cin >> Weight;
			if ((Weight < 300) && (Weight > 10)){
				Sum = Sum + Weight;
				N[i] = Weight;
				if (N[i] > Most){
					Most = N[i];
					while (i > 0){
						i = i - 1;
						if ((N[i] > Most2) && (N[i] < Most)){
							Most2 = N[i];
						}
					}
					i = n;
				}
				else if ((N[i] > Most2) && (N[i] < Most)){
					Most2 = N[i];
				}
				if (N[i] < Least){
					Least = N[i];
					while (i > 0){
						i = i - 1;
						if ((N[i] < Least2) && (N[i] > Least)){
							Least2 = N[i];
						}
					}
					i = n;
				}
				else if ((N[i] < Least2) && (N[i] > Least)){
					Least2 = N[i];
				}
				i++;
				n++;
				Average = Sum / i;
			}
			else{
				cout << "\nWeight format entered was invalid\n";
			}
		}
		else{
			cout << "\nNow calculating...\n";
			cout << "\nHighest weight     = " << Most << "kg";
			cout << "\n2nd Highest Weight = " << Most2 << "kg";
			cout << "\nLowest Weight      = " << Least << "kg";
			cout << "\n2nd Lowest Weight  = " << Least2 << "kg";
			cout << "\nAverage weight     = " << Average << "kg";
			cout << endl << endl;
			i = 0;
			while (i < n){
				M[i] = N[i];
				Sum_stand = Sum_stand + ((M[i] - Average)*(M[i] - Average));
				i++;
			}
			if (i == n){
				Stand = sqrt(Sum_stand /(i));
				cout << "Standard deviation is " << Stand << endl << endl;
			}
			i = 101;
		}
	}
	return 0;
}
==> ./Projects/multidimensional arrays/multidimensional arrays/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

double A[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
};

int main(){
	int row, col;
	for (row = 0; row < 3; row++){
		for (col = 0; col < 4; col++){
			cout << setw(4) << A[row][col];
		}
		cout << endl << endl;
	}
}

==> ./Projects/multidimensional1/multidimensional1/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

double A[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

int main(){
	int row, col;
	for (row = 0; row < 3; row++){
		for (col = 0; col < 4; col++){
			cout << setw(4) << A[row][col];
		}
		cout << endl << endl;
	}
}
==> ./Projects/Multiple Argument Function/Multiple Argument Function/Source.cpp <==
#include <iostream>

using namespace std;

auto Power(double, unsigned) -> double; //returns x^n

auto main() -> int{
	cout << "2.1 ^ 2 =\t" << Power(2.1, 2) << endl;
	cout << "3.0 ^ 5 =\t" << Power(3.0, 5) << endl;
	cout << "-4.0 ^ 7 =\t" << Power(-4.0, 7) << endl;
	cout << "2 ^ 2.1 =\t" << Power(2, 2.1) << endl;
}

auto Power(double x, unsigned n) -> double{
	double Result(1.0);
	for (unsigned k = 0; k < n; k++){
		Result *= x;
	}
	return Result;
}
==> ./Projects/mynewproj/mynewproj/mynewproj.cpp <==
// mynewproj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


==> ./Projects/mynewproj/mynewproj/stdafx.cpp <==
// stdafx.cpp : source file that includes just the standard includes
// mynewproj.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

==> ./Projects/mynewproj/mynewproj/stdafx.h <==
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

==> ./Projects/mynewproj/mynewproj/targetver.h <==
#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>

==> ./Projects/mynewproj1/mynewproj1/Source.cpp <==
#include <iostream>

using namespace std;

int main() {
	double NormalHours;
	double NormalRate;

	cin >> Wages1;
	cin >> Wages2;
	
	cout << "Total wages = " << wages1 + wages2 << endl;

	return 0;
}
==> ./Projects/nested if return/nested if return/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	char letter;
	cout << "Enter a capital letter\n";
	cin >> letter;

	if (letter >= 'A'){
		if (letter <= 'Z'){
			cout << "You entered a capital letter\n";
			cout << "\n";
			return -1;
		}
	}
	cout << "You did not enter a capital letter\n";
	cout << "\n";
	return 0;
}
==> ./Projects/nested if-else/nested if-else/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	char tea, coffee, donut, answer;
	int count;
start:	
	cout << "Would you like tea [y/n] : "; cin >> tea;
	cout << "\n";
	cout << "Would you like coffee [y/n] : "; cin >> coffee;
	cout << "\n";
	cout << "Would you like a donut [y/n] : "; cin >> donut;
	cout << "\n";

	if (tea == 'y'){
		if (coffee == 'y'){
			cout << "You cannot choose tea and coffee\n";
			cout << "\n";
			goto start;
		}
		else if (donut == 'y'){
			cout << "You have chosen tea and a donut\n";
			cout << "\n";
		}
		else{
			cout << "You have chosen tea\n";
			cout << "\n";
		}
	}
	else if (coffee == 'y'){
		if (donut == 'y'){
			cout << "You have chosen coffee and a drink\n";
			cout << "\n";
		}
		else{
			cout << "You have chosen coffee\n";
			cout << "\n";
		}
	}
	else{
		if (donut == 'y'){
			cout << "You have chosen a donut\n";
		}
		else{
			cout << "You have chosen nothing. Are you sure [y/n] : "; cin >> answer;
			cout << "\n";
			if (answer != 'y'){
				goto start;
			}
		}
	}

	cout << "Thank you for using this service\n";
	cout << "\n";
	return 0;
}
==> ./Projects/nested loops - hexadecimal times tables/nested loops - hexadecimal times tables/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

const int width(6);

int main(){
	unsigned row, col;
	// print the title and top row of the table
	cout << endl << endl << setw(54) << "Hexadecimal Times Table\n\n" << hex;
	for (col = 1; col < 16; col++){
		cout << setw(width -3) << col << " |";
	}
	cout << '\n'; 
	//Print a horizontal line
	for (col = 1; col < 16; col++){
		cout << "-----";
	}
	cout << "\n\n";
	for (row = 1; row < 16; row++){
		for (col = 1; col < 16; col++){
			cout << setw(width - 3) << col*row << " |";
		}
		cout << "\n";
		
	}
	cout << endl << endl;
	return 0;
}
==> ./Projects/nested loops (diagonal line)/nested loops (diagonal line)/Source.c <==
#include <stdio.h>

main()
{
	int i, j;
	for (j = 10; j > 0; j--)
	{
		for (i = 0; i <= j; i++) 
			printf(" ");
		printf(",\n");
	}

	printf("\n");

	int int1, int2;

	printf("\nPlease type in two integers : ");

	scanf("%d %d", &int1, &int2);

	if (int1 >= int2) printf("\n%d\n", int1);
	
	else printf("\n%d\n", int2);

	printf("\n");

	int grade;
	printf("Please enter percentage : ");
	scanf("%d", &grade);
	if (grade >= 70) printf("\nA - grade\n\n");
	else if (grade >= 60) printf("\nB - grade\n\n");
	else if (grade >= 50) printf("\nC - grade\n\n");
	else printf("\nYou have failed\n\n");
}
==> ./Projects/nested structures/nested structures/Source.cpp <==
#include <iostream>

using namespace std;

struct DateType
{	int month;
	int day;
	int year;
};

struct HistoryType
{	float		failRate;
	DateType	lastServiced; //DateType is a struct type
	int			downDays;
};

struct MachineRec
{
	int			id;
	string		desc;
	HistoryType history; //HistoryType is a struct type
	DateType	purchaseDate; //DateType is a struct type
	float		cost;
};

MachineRec	machine; //An instance of MachineRec
==> ./Projects/nesting structures/nesting structures/Source.cpp <==
#include <iostream>

using namespace std;

struct Address{
	char StreetName[20];
	unsigned HouseNumber;
	char town[10];
	char postcode[10];
};

struct a_person{
	char Firstname[10];
	char Surname[15];
	unsigned Age;
	unsigned Height;
	unsigned Weight;
	bool Employed;
	Address PostAddress;
};

int main(){
	a_person MyNeighbour =
	{
		"John",
		"Bloggs",
		32,
		175,
		79,
		true,
		{
			"London Road",
			125
		}
	};

	// Add records not set during the initialisation

	strcpy_s(MyNeighbour.PostAddress.town, "Wembley");
	strcpy_s(MyNeighbour.PostAddress.postcode, "WQR 3T4");


	cout << "My next door neighbour is " << MyNeighbour.Firstname;
	cout << " " << MyNeighbour.Surname;
	cout << "\nHe is " << MyNeighbour.Age << " years old, ";
	cout << MyNeighbour.Height;
	cout << "cm tall, and weighs " << MyNeighbour.Weight << "kg.\n";
	cout << "He is " << (MyNeighbour.Employed ? "employed" : "unemployed");//conditional operator -
	//comprises one boolean expression separated with a question mark, followed by two rvalues separated by a colon
	cout << "\nMy neighbour's postcoode is " << MyNeighbour.PostAddress.postcode << "\n";
	cout << "The third letter of his street name is\n\n\t\t" << MyNeighbour.PostAddress.StreetName[2];
	cout << "\n\n";
	return 0;
}
==> ./Projects/new wallpaper rolls/new wallpaper rolls/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double width, height, length, area1, area2;
	double rollwidth(1.2), rollheight(15), nstripsh, nstripsw, nstripsl, nstripsp, nstrips;

	cout << "Please enter room height (meters) : "; cin >> height;
	cout << "\n";
	cout << "Please enter room width (meters) : "; cin >> width;
	cout << "\n";
	cout << "Please enter room length (meters) : "; cin >> length;
	cout << "\n";

	area1 = length * height;
	area2 = width * height;

	nstripsh = floor(rollheight/height);
	nstripsw = ceil(width / rollwidth);
	nstripsl = ceil(length / rollwidth);
	nstripsp = 2 * nstripsw + 2 * nstripsl;
	nstrips = ceil(nstripsp / nstripsh);

	cout << "Number of wallpaper rolls required for the room is " << nstrips << " rolls.\n\n";
	return 0;
}
==> ./Projects/newproj02/newproj02/Source.cpp <==
#include <iostream>

using namespace std;

int main() {

	cout << "I really love computer programming ";

	cout << "very much indeed ";

	return 0;
}
==> ./Projects/newproj03/newproj03/Source.cpp <==
#include <iostream>

using namespace std;

int main() {

	cout << "15.0 plus 2.0 equals " << (15.0 + 2.0) << endl;
	cout << "15.0 minus 20.0 equals " << (15.0 - 2.0) << '\n';
	cout << "15.0 times 2.0 equals " << (15.0 * 2.0) << '\n';
	cout << "15.0 divided by 2.0 equals " << (15.0 / 2.0) << '\n';

	return 0;
}
==> ./Projects/numericalexpressions/numericalexpressions/Source.cpp <==
#include <iostream>

using namespace std;

int main() {
	double X, Y, Z, W, T;
	
	cout << "Please input value for W : ";
	cin >> W; '\n';
	cout << "Please input value for X : ";
	cin >> X; '\n';
	cout << "Please input value for Y : ";
	cin >> Y; '\n';
	cout << "Please input value for Z : ";
	cin >> Z; '\n';

	T = (X + Y) / (W - Z) + X / (Y + 5);
	cout << "Value of T is : " << T << '\n';

	return 0; 
}
==> ./Projects/obtaining memory address/obtaining memory address/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int X;
	double NUMBER;
	char CH;

	cout << "Address of x is " << &X << endl;
	cout << "Address of NUMBER is " << &NUMBER << endl;
	cout << "Address of CH is " << &CH << endl;

	return 0;
}
==> ./Projects/old tutorial ex1/old tutorial ex1/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;
string upperCase(string response); //prototype for function

int main(){
	string myText1, myText2, allText;
	myText1 = "smile";
	myText2 = "now";
	cout << "Our string is " << myText1 << endl;
	allText = myText1 + " always";
	cout << "Our string 1 is " << allText << endl;
	allText = myText1 + " " + myText2;
	cout << "Our string 2 is " << allText << endl;
	int sl = myText1.length();
	cout << "The length is " << sl << endl;
	if (myText1 == "smile"){ 
		cout << "myText1 equal to \"smile\"" << endl; }
	if (!(myText1 == myText2)){
		cout << "myText1 not equal to myText2" << endl << endl; }

	cout << "substring1 " << myText1.substr(3) << endl;
	cout << "substring2 " << myText1.substr(1, 3) << endl << endl;

	myText1 = myText1.replace(0, 1, "green "); //replace positions between (x,y) with new string 
	cout << "Our new string is " << myText1 << endl;
	myText1 = upperCase(myText1); // caller for function upperCase
	cout << "Our upper string is " + myText1 << endl << endl;
}

string upperCase(string str){ 
	//cout << str;
	int i = 0;
	char c;
	while (str[i]){
		c = str[i];
		str[i] = toupper(c); //changes letters to uppercase
		i = i++; //moves to next letter in sequuence
	}
	return str;
}
==> ./Projects/output manipulation/output manipulation/Source.cpp <==
#include <iostream>
#include <iomanip>

int main(){

	using namespace std;
	int a(10), b(-3), c(0xabc1);
	double d(-31e4), e(1.5), f(0);
	bool g(true);

	cout << "Test 1 \n" << a << b << c << d << e << f << g << endl;
	cout << " \n";
	cout << "Test 2 \n" << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << d << right << setw(10) << e << setw(10) << f << setw(10) << g << endl;
	cout << " \n";
	cout << "Test 3 \n" << left << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << d << right << setw(10) << e << setw(10) << f << setw(10) << g << endl;
	cout << " \n";
	cout << "Test 4 \n" << hex << left << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << d << right << setw(10) << e << setw(10) << f << setw(10) << g << endl;
	cout << " \n";
}

==> ./Projects/pass array to function (c code)/pass array to function (c code)/Source.cpp <==
#include <stdio.h>

int sum(int[], int t);

main()
{
	int numb[10];
	int i, no_numb;

	printf("How many numbers do you wish to add : ");
	scanf("%d", &no_numb);

	for (i = 0; i < no_numb; i++)
	{
		printf("\nPlease add numb[%d] : ", i);
		scanf("%d", &numb[i]);
	}

	printf("\nThe sum of the %d numbers is %d\n\n", no_numb, sum(numb, no_numb));
}

int sum(int numb1[], int size)
{
	int sum = 0, i;
	
	for (i = 0; i < size; i++)
		sum += numb1[i];

	return sum;
}
==> ./Projects/Passing Arguments by value/Passing Arguments by value/Source.cpp <==
/*It is clear from the above printout that the variable x in the main programme was stored in the address 0x17F75C but for the use by the function ADD a copy 
was made and put in the address 0x17F658. The copied version was zeroed inside
ADD function. But this had no effect on the original value of x in the main programme*/

#include <iostream>

using namespace std;

double ADD(double x, double y);

int main(){
	double x(1.6), y(5.0), z(0);
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	z = ADD(x, y);
	cout << x << " + " << y << " = " << z << endl;
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	return 0;
}

double ADD(double x, double y){
	double z = x + y;
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	x = 0;
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	return z;
}
==> ./Projects/Passing array of structs to function/Passing array of structs to function/Source.cpp <==
#include <iostream>

using namespace std;

struct myDataType
{
	char name[20];
	int grade;
};

void ReadData(myDataType data[], int n);

int main()
{
	myDataType *record;
	int nItems, i;

	cout << "How many numbers are there to process? : ";
	cin >> nItems;
	record = new myDataType[nItems]; //created dynamically
	ReadData(record, nItems); //effectively record used like an array

	for (i = 0; i < nItems; i++)
		cout << record[i].name << " " << record[i].grade << endl;

	return 0;
}

void ReadData(myDataType data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Enter a name : ";
		cin >> data[i].name;
		cout << "Enter a grade : ";
		cin >> data[i].grade;
	}
}
==> ./Projects/Passing array to function/Passing array to function/Source.cpp <==
/*
The name of an array works like a pointer to it

Therefore when only the name of an array is used as an argument to
a function on;y the address of the first element is passed there.

Any element of an array passed to a function by its name can be 
changed within the function.

Arrays are the only objects in C++ that cannot be passed to afunction by value

The size of the array is not automatically stored, this is the responsibilty of 
the programmer to make sure this information is somehow passed to the function
so that the correct chunk of memory is used
*/

#include <iostream>
#include <iomanip>

using namespace std;

void Fun9(unsigned A[], int N);

int main(){
	unsigned AR[] = { 4, 12, 3, 20, 11, 0, 0, 5 };
	const int N = sizeof(AR) / sizeof(AR[0]);
	for (int k = 0; k < N; k++){
		cout << setw(4) << AR[k];
	}
	Fun9(AR, N);
	cout << endl;
	for (int k = 0; k < N; k++){
		cout << setw(4) << AR[k];
	}
	cout << "\n\n";
	return 0;
}

//Makes all but largest component of array equal to zero
void Fun9(unsigned A[], int N){
	unsigned *Largest = A;
	for (int k = 1; k < N; k++){
		if (A[k] > *Largest){
			*Largest = 0;
			Largest = A + k;
		}
		else{
			A[k] = 0;
		}
	}
}

//if want to pevent aray being chained by function use const identifier

//void Fun9(const unsigned A[], int N); 

==> ./Projects/passing data - by value/passing data - by value/Source.cpp <==
#include <iostream>

using namespace std;

void DoubleMe(int B);

int main(){
	int w = 3;

	cout << "w before the founction call is " << w << endl;
	cout << " \n";
	DoubleMe(w);
	cout << "w after the function call is " << w << endl;
	cout << " \n";
	return 0;
}

void DoubleMe(int B){
	cout << "Value passed to the function is " << B << endl;
	cout << " \n";
	B = B * 2;
	cout << "Value at end of the function is " << B << endl;
	cout << " \n";
}
==> ./Projects/Passing data to function by reference/Passing data to function by reference/Source.c <==
#include <stdio.h>

void DoubleMe(int &B);

main()
{
	int w = 3;


}
==> ./Projects/passing dynamic array to function/passing dynamic array to function/Source.cpp <==
#include <iostream>

using namespace std;

void ReadData(int data[], int n);

int main()
{
	int *number;
	int nItems;

	cout << "How many numbers are there to process? : ";
	cin >> nItems;
	number = new int[nItems]; //created dynamically

	ReadData(number, nItems); //pass and use like a static array
	
	for (int n = 0; n < nItems; n++)
	{
		cout << number[n] << " ";
	}

	return 0;
}

void ReadData(int data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cin >> data[i];

}
==> ./Projects/passing dynamic struct to function/passing dynamic struct to function/Source.cpp <==
#include <iostream>

using namespace std;

struct myDataType
{
	char name[20];
	int grade;
};

void ReadData(myDataType *rec);

int main()
{
	myDataType *newrecord;

	newrecord = new myDataType; //created dynamically
	ReadData(newrecord); //pass the address of the new record

	cout << newrecord->name << " " << newrecord->grade << endl;

	delete newrecord;

	return 0;
}

void ReadData(myDataType *rec)
{
	cout << "Enter a name : ";
	cin >> rec->name;
	cout << "Enter a grade : ";
	cin >> rec->grade;
}
==> ./Projects/passing dynamic variable to function/passing dynamic variable to function/Source.cpp <==
#include <iostream>

using namespace std;

void ReadData(int *Data);

int main()
{
	int *number; //number contains an address

	number = new int; //created dynamically
	ReadData(number); //pass by reference - pointer method

	cout << "\nNumber = " << *number << "\n\n";

	return 0;
}

//ReadData needs a parameter that can store an address
//data is a pointer so it can receive an address
void ReadData(int *Data)
{
	cout << "Please enter data : ";
	cin >> *Data; //to read in a value pointed at address we use the dereference operator *
}
==> ./Projects/Passing functions as parameter/Passing functions as parameter/main.cpp <==
/*If function returns a value, can be passed as a parameter of that value*/

#include <iostream>
#include <string>

using namespace std;

//function declarations
string askUserName();
//askUserName - sets name of user
//@return string - name of user

int askCreditScore();
//askCreditScore - asks credit score of user
//@return int - credit score of user

void evaluateScore(int, string);
//evaluateScore - prints whether user has good score or needs to improve
//@param string - name of user
//@param int - credit score of user

int main(){
	evaluateScore(askCreditScore(), askUserName());
	return 0;
}

string askUserName(){
	string name;
	cout << "Please enter your name : ";
	cin >> name;
	cout << endl;
	return name;
}

int askCreditScore(){
	int score;
	cout << "Please enter your credit score : ";
	cin >> score;
	cout << endl;
	return score;
}

void evaluateScore(int score, string name){
	if (score >= 740){		cout << name << " has a good credit score\n";}
	else {		cout << name << " needs to improve their credit score\n";}
}
==> ./Projects/passing multi-dimensinal arrays to funct/passing multi-dimensinal arrays to funct/Source.cpp <==
#include <iostream>

using namespace std;

const int COLS = 3;

void addRows(int[][COLS]);

void printScores(int[][COLS]);

int main(){
	int testscores[][COLS] = { { 2, 3, 4 }, { 7, 6, 5 } };
	addRows(testscores);
	printScores(testscores);
	return 0;
}

void addRows(int testscores[][COLS]){
	int score;
	for (int i = 0; i < 5; i++){
		if (testscores[i][0] == NULL){ //not initisalized so no array member == 0
			cout << "Enter scores for student " << i + 1 << " :";
			for (int j = 0; j < COLS; j++){
				cout << "Enter test #" << j+1 << " :";
				cin >> score;
				testscores[i][j]= score;
			}
		}
	}
}

void printScores(int testscores[][COLS]){
	for (int i = 0; i < 5; i++){
		cout << "\nStudent #" << i + 1 << " scores are: ";
		for (int j = 0; j < COLS; j++){
			cout << testscores[i][j] << " ";
		}
	}
}
==> ./Projects/password program/password program/Source.cpp <==
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string isDigit(string str);

int main(){
	string Password;
	int ch;

	cout << "Password must be more than 6 characters\n";
	cout << "It must contain 2 or more digits, and contain upper and lower case characters\n\n";
	cout << "Please enter your Password : "; cin >> Password;
	cout << endl;
	ch = Password.length();

	if (ch < 6){
		cout << "Your password is too short\n\n";
		cout << "Please re-enter your Password : ";  cin >> Password;
	}

	if (ch >= 6){
		int i = 0;
		isDigit(Password);
	}
}

string isDigit(string str){
	int i = 0, b = 0;
	char c;	
	int ch = str.length();
	while (str[i]){
		c = str[i];
		if ((c > '9') || (c < '0')){
			i++;
			cout << "N ";
		}
		else{
			i++;
			b++;
			cout << "Y ";
		}
		if (i == ch){
				if (b >= 2){
					cout << "Password contains at least 2 digits\n\n";
				}
				else{
					cout << "Password does not contain at least 2 digits\n\n";
				}
			}
	}
	return str;
}
==> ./Projects/password program1/password program1/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

int main(){
	string Password;
	int ch;

	cout << "Password must be more than 6 characters\n";
	cout << "It must contain 2 or more digits, and contain upper and lower case characters\n\n";
start:
	cout << "Please enter your Password : "; cin >> Password;
	ch = Password.length();

	while (ch < 6){
		cout << "Your password is too short\n\n";
		cout << "Please enter your Password : ";  cin >> Password;
		ch = Password.length();
	}

	if (ch >= 6){
		int i = 0, b = 0;
		char c;
		while (Password[i]){
			c = Password[i];
			if ((c > '9') || (c < '0')){
				i++;
			}
			else{
				i++;
				b++;
			}
			if (i == ch){
				if (b < 2){
					cout << "Password must contain two digits\n\n";
					goto start;
				}
				else{
					int i1 = 0, b1=0, b2=0;
					char c1;
					while (Password[i1]){
						c1 = Password[i1];
						if (isupper(c1)){
							b1++;
							i1 = i1 + 1;
							cout << c1;
						}
						else if (islower(c1)){
							b2++;
							i1 = i1 + 1;
							cout << c1;
						}
						else{
							i1++;
							cout << c1;
						}
						if (i1 == ch){
							if ((b1 >= 1) && (b2 >=1)){
								cout << "\n\nNo. of Uppercase characters = " << b1 << endl;
								cout << "No. of Lowercase characters = " << b2;
								cout << "\n\nYou have chosen well grasshopper\n\n";
							}
							else{
								cout << "Password must contain upper and lowercase characters\n\n";
								goto start;
							}
						}
					} 
				}
			}
		}
	}
	return 0;
}


==> ./Projects/pasword encryption/pasword encryption/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

int main(){
	string Password;
	int i = 0, asciivalue;
	char c, encrypted;

	cout << "Please enter your password : "; cin >> Password;

	while (Password[i]){
		c = Password[i];
		int asciivalue = (int)c; //converts character to ASCII value 
		asciivalue += 3;
		char encrypted = (char)asciivalue;
		cout << encrypted;
		i++;
	}
	
	cout << "\n\n" << endl << endl;
	return 0;
}
==> ./Projects/permutation/permutation/Source.c <==
#include <stdio.h>

void swap(char *a, char *b);
void permute(char *str, int l, int r);

main()
{
	char str[] = "AB";
	int y = sizeof(str)/sizeof(char); //there is a null character at the end
	permute(str, 0, (y - 2));
	return;
}

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *str, int l, int r)
{
	int i;
	if (l == r)
	{
		printf("%s \n", str);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((str + l), (str + i));
			permute(str, (l + 1), r);
			swap((str + l), (str + i));
		}
	}
}
==> ./Projects/Pick a card (any card)/Pick a card (any card)/Source.cpp <==
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main(){
	int X, Y;
	string A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, J, Q, K;
	string C, D, H, S;
	char answer;

	A1 = "Ace "; A2 = "Two "; A3 = "Three "; A4 = "Four "; A5 = "Five "; A6 = "Six "; A7 = "Seven "; A8 = "Eight ";
	A9 = "Nine "; A10 = "Ten "; J = "Jack "; Q = "Queen "; K = "King "; C = "of Clubs \n"; D = "of Diamonds \n";
	H = "of Hearts \n"; S = "of Spades \n"; X = 0; Y = 0;

	srand((unsigned int)time(NULL));

	cout << "Would you like to play a game with me? Please enter Y/N : ";
	cin >> answer;
	cout << " \n";
	
	if (answer == 'Y'){
		cout << "Pick a card (any card) \n";
		cout << " \n";
		cout << "Choosing card... \n";
		cout << " \n";

		X = rand() % 13 + 1;
		Y = rand() % 4 + 1;
		if (X == 1){
			cout << A1;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 2){
			cout << A2;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 3){
			cout << A3;
			if (Y == 1){
					cout << C;
				}
			else if (Y == 2){
					cout << D;
				}
			else if (Y == 3){
					cout << H;
				}
			else if (Y == 4){
					cout << S;
				}
			cout << " \n";
			}
		else if (X == 4){
			cout << A4;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 5){
			cout << A5;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 6){
			cout << A6;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 7){
			cout << A7;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 8){
			cout << A8;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 9){
			cout << A9;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 10){
			cout << A10;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 11){
			cout << J;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 12){
			cout << Q;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
		else if (X == 13){
			cout << K;
			if (Y == 1){
				cout << C;
			}
			else if (Y == 2){
				cout << D;
			}
			else if (Y == 3){
				cout << H;
			}
			else if (Y == 4){
				cout << S;
			}
			cout << " \n";
		}
	}
	else {
		cout << "That's a shame... \n";
		cout << " \n";
	}
	return 0;
}
==> ./Projects/pointer (c code)/pointer (c code)/Source.c <==
#include <stdio.h>

main()
{
	char *ptr1_test; //pointer whhich will point to address containing single char
	char test; // variable of type char "test"
	ptr1_test = &test; //copy the address of variable "test" into the pointer
	test = 'C'; //assign ascii value of 'C' to variable "test"
	*ptr1_test = 'B'; //assign ASCII value of 'B' to address held by pointer and subsequently to "test" 
	return;
}
==> ./Projects/Pointer arithmetic/Pointer arithmetic/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int *data, nItems;
	cout << "Enter the number of items to be processed : ";
	cin >> nItems;
	data = new int[nItems];
	
	cout << endl;
	*data = 1;
	for (int i = 0; i < nItems; i++){
		cout << *data << " ";
		data++;
		*data = 4;
	}

	return 0;
}
==> ./Projects/Pointer as an argument to function/Pointer as an argument to function/Source.cpp <==
//if argument needs to be changed in main window, pointer to the argument can be used in the function
//As shown below this changes the argumeent in the main function as well. Note address of x

#include <iostream>

using namespace std;

double ADD(double* px, double y);

int main(){
	double x(1.6), y(5.0), z(0);
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	z = ADD(&x, y);
	cout << x << " + " << y << " = " << z << endl;
	cout << "Adress of x is " << &x << ". The value of x is " << x << endl;
}

double ADD(double* px, double y){
	double z = *px + y;
	cout << "Address of x is " << px << ". The value of x is " << *px << endl;
	*px = 0;
	cout << "Address of x is " << px << ". The value of x is " << *px << endl;
	return z;
}

==> ./Projects/pointer declared constant error/pointer declared constant error/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

double ARR[5];
double* const ptrD = &ARR[0];

int main(){
	for (int n = 0; n < 5; n++){
		*ptrD++ = n;;
	}
	return 0;
}

//IntelliSense: expression must be a modifiable lvalue
//Error	1	error C3892: 'ptrD' : you cannot assign to a variable that is const	
==> ./Projects/pointer declared constant/pointer declared constant/Source.cpp <==
//When a pointer is declared constant (as opposed to a pointer to a constant) the pointer can be used to read and write 
//into pointed variables but the address stored in the pointer cannot be changed.

#include <iostream>
#include <iomanip>

using namespace std;

double ARR[5];
double* const ptrD = &ARR[0];

int main(){
	ptrD[0] = 1;
	ptrD[1] = 2;
	ptrD[2] = 5;
	ptrD[3] = 7;
	cout << setw(4) << *ptrD << setw(4) << ptrD[1] << setw(4) << *(ptrD + 2) << setw(4) << ptrD[3]
		<< endl << endl;
	return 0;
}
==> ./Projects/pointer increment/pointer increment/Source.c <==
#include <stdio.h>

main()
{
	int *x = 5;
	;
	printf("%d", x);
	return;
}
==> ./Projects/pointer test/pointer test/Source.cpp <==
//ptr  // represents the address stored in ptr
//&a  // is the address of the variable a

//If the variable a is of the same type as to which ptr points 
//then the following substitution can be madeptr = &a;

//Pointers can be initialised with addresses of existing objects.
//They can also be initialised to a special value nullptr (or NULL for compatibility with C language)

//The memory location pointed by nulled pointers  cannot be accessed. In fact any attempt like
//long *ptr(nullptr);*ptr = 10L;
//will result in a runtime error and a warning message on the screen.

//If nullptr value is converted to bool type it will evaluate as false.Therefore the following code is safer
//long *ptr(nullptr);
//Label:
//if (ptr)
//	*ptr = 10L;


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long A(1);
	long B(10);
	long *ptr(nullptr);
	//variable ptr is declared to keep an address of a memory place storing a long variable
	ptr = &A;
	cout << "A= " << setw(5) << A << "\tB= " << setw(4) << B << endl;
	cout << "*ptr= " << setw(2) << *ptr << "\tptr= " << setw(8) << ptr << endl << endl;

	 //Assign the address of A to ptr
	*ptr = 2; //Assign 2 to hte memory location pointed by ptr
	cout << "A= " << setw(5) << A << "\tB= " << setw(4) << B << endl;
	cout << "*ptr= " << setw(2) << *ptr << "\tptr= " << setw(8) << ptr << endl << endl;

	ptr = &B; // Assign the address of B to ptr
	cout << "A= " << setw(5) << A << "\tB= " << setw(4) << B << endl;
	cout << "*ptr= " << setw(2) << *ptr << "\tptr= " << setw(8) << ptr << endl << endl;

	*ptr = -4; // Assign 2 to the memory location pointed by ptr
	cout << "A= " << setw(5) << A << "\tB= " << setw(4) << B << endl;
	cout << "*ptr= " << setw(2) << *ptr << "/tptr= " << setw(8) << ptr << endl << endl;
}
==> ./Projects/pointer use in arrays/pointer use in arrays/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

double A[4] = { 20, 21, 22, 23 };
double* ptrA = &A[2]; //ptrA points at 3rd element of array A 

int main(){
	cout << "Array A:\n" << setw(4) << A[0] << setw(4)
		<< A[1] << setw(4) << A[2] << setw(4) << A[3];

	cout << "\n\n*ptrA= " << setw(4) << *ptrA;
	cout << "\n\n*(ptrA+1)= " << setw(4) << *(ptrA + 1);
	cout << "\n\n*(ptrA+2)= " << setw(4) << *(ptrA + 2);
	cout << "\n\n*(ptrA-1)= " << setw(4) << *(ptrA - 1);
	cout << "\n\n*(ptrA-2)= " << setw(4) << *(ptrA - 2);
	cout << "\n\nptrA[0]= " << setw(4) << ptrA[0];
	cout << "\n\nptrA[-1]= " << setw(4) << ptrA[-1];
	cout << "\n\nptrA[-2]= " << setw(4) << ptrA[-2];
	cout << "\n\nptrA[-3]= " << setw(4) << ptrA[-3];
	cout << "\n\nptrA[1]= " << setw(4) << ptrA[1];

	ptrA = A; // The name of the array returns the address of its first element
	cout << "\n\nptrA; \n";
	for (int n = 0; n < 4; n++)
		cout << setw(4) << *ptrA++;
	return 0;
}

//While the pointer looks at specific address at memory it is possible 
//with its use to explore and change the neighbourhood of the pointed address.

//This feature is particularly useful when the pointer points at an element of an 
//array. In such a case the neighbouring components could be other elements of the array

//to access the next of previous memory location we can increase/decrease the pointer using//ptr++, ++ptr, ptr += 1 or ptr = ptr + 1;
//ptr--, --ptr, ptr -= 1 or ptr = ptr - 1;

//Another possibility is indirect access to the memory. To access the memory element 
//next to the one pointed one by the pointer ptr we can use  *(ptr+1), and even ptr[1].
==> ./Projects/pointer variable/pointer variable/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int x;
	int *ptr;
	x = 12;
	ptr = &x;
	//because ptr holds addres of x we say ptr points to x
	
	cout << "x = " << x; //ans = 12
	cout << "\n*ptr = " << *ptr; // ans = 12

	*ptr = 5; //changes the value at address ptr to 5

	cout << "\n\nx = " << x; //ans = 5
	cout << "\n*ptr = " << *ptr << "\n\n"; //ans = 5

	return 0;
}




==> ./Projects/pointer-constant error/pointer-constant error/Source.cpp <==
//Here A is declared as a pointer to a constant. The way to read it is to start with the name of the variable. 
//By going to the left we have a star which indicates that A is a pointer, going further char says that the pointer 
//is to a char type variable and finally const says that the variable is constant. This declaration will inform the 
//compiler that the memory location pointed by A cannot be changed. We clearly violate this rule in the main 
//function. Therefore this programme will not compile and the following message will appear:

#include <iostream>
#include <iomanip>

using namespace std;

const char* A = "abcd";

int main(){
	A[0] = '1';
}

//1	IntelliSense: expression must be a modifiable lvalue - constant error\pointer - constant error\Source.cpp	9	2	pointer - constant error

==> ./Projects/pointers + arrays (c code)/malloc - dynamic allocation (c code)/malloc - dynamic allocation (c code)/Source.c <==
/*malloc() reserves a block of memory and returns an address
syntax: pointer_label = (type *) malloc(size, requires stdlib*/

#include <stdio.h>
#include <stdlib.h>

main()
{
	int *ptr_int; //allocated space in memory
	
	/*sizeof(int) returns memory size of 2 bytes, malloc() 2 bytes of space
	cast (int*) indicates value returned will be pointer which stores an int*/
	
	ptr_int = (int*)malloc(sizeof(int)); //call of functionm malloc()
	//copies address generated by malloc into pointer ptr_int
	
	*ptr_int = 6; //assign to the address held by ptr_int value of 6

	printf("%p \t", &ptr_int); //print address of pointer labelled ptr_int
	printf("%p \t", ptr_int); //print contents of ptr_int, this is address returned by malloc()
	printf("%d \n", *ptr_int); //print value at address pointed to by ptr_int
	return;
}
==> ./Projects/pointers + arrays (c code)/pointers + arrays (c code)/Source.c <==
#include <stdio.h>

void swap(int *p1, int *p2);

main()
{
	int x[3] = { 1, 4, 9 };
	printf("%p %p %d \n", x, &x[0], x[0]);
	printf("%p %p %d \n", (x + 1), &x[1], x[1]);
	printf("%p %p %d %d \n\n", (x + 2), &x[2], x[2], *(x+2));
	
	int *ptr1;
	ptr1 = x; //ptr1 holds based address of x
	for (int i = 0; i < 3; i++)
		printf("%d\n", *ptr1++);

	int a = 3, b = 4;
	printf("\na = %d  b = %d", a, b);
	swap(&a, &b);
	printf("\na = %d  b = %d\n\n", a, b);
	return;
}

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	return;
}
==> ./Projects/pointers to struct/pointers to struct/Source.cpp <==
#include <iostream>

using namespace std;

struct Address{
	char StreetName[25];
	unsigned HouseNumber;
	char Town[15];
	char Postcode[10];
};

struct a_Person{
	char FirstName[10];
	char Surname[10];
	unsigned age;
	unsigned height;
	unsigned weight;
	bool Employed;
	Address PostAddress;
};

a_Person MyNeighbour =
{
	"John",
	"Bloggs",
	32,
	175,
	79,
	true,
	{
		"London Road",
		125
	}
};

a_Person *ptr = &MyNeighbour;

int main(){
	strcpy_s((*ptr).PostAddress.Town, "Wembley");
	strcpy_s(ptr->PostAddress.Postcode, "WQR 3T4");
	cout << ptr->PostAddress.Town << "\n";
	cout << ptr->PostAddress.Postcode << "\n";
	return 0;
}
==> ./Projects/pointers2constant1/pointers2constant1/Source.cpp <==
//Pointer5.cpp

#include <iostream>
#include <iomanip>

using namespace std;

char* A = "abcd";

int main(){
	for (int n = 0; n < 4; n++){
		cout << *A++ << " ";
	}
	cout << endl << endl;
	return 0;
}
==> ./Projects/pointers2constants/pointers2constants/Source.cpp <==
char * A = "abcd";

int main(){
	A[0] = '1';
}

//does not run, string literal "abcd" treated as const char, so cannot be changed
//However the pointer A is not constant and can be changed
==> ./Projects/Prime number/Prime number/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N, N1, N2, i=2;

	cout << "Please enter number : "; cin >> N;
	N1 = N - 1;

	while (i <= N1){
		N2 = N % i;
		i++;
		if (N2 == 0){
			cout << "\nNumber is not a prime number\n\n";
			i = N + 1;
		}
		if (i == N1){
			cout << "\nNumber is a Prime number\n\n";
		}
	}
	return 0;
}
==> ./Projects/print text from file/print text from file/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	fstream Myfile;

	Myfile.open("Example.txt", ios::out | ios::in | ios::app);
	/*Myfile << "This is what's written in the file." << endl;
	Myfile << "This is what I expect to output" << endl;
	Myfile.close();*/
	string Line;
	if (Myfile.is_open()){
		while (getline(Myfile, Line)){
			cout << Line << endl;
		}
	}
	else{
		cout << "The file is closed";
	}
	
	return 0;
}
==> ./Projects/printf command/printf command/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	printf("i = %d\n", i);
	printf("i = %d\n", ++i); 
	//increments variable by 1 before statement execution
	printf("i = %d\n", i);
	cout << "\n";

	i = 1;
	printf("i = %d\n", i);
	printf("i = %d\n", i++);
	//increments variable by 1 after the statement is executed
	printf("i = %d\n", i);

	i = 10;
	int in[4];
	//%d prints in base10(decimal), %x prints hexadecimal, %o prints octal, &i prints integer
	printf("%d %i %x %o\n", i, i, i, i);
	//leading 0 puts in octal mode (base8), 
	sscanf_s("010 010 010 010", "%d %i %x %0", &in[0], &in[1], &in[2], &in[3]);
	printf("%d %d %d %d\n", in[0], in[1], in[2], in[3]);
	sscanf_s("0x10 10 010", "%i %i %i", &in[0], &in[1], &in[2]);
	printf("%d %d %d\n", in[0], in[1], in[2]);

	return 0;
}


==> ./Projects/printf/printf/Source.c <==
/*printf used to display output onto screen. General Syntax-
printf("control string", arg1, arg2, ..., argN);

%c - character
%d - decimal integer
%e - floating point no. with exponent
%f - floating point no. without exponent
%g - floating point no. notrailing zeros
%h - short integer
%i - integer (decimal, hexadecimal, octal)
%o - octal integer
%p - pointer
%s - string(note a null char will be added at end)
%u - unsigned decimal integer
%x - Hexadecimal integer
*/

#include <stdio.h>
#include <math.h> //math library header file

main()
{
	float a = 36.5, b = 23.4;
	printf("%f %f\n\n", sin(a), sqrt(a + b + 3.3));

	int i = 123456;
	float x = 345.678;
	
	printf("%3d %7d\n\n", i, i);

	printf("%3f %13f\n\n", x, x);

	printf("%13e %16e\n\n", x, x, x);

	/*printf("%15.5s", variablename)
	15 = min field length to be displayed on screen;
	5s = number of characters to be displayed from string*/

	char line[12] = "hexadecimal";

	printf("| % 3s ||%3.3s| | % 15s | | %15.5s |\n\n", line, line, line, line);

	/*Can also format representation of floating point numbers in the same way	
	printf("%5.2s", variablename) 
	5 = min field length
	2s = no. of decimal places to be displayed
	*/

	x = 123.456;

	printf("|%7f| |%7.3f| |%7.1f| |%0.2f|\n\n", x, x, x, x);

	printf("|%12e| |%12.5e| |%12.3e|\n\n", x, x, x);

	i = 123; x = 12.0; float y = -3.3;

	//no flags used- Data item right justified blank spaces on left 
	printf("|%6d| |%7.0f| |%10.1e|\n\n", i, x, y);

	//- flag used - Data item left justified/blank spaces on right
	printf("|%-6d| |%-7.0f| |%-10.1e|\n\n", i, x, y);

	//+ flag used - Sign will precede on each numerical data item
	printf("|%+6d| |%+7.0f| |%+10.1e|\n\n", i, x, y);

	//0 flag used- leading 0s to be placed on screen 
	printf("|%06d| |%07.0f| |%010.1e|\n\n", i, x, y);

	//# flag used- force decimal point (%e, f, g) to be displayed even when data is whole no. 
	printf("|%#6d| |%#7.0f| |%#10.1e|\n\n", i, x, y);
}
==> ./Projects/process choice A/process choice A/Source.cpp <==
#include <iostream>

using namespace std;
void demofunction(); // function prototype

//void used if not returning a value other double/int
//double Addnumbers(double A, double B); - typical function
//function prototype needed as function cannot be called unless it has been declared
//enables access to functions written in other source files

int main(){
	cout << "In main\n";
	demofunction();  //function call
	cout << "Back in main\n";
	return 0;
}

void demofunction(){ //function definition
	cout << "In DemoFunction\n";
	cout << "Still in function.\n";
}

//function definition = instructions needed to complete out sub-task
==> ./Projects/product calc example/product calc example/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double res(1), factor;
	for (factor = 0.2; factor < 103; factor *= 2)
		res *= factor;
	cout << fixed << res;
}
==> ./Projects/quadratic equation/quadratic equation/Source.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//real-value solutions to the quadratic equation a x^2 + b x + c = 0
	double a, b, c, d, x1, x2;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;
	cout << "\n";
	if (a = 0){
		cout << "a=0 --> This is not a quadratic equation";
		return -1;
	}

	d = b * b - 4 * a * c;
	
	if (d < 0){
		cout << "This equation has no real solutions";
		return -2;
	}

	x1 = (-b + sqrt(d)) / 2 / a;
	x2 = (-b - sqrt(d)) / 2 / a;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	return 0;
}
==> ./Projects/quadratic equation/quadratic equation/Source1.cpp <==
#include <iostream>

using namespace std;

int main(){
	char letter;
	cout << "Enter a capital letter\n";
	cin >> letter;
	
	if (letter >= 'A'){
		if (letter <= 'Z'){
			cout << "You entered a capital letter";
			return -1;
		}
	}
	cout << "You did not enter a capital letter";
	return 0;
}
==> ./Projects/quadratic equation1/quadratic equation1/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	//real-valued solutions to the equation: a x^2 + b x + c
	double a, b, c, d, x1, x2;
	enum Scenario {None, All, OneFirst, OneSecond, TwoSecond} MyCase;
	// Declaration of the variable MyCase of the type "Scenario" 
	// {None, etc.} are range of values in our created type "Scenario"
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;
	d = b*b - 4 * a*c;
	if (d < 0 || a == 0 && b == 0 && c != 0){
		MyCase = None;
	}
	else if (a == 0){
		MyCase = b!=0 ? OneFirst : All;
		// if (b!=0){MyCase = OneFirst;} else{MyCase = all;}
	}
	else{
		MyCase = d == 0 ? OneSecond : TwoSecond;
		// if (d==0){MyCase = OneSecond;} else{MyCase = TwoSecond;}
	}

	switch (MyCase){
	case None:
		cout << "This equation has no real solutions\n";
		break;
	case All:
		cout << "Any real number is a solution to this equation\n";
		break;
	case OneFirst:
		cout << "One real solution x = " << -c / b;
		break;
	case OneSecond:
		cout << "One real solution x = " << -b / 2 / a;
		break;
	case TwoSecond:
		cout << "Two real solutions\n";
		x1 = (-b + sqrt(d)) / 2 / a;
		x2 = (-b - sqrt(d)) / 2 / a;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	return 0;
}
==> ./Projects/random numbers/random numbers/main.cpp <==
#include <iostream>
#include <ctime>

//gbK4nsr

using namespace std;

int main(){
	srand(time(0)); //uses time to create random number
	int y= 0;
	
	while (y < 40){
		int x = rand() % 122 + 1;
		if (((x >= 48) && (x <= 57)) || ((x >= 65) && (x <= 90)) || ((x >= 97) && (x <= 122))){
			cout << char(x);
			y += 1;
		}
	}
	cout << endl;
	return 0;
}

//clearly buy emotion like jealous some annoy completely false smoke letter wow
==> ./Projects/randomnumber/randomnumber/Source.cpp <==
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	int i, var;

	srand((unsigned int)time(NULL)); //seed the random number
	//generator by using the system time

	for (i = 0; i < 100; i++){
		var = rand() % 31 + 200; //generate random values between 0-10
		// then add 100 to generate range of 100 - 110
		cout << var << endl; //display
	}
	return 0;
}
==> ./Projects/range calculation/range calculation/Source.cpp <==

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
	double V, theta, range;
	const double g = 9.8;

	cout << "Please enter a value for arrow's intial Velocity (m/s): ";
	cin >> V;
	cout << " " << endl;

	cout << "Please enter a value for the arrow's initial angle (radians): ";
	cin >> theta;
	cout << " " << endl;
	 	
	while (V <= 0) {
		cout << "Velocity entered is outside of normal range." << endl;
		cout << " " << endl;
		cout << "Please enter a new value greater than zero: ";
		cin >> V;
		cout << " " << endl;
	}

	while ((theta <= 0) || (theta > 1.571)){
		cout << "Angle entered is outside of normal range." << endl;
		cout << " " << endl;
		cout << "Please enter a value between 0 and 1.571 (radians): ";
		cin >> theta;
		cout << " " << endl;
	}

	range = 2 * V*V*cos(theta)*sin(theta) / g;

	cout << "Range= " << range << endl;
	cout << " " << endl;
	return 0;
}
==> ./Projects/range table/range table/Source.cpp <==
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	float V, theta, range;
	const float g = 9.8;
	theta = 0;
	V = 30;
	cout << "Theta   ";
	while ((theta <= 1.1) && (V == 30)){
		theta = theta + 0.1;
		cout << fixed << setprecision(2) << "  " << theta;
		if (theta >= 1.0){
			V++;
			theta = 0;
		}
	}

	cout << " " << endl;
	cout << " " << endl;
	cout << "Velocity  Range" << endl;
	cout << " " << endl;

	V = 10;
	theta = 0;

	while ((theta <= 1.0) && (V <= 20)){
		if (theta == 0){
			cout << V << "   ";
		}
		theta = theta + 0.1;
		range = 2 * V * V * cos(theta) * sin(theta) / g;
		if (range < 10){
			cout << fixed << setprecision(2) << "  " << range;
		}
		else {
			cout << fixed << setprecision(2) << " " << range;
		}
		if (theta >= 1.0){
			cout << endl;
			V++;
			theta = 0;
		}
	}
	
	cout << " " << endl;
	return 0;
}
==> ./Projects/read text from file2/read text from file2/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	fstream Myfile;
	Myfile.open("Mytext.txt", ios::in | ios::out | ios::app);
	/*Myfile << "1 Alex 16" << endl;
	Myfile << "2 Yoni 28" << endl;
	Myfile << "3 Sarge 24" << endl;
	Myfile.close();*/
	int ID;
	string Name;
	int Age;
	if (Myfile.is_open()){
		while (Myfile >> ID >> Name >> Age){
			cout << ID << " " << Name << " " << Age << endl;
		}
	}
	else{
		cout << "File is closed";
	}
	return 0;
}
==> ./Projects/read text from file2/read text from file2/Source1.cpp <==

==> ./Projects/Reading and Writing Memory Blocks/Reading and Writing Memory Blocks/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int k;
	fstream myfile; 
	//ofstream  to write into files
	//ifstream  to read from files
	//fstream reads and writes to + from files
	
	//After declaring a stream as one of the above we need to 
	//associate it with a physical file on the disk. THis procedure is known as open a file

	myfile.open("example1.txt", ios::out|ios::in|ios::app);

	//The function that opens the file is called open. It has two parameters
	//	- The first paramater must always be provided, it is a string containing the name of
	//	file to open
	//	- The second parameter specifies the mode

	//ios::in	Open for input operations.
	//ios::out	Open for output operations.
	//ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
	//ios::binary	Open in binary mode.

	//If more than one value is to be taken they have to be combined using bitwise or | operator
	//The stream ofstream has the default value ios::out of the mode parameter
	//The stream ifstream has the default value ios::in of the mode parameter
	//The stream fstream always requires specification of the mode

	if (myfile.is_open()){
		cout << "The file is open\n\n";
	}
	else{
		cout << "The file is closed\n\n";
	}

	for (k = 42; k < 50; k++){
		myfile.write(reinterpret_cast<char *>(&k), sizeof(k));
	}
	myfile.seekg(ios::beg);
	k = 0;
	char MyChar;

	//When performing the read / write operation on a file we can monitor if 	//there are any problems detected by the system

	//There are four functions that support this monitoring.
	while (myfile.read(&MyChar, 1), myfile.good()){
		cout << k++ << '\t' << MyChar << '\t' << static_cast<int>(MyChar);
		cout << endl;
	}
	//- bad() -	Returns true if a reading or writing operation fails. For example, the case 	//	of  writing to a file that is not open for writing or if the device has no space left.
	//- fail() - Returns true in the same cases as bad(), but also in the case that a format error
	//	happens, like when an alphabetical character is extracted when trying to read an integer number.
	//- eof() - Returns true if a file open for reading has reached the end.
	// -good() - Returns false in the same cases in which calling any of the previous functions would 
	//	return true.Note that good and bad are not exact opposites(good checks more state flags at once).
	// -clear() will reset the state flags
	
	return 0;
}
==> ./Projects/recursive function (C code) stack model/recursive function (C code) stack model/Source.c <==
#include <stdio.h>

float power(float x, unsigned int n);

main()
{
	float x1 = 6.0, y;
	unsigned int n1 = 3;
	
	y = power(x1, n1);
	
	return;
}

float power(float x, unsigned int n)
{
	int y = 0;
	if (!n) /*if n equals 0*/
		return 1;
	return x*power(x, n - 1);
}

//function will not return any values as it is recursive, used to demonstrate 
//activation record/run-time stack
==> ./Projects/references as arguments to a function/references as arguments to a function/Source.cpp <==
//last mechanism of passing an argument to a function is use of references
//when function called, reference made to appropriate argument and passed to function
//references provides full access to original argument including value and address
#include <iostream>

using namespace std;

double ADD(double &any, double &y);

int main(){
	double x(1.6), y(5.0), z(0);
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	z = ADD(x, y);
	cout << x << " + " << y << " = " << z << endl;
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	return 0;
}

double ADD(double &any, double &y){
	double z = any + y;
	cout << "Address of x is " << &any << ". The value of x is " << any << endl;
	any = 0;
	cout << "Address of x is " << &any << ". The value of x is " << any << endl;
	return z;
}
 
==> ./Projects/repeating block - loop/repeating block - loop/Source.cpp <==
//Many programming tasks require repeating a sequence (block)
//of statements with just a few changes

#include <iostream>

using namespace std;

int main(){
	int N, Sum(0), Comp(1);
	cout << "N="; cin >> N;
	if (N < 1 || N>1000000){
		cout << "N is outside the permissible range";
	}
loopdeloop:
	Sum = Sum + Comp;
	Comp += 2;
	if (Comp <= N){
		goto loopdeloop;
	}
	cout << "Sum = " << Sum << endl;
	return 0;
}
==> ./Projects/running total/running total/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int RunningTotal;
	int BP;
	int i;
	int nReadings;

	RunningTotal = 0;
	i = 1;
	cout << "How many BPs to add? : "; cin >> nReadings;
	cout << " " << endl;
	while (i <= nReadings) {
		cout << "Enter a BP: " << endl;
		cin >> BP;
		cout << " " << endl;
		RunningTotal = RunningTotal + BP;
		i++;
	}
	cout << "Average BP is :" << endl;
	cout << RunningTotal / nReadings << endl;
	cout << " " << endl;
	return 0;
}
==> ./Projects/saving a text file/saving a text file/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ofstream Myfile;
	int Array = 1;
	string *Newtext;
	string New;
	string *Arraystore;
	
	Newtext = new string[Array];
	Arraystore = new string[Array];
	Newtext[0] = "0";
	int n;

	for (n = 0; n < Array; n++){
		Newtext = new string[Array];
		cin >> New;
		for (int k = 0; k < n; k++){
			Newtext[k] = Arraystore[k];
		}
		Newtext[n] = New;
		if (Newtext[n] != "3ND"){
			Array += 1;
			n++;
			Arraystore = new string[Array];
			for (int k = 0; k < n; k++){
				Arraystore[k] = Newtext[k];
			}
			cin >> New;
			Arraystore[n] = New;
			if (Arraystore[n] != "3ND"){
				Array += 1;
			}
		}	
	}

	Array--;

	if (n % 2){
		for (int x = 0; x < Array; x++){
			cout << Newtext[x] << " ";
			}
	}
	else{
		for (int x = 0; x < Array; x++){
			cout << Arraystore[x] << " ";
		}
	}

	Myfile.open("Newfile.txt", ios::in | ios::out | ios::app);
	if (n % 2){
		for (int x = 0; x < Array; x++){
			Myfile << Newtext[x] << " ";
		}
	}
	else{
		for (int x = 0; x < Array; x++){
			cout << Arraystore[x] << " ";
		}
	}
	Myfile.close();
	return 0;
}
==> ./Projects/scanf continued/scanf continued/Source.c <==
#include <stdio.h>

main()
{
	char line[80];
	scanf("%[^\n]", line);
	
	/*reads a line into string 'line' - input all characters except for new line \n
	carat symbol - ^, code stops reading when it encounters the <CR>*/

	int a, b, c;
	scanf("%3d %4d %2d", &a, &b, &c);
	
	/*inputs integers max size 3 digits long, 4 digits long and 2 digits long and stores
	at memory addresses a, b, and c

	Potential issues: input of 3432 564 34 would result in	a = 343, b = 2, c = 56*/
}
==> ./Projects/scanf/scanf/Source.c <==
/*Data can be read using scanf

Syntax: Scanf("Control string", arg1, arg2, ..., argN);

Control string contains required formatting info.
It is made up of individual groups of characters which must begin with a % sign.

%c - character
%d - decimal integer
%e - floating point no. with exponent
%f - floating point no. without exponent
%g - floating point no. notrailing zeros
%h - short integer
%i - integer (decimal, hexadecimal, octal)
%o - octal integer
%p - pointer
%s - string(note a null char will be added at end)
%u - unsigned decimal integer
%x - Hexadecimal integer

arg1, arg2, .. etc are individual arguments for each data item to be read
*/

#include <stdio.h>

main()
{
	char item[20];
	int a;
	float cost;

	//input a string %s, into memory location 'item', NB: item represents base address for array
	//input an integer %d, and place at the address location of 'a' (&a)
	//input a floating point number %f, and place at address location of 'cost' (&cost)
	scanf("%s %d %f", item, &a, &cost);

	/*scanf uses blank spaces as its data item seperator
	This can cause problems

	consider the following piece of code*/
	
	char item1[20];
	int int1;

	//scanf("%s %d", item1, &int1);
	
	/*if a string such as G Charambolous 6 was entered, G would form the initial string, the function would 
	attempt to input Charambolous into the address for int1 and the 6 would also cause problems*/
}
==> ./Projects/searching null-terminated strings/searching null-terminated strings/Source.cpp <==
#include <iostream>

using namespace std;

char Str1[] = "3195";
char Str2[] = "213";
char Str3[] = "1332AT";
char Str4[] = "XYZ";

int main(){
	cout << "Searching " << Str1 << " for " << Str2 << ".\t\tResult: "
		<< strspn(Str1, Str2) << endl; //The function strspn() searches the first string to 
	//find there the first occurrence of any character not contained in the second string
	cout << "Searching " << Str1 << " for " << Str3 << ".\tResult: "
		<< strspn(Str1, Str3) << endl;
	cout << "Searching " << Str1 << " for " << Str4 << ".\t\tResult: "
		<< strspn(Str1, Str4) << endl;
	cout << "Searching " << Str2 << " for " << Str1 << ".\t\tResult: "
		<< strspn(Str2, Str1) << endl;
	cout << "Searching " << Str2 << " for " << Str3 << ".\tResult: "
		<< strspn(Str2, Str3) << endl;
	cout << "Searching " << Str2 << " for " << Str4 << ".\t\tResult: "
		<< strspn(Str2, Str4) << endl;
	cout << "Searching " << Str3 << " for " << Str1 << ".\tResult: "
		<< strspn(Str3, Str1) << endl;
	cout << "Searching " << Str3 << " for " << Str2 << ".\tResult: "
		<< strspn(Str3, Str2) << endl;
	cout << "Searching " << Str3 << " for " << Str4 << ".\tResult: "
		<< strspn(Str3, Str4) << endl;
	cout << "Searching " << Str4 << " for " << Str1 << ".\t\tResult: "
		<< strspn(Str4, Str1) << endl;
	cout << "Searching " << Str4 << " for " << Str2 << ".\t\tResult: "
		<< strspn(Str4, Str2) << endl;
	cout << "Searching " << Str4 << " for " << Str3 << ".\tResult: "
		<< strspn(Str4, Str3) << endl;
	return 0;
}
==> ./Projects/sentinelloop/sentinelloop/Source.cpp <==
//Sentinel loop
//bp must be greater than or equal to zero
//so any negative number can act as a sentinel

#include <iostream>

using namespace std;

int main(){
	int BP;
	int i;
	int RunningTotal;

	i = 0;
	RunningTotal = 0;
	BP = 0;
	while (BP != -1){
		cout << "Please enter a blood pressure: ";
		cin >> BP;
		cout << " " << endl;
		if (BP != -1){
			i++;
			RunningTotal = RunningTotal + BP;}
		}
	cout << "Total entries: " << i << endl;
	cout << " " << endl;
	cout << "Average blood pressure is: " << RunningTotal / (i) << endl;
	cout << " " << endl;
	return 0;
}
==> ./Projects/shell4/shell4/Source.cpp <==
//Program Shell4 reads in a temperature and prints an appropriate message
#include <iostream>

using namespace std;

int main(){
	int temp;

	cout << "Enter the temperature in your room : ";
	cin >> temp;

	if (temp > 90){
		cout << "Visit a neighbour." << endl;
	}
	else if ((temp <= 90) && (temp > 80)){
		cout << "Turn on air conditioning." << endl;
	}
	else if ((temp <= 80) && (temp > 70)){
		cout << "Do nothing." << endl;
	}
	else if ((temp <= 70) && (temp > 55)){
		cout << "Turn on heat." << endl;
	}
	else
		cout << "Go back to bed." << endl;
	return 0;
}
==> ./Projects/simple c++ class declaration/simple c++ class declaration/Header.h <==

==> ./Projects/simple c++ class declaration/simple c++ class declaration/Set function.cpp <==
#include "Tymetype.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Timetype::Set(int h, int m, int s){
	hrs = h;
	mins = m;
	secs = s;
}

void Timetype::Increment()
{
	secs++;
	if (secs >= 60)
	{
		secs = 0;
		mins++;
	}
	if (mins >= 60)
	{
		mins = 0;
		hrs++;
	}
	if (hrs >= 24)
	{
		hrs = 0;
	}
}

void Timetype::Write()
{
	cout << setfill('0');
	cout << setw(2) << hrs << ':';
	cout << setw(2) << mins << ':';
	cout << setw(2) << secs << endl;
}

bool Timetype::LessThan(const Timetype &otherTime)
{
	if (hrs < otherTime.hrs)
		return true;
	if (hrs > otherTime.hrs)
		return false;
	if (mins < otherTime.mins)
		return true;
	if (secs < otherTime.secs)
		return true;
	if (secs >= otherTime.secs)
		return false;
}

bool Timetype::IsEqual(const Timetype &otherTime)
{
	if ((hrs == otherTime.hrs) && (mins == otherTime.mins)
		&& (secs == otherTime.secs))
		return true;
	else
		return false;
}
==> ./Projects/simple c++ class declaration/simple c++ class declaration/Source.cpp <==
#include <iostream>
#include <iomanip>
#include "Tymetype.h"

using namespace std;

int main(){
	Timetype	currentTime;
	Timetype	endTime;
	bool	done = false;

	currentTime.Set(5, 30, 0);
	endTime.Set(18, 30, 0);
	while (!done) {
		currentTime.Increment();
		if (currentTime.IsEqual(endTime))
			done = true;
	};
	currentTime.Write();
	endTime.Write();

	return 0;
}

==> ./Projects/simple c++ class declaration/simple c++ class declaration/Tymetype.h <==
//the following preprocessor directives are used to avoid the compilation error that
//would otherwise occur from multiple uses of #include for the same header file

#ifndef TIME_H
#define TIME_H

class Timetype {
public:
	//public interface function members
	void Set(int h, int m, int s);
	void Increment();
	void Write();
	bool IsEqual(const Timetype &otherTime);
	bool LessThan(const Timetype &otherTime);

private:
	//private data members
	int hrs;
	int mins;
	int secs;
};

#endif
==> ./Projects/simple dynamic allocation/simple dynamic allocation/Source.cpp <==
//When discussing duration of C++ variables we named three types of them : automatic, static and dynamic
//Dynamic variables are created during the programme runtime. 
//	-They are not declared in the programme,
//	-The programmer does not have to decide how many of them will be created (will be made once programme runs)
//	-In case of arrays the size of them can be decided during the runtime.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double *ptr(nullptr);//A pointer to dynamically allocated variable, initialise to nullptr
	double *pt_dbl(nullptr);
	int n;
	cout << "ptr before memory allocation= " << ptr << endl;
	cout << "pt_dbl before memory allocation= " << pt_dbl << endl << endl;
	ptr = new double; //Memory to store one double number has been created and its adress assigned to ptr
	pt_dbl = new double[3];
	// pt_int = new int[5][8][13]
	cout << "ptr after memory allocation= " << ptr << endl;
	cout << "ptr_dbl after memory allocation= ";
	for (n = 0; n < 3; n++){
		cout << setw(8) << ptr << " ";
	}
	cout << endl << endl;
	*ptr = 3.1415926;
	cout << *ptr << endl;
	delete ptr;
	delete pt_dbl;
	// delete pt_int
	ptr = nullptr;
	pt_dbl = nullptr;
	// pt_int = nullptr
	cout << "ptr after memory deallocation and setting it to nullptr= " << ptr << endl;
	cout << "pt_dbl after memory deallocation and setting it to nullptr= " << pt_dbl << endl;
	return 0;
}
==> ./Projects/software principles tut 3.1/software principles tut 3.1/Source.cpp <==

==> ./Projects/software tutorial 2.1/software tutorial 2.1/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	//In the two lines below you can change initialisation from numerical
	//values to specify the character explicity e.g. 'A', 'n' or '{'

	char C1 = '\103';
	unsigned char C2 = '\x041';

	short I1 = 1234;
	unsigned short I2 = -1; // Check how -1 is converted into an unsigned number

	int I3 = -123456789;
	unsigned I4 = 123456789;

	long I5(0L);
	unsigned long I6 = { 1234567890UL };

	long long I7 = -123456789012345678LL;
	unsigned long long I8 = 123456789012345678ULL;

	float X1 = 123456789.0F;
	double X2 = 1234567890123456789.0;

	bool B1(true);
	cout << "\n";
	cout << "Char numbers" << endl;
	cout << "Type " << typeid(C1).name() << ".\t\tSize " << sizeof(C1)
		<< " byte(s).\tSample value " << C1 << endl;
	cout << "Type " << typeid(C2).name() << ".\t\tSize " << sizeof(C2)
		<< " byte(s).\tSample value " << C2 << endl;
	cout << "\n";

	cout << "Short numbers" << endl;
	cout << "Type " << typeid(I1).name() << ".\t\tSize " << sizeof(I1)
		<< " byte(s).\tSample value " << I1 << endl;
	cout << "Type " << typeid(I2).name() << ".\t\tSize " << sizeof(I2)
		<< " byte(s).\tSample value " << I2 << endl;
	cout << "\n";

	cout << "Int numbers" << endl;
	cout << "Type " << typeid(I3).name() << ".\t\tSize " << sizeof(I3)
		<< " byte(s).\tSample value " << I3 << endl;
	cout << "Type " << typeid(I4).name() << ".\t\tSize " << sizeof(I4)
		<< " byte(s).\tSample value " << I4 << endl;
	cout << "\n";

	cout << "Long numbers" << endl;
	cout << "Type " << typeid(I5).name() << ".\t\tSize " << sizeof(I5)
		<< " byte(s).\tSample value " << I5 << endl;
	cout << "Type " << typeid(I6).name() << ".\t\tSize " << sizeof(I6)
		<< " byte(s).\tSample value " << I6 << endl;
	cout << "\n";

	cout << "Long long numbers" << endl;
	cout << "Type " << typeid(I7).name() << ".\t\tSize " << sizeof(I7)
		<< " byte(s).\tSample value " << I7 << endl;
	cout << "Type " << typeid(I8).name() << ".\t\tSize " << sizeof(I8)
		<< " byte(s).\tSample value " << I8 << endl;
	cout << "\n";
	//format manipulator fixed prints the floating point numbers using fixed point notation
	//Compare how accurately the same value is stored in the float and double variables

	cout << "Float numbers" << endl;
	cout << "Type " << typeid(X1).name() << ".\t\tSize " << sizeof(X1)
		<< " byte(s).\tSample value " << X1 << endl;
	cout << "Type " << typeid(X2).name() << ".\t\tSize " << sizeof(X2)
		<< " byte(s).\tSample value " << X2 << endl;
	cout << "\n";

	cout << "Bool number" << endl;
	cout << "Type " << typeid(B1).name() << ".\t\tSize " << sizeof(B1)
		<< " byte(s).\tSample value " << B1 << endl;
	cout << "Type " << typeid(B1).name() << ".\t\tSize " << sizeof(B1)
		<< " byte(s).\tSample value " << boolalpha << B1 << endl;
	cout << "\n";

	return 0;
}
==> ./Projects/SomeNumbers program/SomeNumbers program/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int SomeNumbers(char *Storage, int Len);

int main(){
	char *Storage;
	int Len;

	cout << "Please input the length of your array : ";
	cin >> Len;

	Storage = new char[Len];
	for (int x = 0; x < Len; x++){
		Storage[x] = 0;
	}

	SomeNumbers(Storage, Len);
	
	cout << "\nNumbers that have been read from file is : " << Len;

	return 0;
}

int SomeNumbers(char *Storage, int Len){
	fstream Newfile;
	char C;

	Newfile.open("SomeNumbers.bin", ios::in | ios::out | ios::binary | ios::app);
	
	while (Newfile.read(&C, 1), Newfile.good()){
		Storage[Len++] = C;
		cout << Storage[Len] << ", ";
	}
	
	return Len;
}
==> ./Projects/sort array descending/sort array descending/Source.cpp <==
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//This function defines how to sort the vector. Pass this function into the third parameter and i will tell it to sort in descending order
bool wayToSort(int i, int j) { return i > j; }

int main(){
	vector<int> IntVec = { 56, 32, -43, 23, 12, 93, 132, -154 };
	
	sort(IntVec.begin(), IntVec.end(), wayToSort);
	
	for (int i : IntVec){
		cout << i << " ";
	}
}
==> ./Projects/sort array/sort array/Source.cpp <==
#include <iostream>
#include <algorithm>

using namespace std;

const int Size = 7;

int main(){
	int Array[Size] = { 5, 3, 32, -1, 1, 104, 53 };

	sort(Array, Array + Size);

	cout << "Sorted Array looks like this." << endl;
	for (size_t i = 0; i != Size; ++i){
		cout << Array[i] << " ";
	}

	return 0;
}
==> ./Projects/spaceninja/spaceninja/Source.cpp <==
#include <iostream>

using namespace std;

int main() {
	const double GunRange = 50.0;
	double X1, Y1, X2, Y2, distance;

	cout << "Please enter Space Ninja's X co-ordinates ";
	cin >> X1; '\n';
	cout << "Please enter Space Ninja's Y co-ordinates ";
	cin >> Y1; '\n';
	cout << "Please enter Space Imp's X co-ordinates ";
	cin >> X2; '\n';
	cout << "Please enter Space Imp's Y co-ordinates ";
	cin >> Y2; '\n';

	distance = sqrt((Y2 - Y1) * (Y2 - Y1) + (X2 - X1) * (X2 - X1));

	cout << "Space Ninja's co-ordinates are: " << X1 << ", " << Y1 << '\n';
	cout << "Space Imps's co-ordinates are: " << X2 << ", " << Y2 << '\n';
	cout << "Distance to target is " << distance << " metres" << '\n';

	if (distance <= GunRange){
		cout << "Target is in range" << '\n';
		cout << "Commencing firing sequence" << '\n';
		cout << "3..." << '\n';
		cout << "2..." << '\n';
		cout << "1..." << '\n';
		cout << "Target desroyed!" << '\n';
	}
	else
	{
		cout << "Target is not in range." << '\n';
	}

	return 0;

}
==> ./Projects/static variables/static variables/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

class Human{
private:
	string *name;
	int * age;
public:
	Human(string s, int n){
		name = new string;
		age = new int;
		*name = s;
		*age = n;
		cout << "New Human object created\n\n";
	}
	void display(){
		cout << "Hi, I am " << *name << " and I am " << *age << " years old.\n\n";
	}
	~Human(){
		delete name;
		delete age;
		cout << "Human object deleted. Memory deallocated.\n\n";
	}
	/*Destructor usually used to deallocate memory*/
};

int main(){
	Human *leslie;
	leslie = new Human("Leslie", 29);

	leslie -> display();
	delete leslie;

	return 0;
}
==> ./Projects/string function call/string function call/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;
string upperCase(string response); //prototype for function

int main(){
	string myText1, myText2, allText;
	myText1 = "smile";
	myText2 = "now";
	cout << "Our string is " << myText1 << endl;
	allText = myText1 + " always";
	cout << "Our string 1 is " << allText << endl;
	allText = myText1 + " " + myText2;
	cout << "Our string 2 is " << allText << endl;
	int sl = myText1.length();
	cout << "The length is " << sl << endl;
	if (myText1 == "smile"){
		cout << "myText1 equal to \"smile\"" << endl;
	}
	if (!(myText1 == myText2)){
		cout << "myText1 not equal to myText2" << endl << endl;
	}

	cout << "substring1 " << myText1.substr(3) << endl;
	cout << "substring2 " << myText1.substr(1, 3) << endl << endl;

	myText1 = myText1.replace(0, 1, "green "); //replace positions between (x,y) with new string 
	cout << "Our new string is " << myText1 << endl;
	myText1 = upperCase(myText1); // caller for function upperCase
	cout << "Our upper string is " + myText1 << endl << endl;
}

string upperCase(string str){
	//cout << str;
	int i = 0;
	char c;
	while (str[i]){
		c = str[i];
		str[i] = toupper(c); //changes letters to uppercase
		i = i++; //moves to next letter in sequuence
	}
	return str;
}
==> ./Projects/string functions/string functions/Source.cpp <==
#include <iostream>
#include <string>
// for string "tools" e.g length, find, substr

using namespace std;

int main() {

	string stateName = "Mississippi";
	int pos;
	int pos1;

	pos = stateName.find("ssi", 0);
	pos1 = stateName.find("is", 0);

	cout << "Number of letter in " << stateName;
	cout << " is " << stateName.length() << '\n';

	// Location of substring "ssi
	cout << "First pos of \"ssi\ is " << stateName.find("ssi", 0) << '\n';
	// 2 arguments, "ssi" = string to find, 0 = position to start looking
	cout << "Second pos of \"ssi\" is " << stateName.find("ssi", pos + 1) << '\n';
	// now pos+1 is position to start looking

	// Location of substring "is"
	cout << "First pos of \"is\" is " << pos1 << '\n';
	// pos1 = stateName.find("is", 0);
	cout << "Second pos of \"is\" is " << stateName.find("is", pos1 + 1) << '\n';

	cout << "Positions 1-4 '" << stateName.substr(0, 4) << "'" << '\n';
	cout << "Positions 5-6 '" << stateName.substr(4, 2) << "'" << '\n';
	cout << "Positions 10-11 '" << stateName.substr(9, 2) << "'" << '\n';

	return 0;
}
==> ./Projects/string handling-character handling/string handling-character handling/Source.cpp <==
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int stringToInt(string response);
string inToString(int response);

int main(){
	string inText, newText;
	char ch;
	int number;
	cout << "Enter number : ";
	cin >> inText;
	cout << " input text is " << inText << endl;
	if (inText.length() != 1){
		cout << " Enter one digit only" << endl;
	}
	ch = inText.at(0);  // get out the first character
	cout << "First input character is " << ch << endl;
	if ((ch > '9') || (ch < '0')){
		cout << "It is not a number character " << endl;
	}
	else {
		number = stringToInt(inText);	//convert to int
		cout << " the number is " << number << endl;
		newText = inToString(number);	//convert to string
		cout << " into text again " << newText << endl;
	}
	}

string inToString(int number){
	stringstream ss;	//create a stringstream
	ss << number;		//add number to the stream
	return ss.str();	//return a string with the contents of the stream
}

int stringToInt(string s){
	stringstream ss;	//create a stringstream
	int number;			//create a place to store our number
	ss << s;			//add number to the stream
	ss >> number;
	return number;
}
==> ./Projects/string input/string input/Source.cpp <==
#include <iostream>

using namespace std;

char TXT[80];

int main(){
	cout << "\n\nType a string\n\n";
	cin.getline(TXT, 20, 'a');
	cout << "\n\n" << TXT;
	return 0;
}
==> ./Projects/string literals/string literals/Source.cpp <==
//each of the four declarations declares a character array 
//of length 6 containing ABCDE terminated with a null character

char txt1[] = "ABCDE";
char txt2[6] = "ABCDE";
char txt3[] = { 'A', 'B', 'C', 'D', 'E', 0 };
char txt4[6] = { 'A', 'B', 'C', 'D', 'E', 0 };

//the string literal is a sequence of characters taken between double quotation marks
//memory space equal to number of characters plus one null character (0) at the end of the array
==> ./Projects/string permutations/string permutations/Source.c <==
#include <stdio.h>
#include <string.h>

void permute(char *a, int l, int r);
void swap(char *x, char *y);

main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n - 1);
	return;
}

void swap(char *x, char *y)
{
	char temp; //creates new character
	temp = *x; //stores value for x in temp
	*x = *y; //puts old value of y in storage space for x
	*y = temp; //puts old value of x in the storage space for y
}

void permute(char *a, int l, int r) //*a is char array (string)
//l is initialised as start of string, r is initialised as last letter of string
{
	int i;
	if (l == r)
		printf("\n\n%s", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			//printf("\nswap A[%i], A[%i]", (a + l), (a + i));
			swap((a + l), (a + i));
			//printf("\npermute A, %i, %i", (l + 1), (r));
			permute(a, l + 1, r);
			//printf("\nswap A[%i], A[%i]", (a + l), (a + i));
			swap((a + l), (a + i)); //backtrack
		}
	}
}
==> ./Projects/string variables/string variables/Source.cpp <==

==> ./Projects/sum for/sum for/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N, Sum, Comp;

	cout << "N = "; cin >> N;
	if (N < 1 || N > 1000000){
		cout << "N is outside the permissible range.\n";
	}
	for (Sum = 0, Comp = 1; Comp <= N; Comp += 2){
		Sum += Comp;
	}
	cout << "Sum = " << Sum << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/sum for1/sum for1/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N, Sum(0), Comp(-1);

	cout << "N = "; cin >> N;
	if (N < 1 || N > 1000000){
		cout << "N is outside the permissible range.\n";
	}
	for (; (Comp += 2) <= N; Sum += Comp);

	cout << "Sum = " << Sum << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/sum/sum/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N, sum(0);

	cout << "Please enter a value for N : "; cin >> N;
	cout << "\n";

	if (N == 5){
		sum += 5; N -= 1;
	}
	if (N == 4){
		sum += 4; N -= 1;
	}
	if (N == 3){
		sum += 3; N -= 1;
	}
	if (N == 2){
		sum += 2; N -= 1;
	}
	if (N == 1){
		cout << "Sum is " << sum++ << endl;
		cout << "\n"; N -= 1;
	}
	else {
		cout << "number outside range\n";
		return -1;
	}
	
	return 0;
}
==> ./Projects/sumfloat/sumfloat/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	float a, b, c, d, e, f;
	
	cout << "Please enter first number : ";
	cin >> a;
	cout << " \n";
	cout << "Please enter second number : ";
	cin >> b;
	cout << " \n";
	cout << "Please enter third number : ";
	cin >> c;
	cout << " \n";
	cout << "Please enter fourth number : ";
	cin >> d;
	cout << " \n";
	cout << "Please enter fifth number : ";
	cin >> e;
	cout << " \n";

	f = a + b + c + d + e;

	cout << "Sum total is : " << f << endl;
	cout << " \n";
	return 0;
}
==> ./Projects/switch statement Ccode/switch statement Ccode/Source.c <==
#include <stdio.h>
#include <math.h>

main()
{
	int flag;
	float x = 112.35, y;

	scanf("%d", &flag);

	switch(flag)
	{
		case -1: y = fabs(x); //returns absolute value of floating point number
			break;
		case 0: y = cos(x);
			break;
		case 1: y = tan(x);
			break;
		case 2: y = sin(x);
			break;
		default: y = x;
	}
	printf("\n\nx = %5.2f \n\ny = %5.2f\n\n", x, y);
}
==> ./Projects/switch statement getchar/switch statement getchar/Source.c <==
#include <stdio.h>

main()
{
	char choice;

	switch (choice = toupper(getchar()))
	{
	case 'R': printf("\nRED\n\n");
		break;
	case 'W': printf("\nWHITE\n\n");
		break;
	case 'B': printf("\nBLUE\n\n");
		break;
	default: printf("\nNeither R W or B inputted\n\n");
	}
}
==> ./Projects/switch statement/switch statement/Source.cpp <==
//switch statement allows to create a large number of branches depending on values of tested expression
//may use following key words "case", "default" and "break"

#include <iostream>

using namespace std;

int main(){
	int N, Sum(0);

	cout << "N = "; cin >> N;
	switch (N){
	case 5: Sum += 5; // if N = 5, sum +5
	case 4: Sum += 4; // if N = 4, sum +4
	case 3: Sum += 3; // if N = 3, sum +3
	case 2: Sum += 2; // if N = 2, sum +2
	case 1:
		cout << "The sum of numbers from 1 to " << N << " is " << ++Sum << endl;
		break;
	default: cout << "The number is outside the permissible range\n";
	}

	cout << "\n";
	return 0;
}
==> ./Projects/switch statement-1/switch statement-1/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int Test = 1;
	switch (Test){
		case 1:
		cout << "One"; // if test= 1 cout...
		break;

		case 2:
		cout << "Two";
		break;
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/switch statement2/switch statement2/Source.cpp <==
//switch statement allows to create a large number of branches depending on values of tested expression
//may use following key words "case", "default" and "break"

#include <iostream>

using namespace std;

int main(){
	int N, Sum(0);

	// all commands following the case where N is satisfied operate sequentially until the "break;" command is used
	// regardless of whether the condition "case" is satisfied or not
	cout << "N = "; cin >> N;
	switch (N){
	case 1: Sum += 1;
	case 2: Sum += 2; 
	case 3: Sum += 3; 
	case 4: Sum += 4; 
	case 5: Sum += 5;	
		cout << "The sum of numbers from " << N << " to 5 is " << Sum << endl;
		break;
	default: cout << "The number is outside the permissible range\n";
	}

	cout << "\n";
	return 0;
}
==> ./Projects/tempconv/tempconv/Source.cpp <==
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

float StringtoFloat(string response);

int main(){
	string Temperature, Nstring;
	int Stringlength, Nstringlength, i, k, Digits=0;
	float Farenheit, Celsius;
	char Temp;
	
Start:
	cout << "Please enter your temperature in degrees Celsius or Farenheit\n";
	cout << "Include a \"C\" or \"F\" (uppercase) after entering the temperature.\n\n";
	cout << "Temperature : ";  cin >> Temperature;

	i = 0; k = 0;
	string Newstring;

	Stringlength = Temperature.length();
	Nstringlength = Stringlength - 1;

	while (i < Stringlength){
		Temp = Temperature[i];
		if ((i == 0) && (Temp == '-')){
			i++;
		}
		else if ((Temp >= '0') && (Temp <= '9')){
			i++;
			if (i == Stringlength){
				cout << "\nTemperature has been entered in an invalid format\n\n";
				goto Start;
			}
		}
		else if (Temp == '.'){
			i++;
			k++;
		}
		else if ((Temp == 'C') || (Temp == 'F')){
			i++;
			cout << Newstring << endl;
			if (k <= 1){
				if (i == Stringlength){
					if (Temp == 'C'){
						cout << "\nThe temperature you have entered is " << Newstring << " degrees Celsius\n\n";
						Digits = StringtoFloat(Newstring);
						Farenheit = 1.8 * Digits + 32;
						cout << Digits << endl;
						cout << fixed << setprecision(2) << "This is equivalent to " << Farenheit << " degrees Farenheit\n\n";
					}
					else if (Temp == 'F'){
						cout << "\nThe temperature you have entered is " << Newstring << " degrees Farenheit\n\n";
						Digits = StringtoFloat(Newstring);
						cout << Digits << endl;
						Celsius = (Digits - 32) * (5.0 / 9.0);
						cout << fixed << setprecision(2) << "This is equivalent to " << Celsius << " degrees Celsius\n\n";
					}
				}
			}
			else {
				cout << "\nTemperature has been entered in an invalid format\n\n";
				goto Start;
			}
		}
		else{
			cout << "\nTemperature has been entered in an invalid format\n\n";
			goto Start;
		}
	}

	//Nstring = Temperature.substr(0, Nstringlength);
	//cout << "\n" << Nstring << endl;

	//Digits = StringtoInt(Nstring);
	//cout << "\n" << Digits << endl;

	return 0;
}

float StringtoFloat(string s){
	stringstream ss;
	float Digits;
	ss << s;
	ss >> Digits;
	return Digits;
}


==> ./Projects/test decrement/test decrement/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int a = 5;

	for (a = 5; a > 0; a--){
		cout << a << " ";
	}
	return 0;
}
==> ./Projects/three function prog/three function prog/Source.cpp <==
#include <iostream>

using namespace std;

int Square(int n);   // Declares these two
int Cube(int n);     // value-returning functions

int main() {
	cout << "The square of 27 is " << Square(27) << '\n'; //Function call
	cout << "The cube of 27 is " << Cube(27) << '\n'; //Function call
	return 0;
}

int Square(int n) {
	return n * n;
}

int Cube(int n) {
	return n * n * n;
}
==> ./Projects/Timestable Basic/Timestable Basic/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/treadmill/treadmill/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double total;
	total = 0;

	for (int i = 1; i <= 30; i++){
		total = total + 3.9;
		if ((i % 5 == 0) && (i != 5)){
			cout << "Calories burned after " << i << " minutes : " << total << endl;
			cout << " \n";
		}
	}
	return 0;
}
==> ./Projects/Triangulation program/c++ 24 inheritance/checking.cpp <==

==> ./Projects/Triangulation program/c++ 24 inheritance/checking.h <==
#ifndef CHECKING_H
#define CHECKING_H

#include "triangle.h"




#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/equilateral.cpp <==
#include "Equilateral.h"

Equilateral::Equilateral(){}

Equilateral::Equilateral(double newbase, double newheight)
	: Triangle(newbase, newheight){
	cout << "Equilateral Triangle created.\n\n";
}

double Equilateral::getePerimeter() const{
	return getBase() * 3;
}
==> ./Projects/Triangulation program/c++ 24 inheritance/equilateral.h <==
#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include "Triangle.h"
#include <iostream>
using namespace std;

class Equilateral : virtual public Triangle{
public:
	//default constructor
	Equilateral();

	//overloaded constructor
	Equilateral(double, double);
	//Equilateral - creates triangle with parameters of side length & height
	//@param double - side length to be set
	//@param double - height to be set

	double getePerimeter() const;
};

#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/externalfunctions.cpp <==
#include "externalfunctions.h"

vector<TriangleV> newTriangles;

static int counter = 0;

void mainScreen(){
	int choice;
	do{
		cout << "What type of triangle would you like to create ?\n\n";
		cout << "1: Scalene\n2: Equilateral\n3: Isoceles\n4: Print Set\n5: Exit\n";
		cout << "\nPlease enter your option : ";
		cin >> choice;
		if (choice < 1 || choice > 5){
			cout << "\nPlease choose a valid option\n\n";
		}
	} while (choice < 1 || choice > 5);

	switch (choice){
	case 1: setScalene(newTriangles); break;
	case 2: setEquilateral(newTriangles); break;
	case 3: setIsoceles(newTriangles); break;
	case 4: printSet(newTriangles); break;
	case 5: cout << "\nThank you for using this program\n\n";
	}
}

void setScalene(vector<TriangleV>& newTriangles){
	double base, height, side1, side2, test, calcS1, calcS2;
	int choice;
	do{
		cout << "\nPlease enter the base in cm : ";
		cin >> base;
		cout << "Please enter side1 in cm : ";
		cin >> side1;
		cout << "Please enter side2 in cm : ";
		cin >> side2;
		cout << "Please enter height in cm : ";
		cin >> height;

		calcS2 = sqrt(side2*side2 - height*height);
		calcS1 = sqrt(side1*side1 - height*height);

		if ((height == side1)&&(height < side2)) {
			test = base - calcS2;
		}
		else if ((height == side2)&&(height < side1)){
			test = base - calcS1;
		}
		else if ((height > side1) || (height > side2)){
			test = 2;
		}
		else if ((side1 > side2) && (calcS1 > base)){
			test = base + calcS2 - calcS1;
		}
		else if ((side2 > side1) && (calcS2 > base)){
			test = base + calcS1 - calcS2;
		}
		else{
			test =
				base - calcS1 - calcS2;
		}

		do{
			if ((test > 0.1) || (test < -0.1)){
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			}
			else {
				choice = 2;
				cout << "\nNow creating triangle...\n";
			}
		} while ((choice < 1) || (choice > 2));
	} while (((test > 0.1) || (test < -0.1)) && (choice == 1));

	if ((test <= 0.1) && (test >= -0.1)){
		TriangleV newScalene(base, side1, side2, height);
		counter++; cout << "counter = " << counter;
		newTriangles.push_back(newScalene);
		cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
		cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
		cout << "Perimeter : " << newTriangles[counter-1].getsPerimeter() << "\n\n";
		cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	}
	mainScreen();
}

void setEquilateral(vector<TriangleV>& newTriangles){
	double side, height;
	cout << "Please enter the length of a side in cm : ";
	cin >> side;

	height = sqrt(side*side - 0.25*side*side);
	TriangleV newEquilateral(side, height);
	counter++;
	newTriangles.push_back(newEquilateral);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getePerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void setIsoceles(vector<TriangleV>& newTriangles){
	double base, side, height;
	int choice;
	do{
		cout << "Please enter the length of your base in cm : ";
		cin >> base;
		cout << "Please enter a side length in cm : ";
		cin >> side;
		if (side <= 0.5*base){
			do {
				cout << "\nThis is not a triangle. Enter 1 to try again or 2 to return to main screen\n";
				cout << "Your choice : ";
				cin >> choice;
				if ((choice < 1) || (choice > 2)){
					cout << "\nPlease pick a valid option\n\n";
				}
				else if (choice == 2){
					cout << "\nNow returning to main screen..\n\n";
				}
			} while ((choice < 1) || (choice > 2));
		}
	} while (side <= 0.5*base);


	height = sqrt(side*side - 0.25*base*base);
	TriangleV newIsoceles(base, side, height);
	counter++;
	newTriangles.push_back(newIsoceles);
	cout << "Height : " << newTriangles[counter-1].getHeight() << "\n\n";
	cout << "Base : " << newTriangles[counter-1].getBase() << "\n\n";
	cout << "Perimeter : " << newTriangles[counter-1].getiPerimeter() << "\n\n";
	cout << "Area : " << newTriangles[counter-1].getArea() << "\n\n";
	mainScreen();
}

void printSet(const vector<TriangleV>& newTriangles){
	unsigned int size = newTriangles.size();
	if (size == 0){
		cout << "\nThere are no triangles in this array\n";
	}
	else{
		cout << "\n";
		for (unsigned int i = 0; i < size; i++){
			cout << "Triangle " << i + 1 << "\n";
			cout << "Height : " << newTriangles[i].getHeight() << "\n";
			cout << "Base : " << newTriangles[i].getBase() << "\n";
			cout << "Perimeter : " << newTriangles[i].getsPerimeter() << "\n";
			cout << "Area : " << newTriangles[i].getArea() << "\n";
		}
	}
	mainScreen();
}
==> ./Projects/Triangulation program/c++ 24 inheritance/externalfunctions.h <==
#ifndef EXTERNALFUNCTIONS_H
#define EXTERNALFUNCTIONS_H

#include <iostream>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "vector.h"

using namespace std;

void mainScreen();
void setScalene(vector<TriangleV>&);
void setEquilateral(vector<TriangleV>&);
void setIsoceles(vector<TriangleV>&);
void printSet(const vector<TriangleV>&);

#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/isoceles.cpp <==
#include "isoceles.h"

Isoceles::Isoceles(){}

Isoceles::Isoceles(double newBase, double newequalSide, double newHeight) 
	: Triangle(newBase, newHeight){
	equalside = newequalSide;
	cout << "Isoceles Triangle created.\n\n";
}

double Isoceles::getiPerimeter() const{
	return getBase() + equalside * 2;
}



==> ./Projects/Triangulation program/c++ 24 inheritance/isoceles.h <==
#ifndef ISOCELES_H
#define ISOCELES_H

#include <iostream>
#include "triangle.h"
using namespace std;

class Isoceles : virtual public Triangle{
private:
	//member variables
	double equalside;
public:
	//default constructor
	Isoceles();

	Isoceles(double base, double equalside, double height);
	//Isoceles - creates Isoceles triangle with base, height, and equal side
	//@param double - base to be set 
	//@param double - equal sides to be set
	//@param double - height to be set

	virtual double getiPerimeter() const;
	//getPerimeter - returns Perimeter of triangle
	//@param double - base to be used in calculation
	//@param double - equal sides to be used in calculation
	//@return double - perimeter to be returned 

};

#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/main.cpp <==
#include <iostream>
#include <vector>
#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include "triangle.h"
#include "externalfunctions.h"

using namespace std;

int main(){
	
	mainScreen();

	return 0;
}


==> ./Projects/Triangulation program/c++ 24 inheritance/scalene.cpp <==
#include "scalene.h"

Scalene::Scalene(){}

Scalene::Scalene(double ibase, double newSide1, double newSide2, double height)
	: Triangle(ibase, height){
	base = ibase;
	side1 = newSide1;
	side2 = newSide2;
	cout << "Scalene Triangle created.\n\n";
}

double Scalene::getsPerimeter() const{
	return side1 + side2 + base;
}


==> ./Projects/Triangulation program/c++ 24 inheritance/scalene.h <==
#ifndef SCALENE_H
#define SCALENE_H

#include "triangle.h"
#include <iostream>
using namespace std;

class Scalene : virtual public Triangle{
private:
	//member variables
	double base, side1, side2;
public:
	//default constructor
	Scalene();

	//overloaded constructor
	Scalene(double base, double side1, double side2, double height);
	//Scalene - creates Scalene object with base, side1, side2 and height

	virtual double getsPerimeter() const;
};

#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/triangle.cpp <==
#include "triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(double equalSides, double iHeight){
	cout << "\nEquilateral triangle created.\n";
	base = equalSides;
	side1 = equalSides;
	side2 = equalSides;
	height = iHeight;
}

Triangle::Triangle(double ibase, double equalSides, double iHeight){
	cout << "\nIsoceles triangle created.\n";
	base = ibase;
	side1 = equalSides;
	side2 = equalSides;
	height = iHeight;
}

Triangle::Triangle(double ibase, double iSide1, double iSide2, double iHeight){
	cout << "\nScalene triangle created.\n";
	base = ibase;
	side1 = iSide1;
	side2 = iSide2;
	height = iHeight;
}

//Accessor functions
double Triangle::getHeight() const{
	return height;
}

double Triangle::getBase() const{
	return base;
}

double Triangle::getSide1() const{
	return side1;
}

double Triangle::getSide2() const{
	return side2;
}

double Triangle::getPerimeter() const{
	return base + side1 + side2;
}

double Triangle::getArea() const{
	return 0.5 * height * base;
}
==> ./Projects/Triangulation program/c++ 24 inheritance/triangle.h <==
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
using namespace std;

class Triangle{
private:
	//member variables
	double height;
	double base;
	double side1;
	double side2;
public:
	//default constructor
	Triangle();

	//overloaded constructor
	Triangle(double side, double height);
	//Equilateral - creates triangle with parameters of side length & height
	//@param double - input to set member variables base, side1, side2
	//@param double - height to be set

	//overloaded constructor
	Triangle(double base, double equalside, double height);
	//Triangle - creates Isoceles triangle with base, height, and equal side
	//@param double - member variable base to be set from input 
	//@param double - member variables side1 and side2 to be set from input
	//@param double - member variable height to be set from input

	//overloaded constructor
	Triangle(double base, double side1, double side2, double height);
	//Triangle - creates Scalene object with base, side1, side2 and height
	//@param double - base length input in cm
	//@param double - side1 length input in cm
	//@param double - side2 length input in cm
	//@param double - height length input in cm

	//accessor functions
	double getHeight() const;
	//getHeight - returns the triangle's height
	//@return double - height to be returned in cm

	double getBase() const;
	//getBase - returns the triangle's height
	//@return double - Triangle's base to be returned in cm
	
	double getSide1() const;
	//getSide1() - returns the triangle's height
	//@return double - Triangle's first side to be returned in cm
	
	double getSide2() const;
	//getSide2() - returns the member variable side2
	//@return double - Triangle's second side to be returned in cm

	double getArea() const;
	//getArea - returns the area of the triangle
	//@return double - area to be returned

	double getPerimeter() const;
	//getPerimeter - returns the area of the triangle
	//@return double - perimeter to be returned
};

#endif
==> ./Projects/Triangulation program/c++ 24 inheritance/Vector.cpp <==
#include "vector.h"

TriangleV::TriangleV(){}

TriangleV::TriangleV(double ibase, double iside1, double iside2, double iheight)
	: Scalene(ibase, iside1, iside2, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double isides, double iheight)
	: Isoceles(ibase, isides, iheight){
	setBase(ibase);
	setHeight(iheight);
}

TriangleV::TriangleV(double ibase, double iheight)
	: Equilateral(ibase , iheight){
	setBase(ibase);
	setHeight(iheight);
}
	
==> ./Projects/Triangulation program/c++ 24 inheritance/vector.h <==
#ifndef TRIANGLEV_H
#define TRIANGLEV_H

#include "equilateral.h"
#include "scalene.h"
#include "isoceles.h"
#include <vector>

class TriangleV : virtual public Isoceles, virtual public Equilateral, virtual public Scalene{
public:
	//default constructor
	TriangleV();

	//overloaded Scalene constructor
	TriangleV(double base, double side1, double side2, double height);

	//overloaded Isoceles constructor
	TriangleV(double base, double sides, double height);

	//overloaded Equilateral constructor
	TriangleV(double base, double height);

};



#endif
==> ./Projects/try1/try1/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/try2/try2/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/tut9 q2 array of struct/tut9 q2 array of struct/Source.cpp <==
#include <iostream>

using namespace std;

struct a_Book{
	char Title[30];
	char Author[30];
	unsigned int PublicationDate;
	bool NotReadYet;
};

a_Book Books[2];

int main(){
	Books[0].PublicationDate = 1921;
	strcpy_s(Books[0].Title, "Ulysses");
	strcpy_s(Books[0].Author, "James Joyce");
	Books[0].NotReadYet = false;
	strcpy_s(Books[1].Title, "The Man Without Qualities");
	strcpy_s(Books[1].Author, "Robert Musil");
	Books[1].PublicationDate = 1952;
	Books[1].NotReadYet = true;

	cout << Books[0].PublicationDate << endl
		<< Books[0].Title << endl
		<< Books[0].Author << endl
		<< (Books[0].NotReadYet ? "I have not read this book" : "I have read this book") << endl << endl
		<< Books[1].Title << endl
		<< Books[1].Author << endl
		<< Books[1].PublicationDate << endl
		<< (Books[1].NotReadYet ? "I have not read this book" : "I have read this book") << endl << endl;

	return 0;
	}
==> ./Projects/tut9 q3 dynamic struct array/tut9 q3 dynamic struct array/Source.cpp <==
#include <iostream>

using namespace std;

struct a_Book{
	char Title[30];
	char Author[30];
	int PublicationDate;
	bool NotReadYet;
};

a_Book *Books;

void Number(int M);

int main(){
	int N;
	char Answer;
	cout << "Please enter the number of books you would like to enter : ";
	cin >> N;
	Books = new a_Book[N];
	for (int x = 0; x < N; x++){
		cout << "\nPlease enter the title of your "; Number(x); cout << " book\nTitle : ";
		cin.getline(Books[x].Title, 30); cin.getline(Books[x].Title, 30);
		cout << "\nPlease enter the author's name\nName : ";
		cin.getline(Books[x].Author, 30);
		cout << "\nPlease enter the date of publication : ";
		cin >> Books[x].PublicationDate;
		cout << "\nHave you read this book? Please enter Y/N : ";
		cin >> Answer;
		if ((Answer == 'Y') || (Answer == 'y')){
			Books[x].NotReadYet = true;
		}
	}
	cout << endl;
	return 0;
}

void Number(int M){
	switch (M){
	case 0: cout << "1st";
		break;
	case 1: cout << "2nd";
		break;
	case 2: cout << "3rd";
		break;	
	}
	if (M > 2){
		cout << M + 1 << "th";
	}
}
==> ./Projects/tutorial 1.2/tutorial 1.2/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double A, B, sum, difference, product, ratio;

	A = 24; B = 8;                                                                   
	cout << fixed << setprecision(0) << "A = " << A << endl;
	cout << fixed << setprecision(0) << "B = " << B << endl;
	cout << "\n";

	sum = A + B; 
	difference = A - B;
	product = A * B;
	ratio = A / B;

	cout << fixed << setprecision(0) << "You entered A=" << A << " and B=" << B << endl;
	cout << fixed << setprecision(0) << "The sum of these numbers is C=A+B=" << sum << endl;
	cout << fixed << setprecision(0) << "The difference of these numbers is D=A-B=" << difference << endl;
	cout << fixed << setprecision(0) << "The product of these numbers is E=A*B=" << product << endl;
	cout << fixed << setprecision(0) << "The ratio of these numbers is F=A/B=" << ratio << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/tutorial 1.3/tutorial 1.3/Source.cpp <==
#include <iostream>
#include <iomanip>

namespace Leslie{
	double length(5.0);
	double height(3.0);
	double width(3.5);
}

namespace Tetteh{
	double length(7.5);
	double height(3.0);
	double width(3.5);
}

using std::cout;
using std::endl;

// define directive changes name of the namespace
#define nmsp Tetteh
#define nmsp2 Leslie

int main(){
	cout << "The length of the room is " << nmsp::length << endl;
	cout << "The height of the room is " << nmsp::height << endl;
	cout << "The width of the room is " << nmsp::width << endl;
	cout << "The length of the room is " << nmsp2::length << endl;
	cout << "The height of the room is " << nmsp2::height << endl;
	cout << "The width of the room is " << nmsp2::width << endl;
	cout << "\n";
	return 0;
}
==> ./Projects/tutorial 1/tutorial 1/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float height;
	double weight;
	unsigned short int age;

	cout << "Please enter your height in meters : ";
	cin >> height;
	cout << "Please enter your weight in kilograms : ";
	cin >> weight;
	cout << "Please enter your age : ";
	cin >> age;

	cout << "You are " << height << "m tall, you weigh " << weight << "kg and you are " << age << " years old. \n";
	cout << endl;
}
==> ./Projects/tutorial 2.3/tutorial 2.3/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	unsigned int Y, a, b, c, d, e, f, g;

	Y = 237; a = 27;
	b = Y & a;
	c = Y | a;
	d = Y ^ a;
	e = Y >> 1;
	f = Y >> 2;
	g = Y >> 3;

	cout << Y / a << endl << endl;
	
	cout << b << endl << endl;

	cout << c << endl << endl;

	cout << d << endl << endl;

	cout << e << endl << endl;

	cout << f << endl << endl;

	cout << g << endl << endl;
}
==> ./Projects/tutorial 7 q1/tutorial 7 q1/Source.cpp <==
#include <iostream>

using namespace std;

void Name(int a, int b){
	while (a--){
		cout << "Leslie\n";
		for (int c = 0; c <= b; c++){
			cout << endl;
		}
	}
}

int main(){
	int x, y;
	do{
		cout << "\nHow many times would you like your name to be printed?\n";
		cout << "Please enter a number between 1 and 5 : ";
		cin >> x;
	} while ((x <= 0) || (x > 5));
	do {
		cout << "\nHow many lines of space should be left between consecutive printouts?\n";
		cout << "Please enter a number between 1 and 5 : ";
		cin >> y;
	} while ((y <= 0) || (y > 5));

	Name(x, y);
	return 0;
}
==> ./Projects/tutorial 7 q2a/tutorial 7 q2a/Source.cpp <==
#include <iostream>

using namespace std;

unsigned long long Factorial(int n);

int main(){
	int n;
	cout << "Please enter the value of the factorial you wish to calculate\n";
	cin >> n;
	Factorial(n);
	return 0;
}

unsigned long long Factorial(int n){
	unsigned long long z = 1ULL;
	while (n--){
		z *= n;
	}
	cout << z;
	return z;
}
==> ./Projects/tutorial 7 q3/tutorial 7 q3/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

void Neg(int A[], int N);

int main(){
	int B[] = { -1, 2, 3, -5, 6, 8 };
	int Z = sizeof(B) / sizeof(B[0]);
	Neg(B, Z);
	cout << "Zeroed neg integers ";
	for (int n = 0; n < Z; n++){
		cout << setw(4) << B[n];
	}
	return 0;
}

void Neg(int A[], int N){
	for (int n = 0; n < N; n++){
		if (A[n] < 0){
			A[n] = 0;
		}
	}
}
==> ./Projects/tutorial 8 q1 + test/tutorial 8 q1 + test/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int scan(double *A, int Length)
{
	int res = 0;
	int k;
	for (k = 0; k < Length; k++)
	{
		if (*A < 0)
		{
			*A = 0;
			res++;
		}
		A++;
	}
	return res;
}

int main()
{
	double B[] = { 1, 2, 3, 5, -6, -12.1, 3, -10, 0, 6 };
	// B++;  This is not allowed
	int N = sizeof(B) / sizeof(B[0]);
	cout << "Before: ";
	int k;
	for (k = 0; k < N; k++)
		cout << setw(6) << B[k];
	int res = scan(B, N);
	cout << "\n\n" << res << " elements were zeroed\n\n";
	cout << "After:  ";
	for (k = 0; k < N; k++)
		cout << setw(6) << B[k];
	cout << endl << endl;
	return 0;
}
==> ./Projects/tutorial 8 q1/tutorial 8 q1/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int* zero(double A[], int Length);

int main(){
	double A[] = { -1, 2, 3, - 4, 5, 6, -7, -8, -9, -10, -11 };
	int Length = sizeof(A) / sizeof(A[0]);
	cout << "A = ";
	for (int k = 0; k < Length; k++){
		cout << A[k] << " ";
	}
	cout << "\n\n";
	int* Result = zero(A, Length);
	cout << Result[0] -1 << " elements were zeroed.\n\n";
	int res = Result[0];
	for (int a = 1; a < res; a++){
		switch (a){
		case 1: cout << a << "st"; break;
		case 2: cout << a << "nd"; break;
		case 3: cout << a << "rd"; break;
		}
		if ((a != 1) && (a != 2) && (a != 3)){
			cout << a << "th";
		}
		cout << " Element was zeroed at position A[" << Result[a] << "]" << endl;
	}
	cout << endl;
	cout << "A = ";
	for (int k = 0; k < Length; k++){
		cout << A[k] << " ";
	}
	cout << "\n\n";
	return 0;
}

int* zero(double A[], int Length){
	int* Result;
	int* Result2;
	int res = 1;

	Result = new int[res];
	Result2 = new int[res];

	for (int k = 0; k < Length; k++){
		if ((A[k] < 0)&&(k < Length)){
			A[k] = 0;
			res++;
			delete[] Result;
			Result = new int[res];
			Result[0] = res;
			for (int a = 1; a < res - 1; a++){
				Result[a] = Result2[a];
			}
			Result[res - 1] = k;
			k++;
			while ((A[k] >= 0) && (k < Length)){
				k++;
			}
			if ((k < Length) && (A[k] < 0)){
				A[k] = 0;
				res++;
				delete[] Result2;
				Result2 = new int[res];
				Result2[0] = res;
				for (int a = 1; a < res - 1; a++){
					Result2[a] = Result[a];
				}
				Result2[res - 1] = k;
			}

		}
	}
	if (res % 2){
		return Result2;
	}
	else{
		return Result;
	}
	cout << endl;
}
==> ./Projects/tutorial q7 2b/tutorial q7 2b/Source.cpp <==
#include <iostream>
using namespace std;
typedef unsigned  long MySize;

MySize Factorial(int);

int main()
{
	int N;
	do
	{
		cout << "N=";
		cin >> N;
	} while (N <0);
	cout << N << "! = " << Factorial(N) << endl;
}

MySize Factorial(int N)
{
	MySize Result = 1ULL;
	while (N--)
		Result *= N;
	return Result;
}

==> ./Projects/tutorial10q1/tutorial10q1/Client.cpp <==
#include <iostream>

using namespace std;

struct myDataType
{
	char name[20];
	int grade;
	char favouriteSubject[20];
};

void ReadData(myDataType data[], int n);

int main()
{
	myDataType *record; //record holds a pointer to a myDataType
	int nItems;
	int i;

	cout << "How many numbers are there to process? : ";
	cin >> nItems;
	record = new myDataType[nItems]; //created dynamically
	ReadData(record, nItems); //effectively record used like an array

	for (i = 0; i < nItems; i++)
	{
		cout << "\n" << record[i].name << "\t" << record[i].grade << endl;
		cout << "Favourite subject : " << record[i].favouriteSubject << endl;
	}
		
	return 0;
}

void ReadData(myDataType data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "\nEnter a name : ";
		cin >> data[i].name;
		cout << "\nEnter a grade : ";
		cin >> data[i].grade;
		cout << "\nEnter your favourite subject : ";
		cin >> data[i].favouriteSubject;
	}
}
==> ./Projects/tutorial7 q2/tutorial7 q2/Source.cpp <==
#include <iostream>

using namespace std;

unsigned long long Factorial(int n);

int main(){
	int n;
	cout << "Please enter the value of the factorial you would like to calculate\n";
	cin >> n;
	Factorial(n);
	return 0;
}

unsigned long long Factorial(int n){
	unsigned long long z = 1;
	for (int a = 1; a <= n; a++){
		z *= a;
	}
	cout << z << "\n";
	return z;
}
==> ./Projects/tutorial9 softdev q1 declaring struct/tutorial9 softdev q1 declaring struct/Source.cpp <==
#include <iostream>

using namespace std;

struct a_Book{
	char Title[30];
	char Author[30];
	unsigned Publication_year;
	bool NotReadyet;
};

int main(){
	a_Book Ulysses{
		"Ulysses",
		"James Joyce",
		1921,
		false,
	};

	cout << Ulysses.Title << endl;
	cout << Ulysses.Author << endl;
	cout << Ulysses.Publication_year << endl;
	cout << "I have " << (Ulysses.NotReadyet ? "not read this book" : "read this book") << "\n\n";

	return 0;
}
==> ./Projects/Two dimensional arrays to function/Two dimensional arrays to function/Source.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void FindAverages(const int A1[][31], double A2[]);
//with higher dimensional array, size of all dimensions except first must be included
//in function header and prototype

int myrand(int n, int y);

int main()
{
	int YearTemps[12][31], i, n = 0, x, y; 
	double Averages[12];
	int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 

	cout << "Please enter average temp(c) for Month " << n + 1 << " : ";
	cin >> y;
	cout << "\nPlease enter interquartile range for Month " << n + 1 << " : ";
	cin >> x;
	y = y - (x * 2);

	for (i = 0; i <= DaysInMonth[n]; i++)
	{	
		if (n < 12)
		YearTemps[n][i] = myrand(x, y);
		if ((i == DaysInMonth[n])&&(n < 12))
		{	
			cout << "\nMonth " << n + 1 << " :\n";
			if (DaysInMonth[n] < 31)
			{
				for (int b = DaysInMonth[n]; b < 31; b++)
				{
					YearTemps[n][b] = 0;
				}
			}
			for (int a = 0; a < 31; a++)
			{
				cout << setw(4) << YearTemps[n][a];
			}			
			n++;
			cout << "\n\nPlease enter average temp(c) for Month " << n + 1 << " : ";
			cin >> y;
			cout << "\nPlease enter interquartile range for Month " << n + 1 << " : ";
			cin >> x;
			y = y - (x * 2); 
			i = 0;
		}
	}
	return 0;
}

int myrand(int n, int y)
{
	unsigned int t;
	static int x = 2; //use static local variable
	if (x == 2)
	{
		t = unsigned(time(0));
		srand(t);
		x = 3; //call srand, then change local variable
	}
	return rand() % n + rand() % n + rand() % n + rand() % n + y + 1;
}

/*void FindAverages(const int A1[][31], double A2[]){
	int month;
	int day, ndays;
	int total;
	int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (month = 0; month < 12; month++)
	{	total = 0;
		ndays = DaysInMonth[month];
		for (day = 0; day < ndays; day++)
		{
			total = total + A1[month][day]; //add up along columns
		}
		A2[month] = double(total) / ndays; //set the value in A2
	}
}*/


==> ./Projects/type casting/type casting/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{
	float a = 6.542; 
	int b = 3, y;

	y = (int)a + b; //a is typecast into an integer value
	cout << "y = " << y << endl;

	return 0;
}
==> ./Projects/typedef statement/typedef statement/Source.cpp <==
#include <iostream>

using namespace std;

int main()
{	typedef int Banana; // Banana alias for int
	Banana Bunch; //create a bunch of bananas 
	Bunch = 10; //set Bunch to 10

	return 0;
}
==> ./Projects/typeid and sizeof with struct/typeid and sizeof with struct/Source.cpp <==
#include <iostream>

using namespace std;

struct Address{
	char StreetName[10];
	unsigned HouseNumber;
	char Town[10];
	char Postcode[10];
} A;

struct a_Person{
	char FirstName[10];
	char Surname[10];
	unsigned age;
	unsigned height;
	unsigned weight;
	bool Employed;
	Address PostAddress;
} B;

int main(){
	cout << "Variable A is \"" << typeid(A).name() << "\" and occupies " << sizeof(A) << " bytes\n";
	cout << "Variable B is \"" << typeid(B).name() << "\" and occupies " << sizeof(B) << " bytes\n";
	return 0;
}
==> ./Projects/understanding rvalue and lvalue/understanding rvalue and lvalue/main.cpp <==
#include <iostream>

using namespace std;

class Dog{

};

int sum(int x, int y){
	return x + y;
};

int sq(int& x){
	return x * x;
}

int square(const int& x){
	return x *x;
}

int main(){
	int i; //i is an l value
	int *p = &i; //lvalues have an identifiable memory address
	i = 2; //memory content is modified

	Dog d1; //d1 is an l value - has an identifiable memory address

	int x = 2; //2 is an rvalue
	x = i + 2; //i+2 is an rvalue
	//&(i + 2); //error, no identifiable memory address,
	//i + 2 = 6; //error, no assignments can be made to iot

	d1 = Dog(); //Dog() is rvalue, no mem address, no assignments can be made to it

	int y = sum(3, 4); //sum(3, 4) is rvalue, no mem address, no assignments
	//lvalues - d1, x, y, i, p
	//rvalues - Dog(), sum(3, 4), 2, i+2

	/*Reference (or lvalue reference): */

	int &r = i;
	//int &r = 5; error, initial value of reference to non-const must be an lvalue

	const int &r1 = 5; //const lvalue reference can be assigned an rvalue
	//creates temporary lvalue to store 5 - memory use

	sq(y);
	//sq(7); error parameter int& x requires lvalue to be passed

	square(y);
	square(7); //fine but creates temporary lvalue object to be passed


}
==> ./Projects/unique word counter 2/unique word counter 2/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	fstream Myfile;
	string L[1310];
	fstream Newfile;
	int n = 0;
	int Total = 0;
	char *Myarray;
	string Word[5400];
	int Money[5400];

	Myfile.open("newfile.txt", ios::out | ios::in | ios::app);
	/*Myfile << "This is what's written in the file." << endl;
	Myfile << "This is what I expect to output" << endl;
	Myfile.close();*/
	string Line;
	if (Myfile.is_open()){
		while (getline(Myfile, Line)){
			L[n] = Line;
			n++;
		}
	}

	for (int a = 0; a < 1310; a++){
		//cout << "Length of string L[" << a << "] is " << L[a].length() << endl;
		Total = Total + L[a].length();
	}

	Myarray = new char[Total];
	n = 0;

	for (int a = 0; a < 1310; a++){
		int c = L[a].length();
		for (int b = 0; b < c; b++){
			Myarray[n] = L[a].at(b);
			switch (Myarray[n]){
			case (char)145: Myarray[n] = char(96);
				break;
			case (char)146: Myarray[n] = char(39);
				break;
			case (char)147: Myarray[n] = char(34);
				break;
			case (char)148: Myarray[n] = char(34);
				break;
			}
			if ((Myarray[n] >= (char)65) && (Myarray[n] <= (char)90)){
				int H = (int)Myarray[n];
				H = H + 32;
				Myarray[n] = (char)H;
			}
			n++;
		}
	}

	for (int x = 0; x <5400; x++){
		Money[x] = 0;
	}

	n = 0;
	int d = 0;
	int a = 0;

	while (a < Total){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case (char)39:
				int b = 0;
				int c = 0;
				if ((Myarray[a - 1] >= 'a') && (Myarray[a - 1] <= 'z')){
					do{
						if ((Myarray[d] >= 'a') && (Myarray[d] <= 'z')){
							for (b = d; b < a; b++){
								Word[n] = Word[n] + Myarray[b];
							}
						}
						else d++;
					} while (b < a);
					d = a + 1;
					if (Word[n] == "s"){
						Word[n].clear();
					}
					/*else{
						cout << "Word [" << n << "] = " << Word[n] << endl;
					}*/
					for (c = 0; c < n; c++){
						if (Word[n] == Word[c]){
							Word[n].clear();
							Money[c]++;
							c = n + 1;
						}
					}
					if (c == n){
						Money[n] = Money[n] + 1;
						n++;
					}
				}
			}
		}

		int *M;
		string *N;
		int Most = 0;

		M = new int[n];
		N = new string[n];

		for (int x = 0; x < n; x++){
			if (Money[x] >= Most){
				Most = Money[x];
				if (x != 0){
					for (int b = x; b > 0; b--){
						M[b] = M[b - 1];
						N[b] = N[b - 1];
					}
				}
				M[0] = Most;
				N[0] = Word[x];
			}
			else{
				for (int b = 0; b < x; b++){
					if (Money[x] >= M[b]){
						for (int c = x; c > b; c--){
							M[c] = M[c - 1];
							N[c] = N[c - 1];
						}
						M[b] = Money[x];
						N[b] = Word[x];
						b = n + 2;
					}
				}
			}
		}

	Myfile.close();
	
	Newfile.open("output3.txt", ios::in | ios::out | ios::app);
	for (int a = 0; a < 1000; a++){
		if ((M[a] < 100) && (M[a] > 10)){
			Newfile << N[a] << ", ";
		}
	}

	Newfile.close();

	return 0;
}

==> ./Projects/unique word counter 3/unique word counter 3/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	fstream Myfile;
	string L[1310];
	fstream Newfile;
	int n = 0;
	int Total = 0;
	char *Myarray;
	string *Word, *Word2;
	int *Money, *Money2;

	Myfile.open("newfile.txt", ios::out | ios::in | ios::app);
	string Line;
	if (Myfile.is_open()){
		while (getline(Myfile, Line)){
			L[n] = Line;
			n++;
		}
	}

	for (int a = 0; a < 1310; a++){
		//cout << "Length of string L[" << a << "] is " << L[a].length() << endl;
		Total = Total + L[a].length();
	}

	Myarray = new char[Total];
	n = 0;

	for (int a = 0; a < 1310; a++){
		int c = L[a].length();
		for (int b = 0; b < c; b++){
			Myarray[n] = L[a].at(b);
			switch (Myarray[n]){
			case (char)145: Myarray[n] = char(96);
				break;
			case (char)146: Myarray[n] = char(39);
				break;
			case (char)147: Myarray[n] = char(34);
				break;
			case (char)148: Myarray[n] = char(34);
				break;
			}
			if ((Myarray[n] >= (char)65) && (Myarray[n] <= (char)90)){
				int H = (int)Myarray[n];
				H = H + 32;
				Myarray[n] = (char)H;
			}
			n++;
		}
	}

	int Array = 1;
	
	Money = new int[Array];
	Money2 = new int[Array];

	for (int x = 0; x < Array; x++){
		Money[x] = 0;
		Money2[x] = 0;
	}

	Word = new string[Array];
	Word2 = new string[Array];
	n = 0;
	int d = 0;
	int a = 0;

	for (n = 0; n < Array; n++){
		delete[] Word;
		Word = new string[Array];
		Money = new int[Array];
		for (int x = 0; x < Array; x++){
			Money[x] = 0;
		}
		for (int k = 0; k < n; k++){
			Word[k] = Word2[k];
			Money[k] = Money2[k];
		}
		while (a < Total){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case (char)39:
				int b = 0;
				int c = 0;
				if ((Myarray[a - 1] >= 'a') && (Myarray[a - 1] <= 'z')){
					do{
						if ((Myarray[d] >= 'a') && (Myarray[d] <= 'z')){
							for (b = d; b < a; b++){
								Word[n] = Word[n] + Myarray[b];
							}
						}
						else d++;
					} while (b < a);
					d = a + 1;
					if (Word[n] == "s"){
						Word[n].clear();
					}
					else{
						cout << "Word [" << n << "] = " << Word[n] << endl;
					}
					for (c = 0; c < n; c++){
						if (Word[n] == Word[c]){
							Word[n].clear();
							Money[c]++;
							c = n + 1;
							n--;
						}
					}
					if (c == n){
						Money[n] = Money[n] + 1;
					}
				}
				if (b > 0){
					a = Total + 1;
					Array++;
				}
			}
		}
		a = d;
		n++;
		delete[] Word2;
		Word2 = new string[Array];
		Money2 = new int[Array];
		for (int x = 0; x < Array; x++){
			Money2[x] = 0;
		}
		for (int k = 0; k < n; k++){
			Word2[k] = Word[k];
			Money2[k] = Money[k];
		}
		while (a < Total){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case (char)39:
				int b = 0;
				int c = 0;
				if ((Myarray[a - 1] >= 'a') && (Myarray[a - 1] <= 'z')){
					do{
						if ((Myarray[d] >= 'a') && (Myarray[d] <= 'z')){
							for (b = d; b < a; b++){
								Word2[n] = Word2[n] + Myarray[b];
							}
						}
						else {
							d++;
						}
					} while (b < a);
					d = a + 1;
					if (Word2[n] == "s"){
						Word2[n].clear();
					}
					else{
						cout << "Word [" << n << "] = " << Word2[n] << endl;
					}
					for (c = 0; c < n; c++){
						if (Word2[n] == Word2[c]){
							Word2[n].clear();
							Money2[c]++;
							c = n + 1;
							n--;
						}
					}
					if (c == n){
						Money2[n] = Money2[n] + 1;
					}
				}
				if (b > 0){
					a = Total + 1;
					Array++;
				}
			}
		}
		a = d;
	}

	int *M;
	string *N;
	int Most = 0;
	M = new int[n];
	N = new string[n];

	for (int x = 0; x < n; x++){
		if (Money[x] >= Most){
			Most = Money[x];
			if (x != 0){
				for (int b = x; b > 0; b--){
					M[b] = M[b - 1];
					N[b] = N[b - 1];
				}
			}
			M[0] = Most;
			N[0] = Word[x];
		}
		else{
			for (int b = 0; b < x; b++){
				if (Money[x] >= M[b]){
					for (int c = x; c > b; c--){
						M[c] = M[c - 1];
						N[c] = N[c - 1];
					}
					M[b] = Money[x];
					N[b] = Word[x];
					b = 5401;
				}
			}
		}
	}

	Myfile.close();

	Newfile.open("output.txt", ios::in | ios::out | ios::app);
	for (int a = 0; a < 1000; a++){
		if ((M[a] < 100) && (M[a] > 10)){
			Newfile << setw(13) << N[a];
			Newfile << " = " << M[a] << " times" << endl;
		}
	}

	Newfile.close();

	return 0;
}

==> ./Projects/unique word counter v2/unique word counter v2/Source.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	string L[10000];
	
	fin.open("newfile.txt");
	for (int x = 0; x < 10000; x++)
	{
		fin >> L[x];
		for (int c = 0; c < x; c++)
		{
			if (L[x] == L[c])
			{
				L[x].clear();
				x--;
			}
		}
		cout << "L [" << x << "] = " << L[x] << endl;
	}
	fin.close();
	return 0;
}

==> ./Projects/Unique word counter/Unique word counter/Source.cpp <==
#include <iostream>
#include <string>

using namespace std;

int main(){
	string *Wordarray;
	int *Wordcounter, X = 0;
	char *Stringliteral, *Stringliteral1;
	char Inputtext;

	while ((X >= 0) && (X < 1000000)){
		cin >> Inputtext;
		X++;
		Stringliteral = new char[X];
		
		for (int n = 0; n < X; n++){
			Stringliteral[n] = Stringliteral1[n];
		}

		cout << "Welcome to the unique word counter\n";
		cout << "\nPlease enter your input text : \n";


	}
	
	return 0;
}
==> ./Projects/unique word counter1]/unique word counter1]/Source.cpp <==
/*First program I designed*/
/*NB - ALL INCREMENTING ARRAYS CAN NOW BE REPLACED WITH VECTORS. NO NEED FOR CHAR ARRAY AS .at() FUNCTION SOLVES
	SAME PROBLEM. NO NEED FOR LINE ARRAY AS CAN PROCESS DATA DIRECTLY FROM STRING LINE. CAN USE IN-BUILT BUBBLE 
	SORT FOR VECTOR INSTEAD OF MANUAL SORT, SO NO SEPARATE ARRAYS NEEDED. TWO VECTORS NEEDED IN TOTAL.
	tolower() FUNCTION CAN BE USED TO CONVERT CHARS TO LOWER CASE - REQUIRES HEADER <CCTYPE>*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main(){
	fstream Myfile; //text file to be read
	string L[6000]; //store for lines of text
	fstream Newfile; //File for writing most popular words and how often they are used (words used more than once)
	int n = 0;  
	int d = 0; 
	int a = 0; 
	int Total = 0; //used to determine how many characters store in line store string array L
	char *Myarray; //pointer for dynamic char array created on basis of total characters determined by total 
	string *Word, *Word2;  
	//pointers for dynamic arrays used as stores for unique words, two are needed to increment array size whilst  
	//preserving contents of old one. 
	/*NB: Use of function can increment array size without need for second array*/
	int *Money, *Money2;
	//above store for count related to word usage for each unique word, two are needed to increment array size
	//whilst preserving contents of old one
	int *M; //int array for storing most popular words
	string *N; //string array for storing most popular words

	Myfile.open("ssa.txt", ios::out | ios::in | ios::app); //opens file for reading input
	/*Myfile << "This is what's written in the file." << endl;
	Myfile << "This is what I expect to output" << endl;
	Myfile.close();*/
	string Line; //string variable for storing lines
	if (Myfile.is_open()){
		while (getline(Myfile, Line)){
			L[n] = Line + " "; //gets lines of text from input file, stores in string array
			n++;
		}
	}
	else{
		cout << "The file is closed"; 
	}

	cout << "n = " << n << endl;
	Myfile.close(); //closes file

	for (int k = 0; k < n; k++){
		//cout << "Length of string L[" << a << "] is " << L[a].length() << endl;
		Total = Total + L[k].length();
	}

	Myarray = new char[Total]; //total number of characters used to initialise char array
	d = 0; //d in this case used to denote position of char array

	for (int k = 0; k < n; k++){ //crawls line string array
		int c = L[k].length(); //stores line length
		for (int b = 0; b < c; b++){ //crawls character elements for length of each line string
			Myarray[d] = L[k].at(b); //inserts character element into char array
			switch (Myarray[d]){
				//finds cases of special characters, changes into to standard ascii
			case (char)145: Myarray[d] = char(96); 
				break;
			case (char)146: Myarray[d] = char(39);
				break;
			case (char)147: Myarray[d] = char(34);
				break;
			case (char)148: Myarray[d] = char(34);
				break;
			}
			if ((Myarray[d] >= (char)65) && (Myarray[d] <= (char)90)){ //if character is upper case
				int H = (int)Myarray[d]; //stores ascii value for upper case character as an integer
				H = H + 32; //changes to ascii value for lower case, ascii value for upper case + 32
				Myarray[d] = (char)H; //lower case character placed into array position
				/*NB - CAN USE tolower() FUNCTION*/
			}
			d++; //moves to next position
		}
	}

	/*NB - CAN READ STRAIGHT FROM LINE ARRRAY USING ABOVE LOOPS AND .at(). NO NEED FOR CHAR ARRAY*/
	
	for (int y = 0; y < 100; y++){
		cout << Myarray[y];
	}

	cout << "\n\nCharacter count (including spaces) = " << Total << endl;

	int Array = 1; //initial size of usage count and unique word arrays
	
	//creates new arrays for storing word usage counts. two needed, one for incrementing, one for transferring 
	//stored values to incremented array
	Money = new int[Array];
	Money2 = new int[Array];

	for (int x = 0; x < Array; x++){
		Money[x] = 0;
		Money2[x] = 0;
	} //initializes values
	
	//creates new arrays for storing unique words. two needed, one for incrementing, one for transferring stored
	//values to incremented array
	Word = new string[Array];
	Word2 = new string[Array];
	
	n = 0; //n variable used to simultaneously crawl up 'unique word' array and usage count arrays as entries added 
	d = 0; 
	a = 0;
	/*d and a are required to crawl the character array, when a finds the end of word case ' ', '.', etc.
	a will denote the position of the case and position d will denote the start of the word, i.e. if the
	first word is "this", a will stop at position 4, and d will be at position 0. For the next word d will
	start at position 5, and a will crawl the char array until it finds the next end of word case. d will be 
	used to crawl up the array to confirm a letter is present to indicate the start of a word*/

	for (n = 0; n < Array; n++){
		delete[] Word; //deletes old array
		Word = new string[Array]; //creates new 'unque word' string array incremented in size
		delete[] Money; //deletes old array
		Money = new int[Array]; //creates new 'word instance count' int array incremented in size
		for (int x = 0; x < Array; x++){
			Money[x] = 0;
		}//initialization - possible problem running without initialization?
		for (int k = 0; k < n; k++){
			Word[k] = Word2[k]; //transfers contents of old word array to new incremented array 
			Money[k] = Money2[k]; //transfers contents of old count array to new incrememted array
		}
		//below code searches character array for next space
		while (a < Total){
			a++;
			switch (Myarray[a]){ //potential cases indicating a word end
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case ';':
			case ')':
			case (char)133:
			case (char)160: 
			case (char)39:
				int b = 0; 
//b is used to crawl the char array between myarray[d] (start of the word) and myarray[a] (end of the word)
				int c = 0;
//c is used to crawl the word array to find out if there is already a matching word entry
				if ((Myarray[a - 1] >= 'a') && (Myarray[a - 1] <= 'z')){ 
				//finds if word end signifier is preceded by a letter
					do{
						if ((Myarray[d] >= 'a') && (Myarray[d] <= 'z')){
							//finds if position d indicates start of word 
							Array++;
							for (b = d; b < a; b++){ 
								Word[n] = Word[n] + Myarray[b];	//the word is added as a new entry
							}
						}
						else d++; //else crawl up char array to find start of word
					} while (b < a); //until word entry has been completed
					d = a + 1; // d moves to start of the next potential word after word end detected
					if (Word[n] == "s"){ //check to see if word is just a case of 's
						Word[n].clear(); //clears entry
						n--;
						Array--;
						//for decreasing the size of the array
					}
					/*else{
						cout << "Word [" << n << "] = " << Word[n] << endl;
					}*/
					for (c = 0; c < n; c++){
						if (Word[n] == Word[c]){ //if match is fonund in word string array
							Word[n].clear(); //clears entry made in array
							Money[c]++; //counts instances of word in program
							c = n + 1; //c prepares for next entry
							n--; 
							Array--; //for decreasing the size of the array
						}
					}
					if (c == n){ //if no match is found
						Money[n] = Money[n] + 1; //add usage count to array slot
						cout << "Word2 [" << n << "] = " << Word[n] << endl;
						//display new addition to unique word array
					}
				}
				if (b > 0){
					a = Total +1;
				}// breaks out of the while loop
			}
		}
		a = d; //sets a to the potential starting position of the next word
		n++; //next potential empty slot of unique word array
		
		/*below runs for the purpose of incrementing the array*/
		delete[] Word2; //deletes old array
		Word2 = new string[Array]; //creates new 'unque word' string array incremented in size
		delete[] Money2; //deletes old array
		Money2 = new int[Array]; //creates new 'word instance count' int array incremented in size
		for (int x = 0; x < Array; x++){
			Money2[x] = 0; 
		}//initialization - possible problem running without initialization?
		for (int k = 0; k < n; k++){
			Word2[k] = Word[k]; //transfers contents of old word array to new incremented array 
			Money2[k] = Money[k]; //transfers contents of old count array to new incrememted array
		}
		//below code searches character array for next space
		while (a < Total){
			a++;
			switch (Myarray[a]){
			case ' ':
			case '?':
			case '!':
			case ',':
			case '.':
			case '"':
			case '-':
			case ':':
			case ';':
			case ')':
			case (char)133:
			case (char)160:
			case (char)39:
				int b = 0;
//b is used to crawl the char array between myarray[d] (start of the word) and myarray[a] (end of the word)
				int c = 0;
//c is used to crawl the word array to find out if there is already a matching word entry
				if ((Myarray[a - 1] >= 'a') && (Myarray[a - 1] <= 'z')){ 
				//finds if word end signifier is preceded by a letter
					do{
						if ((Myarray[d] >= 'a') && (Myarray[d] <= 'z')){
							//finds if position d indicates start of word 
							Array++;
							for (b = d; b < a; b++){
								Word2[n] = Word2[n] + Myarray[b]; //the word is added as a new entry
							}
						}
						else {
							d++; //else crawl up char array to find start of word
						}
					} while (b < a); //until word entry has been completed
					d = a + 1; // d moves to start of the next potential word after word end detected
					if (Word2[n] == "s"){ //check to see if word is just a case of 's
						Word2[n].clear(); //clears entry
						n--;
						Array--;
						//for decreasing the size of the array						
					}
					/*else{
						cout << "Word2 [" << n << "] = " << Word2[n] << endl;
					}*/
					for (c = 0; c < n; c++){
						if (Word2[n] == Word2[c]){ //if match is fonund in word string array
							Word2[n].clear(); //clears entry made in array
							Money2[c]++; //counts instances of word in program
							c = n + 1; //c prepares for next entry
							n--;
							Array--; //for decreasing the size of the array
						}
					}
					if (c == n){ //if no match is found
						Money2[n] = Money2[n] + 1; //add usage count to array slot
						cout << "Word2 [" << n << "] = " << Word2[n] << endl;
						//display new addition to word array
					}
				}
				if (b > 0){
					a = Total + 1; //breaks while loop
				}
			}
		}
		a = d; //sets a at starting position of next potemtial word
	}

	cout << "ok\n";
	//code always ends with Word2 and Money2 array holding most recent version.
	delete[] Word; 
	delete[] Money;
	delete[] Myarray; //char array no longer needed
	
	Newfile.open("uni4.txt", ios::in | ios::out | ios::app); //opens newfile for writing

	for (int k = 0; k < n; k++){
		Newfile << Word2[k] << " " << Money2[k] << endl; //writes results to newfile 
	}

	int Most = 0; //sets up int to be used to store the vslue of the highest word usage count

	M = new int[n]; //n is size of unique words collected
	N = new string[n];

	cout << "alright\n";

	/*entire for loop and if-else statement = manual bubble sort algorithm*/
	for (int x = 0; x < n; x++){
	//if {current word usage count is highest, it goes in position 0 - everything else gets shifted down a place}
		if (Money2[x] >= Most){ 
			Most = Money2[x];  
			if (x != 0){
				for (int b = x; b > 0; b--){  
					M[b] = M[b - 1]; //every other word usage count shifts down shifts down
					N[b] = N[b - 1]; //every other unique word shifts down
				}
			}
			M[0] = Most; //new highest word usage count in position 1
			N[0] = Word2[x]; //associated unique word goes into that position
		}
		else{
			//else crawl down array, if current usage count is bigger or equal to count curently in array slot, it 
			//goes in that position and everything else is shifted down a place
			for (int b = 0; b < x; b++){
				if (Money2[x] >= M[b]){
					for (int c = x; c > b; c--){
						M[c] = M[c - 1]; //every other usage count stored shifts down
						N[c] = N[c - 1]; //every other unique word stored shifts down
					}
					M[b] = Money2[x]; //current word usage count goes into size ordered position
					N[b] = Word2[x]; //associated unique word also goes into postion
					b = n +1;
				}
			}
		}
	}

	for (int x = 0; x < 300; x++){
		cout << N[x] << " = " << M[x] << "times\n"; 
		//outputs 300 most used words in order of how often they are used
	}

	Newfile.close(); //closes newfile

	return 0;
}

/*char Text[120];
char *MyCh(Text);

int main(){.
	cout << "A word is a sequence of characters terminated with a\n";
	cout << "space, tab, comma, full stop or newline. \n\n";
	cout << "A full sentence is a sequence of words terminated with\na full stop";
	cout << ", question mark or exclamation mark.\n\n";
	cout << "Type the text to analyse and press Enter\n\n";
	cin.getline(Text, 120, '\n');

	int Chrno(0), Wrdno(0), Sntno(0);
	bool WordTerminator = true;
	bool SentenceTerminator = true;
	
	do{
		Chrno++;
		switch (*MyCh){
		case ' ':
		case '\t':
		case ',':
			if (!WordTerminator) Wrdno++;
			WordTerminator = true;
			break;
		case '.':
		case '?':
		case '!':
			if (!SentenceTerminator) Sntno++;
			if (!WordTerminator) Wrdno++;
			SentenceTerminator = true;
			WordTerminator = true;
			break;
		default:
			SentenceTerminator = false;
			WordTerminator = false;
		}
	} while (*++MyCh);
	if (!SentenceTerminator) Sntno++;
	if (!WordTerminator) Wrdno++;
	cout << "\n\n" << "This text comprises\n" << Chrno << " characters\n";
	cout << Wrdno << " words, and\n" << Sntno << " sentences\n";
	return 0;
	}*/

/*Word[20000];
int J = 200;
int *Money;

Money = new int[J];

for (int x = 0; x < J; x++){
Money[x] = 0;
}

int n = 0;
int d = 0;
for (int a = 0; a < 115; a++){
switch (Myarray[a]){
case ' ':
case '?':
case '!':
case ',':
case '.':
case '"':
case '-':
case (char)39:
int b = 0;
int c = 0;
if ((Myarray[a - 1] >= 'A') && (Myarray[a - 1] <= 'z')){
do{
if ((Myarray[d] >= 'A') && (Myarray[d] <= 'z')){
for (b = d; b < a; b++){
Word[n] = Word[n] + Myarray[b];
}
}
else d++;
} while (b < a);
if (Word[n] == "s"){
Word[n].clear();
}
else{
cout << "Word [" << n << "] = " << Word[n] << endl;
}
for (c = 0; c < n; c++){
if (Word[n] == Word[c]){
Word[n].clear();
Money[c]++;
c = n + 1;
}
}
if (c == n){
Money[n] = Money[n] + 1;
n++;
}
}
d = a + 1;
}
}

cout << "Money[9] = " << Money[9] << endl;


int M[18];
int Most = 0;

for (int a = 0; a < 18; a++){
M[a] = -1;
}

for (int a = 0; a < 18; a++){
if (Money[a] >= Most){
Most = Money[a];
if (a != 0){
for (int b = a; b > 0; b--){
M[b] = M[b - 1];
}
}
M[0] = Most;
}
else{
for (int b = 0; b < a; b++){
if (Money[a] >= M[b]){
for (int c = a; c > b; c--){
M[c] = M[c - 1];
}
M[b] = Money[a];
b = 18;
}
}
}
}

cout << "\nThe ordered matrix is now :\n";
for (int a = 0; a < 18; a++){
cout << M[a] << " ";
}*/

==> ./Projects/uppercase function/uppercase function/Source.cpp <==
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Uppercase(string str);

int main(){
	string MyText1;
	MyText1 = "smile";

	MyText1 = Uppercase(MyText1);
	cout << "Our upper string is " << MyText1 << endl << endl;
	return 0;
}

string Uppercase(string str){
	int i = 0;
	char c;
	while (str[i]){
		c = str[i];
		str[i] = toupper(c);
		i++;
	}
	return str;
}
==> ./Projects/uppercase function/using const modifier (references)/using const modifier (references)/Source.cpp <==
#include <iostream>using namespace std;

double ADD(const double& rx, double y);

int main()
{
	double x(1.6), y(5.0), z(0);
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
	z = ADD(x, y);
	cout << x << "+" << y << "=" << z << endl;
	cout << "Address of x is " << &x << ". The value of x is " << x << endl;
}

double ADD(const double& rx, double y)
{
	double z = rx + y;
	cout << "Address of x is " << &rx << ". The value of x is " << rx << endl;
	//rx = 0;
	cout << "Address of x is " << &rx << ". The value of x is " << rx << endl;
	return z;
}

fun12.cpp(20) : error C3892 : 'rx' : you cannot assign to a variable that is const

==> ./Projects/using literals/using literals/Resource.h <==
//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by using literals.rc
//

#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_USINGLITERALS_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_USINGLITERALS			107
#define IDI_SMALL				108
#define IDC_USINGLITERALS			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif

==> ./Projects/using literals/using literals/stdafx.cpp <==
// stdafx.cpp : source file that includes just the standard includes
// using literals.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

==> ./Projects/using literals/using literals/stdafx.h <==
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here

==> ./Projects/using literals/using literals/targetver.h <==
#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>

==> ./Projects/using literals/using literals/using literals.cpp <==
#include <iostream>

using namespace std;

int main() {
	cout << "The sum of one plus three is " << 1 + 3 << '\n';
	return 0; 
}

==> ./Projects/using literals/using literals/using literals.h <==
#pragma once

#include "resource.h"

==> ./Projects/using main function with arguments/using main function with arguments/Source.cpp <==
#include <iostream>

using namespace std;

//first argument is integer - specifies how many arguments used when programme called
int main(int argc, char* arg1[]){
//second argument is array of pointers to char. every pointer provides address of string representing the argument
	double Result(0);
	int n;
	for (n = 0; n < argc; n++){
		Result += atof(arg1[n]);
	}
	cout << Result;
}


==> ./Projects/using namespace/using namespace/Source.cpp <==
#include <iostream>

namespace Tom{
	int a;
}

namespace Carl{
	int a;
}

int main(){
	//It is possible that names from a particular namespace are used
	//Without dpecifying the namespace in front of the name. This is
	//achieved with the "using" declaration
		{using namespace Tom;
		a = 4;
		a = a + 1;
		}
	{using namespace Carl;
	a = Tom::a; //The first "a" is from Carl namespace while the second
	//one is from Tom namespace
	a = Carl::a * 2; //It is OK although not needed to indicate the namespace here
	}
	using std::endl;
	std::cout << "The value of a in Tom namespace is " << Tom::a << endl;
	std::cout << " \n";
	std::cout << "The value of a in Carl namespace is " << Carl::a << endl;
	std::cout << " \n";
	return 0;
}
==> ./Projects/using references-pointers/using references-pointers/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double a; // Variable a declared
	double& b(a); // Variable b is a reference to a double, b is initialised to refer to a
	double *c = &b;

	a = 10;
	cout << "a= " << a << "\tb= " << b << "\tc= " << c << "\t&a= " << &a << "\t&b= " << &b << "\t&c= " << &c << endl;
	b = 20;
	cout << "a= " << a << "\tb= " << b << "\tc= " << c << "\t&a= " << &a << "\t&b= " << &b << "\t&c= " << &c << endl;
	cout << "\nNow it does not matter if we deal with a or b";
	cout << "\nIn both cases we modify all.\n\n";
	return 0;
}

//a reference is declared using an ampersand before the name of the variable
//a reference must be initialised when declare i.e. simply "double &b" results in error

//It is illegal to create arrays of references, but references to arrays are OK 
==> ./Projects/vector add/vector add/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	double N[5], M[5], O[5];
	
	cout << "You will now be directed to enter the first vector.\n";

	for (int i = 0; i < 5; i++){
		cout << "\nPlease enter term N[" << i << "] : "; cin >> N[i];
		}
	cout << "\nThe vector you input was ";
	for (int i = 0; i < 5; i++){
		cout << N[i] << " ";
	}

	cout << "\n\nYou will now be directed to enter the second vector.\n";
	for (int i = 0; i < 5; i++){
		cout << "\nPlease enter term M[" << i << "] : "; cin >> M[i];
	}
	cout << "\nThe vector you input was ";
	for (int i = 0; i < 5; i++){
		cout << M[i] << " ";
	}	
	for (int i = 0; i < 5; i++){
		O[i] = M[i] + N[i];
	}
	cout << "\n\nThe result of your vector addition is "; 
	for (int i = 0; i < 5; i++){
		cout << O[i] << " ";
	}

	cout << endl << endl;

	return 0;
}
==> ./Projects/vector ascending order/vector ascending order/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	int N[18];
	int M[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Least = 9999; 

	cout << "Please enter your vector N[18] : \n";
	for (int x = 0; x < 18; x++){
		cout << "N[" << x << "] : "; cin >> N[x];
	}

	cout << "\nOriginal matrix is\n" << "N = ";
	for (int x = 0; x < 18; x++){
		cout << N[x] << " ";
	}

	for (int i = 0; i < 18; i++){
		if (N[i] <= Least){
			Least = N[i];
			int a = i;
			for (a = i; a > 0; a--){
				M[a] = M[a - 1];
			}
			M[0] = N[i];
		}
		else if (N[i] > Least){
			int e = i;
			int d = 0;
			while (d == 0, d < 18){
				if ((N[i] > M[d]) && (M[d] != 0)){ //Make M[d] != whatever value you initialise matrix with
					d++;
				}
				else if ((N[i] > M[d]) && (M[d] == 0)){
					M[d] = N[i];
					d = 18;
				}
				else{
					for (e = i; e > d; e--){
						M[e] = M[e - 1];
					}
					M[d] = N[i];
					d = 18;
				}	
			}
		}
	}
	cout << "\n\nThe ordered matrix should now be\n" << "N = ";
	for (int y = 0; y < 18; y++){
		N[y] = M[y];
		cout << N[y] << " ";
	}
	cout << endl << endl;
	return 0;
}
==> ./Projects/vectors and vector functions/vectors and vector functions/Source.cpp <==
#include <iostream>
#include <vector>

using namespace std;

int main(){
	//format: vector<dataType> name of vector; 
	vector<int> myVector;
	
	//myVector.push_back(value) ==> adds an element to the end of the vector (+resizes it)
	//myVector.at(index) ==> returns value at index position
	//myVector.size() ==> returns an unsined int equal to number of elements
	//myVector.begin() ==> reads vector from first element (index 0)
	
	myVector.push_back(3);
	myVector.push_back(1);
	myVector.push_back(7);
	myVector.push_back(5);
	myVector.push_back(3);
	myVector.push_back(7);

	/*must be unsigned int as vector.size returns unsigned int, signed and 
	unsigned int represent different data types which cannot be compared */
	cout << "Vector = ";
	for (unsigned int i = 0; i < myVector.size(); i++){
		cout << myVector[i] << " ";
	} cout << endl;

	/*myVector.insert(myVector.begin() + int, new value) ==> inserts new value 
	at position equal to integer given*/ 
	myVector.insert(myVector.begin(), 88);
	myVector.insert(myVector.begin() + 4, 777);
	cout << "Vector = ";
	for (unsigned int i = 0; i < myVector.size(); i++){
		cout << myVector[i] << " ";
	} cout << endl;

	/*myVector.erase(myVector.begin() + int, new value) ==> erases value at position 
	equal to integer specified*/
	myVector.erase(myVector.begin());
	myVector.erase(myVector.begin() + 3);
	cout << "Vector = ";
	for (unsigned int i = 0; i < myVector.size(); i++){
		cout << myVector[i] << " ";
	} cout << endl;
	

	/*myVector.empty() ==> returns boolean value to show if vector is empty
	myVector.clear() ==> clears vector*/

	if (myVector.empty()) 
		cout << "\nVector is empty\n";  
	else 
		cout << "\nVector is not empty\n";

	myVector.clear();

	if (myVector.empty()) 
		cout << "\nVector is empty\n";
	else 
		cout << "\nVector is not empty\n";

	return 0;
}
==> ./Projects/vectors as parameters/vectors as parameters/main.cpp <==
/*ectors are large memory items so should always be passed by reference
Use const indentifier if vector shouldn't be changed*/
#include <iostream>
#include <vector>

using namespace std;

//function definitions

void fillVector(vector<int>&);
//fillVector - inputs values to vector
//@param vector<int>& - vector to be filled

void printVector(const vector<int>&);
//printVector - prints values stored in vector
//@param const vector<int>& - vector to be printed

void reverseVector(const vector<int>&);
//reverseVector -prints values stored in vector in reverse order
//@param const vector<int>& - vector to be printed

void printVectorEvens(const vector<int>&);
//printVectorEvens - prints even values stored in vector
//@param const vector<int>& - vector to be printed

void replaceVectorValue(vector<int>&);
//replaceVectorValue - replaces all instances of a particular value in vector
//@oaram vector<int>& - vector to be modified

int main(){
	vector<int> myVector;

	fillVector(myVector);
	printVector(myVector);
	reverseVector(myVector);
	printVectorEvens(myVector);
	replaceVectorValue(myVector);
	return 0;
}

//function definitions
void fillVector(vector<int>& myVector){
	int nextNumber;
	cout << "Please input the next value (press -1 to stop) : ";
	cin >> nextNumber;
	//cout << endl;
	
	while (nextNumber != -1){
		myVector.push_back(nextNumber);
		//cout << "Please input the next value (press -1 to stop) : ";
		cin >> nextNumber;
		//cout << endl;
		}
	cout << endl;
}

void printVector(const vector<int>& myVector){
	cout << "\nVector : ";
	for (unsigned int i = 0; i < myVector.size(); i++){
		cout << myVector[i] << " ";
	}
	cout << endl;
}

void reverseVector(const vector<int>& myVector){
	cout << "\nVector reversed : ";
	for (unsigned int i = myVector.size(); i > 0; i--){
		cout << myVector[i - 1] << " ";
	}
	cout << endl;
}

void printVectorEvens(const vector<int>& myVector){
	cout << "\nEven values stored in vector : ";
	for (unsigned int i = 0; i < myVector.size(); i++){
		if (myVector[i] % 2 == 0){
			cout << myVector[i] << " ";
		}
	}
	cout << endl;
}

void replaceVectorValue(vector<int>& myVectorN){
	int orig, replace;
	cout << "\nPlease enter the original value and the replacement value leaving" <<
		"\na space in-between the two values : ";
	cin >> orig >> replace;
	cout << endl;
	for (unsigned int i = 0; i < myVectorN.size(); i++){
		if (myVectorN[i] == orig){
			myVectorN[i] = replace;
		}
	}
	printVector(myVectorN);
}
==> ./Projects/Vertical histogram/Vertical histogram/Source.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	// Here I detail all the variables I am going to be using for this bit of code
	char A;
	double count1, count2, count3, count4, i, B, totalcount;
	int count1a, count2a, count3a, count4a, B1, B2, total;

    // Here I initialise the variables. I describe char A as a '*' because that's the
	// symbol I want to use on my histogram, count variables are listed as such

	A = '*';
	i = 0;
	count1 = 0;
	count1a = 0;
	count2 = 0;
	count2a = 0;
	count3 = 0;
	count3a = 0;
	count4 = 0;
	count4a = 0;

	// These are the instructions I want to appear on screen for the user of my program

	cout << "At the prompt please enter a students grade between 0 and 100. Press enter." << endl;
	cout << " " << endl;
	cout << "Entering a mark greater than 100 will end the program." << endl;
	cout << " " << endl;
	cout << "Please enter student's grade (0-100): ";

	// This is where the first students grade is entered as variable 'B'

	cin >> B;
	cout << " " << endl;
	B1 = 0;
	B2 = 100;
	total = 0;

	// This counts marks in each category for each grade entered, and allows user to enter the next grade

	while (B <= 100){
		if ((B >= 0) && (B < 30)){
			count1++;
			total = total + B;
		}
		else if ((B >= 30) && (B < 40)){
			count2++;
			total = total + B;
		}
		else if ((B >= 40) && (B < 70)){
			count3++;
			total = total + B;
		}
		else if ((B >= 70) && (B <=100)){
			count4++;
			total = total + B;
		}
		cout << "Please enter student's grade (0-100): ";
		cin >> B;
		cout << endl;
	}

	// This outputs the column headers

	if (B > 100){
		cout << "   0-29" << "  30-39" << "  40-69" << " 70-100" << endl;

		// This places the stars in rows while the stars in the first column have not yet been counted
		while (count1a < count1){
			cout << "   *   ";
			count1a++;
			if ((count2a < count2) && (count3a < count3) && (count4a < count4)){
				cout << "   *   " << "   *   " << "   *   " << endl;
				count2a++;
				count3a++;
				count4a++;
			}
			else if ((count2a < count2) && (count3a < count3) && (count4a >= count4)){
				cout << "   *   " << "   *   " << "       " << endl;
				count2a++;
				count3a++;
			}
			else if  ((count2a < count2) && (count3a >= count3) && (count4a < count4)){
				cout << "   *   " << "       " << "   *   " << endl;
				count2a++;
				count4a++;
			}
			else if ((count2a < count2) && (count3a >= count3) && (count4a >= count4)){
				cout << "   *   " << "       " << "       " << endl;
				count2a++;
			}
			else if ((count2a >= count2) && (count3a < count3) && (count4a < count4)){
				cout << "       " << "   *   " << "   *   " << endl;
				count3a++;
				count4a++;
			}
			else if ((count2a >= count2) && (count3a >= count3) && (count4a < count4)){
				cout << "       " << "       " << "   *   " << endl;
				count4a++;
			}
			else if ((count2a >= count2) && (count3a < count3) && (count4a >= count4)){
				cout << "       " << "   *   " << "       " << endl;
				count3a++;
			}
			else if ((count2a >= count2) && (count3a >= count3) && (count4a >= count4)){
				cout << " " << endl;
			}
		}

		// This places the stars in rows after the first column has been counted 

		if (count1a >= count1){
			while ((count2a < count2) && (count3a < count3) && (count4a < count4)){
				cout << "       " << "   *   " << "   *   " << "   *   " << endl;
				count2a++;
				count3a++; 
				count4a++;
			}
			while ((count2a < count2) && (count3a < count3) && (count4a >= count4)){
				cout << "       " << "   *   " << "   *   " << "       " << endl;
				count2a++;
				count3a++;
			}
			while ((count2a < count2) && (count3a >= count3) && (count4a < count4)){
				cout << "       " << "   *   " << "       " << "   *   " << endl;
				count2a++;
				count4a++;
			}
			while ((count2a < count2) && (count3a >= count3) && (count4a >= count4)){
				cout << "       " << "   *   " << "       " << "       " << endl;
				count2a++;
			}
			while ((count2a >= count2) && (count3a < count3) && (count4a < count4)){
				cout << "       " << "       " << "   *   " << "   *   " << endl;
				count3a++;
				count4a++;
			}
			while ((count2a >= count2) && (count3a >= count3) && (count4a < count4)){
				cout << "       " << "       " << "       " << "   *   " << endl;
				count4a++;
			}
			while ((count2a >= count2) && (count3a < count3) && (count4a >= count4)){
				cout << "       " << "       " << "   *   " << "       " << endl;
				count3a++;
			}
		}
	}
	return 0;
}
==> ./Projects/wages/wages/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/wallpaper rolls/wallpaper rolls/Source.cpp <==
#include <iostream>

int main(){
	using namespace std;
	const double RollWidth(1.2); //width in metres
	const double RollLength(15); //length of roll in metres
	double RoomWidth, RoomLength, RoomHeight, Perimeter, NoStripes, StripesPerRoll;
	int NoRolls;
	cout << "Width of room (in meters) = ";
	cin >> RoomWidth;
	cout << "Length of room (in meters = ";
	cin >> RoomLength;
	cout << "Height of room (in meters) = ";
	cin >> RoomHeight;
	Perimeter = 2 * (RoomLength + RoomWidth);
	NoStripes = ceil(Perimeter / RollWidth);
	// ceil function rounds number up i.e 1.1 -> 2.0 or -1.1 -> -1.0 
	StripesPerRoll = floor(RollLength / RoomHeight);
	// floor function rounds number down i.e. 1.1 -> 1.0 or -1.1 -> -2.0
	NoRolls = static_cast<int>(ceil(NoStripes / StripesPerRoll));
	// type casting assingns an expression of one type (double) into variable of diff type (int)
	//static_cast<int> converts into integer type, ceil rounds up 
	cout << "You need " << NoRolls << " rolls for this room \n";
	cout << "\n";
	return 0;
}
==> ./Projects/week 1 exercises/week 1 exercises/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/week 1/week 1/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/week 1/week 1/mymain.cpp <==
ï»¿#include <iostream>

int main() {
	double wages1
	double wages2
	double total

	wages1 = 10.50
	wages2 = 35.63
	total = wages1 + wages2
	std::cout << "Total wages = "
		<< total << std::end1
	return 0
}


==> ./Projects/while loop BASIC 2/while loop BASIC 2/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/while loop BASIC/while loop BASIC/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>false</MySubMain>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>2</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/while loop/while loop/Source.cpp <==
#include <iostream>

using namespace std;

int main() {
	int i;
	i = 1;
	
	while (i <= 4){
		cout << "i = " << i << endl;
		i++;
	}
	cout << "Done" << endl;
	return 0;
}
==> ./Projects/while-lopp/while-lopp/Source.cpp <==
#include <iostream>

using namespace std;

int main(){
	bool Correct(false);
	char Letter;

	while (!Correct){
		cout << "Enter a capital letter\n"; cin >> Letter;
		cout << "\n";
		Correct = Letter >= 'A' && Letter <= 'Z';
	}
	cout << "You have entered " << Letter << endl << endl;
	return 0;
}
==> ./Projects/Wintry1/Wintry1/My Project/Application.myapp <==
ï»¿<?xml version="1.0" encoding="utf-8"?>
<MyApplicationData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <MySubMain>true</MySubMain>
  <MainForm>Form1</MainForm>
  <SingleInstance>false</SingleInstance>
  <ShutdownMode>0</ShutdownMode>
  <EnableVisualStyles>true</EnableVisualStyles>
  <AuthenticationMode>0</AuthenticationMode>
  <ApplicationType>0</ApplicationType>
  <SaveMySettingsOnExit>true</SaveMySettingsOnExit>
</MyApplicationData>

==> ./Projects/writing formatted text data/writing formatted text data/Source.cpp <==
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream myfile; //used to write into files
	
	//After declaring a stream as one of the above we need to 
	//associate it with a physical file on the disk. THis procedure is known as open a file
	myfile.open("example.txt");
	//The function that opens the file is called open. It has two parameters
	//	- The first paramater must always be provided, it is a string containing the name of
	//	file to open
	//	- The second parameter specifies the mode to open the file
	
	myfile << "Writing this to a file.\n";
	myfile.close();
	return 0;
}==> ./Projects/a13++ Resource Managing Class/a13++ Resource Managing Class/main.cpp <==
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
	string * pName_;
	static int noOfUnnamed;
public:
	Person(string name) {
		pName_ = new string(name);
	}
	Person() {
		noOfUnnamed++;
		string temp1 = to_string(noOfUnnamed);
		pName_ = new string("Nameless_" + temp1);
	}
	~Person(){
		cout << "Person has been deleted\n";
	}
	void printName() {
		cout << *pName_;
	}
};

int Person::noOfUnnamed = 0;

class APerson {
    string * pName_;
    static int noOfUnnamed;
public:
    APerson(string name) {
        pName_ = new string(name);
    }
    
    APerson() {
        noOfUnnamed++;
        pName_ = new string("Nameless_" + to_string(noOfUnnamed));
    }
    
    // Destructor
    ~APerson() {
        delete pName_;
        cout << "APerson has been deleted\n";
    }
    
    // Print function
    void printName() {
        cout << *pName_;
    }
    
    // Accessor for pName_
    string* pName() const {
        return pName_;
    }
    
    // Copy constructor (deep copy)
    APerson(const APerson &rhs) {
        pName_ = new string(*(rhs.pName()));
    }
    
    // Copy assignment operator (deep copy)
    APerson& operator=(const APerson& rhs) {
        if (this != &rhs) {
            delete pName_;
            pName_ = new string(*(rhs.pName()));
        }
        return *this;
    }
};

int APerson::noOfUnnamed = 0;

class Human {
	string *pName_;
public:

};

class AHuman {
	unique_ptr<string> pName_;
public:

};

int main() {
	vector<Person> persons;
	persons.push_back(Person("George"));
	//1. "George" is constructed
	//2. A copy of "George" is saved in the vector persons (shallow copy)
	//because of default constructor. Thus the pointer in copy George and
	//original George point to the same string.
	//3. "George" is destroyed, string pointed to is deleted

	/*solutions in APerson, Human, and AHuman*/

//	try {
//		throw 20;
//		persons.back().printName();
//	}
//	catch (int x) {
//		cout << ".printName() function causes program to crash\n";
//	}
//
//    vector<APerson> people;
//    people.push_back(APerson("George"));
//    people.back().printName();
//    cout << endl;
    
    // Test copy constructor:
    APerson a("Alice");
    APerson b = a; // Uses copy constructor
    b.printName();
    cout << endl;
    
    // Test copy assignment operator:
    APerson c("Charlie");
    c = a; // Uses copy assignment
    c.printName();
    cout << endl;
    
    return 0;
}

==> ./Projects/binary search/binary search/main (binary search).cpp <==
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename eType>
int binarySearch(const eType list[], int loc, eType &item);

int main() {
	cin.exceptions(ios_base::failbit);
	const int len = 20;
	int list[len];
	
	for (int i = 0; i < len; i++) {
		list[i] = i+1;
	}

	int temp = 0;

	do {
		try {
			cout << "Please enter the integer you want to search for (1-20): ";
			cin >> temp;
		}
		catch (exception e) {
			cout << "A valid inteer was not entered\n";
			cin.clear();
			cin.ignore(100, '\n');
			temp = 0;
		}
	} while ((temp < 1) || (temp > 20));

	temp = binarySearch(list, len, temp);

	if (temp == -1) {
		cout << "Search item not found\n";
	}
	else {
		cout << "Item found at index position [" << temp << "]\n";
	}

	return 0;
}

template <typename eType>
int binarySearch(const eType list[], int length, eType &item) {
	int mid, beg = 0, end = length - 1, count = 0;
	bool found = false;
	while ((beg <= end) && (!found)) {
		mid = (beg + end) / 2;
		if (list[mid] == item) {
			found = true;
		}
		else {
			if (item < list[mid]) {
				end = mid - 1;
			}
			else if (item > list[mid]) {
				beg = mid + 1;
			}
		}
		count = end - beg;
		for (int i = 0; i < count; i++) {
			cout << list[beg + i] << " ";
		}
		cout << endl;
	}

	if (found) {
		return mid;
	}
	else {
		return -1;
	}
}

==> ./Projects/c++ in 28 - getline, string data/c++ in 28 - getline, string data/main.cpp <==
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> names; //string vector for storing names
	vector<double> scores; //double vector for storing scores
	string line; //temp string for storing string input
	vector<int> counts;
	double avgscore = 0.0;
	ifstream infile;
	ofstream outfile;

	infile.open("input.txt");
	outfile.open("output.txt");

	int length;
	int c = 0;
	int count = 0;

	if (!infile.is_open()) {
		std::cout << "Error opening input file\n";
	}
	else {
		while (getline(infile, line)) {
			cout << "line = " << line << endl;
			/*line = line + " ";
			c = 0;
			count = 0;
			length = line.length();//
			for (int b = 0; b < length; b++) {
				string ntemp;
				double dtemp;
				switch (line[b]) {
				case ' ':
					for (c; c < b; c++) {
						ntemp = ntemp + line.at(c);
					}
					if ((ntemp.at(0) >= '0') && (ntemp.at(0) <= '9')) {
						dtemp = stod(ntemp);
						scores.push_back(dtemp);
						count++;
					}
					else {
						names.push_back(ntemp);
					} c = b + 1;
					break;
				case '\n':
					for (c; c < b; c++) {
						ntemp = ntemp + line[c];
					}
					if ((ntemp.at(0) >= '0') && (ntemp[0] <= '9')) {
						dtemp = stod(ntemp);
						scores.push_back(dtemp);
						count++;
					}
					else {
						names.push_back(ntemp);
					} c = b + 1;
					break;
				}*/
			}
			//counts.push_back(count);
		}

		/*unsigned int a1 = 0;
		unsigned int a2 = 0;
		unsigned int a3 = 0;
		unsigned int a4 = 0;
		unsigned int ac = 0;

		if (outfile.is_open()) {
			outfile.clear();
			outfile << fixed << showpoint << setprecision(2);
			while (a1 < names.size()) {
				avgscore = 0;
				outfile << left << setw(8) << "Name: ";
				for (a1 = a2; a1 < a2 + 2; a1++) {
					outfile << left << setw(8) << names[a1];
				}
				a2 = a2 + 2;
				outfile << endl;
				outfile << left << setw(8) << "Score: ";
				while (a3 < a4 + counts[ac]) {
					for (a3 = a4; a3 < a4 + counts[ac]; a3++) {
						outfile << left << setw(8) << scores[a3];
						avgscore += scores[a3];

					}
					outfile << endl;
					avgscore = avgscore / counts[ac];
					outfile << left << setw(8) << "Avg: " << avgscore;
					outfile << endl << endl;
				}
				a4 = a4 + counts[ac];
				a3 = a4;
				ac++;
			}
		}*/

		infile.close();
		//outfile.close();
	//}
	return 0;
}
==> ./Projects/c++ in 92 recursion - factorial/c++ in 92 recursion - factorial/main.cpp <==
#include <iostream>

using namespace std;

int factorial(int);
int fibonacci(int, int, int);
int f1bonacci(int, int, int);

int main() {
	cout << factorial(4) << endl;
	int fib = 0, fib2 = 1;

    cout << fibonacci(fib, fib2, 5) << endl;
    cout << f1bonacci(fib, fib2, 5) << endl;
	return 0;
}

int factorial(int x) {
	if (x > 1) {
		return x * factorial(x-1);
	}
	else {
		return 1;
	}
}

int fibonacci(int a, int b, int n) {
	if (n == 1) {
		return a;
	}
	else if (n == 2) {
		return b;
	}
	else {
		return fibonacci(a, b, n - 1) + fibonacci(a, b, n - 2);
	}
}

int f1bonacci(int a, int b, int n) {
	for (int i = 0; i < n; i++) {
		int temp = b;
		b += a;
		a = temp;
	}
	return a;
}

==> ./Projects/c++ int 04 - file streaming/c++ int 04 - file streaming/main.cpp <==
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> names; //string vector for storing names
	string stemp; //temp string for storing input stream name
	vector <double> scores; //double vector for storing scores
	double dtemp; //temp double for storing input stream double
	char ch;
	int scorecount = 0;
	double avgscore = 0.0;
	ifstream infile;
	ofstream outfile;

	infile.open("input.txt");
	outfile.open("output.txt");
	
	if (!infile.is_open()){
		cout << "Error opening input file\n";
	}
	else {
		do {
			ch = infile.peek();
			if (((ch >= (char)65) && (ch <= (char)90)) ||
				((ch >= (char)97) && (ch <= (char)122))) {
				infile >> stemp;
				names.push_back(stemp);
				//if char = 'A-Z' or 'a-z' -> store string in "names" vector
			}
			else if ((ch >= (char)48) && (ch <= (char)57)) {
				infile >> dtemp;
				scores.push_back(dtemp);
				scorecount++;
				//if char = '0-9' -> store double in "scores" vector
			}
			else if (infile.eof()) {
				cout << "Have reached end of file\n";
			}
			else {
				for (int i = 0; i < 100; i++) {
					if (!infile.eof()) {
						ch = infile.get();
					}
				}
			}
			infile.ignore(100, ' ');
		} while (!infile.eof());
	}
	
	if (outfile.is_open()) {
		outfile.clear();
		outfile << fixed << showpoint << setprecision(2);
		outfile << left << setw(8) << "Names: ";
		for (auto i : names) {
			outfile << left << setw(8) << i;
		}
		outfile << left << setw(8) << "\nScores: ";
		for (auto i : scores) {
			outfile << left << setw(6) << i << " ";
			avgscore += i;
		}
		avgscore = avgscore / scorecount;
		outfile << left << setw(8) << "\nAvg:  " << avgscore;
	}
	
	/*for (int i = 0; i < 255; i++) {
		cout << i << " : " << static_cast<char>(i) << endl;
	}*/
	
	infile.close();
	outfile.close();

	return 0;
}
==> ./Projects/c++ int 105 Stack ADT/c++ int 105 Stack ADT/main.cpp <==
#include <iostream>
#include "stackType.h"

using namespace std;

void test(stackType<int>);

int main() {
	stackType<int> stack(50), copyStack(50), dummyStack(100);
	stack.initializeStack();
	stack.push(12);
	stack.push(13);
	stack.push(14);
	stack.push(15);
	copyStack = stack;
	cout << "copyStack = ";
	while (!copyStack.isEmptyStack()) {
		cout << copyStack.top() << " ";
		copyStack.pop();
	}
	cout << endl;

	copyStack = stack;
	test(stack);
	if (!stack.isEmptyStack()) {
		cout << "Original stack is not empty \nTop element of original stack = " << copyStack.top() << endl;
	}
	dummyStack = stack;
	cout << "dummyStack = ";
	while (!dummyStack.isEmptyStack()) {
		cout << dummyStack.top() << " ";
		dummyStack.pop();
	}
	cout << endl;

	return 0;
}

void test(stackType<int> rhs) {
	if (!rhs.isEmptyStack()) {
		cout << "rhs stack is not empty \ntop element of rhs = " << rhs.top() << endl;
	}
}
==> ./Projects/c++ int 105 Stack ADT/c++ int 105 Stack ADT/stackADT.h <==
#ifndef STACKADT_H
#define STACKADT_H
#include <iostream>

using namespace std;

template <typename Type>
class stackADT {
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type&) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

#endif

==> ./Projects/c++ int 105 Stack ADT/c++ int 105 Stack ADT/stackType.h <==
#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;

template <typename Type>
class stackType : public stackADT<Type> {
	int maxStackSize;
	int stackTop;
	Type *list;
	void copyStack(const stackType<Type>&);
public: 
	stackType(int stackSize = 100); //constructor
	stackType(const stackType<Type>&); //copy constructor
	~stackType(); //destructor
	const stackType<Type>& operator=(const stackType<Type>&); //copy assignment operator
	void initializeStack(); //initializes stack
	bool isEmptyStack() const; //checks if stack is empty
	bool isFullStack() const; //checks if stack is full
	void push(const Type&); //adds item to stack
	Type top() const; //displays last object pushed onto stack
	void pop(); //deletes object at the top of the stack
};

template <typename Type> 
void stackType<Type>::initializeStack() {
	stackTop = 0; //value of stack top indicates whether stack is empty, setting at zero ssentially resets the stack (indicating array position zero)
}

template <typename Type> 
bool stackType<Type>::isEmptyStack() const {
	return (stackTop == 0); //if position of stackTop is at zero, stack is empty, returns true
}

template <typename Type>
bool stackType<Type>::isFullStack() const {
	return (stackTop == maxStackSize); //if position of stackTop is at maxSize - 1, stack is full, returns true
}

template <typename Type>
void stackType<Type>::push(const Type &item) {
	if (!isFullStack()) {
		list[stackTop] = item;
		stackTop++;
	}
	else {
		cout << "The stack is full\n";
	}
}

template <typename Type>
Type stackType<Type>::top() const {
	assert(stackTop != 0);
	return list[stackTop - 1];
}

template <typename Type>
void stackType<Type>::pop() {
	if (!isEmptyStack()) {
		stackTop--;
	}
	else {
		cout << "The stack is empty\n";
	}
}

template <typename Type>
void stackType<Type>::copyStack(const stackType<Type> &rhs) {
	delete[] list;
	maxStackSize = rhs.maxStackSize;
	stackTop = rhs.stackTop;
	list = new Type[maxStackSize];
	for (int j = 0; j < stackTop; j++) {
		list[j] = rhs.list[j];
	}
}

template <typename Type>
stackType<Type>::stackType(int stackSize) {
	if (stackSize == 0) {
		cout << "Size must be positive. Creating default size of 100.\n";
		maxStackSize = 100;
	}
	else {
		maxStackSize = stackSize;
	}
	stackTop = 0;
	list = new Type[maxStackSize];
}

template <typename Type>
stackType<Type>::stackType(const stackType<Type> &rhs) {
	list = NULL;
	copyStack(rhs);
}

template <typename Type>
stackType<Type>::~stackType() {
	delete[] list;
}

template <typename Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type> &rhs) {
	//if (this != rhs) {
		//list = NULL;
		copyStack(rhs);
	//}
	return *this;
}

#endif
==> ./Projects/c++ int 109 stack as a linked list/c++ int 109 stack as a linked list/linkedStackType.h <==
#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <iostream>
#include <cassert>
#include "StackADT.h"

using namespace std;

template <typename Type>
struct node {
	Type info;
	node<Type> *link;
};

template <typename Type>
class linkedStackType : public stackADT<Type> {
	node<Type> *stackTop;
	void copyStack(const linkedStackType<Type>&);
public:
	const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
	bool isEmptyStack() const;
	void initialiseStack();
	void push(const Type&);
	Type top() const;
	void pop();
	linkedStackType();
	linkedStackType(const linkedStackType<Type>&);
	~linkedStackType();
};

template <typename Type>
linkedStackType<Type>::linkedStackType() {
	stackTop = NULL;
}

template <typename Type>
bool linkedStackType<Type>::isEmptyStack() const{
	return (stackTop == NULL);
}

template <typename Type>
void linkedStackType<Type>::initialiseStack() {
	node<Type> *temp;
	while (stackTop != NULL) {
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}

template <typename Type>
void linkedStackType<Type>::push(const Type &item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <typename Type>
Type linkedStackType<Type>::top() const {
	assert(stackTop != NULL);
	return stackTop->info;
} 

template <typename Type>
void linkedStackType<Type>::pop() {
	node<Type> *temp;
	if (stackTop != NULL) {
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	else {
		cout << "The stack is empty\n";
	}
}

template <typename Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &rhs) {
	node<Type> *current, *rhscurrent, *last;
	if (stackTop != NULL) {
		initialiseStack();
	}
	if (rhs.stackTop == NULL) {
		stackTop = NULL;
	}
	else {
		rhscurrent = rhs.stackTop;
		stackTop = new node<Type>;
		stackTop->info = rhscurrent->info;
		stackTop->link = NULL;
		last = stackTop;
		rhscurrent = rhscurrent->link;
		while (rhscurrent != NULL) {
			current = new node<Type>;
			current->info = rhscurrent->info;
			current->link = NULL;
			last->link = current;
			last = last->link;
			rhscurrent = rhscurrent->link;
		}
	}
}

template <typename Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &rhs) {
	stackTop = NULL;
	copyStack(rhs);
}

template <typename Type>
linkedStackType<Type>::~linkedStackType() {
	initialiseStack();
}

template <typename Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& rhs) {
	copyStack(rhs);
	return *this;
}

#endif
==> ./Projects/c++ int 109 stack as a linked list/c++ int 109 stack as a linked list/main.cpp <==
#include <iostream>
#include "linkedStackType.h"

using namespace std;

void test(linkedStackType<int>);

int main() {
	linkedStackType<int> stack1, stack2, stack3;
	stack1.push(11);
	stack1.push(12);
	stack1.push(13);
	stack1.push(14);
	stack3 = stack1;
	cout << "After assignment, stack3 = " << endl;
	while (!stack3.isEmptyStack()) {
		cout << stack3.top() << endl;
		stack3.pop();
	}
	stack2 = stack1;
	cout << "Testing copy constructor.\n";
	test(stack2);
	cout << "After copying, stack2 = " << endl;
	while (!stack2.isEmptyStack()) {
		cout << stack2.top() << endl;
		stack2.pop();
	}
	system("PAUSE");
	return 0;
}

void test(linkedStackType<int> rhs) { //copy constructor automatically called when stack2 passed by value
	cout << "In function test... testing copy constructor." << endl;
	while (!rhs.isEmptyStack()) {
		cout << rhs.top() << endl;
		rhs.pop();
	}
}
==> ./Projects/c++ int 109 stack as a linked list/c++ int 109 stack as a linked list/StackADT.h <==
#ifndef STACKADT_H
#define STACKADT_H
#include <iostream>

using namespace std;

template <typename Type>
class stackADT {
	virtual bool isEmptyStack() const = 0;
	virtual Type top() const = 0;
	virtual void push(const Type&) = 0;
	virtual void pop() = 0;
	virtual void initialiseStack() = 0;
};

#endif

==> ./Projects/c++ int 11 - number guessing game/c++ int 11 - number guessing game/main.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	int x, num, noOfguesses = 5;
	bool done = false;
	num = (rand() + time(0)) % 100 + 1;
	 
	while (!done) {
		do {
			cout << "Please enter your guess (between 1-100) : ";
			cin.exceptions(ios_base::failbit); //will throw an exception if 
			//input stream doesn't match input type (double/float or int)
			try {
				cin >> x;
			}
			catch (exception e) {
				cout << "You didn't enter an integer\n";
				cin.clear();
				cin.ignore(100, '\n');
				x = 0;
				}
			if ((x > 100) || (x < 1)) {
				cout << "Please enter a number between 1 and 100\n\n";
			}
		} while ((x > 100) || (x < 1));
		if (x == num) {
			cout << "Correct. You win!\n\n";
			done = true;
		}
		else if (--noOfguesses > 0) {
			if (noOfguesses > 0)
				if (x > num) {
					cout << "Too high. Try again. Guesses left: " << noOfguesses << "\n\n";
				}
				else if (x < num) {
					cout << "Too low.x Try again. Guesses left: " << noOfguesses << "\n\n";
				}
		}
		else {
			cout << "Game over!\n\n";
			done = true;
		}
	}
}

==> ./Projects/c++ int 111 - seq search/c++ int 111 - seq search/main.cpp <==
//seq search most useful for smaller arrays, as the average number of elements to search is equal to 50 array places
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename eType>
int seqSearch(const eType list[], int length, const eType &item);

int main() {
	cin.exceptions(ios_base::failbit);
	const int len = 100;
	int list[len];
	for (int i = 0; i < len; i++) {
		list[i] = (rand() + time(0)) % 10000;
		cout << setw(5) << list[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	int num = 10000;
	do {
		try {
			cout << "Please enter a number to search for in the list: ";
			cin >> num;
		}
		catch (exception e) {
			cout << "A valid integer was not entered\n";
			cin.clear();
			cin.ignore('\n', 100);
			num = 10000;
		}
	} while ((num > 9999) || (num < 0));

	int location = seqSearch(list, len, num);

	if (location != -1) {
		cout << "item found, location is list [" << location << "]\n";
	}
	else {
		cout << "Item not found\n";
	}

	system("PAUSE");
	return 0;
}

template <typename eType>
int seqSearch(const eType list[], int length, const eType &item) {
	bool found = false;
	int loc;
	for (loc = 0; loc < length; loc++) {
		if (item == list[loc]) {
			found = true;
			break;
		}
	}

	if (found) {
		return loc;
	}
	else {
		return -1;
	}
}
==> ./Projects/c++ int 112 - binary search/c++ int 112 - binary search/main.cpp <==
//binary search can only be used on a sorted list, uses middle of array + greater/less than to determine the position of an array element. For a 1000 item array reduces average amount of search processing to find data from 500 items down to 11 items. 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename eType>
int binarySearch(const eType list[], int loc, eType & item);

int main() {
	cin.exceptions(ios_base::failbit);
	const int len = 100;
	int list[len];

	for (int i = 0; i < len; i++) {
		list[i] = (rand() * time(0)) % 10000;
	}

	int temp;

	for (int i = 0; i < 100; i++) {
		cout << setw(5) << list[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	cout << "\n\n";

	
	//sort algorithm
	for (int i = 1; i < 100; i++) {
		for (int a = 0; a < i; a++) {
			if (list[i] < list[a]) {
				temp = list[i];
				for (int b = i; b > a; b--) {
					list[b] = list[b - 1];
				}
				list[a] = temp;
				break;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		cout << setw(5) << list[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	temp = 10000;

	do {
		try {
			cout << "Please enter the integer you wish to search for (0-9999): ";
			cin >> temp;
		}
		catch (exception e) {
			cout << "A valid integer was not entered\n";
			cin.clear();
			cin.ignore(100, '\n');
			temp = 10000;
		}
	} while ((temp < 0) || (temp > 9999));

	temp = binarySearch(list, len, temp);
	
	if (temp == -1) {
		cout << "Search item not found\n";
	}
	else {
		cout << "Item found at index position [" << temp << "]\n";
	}

	system("PAUSE");
	return 0;
}

 template <typename eType>
 int binarySearch(const eType list[], int length, eType &item) {
	 int mid, beg = 0, end = length -1;
	 bool found = false;
	 while ((beg <= end) &&(!found)) {
		 mid = (beg + end) / 2;
		 if (list[mid] == item) {
			 found = true;
		 }
		 else {
			 if (item < list[mid]) {
				 end = mid - 1;
			 }
			 else if (item > list[mid]) {
				 beg = mid + 1;
			 }
		 }
	 }

	 if (found) {
		 return mid;
	 }
	 else {
		 return -1;
	 }
 }
==> ./Projects/c++ int 113 bubble sort algorithm/c++ int 113 bubble sort algorithm/main.cpp <==
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void bubbleSort(eType[], int);

template <typename eType>
void print(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:" << endl;
	print(intList, 100);
	cout << "\n\n";
	bubbleSort(intList, 100);
	cout << "intList after bubble sort:" << endl;
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void bubbleSort(eType list[], int length) {
	for (int i = 1; i < length; i++) {
		for (int index = 0; index < length - i; index++) {
			if (list[index] > list[index + 1]){
				eType temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}
}

//my earlier version of sorting algorithm
/*for (int i = 1; i < 100; i++) {
	for (int a = 0; a < i; a++) {
		if (list[i] < list[a]) {
			temp = list[i];
			for (int b = i; b > a; b--) {
				list[b] = list[b - 1];
			}
			list[a] = temp;
			break;
		}
	}
}*/

template <typename eType>
void print(eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}
==> ./Projects/c++ int 114 selection sort and analysis/c++ int 114 selection sort and analysis/main.cpp <==
//selection sort analysis - generally not good for larger sets of data, does O.n^2 comparisons, O.n data moves but if data movement is expensive and comparison is not may be a better choice than other algorithms
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void print(const eType[], int);

template <typename eType>
int minLocation(eType[], int, int);

template <typename eType>
void swap(eType[], int, int);

template <typename eType>
void selectionSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:" << endl;
	print(intList, 100);
	cout << "\n\n";
	selectionSort(intList, 100);
	cout << "intList after selection sort:" << endl;
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void print(const eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename eType>
int minLocation(eType list[], int first, int last) {
	int loc, minIndex;
	minIndex = first;
	for (loc = first + 1; loc <= last; loc++) {
		if (list[loc] < list[minIndex]) {
			minIndex = loc;
		}
	}
	return minIndex;
}

template <typename eType>
void swap(eType list[], int first, int second) {
	eType temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template <typename eType>
void selectionSort(eType list[], int length) {
	int loc, minIndex;
	for (loc = 0; loc < length; loc++) {
		minIndex = minLocation(list, loc, length - 1);
		swap(list, loc, minIndex);
	}
}
==> ./Projects/c++ int 115 insertion sort/c++ int 115 insertion sort/main.cpp <==
//insertion sort can be from O.n-1 to O.n^2 (max) number of comparisons, depending on the disorder of the list
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void print(eType[], int);

template <typename eType>
void insertionSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:\n";
	print(intList, 100);
	cout << "\n\n";
	insertionSort(intList, 100);
	cout << "intList after selection sort:\n";
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void print(eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename eType>
void insertionSort(eType list[], int length) {
	for (int firstOrder = 1; firstOrder < length; firstOrder++) {
		if (list[firstOrder] < list[firstOrder - 1]) {
			eType temp = list[firstOrder]; //copies first out of order into temp
			int location = firstOrder; //initializes location to first out of order
			do {
				list[location] = list[location - 1]; //shifts all places down to accomodate value.
				location--; 
			} while ((location > 0) && (list[location - 1] > temp));
			list[location] = temp; //copy temp into list location
		}
	}
}
==> ./Projects/c++ int 116 quick sort/c++ int 116 quick sort/main.cpp <==
//average number of comparisons for quick sort is nlog2n, which makes it a quite efficient sort algorithm
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

template <typename eType>
void print(const eType[], int);

template <typename eType>
int partition(eType[], int, int);

template <typename eType>
void swap(eType[], int, int);

template <typename eType>
void recursiveQuick(eType[], int, int);

template <typename eType>
void quickSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = rand() % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:\n";
	print(intList, 100);
	cout << "\n\n";
	quickSort(intList, 100);
	cout << "intList after quick sort:\n";
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void print(const eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename eType>
int partition(eType list[], int first, int last) {
	eType pivot;
	int index, smallIndex;
	swap(list, first, (first + last) / 2);
	pivot = list[first];
	smallIndex = first;
	for (index = first + 1; index <= last; index++) {
		if (list[index] < pivot) {
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}
	swap(list, first, smallIndex);
	return smallIndex;
}

template <typename eType>
void swap(eType list[], int first, int second) {
	eType temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template <typename eType>
void recursiveQuick(eType list[], int first, int last) {
	int pivotLocation;
	if (first < last) {
		pivotLocation = partition(list, first, last);
		recursiveQuick(list, first, pivotLocation - 1);
		recursiveQuick(list, pivotLocation + 1, last);
	}
}

template <typename eType>
void quickSort(eType list[], int length) {
	recursiveQuick(list, 0, length - 1);
}
==> ./Projects/c++ int 117 merge sort/c++ int 117 merge sort/main.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unorderedLinkedList.h"

using namespace std;

int main() {
	UnorderedLinkedList<int> list1;
	for (int i = 0; i < 10; i++) {
		list1.insertLast((rand() + time(0)) % 100);
	}
	list1.print();

	list1.mergeSort();
	list1.print();

	return 0;
}
==> ./Projects/c++ int 117 merge sort/c++ int 117 merge sort/unorderedLinkedList.h <==
#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename Type>
struct Node {
	Type info;
	Node *link;
};

template <typename Type>
class UnorderedLinkedList {
	Node<Type> *head = NULL;
	Node<Type> *last = NULL;
public:
	UnorderedLinkedList();
	bool search(const Type&) const;
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
	void divideList(Node<Type>*, Node<Type>*&);
	void print() const;
	Node<Type>* mergeList(Node<Type>*&, Node<Type>*);
	void recursiveSort(Node<Type>*&);
	void mergeSort();
};

template <typename Type>
void UnorderedLinkedList<Type>::print() const {
	Node<Type> *current = NULL;
	int count = 0;
	if (head != NULL) {
		current = head;
		cout << current->info;
		count++;
	}
	while (current->link != NULL) {
		current = current ->link;
		cout << " " << current->info;
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename Type>
bool UnorderedLinkedList<Type>::search(const Type &item) const {
	Node<Type> *current;
	current = head;
	while (current != NULL) {
		if (current->info == item) {
			return true;
		}
		else {
			current = current->link;
		}
	}
	if (current == NULL) {
		return false;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::insertFirst(const Type &item) {
	Node<Type> *current;
	current = new Node<Type>;
	current->info = item;
	current->link = head;
	head = current;
	if (last == NULL) {
		last = head;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::insertLast(const Type &item) {
	Node<Type> *current;
	current = new Node<Type>;
	current->info = item;
	current->link = NULL;
	if (last == NULL) {
		last = current;
		head = last;
	}
	else {
		last->link = current;
		last = last->link;
	}
}

template <typename Type>
UnorderedLinkedList<Type>::UnorderedLinkedList() {
	head = NULL;
	last = NULL;
}

template <typename Type>
void UnorderedLinkedList<Type>::divideList(Node<Type> *first1, Node<Type> *&first2) {
	Node<Type> *middle, *current;
	if (first1 == NULL) { //list is empty
		first2 = NULL;
	}
	else if (first1->link == NULL) { //list only has one node
		first2 = NULL;
	}
	else {
		middle = first1;
		current = first1->link;
		if (current != NULL) {
			current = current->link;
		}
		while (current != NULL) {
			middle = middle->link;
			current = current->link;
			if (current != NULL) {
				current = current->link;
			}
		}
		first2 = middle->link; //points to first node of second sublist
		middle->link = NULL; //link of last node of first sublist set to null
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::deleteNode(const Type &item) {
	Node<Type> *current, *trailCurrent;
	bool found = false;
	current = head;
	while (current != NULL) {
		if (current->info == item) {
			found = true;
			if (current == head) {
				current = current->link;
				delete head;
				head = current;
				count--;
				break;
			}
			else {
				trailCurrent->link = current->link;
				if (current == last) {
					last = trailCurrent;
				}
				delete current;
				count--;
				break;
			}
		}
		else {
			trailCurrent = current;
			current = current->link;
		}
	}
	if (!found) {
		cout << "Item does not exist\n";
	}
}

template <typename Type>
Node<Type>* UnorderedLinkedList<Type>::mergeList(Node<Type> *&first1, Node<Type> *first2) {
	Node<Type> *lastSmall, *newHead;
	if (first1 == NULL) { //first sublist is empty
		return first2;
	}
	else if (first2 == NULL) { //second sublist is empty
		return first1;
	}
	else {
		if (first1->info < first2->info) {
			newHead = first1;
			first1 = first1->link;
			lastSmall = newHead;
		}
		else {
			newHead = first2;
			first2 = first2->link;
			lastSmall = newHead;
		}
		while ((first1 != NULL) && (first2 != NULL)) {
			if (first1->info < first2->info) {
				lastSmall->link = first1;
				lastSmall = lastSmall->link;
				first1 = first1->link;
			}
			else {
				lastSmall->link = first2;
				lastSmall = lastSmall->link;
				first2 = first2->link;
			}
		}
		if (first1 == NULL) { //first sublist is processed first
			lastSmall->link = first2;
		}
		else { //second sublist is processed first
			lastSmall->link = first1;
		}
		return newHead;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::recursiveSort(Node<Type> *&ihead) {
	Node<Type> *otherHead;
	otherHead = new Node<Type>;
	if (ihead != NULL) {
		if (ihead->link != NULL) {
			divideList(ihead, otherHead);
			recursiveSort(ihead);
			recursiveSort(otherHead);
		}
		if (otherHead->link == NULL) {
			head = mergeList(head, otherHead);
		}
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::mergeSort() {
	recursiveSort(head);
	if (head == NULL) {
		last = NULL;
	}
	else {
		last = head;
		while (last->link != NULL) {
			last = last->link;
		}
	}
}

#endif
==> ./Projects/c++ int 118 binary trees/c++ int 118 binary trees/main.cpp <==
#include <iostream>
#include <cmath>

using namespace std;

template <typename eType>
struct Node {
	eType info;
	Node<eType> *leftLink;
	Node<eType> *rightLink;
};

template <typename eType>
int height(Node<eType> *p) {
	if (p == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(p->leftLink), height(p->rightLink)); 
		//recursive algorithm adds one for every level of structure, max() = cmath function, returns max of two integers/doubles
	}
}

template <typename eType>
void copyTree(const Node<eType> *treeRoot, Node<eType> *&otherRoot) {
	if (treeRoot == NULL) {
		otherRoot = NULL;
	}
	else {
		otherRoot = new Node<eType>;
		otherRoot->info = treeRoot->info;
		copyTree(treeRoot->leftLink, otherRoot->leftLink);
		copyTree(treeRoot->rightLink, otherRoot->rightLink);
	}
}

/*
Inorder traversal:		1 - Traverse the left subtree, 2 - Visit the node, 3 - Traverse the right subtree
Preorder traversal:		1 - Visit the node, 2 - Traverse the left subtree, 3 - Traverse the right subtree
Postorder traversal:	1 - Traverse the left subtree, 2 - Traverse the right subtree, 3 - Visit the node
*/

template <typename eType>
void inorder(Node<eType> *p) {
	if (p != NULL) {
		inorder(p->leftLink);
		cout << p->info << " ";
		inorder(p->rightLink);
	}
}

template <typename eType>
void preorder(Node<eType> *p) {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->leftLink);
		preorder(p->rightLink);
	}
}

template <typename eType>
void postorder(Node<eType> *p) {
	if (p != NULL) {
		postorder(p->leftLink);
		postorder(p->rightLink);
		cout << p->info << " ";
	}
}

int main() {
	
	
	return 0;
}
==> ./Projects/c++ int 119 binary tree implementation/c++ int 119 binary tree implementation/binaryTreeType.h <==
#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H
#include <iostream>

using namespace std;

template <typename eType>
struct Node {
	eType info;
	Node<eType> *leftLink;
	Node<eType> *rightLink;
};

template <typename eType>
class BinaryTree {
protected:
	Node<eType> *root;
public:
	const BinaryTree<eType>& operator=(const BinaryTree<eType>&); //copy assignment operator
	bool isEmpty() const; //
	void inorderTraversal() const; //
	void preorderTraversal() const; //
	void postorderTraversal() const; //
	int treeHeight() const; //
	int treeNodeCount() const; //
	int treeLeafCount() const; //
	void destroyTree(); //
	virtual bool search(const eType&) const = 0;
	virtual void insert(const eType&) = 0;
	virtual void deleteNode(const eType&) = 0;
	BinaryTree(const BinaryTree<eType>&);
	BinaryTree();
	~BinaryTree();
private:
	void copyTree(Node<eType>* &, Node<eType>*);
	void destroy(Node<eType>* &);
	void inorder(Node<eType>*) const;
	void preorder(Node<eType>*) const;
	void postorder(Node<eType>*) const;
	int height(Node<eType>*) const;
	int max(int, int) const;
	int nodeCount(Node<eType>*) const;
	int leafCount(Node<eType>*) const;
};

template <typename eType>
bool BinaryTree<eType>::isEmpty() const {
	return (root == NULL);
}

template <typename eType>
BinaryTree<eType>::BinaryTree() {
	root = NULL;
}

template <typename eType>
void BinaryTree<eType>::inorderTraversal() const{
	inorder(root);
}

template <typename eType>
void BinaryTree<eType>::preorderTraversal() const {
	preorder(root);
}

template <typename eType>
void BinaryTree<eType>::postorderTraversal() const {
	postorder(root);
}

template <typename eType>
int BinaryTree<eType>::treeHeight() const {
	return height(root);
}

template <typename eType>
int BinaryTree<eType>::treeNodeCount() const {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + nodeCount(root);
	}
}

template <typename eType>
int BinaryTree<eType>::treeLeafCount() const {
	return leafCount(root);
}

template <typename eType>
void BinaryTree<eType>::inorder(Node<eType> *p) const {
	if (p != NULL) {
		inorder(p->leftLink);
		cout << p->info << " ";
		inorder(p->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::preorder(Node<eType> *p) const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->leftLink);
		preorder(p->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::postorder(Node<eType> *p) const {
	if (p != NULL) {
		postorder(p->leftLink);
		postorder(p->rightLink);
		cout << p->info << " ";
	}
}

template <typename eType>
int BinaryTree<eType>::height(Node<eType> *p) const {
	if (p == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(p->leftLink), height(p->rightLink));
	}
}

template <typename eType>
int BinaryTree<eType>::max(int x, int y) const {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

template <typename eType>
int BinaryTree<eType>::nodeCount(Node<eType> *p) const {
	int count = 0;
	if (p->leftLink != NULL) {
		count += 1 + nodeCount(p->leftLink);	
	}
	if (p->rightLink != NULL) {
		count += 1 + nodeCount(p->rightLink);
	}
	return count;
}

template <typename eType>
void BinaryTree<eType>::copyTree(Node<eType> *&newRoot, Node<eType> *rhsRoot) {
	if (rhsRoot == NULL) {
		newRoot = NULL;
	}
	else {
		newRoot = new Node<eType>;
		newRoot->info = rhsRoot->info;
		copyTree(newRoot->leftLink, rhsRoot->leftLink);
		copyTree(newRoot->rightLink, rhsRoot->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::destroy(Node<eType> *&p) {
	if (p != NULL) {
		destroy(p->leftLink);
		destroy(p->rightLink);
		delete p;
		p = NULL;
	}
}

template <typename eType>
void BinaryTree<eType>::destroyTree() {
	destroy(root);
}

template <typename eType>
BinaryTree<eType>::BinaryTree(const BinaryTree<eType> &rhs) {
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

template <typename eType>
BinaryTree<eType>::~BinaryTree() {
	destroy(root);
}

template <typename eType>
const BinaryTree<eType>& BinaryTree<eType>::operator=(const BinaryTree<eType> &rhs) {
	if (root != NULL) {
		destroy(root);
	}
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

#endif
==> ./Projects/c++ int 119 binary tree implementation/c++ int 119 binary tree implementation/main.cpp <==
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "searchTree.h"

using namespace std;

int main() {
	int num = 0, count = 0;
	SearchTree<int> tree1;
	while (count < 10) {
		num = (rand() + time(0)) % 1000 + 1;
		//cout << num << " ";
		tree1.insert(num);
		count++;
	}

	//cout << endl;
	cout << "Node count: " << tree1.treeNodeCount() << endl;
	tree1.inorderTraversal();
	cout << endl;
	/*tree1.postorderTraversal();
	cout << endl;
	tree1.preorderTraversal();
	cout << endl;*/
	cout << "\n\nEnter a number to find: ";
	cin >> num;
	cout << endl;
	tree1.search(num);
	cout << "\n\nEnter a number to be deleted: ";
	cin >> num;
	cout << endl;
	tree1.deleteNode(num);
	cout << "Node count: " << tree1.treeNodeCount() << endl;

	tree1.inorderTraversal();
	cout << endl;

	SearchTree<int> tree2 = tree1;
	tree2.inorderTraversal();
	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 119 binary tree implementation/c++ int 119 binary tree implementation/searchTree.h <==
#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <iostream>
#include "binaryTreeType.h"

using namespace std;

template <typename eType>
class SearchTree : public BinaryTree<eType> {
public:
	bool search(const eType&) const;
	void insert(const eType&);
	void deleteNode(const eType&);
private:
	void deleteFromTree(Node<eType> *&);
};

template <typename eType>
bool SearchTree<eType>::search(const eType &item) const {
	Node<eType> *current;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty.\n";
	}
	else {
		current = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else if (current->info > item) {
				current = current->leftLink;
			}
			else {
				current = current->rightLink;
			}
		}
	}
	if (found) {
		cout << "\nfound item\n";
	}
	return found;
}

template <typename eType>
void SearchTree<eType>::insert(const eType &item) {
	Node<eType> *current, *trail, *newNode;
	newNode = new Node<eType>;
	newNode->info = item;
	newNode->leftLink = NULL;
	newNode->rightLink = NULL;
	if (root == NULL) {
		root = newNode;
	}
	else {
		current = root;
		while (current != NULL) {
			trail = current;
			if (current->info == item) {
				cout << "Item is already in tree, no duplicates.\n";
				return;
			}
			else if (current->info > item) {
				current = current->leftLink;
			}
			else {
				current = current->rightLink;
			}
		}
		if (trail->info > item) {
			trail->leftLink = newNode;
		}
		else {
			trail->rightLink = newNode;
		}
	}
}

template <typename eType>
void SearchTree<eType>::deleteFromTree(Node<eType> *&p) {
	Node<eType> *current, *trail, *temp;
	if (p == NULL) {
		cout << "The node is NULL.\n";
	}
	else if ((p->leftLink == NULL) && (p->rightLink == NULL)) {
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->leftLink == NULL) {
		temp = p;
		p = temp->rightLink;
		delete temp;
	}
	else if (p->rightLink == NULL) {
		temp = p;
		p = temp->leftLink;
		delete temp;
	}
	else {
		current = p->leftLink;
		trail = NULL;
		while (current->rightLink != NULL) {
			trail = current;
			current = current->rightLink;
		}
		p->info = current->info;
		if (trail == NULL) {
			p->leftLink = current->leftLink;
		}
		else {
			trail->rightLink = current->leftLink;
			delete current;
		}
	}
}

template <typename eType>
void SearchTree<eType>::deleteNode(const eType &item) {
	Node<eType> *current, *trail;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty\n";
	}
	else {
		current = root;
		trail = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else {
				trail = current;
				if (current->info > item) {
					current = current->leftLink;
				} 
				else {
					current = current->rightLink;
				}
			}
		}
		if (current == NULL) {
			cout << "Item is not found in tree\n";
		}
		else if (found) {
			if (current == root) {
				deleteFromTree(root);
			}
			else if (trail->info > item) {
				deleteFromTree(trail->leftLink);
			}
			else {
				deleteFromTree(trail->rightLink);
			}
		}
		else {
			cout << "Item not found in tree\n";
		}
	}
}

#endif
==> ./Projects/c++ int 120 - functions as parameters/c++ int 120 - functions as parameters/binaryTreeType.h <==
#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H
#include <iostream>

using namespace std;

template <typename eType>
struct Node {
	eType info;
	Node<eType> *leftLink;
	Node<eType> *rightLink;
};

template <typename eType>
class BinaryTree {
protected:
	Node<eType> *root;
public:
	const BinaryTree<eType>& operator=(const BinaryTree<eType>&);
	bool isEmpty() const;
	void inorderTraversal(void (*v1sit) (eType&)) const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	int treeHeight() const;
	int treeNodeCount() const; 
	int treeLeafCount() const;
	void destroyTree();
	virtual bool search(const eType&) const = 0;
	virtual void insert(const eType&) = 0;
	virtual void deleteNode(const eType&) = 0;
	BinaryTree(const BinaryTree<eType>&);
	BinaryTree();
	~BinaryTree();
private:
	void copyTree(Node<eType>*&, const Node<eType>*);
	void destroy(Node<eType>*&);
	void inorder(Node<eType>*, void(*v1sit) (eType&)) const;
	void preorder(Node<eType>*) const;
	void postorder(Node<eType>*) const;
	int height(Node<eType>*) const;
	int max(int, int) const;
	int nodeCount(Node<eType>*) const;
	int leafCount(Node<eType>*) const;
};

template <typename eType>
bool BinaryTree<eType>::isEmpty() const {
	return (root == NULL);
}

template <typename eType>
BinaryTree<eType>::BinaryTree() {
	root = NULL;
}

template <typename eType>
void BinaryTree<eType>::inorderTraversal(void (*v1sit) (eType &item)) const {
	inorder(root, *v1sit);
}

template <typename eType>
void BinaryTree<eType>::postorderTraversal() const {
	postorder(root);
}

template <typename eType>
void BinaryTree<eType>::preorderTraversal() const {
	preorder(root);
}

template <typename eType>
int BinaryTree<eType>::treeHeight() const {
	return height(root);
}

template <typename eType>
int BinaryTree<eType>::treeNodeCount() const {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + nodeCount(root);
	}
}

template <typename eType>
int BinaryTree<eType>::treeLeafCount() const {
	return leafCount(root);
}

template <typename eType>
void BinaryTree<eType>::inorder(Node<eType> *p, void (*v1sit) (eType &item)) const {
	if (p != NULL) {
		inorder(p->leftLink, *v1sit);
		(*v1sit)(p->info);
		inorder(p->rightLink, *v1sit);
	}
}

template <typename eType>
void BinaryTree<eType>::preorder(Node<eType> *p) const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->leftLink);
		preorder(p->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::postorder(Node<eType> *p) const {
	if (p != NULL) {
		postorder(p->leftLink);
		postorder(p->rightLink);
		cout << p->info << " ";
	}
}

template <typename eType>
int BinaryTree<eType>::height(Node<eType> *p) const {
	if (p == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(p->leftLink), height(p->rightLink));
	}
}

template <typename eType>
int BinaryTree<eType>::max(int x, int y) const {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

template <typename eType>
int BinaryTree<eType>::nodeCount(Node<eType> *p) const {
	int count = 0;
	if (p->leftLink != NULL) {
		count += 1 + nodeCount(p->leftLink);
	}
	if (p->rightLink != NULL) {
		count += 1 + nodeCount(p->rightLink);
	}
	return count;
}

template <typename eType>
void BinaryTree<eType>::copyTree(Node<eType> *&newRoot, const Node<eType> *rhsRoot) {
	if (rhsRoot == NULL) {
		newRoot = NULL;
	}
	else {
		newRoot = new Node<eType>;
		newRoot->info = rhsRoot->info;
		copyTree(newRoot->leftLink, rhsRoot->leftLink);
		copyTree(newRoot->rightLink, rhsRoot->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::destroy(Node<eType> *&p) {
	if (p != NULL) {
		destroy(p->leftLink);
		destroy(p->rightLink);
		delete p;
		p = NULL;
	}
}

template <typename eType>
void BinaryTree<eType>::destroyTree() {
	destroy(root);
}

template <typename eType>
BinaryTree<eType>::BinaryTree(const BinaryTree<eType> &rhs) {
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

template <typename eType>
BinaryTree<eType>::~BinaryTree() {
	destroy(root);
}

template <typename eType>
const BinaryTree<eType>& BinaryTree<eType>::operator=(const BinaryTree<eType> &rhs) {
	if (root != NULL) {
		destroy(root);
	}
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

#endif
==> ./Projects/c++ int 120 - functions as parameters/c++ int 120 - functions as parameters/main.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchTree.h"

using namespace std;

void print(int&);
void update(int&);

int main() {
	SearchTree<int> tree1;
	int num;
	for (int i = 0; i < 10; i++) {
		tree1.insert((rand() + time(0)) % 1000);
	}
	cout << "\ntree = \n";
	tree1.inorderTraversal(print);
	cout << "\ntree height = " << tree1.treeHeight() << "\n\n";
	cout << "---------------UPDATE NODES------------------\n";
	tree1.inorderTraversal(update);
	cout << "tree after update = " << endl;
	tree1.inorderTraversal(print);
	cout << endl;
	system("PAUSE");
	return 0;
}

void print(int &x) {
	cout << x << " ";
}

void update(int &x) {
	x = 2 * x;
}
==> ./Projects/c++ int 120 - functions as parameters/c++ int 120 - functions as parameters/searchTree.h <==
#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <iostream>
#include "binaryTreeType.h"

using namespace std;

template <typename eType>
class SearchTree : public BinaryTree<eType> {
public:
	bool search(const eType&) const;
	void insert(const eType&);
	void deleteNode(const eType&);
private:
	void deleteFromTree(Node<eType> *&);
};


template <typename eType>
void SearchTree<eType>::insert(const eType &item) {
	Node<eType> *current, *trail, *newNode;
	newNode = new Node<eType>;
	newNode->info = item;
	newNode->leftLink = NULL;
	newNode->rightLink = NULL;
	if (root == NULL) {
		root = newNode;
	}
	else {
		current = root;
		while (current != NULL) {
			trail = current;
			if (current->info == item) {
				cout << "Item is already in tree, no duplicates\n";
				return;
			}
			else if (current->info > item) {
				current = current->leftLink;
			}
			else {
				current = current->rightLink;
			}
		}
		if (trail->info > item) {
			trail->leftLink = newNode;
		}
		else {
			trail->rightLink = newNode;
		}
	}
}

template <typename eType>
bool SearchTree<eType>::search(const eType &item) const {
	Node<eType> *current;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty\n";
	}
	else {
		current = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else if (current->info > item) {
				current = current->leftLink; 
			}
			else {
				current = current->rightLink;
			}
		}
	}
	if (found) {
		cout << "\nfound item\n";
	}
	return found;
}

template <typename eType>
void SearchTree<eType>::deleteFromTree(Node<eType> *&p) {
	Node<eType> *current, *trail, *temp;
	if (p == NULL) {
		cout << "The node is NULL\n";
	}
	else if ((p->leftLink == NULL) && (p->rightLink == NULL)) {
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->leftLink == NULL) {
		temp = p;
		p = temp->rightLink;
		delete temp;
	}
	else if (p->rightLink == NULL) {
		temp = p;
		p = temp->leftLink;
		delete temp;
	}
	else { //always goes to the maximum node value on the left hand side of the structure and replaces p with this so structure remains intact
		current = p->leftLink;
		trail = NULL;
		while (current->rightLink != NULL) {
			trail = current;
			current = current->rightLink;
		}
		p->info = current->info;
		if (trail == NULL) {
			p->leftLink = current->leftLink;
		}
		else {
			trail->rightLink = current->leftLink;
			delete current;
		}
	}
}

template <typename eType>
void SearchTree<eType>::deleteNode(const eType &item) {
	Node<eType> *current, *trail;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty\n";
	}
	else {
		current = root;
		trail = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else {
				trail = current;
				if (current->info > item) {
					current = current->leftLink;
				}
				else {
					current = current->rightLink;
				}
			}
		}
		if (current == NULL) {
			cout << "Item is not found in tree\n";
		}
		else if (found) {
			if (current == root) {
				deleteFromTree(root);
			}
			else if (trail->info > item) {
				deleteFromTree(trail->leftLink);
			}
			else {
				deleteFromTree(trail->rightLink);
			}
		}
		else {
			cout << "Item not found in tree\n";
		}
	}
}

#endif
==> ./Projects/c++ int 121 stl vectors/c++ int 121 stl vectors/main.cpp <==
//vector is part of stl, stl has 3 main components: containers, iterators and algorithms. containers and iterators are class templates, iterators are used tto step through the components of a container, and algorithms are used to manipulate data
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	/*vector<int> intList(5); //initialises 5 components of vector<int>
	vector<string> stringList(5); //intialises 5 components of vector stringList
	for (int i = 0; i < 6; i++) {
		stringList.push_back("a");
	}
	for (auto i : stringList) {
		cout << "i: " << i << endl;
	}
	cout << endl;
	vector<string> strList(5, "a"); //initialises 5 components of vector strList with "a"
	vector<int> list2(3, 43);
	for (auto i : list2) {
		cout << "i: " << i << endl;
	}
	cout << endl;
	cout << strList.at(3) << endl;
	cout << strList[3] << endl;
	cout << strList.front() << endl;
	cout << strList.back() << endl;
	cout << strList.capacity() << endl;
	cout << strList.empty() << endl;
	cout << strList.size() << endl;
	cout << strList.max_size() << endl;
	strList.clear();
	strList.push_back("dave");
	strList.pop_back();
	strList.resize(15); 
	strList.resize(4, "dave");
	strList.resize(strList.size() + 10);
	
	vector<string>::iterator iter; //creates an iterator for the vector
	// ++iter - advances iterator to the next position in array
	// *iter - returns element at current iterator position

	iter = strList.begin();
	for (iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter << endl;
	}

	string strArray[7] = { "a", "b", "c", "d", "e", "f", "g" };
	vector<string> list3(strArray, strArray + 7);
	for (auto i : list3) {
		cout << i << endl;
	}
	cout << endl;
	vector<string>::iterator newiter;
	newiter = list3.begin();
	++newiter;
	list3.insert(newiter, "hey");
	for (auto i : list3) {
		cout << i << endl;
	}*/

	vector<string> strList;
	strList.push_back("hi");
	strList.push_back("i'm");
	strList.push_back("super");
	strList.push_back("ok");
	cout << "strList elements = ";
	for (int i = 0; i < 4; i++) {
		cout << strList[i] << " ";
	}
	cout << endl;
	for (auto i : strList) {
		i += " there."; //this code will ot alter strList as i is a local variable created using 'auto' keyword
	}
	for (int i = 0; i < 4; i++) {
		strList[i] += " good looking.";
	}
	cout << "\n\n";
	//cout << "\nstrList elements = \n";
	for (auto i : strList) {
		cout << i << "\n";
	}
	cout << "\n";

	vector<string>::iterator iter;
	for (iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter << "\n";
	}
	cout << "\n";
	
	iter = strList.begin();
	++iter;
	++iter;
	strList.insert(iter, "*fart*");
	//cout << "\nstList elements: \n";
	for (iter = strList.begin(); iter != strList.end(); ++iter) {
		cout << *iter << "\n";
	}
	cout << endl;
	
	vector<int> numbers;

	numbers.reserve(4); //allocates memory for 4 elements of type int to "numbers" 

	vector <vector <int>> numbers2; //multi-dimensional vector
	numbers.push_back(1);
	numbers.push_back(2);
	numbers2.push_back(numbers);
	numbers.clear();
	numbers.push_back(1);
	numbers.push_back(3);
	numbers2.push_back(numbers);
	numbers.clear();
	
	for (auto i : numbers2) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 122 the copy algorithm/c++ int 122 the copy algorithm/main.cpp <==
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int intArray[] = { 5, 6, 8, 3, 40, 36, 98, 29, 75 };
	vector<int> vecList(9);
	ostream_iterator<int> screen(cout, " "); //takes cout and space as arguments, will print to cout to consol with space " " in-between each element

	cout << "intArray = ";
	copy(intArray, intArray + 9, screen);
	cout << endl;

	copy(intArray, intArray + 9, vecList.begin()); //outputs betweenn intArray	memory address of first element and memory address of 9th element, for size of vecList - 9 elements 
	cout << "vecList = ";
	copy(vecList.begin(), vecList.end(), screen); 
	cout << endl;

	copy(intArray + 3, intArray + 9, intArray);
	cout << "after shifting elements, intArray = ";
	copy(intArray, intArray + 9, screen);
	cout << endl;

	copy(vecList.rbegin() + 7, vecList.rend(), vecList.rbegin());
	cout << "After shifting elements, vecList = ";
	copy(vecList.begin(), vecList.end(), screen);
	cout << endl;

	return 0;
}


==> ./Projects/c++ int 123 stl deque/c++ int 123 stl deque/main.cpp <==
#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	cin.exceptions(ios_base::failbit);
	deque<int> deq;
	deque<int> list2(deq);
	deque<int> list3(15); //initialises 0 for 15 elements
	for (auto i : list3) {
		cout << i << " "; 
	}
	cout << endl;
	deque<char> list4(20, 'A');
	deq.assign(5, 12); //12 for 5 places
	for (auto i : deq) {
		cout << i << " ";
	}
	cout << endl;
	deq.push_front(4); //places 4 at front
	deq.pop_back(); //deletes 12 from back
	//deq.at(3) == deq[3]
	cout << "front: " << deq.front() << endl;
	cout << "back: " << deq.back() << endl;
	
	deque<int> intDeq;
	ostream_iterator<int> screen(cout, " ");
	intDeq.push_back(13);
	intDeq.push_back(75);
	intDeq.push_back(28);
	intDeq.push_back(35);
	cout << "intDeq = ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.push_front(0);
	intDeq.push_front(100);
	cout << "intDeq = ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.pop_back();
	intDeq.pop_back();
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.pop_back();
	intDeq.pop_back();
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	deque<int>::iterator iter;
	iter = intDeq.begin();
	++iter; // iterator moves to second position
	intDeq.insert(iter, 44); //inserts at second position
	cout << "intDeq = ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.assign(2, 45); //reinitializes with 45 for 2 positions
	cout << "intDeq = ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.push_front(-10);
	intDeq.push_back(-999);
	cout << "intDeq = ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 124 - stl list container/c++ int 124 - stl list container/main.cpp <==
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	list<int> list1;
	list<int> list2(list1);
	list<char> list3;
	list<int> list4(5, 12);
	for (auto i : list4) {
		cout << i << " ";
	}
	cout << endl;
	list1.assign(5, 15);
	//list2(5, 13); only works at object initialization use .assign()
	list1.push_front(25);
	list1.pop_back();

	for (int i = 65; i < 70; i++) {
		list3.push_back((char)i);
		list3.push_front((char)i);
	}
	cout << "list3: ";
	for (auto i : list3) {
		cout << i << " ";
	}
	cout << endl;
	list3.remove('C'); //if there is a C at the end of the list this will not functiion - use erase-remove idiom (c++ int 132)
	cout << "list3: ";
	for (auto i : list3) {
		cout << i << " ";
	}
	cout << endl;

	list3.unique(); //removes duplicates from the list, only if they are consecutive elements 
	cout << "list3 ";
	for (auto i : list3) {
		cout << i << " ";
	}
	cout << endl;

	cout << "front " << list1.front() << endl;
	cout << "back " << list1.back() << endl;
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;
	int x = 15;


	//list3.erase(remove_if(list3.begin(), list3.end(), [](char x) {return isspace(x); }), list3.end());

	list1.erase(remove_if(list1.begin(), list1.end(), [](int y) {return (y > 16); }), list1.end());
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;

	list1.push_back(13);
	list1.erase(remove_if(list1.begin(), list1.end(), [](int y) {return (y == 15); }), list1.end()); 
	//erase-remove idiom, 3rd parameter an be lamda function or simple rh value, variable, built-in functions such as isupper, islower etc.

	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;
	list1.assign(4, 15);
	list1.unique(); //removes duplicates from the list, only if they are consecutive elements
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;

	for (int i = 1; i < 5; i++) {
		list1.push_back(i);
	}
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;

	list<int>::iterator iter;
	
	iter = list1.begin();

	for (int i = 0; i < 3; i++) {
		++iter;
	}

	//list1.splice(list1.begin(), list4);
	//list1.splice(list1.end(), list4);
	list1.splice(iter, list4); //splices list1 and list4 at position denoted by iter, empties list4
	//iter increases position by number of elemets that were in list4
	list1.insert(iter, 798); //inserts 798 at iter
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;
	cout << "list4 = ";
	for (auto i : list4) {
		cout << i << " ";
	}
	cout << endl;
	list1.sort();
	list1.unique();
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;
	list4.assign(4, 17);
	list1.merge(list4); //== list1.splice(list1.end(), list4);
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;
	list1.unique();
	list1.reverse();
	cout << "list1 = ";
	for (auto i : list1) {
		cout << i << " ";
	}
	cout << endl;

	ostream_iterator<int> screen1(cout, " ");
	cout << "list1 = ";
	copy(list1.begin(), list1.end(), screen1);
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 125 iterators/c++ int 125 iterators/main.cpp <==
/*iterators function similarly to a pointer to element of container such as vector, list, deque (sequence & associative). iterators help to access, process, manipulate data from the elements of containers. 
There are 5 types of iterators: 1 - input iterators, 2 - output iterators, 3 - forward iterators, 4 - bi-directional iterators, 5 - random access iterators

1- input iterators with read access step forward element by element, and return values. provided for reading data from an input stream , 
2 - output iterators provided for writing data to output stream and used as inserters, if used with assignment operator = or a function will assign value to element position
3 - forward iterators have all of functionality of input iterators and almost all functionality of output iterators, can assign forward iterator the value of another iterator
4 - bi-directional iterators are like forward iterators but can iterate backwards over the elements with decrement -- operator
5 - random access iterators, bi-directional can randomly process elements of a container
	functions for random access iterators	
		iter[n] - accesses nth element;		iter += n - moves forward by n positions;		iter + n; returns iterator of next nth element			iter1 - iter2; returns distance between elements	  
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*common iterator functions
*iter; //dereference - (*) dereference operator gives access to value to which iterator points
iter->member; - will give aaccess to a member of the element similar to arrow operator for pointer
++iter; - steps forward by one element, returns new position
iter++; - steps forward by one element, returns old position
iter1 == iter2; - returns boolean true or false
*/

int main() {
	vector<int>::iterator intVecIter; //each container has type def iterator accessed by use of sope resolution operator 
	vector<int>::const_iterator cIter; //const_iterator prevents iterator from modifying the contents of the container (read-only)
	vector<int>::const_reverse_iterator cRIter;
	vector<int>::difference_type dType; 
	vector<int>::pointer p; //pointer to elements store in container
	//vector<int>::reference r; //must be intialized when declared can only be assigned once - refernce to elements in continer
	//vector<int>::const_reference cR;
	vector<int>::size_type sT; //type used to count through elements stored in container - can index through sequence containers except list containers
	vector<int>::value_type vT; 
	//stream iterators - found in <iterator> header
	istream_iterator<int> in(cin); //used to  input data from input stream, initialise with cin or ifstream object, etc.
	ostream_iterator<int> out(cout); //u sed to output data, initialise with cout or ofstream object, can specify character seperatimng output as 2nd initialization parameter i.e. ostream_iterator<int> out(cout, " ");
	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 126 set and multiiset/c++ int 126 set and multiiset/main.cpp <==
//sets and multisets automatically order components via use of a binary tree
#include <iostream> //std::cout, std::auto
#include <set> //std::set 
#include <string> //std::string
#include <algorithm>
#include <iterator>
#include <functional> //std::greater
#include <unordered_set> //

using namespace std;

//as sets are sorted by default custom sorting method can be created for the type - following will sort by string length
struct SortOrder {
	//operator overload of () brackets is called a 'functor'
	bool operator()(const string &first, const string &second) {
		int length1 = first.length();
		int length2 = second.length();

		if (length1 == length2) {
			return (first < second); //will sort in default order
		}
		return (length1 > length2); //returns bool value true if condition met, false if not
	}
};

int main() {
	set<int> set1;
	
	set<int> set3(set1);
	multiset<int, greater <int>> set4; //multisets allow you to use multiples of the same value, will still sort values
	set<int, greater<int> > set5; 
	unordered_set<int> set6; //will be unordered but will still store each value only once
	unordered_multiset<int> set7; //will be unordered and can store each value more than once

	set1.insert(24);
	set1.insert(24);
	set4.insert(24);
	set4.insert(24);
	set5.insert(24);
	set5.insert(24);

	for (int i = 1; i <= 5; i++) {
		set1.insert(i);
	}
	cout << "set 1 :\n";
	for (auto i : set1) {
		cout << i << endl;
	}

	for (int i = 1; i <= 5; i++) {
		set5.insert(i);
	}
	cout << "set 5 :\n";
	for (auto i : set5) {
		cout << i << endl;
	}

	set<int>::iterator iter;
	iter = set1.begin();
	iter++;
	set1.erase(iter);
	set5.erase(2);
	ostream_iterator<int> scr33n(cout, " ");

	set1.clear();
	set5.clear();

	set1.insert(16);
	set1.insert(8);
	set1.insert(20);
	set1.insert(3);
	cout << "set1 = ";
	copy(set1.begin(), set1.end(), scr33n);
	cout << endl;
	set5.insert(36);
	set5.insert(84);
	set5.insert(30);
	set5.insert(39);
	set5.insert(59);
	set5.insert(237);
	set5.insert(152);
	set5.insert(301);
	cout << "set5 = ";
	copy(set5.begin(), set5.end(), scr33n);
	cout << endl;

	set5.erase(59);
	cout << "set5 = ";
	copy(set5.begin(), set5.end(), scr33n);
	cout << endl;
	iter = set5.begin();
	++iter;
	++iter;
	++iter;
	set5.erase(iter);

	set<int, greater<int> > set2(set5);
	cout << "set 2 = ";
	copy(set2.begin(), set2.end(), scr33n);
	cout << endl;
	set2.clear();
	cout << "set 2 = ";
	copy(set2.begin(), set2.end(), scr33n);

	set<string,  SortOrder > name;
	set<string,  SortOrder >::iterator iter1;
	ostream_iterator<string> screen1(cout, ", ");
	name.insert("Green");
	name.insert("Breenie");
	name.insert("Dreener");
	name.insert("Areen");
	cout << "name = ";
	copy(name.begin(), name.end(), screen1);
	cout << endl;

	return 0;
}
==> ./Projects/c++ int 127 function objects/c++ int 127 function objects/main.cpp <==
/*function objects - stored in functional header file, can be used more easily than standard functions - used in some type declarations, e.g.  greater<Type> used in declaring:	 
	set<int, greater<int> >   or	multiset<int, greater<int> >

//plus<Type>//
plus<int> addNUm;
int sum = addNum(12, 35);

//minus<Type>//
minus<int> subtractNum;
int diff = subtractNum(12, 5);

//multiplies<Type>//
multiplies<int> prodNum;
int prod = prodNum(12, 35);

//divides<Type>//
divides<int> quoNum;
int div = quoNum(12, 5);

//modulus<Type>//
modulus<int> modNum;
int mod = modNum(12, 5);

//negate<Type>//
mult<int> prodNum;
int prod = prodNum(12, 35);

//equal_to<Type>//
equal_to<int> compnum;
bool isEqual = compNum(12, 35);

//not_equal_to<Type>//
not_equal_to<int> compNum;
bool notEqual = compNum(12, 35);

//greater<Type>//
greater<int> compNum;
bool isGreater = compNum(12, 35);

//greater_equal<Type>//
greater_equal<int> compNum;
bool isEqualGreater = compNum(12, 35);

//less<Type>//
less<int> compNum;
bool isLess = compNum(12, 35);

//less_equal<Type>//
mult<int> prodNum;
int prod = prodNum(12, 35);
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

int function1(plus<int>, int, int);

int main() {
	plus<int> addNum;
	int num = addNum(34, 56);
	cout << "num = " << num << endl;

	plus<string> join;
	string str1 = "Sup ", str2 = "y'all";
	string str = join(str1, str2);
	cout << "str = " << str << endl;
	cout << "sum of 12 and 23 = " << function1(addNum, 12, 23) << endl;

	int list1[8] = { 1,2,3,4,5,6,7,8 };
	vector<int> intList(list1, list1 + 8);
	ostream_iterator<int> print1(cout, " ");
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;

	int sum = accumulate(intList.begin(), intList.end(), 0);
	cout << "sum of elements of intList = " << sum << endl;

	int product = accumulate(intList.begin(), intList.end(), 0, multiplies<int>());
	cout << "product of elements of intList = " << product << endl;

	equal_to<int> compare;
	bool isEqual = compare(5, 6);
	cout << "isEqual = " << isEqual << endl;
	
	vector<int>::iterator iter1, iter2;
	
	greater<string> larger;
	if (larger(str1, str2)) {
		cout << str1 << " is greater than " << str2 << endl;
	}
	else {
		cout << str1 << " isn't greater than " << str2 << endl;
	}

	int temp[8] = { 2, 3, 4, 5, 1, 7, 8 , 9 };
	vector<int> vecList(temp, temp + 8);
	copy(vecList.begin(), vecList.end(), print1);
	cout << endl;

	iter1 = adjacent_find(vecList.begin(), vecList.end(), greater<int>());
	if (iter1 == vecList.end()) {
		cout << "The entire vector is sorted in ascending order\n";
	}
	else {
		cout << "The last element in the non-decreasing subsequence is at: " << distance(vecList.begin(), iter1) << '\n';
	}

	iter1 = adjacent_find(vecList.begin(), vecList.end(), greater<int>());
	iter2 = iter1 + 1;
	cout << "First set of out of order elements = " << *iter1 << " " << *iter2 << endl;
	cout << "First set of out of order element position = " << vecList.end() - iter2 << endl;

	system("PAUSE");
	return 0;
}

int function1(plus<int> sum, int a, int b) {
	return sum(a, b);
}
==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/Abstractgraph.h <==
#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include <iostream>
#include <fstream>
#include <deque>
#include "unorderedlinkedlist.h"
#include "linkedListIterator.h"

using namespace std;

class graphType {
public:
	bool isEmpty() const;
	void createGraph();
	void clearGraph();
	void printGraph() const;
	void depthFirstTraversal();
	void dftAtVertex(int);
	void breadthFirstTraversal();
	graphType(int size = 0);
	~graphType();
protected:
	int maxSize;
	int gSize;
	unorderedlinkedList<int> *graph; //linked list of pointers, 2d array effect
private:
	void dft(int, bool[]);
};

bool graphType::isEmpty() const {
	return (gSize == 0);
}

void graphType::createGraph() {
	ifstream infile;
	char fileName[50];
	int index, vertex, adjacentVertex;
	if (gSize != 0) {
		clearGraph();
	}
	cout << "Enter file name: ";
	cin >> fileName;
	cout << endl;
	infile.open(fileName);
	if (!infile) {
		cout << "Cannot open file\n";
		return;
	}
	infile >> gSize;
	for (index = 0; index < gSize; index++) {
		infile >> vertex;
		infile >> adjacentVertex;
		while (adjacentVertex != -999) {
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}
	infile.close();
}

void graphType::clearGraph() {
	for (int index = 0; index < gSize; index++) {
		graph[index].destroyList();
	}
	gSize = 0;
}

void graphType::printGraph() const {
	for (int index = 0; index < gSize; index++) {
		cout << index << " ";
		graph[index].print();
		cout << endl;
	}
	cout << endl;
}

graphType::graphType(int size) {
	maxSize = size;
	gSize = 0;
	graph = new unorderedlinkedList<int>[size];
}

void graphType::dft(int i, bool visited[]) { //depth first traversal
	visited[i] = true;
	cout << " " << i << " ";
	linkedlistIterator<int> iter;
	for (iter = graph[i].begin(); iter != graph[i].end(); ++iter) {
		int w = *iter;
		if (!visited[w]) {
			dft(w, visited);
		}
	}
}

void graphType::depthFirstTraversal() {
	bool *visited; //pointer to create array to store visited vertices
	visited = new bool[gSize];
	int index;
	for (index = 0; index < gSize; index++)
		visited[index] = false;
	//for vertices not visited, perform depth first traversal
	for (index = 0; index < gSize; index++) {
		if (!visited[index]) {
			dft(index, visited);
		}
	}
	delete[] visited;
}

void graphType::dftAtVertex(int vertex) {
	bool *visited;
	visited = new bool[gSize];
	for (int index = 0; index < gSize; index++) {
		visited[index] = false;
	}
	dft(vertex, visited);
	delete[] visited;
}

void graphType::breadthFirstTraversal() {
	deque<int> queue;
	bool *visited;
	for (int i = 0; i < gSize; i++) {
		visited[i] = false;
	}
	linkedlistIterator<int> iter;
	for (int index = 0; index < gSize; index++) {
		if (!visited[index]) {
			queue.push_front(index);
			visited[index] = true;
			cout << " " << index << " ";
			while (!queue.empty()) {
				int u = queue.front();
				queue.pop_front();
				for (iter = graph[u].begin(); iter != graph[u].end(); ++iter) {
					int w = *iter;
					if (!visited[w]) {
						queue.push_front(w);
						visited[w] = true;
						cout << " " << w << " ";
					}
				}
			}
		}
	}
	delete[] visited;
}

#endif
==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/linkedListClass.h <==
#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H
#include <iostream>
#include <cassert>
#include "linkedListIterator.h"

using namespace std;

template <typename Type>
class linkedlistType {
public:
	//linkedlistType<Type>& operator=(const linkedlistType<Type> &rhs);
	bool operator==(const linkedlistType<Type> &rhs) const;
	bool operator!=(const linkedlistType<Type> &rhs) const;
	linkedlistType<Type> operator=(const linkedlistType);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;
	virtual bool search(const Type&) const = 0;
	virtual void insertFirst(const Type&) = 0;
	virtual void insertLast(const Type&) = 0;
	virtual void deleteNode(const Type&) = 0;
	linkedlistIterator<Type> begin();
	linkedlistIterator<Type> end();
	~linkedlistType();
	linkedlistType(const linkedlistType<Type>&);
	linkedlistType();
protected:
	int count;
	node<Type> *first;
	node<Type> *last;
private:
	void copyList(const linkedlistType<Type>&);
};

template <typename Type>
void linkedlistType<Type>::print() const {
	node<Type> *current;
	current = first;
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
}

template <typename Type>
void linkedlistType<Type>::destroyList() {
	node<Type> *temp;
	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	first = NULL;
	last = NULL;
	count = 0;
}

template <typename Type>
void linkedlistType<Type>::copyList(const linkedlistType<Type> &rhs) {
	node<Type> *newNode, *current;
	if (first != NULL) {
		destroyList();
	}
	if (rhs.first == NULL) {
		first = NULL;
		last = NULL;
		count = 0;
	}
	else {
		current = rhs.first; //value of first node is copied
		count = rhs.count; //value of count is copied
		first = new node<Type>; //first created as new node
		first->info = current->info; //value of current info assigned to first->info
		first->link = NULL; //pointer field of first set to NULL
		last = first; //initializes last as first
		current = current->link; //current set to next value in list
		while (current != NULL) {
			newNode = new node<Type>; //newNode created for storage
			newNode->info = current->info; //value int current-> info stored in newNode
			newNode->link = NULL; //pointer field of newNode set to NULL
			last->link = newNode; //link in previous node now points to newNode
			last = newNode; //last now equalt to newNOde, last->link = NULL
			current = current->link; //current moves on to next node
		}
	}
}

template <typename Type>
bool linkedlistType<Type>::operator==(const linkedlistType<Type> &rhs) const {
	node<Type> *current = first, *rhscurrent = rhs.first;
	while ((current != NULL) && (rhscurrent != NULL)) {
		if (current->info != rhscurrent->info) {
			return false;
		}
		else {
			current = current->link;
			rhscurrent = rhscurrent->link;
		}
	}
	if ((current == NULL) && (rhscurrent == NULL)) {
		return true;
	}
	else {
		return false;
	}
}

template <typename Type>
bool linkedlistType<Type>::operator!=(const linkedlistType<Type> &rhs) const {
	node<Type> *current = first, *rhscurrent = rhs.first;
	while ((current != NULL) && (rhscurrent != NULL)) {
		if (current->info != rhscurrent->info) {
			return true;
		}
		else {
			current = current->link;
			rhscurrent = rhscurrent->link;
		}
	}
	if ((current == NULL) && (rhscurrent == NULL)) {
		return false;
	}
	else {
		return true;
	}
}

template <typename Type>
bool linkedlistType<Type>::isEmptyList() const {
	return (first == NULL);
}

template <typename Type>
linkedlistType<Type>::linkedlistType() {
	destroyList();
}

template <typename Type>
linkedlistType<Type>::~linkedlistType() {
	destroyList();
}

template <typename Type>
linkedlistType<Type>::linkedlistType(const linkedlistType<Type> &rhs) {
	destroyList();
	copyList(rhs);
}

/*template <typename Type>
linkedlistType<Type>& linkedlistType<Type>::operator=(const linkedlistType<Type> *&rhs) {
	//previous incarnations showed that the boolean operators worked within the main window but not within the class, other classes with overloaded boolean operators have been able too function withi the class. 
	//difference may be down to the fact that the this object is a pointer and the rhs object is not
	if (this != rhs) {
		copyList(rhs);
	}
	return *this;
}*/

#endif

==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/linkedListIterator.h <==
#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H
#include <iostream>

using namespace std;

template <typename Type>
struct node {
	Type info;
	node<Type> *link;
};

template <typename Type>
class linkedlistIterator {
	node<Type> *current;
public:
	linkedlistIterator(); 
	linkedlistIterator(node<Type>*);
	Type operator*();
	linkedlistIterator<Type> operator++();
	bool operator==(const linkedlistIterator<Type>&) const;
	bool operator!=(const linkedlistIterator<Type>&) const;
};

template <typename Type>
linkedlistIterator<Type>::linkedlistIterator() {
	current = NULL;
}

template <typename Type>
linkedlistIterator<Type>::linkedlistIterator(node<Type> *ptr) {
	current = ptr;
}


template <typename Type>
Type linkedlistIterator<Type>::operator*() {
	return current->info;
}

template <typename Type>
linkedlistIterator<Type> linkedlistIterator<Type>::operator++() {
	current = current->link;
	return *this;
}

template <typename Type>
bool linkedlistIterator<Type>::operator==(const linkedlistIterator<Type> &rhs) const {
	return (current == rhs.current);
}


template <typename Type>
bool linkedlistIterator<Type>::operator!=(const linkedlistIterator<Type> &rhs) const {
	return (current != rhs.current);
}

#endif

==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/main.cpp <==
#include <iostream>
#include "unorderedlinkedlist.h"
#include "linkedListIterator.h";

int main() {
	/*weightedGraphType graph(7);
	graph.createGraph();
	graph.printGraph();
	cout << endl;
	graph.breadthFirstTraversal();
	cout << endl;
	graph.depthFirstTraversal();
	cout << endl;
	graph.dftAtVertex(3);
	cout << endl;
	system("PAUSE");*/

	unorderedlinkedList<int> numbers;

	return 0;
}
==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/unorderedlinkedlist.h <==
#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H
#include <iostream>
#include "linkedListClass.h"

using namespace std;

template <typename Type>
class unorderedlinkedList : public linkedlistType<Type> {
public:
	bool search(const Type&) const;
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
};

template <typename Type>
bool unorderedlinkedList<Type>::search(const Type &item) const {
	node<Type> *current;
	current = first;
	bool found = false;
	while ((current != NULL) && (!found)) {
		if (current->info == item) {
			found = true;
			break;
		}
		else {
			current = current->link;
		}
	}
	return found;
}

template <typename Type>
void unorderedlinkedList<Type>::insertFirst(const Type &item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = first;
	first = newNode;
	count++;
	if (last == NULL) {
		last = newNode;
	}
}

template <typename Type>
void unorderedlinkedList<Type>::insertLast(const Type &item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = NULL;
	if (first == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->link = newNode;
		last = newNode;
	}
}

template <typename Type>
void unorderedlinkedList<Type>::deleteNode(const Type &item) {
	node<Type> *current, *trail;
	bool found;
	if (first == NULL) {
		cout << "The list is empty\n";
	}
	else {
		if (first->info == item) {
			current = first;
			first = first->link;
			count--;
			if (first == NULL) {
				last = NULL;
			}
			delete current;
		}
		else {
			found = false;
			trail = first;
			current = first->link;
			while ((current != NULL) && (!found)) {
				if (current->info != item) {
					trail = current;
					current = current->link;
				}
				else {
					found = true;
				}
			}
			if (found) {
				trail->link = current->link;
				count--;
				if (last == current) {
					last = trail;
				}
				delete current;
			}
			else {
				cout << "Item not found in list\n";
			}
		}
	}
}

#endif
==> ./Projects/c++ int 128 graphs/c++ int 128 graphs/WeightedGraphType.h <==
#ifndef WEIGHTEDGRAPHTYPE_H
#define WEIGHTEDGRAPHTYPE_H
#include <iostream>
#include <cfloat>
#include <iomanip>
#include "Abstractgraph.h"

using namespace std;

class weightedGraphType : public graphType {
public:
	void createWeightedGraph();
	void shortestPath(int);
	void printShortestDistance(int);
	weightedGraphType(int size = 0);
	~weightedGraphType();
protected:
	double **weights;
	double *smallestWeight;
};

void weightedGraphType::shortestPath(int vertex) {
	for (int i = 0; i < gSize; i++) {
		smallestWeight[i] = weights[vertex][i]; //store weights at vertex into smalles weight container
	}
	bool *weightFound;
	weightFound = new bool[gSize];
	for (int i = 0; i < gSize; i++) {
		weightFound[i] = false;
	}
	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;
	for (int i = 0; i < gSize; i++) {
		double minWeight = DBL_MAX;
		int v;
		for (int i = 0; i < gSize; i++) { //should this be here?
			if(!weightFound[i]){
				if (smallestWeight[i] < minWeight) {
					v = i;
					minWeight = smallestWeight[v];
				}				
			}
		}
		weightFound[v] = true;
		for (int i = 0; i < gSize; i++) {
			if (!weightFound[i]) {
				if (minWeight + weights[v][i] < smallestWeight[i]) {
					smallestWeight[i] = minWeight + weights[v][i];
				}
			}
		}
	}
}

void weightedGraphType::printShortestDistance(int vertex) {
	cout << "Source vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex" << endl;
	cout << "Vertex     Shortest Distance\n";
	for (int i = 0; i < gSize; i++) {
		cout << setw(4) << i << setw(12) << smallestWeight[i] << endl;
	}
	cout << endl;
}

weightedGraphType::weightedGraphType(int size) : graphType(size) {
	weights = new double*[size];
	for (int i = 0; i < size; i++) {
		weights[i] = new double[size];
	}
	smallestWeight = new double[size];
}

weightedGraphType::~weightedGraphType() {
	for (int i = 0; i < gSize; i++) {
		delete[] weights[i];
	}
	delete[] weights;
	delete smallestWeight;
}

void weightedGraphType::createWeightedGraph() {
	graphType::createGraph();
}

#endif
==> ./Projects/c++ int 129 - insert iterators/c++ int 129 - insert iterators/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

//back_inserter, front_inserter, inserter

int main() {
	int temp[8] = { 1,2,3,4,5,6,7,8 };
	vector<int> list1, list2;
	ostream_iterator<int> print(cout, " ");
	copy(temp, temp + 8, back_inserter(list1));
	cout << "list1 = ";
	copy(list1.begin(), list1.end(), print);
	cout << endl;

	copy(list1.begin(), list1.end(), inserter(list2, list2.begin()));
	cout << "list2 = ";
	copy(list2.begin(), list2.end(), print);
	cout << endl;

	list<int> list3;
	copy(list2.begin(), list2.end(), front_inserter(list3)); //front_inserter can only be used with containers that have .push_front() such as deques and lists
	cout << "list3 = ";
	copy(list3.begin(), list3.end(), print);
	cout << endl;
	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 130 fill-generate functions/c++ int 130 fill-generate functions/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int nextNum();

int main() {
	vector<int> vList(8);
	ostream_iterator<int> print(cout, " ");

	fill(vList.begin(), vList.end(), 2); //fills list with variable '2'
	cout << "vList = ";
	copy(vList.begin(), vList.end(), print);
	cout << endl;

	fill_n(vList.begin(), 3, 5); //   fill_n(start pos    number of spaces   number to fill)
	cout << "vList = ";
	copy(vList.begin(), vList.end(), print);
	cout << endl;

	vector<int> newList(8);
	generate(newList.begin(), newList.end(), nextNum);
	cout << "newList = ";
	copy(newList.begin(), newList.end(), print);
	cout << endl;

	generate_n(newList.begin(), 3, nextNum);
	cout << "newList = ";
	copy(newList.begin(), newList.end(), print);
	cout << endl;

	system("PAUSE");
	return 0;
}

int nextNum() {
	static int n = 1;
	return n++;
}
==> ./Projects/c++ int 131 stl find functions/c++ int 131 stl find functions/main.cpp <==
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	cin.exceptions(ios_base::failbit);

	char cList[10] = { 'a', 'i', 'C', 'd', 'e', 'f', 'o', 'H', 'u', 'j'};
	vector<char> charList(cList, cList + 10);
	ostream_iterator<char> print(cout, " ");

	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	vector<char>::iterator position;
	position = find(charList.begin(), charList.end(), 'd');
	if (position != charList.end()) {
		cout << "element fund at position " << (position - charList.begin()) << endl;
	}
	else {
		cout << "element not found in list\n";
	}

	position = find_if(charList.begin(), charList.end(), isupper);
	if (position != charList.end()) {
		cout << "first upper case letter found at " << (position - charList.begin()) << endl;
	}
	else {
		cout << "no upeercase characters found in list\n";
	}

	int list1[11] = { 12, 34, 56, 68, 21, 34, 78, 34, 56, 12, 25 };
	for (int i = 0; i < 10; i++) {
		cout << "list [" << i << "] = " << &list1[i] << endl;
	}
	int list2[2] = { 34, 56 };
	int list3[3] = { 56, 21, 35 };
	int list4[3] = { 56, 21, 34 };
	
	cout << "find_end: " << (find_end(list1, list1 + 11, list2, list2 + 2)) << endl; //searches list1[10] for subrange of list2[2] {34, 56), returns last instance at list1[6]
	
	cout << "find_end: " << (find_end(list1, list1 + 11, list3, list3 + 3)) << endl; //searches list1[10] for subrange of list2[2] {56, 21, 35}, does not find, returns memory address exceeding value of list

	cout << "find_first_of : " << (find_first_of(list1, list1 + 11, list2, list2 + 2)) << endl; //searches list1[10] for subrange of list2[2], returns first instance at list1[1]
	
	cout << "find_first_of: " << (find_first_of(list1, list1 + 11, list3, list3 + 3)) << " number is " << *(find_first_of(list1, list1 + 11, list4, list4 + 3)) << endl; //searches list1 for first occurence of any of the numbers contained in list3

	cout << "find_first_of: " << (find_first_of(list1, list1 + 11, list4, list4 + 3)) << " number is "  << *(find_first_of(list1, list1 + 11, list4, list4 + 3)) << endl; //searches list1 for first occurence of any of the numbers contained in list4

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 132 stl remove functions/c++ int 132 stl remove functions/main.cpp <==
#include <iostream>
#include <cctype> //isupper, islower
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool lessequal50(int);

int main() {
	char cList[10] = { 'A', 'a', 'A', 'B', 'A', 'c', 'D', 'e', 'F', 'A' };
	vector<char> charList(cList, cList + 10);
	vector<char>::iterator last, newLast;
	ostream_iterator<char> print(cout, " ");
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	charList.erase(remove(charList.begin(), charList.end(), 'A'), charList.end()); //removes all instances of 'A'
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	charList.erase(remove_if(charList.begin(), charList.end(), isupper), charList.end()); //removes all instances of uppercase character
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	int list[10] = { 12, 34, 56, 21, 34, 78, 34, 55, 12, 25 };
	vector<int> intList(list, list + 10);
	vector<int>::iterator end;
	ostream_iterator<int> print1(cout, " ");
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;

	vector<int> temp1(10);
	remove_copy(intList.begin(), intList.end(), temp1.begin(), 34 ); //copies all elementsinto container except 34
	cout << "temp1 = ";
	copy(temp1.begin(), temp1.end(), print1);
	cout << endl;

	vector<int> temp2(10, 0);
	remove_copy_if(intList.begin(), intList.end(), temp2.begin(), [](int y) {return (y <= 50); });
	//remove_copy_if(intList.begin(), intList.end(), temp2.begin(), lessequal50); will accomplish same purpose
	cout << "temp2 = ";
	copy(temp2.begin(), temp2.end(), print1);
	cout << endl;

	system("PAUSE");
	return 0;
}

bool lessequal50(int num) {
	return (num <= 50);
}
==> ./Projects/c++ int 136 stl merge functions/c++ int 136 stl merge functions/main.cpp <==
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main() {
	int list1[10] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int list2[10] = { 0, 1, 6, 6, 2, 3, 4, 5, 6, 6 };
	int list3[5] = { 0, 2, 4, 6, 8 };
	int list4[5] = { 1, 3, 5, 7, 9 };
	list<int> intList(list2, list2 + 10);
	vector<int> vecList(list1, list1 + 10);
	list<int>::iterator listIter;
	vector<int>::iterator vecIter;
	ostream_iterator<int> print(cout, " ");

	cout << "intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;

	listIter = adjacent_find(intList.begin(), intList.end());
	if (listIter != intList.end()) {
		cout << "adjacent elements found at position " << distance(intList.begin(), listIter) << endl;
	}
	else {
		cout << "adjacent elements not found\n";
	}

	intList.clear();

	merge(list3, list3 + 5, list4, list4 + 5, back_inserter(intList));
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;

	vecIter = adjacent_find(vecList.begin(), vecList.end(), greater<int>());
	cout << "finds element with highest value " << *vecIter << endl;
	cout << "vecList = ";
	for (auto i : vecList) {
		cout << i << " ";
	}
	cout << endl;
	vecIter++;

	inplace_merge(vecList.begin(), vecIter, vecList.end());
	for (auto i : vecList) {
		cout << i << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 137 stl reverse and rotate/c++ int 137 stl reverse and rotate/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
	int temp[10] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	list<int> intList(temp, temp + 10);
	list<int> result;
	list<int>::iterator iter;
	ostream_iterator<int> print(cout, " ");

	cout << "intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;

	reverse(intList.begin(), intList.end());
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;

	reverse_copy(intList.begin(), intList.end(), back_inserter(result));
	cout << "result = ";
	copy(result.begin(), result.end(), print);
	cout << endl;

	intList.clear();
	for (int i = 0; i < 10; i++) {
		intList.push_back(i);
	}

	iter = intList.begin();
	iter++;
	iter++;
	iter++;
	cout << "before rotation, intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;
	rotate(intList.begin(), iter, intList.end());
	cout << "after rotation, intList = ";
	copy(intList.begin(), intList.end(), print);
	cout << endl;
	
	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 138 stl functions count, min, max/c++ int 138 stl functions count, min, max/main.cpp <==
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	char cList[10] = { 'Z', 'a', 'Z', 'B', 'Z', 'c', 'D', 'e', 'F', 'Z' };
	vector<char> charList(cList, cList + 10);
	ostream_iterator<char> print(cout, " ");

	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	cout << "Number of Z's: " << count(charList.begin(), charList.end(), 'Z') << endl;
	cout << "Number of upper case characters: " << count_if(cList, cList+10, isupper) << endl;

	int list[10] = { 12, 34, 56, 21, 34, 78, 34, 55, 12, 25 };
	ostream_iterator<int> out(cout, " ");
	cout << "list = ";
	copy(list, list + 10, out);
	cout << endl;

	cout << "largest element in list: " << *max_element(list, list + 10) << endl;
	cout << "smallest element in list: " << *min_element(list, list + 10) << endl;

	random_shuffle(list, list + 10);
	cout << "list after random shuffle: ";
	for (auto i : list) {
		cout << i << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 139 STL - for each, transform/c++ int 139 STL - for each, transform/main.cpp <==
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

//void doubleNum(int&);

int main() {
	char cList[5] = { 'a', 'b', 'c', 'd', 'e' };
	vector<char> charList(cList, cList + 5);
	ostream_iterator<char> print(cout, " ");

	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	//        input iter        input iter      output iter       unaryoperation
	transform(charList.begin(), charList.end(), charList.begin(), toupper);
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	int list[7] = { 2, 5, 8, 1, 7, 11, 3 };
	cout << "list: ";
	for (auto i : list) {
		cout << i << " ";
	}
	cout << endl;

	cout << "for each function = \n";
	for_each(list, list + 7, [](int &y) { y = 2 * y; });
	//same as for_each(list, list + 7, doubleNum)
	cout << endl;

	cout << "list: ";
	for (auto i : list) {
		cout << i << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}

/*void doubleNum(int &num) {
	num = 2 * num;
}*/
==> ./Projects/c++ int 140 STL set, include/c++ int 140 STL set, include/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	char setA[5] = { 'A', 'B', 'C', 'D', 'E' };
	char setB[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'I', 'J', 'K', 'L' };
	char setC[5] = { 'A', 'E', 'I', 'O', 'U' };
	
	cout << "setA = ";
	for (auto i : setA) {
		cout << i << " ";
	}
	cout << endl;

	cout << "setB = ";
		for (auto i : setB) {
			cout << i << " ";
		}
	cout << endl;

	cout << "setC = ";
		for (auto i : setC) {
			cout << i << " ";
		}
	cout << endl;

	if (includes(setB, setB + 10, setA, setA + 5)) {
		cout << "setA is a subsetof setB\n";
	}
	else {
		cout << "setA is not a  subset of setB\n";
	}

	if (includes(setB, setB + 10, setC, setC + 5)) {
		cout << "setC is a subsetof setB\n";
	}
	else {
		cout << "setC is not a  subset of setB\n";
	}

	int set1[5] = { 2, 4, 5, 7, 8 };
	int set2[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int set3[5] = { 2, 5, 8, 8, 15 };
	int set4[6] = { 1, 4, 4, 6, 7, 12 };

	int AunionB[12];
	int BunionC[10];
	int BunionD[13];
	int AintersectB[12];
	int BintersectC[15];
	int *lastElem;
	ostream_iterator<int> print(cout, " ");

	cout << "set1 = ";
	for (auto i : set1) {
		cout << i << " ";
	}
	cout << endl;
	
	cout << "set2 = ";
	for (auto i : set2) {
		cout << i << " ";
	}
	cout << endl;
	
	cout << "set3 = ";
	for (auto i : set3) {
		cout << i << " ";
	}
	cout << endl;
	
	cout << "set4 = ";
	for (auto i : set4) {
		cout << i << " ";
	}
	cout << endl;

	lastElem = set_union(set1, set1 + 5, set2, set2 + 7, AunionB);
	cout << "set 1 union set 2 = ";
	copy(AunionB, lastElem, print);
	cout << endl;

	lastElem = set_union(set2, set2 + 7, set3, set3 + 5, BunionC);
	cout << "set 2 union set 3 = ";
	copy(BunionC, lastElem, print);
	cout << endl;

	lastElem = set_union(set2, set2 + 7, set4, set4 + 6, BunionD);
	cout << "set 2 union set 4 = ";
	copy(BunionD, lastElem, print);
	cout << endl;
	
	lastElem = set_intersection(set1, set1 + 5, set2, set2 + 7, AintersectB);
	cout << "set 1 intersect set 2 = ";
	copy(AintersectB, lastElem, print);
	cout << endl;

	lastElem = set_intersection(set2, set2 + 7, set3, set3 + 5, BintersectC);
	cout << "set 2 intersect set 3 = ";
	copy(BintersectC, lastElem, print);
	cout << endl;

	int seta[5] = { 2, 4, 5, 7, 8 };
	int setb[7] = { 3, 4, 5, 6, 7, 8, 10 };
	int setc[5] = { 1, 5, 6, 8, 15 };

	int AdifferenceC[8];
	int BsymdiffC[15];

	cout << "seta = ";
	for (auto i : seta) {
		cout << i << " ";
	}
	cout << endl;

	cout << "setb = ";
	for (auto i : setb) {
		cout << i << " ";
	}
	cout << endl;

	cout << "setc = ";
	for (auto i : setc) {
		cout << i << " ";
	}
	cout << endl;

	//AdifferenceB = 2
	//BdifferenceA = 3, 6, 10
	//BdifferenceC = 3, 4, 7, 10
	//CdifferenceB = 1, 15
	//BsymdiffC = 1, 3, 4, 7, 10, 15

	lastElem = set_difference(seta, seta + 5, setc, setc + 5, AdifferenceC);
	cout << "AdifferenceC = "; //2 4 7, CdiffA = 1 6 15 
	copy(AdifferenceC, lastElem, print);
	cout << endl;

	lastElem = set_symmetric_difference(setb, setb + 7, setc, setc + 5, BsymdiffC);
	cout << "BsymdiffC = ";
	copy(BsymdiffC, lastElem, print);
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 141 STL arithmetic functions/c++ int 141 STL arithmetic functions/main.cpp <==
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

void print(vector<int>);

int main() {
	int list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> vecList(list, list + 8);
	vector<int> newList(8);

	cout << "vecList = ";
	print(vecList);

	int sum = accumulate(vecList.begin(), vecList.end(), 0);
	cout << "sum elments of vecList = " << sum << endl;

	int product = accumulate(vecList.begin(), vecList.end(), 1, multiplies<int>());
	cout << "product elments of vecList = " << product << endl;

	adjacent_difference(vecList.begin(), vecList.end(), newList.begin());
	cout << "newList = ";
	print(newList);

	adjacent_difference(vecList.begin(), vecList.end(), newList.begin(), multiplies<int>()); //multiplies adjacent elements
	cout << "newList = ";
	print(newList);

	sum = inner_product(vecList.begin(), vecList.end(), newList.begin(), 0); 
	// sum of multiplication of elements within arrays i.e. (vecList[0] * newList[0]) + (vecList[1] * newlist[1]) + ... equiv to
	cout << "sum = " << sum << endl;
	int sum1 = 0;
	for (int i = 0; i < 8; i++) {
		sum1 += vecList[i] * newList[i];
	}
	cout << "sum1 = " << sum1 << endl;

	sum = inner_product(vecList.begin(), vecList.end(), newList.begin(), 0, plus<int>(), plus<int>());
	//  0 +=  vecList[i] + newList[i]
	// plus<int>       plus<int>
	cout << "sum = " << sum << endl;
	sum1 = 0;
	for (int i = 0; i < 8; ++i) {
		sum1 += vecList[i] + newList[i];
	}
	cout << "sum1 = " << sum1 << endl;

	sum = inner_product(vecList.begin(), vecList.end(), newList.begin(), 0, plus<int>(), minus<int>());
	// 0 += vecList[i] - newList[i]
	// plus<int>    minus<int>
	cout << "sum = " << sum << endl;
	sum1 = 0;
	for (int i = 0; i < 8; ++i) {
		sum1 += vecList[i] - newList[i];
	}
	cout << "sum1 = " << sum1 << endl;

	partial_sum(vecList.begin(), vecList.end(), newList.begin());
	// newlist[i] = vecList [i] + vecList [i - 1] + ... + vecList[0]
	cout << "newList with partial sum = ";
	print(newList);

	partial_sum(vecList.begin(), vecList.end(), newList.begin(), multiplies<int>());
	//newList[i] = vecList[i] * vecList[i - 1] * ... * vecList[0]
	cout << "newList with partial multiplication = ";
	print(newList);

	system("PAUSE");
	return 0;
}

void print(vector<int> vList) {
	ostream_iterator<int> print(cout, " ");
	copy(vList.begin(), vList.end(), print);
	cout << endl;
}
==> ./Projects/c++ int 143 priority queues/c++ int 143 priority queues/main.cpp <==
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	//priority queue orders items from largest to smallest
	priority_queue<int> queue;

	queue.push(10);
	queue.push(40);
	queue.push(5);

	for (int i = 0; i < 3; i++) {
		cout << queue.top() << " ";
		queue.pop();
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 145 - array container class/c++ int 145 - array container class/main.cpp <==
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	array<int, 3> newArray = { 1, 2, 3 }; //== int newArray[3]
	typedef array<int, 3>::iterator it;
	it iter;

	for (int i = 0; i < newArray.size(); i++) {
		cout << newArray[i] << endl;
	}

	for (iter = newArray.begin(); iter != newArray.end(); iter++) {
		cout << *iter << " ";
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 145 type casting/c++ int 145 type casting/main.cpp <==
#include <iostream> 

using namespace std;

class Parent {
protected:
	int x, y;
public:
	void setPosition(int x, int y) { this->x = x; this->y = y; }
	void Display() { cout << x << " " << y << endl; }
};

class Child : public Parent {};

class Stranger {};

void displayMessage(char *message) {
	cout << message << endl;
}

int main() {
	float floatVariable = 2.4f;

	int inVariable = floatVariable; //works, 
	int intVariable1 = (int)floatVariable; //c- style cast 
	int intVariable2 = static_cast<int>(floatVariable); //static cast does same kind of cast as the old c-style cast, but in a more type-safe way - does not error check before converting like dynamic cast

	int cstylecast = NULL;
	int staticcast = NULL;
	int dynamiccast = NULL;
	int reinterpretcast = NULL;
	int constcast = NULL;

	Child c1, *c2;
	Parent *p;
	Stranger *s;

	//system("tree");
	//system("dir");
	system("ping");

	if (dynamiccast) {
		//dynamic cast converts child to parent but not other way round, unless parent class is polymorphic
		p = dynamic_cast<Parent*>(&c1); //when wanting to converted class to pointer or referenced inheritance class, will check for compatibility 
	}

	if (staticcast) {
		c2 = static_cast<Child*>(p); //static cast can convert parent to child class 
	}

	if (reinterpretcast) {
		//reinterpret_cast is possibly least safe way to cast, converts any pointer type into any other pointer type, no necessity of relationship, inheritance, etc. between two classes, copies bytes from one class to another
		p = reinterpret_cast<Parent*>(s);
	}
	
	const char *message = "yo";
	if (cstylecast) {
		displayMessage((char*)message); //will not always work
	}
	if (constcast){
		displayMessage(const_cast<char*>(message)); //most type safe way to cast const type, removes 'constness' from pointer
	}

	return 0;
}
==> ./Projects/c++ int 146 extern, inline/c++ int 146 extern, inline/Class.cpp <==
#include "Class.h"



Class::Class()
{
}


Class::~Class()
{
}

void Class::ChangeScore(int value) {
	score = value;
}

void Class::DisplayScore() const {
	cout << "Score: " << score << endl;
}

int Class::Count() {
	static int count1;
	return ++count1;
}
==> ./Projects/c++ int 146 extern, inline/c++ int 146 extern, inline/Class.h <==
#include <iostream>

using namespace std;

extern unsigned short score; //extern keyword is used to get global variables which will be used througout the entire program scope

class Class
{
public:
	Class();
	~Class();

	void DisplayScore() const;
	void ChangeScore(int value);

	static int Count(); // non-static type class member variables cannot be used inside of a static type function
};


==> ./Projects/c++ int 146 extern, inline/c++ int 146 extern, inline/main.cpp <==
#include <iostream>
#include "Class.h"

using namespace std;

unsigned short score = 10; //extern keyword is used to get global variables which will be used througout the entire program scope

short Count() {
	static short count = 0; //static variables can only be initialised once
	return ++count;
}

inline void Function() { 
	//inline tells compiller to replace function call in main window with function boody, preventing the double call. is handled automatically by c++ compilers nowadays, and any call to inline is taken by compiler as a 'suggestion'
	//inline cannot be used with function definitions, if inline is used the body of the function must be supplied there and then.
	cout << "Test function" << endl;
}

int main() {
	cout << "oscore: " << score << endl;
	Class testClass;

	testClass.ChangeScore(20);
	testClass.DisplayScore();
	cout << "nscore: " << score << endl;

	for (int i = 0; i < 7; i++) {
		cout << Count() << endl;
	}
	
	for (int i = 0; i < 5; i++) {
		cout << Class::Count() << " "; // can be called with no instance of program
	}
	cout << endl;

	cout << testClass.Count() << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int 18 - print triangle/c++ int 18 - print triangle/main.cpp <==
#include <iostream>
#include <stdexcept>

using namespace std;

void printTriangle(int, int);

int main() {
	int lines, blanks = 30;
	do {
		cout << "Enter lines to be printed : ";
		cin.exceptions(ios_base::failbit);
		try {
			cin >> lines;
		}
		catch (exception e) {
			cout << "\nYou did not enter an integer value\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		if ((lines < 1) || (lines > 20))
			cout << "Number should be between 1 and 20.\n";
	} while ((lines < 1) || (lines > 20));
	cout << "\n\n";

	for (int count = 1; count <= lines; count++) {
		printTriangle(blanks, count);
		blanks--;
	}
	return 0;
}

void printTriangle(int blanks, int stars) {
	int count;
	for (count = 1; count <= blanks; count++) {
		cout << " ";
	}for (count = 1; count <= stars; count++) {
		cout << " *";
	}
	cout << endl;
}
==> ./Projects/c++ int 24 static + automatic variables/c++ int 24 static + automatic variables/main.cpp <==
#include <iostream>

using namespace std;

void func0();
void func1(int);
void func2(static int);
static int z = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		func0();
		func1(z);
		func2(z);
	}
	cout << "Inside main(), z : " << z << "\n\n";
	return 0;
}

void func0(){
	static int x = 0;
	x = x + 2;
	cout << "x : " << x << endl;
}

void func1(int z) {
	z++;
	cout << "Inside func1, z : " << z << endl;
}

void func2(static int z) {
	z = z + 2;
	cout << "Inside func2, z : " << z << endl;
}
==> ./Projects/C++ int 26 - rock, paper scissors/C++ int 26 - rock, paper scissors/main.cpp <==
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

enum class object{ ROCK, PAPER, SCISSORS };

void displayRules();
object getPlay();
void play(int&, int&, int&);
object AI();
object determineWinner(object, object);
void print(int, int, int);

int main() {
	int menuChoice = 0, p1Wins = 0, p2Wins = 0, tie = 0;

	while (menuChoice != 4){
		do {
			cout << "ROCK - PAPER - SCISSORS " << endl;
			cout << "\nTo see the rules - enter 1" << endl;
			cout << "To play the game - enter 2" << endl;
			cout << "To display results, enter 3" << endl;
			cout << "To exit, enter 4" << endl;
			cin.exceptions(ios_base::failbit);
			try {
				cin >> menuChoice;
			}
			catch (exception e) {
				cout << "You did not enter a valid integer\n";
				cin.clear();
				cin.ignore(100, '\n');
				menuChoice = 0;
			}
		} while ((menuChoice < 1) || (menuChoice > 4));
		//cin.clear();
		//cin.ignore(100, '\n');
		switch (menuChoice) {
		case 1: displayRules(); break;
		case 2: play(p1Wins, p2Wins, tie); break;
		case 3: print(p1Wins, p2Wins, tie); break;
		case 4: cout << "\nThank you for playing!\n\n"; break;
		default: break;
		}
	} 

	return 0;
}

void displayRules(){
	cout << "Nahh...\n\n";
}

object getPlay() {
	object p1;
	char ch;
	bool isValid = false;
	cout << "Enter R for rock, S for scissors, P for paper : ";
	do {
		cin >> ch;
		switch (ch){
			case 'R':
			case 'r': isValid = true; p1 = object::ROCK; break;
			case 'S':
			case 's': isValid = true; p1 = object::SCISSORS; break;
			case 'P':
			case 'p': isValid = true; p1 = object::PAPER; break;
		}
		cin.clear();
		cin.ignore(100, '\n');
	} while (isValid == false);
	return p1;
}

void play(int &win1, int &win2, int &tie) {
	object player1, player2, winner;
	bool isWon = false;
		cout << "Player one" << endl;
		player1 = getPlay();
		switch (player1) {
		case object::ROCK: cout << "Rock\n"; break;
		case object::PAPER: cout << "Paper\n"; break;
		case object::SCISSORS: cout << "Scissors\n"; break;
		}
		cout << "Computer chooses ";
		player2 = AI();
		cout << endl;
		winner = determineWinner(player1, player2);
		if (player1 == player2) {
			cout << "Game is a tie\n";
			tie++;
		}
		else if (winner == player1) {
			cout << "Player 1 wins!\n";
			win1++; cout << "win1 : " << win1;
		}
		else if (winner == player2) {
			cout << "Computer wins!\n";
			win2++; cout << "win2 : " << win2;
		}
		isWon = true;
}

object AI() {
	object p2;
	int num;
	bool isValid = false;
	num = (rand() + time(0)) % 3 + 1;
		switch (num) {
		case 1: cout << "rock\n"; 
			p2 = object::ROCK; isValid = true; break;
		case 2: cout << "scissors\n"; 
			p2 = object::SCISSORS; isValid = true; break;
		case 3: cout << "paper\n"; 
			p2 = object::PAPER; isValid = true; break;
		}
	return p2;
}

object determineWinner(object p1, object p2) {
	if (((p1 == object::ROCK) && (p2 == object::SCISSORS)) ||
		((p2 == object::ROCK) && (p1 == object::SCISSORS))) {
		return object::ROCK;
	}
	if (((p1 == object::ROCK) && (p2 == object::PAPER)) ||
		((p2 == object::ROCK) && (p1 == object::PAPER))) {
		return object::PAPER;
	}
	else {
		return object::SCISSORS;
	}
}

void print(int p1, int p2, int tie) {
	cout << "Player 1 has won " << p1 << " games\n" <<
		"Computer has won " << p2 << " games\n" <<
		"Number of games tied : " << tie << "\n" <<
		"Total number of games : " << p1 + p2 + tie << "\n\n";
}
==> ./Projects/c++ int 27 - using namespaces/c++ int 27 - using namespaces/mian.cpp <==
#include <iostream>
#include "namespace1.cpp"

using namespace std;
//if wasn't declared an only access functions like cout by using 
//std::cout and std::cin

int main() {
	one::x = 6;
	y = 'n';

	using namespace one;
	y = 'a';
	x = 4;

	return 0;
}
==> ./Projects/c++ int 27 - using namespaces/c++ int 27 - using namespaces/namespace1.cpp <==
namespace one {
	int x;
	char y;
}
==> ./Projects/C++ int 30 - string functions/C++ int 30 - string functions/main.cpp <==
#include <iostream>
#include <string>

using namespace std;

int main() {
	int position;
	string str1 = "It is hot and humid outside today";
	cout << "str1 = " << str1 << endl;
	position = str1.find("hot");
	cout << "Position of \"hot\" is " << position << endl;
	cout << "substr(0,5) = " << str1.substr(0, 5) << endl;
	//.substr(starting pos, no. of characters) 
	
	string str2 = "cloudy", str3 = "warm";
	str2.swap(str3);
	cout << "str2 = " << str2 << " str3 = " << str3 << endl;
	//if specifying substr to swap out must use .replace()
	str1.replace(6, 3, str2); //starting position, number of characters
	cout << "str1 = " << str1 << endl;
	return 0;
}
==> ./Projects/c++ int 33 - pig latin string program/c++ int 33 - pig latin string program/main.cpp <==
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char);
string rotate(string);
string plString(string);

int main() {
	string str;
	cout << "Enter a string : ";
	cin >> str;
	cout << endl << str << " in pig latin " << plString(str) << endl;
	return 0;
}

bool isVowel(char ch) {
	bool isT;
	switch (ch) {
	case 'a':
	case 'e':
	case 'o':
	case 'i':
	case 'u':
	case 'y':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y': return true;
	default: return false;
	}
}

string rotate(string str) {
	string::size_type len = str.length();
	string str1;
	str1 = str.substr(1, len - 1) + str[0];
	return str1;
}

string plString(string str) {
	string::size_type len;
	bool vowel;
	int counter;
	if (isVowel(str[0])) {
		str = str + "-way";
	}
	else {
		str = str + "-";
		str = rotate(str);
		len = str.length();
		vowel = false;
		for (counter = 1; counter < len - 1; counter++) {
			if (isVowel(str[0])) {
				vowel = true;
				break;
			}
			else {
				str = rotate(str);
			}
		}
		if (!vowel) {
			str = str.substr(1, len) + "-way";
		}
		else {
			str = str + "ay";
		}	
	}
	return str;
}
==> ./Projects/c++ int 36 c strings/c++ int 36 c strings/main.cpp <==
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	char ch = '\0'; // null character - ASCII code 0
	//"Jack M White"
	//"Hello World" - both statements null-terminated by default
// 'A' "A" - second statement is two characters, first + null character

	char name[16];
//char array is not necessarily a C string, C strings are null-terminated
//if initialised with chars may not be null-terminated
	char name1[16] = { 'J', 'o', 's', 'e', 'p', 'h', '\0' };
	//name1 is equivalent to a C-string (below)
	//char name1[16] = "Joseph";
	//char name[] = "Joseph"; both produce C-strings

	//illegal operation
	/*
	char name2[26];
	name2 = "Jack"; 
	would have to be initialised like normal array or use functions*/

	char yourName[26];
	char myName[16];
	char newName[16];
	int len;
	strcpy(myName, "Joseph Tomlin");
	len = strlen(myName);
	cout << myName << " is length " << len << endl;

	//reading and writing strings
	/*
	char example1[31];
	cin >> example1; - 
	input will terminate after first space, if more than 30 characters
	are input, wil be stored in memory addresses subsequent to the array
	in the form of corrupted data. and can cause program malfunction
	
	cin.get(example, m+1) -
	will get all characters for length of m (+1 for null termination)
	or until a newline character is hit
	*/

	cout << "Please enter your name : ";
	cin.get(yourName, 26);
	cout << endl << yourName << endl;

	ifstream infile;
	string filename;
	cout << "Please enter file name. include file extension: ";
	cin >> filename;
	cout << endl;
	infile.open(filename.c_str());
	//string variables must be converter to c-strings via func .c_str()
	//found under <cstring> header file - adds null character
	infile.close();

	char filename2[51];
	cout << "Please enter file name. include file extension: ";
	cin >> filename;
	cout << endl;
	infile.open(filename2); 
	//already null-terminated, no need for conversion function
	infile.close();

	return 0;
}
==> ./Projects/C++ int 38 - line letter count program/C++ int 38 - line letter count program/main.cpp <==
#include <iostream>
#include <fstream>
#include <cctype> //needed for tolower() and toupper() funstions

using namespace std;

void initialise(int&, int[]);
void copyText(ifstream&, ofstream&, char&, int[]);
void count(char&, int[]);
void print(ofstream&, int, int[]);

int main() {
	int line;
	int letter[26];
	char ch;
	ifstream infile;
	ofstream outfile;
	infile.open("inData.txt");
	outfile.open("outData.txt");
	initialise(line, letter);
	infile.get(ch);
	while (infile) {
		copyText(infile, outfile, ch, letter);
		line++;
		infile.get(ch);
	}
	print(outfile, line, letter);
	infile.close();
	outfile.close();

	return 0;
}

void initialise(int& loc, int list[]) {
	loc = 0;
	for (int i = 0; i < 26; i++) {
		list[i] = 0;
	}
}

void copyText(ifstream& in, ofstream& out, char& ch, int list[]) {
	while (ch != '\n') {
		count(ch, list);
		cout << ch;
		in.get(ch);
	}
	out << ch;
}

void count(char& ch, int list[]) {
	ch = toupper(ch);
	int index = static_cast<int>(ch) - static_cast<int>('A');
	if ((0 <= index) && (index > 26)) {
		list[index]++;
	}
}

void print(ofstream &out, int loc, int list[]) {
	out << endl << endl;
	out << "The number of lines = " << loc << endl;
	for (int i = 0; i < 26; i++) {
		out << static_cast<char>(i + static_cast<int>('A'))
			<< " count = " << list[i] << endl;
	}
}
==> ./Projects/c++ int 39 struct/c++ int 39 struct/main.cpp <==
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct employee {
	string firstName;
	string lastName;
	string address1;
	string address2;
	double salary;
	string empID;
};

string inputFileName();
ifstream openFile();
vector<employee> copyRecords();

int main() {
	vector<employee> employeesR = copyRecords();
	return 0;
}

vector<employee> copyRecords() {
	ifstream ifile = openFile();
	string line;
	vector<employee> employees;
	int employeeCount = 0;

	while (getline(ifile, line)) {
		line = line + ",";
		cout << line << endl;
		employee newEmployee;
		int len = line.length();
		int ib = 0;
		int ic = 0;
		int a = 0;
		for (int ia = 0; ia < len; ia++) {
			if (a < 1) {
				switch (line[ia]) {
				case ' ':
					cout << line.substr(ib, ia - ib) << endl;
					newEmployee.firstName = line.substr(ib, ia - ib);
					a++;
					ib = ia + 1;
					break;
				}
			}
			else if (a == 1) {
				switch (line[ia]) {
				case ',':
					cout << line.substr(ib, ia - ib) << endl;
					newEmployee.lastName = line.substr(ib, ia - ib - 1);
					a++;
					ib = ia + 2;
					break;
				}
			}
			else if (a == 2) {
				switch (line[ia]) {
				case ',':
					if ((line[ib] > '9') && (line[ic] > '9')) {
						ic = ia + 2;
					}
					else if ((line[ic] <= '9') && (line[ic] >= '0')) {
						cout << line.substr(ib, ia - ib - 1);
						newEmployee.address1 = line.substr(ib, ia - ib - 1);
						ib = ia + 2;
						a++;
					}
					else if ((line[ib] <= '9') && (line[ib] >= '0')) {
						cout << line.substr(ib, ia - ib) << endl;
						newEmployee.address1 = line.substr(ib, ia - ib - 1);
						ib = ia + 2;
						a++;
					}
				}
			}
			else if (a == 3) {
				switch (line[ia]) {
				case ',':
					ic = ia + 2;
					if ((line[ic] >= '0') && (line[ic] <= '9')) {
						cout << line.substr(ib, ia - ib) << endl;
						newEmployee.address2 = line.substr(ib, ia - ib - 1);
						ib = ia + 2;
						a++;
					}
				}
			}
			else if (a == 4) {
				if (line[ia] == ',') {
					string temp;
					cout << line.substr(ib, ia - ib) << endl;
					temp = line.substr(ib, ia - ib);
					newEmployee.salary = stod(temp);
					ib = ia + 2;
					a++;
				}
			}
			else if (a == 5) {
				if (line[ia] == ',') {
					cout << line.substr(ib, ia - ib) << endl;
					newEmployee.empID = line.substr(ib, ia - ib);
					a++;
				}
			}
		}
		employees.push_back(newEmployee);
	}
	return employees;
}

ifstream openFile() {
	ifstream infile;
	do {
		infile.open(inputFileName().c_str());
		if (!infile.is_open()) {
			cout << "No file detected, please input filename again\n";
		}
	} while (!infile.is_open());
	return infile;
}

string inputFileName() {
	string filename;
	int len;
	do {
		cout << "Please enter filename including directory path and file extension" << endl;
		cout << "i.e. \"c:/windows/example.txt\"" << endl;
		cout << "\nFilename : ";
		cin >> filename;
		cout << endl;
		len = filename.length();
		if (len < 5) {
			cout << "-Filename is too short-\n\n";
		}
		else if (filename.substr(len - 4, 4) != ".txt") {
			cout << "-File extension is incorrect-\n\n";
		}
	} while ((len < 5) ||
		(filename.substr(len - 4, 4) != ".txt"));

	return filename;
}
==> ./Projects/c++ int 58 pointer arithmetic/c++ int 58 pointer arithmetic/main.cpp <==
#include <iostream>

using namespace std;

void test1(int *&x, int *y);
int* test2();

int main() {
	int *p, x; //x is normal int
	double *q, y; //y is normal double

	p = &x;
	q = &y;

	//adding intger values to a pointer variable incrementing the memory
	//allocated to the pointer by an amount equal to the integer value
	//multiplied by the size of the variable i.e.

	p++; // size increase of 4 bytes
	q = q + 2; //size increase of 16 bytes (8 * 2 bytes)

	return 0;
}

void test1(int *&x, int *y) {

}

int* test2() {
	int x = 6;
	return &x;
}
==> ./Projects/c++ int 61 - two-dimensional arrays/c++ int 61 - two-dimensional arrays/main.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

void fill(int**, int, int);
void print(int**, int, int);

int main() {
	int **p;

	int a = 0;
	p = new int*[10];
	for (int i = 0; i < 10; i++) {
		p[i] = new int[10];
		for (int j = 0; j < 10; j++) {
			p[i][j] = ++a;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << setw(4) << p[i][j];
		}
		cout << endl;
	}

	delete[] *p;
	cout << endl;
	fill(p, 3, 4);
	print(p, 3, 4);

	return 0;
}

void fill(int** a, int rows, int cols) {
	int b = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			a[i][j] = ++b;
		}
	}
}

void print(int** a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
}
==> ./Projects/c++ int 62, shallow vs. deep copy/c++ int 62, shallow vs. deep copy/main.cpp <==
#include <iostream>

using namespace std;

int main() {
	int *x, *y, *z;

	x = new int[10];
	for (int i = 0; i < 10; i++) {
		x[i] = i;
	}
	
	y = x;
	//shallow copy, y points to same memory location as x. if x is deleted
	//y will also be deleted, and if y is deleted x will also be deleted

	z = new int[10];
	for (int i = 0; i < 10; i++) {
		z[i] = x[i];
	}
	//deep copy, if either z or x is deleted the other array will remain 

	delete[] x;

	cout << "\ny array : ";
	for (int i = 0; i < 10; i++) {
		cout << y[i] << " ";
	} //y is deleted
	cout << "\nz array : ";
	for (int i = 0; i < 10; i++) {
		 cout << z[i]<< " ";
	} //z is intact
	return 0;
}
==> ./Projects/c++ int 62, shallow vs. deep copy/c++ int 71 - address operator and classes/c++ int 71 - address operator and classes/main.cpp <==
#include <iostream>
#include "Test.h"

using namespace std;

int main() {
	int x = 6;
	int &y = x; //memory address of x stored in y;

	cout << "After changing y, x is " << x << endl;

	x = 7;
	cout << "After changing x, y is " << y << endl;

	Test subject;

	int &a = subject.getAdd();
	a++;
	cout << "After modiying int a, private member variable ";
	subject.print();

	return 0;
}


==> ./Projects/c++ int 62, shallow vs. deep copy/c++ int 71 - address operator and classes/c++ int 71 - address operator and classes/Test.cpp <==

==> ./Projects/c++ int 62, shallow vs. deep copy/c++ int 71 - address operator and classes/c++ int 71 - address operator and classes/Test.h <==
#ifndef TEST_H
#define TEST_H
#include <iostream>

using namespace std;

class Test {
	int x;
public:
	Test() {
		x = 50;
	}
	void print() const {
		cout << "x = " << x << endl;
	}

	//private member variable can be accessed and changed outside of class
	//as memory address is returned
	int& getAdd(){
		return x;
	}

	//const modifier will prevent use of memory address to alter private
	//member variable

	const int& getAdd1() const{
		return x;
	}
};

#endif // !TEST_H

==> ./Projects/c++ int 63 - pointers and destructors/c++ int 63 - pointers and destructors/main.cpp <==
#include <iostream>
#include <iomanip>

using namespace std;

class pointerDemo {
	int* p = new int[10];
	int*** x = new int **[5];
public:
	pointerDemo() {
		int a = 0;
		for (int i = 0; i < 5; i++) {
			x[i] = new int*[4];
			for (int j = 0; j < 4; j++) {
				x[i][j] = new int[3];
				for (int k = 0; k < 3; k++) {
					x[i][j][k] = ++a;
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					cout << setw(3) << x[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	~pointerDemo() {
		delete[] p;
		delete[] **x;
		//memory would not be deallocated if no custom destructor
	}
};

int main() {
	pointerDemo xer;
	

	return 0;
}
==> ./Projects/c++ int 65 - copy constructor/c++ int 65 - copy constructor/main.cpp <==
/*To prevent shallow copies, default copy constructor must be overridden. 

The copy constructor automatically executes in three situations

1. When an object is declared and initialized by using the value of 
another object
2. When as a parameter an object is passed by value (i.e. into a function)
3. When the return value of a function is an object
*/

#include <iostream>
#include "pointerDataClass.h"

using namespace std;

void testCopy(pointerDataClass);

int main() {
	pointerDataClass *obj1, *obj3;
	obj1 = new pointerDataClass();

	pointerDataClass obj2(6);

	int i = 0;
	for (i = 0; i < 5; i++) {
		obj1->insertAt(i, i);
		obj2.insertAt(i, i+5);
	}
	cout << "obj1 : ";
	obj1->print();
	cout << endl << "obj2 : ";
	obj2.print();

	obj3 = new pointerDataClass(*obj1);
	delete obj1;
	cout << endl << "obj3 : ";
	obj3->print();
	obj1 = new pointerDataClass(obj2);
	cout << endl << "obj1 : ";
	obj1->print();
	delete obj1;
	delete obj3;
	cout << endl;
	return 0;
}

void testCopy(pointerDataClass temp) {
	temp.print();
	cout << endl << endl;
	temp.insertAt(3, -100);
	temp.print();
	cout << endl;
}
==> ./Projects/c++ int 65 - copy constructor/c++ int 65 - copy constructor/pointerDataClass.cpp <==
#include "pointerDataClass.h"
#include <iostream>
#include <cassert> //for assert statement

using namespace std;

pointerDataClass::pointerDataClass(int size) {
	if (size <= 0) {
		cout << "Array size must be a positive number\n";
		cout << "Setting default size to 10\n";
		maxSize = 10;
	}
	else {
		maxSize = size;
	}
	length = 0;
	p = new int[maxSize];
}

pointerDataClass::~pointerDataClass() {
	delete[] p;
}

pointerDataClass::pointerDataClass(const pointerDataClass& other) {
	maxSize = other.maxSize;
	length = other.length;
	p = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		p[i] = other.p[i]; //deep copying
	}
}

void pointerDataClass::insertAt(int index, int num) {
	assert(index >= 0 && index < maxSize);
//can be used with if statement, but assert statement serves same use
	if (index < length) {
		p[index] = num;
	}
	else {
		p[length] = num;
		length++;
	}
}

void pointerDataClass::print() const {
	for (int i = 0; i < length; i++) {
		cout << p[i] << " ";
	}
}

int pointerDataClass::getMaxSize() const {
	return maxSize;
}
==> ./Projects/c++ int 65 - copy constructor/c++ int 65 - copy constructor/pointerDataClass.h <==
#ifndef POINTER_H
#define POINTER_H

#include <iostream>

using namespace std;

class pointerDataClass {
	int maxSize, length, *p;
public:
	pointerDataClass(int size = 10); //constructor - default size
	~pointerDataClass(); //destructor
	pointerDataClass(const pointerDataClass&); //copy constructor
	void print() const;
	void insertAt(int, int);
	int getMaxSize() const;
};

#endif
==> ./Projects/c++ int 66 - virtual functions + pointers/c++ int 66 - virtual functions + pointers/main.cpp <==
#include <iostream>

using namespace std;

class BaseClass {
	int x;
public:
	BaseClass(int u = 0) { //makes default value if no value passed in
		x = u;
	}
	virtual void print() const {
		cout << "Base class .print() function\n";
		cout << "x = " << x << endl;
	}

	int setX() {
		cout x
	}
};

class DerivedClass : public BaseClass {
	int y;
public:
	DerivedClass(int u = 0, int v = 0) : BaseClass(u){
		y = v;
	}
	virtual void print() const {
		cout << "Derived class .print() function\n";
		cout << "y = " << y << endl;
		BaseClass::print();
	}
};

void callPrint(BaseClass &);
void callPrint(BaseClass *);
void callPrint1(BaseClass);

int main() {
	BaseClass obj1(5);
	obj1.print();
	cout << endl;
	DerivedClass obj2(3, 15);
	obj2.print();
	cout << endl;
	callPrint(obj1);
	cout << endl;
	callPrint(obj2);
	cout << endl;

	BaseClass *ptr1;
	DerivedClass *ptr2 = new DerivedClass(obj2);
	ptr1 = new BaseClass(obj1);

	ptr1->print();
	cout << endl;
	ptr2->print();

	callPrint(ptr1);
	callPrint(ptr2);

	callPrint1(*ptr2);
	callPrint1(obj2);
	/*As the callPrint1 function takes a parameter passed by value
	the dynamic variable created only has the member variables and
	functions of a base class object, so it's print will only print
	BaseClass variables regardless of whether the object passed in is
	a derived class object or not*/

	return 0;
}

void callPrint(BaseClass &obj) {
	obj.print();
} //static binding called by compiler, without virtual function will call
//base class function, generated by compiler. virtual function uses 
//run-time binding generated at execution time aka "dynamic binding".  

//Pointer overload
void callPrint(BaseClass *ptr) {
	cout << "\nPointer print\n\n";
	ptr->print();
}

void callPrint1(BaseClass bcl) {
	cout << "\nPass by value print\n\n";
	bcl.print();
}
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/EmployeeType.cpp <==
#include "EmployeeType.h"


EmployeeType::EmployeeType(string fname, string lname, int _ID) 
	: PersonType(fname, lname){
	ID = _ID;
}

int EmployeeType::getID() const {
	return ID;
}

void EmployeeType::setID(int _ID) {
	ID = _ID;
}


==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/EmployeeType.h <==
#ifndef EMPLOYEETYPE_H
#define EMPLOYEETYPE_H
#include <iostream>
#include <string>
#include "PersonType.h"

using namespace std;

class EmployeeType : public PersonType {
	int ID;
public:
	EmployeeType(string fname = "noname", string lname = "noname", 
		int _ID = 0);
	int getID() const;
	void setID(int);

	//pure virtual functions made by making function equiv to 0. does not
	//need to be defined in base class (abstract class), but needs to be 
	//overloaded in every class derived from base class
	virtual double calculatePay() const = 0;
	virtual void print() const = 0;
};

#endif
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/FullTimeEmployee.cpp <==
#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(string fname, string lname, int _ID,
	double _salary, double _bonus) : EmployeeType(fname, lname, _ID) {
	salary = _salary;
	bonus = _bonus;
}

double FullTimeEmployee::getBonus() const {
	return bonus;
}

double FullTimeEmployee::getSalary() const {
	return salary;
}

double FullTimeEmployee::calculatePay() const {
	return (salary + bonus);
}

void FullTimeEmployee::setBonus(double ibonus) {
	bonus = ibonus;
}

void FullTimeEmployee::setSalary(double isalary) {
	salary = isalary;
}

void FullTimeEmployee::print() const {
	cout << setw(10) << "ID: " << getID() << endl;
	cout << setw(10) << "Name: " << getFName() << " " << getLName() << endl;
	cout << setw(10) << "Wages: " << (char)156 << calculatePay() << endl;
}

void FullTimeEmployee::set(string fname, string lname, int iId,
	double isalary, double ibonus) {
	setName(fname, lname);
	setID(iId);
	salary = isalary;
	bonus = ibonus;
}
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/FullTimeEmployee.h <==
#ifndef FULLTIME_H
#define FULLTIME_H
#include <iostream>
#include <string>
#include <iomanip>
#include "EmployeeType.h"
#include "PersonType.h"

using namespace std;

class FullTimeEmployee : public EmployeeType {
	double salary;
	double bonus;
public:
	FullTimeEmployee(string fname = "noname", string lname = "noname",
		int _ID = 0, double _salary = 0, double _bonus = 0);
	double getSalary() const;
	void setSalary(double);
	double getBonus() const;
	void setBonus(double);
	double calculatePay() const;
	void print() const;
	void set(string, string, int, double, double);
};

#endif
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/Header.h <==
#pragma once

==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/main.cpp <==
#include <iostream>
#include <iomanip>
#include <string>
#include "PersonType.h"
#include "EmployeeType.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

int main() {
	FullTimeEmployee ft1("John", "Doe", 7648, 65000, 13000);
	PartTimeEmployee pt1("James", "Dean", 9648, 25.0, 2000);

	ft1.print();
	pt1.print();

	

	return 0;
}
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/PartTimeEmployee.cpp <==
#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(string fname, string lname, int iID,
	double iHours, double iRate) : EmployeeType(fname, lname, iID) {
	hoursWorked = iHours;
	payRate = iRate;
}

void PartTimeEmployee::setHours(double iHours) {
	hoursWorked = iHours;
}

void PartTimeEmployee::setRate(double iRate) {
	payRate = iRate;
}

double PartTimeEmployee::getHours() const {
	return hoursWorked;
}

double PartTimeEmployee::getRate() const {
	return payRate;
}

double PartTimeEmployee::calculatePay() const {
	return hoursWorked * payRate;
}

void PartTimeEmployee::print() const {
	cout << setw(10) << "ID: " << getID() << endl;
	cout << setw(10) << "Name: " << getFName() << " " << getLName() << endl;
	cout << setw(10) << "Wages: " << (char)156 << calculatePay() << endl;
}
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/PartTimeEmployee.h <==
#ifndef PARTTIME_H
#define PARTTIME_H
#include <iostream>
#include <string>
#include <iomanip>
#include "EmployeeType.h"
#include "PersonType.h"

using namespace std;

class PartTimeEmployee : public EmployeeType {
	double hoursWorked;
	double payRate;
public:
	PartTimeEmployee(string fname = "noname", string lname = "noname",
		int _ID = 0, double hoursWorked = 0.0, double payRate = 0.0);
	double getHours() const;
	void setHours(double);
	double getRate() const;
	void setRate(double);
	double calculatePay() const;
	void print() const;
};

#endif
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/PersonType.cpp <==
#include "PersonType.h"
#include <iostream>

using namespace std;

PersonType::PersonType(string fname, string lname) {
	firstName = fname;
	lastName = lname;
}

string PersonType::getFName() const {
	return firstName;
}

string PersonType::getLName() const {
	return lastName;
}

void PersonType::setName(string fname, string lname) {
	firstName = fname;
	lastName = lname;
}

void PersonType::print() const {
	cout << firstName << " " << lastName << endl;
}
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 67 - pure virtual functions/PersonType.h <==
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>

using namespace std;

class PersonType {
	string firstName;
	string lastName;
public:
	PersonType(string fname = "noname", string lname = "noname");
	string getFName() const;
	string getLName() const;
	void setName(string, string);
	virtual void print() const;
};


#endif 
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 74 friend functions/c++ int 74 friend functions/Friendtest.h <==
#ifndef FRIENDTEST_H
#define FRIENDTEST_H
#include <iostream>

using namespace std;

class FriendTest {
	int x;
public: 
	void print() {
		cout << "x is " << x << endl;
	}
	void setX(int u) {
		x = u;
	}
	friend void testFriend(FriendTest &); 
//for friend function, function declaration must be inside of the class
//friend keyword is used here, function body can be used outside of class
};



#endif
==> ./Projects/c++ int 67 - pure virtual functions/c++ int 74 friend functions/c++ int 74 friend functions/main.cpp <==
#include <iostream>
#include "Friendtest.h"

using namespace std;

int main() {
	FriendTest fun;
	testFriend(fun);

	return 0;
}

//private member variables of any object the friend function is a friend
//to can be accessed directly inside of the friend function
void testFriend(FriendTest &fun1) {
	FriendTest nofun;
	nofun.x = 6;
	nofun.print();
	nofun.setX(8);
	cout << "x is now " << nofun.x << "\n\n";

	fun1.x = 70;
	fun1.print();
	fun1.setX(64);
	cout << "x is now " << fun1.x << "\n\n";
}
==> ./Projects/c++ int 68 - Array based lists/c++ int 68 - Array based lists/main.cpp <==
/*Operations to perform on lists

1. Create the list. The list is initialized to empty state
2. Determine whether the list is empty
3. Determine whether the list is full
4. Find the size of the list
5. Destroy or clear the list
6. Determine whether an item is the same as a list element
7. Insert an item in the list at a specified location
8. Remove an item 


*/


#include <iostream>

using namespace std;

int main() {

	return 0;
}

==> ./Projects/c++ int 75 operator overloading/c++ int 75 operator overloading/main.cpp <==
/*Function which overloads (), ->, [], =, for a class must be a member
of the class

if the left hand operand of an operator is an object of a different type
i.e. Cat + Dog, function which overloads the operator must be a non-member

if the function which overloads an operator is the member of a class, 
left-hand operand of the operator must be of that class type
*/

#include <iostream>
#include <cassert>
#include <iomanip>
#include "RectangleType.h"

using namespace std;

int main() {
	RectangleType r1(5,6);
	RectangleType r2(3,4);
	RectangleType r3(2,2);
	RectangleType *r4;
	r4 = new RectangleType(r2 + r3);
	//r2 + r3 == r2.operator+(r3)
	r1.print();
	if (*r4 == r1) { //*r4.operator==(r1)
		cout << "All is well\n";
	}
	else {
		cout << "All is lost!\n";
	}
	if (*r4 != r2) {
		cout << "Like!\n";
	}
	else {
		cout << "Dislike!!!\n";
	}
	delete r4;
	r4 = new RectangleType(r3 * r3);
	r4->print();
	delete r4;
	r4 = new RectangleType();
	cout << "r4: " << *r4 << endl;
	cout << "Please enter new length and width: ";
	cin >> *r4;
	cout << "\nr4: " << *r4 << endl;
	delete r4;
	cout << "r3 + r2 : " << r3 + r2 << endl;
	cout << "r3 + r2 : " << r3 * r2 << endl;
	cout << r3--; //cout.operator<<(r3.operator--())
	cout << r3;
	cout << --r2; //cout.operator<<(r2.operator--(r2))
	return 0;
}
==> ./Projects/c++ int 75 operator overloading/c++ int 75 operator overloading/RectangleType.cpp <==
#include <iostream>
#include <cassert>
#include "RectangleType.h"

using namespace std;

RectangleType::RectangleType() {
}

RectangleType::RectangleType(double ilength, double iwidth) {
	assert((ilength >= 1) && (iwidth >= 1)); 
		length = ilength;
		width = iwidth;
}

double RectangleType::getWidth() const {
	return width;
}

double RectangleType::getLength() const {
	return length;
}

double RectangleType::getArea() const {
	return length * width;
}

double RectangleType::getPerimeter() const {
	return 2 * (length + width);
}

void RectangleType::print() const {
	cout << "Length = " << length << "\nWidth = " << width << endl;
}

RectangleType RectangleType::operator *(const RectangleType &rec) const{
	RectangleType temp;
	temp.length = length * rec.length;
	temp.width = width * rec.width;
	return temp;
}

RectangleType RectangleType::operator +(const RectangleType &rec) const{
	RectangleType temp;
	temp.length = length + rec.length;
	temp.width = width + rec.width;
	return temp;
}

RectangleType RectangleType::operator -(const RectangleType &rec) const {
	RectangleType temp;
	temp.length = length - rec.length;
	temp.width = width - temp.width;
	return temp;
}

RectangleType RectangleType::operator /(const RectangleType &rec) const {
	RectangleType temp;
	temp.length = length / rec.length;
	temp.width = width / rec.width;
	return temp;
}

bool RectangleType::operator==(const RectangleType &rec) const {
	bool temp;
	if ((length == rec.length) && (width == rec.width)) {
		temp = true;
	}
	else {
		temp = false;
	}
	return temp;
}

bool RectangleType::operator!=(const RectangleType &rec) const {
	bool temp;
	if ((length == rec.length) && (width == rec.width)) {
		temp = false;
	}
	else {
		temp = true;
	}
	return temp;
}

bool RectangleType::operator>=(const RectangleType &rec) const {
	if ((length*width) >= (rec.length*rec.width)) {
		return true;
	}
	else {
		return false;
	}
}

bool RectangleType::operator>(const RectangleType &rec) const {
	if ((length*width) > (rec.length*rec.width)) {
		return true;
	}
	else {
		return false;
	}
}

bool RectangleType::operator<=(const RectangleType &rec) const {
	if ((length*width) <= (rec.length*rec.width)) {
		return true;
	}
	else {
		return false;
	}
}

bool RectangleType::operator<(const RectangleType &rec) const {
	if ((length*width) < (rec.length*rec.width)) {
		return true;
	}
	else {
		return false;
	}
}

RectangleType RectangleType::operator++() {
	length++;
	width++;
	return *this;
}

RectangleType RectangleType::operator++(int i) {
	RectangleType temp = *this;
	length++;
	width++;
	return temp;
}

RectangleType RectangleType::operator--() {
	length--;
	width--;
	return *this;
}

RectangleType RectangleType::operator--(int i) {
	RectangleType temp = *this;
	length--;
	width--;
	return temp;
}

ostream& operator<<(ostream &out, const RectangleType &rec) {
	out << "Length = " << rec.length << " Width = " << rec.width << "\n";
	return out;
}

istream& operator>>(istream &in, RectangleType &rec) {
	in >> rec.length >> rec.width;
	return in;
}
==> ./Projects/c++ int 75 operator overloading/c++ int 75 operator overloading/RectangleType.h <==
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <cassert>

using namespace std;

class RectangleType {
	double length = 0, width = 0;
public:
	RectangleType();
	RectangleType(double, double);
	void setDimension(double, double);
	double getLength() const;
	double getWidth() const;
	double getArea() const;
	double getPerimeter() const;
	void print() const;

	RectangleType operator*(const RectangleType&) const;
	RectangleType operator+(const RectangleType&) const;
	RectangleType operator-(const RectangleType&) const;
	RectangleType operator/(const RectangleType&) const;
	bool operator==(const RectangleType&) const;
	bool operator!=(const RectangleType&) const;
	bool operator<=(const RectangleType&) const;
	bool operator>=(const RectangleType&) const;
	bool operator<(const RectangleType&) const;
	bool operator>(const RectangleType&) const;
	RectangleType operator++(); //pre-increment
	RectangleType operator++(int i); //post-increment
	RectangleType operator--(); //pre-increment
	RectangleType operator--(int i); //post-increment
	friend ostream& operator<<(ostream&, const RectangleType&);
	friend istream& operator>>(istream&, RectangleType&);
};

#endif
==> ./Projects/c++ int 77 - assignment operator overload/c++ int 77 - assignment operator overload/ArrayList.cpp <==
#include "ArrayList.h"

ArrayList::ArrayList() {

}

ArrayList::ArrayList(int ilength) {
	length = ilength;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

ArrayList::ArrayList(int ilength, int imaxSize) {
	length = ilength;
	maxSize = imaxSize;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

ArrayList::ArrayList(const ArrayList &rhs) {
	maxSize = rhs.maxSize;
	length = rhs.length;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = rhs.list[i];
	}
}

void ArrayList::print() const {
	cout << "List: ";
	if (!list) {
		cout << "List is empty\n";
	}
	else {
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}

void ArrayList::destroyList() {
	delete[] list;
	list = NULL;
}

void ArrayList::initialiseList() {
	int temp;
	cout << "PLease enter " << length << " numbers:\n";
	for (int i = 0; i < length; i++) {
		cin >> temp;
		list[i] = temp;
	}
}

void ArrayList::addNewMember() {
	if (length < maxSize) {
		cout << "Please enter new member: ";
		cin >> list[length];
		length++;
	}
	else {
		cout << "List is already full\n";
	}
}

bool ArrayList::operator==(const ArrayList& rhs) const {
	bool truther = false;
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] == rhs.list[i]) {
				a++;
			}
		}
	}
	if ((length == rhs.length) && (a == maxSize)) {
		truther = true;
	}
	return truther;
}

bool ArrayList::operator!=(const ArrayList &rhs) const {
	bool truther = false;
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] == rhs.list[i]) {
				a++;
			}
		}
	}
	if ((length == rhs.length) && (a == maxSize)) {
		truther = false;
	}
	else {
		truther = true;
	}
	return truther;
}

const ArrayList& ArrayList::operator=(const ArrayList& rhs)  {
	if (this != &rhs) {
		length = rhs.length;
		maxSize = rhs.maxSize;
		list = new int[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
		return *this;
	}
}

istream& operator>>(istream &in, ArrayList &arl) {
	if (!arl.list) {
		arl.list = new int[arl.maxSize];
	}
	
	for (int i = 0; i < arl.length; i++) {
		in >> arl.list[i];
	}
	return in;
}

ostream& operator<<(ostream& out, ArrayList &arl) {
	if (!arl.list) {
		out << "No list available\n";
	}
	else {
		for (int i = 0; i < arl.length; i++) {
			out << arl.list[i] << " ";
		}
		out << endl;
	}
	return out;
}


==> ./Projects/c++ int 77 - assignment operator overload/c++ int 77 - assignment operator overload/ArrayList.h <==
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
using namespace std;

class ArrayList {
	int maxSize = 10;
	int length;
	int *list;
public:
	ArrayList();
	ArrayList(int);
	ArrayList(int, int);
	ArrayList(const ArrayList&);

	void print() const;
	void initialiseList();
	void addNewMember();
	void destroyList();
	
	friend istream& operator>>(istream&, ArrayList&);
	friend ostream& operator<<(ostream&, ArrayList&);
	bool operator==(const ArrayList&) const;
	bool operator!=(const ArrayList&) const;
	const ArrayList& operator=(const ArrayList&);
};

#endif
==> ./Projects/c++ int 77 - assignment operator overload/c++ int 77 - assignment operator overload/main.cpp <==
#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList al1(5), al2, al3;

	al1.initialiseList();
	
	ArrayList al4(al1);

	al3 = al2 = al1;
	al2.destroyList();
	cout << "al4: ";
    al4.print();
	cout << "al3: ";
	al3.print();
	cout << "al2: ";
	al2.print();
	cout << "al1: ";
	al1.print();

	cout << "new al1: " << al1;
	cout << "\nEnter new numbers for al2 : ";
	cin >> al2;
	cout << "\nal2 new: " << al2;

	return 0;
}
==> ./Projects/c++ int 80 complex number program/c++ int 80 complex number program/ComplexNumber.cpp <==
#include <iostream>
#include <string>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber(){
	realpart = 0;
	imagpart = 0;
}

ComplexNumber::ComplexNumber(double real, double imaginary) {
	realpart = real;
	imagpart = imaginary;
}

ComplexNumber::ComplexNumber(const ComplexNumber &rhs) {
	realpart = rhs.realpart;
	imagpart = rhs.imagpart;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &rhs) const{
	ComplexNumber temp;
	temp.realpart = realpart + rhs.realpart;
	//cout << "temp.realpart = " << temp.realpart << "i\n";
	temp.imagpart = imagpart + rhs.imagpart;
	//cout << "temp.imagpart = " << temp.imagpart << "i\n";
	//cout << temp.realpart << " + " << temp.imagpart << "i" << endl;
	return temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &rhs) const{
	ComplexNumber temp;
	temp.realpart = realpart - rhs.realpart;
	temp.imagpart = imagpart - rhs.imagpart;
	return temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs) const{
	ComplexNumber temp;
	temp.realpart = (realpart*rhs.realpart) - (imagpart*rhs.imagpart);
	temp.imagpart = (realpart*rhs.imagpart) + (imagpart*rhs.realpart);
	return temp;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &rhs) const{
	ComplexNumber compconj[3];
	compconj[0] = ComplexNumber(rhs.realpart, -rhs.imagpart);
	compconj[1] = *this * compconj[0];
	compconj[2] = rhs * compconj[0];

	ComplexNumber temp;
	double a = (compconj[1].realpart / compconj[2].realpart);
	double b = (compconj[1].imagpart / compconj[2].imagpart);
	double c = (compconj[1].imagpart / compconj[2].realpart);
	double d = -(compconj[1].realpart / compconj[2].imagpart);

	if (compconj[1].realpart == 0) {
		a = 0; d = 0;
	}
	if (compconj[1].imagpart == 0) {
		b = 0; c = 0;
	}
	if (compconj[2].realpart == 0) {
		a = 0; c = 0;
	}
	if (compconj[2].imagpart == 0) {
		b = 0; d = 0;
	}

	temp.realpart = a + b;
	temp.imagpart = c + d;

	return temp;
}

const ComplexNumber& ComplexNumber::operator=(const ComplexNumber &rhs){
	realpart = rhs.realpart;
	imagpart = rhs.imagpart;
	return *this;
}

bool ComplexNumber::operator==(const ComplexNumber &rhs) {
	if ((realpart == rhs.realpart) && (imagpart == rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator!=(const ComplexNumber &rhs) {
	if ((realpart == rhs.realpart) && (imagpart == rhs.imagpart)) {
		return false;
	}
	else {
		return true;
	}
}

bool ComplexNumber::operator<(const ComplexNumber &rhs) {
	if (realpart < rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart < rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator<=(const ComplexNumber &rhs) {
	if (realpart < rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart <= rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator>(const ComplexNumber &rhs) {
	/*cout << "realpart" << realpart << endl;
	cout << "rhs.realpart" << rhs.realpart << endl;
	cout << "imagpart" << imagpart << endl;
	cout << "rhs.imagpart" << rhs.imagpart << endl;*/
	if (realpart > rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart > rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator>=(const ComplexNumber &rhs) {
	if (realpart > rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart >= rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream &in, ComplexNumber &rhs) {
	in >> rhs.realpart >> rhs.imagpart;
	return in;
}

ostream& operator<<(ostream& out, const ComplexNumber &rhs) {
	out << rhs.realpart << " + " << rhs.imagpart << "i";
	return out;
}
==> ./Projects/c++ int 80 complex number program/c++ int 80 complex number program/ComplexNumber.h <==
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

using namespace std;

class ComplexNumber {
	
public:
	ComplexNumber();
	ComplexNumber(double, double);
	ComplexNumber(const ComplexNumber&);

	double realpart;
	double imagpart;

	ComplexNumber operator+(const ComplexNumber&) const;
	ComplexNumber operator-(const ComplexNumber&) const;
	ComplexNumber operator*(const ComplexNumber&) const;
	ComplexNumber operator/(const ComplexNumber&) const;
	const ComplexNumber& operator=(const ComplexNumber&);
	bool operator<(const ComplexNumber&);
	bool operator>(const ComplexNumber&);
	bool operator>=(const ComplexNumber&);
	bool operator<=(const ComplexNumber&);
	bool operator==(const ComplexNumber&);
	bool operator!=(const ComplexNumber&);
	friend ostream& operator<<(ostream&, const ComplexNumber&);
	friend istream& operator>>(istream&, ComplexNumber&);

};

#endif
==> ./Projects/c++ int 80 complex number program/c++ int 80 complex number program/main.cpp <==
#include <iostream>
#include <iomanip>
#include <string>
#include "ComplexNumber.h"

ComplexNumber power(ComplexNumber, int);

using namespace std;

int main() {
	ComplexNumber num1(1, 1), num2(1, -1), num3(-1,-1), num4(-1,1);

	cout << num1 * num1 << endl;
	cout << num2 * num2 << endl;
	cout << num3 * num3 << endl;
	cout << num4 * num4 << endl;

	/*ComplexNumber numser[100];
	numser[0] = num1;
	for (int i = 0; i < 50; i++) {
		numser[i + 1] = numser[i] * num2;
		cout << setw(8) << numser[i] << endl;
	}
	cout << endl;
	/*for (int i = 1; i <= 16; i++) {
		cout << "(1+i)^" << i << " = " << power(num1, i) << endl;
		cout << "(1-i)^" << i << " = " << power(num2, i) << endl;

		cout << "(-1-i)^" << i << " = " << power(num3, i) << endl;
		cout << "(-1+i)^" << i << " = " << power(num4, i) << endl;
		cout << endl;
	}*/
	

	//cout << num1 * num3 << endl;
	//cout << num2 * num3 << endl;

	//cout << (num1 / num2)/num3 << endl;

	
	/*num2 = num1 + num1;
	cout << "num2 = " << num2 << endl;
	num2 = num1 * num1;
	cout << "num2 = " << num2 << endl;
	num2 = num1 / num1;
	cout << "num2 = " << num2 << endl;
	num2 = num3 - num1;
	cout << "num2 = " << num2 << endl;
	cout << num3 / num3 << endl;*/ 

	/*ComplexNumber numser[100];
	int a = 0, b = 0;

	for (int i = 0; i < 100; i++) {
		ComplexNumber temp(1, i+1);
		numser[i] = temp;
	}

	
	cout << setprecision(5) << showpoint << endl;
	for (int i = 1; i < 100; i++) {
	cout << "(" << numser[i] << ") / (" << numser[i - 1] << ") =\t";
		cout << numser[i] / numser[i - 1] << endl;
	}

	cout << setprecision(4) << endl;
	for (int i = 1; i < 100; i++) {
		cout << "(" << numser[i] << ") / (" << numser[0] << ") =\t";
		cout << numser[i] / numser[0] << endl;
	}
	int i1 = 2;
	for (int i = 0; i < 100; i++) {
		ComplexNumber temp(2, i1);
		numser[i] = temp;
		i1--;
	}

	cout << setprecision(4) << endl;
	for (int i = 1; i < 100; i++) {
		cout << "(" << numser[i] << ") / (" << numser[0] << ") =\t";
		cout << numser[i] / numser[0] << endl;
	}

	//cout << "num3 * num4 = " << num3 * num4;

	/*if (num2 == num1) {
		cout << "num2 == num1\n";
	}
	if (num2 >= num1) {
		cout << "num2 >= num1\n";
	}
	if (num2 > num1) {
		cout << "num2 > num1\n";
	}
	if (num2 <= num1) {
		cout << "num2 <= num1\n";
	}
	if (num2 < num1) {
		cout << "num2 < num1\n";
	}
	if (num2 != num1) {
		cout << "num2 != num1\n";
	}*/
	//system("PAUSE");
	return 0;
}

ComplexNumber power(ComplexNumber num, int p) {
	ComplexNumber temp(num);
	for (int i = 1; i < p; i++) {
		temp = temp * num;
	}
	return temp;
}
==> ./Projects/c++ int 80 complex number program/c++ int 80 complex number program/random stuff.cpp <==
/*if ((realpart != 0) && (imagpart != 0) && (rhs.realpart != 0)
	&& (rhs.imagpart != 0)) {
	temp.realpart = (realpart / rhs.realpart) + (imagpart / rhs.imagpart);
	temp.imagpart = (imagpart / rhs.realpart) - (realpart / rhs.imagpart);
}
double a = (realpart / rhs.realpart);
double b = (imagpart / rhs.imagpart);
double c = (imagpart / rhs.realpart);
double d = -(realpart / rhs.imagpart);

switch (realpart) {
case 0: a = 0; d = 0; break;
}
switch (imagepart) {
case 0: b = 0; c = 0; break;
}
switch (rhs.realpart) {
case 0: a = 0; c = 0; break;
}
switch (rhs.imagepart) {
case 0: b = 0; d = 0; break;
}

temp.realpart = a + b;
temp.imagpart = c + d;


else if (((realpart == 0) && (imagpart == 0)) || ((rhs.realpart == 0)
	&& (rhs.imagpart == 0))) {
	temp.realpart = 0;
	temp.imagpart = 0;
}

else if (realpart == 0) {
	temp.imagpart = 0;
	temp.realpart = 0;
	if (rhs.realpart != 0) {
		temp.realpart = 0;
		temp.imagpart = (imagpart / rhs.realpart);
	}
	else if (rhs.imagpart != 0) {
		temp.realpart = (imagpart / rhs.imagpart);
		temp.imagpart = 0;
	}
}

else if (imagpart == 0) {
	temp.imagpart = 0;
	temp.realpart = 0;
	if (rhs.imagpart != 0) {
		temp.imagpart = -(realpart / rhs.imagpart);
	}
	if (rhs.realpart != 0) {
		temp.realpart = (realpart / rhs.realpart);
	}
}
*/

==> ./Projects/c++ int 82 new string program/c++ int 82 new string program/main.cpp <==
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "NewString.h"

using namespace std;

template <typename Type> Type larger(Type, Type);

int main(){
	char huy[100];
	cin >> setw(100) >> huy;
	NewString muy;
	muy = huy;
	cout << muy;
	
	NewString str1("Leslie");
	cout << str1 << endl;

	NewString str2;
	str2 = str1;
	cout << str2;

	NewString str3(str1);
	cout << str3;

	NewString str4;
	str4 = "hello";
	cout << str4 << endl;

	if (str1 == str2) {
		cout << "good\n";
	}
	if (str1 == str3) {
		cout << "good yes\n";
	}
	if (str1 != str4) {
		cout << "All good\n";
	}

	NewString str5;
	cin >> str5;

	cout << str4 + str1 << endl;
	cout << str4 + " world" << endl;

	cout << larger(5, 3) << endl;
	cout << larger('A', 'B') << endl;
	cout << larger("Hello", "World") << endl;

	return 0;
}

//will worker with all possible 'Types' including classes such as NewString, given they have a >= operator function 
template <typename Type> Type larger(Type x, Type y) {
	if (x >= y) {
		return x;
	}
	else {
		return y;
	}
}
==> ./Projects/c++ int 82 new string program/c++ int 82 new string program/NewString.cpp <==
#include "NewString.h"

NewString::NewString(){
	strLength = 0;
	strPtr = new char[1];
	strcpy(strPtr, "");
}

NewString::NewString(const char* temp) {
	strLength = strlen(temp);
	strPtr = new char[strLength + 1];
	for (int i = 0; i < strLength; i++) {
		strPtr[i] = temp[i];
	}
}

NewString::~NewString() {
	if (strPtr) {
		delete[] strPtr;
	}
}

NewString::NewString(const NewString &rhs) {
	strLength = rhs.strLength;
	if (rhs.strPtr) {
		strPtr = new char[strLength + 1];
		for (int i = 0; i < strLength; i++) {
			strPtr[i] = rhs.strPtr[i];
		}
	}
}

char& NewString::operator[] (int index) {
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

const char& NewString::operator[](int index) const {
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

const NewString& NewString::operator=(const NewString &rhs) {
	if (this != &rhs) {
		strLength = rhs.strLength;
		if (rhs.strPtr) {
			strPtr = new char[strLength + 1];
			for (int i = 0; i < strLength; i++) {
				strPtr[i] = rhs.strPtr[i];
			}
		}
	}
	return *this;
}

const NewString& NewString::operator=(const char *nline) {
	strLength = strlen(nline);
	if (strPtr) {
		delete[] strPtr;
	}
	strPtr = new char[strLength];
	for (int i = 0; i < strLength; i++) {
		strPtr[i] = nline[i];
	}
	return *this;
}

const NewString& NewString::operator+ (const NewString &rhs) {
	NewString *temp;
	temp = new NewString();
	temp->strLength = strLength + rhs.strLength;
	//cout << "temp.strlength = " << temp->strLength << endl;
	temp->strPtr = new char[temp->strLength + 1];
	int j = 0;
	for (int i = 0; i < temp->strLength; i++) {
		if (i < strLength) {
			temp->strPtr[i] = strPtr[i];
		}
		else {
			temp->strPtr[i] = rhs.strPtr[j];
			j++;
		}
	}

	return *temp;
}

const NewString& NewString::operator+ (const char* line) {
	NewString *temp;
	temp = new NewString();
	temp->strLength = strLength + strlen(line);
	temp->strPtr = new char[temp->strLength + 1];
	int j = 0;
	for (int i = 0; i < temp->strLength; i++) {
		if (i < strLength) {
			temp->strPtr[i] = strPtr[i];
		}
		else {
			temp->strPtr[i] = line[j];
			j++;
		}
	}
	return *temp;
}

bool NewString::operator==(const NewString &rhs) const {
	int a = 0;
	if (strLength == rhs.strLength) {
		for (int i = 0; i < strLength; i++) {
			if (strPtr[i] == rhs.strPtr[i]) {
				a++;
			}
		}
		if (a == strLength) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool NewString::operator!=(const NewString &rhs) const {
	int a = 0;
	if (strLength == rhs.strLength) {
		for (int i = 0; i < strLength; i++) {
			if (strPtr[i] == rhs.strPtr[i]) {
				a++;
			}
		}
		if (a == strLength) {
			return false;
		}
	}
	else {
		return true;
	}
}

bool NewString::operator==(const char* line) const {
	int a = 0;
	int linelngth = strlen(line);
	if (strLength == linelngth) {
		for (int i = 0; i < linelngth; i++) {
			if (strPtr[i] == line[i]) {
				a++;
			}
		}
		if (a == strLength) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool NewString::operator!=(const char* line) const {
	int a = 0;
	int linelngth = strlen(line);
	if (strLength == linelngth) {
		for (int i = 0; i < linelngth; i++) {
			if (strPtr[i] == line[i]) {
				a++;
			}
		}
		if (a == strLength) {
			return false;
		}
	}
	else {
		return true;
	}
}

ostream& operator<<(ostream &out, const NewString& str1) {
	for (int i = 0; i < str1.strLength; i++) {
		out << str1.strPtr[i];
	}
	out << endl;
	return out;
}

istream& operator>>(istream &in, NewString& stri) {
	char temp[100];
	in >> setw(100) >> temp;
	stri = temp;

	return in;
}
==> ./Projects/c++ int 82 new string program/c++ int 82 new string program/NewString.h <==
#ifndef NEWSTRING_H
#define NEWSTRING_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>

using namespace std;

class NewString {
	char *strPtr;
	int strLength;
public:
	NewString();
	NewString(const char*);
	NewString(const NewString&);
	~NewString();

	char& operator[](int);
	const char& operator[](int) const;

	bool operator==(const NewString&) const;
	bool operator!=(const NewString&) const;
	/*bool operator>=(const NewString&) const;
	bool operator<=(const NewString&) const;
	bool operator<(const NewString&) const;
	bool operator>(const NewString&) const;*/

	bool operator==(const char*) const;
	bool operator!=(const char*) const;
	/*bool operator>=(const char*) const;
	bool operator<=(const char*) const;
	bool operator<(const char*) const;
	bool operator>(const char*) const;*/

	const NewString& operator+(const NewString&);
	const NewString& operator+(const char*);
	const NewString& operator=(const NewString&);
	const NewString& operator=(const char*);

	friend ostream& operator<<(ostream &out, const NewString&);
	friend istream& operator>>(istream &in, NewString&);
};

#endif
==> ./Projects/C++ int 84 class templates/C++ int 84 class templates/ArrayListType.cpp <==
/*#include "ArrayListType.h"

template <class elemType> 
ArrayListType<elemType>::ArrayListType(int size) {
	if (size <= 0) {
		cout << "Array size must be positive, creating default aray size of 100\n";
		maxSize = 100;
	}
	else {
		maxSize = size;
	}
	length = 0;
	list = new elemType[maxSize];
}

template <class elemType> 
ArrayListType<elemType>::ArrayListType(const ArrayListType<elemType> &rhs) {
	maxSize = rhs.maxSize;
	length = rhs.length;
	list = new elemType[maxSize];
	for (int i = 0; i < length; i++) {
		list[i] = rhs.list[i];
	}
}

template <class elemType> 
ArrayListType<elemType>::~ArrayListType() {
	delete[] list;
}

template <class elemType>
const ArrayListType<elemType>& ArrayListType<elemType>::operator=(const ArrayListType<elemType> &rhs) {
	if (this != rhs) {
		delete[] list;
		maxSize = rhs.maxSize;
		length = rhs.Length;
		list = new elemType[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

template <class elemType> 
bool ArrayListType<elemType>::isEmpty() const {
	return(length == 0);
}

template <class elemType> 
bool ArrayListType<elemType>::isFull() const {
	return(length == maxSize);
}

template <class elemType> 
int ArrayListType<elemType>::listSize() const {
	return length;
}

template <class elemType> 
int ArrayListType<elemType>::maxListSize() const {
	return maxSize;
}

template <class elemType> 
void ArrayListType<elemType>::clearList() {
	length = 0;
}

template <class elemType> 
void ArrayListType<elemType>::print() const {
	for (int i = 0; i < length; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

template <class elemType> 
bool ArrayListType<elemType>::isItemAtEqual(int loc, const elemType& item) const {
	if ((loc < 0) || (loc >= length)) {
		cout << "The location is out of range.\n";
		return false;
	}
	else {
		return (list[loc] == item);
	}
}

template <class elemType> 
void ArrayListType<elemType>::removeAt(int location) {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range.\n";
	}
	else {
		for (int i = location; i < length - 1; i++) {
			list[i] = list[i + 1];
		}
		length--;
	}
}

template <class elemType>
void ArrayListType<elemType>::retrieveAt(int location, elemType &item) const {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range";
	}
	else {
		cout << list[location] << endl;
	}
}*/
==> ./Projects/C++ int 84 class templates/C++ int 84 class templates/ArrayListType.h <==
#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H
#include <iostream>

using namespace std;

//abstract data type ArrayListType - contains pure virtual functions

template <class elemType>
class ArrayListType {
protected: 
	elemType *list;
	int length;
	int maxSize;
public:
	ArrayListType(int size = 100);
	ArrayListType(const ArrayListType<elemType>&);
	virtual ~ArrayListType();
	const ArrayListType<elemType>& operator=(const ArrayListType<elemType>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int, const elemType&) const;
	void removeAt(int);
	void retrieveAt(int, elemType&) const;
	void clearList();

	virtual void insertAt(int, const elemType&) = 0;
	virtual void insertEnd(const elemType&) = 0;
	virtual void replaceAt(int, const elemType&) = 0;
	virtual int seqSearch(const elemType&) const = 0;
	virtual void remove(const elemType&) = 0;
};

template <class elemType>
ArrayListType<elemType>::ArrayListType(int size) {
	if (size <= 0) {
		cout << "Array size must be positive, creating default aray size of 100\n";
		maxSize = 100;
	}
	else {
		maxSize = size;
	}
	length = 0;
	list = new elemType[maxSize];
}

template <class elemType>
ArrayListType<elemType>::ArrayListType(const ArrayListType<elemType> &rhs) {
	maxSize = rhs.maxSize;
	length = rhs.length;
	list = new elemType[maxSize];
	for (int i = 0; i < length; i++) {
		list[i] = rhs.list[i];
	}
}

template <class elemType>
ArrayListType<elemType>::~ArrayListType() {
	delete[] list;
}

template <class elemType>
const ArrayListType<elemType>& ArrayListType<elemType>::operator=(const ArrayListType<elemType> &rhs) {
	if (this != rhs) {
		delete[] list;
		maxSize = rhs.maxSize;
		length = rhs.Length;
		list = new elemType[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

template <class elemType>
bool ArrayListType<elemType>::isEmpty() const {
	return(length == 0);
}

template <class elemType>
bool ArrayListType<elemType>::isFull() const {
	return(length == maxSize);
}

template <class elemType>
int ArrayListType<elemType>::listSize() const {
	return length;
}

template <class elemType>
int ArrayListType<elemType>::maxListSize() const {
	return maxSize;
}

template <class elemType>
void ArrayListType<elemType>::clearList() {
	length = 0;
}

template <class elemType>
void ArrayListType<elemType>::print() const {
	for (int i = 0; i < length; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

template <class elemType>
bool ArrayListType<elemType>::isItemAtEqual(int loc, const elemType& item) const {
	if ((loc < 0) || (loc >= length)) {
		cout << "The location is out of range.\n";
		return false;
	}
	else {
		return (list[loc] == item);
	}
}

template <class elemType>
void ArrayListType<elemType>::removeAt(int location) {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range.\n";
	}
	else {
		for (int i = location; i < length - 1; i++) {
			list[i] = list[i + 1];
		}
		length--;
	}
}

template <class elemType>
void ArrayListType<elemType>::retrieveAt(int location, elemType &item) const {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range";
	}
	else {
		cout << list[location] << endl;
	}
}


#endif

==> ./Projects/C++ int 84 class templates/C++ int 84 class templates/main.cpp <==
#include <iostream>
#include <string>
#include "ArrayListType.h"
#include "UnorderedListType.h"

using namespace std;

int main() {
	UnorderedArrayList<string> strList(25);
	UnorderedArrayList<int> intList(25);
	string str;
	int num;
	cout << "Enter 5 strings: ";
	for (int count = 0; count < 5; count++) {
		cin >> str;
		strList.insertEnd(str);
	}
	cout << endl;
	cout << "Enter 5 integers: ";
	for (int count = 0; count < 5; count++) {
		cin >> num;
		intList.insertEnd(num);
	}
	cout << endl;

	cout << "strlist = ";
	strList.print();
	cout << "\nintlis = ";
	intList.print();

	return 0;
}
==> ./Projects/C++ int 84 class templates/C++ int 84 class templates/UnorderedListType.cpp <==
/*#include "UnorderedListType.h"

template <class elemType> 
UnorderedArrayList<elemType>::UnorderedArrayList(int size) {
	if (size <= 0) {
		cout << "Size most be a positive integer\n";
		maxSize = 100;
	}
	else {
		maxSize = size;
	}
	list = new elemType[maxSize];
	length = 0;
}

template <class elemType> 
void UnorderedArrayList<elemType>::insertAt(int location, const elemType &item) {
	if (length >= maxSize) {
		cout << "Array is already full\n";
	}
	else if ((location < 0)||(location >= length)) {
		cout << "Location exceeds the size of the array\n";
	}
	else {
		for (int i = length; i > location; i--) {
			list[i] = list[i - 1];
		}
		list[location] = item;
		length++;
	}
}

template <class elemType> 
void UnorderedArrayList<elemType>::insertEnd(const elemType &item) {
	if (length >= maxSize) {
		cout << "Array is already full\n";
	}
	else {
		list[length] = item;
		length++;
	}
}

template <class elemType> 
void UnorderedArrayList<elemType>::replaceAt(int location, const elemType &item) {
	if ((location <0)||(location >= length)) {
		cout << "Location exceeds the size of the array\n";
	}
	else {
		list[location] = item;
	}
}

template <class elemType> 
int UnorderedArrayList<elemType>::seqSearch(const elemType &item) const {
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++) {
		if (list[loc] == item) {
			found = true;
			break;
		}
	}
	if (found) {
		return loc;
	}
	else {
		return -1;
	}
}

template <class elemType> 
void UnorderedArrayList<elemType>::remove(const elemType &item) {
	int loc;
	if (length == 0) {
		cout << "The list is empty\n";
	}
	else {
		loc = seqSearch(item);
		if (loc != -1) {
			removeAt(loc);
		}
		else {
			cout << "THe item is not on the list\n";
		}
	}
}*/
==> ./Projects/C++ int 84 class templates/C++ int 84 class templates/UnorderedListType.h <==
#ifndef UNORDEREDLIST_H
#define UNORDEREDLIST_H
//#include <iostream>
#include "ArrayListType.h"

//using namespace std;

template <class elemType>
class UnorderedArrayList : public ArrayListType<elemType> {
public:
	UnorderedArrayList(int size = 100){
		if (size <= 0) {
			cout << "Size must be a positive integer\n";
			maxSize = 100;
		}
		else {
			maxSize = size;
		}
		list = new elemType[maxSize];
		length = 0;
	}

	void insertAt(int location, const elemType& item){
		if (length >= maxSize) {
			cout << "Array is already full\n";
		}
		else if ((location < 0) || (location >= length)) {
			cout << "Location exceeds the size of the array\n";
		}
		else {
			for (int i = length; i > location; i--) {
				list[i] = list[i - 1];
			}
			list[location] = item;
			length++;
		}
	}

	void insertEnd(const elemType& item){
		if (length >= maxSize) {
			cout << "Array is already full\n";
		}
		else {
			list[length] = item;
			length++;
		}
	}

	void replaceAt(int location, const elemType &item){
		if ((location <0) || (location >= length)) {
			cout << "Location exceeds the size of the array\n";
		}
		else {
			list[location] = item;
		}
	}

	void remove(const elemType &item){
		int loc;
		if (length == 0) {
			cout << "The list is empty\n";
		}
		else {
			loc = seqSearch(item);
			if (loc != -1) {
				removeAt(loc);
			}
			else {
				cout << "THe item is not on the list\n";
			}
		}
	}
	
	int seqSearch(const elemType &item) const{
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++) {
			if (list[loc] == item) {
				found = true;
				break;
			}
		}
		if (found) {
			return loc;
		}
		else {
			return -1;
		}
	}
};

/*template <class elemType>
UnorderedArrayList<elemType>::UnorderedArrayList(int size) {
	if (size <= 0) {
		cout << "Size most be a positive integer\n";
		maxSize = 100;
	}
	else {
		maxSize = size;
	}
	list = new elemType[maxSize];
	length = 0;
}

template <class elemType>
void UnorderedArrayList<elemType>::insertAt(int location, const elemType &item) {
	if (length >= maxSize) {
		cout << "Array is already full\n";
	}
	else if ((location < 0) || (location >= length)) {
		cout << "Location exceeds the size of the array\n";
	}
	else {
		for (int i = length; i > location; i--) {
			list[i] = list[i - 1];
		}
		list[location] = item;
		length++;
	}
}

template <class elemType>
void UnorderedArrayList<elemType>::insertEnd(const elemType &item) {
	if (length >= maxSize) {
		cout << "Array is already full\n";
	}
	else {
		list[length] = item;
		length++;
	}
}

template <class elemType>
void UnorderedArrayList<elemType>::replaceAt(int location, const elemType &item) {
	if ((location <0) || (location >= length)) {
		cout << "Location exceeds the size of the array\n";
	}
	else {
		list[location] = item;
	}
}

template <class elemType>
int UnorderedArrayList<elemType>::seqSearch(const elemType &item) const {
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++) {
		if (list[loc] == item) {
			found = true;
			break;
		}
	}
	if (found) {
		return loc;
	}
	else {
		return -1;
	}
}

template <class elemType>
void UnorderedArrayList<elemType>::remove(const elemType &item) {
	int loc;
	if (length == 0) {
		cout << "The list is empty\n";
	}
	else {
		loc = seqSearch(item);
		if (loc != -1) {
			removeAt(loc);
		}
		else {
			cout << "THe item is not on the list\n";
		}
	}
}*/

#endif
==> ./Projects/c++ int 88 exception classes/c++ int 88 exception classes/main.cpp <==
#include <iostream>
#include <string>

using namespace std;

//user defined exception
class divByZero {
	string message;
public:
	divByZero() {
		message = "Cannot divide by zero\n";
	}
	string what() {
		return message;
	}
};


//throw (exception) used to rethrow exception, for example if exception occurs in function used by enterNumber() 
void enterNumber() throw (exception);

int main() {
	cin.exceptions(ios_base::failbit);
	string sentence, str1, str2, str3;
	try {
		sentence = "Testing string exceptions.";
		cout << "sentence = " << sentence << endl;
		cout << "sentence length = " << sentence.length() << endl;
		str1 = sentence.substr(8, 20);
		cout << "str1 = " << str1 << endl;
		str2 = sentence.substr(28, 10);
		cout << "str2 = " << str2 << endl;
		str3 = "Exception handling. " + sentence;
		cout << "str3 = " << str3 << endl;
	}
	//standard exception class 'out_of_range' - have .what() function
	catch (out_of_range re) {
		cout << "Out of range, re.what(): " << re.what() << endl;
	}
	//standard exception class 'length_error' - have .what() function
	catch (length_error le) {
		cout << "Length error, le.what(): " << le.what() << endl;
	}

	string *list[100];
	try {
		for (int i = 0; i < 1000; i++) {
			list[i] = new string[1000000];
			cout << "created list [" << i << "] of 10000000 components\n";
		}
	}
	catch (bad_alloc be) {
		cout << "Bad alloc, be.what(): " << be.what() << endl;
	}

	delete[] * list;
	try {
		int dividend, divisor;
		cout << "Please enter dividend: ";
		cin >> dividend;
		cout << "\nPlease enter divisor: ";
		cin >> divisor;
		if (divisor == 0) {
			throw divByZero();
		}
	}
	catch (divByZero de) {
		cout << "Division by zero, de: " << de.what() << endl;
	}

	try {
	enterNumber();
	}
	catch (exception ex) {
		cout << "Input error, ex.what(): " << ex.what() << endl;
	}
	
	return 0;
}

void enterNumber() throw (exception){
	try {
		int move = 0;
		cin >> move;
		move = move + 7;
	}
	catch (exception e) {
		cout << "ok";
	}

	try {
		int seven;
		cin >> seven;
		seven = seven + 7;
	}
	catch (exception e) {
		throw;
	}
}
==> ./Projects/c++ int 91 - stack unwinding/c++ int 91 - stack unwinding/main.cpp <==
/*When an exception occurs in a function, the function call stack will be unwound. All local variables will be 
destroyed, and the stack will unwind until it encounters a try-catch block which can catch the exception.*/

#include <iostream>
#include <string>

using namespace std;

class MyException {
	string message;
public:
	MyException(string s) {
		message = s;
	}
	string what() {
		return message;
	}
};

void functionA() throw(MyException);
void functionB() throw(MyException);
void functionC() throw(MyException);

void functionA1();
void functionB1();
void functionC1() throw(MyException);

int main() {
	cin.exceptions(ios_base::failbit);

	try {
		functionA();
	}
	catch (MyException ex) {
		cout << ex.what() <<  " caught in main" << endl;
	}

	functionA1();
	return 0;
}

void functionA() throw(MyException) {
	functionB();
	cout << "To you neighbour\n";
}

void functionB() throw(MyException) {
	functionC();
	cout << "Howdy doody\n";
}

void functionC() throw(MyException) {
	throw MyException("Exception generated in function C");
	cout << "I'm Misterman\n";
}


void functionA1() {
	functionB1();
	cout << "To you neighbour\n";
}

void functionB1() {
	try {
		functionC1();
	}
	catch (MyException ex) {
		cout << ex.what() << " caught in function B1\n";
	}
	cout << "Howdy doody\n";
}

void functionC1() throw(MyException) {
	throw MyException("Exception generated in function C1");
	cout << "I'm Misterman\n";
}
==> ./Projects/c++ int 95 tower of hanoi recursion/c++ int 95 tower of hanoi recursion/main.cpp <==
#include <iostream>

using namespace std;

void move(int, int, int, int);

int main() {
	cin.exceptions(ios_base::failbit);
	int num = 0;
	do {
		cout << "Enter the number of disks : ";
		try {
			cin >> num;
		}
		catch (exception ex) {
			cout << "ex.what() = " << ex.what() << endl;
			cin.clear();
			cin.ignore(100, '\n');
			num = 0;
		}
	} while (num == 0);
	cout << endl;
	move(num, 1, 3, 2);
	system("PAUSE");
	return 0;
}

void move(int count, int n1, int n3, int n2) {
	if (count > 0) {
		move(count - 1, n1, n2, n3);
		cout << "Move disk " << count << " from needle " << n1 << " to needle " << n3 << endl;
		move(count - 1, n2, n3, n1);
	}
}


==> ./Projects/c++ int133 stl replace functions/c++ int133 stl replace functions/main.cpp <==
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool greatequal50(int);

int main() {
	char cList[10] = { 'A', 'a', 'A', 'B', 'A', 'c', 'D', 'e', 'F', 'A' };
	vector<char> charList(cList, cList + 10);
	ostream_iterator<char> print(cout, " ");
	cout << "charList = ";
	/*copy(charList.begin(), charList.end(), print);
	cout << endl;*/
	for (auto i : charList) {
		cout << i << " ";
	}
	cout << endl;

	replace(charList.begin(), charList.end(), 'A', 'Z');
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	replace_if(charList.begin(), charList.end(), isupper, '*');
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	int list[10] = { 12, 34, 56, 21, 34, 78, 34, 55, 12, 25 };
	vector<int> list1(list, list + 10);
	ostream_iterator<int> print1(cout, " ");
	cout << "intList = ";
	copy(list1.begin(), list1.end(), print1);
	cout << endl;

	vector<int> temp1(10);
	replace_copy(list1.begin(), list1.end(), temp1.begin(), 34, 89);
	cout << "temp1 = ";
	copy(temp1.begin(), temp1.end(), print1);
	cout << endl;
	
	vector<int> temp2(10);
	replace_copy_if(list1.begin(), list1.end(), temp2.begin(), [](int y) {return(y >= 50); }, 55);
	//same as replace_copy_if(list1.begin(), list1.end(), temp1.begin(), greatequal50, 55);
	cout << "temp2 = ";
	copy(temp2.begin(), temp2.end(), print1);
	cout << endl;

	system("PAUSE");
	return 0;
}

bool greatequal50(int y) {
	return (y >= 50);
}
==> ./Projects/c++ int144 forward lists/c++ int144 forward lists/main.cpp <==
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> list; //only allows eleents to be added to the front, normal list can be added to back or front
	typedef forward_list<int>::iterator it;
	it iter;
	forward_list<int>::iterator iter1;

	list.push_front(3);
	list.push_front(2);

	for (iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << endl;
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int97 linked lists/c++ int97 linked lists/main.cpp <==
#include <iostream>

using namespace std;

struct node {
	int info;
	node *link = NULL;
};

int main() {
	node *head, *x01, *x02, *x03, *p, *q, *newNode, *current;
	head = new node;
	head -> info = 39;
	x01 = new node;
	x01->info = 40;
	head->link = x01;
	x02 = new node;
	x02->info = 41;
	x01->link = x02;

	current = head;
	while (current != NULL) {
		cout << current->info << endl;
		current = current->link;
	}
	
	cout << endl;
	newNode = new node;
	newNode->info = 50;
	newNode->link = x01->link;
	x01->link = newNode;

	current = head;
	while (current != NULL) {
		cout << current->info << endl;
		current = current->link;
	}

	x01->link = x02;
	delete newNode;

	cout << endl;
	current = head;
	while (current != NULL) {
		cout << current->info << endl;
		current = current->link;
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++ int99 building a linked list/c++ int99 building a linked list/main.cpp <==
#include <iostream>

using namespace std;

struct node {
	int info;
	node *link;
};

node* buildListForward(); //new node inserted at back of list 
node* buildListBackward(); //new node inserted at front of list

int main() {
	node *current, *head;
	head = buildListForward();
	current = head;
	cout << "linked list = ";
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;

	head = buildListBackward();
	current = head;
	cout << "linked list = ";
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}

node* buildListForward() {
	node *first, *newNode, *last;
	first = NULL;
	last = NULL;
	int num;
	cout << "Enter integers, enter -999 when done." << endl;
	cin >> num;
	while (num != -999) {
		newNode = new node; //create new node
		newNode->info = num; //stores data in new node
		newNode->link = NULL; //initializes pointer as NULL
		if (first == NULL) {
			first = newNode; //sets first to newNode
			last = newNode; //sets last to newNode (as initialization)
		}
		else {
			last->link = newNode; //sets link in previous node to point to newNode
			last = newNode; //makes newnode the new last node
		}
		cin >> num;
	}
	return first;
}

node* buildListBackward() {
	node *first, *newNode;
	first = NULL; newNode = NULL;
	int num = NULL;
	cout << "Enter integers, enter -999 when done.\n";
	cin >> num;
	while (num != -999) {
		newNode = new node; //create new node
		newNode->info = num; //store data in new node
		newNode->link = first; //put new node at the beginning of the list
		first = newNode; //update head pointer of the list
		cin >> num;
	}
	return first;
}
==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/LinkedListClass.cpp <==

==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/LinkedListClass.h <==
#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <iostream>
#include <cassert>
#include "Linkedlistiterator.h"

using namespace std;

template <typename Type> class linkedListType {
public:
	const linkedListType<Type>& operator=(const linkedListType<Type> &rhs);
	bool operator==(const linkedListType<Type> &rhs) {
		node<Type> *current = first, *rhscurrent = rhs.first;
		while ((current != NULL) && (rhscurrent != NULL)) {
			if (current->info != rhscurrent->info) {
				return false;
			}
			else {
				current = current->link;
				rhscurrent = rhscurrent->link;
			}
		}
		if ((current == NULL) && (rhscurrent == NULL)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const linkedListType<Type> &rhs) {
		node<Type> *current = first, *rhscurrent = rhs.first;
		while ((current != NULL) && (rhscurrent != NULL)) {
			if (current->info != rhscurrent->info) {
				return true;
			}
			else {
				current = current->link;
				rhscurrent = rhscurrent->link;
			}
		}
		if ((current == NULL) && (rhscurrent == NULL)) {
			return false;
		}
		else {
			return true;
		}
	}
	void initializeList(); //initializes list
	bool isEmptyList() const; //returns true if list is empty
	void print() const; //prints list
	int length() const; //returns length of the list
	void destroyList(); //destroys the list
	Type front() const; // returns value at front of list
	Type back() const; //returns value at end of list
	virtual bool search(const Type&) const = 0; //will differ for ordered and nordered lists
	virtual void insertFirst(const Type&) = 0;
	virtual void insertLast(const Type&) = 0;
	virtual void deleteNode(const Type&) = 0;
	linkedListIterator<Type> begin(); 
	linkedListIterator<Type> end();
	linkedListType(); //default constructor
	linkedListType(const linkedListType<Type>&); //copy constructor
	~linkedListType(); //destructor
protected:
	int count; 
	node<Type> *first;
	node<Type> *last;
private:
	void copyList(const linkedListType<Type>&);
};

template <typename Type> void linkedListType<Type>::destroyList() {
	node<Type> *temp;
	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	first = NULL;
	last = NULL;
	count = 0;
}

template <typename Type> void linkedListType<Type>::copyList(const linkedListType<Type>& rhs) {
	node<Type> *newNode, *current;
	if (first != NULL) {
		destroyList();
	}
	if (rhs.first == NULL) {
		first = NULL;
		last = NULL;
		count = 0;
	}
	else {
		current = rhs.first; //value of first node is copied
		count = rhs.count; //value of count is copied
		first = new node<Type>; //first created as new node
		first->info = current->info; //value of current info assigned to first->info
		first->link = NULL; //pointer field of first set to null
		last = first;
		current = current->link; //current set to next value in list
		while (current != NULL) {
			newNode = new node<Type>; //newNode created for storage
			newNode->info = current->info; //info in current stored in newNode
			newNode->link = NULL; //pointer in newNode set to null
			last->link = newNode; //link in previous node now points to newNode
			last = newNode; //last is now equal to newNode, last->link = NULL;
			current = current->link; //current has value of next node
		}
		/*although we need the pointer in current to traverse the linked list, to avoid a shallow copy, new memory
		addresses should be formed. newNode is needed for this purpose
		*/
	}
}

template <typename Type> bool linkedListType<Type>::isEmptyList() const {
	return (first == NULL);
}

template <typename Type> linkedListType<Type>::linkedListType() {
	first = NULL;
	last = NULL;
	count = 0;
}

template <typename Type> linkedListType<Type>::~linkedListType() {
	destroyList();
}

template <typename Type> linkedListType<Type>::linkedListType(const linkedListType<Type> &rhs) {
	first = NULL;
	copyList(rhs);
}

/*template <typename Type> bool linkedListType<Type>::operator!=(const linkedListType<Type> &rhs) const {
	bool found = false;
	node<Type> *current = first, *rhscurrent = rhs.first;
	if ((current == NULL) && (rhscurrent == NULL)) {
		return false;
	}
	else {
		while ((current != NULL) && (rhscurrent != NULL)) {
			if (current->info == rhscurrent->info) {
				current = current->link;
				rhscurrent = rhscurrent->link;
			}
			else {
				return true;
			}
		}
		if ((current == NULL) && (rhscurrent == NULL)) {
			return false;
		}
		else {
			return true;
		}
	}
}*/

template <typename Type> const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type> &rhs) {
		copyList(rhs);
	
	return *this;
}

/*template <typename Type> bool linkedListType<Type>::operator==(const linkedListType<Type> &rhs) const {
	bool output = true;
	node<Type> *rhscurrent = rhs.first;
	node<Type> *current = first;
	while ((current != NULL) && (rhscurrent != NULL)) {
		if (current->info != rhscurrent->info) {
			output = false;
			break;
		}
		else {
			current = current->link;
			rhscurrent = rhscurrent->link;
		}
	}
	if ((current == NULL) && (rhscurrent == NULL) && (output == true)) {
		return output;
	}
	else {
		output = false;
		return output;
	}
}*/

template <typename Type>
void linkedListType<Type>::initializeList() {
	destroyList();
}

template <typename Type>
void linkedListType<Type>::print() const {
	node<Type> *current;
	current = first;
	if (current == NULL) {
		cout << "list is empty\n";
	}
	while (current != NULL) {
		cout << current->info << endl;
		current = current->link;
	}
}

template <typename Type> int linkedListType<Type>::length() const {
	return count;
}

template <typename Type> Type linkedListType<Type>::front() const {
	assert(first != NULL);
	return first->info;
}

template <typename Type> Type linkedListType<Type>::back() const {
	assert(last != NULL);
	return last->info;
}

template <typename Type> linkedListIterator<Type> linkedListType<Type>::begin() {
	linkedListIterator<Type> temp(first);
	return temp;
}

template <typename Type> linkedListIterator<Type> linkedListType<Type>::end() {
	linkedListIterator<Type> temp(NULL);
	return temp;
}

#endif
==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/Linkedlistiterator.h <==
#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

template <typename Type>
struct node {
	Type info;
	node<Type> *link;
};

//goes through 
template <typename Type>
class linkedListIterator {
	node<Type> *current;
public:
	linkedListIterator(); //default constructor
	linkedListIterator(node<Type>*); //constructor with parameters
	Type operator*(); //dereference operator
	linkedListIterator<Type> operator++(); //increment operator
	bool operator==(const linkedListIterator<Type>&) const;
	bool operator!=(const linkedListIterator<Type>&) const;
};

template <typename Type>
linkedListIterator<Type>::linkedListIterator() {
	current = NULL;
}

template <typename Type>
linkedListIterator<Type>::linkedListIterator(node<Type> * ptr) {
	current = ptr;
}

template <typename Type>
Type linkedListIterator<Type>::operator *() {
	return current->info;
}

template <typename Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
	current = current->link;
	return *this;
}

template <typename Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& rhs) const {
	return (current == rhs.current);
}

template <typename Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& rhs) const {
	return (current != rhs.current);
}
#endif

==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/main.cpp <==
//linked list as an abstract data type - for use in deriving ordered and unordered linked lists (inheritance)
#include <iostream>
#include "LinkedListClass.h"
#include "unorderedlinkedlist.h"
#include "Linkedlistiterator.h"
#include "OrderedLinkedList.h"

using namespace std;

int main() {
	cin.exceptions(ios_base::failbit);
	unorderedLinkedList<int> list1, list2;
	int num;
	cout << "Enter integers. If you have finished type -999\n";
	cin >> num;
	while (num != -999) {
		list1.insertLast(num);
		cin >> num;
	}
	cout << "list = \n";
	list1.print();
	cout << endl;

	unorderedLinkedList<int> list3(list1);

	if (list3 != list1) {
		cout << "inequality no works\n";
	}
	if (list3 == list1) {
		cout << "equality works\n";
	}

	list3.insertLast(55);

	list3.print();

	if (list3 != list1) {
		cout << "inequality works\n";
	}
	if (list3 == list1) {
		cout << "equality no works\n";
	}

	unorderedLinkedList<int> list4 = list3;
	list3.destroyList();
	list4.print();
	list3.print();

	list2 = list1;
	list1.destroyList();
	cout << "list 2 = ";
	list2.print();

	orderedLinkedList<int> olist1, olist2;
	cout << "\nEnter numbers ending with -999\n";
	cin >> num;
	while (num != -999) {
		olist1.insert(num);
		cin >> num;
	}
	cout << "\nolist 1 = \n";
	olist1.print();
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/OrderedLinkedList.h <==
#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
#include "LinkedListClass.h"

using namespace std;

template <typename Type>
class orderedLinkedList : public linkedListType<Type> {
public: 
	bool search(const Type&) const;
	void insert(const Type&);
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
};

template <typename Type> bool orderedLinkedList<Type>::search(const Type& item) const {
	bool found = false;
	node<Type> *current; //pointer to traverse list
	current = first; //start search with first node
	while ((current != NULL) && (!found)) { //while item left to be processed
		if (current->info == item) {
			found = true;
		}
		else {
			current = current->link; //advance current
		}
	}
	if (found) {
		found = true;
	}
	return found;
}

template <typename Type> void orderedLinkedList<Type>::insert(const Type& item) {
	node<Type> *current, *trailCurrent, *newNode; //pointers to traverse and create node
	bool found;
	newNode = new node<Type>; //create the new node
	newNode->info = item; //store item in node
	newNode->link = NULL; //link is set to NULL
	if (first == NULL) { //if list is empty
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		current = first; //start at first node
		found = false;
		while ((current != NULL) && (!found)) {
			if (current->info >= item) {
				found = true;
			}
			else {
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == first) { //item to be inserted is smaller than smallest in the list
			newNode->link = first;
			first = newNode;
			count++;
		}
		else {
			trailCurrent->link = newNode;
			newNode->link = current;
			if (current == NULL) {
				last = newNode;
			}
			count++;
		}
	}
}

template <typename Type> void orderedLinkedList<Type>::insertFirst(const Type& item) {
	insert(item);
}

template <typename Type> void orderedLinkedList<Type>::insertLast(const Type& item) {
	insert(item);
}

template <typename Type> void orderedLinkedList<Type>::deleteNode(const Type& item) {
	node<Type> *current, *trailCurrent;
	bool found;
	if (first == NULL) {
		cout << "The list is empty\n";
	}
	else {
		current = first;
		found = false;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else {
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == NULL){
			cout << "The item is not in the list\n";
		}
		else {
			if (current->info == item) {
				if (first == current) {
					first = first->link;
					if (first == NULL) {
						last = NULL;
					}
					delete current;
				}
				else {
					trailCurrent->link = current->link;
					if (current == last) {
						last = trailCurrent;
					}
					delete current;
				}
				count--;
			}
			else {
				cout << "Item is not on the list\n";
			}
		}
	}
}

#endif

==> ./Projects/c++int 100 linked list as an adt/c++int 100 linked list as an adt/unorderedlinkedlist.h <==
#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <iostream>
#include "LinkedListClass.h"

using namespace std;

template <typename Type> class unorderedLinkedList : public linkedListType<Type> {
public:
	bool search(const Type&) const;
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
};


/*template <typename Type> bool unorderedLinkedList<Type>::operator==(const unorderedLinkedList<Type> &rhs) {
	node<Type> *current = first, *rhscurrent = rhs.first;
	while ((current != NULL) && (rhscurrent != NULL)) {
		if (current->info != rhscurrent->info) {
			return false;
		}
		else {
			current = current->link;
			rhscurrent = rhscurrent->link;
		}
	}
	if ((current == NULL) && (rhscurrent == NULL)) {
		return true;
	}
	else {
		return false;
	}
}

template <typename Type> bool unorderedLinkedList<Type>::operator!=(const unorderedLinkedList<Type> &rhs) {
	node<Type> *current, *rhscurrent;
	current = new node<Type>;
	rhscurrent = new node<Type>;
	current = first;
	rhscurrent = rhs.first;
	while ((current != NULL) && (rhscurrent != NULL)) {
		if (current->info != rhscurrent->info) {
			return true;
		}
		else {
			current = current->link;
			rhscurrent = rhscurrent->link;
		}
	}
	if ((current == NULL) && (rhscurrent == NULL)) {
		return false;
	}
	else {
		return true;
	}
}*/

template <typename Type> bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
	node<Type> *current;
	bool found = false;
	current = first;
	while ((current != NULL) && (!found)) {
		if (current->info == searchItem){
			found = true;
		}
		else {
			current = current->link;
		}
	}
	return found;
}

template <typename Type> void unorderedLinkedList<Type>::insertFirst(const Type &item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = first;
	first = newNode;
	count++;
	if (last == NULL){
		last = newNode;
	}
}

template <typename Type> void unorderedLinkedList<Type>::insertLast(const Type& item){
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = NULL;
	if (first == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->link = newNode;
		last = newNode;
	}
}

template <typename Type> void unorderedLinkedList<Type>::deleteNode(const Type&item) {
	node<Type> *current, *trailCurrent;
	bool found;
	if (first == NULL) {
		cout << "The list is empty\n";
	}
	else {
		if (first->info == item) {
			current = first;
			first = first->link;
			count--;
			if (first == NULL) {
				last = NULL;
			}
			delete current;
		}
		else {
			found = false;
			trailCurrent = first;
			current = first->link;
			while ((current != NULL) && (!found)) {
				if (current->info != item) {
					trailCurrent = current;
					current = current->link;
				}
				else {
					found = true;
				}
			}
			if (found) {
				trailCurrent->link = current->link;
				count--;
				if (last == current) {
					last = trailCurrent;
				}
				delete current;
			}
			else {
				cout << "Item not found in list\n";
			}
		}
	}
}

#endif
==> ./Projects/c++int 109 postfix expression calculator/c++int 109 postfix expression calculator/LinkedStackType.h <==
#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;

template <typename Type>
struct node{
	Type info;
	node *link;
};

template <typename Type>
class linkedStackType : public stackADT<Type> {
	node<Type> *stackTop;
	void copyStack(const linkedStackType<Type>&);
public:
	linkedStackType();
	linkedStackType(const linkedStackType<Type>&);
	~linkedStackType();
	linkedStackType<Type>& operator=(const linkedStackType<Type>&);
	bool isEmptyStack() const;
	Type top() const;
	void pop();
	void push(const Type&);
	void initialiseStack();
};

template <typename Type>
linkedStackType<Type>::linkedStackType() {
	stackTop = NULL;
}

template <typename Type>
void linkedStackType<Type>::initialiseStack() {
	node<Type> *current;
	current = stackTop;
	while (current != NULL) {
		current = stackTop->link;
		delete stackTop;
		stackTop = current;
	}
}

template <typename Type>
linkedStackType<Type>::~linkedStackType() {
	initialiseStack();
}

template <typename Type>
bool linkedStackType<Type>::isEmptyStack() const {
	return (stackTop == NULL);
}

template <typename Type>
void linkedStackType<Type>::push(const Type &newitem) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = newitem;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <typename Type>
Type linkedStackType<Type>::top() const {
	assert(stackTop != NULL);
	return stackTop->info;
}

template <typename Type>
void linkedStackType<Type>::pop() {
	node<Type> *current;
	current = stackTop;
	if (current != NULL) {
		stackTop = current->link;
		delete current;
	}
}

template <typename Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &rhs) {
	node<Type> *current, *rhscurrent, *last;
	if (stackTop != NULL) {
		initialiseStack();
		stackTop = NULL;
	}
	if (rhs.stackTop == NULL) {
		stackTop = NULL;
	}
	else{
		rhscurrent = rhs.stackTop;
		last = new node<Type>;
		last->info = rhscurrent->info;
		rhscurrent = rhscurrent->link;
		while (rhscurrent != NULL) {
			current = new node<Type>;
			current->info = rhscurrent->info;
			current->link = NULL;
			last->link = current;
			if (stackTop == NULL) {
				stackTop = last;
			}
			rhscurrent = rhscurrent->link;
			last = current;
		}
	}
}	

template <typename Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &rhs) {
	stackTop = NULL;
	copyStack(rhs);
}

template <typename Type>
linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type> &rhs) {
	copyStack(rhs);
	return *this;
}

#endif
==> ./Projects/c++int 109 postfix expression calculator/c++int 109 postfix expression calculator/main.cpp <==
#include <iostream>
#include <iomanip>
#include <fstream>
#include "LinkedStackType.h"

using namespace std;

void test(linkedStackType<int>);
void evalExpression(ifstream&, ofstream&, linkedStackType<double>&, char&, bool&);
void evalOperator(ofstream&, linkedStackType<double>&, char&, bool&);
void discard(ifstream&, ofstream&, char&);
void print(ofstream&, linkedStackType<double>&, bool);

int main() {
	bool expressionOk;
	char ch;
	linkedStackType<double> stack;
	ifstream infile;
	ofstream outfile;
	infile.open("data.txt");
	outfile.open("results.txt");
	outfile << fixed << showpoint << setprecision(2);
	infile >> ch;
	while (infile) {
		stack.initialiseStack();
		expressionOk = true;
		outfile << ch;
		evalExpression(infile, outfile, stack, ch, expressionOk);
		print(outfile, stack, expressionOk);
		infile >> ch;
	}
	infile.close();
	outfile.close();

	system("PAUSE");
	return 0;
}

void evalExpression(ifstream& in, ofstream& out, linkedStackType<double>& stack, char& ch, bool& isOk) {
	double num;
	while (ch != '=') {
		switch (ch) {
		case '#': 
			in >> num;
			out << num << " ";
			stack.push(num);
			break;
		default:
			evalOperator(out, stack, ch, isOk);
		}
		if (isOk) {
			in >> ch;
			out << ch;
			if (ch != '#') {
				out << " ";
			}

		}
		else {
			discard(in, out, ch);
		}
	}
}

void evalOperator(ofstream& out, linkedStackType<double>& stack, char& ch, bool& isOk) {
	double op1, op2;
	if (stack.isEmptyStack()) {
		out << " (Not enough operands)";
		isOk = false;
	}
	else {
		op2 = stack.top();
		stack.pop();
		if (stack.isEmptyStack()) {
			out << " (Not enough operands)";
			isOk = false;
		}
		else {
			op1 = stack.top();
			stack.pop();
			switch (ch) {
			case '+': stack.push(op1 + op2); break;
			case '-': stack.push(op1 - op2); break;
			case '*': stack.push(op1 * op2); break;
			case '/': if (op2 != 0) stack.push(op1 / op2); else { out << " (Division by zero)"; isOk = false;} break;
			default: out << " (Illegal operator)"; isOk = false;
			}
		}
	}
}

void discard(ifstream& in, ofstream& out, char& ch) {
	while (ch != '=') {
		in.get(ch);
		out << ch;
	}
}

void print(ofstream& out, linkedStackType<double>& stack, bool isOk) {
	double result;
	if (isOk) {
		if (!stack.isEmptyStack()) {
			result = stack.top();
			stack.pop();
			if (stack.isEmptyStack()) {
				out << result << endl;
			}
			else {
				out << " (Too many operands)" << endl;
			}
		}
		else {
			out << " (Error in expression)" << endl;
		}
	}
	else {
		out << " (Error in expression)" << endl;
	}
	out << "____________________________________\n\n";
}

void test(linkedStackType<int> copystack) {
	cout << "Testing copy constructor... ";
	while (!copystack.isEmptyStack()) {
		cout << copystack.top() << " ";
		copystack.pop();
	}
}
==> ./Projects/c++int 109 postfix expression calculator/c++int 109 postfix expression calculator/stackADT.h <==
#ifndef STACKADT_H
#define STACKADT_H
#include <iostream>
using namespace std;

template <typename Type>
class stackADT {
	virtual void initialiseStack() = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
	virtual void push(const Type&) = 0;
	virtual bool isEmptyStack() const = 0;
};

#endif
==> ./Projects/c++int 110 Queue ADT/c++int 110 Queue ADT/main.cpp <==
#include <iostream>
#include "queueType.h"

using namespace std;

int main() {
	queueType<int> list1, list2;
	int i, num;

	cout << "Enter integers to add to queue: ";
	for (i = 0; i < 5; i++) {
		cin >> num;
		list1.addQueue(num);
	}
	list2 = list1;
	cout << "list1 = ";
	for (i = 0; i < 5; i++) {
		cout << list1.front() << " ";
		list1.deleteQueue();
	}
	cout << endl;

	cout << "list2 = ";
	for (i = 0; i < 5; i++) {
		cout << list2.front() << " ";
		list2.deleteQueue();
	}
	cout << endl;
	list1.initialiseQueue();
	list1.addQueue(2);
	list1.addQueue(4);
	list1.addQueue(6);
	list1.addQueue(8);
	list1.addQueue(10);
	list1.deleteQueue();
	list1.addQueue(12);
	list1.deleteQueue();
	list1.addQueue(14);
	cout << "list1 = ";
	while (!list1.isEmptyQueue()) {
		cout << list1.front() << " ";
		list1.deleteQueue();
	}
	cout << endl;
	return 0;
}
==> ./Projects/c++int 110 Queue ADT/c++int 110 Queue ADT/QueueADT.h <==
#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <iostream>

using namespace std;

template <typename Type>
class queueADT {
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initialiseQueue() = 0;
	virtual void deleteQueue() = 0;
	virtual void addQueue(const Type&) = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
};

#endif
==> ./Projects/c++int 110 Queue ADT/c++int 110 Queue ADT/queueType.h <==
#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include <iostream>
#include <cassert>
#include "QueueADT.h"
 
using namespace std;

template <typename Type>
class queueType : public queueADT<Type> {
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type *list;
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initialiseQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type&);
	void deleteQueue();
	queueType(int queueSize = 100);
	queueType(const queueType<Type>&);
	~queueType();
};

template <typename Type>
bool queueType<Type>::isFullQueue() const {
	return (count == maxQueueSize);
}

template <typename Type>
bool queueType<Type>::isEmptyQueue() const {
	return (count == 0);
}

template <typename Type>
void queueType<Type>::initialiseQueue() {
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template <typename Type>
Type queueType<Type>::front() const {
	assert(!isEmptyQueue());
	return list[queueFront];
}

template <typename Type>
Type queueType<Type>::back() const {
	assert(!isEmptyQueue());
	return list[queueRear];
}

template <typename Type>
void queueType<Type>::addQueue(const Type& item) {
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize; //modulus operator used to advance queuerear as array is circular
		count++;
		list[queueRear] = item;
	}
	else {
		cout << "The queue is full.\n";
	}
}

template <typename Type>
void queueType<Type>::deleteQueue() {
	if (!isEmptyQueue()) {
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; //modulus operator used to advance queuerear as array is circular 
	}
}

template <typename Type>
queueType<Type>::queueType(int queueSize) {
	if (queueSize <= 0) {
		cout << "Size must be positive, creating default size of 100.\n";
		maxQueueSize = 100;
	}
	else {
		maxQueueSize = queueSize;
	}
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}

template <typename Type>
queueType<Type>::~queueType() {
	delete[] list;
}

template <typename Type>
queueType<Type>::queueType(const queueType<Type> &rhs) {
	delete[] list;
	count = rhs.count;
	maxQueueSize = rhs.maxQueueSize;
	queueFront = rhs.queueFront;
	queueRear = rhs.queueRear;
	list = new Type[maxQueueSize];
	assert(list != NULL);
	for (int i = 0; i < count; i++) {
		list[i] = rhs.list[i];
	}
}

template <typename Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type> &rhs) {
	delete[] list;
	count = rhs.count;
	maxQueueSize = rhs.maxQueueSize;
	queueFront = rhs.queueFront;
	queueRear = rhs.queueRear;
	list = new Type[maxQueueSize];
	assert(list != NULL);
	for (int i = 0; i < count; i++) {
		list[i] = rhs.list[i];
	}
	return *this;
}

#endif
==> ./Projects/c++int 134 stl search functions/c++int 134 stl search functions/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	int list1[15] = { 3, 6, 18, 23, 45, 23, 12, 67, 23, 23, 89, 43, 76, 54, 32 };
	vector<int> vecList(list1, list1 + 15);
	int list2[2] = { 23,45 };
	vector<int>::iterator iter;
	ostream_iterator<int> print(cout, " ");

	cout << "vecList = ";
	copy(vecList.begin(), vecList.end(), print);
	cout << endl;

	cout << "list2 = ";
	copy(list2, list2 + 2, print);
	cout << endl;

	vector<int>::iterator iter;
	iter = search(vecList.begin(), vecList.end(), list2, list2 + 2);
	if (iter != vecList.end()){
		cout << "list2 found in vecList at position " << (iter - vecList.begin()) << endl;
	}
	else {
		cout << "list2 not found in vecList\n";
	}

	iter = search_n(vecList.begin(), vecList.end(), 2, 23);
	if (iter != vecList.end()) {
		cout << "Two consecutive numbers (23) at position " << (iter - vecList.begin()) << endl;
	}
	else {
		cout << "No consecutive numbers (23)\n";
	}

	sort(vecList.begin(), vecList.end()); //sorts vecList in ascending order
	cout << "vecList = ";
	copy(vecList.begin(), vecList.end(), print);
	cout << endl;

	bool found;
	found = binary_search(vecList.begin(), vecList.end(), 45);
	if (found) {
		cout << "45 found in vecList\n";
	}
	else {
		cout << "45 not found in vecList\n";
	}

	system("PAUSE");
	return 0;
}
==> ./Projects/c++int 135 stl swap functions/c++int 135 stl swap functions/main.cpp <==
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	char cList[10] = { 'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K' };
	vector<char> charList(cList, cList + 10);
	vector<char>::iterator chIter;
	ostream_iterator<char> print(cout, " ");
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	swap(charList[0], charList[1]);
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	iter_swap(charList.begin() + 2, charList.begin() + 3);
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	chIter = charList.begin() + 4;
	iter_swap(chIter, chIter + 1);
	cout << "charList = ";
	copy(charList.begin(), charList.end(), print);
	cout << endl;

	int list[10];
	for (int i = 0; i < 10; i++) {
		list[i] = i + 1;
	}
	vector<int> intList(list, list + 10);
	ostream_iterator<int> print1(cout, " ");
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;

	swap_ranges(intList.begin(), intList.begin() + 3, intList.begin() + 5); //amount swapped dependent on distance between first two parameters. swap begins from 3rd parameter
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;

	swap_ranges(list, list + 10, intList.begin());
	cout << "list = ";
	copy(list, list+ 10, print1); //ostream_iterator<int> can be used on standard arrays
	cout << endl;
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;


	system("PAUSE");
	return 0;
}
==> ./Projects/c++int 142 map container class/c++int 142 map container class/main.cpp <==
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <unordered_map>

using namespace std;

int main() {
	string tempArray[2] = { "hello" , "world" };
	//tempArray[0] = 2, key/identifier is 0, value stored is "hello"

	map<string, int> map1; //in this case a string is the key/identifier, and the value stored within is an integer
	//no push/pop function
	typedef map<string, int>::iterator it; // makes it = "map<string, int>::iterator" 
	it iter;

	map1["Test"] = 2;
	map1["Test2"] = 3;

	for (iter = map1.begin(); iter != map1.end(); iter++) { 
		cout << iter->first << " " << iter->second << endl;
	}

	//two ways of using insert function
	map1.insert(pair<string, int>("Test3", 1));
	map1.insert(make_pair("Test4", 4));
	pair <int, int> newtest; //.first and .second are intrinsic to any pair created in ths way

	newtest.first = 10;
	newtest.second = 20;

	cout << newtest.first << " " << newtest.second << endl;

	multimap<string, float> map2; //allows you to specify the same key for two different values;
	multimap<string, float>::iterator iter1;

	map2.insert(make_pair("John", 64.3));
	map2.insert(make_pair("Jake", 74.3));
	map2.insert(make_pair("John", 66.8));

	for (iter1 = map2.begin(); iter1 != map2.end(); iter1++) {
		cout << iter1->first << " " << iter1->second << endl;
	}
	//map keys are sorted by less than algorithm so strings are output in alphabetical order

	unordered_map<string, float> map3;
	unordered_multimap<string, float> map4;
	//unordered maps an unordered multmaps sort 

	return 0;
}
==> ./Projects/c++int 96 dec-to-binary/c++int 96 dec-to-binary/main.cpp <==
#include <iostream>
#include <vector>

using namespace std;

//void toDecimal();
//void toBinary();

int main() {
	cin.exceptions(ios_base::failbit);
	int number = 0;

	do {
		cout << "Please input a number to be converted to binary\n";
		try {
			cin >> number;
		}
		catch (exception e) {
			cout << "You did not enter a valid integer\n";
			cin.clear();
			cin.ignore(100, '\n');
			number = 0;
		}
	} while (number == 0);

	vector<int> remainder;

	
	

	cout << "Binary: ";
	for (auto i : remainder) {
		cout << i;
	}
	cout << endl;

	system("PAUSE");
	return 0;
}


==> ./Projects/c++int104 - stl data satack structure/c++int104 - stl data satack structure/main.cpp <==
#include <iostream>
#include <string>
#include <stack>

//obj of stack type have 5 main functions .push() pushes data onto stack, .top() returns object at top of stack, .pop() deletes object at top of stack(), .empty() returns true if stack is empty, .size() returns size of stack

using namespace std;

class testClass {
	int x;
	int y;
public:
	testClass(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {
	cin.exceptions(ios_base::failbit);
	stack<int> intList, intTemp;
	stack<string> strList, strTemp;
	stack<testClass> objList;
	testClass obj;
	int num = 0, i, num2;
	string str;

	for (i = 0; i < 5; i++) {
		do {
			if (num == 0) {
				cout << "Enter an integer for the stack: ";
			}
			try {
				cin >> num;
			}
			catch (exception e) {
				cout << "Valid integer was not entered\n";
				cin.clear();
				cin.ignore(100, '\n');
				num = 0;
			}
			cout << endl;
		} while (num == 0);
		intList.push(num);
		num = 0;
		cin.clear();
		cin.ignore(100, '\n');
	}

	intTemp = intList;

	for (i = 0; i < 5; i++) {
		cout << intTemp.top() << " ";
		intTemp.pop();
	}

	for (i = 0; i < 5; i++) {
		cout << "\nEnter a string : ";
		cin >> str;
		strList.push(str);
		cin.clear();
		cin.ignore(100, '\n');
	}

	strTemp = strList;
	for (i = 0; i < 5; i++) {
		cout << strTemp.top() << " ";
		strTemp.pop();
	}

	for (i = 0; i < 5; i++) {
		do {
			if (num == 0) {
				cout << "\nEnter x and y data for the class: ";
			}
			try {
				cin >> num >> num2;
			}
			catch (exception e) {
				cout << "Valid integer was not entered\n";
				cin.clear();
				cin.ignore(100, '\n');
				num = 0;
				num2 = 0;
			}
		} while ((num == 0)&&(num2 == 0));
		obj.setXY(num,num2);
		objList.push(obj);
		num = 0;
		num2 = 0;
		cin.clear();
		cin.ignore(100, '\n');
	}

	for (i = 0; i < 5; i++) {
		cout << "objList " << i + 1 << " - " << objList.top().getX() << " " << objList.top().getY() << endl;
		objList.pop();
	}

	return 0;
}
==> ./Projects/c++int128 graphs/c++int128 graphs/Abstractgraph.h <==
#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include <iostream>
#include <fstream>
#include <deque>
#include "unorderedlinkedlist.h"
#include "linkedListIterator.h"

using namespace std;

class graphType {
public:
	bool isEmpty() const;
	void createGraph();
	void clearGraph();
	void printGraph() const;
	void depthFirstTraversal();
	void dftAtVertex(int);
	void breadthFirstTraversal();
	graphType(int size = 0);
	~graphType();
protected:
	int maxSize;
	int gSize;
	unorderedLinkedList<int> *graph; //linked list of pointers, 2d array effect
private:
	void dft(int, bool[]);
};

graphType::~graphType() {
	clearGraph();
}

bool graphType::isEmpty() const {
	return (gSize == 0);
}

void graphType::createGraph() {
	ifstream infile;
	char fileName[50];
	int index, vertex, adjacentVertex;
	if (gSize != 0) {
		clearGraph();
	}
	cout << "Enter file name: ";
	cin >> fileName;
	cout << endl;
	infile.open(fileName);
	if (!infile) {
		cout << "Cannot open file\n";
		return;
	}
	infile >> gSize;
	for (index = 0; index < gSize; index++) {
		infile >> vertex;
		infile >> adjacentVertex;
		while (adjacentVertex != -999) {
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}
	infile.close();
}

void graphType::clearGraph() {
	for (int index = 0; index < gSize; index++) {
		graph[index].destroyList();
	}
	gSize = 0;
}

void graphType::printGraph() const {
	for (int index = 0; index < gSize; index++) {
		cout << "index " << index << ": ";
		graph[index].print();
		cout << endl;
	}
	cout << endl;
}

graphType::graphType(int size) {
	maxSize = size;
	gSize = 0;
	graph = new unorderedLinkedList<int>[size];
}

void graphType::dft(int i, bool visited[]) { //depth first traversal
	visited[i] = true;
	cout << " " << i << " ";
	linkedListIterator<int> iter;
	for (iter = graph[i].begin(); iter != graph[i].end(); ++iter) {
		int w = *iter;
		if (!visited[w]) {
			dft(w, visited);
		}
	}
}

void graphType::depthFirstTraversal() {
	bool *visited; //pointer to create array to store visited vertices
	visited = new bool[gSize];
	int index;
	for (index = 0; index < gSize; index++)
		visited[index] = false;
	//for vertices not visited, perform depth first traversal
	for (index = 0; index < gSize; index++) {
		if (!visited[index]) {
			dft(index, visited);
		}
	}
	delete[] visited;
}

void graphType::dftAtVertex(int vertex) {
	bool *visited;
	visited = new bool[gSize];
	for (int index = 0; index < gSize; index++) {
		visited[index] = false;
	}
	dft(vertex, visited);
	delete[] visited;
}

void graphType::breadthFirstTraversal() {
	deque<int> queue;
	bool *visited;
	visited = new bool[gSize];
	for (int i = 0; i < gSize; i++) {
		visited[i] = false;
	}
	linkedListIterator<int> iter;
	for (int index = 0; index < gSize; index++) {
		if (!visited[index]) {
			queue.push_front(index);
			visited[index] = true;
			cout << " " << index << " ";
			while (!queue.empty()) {
				int u = queue.front();
				queue.pop_front();
				for (iter = graph[u].begin(); iter != graph[u].end(); ++iter) {
					int w = *iter;
					if (!visited[w]) {
						queue.push_front(w);
						visited[w] = true;
						cout << " " << w << " ";
					}
				}
			}
		}
	}
	delete[] visited;
}

#endif
==> ./Projects/c++int128 graphs/c++int128 graphs/linkedListClass.h <==
#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <iostream>
#include <cassert>
#include "Linkedlistiterator.h"

using namespace std;

template <typename Type> class linkedListType {
public:
	const linkedListType<Type>& operator=(const linkedListType<Type> &rhs);
	bool operator==(const linkedListType<Type> &rhs) {
		node<Type> *current = first, *rhscurrent = rhs.first;
		while ((current != NULL) && (rhscurrent != NULL)) {
			if (current->info != rhscurrent->info) {
				return false;
			}
			else {
				current = current->link;
				rhscurrent = rhscurrent->link;
			}
		}
		if ((current == NULL) && (rhscurrent == NULL)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const linkedListType<Type> &rhs) {
		node<Type> *current = first, *rhscurrent = rhs.first;
		while ((current != NULL) && (rhscurrent != NULL)) {
			if (current->info != rhscurrent->info) {
				return true;
			}
			else {
				current = current->link;
				rhscurrent = rhscurrent->link;
			}
		}
		if ((current == NULL) && (rhscurrent == NULL)) {
			return false;
		}
		else {
			return true;
		}
	}
	void initializeList(); //initializes list
	bool isEmptyList() const; //returns true if list is empty
	void print() const; //prints list
	int length() const; //returns length of the list
	void destroyList(); //destroys the list
	Type front() const; // returns value at front of list
	Type back() const; //returns value at end of list
	virtual bool search(const Type&) const = 0; //will differ for ordered and nordered lists
	virtual void insertFirst(const Type&) = 0;
	virtual void insertLast(const Type&) = 0;
	virtual void deleteNode(const Type&) = 0;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType(); //default constructor
	linkedListType(const linkedListType<Type>&); //copy constructor
	~linkedListType(); //destructor
protected:
	int count;
	node<Type> *first;
	node<Type> *last;
private:
	void copyList(const linkedListType<Type>&);
};

template <typename Type> void linkedListType<Type>::destroyList() {
	node<Type> *temp;
	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	first = NULL;
	last = NULL;
	count = 0;
}

template <typename Type> void linkedListType<Type>::copyList(const linkedListType<Type>& rhs) {
	node<Type> *newNode, *current;
	if (first != NULL) {
		destroyList();
	}
	if (rhs.first == NULL) {
		first = NULL;
		last = NULL;
		count = 0;
	}
	else {
		current = rhs.first; //value of first node is copied
		count = rhs.count; //value of count is copied
		first = new node<Type>; //first created as new node
		first->info = current->info; //value of current info assigned to first->info
		first->link = NULL; //pointer field of first set to null
		last = first;
		current = current->link; //current set to next value in list
		while (current != NULL) {
			newNode = new node<Type>; //newNode created for storage
			newNode->info = current->info; //info in current stored in newNode
			newNode->link = NULL; //pointer in newNode set to null
			last->link = newNode; //link in previous node now points to newNode
			last = newNode; //last is now equal to newNode, last->link = NULL;
			current = current->link; //current has value of next node
		}
		/*although we need the pointer in current to traverse the linked list, to avoid a shallow copy, new memory
		addresses should be formed. newNode is needed for this purpose
		*/
	}
}

template <typename Type> bool linkedListType<Type>::isEmptyList() const {
	return (first == NULL);
}

template <typename Type> linkedListType<Type>::linkedListType() {
	first = NULL;
	last = NULL;
	count = 0;
}

template <typename Type> linkedListType<Type>::~linkedListType() {
	destroyList();
}

template <typename Type> linkedListType<Type>::linkedListType(const linkedListType<Type> &rhs) {
	first = NULL;
	copyList(rhs);
}

/*template <typename Type> bool linkedListType<Type>::operator!=(const linkedListType<Type> &rhs) const {
bool found = false;
node<Type> *current = first, *rhscurrent = rhs.first;
if ((current == NULL) && (rhscurrent == NULL)) {
return false;
}
else {
while ((current != NULL) && (rhscurrent != NULL)) {
if (current->info == rhscurrent->info) {
current = current->link;
rhscurrent = rhscurrent->link;
}
else {
return true;
}
}
if ((current == NULL) && (rhscurrent == NULL)) {
return false;
}
else {
return true;
}
}
}*/

template <typename Type> const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type> &rhs) {
	copyList(rhs);

	return *this;
}

/*template <typename Type> bool linkedListType<Type>::operator==(const linkedListType<Type> &rhs) const {
bool output = true;
node<Type> *rhscurrent = rhs.first;
node<Type> *current = first;
while ((current != NULL) && (rhscurrent != NULL)) {
if (current->info != rhscurrent->info) {
output = false;
break;
}
else {
current = current->link;
rhscurrent = rhscurrent->link;
}
}
if ((current == NULL) && (rhscurrent == NULL) && (output == true)) {
return output;
}
else {
output = false;
return output;
}
}*/

template <typename Type>
void linkedListType<Type>::initializeList() {
	destroyList();
}

template <typename Type>
void linkedListType<Type>::print() const {
	node<Type> *current;
	current = first;
	if (current == NULL) {
		cout << "list is empty\n";
	}
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
}

template <typename Type> int linkedListType<Type>::length() const {
	return count;
}

template <typename Type> Type linkedListType<Type>::front() const {
	assert(first != NULL);
	return first->info;
}

template <typename Type> Type linkedListType<Type>::back() const {
	assert(last != NULL);
	return last->info;
}

template <typename Type> linkedListIterator<Type> linkedListType<Type>::begin() {
	linkedListIterator<Type> temp(first);
	return temp;
}

template <typename Type> linkedListIterator<Type> linkedListType<Type>::end() {
	linkedListIterator<Type> temp(NULL);
	return temp;
}

#endif
==> ./Projects/c++int128 graphs/c++int128 graphs/linkedListIterator.h <==
#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

template <typename Type>
struct node {
	Type info;
	node<Type> *link;
};

//goes through 
template <typename Type>
class linkedListIterator {
	node<Type> *current;
public:
	linkedListIterator(); //default constructor
	linkedListIterator(node<Type>*); //constructor with parameters
	Type operator*(); //dereference operator
	linkedListIterator<Type> operator++(); //increment operator
	bool operator==(const linkedListIterator<Type>&) const;
	bool operator!=(const linkedListIterator<Type>&) const;
};

template <typename Type>
linkedListIterator<Type>::linkedListIterator() {
	current = NULL;
}

template <typename Type>
linkedListIterator<Type>::linkedListIterator(node<Type> * ptr) {
	current = ptr;
}

template <typename Type>
Type linkedListIterator<Type>::operator *() {
	return current->info;
}

template <typename Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
	current = current->link;
	return *this;
}

template <typename Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& rhs) const {
	return (current == rhs.current);
}

template <typename Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& rhs) const {
	return (current != rhs.current);
}
#endif

==> ./Projects/c++int128 graphs/c++int128 graphs/main.cpp <==
#include <iostream>
#include "WeightedGraphType.h"

using namespace std;

int main() {
	unorderedLinkedList<int> list1;
	weightedGraphType graph(7);
	graph.createGraph();
	graph.printGraph();
	cout << endl;
	cout << "breadth first :\n";
	graph.breadthFirstTraversal();
	cout << endl;
	graph.depthFirstTraversal();
	cout << endl;
	graph.dftAtVertex(3);
	cout << endl;

	system("PAUSE");
	return 0;
}
==> ./Projects/c++int128 graphs/c++int128 graphs/unorderedlinkedlist.h <==
#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <iostream>
#include "LinkedListClass.h"

using namespace std;

template <typename Type> class unorderedLinkedList : public linkedListType<Type> {
public:
	bool search(const Type&) const;
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
};


/*template <typename Type> bool unorderedLinkedList<Type>::operator==(const unorderedLinkedList<Type> &rhs) {
node<Type> *current = first, *rhscurrent = rhs.first;
while ((current != NULL) && (rhscurrent != NULL)) {
if (current->info != rhscurrent->info) {
return false;
}
else {
current = current->link;
rhscurrent = rhscurrent->link;
}
}
if ((current == NULL) && (rhscurrent == NULL)) {
return true;
}
else {
return false;
}
}

template <typename Type> bool unorderedLinkedList<Type>::operator!=(const unorderedLinkedList<Type> &rhs) {
node<Type> *current, *rhscurrent;
current = new node<Type>;
rhscurrent = new node<Type>;
current = first;
rhscurrent = rhs.first;
while ((current != NULL) && (rhscurrent != NULL)) {
if (current->info != rhscurrent->info) {
return true;
}
else {
current = current->link;
rhscurrent = rhscurrent->link;
}
}
if ((current == NULL) && (rhscurrent == NULL)) {
return false;
}
else {
return true;
}
}*/

template <typename Type> bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
	node<Type> *current;
	bool found = false;
	current = first;
	while ((current != NULL) && (!found)) {
		if (current->info == searchItem) {
			found = true;
		}
		else {
			current = current->link;
		}
	}
	return found;
}

template <typename Type> void unorderedLinkedList<Type>::insertFirst(const Type &item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = first;
	first = newNode;
	count++;
	if (last == NULL) {
		last = newNode;
	}
}

template <typename Type> void unorderedLinkedList<Type>::insertLast(const Type& item) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = item;
	newNode->link = NULL;
	if (first == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->link = newNode;
		last = newNode;
	}
}

template <typename Type> void unorderedLinkedList<Type>::deleteNode(const Type&item) {
	node<Type> *current, *trailCurrent;
	bool found;
	if (first == NULL) {
		cout << "The list is empty\n";
	}
	else {
		if (first->info == item) {
			current = first;
			first = first->link;
			count--;
			if (first == NULL) {
				last = NULL;
			}
			delete current;
		}
		else {
			found = false;
			trailCurrent = first;
			current = first->link;
			while ((current != NULL) && (!found)) {
				if (current->info != item) {
					trailCurrent = current;
					current = current->link;
				}
				else {
					found = true;
				}
			}
			if (found) {
				trailCurrent->link = current->link;
				count--;
				if (last == current) {
					last = trailCurrent;
				}
				delete current;
			}
			else {
				cout << "Item not found in list\n";
			}
		}
	}
}

#endif
==> ./Projects/c++int128 graphs/c++int128 graphs/WeightedGraphType.h <==
#ifndef WEIGHTEDGRAPHTYPE_H
#define WEIGHTEDGRAPHTYPE_H
#include <iostream>
#include <iomanip>
#include "Abstractgraph.h"

using namespace std;

class weightedGraphType : public graphType {
public:
	void createWeightedGraph();
	void shortestPath(int);
	void printShortestDistance(int);
	weightedGraphType(int size = 0);
	~weightedGraphType();
protected:
	double **weights;
	double *smallestWeight;
};

void weightedGraphType::shortestPath(int vertex) {
	for (int i = 0; i < gSize; i++) {
		smallestWeight[i] = weights[vertex][i]; //store weights at vertex into smalles weight container
	}
	bool *weightFound;
	weightFound = new bool[gSize];
	for (int i = 0; i < gSize; i++) {
		weightFound[i] = false;
	}
	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;
	for (int i = 0; i < gSize; i++) {
		double minWeight = 1000000.0;
		int v;
		for (int i = 0; i < gSize; i++) { 
			if (!weightFound[i]) {
				if (smallestWeight[i] < minWeight) {
					v = i;
					minWeight = smallestWeight[v];
				}
			}
		}
		weightFound[v] = true;
		for (int i = 0; i < gSize; i++) {
			if (!weightFound[i]) {
				if (minWeight + weights[v][i] < smallestWeight[i]) {
					smallestWeight[i] = minWeight + weights[v][i];
				}
			}
		}
	}
}

void weightedGraphType::printShortestDistance(int vertex) {
	cout << "Source vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex" << endl;
	cout << "Vertex     Shortest Distance\n";
	for (int i = 0; i < gSize; i++) {
		cout << setw(4) << i << setw(12) << smallestWeight[i] << endl;
	}
	cout << endl;
}

weightedGraphType::weightedGraphType(int size) : graphType(size) {
	weights = new double*[size];
	for (int i = 0; i < size; i++) {
		weights[i] = new double[size];
	}
	smallestWeight = new double[size];
}

weightedGraphType::~weightedGraphType() {
	for (int i = 0; i < gSize; i++) {
		delete[] weights[i];
	}
	delete[] weights;
	delete smallestWeight;
}

void weightedGraphType::createWeightedGraph() {
	graphType::createGraph();
}

#endif
==> ./Projects/calculator/calculator/main.cpp <==
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
	char ch;
	string line;
	int tempint = 0;
	multiset<int> viewslist;
	fstream myfile;
	int count = 0;
	
	myfile.open("C:/Users/Leslie/Documents/numbers.txt");
	if (!myfile.is_open()) {
		cout << "Error opening input file\n";
	}
	else {
		while (getline(myfile, line)) {
			tempint = stoi(line);
			viewslist.insert(tempint);
		}
	}

	for (auto i : viewslist) {
		count ++;
		cout << "count = " << count << " " << i << endl;
	}

	return 0;
}
==> ./Projects/card-deck-shuffle/card-deck-shuffle/main.cpp <==
#include <iostream>
#include <random>
#include <vector>

using namespace std;

enum suit { Clubs, Diamonds, Hearts, Spades };
enum cardno { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct Card {
	enum suit newSuit;
	enum cardno newCardno;
};

void swap(Card& A, Card& B);

void shuffle(vector<Card> &Deck);

int main() {
	vector<Card> Deck;
	Card newCard;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			newCard.newSuit = suit(i);
			newCard.newCardno = cardno(j);
			Deck.push_back(newCard);
		}
	}

	shuffle(Deck);
	for (auto i : Deck) {
		cout << i.newSuit << " " << i.newCardno << endl;
	}

	return 0;
}

void swap(Card &A, Card &B) {
	Card temp = A;
	A = B;
	B = temp;
}

void shuffle(vector<Card> &Deck) {
	for (int i = 0; i < 250; ++i) {
		swap(Deck[rand() % 52], Deck[rand() % 52]);
	}
}
==> ./Projects/card-deck-shuffle-strings/card-deck-shuffle-strings/main.cpp <==
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <set>
#include <string>

using namespace std;

struct Card {
	char newSuit;
	char newCardno;
};

void populateDeck(vector<Card> &Deck);
void shuffle(vector<Card> &Deck);
void swap(Card& A, Card& B);
void printDeck(const vector<Card> &Deck);
int createPlayers();
int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers);
void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers);
void cardPermutations(int combos[][5]);
void clearLast(vector<vector<Card>> &hands, vector<Card> &faceup, const int &noplayers);

int main() {
	vector<Card> Deck;
	vector<vector<Card>> hands;
	vector<Card> faceup;
	int noofplayers;
	int position;
	char answer;

	populateDeck(Deck);
	printDeck(Deck);
	shuffle(Deck);
	printDeck(Deck);

	noofplayers = createPlayers();
	
	do {
		shuffle(Deck);
		position = dealHands(Deck, hands, noofplayers);
		dealFlop(Deck, faceup, position);
		dealTurn(Deck, faceup, position);
		dealRiver(Deck, faceup, position);

		for (auto i : faceup) {
			cout << i.newCardno << " " << i.newSuit << "  ";
		}
		cout << "\n\n";
		constructScores(hands, faceup, noofplayers);
		clearLast(hands, faceup, noofplayers);
		do {
			cout << "\nWant to play another rounnd? (Y/N)";
			cin >> answer;
		} while ((answer != 'y') && (answer != 'Y') && (answer != 'N') && (answer != 'n'));
	} while ((answer == 'y') || (answer == 'Y'));
	
	return 0;
}


void populateDeck(vector<Card> &Deck) {
	if (Deck.size() > 0) {
		for (int i = 0; i < Deck.size(); ++i) {
			Deck.pop_back();
		}
	}
	Card newCard;
	char suit[] = { (char)3, (char)4, (char)5, (char)6 };
	char cardno[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			newCard.newSuit = suit[i];
			newCard.newCardno = cardno[j];
			Deck.push_back(newCard);
		}
	}
}

void printDeck(const vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		cout << Deck[i].newCardno << " " << Deck[i].newSuit << endl;
	}
	cout << endl;
}

void swap(Card &A, Card &B) {
	Card temp = A;
	A = B;
	B = temp;
}

void shuffle(vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		swap(Deck[i], Deck[(rand() + time(0)) % 52]);
	}
}

int createPlayers() {
	int noplayers;
	do {
		cout << "How many players would you like to enter? ";
		try {
			cin >> noplayers;
		}
		catch (exception e) {
			cout << "You didn't enter an integer\n";
			cin.clear();
			cin.ignore(100, '\n');
			noplayers = 0;
		}
		if ((noplayers < 2) || (noplayers > 10)) {
			cout << "Please enter a number of players between 2-10";
		}
	} while ((noplayers < 2) || (noplayers > 10));
	return noplayers;
}

int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers) {
	int position = 0;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < noplayers; ++j) {
			hands.push_back(vector<Card>());
			hands[j].push_back(Deck[position]);
			++position;
		}
	}

	for (int i = 0; i < noplayers; ++i) {
		cout << "Hand " << i;
		for (int j = 0; j < 2; ++j) {
			cout << ": " << hands[i][j].newCardno << " " << hands[i][j].newSuit << "  ";
		}
		cout << "\n\n";
	}

	return position;
}

void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	for (int i = 0; i < 3; ++i) {
		faceup.push_back(Deck[position]);
		++position;
	}
}

void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void cardPermutations(int combos[][5]) {
	int allcards[7] = { 0, 1, 2, 3, 4, 5, 6 };
	string temp = "";
	set<string> combinations;

	for (int j = 1; j < 7; ++j) {
		for (int k = 1; k < 7; ++k) {
			if (allcards[k] != allcards[j]) {
				temp += (allcards[k] + 48);
			}
		}
		if (temp != "") {
			combinations.insert(temp);
			temp = "";
		}
	}
	for (int i = 0; i < 7; ++i) {
		for (int k = 1; k < 7; ++k) {
			for (int j = 0; j < 7; ++j) {
				if ((j != k) && (i != j) && (i != k)) {
					temp += (allcards[j] + 48);
				}
			}
			if (temp != "") {
				combinations.insert(temp);
				temp = "";
			}
		}
	}

	int count = 0;
	for (auto i : combinations) {
		for (int j = 0; j < 5; ++j) {
			combos[count][j] = (int)(i[j] - 48);
		}
		++count;
	}
}

void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers) {
	int npermutations[21][5];
	cardPermutations(npermutations);
	Card hriver[7];
	Card cpermutations[21][5];
	int points[21][2];
	//vector<vector<Card>> hscore;
	//vector<multiset<int>> cardnos;
	//vector<int> mostarray;
	//int highest = 0;

	for (int j = 0; j < 5; ++j) {
		hriver[j + 2] = faceup[j];
	}

	for (int i = 0; i < noplayers; ++i) {
		int most[2] = { 0, 0 };
		for (int i = 0; i < 21; ++i) {
			for (int j = 0; j < 6; ++j) {
				points[i][j] = 0;
			}
		}
		for (int j = 0; j < 2; ++j) {
			hriver[j] = hands[i][j];
		}
		for (int k = 0; k < 21; ++k) {
			for (int l = 0; l < 5; ++l) {
				cpermutations[k][l] = hriver[npermutations[k][l]];
			}
		}

		for (int k = 0; k < 21; ++k) {
			if ((cpermutations[k][0].newSuit == cpermutations[k][1].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][2].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][3].newSuit) && 
				(cpermutations[k][0].newSuit == cpermutations[k][4].newSuit) ) { //flush
				points[k][0] += 1024;
			}
			set<int> straight;
			for (int l = 0; l < 5; ++l) {
				switch (cpermutations[k][l].newCardno) {
				case 'A': straight.insert(1); straight.insert(14); break;
				case '2': straight.insert(2); break;
				case '3': straight.insert(3); break;
				case '4': straight.insert(4); break;
				case '5': straight.insert(5); break;
				case '6': straight.insert(6); break;
				case '7': straight.insert(7); break;
				case '8': straight.insert(8); break;
				case '9': straight.insert(9); break;
				case 'T': straight.insert(10); break;
				case 'J': straight.insert(11); break;
				case 'Q': straight.insert(12); break;
				case 'K': straight.insert(13); break;
				}
				if (straight.size() >= 5) {
					int strait[5];
					int strai2[5] = { 0,0,0,0,0 };
					int m = 0; int n = -1;
					for (auto i2 : straight) {
						if (m <= 4){
							strait[m] = i2;
						}
						if ((n >= 0)&&(n <= 4)) {
							strai2[n] = i2;
						}
						++m;
						++n;
					}
					m = 4; n = 4;
					while (m > 0) {
						if (strait[m] - strait[m - 1] == 1) {
							--m;
						}
						else {
							m = -1;
						}
					}
					if (straight.size() == 6) {
						while (n > 0) {
							if (strai2[n] - strai2[n - 1] == 1) {
								--n;
							}
							else {
								n = -1;
							}
						}
					}
					if (n == 0) {
						for (int i2 = 0; i2 < 5; ++i2) {
							strait[i2] = strai2[i2];
						}
					}
					if ((m == 0)||(n == 0)) { //straight 
						points[k][0] += 256;
						if ((cpermutations[k][0].newSuit == cpermutations[k][1].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][2].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][3].newSuit) &&
							(cpermutations[k][0].newSuit == cpermutations[k][4].newSuit)) { //straight flush
							points[k][0] += 65536;
						}
					}
				}
			}

			for (int l = 0; l < 5; ++l) {
				for (int m = 0; m < 5; ++m) {
					if ((l != m) && (l < m)) {
						if (cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) { //pair
							points[k][0] += 4;
							for (int n = 0; n < 5; ++n) {
								if ((l != m) && (m != n) && (l < m) && (m < n)) {
									if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][l].newCardno == cpermutations[k][n].newCardno)) { //triples
										points[k][0] += 64;
									}
								}
								for (int o = 0; o < 5; ++o) {
									if ((l != m) && (l != n) && (l != o) && (m != n) && (m != o) && (n != o) && (l < m) && (n < o)) {
										if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)) { //two pair
											points[k][0] += 16;
											for (int p = 0; p < 5; ++p) {
												if ((o != p)&&(p !=m) &&(p != n) && (p!= l) && (l==0)) {
													if ((cpermutations[k][l].newCardno == cpermutations[k][p].newCardno) || (cpermutations[k][p].newCardno == cpermutations[k][o].newCardno)) { //full house
														points[k][0] += 4096;
													}
												}
											}
										}
										if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)
											&& (cpermutations[k][n].newCardno == cpermutations[k][l].newCardno) && ((l==0)||(l==1)) && ((m ==1)||(m==2)) && ((n==2)||(n==3)) && ((o==3)||(o==4))) { //four of a kind
											points[k][0] += 16384;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		for (int k = 0; k < 21; ++k) {
			if (points[k][0] > most[0]) {
				most[0] = points[k][0];
			}
		}

		//mostarray.push_back(most[0]);

		for (int k = 0; k < 21; ++k) {
			if ((((most[0] >= 0)&&(most[0] < 4)) && ((points[k][0] >= 0)&&(points[k][0] < 4))) //High Card
				|| (((most[0] >= 4) && (most[0] < 16)) && ((points[k][0] >= 4) && (points[k][0] < 16))) //Pair
				|| (((most[0] >= 16) && (most[0] < 64)) && ((points[k][0] >= 16) && (points[k][0] < 64))) //Two pair
				|| (((most[0] >= 64) && (most[0] < 256)) && ((points[k][0] >= 64) && (points[k][0] < 256))) //Triple
				|| (((most[0] >= 256) && (most[0] < 1024)) && ((points[k][0] >= 256) && (points[k][0] < 1024))) //Straight
				|| (((most[0] >= 1024) && (most[0] < 4096)) && ((points[k][0] >= 1024) && (points[k][0] < 4096))) //Flush
				|| (((most[0] >= 4096) && (most[0] < 16384)) && ((points[k][0] >= 4096) && (points[k][0] < 16384))) //Full House
				|| (((most[0] >= 16384) && (most[0] < 65536)) && ((points[k][0] >= 16384) && (points[k][0] < 65536))) //Four of a kind
				|| ((most[0] >= 65536) && (points[k][0] >= 65536))) { //Straight Flush
				for (int l = 0; l < 5; ++l) {
					switch (cpermutations[k][l].newCardno) {
					case 'A': points[k][1] += 14; break;
					case '2': points[k][1] += 2; break;
					case '3': points[k][1] += 3; break;
					case '4': points[k][1] += 4; break;
					case '5': points[k][1] += 5; break;
					case '6': points[k][1] += 6; break;
					case '7': points[k][1] += 7; break;
					case '8': points[k][1] += 8; break;
					case '9': points[k][1] += 9; break;
					case 'T': points[k][1] += 10; break;
					case 'J': points[k][1] += 11; break;
					case 'Q': points[k][1] += 12; break;
					case 'K': points[k][1] += 13; break;
					}
				}
			}
		}
		
		for (int k = 0; k < 21; ++k) {
			if (points[k][1] > most[1]) {
				most[1] = points[k][1];
			}
		}
		/*for (int k = 0; k < 21; ++k) {
			if (points[k][1] == most[1]) {
				hscore.push_back(vector<Card>());
				for (int l = 0; l < 5; ++l) {
					hscore[i].push_back(cpermutations[k][l]);
				}
				break;
			}
		}

		cout << "\nPlayer " << i << ": ";
		for (int k = 0; k < 5; ++k) {
			cout << hscore[i][k].newCardno << " " << hscore[i][k].newSuit << "  ";
		}*/
 		if (most[0] >= 65536) {
			cout << "Straight flush!\n";
		}
		else if (most[0] >= 16384) {
			cout << "Four of a kind!\n";
		}
		else if (most[0] >= 4096) {
			cout << "Full house!\n";
		}
		else if (most[0] >= 1024) {
			cout << "Flush!\n";
		}
		else if (most[0] >= 256) {
			cout << "Straight!\n";
		}
		else if (most[0] >= 64) {
			cout << "Triple!\n";
		}
		else if (most[0] >= 16) {
			cout << "Two pair!\n";
		}
		else if (most[0] >= 4) {
			cout << "A pair!\n";
		}
		else {
			cout << "High card\n";
		}
	}

	/*for (int i = 0; i < noplayers; ++i) {
		if (mostarray[i] > highest) {
			highest = mostarray[i];
		}
	}*/

	/*int h = 0;
	for (int i = 0; i < noplayers; ++i) {
		if ((((highest >= 0) && (highest < 4)) && ((mostarray[i] >= 0) && (mostarray[i] < 4))) //High Card
			|| (((highest >= 4) && (highest < 16)) && ((mostarray[i] >= 4) && (mostarray[i] < 16))) //Pair
			|| (((highest >= 16) && (highest < 64)) && ((mostarray[i] >= 16) && (mostarray[i] < 64))) //Two pair
			|| (((highest >= 64) && (highest < 256)) && ((mostarray[i] >= 64) && (mostarray[i] < 256))) //Triple
			|| (((highest >= 256) && (highest < 1024)) && ((mostarray[i] >= 256) && (mostarray[i] < 1024))) //Straight
			|| (((highest >= 1024) && (highest < 4096)) && ((mostarray[i] >= 1024) && (mostarray[i] < 4096))) //Flush
			|| (((highest >= 4096) && (highest < 16384)) && ((mostarray[i] >= 4096) && (mostarray[i] < 16384))) //Full House
			|| (((highest >= 16384) && (highest < 65536)) && ((mostarray[i] >= 16384) && (mostarray[i] < 65536))) //Four of a kind
			|| ((highest >= 65536) && (mostarray[i] >= 65536))) { //Straight Flush
			cardnos.push_back(multiset<int>());
			for (int j = 0; j < 5; ++j) {
				switch (hscore[i][j].newCardno) {
				case 'A': cardnos[h].insert(14); break;
				case '2': cardnos[h].insert(2); break;
				case '3': cardnos[h].insert(3); break;
				case '4': cardnos[h].insert(4); break;
				case '5': cardnos[h].insert(5); break;
				case '6': cardnos[h].insert(6); break;
				case '7': cardnos[h].insert(7); break;
				case '8': cardnos[h].insert(8); break;
				case '9': cardnos[h].insert(9); break;
				case 'T': cardnos[h].insert(10); break;
				case 'J': cardnos[h].insert(11); break;
				case 'Q': cardnos[h].insert(12); break;
				case 'K': cardnos[h].insert(13); break;
				}
			}
			++h;
		}
	}*/
}

void clearLast(vector<vector<Card>> &hands, vector<Card> &faceup, const int &noplayers) {
	for (int i = 0; i < noplayers; ++i) {
		for (int j = 0; j < 2; ++j) {
			hands[i].pop_back();
		}
	}

	for (int i = 0; i < 5; ++i) {
		faceup.pop_back();
	}
}
==> ./Projects/class templates/class templates/ArrayListType.h <==
#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H
#include <iostream>
#include <string>

using namespace std;

template <typename elemType>
class ArrayListType {
protected:
	elemType *list;
	int length;
	int maxSize;
public:
	ArrayListType(int size = 100);
	ArrayListType(const ArrayListType<elemType>&);
	virtual ~ArrayListType();
	const ArrayListType<elemType>& operator=(const ArrayListType<elemType>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int, const elemType&) const;
	void removeAt(int);
	void retrieveAt(int, elemType&) const;
	void clearList();

	virtual void insertAt(int, const elemType&) = 0;
	virtual void insertEnd(const elemType&) = 0;
	virtual void replaceAt(int, const elemType&) = 0;
	virtual void remove(const elemType&) = 0;
	virtual int seqSearch(const elemType&) const = 0;
};

template <typename elemType>
ArrayListType<elemType>::ArrayListType(int size) {
	if (size <= 0) {
		cout << "Array size must be positive, creating default array size of 100\n";
		maxSize = 100;
	}
	else {
		maxSize = size;
	}
	length = 0;
	list = new elemType[maxSize];
}

template <typename elemType>
ArrayListType<elemType>::ArrayListType(const ArrayListType<elemType> &rhs) {
	maxSize = rhs.maxSize;
	length = rhs.length;
	list = new elemType[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = rhs.list[i];
	}
}

template <typename elemType>
ArrayListType<elemType>::~ArrayListType() {
	delete[] list;
}

template <typename elemType>
const ArrayListType<elemType>& ArrayListType<elemType>::operator=(const ArrayListType<elemType> &rhs) {
	if (this != rhs) {
		delete[] list;
		maxSize = rhs.maxSize;
		length = rhs.length;
		list = new elemType[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

template <typename elemType>
bool ArrayListType<elemType>::isEmpty() const {
	return(length == 0);
}

template <typename elemType>
bool ArrayListType<elemType>::isFull() const {
	return(length == maxSize);
}

template <typename elemType>
int ArrayListType<elemType>::listSize() const {
	return length;
}

template <typename elemType>
int ArrayListType<elemType>::maxListSize() const {
	return maxSize;
}

template <typename elemType>
void ArrayListType<elemType>::clearList() {
	length = 0;
}

template <typename elemType>
void ArrayListType<elemType>::print() const {
	for (int i = 0; i < length; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

template <typename elemType>
bool ArrayListType<elemType>::isItemAtEqual(int loc, const elemType& item) const {
	if ((loc < 0) || (loc >= length)) {
		cout << "The location is out of range.\n";
		return false;
	}
	else {
		return (list[loc] == item);
	}
}

template <typename elemType>
void ArrayListType<elemType>::removeAt(int location) {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range.\n";
	}
	else {
		for (int i = location; i < length - 1; i++) {
			list[i] = list[i + 1];
		}
		length--;
	}
}

template <typename elemType>
void ArrayListType<elemType>::retrieveAt(int location, elemType &item) const {
	if ((location < 0) || (location >= length)) {
		cout << "The location is out of range\n";
	}
	else {
		cout << list[location] << endl;
	}
}

#endif
==> ./Projects/class templates/class templates/main(class templates).cpp <==
#include <iostream>
#include <string>
#include "UnorderedListType.h"

using namespace std;

int main() {
	UnorderedArrayList<string> strList(25);
	UnorderedArrayList<int> intList(25);
	string str;
	int num;
	cout << "Enter 5 strings: ";
	for (int count = 0; count < 5; count++) {
		cin >> str;
		strList.insertEnd(str);
	}
	cout << endl;

	cout << "Enter 5 integers: ";
	for (int count = 0; count < 5; count++) {
		cin >> num;
		intList.insertEnd(num);
	}
	cout << endl;

	cout << "strlist = ";
	strList.print();
	cout << "\nintlist = ";
	intList.print();

	system("PAUSE");
	return 0;
}
==> ./Projects/class templates/class templates/UnorderedListType.h <==
#ifndef UNORDEREDLIST_H
#define UNORDEREDLIST_H
#include <iostream>
#include "ArrayListType.h"

using namespace std;

template <typename elemType>
class UnorderedArrayList : public ArrayListType<elemType> {
public:
	UnorderedArrayList(int size = 100) {
		if (size <= 0) {
			cout << "Size must be a positive integer\n";
			maxSize = 100;
		}
		else {
			maxSize = size;
		}
		list = new elemType[maxSize];
		length = 0;
	}

	void insertAt(int location, const elemType& item) {
		if (length >= maxSize) {
			cout << "Array is already full\n";
		}
		else if ((location < 0) || (location >= length)) {
			cout << "Location exceeds the size of the array\n";
		}
		else {
			for (int i = length; i > location; i--) {
				list[i] = list[i - 1];
			}
			list[location] = item;
			length++;
		}
	}

	void insertEnd(const elemType& item) {
		if (length >= maxSize) {
			cout << "Array is already full\n";
		}
		else {
			list[length] = item;
			length++;
		}
	}

	void replaceAt(int location, const elemType &item) {
		if ((location < 0) || (location >= length)) {
			cout << "Location exceeds the size of the array\n";
		}
		else {
			list[location] = item;
		}
	}

	void remove(const elemType &item) {
		int loc;
		if (length == 0) {
			cout << "The list is empty\n";
		}
		else {
			loc = seqSearch(item);
			if (loc != -1) {
				removeAt(loc);
			}
			else {
				cout << "The item is not on the list\n";
			}
		}
	}

	int seqSearch(const elemType &item) const {
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++) {
			if (list[loc] == item) {
				found = true;
				break;
			}
		}
		if (found) {
			return loc;
		}
		else {
			return -1;
		}
	}
};



#endif // ! UNORDEREDLIST_H

==> ./Projects/complex number calculator/complex number calculator/ComplexNumber.cpp <==
#include <iostream>
#include <string>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber() {
	realpart = 0;
	imagpart = 0;
}

ComplexNumber::ComplexNumber(double real, double imaginary) {
	realpart = real;
	imagpart = imaginary;
}

ComplexNumber::ComplexNumber(const ComplexNumber &rhs) {
	realpart = rhs.realpart;
	imagpart = rhs.imagpart;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &rhs) const {
	ComplexNumber temp;
	temp.realpart = realpart + rhs.realpart;
	temp.imagpart = imagpart + rhs.imagpart;
	return temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &rhs) const {
	ComplexNumber temp;
	temp.realpart = realpart - rhs.realpart;
	temp.imagpart = imagpart - rhs.imagpart;
	return temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs) const {
	ComplexNumber temp;
	temp.realpart = (realpart*rhs.realpart) - (imagpart*rhs.imagpart);
	temp.imagpart = (realpart*rhs.imagpart) + (rhs.realpart*imagpart);
	return temp;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &rhs) const {
	ComplexNumber compconj[3];
	compconj[0] = ComplexNumber(rhs.realpart, -rhs.imagpart);
	compconj[1] = *this * compconj[0];
	compconj[2] = rhs * compconj[0];

	ComplexNumber temp;
	double a = (compconj[1].realpart / compconj[2].realpart);
	double b = (compconj[1].imagpart / compconj[2].imagpart);
	double c = (compconj[1].imagpart / compconj[2].realpart);
	double d = -(compconj[1].realpart / compconj[2].imagpart);

	if (compconj[1].realpart == 0) {
		a = 0; d = 0;
	}
	if (compconj[1].imagpart == 0) {
		b = 0; c = 0;
	}
	if (compconj[2].realpart == 0) {
		a = 0; c = 0;
	}
	if (compconj[2].imagpart == 0) {
		b = 0; d = 0;
	}

	temp.realpart = a + b;
	temp.imagpart = c + d;

	return temp;
}

const ComplexNumber& ComplexNumber::operator=(const ComplexNumber &rhs) {
	realpart = rhs.realpart;
	imagpart = rhs.imagpart;
	return *this;
}

bool ComplexNumber::operator==(const ComplexNumber &rhs) {
	if ((realpart == rhs.realpart) && (imagpart == rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator!=(const ComplexNumber &rhs) {
	if ((realpart == rhs.realpart) && (imagpart == rhs.imagpart)) {
		return false;
	}
	else {
		return true;
	}
}

bool ComplexNumber::operator<(const ComplexNumber &rhs) {
	if (realpart < rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart < rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator<=(const ComplexNumber &rhs) {
	if (realpart < rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart <= rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator>(const ComplexNumber &rhs) {
	if (realpart > rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart > rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator>=(const ComplexNumber &rhs) {
	if (realpart > rhs.realpart) {
		return true;
	}
	else if ((realpart == rhs.realpart) && (imagpart >= rhs.imagpart)) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream &in, ComplexNumber &rhs) {
	in >> rhs.realpart >> rhs.imagpart;
	return in;
}

ostream& operator<<(ostream& out, const ComplexNumber &rhs) {
	out << rhs.realpart << " + " << rhs.imagpart << "i";
	return out;
}
==> ./Projects/complex number calculator/complex number calculator/ComplexNumber.h <==
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

using namespace std;

class ComplexNumber {
public:
	ComplexNumber();
	ComplexNumber(double, double);
	ComplexNumber(const ComplexNumber&);

	double realpart;
	double imagpart;

	ComplexNumber operator+(const ComplexNumber&) const;
	ComplexNumber operator-(const ComplexNumber&) const;
	ComplexNumber operator*(const ComplexNumber&) const;
	ComplexNumber operator/(const ComplexNumber&) const;
	const ComplexNumber& operator=(const ComplexNumber&);
	bool operator<(const ComplexNumber&);
	bool operator>(const ComplexNumber&);
	bool operator>=(const ComplexNumber&);
	bool operator<=(const ComplexNumber&);
	bool operator==(const ComplexNumber&);
	bool operator!=(const ComplexNumber&);
	friend ostream& operator<<(ostream&, const ComplexNumber&);
	friend istream& operator<<(istream&, const ComplexNumber&);
};

#endif
==> ./Projects/complex number calculator/complex number calculator/main(complex number calculator).cpp <==
#include <iostream>
#include <iomanip>
#include <string>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber power(ComplexNumber num, int p);

int main() {
	ComplexNumber *num1;
	double a1 = 1, b1 = 1;

	num1 = new ComplexNumber(a1, b1);

	/*for (int i = 1; i < 100000; i++) {
		//power(*num1, 2);
		cout << "\nPower^4 = " << power(*num1, 4);
		double a = 0.0001; double b = 0.0001;
		a1 += a;
		b1 += b;
		delete num1;
		num1 = new ComplexNumber(a1, b1);
	}
	
	/*ComplexNumber num1(4, 4), num2(4, -4), num3(-4, 4), num4(-4, -4);

	cout << num1 * num1 << endl;
	cout << num2 * num2 << endl;
	cout << num3 * num3 << endl;
	cout << num4 * num4 << endl;

	cout << "\nPower^4 = " << power(*num1, 4);*/

	//cout << (2.5 * 2) % 2 << endl;

	//cout << 5.0 % 2 << endl;
	
	return 0;
}

ComplexNumber power(ComplexNumber num, int p) {
	ComplexNumber temp(num);
	for (int i = 1; i < p; i++) {
		temp = temp * num;
	}
	return temp;
}
==> ./Projects/Concurrent C++ - Thread Management/Concurrent C++ - Thread Management/main.cpp <==
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void DummyCode();

void function_1() {
	cout << "Beauty is only skin deep" << endl;
}

//suppose we have a functor
class Fctor {
public:
	void operator()() {
		for (int i = 0; i > -100; i--) {
			cout << "from t1 " << i << endl;
		}
	}

	void operator()(string& msg) {
		cout << "thread says: " << msg << endl;
		msg = "Trust is the mother of deceit\n";
	}
};

int main() {
	Fctor fct;
	string s = "Where there is trust there is not necessarily love. The two are not equatable.\n";
	thread t1(fct);
	//thread t3((Fctor()));
	thread t2((Fctor()), s); //parameter to a thread is always passed by value

	t2.join();

	cout << s;

	thread t4((Fctor()), ref(s)); //the ref() wrapper allows parameter to be passed to a thread by reference. this can be dangerous as memory is now being shared between threads`
	t4.join();
	cout << "After t4, s = " << s;

	thread t5((Fctor()), move(s));
	t5.join();
	cout << "After t5, s = " << s; //s in main is now empty

	//if function threw ;an exception without try-catch block then if t1.join() was called after, it would not be joined and object would be destroyed
	try {
		for (int i = 0; i < 100; i++) {
			cout << "from main: " << i << endl;
		}
	}
	catch (...) {
		t1.join();
		throw;
	}

	if (t1.joinable()) {
		t1.join();
	}

	//t3.join(); 

	//Another approcah is using RAII - resource acquisition is initialisation. Wrapper class that wraps around tw=1, i.e. Wrapper w(t1), and in destructor call t1.join()
	//This ensures that when Wrapper w goes out of scope t1 will rejoin the main thread

	cout << "\n\n\n";

	cout << "Main thread id is " << this_thread::get_id() << endl;
	cout << "t1 id is " << t1.get_id() << endl;
	cout << "t2 id is " << t2.get_id() << endl;
	//since these threads have rejoined the main thread their id's are now 0

	//Oversubscription is when there are more threads running than CPU cores, this will mean more 'contact switching', leading to degraded performance
	cout << "\n\n\Thread concurrency is : " << thread::hardware_concurrency() << "\n"; //shows how many threads can be running "truly concurrently"

	return 0;
}

void DummyCode() {
	//if run inside main this will not compile, this does not crea a thread t1, reads as declaring fucntion t1 with parameter of pointer to another function, and this function takes no parameter and returns type Fctor
	thread t2(Fctor()); //c++ standard says that whenever syntax can be read as a function declaration it will be treated as a function declaration

	//Using another pair of brackets allows to ecplicitly declare as a functor being passed to t1
	thread t3((Fctor()));

	//thread t1 = t3; this will not compile, must use move() function, threads cannot be copied, only moved
	thread t1 = move(t3); //now this will compile
}
==> ./Projects/Concurrent C++ 1 - introduction/Concurrent C++ 1 - introduction/main.cpp <==
#include <iostream>
#include <thread>

using namespace std;

void function_1() {
	cout << "Beauty is only skin-deep" << endl;
}

void function_2() {
	cout << "So are nerve endings." << endl;
}

int main() {
	thread t1(function_1); //t1 starts running
	t1.join();  // main thread waits for t1 to finish

	//message is printed out by the child thread t1. Two threads running, main thread and t1

	thread t2(function_2);
	t2.detach(); //will sever the connection between main thread and t1, now t1 will run freely on its own -- daemon process
	//main thread finishes running before t2 has a chance to run ressulting in only t1's message output to consolet2.join();
	
	//once detached threads cannot be rejoined, however .joinable() function can be used to test if thread can be joined or not
	if (t2.joinable()) {
		t2.join();
	}

	return 0;
}
==> ./Projects/Concurrent C++ 10 - Time Constraints/Concurrent C++ 10 - Time Constraints/main.cpp <==
#include <iostream>
#include <future>
#include <thread>
#include <mutex>

using namespace std;

int factorial(int N)
{
	int res = 1;
	for (int i = N; i > 1; --i)
	{
		res *= i;
	}
	cout << "Result is: " << res << endl;
	return res;
}

//time functions endig in _for take duration as parameter, those ending in _until take time_point as a parameter
int main()
{
	/* thread */
	std::thread t1(factorial, 6);
	std::this_thread::sleep_for(chrono::milliseconds(3)); //will define how long a thread will sleep for - see Concurrent C++ 6
	chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::seconds(2); //defines a time point for the thread to sleep until
	std::this_thread::sleep_until(tp); 

	/* Mutex */
	std::mutex mu; //mu.lock(), mu.unlock() - not recommended for best practice;
	std::lock_guard<mutex> locker(mu);
	std::unique_lock<mutex> ulocker(mu);
	ulocker.try_lock(); //will attempt to lock, rreturn if unsuccesful
	ulocker.try_lock_for(chrono::nanoseconds(500)); 
	ulocker.try_lock_until(tp);

	/* Condition variable */
	std::condition_variable cond;
	cond.wait_for(ulocker, chrono::microseconds(2));
	cond.wait_until(ulocker, tp);

	/* Future and Promise */
	std::promise<int> p;
	std::future<int> f = p.get_future();
	f.get();
	f.wait();
	f.wait_for(chrono::milliseconds(2));
	f.wait_until(tp);

	/* async */
	std::future<int> fu = async(factorial, 6);

	/* Packaged Task */
	std::packaged_task<int(int)> t(factorial);
	std::future<int> fu2 = t.get_future();
	t(6);
}
==> ./Projects/concurrent c++ 3 - Data Race and Mutex/concurrent c++ 3 - Data Race and Mutex/main.cpp <==
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

std::mutex mu; //mutually exclusive function - used for thread management

void shared_print1(string msg, int id) 
{
	mu.lock(); //whilst printing message other threads will not be able to printthe message
	std::cout << msg << id << endl;
	mu.unlock(); // allows other thread to access and print their message

	/*if exception is thrown before unlock() function called then would be locked forever. Lock guard prevents this below*/
}

void shared_print(string msg, int id)
{
	std::lock_guard<std::mutex> guard(mu); //RAII
	std::cout << msg << id << endl;
}

/*cout is not truly protected by mutex as camn be accessed by oother functions. Better example of mutex/lock_guard use is shown below*/
class LogFile {
	std::mutex m_mutex;
	ofstream f;
public:
	LogFile()
	{
		f.open("log.txt");
	}

	void shared_print(string id, int value)
	{
		std::lock_guard<mutex> locker(m_mutex);
		f << " From " << id << ": " << value << endl;
	}

	/*f is now under the complete protection of the mutex as long as the following conditions are met
	
	- Never return f to the outside world i.e. 
		ofstream& getStream() { return f; }			 as user can access f without going through mutex
	- Never pass f as an argument to a user provided function
		void processf(void fun(ofstream&)) { fun(f); }      Use could copy f to global variable, close f, etc.
	*/
};

class stack {
	int* _datat;
	std::mutex _mu;
public:
	void pop(); //pops off the item on top of the stack
	int& top(); //returns the item on top of the stack
};

void function_1()
{
	for (int i = 0; i > -100; --i)
	{
		//cout << "From t1: " << i << endl;
		shared_print(string("From t1: "), i);
	}
}

void function_2(LogFile& log)
{
	for (int i = 0; i > -100; --i)
	{
		//cout << "From t1: " << i << endl;
		log.shared_print(string("From t1: "), i);
	}
}

void function_3(stack& st)
{
	//would not be threadsafe - see video, either use mutex here or redesign stack
	int v = st.top();
	st.pop();
	//process(v);
}

int main()
{
	LogFile log;
	std::thread t1(function_2, std::ref(log));

	for (int i = 0; i < 100; ++i)
	{
		//cout << "From main: " << i << endl;
		shared_print(string("From main: "), i);
	}

	t1.join();

	system("PAUSE");
	return 0;
}

/*Output is scattered if no mutex is used, this results in data race, where two threads are competing for a common resource (in original case cout)*/
==> ./Projects/Concurrent C++ 4 - Deadlock/Concurrent C++ 4 - Deadlock/main.cpp <==
/*dealoc can be avoided y
1. Prefering to lock a single mutex
2. Avoid locking a mutex and then calling a user provided function
3. Use std::lock() to lock more than one mutex
4. Lock the mutex in the same order

Fine-grained lock protects small amount of data, coarse-grained protects large amounts of data, too coarse-grained results in loss of opportunity for runing multiple threads, too fine-grained could lead to 
potential deadlock*/

#include <iostream>
#include <mutex>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

class LogFile {
	std::mutex _mu;
	std::mutex _mu2;
	ofstream _f;
public:
	LogFile()
	{
		_f.open("log.txt");
	} 

	void shared_print(string id, int value)
	{
		std::lock_guard<std::mutex> locker(_mu);
		std::lock_guard<std::mutex> locker2(_mu2);
		cout << "From " << id << ": " << value << endl;
	}
	void shared_print2(string id, int value)
	{
		std::lock_guard<std::mutex> locker2(_mu2);
		std::lock_guard<std::mutex> locker(_mu);
		//this creates classic deadlock situation. both mutexes are locked at the same time and neither function call can access the other mutex, to avoid deadlock always lock mutexes in the same order
		//this can also be avoided by use of std::lcok demonstrated in shared_print 3 and shared_print4 below
		cout << "From " << id << ": " << value << endl;
	}

	void shared_print3(string id, int value)
	{
		std::lock(_mu, _mu2); //can take arbritrary number of parameters, uses deadlock avoidance algorithm 
		std::lock_guard<std::mutex> locker(_mu, std::adopt_lock);
		std::lock_guard<std::mutex> locker2(_mu2, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
	void shared_print4(string id, int value)
	{
		std::lock(_mu, _mu2);
		std::lock_guard<std::mutex> locker2(_mu2, std::adopt_lock);
		std::lock_guard<std::mutex> locker(_mu, std::adopt_lock);
		cout << "From " << id << ": " << value << endl;
	}
	
	~LogFile()
	{
		_f.close();
	}
};

void function_1(LogFile &log)
{
	for (int i = 0; i > -100; --i)
	{
		log.shared_print2(string("t1"), i);
	}
}

int main()
{
	LogFile log;
	std::thread t1(function_1, std::ref(log));
	for (int i = 0; i < 100; ++i)
	{
		log.shared_print(string("main"), i);
	}
	t1.join();

	return 0;
}
==> ./Projects/Concurrent C++ 5  - unique lock lazy init/Concurrent C++ 5  - unique lock lazy init/main.cpp <==
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class LogFile {
	std::mutex _mu;
	ofstream _f;
public:
	LogFile()
	{
		_f.open("log.txt");
	}
	void shared_print(string id, int value)
	{
		//std::lock_guard<std::mutex> locker(_mu);
		std::unique_lock<std::mutex> locker(_mu); //similar to lock_quard, but allows manual unlock providing more flexibility, however is more heavyweight than lock_huard 
		_f << "From " << id << ": " << value << endl;
		locker.unlock(); 
		//...
	}
	void shared_print2(string id, int value)
	{
		std::unique_lock<std::mutex> locker(_mu, std::defer_lock); //parameter defer lock can also be passed, allowing the lock to be called as and when needed 
		if (true)
		{
			locker.lock();
			//...
			locker.unlock();
		}
		
		//...

		locker.lock();
		//...

		std::unique_lock<std::mutex> locker2 = std::move(locker); //unique_lock like std::lock() cannot be copied, but it can be moved, this gives ownership of the mutex to another lock
	}

	~LogFile()
	{
		_f.close();
	}
};

//THREADSAFE LAZY INITIALIZATION
class LogFile2 {
	std::mutex _mu;
	std::mutex _mu_open_;
	std::once_flag _flag; //used instead of another mutex to deal with file opening problem
	ofstream _f;																											
public:
	LogFile2() {}
	void shared_print_problem(string id, int value)
	{
		std::lock(_mu_open_, _mu);
		
		std::lock(_mu_open_, _mu);
		{
			std::unique_lock<std::mutex> locker2(_mu_open_);
			if (!_f.is_open()) // would require mutex as is not thread safe, lock has to be before the if statement otherwise two threads could recognize !_f.is_open, and open the same log.txt for writing
			{																																											
				_f.open("log.txt");
			} //program will run unecessary locking and unlocking of mutex and file-checking wasting cpu cycles
		}

		std::unique_lock<std::mutex> locker(_mu);
		_f << "From " << id << ": " << value << endl;
	}

	void shared_print_solution(string id, int value)
	{
		std::call_once(_flag, [&]() { _f.open("log.txt"); }); //call_once function passed _flag and lambda function calling _f.open("log.txt") as arguments.  
		//Replaces need for mutex as it makes sure that the lambda function is only called once and by one thread

		std::unique_lock<std::mutex> locker(_mu);
		_f << "From " << id << ": " << value << endl;
	}
};

int main()
{
	system("PAUSE");
	return 0;
}
==> ./Projects/Concurrent C++ 6 - Condition variable/Concurrent C++ 6 - Condition variable/main.cpp <==
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <deque>

using namespace std;

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

void function_1()
{
	int count = 10;
	while (count > 0)
	{
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function_2()
{
	int data = 0;
	while (data != 1)
	{
		std::unique_lock<mutex> locker(mu);
		if (!q.empty())
		{
			data = q.back();
			q.pop_back();
			locker.unlock();
			cout << "t2 got a value from t1: " << data << endl;
		}
		else
		{
			locker.unlock();
		}
	}
}

//the above code is valid, q is a shared object and both threads/functions access via use of a mutex preventing data race, however thread t2 will continue to loop checking if q is empty, grossly inefficient
//use of std::condition_variable cond; can improve matters considerably

void function_1_improved()
{
	int count = 10;
	while (count > 0)
	{
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one(); //notify one waiting thread if there is one (will wake up a thread if there is any waiting on std::condition_variable cod;
		//cond.notify_all(); //would wake up all threads waiting on cond;
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function_2_improved()
{
	int data = 0;
	while (data != 1)
	{
		std::unique_lock<mutex> locker(mu);
		cond.wait(locker, [](){ return !q.empty(); }); //puts thread t2 to sleep until notified by thread t1, cond.wait() takes parameter of std::unique_lock to unlock the mutex before it goes to sleep. 
			//Upon waking up it relocks the mutex. As it has to be lock and unlocked multiple times has to be std::unique_lock and not std::lock_guard 
			//thread t2 could also wake by itself known as a spurious wake, second parameter of lambda function which will check if q is empty and put back to sleep unless q is not empty
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "t2 got a value from t1: " << data << endl;
	}
}


int main()
{
	//std::thread t1(function_1);
	//std::thread t2(function_2);
	std::thread t1(function_1_improved);
	std::thread t2(function_2_improved);
	t1.join();
	t2.join();
	return 0;
}
==> ./Projects/Concurrent C++ 7 - Future Promise async()/Concurrent C++ 7 - Future Promise async()/main.cpp <==

==> ./Projects/Concurrent C++ 7 a Future Promise async/Concurrent C++ 7 a Future Promise async/main.cpp <==
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
//if we want to return the result from the child thread to the parent thread

std::mutex mu; //as x is shared between child and parent thread
std::mutex mu2;
std::condition_variable cond; //need to make sure child thread sets variable before parent thread retrieves it

void factorial(int N, int& x)
{
	std::unique_lock<mutex> locker(mu);
	int res = 1;
	
	for (int i = N; i > 1; --i)
	{
		res *= i;
	}
	std::cout << "Result is: " << res << endl;

	x = res;
	locker.unlock();
	cond.notify_one();
}

int main()
{
	int x = 0;
	std::thread t1(factorial, 4, std::ref(x));

	std::unique_lock<mutex> locker2(mu2);
	cond.wait(locker2); //no way to pass x into lambda function unless it is global variable, mutex header does not seem to allow lambda function with argument to be passed in here
	std::cout << "x is " << x << endl;
	locker2.unlock();
	t1.join();

	return 0; 
}
==> ./Projects/Concurrent C++ 7b Future Promis async/Concurrent C++ 7b Future Promis async/main.cpp <==
//better method than previous is to use a future, doesn't eed mutex and condition_variable globals, nor lock(), unlock(), cond.wait(std::unique_lock<mutex>), cond.notify_one()
#include <iostream>
#include <future>
#include <mutex>

std::mutex mu;

using namespace std;

int factorial(int N)
{
	std::unique_lock<mutex> locker(mu);
	int res = 1;
	for (int i = N; i > 1; --i)
	{
		res *= i;
	}
	cout << "Result is: " << res << endl;

	return res;
}

int factorial2(std::future<int>& f)
{
	std::unique_lock<mutex> locker(mu);
	int res = 1;

	int N = f.get();  //if promise is not set, throws exception std::future_errc::broken_promise
	for (int i = N; i > 1; --i)
	{
		res *= i;
	}
	cout << "Result is: " << res << endl;

	return res;
}

int main()
{
	int x;
	std::future<int> fu3 = std::async(factorial, 2); //async funcion returns a future object, identiacl to syntax below
	std::future<int> fu2 = std::async(std::launch::deferred | std::launch::async, factorial, 3); //standard implementation, deferred waits until get() is called in main class
	std::future<int> fu = std::async(std::launch::async, factorial, 4); //automatically launches new thread

	x = fu.get(); //waits until child thread finishes then returns the return value
	cout << x << endl;
	//fu.get(); can only be called once per future, calling twice willl crash the program

	x = fu2.get();
	cout << x << endl;

	x = fu3.get();
	cout << x << endl;

	//std::future passes value from child thread to parent thread. value can be passed from parent thread to child thread using std::future and std::promise

	std::promise<int> p;
	std::future<int> f = p.get_future();
	
	std::future<int> f2 = std::async(std::launch::async, factorial2, std::ref(f));
	//this tells child thread that we will send it a value, however we don't have the value yet and it will be sent over in the future

	//do something else...
	std::this_thread::sleep_for(chrono::seconds(3));
	int y = 0;

	cout << "Please enter a value less than 10 : ";
	cin >> y;

	if ((y > 0) && (y < 10))
	{
		p.set_value(y); //keeps promise by setting a value
	}
	else
	{
		p.set_exception(std::make_exception_ptr(std::runtime_error("incorrect value entered\n")));
	}

	x = f2.get();
	cout << x << endl;

	//futures and promises cannot be coppied can onle be moved

	//std::future<int> fu2 = fu;     - will not compile
	//std::future fu2 = std::move(fu)     - will compile

	return 0;
}
==> ./Projects/Concurrent C++ 7c shared future/Concurrent C++ 7c shared future/main.cpp <==
#include <iostream>
#include <future>
#include <mutex>

using namespace std;

std::mutex mu;

int factorial(std::shared_future<int> f)
{
	std::unique_lock<mutex> locker(mu);
	int res = 1;

	int N = f.get();
	for (int i = N; i > 1; --i)
	{
		res *= i;
	}

	cout << "Result is: " << res << endl;
	return res;
}

int main()
{
	int x;

	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::shared_future<int> sf = f.share();
	//rather than having to create multiple promises and multiple futures if you want to call the .get() function more than once can create an std::shared_future<template> object, can use .get() multiple times 
	//and pass by value instead of ref

	std::future<int> fu = std::async(std::launch::async, factorial, sf);
	std::future<int> fu2 = std::async(std::launch::async, factorial, sf);
	//...

	p.set_value(4);

	return 0;
}
==> ./Projects/Concurrent C++ 8 - Callable Objects/Concurrent C++ 8 - Callable Objects/main.cpp <==
#include <iostream>
#include <thread>
#include <future>

using namespace std;

class A {
public:
	void f(int x, char c) { }	
	long g(double x) { return 0; }
	int operator()(int N) { return 0; } //makes a a functor
};

void foo(int x) {}

int main() {
	A a;

	std::async(std::launch::async, a, 6);
	std::bind(a, 6);
	std::call_once(once_flag, a, 6);
	//also takes callable object followed by argument(s), std library functions can all take the following thread forms as arguments

	std::thread t1(a, 6); //copy_of_a(6) in a different thread
	std::thread t2(std::ref(a), 6); // a(6) in a different thread
	std::thread t3(A(), 6); //temp A
	std::thread t4([](int x) { return x*x; }, 6); //lambda function
	std::thread t5(foo, 6); //function

	std::thread t6(&A::f, a, 8, 'w'); //copy_of_a.f(8, 'w') in a different thread
	std::thread t7(&A::f, &a, 8, 'w'); // a.f(8, 'w') in a different thread
	std::thread t8(std::move(a), 6); //a no longer usable in main thread

	return 0;
}
==> ./Projects/Concurrent C++ 9 - Packaged Tasks/Concurrent C++ 9 - Packaged Tasks/main.cpp <==
#include <iostream>
#include <future>
#include <thread>
#include <deque>

using namespace std;

int factorial(int N) 
{
	int res = 1;
	for (int i = N; i > 1; --i) 
	{
		res *= i;
	}
	cout << "Result is: " << res << endl;
	return res;
}

std::deque<std::packaged_task<int()> > task_q;
std::mutex mu; //as task_q is being shared between main thread and child thread, mutex mu must be called
std::condition_variable cond;

void thread_1()
{
	std::packaged_task<int()> t;
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, []() { return !task_q.empty(); });
		t = std::move(task_q.front());
		task_q.pop_front(); //pops off front after task is used
	}
	t();
}

int main()
{
	std::packaged_task<int(int)> t(factorial); //t is a task being packaged and can be passed to different places such as threads, functions or objects, integer parameter in template argument for future call
	
	std::thread t1(factorial, 6);// can pass extra parameter to thread and will treat it as the argument for the factorial function
	t1.join();

	std::packaged_task<int()> t2(std::bind(factorial, 6)); //cannot pass extra parameter to packaged task in this way, must use the std::bind() function to do this, (int) parameter removed from template

	auto t3 = std::bind(factorial, 6); //creates a function object which can be called later during program exectution, can be passed to thread/function just like packaged_task object
	//However a packaged task can link a callable object to a future, which can be very important in a threading environment

	//... some things happen

	t(6); //executed in a different context
	//cannot get the return value from t i.e. int x = t(6), as t always returns void, therefore:
	int x = t.get_future().get(); //will return value from the factorial function

	t2();  //cannot accept a parameter as parameter already bound to packaged task using std::bind() object.
	t3(); //function object called

	std::thread thr1(thread_1);
	std::packaged_task<int()> tsk(bind(factorial, 6));
	std::future<int> fu = tsk.get_future(); //future object can be created with the packaged_task's get_future function in order to get the return value
	{
		std::lock_guard<std::mutex> locker(mu);
		task_q.push_back(std::move(tsk));
	}
	cond.notify_one();
	cout << "Return value is " << fu.get() << endl;

	thr1.join();
	return 0;
}

/* Summary
 * 3 ways to get a future:
 * - promise::get_future()
 * - packaged_task::get_future()
 * - async() returns a future 
 */
==> ./Projects/copy assignment operator overload/copy assignment operator overload/main.cpp <==
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "TestClass.h"

using namespace std;

int main() {
	TestClass t1(5), t2;
	cout << "Fill array t1: ";
	cin >> t1;
	
	t2 = t1;
	TestClass t3(t1);

	t2.destroyList();

	cout << "t1: " << t1 << endl;
	cout << "t2: " << t2 << endl; 
	cout << "t3: " << t3 << endl;

	if (t1 == t3) {
		cout << "All good\n";
	}

	cin >> t2;

	if (t1 != t2) {
		cout << "Double good\n";
	}

	return 0;
}
==> ./Projects/copy assignment operator overload/copy assignment operator overload/TestClass.cpp <==
#include "TestClass.h"

TestClass::TestClass() {

}

TestClass::TestClass(int length) {
	if (length <= maxSize) {
		this->length = length;
	}
	else {
		cin.ios_base::failbit;
		do {
			cout << "Please enter a new value for length less than "
				<< maxSize << ": ";
			try {
				cin >> this->length;
			}
			catch (exception e) {
				cout << "\nYou did not enter an integer value\n";
				cin.clear();
				cin.ignore(100, '\n');
				this->length = maxSize + 1;
			}
		} while (this->length > maxSize);
	}
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

TestClass::TestClass(int length, int maxSize) {
	this->maxSize = maxSize;
	if (length <= maxSize) {
		this->length = length;
	}
	else {
		cin.ios_base::failbit;
		do {
			cout << "Please enter a new value for length less than "
				<< maxSize << ": ";
			try {
				cin >> this->length;
			}
			catch (exception e) {
				cout << "\nYou did not enter an integer value\n";
				cin.clear();
				cin.ignore(100, '\n');
				this->length = maxSize + 1;
			}
		} while (this->length > maxSize);
	}
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

TestClass::TestClass(const TestClass& rhs) {
		length = rhs.length;
		maxSize = rhs.maxSize;
		list = new int[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
}

bool TestClass::operator==(const TestClass& rhs) const {
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] == rhs.list[i]) {
				++a;
			}
		}
	}
	if ((length == rhs.length) && (a == rhs.maxSize)) {
		return true;
	}
	else {
		return false;
	}
}

bool TestClass::operator!=(const TestClass& rhs) const {
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] == rhs.list[i]) {
				++a;
			}
		}
	}
	if ((length == rhs.length) && (a == rhs.maxSize)) {
		return false;
	}
	else {
		return true;
	}
}

const TestClass& TestClass::operator=(const TestClass &rhs)  {
	if (this != &rhs) { //if this doesn't store the address rhs
		length = rhs.length;
		maxSize = rhs.maxSize;
		if (rhs.list) {
			list = new int[maxSize];
			for (int i = 0; i < maxSize; i++) {
				list[i] = rhs.list[i];
			}
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const TestClass &rhs) {
	if (rhs.list) {
		for (int i = 0; i < rhs.length; i++) {
			out << rhs.list[i] << " ";
		}
		out << endl;
		return out;
	}
	else {
		out << "List has been destroyed" << endl;
		return out;
	}
}

istream& operator>>(istream& in, TestClass &rhs) {
	assert(rhs.length);
	if (!rhs.list) {
		rhs.list = new int[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; i++) {
			rhs.list[i] = 0;
		}
	}
	for (int i = 0; i < rhs.length; i++) {
		in >> rhs.list[i];
	}
	return in;
}

void TestClass::print() {
	cout << "List : ";
	if (list) {
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "List has been destroyed\n";
	}
}

void TestClass::initialiseList() {
	if (!list) {
		list = new int[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = 0;
		}
	}
	int temp = 0;
	for (int i = 0; i < length; i++) {
		cin >> temp;
		list[i] = temp;
	}
}

void TestClass::destroyList() {
	delete[] list;
	list = NULL;
}

void TestClass::addItem() {
	if (length < maxSize) {
		cout << "Please enter the new entry: ";
		length++;
		cin >> list[length - 1];
	}
	else {
		cout << "The list is full";
	}
	cout << endl;
}


==> ./Projects/copy assignment operator overload/copy assignment operator overload/TestClass.h <==
#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

class TestClass {
	int maxSize = 10;
	int length = 0;
	int *list;
public:
	TestClass();
	TestClass(int);
	TestClass(int, int);
	TestClass(const TestClass&);

	void print();
	void initialiseList();
	void addItem();
	void destroyList();

	bool operator==(const TestClass&) const;
	bool operator!=(const TestClass&) const;
	const TestClass& operator=(const TestClass&);
	friend ostream& operator<<(ostream&, const TestClass&);
	friend istream& operator>>(istream&, TestClass&);
};

#endif
==> ./Projects/gotw (d. 2) 48 switching streams/assignment operator overload/assignment operator overload/ArrayList.cpp <==
#include "ArrayList.h"

ArrayList::ArrayList() {

}

ArrayList::ArrayList(int ilength) {
	length = ilength;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

ArrayList::ArrayList(int ilength, int imaxsize) {
	length = ilength;
	maxSize = imaxsize;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

ArrayList::ArrayList(const ArrayList &rhs) {
	maxSize = rhs.maxSize;
	length = rhs.length;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = 0;
	}
}

void ArrayList::print() const {
	cout << "List: ";
	if (!list) {
		cout << "List is empty\n";
	}
	else {
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}

void ArrayList::destroyList() {
	delete[] list;
	list = NULL;
}

void ArrayList::initialiseList() {
	int temp;
	cout << "Please enter " << length << " numbers:\n";
	for (int i = 0; i < length; i++) {
		cin >> temp;
		list[i] = temp;
	}
}

void ArrayList::addNewMember() {
	if (length < maxSize) {
		cout << "Please enter new member: ";
		cin >> list[length];
		length++;
	}
	else {
		cout << "List is already full\n";
	}
}

bool ArrayList::operator==(const ArrayList &rhs) const {
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] == rhs.list[i]) {
				a++;
			}
		}
	}
	if ((length == rhs.length) && (a == maxSize)) {
		return true;
	}
	else {
		return false;
	}
}

bool ArrayList::operator!=(const ArrayList &rhs) const {
	bool truther = false;
	int a = 0;
	if (maxSize == rhs.maxSize) {
		for (int i = 0; i < maxSize; i++) {
			if (list[i] = rhs.list[i]) {
				a++;
			}
		}
	}
	if ((length == rhs.length) && (a == maxSize)) {
		truther = false;
	}
	else {
		truther = true;
	}
	return truther;
}

const ArrayList& ArrayList::operator=(const ArrayList &rhs) {
	if (this != &rhs) {
		length = rhs.length;
		maxSize = rhs.maxSize;
		list = new int[maxSize];
		for (int i = 0; i < maxSize; i++) {
			list[i] = rhs.list[i];
		}
		return *this;
	}
}

istream& operator>>(istream &in, ArrayList &arl) {
	if (!arl.list) {
		arl.list = new int[arl.maxSize];
	}

	for (int i = 0; i < arl.length; i++) {
		in >> arl.list[i];
	}
	return in;
}

ostream& operator<<(ostream& out, ArrayList &arl) {
	if (!arl.list) {
		out << "No list available\n";
	}
	else {
		for (int i = 0; i < arl.length; i++) {
			out << arl.list[i] << " ";
		}
		out << endl;
	}
	return out;
}

==> ./Projects/gotw (d. 2) 48 switching streams/assignment operator overload/assignment operator overload/ArrayList.h <==
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

using namespace std;

class ArrayList {
	int maxSize = 10;
	int length;
	int *list;
public:
	ArrayList();
	ArrayList(int);
	ArrayList(int, int);
	ArrayList(const ArrayList&);

	void print() const;
	void initialiseList();
	void addNewMember();
	void destroyList();

	friend istream& operator>>(istream&, ArrayList&);
	friend ostream& operator<<(ostream&, ArrayList&);
	bool operator==(const ArrayList&) const;
	bool operator!=(const ArrayList&) const;
	const ArrayList& operator=(const ArrayList&);
};

#endif
==> ./Projects/gotw (d. 2) 48 switching streams/assignment operator overload/assignment operator overload/main(assignment operator).cpp <==
#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList al1(5), al2, al3;

	al1.initialiseList();

	ArrayList al4(al1);

	al3 = al2 = al1;
	al2.destroyList();
	cout << "al4: ";
	al4.print();
	cout << "al3: ";
	al3.print();
	cout << "al2: ";
	al2.print();
	cout << "al1: ";
	al1.print();

	cout << "new al1: " << al1;
	cout << "\nEnter new numbers for al2: ";
	cin >> al2;
	cout << "\nal2 new: " << al2;
	al3 = al2;
	cout << "al3: " << al3 << endl;
	return 0;
}
==> ./Projects/gotw (d. 2) 48 switching streams/gotw (d. 2) 48 switching streams/main.cpp <==
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int x = 1;
	char y[80] = "hello";
	string z;
	char *a;

	z = (x == 2) ? "variable x = 2\n" : (x == 1) ? "variable x = 1\n" : "variable x is not 1 or 2\n";
	cout << z;
	
	a = (x == 2) ? "variable x = 2\n" : "variable x is not 2\n";
	cout << a;
	
	x = 2;
	cout << (x == 2 ? "variable x = 2\n" : "variable x is not 2\n");
	//(argc > 2 ? ofstream(argv[2], ios::out | ios::binary) : cout) << (argc > 1 ? ifstream(argv[1], ios::out | ios::binary) : cin).rdbuf();

	return 0;
}
==> ./Projects/gotw (d. 2) 80 order order/gotw (d. 2) 80 order order/main.cpp <==
#include <string>

using namespace std;

class A
{
public:
	A(const string& s) { /* ... */ }
	string f() { return "hello, world"; }
};

class B : public A
{
public:
	B() : A(s = f()) {}
	//problem 1 - calls function from A as argument for A's constructor before A object is initialized
	//uses B member variable s as argument for A's constructor, before B object is initialized 
private:
	string s;
};

int main()
{
	B b;
}
==> ./Projects/gotw (d. 5) 2 temporry objects/gotw (d. 5) 2 temporry objects/main.cpp <==
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Employee {
	string addr;
};

string FindAddr(list<string> l, string name);

int main() 
{
	list<Employee> Employees;
	Employee* current;
	string Emp_name;
	int num;

	cout << "How many employees would you like to enter?";
	cin >> num;

	for (int i = 0; i < num; ++i) {

	}
		
	return 0;
}

string FindAddr(list<Employee> l, string name)
{
	for (list<Employee>::iterator i = l.begin(); i != l.end(); i++)
	{
		if (*i == name)
		{
			return (*i).addr;
		}
	}
	return "";
}
==> ./Projects/Linked List Class/Linked List Class/LinkedListClass.h <==
#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H
#include <iostream>

using namespace std;

template <typename Type>
struct node {
	Type info;
	node *link;
};

template <typename Type>
class linkedListType {
	node<Type> *first = NULL;
	node<Type> *last = NULL;
	int count = 0;
public:
	linkedListType() {
		initializeList();
	}

	void initializeList() {
		first = NULL;
		last = NULL;
		count = 0;
	}

	void print() {
		if (first == NULL) {
			cout << "List is empty\n";
		}
		else {
			node<Type> *current;
			current = first;
			while (current != NULL) {
				cout << current->info << " ";
				current = current->link;
			}
			cout << endl;
		}
	}

	bool isEmpty() const {
		return (first == NULL);
	}
	
	int length() const {
		return count;
	}

	void destroyList() {
		node<Type> *current;
		if (first == last) {
			initializeList();
		}
		else {
			while (current != NULL) {
				current = first->link;
				delete first;
				first = current;
			}
			initializeList();
		}
	}

	Type front() const {
		return first->info;
	}

	Type back() const {
		return last->info;
	}

	void insertFirst(const Type &item) {
		node<Type> *current;
		current = new node<Type>;
		current->info = item;
		if (first == NULL) {
			current->link = NULL;
			first = current;
			last = first;
			count++;
		}
		else {
			current->link = first;
			first = current;
			count++;
		}		
	}

	void insertLast(const Type &item) {
		node<Type> *current;
		current = new node<Type>;
		current->info = item;
		current->link = NULL;
		if (first == NULL) {
			first = current;
			last = first;
			count++;
		}
		else {
			last->link = current;
			last = current;
			count++;
		}
	}

	bool search(const Type &item) {
		node<Type> *current;
		current = first;
		while (current != NULL) {
			if (current->info == item) {
				return true;
			}
			else {
				current = current->link;
			}
		}
		cout << "Cannot find item\n";
		return false;
	}

	void deleteNode(const Type &item) {
		node<Type> *current, *trailCurrent;
		current = first;
		bool found = false;
		while (current != NULL) {
			if (current->info == item) {
				found = true;
				if (current == first) {
					current = current->link;
					delete first;
					first = current;
					count--;
					break;
				}
				else {
					trailCurrent->link = current->link;
					if (current == last) {
						last = trailCurrent;
					}
					delete current;
					count--;
					break;
				}
			}
			else {
				trailCurrent = current;
				current = current->link;;
			}
		}
		if (!found) {
			cout << "Item does not exist\n";
		}
	}

	const Type operator[](const int position) const {
		node<Type> *current;
		if ((position >= count)||(position < 0)) {
			cout << "Out of bounds\n";
		}
		else {
			current = first;	
			for (int i = 0; i <= position; ++i) {
				if (i == position) {
					return current->info;
				}
				else {
					current = current->link;
				}
			}
		}
	}
};


#endif

==> ./Projects/Linked List Class/Linked List Class/main.cpp <==
#include <iostream>
#include <string>
#include "LinkedListClass.h"

using namespace std;

int main() {
	cin.exceptions(ios_base::failbit);
	linkedListType<string> list1;
	string entry;
	cout << "Please enter some words separated by spaces. Type STOP to stop (in caps) :\n";
	cin >> entry;
	while (entry != "STOP") {
		list1.insertLast(entry);
		cin >> entry;
	}
	list1.print();
	cout << list1.length() << endl;
	for (int i = 0; i < list1.length(); i++) {
		cout << list1[i] << " ";
	}
	cout << endl;

	list1.deleteNode("hello");
	list1.print();
	list1.insertFirst("howdy");
	list1.print();
	list1.deleteNode("leslie");
	list1.deleteNode("leslie");
	list1.deleteNode("my");
	list1.insertLast("?");
	list1.print();

	return 0;
}
==> ./Projects/modern c++ 06 - compiler generated functs/modern c++ 06 - compiler generated functs/main.cpp <==
#include <iostream>

using namespace std;

/* Compiler generated functions

C++ 03
1. Default constructor (generated only if no constructor declared by user)
2. Copy constructor (generated only if 3, 4, 5, 6 not declared by user)
3. Copy assignment operator (generated only if 2, 4, 5, 6 not declared by user)
4. Destrucor

C++ 11
5. Move constructor (generated only if 2, 3, 4, 6 not declared by user)
6. Move assignment operator (generated only if 2, 3, 4, 6 not declared by user)
*/

class Dog {
	/* Compiler generated functions

	1. Dog(){ }	

	2. Dog(const Dog&){ }
	
	3. Dog& operator=(const Dog&){ }
	
	4. ~Dog(){ }

	5. Dog(const Dog&&){ }

	6. Dog&& operator=(const Dog&&){ }
	
	*/
};

int main() {

}
==> ./Projects/modern c++ 07 - shared pointers/modern c++ 07 - shared pointers/main.cpp <==
#include <iostream>
#include <string>
#include <memory> //allows use of 'smart' pointers, including shared_ptr

using namespace std;

class Dog {
	string _name;
public:
	Dog(string name) {
		_name = name;
		cout << name << " : Dog is created\n";
	}
	Dog() {
		_name = "Nameless";
		cout << _name << " dog is created\n";
	}
	~Dog() {
		cout << "Dog is destroyed. Bye bye " << _name << endl;
	}
	void bark() {
		cout << "My name is " << _name << endl;
	}
};

void oof() {
	try {
		throw 20;
		Dog *p = new Dog("Gunner");
		// ...
		delete p;
		//...
		p->bark(); //p is a dangling pointer - undefined behaviour
		(*p).bark();
	} //otherwise if p is not deleted, potential memory leak from Dog object
	catch (int x) {
		cout << "Try-catch prevents code running\n";
	}
}

void ofo() {
	/*shared_ptr keeps track of how many pointers are pointing to an object 
	when the count becomes zero, object is deleted automatically*/
	
	shared_ptr<Dog> p(new Dog("Gunner")); // Count = 1
	{
		shared_ptr<Dog> p2 = p; //Count = 2
		p2->bark();
		cout << p.use_count() << endl; // p.use_count() == 2
	}//Count = 1

	cout << p.use_count() << endl; //p.use_count() == 1
	p->bark();
} // Count = 0
//when shared_ptr goes out of scope, Count == 0, object pointed to is deleted

int main() {
	ofo();

	Dog *d = new Dog("Tank"); //bad idea
	try {
		throw 20;
		shared_ptr<Dog> p(d); //p.use_count() == 1
		shared_ptr<Dog> p2(d); //p2.use_count() == 1
		//Dog destroyed twice when 2 objects go out of scope
	}
	catch (int x) {
		cout << "Try-catch prevents code running\n";
	}

	shared_ptr<Dog> p = make_shared<Dog>("Tank"); 
	// faster & safer than below code - one step faster, exception safe

	shared_ptr<Dog> p2(new Dog("Gunner"));
	//two steps 1. "Gunner" is created 2. p is created, slower
	/*not exception safe - Gunner created, memory allocation failure leads
	to Gunner never being destroyed*/

	/*shared pointers can be cast into different kinds of pointers in the same
	way as a raw pointer
	
	static_pointer_cast
	dynamic_pointer_cast
	const-pointer_cast
	*/

	return 0;
}
==> ./Projects/Modern C++ 08 - shared pointer 2/Modern C++ 08 - shared pointer 2/main.cpp <==
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog {
	string name_;
public:
	Dog() {
		name_ = "Nameless";
		cout << name_ << " dog is created\n";
	}
	Dog(string name) {
		name_ = name;
		cout << name_ << " the dog is created\n";
	}
	void bark() {
		cout << "Hi, my name is " << name_ << endl;
	}
	void setName(string name) {
		name_ = name;
	}
	~Dog() {
		cout << name_ << " the dog is destroyed\n";
	}
};

void avoidMemoryLeak() { //how shared ptr 'smart pointer' avoids memory leak 
	shared_ptr<Dog> d1 = make_shared<Dog>("Gunner"); // Count = 1
	shared_ptr<Dog> d2 = make_shared<Dog>("Rexxy"); // Count = 1
	try {
		d1 = d2; //d2 Count = 0, Rexxy is destroyed, no memory leak 
		throw 20;
		d1 = nullptr;
		d1.reset();
		//all three commands would result in Gunner being destroyed
	}
	catch (int x) {
		cout << "Try-catch prevents =nullptr and .reset() running\n";
	}
}

void customDelete() { //use of custom delete to avoid memory leak
	shared_ptr<Dog> d1 = make_shared<Dog>("Dozer");
	//above uses default deleter, operator: delete;

	/*This makes it necessary to use the longer 2-step version of initializing
	a shared_ptr to create a custom delete, e.g. if the shared_ptr is used to
	store an array*/

//overloaded function allows user to specify custom deleter via lambda function
	shared_ptr<Dog> d2 = shared_ptr<Dog>(new Dog("Tank"),
		[](Dog* p) {cout << "Custom deleter: "; delete p;});

	try {
		throw 10;
		shared_ptr<Dog> b(new Dog[3]);
		/*uses default operator delete; when scope finishes will only delete 
		first dog, other two dog objects will create a memory leak*/
	}
	catch (int x) {
		cout << "Try-catch Prevents memory leak shared_ptr from running\n";
	}

	shared_ptr<Dog> a(new Dog[3],
		[](Dog* p) {cout << "Custom deleter: "; delete[] p;});
	/*uses custom delete operator delete[];*/
	a.get()[0].setName("Ted");
	a.get()[1].setName("Tex");
	a.get()[2].setName("Ten");
	//.get() function returns memory address, so functions as raw pointer
}

int main() {
	avoidMemoryLeak();
	customDelete();
	
	return 0;
}
==> ./Projects/Modern C++ 09 - weak pointers/Modern C++ 09 - weak pointers/Dog.h <==
#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Dog {
	static int noOfUnnamed;
	shared_ptr<Dog> myFriend;
	string name_;
public:
	Dog();

};

#endif
==> ./Projects/Modern C++ 09 - weak pointers/Modern C++ 09 - weak pointers/main.cpp <==
#include <iostream>
#include <memory>
#include <string> 

using namespace std;

class Dog {
	string name_;
	static int noOfUnnamed;
	shared_ptr<Dog> myFriend;
	weak_ptr<Dog> m_Friend;
	/*weak pointer only accesses shared_ptr, does not take ownership, does
	not delete object. Functions similar to raw pointer, but no user
	can perform operator delete; on it, which is extra level of protection
	if object is deleted it becomes an empty pointer*/
public:
	Dog() {
		noOfUnnamed++;
		string temp1 = to_string(noOfUnnamed);
		name_ = "Nameless_" + temp1;
		cout << name_ << " the dog is created\n";
	}
	Dog(string name) {
		name_ = name;
		cout << name_ << " the dog is created\n";
	}
	~Dog() {
		cout << name_ << " is destroyed\n";
	}
	void makeFriend(shared_ptr<Dog> f) {
		myFriend = f;
		cout << name_ << " says " << f->name_ << " is my friend\n";
	}
	void makeaFriend(weak_ptr<Dog> f) {
		m_Friend = f;
		cout << name_ << " says " << f.lock()->name_ << " is my new friend\n";
		//safer access to pointer - .lock() function creates shared_ptr
		try {
			throw 20;
			if ((name_ == "Tank") || (name_ == "Dozer")) {
				cout << "Friend!!\n";
				myFriend = f.lock();
				cout << "Friend : " << myFriend.use_count() << endl;
			} //needs both pointers point at each other, one shared_ptr
			//will still be destroyed
		}
		catch (int x) {
			cout << "Try-catch to prevent weak_ptr.lock() function " <<
				" creating a shared_ptr\n";
		}
	}
};

int Dog::noOfUnnamed = 0;

int main() {
	shared_ptr<Dog> d1 = make_shared<Dog>(); //Count = 1
	shared_ptr<Dog> d2(make_shared<Dog>()); //Count = 1

	d1->makeFriend(d2); //d1 contains shared_ptr to d2, Count = 2
	d2->makeFriend(d1); //d2 contains shared_ptr to d1, Count = 2
//pointers never go out of scope, dog objects never destroyed, memory leak

	shared_ptr<Dog> d3(new Dog("Tank"));
	shared_ptr<Dog> d4 = shared_ptr<Dog>(new Dog("Dozer"));

	d3->makeaFriend(d4);
	d4->makeaFriend(d3);

	return 0; 
}
==> ./Projects/Modern C++ 10 - Unique pointers/Modern C++ 10 - Unique pointers/main.cpp <==
/*Unique pointer represents unique ownership and is a lightweight smart 
pointer uses less resources than shared_ptr. when unique_ptr points to
another object the original object is automatically deleted*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Bone { };

class Dog {
	static int noOfUnnamed;
	string name_;
	unique_ptr<Bone> pbone;
	Bone *pb;
	
public:
	Dog() {
		try {
			throw 20;
			pb = new Bone;
			// if exception occurs, bone will be created & not destroyed
		}
		catch (int x) {
			//If allowed to run will crash the program
		}
		pbone = unique_ptr<Bone>(new Bone());
		//will be destroyed on its own automatically once scope ends
		noOfUnnamed++;
		string temp1 = to_string(noOfUnnamed);
		name_ = "Nameless_" + temp1;
		cout << name_ << " the dog has been created\n";
	}
	Dog(string name) {
		name_ = name;
		cout << name_ << " the dog has been created\n";
	}
	void bark() {
		cout << "Hi, my name is " << name_ << endl;
	}
	~Dog() {
		try {
			throw 20;
			if (pb != nullptr) {
				delete pb;
			}
		}
		catch (int x) {
			//If allowed to run will crash the program
		}
		cout << name_ << " the dog has been destroyed\n";
	}
};

int Dog::noOfUnnamed = 0;

void func(unique_ptr<Dog> pd) {
	pd->bark();
}

void test() {
	unique_ptr<Dog> d1(new Dog());
	d1->bark();

	d1.get()->bark(); //.get() returns raw pointer as in shared_ptr
	Dog *p1 = d1.get();

	p1 = d1.release(); //.release() also returns raw pointer, however 
	//causes object stored in unique_ptr to be reset to nullptr;

	if (!d1) cout << "d1 is empty\n";
	else cout << "d1 is not empty\n";
	
	delete p1;
	
	d1 = unique_ptr<Dog>(new Dog("Smokey"));
	d1.reset(new Dog("Tex"));
	
	unique_ptr<Dog> d2(new Dog("Gunner"));
	d2.reset(); //d2 = nullptr;
	d2 = move(d1); //object in d2 is destroyed, d1 becomes empty
	d2->bark();
	/*3 consequences since two ptrs cannot point to same object - 
	1. Gunner destroyed 
	2. d1 becomes nullptr
	3. d2 owns Smoky
	*/

	if (!d1) cout << "d1 is empty\n";
	else cout << "d1 is not empty\n";

	func(move(d2));
	if (!d2) cout << "d2 is empty\n";
	else cout << "d2 is not empty\n";
	cout << "unique pointer moved to func, Tex was destroyed when scope ended\n";
}

void specialArray() {
	cout << endl;
	//share_ptr requires custom delete to deal with arrays
	shared_ptr<Dog> d1(new Dog[3],
		[](Dog *p) {cout << "custom delete function\n"; delete[] p;});

	//unique_ptr is specialised to deal with arrays
	unique_ptr<Dog[]> d2(new Dog[3]);

	cout << endl;
}

int main() {
	test();
	specialArray();
}
==> ./Projects/modern c++05 - user defined literals/modern c++05 - user defined literals/main.cpp <==
#include <iostream>

using namespace std;

//no runtime cost due to constexpr
constexpr long double operator"" _m(long double x) { return x * 1000; }
constexpr long double operator"" _cm(long double x) { return x * 10; }
constexpr long double operator"" _mm(long double x) { return x; }

/*4 types of literals

1. string - char*
2. character - char
3. floating point - float, double
4. integer - int, unsigned int

user defined literals can only be used with these four types
*/

int main() {
	long double y = 3.4_cm;
	long double z = 13.0_m;

	cout << y + z << "mm\n";

	return 0;
}
==> ./Projects/module1/module1/module1.c <==
#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(module1_example_doc, "example(obj, number)\
\
Example function");

PyObject *module1_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to module1 in exec_module1().
 */
static PyMethodDef module1_functions[] = {
    { "example", (PyCFunction)module1_example, METH_VARARGS | METH_KEYWORDS, module1_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize module1. May be called multiple times, so avoid
 * using static state.
 */
int exec_module1(PyObject *module) {
    PyModule_AddFunctions(module, module1_functions);

    PyModule_AddStringConstant(module, "__author__", "Leslie");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2017);

    return 0; /* success */
}

/*
 * Documentation for module1.
 */
PyDoc_STRVAR(module1_doc, "The module1 module");


static PyModuleDef_Slot module1_slots[] = {
    { Py_mod_exec, exec_module1 },
    { 0, NULL }
};

static PyModuleDef module1_def = {
    PyModuleDef_HEAD_INIT,
    "module1",
    module1_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    module1_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_module1() {
    return PyModuleDef_Init(&module1_def);
}

==> ./Projects/parentclassfunction/parentclassfunction/main.cpp <==
#include <iostream>

using namespace std;

class BaseClass {
	int x;
public:
	BaseClass(int u = 0) { //makes default value if no value passed in
		x = u;
	}
	virtual void print() const {
		cout << "Base class .print() function\n";
		cout << "x = " << x << endl;
	}

	int& setX() {
		cout << x << endl;
		x = 5;
		cout << x << endl;
		int j = 10;
		return j;
	}
};

class DerivedClass : public BaseClass {
	int y;
public:
	DerivedClass(int u = 0, int v = 0) : BaseClass(u) {
		y = v;
	}
	/*virtual void print() const {
		cout << "Derived class .print() function\n";
		cout << "y = " << y << endl;
		BaseClass::print();
	}*/
};

void callPrint(BaseClass &);
void callPrint(BaseClass *);
void callPrint1(BaseClass);

int main() {
	DerivedClass classnew;
	classnew.setX();/
	classnew.print();

	return 0;
}

==> ./Projects/poker game/poker game/main.cpp <==
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <stdexcept>

using namespace std;

struct Card {
	char newSuit;
	char newCardno;
};

void populateDeck(vector<Card> &Deck);
void shuffle(vector<Card> &Deck);
void swap(Card& A, Card& B);
void printDeck(const vector<Card> &Deck);
int createPlayers();
int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers);
void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers);
void cardPermutations(int combos[][5]);
void clearLast(vector<vector<Card>> &hands, vector<Card> &faceup, const int &noplayers);

int main() {
	vector<Card> Deck;
	vector<vector<Card>> hands;
	vector<Card> faceup;
	int noofplayers;
	int position;
	char answer;

	populateDeck(Deck);
	//printDeck(Deck);
	shuffle(Deck);
	//printDeck(Deck);

	cin.exceptions(ios_base::failbit);
	noofplayers = createPlayers();

	do {
		shuffle(Deck);
		position = dealHands(Deck, hands, noofplayers);
		dealFlop(Deck, faceup, position);
		dealTurn(Deck, faceup, position);
		dealRiver(Deck, faceup, position);

		for (auto i : faceup) {
			cout << i.newCardno << " " << i.newSuit << "  ";
		}
		cout << "\n\n";
		constructScores(hands, faceup, noofplayers);
		clearLast(hands, faceup, noofplayers);
		do {
			cout << "\nWant to play another rounnd? (Y/N)";
			cin >> answer;
		} while ((answer != 'y') && (answer != 'Y') && (answer != 'N') && (answer != 'n'));
	} while ((answer == 'y') || (answer == 'Y'));

	return 0;
}


void populateDeck(vector<Card> &Deck) {
	if (Deck.size() > 0) {
		for (int i = 0; i < Deck.size(); ++i) {
			Deck.pop_back();
		}
	}
	Card newCard;
	char suit[] = { (char)3, (char)4, (char)5, (char)6 };
	char cardno[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			newCard.newSuit = suit[i];
			newCard.newCardno = cardno[j];
			Deck.push_back(newCard);
		}
	}
}

void printDeck(const vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		cout << Deck[i].newCardno << " " << Deck[i].newSuit << endl;
	}
	cout << endl;
}

void swap(Card &A, Card &B) {
	Card temp = A;
	A = B;
	B = temp;
}

void shuffle(vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		swap(Deck[i], Deck[(rand() + time(0)) % 52]);
	}
}

int createPlayers() {
	int noplayers;
	do {
		cout << "\nHow many players would you like to enter? ";
		try {
			cin >> noplayers;
		}
		catch (exception e) {
			cout << "\nYou did not enter an integer\n";
			cin.clear();
			cin.ignore(100, '/n');
			noplayers = 0;
		}
		if ((noplayers < 2) || (noplayers > 10)) {
			cout << "Please enter a number of players between 2-10\n";
		}
	} while ((noplayers < 2) || (noplayers > 10));
	return noplayers;
}

int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers) {
	int position = 0;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < noplayers; ++j) {
			hands.push_back(vector<Card>());
			hands[j].push_back(Deck[position]);
			++position;
		}
	}

	for (int i = 0; i < noplayers; ++i) {
		cout << "Hand " << i;
		for (int j = 0; j < 2; ++j) {
			cout << ": " << hands[i][j].newCardno << " " << hands[i][j].newSuit << "  ";
		}
		cout << "\n\n";
	}

	return position;
}

void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	for (int i = 0; i < 3; ++i) {
		faceup.push_back(Deck[position]);
		++position;
	}
}

void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void cardPermutations(int combos[][5]) {
	int allcards[7] = { 0, 1, 2, 3, 4, 5, 6 };
	string temp = "";
	set<string> combinations;

	for (int j = 1; j < 7; ++j) {
		for (int k = 1; k < 7; ++k) {
			if (allcards[k] != allcards[j]) {
				temp += (allcards[k] + 48);
			}
		}
		if (temp != "") {
			combinations.insert(temp);
			temp = "";
		}
	}
	for (int i = 0; i < 7; ++i) {
		for (int k = 1; k < 7; ++k) {
			for (int j = 0; j < 7; ++j) {
				if ((j != k) && (i != j) && (i != k)) {
					temp += (allcards[j] + 48);
				}
			}
			if (temp != "") {
				combinations.insert(temp);
				temp = "";
			}
		}
	}

	int count = 0;
	for (auto i : combinations) {
		for (int j = 0; j < 5; ++j) {
			combos[count][j] = (int)(i[j] - 48);
		}
		++count;
	}
}

void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers) {
	int npermutations[21][5];
	cardPermutations(npermutations);
	Card hriver[7];
	Card cpermutations[21][5];
	int points[21][2];
	vector<vector<Card>> hscore;
	vector<multiset<int, greater<int>>> cardnos;
	vector<int> mostarray;
	int highest[7] = { 0, 0, 0, 0, 0, 0, 0 };
	vector<int> winningplayer;

	for (int j = 0; j < 5; ++j) {
		hriver[j + 2] = faceup[j];
	}

	for (int i = 0; i < noplayers; ++i) {
		int most[2] = { 0, 0 };
		for (int i = 0; i < 21; ++i) {
			for (int j = 0; j < 2; ++j) {
				points[i][j] = 0;
			}
		}
		for (int j = 0; j < 2; ++j) {
			hriver[j] = hands[i][j];
		}
		for (int k = 0; k < 21; ++k) {
			for (int l = 0; l < 5; ++l) {
				cpermutations[k][l] = hriver[npermutations[k][l]];
			}
		}
	

		for (int k = 0; k < 21; ++k) {
			if ((cpermutations[k][0].newSuit == cpermutations[k][1].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][2].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][3].newSuit) &&
				(cpermutations[k][0].newSuit == cpermutations[k][4].newSuit)) { //flush
				points[k][0] += 1024;
			}
			set<int> straight;
			for (int l = 0; l < 5; ++l) {
				switch (cpermutations[k][l].newCardno) {
				case 'A': straight.insert(1); straight.insert(14); break;
				case '2': straight.insert(2); break;
				case '3': straight.insert(3); break;
				case '4': straight.insert(4); break;
				case '5': straight.insert(5); break;
				case '6': straight.insert(6); break;
				case '7': straight.insert(7); break;
				case '8': straight.insert(8); break;
				case '9': straight.insert(9); break;
				case 'T': straight.insert(10); break;
				case 'J': straight.insert(11); break;
				case 'Q': straight.insert(12); break;
				case 'K': straight.insert(13); break;
				}
				if (straight.size() >= 5) {
					int strait[5];
					int strai2[5] = { 0,0,0,0,0 };
					int m = 0; int n = -1;
					for (auto i2 : straight) {
						if (m <= 4) {
							strait[m] = i2;
						}
						if ((n >= 0) && (n <= 4)) {
							strai2[n] = i2;
						}
						++m;
						++n;
					}
					m = 4; n = 4;
					while (m > 0) {
						if (strait[m] - strait[m - 1] == 1) {
							--m;
						}
						else {
							m = -1;
						}
					}
					if (straight.size() == 6) {
						while (n > 0) {
							if (strai2[n] - strai2[n - 1] == 1) {
								--n;
							}
							else {
								n = -1;
							}
						}
					}
					if (n == 0) {
						for (int i2 = 0; i2 < 5; ++i2) {
							strait[i2] = strai2[i2];
						}
					}
					if ((m == 0) || (n == 0)) { //straight 
						points[k][0] += 256;
						if ((cpermutations[k][0].newSuit == cpermutations[k][1].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][2].newSuit) && (cpermutations[k][0].newSuit == cpermutations[k][3].newSuit) &&
							(cpermutations[k][0].newSuit == cpermutations[k][4].newSuit)) { //straight flush
							points[k][0] += 65536;
						}
					}
				}
			}

			for (int l = 0; l < 5; ++l) {
				for (int m = 0; m < 5; ++m) {
					if ((l != m) && (l < m)) {
						if (cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) { //pair
							points[k][0] += 4;
							for (int n = 0; n < 5; ++n) {
								if ((l != m) && (m != n) && (l < m) && (m < n)) {
									if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][l].newCardno == cpermutations[k][n].newCardno)) { //triples
										points[k][0] += 64;
									}
								}
								for (int o = 0; o < 5; ++o) {
									if ((l != m) && (l != n) && (l != o) && (m != n) && (m != o) && (n != o) && (l < m) && (n < o)) {
										if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)) { //two pair
											points[k][0] += 16;
											for (int p = 0; p < 5; ++p) {
												if ((o != p) && (p != m) && (p != n) && (p != l) && (l == 0)) {
													if ((cpermutations[k][l].newCardno == cpermutations[k][p].newCardno) || (cpermutations[k][p].newCardno == cpermutations[k][o].newCardno)) { //full house
														points[k][0] += 4096;
													}
												}
											}
										}
										if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)
											&& (cpermutations[k][n].newCardno == cpermutations[k][l].newCardno) && ((l == 0) || (l == 1)) && ((m == 1) || (m == 2)) && ((n == 2) || (n == 3)) && ((o == 3) || (o == 4))) { //four of a kind
											points[k][0] += 16384;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		for (int k = 0; k < 21; ++k) {
			if (points[k][0] > most[0]) {
				most[0] = points[k][0];
			}
		}

		mostarray.push_back(most[0]);

		for (int k = 0; k < 21; ++k) {
			if ((((most[0] >= 0) && (most[0] < 4)) && ((points[k][0] >= 0) && (points[k][0] < 4))) //High Card
				|| (((most[0] >= 4) && (most[0] < 16)) && ((points[k][0] >= 4) && (points[k][0] < 16))) //Pair
				|| (((most[0] >= 16) && (most[0] < 64)) && ((points[k][0] >= 16) && (points[k][0] < 64))) //Two pair
				|| (((most[0] >= 64) && (most[0] < 256)) && ((points[k][0] >= 64) && (points[k][0] < 256))) //Triple
				|| (((most[0] >= 256) && (most[0] < 1024)) && ((points[k][0] >= 256) && (points[k][0] < 1024))) //Straight
				|| (((most[0] >= 1024) && (most[0] < 4096)) && ((points[k][0] >= 1024) && (points[k][0] < 4096))) //Flush
				|| (((most[0] >= 4096) && (most[0] < 16384)) && ((points[k][0] >= 4096) && (points[k][0] < 16384))) //Full House
				|| (((most[0] >= 16384) && (most[0] < 65536)) && ((points[k][0] >= 16384) && (points[k][0] < 65536))) //Four of a kind
				|| ((most[0] >= 65536) && (points[k][0] >= 65536))) { //Straight Flush
				for (int l = 0; l < 5; ++l) {
					switch (cpermutations[k][l].newCardno) {
					case 'A': points[k][1] += 14; break;
					case '2': points[k][1] += 2; break;
					case '3': points[k][1] += 3; break;
					case '4': points[k][1] += 4; break;
					case '5': points[k][1] += 5; break;
					case '6': points[k][1] += 6; break;
					case '7': points[k][1] += 7; break;
					case '8': points[k][1] += 8; break;
					case '9': points[k][1] += 9; break;
					case 'T': points[k][1] += 10; break;
					case 'J': points[k][1] += 11; break;
					case 'Q': points[k][1] += 12; break;
					case 'K': points[k][1] += 13; break;
					}
				}
			}
		}

		for (int k = 0; k < 21; ++k) {
			if (points[k][1] > most[1]) {
				most[1] = points[k][1];
			}
		}
		for (int k = 0; k < 21; ++k) {
			if (points[k][1] == most[1]) {
				hscore.push_back(vector<Card>());
				for (int l = 0; l < 5; ++l) {
					hscore[i].push_back(cpermutations[k][l]);
				}
				break;
			}
		}

		cout << "\nPlayer " << i << ": ";
		for (int k = 0; k < 5; ++k) {
			cout << hscore[i][k].newCardno << " " << hscore[i][k].newSuit << "  ";
		}
		if (most[0] >= 65536) {
			cout << "Straight flush!\n";
		}
		else if (most[0] >= 16384) {
			cout << "Four of a kind!\n";
		}
		else if (most[0] >= 4096) {
			cout << "Full house!\n";
		}
		else if (most[0] >= 1024) {
			cout << "Flush!\n";
		}
		else if (most[0] >= 256) {
			cout << "Straight!\n";
		}
		else if (most[0] >= 64) {
			cout << "Triple!\n";
		}
		else if (most[0] >= 16) {
			cout << "Two pair!\n";
		}
		else if (most[0] >= 4) {
			cout << "A pair!\n";
		}
		else {
			cout << "High card\n";
		}
	}

	for (int i = 0; i < noplayers; ++i) {
		if (mostarray[i] > highest[0]) {
			highest[0] = mostarray[i];
		}
	}

	int h = 0;
	for (int i = 0; i < noplayers; ++i) {
		if ((((highest[0] >= 0) && (highest[0] < 4)) && ((mostarray[i] >= 0) && (mostarray[i] < 4))) //High Card
			|| (((highest[0] >= 4) && (highest[0] < 16)) && ((mostarray[i] >= 4) && (mostarray[i] < 16))) //Pair
			|| (((highest[0] >= 16) && (highest[0] < 64)) && ((mostarray[i] >= 16) && (mostarray[i] < 64))) //Two pair
			|| (((highest[0] >= 64) && (highest[0] < 256)) && ((mostarray[i] >= 64) && (mostarray[i] < 256))) //Triple
			|| (((highest[0] >= 256) && (highest[0] < 1024)) && ((mostarray[i] >= 256) && (mostarray[i] < 1024))) //Straight
			|| (((highest[0] >= 1024) && (highest[0] < 4096)) && ((mostarray[i] >= 1024) && (mostarray[i] < 4096))) //Flush
			|| (((highest[0] >= 4096) && (highest[0] < 16384)) && ((mostarray[i] >= 4096) && (mostarray[i] < 16384))) //Full House
			|| (((highest[0] >= 16384) && (highest[0] < 65536)) && ((mostarray[i] >= 16384) && (mostarray[i] < 65536))) //Four of a kind
			|| ((highest[0] >= 65536) && (mostarray[i] >= 65536))) { //Straight Flush
			cardnos.push_back(multiset<int, greater<int>>());
			winningplayer.push_back(i);
			for (int j = 0; j < 5; ++j) {
				switch (hscore[i][j].newCardno) {
					case 'A': cardnos[h].insert(14); break;
					case '2': cardnos[h].insert(2); break;
					case '3': cardnos[h].insert(3); break;
					case '4': cardnos[h].insert(4); break;
					case '5': cardnos[h].insert(5); break;
					case '6': cardnos[h].insert(6); break;
					case '7': cardnos[h].insert(7); break;
					case '8': cardnos[h].insert(8); break;
					case '9': cardnos[h].insert(9); break;
					case 'T': cardnos[h].insert(10); break;
					case 'J': cardnos[h].insert(11); break;
					case 'Q': cardnos[h].insert(12); break;
					case 'K': cardnos[h].insert(13); break;
				}
			}
			++h;
		}
	}
	
	for (int i = 0; i < h; ++i) {
		multiset<int, greater<int>>::iterator iter;
		iter = cardnos[i].begin();
		int j = 1;
		while (iter != cardnos[i].end()) {
			if (*iter > highest[j]) {
				highest[j] = *iter;
			}
			++j;
			++iter;
		}
	}

	int g = 0;
	for (int i = 1; i < 5; ++i) {
		for (int j = 0; j < h; ++j) {
			multiset<int, greater<int>>::iterator iter;
			iter = cardnos[j].begin();
			for (int k = 0; k < (i - 1); ++k) {
				++iter;
			}
			if (*iter == highest[i]) {
				++g;
				highest[6] = j;
			}
		}
		if (g == 1) {
			break;
		}
	}

	cout << "The winning hand is player " << winningplayer[highest[6]] << "!" << endl; /*NB: This does not yet display the true winning hand, except in the case of straights, flushes, straight flushes,
																					   or in the case where one player has a higher order winning hand (i.e triple vs a pair)*/
}

void clearLast(vector<vector<Card>> &hands, vector<Card> &faceup, const int &noplayers) {
	for (int i = 0; i < noplayers; ++i) {
		for (int j = 0; j < 2; ++j) {
			hands[i].pop_back();
		}
	}

	for (int i = 0; i < 5; ++i) {
		faceup.pop_back();
	}
}

==> ./Projects/poker2/poker2/main.cpp <==
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <set>
#include <string>

using namespace std;

struct Card {
	char newSuit;
	char newCardno;
};

void populateDeck(vector<Card> &Deck);
void shuffle(vector<Card> &Deck);
void swap(Card& A, Card& B);
void printDeck(const vector<Card> &Deck);
int createPlayers();
int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers);
void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position);
void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers);
void cardPermutations(int combos[][5]);

int main() {
	vector<Card> Deck;
	vector<vector<Card>> hands;
	vector<Card> faceup;
	int noofplayers;
	int position;

	populateDeck(Deck);
	printDeck(Deck);
	shuffle(Deck);
	printDeck(Deck);
	shuffle(Deck);

	noofplayers = createPlayers();
	position = dealHands(Deck, hands, noofplayers);

	dealFlop(Deck, faceup, position);
	dealTurn(Deck, faceup, position);
	dealRiver(Deck, faceup, position);

	for (auto i : faceup) {
		cout << i.newCardno << " " << i.newSuit << "  ";
	}
	cout << "\n\n";
	constructScores(hands, faceup, noofplayers);
	return 0;
}


void populateDeck(vector<Card> &Deck) {
	if (Deck.size() > 0) {
		for (int i = 0; i < Deck.size(); ++i) {
			Deck.pop_back();
		}
	}
	Card newCard;
	char suit[] = { (char)3, (char)4, (char)5, (char)6 };
	char cardno[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			newCard.newSuit = suit[i];
			newCard.newCardno = cardno[j];
			Deck.push_back(newCard);
		}
	}
}

void printDeck(const vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		cout << Deck[i].newCardno << " " << Deck[i].newSuit << endl;
	}
	cout << endl;
}

void swap(Card &A, Card &B) {
	Card temp = A;
	A = B;
	B = temp;
}

void shuffle(vector<Card> &Deck) {
	for (int i = 0; i < 52; ++i) {
		swap(Deck[i], Deck[(rand() + time(0)) % 52]);
	}
}

int createPlayers() {
	int noplayers;
	do {
		cout << "How many players would you like to enter? ";
		try {
			cin >> noplayers;
		}
		catch (exception e) {
			cout << "You didn't enter an integer\n";
			cin.clear();
			cin.ignore(100, '\n');
			noplayers = 0;
		}
		if ((noplayers < 2) || (noplayers > 10)) {
			cout << "Please enter a number of players between 2-10";
		}
	} while ((noplayers < 2) || (noplayers > 10));
	return noplayers;
}

int dealHands(const vector<Card> &Deck, vector<vector<Card>> &hands, const int &noplayers) {
	int position = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < noplayers; ++j) {
			hands.push_back(vector<Card>());
			hands[j].push_back(Deck[position]);
			++position;
		}
	}

	for (int i = 0; i < noplayers; ++i) {
		cout << "Hand " << i;
		for (int j = 0; j < 2; ++j) {
			cout << ": " << hands[i][j].newCardno << " " << hands[i][j].newSuit << "  ";
		}
		cout << "\n\n";
	}

	return position;
}

void dealFlop(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	for (int i = 0; i < 3; ++i) {
		faceup.push_back(Deck[position]);
		++position;
	}
}

void dealTurn(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void dealRiver(const vector<Card> &Deck, vector<Card> &faceup, int &position) {
	++position;
	faceup.push_back(Deck[position]);
	++position;
}

void cardPermutations(int combos[][5]) {
	int allcards[7] = { 0, 1, 2, 3, 4, 5, 6 };
	string temp = "";
	set<string> combinations;

	for (int j = 1; j < 7; ++j) {
		for (int k = 1; k < 7; ++k) {
			if (allcards[k] != allcards[j]) {
				temp += (allcards[k] + 48);
			}
		}
		if (temp != "") {
			combinations.insert(temp);
			temp = "";
		}
	}
	for (int i = 0; i < 7; ++i) {
		for (int k = 1; k < 7; ++k) {
			for (int j = 0; j < 7; ++j) {
				if ((j != k) && (i != j) && (i != k)) {
					temp += (allcards[j] + 48);
				}
			}
			if (temp != "") {
				combinations.insert(temp);
				temp = "";
			}
		}
	}

	int count = 0;
	for (auto i : combinations) {
		for (int j = 0; j < 5; ++j) {
			combos[count][j] = (int)(i[j] - 48);
		}
		++count;
	}
}

void constructScores(const vector<vector<Card>> &hands, const vector<Card> &faceup, const int &noplayers) {
	int npermutations[21][5];
	cardPermutations(npermutations);
	Card hriver[7];
	Card cpermutations[21][5];
	int points[21];
	int number = 0;


	for (int i = 0; i < 21; ++i) {
		cout << ++number << endl;
		points[i] = 0;
	}

	for (int j = 0; j < 5; ++j) {
		cout << ++number << endl;
		hriver[j + 2] = faceup[j];
	}

	for (int i = 0; i < noplayers; ++i) {
		cout << ++number << endl;
		for (int j = 0; j < 2; ++j) {
			cout << ++number << endl;
			hriver[j] = hands[i][j];
		}
		for (int k = 0; k < 21; ++k) {
			cout << ++number << endl;
			for (int l = 0; l < 5; ++l) {
				cout << ++number << endl;
				cpermutations[k][l] = hriver[npermutations[k][l]];
			}
		}

		for (int k = 0; k < 21; ++k) {
			cout << "k = " << k << " number = " << ++number << endl;
			if (cpermutations[k][0].newSuit == cpermutations[k][1].newSuit == cpermutations[k][2].newSuit == cpermutations[k][3].newSuit == cpermutations[k][4].newSuit) { //flush
				points[k] += 1024;
			}
			set<int> straight;
			for (int l = 0; l = 5; ++l) {
				switch (cpermutations[k][l].newCardno) {
				case 'A': straight.insert(1); break;
				case '2': straight.insert(2); break;
				case '3': straight.insert(3); break;
				case '4': straight.insert(4); break;
				case '5': straight.insert(5); break;
				case '6': straight.insert(6); break;
				case '7': straight.insert(7); break;
				case '8': straight.insert(8); break;
				case '9': straight.insert(9); break;
				case 'T': straight.insert(10); break;
				case 'J': straight.insert(11); break;
				case 'Q': straight.insert(12); break;
				case 'K': straight.insert(13); break;
				}
				if (straight.size() == 5) {
					int strait[5];
					int m = 0;
					for (auto i : straight) {
						strait[m] = i;
						if (m < 4) {
							++m;
						}
					}
					while (m > 0) {
						if (strait[m] - strait[m - 1] == 1) {
							--m;
						}
						else {
							m = -1;
						}
					}
					if (m == 0) { //straight 
						points[k] += 256;
						if (cpermutations[k][0].newSuit == cpermutations[k][1].newSuit == cpermutations[k][2].newSuit == cpermutations[k][3].newSuit == cpermutations[k][4].newSuit) { //straight flush
							points[k] += 65536;
						}
					}
				}
			}

			for (int l = 0; l < 5; ++l) {
				cout << "k = " << k << "l = " << l << " number = " << ++number << endl;
				for (int m = 0; m < 5; ++m) {
					cout << "k = " << k << " l = " << l << " m = " << m << " number = " << ++number << endl;
					if ((l != m) && (l < m)) {
						if (cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) { //doubles
							points[k] += 4;
						}
					}
					for (int n = 0; n < 5; ++n) {
						cout << "k = " << k << " l = " << l << " m = " << m << " n = " << n << " number = " << ++number << endl;
						if ((l != m) && (m != n) && (l < m) && (m < n)) {
							if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][l].newCardno == cpermutations[k][n].newCardno)) { //triples
								points[k] += 64;
							}
						}
						for (int o = 0; o < 5; ++o) {
							cout << "k = " << k << " l = " << l << " m = " << m << " n = " << n << " o = " << o << " number = " << ++number << endl;
							if ((l != m) && (m != n) && (n != o) && (l < m) && (n < o)) {
								if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno) && (cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)) { //two pair
									points[k] += 16;
									for (int p = 0; p < 5; ++p) {
										cout << "p = " << ++number << endl;
										if (o != p) {
											if ((cpermutations[k][l].newCardno == cpermutations[k][p].newCardno) || (cpermutations[k][p].newCardno == cpermutations[k][o].newCardno)) { //full house
												points[k] += 4096;
											}
										}
									}
								}
								if ((cpermutations[k][l].newCardno == cpermutations[k][m].newCardno == cpermutations[k][n].newCardno == cpermutations[k][o].newCardno)) { //four of a kind
									points[k] += 16384;
								}
							}
						}
					}
				}
			}
		}
	}
}
==> ./Projects/quick sort/quick sort/main.cpp <==
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int[], int, int);

int partition(int[], int, int);

void failedquickSort(int[]);

void quickSort(int[], int);

void recursiveQuick(int[], int, int);

int main() {
	int newlist[100];
	for (int i = 0; i < 100; i++) {
		newlist[i] = (rand() + time(0)) % 10000;
	}
	for (int i = 0; i < 100; i++) {
		cout << setw(5) << newlist[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	int length = sizeof(newlist)/sizeof(int);

	quickSort(newlist, length);
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << setw(5) << newlist[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	system("PAUSE");
	return 0;
}

void swap(int list[], int x, int y) {
	int temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}

int partition(int list[], int first, int last) {
	int pivot = (first + last) / 2;
	swap(list, first, pivot);
	int smallIndex = first;
	for (int i = first + 1; i <= last; i++) {
		if (list[i] < list[first]) {
			smallIndex++;
			swap(list, smallIndex, i);
		}
	}
	swap(list, first, smallIndex);
	return smallIndex;
}

void recursiveQuick(int list[], int first, int last) {
	if (first < last) {
		int middle = partition(list, first, last);
		recursiveQuick(list, first, middle - 1);
		recursiveQuick(list, middle + 1, last);
	}
}

void quickSort(int list[], int length) {
	recursiveQuick(list, 0, length - 1);
}

void failedquickSort(int list[]) { //despite the array operator symbol, what is actually passed is the first element of the array by reference, the sizeof(list) command therefore returns as 4 bytes
	cout << "running\n";
	int length = sizeof(list) / sizeof(int);
	cout << "length = " << length;
	recursiveQuick(list, 0, length - 1);
}
==> ./Projects/tempcode/tempcode/main.cpp <==
..;..
==> ./Projects/tempstuff/tempstuff/main.cpp <==

==> ./Projects/testc/testc/Source.c <==
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

main() {
	int a = 5;
	double b = 2.3;
	double c;

	c = a / b;
	printf("%.2f", c);
	printf("\n");

	return;
}
==> ./Projects/tictactoegame/tictactoegame/main.cpp <==
#include <iostream>
#include <string>
//#include <stdexcept>

using namespace std;

void createBoard(char [5][5]); //this initialises the structure for the game board
void printBoard(const char[5][5]); //prints the game board
void humanMove(char[5][5], int[8], int[9], int&); //allows human player to make a move
void humanPaths(int[8], char[5][5], int, int); //examines the board and adds to the array storing information on the winning paths possible for a human player
void checkWinner(char[5][5], int&); //checks the board to determine if there is a winner
void testMove(int[8], int[8], char[5][5], int, int, int [4], int); //tests all possible moves in order to determine the optimal move for the computer to play
void computerMove(int[8], int[8], char[5][5], int[9], int&); //makes the computer's best move and stores information on which winning paths are open/closed
void initialiseArrays(int[8], int[8], int[9]); //initialises game arrays, for storing information on how close a player is to a win
void testHumMove(char[5][5], int[8], int[8], int&, int, int); //tests the next move a human player can make, part of determining the optimal move for the computer to play

int squares[9]; //global variable, stores information on whether squares have been filled

int main() {
	char board[5][5]; //game board
	int a = 0; //variable passed into functions, reset to 0 if game board is full
	int c = 0; //counter for determining if a game is finished 
	int humanarray[8], computerarray[8]; //these are created to store information on winning paths for computer and human player, there are 8 winning paths in the game
	bool isFull = false; //this shows whether or not the board is full
	
	createBoard(board);
	initialiseArrays(computerarray, humanarray, squares);
	cin.exceptions(ios_base::failbit);

	do {
		c++;
		humanMove(board, humanarray, squares, a);
		checkWinner(board, a);
		if (c < 5) {
			computerMove(computerarray, humanarray, board, squares, a);
		}
		printBoard(board);
		checkWinner(board, a);
		if (a == 0) {
			isFull = true;
		}
	} while (isFull == false);
	
	cout << "Thank you for playing\n";

	return 0;
}

void initialiseArrays(int computerarray[8], int humanarray[8], int squares[9]) { //initialise all arrays with 0 
	for (int i = 0; i < 9; i++) {
		if (i < 8) {
			squares[i] = 0;
			humanarray[i] = 0;
			computerarray[i] = 0;
		}
		else
			squares[i] = 0;
	}
}

void createBoard(char board[5][5]) { //creates empty game board
	for (int i = 0; i < 5; i++) {
		if ((i + 1) % 2 == 1) {
			for (int j = 0; j < 5; j++) {
				if ((j + 1) % 2 == 1) {
					board[i][j] = ' ';
				}
				else if ((j + 1) % 2 == 0) {
					board[i][j] = '|';
				}

			}
		}
		else if ((i + 1) % 2 == 0) {
			for (int j = 0; j < 5; j++) {
				if ((j + 1) % 2 == 1) {
					board[i][j] = '-';
				}
				else if ((j + 1) % 2 == 0) {
					board[i][j] = '+';
				}
			}
		}
	}
	printBoard(board);
}

void printBoard(const char board[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void humanMove(char board[5][5], int humanarray[8], int squares[9], int &a) {
	int move = 0; //accepts number between 1 and 9 corresponding to game squares
	int count = 0; //for checking if square is empty
	do {
		cout << "Please enter an integer between 1 and 9 : ";
		try {
			cin >> move;
		}
		catch (exception e) { //try-catch block asks for an integer if no integer is entered
			cout << "\nYou did not enter an integer\n";
			cin.clear();
			cin.ignore(100, '\n');
			move = 0; 
		}
		if ((move < 1) || (move > 9)) { //asks for integer 1-9 if not input successfully
			cout << "\nPlease pick a move between 1 and 9\n";
		}
		else if ((move >= 1) && (move <= 9)) {
			a = 0;
			count = 0;
			for (int i = 0; i < 5; i += 2) {
				for (int j = 0; j < 5; j += 2) { 
					if (++count == move) { //loop increments along the squares of the tictactoe board using varable count until move == count
						if (squares[count - 1] == 0) { //checks if current square selected is empty
							board[i][j] = 'x'; //places marker
							squares[count - 1]++; //increments in array to indicate square is no longer empty
							humanPaths(humanarray, board, i, j); //adds to the human potential winning paths array
						}
						else if (squares[count - 1] > 0) { //if square is not empty, tells player to move again
							cout << "Invalid move. Please try again\n"; 
							move = 0;
							i = 6; j = 6; //int i and j set outside "for loop" constraints
						}
					}
					if (board[i][j] == ' ') {
						a = 1; //indicates board is not full
					}
				}
			}
		}
	} while ((move < 1) || (move > 9)); //runs loop whilst move is not valid for the game board
}

void humanPaths(int humanarray[8], char board[5][5], int i, int j) {
	switch (board[i][j]) {
	case 'x':
		switch (i) { //increment along the 8 winning conditions, i.e square [0][0] as opening move is on 3 winning paths, increments on humanarray[0], humanarray[3] and humanarray[6]
		case 0:	humanarray[0]++; break; 
		case 2: humanarray[1]++; break;
		case 4: humanarray[2]++; break;
		}
		switch (j) {
		case 0:	humanarray[3]++; break;
		case 2: humanarray[4]++; break;
		case 4: humanarray[5]++; break;
		}
		if (i == j) {
			humanarray[6]++;
		}
		if (i + j == 4) {
			humanarray[7]++;
		}
		break;
	}
}

void checkWinner(char board[5][5], int &a) {
	int countd2 = 0; 
	for (int i = 0; i < 5; i += 2) {
		int counth = 0; //count to see if there are 3 in a row on any horizontal
		int countv = 0; //count to see if there are 3 in a row on any vertical
		int countd = 0; //count to see if there arew 3 in a row on diagonal 1
		for (int j = 0; j < 5; j += 2) { //separate conditions arbitrary values for player 'x' and player 'o' 
			switch (board[i][j]) { 
			case 'x': counth++; break;
			case 'o': counth += 5; break;
			}
			switch (board[j][i]) {
			case 'x': countv++; break;
			case 'o': countv += 5; break;
			}
			switch (board[j][j]) {
			case 'x': countd++; break;
			case 'o': countd += 5; break;
			}
			if (i + j == 4) {
				switch (board[i][j]) {
				case 'x': countd2++; break;
				case 'o': countd2 += 5; break;
				}
			}
			if ((countv == 3) || (counth == 3) || (countd == 3)
				|| (countd2 == 3)) {
				a = 0; i = 6; j = 6; cout << "x wins!!\n";
			} 
			if ((countv == 15) || (counth == 15) || (countd == 15)
				|| (countd2 == 15)) {
				a = 0; i = 6; j = 6; cout << "o wins!!\n";
			}
		}
	}
}

void computerMove(int computerarray[8], int humanarray[8], char board[5][5], int squares[9], int &a) { //makes computer's optimal move
	int move = 0; //variable for storing computer move decision
	int most[4] = { 0, 0, 0, 0 }; //array for storing optimal move and move location
	int count = 0; //variable to cycle through game squares until computer's move is reached
	for (int b = 1; b < 10; b++) {
		move = b;
		count = 0;
		for (int i = 0; i < 5; i += 2) {
			for (int j = 0; j < 5; j += 2) {
				if (++count == move) { //if board position is equal to move position
					if (squares[count - 1] == 0) { //if board position is empty
						testMove(computerarray, humanarray, board, i, j, most, move); //tests move to determine whether it is optimal
					}
					else if (squares[count - 1] > 0) { //if board poosition is not empty
						move = 0;
						i = 6; j = 6; //breaks loop
					}
				}
				if (board[i][j] == ' ') {
					a = 1; //board is not full
				}
			}
		}
	}
	board[most[1]][most[2]] = 'o'; // places mark in optimal position
	squares[most[3] - 1]++; //increments array to show position has been filled
	switch (board[most[1]][most[2]]) {
	case 'o':
		switch (most[1]) { //increments along the 8 winning conditions if satisfied
		case 0:	computerarray[0]++; break;
		case 2: computerarray[1]++; break;
		case 4: computerarray[2]++; break;
		}
		switch (most[2]) {
		case 0:	computerarray[3]++; break;
		case 2: computerarray[4]++; break;
		case 4: computerarray[5]++; break;
		}
		if (most[1] == most[2]) {
			computerarray[6]++;
		}
		if (most[1] + most[2] == 4) {
			computerarray[7]++;
		}
		break;
	}
}

void testMove(int computerarray[8], int humanarray[8], char board[5][5], int i, int j, int most[4], int move) {
	int comarray[8]; //clone arrays showing potential winning paths
	int humarray[8]; //clone arrays showing potential winning paths
	for (int x = 0; x < 8; x++) { //initialisd with data from arrays storing potential winning paths
		comarray[x] = computerarray[x]; 
		humarray[x] = humanarray[x];
	}
	board[i][j] = 'o';
	switch (board[i][j]) { //increment along the 8 winning conditions, i.e square [0][0] is on 3 winning paths, would increment on comarray[0], comarray[3] and comarray[6]
	case 'o':
		switch (i) {
		case 0:	comarray[0]++; break;
		case 2: comarray[1]++; break;
		case 4: comarray[2]++; break;
		}
		switch (j) {
		case 0:	comarray[3]++; break;
		case 2: comarray[4]++; break;
		case 4: comarray[5]++; break;
		}
		if (i == j) {
			comarray[6]++;
		}
		if (i + j == 4) {
			comarray[7]++;
		}
		break;
	}
	
	for (int x = 0; x < 8; x++) { //if winning path occupied by both computer and human, no longer a potential winning path
		if ((comarray[x] > 0) && (humarray[x] > 0)) {
			humarray[x] = -1; comarray[x] = -1;
		}
	}
	int points = 0;

	for (int x = 0; x < 8; x++) { //conditions for selecting optimal move, if either comarray or humarray = 3, that is a game win, arbitrary points increase based on effectiveness of move 
		if (comarray[x] == 3) {
			points += 1024;
		}
		if ((humanarray[x] == 2) && (humarray[x] == -1)) {
			points += 64;
		}
		if (comarray[x] == 2) {
			points += 16;
		}
		if (humarray[x] == -1) {
			points += 4;
		}
		if (comarray[x] == 1) {
			points += 1;
		}
	}
	int nxtmove = 0; 
	for (int b = 1; b < 10; b++) { //tests next human move as part of determining the next optimal move, integers 1-9 represent spaces on game board
		nxtmove = b; 
		int count = 0; //count integer for cycling through game board positions 1-9, until reaches move position
		for (int k = 0; k < 5; k += 2) {
			for (int l = 0; l < 5; l += 2) {
				if (++count == nxtmove) { //reaches move position
					if (squares[count - 1] == 0) { //if square is empty
						testHumMove(board, comarray, humarray, points, k, l); //tests human move
					}
					else if (squares[count - 1] > 0) { //if square is already full
						nxtmove = 0;
						k = 6; l = 6; //breaks loop
					}
				}
			}
		}
	}

	if (points > most[0]) { //if points indicate it is the optimal move 
		most[0] = points;
		most[1] = i;
		most[2] = j;
		most[3] = move;
	} //stores optimal move and move location data
	board[i][j] = ' '; //clears board of potential moves
}

void testHumMove(char board[5][5], int comarray[8], int humarray[8], int &points, int k, int l) { //tests the next human move as part of determining the optimal position
	board[k][l] = 'x';
	int comarray2[8]; //clone arrays for winning paths
	int humarray2[8]; //clone arrays for winning paths

	for (int i = 0; i < 8; i++) { //initialized with winning path information
		comarray2[i] = comarray[i];
		humarray2[i] = humarray[i];
	}
	switch (board[k][l]) {
	case 'x': //increments for 8 winning conditions if conditions are met
		switch (k) {
		case 0:	humarray2[0]++; break;
		case 2: humarray2[1]++; break;
		case 4: humarray2[2]++; break;
		}
		switch (l) {
		case 0:	humarray2[3]++; break;
		case 2: humarray2[4]++; break;
		case 4: humarray2[5]++; break;
		}
		if (k == l) {
			humarray2[6]++;
		}
		if (k + l == 4) {
			humarray2[7]++;
		}
		break;
	}
	board[k][l] = ' ';
	for (int x = 0; x < 8; x++) {
		if ((comarray2[x] > 0) && (humarray2[x] > 0)) {
			humarray2[x] = -1; comarray2[x] = -1;
		}
	}
	int hcount = 0;
	int ccount = 0;
	for (int x = 0; x < 8; x++) { //conditions determine if human's next move would be detrimental to computer's move 
		if (humarray2[x] == 2) {
			hcount++;
		}
		if (comarray2[x] == 2) {
			ccount++;
		}
	}
	if ((hcount > 1) && (ccount < 1)) {
		points -= 256; //arbitrary point decrease in line with the scale-4 mechanism used previously
	} 
}
==> ./Projects/tictactoegame/tictactoegame/practice.cpp <==
/*#include <iostream>

using namespace std;

for (int i = 0; i < 5; i += 2) {
	for (int j = 0; j < 5; j += 2) {
		switch (board[i][j]) {
		case 'x':
			switch (i) {
			case 0:	humanarray[0]++; break;
			case 2: humanarray[1]++; break;
			case 4: humanarray[2]++; break;
			}
			switch (j) {
			case 0:	humanarray[3]++; break;
			case 2: humanarray[4]++; break;
			case 4: humanarray[5]++; break;
			}
			if (i == j) {
				humanarray[6]++;
			}
			if (i + j == 4) {
				humanarray[7]++;
			}
			break;
		case 'o':
			switch (i) {
			case 0:	computerarray[0]++; break;
			case 2: computerarray[1]++; break;
			case 4: computerarray[2]++; break;
			}
			switch (j) {
			case 0:	computerarray[3]++; break;
			case 2: computerarray[4]++; break;
			case 4: computerarray[5]++; break;
			}
			if (i == j) {
				computerarray[6]++;
			}
			if (i + j == 4) {
				computerarray[7]++;
			}
			break;
		}
	}
}

for (int i = 0; i < 7; i++) {
	if ((computerarray[i] > 0) && (humanarray[i] > 0)) {
		humanarray[i] = -1; computerarray[i] = -1;
	}
}


void test() {
	most = 0;
	points = 0;
	dopossiblemove();
	for (int i = 0; i < 8; i++) {
		if (computerarray[i] == 3) {
			points += 21;
		}
		if (computerarray[i] == 2) {
			points += 8;
		}
		if (humanarray[i] == -1) {
			points += 3;
		}
		if (computerarray[i] == 1) {
			points += 1;
		}
	}
	if (points > most) {
		most = points;
		savepossiblemove();
	}
	makemove();
}

void testHumanMove(int computerarray[8], int humanarray[8],
	char board[5][5], int i, int j, int most[4], int move) {
	int comarray[8];
	int humarray[8];
	for (int x = 0; x < 8; x++) {
		comarray[x] = computerarray[x];
		humarray[x] = humanarray[x];
	}
	board[i][j] = 'x';
	switch (board[i][j]) {
	case 'x':
		switch (i) {
		case 0:	humarray[0]++; break;
		case 2: humarray[1]++; break;
		case 4: humarray[2]++; break;
		}
		switch (j) {
		case 0:	humarray[3]++; break;
		case 2: humarray[4]++; break;
		case 4: humarray[5]++; break;
		}
		if (i == j) {
			humarray[6]++;
		}
		if (i + j == 4) {
			humarray[7]++;
		}
		break;
	}
	board[i][j] = ' ';
	for (int x = 0; x < 8; x++) {
		if ((comarray[x] > 0) && (humarray[x] > 0)) {
			humarray[x] = -1; comarray[x] = -1;
		}
	}
	int hcount = 0;
	int ccount = 0;
	for (int x = 0; x < 8; x++) {
		if (humarray[x] == 2) {
			hcount++;
		}
		if (comarray[x] == 2) {
			ccount++;
		}
	}
	if (hcount > 1) && (ccount < 1) {
		points -= 256;
	}


	for (int x = 0; x < 8; x++) {
		if (comarray[x] == 3) {
			points += 256;
		}
		if ((humanarray[x] == 2) && (humarray[x] == -1)) {
			points += 64;
		}
		if (comarray[x] == 2) {
			points += 16;
		}
		if (humarray[x] == -1) {
			points += 4;
		}
		if (comarray[x] == 1) {
			points += 1;
		}
	}
	if (points > most[0]) {
		most[0] = points;
		most[1] = i;
		most[2] = j;
		most[3] = move;
	}
}*/
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for (int i = 0; i < 10; i++){
		cout << "Line number " << i << endl;
	        SetConsoleTextAttribute(h,FOREGROUND_BLUE);
	}
	return 0;
}
