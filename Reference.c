==> ../../section_05/automatic_variables/main.c <==
#include <stdio.h>

int main(){
    auto int x; //local variable - auto keyword is implicit in C and is repurposed for C++ so best not tou use
  //int x;  means the same as the preceding statement

    int m;
    
    scanf("%d", &m)
    {
        int i; //both m and i can be used in scanf code block
        
        for (int i = 0; i < m; i++)
        {
        }
    }


    return 0;
}

char* myFunction(){
char x[] = "apple";

return x;
}


==> ../../section_05/challenge/challenge1.c <==
#include <stdio.h>

static double a = 3.0; //global double variable onl accessible within the file
float b = 4.0;  // float variable that is accessible throughout program,

static int foo(); //function only accessible within the program where it is defined 

int main(){
    register int d = 7; //register int variable 
    return 0;
}

static int foo(){
    int x = 0; // int variable with block scope and temporary storage
    static float c = 5.0; //float local variable with permanent storage
    
    c++; 
    return c;
}

==> ../../section_05/challenge/challenge2.c <==
#include <stdio.h>

int sum(int num){
    static int x = 0;
    x += num;
    return x;
}

int main(){
    printf("%d\n", sum(25)); 
    printf("%d\n", sum(15)); 
    printf("%d\n", sum(30)); 
    return 0;
}

==> ../../section_05/challenge/challenge3_display.c <==

void display(){
   extern int loopCounter;

   printf("%d\n", loopCounter);
}

==> ../../section_05/challenge/challenge3_main.c <==
#include <stdio.h>

int loopCounter = 0; //global variale to be used as a loop counter

void display();  //display function tsakes no parameters

int main(){
    for (loopCounter = 0; loopCounter < 5; ++loopCounter){
        display();
    } 

    return 0;
}

==> ../../section_05/external_variables/foo.c <==
//cannot initialize variable, siilar to extern definition in assembly language, placed as global variable if
//multiple functions need to access it

extern int i;

//if char text[500]; is defined in main can be referenced as extern by using empty brackets 
extern char text[];

//if 2d array, must declare second variable in array
extern char pagetext[][25];

void foo(void){
  //extern int i;   if only accessed by one function could define it within the function so passes out of scope at end of function
    i = 100;
}

void bar(void){
    i = 50;
}

==> ../../section_05/external_variables/main.c <==
#include <stdio.h>

int i = 5;

char text[500];

char pagetext[500][25];

//function declaration is extern by default
void foo(void); //same as writing  -   extern void foo(void);

int main (void)
{
    printf("%i ", i);
    foo();
    printf("%i\n", i);

    return 0;
}

==> ../../section_05/overview/main.c <==
#include <stdio.h>
#include "other.h"

void main(){
   printf("%d\n", getfavouritenumber());

}


==> ../../section_05/overview/other.c <==
#include "other.h"

int getfavouritenumber(void){
    return 3;
}

==> ../../section_05/register_variables/main.c <==
#include <stdio.h>

int main()
{
    register int x; // register variable - if attempt to use &x to access memory address, compiler will return an error 
                    // as it is stored in a register not in memory (RAM)
    
//  int *a = &x;    // would cause compile failure

    for (x = 1; x <= 15; x++)
    {
        printf("%d\n", x); 
    }

    return 0;
}

==> ../../section_05/stack_heap/heap.c <==
#include <stdio.h>
#include <stdlib.h>

//by using malloc() data is being allocated onto the heap (located in RAM) all data is allocated on the heap and free(0 is used to free it

double* multiplyByTwo(double *input){
    double *twice = malloc(sizeof(double));
    *twice = input * 2.0;
    return twice;
}

int main()
{
    int *age = malloc(sizeof(int));
    *age = 30;
    double *salary = malloc(sizeof(double));
    *salary = 123456.78;
    double *myList[3] = malloc(sizeof(double));
    *myList[0] = 1.2;
    *myList[1] = 2.3;
    *myList[2] = 3.4;
    double *twiceSalary = multiplyByTwo(salary);    

    printf("double your salary is %.3f\n", *twiceSalary);
    
    free(age);
    free(salary);
    free(myList);
    free(age);

    Return 0;
}

==> ../../section_05/stack_heap/stack.c <==
#include <stdio.h>

//both functions main() and multiplyByTwo allocate data onto the stack which is popped off the stack when the program finishes
//stack data is very quick read/access

double multiplyByTwo(double input){
    double twice = input * 2.0;
    return twice;
}

int main()
{
    int age = 30;
    double salary = 123456.78;
    double myList[3] = {1.2, 2.3, 3.4};
    
    printf("double your salary is %.3f\n", multiplyByTwo(salary));
    
    Return 0;
}

==> ../../section_05/static_variables/foo.c <==
extern int fun();
// variable declation 

// were this file to be included in compilation would cause a compilation error as fun2 has been declaed to be static
// meaning it can only be accessed from within the main.c
extern int fun2();

int foo(){
    fun();
}

==> ../../section_05/static_variables/main.c <==
#include <stdio.h>

//does not recreate variable each time function is called but allows variable to be hidden from other parts of program
int fun(){
    // has t be initialized t a constatn, cannot be initiaized using a function i.e. static int count = initialize();
    static int count =0;

    count++;
    return count;
}

static int fun2(){
    int count = 0;

    count++;
    return count;
}

int main(){
    printf("Count is %d\n", fun());
    printf("Count is %d\n", fun());

    return 0;
}

==> ../../section_05/static_variables/static.c <==
 #include <stdio.h>
int x = 15;
void first(void);
void second(void);
 
int main(void)  {
  extern int x;
 
  printf("x in main() is %d\n", x);
  first();
  printf("x in main() is %d\n", x);
  second();
  printf("x in main() is %d\n", x);
  return 0;
}
 
 
void first(void) {
  int x;
  x = 25;
  printf("x in first() is %d\n", x);
}
 
void second(void) {
  x = 35;
  printf("x in second() is %d\n", x);
}

==> ../../section_05/static_variables/statictest.c <==
#include <stdio.h>
int main() {
    static int i=5;
    if(--i){
        printf("%d ",i);
        main();
    }
}

==> ../../section_06/complex_numbers/challenge1.c <==
#include <stdio.h>
#include <complex.h>
#include <math.h>

#define PI acos(-1)

int main(){
    const double complex num  = 2.00 + 3.00 * I;
    //const double PI = acos(-1); either definition of PI works
    const double complex num1  = 0.00 + 1.00 * I;

    printf("Output of num1 * num1 = %.2f%+.2fi\n", creal(num1 * num1), cimag(num1*num1));
    printf("Output of cpow(num1) = %.2f%+.2fi\n", creal(cpow(num1, 2)), cimag(cpow(num1, 2)));
    printf("Complex conjugate of %.2f%+.2fi  is %.2f%+.2fi\n", creal(num), cimag(num), creal(conj(num)), cimag(conj(num)));
    printf("Output of Euler's formula is %.2f%+.2fi\n", creal(exp(PI * num1)), cimag(exp(PI * num1)));

    return 0;
}

==> ../../section_06/complex_numbers/complex_main.c <==
#include <stdio.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXIT1__ 1

int main() {
    #ifdef __STDC_NO_COMPLEX__
        printf("Complex numbers are not supported.\n");
        exit(1);
    #else
        printf("Complex numbers are supported.\n");

        double complex a = 32.123 + 24.456 * I;
        double complex b = 23.789 + 42.987 * I;
        double complex c = 3.0 + 2.0 * I;
    
        double complex sum = a + b;
        double complex pwr = cpow(a, c);
 
        printf("a  = %.2f%+.2fi\n", creal(a), cimag(a));
        printf("b  = %.2f%+.2fi\n", creal(b), cimag(b));
        printf("c  = %.2f%+.2fi\n", creal(c), cimag(c));
        
        printf("Power = %.2f%+.2fi\n", creal(pwr), cimag(pwr));
    
        printf("Product  = %.2f%+.2fi\n", creal(a*b), cimag(a*b));
    
        printf("Quotient  = %.2f%+.2fi\n", creal(a/b), cimag(a/b));
    
        printf("Difference  = %.2f%+.2fi\n", creal(a-b), cimag(a-b));

        printf("Sum  = %.2f%+.2fi\n", creal(a+b), cimag(a+b));
    
    #endif

    return 0;
}

==> ../../section_06/complex_numbers/main.c <==
#include <stdio.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXIT1__ 1

int main() {
    #ifdef __STDC_NO_COMPLEX__
        printf("COmplex numbers are not supported.\n");
        exit(1);
    #else
        printf("Complex numbers are supported.\n");
    #endif

    double complex cx = 1.0 + 3.0 * I;
    double complex cy = 1.0 - 4.0 * I;

    // %+ means don't always output the '+' symbol, chnage sign dependent on negative or positive value
    printf("Work with complex numbers:\n");
    printf("Starting values;  cx = %.2f%+.2fi  cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

    double complex csum = cx + cy;
    printf("Sum  = %.2f%+.2fi\n", creal(csum), cimag(csum));

    double complex cdiff = cx - cy;
    printf("Difference  = %.2f%+.2fi\n", creal(cdiff), cimag(cdiff));

    double complex cprod = cx * cy;
    printf("Product  = %.2f%+.2fi\n", creal(cprod), cimag(cprod));

    double complex cdiv = cx / cy;
    printf("Quotient  = %.2f%+.2fi\n", creal(cdiv), cimag(cdiv));

    double complex conjugate = conj(cx);
    printf("Conjugate  = %.2f%+.2fi\n", creal(conjugate), cimag(conjugate));


    return 0;
}

==> ../../section_06/designated_initializers/main.c <==
#include <stdio.h>

struct point{
    int x;
    int y;
    int z;
};

int main(){
    //array elements not being initialized in order
    int numbers[100] = {1, 2, 3, [3 ... 9] = 10, [10] = 80, 15, [70] = 50, [42] = 400};
    
    printf("Size of array : %d \n\n", sizeof(numbers)/sizeof(int));

    printf("Array contains :");
    for (int i = 0; i < 100; i++){
        if (i % 20 == 0){
            printf("\n");
        }
        printf("%-3d ", numbers[i]);        
    }
    printf("\n\n");

    // all of following initializers are valid and do the same thing
    struct point p1 = { .y = 2, .x = 3 }; 
    struct point p2 = { y : 2, x : 3 }; 
    struct point p3 = { 3, 2 }; 

    printf("p1 x = %d, y = %d \n", p1.x, p1.y);
    printf("p2 x = %d, y = %d \n", p2.x, p2.y);
    printf("p3 x = %d, y = %d \n\n", p3.x, p3.y);
 
    //cannot use curly bace syntax for reassignment outside fof initializer
    //p1 = { .x = 0, .y = 1, .z = 2 }; does not work here
    p1.y = 1;
    p1.x = 0;
    p1.z = 2;
    p2.x = 20;

    printf("p1 x = %d, y = %d, z = %d \n", p1.x, p1.y), p1.z;
    printf("p2 x = %d \n\n", p2.x);

    struct point pts[5] = { [2].y = 5, [2].x = 6, [0].z = 7 };

    for (int i = 0; i < 5; i++){
        printf("%d %d %d\n", pts[i].x, pts[i].y, pts[i].z);
    }

    return 0;
}

==> ../../section_06/flexible_array_member/challenge1.c <==
#include <stdio.h>
#include <malloc.h>

struct myArray{
    int length;
    int array[];
};

int main(){
    int arrayLength;
    struct myArray *ptr;

    printf("Please enter the size of your array:");
    scanf("%zd", &arrayLength);

    //ptr = (struct myArray*)malloc(sizeof(struct myArray) + arrayLength * sizeof(int));
    ptr = malloc(sizeof(struct myArray) + arrayLength * sizeof(int));

    ptr->length = arrayLength;
    printf("Array length is %d\n", ptr->length);

    for (int i = 0; i < arrayLength; i++){
        printf("Please enter the array element %d: ", i);
        scanf("%zd", ptr->array + i);
    }

    printf("\nArray is size %d and contains: ", arrayLength);
    for (int i = 0; i < arrayLength; i++){
        printf("%d ", ptr->array[i]);
    }

    printf("\n");

    return 0;
}


==> ../../section_06/flexible_array_member/main.c <==
#include <stdio.h>
#include <malloc.h>

struct s {
    int arraySize;
    int array[];   // flexible array can only be declared as the last member of a struct and each struct can
};                 // only contain one flexible array member, any struct containing a flexible array member
                   // cannot be a member of another struct, and must contain at least one other member

int main() {
    int desiredSize = 5;
    struct s *ptr;
    
    // a struct containing a flexible array cannot be statically initialized, must be dynamically allocated (i.e. malloc)
    ptr = (struct s*)malloc(sizeof(struct s)  + desiredSize * sizeof(int));
                                     //allocates memory for flexible array
 
    ptr->arraySize = desiredSize;
    printf("Array size is %d\n", ptr->arraySize);

    for (int i = 0; i < ptr->arraySize; i++)
    {
        printf("Please enter array element %d:", i);
        scanf("%zd", ptr->array + i);
//        ptr->array[i] = i;
    }

    printf("Array is: ");

    for (int i = 0; i < ptr->arraySize; i++)
    {
        printf("%d ", ptr->array[i]);
    }
    printf("\n");

    return 0;
}

==> ../../section_06/typedef/main.c <==
#include <stdio.h>

// i_pointer equiv int*
typedef float* f_pointer;

#define peach int
#define char_pointer char *


unsigned peach i;  // same as unsigned int i




int main() {
    f_pointer p;            // equiv of int *p; 
    f_pointer a, *b;        // equiv of int *a; int **b; 
    char_pointer c, d;      // equiv of char *c; char d;  //d is a char not a char* bcause of comma rule
    f_pointer e, f;         // equiv of float *e; float *f;  //typedef works in different fashion

    f_pointer myArray[10];  // equiv of int* myArray[10]; 

    return 0;
}

==> ../../section_06/variable_length_arrays/challenge1.c <==
#include <stdio.h>

int sum(int size){ 
    int arr[size];
    int tot = 0;

    for (int i = 0; i < size; i++){
        printf("Please enter array element:");
        scanf("%zd", &arr[i]);
     // scanf("%d", &arr[i]);
        tot += arr[i];
    }
 
    return tot;
}

int main(){
    size_t size;

    printf("Please enter the size of your array:");
    scanf("%zd", &size);
    
    printf("The sum total of array elements is %d\n", sum(size));

    return 0;
}

==> ../../section_06/variable_length_arrays/main.c <==
#include <stdio.h>

void array(int size) {
    char alpha[size];
    int x = 0;

    printf("Alpha is: ");    
    while(x < size){
        alpha[x] = 'A' + x;
        printf("%c ", alpha[x]);    
        x++;
    }
    printf("\n");
}

        // rows and cols must be passed in before the array variable
void sum2d(int rows, int cols, int array[rows][cols]){
//void sum2d(int rows, int cols, int array[*][*]){
    int r;
    int c;
    int tot = 0;
    
    for (r = 0; r < rows; r++){
        for (c = 0; c < cols; c++){
            tot += ar[r][c];
        }
    }

    return tot;
}

int main(){
    size_t size = 0;
    
    size_t rows = 0;
    size_t cols = 0;
 
    printf("Enter the number of elements you want to store:");
    scanf("%zd", &size);

    float values[size];

    printf("\nEnter the number of rows you want to store:");
    scanf("%zd", &rows);

    printf("\nEnter the number ofcolumns you want to store:");
    scanf("%zd", &cols);

    float values1[rows][cols];
    
    array(6);
    array(20);
    
    return 0;
}

==> ../../section_07/const/main.c <==
#include <stdio.h>
#include <math.h>

const double pi = acos(-1); //const is idempotent, meaning it can be used more than once and will only count as one usage 

int main(){

    const float *pf; // pf points to a constant float value, value cannot change
 // float const *pf; placement of asterisk means it is the same as statement above order of const and float does not matter 

    float* const pt; // pointer itself is constant, address cannot change

    const float* const ptr; // address held by the pointer is constant and value in address is constant
    

    return 0;
}

// void display(const int array[], int limit) is the same as saying
// void display(const int* array, int limit)



==> ../../section_07/const/using_global.c <==
//if calling a global const must use the same const qualifier when calling it.
extern const double pi;

==> ../../section_07/restrict/main.c <==
#include <stdio.h> 
#include <malloc.h> 

void f1(int n, float * restrict a1, const float * restrict a2)
{
    for(int i =0; i < n; i++){
        a1[i] + a2[i];
    }
}

int main(){
    int array[10];
    
    // means pointer restar is sole means of accessing memory allocated my malloc
    int* restrict restar = (int*) malloc(10*sizeof(int));

    // this cannot be qualified as restrict as there is another means of accessing the daty in the array
    int *par = array;

    // When compiled to assembly language, assembler can optimize by issuing one instruction for restar[n], which
    // is restar[n] += 8, hiwever cannit do the same for par as is accessed via array[n] for *= 2 operation 
    for(int n =0; n < 10; n++){
        par[n] += 5;
	restar[n] += 5; //optimization to += 8 via restrict
	array[n] *= 2;
	par[n] += 3;    
 	restar[n] += 3; //optimization to += 8 via restrict
    }

    return 0;
}

// C99 standard has two functions for moving memory which are
//
// void* memcpy(void* restrict s1, const void* restrict s2, size_t n);  which requires that there is no overlap between the two
// memory blocks specified, which means for the scope of the function both variables are restricted in their access
//
// void* memmove(void *s1, const void *s2, size_t n); whichdoesn't have the requirement that there is no overlap between the two
// blocks of memory and so doesn't use the restrict keyword


==> ../../section_08/binary_nos_bits/challenge1.c <==
#include <stdio.h>

long long convertDecimaltoBinary(int n){
    int base = 1;
    int v = n;
    long long int bin = 0;

    while (v > 1){
        v /= 2;
        base *= 2;
    }

    while (base > 0){
        bin *= 10;

        if (n - base >= 0){
            bin += 1;
            n -= base;
        }
        
        base /= 2;
    }

    return bin;
}

int convertBinaryToDecimal(long long n){
    int base = 1;
    int decimal = 0;
    while (n > 0){
        if (n % 2 == 1)
           decimal += base;
        n /= 10;
        base *= 2;
    }
    
    return decimal;      
}

int main(){
    int decimal;
    long long bin;
    char answer = 'y';

    while (answer == 'y'){
        printf("Would you like to convert a decimal or binary (d or b):");
        scanf("%s", &answer);     
    
        if (answer == 'd'){
            printf("Please enter a decimal number:");
            scanf("%zd", &decimal);
        
            printf("Binary number is %d\n",convertDecimaltoBinary(decimal));
        }
    
        if (answer == 'b'){
            printf("Please enter a binary number:");
            scanf("%zlld", &bin);
        
            printf("Decimal number is %d\n",convertBinaryToDecimal(bin));
        }

        printf("Would you like another conversion (y or n):");
        scanf("%s", &answer);     
    }

    return 0;
}

==> ../../section_08/bitfields/challenge1.c <==
#include <stdio.h>
#include <stdbool.h>

//000 0 black
//001 1 red
//010 2 green
//011 3 yellow
//100 4 blue
//101 5 magenta
//110 6 cyan
//111 7 white

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED + GREEN)
#define MAGENTA (RED + BLUE)
#define CYAN (GREEN + BLUE)
#define WHITE (RED + GREEN + BLUE)

#define SOLID 0
#define DASHED 1
#define DOTTED 2

struct packed_struct {
    unsigned int :4;
    bool fill:1; // 0 - transparent, 1 - opaque
    unsigned int fillColor:3; // 0-7 3-bit color
    unsigned int :2;
    bool border:1; // 0 - no border, 1 - border
    unsigned int borderColor:3; //0-7 3-bit color
    unsigned int borderStyle:2;// 0 -solid, 1 - dashed, 2 - dotted
};

char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
char *styles[3] = {"solid", "dashed", "dotted"};

void print_properties(struct packed_struct box);

int main(){
    struct packed_struct newbox = {true,CYAN,true,BLUE,DOTTED};

    print_properties(newbox);
 
    newbox.fillColor = YELLOW;
    newbox.borderColor = GREEN;
    newbox.borderStyle = SOLID;

    print_properties(newbox);
 
    return 0;
}

void print_properties(const struct packed_struct box){
    printf("fill %s\n", box.fill == true ? "opaque" : "transparent");
    printf("fill Color %s\n", colors[box.fillColor]);
    printf("border %s\n", box.border == true ? "yes" : "no");
    printf("border color %s\n", colors[box.borderColor]);
    printf("border style %s\n\n", styles[box.borderStyle]);
}

==> ../../section_08/bitfields/main.c <==
#include <stdio.h>

struct packed_struct {
    unsigned int :3; // for bit packing n field name specified :3 indicates the padding 3 bits, so contains 29 bits, 29 bits specified below
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
};

// cannot take address of bit fields by use of & or any other dereferencer, cannot create arrays
int main(){
    struct packed_struct packed_data;
    
    packed_data.type = 233; // if you over set it i.e 266 (8 its = 1-255) will only set the lower order 8 bits using the number   
    unsigned int bit = packed_data.type;
                                         //    f1 f2 f3 type index 
    struct packed_struct new_packed_data = {0, 1, 1, 1, 246, 897}; //can use a designated array initializer same way for bit fields

    return 0;
}

==> ../../section_08/bitfields/new.c <==
#include <stdio.h>

int main(){
    int a = 2;

    if (a >> 1){
        printf("%d\n", a);
    }

    return 0;
}

==> ../../section_08/bitmasks/challenge1.c <==
#include <stdio.h>

int main(){
    int input;
    int input1;
    int pos;
    int count = 1;
    int mask = 1;

    printf("Please enter your integer:");
    scanf("%d", &input);

    input1 = input;

    printf("Please enter your position:");
    scanf("%d", &pos);
    
    for (int i = 0; i < pos; i++){
        mask *= 2;
    }

    while (input1 > mask){
        input1 = input1 >> 1;
        count *= 2;        
    }

    if ((input1 & 1) == 1){
        printf("bit in position %d is set\n", pos);
    }
    else{
        printf("bit in position %d is not set\n", pos);
        input = input | count;       
        printf("bit in position %d is now set: %d\n", pos, input);
    }

    return 0;
}

==> ../../section_08/bitmasks/main.c <==
#include <stdio.h>

int main(){
    int flags = 15; //0000 1111
    int mask = 182; //1011 0110
    int flags1; 

    flags1 = flags | mask; // 1011 1111
    flags1 = flags & ~(mask); // 0000 1001
    flags1 = flags ^ mask; // 0000 1001

    //finding if particular bit is set to zero
    mask = 2;

    if ((flags & mask) == mask){
        printf("bit 2 is set\n");
    }

    return 0;
}

==> ../../section_08/bitwise_operators/bit_shifting.c <==
#include <stdio.h>

int main(){
    int w1 = 3; // 0000 0000 0000 0000 0000 0000 0000 0011,  int is represented by 32 bits in binary
    int result = w1 << 1; // bitwise shitft left +1, multiplied by two

    printf("%d\n", result);

    unsigned int w2 = 34; // 0000 0000 0000 0000 0000 0000 0000 0011,  int is represented by 32 bits in binary
    result = w2 >> 1; // bitwise shitft right +1, divided by 2, rightmost bit disappears

    printf("%d\n", result);

    signed int w3 = 142; // 0000 0000 0000 0000 0000 0000 0000 0011,  int is represented by 32 bits in binary
    result = w3 >> 2; // bitwise shitft right +1, divided by 2, rightmost bit disappears

    printf("%d\n", result); // with signed bits can give an undefined result

    return 0;
}

==> ../../section_08/bitwise_operators/challenge1.c <==
#include <stdio.h>

long long decimalToBinary(int n){
    long long bin = 0;
    int count = 1;

    while (n != 0){
        bin += n % 2 * count;
        count *=  10;
        n /= 2;   
    }

    return bin;
}

int main(){
    int decimal1, decimal2;
    printf("Please enter 1st decimal: ");
    scanf("%d", &decimal1);
    printf("Please enter 2nd decimal: ");
    scanf("%d", &decimal2);

    printf("The ones complement of 1st decimal is %d\n", decimalToBinary(~(decimal1)));
    printf("The ones complement of 2nd decimal is %d\n", decimalToBinary(~(decimal2)));
    printf("The bitwise and of 1st and 2nd decimal is %d\n", decimalToBinary(decimal1 & decimal2));
    printf("The bitwise or of 1st and 2nd decimal is %d\n", decimalToBinary(decimal1 | decimal2));
    printf("The bitwise xor of 1st and 2nd decimal is %d\n", decimalToBinary(decimal1 ^ decimal2));
    printf("The bitwise shift right of the 1st decimal is %d\n", decimalToBinary(decimal1 >> 1));
    printf("The bitwise shift left of the 1st decimal is %d\n", decimalToBinary(decimal1 << 2));

    //printf("Binary is %d\n", decimalToBinary(decimal1));  

    return 0;
}

==> ../../section_08/bitwise_operators/main.c <==
#include <stdio.h>

int main(){
    short int w1 = 149;
    short int w2 = 57;
    short int w3 = 0;

    //10011001
    //00111001

    w3 = w1 & w2; // bitwise and

    printf("bitwise and %d\n", w3);

    w3 = w1 | w2; // bitwise or
    
    printf("bitwise or %d\n", w3);

    w3 = w1 ^ w2; // bitwise or
    
    printf("bitwise xor %d\n\n", w3);

    printf("w1 = %d w2 = %d\n", w1, w2);

    //alternate swap operation
     w1 ^= w2;   //10011001
                 //00111001
                 //10100000

     w2 ^= w1;   //00111001
                 //10100000
                 //10011001

     w1 ^= w2;   //10100000
                 //10011001
                 //00111001

    printf("w1 = %d w2 = %d\n\n", w1, w2);

    w3 = ~(w1);  // ones compliment, flips all the bits then adds a 1 at the end
    printf("twos compliment of w1 = %d\n", w3); 

    return 0;
}

==> ../../section_09/commaoperator/main.c <==
#include <stdio.h>

int main(){
    while (i < 100)
        sum += data[i], ++i; //two expressions separated by comma operatof

    int i(5, 10); // 10 is assigned to i

    int j = (f1(), f2()); //return value from f1 is discarded and return value from f2 is assigned to j

    x = (y = 3, (z= ++y + 2) + 5); //assigns value to y first tehn uses y vaue to calculate rest of expression before assigning to x

    for (i = 0, j = 100; i != 10; ++i, j -= 10){ //used to evaluate i an j in the body of the loop

    int houseprice = 249,500; // int houseprice = 249; 500;
    int houseprice = (249,500); // int ouseprice = 500;

    return 0;
}

==> ../../section_09/goto/challenge1.c <==
#include <stdio.h>

int main(){
    int count = 10;
    int i = 1; 
    int j = 0; 
    
    loop:
        if((i != count/2 - j)&&(i != count/2 + j))
            printf(" ");
        else
            printf("*");

        if (j == 4)
            goto end;
         
        i++;
        if (i < count)
            goto loop;
        else{
            printf("\n");
            i = 1;
            j++;
            goto loop;
        }
  
    end:
        printf("********\n");

    return 0;
}

==> ../../section_09/goto/main.c <==
#include <stdio.h>

int main(){
    const int maxInput = 5;
    int i = 0; 
    double number = 0.0, average, sum = 0.0;

    for (i = 0; i < maxInput; i++){
        printf("%d Enter a number:", i);
        scanf("%lf", &number);

        if (number < 0.0){
            goto jump;
        }

        sum += number;
    }

    jump:
        average = sum/i;
        printf("Sum = %.2f\n", sum);
        printf("Average = %.2f\n", average);

    return 0;
}

==> ../../section_09/setjmp-longjmp/error_handling.c <==
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery() {
    printf("Detected an unrecoverable error\n");
    longjmp(buf, 1);
}

int main() {
    while(1){
        if (setjmp(buf)) {
            printf("back in main\n");
            break;
        }
        else {
            error_recovery();
        }
    }

    return 0;
}

==> ../../section_09/setjmp-longjmp/main.c <==
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

int main(){
    int i = setjmp(buf);

    if (i != 0) 
        exit(0);

    printf("i=%d\n", i);
    longjmp(buf, 42);
    printf("Does this line get printed");
    return 0;
}

==> ../../section_09/setjmp-longjmp/newmain.c <==
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction() {
    printf("in myFunction()\n");
    longjmp(buf, 1);
    
    printf("You'll never see this because I longjumped\n");
}

int main(){
    if(setjmp(buf))
        printf("back in main\n");
    else {
        printf("first time through\n");
        myFunction();
    }

    return 0;
}

/*example code if referencing a suspicious pointer*/

void newFunc(){
   int apple, *suspicious; 
   jmp_buf jbuf;

   switch(setjmp(jbuf)){
        case 0:
            apple = *suspicious;
            break;
        case 1:
            printf("suspicious is indeed a bad pointer\n");
            break;
        default:
             ;            //die("Unexpected value returned by longjmp"); 
    }
}

==> ../../section_10/charfunctions/challenge1.c <==
#include <stdio.h>
#include <malloc.h>

void readchfromfile(char **argv);
void readchfromstdin();

int main(int argc, char **argv){
    if (argc == 2){
        printf("One argument was passed\n");
        readchfromfile(argv);
    }
    else if (argc <= 1){
        printf("No argument passed\n");
        readchfromstdin();
    }
    else {
        printf("Incorrect number of arguments passed\n");
    }
    return 0;
}

void readchfromfile(char **argv){
    FILE *pFile;
    char ch;

    int countc = 0;
    int countw = 0;

    pFile = fopen(argv[1],"r");
    if(pFile != NULL){
        while (1) {
            ch = fgetc(pFile);
    
            if ( ch == EOF ) {
                break;
            }
            
            ch == ' ' ? countw++, countc++ : countc++;
            
            printf("%c", ch);
        }
        countw++;     
   
        fclose(pFile);
    }
    
    printf("There are %d words in this file\n", countw);
    printf("There are %d characters in this file\n", countc);
}

void readchfromstdin(){
    char ch;
    int i = 0;

    int countc = 0;
    int countw = 0;

    int size = 256;
    char* charray = (char*)malloc((size)*sizeof(char));
    
    while ((ch = getchar()) != EOF){
        charray[i] = ch;
        ch == ' ' ?  countw++, countc++ : countc++; 
    }
    countw++; 

    printf("\nThere are %d words in stdin\n", countw);
    printf("There are %d characters in stdin\n", countc);
}

==> ../../section_10/charfunctions/challenge2.c <==
#include <stdio.h>
#include <stdlib.h>

FILE* openFile(char* file){
    FILE *fptr;
    char ch = '\0';
    int size = 256;

    fptr = fopen(file, "rw");

    if (fptr == NULL){
        printf("Could not open file\n"); 
        exit(1);
    }
    return fptr;
}

void convertToLower(FILE *fptr, FILE *dest){
    char ch;
    while(1){
        ch = fgetc(fptr);

        if (ch == EOF)
            break;

        if ((ch >= 65) && (ch <= 90)){
            ch = ch + 32;
        }
        fputc(ch, dest);            
    }   
}

void convertToUpper(FILE *fptr, FILE *dest){
    char ch;
    while(1){
        ch = fgetc(fptr);

        if (ch == EOF)
            break;

        if ((ch >= 97) && (ch <= 122)){
            ch = ch - 32;
        }
        fputc(ch, dest);            
    }   
}

FILE* createTemp(){
    FILE *dest = NULL;
    char ch = '\0';

    // Temporary file to store result
    dest = fopen("temp.txt", "w");
    if (dest == NULL){
        printf("Could not open file\n"); 
        exit(1);
    }

    return dest;
}

void convert2Lower(){
    char ch;

    while((ch = getchar()) != EOF){
        ch = ch + 32;
        putc(ch, stdout);
    }
    printf("\n");
}

void convert2Upper(){
    char ch;

    while((ch = getchar()) != EOF){
        ch = ch - 32;
        putc(ch, stdout);
    }
    printf("\n");
}

int main(int argc, char **argv){
    char answer;
    printf("Converter to upper or lower (u or l)?");
    scanf("%c", &answer);

    if (argc == 2){
        FILE *fptr = openFile(argv[1]);
        FILE *dest = createTemp();
        answer == 'u' ? convertToUpper(fptr, dest) : convertToLower(fptr, dest);
        remove(argv[1]);
        rename("temp.txt", argv[1]);
    }
    else if (argc <= 1){
        answer == 'u' ? convert2Upper() : convert2Lower();
    }
    else{
        printf("Incorrect number of arguments given");
    }

    return 0;
}

==> ../../section_10/charfunctions/fgetc.c <==
#include <stdio.h>

/* Function rototype of getc
int fgetc(FILE *fp);  // stdout, stin and stderr all count as files
*/

int example(){
    FILE *fp;
    char ch = '\0';

    fp = fopen("MyFile.c", "r"); // opening an existing file 

    if ( fp == NULL ) {
        printf("Could not open file myFile.c");
        return 1;
    }

    printf("Reading the file myFile.c\n");

    while (1) {
        ch = fgetc(fp);

        if ( ch == EOF ) {
            break;
        }

        printf("%c", ch);

    }

    printf("Closing the file test.c");
    fclose(fp);

    printf("PLease enter a character\n");
    ch = getc(stdin); //getc can be used for any file input stream, whilst getchar is only stdin

    printf("read in character %c\n", ch);

    return 0;
}

int main (){
    example();

    return 0;
}

==> ../../section_10/charfunctions/fputc.c <==
#include <stdio.h>

/*
int fputc(int character, FILE *stream);
*/

int main(){
    FILE *pFile;
    char c;

    pFile = fopen("writefile.txt","w");
    if (pFile != NULL){
        for (c = 'A'; c <= 'Z'; c++){
            fputc(c, pFile);
        }
        fputc('\n', pFile);
        fclose(pFile);
    }

    return 0;
}

==> ../../section_10/charfunctions/getc.c <==
#include <stdio.h>

/* Function rototype of getc

int getc(FILE *stream);  // stdout, stin and stderr all count as files
*/

void example_usage();

int main (){
    char ch = '\0';

    printf("PLease enter a character\n");
    ch = getc(stdin); //getc can be used for any file input stream, whilst getchar is only stdin

    printf("read in character %c\n", ch);
    return 0;
}

void example_usage(){
    char ch = '\0';
    FILE *fp;

    if (fp = fopen("somefile.c", "rw")){
        ch = getc(fp);
        
        while (ch != EOF){
            ch = getc(fp);
        }
        fclose(fp);
    }
}

==> ../../section_10/charfunctions/getchar.c <==
#include <stdio.h>
#include <malloc.h>

/* Function prototype of getchar
int getchar(void); 
*/

void example();

int main (){
    printf("PLease enter a character\n");
    printf("read in character %c\n", getchar());

    example();
    return 0;
}

void example(){
    int ch = 0;

    int i = 0;
    int size = 128;
    char * newarray = (char*)malloc((size)*sizeof(char));

    //can use with EOF as stdin counts as a file, Ctrl+D or Ctrl+Z used as EOF signal, if comparing to EOF, ch should always be int
    while ((ch = getchar()) != EOF){
        //printf("%c\n", ch);
        newarray[i] = (char)ch;
        i ++;
    }

    printf("%s\n", newarray);
}

==> ../../section_10/charfunctions/putc.c <==
#include <stdio.h>

/* Function prototype of getc
int putc(FILE *stream);  // stdout, stin and stderr all count as files
*/

int main (){
    int ch = '0';
    FILE *fp = NULL;
  
//    if (fp = fopen("writefile.txt", "rw")){
//        ch = getc(fp);
        while ((ch = getchar()) != EOF) {
            putc(ch, stdout);
            ch = getc(stdout);
        }
        fclose(fp);
//    }

        

    return 0;
}

==> ../../section_10/charfunctions/putchar1.c <==
#include <stdio.h>

int main (){
    int ch = '0';

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    ungetc(ch, stdin);
    printf("Thank you!\n");

    return 0;
}

==> ../../section_10/charfunctions/putchar.c <==
#include <stdio.h>

/* Function prototype of getc
int putc(FILE *stream);  // stdout, stin and stderr all count as files
*/

int main (){
    char string[] = "Hello Jason, \nWhatever!\n";
    FILE *fp = NULL;
    int i = 0;  

    while (string[i] != '\0') {
        //if (string[i] != '\n') {
            putchar(string[i]);
        //}        
        i++;
    }

    return 0;
}

==> ../../section_10/charfunctions/ungetc.c <==
#include <stdio.h>
#include <ctype.h>

/* Function rototype of ungetc

//allows user to put a character they have just read back into the input stream, cannot determine which character is on the stream 
//until it has been read. can push a succession of characters back into input stream, but only one is guaranteed

int ungetc(int ch, FILE *stream);  // stdout, stin and stderr all count as files
*/

int main (){
    char ch = '\0';

    while(isspace(ch = (char)getchar())){ //Read as long as there are spaces 
        ungetc(ch, stdin);                    //Put back the nonspace character
    }

    printf("put back character %c\n", getchar());
    return 0;
}

==> ../../section_10/formattingfunctions/challenge1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#define LINE_MAX 256

int find_prime(int num);

int identity(int num);

int main(int argc, char **argv){
    FILE *fptr;
    char line[LINE_MAX];
    int i = 0;
    int ch;
    int *num = (int*)malloc(1 * sizeof(int));
 
    if (argc != 2){
        fprintf(stderr, "Incorrect number of arguments passed\n");
        exit(1);
    }

    if((fptr = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Could not open file..\n");
        exit(1);
    }

    while (fgets(line,sizeof(line),fptr)){
        num = (int*)realloc((num), (i+5) *sizeof(int));
        sscanf(line, "%d %d %d %d %d", num+i, num+i+1, num+i+2, num+i+3, num+i+4);
        i += 5;
    }

    int *even = (int*)malloc(1 * sizeof(int)), a=0;
    int *prime = (int*)malloc(1 * sizeof(int)), b=0;
    int *odd = (int*)malloc(1 * sizeof(int)), c=0; 

    for (int j = 0; j < i; j++){
        switch(identity(num[j])){
            case 0: ++a; even = (int*)realloc((even), a*sizeof(int)); even[a-1] = num[j]; break;
            case 1: ++b; prime = (int*)realloc((prime), b*sizeof(int)); prime[b-1] = num[j];
            case 2: ++c; odd = (int*)realloc((odd), c*sizeof(int)); odd[c-1] = num[j]; break;
        }
    }

    printf("Evens:\n");
    for (int j = 0; j < a; j++){
        printf("%d\n", even[j]);
    }

    printf("\nOdds:\n");
    for (int j = 0; j < c; j++){
        printf("%d\n", odd[j]);
    }

    printf("\nPrimes:\n");
    for (int j = 0; j < b; j++){
        printf("%d\n", prime[j]);
    }
 
    return 0;
}

int find_prime(int num){
    int squareRoot = (int)sqrt(num);
    for(int i = 3, j = -1, k = 0; i < squareRoot; i +=2, j++, k++){
        if((k == 3) && (j == 5)) {j = 0, k = 0; continue;}
        if(k == 3) {k = 0; continue;}     
        if(j == 5) {j = 0; continue;}
   
        if((num % i) == 0) { return 1; }
    }
    return 0;
}

int identity(int num){
    if ((num % 2) == 0)
        return 0;
    else if (find_prime(num) == 0) 
        return 1;
    else 
        return 2;
}

==> ../../section_10/formattingfunctions/fprintf.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f = NULL;
    char ch[100];

    //opens the file for read + write operation
    if ((f=fopen("data.txt","r+"))==NULL) {
        printf("Cannot open the file...\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++){
        //enter the strings with values in the file
        fprintf(f, "The count number is %d\n", i + 1);
    }

    fclose(f);
 
    if((f=fopen("data.txt","r+"))==NULL){
        printf("Cannot open the file...\n");
    }

    printf("File content is--\n");
    printf("\n.......print the strings......\n\n");

    //will check for the end of the file whilst reading
    while(!feof(f)){
        fgets(ch,100,f); //will store 100 bytes of string into character buffer ch
        printf("%s",ch); // will print out ch
    }
    
    fclose(f);
 
    return 0;
}

==> ../../section_10/formattingfunctions/fscanf1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

int main() {
    FILE *fp = NULL;
    char wordsbuff[MAX_SIZE];

    fp = fopen("file.txt", "r");
    if ((fp = fopen("data.txt", "a+")) == NULL){
        fprintf(stderr, "Can't open file...\n");
        exit(1);
    }

    rewind(fp); //sets cursor to beginning of the file
    //while not equal to end of file, store words in wordsbuff (fscanf uses spaces as separator, not line breaks)
    while(fscanf(fp, "%s", wordsbuff) != EOF){
        printf("%s ", wordsbuff);
    }

    puts("\nEnter words to add to the file; Press the #");
    puts("Key at the beginning of a line to terminate");

    while((fscanf(stdin,"%40s", wordsbuff) == 1) && (wordsbuff[0] != '#')){
        fprintf(fp, "%s\n", wordsbuff);
    }

    puts("File contents");
    rewind(fp); //sets cursor to beginning of the file

    while(fscanf(fp,"%s%", wordsbuff) == 1){
        puts(wordsbuff);
    }

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");

    return 0;
}

==> ../../section_10/formattingfunctions/fscanf.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

int main() {
    FILE *fp = NULL;
    char wordsbuff[MAX_SIZE];

    fp = fopen("file.txt", "r");

    //while not equal to end of file, store words in wordsbuff (fscanf uses spaces as separator, not line breaks)
    while(fscanf(fp, "%s", wordsbuff) != EOF){
        printf("%s ", wordsbuff);
    }
    printf("\n");
    fclose(fp);

    return 0;
}

==> ../../section_10/formattingfunctions/sprintf.c <==
#include <stdio.h>

int main(){
    char string[100];
    int num = 55;
    sprintf(string, "Hello this is the number: %d", num);
    puts(string); 

    return 0;
}

==> ../../section_10/formattingfunctions/sscanf.c <==
#include <stdio.h>

int main(){
    char *str = "Jason Instructor 43\n";
    char name[10], title[20];
    int age = 0, ret = 0;

    ret = sscanf(str, "%s %s %d", name, title, &age);

    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);
    return 0;
}

==> ../../section_10/formattingfunctions/test.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
   while (putchar(getchar())) ;

   return 0;
}

==> ../../section_10/stringfunctions/challenge1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 256

int has_ch(char ch, const char* line);

int main(int argc, char **argv){
    char linebuf[LINE_MAX];
    char *p = NULL;
    char ch = '\0';    

    if (argc != 3){
        printf("Incorrect number of arguments given\n");
        exit(1);
    }
    
    FILE *fptr = fopen(argv[2], "r");
    if (fptr == NULL){
        printf("File %s failed to open\n", argv[2]);
        exit(1);
    }

    while (fgets(linebuf, sizeof(linebuf), fptr)) {
        p = strchr(linebuf, (char)argv[1][0]);
        if (p){
            puts(linebuf);
        }
    }
    fclose(fptr);

    return 0;
}

int has_ch(char ch, const char* line){
    while(*line)
        if(ch == *line++)
            return 1;

    return 0;
}


==> ../../section_10/stringfunctions/fgets.c <==
#include <stdio.h>
#include <string.h>

#define LINE_MAX 255

int main(){
    char buf[LINE_MAX];
    int ch = '\0';
    char *p = NULL;

    if (fgets(buf, sizeof(buf), stdin)) {
        p = strchr(buf, '\n'); // checks buf for newline character, returns a pointer to the first occurrence
        if (p){ 
            *p = '\0';
        }
        else {
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin)){
                ;
            }
        }
    }
    else{

    }

    printf("Our buffer contains: %s\n", buf);

    return 0;
}

==> ../../section_10/stringfunctions/fputs.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int fputs(const char* buffer, FILE *fileptr);

int main(){
    FILE *fileptr;
    fileptr = fopen("newfile.txt", "w");
    char string[40];
    strcpy(string, "Hello, how are you?\n");
    fputs(string, stdout);
    fputs(string, fileptr);
    fclose(fileptr);

    return 0;
}


==> ../../section_10/stringfunctions/getline.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main(){
    char buffer[99];
    char *b = buffer;
    size_t bufsize = 99;
    size_t characters;

    if (buffer == NULL){
        exit(1);
    }

    printf("Type something :");
    characters = (&b,&bufsize,stdin);
     
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);


    return 0;
}

==> ../../section_10/stringfunctions/puts.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[40];
    strcpy(string, "Hello, how are you?");
    puts(string);

    return 0;

}


==> ../../section_11/recursion/challenge1.c <==
#include <stdio.h>

int sum(int x){
    int answer = 0;
    if (x == 1)
       answer = 0;
    else 
       answer = sum(x - 1);
  
    return(answer+x);
}

int main(){
    int num;
    printf("Enter a number to find the sum of numbers up to: ");
    scanf("%d", &num);

    printf("\nSum of numbers up to %d: %d\n", num, sum(num));

    return 0;
}

==> ../../section_11/recursion/challenge2-alt.c <==
#include <stdio.h>

int findGCD(int, int);

int main(){
    int num1 = 0, num2 = 0;
    printf("Please enter number 1: ");
    scanf("%d", &num1); 
    printf("Please enter number 2: ");
    scanf("%d", &num2); 

    printf("GCD is %d\n", findGCD(num1, num2)); 
    return 0;
}

int findGCD(int a, int b){
   //while (a != b){
       if (a > b)
           a = findGCD(a - b, b);
       else if (b > a)
           a = findGCD(a, b - a);
   //}

   return a;
} 

==> ../../section_11/recursion/challenge2.c <==
#include <stdio.h>
#include <malloc.h>

int GCD(int, int, int, int);

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,71,73,79,83,89,93,97}; 

int main(){
    int num1, num2;
    printf("Please enter number 1 (<200): ");
    scanf("%d", &num1);
    printf("Please enter number 2 (<200): ");
    scanf("%d", &num2);
    int limit = (num1 < num2) ? num1/2 : num2/2;

    printf("%d\n", GCD(num1, num2, 0, limit));
    return 0;
}

int GCD(int x, int y, int z, int limit){
    int num = 0;  

    if (primes[z] > limit){
        return 1;
    }   
    else if (((x % primes[z]) == 0) && ((y % primes[z]) == 0)){
        num = GCD(x/primes[z],y/primes[z],z,limit);
        return num * primes[z];
    }
    else{
        num = GCD(x,y,z+1,limit);
    }
    return num;
}

==> ../../section_11/recursion/challenge3-alt.c <==
#include <stdio.h>

char * reverse(char * str);

int main(){
    char str[100];
    char *rev = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("The original string is: %s\n", str);
    rev = reverse(str);

    printf("The reversed string is: %s\n", rev);
    return 0;
}

char * reverse(char * str){
    static int i = 0;
    static char rev[100];

    if (*str){
        reverse(str + 1);
        rev[i++] = *str;
    }

    return rev;
}

==> ../../section_11/recursion/challenge3.c <==
#include <stdio.h>
#include <malloc.h>

void reverse_string(char*, int);

int main(){
    char *word = (char*)malloc(40*sizeof(char));
    printf("%c\n", (char)66);
    printf("Please enter your string (no spaces): \n");
    fscanf(stdin,"%40s", word);
    reverse_string(word, 0);
    printf("\n");
    return 0;
}

void reverse_string(char *word, int i){
     if (((word[i] >= 65) && (word[i] <= 90))||((word[i] >= 97) && (word[i] < 122)))
         reverse_string(word, i+1);

     printf("%c", word[i]);
}


==> ../../section_11/recursion/recursion.c <==
#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    int result = 0;
 
    if (n == 0)
        result = 1;
    else
        result = n * factorial(n-1);

   return result;
}

int main(){
    for (int i = 1; i <= 8 ; ++i){
        printf("%d! = %d\n", i, factorial(i));
    }
  
    return 0;
}

==> ../../section_11/recursion/upanddown.c <==
#include <stdio.h>

void up_and_down(int);

int main(){
    up_and_down(1);

    return 0;
}

//demonstration
void up_and_down(int n){
    //printf("LEVEL %d: n location %p\n", n, &n);

    if (n < 4)
        up_and_down(n+1);
    
    printf("LEVEL %d: n location %p\n", n, &n);
}

==> ../../section_11/unions/accessingunions.c <==
#include <stdio.h>

union mixed {
    char c;
    float f;
    int i;
};


int main(){
    union mixed x;
    union mixed y = {.f = 8.45 };
    union mixed z = { 'a'};
    union mixed a = z;
    union mixed *b = &a;

    b->c = 'd';
    
    x.c = 'j'; // only c is set
    printf("x.c = %c\n", x.c);
    printf("x.f = %f\n", x.f);
    printf("x.i = %d\n\n", x.i);
    
    x.i = 8; // only i is set
    printf("x.c = %c\n", x.c);
    printf("x.f = %f\n", x.f);
    printf("x.i = %d\n\n", x.i);

    x.f = 9.0; // only f is set
    printf("x.c = %c\n", x.c);
    printf("x.f = %f\n", x.f);
    printf("x.i = %d\n\n", x.i);

    return 0;
}

==> ../../section_11/unions/anonymousunions.c <==
#include <stdio.h>

struct owner {
    char socsecurity[12];
};

struct leasecompany {
    char name[40];
    char headquarters[40];
};

struct car_data {
    char make[15];
    int status; /* 0 = owned, 1 = leased */
    union {
        struct owner owncar;
        struct leasecompany leasecar;
    };
};

struct {
    char* name;
    enum symbolType type;
    union {
        int i;
        float f; 
        char c;
    } data;
} table[entries];


              

==> ../../section_11/unions/challenge1.c <==
#include <stdio.h>

union student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main(){
    union student var1;
    union student var2;

    var1.exactGrade = 80.3; 
    var1.roundedGrade = 80; 
    var1.letterGrade = 'A'; // only letterGrade is set
    printf("var1.letterGrade = %c\n", var1.letterGrade);
    printf("var1.roundedGrade = %d\n", var1.roundedGrade);
    printf("var1.exactGrade = %f\n\n", var1.exactGrade);
    
    var2.letterGrade = 'A'; // only letterGrade is set
    printf("var2.letterGrade = %c\n", var2.letterGrade);
    
    var2.roundedGrade = 86; // only letterGrade is set
    printf("var2.roundedGrade = %d\n", var2.roundedGrade);
    
    var2.exactGrade = 85.6; // only letterGrade is set
    printf("var2.exactGrade = %f\n\n", var2.exactGrade);
    return 0;
}

==> ../../section_11/unions/unions.c <==
#include <stdio.h>

union car {
    int i_value;
    float f_value;
    char c_value[20];
} car4, car5, *car6;

int main(){
    union car car1, car2, *car3;
    printf("Memory size occupied by data %zu\n", sizeof(car1));
    return 0;
}

==> ../../section_11/variadicfunctions/challenge1.c <==
#include <stdio.h>
#include <stdarg.h>

int sum(int v1, ...);

int main(){
    printf("Sum = %d\n", sum(1,2,3,4,5,6));
    return 0;
}

int sum(int v1, ...){
    va_list pargs;
    int value = 0;
    int sum = v1;

    va_start(pargs, v1);

    while ((value = va_arg(pargs, int)) != 0){
        sum += value;    
    }

    va_end(pargs);

    return sum;
}

==> ../../section_11/variadicfunctions/va_copy.c <==
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double sample_stddev(int count, ...);

int main(){
    printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));

    return 0;
}

double sample_stddev(int count, ...){
    double sum = 0;
    
    va_list args1;
    va_start(args1, count);

    va_list args2;
    va_copy(args2, args1);
 
    for (int i =0; i < count; i++){
        double num = va_arg(args1, double);
        sum += num;
    }

    va_end(args1);
    
    double mean = sum/count;
    double sum_sq_diff = 0;
 
    for (int i =0; i < count; i++){
        double num = va_arg(args1, double);
        sum_sq_diff += (num - mean) * (num - mean);
    }

    va_end(args2);

    return sqrt(sum_sq_diff/count);
}

==> ../../section_11/variadicfunctions/variadicfunction.c <==
#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

int main(){
    double v1 =10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;

    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0)); 
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0)); 
    printf("Average = %.2lf\n", average((double)num2, (double)num1, v2, (double)num3, (double)num4, 0.0)); 

    return 0;
}

// Function to calculate the average of two or more arguments
double average(double v1, double v2, ...) {
    va_list parg;					//Pointer for variable list
    double sum = v1 + v2;				//Accumulate sum of the first two fixed arguments
    double value = 0.0;					//Argument value

    int count = 2;					//Count of number of arguments, at least 2
    va_start(parg,v2);					//Initialize argument list, takes va_list and last fixed argument parameter

    while((value = va_arg(parg, double)) != 0.0) {	//va_arg() in stdarg.h, 1st arg va_list, 2nd arg type of argument
        sum += value;					//update pointer parg to point to next argument in the list
        ++count;
    }

    va_end(parg);					//End variable argument

    return sum/count;
}

==> ../../section_13/macros/macro.c <==
#include <stdio.h>

#define PI 3.14 //symbolic constant

//macro resembling a function -  operations defined as symbols
#define PRNT(a,b) \
    printf("value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);

int main(){
    int x = 2;
    int y = 3;
    PRNT(x,y);

/* program body is replaced with 
 *
    int x = 2;
    int y = 3;
    printf("value 1 = %d\n", a); 
    printf("value 2 = %d\n", b);
 *  
 *  prior to compilation
 */
    return 0;
} 

==> ../../section_13/macros/macros2.c <==
#include <stdio.h>

#define PI 3.14

#define CIRCLE_AREA(X) ((PI) * (X) * (X)) //parentheses are needed in a case a parameter llike c + 2 is passed as x, maintains (c+2)*(c+2)

//variadic macros do not require mandatory parameter, use __VA_ARGS__ macro
#define Warning(...) fprintf(stderr, __VA_ARGS__)
//#define Warning(format, ...) fprintf(format, stderr, __VA_ARGS__)

// Avoid "side-effects" in macros such as changing state data of function arguments i.e.
// #define Square(++x) 

#define MISC(x) (puts("incrementing", (x)++))  //comma operator allows both statements to be evaluated, returning value of tstatement on the right

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 * Instead of for loop
for (int i = 0; i < n, i++) ...

Can replace wit a macro i.e.
# define UpTo(i, n) for ((i) = 0; (i) < (n); (i)++)

UpTo(1,10);
*/

int main(){
   float area = CIRCLE_AREA(4);
   printf("Area is %.2f\n", area);
   
   Warning("%s This program is here\n", "Leslie");
   return 0;
}

==> ../../section_13/predefinedmacros/challenge1.c <==
#include <stdio.h>

int main(){
    printf("File is: %s\n", __FILE__);
    printf("Line is: %d\n", __LINE__);
    printf("Date is: %s\n", __DATE__);
    printf("Time is: %s\n", __TIME__);
    (__STDC__ == 1) ? printf("ISO conforming\n") : printf("Non-ISO conforming\n");


    return 0;
}

==> ../../section_13/predefinedmacros/challenge2.c <==
#include <stdio.h>

#define SUM(a,b) ((a) + (b))

int main(){
    printf("%d\n", SUM(4, 5));
    return 0;
}

==> ../../section_13/predefinedmacros/challenge3.c <==
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

#define CUBE(x) ((x) * (x) * (x))

int main(){
    printf("Square of 2: %d\n", SQUARE(2));
    printf("Cube of 3: %d\n", CUBE(3));

    return 0;
}

==> ../../section_13/predefinedmacros/challenge4.c <==
#include <stdio.h>

#define IS_UPPER(x) (((x) <= 90) && ((x) >= 65))
#define IS_UPPER_ALT(x) (((x) <= 'Z') && ((x) >= 'A'))

#define IS_LOWER(x) (((x) <= 122) && ((x) >= 97))
#define IS_LOWER_ALT(x) (((x) <= 'z') && ((x) >= 'a'))

int main(){
    printf("Please enter a character: ");
    char x = getchar();
    IS_UPPER(x) ?  printf("\'%c\' is upper case\n",x) : IS_LOWER(x) ? printf("\'%c\' is lower case\n",x) : printf("\'%c\' is not in alphabet\n",x);

    return 0;
}

==> ../../section_13/predefinedmacros/macros.c <==
#include <stdio.h>

void Leslie(void) {
    printf("%s was called.\n", __func__);
} 

int main() {
  # if (__STDC__ == 1)
    printf("Implementation is ISO conforming.\n");
  # else
    printf("Implementation is not ISO conforming.\n");
  # endif

  printf("File is %s on line %d\n", __FILE__, __LINE__);
  printf("Program was compiled on %s at %s\n", __DATE__, __TIME__);

  Leslie();

  return 0;
}

==> ../../section_13/predefinedmacros/main.c <==
#include <stdio.h>

void main(){
    printf("Hello world\n");
}

==> ../../section_13/preprocessor_directives/elifpreprocessor.c <==
#include <stdio.h>

#define US 0
#define UK 1
#define FR 2
#define DE 3

#if Country == US || Country == UK
    #define GREETING "Hello."
#elif Country == FR
    #define GREETING "Bonjour."
#elif Country == DE
    #define GREETING "Hallo."
#endif 

int main(){
    printf("%s\n", GREETING);
}

==> ../../section_13/preprocessor_directives/ifdef.c <==
#include <stdio.h>

//#define JUST_CHECKING  //sets to  zero by default : also set by : gcc -D JUST_CHECKING -g ifdef.c -o ifdef -std=c99
#define LIMIT 4

int main(){
    int i;
    int total = 0;
    
    for (i = 1; i <= LIMIT; i++){
        total += 2*i*i + 1;
        
        #ifdef JUST_CHECKING
            printf("i=%d, running total = %d\n", i, total);
        #endif
    }

    printf("Grand total = %d\n", total);

    return 0;
}

==> ../../section_13/preprocessor_directives/ifpreprocessor.c <==
#include <stdio.h>

#define MYDEF 4
#define MYOTHERDEF 2

#ifdef UNIX
#  define DATADIR "/uxn1/data"
#else
#  define DATADIR "\usr\data\"
#endif

// can also assign value on command line: GCC -D DATADIR=/c/mydata    


int main(){
    #if MYDEF == 5 && MYOTHERDEF == 2
        printf("Hello\n");
    #endif
}

==> ../../section_13/preprocessor_directives/pragma2.c <==
#include <stdio.h>

#pragma GCC warning "hello"
#pragma GCC error "what"
#pragma message "ok"

/* gcc pragma2.c -o pragma -std=c99
 * return

pragma2.c:3:21: warning: hello [enabled by default]
 #pragma GCC warning "hello"
                     ^
pragma2.c:4:19: error: what
 #pragma GCC error "what"
                   ^
pragma2.c:5:9: note: #pragma message: ok
 #pragma message "ok"
         ^
*/

int main(){
    return 0;
}

==> ../../section_13/preprocessor_directives/pragma.c <==
#include <stdio.h>

#pragma GCC poison printf
/* gcc pragma.c -o pragma -std=c99
 * returns

pragma.c: In function ‘main’:
pragma.c:6:5: error: attempt to use poisoned "printf"
     printf("Hello");
*/


int main(){
    printf("Hello");
    
    return 0;
}

==> ../../section_13/preprocessoroperators/bigmacro.c <==
#include <stdio.h>

#define DeclareSort(prefix, type) \
static int \
_DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) \
{ \
    const type *aa; const type *bb; \
    aa = a; bb = b; \
    if (aa < bb) return -1; \
    else if(bb < aa) return 1; \
    else return 0; \
} \
\
void \
prefix ## _sort(type *a, int n) \
{ \
    qsort(a, sizeof(type), n, _DeclareSort_ ## prefix ## _Compare) ; \
}
/* qsort is a C standard library function*/

#include <stdlib.h>

/* note: must appear outside the function, and has no trailing spa */
DeclareSort(int, int);

int main(int argc, int **argv){
    int x = 5;
    int *a = &x;
    int n = 6;

    int_sort(a, n);

    return 0;
}


==> ../../section_15/debugging/debugging1.c <==
#include <stdio.h>
#include <stdlib.h>

int Debug=0;
#ifdef DEBUG_ON
#define DEBUG(level, fmt, ...) \
  if (Debug >= level) \
     fprintf(stderr, fmt, __VA_ARGS__)
#else
#define DEBUG(level, fmt, ...)
#endif

int process(int i, int j) {
    int val = 0; 

    DEBUG(1, "process(%i, %i)\n", i, j);

    val = i*j;

    DEBUG(3, "return %i\n", val);

    return val;
}

int main(int argc, char **argv) {
    int arg1 = 0, arg2 = 0;

    if (argc > 1)
        arg1 = atoi(argv[1]);
    if (argc > 2 )
        arg2 = atoi(argv[2]);
    if (argc == 4)
        Debug = atoi(argv[3]);

    DEBUG(2, "Processed %i arguments\n", argc);
    DEBUG(3, "arg1 = %i, arg2= %i\n", arg1, arg2);

    printf("%d\n", process(arg1, arg2));
    return 0;
}

==> ../../section_15/debugging/debugging.c <==
#include <stdio.h>

//#define DEBUG

int process(int i, int j, int k) {
     return i + j + k;
}

int main() {
    int i, j, k, nread; 

    nread = scanf("%d %d %d", &i, &j, &k);

    #ifdef DEBUG
        fprintf(stderr, "Number of integers read = %i\n", nread);
        fprintf(stderr, "i = %i, j = %i, k = %i\n", i, j, k);
    #endif

    printf("%d\n", process(i, j, k));
    return 0;
}

==> ../../section_15/gdb/date.c <==
#include <stdio.h>
#include <stdlib.h>

struct date {
    int month;
    int day;
    int year;
};

struct date foo (struct date x) {
    ++x.day;
    return x;
}

int main(){
    struct date today = {10, 11, 2014};
    int array[5] = {1,2,3,4,5};
    struct date *newdate, foo();
    char *string = "test string";
    int i = 3;
    
    newdate = (struct date*)malloc(sizeof(struct date));
    newdate->month = 11;
    newdate->day = 15;
    newdate->year = 2014;
    
    today = foo(today);
    free(newdate);
    
    return 0;
}



==> ../../section_15/gdb/gdb.c <==
#include <stdio.h>

int foo(x){
    return x * x;
}

int main(){
    const int data[5] = {1, 2, 3, 4, 5};
    int i = 0, sum = 0;
    
    for (i = 0; i >= 0; i++)
        sum += data[i];
    
    printf("sum = %i\n", sum);
    
    return 0;
}


==> ../../section_15/profiler/challenge1.c <==
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#ifdef DEBUG_ON
#define DEBUG(...) (fprintf(stderr, __VA_ARGS__))
#else
#define DEBUG(...)
#endif

int sum(int x, int y, int z) {
    char c = 2;
    int *a = (int*)malloc(sizeof(int));
    
    DEBUG("x = %d\n", x);
    DEBUG("y = %d\n", y);
    DEBUG("z = %d\n", z);
    DEBUG("c = %d\n", c);
    DEBUG("a = %d\n", a);
    *a = 5;

    return (c + x + y + z + *a) / 3;
}

int main(int argc, char **argv){
    int i, j, k;
    int result;

    if (argc != 4) {
        printf("Please specify three parameters as number.\n");
        exit(1);
    }

    i = atoi(argv[1]);
    j = atoi(argv[2]);
    k = atoi(argv[3]);

    result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

    printf("%d\n", result);

    return 0;
}

==> ../../section_15/profiler/test2.c <==
#include <stdio.h>

void new_func1(void){
    printf("\nInside new_func1()\n");
    int i = 0;

    for(;i<0xffffffee;i++);

    return;
}

==> ../../section_15/profiler/test.c <==
#include <stdio.h>

void new_func1(void);

void func1(void){
    printf("\nInside func1 \n");
    int i = 0;
    
    for(;i<0xffffffff;i++);
    new_func1();
    
    return;
}

static void func2(void){
    printf("\nInside func1 \n");
    int i = 0;
    
    for(;i<0xffffffff;i++);
    return;
}

int main(void){
    printf("\nInside main()\n");
    int i = 0;
    
    for(;i<0xffffffff;i++);
    func1();
    func2();
    
    return 0;
}

==> ../../section_16/doublepointers/challenge1.c <==
#include <stdio.h>

int main(){
    int a = 4;
    int *ptr = &a;
    int **dblptr = &ptr;

    printf("Value: %d %d %d\n", a, *ptr, **dblptr);
    printf("Value of ptr: %p %p %p\n", &a, ptr, *dblptr);
    printf("Value of dblptr: %p %p\n", &ptr, dblptr);
    printf("Address of dblptr: %p\n", &dblptr);
    return 0;
}

==> ../../section_16/doublepointers/challenge2.c <==
#include <stdio.h>
#include <malloc.h>

void allocateMemory(int **ptr){
    *ptr = malloc(sizeof(int));
}

int main(){
    int *ptr = NULL;
    allocateMemory(&ptr);
    *ptr = 5;
    printf("%d\n", *ptr);
    free(ptr);

    return 0;
}

==> ../../section_16/doublepointers/main1.c <==
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//anything passed into function in C is only a shallow copy, pointer is still empty in main and result in segfault
void foo(char **ptr){
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
}

int main(){
    char *ptr = NULL;
    foo(&ptr);
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}  

==> ../../section_16/doublepointers/main.c <==
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//anything passed into function in C is only a shallow copy, pointer is still empty in main and result in segfault
void foo(char *ptr){
    ptr = malloc(255);
    strcpy(ptr, "Hello World");
    printf("foo() pointer  %p\n", &ptr);
}

int main(){
    char *ptr = NULL;
    printf("main() pointer %p\n", &ptr);
    foo(ptr);
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}  

==> ../../section_16/functionpointers/challenge1.c <==
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int array1[] = {10,20,30,40,50,60,70,80,90,100};
int array2[] = {38,27,87,63,59,223,132,1,19,7};

int add(int a, int b) { return a + b;}
int sub(int a, int b) { return a - b;}
int mult(int a, int b) { return a * b;}
int div(int a, int b) { return a / b;}

//Array of pointers to functions
// INSERT YOU FUNCTION POINTER INITIALIZATION HERE
int (*func_ptr[])(int, int) = {add, sub, mult, div};

// Performs the given operation on elements of the array
int* performOp(int *a, int *b, int size, int (*func_ptr)(int, int));

//displays elemnts of an array
void display(int *x, int size);

int main(){
    int choice = 0;

    // size of the array
    unsigned int size = sizeof(array1) / sizeof(int);

    int *result = NULL;
    char* choices[] =  {"Add", "Subtract", "Multiply", "Divide"};

    while (choice != 5){
        printf("\n\nWhich operation do you wish to perform?\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
	printf("5. None\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice < 1 || choice > 5) continue;

        int j = choice - 1;

        printf("You have chosen %s\n", choices[j]);
        result = performOp(array1,array2,size, func_ptr[j]);

        printf("\nThe results are ...\n");
        display(result,size);

        if (result != NULL) 
            free(result);
    }

    return 0;
}


int* performOp(int *a, int *b, int size, int (*func_ptr)(int, int)){
    int * result = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++){
        result[i] = (*func_ptr)(a[i], b[i]);
    }
    return result;
}

void display(int *x, int size){
    printf("\n---Display has been called---\n");
    for (int i = 0; i < size; i++){
        i == size -1 ? printf("%d\n", x[i]) : printf("%d, ", x[i]);
    }
}

==> ../../section_16/functionpointers/funcpointers.c <==
#include <stdio.h>

int somedisplay();
void func1(int);
void func2(int);

typedef void FuncType(int);

int main(){
    int (*func_ptr)() = somedisplay;

  //  func_ptr = somedisplay;
    printf("\nAddress of function some display is %p\n", func_ptr);

    (*func_ptr)();

    FuncType *new_func_ptr = NULL;
    new_func_ptr = func1;

    (*new_func_ptr)(100);

    new_func_ptr = func2;
    
    (*new_func_ptr)(200);

    return 0;
}

int somedisplay(){
    printf("\n--Displaying some text--\n");
    return 0;
}

void func1(int x){
    printf("\nNumber passed to func1(int x) is %d\n", x);   
}

void func2(int x){
    printf("\nNumber passed to func2(int x) is %d\n", x);   
}


==> ../../section_16/voidpointers/main.c <==
#include <stdio.h>

int main(){
    int i = 10;
    float f = 2.34;
    char c = 'k';

    void *vptr = NULL;

    vptr = &i;
    printf("void pointer points to value %d\n", *(int*)vptr);

    vptr = &f;
    printf("void pointer points to value %f\n", *(float*)vptr);

    vptr = &c;
    printf("void pointer points to value %c\n", *(char*)vptr);

    int *iptr =  NULL;
    float *fptr =  NULL;
    char *cptr =  NULL;
    void *voptr = NULL;
     
    printf("size of int* %zu\n", sizeof(iptr));
    printf("size of float* %zu\n", sizeof(fptr)); 
    printf("size of char* %zu\n", sizeof(cptr));
    printf("size of void* %zu\n", sizeof(voptr));
    printf("size of *(int*) %zu\n", sizeof(*iptr));
    printf("size of *(float*) %zu\n", sizeof(*fptr)); 
    printf("size of *(char*) %zu\n", sizeof(*cptr));
    printf("size of *(void*) %zu\n", sizeof(*voptr));


    return 0;
}

==> ../../section_17/dynamiclibraries/libnew.c <==
#include <stdio.h>
#include "libnew.h"

void fun(){
    printf("fun() called from a dynamic library\n");
} 


==> ../../section_17/dynamiclibraries/main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "libnew.h"

int main(){
    fun();

    return 0;
}

==> ../../section_17/dynamicloading/challenge1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void checkForError() {
    char *error = NULL;
    
    if ((error = dlerror()) != NULL){
        fputs(error, stderr);
        exit(1);	
    }
}

int main(){
    void *handle = NULL;
    char *error = NULL;

    int (*findStringLen)(char*) = NULL;
    int (*findCharFreq)(char*, char) = NULL;
    void (*removeNonAlpha)(char**) = NULL;
    int (*concatenateStr)(char**, char*) = NULL;
    int (*stringCpy)(char*, char**) = NULL;
    int (*substr)(char*, int, int, char**) = NULL;

    handle = dlopen("/home/tetteh_l/advanced_c/section_17/staticlibraries/lib_stringfunction.so", RTLD_LAZY);
    if (!handle){
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror(); /* clear error code */

    findStringLen = dlsym(handle, "findStringLength");
    checkForError();
    findCharFreq = dlsym(handle, "findCharFrequency");
    checkForError();
    removeNonAlpha = dlsym(handle, "removeNonAlphabetic");
    checkForError();
    concatenateStr = dlsym(handle, "concatenateStrings");
    checkForError();
    stringCpy = dlsym(handle, "stringCopy");
    checkForError();
    substr = dlsym(handle, "substring");
    checkForError();

    char* string1 = "Hello y'all I'm Dave";   
    char* string2 = "Hey everyone. What's my name?";   
    char* string3 = (char*)malloc(2*sizeof(char));
    char* string4 = (char*)malloc(2*sizeof(char));

    printf("The string length of string1 is %d\n", (*findStringLen)(string1));
    printf("The letter 'e' is in string2 %d times\n", (*findCharFreq)(string2, 'e'));
    (*stringCpy)(string1, &string3);
    printf("Copied string1 to string3, string 3 is now %s\n", string3);
    (*concatenateStr)(&string3, string2);
    printf("Concatenated string2 to string3, string 3 is now %s\n", string3);
    removeNonAlpha(&string3);
    printf("Removed non alphabetic characters from string 3, string 3 is now %s\n", string3);
    (*substr)(string3, 5, 15, &string4);
    printf("Substring from string3 from position 5 to position 15 is  %s\n", string4);
   
    return 0;
}

==> ../../section_17/dynamicloading/main.c <==
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
    void *handle = NULL;
    double (*cosine)(double) = NULL;
    char *error = NULL;

    handle = dlopen("/lib64/libm.so.6", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror(); /* clear error code */
    cosine = dlsym(handle, "cos");
    if ((error = dlerror()) != NULL){
        fputs(error, stderr);
        exit(1);
    }
    
    printf("%f\n", (*cosine)(2.0));
    dlclose(handle);

    return 0;
}

==> ../../section_17/staticlibraries/lib.c <==
#include <stdio.h>

void fun(void){
    printf("fun() called from a static library\n");
}

==> ../../section_17/staticlibraries/main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    fun();
    return 0;
}


==> ../../section_17/staticlibraries/newmain.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stringfunctions.h"

int strCopy(char *source, char *destination){
    char i;

    printf("Address of destination is %p\n", destination);
    for (i = 0; source[i] != '\0'; ++i){
        destination[i] = source[i];        
    }

    destination[i] = '\0';  

    return 0;
}

int main(){
    char* string1 = "Hello y'all I'm Dave";   
    char* string2 = "Hey everyone. What's my name?";   
    char* string3 = (char*)malloc(2*sizeof(char));
    char* string4 = (char*)malloc(2*sizeof(char));
    char temp3[100];

    printf("The string length of string1 is %d\n", findStringLength(string1));
    printf("The letter 'e' is in string2 %d times\n", findCharFrequency(string2, 'e'));
    stringCopy(string1, &string3);
    printf("Copied string1 to string3, string 3 is now %s\n", string3);
    concatenateStrings(&string3, string2);
    printf("Concatenated string2 to string3, string 3 is now %s\n", string3);
    removeNonAlphabetic(&string3);
    printf("Removed non alphabetic characters from string 3, string 3 is now %s\n", string3);
    substring(string3, 5, 15, &string4);
    printf("Substring from string3 from position 5 to position 15 is  %s\n", string4);
   
    printf("Address of temp3 = %p\n", temp3);
    strCopy(string1, temp3);
    printf("%s\n", temp3);
    return 0;
}

==> ../../section_17/staticlibraries/stringfunctions.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int findStringLength(char *s){
    int i = 0;
    while(s[i]){
        i++;
    }

    return i;
}

int findCharFrequency(char *s,char c){
    int i = 0;
    int count = 0;
    while(s[i]){
        if (s[i] == c)
            count++;
        i++;
    }

    return count;
}

void removeNonAlphabetic(char **s){
    int length = findStringLength(*s);
    int newlength = length;

    while(**s){
        if ((**s >= 0 && **s < 65)||(**s > 90 && **s < 97)||(**s > 122)){
            int count = 0;
            newlength--;
            while (**s){
                **s = *(*s + 1);
                count++;
                *s += sizeof(char);
            }
            *s -= (newlength * sizeof(char));
        }
        *s += sizeof(char);
    }
    *s -= newlength * sizeof(char);
}

int concatenateStrings(char **s1, char *s2){
    int length1 = findStringLength(*s1);
    int length2 = findStringLength(s2);

    *s1 = (char*)realloc(*s1, (length1 + length2) * sizeof(char));
    *s1 += (length1 * sizeof(char));
    for (int i = length1; i < (length1 + length2); i++){
        **s1 = s2[i - length1];
        *s1 += sizeof(char);
    }
    *s1 -= ((length1 + length2) * sizeof(char));

    int i = 0;
    while(s2[i]){
        if (s2[i] != *(*s1 + length1 + i))
            return 1;
        i++;
    }

    return 0;
}
int stringCopy(char *s1, char** s2){
    int length1 = findStringLength(s1);
    *s2 = (char*)realloc(*s2, length1 * sizeof(char));
    for (int i = 0; i < length1; i++){
        **s2 = s1[i];
        *s2 += sizeof(char);
    }
    *s2 -= (length1 * sizeof(char));

    int i = 0;
    while(s1[i]){
        if (s1[i] != *(*s2 + i))
            return 1;
        i++;
    }

    return 0;
}

int substring(char *s, int from, int to, char **tg){
    if (from >= to){
        return 1;
    }

    *tg = (char*)realloc(*tg, to - from * sizeof(char));
    for (int i = from; i <= to; i++){
        **tg = s[i];
        *tg += sizeof(char);
    }
    *tg -= (to - from * sizeof(char));

    int i = 0;
    while((from + i) <= to){
        if (s[from + i] != *(*tg + i))
            return 1;
        i++;
    }

    return 0;
}

==> ../../section_17/testfolder/main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "libnew.h"

int main(){
    fun();

    return 0;
}

==> ../../section_17/testfolder/newmain.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stringfunctions.h"

int strCopy(char *source, char *destination){
    char i;

    printf("Address of destination is %p\n", destination);
    for (i = 0; source[i] != '\0'; ++i){
        destination[i] = source[i];        
    }

    destination[i] = '\0';  

    return 0;
}

int main(){
    char* string1 = "Hello y'all I'm Dave";   
    char* string2 = "Hey everyone. What's my name?";   
    char* string3 = (char*)malloc(2*sizeof(char));
    char* string4 = (char*)malloc(2*sizeof(char));
    char temp3[100];

    printf("The string length of string1 is %d\n", findStringLength(string1));
    printf("The letter 'e' is in string2 %d times\n", findCharFrequency(string2, 'e'));
    stringCopy(string1, &string3);
    printf("Copied string1 to string3, string 3 is now %s\n", string3);
    concatenateStrings(&string3, string2);
    printf("Concatenated string2 to string3, string 3 is now %s\n", string3);
    removeNonAlphabetic(&string3);
    printf("Removed non alphabetic characters from string 3, string 3 is now %s\n", string3);
    substring(string3, 5, 15, &string4);
    printf("Substring from string3 from position 5 to position 15 is  %s\n", string4);
   
    printf("Address of temp3 = %p\n", temp3);
    strCopy(string1, temp3);
    printf("%s\n", temp3);
    return 0;
}

==> ../../section_18/assert/main.c <==
#include <stdio.h>
#include <assert.h>

int main(){
    int y = 5;
    
    for (int x = 0; x < 20; x++){
        printf("x = %d, y = %d\n", x, y);
        assert(x < y); //when x >= y program will abort as condition is no longer true
    }

    return 0;
}



==> ../../section_18/assert/newmain.c <==
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(){
    double x, y, z;

    puts("Enter a pair of numbers (0 0 to quit): ");
    while(scanf("%lf %lf", &x, &y) == 2 && (x != 0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("Answer is %f\n", sqrt(z));
        puts("Next pair of numbers ");
    }
    puts("Done");

    return 0;
}

==> ../../section_18/assert/static_assert.c <==
#include <stdio.h>
#include <limits.h>
#include <assert.h>

static_assert(CHAR_BIT == 16, "16-bit char falsely assumed.");

int main(){
    puts("char is 16 bits.");
    return 0;
}

==> ../../section_18/date_time/birthday.c <==
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){
    time_t calendar_start = time(NULL);

    struct tm* time_data;
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const char* suffix[] = {"st", "nd", "rd", "th"};
    time_data = localtime(&calendar_start);

    enum sufindex { st, nd, rd, th} sufse1 = th;
    
    struct tm birthday = {0};
    char name[30] = {'\0'};
  
    printf("Enter a name: ");
    scanf("%s", name);

    printf("Enter the birthday for %s as day month year integers separated by spaces\ne.g. Enter the 1st February 1985 as 1 2 1985 : ", name);

    printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year+1900);

    scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);
     
    birthday.tm_mon -= 1;
    birthday.tm_year -= 1900;
   
    time_t bday_now;
    if ((bday_now = mktime(&birthday)) == -1){
        fprintf(stderr, "Operation failed.\n");
        return -1;
    }
    switch(birthday.tm_mday) {
        case 1: case 21: case 31:
            sufse1 = st;
            break;
        case 2: case 22:
            sufse1 = nd;
            break;
        case 3: case 23:
            sufse1 = rd;
            break;
        default:
            sufse1 = th;
            break;
    }

    printf("%s was born on the %d%s %s %d, which was a %s.\n", name, birthday.tm_mday, suffix[sufse1], months[birthday.tm_mon], birthday.tm_year, days[birthday.tm_wday]);
    printf("%lld %lld\n", (long long)calendar_start, (long long)bday_now);

    return 0;
}

==> ../../section_18/date_time/challenge3-alt.c <==
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){
    time_t calendar_start = time(NULL);

    if (calendar_start == ((time_t)-1)){
        fprintf(stderr, "Failed to get the current time.\n");
        exit(1);
    } 

    char* time_string = ctime(&calendar_start);

    if (time_string == NULL){
        fprintf(stderr, "Failed to convert the current time.\n");
        exit(1);
    }

    printf("The current time is %s\n", time_string);
    return 0;
}

==> ../../section_18/date_time/challenge3.c <==
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){
    time_t calendar_start = time(NULL);

    if (calendar_start == ((time_t)-1)){
        fprintf(stderr, "Failed to get the current time.\n");
        exit(1);
    } 

    struct tm now;
    now = *(localtime(&calendar_start));

    printf("The current time is %d:%d:%d\n", now.tm_hour, now.tm_min, now.tm_sec);
    return 0;
}

==> ../../section_18/date_time/challenge4.c <==
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int main(){
    time_t calendar_now = time(NULL);
    time_t calendar_start;
    struct tm time_now;
    struct tm first_of_mon;
    time_now = *(localtime(&calendar_now));

    first_of_mon = time_now;
    first_of_mon.tm_mday = 1;
    first_of_mon.tm_hour = 0;
    first_of_mon.tm_min = 0;
    first_of_mon.tm_sec = 0;

    if ((calendar_start = mktime(&first_of_mon)) == -1){
        fprintf(stderr, "mktime failed to convert tm structure to time_t");
        return -1;
    }

    printf("%.2d:%.2d:%.2d %.2d/%.2d/%.4d\n", first_of_mon.tm_hour, first_of_mon.tm_min, first_of_mon.tm_sec, first_of_mon.tm_mday, first_of_mon.tm_mon, first_of_mon.tm_year+1900); 

    printf("%lld %lld\n", (long long)calendar_now, (long long)calendar_start);
    printf("%lld\n", (long long)calendar_now - (long long)calendar_start);
    printf("Number of seconds elapsed = %.2lf\n", difftime(calendar_now, calendar_start));

    return 0;
}

==> ../../section_18/date_time/date_time_funcs.c <==
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){
    time_t calendar_start = time(NULL);
    clock_t cpu_start = clock();
    int count = 0;

    const long long iterations = 1000000000LL;
    char answer = 'y';
    double x = 0.0;
    
    printf("Initial clock time = %lld Initial calendar time = %lld\n", (long long)cpu_start, (long long)calendar_start );

    while(tolower(answer) == 'y'){
        for(long long i = 0LL; i < iterations; i++){
            x = sqrt(3.14159265);
        }

        printf("%lld square roots completed.\n", iterations*(++count));
        printf("Do you want to run some more(y or n)? \n");
        scanf("\n%c", &answer);
    }

    clock_t cpu_end = clock();
    time_t calendar_end = time(NULL);

    printf("Final clock time = %lld Final calendar time = %lld \n", (long long)cpu_end, (long long)calendar_end);
    printf("CPU time for %lld iterations is %.2lf seconds\n", count*iterations, ((double)(cpu_end-cpu_start))/CLOCKS_PER_SEC);
    printf("Elapsed calendar time to execute the program is %.2lf seconds \n", difftime(calendar_end, calendar_start));
    return 0;
}

==> ../../section_18/date_time/time.c <==
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(){
    time_t calendar_start = time(NULL);

    struct tm* time_data;
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    time_data = localtime(&calendar_start);

    printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year+1900);
    return 0;
}

==> ../../section_18/stdlibutils/atof.c <==
#include <stdio.h>
#include <stdlib.h>

/* function prototype
long int atof(char const *c);
*/

int main(){
    char a[10] = "3.14";
    float value = atof(a);
    
    printf("%f\n", value);
    return 0;
}

==> ../../section_18/stdlibutils/atoi.c <==
#include <stdio.h>
#include <stdlib.h>

/* Function prototype of atoi() is
    int atoi(char const *s)
*/

int main(){
    char a[100] = "100";
    int value = atoi(a);

    printf("%d\n", value);
    return 0;
}

==> ../../section_18/stdlibutils/atol.c <==
#include <stdio.h>
#include <stdlib.h>

/* function prototype
long int atol(char const *c);
*/

int main(){
    char a[10] = "1234567890";
    int value = atol(a);
    
    printf("%ld\n", value);
    sprintf(a, "%d", 45);

    printf("%s\n", a);
    return 0;
}

==> ../../section_18/stdlibutils/challenge1.c <==
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(0));
    double x;
    
    printf("Printing 50 random numbers:\n");

    for (int i = 0 ; i < 50; i++){
        x = rand();
        while (x > 1)
            x /= 10;

        x -= 0.5;
        printf("%.8f\n", x);
    }

    return 0;
}

==> ../../section_18/stdlibutils/challenge2.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int compare_doubles(const void* p1, const void* p2);

int main(){
    double *ar = (double*)malloc(sizeof(double));
    int size = 0;
    srand(time(0));

    printf("Please enter the size of the array you would like to create:");
    scanf("%d", &size);

    fillarray(ar, size);
    showarray(ar, size);
    qsort(ar, size, sizeof(double), compare_doubles);

    showarray(ar, size);
    return 0;
}

void fillarray(double ar[], int n){
    ar = (double*)realloc(ar, (n * sizeof(double)));
    double x = 0;

    for (int i = 0 ; i < n; i ++){
        x = rand();
        while (x > 100)
            x /= 100;
        ar[i] = x;
    }
}

void showarray(const double ar[], int n){
    for (int i = 0 ; i < n; i ++)
        i % 5 == 0 ? printf("\n%10.5f ", ar[i]) : printf("%10.5f ", ar[i]);

    printf("\n");
}

int compare_doubles(const void* p1, const void* p2){
    const double d1 = *(const double*)p1;
    const double d2 = *(const double*)p2;
    
    return d1 > d2; // retruns 1 if true, 0 if false
}

==> ../../section_18/stdlibutils/getenv.c <==
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    char *str = NULL;
 
    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Environment Variable\" : %s\n\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Environment Variable\" : %s\n\n", str);

    assert((str = getenv("LOGNAME")) != NULL);
    printf("Value of \"LOGNAME Environment Variable\" : %s\n\n", str);

    assert((str = getenv("LESLIE")) != NULL);
    printf("Value of \"LESLIE Environment Variable\" : %s\n\n", str);

    return 0;
}


==> ../../section_18/stdlibutils/main.c <==
#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(){
    int n = 0;

    atexit(sign_off); //Register the sign_off function

    if (scanf("%d", &n) != 1){
        puts("That's no integer!");
        atexit(too_bad); // register the too_bad() function
        exit(EXIT_FAILURE);  
    }
    return 0;
}

void sign_off(void){
    puts("Sign off..");
}

void too_bad(void){
    puts("Too bad..");
}


==> ../../section_18/stdlibutils/memcpy.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void show_array(const int ar[], int n);

//static_assert(sizeof(double) == 2 * sizeof(int), "Assertion raised: double not twice int size");

int main(){
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
    puts("memcpy() used");
    puts("Values (original data)");
    show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("Target (copy of values0: ");
    show_array(target, SIZE);

    puts("\n Using memmove with overlapping ranges: ");
    memmove(values +2, values, 5 * sizeof(int));
    puts("values -- elents ---5 copied to 2-7");
    show_array(values, SIZE);

    puts("\nUsing memcpy() to copy double tto int");
    memcpy(target, curious, SIZE/2);
    puts("target -- doubles into 10 int positions ");
    show_array(target, SIZE);
    show_array(target + 5, SIZE);

    return 0;
}

void show_array(const int ar[], int n){
    int i;

    for (i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
}



==> ../../section_18/stdlibutils/newmain.c <==
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fp;
    
    fp = fopen("somefile.txt","r");

    if (fp == NULL){
        printf("Going to abort the program\n");
        abort();
    }

    printf("Going to abort the program\n");
    abort();

    return 0;
}

==> ../../section_18/stdlibutils/qsort.c <==
#include <stdlib.h>
#include <stdio.h>

int comp_ints(const void*,const void *);

int main(){
    int data[5] = {54, 3, 12, 9, 24};
    qsort(data, 5, sizeof(int), comp_ints);
         //array, size, element size, function name 
   
    for (int i = 0; i < 5; i++){
        printf("%d\n", data[i]);
    }    

    return 0;
}

int comp_ints(const void *p1, const void* p2){
    const int i1 = *(const int*) p1;
    const int i2 = *(const int*) p2;
    return i1 - i2; //should return 1(true) if 1 > i2, return 0 (false) if i1 == 12 and 0 (false) if i2 Vp1
}

==> ../../section_18/stdlibutils/rand.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    for (int i = 0; i < 5; i++){
        printf("%d\n", rand());
    }
    return 0;
}

==> ../../section_18/stdlibutils/sprintf.c <==
#include <stdio.h>
#include <stdlib.h>

//best way to convert from int, float or doube to a string is the sprintf function shown below
int main(){
    char a[10];
    
    sprintf(a, "%d", 45);

    printf("%s\n", a);
    return 0;
}

==> ../../section_18/stdlibutils/srand.c <==
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));

    for(int i=0; i<10; i++){
        printf("%d\n", rand() % 5 + 1);
    }

    return 0;
}

==> ../../section_18/stdlibutils/strdup.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p1 = "Leslie";
    char *p2 = NULL;

    p2 = strdup(p1);
    
    printf("duplicated string is %s\n", p2);
    return 0;
}

==> ../../section_18/stdlibutils/strndup.c <==
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(){
    char p1[] = "Leslie";
    char *p2 = strndup(p1, 6);
    
    //5 bytes of memory are copied to a new memory location and allocated
    //dynamiclly using malloc and pointer to the copied memory is returned
    printf("duplicated string is %s\n", p2);
    free(p2);
    return 0;
}

==> ../../section_18/stdlibutils/strtod.c <==
#include <stdio.h>
#include <stdlib.h>

/* function prototype
double strtod(const char *s, char ** end);
*/

int main(){
    char a[] = "123.456xyz", *end;
    double value = 0;
    
    value = strtod(a, &end);

    printf("Value = %1f\n", value);
    return 0;
}

==> ../../section_18/stdlibutils/strtof.c <==
#include <stdio.h>
#include <stdlib.h>

/* function prototype
float strtof(const char *s, char ** end);
*/

int main(){
    char a[] = "123.4 7.89", *end;
    float value = 0, value2 = 0;
    
    value = strtof(a, &end);
    value2 = strtof(end, NULL);

    printf("Value1 = %lf\n", value);
    printf("Value2 = %lf\n", value2);
    return 0;
}

==> ../../section_18/stdlibutils/strtol.c <==
#include <stdio.h>
#include <stdlib.h>

/* function prototype
float strtol(const char *s, char ** end, int base);
*/

int main(){
    char str[30] = "2030300 This is a test", *end;
    char *ptr = NULL;
    long ret = 0;
    ret = strtol(str, &ptr, 10);
    printf("The number (unsigned long integer) is %1d\n", ret);
    printf("String part is |%s|\n", ptr);
    
    return 0;
}

==> ../../section_18/stdlibutils/system.c <==
#include <stdlib.h>
#include <string.h>

int main() {
    char command[50];

    strcpy(command, "ls -l");
    system(command);
    return 0;
}

==> ../../section_19/binarytrees/binarytree.c <==
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    int data;
    struct treeNode* leftPtr;
    struct treeNode* rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(){
    int item = 0;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");

    for (int i = 0; i < 10; i++) {
        item = rand() % 15;
        insertNode(&rootPtr, item);
    }
    printf("\n");

    inOrder(rootPtr);
    printf("\n");
    preOrder(rootPtr);
    printf("\n");
    postOrder(rootPtr);
    printf("\n");

    return 0;
}

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL) {
	*treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));
	if (*treePtr != NULL) {
	    (*treePtr)->data = value;
	    (*treePtr)->leftPtr = NULL;
	    (*treePtr)->rightPtr = NULL;
	}
        else 
            printf("%d not inserted. No memory available\n", value);
    }
    else {
	if (value < (*treePtr)->data)
	    insertNode(&((*treePtr)->leftPtr), value);
	else if (value > (*treePtr)->data)
	    insertNode(&((*treePtr)->leftPtr), value);
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL){
	inOrder(treePtr->leftPtr);
        printf("%5d", treePtr->data);
	inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL){
        printf("%5d", treePtr->data);
	preOrder(treePtr->leftPtr);
	preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL){
	postOrder(treePtr->leftPtr);
	postOrder(treePtr->rightPtr);
        printf("%5d", treePtr->data);
    }
}


==> ../../section_19/linkedlist/challenge1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int value;
    struct node* nextNode;
} node_t;

typedef node_t* nodePtr;

void insertAtFirst(nodePtr *head, int x);
void insertAtLast(nodePtr *head, int x);
void insertAtPosition(nodePtr *head, int x, int pos);
int deleteFromPosition(nodePtr *head, int x, int pos);
int updateNodeValue(nodePtr *head, int x, int pos);
int searchElement(nodePtr head, int x);
void printList(nodePtr head);

int main(){
    int choice = -1;
    int value = -1;
    int pos = -1;
    nodePtr head = (nodePtr)malloc(sizeof(node_t));

    printf("Please select from one of the following options\n"
	"   1. Insert an integer at the beginning of the list\n"
	"   2. Insert an integer at the end of the list\n"
	"   3. Insert an integer at a specified position in the list\n"
	"   4. Delete an integer at a specified position in the list\n"
	"   5. Update an integer at a specified position in the list\n"
	"   6. Find an integer within the list\n"
	"   7. Print the list\n"
	"   8. Exit\n"
	"   :: ");

    scanf("%d", &choice);

    while(choice != 8)
    {
        switch(choice){
	    case 1: printf("Please enter an integer: ");
                    scanf("\n%d", &value);
                    insertAtFirst(&head, value);
                    printList(head);
		    break; 
	    case 2: printf("Please enter an integer: ");
                    scanf("\n%d", &value);
                    insertAtLast(&head, value);
                    printList(head);
		    break; 
	    case 3: printf("Please enter an integer: ");
                    scanf("\n%d", &value);
                    printf("\nPlease enter a position: ");
                    scanf("\n%d", &pos);
                    insertAtPosition(&head, value, pos);
                    printList(head);
		    break; 
	    case 4: printf("\nPlease enter a position: ");
                    scanf("\n%d", &pos);
                    deleteFromPosition(&head, value, pos);
                    printList(head);
		    break; 
	    case 5: printf("Please enter an integer: ");
                    scanf("\n%d", &value);
                    printf("\nPlease enter a position: ");
                    scanf("\n%d", &pos);
                    updateNodeValue(&head, value, pos);
                    printList(head);
		    break; 
	    case 6: printf("Please enter an integer: ");
                    scanf("\n%d", &value);
                    searchElement(head, value);
                    printList(head);
		    break; 
	    case 7:
                    printList(head);
		    break; 
	    default: printf("You did not select a valid option\n");
                    printf("Please select from one of the following options\n"
                	"   1. Insert an integer at the beginning of the list\n"
                	"   2. Insert an integer at the end of the list\n"
                	"   3. Insert an integer at a specified position in the list\n"
                	"   4. Delete an integer at a specified position in the list\n"
                	"   5. Update an integer at a specified position in the list\n"
                	"   6. Find an integer within the list\n"
                	"   7. Print the list\n"
                	"   8. Exit\n"
                	"   :: ");
                
                    scanf("\n%d", &choice);

		    break; 
	}
        printf("Please select from one of the following options\n"
    	"   1. Insert an integer at the beginning of the list\n"
    	"   2. Insert an integer at the end of the list\n"
    	"   3. Insert an integer at a specified position in the list\n"
    	"   4. Delete an integer at a specified position in the list\n"
    	"   5. Update an integer at a specified position in the list\n"
    	"   6. Find an integer within the list\n"
    	"   7. Print the list\n"
    	"   8. Exit\n"
    	"   :: ");
    
        scanf("%d", &choice);
    }

    return 0;
}

void insertAtFirst(nodePtr *head, int x)
{
    if ((**head).value){
        nodePtr newPtr = (nodePtr)malloc(sizeof(node_t));
        newPtr->value = x;
        newPtr->nextNode = *head;
        *head = newPtr;
    }
    else{
        (**head).value = x;
    }
}

void insertAtLast(nodePtr *head, int x)
{
    nodePtr newPtr = *head;
    nodePtr prevPtr = *head;

    while (newPtr){
        prevPtr = newPtr;
        newPtr = newPtr->nextNode;      
    }
    
    if (prevPtr->value){
        prevPtr->nextNode = (nodePtr)malloc(sizeof(node_t));
        newPtr = prevPtr->nextNode;
        newPtr->value = x;
    }
    else
        prevPtr->value = x;
}

void insertAtPosition(nodePtr *head, int x, int pos)
{
    nodePtr newPtr = *head;
    nodePtr prevPtr = *head;
    int i;

    if (pos==0 && (*head)->value){
        prevPtr = (nodePtr)malloc(sizeof(node_t));
        prevPtr->nextNode = newPtr;
        prevPtr->value = x;
        *head = prevPtr;
    }
    else if (pos == 0){
        (**head).value = x;
    }

    for(i = 0; i < pos; ++i){
        if (i == pos -1){
            newPtr = (nodePtr)malloc(sizeof(node_t));
            newPtr->nextNode = prevPtr->nextNode;
            prevPtr->nextNode = newPtr;
            newPtr->value = x;
        }
        else if(!prevPtr->nextNode)
            break;
        else{    
            newPtr = prevPtr->nextNode;
            prevPtr= newPtr;
        }
    }

    if (i != pos){
        printf("No number present at specified position\n");
    }
}

int deleteFromPosition(nodePtr *head, int x, int pos)
{
    nodePtr newPtr = *head;
    nodePtr prevPtr = *head;
    int i = 0;

    if (pos==0 && newPtr->nextNode){
        *head = prevPtr->nextNode;
        free(prevPtr);
        return 0;
    }

    for(i = 0; i <= pos; ++i){
        if (i == pos){
            newPtr = newPtr->nextNode;
            free(prevPtr->nextNode);
            prevPtr->nextNode = newPtr;
        }
        else if(!prevPtr->nextNode)
            break;
        else{    
            prevPtr= newPtr;
            newPtr = prevPtr->nextNode;
        }
    }
    return 0;
}

int updateNodeValue(nodePtr *head, int x, int pos)
{
    nodePtr newPtr = *head;
    nodePtr prevPtr = *head;
    int i = 0;

    for(i = 0; i <= pos; ++i){
        if (i == pos){
            newPtr->value = x;
            return 1;
        }
        else if(!prevPtr->nextNode)
            break;
        else{    
            newPtr = prevPtr->nextNode;
            prevPtr= newPtr;
        }
    }

    printf("No number exists in position\n");
    return 0;
}

int searchElement(nodePtr head, int x)
{
    nodePtr newPtr = head;
    nodePtr prevPtr = head;

    while(newPtr){
        prevPtr = newPtr;
        newPtr = newPtr->nextNode;
        if (prevPtr->value == x){
            printf("Found value %d\n", x);
            return 1;
        }       
    }

    return 0;
}

void printList(nodePtr head)
{
    nodePtr curPtr = head;
    while (curPtr != NULL){
        printf("%d ", curPtr->value);
        curPtr = curPtr->nextNode;
    }

    printf("\n\n");
}



==> ../../section_19/linkedlist/linkedlist.c <==
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* nextPtr;
} node_t;

typedef node_t* ListNodePtr; //typedef for easier use in passsing into functions, etc.

/*prototypes*/
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr head);

int main(){
    ListNodePtr head = NULL;
    int choice = 0; //user's choice
    char item = '\0'; //char entered by user

    /* display the menu */
    printf("Enter the choice:\n"
	"   1 to insert an element into the list in alphabetical order.\n"
	"   2 to insert an element at the end of the list.\n"
	"   3 to insert an element at the beginning of the list.\n"
	"   4 to delete an element from the list.\n"
	"   5 to delete an element from the beginning of the list.\n"
	"   6 to end.\n" );

    printf(":: ");
    scanf("%d", &choice);

    /* loop while user does not choose 3 */
    while ( choice != 6 ) {
        switch(choice) {
            case 1:
                printf("Enter a character: \n");
                scanf("\n%c", &item);
		insert(&head, item); /*insert item in list*/
		printList(head);
		break;

            case 2:
                printf("Enter a character: \n");
                scanf("\n%c", &item);
		insertAtEnd(&head, item); /*insert item in list*/
		printList(head);
		break;

            case 3:
                printf("Enter a character: \n");
                scanf("\n%c", &item);
		insertAtBeginning(&head, item); /*insert item in list*/
		printList(head);
		break;

            case 4: /*delete an element*/
                /*if list is not empty*/
                if (!isEmpty(head)){
                    printf("Enter a character to be deleted: \n");
                    scanf("\n%c", &item);
                    if (delete(&head, item)){
    		        printf("%c deleted.\n", item);
    		        printList(head);}
                    else 
    		        printf("%c not found.\n\n", item);}
		else
		    printf("List is empty\n");

		break;

            case 5: /*delete an element*/
                /*if list is not empty*/
                if (!isEmpty(head)){
                    deleteAtBeginning(&head);
    		    printList(head);}
		else
		    printf("List is empty\n");

		break;

	    default:
		printf("Invalid choice.\n\n");

		/* display the menu */
		printf("Enter your choice:\n"
            	"   1 to insert an element into the list in alphabetical order.\n"
            	"   2 to insert an element at the end of the list.\n"
            	"   3 to insert an element at the beginning of the list.\n"
            	"   4 to delete an element from the list.\n"
            	"   5 to delete an element from the beginning of the list.\n"
            	"   6 to end.\n" );

                scanf("\n%d", &choice);
		break;
        }
        printf("Enter the choice:\n"
    	"   1 to insert an element into the list in alphabetical order.\n"
    	"   2 to insert an element at the end of the list.\n"
    	"   3 to insert an element at the beginning of the list.\n"
    	"   4 to delete an element from the list.\n"
    	"   5 to delete an element from the beginning of the list.\n"
    	"   6 to end.\n" );
    
        printf(":: ");
        scanf("\n%d", &choice);


    }
    return 0;
}

void insertAtBeginning(ListNodePtr *head, char val) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = val;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char val)
{
    ListNodePtr current = *head;
    if (current != NULL)
    {
        while(current->nextPtr != NULL)
	{
	    current = current->nextPtr;
        }

	/* now we can add a new variable */
	current->nextPtr = malloc(sizeof(node_t));
	current->nextPtr->data = val;
	current->nextPtr->nextPtr = NULL;
    }
    else 
    {
	current = malloc(sizeof(node_t));
	current->data = val;
	current->nextPtr = NULL;
        *head = current;
    }
}

void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;      /* pointer to new node */
    ListNodePtr previousPtr; /* pointer to previous node in list */
    ListNodePtr currentPtr;  /* pointer to current node in list */

    newPtr = malloc(sizeof(node_t)); /* create node */
    currentPtr = *head;

    if (currentPtr == NULL)
    {
	currentPtr = malloc(sizeof(node_t));
	currentPtr->data = value;
	currentPtr->nextPtr = NULL;
        *head = currentPtr;
    }
    else if (newPtr != NULL)
    {
	newPtr->data = value;
	newPtr->nextPtr = NULL;

        previousPtr = NULL;
	// loop to find the correct location  in the list - inserts in alphabetical prder
        while(currentPtr != NULL && value > currentPtr->data)
	{
	    previousPtr = currentPtr;  //walk to..
	    currentPtr = currentPtr->nextPtr;  //next node..
        } //end while

        if (previousPtr != NULL)
	{
            newPtr->nextPtr = previousPtr->nextPtr;
            previousPtr->nextPtr = newPtr;
        }      
        else 
        {
	    newPtr->nextPtr = currentPtr;
            *head = newPtr;
        }  
    }
    else
	printf("%c not inserted. No memory available.\n", value); 
}

void deleteAtBeginning(ListNodePtr *head){
    ListNodePtr tempPtr = NULL;

    if (head == NULL)
        return;
    else 
    {
	tempPtr = *head; 	  //hold onto node being removed a
	*head = (*head)->nextPtr; //de-thread the node
	free(tempPtr);  	  //free the de-threaded node
    }
}

char delete(ListNodePtr *head, char value){
    ListNodePtr previousPtr = NULL; //ptr to previous node
    ListNodePtr currentPtr = NULL;  //prtr to current node
    ListNodePtr tempPtr = NULL;     //temporer pointer
    
    //delete first node
    if (value == (*head)->data){
        tempPtr = *head;
        *head  = (*head)->nextPtr;
        free(tempPtr);
        return value;
    }
    else{
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;

	//loop to find correct location in the list
	while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;          // walk to
            currentPtr = previousPtr->nextPtr; // next node
        }

	if (currentPtr != NULL){
	    tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
	    free(tempPtr);
	    return value;
	}
    }
    return '\0';
}

void printList(ListNodePtr currentPtr){
    /* if list is empty */
    if (currentPtr == NULL)
	printf("List is empty.\n\n");
    else{
        printf("The List is :");
        while (currentPtr != NULL){
	    printf("%c ", currentPtr->data);
	    currentPtr = currentPtr->nextPtr;
	}

	printf("\n\n");
    }
}

int isEmpty(ListNodePtr head){
    return head == NULL;
}


==> ../../section_19/queues/arrays.c <==
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main(){
    int choice = 1;
 
    while (choice !=4) {
        printf("1. Insert element to queue \n");
        printf("2. Delete element from queue \n");
        printf("3. Display queue \n");
        printf("4. Exit program \n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice){
    	case 1:
            enqueue();
    	break;
    	case 2:
            dequeue();
    	break;
    	case 3:
            display();
    	break;
            case 4:
            exit(0);
    	default: printf("Enter your choice: \n");
            printf("1. Insert element to queue \n");
            printf("2. Delete element from queue \n");
            printf("3. Display queue \n");
            printf("4. Exit program \n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
        }
    }

    return 0;
}

void enqueue(){
    int add_item;

    if (rear == MAX -1)
	printf("Queue overflow\n");
    else{
	if (front == -1)
	    front = 0;

	printf("Insert the element in queue: ");
	scanf("%d", &add_item);
	rear = rear + 1;
	queue_array[rear] = add_item;
    }
    display();
}

void dequeue(){
    if (front == -1 || front > rear){
	printf("Queue Underflow\n");
    }
    else {
	printf("Element deleted from queue is: %d\n", queue_array[front]);
	front += 1;
    }
    display();
}

void display(){
    if (front == -1)
	printf("Queue is empty\n");
    else {
	printf("Queue is : \n");
	for (int i = front; i <= rear; i ++)
	    printf("%d ", queue_array[i]);

	printf("\n");
    }
}

==> ../../section_19/queues/queue.c <==
#include <stdio.h>
#include <malloc.h>

struct QNode {
    int key;
    struct QNode* next;
} ;

struct Queue {
    struct QNode *front, *rear;
} ;

struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;   
    return q;
}

void enQueue(struct Queue* q, int k) {
    struct QNode* temp = newNode(k);

    if (q->rear == NULL) {
	q->front = q->rear = temp;
	return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* deQueue(struct Queue* q) {
    if (q->front == NULL)
	return NULL;
   
    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

int main() {
    struct Queue* q = createQueue();
    struct QNode* n;
    enQueue(q, 1);
    enQueue(q, 2);
    n = deQueue(q);
    if (n != NULL)
        printf("Dequeued item is %d\n", n->key);
    free(n);
    n = deQueue(q);
    if (n != NULL)
        printf("Dequeued item is %d\n", n->key);
    free(n);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    n = deQueue(q);
    if (n != NULL)
        printf("Dequeued item is %d\n", n->key);
    free(n);
    return 0;
}

==> ../../section_19/stacks/main.c <==
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* link;
} node_t;

struct Node* top;

void push(int data) {
    struct Node* temp = malloc(sizeof(node_t));
    
    if (temp != NULL){
	temp->data = data;
        temp->link = top;
        top = temp;
    }
} 

int isEmpty(){
    return top == NULL;
}

void pop(){
    struct Node* temp;
    if (top != NULL){
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display(){
    struct Node* temp;
    if (top != NULL){
	temp = top;
	while (temp != NULL) {
	    printf("%d:\n",temp->data);
	    temp = temp -> link;
        }
     }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    display(); 

    pop();
    pop();

    display(); 

    return 0;
}


==> ../../section_19/stacks/stack-array.c <==
#include <stdio.h>

#define MAXSIZE 5

struct stack {
    int stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;

STACK s;

void push();
int pop();
void display();

int main(){
    int choice = 1;
    s.top = -1;

    while (choice != 4) {
	printf(" Please make a choice\n");
	printf(" 1. Push\n");
	printf(" 2. Pop\n");
	printf(" 3. Display\n");
	printf(" 4. Exit\n");
        printf(" :: ");

        scanf("%d", &choice);
	
	switch(choice) {
	    case 1:
		push();
		break;
	    case 2:
		pop();
		break;
	    case 3:
		display();
		break;
	    case 4:
		break;
	    default: printf("---Incorrect option\n");
        	printf(" Please make a choice\n");
        	printf(" 1. Push\n");
        	printf(" 2. Pop\n");
        	printf(" 3. Display\n");
        	printf(" 4. Exit\n");
                printf(" :: ");
        
                scanf("\n%d", &choice);
		break;
	}
        fflush(stdin);
    }

    return 0;
}

void push() {
    int num;
    if (s.top == (MAXSIZE - 1)) {
	printf("Stack is Full\n");
	return;
    }
    else {
	printf("Enter the element to be pushed\n");
	scanf("%d", &num);
	s.top += 1;
	s.stk[s.top] = num;
    }
}

int pop(){
    int num = 0;
    if (s.top == -1) {
	printf("Stack is Empty\n");
	return s.top;
    }
    else {
	num = s.stk[s.top];
	printf("Popped element is %d\n", s.stk[s.top]);
	s.top -= 1;
    }

    return num;
}

void display(){
    int i = 0;
    if (s.top == -1) {
	printf("Stack is Empty\n");
    }
    else {
	printf("\n The status of the stack is \n");
	for (i = s.top; i >= 0; i--)
    	    printf("%d\n", s.stk[i]);
    }
    printf("\n");
}

==> ../../section_20/fork/challenge2.c <==
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    char name[20];
    pid = getpid();

    for (int i = 1; i <= 3; i++){
        if (getpid() == pid){
            fork();
            switch(i){
		case 1: sprintf(name, "First child"); break;
                case 2: sprintf(name, "Second child"); break;
		case 3: sprintf(name, "Third child"); break;
	    }
        }
    }
    
    if (getpid() == pid)
	sprintf(name, "Parent thread");

    printf("%s process ID:%ld, ", name, (long)getpid());
    printf("Parent process ID:%ld\n", (long)pid);

    return 0;
}

==> ../../section_20/fork/fork2.c <==
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 1000
#define BUF_SIZE 100

void main(){
    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();
    for (int i = 1; i <= MAX_COUNT; i++) {
	sprintf(buf, "This line is for pid: %d, value is %d\n", pid, i);
        write(1, buf, strlen(buf));
    }
}

==> ../../section_20/fork/fork3.c <==
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 1000

void childProcess();
void parentProcess();

void main(){
    pid_t pid;

    pid = fork();

    if (pid == 0)
        childProcess();
    else if (pid > 0)
        parentProcess();
    else
	printf("Fork() failed!\n");
}

void childProcess()
{
    for (int i = 1; i <= MAX_COUNT; i++)
	printf("This line is from child, value = %d\n", i);

    printf(" *** Child process is done ***\n");
}

void parentProcess()
{
    for (int i = 1; i <= MAX_COUNT; i++)
	printf("This line is from parent, value = %d\n", i);

    printf(" *** Parent process is done ***\n");
}


==> ../../section_20/fork/fork.c <==
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t = pid;
    
    fork();
    fork();
    printf("Hello world!\n");

    return 0;
}

==> ../../section_20/signals/alarm.c <==
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
    alarm(5);

    // Need to catch SIGALARM or process terminates
    // signal(SIGALRM, alarmhandler);

    for(int i = 0; i < 10; i++){
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}

==> ../../section_20/signals/challenge1-alt.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int score = 0;
int count = 0;

void end_game(){
    printf("\nFinal score: %d out of %d\n", score, count);
    exit(0); 
}

void error(char* msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL);
}
 
void times_up(){
    printf("\nTIME'S UP!\n");
    raise(SIGINT);
}

int main(){
    srand(time(0));
    int a,b;  

    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);

    alarm(30);
    while(1) {
	a = rand() % 13;
	b = rand() % 13;

	char txt[4];

	printf("\nWhat is %d times %d? ", a, b);
        fgets(txt, 4, stdin);

	int answer = atoi(txt);

	answer == a * b ? printf("Correct! score: %d out of %d\n", ++score, ++count) : printf("Incorrect! score: %d out of %d\n", score, ++count);
    }
}

==> ../../section_20/signals/challenge1.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int score = 0;
int count = 0;

void end_game(){
    printf("\nFinal score: %d out of %d\n", score, count);
    exit(0); 
}

void error(char* msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void signalHandler(){
    end_game();
}

void alarmHandler(){
    printf("\n\n***Times up!***\n");
    raise(SIGINT);
}

void signalHandler1(){
    ;
}

int main(){
    srand(time(0));
    int a,b;  

    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler1);
    signal(SIGALRM, alarmHandler);

    while(1) {
        alarm(5);
	a = rand() % 13;
	b = rand() % 13;

	char txt[4];

	printf("\nWhat is %d times %d? ", a, b);
        fgets(txt, 4, stdin);

	int answer = atoi(txt);

	answer == a * b ? printf("Correct! score: %d out of %d\n", ++score, ++count) : printf("Incorrect! score: %d out of %d\n", score, ++count);
    }
}

==> ../../section_20/signals/raise.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(){
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("Back\n\n");
    return 0;
}

==> ../../section_20/signals/sigaction-handling2.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <bits/siginfo.h>

static void hdl(int sig, siginfo_t *siginfo, void *context) {
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main(int argc, char **argv){
    struct sigaction act;

    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &hdl;

    act.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT, &act, NULL) < 0) {
	perror("sigaction");
	return 1;
    }

    while(1)
        sleep(3);
    return 0;
}

==> ../../section_20/signals/sigaction-handling.c <==
#include <signal.h>

void termination_handler(int signum) {
    struct temp_file *p; 

    for (p = temp_file_list; p; p = p>next)
	unlink(p->name);
}

int main() {
    struct sigaction new_action, old_action;

    new_action.sa_handler = termination_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    sigaction(SIGINT, NULL, &oldaction);

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGINT, &newaction, NULL);

    sigaction(SIGHUP, NULL, &old_action); 

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGHUP, &newaction, NULL);

    sigaction(SIGTERM, NULL, &old_action); 

    if (old_action.sa_handler != SIG_IGN)
        sigaction(SIGTERM, &newaction, NULL);
}

==> ../../section_20/signals/signal-handling1.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalValue);

int main(){
    int i;
    int x;

    signal(SIGINT, signalHandler);
    srand(clock());

    /* output numbers 1 to 100 */
    for (i = 1; i <= 100; i++){
	x = 1 + rand() % 50;

	if(x == 25)
	    raise(SIGINT);

        printf("%4d", x);

        if(i % 10 == 0)
	    printf("\n");
    }

    return 0;
}

void signalHandler(int signalValue){
    int response;

    printf("\nInterrupt signal (%d)\nDo you wish to continue ( 1 = yes or 2 = no )? ");
    scanf("%d", &response);

    while (response != 1 && response != 2){
	printf("( 1 = yes or 2 = no )? ");
	scanf("%d", &response);
    }

    if (response == 1) 
	signal(SIGINT, signalHandler);
    else
	exit(0);
}


==> ../../section_20/signals/signal-handling2.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalValue);

int main(){
    int i;
    int x;

    signal(SIGINT, signalHandler);
    srand(clock());

    /* output numbers 1 to 100 */
    for (i = 1; i <= 100; i++){
	x = 1 + rand() % 50;

	if(x == 25)
	    raise(SIGINT);

        printf("%4d", x);

        if(i % 10 == 0)
	    printf("\n");
    }

    return 0;
}

void signalHandler(int signalValue){
    int response;

    printf("\nInterrupt signal (%d)\nDo you wish to continue ( 1 = yes or 2 = no )? ");
    scanf("%d", &response);

    while (response != 1 && response != 2){
	printf("( 1 = yes or 2 = no )? ");
	scanf("%d", &response);
    }

    if (response == 1) 
	signal(SIGINT, signalHandler);
    else
	exit(0);
}


==> ../../section_20/signals/signal-handling.c <==
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_dividebyzero(int signum);

int main(){
    int result = 0;
    int v1 = 121, v2 = 0;
    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_dividebyzero);

    if (sigHandlerReturn == SIG_ERR){
	perror("Signal Error: ");
	return 1;
    }

    result = v1/v2;
    printf("Result of Divide by Zero is %d/n", result);

    return 0;
}

void handler_dividebyzero(int signum){
    if (signum == SIGFPE) {
	printf("Received SIGFPE, Divide by Zero Exception.\n");
	exit(1);
    }
    else {
	printf("Received SIGFPE, Divide by Zero Exception.\n");
	return;
    }
}


==> ../../section_21/condition_variables/condition.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void* functionCount1();
void* functionCount2();
int count = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main(){
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &functionCount1, NULL);
    pthread_create(&thread2, NULL, &functionCount2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void* functionCount1(){
    for(;;){
	pthread_mutex_lock(&condition_mutex);
	
	while(count >= COUNT_HALT1 && count <= COUNT_HALT2)
	    pthread_cond_wait(&condition_cond, &condition_mutex);

	pthread_mutex_unlock(&condition_mutex);

	pthread_mutex_lock(&count_mutex);
	count++;
	printf("Counter value functionCount1: %d\n", count);
	pthread_mutex_unlock(&count_mutex);

	if (count >= COUNT_DONE) return(NULL);
    }
}

void* functionCount2(){
    for(;;){
	//pthread_mutex_lock(&condition_mutex);
	
	if(count < COUNT_HALT1 || count > COUNT_HALT2)
	    pthread_cond_signal(&condition_cond); //tells other threads to wake up

	//pthread_mutex_unlock(&condition_mutex);

	pthread_mutex_lock(&count_mutex);
	count++;
	printf("Counter value functionCount2: %d\n", count);
	pthread_mutex_unlock(&count_mutex);

	if (count >= COUNT_DONE) return(NULL);
    }
}


==> ../../section_21/mutexes/deadlock.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void* resource1(){
    pthread_mutex_lock(&lock1);

    printf("Job started in resource1...\n");
    sleep(2);

    printf("Trying to get resource2\n");
    pthread_mutex_lock(&lock2);
    printf("Acquired resource2\n");
    pthread_mutex_unlock(&lock2);

    printf("Job finished in resource1\n");

    
    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);
}

void *resource2() {
    pthread_mutex_lock(&lock2);

    printf("Job started in resource2...\n");
    sleep(2);

    printf("Trying to get resource1\n");
    pthread_mutex_lock(&lock1);
    printf("Acquired resource1\n");
    pthread_mutex_unlock(&lock1);

    printf("Job finished in resource2\n");

    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);
}

int main(){
    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,resource1,NULL);
    pthread_create(&t2,NULL,resource2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_exit(NULL);

    return 0;
}


==> ../../section_21/mutexes/multithreads_mutex.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 10

void* thread_function(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

int main() {
    pthread_t thread_id[NTHREADS];
    int i, j;

    for (i = 0; i < NTHREADS; i++)
        pthread_create(&thread_id[i], NULL, thread_function, NULL);

    for (j = 0; j < NTHREADS; j++)
        pthread_join(thread_id[j], NULL);

    printf("Final counter value : %d\n", counter);
    return 0;
}

void* thread_function(void* dummyPtr){
    pthread_mutex_lock(&mutex1);
    counter++;
    printf("Thread ID: %ld\n", (long)pthread_self());
    for (int i = 0; i < 5; i++){
        printf("%d ", counter);
        sleep(1);
    }
    printf("... Done\n");
    pthread_mutex_unlock(&mutex1);
}


==> ../../section_21/mutexes/mutexes1.c <==
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

int j = 0;

void* do_process() {
    pthread_mutex_lock(&lock);
    int i = 0;
    j++;

    while(i < 5) {
	printf("%d ", j);
        sleep(1);
        i++;
    }
    
    printf("...Done\n");
    pthread_mutex_unlock(&lock);
}


int main(){
    int err = 0;
    pthread_t t1, t2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
	printf("Mutex initialization failed.\n");
	return 1;
    }

    j = 0;

    pthread_create(&t1, NULL, do_process, NULL);
    pthread_create(&t2, NULL, do_process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_exit(NULL);
    return 0;
}

==> ../../section_21/mutexes/resolved_deadlock.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void* resource1(){
    pthread_mutex_lock(&lock1);

    printf("Job started in resource1...\n");
    sleep(2);

    printf("Trying to get resource2\n");
    while(pthread_mutex_trylock(&lock2)){
	pthread_mutex_unlock(&lock1);
	sleep(2);
	pthread_mutex_lock(&lock1);
    }
    printf("Acquired resource2\n");
    pthread_mutex_unlock(&lock2);

    printf("Job finished in resource1\n");

    
    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);
}

void *resource2() {
    pthread_mutex_lock(&lock2);

    printf("Job started in resource2...\n");
    sleep(2);

    printf("Trying to get resource1\n");
    pthread_mutex_lock(&lock1);
    printf("Acquired resource1\n");
    pthread_mutex_unlock(&lock1);

    printf("Job finished in resource2\n");

    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);
}

int main(){
    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,resource1,NULL);
    pthread_create(&t2,NULL,resource2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_exit(NULL);

    return 0;
}


==> ../../section_21/threads/02_multi_arguments_to_thread.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>

struct thread_data{
    int thread_id;
    int sum;
    char* message;
};

void *printHello(void *thread_arg) {
    struct thread_data *my_data;

    int taskid = 0, sum = 0;
    char hello_msg[255];

    my_data = (struct thread_data*) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strcpy(hello_msg, my_data->message);
    printf("taskid = %d, sum = %d, message = %s\n", taskid, sum, hello_msg);
}

int main(int argc, char** argv) {
    pthread_t my_thread;
    struct thread_data my_thread_data;
    
    my_thread_data.message = malloc(sizeof(char) * 255);
    
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Hello world";

    pthread_t my_id = pthread_create(&my_thread, NULL, printHello, (void*)&my_thread_data);
    pthread_join(my_thread, NULL);
    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/02_passing_args_returning_values.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void *ptr);

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*)message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*)message2);

    pthread_join(thread1, NULL); //wwaits until threads are complete before main continues exiting
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    pthread_exit(NULL);

    return 0;
}

void *print_message_function(void *ptr){
    char *message;
    message = (char*) ptr;
    printf("%s\n", message);
}

==> ../../section_21/threads/03_thread_returnval.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>

//int pthread_join(pthread_t thread, void **retval);

void* hello_return(void* args){
    //allocate a new string on the heap with "Hello world"
    char* hello = strdup("Hello World!\n"); 
    return (void*) hello;
}

int main(int argc, char **argv){
    char* str;
    pthread_t thread;

    //create a new thread that runs hello_return without any arguments
    pthread_create(&thread, NULL, hello_return, NULL);
   
    pthread_join(thread, (void**) &str);
    printf("%s", str);

    free(str);
    pthread_exit(NULL);
    return 0;
}

==> ../../section_21/threads/04_pthread_cancel.c <==
#include <stdio.h>
#include <pthread.h>

//int pthread_cancel(pthread_t thread);

void* my_function(void* ptr){
    printf("Hello world\n");
    pthread_cancel(pthread_self());
    return NULL;
}

int main(){
    pthread_t thread = NULL;

    pthread_create(&thread, NULL, my_function, NULL);
    pthread_join(thread, NULL);
    return 0;
}

==> ../../section_21/threads/04_pthread_self.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calls(void* ptr){
    //using pthread_self get current thread id
    printf("In function \nThread id = %d\n\n", pthread_self);
    pthread_exit(NULL);
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main thread\n Thread id = %d\n\n", thread);
    pthread_join(thread, NULL);
    return 0;
} 

==> ../../section_21/threads/04_stack_functions.c <==
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_attr_t attr;

void *dowork(void *threadid) {
    long tid;
    size_t mystacksize;

    tid = (long)threadid;
    pthread_attr_getstacksize(&attr, &mystacksize);

    printf("Thread %ld: stack size = %li bytes \n", tid, mystacksize);

    pthread_exit(NULL);
}

int main(int argc, char **argv){
    pthread_t myThread;
    size_t stacksize;
    pthread_t myID;
    long t = 5;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize = 9000000;
    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);

    printf("Creating thread with stack size = %li bytes\n", stacksize);
    myID = pthread_create(&myThread, &attr, dowork, (void*)t); //argument t is unnecessary

    if (myID){
	printf("ERROR; return code from pthread_create() is %ld\n");
	exit(-1);
    }

    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/04_thread_detach.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *threadFn(void* arg){
    pthread_detach(pthread_self());
    sleep(5);
    printf("Thread Fn\n");
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFn, NULL);

    if (ret != 0){
	perror("Thread creation Error\n");
	exit(1);
    }

    printf("After thread created in Main\n");
    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/challenge1.c <==
#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

int counter = 0;
pthread_mutex_t lock;

void* thread_func(void* var1){
   // pthread_mutex_lock(&lock);
    int* newvar = (int*)var1;
    printf("Message is %d, thread id = %ld, modified the counter to %d\n", *newvar, (long)pthread_self(), ++counter);
    printf("Message is %d, thread id = %ld, read the counter %d\n", *newvar, (long)pthread_self(), counter);
   // pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t threads[NTHREADS];
    int i = 0;
    
    while (i < NTHREADS){
        pthread_create(&threads[i], NULL, thread_func, (void*)&i);
        i++;
    }

    for (int j = 0; j < NTHREADS; j++){
	pthread_join(threads[j], NULL);
    }

    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/challenge2.c <==
#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

int counter = 0;
pthread_mutex_t lock;

void* thread_func(void* var1){
    pthread_mutex_lock(&lock);
    int* newvar = (int*)var1;
    printf("Message is %d, thread id = %ld, modified the counter to %d\n", *newvar, (long)pthread_self(), ++counter);
    printf("Message is %d, thread id = %ld, read the counter %d\n", *newvar, (long)pthread_self(), counter);
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t threads[NTHREADS];
    int i = 0;
    
    while (i < NTHREADS){
        pthread_create(&threads[i], NULL, thread_func, (void*)&i);
        i++;
    }

    for (int j = 0; j < NTHREADS; j++){
	pthread_join(threads[j], NULL);
    }

    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/challenge3.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 10

int counter = 0;
pthread_mutex_t cond_lock  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition   = PTHREAD_COND_INITIALIZER;

void* thread_func0(void* var1){
    int newvar = *(int*)var1;
    pthread_mutex_lock(&count_lock);
    printf("Message is %d, thread id = %ld, modified the counter to %d\n\r", newvar, (long)pthread_self(), ++counter);
    printf("Message is %d, thread id = %ld, read the counter %d\n\r", newvar, (long)pthread_self(), counter);
    pthread_mutex_unlock(&count_lock);
    sleep(1);
    pthread_mutex_lock(&cond_lock);
    if (counter >= NTHREADS/2)
        pthread_cond_broadcast(&condition);
    pthread_mutex_unlock(&cond_lock);
}

void* thread_func1(void* var1){
    int newvar = *(int*)var1;
    pthread_mutex_lock(&cond_lock);
    while (counter < NTHREADS/2)
        pthread_cond_wait(&condition, &cond_lock);
    pthread_mutex_unlock(&cond_lock);
    pthread_mutex_lock(&count_lock);
    printf("Message is %d, thread id = %ld, modified the counter to %d\n\r", newvar, (long)pthread_self(), ++counter);
    printf("Message is %d, thread id = %ld, read the counter %d\n\r", newvar, (long)pthread_self(), counter);
    pthread_mutex_unlock(&count_lock);
}

int main(){
    pthread_t threads[NTHREADS];
    int values[NTHREADS];
    int i = 0;
    
    while (i < NTHREADS){
        values[i] = i;
        i % 2 == 0 ? pthread_create(&threads[i], NULL, thread_func0, (void*)&values[i]) : pthread_create(&threads[i], NULL, thread_func1, (void*)&values[i]);
        i++;
    }

    for (int j = 0; j < NTHREADS; j++)
	pthread_join(threads[j], NULL);

    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/challenge3-nu.c <==
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 10

int counter = 0;
pthread_mutex_t lock;
pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;

int number_evens_finished = 0;

void* thread_func(void* var1){
    pthread_mutex_lock(&lock);
    int* newvar = (int*)var1;

    if (*newvar % 2 == 0)
	number_evens_finished++;
    else
        pthread_cond_wait(&evens_done, &lock);
    counter++;
    printf("Message is %d, thread id = %ld, modified the counter to %d\n", *newvar, (long)pthread_self(), ++counter);
    printf("Message is %d, thread id = %ld, read the counter %d\n", *newvar, (long)pthread_self(), counter);
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t threads[NTHREADS];
    int values[NTHREADS];
    int i = 0;
    
    while (i < NTHREADS){
        values[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*)&values[i]);
        i++;
    }

    sleep(1);

    while(1){
        if (number_evens_finished == NTHREADS/2) {
	    pthread_cond_broadcast(&evens_done);
	    break;
        }
    }

    for (int j = 0; j < NTHREADS; j++){
	pthread_join(threads[j], NULL);
    }

    pthread_exit(NULL);

    return 0;
}

==> ../../section_21/threads/code1.c <==
   #include<stdio.h>
   #include<pthread.h>
 
   void *fun_t(void *arg)
   {       
       printf("%d\n",a);
       pthread_exit("Bye");
   }
   
   int main()
   {
       int a;  
       pthread_t pt;
   
       a = 10;
    
       if(pthread_create(&pt,NULL,fun_t,NULL) != 0)
           perror("pthread_create");
       
	   if(pthread_join(pt,NULL) != 0)
           perror("pthread_join");
 
       return 0;
   }

==> ../../section_21/threads/code2.c <==
   #include<stdio.h>
   #include<pthread.h>
 
   int a;  
 
   void *fun_t(void *arg)
   {       
       printf("%d\n",a);
       pthread_exit("Bye");
   }
 
   int main()
   {
       pthread_t pt;
       a = 10;
 
       if(pthread_create(&pt,NULL,fun_t,NULL) != 0)
           perror("pthread_create");
 
       if(pthread_join(pt,NULL) != 0)
           perror("pthread_join");
		   
       return 0;
   }

==> ../../section_21/threads/code3.c <==
   #include<stdio.h>
   #include<pthread.h>
 
   void *fun_t(void *arg)
   {
       printf("Jason\n");
       pthread_exit("Bye");
   }
   
   int main()
   {
       pthread_t pt;
   
       if(pthread_create(&pt,NULL,fun_t,NULL) != 0)
           perror("pthread_create");
    
       printf("Fedin\n");
       
	   if(pthread_join(pt,NULL) != 0)
           perror("pthread_join");
       
	   return 0;
   }




==> ../../section_21/threads/code.c <==
   #include<stdio.h>
   #include<pthread.h>
 
   void *fun_t(void *arg)
   {
       printf("Jason\n");
       pthread_join(pthread_self(), NULL);
   }
   int main()
   { 
       pthread_t pt;
 
       if(pthread_create(&pt,NULL,fun_t,NULL) != 0)                
           perror("pthread_create");
	
       printf("Fedin!\n");
	   
       return 0;
   }




==> ../../section_21/threads/creating_a_thread1.c <==
#include <stdio.h>
#include <pthread.h>

void *hello_fun() {
    printf("Hello World!\n");
    return NULL;
}

int main(int argc, char **argv){
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);
    pthread_join(thread, NULL); // without this callpthread is created but has ni time to execute before program return
    return 0;
}

==> ../../section_21/threads/creating_a_thread2.c <==
#include <stdio.h>
#include <pthread.h>

void *hello_fun() {
    printf("Hello World!\n");
    return NULL;
}

int main(int argc, char **argv){
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);
    pthread_join(thread, NULL); // without this callpthread is created but has ni time to execute before program return
    pthread_exit(NULL);  // without this callpthread is created but has ni time to execute before program return
    return 0;
}

==> ../../section_21/threads/creating_a_thread.c <==
#include <stdio.h>
#include <pthread.h>

void *hello_fun() {
    printf("Hello World!\n");
    return NULL;
}

int main(int argc, char **argv){
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);
   //  pthread_exit(NULL);  without this callpthread is created but has ni time to execute before program return
    return 0;
}

==> ../../section_22/client_socket/client1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Create a socket for server communication
short socketCreate() {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect with Server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 second timeout
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive the data from the server
int socketReceive(int hSocket, char* Rsp, short RvcSize) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  //20 sec timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0) {
        printf("Time out\n");
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response %s\n",Rsp);

    return shortRetval;
}

//main driver program
int main(){
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    //Create socket
    hSocket = socketCreate();

    if (hSocket == -1) {
	printf("Could not create socket\n");
	return 1;
    }

    printf("Socket is created\n");
    
    //Connect to remote server
    if (socketConnect(hSocket) < 0) {
        perror("Connect failed.\n");
        return -1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    //Send data to the server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    close(hSocket);

    return 0;
}

==> ../../section_22/client_socket/client2.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Create a socket for server communication
short socketCreate() {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect with Server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 second timeout
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive the data from the server
int socketReceive(int hSocket, char* Rsp, short RvcSize) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  //20 sec timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0) {
        printf("Time out\n");
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response %s\n",Rsp);

    return shortRetval;
}

//main driver program
int main(){
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = "hello";
    char server_reply[200] = {0};

    //Create socket
    hSocket = socketCreate();

    if (hSocket == -1) {
	printf("Could not create socket\n");
	return 1;
    }

    printf("Socket is created\n");
    
    //Connect to remote server
    if (socketConnect(hSocket) < 0) {
        perror("Connect failed.\n");
        return -1;
    }

    printf("Successfully connected with server\n");

    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //Received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server response : %s\n\n", server_reply);

    close(hSocket);

    return 0;
}

==> ../../section_22/client_socket/client.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Create a socket for server communication
short socketCreate() {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect with Server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 second timeout
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive the data from the server
int socketReceive(int hSocket, char* Rsp, short RvcSize) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  //20 sec timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0) {
        printf("Time out\n");
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response %s\n",Rsp);

    return shortRetval;
}

//main driver program
int main(){
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    //Create socket
    hSocket = socketCreate();

    if (hSocket == -1) {
	printf("Could not create socket\n");
	return 1;
    }

    printf("Socket is created\n");
    
    //Connect to remote server
    if (socketConnect(hSocket) < 0) {
        perror("Connect failed.\n");
        return -1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    //Send data to the server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //Received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server response : %s\n\n", server_reply);

    close(hSocket);

    return 0;
}

==> ../../section_22/server_socket/challenge.c <==
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetVal = -1;
    int clientPort = 12345;

    struct sockaddr_in remote= {0};

    //Internet address family IPv4
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port

    iRetVal = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetVal;
}

int main(int argc, char* argv){
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char* pMessage = "hello\n";

    //Create a socket
    socket_desc = socketCreate();
    if (socket_desc == -1){
	printf("Could not create socket");
	return -1;
    }

    printf("Socket created\n");

    if(bindCreatedSocket(socket_desc) < 0) {
	perror("bind failed.\n");
	return 1;
    }

    listen(socket_desc, 3);

    //Accept an incoming connection
    while(1) {
	printf("Waiting for incoming connections...\n");
	clientLen = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	sock = accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&clientLen);

	if (sock < 0){
	    perror("accept failed");
	    return 1;
        }

	printf("Connection accepted\n");
	memset(client_message, '\0', sizeof(client_message));
	memset(message, '\0', sizeof(message));

	//Receive a reply from the client
	if (recv(sock, client_message, 200, 0) < 0) {
	    printf("recv failed\n");
	    break;
	}

	printf("Client message: %s\n", client_message);

	if(strcmp(pMessage,client_message) == 0) 
	    strcpy(message, "Hi there ! ");
	else
	    strcpy(message, "Invalid Message ! ");

	if (send(sock, message, strlen(message), 0) < 0) {
	    printf("send failed\n");
	    return 1;
	}
        
	close(sock);
	sleep(1);
    }

    return 0;
}

==> ../../section_22/server_socket/server1.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetVal = -1;
    int clientPort = 12345;

    struct sockaddr_in remote= {0};

    //Internet address family IPv4
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port

    iRetVal = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetVal;
}

int main(int argc, char* argv){
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char* pMessage = "hello\n";
    int clientretval, clientno = 0;

    //Create a socket
    socket_desc = socketCreate();
    if (socket_desc == -1){
	printf("Could not create socket");
	return -1;
    }

    printf("Socket created\n");

    if(bindCreatedSocket(socket_desc) < 0) {
	perror("bind failed.\n");
	return 1;
    }

    listen(socket_desc, 3);

    //Accept an incoming connection
    while(1) {
	printf("Waiting for incoming connections...\n");
	clientLen = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	if (sock = accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&clientLen))
            clientno++;

	if (sock < 0){
	    perror("accept failed");
	    return 1;
        }

	printf("Connection accepted\n");
	memset(client_message, '\0', sizeof(client_message));
        if (clientno % 2 == 1)
	    memset(message, '\0', sizeof(message));

	//Receive a reply from the client
	if (recv(sock, client_message, 200, 0) < 0) {
	    printf("recv failed\n");
	    break;
	}
        
        if (clientno % 2 == 1){
	printf("Client message: %s\n", client_message);

	if((clientretval = atoi(client_message)) > 0) {
	    clientretval -= 1;
            sprintf(message, "%d", clientretval);
	}
	else
	    strcpy(message, "Invalid Message ! ");
        }
        if (clientno % 2 == 0){
    	if (send(sock, message, strlen(message), 0) < 0) {
    	    printf("send failed\n");
    	    return 1;
    	}
        }      
        
	close(sock);
	sleep(1);
    }

    return 0;
}

==> ../../section_22/server_socket/server2.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket, int port){
    int iRetVal = -1;
    int clientPort = port;

    struct sockaddr_in remote= {0};

    //Internet address family IPv4
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port

    iRetVal = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetVal;
}

int main(int argc, char* argv){
    int socket1_desc = 0, sock1 = 0, clientLen1 = 0;
    int socket2_desc = 0, sock2 = 0, clientLen2 = 0;
    int clientretval;
    struct sockaddr_in client1;
    struct sockaddr_in client2;
    char client_message[200] = {0};
    char message[100] = {0};
    const char* pMessage = "hello\n";

    //Create a socket
    socket1_desc = socketCreate();
    if (socket1_desc == -1){
	printf("Could not create socket");
	return -1;
    }

    //Create a socket
    socket2_desc = socketCreate();
    if (socket2_desc == -1){
	printf("Could not create socket");
	return -1;
    }

    printf("Socket created\n");

    if(bindCreatedSocket(socket1_desc, 12345) < 0 || bindCreatedSocket(socket2_desc, 23456) < 0)  {
	perror("bind failed.\n");
	return 1;
    }

    listen(socket1_desc, 0);

    //Accept an incoming connection
    while(1) {
	printf("Waiting for incoming connections...\n");
	clientLen1 = sizeof(struct sockaddr_in);
	clientLen2 = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	sock1 = accept(socket1_desc,(struct sockaddr *)&client1,(socklen_t*)&clientLen1);
        listen(socket2_desc, 0);
	sock2 = accept(socket2_desc,(struct sockaddr *)&client2,(socklen_t*)&clientLen2);

	if (sock1 < 0 || sock2 < 0){
	    perror("accept failed");
	    return 1;
        }

	printf("Connection accepted\n");
	memset(client_message, '\0', sizeof(client_message));
	memset(message, '\0', sizeof(message));

	//Receive a reply from the client
	if (recv(sock1, client_message, 200, 0) < 0) {
	    printf("recv failed\n");
	    break;
	}

	if (recv(sock2, client_message, 200, 0) < 0) {
	    printf("recv failed\n");
	    break;
	}

        
	printf("Client message: %s\n", client_message);

	if((clientretval = atoi(client_message)) > 0) {
	    clientretval -= 1;
            sprintf(message, "%d", clientretval);
	}     
	else
	    strcpy(message, "Invalid Message ! ");

	if (send(sock2, message, strlen(message), 0) < 0) {
	    printf("send failed\n");
	    return 1;
	}
        
	close(sock1);
	close(sock2);
	sleep(1);
    }

    return 0;
}

==> ../../section_22/server_socket/server.c <==
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetVal = -1;
    int clientPort = 12345;

    struct sockaddr_in remote= {0};

    //Internet address family IPv4
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port

    iRetVal = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetVal;
}

int main(int argc, char* argv){
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char* pMessage = "hello\n";

    //Create a socket
    socket_desc = socketCreate();
    if (socket_desc == -1){
	printf("Could not create socket");
	return -1;
    }

    printf("Socket created\n");

    if(bindCreatedSocket(socket_desc) < 0) {
	perror("bind failed.\n");
	return 1;
    }

    listen(socket_desc, 3);

    //Accept an incoming connection
    while(1) {
	printf("Waiting for incoming connections...\n");
	clientLen = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	sock = accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&clientLen);

	if (sock < 0){
	    perror("accept failed");
	    return 1;
        }

	printf("Connection accepted\n");
	memset(client_message, '\0', sizeof(client_message));
	memset(message, '\0', sizeof(message));

	//Receive a reply from the client
	if (recv(sock, client_message, 200, 0) < 0) {
	    printf("recv failed\n");
	    break;
	}

	printf("Client message: %s\n", client_message);

	if(strcmp(pMessage,client_message) == 0) 
	    strcpy(message, "Hi there ! ");
	else
	    strcpy(message, "Invalid Message ! ");

	if (send(sock, message, strlen(message), 0) < 0) {
	    printf("send failed\n");
	    return 1;
	}
        
	close(sock);
	sleep(1);
    }

    return 0;
}

==> ../../section_23/timers/timerapi.c <==
/*
POSIX provides four basic APIs to manipulate timers on Unix compliant platforms
	- timer_create() - Creates a Timer Data structure (but does not fire it)
	- timer_settime() - Used to start / stop the timers depending on arguments passed to the API
	- timer_gettime() - Returns the time remaining for the timer to fire
	- timer_delete() - Delete the timer data structure

There are some key timer terminologies. For example if you wanted to send a packet after 10 secs:
	At t=0 you either 'start' or 'alarm' the timer.
	At t=10 the timer 'fires' or the altrenative term the timer 'expires' (basically performing
	the action it is supposed to perform.

-----------------------------------------------------------------------------
Example (pseudo-code):
foo(arg) {

}

main () {
	new_timer_launch(foo, arg)
	...
	...
	...
}

When we create a timer there are some mandatory arguments that need to be passed.
The first argument is the function pointer/callback 'foo', which is the function
that the timer will trigger, and also the argument to the function. Each timer thus
needs two arguments. The unit of work the timer will perform i.e. 'foo', and the 2nd
argument being the argument to pass into the function 'foo'. Once the timer is 
invoked the operating system will fork out a new thread and the subsequent lines of 
execution in the calling thread/parent process will continue. The timer thread will
be blocked for the duration of the timer, then the function passed to the timer
thread will execute. Once the execution is complete the timer thread will rejoin the
calling thread/be killed by the kernel, the application should free all allocated 
resources occupied by the timer once the execution of 'foo' is complete (i.e. at end
of 'foo'). These are the same mechanics (thread spawning and blocking behaviour on
the thread) for one shot timers, periodic timers, and exponential back off timers.

---------------------------------------------------------------------------------
Example (API call):
int timer_create(<Type of Timer>, <Timer Controlling Parameters>, <Timer pointer>);
//For above: 0 on success, -1 on error, and errno (errno.h) is set to errcode i.e.
//can see what caused the error by printing the errno variable

<Timer Controlling Parameters>
	These are represented by the data structure:
	struct sigevent evp;

	There are three main members to evp:
	evp.sigev_notify_function - <ptr to callback fn> //timer callback pointer 
													function is passed here. The 
													func invoked when timer fires   
	evp.sigev_value.sival_ptr - <address of argument to callback arg> //Argument to
																	  callback
	evp.sigev_notify = SIGEV_THREAD //asking the kernel to launch a timer thread to 
									invoke the callback - hardcoded to SIGEV_THREAD

	The prototype of the timer callback function is fixed and it should be:
	void timer_callback(union sigval arg) {
		foo(arg.sival_ptr);
	}
	i.e. should return void, and argument is a data type union sigval. 
	sival_ptr i.e. SI value pointer represents the address of the argument. Thus the
	timer callback is just a generic wrapper around a specific application callback

	if say an address 0xfde was passed as evp.sigev_value.sival_ptr then
	arg.sival_ptr will be set to 0xfde

In order to specify the expiration time of the timer, the data structure used is:
struct itimerspec ts; 

This contains the following members
struct itimerspec {
	struct timerspec it_interval; 	//next value
	struct timerspec it_value; 		//current value
};

The timespec data structure referenced within is as follows:
struct timespec {
	time_t tv_sec;	//seconds
	long tv_nsec;	//nanoseconds
};

This facility allows us to specify the granularity of the time in nanoseconds.
Therefore if initializing the timer as such, the timer will fire after 5 seconds

struct itimerspec ts;
ts.it_value.tv_sec = 5;
ts.it_value.tv_nsec = 0;

To then arm the timer we are provided with the following API, which can be 
initialised thus:
int timer_settime(<timer>, 0, &ts, NULL);
*/

==> ../../section_23/timers/timerExampleDemo1.c <==
/*To compile with gcc must link rt library i.e. -lrt */
/*to work with posix timers the two below header files are necessary*/
#include <signal.h>
#include <time.h>

/*Other standard header files we would need are*/
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h> /* for pause() */
#include <stdint.h>
#include <stdbool.h>

static void print_current_system_time() {
	time_t t;
	time(&t);  /* Get the current system time */

	/* Print the current system time. Will insert one \n character */
	printf("%s ", ctime(&t));
}

/* Example user-defined data structure */
typedef struct pair_{
	int a;
	int b;
} pair_t;

pair_t pair = {5, 3};

/* Timer callback function which will be called every time the timer expires. The
signature of the function should be: void <fn_name>(union sigval); */
void timer_callback(union sigval arg) {
	print_current_system_time();

	pair_t *pair = (pair_t*) arg.sival_ptr; /* Extract the user data structure */

	printf("Pair: [%d %d]\n", pair->a, pair->b);
}

void timer_demo() {
	int ret;
	struct sigevent evp;

	/* You can take it in as a local variable if you wish, but in that case we will
	free it in the timer_hadler fn */
	timer_t timer;
	memset(&timer, 0, sizeof(timer_t));

	/* evp variable is used to setup timer properties */
	memset(&evp, 0, sizeof(struct sigevent));
	
	/* Fill the user defined data structure. When the timer expires, this will be 
	passed as an argument to the timer callback handler */
	evp.sigev_value.sival_ptr = (void*)&pair;

	/* On timer expiry, we wat the kernel to launch the timer handler routine in a
	spearate thread context */
	evp.sigev_notify = SIGEV_THREAD;

	/* Register the timer handler routine. This routine shall be invoked when the 
	timer expires - set to address of timer_callback function */
	evp.sigev_notify_function = timer_callback;

	/* Create a timer. Timer initialization, the timer is not Alarmed/Started */
	ret = timer_create(CLOCK_REALTIME, &evp, &timer);
	// CLOCK_REALTIME is the most commmon type of timer

	if (ret < 0) {
		printf("Timer creation filed, errno = %d\n", errno);
		exit(0);
	}

	/* Let us setup the time intervals */
	struct itimerspec ts;

	/* I want the timer to fire for the first time after 5 seconds */
	ts.it_value.tv_sec = 5;
	ts.it_value.tv_nsec = 0;

	ts.it_interval.tv_sec = 0;
	ts.it_interval.tv_nsec = 0;
	
	/* Now start the timer, timer is passed by value but ts is passed by address */
	ret = timer_settime(timer, 0, &ts, NULL);

	if (ret < 0) {
		printf("Timer creation filed, errno = %d\n", errno);
		exit(0);
	}
	else {
		print_current_system_time();
		printf("Timer alarmed successfully\n");
	}
}

int main(int argc, char **argv){
	timer_demo();
	pause();
	return 0;
}
	
==> client.c <==
#include "client.h"

short socketCreate(){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;
    
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    remote.sin_family = AF_INET;                     // Internet Addrees Family IPv4
    remote.sin_port = htons(ServerPort);             // local port

    iRetval = connect(hSocket, (struct sockaddr*) &remote, sizeof(struct sockaddr_in));
    return iRetval;
}

int socketSend(int hSocket, char* serialized_data, short len_serialized_data){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 sec timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time out\n");
        return -1;
    }
    
    shortRetval = send(hSocket, serialized_data, len_serialized_data, 0);
    return shortRetval;
}

int socketReceive(int hSocket, char* serialized_data, short len_serialized_data){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) < 0){
        printf("Time out\n");
        return -1;
    }

    shortRetval = recv(hSocket, serialized_data, len_serialized_data, 0);
    return shortRetval;
}

==> client.h <==
#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

//Create a socket for client communication
short socketCreate();

//try to connect with Server
int socketConnect(int hSocket);

//Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst);

//Receive the data from the server
int socketReceive(int hSocket, char* Rsp,short Rvcsize);

#endif

==> de_serialize_person1.c <==
#include "serialized_buffer.h"

struct occupation {
    char dept_name[30];
    int employee_code;
};

typedef struct person {
    char name[30];
    int age;
    struct occupation occ;
    int weight;
} person_t;

struct occupation* de_serialize_occupation(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE
    
    struct occupation *obj = calloc(1, sizeof(struct occupation));
    de_serialize_data((char*)obj->dept_name, buff, 30);
    de_serialize_data((char*)&obj->employee_code, buff, sizeof(int));
    
    return obj;
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE
    
    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    struct occupation* occ = de_serialize_occupation(buff);
    obj->occ = *occ;
    free(occ);
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> de_serialize_person2.c <==
#include "serialized_buffer.h"

struct occupation {
    char dept_name[30];
    int employee_code;
};

typedef struct person {
    char name[30];
    int age;
    struct occupation occ;
    int weight;
} person_t;

struct occupation* de_serialize_occupation(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE
    
    struct occupation *obj = calloc(1, sizeof(struct occupation));
    de_serialize_data((char*)obj->dept_name, buff, 30);
    de_serialize_data((char*)&obj->employee_code, buff, sizeof(int));
    
    return obj;
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE
    
    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    obj->occ = de_serialize_occupation(buff);
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> de_serialize_person.c <==
#include "serialized_buffer.h"

typedef struct person {
    char name[30];
    int age;
    int weight;
} person_t;

person_t* de_serialize_person_t(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE

    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> intlinkedlist.c <==
#include "intlinkedlist.h"

void serialize_list_t(list_t* obj, ser_buff_t* buff){
    SENTINEL_INSERTION_CODE
    serialize_list_node_t(obj->head, buff);
}

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff){
    SENTINEL_INSERTION_CODE
    serialize_int((&obj->data), buff);
    serialize_list_node_t(obj->right, buff);
}

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff){
    SENTINEL_DETECTION_CODE

    struct list_node_t* obj = calloc(1, sizeof(struct list_node_t));
    de_serialize_int(buff, (&obj->data));
    obj->right = de_serialize_list_node_t(buff);
    return obj;
}

list_t* de_serialize_list_t(ser_buff_t *buff){
    SENTINEL_DETECTION_CODE
    reset_serialize_buffer(buff);

    list_t* obj = calloc(1, sizeof(list_t));
    obj->head = de_serialize_list_node_t(buff);
    return obj;
}

list_t* new_linked_list(){
    list_t * newlist = (list_t*)calloc(1,sizeof(list_t));
    newlist->head = NULL;
    return newlist;
}

int add_int_to_linked_list(list_t* linkedlist, int newitem){
    if (!linkedlist)
        return -1;

    struct list_node_t** currentNode;
    currentNode = &linkedlist->head;

    while (*currentNode != NULL)
        currentNode = &(*currentNode)->right;
    
    *currentNode = (struct list_node_t*)calloc(1, sizeof(struct list_node_t));
    (*currentNode)->data = newitem;
    (*currentNode)->right = NULL;

    return 0;
}

void print_linked_list(list_t linkedlist){
    int i = 0;
    struct list_node_t* currentNode = linkedlist.head;
    while (currentNode != NULL) {
        printf("Data item %d: %d\n", i, currentNode->data);
        currentNode = currentNode->right;
        i++;
    }
}

==> intlinkedlist.h <==
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "tree.h"

struct list_node_t {
    int data;
    struct list_node_t* right;
};

typedef struct list {
    struct list_node_t *head;
} list_t;

void serialize_list_t(list_t* obj, ser_buff_t* buff);

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff);

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff);

list_t* de_serialize_list_t(ser_buff_t *buff);

list_t* new_linked_list();

int add_int_to_linked_list(list_t* linkedlist, int newitem);

void print_linked_list(list_t linkedlist);

#endif

==> linkedlist.c <==
#include "linkedlist.h"

void serialize_list_t(list_t* obj, ser_buff_t* buff){
    SENTINEL_INSERTION_CODE
    serialize_list_node_t(obj->head, buff);
}

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff){
    SENTINEL_INSERTION_CODE
    serialize_person_t(obj->data, buff);
    serialize_list_node_t(obj->right, buff);
}

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff){
    SENTINEL_DETECTION_CODE

    struct list_node_t* obj = calloc(1, sizeof(struct list_node_t));
    obj->data = de_serialize_person_t(buff);
    obj->right = de_serialize_list_node_t(buff);
    return obj;
}

list_t* de_serialize_list_t(ser_buff_t *buff){
    SENTINEL_DETECTION_CODE

    list_t* obj = calloc(1, sizeof(list_t));
    obj->head = de_serialize_list_node_t(buff);
    return obj;
}

==> linkedlist.h <==
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "person1.h"

struct list_node_t {
    person_t* data;
    struct list_node_t* right;
};

typedef struct list {
    struct list_node_t *head;
} list_t;

void serialize_list_t(list_t* obj, ser_buff_t* buff);

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff);

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff);

list_t* de_serialize_list_t(ser_buff_t *buff);

#endif

==> main1.c <==
#include "intlinkedlist.h"
#include "server.h"

int sum_linked_list(list_t linkedlist){
    int sum = 0;
    struct list_node_t* currentNode = linkedlist.head;

    while (currentNode){
        sum += currentNode->data;
        currentNode = currentNode->right;
    }

    return sum;
}

int main(){
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
   
    ser_buff_t *buff;
    init_serialized_buffer(&buff);

    socket_desc = socketCreate();
    if (socket_desc == -1){
        printf("Could not create socket");
        return -1;
    }

    printf("Socket created\n");

    if (bindCreatedSocket(socket_desc) < 0){
        printf("Could not bind created socket\n");
        return -1;
    }

    listen(socket_desc, 3);

    while(1){
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);
        sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&clientLen);

        if (sock < 0){
            perror("accept failed");
            return -1;
        }

        printf("Connection accepted\n");
        
        if (recv(sock, buff->b, buff->size, 0) < 0){
            perror("Receive failed");
            break;
        }

        list_t* secondlist = de_serialize_list_t(buff);
        
        printf("\n");
        print_linked_list(*secondlist);
        int sum = sum_linked_list(*secondlist);
        printf("Sum: %d\n", sum);
        memset(buff->b, '\0', buff->size);
        reset_serialize_buffer(buff);
        serialize_int(&sum, buff);
        
        if (send(sock, buff->b, buff->size, 0) < 0){
            printf("send failed\n");
            return 1;
        }

        close(sock);
        sleep(1);
    }

    return 0;
}

==> main2.c <==
#include "intlinkedlist.h"
#include "client.h"

int main(){
    list_t* firstlist = new_linked_list();

    add_int_to_linked_list(firstlist, 2) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 5) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 8) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 3) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");

    print_linked_list(*firstlist);

    ser_buff_t *buff;
    init_serialized_buffer(&buff);
    serialize_list_t(firstlist, buff);

    int hSocket = 0, sum = 0;
    struct sockaddr_in server;
    
    hSocket = socketCreate();
    if (hSocket == -1){
        printf("Could not create socket\n");
        return 1;
    }    

    printf("Socket is created\n");

    if (socketConnect(hSocket) < 0){
        printf("Connection failed.\n");
        close(hSocket);
        return -1;
    }

    printf("Successfully connected with server\n");
    if (socketSend(hSocket, buff->b, buff->size) < 0){
        printf("Send failed\n");
        close(hSocket);
        return -1;
    }

    ser_buff_t* newbuff;
    init_serialized_buffer(&newbuff);

    if (socketReceive(hSocket, newbuff->b, newbuff->size) < 0){ 
        printf("Receive failed\n");
        close(hSocket);
        return -1;
    }

    de_serialize_int(newbuff, (&sum));
    printf("Server response: %d\n\n", sum);
  
    close(hSocket);

    return 0;
}

==> main.c <==
#include "intlinkedlist.h"

int main(){
    list_t* firstlist = new_linked_list();

    add_int_to_linked_list(firstlist, 2) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 5) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 8) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");
    add_int_to_linked_list(firstlist, 3) == 0 ? printf("Added data item\n") : fprintf(stderr, "Error\n");

    print_linked_list(*firstlist);

    ser_buff_t *buff;
    init_serialized_buffer(&buff);
    serialize_list_t(firstlist, buff);
    printf("\n");

    list_t* secondlist = de_serialize_list_t(buff);
    print_linked_list(*secondlist);

    return 0;
}

==> person1.h <==
#ifndef PERSON_H
#define PERSON_H
#include "serialized_buffer.h"

struct occupation {
    char dept_name[30];
    int employee_code;
};

typedef struct person {
    char name[30];
    int age;
    struct occupation* occ;
    int weight;
} person_t;

void serialize_occupation(struct occupation* obj, ser_buff_t *buff);

void serialize_person_t(person_t* obj, ser_buff_t *buff);

struct occupation* de_serialize_occupation(ser_buff_t* buff);

person_t* de_serialize_person_t(ser_buff_t* buff);

#define SENTINEL_INSERTION_CODE \
    if (!obj) { \
        unsigned int sentinel = 0xFFFFFFFF; \
        serialize_data(buff, (char*)&sentinel, sizeof(unsigned int)); \
        return; \
    }
 
#define SENTINEL_DETECTION_CODE \
    unsigned int sentinel = 0; \
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int)); \
    if (sentinel == 0xFFFFFFFF) \
        return NULL; \
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));

#endif

==> person2.h <==
#ifndef PErSON_H
#define PERSON_H
#include "serialized_buffer.h"

struct occupation {
    char dept_name[30];
    int employee_code;
};

typedef struct person {
    char name[30];
    int age;
    struct occupation occ;
    int weight;
} person_t;

void serialize_occupation(struct occupation* obj, ser_buff_t *buff);

void serialize_person_t(person_t* obj, ser_buff_t *buff);

struct occupation* de_serialize_occupation(ser_buff_t* buff);

person_t* de_serialize_person_t(ser_buff_t* buff);

#define SENTINEL_INSERTION_CODE \
    if (!obj){ \
        unsigned int sentinel = 0xFFFFFFFF; \
        serialize_data(buff, (char*)&sentinel, sizeof(unsigned int)); \
        return; \
    }
 
#define SENTINEL_DETECTION_CODE \
    unsigned int sentinel = 0; \
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int)); \
    if (sentinel == 0xFFFFFFFF) \
        return NULL; \
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));

#endif

==> person.h <==
#ifndef PERSON_H
#define PERSON_H
#include "serialized_buffer.h"
#include <stdio.h>

typedef struct person {
    char name[30];
    int age;
    int weight;
} person_t;

void serialize_person_t(person_t* obj, ser_buff_t *buff);

person_t* de_serialize_person_t(ser_buff_t* buff);

#define SENTINEL_INSERTION_CODE \
    if (!obj) { \
        unsigned int sentinel = 0xFFFFFFFF; \
        serialize_data(buff, (char*)&sentinel, sizeof(unsigned int)); \
        return; \
    } 

#define SENTINEL_DETECTION_CODE \
    unsigned int sentinel = 0; \
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int)); \
    if (sentinel == 0xFFFFFFFF) \
        return NULL; \
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));


#endif

==> serialized_buffer.c <==
#include "serialized_buffer.h"

void init_serialized_buffer(ser_buff_t **ser_buf){
    (*ser_buf) = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
    (*ser_buf)->b = (char*)calloc(1, SERIALIZED_BUFFER_DEFAULT_SIZE);
    (*ser_buf)->size = SERIALIZED_BUFFER_DEFAULT_SIZE;
    (*ser_buf)->next = 0; 
}

void serialize_data(ser_buff_t *buff, char *data, int nbytes){
    int available_size = buff->size - buff->next;
    char isResize = 0;
    
    while (available_size < nbytes) {
	buff->size = buff->size * 2;
	available_size = buff->size - buff->next;
	isResize = 1;
    }

    if (isResize == 0) {
	memcpy((char*)buff->b + buff->next, data, nbytes);
	buff->next += nbytes;
	return;
    }

    // resize the buffer
    buff->b = realloc(buff->b, buff->size);
    memcpy((char*)buff->b + buff->next, data, nbytes);
    buff->next += nbytes;
    return;
}

void de_serialize_data(char* dest, ser_buff_t *buff, int size) {
    memcpy(dest, (char*)buff->b + buff->next, size);
    buff->next += size;
}

void free_serialized_buffer(ser_buff_t *buff){
    int i = 0;
    while (i < buff->size){
        free(buff->b + i);
        i++;
    }
    buff->next = 0;
    buff->size = SERIALIZED_BUFFER_DEFAULT_SIZE;
}

void reset_serialize_buffer(ser_buff_t *buff){
    buff->next = 0;
}

void serialize_buffer_skip(ser_buff_t *buff, int jump){
    while (buff->next + jump > buff->size)
        buff->size *= 2;

    if (buff->next + jump >= 0)
        buff->next += jump;
    else
        fprintf(stderr, "Note nough space in buffer, space: %d, jump size: %d\n", buff->next, jump);
}


==> serialized_buffer.h <==
#ifndef SERIALIZED_BUFFER_H
#define SERIALIZED_BUFFER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SERIALIZED_BUFFER_DEFAULT_SIZE 100

typedef struct serialized_buffer_ {
    int size;   /* size of serialized buffer */
    int next;   /* byte position in serialized buffer where data read from/written into */
    char *b;    /* pointer to the start of the buffer holding the data */
} ser_buff_t;

void init_serialized_buffer(ser_buff_t **ser_buf);

void serialize_data(ser_buff_t *buff, char *data, int nbytes);

void de_serialize_data(char* dest, ser_buff_t *buff, int size);

void free_serialized_buffer(ser_buff_t *buff);

void reset_serialize_buffer(ser_buff_t *buff);

void serialize_buffer_skip(ser_buff_t *buff, int jump);

#endif

==> serialize_person1.c <==
#include "person1.h"

void serialize_occupation(struct occupation* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->dept_name, 30);
    serialize_data(buff, (char*)&obj->employee_code, sizeof(int));
}

void serialize_person_t(person_t* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->name, 30);
    serialize_data(buff, (char*)&obj->age, sizeof(int));
    serialize_occupation(obj->occ, buff);
    serialize_data(buff, (char*)&obj->weight, sizeof(int));
}

struct occupation* de_serialize_occupation(ser_buff_t* buff) {
    unsigned int sentinel = 0;
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int));
    if (sentinel == 0xFFFFFFFF)
        return NULL;
    
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));
    struct occupation *obj = calloc(1, sizeof(struct occupation));
    de_serialize_data((char*)obj->dept_name, buff, 30);
    de_serialize_data((char*)&obj->employee_code, buff, sizeof(int));
    
    return obj;
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    unsigned int sentinel = 0;
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int));
    if (sentinel == 0xFFFFFFFF)
        return NULL;
    
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));
    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    obj->occ = de_serialize_occupation(buff);
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> serialize_person2.c <==
#include "person2.h"

void serialize_occupation(struct occupation* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->dept_name, 30);
    serialize_data(buff, (char*)&obj->employee_code, sizeof(int));
}

void serialize_person_t(person_t* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->name, 30);
    serialize_data(buff, (char*)&obj->age, sizeof(int));
    serialize_occupation(&obj->occ, buff);
    serialize_data(buff, (char*)&obj->weight, sizeof(int));
}

struct occupation* de_serialize_occupation(ser_buff_t* buff) {
    unsigned int sentinel = 0;
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int));
    if (sentinel == 0xFFFFFFFF)
        return NULL;
    
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));
    struct occupation *obj = calloc(1, sizeof(struct occupation));
    de_serialize_data((char*)obj->dept_name, buff, 30);
    de_serialize_data((char*)&obj->employee_code, buff, sizeof(int));
    
    return obj;
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    unsigned int sentinel = 0;
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int));
    if (sentinel == 0xFFFFFFFF)
        return NULL;
    
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));
    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    struct occupation* occ = de_serialize_occupation(buff);
    obj->occ = *occ;
    free(occ);
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> serialize_person.c <==
#include "person.h"

void serialize_person_t(person_t* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->name, 30);
    serialize_data(buff, (char*)&obj->age, sizeof(int));
    serialize_data(buff, (char*)&obj->weight, sizeof(int));
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    unsigned int sentinel = 0;
    de_serialize_data((char*)&sentinel, buff, sizeof(unsigned int));
    if (sentinel == 0xFFFFFFFF)
        return NULL;
    
    serialize_buffer_skip(buff, -1 * sizeof(unsigned int));
    person_t *obj = calloc(1, sizeof(person_t));
    de_serialize_data((char*)obj->name, buff, 30);
    de_serialize_data((char*)&obj->age, buff, sizeof(int));
    de_serialize_data((char*)&obj->weight, buff, sizeof(int));
    
    return obj;
}

==> server.c <==
#include "server.h"

short socketCreate(){
    short hSocket;
    printf("Create the Socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetval = -1;
    int clientPort = 12345;
   
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = htonl(INADDR_ANY); //Any incoming interface
    remote.sin_family = AF_INET;                //Internet address family IPv4
    remote.sin_port = htons(clientPort);        //local port

    iRetval = bind(hSocket, (struct sockaddr*) &remote, sizeof(remote));
    return iRetval;
}

==> server.h <==
#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

short socketCreate();

int bindCreatedSocket(int hSocket);

#endif

==> tree1.c <==
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

tree_t*
init_tree(void)
{
    tree_t *tree = calloc(1,sizeof(tree_t));
    if(!tree)
        return NULL;
    tree->root = NULL;
    return tree;
}

tree_node_t* init_tree_node(int n)
{
    tree_node_t *node = calloc(1, sizeof(tree_node_t));
    if(!node)   return NULL;
    node->data = n;
    return node;
}

int
add_tree_node_by_value(tree_t *tree, int n)
{
    tree_node_t *root = NULL, *parent = NULL;;
    if(!tree) return -1;
    tree_node_t *node = init_tree_node(n);
    if(!tree->root){
        tree->root = node;
        return 0;
    }

    root = tree->root;

    while(root){
        parent = root;
        root = (n < root->data) ? root->left : root->right;
    } // while ends

    if(n < parent->data)
        parent->left = node;
    else if (n >= parent->data)
        parent->right = node;
    else
        return 1;

    node->parent = parent;
    return 0;
}

tree_node_t *
get_left_most(tree_node_t *node){

    if(!node->left)
        return NULL;

    while(node->left){
        node = node->left;
    }
    return node;
}

tree_node_t *
get_next_inorder_succ(tree_node_t *node){

    /* case 1 : Handling root*/
    if(!node->parent){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
        return NULL;
    }

    /*case 2 : if node is a left child of its parent*/
    if(node == node->parent->left){
        if(!node->right)
            return node->parent;
        else
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
    }

    /*case 3 : if node is a right child of its parent*/
    if(node == node->parent->right){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
    }

    /* case 4 : Inorder successor of node is a ancestor whose
     * left children is also an ancestor*/

    tree_node_t *gp = node->parent->parent;
    tree_node_t *parent = node->parent;

    while(gp && gp->left != parent){

        parent = gp;
        gp = gp->parent;
    }

    return gp;
}

int iterinOrder(tree_node_t *node) 
{ 
    int count = 0; 
    while(1){ 
        while(node->left) 
            node = node->left; 
 
        count % 50 == 0 ? printf("\n%3u", node->data) : printf("%3u", node->data); 
        count++; 
        
        if (node->right) 
            node = node->right; 
        else{ 
            while (node->parent){ 
                if (node->data >= node->parent->data) 
                   node = node->parent; 
                else 
                   break; 
            } 
            while (node->parent){ 
                if (node->data < node->parent->data){ 
                    count % 50 == 0 ? printf("\n%3u", node->parent->data) : printf("%3u", node->parent->data); 
                    count++; 
                    node = node->parent; 
                } 
                if (node->right){ 
                    node = node->right; 
                    break; 
                } 
                else{ 
                    while (node->parent){ 
                        if (node->data >= node->parent->data) 
                           node = node->parent; 
                        else 
                           break; 
                    } 
                } 
            }     
        } 
        if (!node->parent) 
            return 0; 
    } 
    return 0; 
} 

void serialize_int(int *obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE
    
    if (obj != NULL)
        serialize_data(buff, (char*)obj, sizeof(int));
}

int* de_serialize_int(ser_buff_t *buff, int* num){
    SENTINEL_DETECTION_CODE
    
    de_serialize_data((char*)num, buff, sizeof(int));
    return num;
}

void serialize_tree_node_t(tree_node_t *obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE

    serialize_int((&obj->data), buff);

    if (obj->left)
        serialize_tree_node_t(obj->left, buff);

    if (obj->right)
        serialize_tree_node_t(obj->right, buff);
}

tree_t* de_serialize_tree(ser_buff_t *buff){
    SENTINEL_DETECTION_CODE

    reset_serialize_buffer(buff);

    tree_t *tree = init_tree();
    
    int *num = (int*)calloc(1, sizeof(int));
    while ((num = de_serialize_int(buff, num)) && (num != NULL)){
        add_tree_node_by_value(tree, *num);
    }

    free(num);
    return tree;
} 



//int
//main(int argc, char **argv){
//    int item;
//    tree_t *tree = init_tree();
//    srand(time(NULL));
//
//   // add_tree_node_by_value(tree,  1);
//    add_tree_node_by_value(tree,  100);
//    add_tree_node_by_value(tree,  50);
//    add_tree_node_by_value(tree,  10);
//    add_tree_node_by_value(tree,  90);
//    add_tree_node_by_value(tree,  95);
//    add_tree_node_by_value(tree,  99);
//   
//    for (int i = 0; i < 15; i++) {
//        item = rand() % 100;
//        i % 50 == 0 ? printf("\n%3d", item) : printf("%3d", item);
//        add_tree_node_by_value(tree, item);
//    }
//    printf("\n");
//    iterinOrder(tree->root);
//    printf("\n");
//
//    ser_buff_t *buff = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
//
//    init_serialized_buffer(&buff);
//
//    serialize_tree_node_t(tree->root, buff);
//
//    int *nptr = NULL;
//    serialize_int(nptr, buff);
//    tree_t *newtree = de_serialize_tree(buff);
//
//    printf("\n");
//    iterinOrder(newtree->root);
//    printf("\n");
////    printf("\n");
////    printf("\n");
////    tree_node_t *treenodeptr = NULL;
////
////    ITERATE_BST_BEGIN(tree, treenodeptr){
////        printf("%3u", treenodeptr->data);
////
////    } ITERATE_BST_END;
////    printf("\n");
//    
//    return 0;
//}

==> tree.c <==
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

tree_t*
init_tree(void)
{
    tree_t *tree = calloc(1,sizeof(tree_t));
    if(!tree)
        return NULL;
    tree->root = NULL;
    return tree;
}

tree_node_t* init_tree_node(int n)
{
    tree_node_t *node = calloc(1, sizeof(tree_node_t));
    if(!node)   return NULL;
    node->data = n;
    return node;
}

int
add_tree_node_by_value(tree_t *tree, int n)
{
    tree_node_t *root = NULL, *parent = NULL;;
    if(!tree) return -1;
    tree_node_t *node = init_tree_node(n);
    if(!tree->root){
        tree->root = node;
        return 0;
    }

    root = tree->root;

    while(root){
        parent = root;
        root = (n < root->data) ? root->left : root->right;
    } // while ends

    if(n < parent->data)
        parent->left = node;
    else if (n >= parent->data)
        parent->right = node;
    else
        return 1;

    node->parent = parent;
    return 0;
}

tree_node_t *
get_left_most(tree_node_t *node){

    if(!node->left)
        return NULL;

    while(node->left){
        node = node->left;
    }
    return node;
}

tree_node_t *
get_next_inorder_succ(tree_node_t *node){

    /* case 1 : Handling root*/
    if(!node->parent){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
        return NULL;
    }

    /*case 2 : if node is a left child of its parent*/
    if(node == node->parent->left){
        if(!node->right)
            return node->parent;
        else
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
    }

    /*case 3 : if node is a right child of its parent*/
    if(node == node->parent->right){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
    }

    /* case 4 : Inorder successor of node is a ancestor whose
     * left children is also an ancestor*/

    tree_node_t *gp = node->parent->parent;
    tree_node_t *parent = node->parent;

    while(gp && gp->left != parent){

        parent = gp;
        gp = gp->parent;
    }

    return gp;
}

int iterinOrder(tree_node_t *node) 
{ 
    int count = 0; 
    while(1){ 
        while(node->left) 
            node = node->left; 
 
        count % 50 == 0 ? printf("\n%3u", node->data) : printf("%4u", node->data); 
        count++; 
        
        if (node->right) 
            node = node->right; 
        else{ 
            while (node->parent){ 
                if (node->data >= node->parent->data) 
                   node = node->parent; 
                else 
                   break; 
            } 
            while (node->parent){ 
                if (node->data < node->parent->data){ 
                    count % 50 == 0 ? printf("\n%3u", node->parent->data) : printf("%4u", node->parent->data); 
                    count++; 
                    node = node->parent; 
                } 
                if (node->right){ 
                    node = node->right; 
                    break; 
                } 
                else{ 
                    while (node->parent){ 
                        if (node->data >= node->parent->data) 
                           node = node->parent; 
                        else 
                           break; 
                    } 
                } 
            }     
        } 
        if (!node->parent) 
            return 0; 
    } 
    return 0; 
} 

int
main(int argc, char **argv){
    int item;
    tree_t *tree = init_tree();
    srand(time(NULL));

//    add_tree_node_by_value(tree,  1);
    add_tree_node_by_value(tree,  100);
    add_tree_node_by_value(tree,  50);
    add_tree_node_by_value(tree,  10);
    add_tree_node_by_value(tree,  90);
    add_tree_node_by_value(tree,  95);
    add_tree_node_by_value(tree,  99);
   
//    for (int i = 0; i < 500; i++) {
//        item = rand() % 100;
//        i % 50 == 0 ? printf("\n%3d", item) : printf("%3d", item);
//        add_tree_node_by_value(tree, item);
//    }
//    printf("\n");
//    iterinOrder(tree->root);
//    printf("\n");

    printf("\n");
    printf("\n");
    tree_node_t *treenodeptr = NULL;

    ITERATE_BST_BEGIN(tree, treenodeptr){
        printf("%3u", treenodeptr->data);

    } ITERATE_BST_END;
    printf("\n");
    
    return 0;
}

==> tree.h <==
#ifndef __TREE__
#define __TREE__
#include "person1.h"

typedef struct tree_node {              
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
    int data;
} tree_node_t;

typedef struct tree {
    tree_node_t *root;
} tree_t;

int
add_tree_node_by_value(tree_t *tree, int n);

tree_t* init_tree(void);

tree_node_t* init_tree_node(int n);

/*Pre-requisites functions to write iterative 
 * macros for a tree.*/

tree_node_t *
get_left_most (tree_node_t *node);

tree_node_t *
get_next_inorder_succ (tree_node_t *node);

void serialize_int(int *obj, ser_buff_t *buff);

int* de_serialize_int(ser_buff_t *buff, int* num);

void serialize_tree_node_t(tree_node_t *obj, ser_buff_t *buff);

tree_t* de_serialize_tree(ser_buff_t *buff);

#define ITERATE_BST_BEGIN(treeptr, currentnodeptr)            \
{                                                             \
    tree_node_t *_next = NULL;                                \
    for(currentnodeptr = get_left_most(treeptr->root); currentnodeptr ; currentnodeptr = _next){    \
                        _next = get_next_inorder_succ(currentnodeptr);

#define ITERATE_BST_END }}

#endif
	
==> backup.c <==
#include "doublelinkedlist.h"


int remove_data_from_dll_by_data_ptr(linked_list_t* linked_list, void* app_data)
{
    list_node_t* currentNode = linked_list->head;
    while(currentNode->data){
	if (currentNode->data == app_data){
	    currentNode->leftPtr->rightPtr = currentNode->rightPtr;
	    currentNode->rightPtr->leftPtr = currentNode->leftPtr;
            free(currentNode->data);
            free(currentNode);
            return 0;
        } 
        currentNode = currentNode->rightPtr;
    }

    return -1;
}

int is_dll_empty(linked_list_t* linked_list)
{
    if (linked_list->head){
        if (linked_list->head->data)
            return -1;
    }
    return 0;
}

void drain_dll(linked_list_t* linked_list) //delete all nodes from linked_list,
{
    list_node_t* currentNode = linked_list->head;
    while(currentNode->data){
        currentNode = currentNode->rightPtr;
	currentNode->leftPtr->leftPtr = NULL;
        currentNode->leftPtr->rightPtr = NULL;
    }
    linked_list->head = currentNode;
}



==> doublelinkedlist.c <==
#include "doublelinkedlist.h"

linked_list_t* get_new_linkedlist()
{
    linked_list_t* newlist = (linked_list_t*)calloc(1, sizeof(linked_list_t));
    newlist->head = (list_node_t*)calloc(1, sizeof(list_node_t));
    newlist->head->leftPtr = NULL;
    newlist->key_match = NULL;
    return newlist;   
}

int add_data_to_ordered_list(linked_list_t* linked_list, void* app_data)
{
    list_node_t* currentNode = linked_list->head;
    while (currentNode->data){
        if(linked_list->key_match(currentNode->data, app_data) == 0)
            return -1;
        if (linked_list->compare_items(currentNode->data, app_data) == 0)
            break;
        currentNode = currentNode->rightPtr;
    }

    list_node_t* newNode = (list_node_t*)calloc(1, sizeof(list_node_t));
    newNode->data = app_data;
    newNode->leftPtr = currentNode->leftPtr;
    newNode->rightPtr = currentNode;
    currentNode->leftPtr = newNode;
    
    if (newNode->leftPtr != NULL)
        newNode->leftPtr->rightPtr = newNode; 
    else
        linked_list->head = newNode;

    return 0;
}

int add_data_to_linked_list(linked_list_t* linked_list, void* app_data)
{
    list_node_t* currentNode = linked_list->head;
    while (currentNode->data)
	currentNode = currentNode->rightPtr;
    
    if ((currentNode->rightPtr = (list_node_t*)calloc(1, sizeof(list_node_t))) == NULL)
        return 1;
    currentNode->rightPtr->leftPtr = currentNode;
    currentNode->data = app_data;
    return 0;
}

void register_print_item_callback(linked_list_t* linked_list, void (*print_data_item)(int, void*))
{
    linked_list->print_data_item = print_data_item;
}

void register_compare_items_callback(linked_list_t* linked_list, int (*compare_items)(void*, void*))
{
    linked_list->compare_items = compare_items;
}

void printList(linked_list_t linked_list)
{
    int i = 0;
    list_node_t* currentNode = linked_list.head;
    while (currentNode->data)
    {
	linked_list.print_data_item(i++, currentNode->data);
	currentNode = currentNode->rightPtr;
    }
}

void register_key_match_callback(linked_list_t* linked_list, int (*key_match)(void*, void*))
{
    linked_list->key_match = key_match;
}

void* dll_search_by_key(linked_list_t* linked_list, void* key)
{
    list_node_t* currentNode = linked_list->head;
    while (currentNode->data){
	if(linked_list->key_match(currentNode->data, key) == 0)
            return (void*)currentNode->data;
        currentNode = currentNode->rightPtr;
    }
}


==> doublelinkedlist.h <==
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct list_node_ {
    void* data;
    struct list_node_* leftPtr;
    struct list_node_* rightPtr;
} list_node_t;

typedef struct linked_list_ {
    struct list_node_* head;
    int (*key_match)(void*, void*);
    int (*compare_items)(void*, void*);
    void (*print_data_item)(int, void*);
} linked_list_t;

linked_list_t* get_new_linkedlist();

int add_data_to_linked_list(linked_list_t* linked_list, void* app_data);

int add_data_to_ordered_list(linked_list_t* linked_list, void* app_data);

void printList(linked_list_t linked_list);

void register_key_match_callback(linked_list_t* linked_list, int (*key_match)(void*, void*));

void register_compare_items_callback(linked_list_t* linked_list, int (*compare_items)(void*, void*));

void register_print_item_callback(linked_list_t* linked_list, void (*print_data_item)(int, void*));

int remove_data_from_dll_by_data_ptr(linked_list_t* linked_list, void* app_data);

int is_dll_empty(linked_list_t* linked_list);

void drain_dll(linked_list_t* linked_list); //delete all nodes from linked_list,

void* dll_search_by_key(linked_list_t* linked_list, void* key);

#endif

==> doublelinkedlistutil.c <==
#include "doublelinkedlist.h"


int remove_data_from_dll_by_data_ptr(linked_list_t* linked_list, void* app_data)
{
    list_node_t* currentNode = linked_list->head;
    while(currentNode->data){
	if (linked_list->key_match(currentNode->data, app_data) == 0){
            if (currentNode->leftPtr != NULL)
	        currentNode->leftPtr->rightPtr = currentNode->rightPtr;
	    currentNode->rightPtr->leftPtr = currentNode->leftPtr;
            if (currentNode == linked_list->head){
                linked_list->head = currentNode->rightPtr;
                linked_list->head->leftPtr = linked_list->head;
            }
            free(currentNode->data);
            free(currentNode);
            return 0;
        } 
        currentNode = currentNode->rightPtr;
    }

    return -1;
}

int is_dll_empty(linked_list_t* linked_list)
{
    if (linked_list->head){
        if (linked_list->head->data)
            return -1;
    }
    return 0;
}

void drain_dll(linked_list_t* linked_list) //delete all nodes from linked_list,
{
    list_node_t* currentNode = linked_list->head;
    while(currentNode->data){
        currentNode = currentNode->rightPtr;
	currentNode->leftPtr->leftPtr = NULL;
        currentNode->leftPtr->rightPtr = NULL;
        //free(currentNode->leftPtr->data);
        //free(currentNode->leftPtr);
    }

    printf("Clearing list...\n");
    linked_list->head = currentNode;
}



==> endianness.c <==
#include <stdio.h>

//unsigned short int a = 1; big endian: 01
//unsigned short int a = 1; little endian: 10

void machine_endianness_type(){
    unsigned short int a = 1;
    char first_byte = *((char*)&a);
    first_byte == 0 ? printf("Big endian (Network byte order)\n") : printf("Little endian (Host byte order)\n");
}

int main(){
    machine_endianness_type();

    return 0;
}

==> main.c <==
#include "doublelinkedlist.h"

static int match_number(void* list_data, void* number)
{
    if (*(int*)list_data == *(int*)number)
	return 0;

    return -1;
}

static int compare_number(void* list_data, void* number)
{
    if (*(int*)list_data > *(int*)number)
	return 0;

    return -1;
}

static void print_number(int i, void* list_data)
{
    printf("Data item %d: %d\n", i, *(int*)list_data);
}

int main(){
    int choice;
    int* input;
    void *data;
    char answer[100];
    linked_list_t* newlist = get_new_linkedlist();

    register_key_match_callback(newlist, match_number);
    register_print_item_callback(newlist, print_number);
    register_compare_items_callback(newlist, compare_number);
    is_dll_empty(newlist) == 0 ? printf("list is empty\n") : printf("list is not empty\n");

    while(1){
        do{
           printf("Would you like to enter a new data item? \t1: Yes \t2: No\n");
           choice = atoi(fgets(answer, sizeof(answer), stdin));
        } while (choice < 1 && choice > 2);
     
        if (choice == 2)
            break;
       
        do{
           printf("Please enter an integer\n");
           input = (int*)calloc(1, sizeof(int));
           *input = atoi(fgets(answer, sizeof(answer), stdin));
        } while (input == 0);
    
        data = input;
      
        add_data_to_ordered_list(newlist, data);
    }

    is_dll_empty(newlist) == 0 ? printf("list is empty\n") : printf("list is not empty\n");
    printList(*newlist); 

    do{
       printf("Please enter an integer\n");
       input = (int*)calloc(1, sizeof(int));
       *input = atoi(fgets(answer, sizeof(answer), stdin));
    } while (choice == 0);

    data = input;

    remove_data_from_dll_by_data_ptr(newlist, data); 
    is_dll_empty(newlist) == 0 ? printf("list is empty\n") : printf("list is not empty\n");

    printList(*newlist); 
    drain_dll(newlist);
    is_dll_empty(newlist) == 0 ? printf("list is empty\n") : printf("list is not empty\n");

    return 0;
}

==> recursive_dependency.c <==
//Compiler must know the size of struct beforehand, but cannot in case of emp_t as occ_t has not been declared yet

struct emp_t {
    char name[32];
    unsigned int emp_id;
    struct occ_t* occ;
};

struct occ_t {
    char name[32];
    unsigned int salary;
    struct emp_t boss;
};

//the same recursive declaration here

struct link_node {
    int data;
    link_node nextPtr;
};

==> recursive_dependency_solution.c <==
///Forward declaration
struct occ_t;  //tells compiler that occ_t will be defined in future, please tolerate usage as a pointer
// size of all pointers on a 32 bit machine is 4 bytes, and all pointers on a 64 bit machine is 8 bytes


struct emp_t {
    char name[32];
    unsigned int emp_id;
    struct occ_t* occ;
};

struct occ_t {
    char name[32];
    unsigned int salary;
    struct emp_t boss;
};

//same forward declaration used for linked list below

struct link_node {
    int data;
    struct link_node* nextNode;
};

==> tlv_assignment.c <==
/*
 * =====================================================================================
 *
 *       Filename:  tlv_assignment.c
 *
 *    Description:  This file is an assignment on TLV
 *
 *        Version:  1.0
 *        Created:  02/07/2020 10:59:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Er. Abhishek Sagar, Juniper Networks (https://csepracticals.wixsite.com/csepracticals), sachinites@gmail.com
 *        Company:  Juniper Networks
 *
 *        This file is part of the TLV Assignment distribution (https://github.com/sachinites) 
 *        Copyright (c) 2019 Abhishek Sagar.
 *        This program is free software: you can redistribute it and/or modify it under the terms of the GNU General 
 *        Public License as published by the Free Software Foundation, version 3.
 *        
 *        This program is distributed in the hope that it will be useful, but
 *        WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *        General Public License for more details.
 *
 *        visit website : https://csepracticals.com for more courses and projects
 *                                  
 * =====================================================================================
 */


 /* visit website : https://csepracticals.com */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define TLV_OVERHEAD_SIZE    2

/* Assignment : 
 * Implement the below macros, and use them in function decode_tlv_buffer
 * to decode TLV buffer and its contents*/
#define ITERATE_TLV_BEGIN(start_ptr, type, length, tlv_ptr, buffer_size) {  \
    long long end = ((long long)start_ptr + buffer_size); \
    while ((long long)start_ptr < end) { \
        char* _type = (char*)calloc(1, 1); \
        memcpy(_type, start_ptr, 1); \
        type = (uint8_t)(*_type); \
        start_ptr += 1; \
        char* _length = (char*)calloc(1,1); \
        memcpy(_length, start_ptr, 1); \
        length = (uint8_t)(*_length); \
        start_ptr += 1; \
        tlv_ptr = (uint8_t*)start_ptr; \
        start_ptr += length; 

#define ITERATE_TLV_END(start_ptr, type, length, tlv_ptr, buffer_size) } } \
   

#define NAME_TLV_CODE	    1  // >> String format , Unit Data length 32B
#define WEBSITE_TLV_CODE	2  // >> String format,  Unit Data length 64B
#define EMP_ID_TLV_CODE    	3  // >> Integer format, Unit Data length 8B
#define IP_ADDRESS_TLV_CODE    	4  // >> Integer format, Unit Data length 16B

static uint8_t
get_unit_data_size(uint8_t tlv_type )
{
    switch(tlv_type){
        case NAME_TLV_CODE:
            return 32;
        case WEBSITE_TLV_CODE:
            return 64;
        case EMP_ID_TLV_CODE:
            return 8;
        case IP_ADDRESS_TLV_CODE:
            return 16;
        default:
            return 1;
    }
}

/*Implement the below function, print all TLVs in the buffer using MACRO definitions*/
void
decode_tlv_buffer(unsigned char *tlv_buffer, 
                  uint32_t tlv_buffer_size){

    uint8_t tlv_type;
    uint8_t tlv_len;
    uint8_t *tlv_value;

    int units = 0, i = 0;

    ITERATE_TLV_BEGIN(tlv_buffer, tlv_type, tlv_len, tlv_value, tlv_buffer_size){
       
        units = tlv_len/get_unit_data_size(tlv_type);

        switch(tlv_type){
            case NAME_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Name = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));                
            }
            break;
            case WEBSITE_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Website Name = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));                
            }
            break;
            case EMP_ID_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Emp ID = %lu\n", tlv_type,
                    *(uint64_t *)(tlv_value + (i * get_unit_data_size(tlv_type))));                
            }
            break;
            case IP_ADDRESS_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, IP Address = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));                
            }
            break;
            default:
                ;
        }
    } ITERATE_TLV_END(tlv_buffer, tlv_type, tlv_len, tlv_value, tlv_buffer_size);
}

/*
   +------------------------------------+
   |           tlv_type = 1             |
   +------------------------------------+
   |           tlv_len = 64             |
   +------------------------------------+
   |                                    |
   |          Abhishek Sagar(32B)       |
   +------------------------------------+
   |                                    |
   |-         Shivani(32B)              |
   +------------------------------------+
   |           tlv_type = 2             |
   +------------------------------------+
   |           tlv_len = 128            |
   +------------------------------------+
   |                                    |
   |          www.csepracticals.com(64B)|
   +------------------------------------+
   |                                    |
   |          www.facebook.com(64B)     |
   +------------------------------------+
   |          tlv_type = 3              |
   +------------------------------------+
   |          tlv_len = 24              |
   +------------------------------------+
   |                                    |
   |          52437(8B)                 |
   +------------------------------------+
   |                                    |
   |          52438(8B)                 |
   +------------------------------------+
   |                                    |
   |          52439(8B)                 |
   +------------------------------------+

*/

/* The below function prepares the tlv buffer in the format
 * as shown in above diagram*/
unsigned char *
prepare_tlv_buffer(uint32_t *total_buffer_size){

    /*Take 222B of TLV buffer*/
    *total_buffer_size = 288;
    unsigned char *tlv_buffer = calloc(1, *total_buffer_size);
    unsigned char *temp = NULL;

    *tlv_buffer = NAME_TLV_CODE;
    *(tlv_buffer + 1) = 64;
    strncpy(tlv_buffer + TLV_OVERHEAD_SIZE, "Abhishek Sagar", 32);
    strncpy(tlv_buffer + TLV_OVERHEAD_SIZE + 32, "Shivani", 32);

    temp = tlv_buffer + TLV_OVERHEAD_SIZE + (32 * 2);

    *temp = WEBSITE_TLV_CODE;
    *(temp + 1) = 128;
    strncpy(temp + TLV_OVERHEAD_SIZE, "www.csepracticals.com", 64);
    strncpy(temp + TLV_OVERHEAD_SIZE + 64, "www.facebook.com", 64);

    temp += TLV_OVERHEAD_SIZE + (64 * 2);

    *temp = EMP_ID_TLV_CODE;
    *(temp + 1) = 24;

    uint64_t *emp_id = (uint64_t *)(temp + TLV_OVERHEAD_SIZE);
    *emp_id = 52437;
    *(emp_id + 1) = 52438;
    *(emp_id + 2) = 52439;   

    temp += TLV_OVERHEAD_SIZE + (8 * 3);
    *temp = IP_ADDRESS_TLV_CODE;
    *(temp + 1) = 64;
    strncpy(temp + TLV_OVERHEAD_SIZE, "122.1.1.1", 16);
    strncpy(temp + 16 + TLV_OVERHEAD_SIZE, "122.1.1.2", 16);
    strncpy(temp + 32 + TLV_OVERHEAD_SIZE, "122.1.1.3", 16);
    strncpy(temp + 48 + TLV_OVERHEAD_SIZE, "122.1.1.4", 16);

    return tlv_buffer;
}

int
main(int argc, char **argv){

    uint32_t total_buffer_size = 0;
    unsigned char *tlv_buffer = prepare_tlv_buffer(&total_buffer_size);
    if(tlv_buffer && total_buffer_size)
        decode_tlv_buffer(tlv_buffer, total_buffer_size);
    return 0;
}

==> glthreads/glthreadsdoublelink.c <==
#include "glthreadsdoublelink.h"

void register_key_match_callback(glthread_dll_t* list, int (*key_match)(void*, void*))
{
    list->key_match = key_match;
}

void register_print_data_item(glthread_dll_t* list, void (*print_data_item)(int, void*))
{
    list->print_data_item = print_data_item;
}

void register_compare_items_callback(glthread_dll_t* list, int (*compare_items)(void*, void*))
{
    list->compare_items = compare_items;
}

void glthread_add(glthread_dll_t* list, glthread_dll_node_t *node)
{
    node->left = NULL;
    node->right = NULL;
}

int glthread_remove(glthread_dll_t* list, void *data)
{
    glthread_dll_node_t *currentNode = list->head;
    
    void* data_struct;
    if (currentNode == NULL){
        return -1;
    }
    while(currentNode){
        data_struct = (void*)((long long)currentNode - list->offset);
        if (list->key_match(data_struct, data) == 0){
            if (currentNode->left)
                currentNode->left->right = currentNode->right;
            if (currentNode->right)
                currentNode->right->left = currentNode->left;
//          free(currentNode);
            return 0;
        }
        currentNode = currentNode->right;
    }

    return -1;
}

glthread_dll_t* init_glthread(unsigned int offset)
{
    glthread_dll_t* list = (glthread_dll_t*)calloc(1, sizeof(glthread_dll_t));
    list->head = NULL;
    list->offset = offset;
}

int add_data_to_linked_list(glthread_dll_t* list, glthread_dll_node_t *node)
{
    if (!node)
        node = (glthread_dll_node_t*)calloc(1, sizeof(glthread_dll_node_t));

    glthread_dll_node_t *currentNode = list->head;
    if (currentNode == NULL){
        list->head = node;
        return 0;
    }
    while (currentNode){
        if (currentNode->right == NULL){
	    currentNode->right = node;
            currentNode->right->left = currentNode;
            return 0;
        }
        currentNode = currentNode->right;
    }
    return 0;
}

==> glthreads/glthreadsdoublelink.h <==
#ifndef GLTHREADS_H
#define GLTHREADS_H
#include <stdio.h>
#include <malloc.h>

#define OFFSET_OFF(struct_name, field_name, off) \
    off = (long long)&((struct_name *)0)->field_name; 

typedef struct glthread_dll_node_ {
    struct glthread_dll_node_* left;
    struct glthread_dll_node_* right;
} glthread_dll_node_t;

typedef struct glthread_dll_ {
    glthread_dll_node_t* head;
    unsigned int offset;
    int (*key_match)(void*, void*);
    int (*compare_items)(void*, void*);
    void (*print_data_item)(int, void*);
} glthread_dll_t;

void glthread_add(glthread_dll_t* list, glthread_dll_node_t *node);

int glthread_remove(glthread_dll_t* list, void *data);

void register_key_match_callback(glthread_dll_t* list, int (*key_match)(void*, void*));

void register_print_data_item(glthread_dll_t* list, void (*print_data_item)(int, void*));

void register_compare_items_callback(glthread_dll_t* list, int (*compare_items)(void*, void*));

void register_offset(unsigned int offset);

#define ITERATE_GLTHREADS_BEGIN(listptr, struct_type, ptr, count) { \
    glthread_dll_node_t* _glnode = NULL; \
    count = 0; \
    for (_glnode = listptr->head; _glnode; _glnode = _glnode->right, count++){ \
        ptr = (struct_type*)((long long)_glnode - listptr->offset);

#define ITERATE_GLTHREADS_END }}

#define glthread_node_init(glnode) \
    glnode->left = NULL; \
    glnode->right = NULL;

glthread_dll_t* init_glthread(unsigned int offset);

int add_data_to_linked_list(glthread_dll_t* list, glthread_dll_node_t *node);

#endif 

==> glthreads/main.c <==
#include "glthreadsdoublelink.h"

typedef struct num_struct{
    int num;
    glthread_dll_node_t glthread_dll_node;
} num_struct_t;

void printNumber(int count, num_struct_t* current){
    printf("Data item %d: %d\n", count, current->num);
}

int matchKey(void* current, void* key){
    int* thisNum = (int*)key;
    num_struct_t* currentNum = (num_struct_t*)(current);
    if (currentNum->num == *thisNum)
        return 0;
    return -1;
}

int compareKey(void* current, void* key){
    int* thisNum = (int*)key;
    num_struct_t* currentNum = (num_struct_t*)(current);
    if (currentNum->num >= *thisNum)
        return 0;
    return -1;
}

int main(){
    unsigned int offset = 0;
    OFFSET_OFF(num_struct_t, glthread_dll_node, offset) 

    num_struct_t newnum1 = {5}, newnum2 = {1}, newnum3 = {3};

    glthread_dll_t* list = init_glthread(offset);

    int* data1 = (int *)calloc(1, sizeof(int));
    *data1 = 3;

    add_data_to_linked_list(list, &newnum1.glthread_dll_node);
    add_data_to_linked_list(list, &newnum2.glthread_dll_node);
    add_data_to_linked_list(list, &newnum3.glthread_dll_node);

    register_key_match_callback(list, matchKey);
    int count = 0;

    num_struct_t* current;
    ITERATE_GLTHREADS_BEGIN(list, num_struct_t, current, count) 
        printNumber(count, current);
    ITERATE_GLTHREADS_END 

    glthread_remove(list, (void*)data1);
    ITERATE_GLTHREADS_BEGIN(list, num_struct_t, current, count) 
        printNumber(count, current);
    ITERATE_GLTHREADS_END 
    return 0;
}

==> tlv/main.c <==
#include "serialize.h"

int main(){
    ser_buff_t* ser_buff = NULL;

    init_serialized_buffer(&ser_buff);
    
    init_serialized_buffer_of_defined_size(&ser_buff, 1024);
    return 0;
}

==> tlv/serialize.c <==
#include "serialize.h"

typedef struct serialized_buffer {
    #define SERIALIZE_BUFFER_DEFAULT_SIZE 512
    void* b;
    int size;
    int next;
    int checkpoint;
} ser_buff_t;

void init_serialized_buffer(ser_buff_t **ser_buf)
{
    *ser_buf = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
    (*ser_buf)->b = calloc(1, SERIALIZE_BUFFER_DEFAULT_SIZE);
    (*ser_buf)->size = SERIALIZE_BUFFER_DEFAULT_SIZE;
    (*ser_buf)->next = 0;
    (*ser_buf)->checkpoint = 0;
}

void init_serialized_buffer_of_defined_size(ser_buff_t **ser_buf, int size)
{
    *ser_buf = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
    (*ser_buf)->b = calloc(1, size);
    (*ser_buf)->size = size;
    (*ser_buf)->next = 0;
    (*ser_buf)->checkpoint = 0;
}


void serialize_string(ser_buff_t* ser_buf, char *data, int size)
{
    if (ser_buff == NULL) assert(0);
    int available = ser_buf->size - ser_buf->next;
    char reSize = 0;

    while (available < size){
        ser_buf->size *= 2;
        available = ser_buf->size - ser_buf->next;
        reSize = 1;
    }

    if (reSize == 0){
        memcpy((char *)ser_buf->b + ser_buf->next, data, size);
        ser_buf-> next += size;
        return;
    }

    ser_buf->b = realloc(ser_buf->b, ser_buf->size);
    memcpy((char*)ser_buf->b + ser_buf->next, data, size);
    ser_buf->next += size;
    return;
}

int is_serialized_buffer_empty(ser_buff_t* ser_buf)
{
    if (ser_buf->next == 0)
        return 0;
    return -1;
}

void de_serialize_string(char* dest, ser_buff_t* ser_buf, int val_size)
{
    if (!ser-buf||!ser_buf->b||!size) assert(0);
    if (ser_buf->size - ser_buf->next < size) assert(0);
    memcpy(dest, (char*)ser_buf->b + ser_buf->next, val_size);
    ser_buf->next += val_size;
}

void copy_in_serialized_buffer_by_offset(ser_buff_t* ser_buf, int size, char* value, int offset)
{
    if (offset + size < SERIALIZE_BUFFER_DEFAULT_SIZE)
        memcpy((char*)ser_buf->b + offset, value, size);
    else
        fprintf(stderr, "Error, isufficient space");
}

void mark_checkpoint_serialize_buffer(ser_buff_t* ser_buf)
{
    if (!ser_buf) assert(0);
    ser_buf->checkpoint = ser_buf->next;
}

int get_serialize_buffer_checkpoint_offset(ser_buff_t* ser_buf)
{
    if (!ser_buf) assert(0);
    return ser_buf->checkpoint;
}

void serialize_buffer_skip(ser_buff_t* ser_buf, int skip_size)
{
    if (!ser_buf||!skip_size) assert(0);

    while (ser_buf->next + skip_size > ser_buf->size){
        ser_buf->size *= 2;
        ser_buf->b = realloc(ser_buf->b, ser_buf->size);
    }

    if (ser_buf->next + skip_size > 0)
        ser_buf->next += skip_size;
    else
        assert(0);   
    
}

void free_serialize_buffer(ser_buff_t* ser_buf)
{
    for (int i = 0; i < ser_buf->size; i++)
        free((char*)(ser_buf->b + i));
 
    free(ser->buf);
}

==> tlv/serialize.h <==
#ifndef SERIALIZE
#define SERIALIZE
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

typedef struct serialized_buffer ser_buff_t; 

/* init functions */

void init_serialized_buffer(ser_buff_t **b);

void init_serialized_buffer_of_defined_size(ser_buff_t **b, int size);

void serialize_string(ser_buff_t* b, char *data, int size);

int is_serialized_buffer_empty(ser_buff_t* b);

void de_serialize_string(char* dest, ser_buff_t* b, int val_size);

void copy_in_serialized_buffer_by_offset(ser_buff_t* b, int size, char* value, int offset);

void mark_checkpoint_serialize_buffer(ser_buff_t* ser_buf);

int get_serialize_buffer_checkpoint_offset(ser_buff_t* ser_buf);

void serialize_buffer_skip(ser_buff_t* ser_buf, int skip_size);

void free_serialize_buffer(ser_buff_t* ser_buf);

#endif