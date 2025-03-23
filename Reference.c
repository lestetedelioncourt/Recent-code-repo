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

//by using malloc() data is being allocated onto the heap (located in RAM) all data is allocated on the heap and free() is used to free it

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
    double *myList[3] = malloc(sizeof(double) * 3);
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

    printf("p1 x = %d, y = %d, z = %d \n", p1.x, p1.y, p1.z);
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
    scanf("%d", &arrayLength);

    //ptr = (struct myArray*)malloc(sizeof(struct myArray) + arrayLength * sizeof(int));
    ptr = malloc(sizeof(struct myArray) + arrayLength * sizeof(int));

    ptr->length = arrayLength;
    printf("Array length is %d\n", ptr->length);

    for (int i = 0; i < arrayLength; i++){
        printf("Please enter the array element %d: ", i);
        scanf("%d", ptr->array + i);
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
        scanf("%d", ptr->array + i);
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
        scanf("%d", &arr[i]);
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
            scanf("%d", &decimal);
        
            printf("Binary number is %d\n",convertDecimaltoBinary(decimal));
        }
    
        if (answer == 'b'){
            printf("Please enter a binary number:");
            scanf("%lld", &bin);
        
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

    unsigned int w2 = 34; // 0000 0000 0000 0000 0000 0000 0010 0010,  int is represented by 32 bits in binary
    result = w2 >> 1; // bitwise shitft right +1, divided by 2, rightmost bit disappears

    printf("%d\n", result);

    signed int w3 = 142; // 0000 0000 0000 0000 0000 0000 1000 1110,  int is represented by 32 bits in binary
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

    //10010101
    //00111001

    w3 = w1 & w2; // bitwise and

    printf("bitwise and %d\n", w3);

    w3 = w1 | w2; // bitwise or
    
    printf("bitwise or %d\n", w3);

    w3 = w1 ^ w2; // bitwise or
    
    printf("bitwise xor %d\n\n", w3);

    printf("w1 = %d w2 = %d\n", w1, w2);

    //alternate swap operation
     w1 ^= w2;   //10010101
                 //00111001
                 //10101000

     w2 ^= w1;   //00111001
                 //10101000
                 //10010001

     w1 ^= w2;   //10101000
                 //10010001
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

jmp_buf buf; // jmp_buf is a type used by setjmp()/longjmp() to store the program’s execution context (like CPU registers, stack pointer, etc.).
// Declaring it globally makes it visible from both main() and error_recovery()

/* Calls longjmp(buf, 1), which:
 * Restores the execution context saved by the most recent setjmp(buf).
 * Forces setjmp(buf) to return the value passed to longjmp(), i.e. 1.
 * Hence, longjmp() effectively jumps back to wherever setjmp() was called.
 */
void error_recovery() {
    printf("Detected an unrecoverable error\n");
    longjmp(buf, 1);
}

/*setjmp(buf) is called.
 * On the very first call, setjmp() returns 0 (the “normal” path).
 * That means we go to the else block → which calls error_recovery().
 * Inside error_recovery():
 * We print "Detected an unrecoverable error".
 * Then we call longjmp(buf, 1).
 * Control jumps back to the same line where setjmp(buf) was called.
 * But now setjmp(buf) returns 1 (because of the longjmp()).
 * We return to main(), inside the same if (setjmp(buf)) { ... } else { ... } expression:
 * This time, setjmp(buf) yields 1, so the if path is taken:
 */
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

/*Key Takeaways
 * setjmp(jmp_buf) stores the program state at that point and returns 0 the first time.
 * longjmp(jmp_buf, val) jumps back to the matching setjmp(), causing it to return val.
 * This pattern is like a manual “try/catch” or “exception” mechanism in straight C.
 */

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

/* example code if referencing a suspicious pointer
 * setjmp(jbuf) returns 0 → we enter the try block.
 * We check suspicious, see that it’s NULL, and then call longjmp(jbuf, 1).
 * That makes setjmp(jbuf) return 1, so we enter the catch block, print "Caught bad pointer exception in newFunc!"
 */
void newFunc(){
    jmp_buf jbuf;
    int   apple; 
    int*  suspicious = NULL; // let's force it to be a bad pointer (NULL)
    
    int jumpVal = setjmp(jbuf);
    if (jumpVal == 0) {
        /*
         * TRY BLOCK
         * ----------
         * This code runs the first time setjmp returns 0.
         */
        printf("Entering newFunc 'try' block.\n");

        // Let's do a pointer check. If it's invalid, let's "throw"
        if (!suspicious) {
            // Instead of crashing on *suspicious, "throw an exception" via longjmp
            longjmp(jbuf, 1); 
        }
        
        // If suspicious had been valid, do something:
        apple = *suspicious;
        printf("Suspicious pointer value: %d\n", apple);
    }
    else {
        /*
         * CATCH BLOCK
         * -----------
         * We jump here if we called longjmp(jbuf, 1) above.
         */
        printf("Caught bad pointer exception in newFunc!\n");
    }
}

int main(){
    if(setjmp(buf))
        printf("back in main\n");
    else {
        printf("first time through\n");
        myFunction();
    }

	newFunc();
    return 0;
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
    
    while ((ch = getchar()) != '\n'){
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

    while((ch = getchar()) != '\n'){
        ch = ch + 32;
        putc(ch, stdout);
    }
    printf("\n");
}

void convert2Upper(){
    char ch;

    while((ch = getchar()) != '\n'){
        ch = ch - 32;
        putc(ch, stdout);
    }
    printf("\n");
}

int main(int argc, char **argv){
    char answer;
    printf("Converter to upper or lower (u or l)?");
    scanf("%c", &answer);

    getchar();
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

int main(int argc, char** argv){
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

int main(int argc, char** argv){
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

int main(int argc, char** argv){
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

int main(int argc, char** argv){
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

==>timer_demo.c<==	
/*To compile with gcc must link rt library i.e gcc <file> -o <bin> -lrt */
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

/* Timer callback function which will be called every time the timer expires. The
signature of the function should be: void <fn_name>(union sigval); */
void timer_callback(union sigval arg) {
	print_current_system_time();

	pair_t* newpair = (pair_t*) arg.sival_ptr; /* Extract the user data structure */

	printf("Pair: [%d %d]\n", newpair->a, newpair->b);
}

pair_t pair = {5, 3};

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

	ts.it_interval.tv_sec = 2; //defining this makes a periodic timer
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

==> domainclient.c <==
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

#define SOCKET_NAME "/tmp/DemoSocket"
#define BUFFER_SIZE 128

int main(int argc, char **argv){
    struct sockaddr_un addr;
    int i;
    int ret;
    int data_socket;
    char buffer[BUFFER_SIZE];

    /* Create data socket */
    
    data_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (data_socket == -1){
        perror("socket");
	exit(EXIT_FAILURE);
    }

    /* For portability clear the whole structure, since some implementations
       have additional (nonstandard fields in the structure) */

    memset(&addr, 0, sizeof(struct sockaddr_un));

    /* Connect socket to socket address */
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) -1);

    ret = connect(data_socket, (const struct sockaddr*)&addr, sizeof(struct sockaddr_un));

    if (ret == -1){
        fprintf(stderr, "The server is down\n");
        exit(EXIT_FAILURE);
    }

    /* Send arguments */
    do {
	printf("Enter number to send to server: \n");
	scanf("%d", &i);
	ret = write(data_socket, &i, sizeof(int));
	if (ret == -1) {
	    perror("write");
	    break;
	}
	printf("No of bytes sent = %d, data sent = %d\n", ret, i);
        sleep(1);
    } while(i);   

    memset(buffer, 0, BUFFER_SIZE);
    ret = read(data_socket, buffer, BUFFER_SIZE);

    if (ret == -1){
	perror("write");
	exit(EXIT_FAILURE);
    }
    
    printf("Recvd from server : %s\n", buffer);

    /* Close socket */

    close(data_socket);
    exit(EXIT_SUCCESS);
}

==> domainserver.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

#define SOCKET_NAME "/tmp/DemoSocket"
#define BUFFER_SIZE 128

int main(int argc, char** argv){
    struct sockaddr_un name; //provided by standard C APIs
        
    #if 0  
	struct sockaddr_un { 
	    sa_family_t sun_family;	/* AF_UNIX */
	    char	sun_path[108];	/* pathname */
	};
    #endif

    int ret;
    int connection_socket;
    int data_socket;
    int result;
    int data;
    char buffer[BUFFER_SIZE];

    /*In case the program exited inadvertently on the last run
     *remove the socket */
    
    unlink(SOCKET_NAME);

    /* Create Master Socket */

    /* SOCK_DGRAM for Datagram based communication */
    connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (connection_socket == -1) {
	perror("socket");
	exit(EXIT_FAILURE);
    }

    printf("Master socket created\n");

    /*Initialize*/
    memset(&name, 0, sizeof(struct sockaddr_un));

    /*Specify the socket Credentials*/
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);
    
    /* Bind socket to socket name 
       Purpose of bind() system call is that application() dictate the underlying
       operating system the criteria of receiving the data. Here, bind() system call
       is telling the OS that if sender process sends the data destined to socket "/tmp/DemoSocket"
       then such data needs to be delivered to this process no me (the server process)*/

    ret = bind(connection_socket, (const struct sockaddr *) &name, sizeof(struct sockaddr_un));

    if (ret == -1) {
	perror("bind");
	exit(EXIT_FAILURE);
    }

    printf("bind() call succeeds\n");

    /* Prepare for accepting connections. The backlog size is set to 20. So
       while one request is being processed other requests can be waiting */
    ret = listen(connection_socket, 20);
    if (ret == -1) {
	perror("listen");
	exit(EXIT_FAILURE);
    }

    /* This is the main loop for handling connections. All Server process usually runs 24 x 7
       Good servers should always be up and running and should never go down. */
    for (;;){
        /* Wait for incoming connections */
        printf("Waiting on accept sys() call\n");

        data_socket = accept(connection_socket, NULL, NULL);
        if (data_socket == -1){
	    perror("accept");
	    exit(EXIT_FAILURE);
        }
    
    	printf("Connection accepted from client\n");
    
        result = 0;
    
    	for (;;) {
    	    /*Prepare the buffer to receive the data */
    	    memset(buffer, 0, BUFFER_SIZE);
    	    
    	    /* Wait for next data packet. Server is blocked here. Waiting for the
     	       data to arrive from the client, 'read' is a blocking system call */ 
    	    printf("Waiting for data from the client\n");
            ret = read(data_socket, buffer, BUFFER_SIZE);

            if (ret == -1) {
		perror("read");
		exit(EXIT_FAILURE);
    	    }
    
    	    /* Add received comand */
    	    memcpy(&data, buffer, sizeof(int));
    	    
            printf("%d\n", data);

    	    if (data == 0) break;
    	    result += data;
    	}
    
    	/* Send result */
    	memset(buffer, 0, BUFFER_SIZE);
    	sprintf(buffer, "Result = %d", result);
    
    	printf("Sending final result back to client\n");
    	ret = write(data_socket, buffer, BUFFER_SIZE);
    	if (ret == -1){
    	    perror("write");
    	    exit(EXIT_FAILURE);
    	}
    
        /* Close socket */
        close(data_socket);
    }
    
    /*Close master socket*/
    close(connection_socket);
    printf("Connection closed.\n");

    return 0;
}

==> genericll.c <==
#include "linkedlist.h"

void serialize_list_t(list_t* obj, ser_buff_t* buff, void (*serialize_fn_ptr)(void*, ser_buff_t*)){
    SENTINEL_INSERTION_CODE
    serialize_list_node_t(obj->head, buff, serialize_fn_ptr);
}

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff, void (*serialize_fn_ptr)(void*, ser_buff_t*)){
    SENTINEL_INSERTION_CODE
    serialize_fn_ptr(obj->data, buff);
    serialize_list_node_t(obj->right, buff);
}

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff, void* (*de_serialize_fn_ptr)(ser_buff_t*)){
    SENTINEL_DETECTION_CODE

    struct list_node_t* obj = calloc(1, sizeof(struct list_node_t));
    obj->data = de_serialize_fn_ptr(buff);
    obj->right = de_serialize_list_node_t(buff);
    return obj;
}

list_t* de_serialize_list_t(ser_buff_t *buff, void* (*de_serialize_fn_ptr)(ser_buff_t*)){
    SENTINEL_DETECTION_CODE

    list_t* obj = calloc(1, sizeof(list_t));
    obj->head = de_serialize_list_node_t(buff);
    return obj;
}

==> genericll.h <==
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct list_node_t {
    void* data;
    struct list_node_t* right;
};

typedef struct list {
    struct list_node_t *head;
} list_t;

void serialize_list_t(list_t* obj, ser_buff_t* buff, void (*serialize_fn_ptr)(void*, ser_buff_t *buff));

void serialize_list_node_t(struct list_node_t* obj, ser_buff_t* buff, void (*serialize_fn_ptr)(void*, ser_buff_t *buff));

struct list_node_t* de_serialize_list_node_t(ser_buff_t *buff, void* (*de_serialize_fn_ptr)(ser_buff_t*));

list_t* de_serialize_list_t(ser_buff_t *buff, void* (*de_serialize_fn_ptr)(ser_buff_t*));

#endif

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

==> multiplexdomainserver.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/DemoSocket"
#define BUFFER_SIZE 128
#define MAX_CLIENT_SUPPORTED 32

/*An array of file descriptors that the server uses to talk to the connected
 * clients. Master socket file descriptor is also a member of this array. */ 
int monitored_fd_set[MAX_CLIENT_SUPPORTED];

/*Each connected client's intermediate result is
 * maintained in this client array */
int client_result[MAX_CLIENT_SUPPORTED] = {0};

/*remove all the file descriptors if any from the array*/
static void initialize_monitor_fd_set(){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	monitored_fd_set[i] = -1;
    }
}

/*Add the FD from monitored file array*/
static void add_to_monitored_fd_set(int skt_fd){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
        if(monitored_fd_set[i] != -1) continue;
        monitored_fd_set[i] = skt_fd;
        break;
    }
}

/*Remove the FD from monitored file array*/
static void remove_from_monitored_fd_set(int skt_fd){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
        if(monitored_fd_set[i] != skt_fd) continue;
        monitored_fd_set[i] = -1;
        break;
    }
}

/*Clone all the FDs from monitored file array into
  fd_set Data stucture*/
static void refresh_fd_set(fd_set *fd_set_ptr){
    FD_ZERO(fd_set_ptr);
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	if (monitored_fd_set[i] != -1){
	    FD_SET(monitored_fd_set[i], fd_set_ptr);
        }
    }
}

/*Get the numerical max value among all FDs which 
  server is monitoring*/
static int get_max_fd(){
    int max = -1;
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
        if (monitored_fd_set[i] > max)
	    max = monitored_fd_set[i];
    }

    return max;
}

int main(int argc, char **argv){
    struct sockaddr_un name;

#if 0
    struct sockaddr_un {
        sa_family_t sun_family;	/*AF_UNIX*/
	char 	sun_path[100];	/*pathname*/
    }
#endif

    int ret;
    int connection_socket;
    int data_socket;
    int result;
    int data;
    char buffer[BUFFER_SIZE];
    fd_set readfds;
    int comm_socket_fd, i;

    initialize_monitor_fd_set();

    /*In cas the program exited inadvertantly on the
 *   last run remove the socket */
    unlink(SOCKET_NAME);

    /*Create Master socket */
    /*SOCK_DGRA for Datagram-base communication*/
    connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (connection_socket == -1){
	perror("socket");
	exit(EXIT_FAILURE);
    }

    printf("Master socket created\n");

    /*initialize*/
    memset(&name, 0, sizeof(struct sockaddr_un));

    /*Specify the socket credentials*/
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

    ret = bind (connection_socket, (const struct sockaddr *) &name, 
	     sizeof(struct sockaddr_un));

    if (ret == -1){
	perror("socket");
	exit(EXIT_FAILURE);
    }

    printf("bind() call succeeded\n");

    /* Prepare for accepting connections. The backlog size is set to 20
       So while one request is being processm=, other requests can be waiting*/

    ret = listen(connection_socket, 20);
    if (ret == -1){
	perror("listen");
	exit(EXIT_FAILURE);
    }
 
    /*Add master socket to Monitored set of FDs*/
    add_to_monitored_fd_set(connection_socket);
    
    /*This is the main loop for handling connections. All server process usually
      run 24/7. Good servers should always be up and running*/
    for (;;) {
	refresh_fd_set(&readfds); /*Copy the entire monitored FDs to readfds*/
	/* Wait for incoming connections*/
	printf("Waiting on select() sys call\n");

	/*Call the select system call, server process blocks here. Linux OS keeps
          this process blocked until the connection initiation request, or data
	  requests arrives on any of the file descriptors in the readfds set */
	select(get_max_fd() + 1, &readfds, NULL, NULL, NULL);

	if(FD_ISSET(connection_socket, &readfds)){
	    /*Data arrives on Master socket only when new client connects with
              the server (that is 'connect' call is invoked on client side */
	    printf("New connection receivd recvd, accep the connection\n");
	    data_socket = accept(connection_socket, NULL, NULL);

	    if(data_socket == -1){
		perror("accept");
		exit(EXIT_FAILURE);
	    }

	    printf("New connection accepted from client\n");
	    
	    add_to_monitored_fd_set(data_socket);
	}
	else{ /* Data arrives on some other client FD*/
            /*Find the client which has sent us the data request*/
	    comm_socket_fd = -1;

  	    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
		if(FD_ISSET(monitored_fd_set[i], &readfds)){
	   	    comm_socket_fd = monitored_fd_set[i];

		    /*Prepare the buffer to recv the data*/
		    memset(buffer, 0, BUFFER_SIZE);

		    /*Wait for the next data packet. Server is blocked here.
		      Waiting for the data to arrive from client. 'read' is a 	
		      blocking system call*/
		    printf("Waiting for data from the client\n");
		    ret = read(comm_socket_fd, buffer, BUFFER_SIZE);

            	    if (ret == -1){
            		perror("read");
            		exit(EXIT_FAILURE);
            	    }

		    /* Add received command */
		    memcpy(&data, buffer, sizeof(int));
		    if(data == 0) {
			/* Send result */
			memset(buffer, 0, BUFFER_SIZE);
			sprintf(buffer, "Result = %d", client_result[i]);

			printf("Sending final result back to client\n");
			ret = write(comm_socket_fd, buffer, BUFFER_SIZE);
	            	if (ret == -1){
	            	    perror("write");
	            	    exit(EXIT_FAILURE);
	            	}
			
			/* Close socket. */
			close(comm_socket_fd);
			client_result[i] = 0;
			remove_from_monitored_fd_set(comm_socket_fd);
			continue; /*go to select() and block*/
		    }
		    client_result[i] += data;
                }
  	    }
	}
    } /* go to select() and block*/

    /*close the master socket*/
    close(connection_socket);
    remove_from_monitored_fd_set(connection_socket);
    printf("Connection closed..\n");

    /*Server should release resources before getting terminated. Unlinkk
    the socket*/

    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);
}

==> multiplextcpserver.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <arpa/inet.h>
#include "common.h"

/*Server process is running on this port no. Client has to send data to this port no.*/
#define SERVER_PORT 3000
#define MAX_CLIENT_SUPPORTED 32

test_struct_t test_struct;
result_struct_t res_struct;
char data_buffer[1024];

int monitored_fd_set[MAX_CLIENT_SUPPORTED];

static void initialize_monitor_fd_set(){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++)
	monitored_fd_set[i] = -1;
}

static void add_to_monitored_fd_set(int skt_fd){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	if(monitored_fd_set[i] != -1)
	    continue;
	monitored_fd_set[i] = skt_fd;
	break;
    }    
}

static void remove_from_monitored_fd_set(int skt_fd){
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	if(monitored_fd_set[i] != skt_fd)
	    continue;
	monitored_fd_set[i] = -1;
	break;
    }    
}

static void re_init_readfds(fd_set *fd_set_ptr){
    FD_ZERO(fd_set_ptr);   
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	if (monitored_fd_set[i] != -1){
	    FD_SET(monitored_fd_set[i], fd_set_ptr);
	}
    }
}

static int get_max_fd(){
    int max = -1;
    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
	if (monitored_fd_set[i] > max){
	    max = monitored_fd_set[i];
        }
    }

    return max;
}

void setup_tcp_server_communication(){
    /*Step 1: Initialization*/
    /*Socket handle and other variables*/
    int master_sock_tcp_fd = 0, /*Master socket file descriptor, used to accept new client connection only, no data exchange*/
    sent_recv_bytes = 0,
    addr_len = 0,
    opt = 1;

    int comm_socket_fd = 0;     /*Client specific communication socket file descriptor, used only for data exchange/communication between file and server*/
    fd_set readfds;		/*Set of file descriptor on which select() polls. Select() unblocks whenever data arrives on any fd present in the set*/
    
    /*variables to hold server information*/
    struct sockaddr_in server_addr, client_addr; /*structure to store the server and client info */

    /* Just drain the array of monitored file descriptors (sockets)*/
    initialize_monitor_fd_set();

    /* Step 2: tcp master socket creation */
    if ((master_sock_tcp_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
	printf("Socket creation failed.\n");
	exit(1);
    }

    /* Step 3: specify server information */
    server_addr.sin_family = AF_INET; /*This socket will process only ipv4 network packets*/
    server_addr.sin_port = SERVER_PORT; /*Server will process any data arriving on port 3000*/
    server_addr.sin_addr.s_addr = INADDR_ANY; /*INADDR_ANY as Server's IP address means Linux will send all data
					        whose dstination address = address of any local interface on this machine*/
    addr_len = sizeof(struct sockaddr);

    /*Bind the server. Binding means, we are telling kernel(OS) that any data you receive with dest ip address of any local interface on this machine
     *and tcp port no = 3000 to send that data to this process. bind() is a mechanism to tell OS what kind of data, the server process is interested in to 
     *receive. Remember server machine can run multiple server processes to process different data and service different clients. Note that bind(0 is used
     *only on the server side, not the client side.*/
    if (bind(master_sock_tcp_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1){
	printf("Socket bind failed.\n");
	exit(1);
    }
 
    /*Step 4 : Tell the Linux OS to maintain the queue of max length to Queue incoming client connections */
    if (listen(master_sock_tcp_fd, 5) < 0){
	printf("Listen failed.\n");
	exit(1);
    }

    /*Add master socket to group of monitored FDs*/
    add_to_monitored_fd_set(master_sock_tcp_fd);

    /*Server infinite loop for servicing the client*/
    while(1){
	/* Step 5: initialize and fill readfds*/
	//FD_ZERO(&readfds);		/*Initialize file descriptor set*/
	//FD_SET(master_sock_tcp_fd, &readfds);  /*Add the socket to this set on which our server is running*/

	re_init_readfds(&readfds);	/*Copy the entire monitored FDs to readfds*/

	printf("blocked on Select() call...\n");

	/*Step 6 : Wait for client connection*/
	/* state machine State 1 */
	select(get_max_fd() + 1, &readfds, NULL, NULL, NULL); //Call the select system call, Linux process blocks here, OS keeps process blocked until data arrives
	
	/*Some data on some fd present in monitored fd set has arrived. Now check on what file descriptor the data arrives and process accordingly*/
	
	/*If Data arrives on Master Socket FD*/
	if (FD_ISSET(master_sock_tcp_fd, &readfds)){
	    /*Data arrives on Master socket only when client connects with the server (that is, 'conect' call is invoked on client side)*/
	    printf("New connection received recvd, acccept the connection. Client and Server completes TCP 3-way handshake at this point.\n");

	    /*Step 7: Accept() returns a new temporary file descriptor(fd). Server uses this 'comm_socket_fd' fd for the rest of the life of connection with this 
	     *client to send and receive msg. Master socket is used only for accepting new client's connection and not for data exchange with the client*/
	    /* state Machine state 2 */
	    comm_socket_fd = accept(master_sock_tcp_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
	    if (comm_socket_fd < 0){
		/* if accept failed to return a socket descriptor, display error and exit */
		printf("accept error : errno = %s\n", strerror(errno));
		exit(1);
	    } 

	    add_to_monitored_fd_set(comm_socket_fd);
	    printf("Connection accepted from client : %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	}
	else{ /*Data arrives on some other client FD*/
	    int comm_socket_fd = -1;
	    for (int i = 0; i < MAX_CLIENT_SUPPORTED; i++){
		if (FD_ISSET(monitored_fd_set[i], &readfds)){
		    comm_socket_fd = monitored_fd_set[i];
		    
		    memset(data_buffer, 0, sizeof(data_buffer));
		    sent_recv_bytes = recvfrom(comm_socket_fd, (char*)data_buffer, sizeof(data_buffer), 0, (struct sockaddr*)&client_addr, &addr_len);
 
		    printf("Server recvd %d bytes from %s:%u\n", sent_recv_bytes, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		    if (sent_recv_bytes == 0){
			/*If server recvs empty msg from client, server may close the connection and wait for fresh new connection with client - same or different*/
			close(comm_socket_fd);
			remove_from_monitored_fd_set(comm_socket_fd);
			break; /*goto step 5*/
		    }

		    test_struct_t* client_data = (test_struct_t*)data_buffer;
		    /*If the client sends a special message to server, then server closes the client communication forever*/
		    /*Step 9*/
		    if (client_data->a == 0 && client_data->b == 0){
			close(comm_socket_fd);
			remove_from_monitored_fd_set(comm_socket_fd);
			printf("Server closes connection with client %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			break; /*goto step 5*/
		    }

		    result_struct_t result;
		    result.c = client_data->a + client_data->b;

		    /*Server replying back to client now*/
		    sent_recv_bytes = sendto(comm_socket_fd, (char*)&result, sizeof(result_struct_t), 0, (struct sockaddr*)&client_addr, sizeof(struct sockaddr));

		    printf("Server sent %d bytes in reply to client\n", sent_recv_bytes);
		}
	    }
        }
    }/*Step 10: wait for new client request again*/
}

int main(int argc, char** argv){
    setup_tcp_server_communication();
    return 0;
}

==> multiply.c <==
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include "rpc_common.h"
#include "serialized_buffer.h"

ser_buff_t* multiply_client_stub_marshal(int a, int b){
    ser_buff_t* client_send_ser_buffer = NULL;
    init_serialized_buffer_of_defined_size(&client_send_ser_buffer, MAX_RECV_SEND_BUFF_SIZE);

    serialize_data(client_send_ser_buffer, (char*)&a, sizeof(int));
    serialize_data(client_send_ser_buffer, (char*)&b, sizeof(int));

    return client_send_ser_buffer;
} 

int multiply_server_stub_unmarshall(ser_buff_t* client_recv_ser_buffer){
    int a;
    de_serialize_data((char*)&a, client_recv_ser_buffer, sizeof(int));

    return a;
}

int rpc_send_rcv(ser_buff_t* client_send_ser_buffer, ser_buff_t* client_recv_ser_buffer){
    struct sockaddr_in dest;
    int sockfd = 0, rc = 0, recv_size = 0;
    int addr_len;

//  dest.asin_family = AF_INET; 
//  dest.sin_port = htons(PORT); 
//  dest.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    dest.sin_family = AF_INET; //IPv4 protocol
    dest.sin_port = htons(SERVER_PORT); //local port 2000
    dest.sin_addr.s_addr = INADDR_ANY; // localhost
    //struct hostent* host = (struct hostent*)gethostbyname(SERVER_IP); // SERVER_IP 127.0.0.1
    //dest.sin_addr = *((struct in_addr *)host->h_addr);
    addr_len = sizeof(struct sockaddr);

   // sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sockfd == -1){
        printf("Socket creation failed\n");
        return -1;
    }

    //connect(sockfd, (struct sockaddr*) &dest, sizeof(struct sockaddr_in));
    //struct timeval tv; tv.tv_sec = 20; tv.tv_usec = 0;
    //setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv);
    //shortRetval = send(sockfd, client_send_ser_buffer->b, client_send_ser_buffer->size, 0);
  //     sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
    rc = sendto(sockfd, client_send_ser_buffer->b, client_send_ser_buffer->size, MSG_CONFIRM, (struct sockaddr *)&dest, sizeof(struct sockaddr));

    printf("%s() : %d bytes sent\n", __FUNCTION__, rc);
    
    recv_size = recvfrom(sockfd, client_recv_ser_buffer->b, client_recv_ser_buffer->size, MSG_WAITALL, (struct sockaddr*)&dest, &addr_len); 

    printf("%s() : %d bytes received\n", __FUNCTION__, recv_size);

    int res = multiply_server_stub_unmarshall(client_recv_ser_buffer);

    return res;
}

int multiply_rpc(int a, int b){
    ser_buff_t* client_send_ser_buffer = multiply_client_stub_marshal(a, b);
    ser_buff_t* client_recv_ser_buffer = NULL;
    init_serialized_buffer_of_defined_size(&client_recv_ser_buffer, MAX_RECV_SEND_BUFF_SIZE);

    int res = rpc_send_rcv(client_send_ser_buffer, client_recv_ser_buffer);
   // free_serialized_buffer(client_send_ser_buffer);
   // free_serialized_buffer(client_recv_ser_buffer);
  
    return res;
}

int main(){
    int a, b;
    printf("Please enter 1st number: ");
    scanf("%d", &a);
    printf("Please enter 2nd number: ");
    scanf("%d", &b);

    int res = multiply_rpc(a, b);
    printf("\n Result is: %d\n", res);

    return 0;
}

//    int sockfd; 
//    char buffer[MAXLINE]; 
//    char *hello = "Hello from client"; 
//    struct sockaddr_in     servaddr; 
//
//    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
//        perror("socket creation failed"); 
//        exit(EXIT_FAILURE); 
//    } 
//  
//    memset(&servaddr, 0, sizeof(servaddr)); 
//    servaddr.sin_family = AF_INET; 
//    servaddr.sin_port = htons(PORT); 
//    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
//      
//    int n, len; 
//      
//    sendto(sockfd, (const char *)hello, strlen(hello), 
//        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
//            sizeof(servaddr)); 
//    printf("Hello message sent.\n"); 
//          
//    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
//                MSG_WAITALL, (struct sockaddr *) &servaddr, 
//                &len); 
//    buffer[n] = '\0'; 
//    printf("Server : %s\n", buffer); 
//  
//    close(sockfd); 

==> newserver.c <==
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h> 

#define PORT    12345
#define MAXLINE  1024 

// Driver code
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
    // Filling server information

    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    // Bind the socket with the server address 

    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    int len, n; 
  
    len = sizeof(cliaddr);  //len is value/resuslt 
  
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                &len); 
    buffer[n] = '\0'; 
    printf("Client : %s\n", buffer); 
    sendto(sockfd, (const char *)hello, strlen(hello),  
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
            len); 
    printf("Hello message sent.\n");  
      
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

void serialize_person_t_wrapper(void* obj, ser_buff_t *buff);

void serialize_person_t(person_t* obj, ser_buff_t *buff);

person_t* de_serialize_person_t(ser_buff_t* buff);

void* de_serialize_person_t_wrapper(ser_buff_t* buff);

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

==> readershm.c <==
#include <stdio.h>
#include <string.h>

extern int read_from_shared_memory(char *mmap_key, char *buffer, unsigned int buff_size, unsigned int bytes_to_read);

int main(int argc, char** argv){
    char *key = "/introduction";
    char read_buffer[128];
    memset(read_buffer, 0, 128);
    int rc = read_from_shared_memory(key, read_buffer, 128, 128);

    if (rc < 0){
	printf("Error reading from shared memory\n");
	return 0;
    }

    printf("Data read = %s\n", (char*)read_buffer);
    return 0;
}

==> recvrMsgQ.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MESSAGES		10
#define MAX_MSG_SIZE		256
#define MSG_BUFFER_SIZE		(MAX_MSG_SIZE + 10)
#define QUEUE_PERMISSIONS	0660

int main(int argc, char **argv){
    fd_set readfds;
    char buffer[MSG_BUFFER_SIZE];
    int msgq_fd = 0;

    if(argc == 1){
	printf("provide a recipient msgQ name : format </msq-name>\n");
	return 0;
    }

    /*To set msgQ attributes*/

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MSG_SIZE;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    printf("%s\n", argv[1]);

    if ((msgq_fd = mq_open(argv[1], O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
	printf("Client: mq_open failed, errno = %s\n", strerror(errno));
        exit(1); 
    }

    while(1){
	FD_ZERO(&readfds);
	FD_SET(msgq_fd, &readfds);
	printf("Receiver blocked on select()\n");
	select(msgq_fd + 1, &readfds, NULL, NULL, NULL);
	if(FD_ISSET(msgq_fd, &readfds)){
	    printf("Msg recvd msgQ %s\n", argv[1]);
	    memset(buffer, 0, MSG_BUFFER_SIZE);
	
	    if(mq_receive(msgq_fd, buffer, MSG_BUFFER_SIZE, NULL) == -1){
		printf("mq_receive error, errno = %s\n", strerror(errno));
		exit(1);
	    }
	    printf("Msg received from queue = %s\n", buffer);
	}
    }
}

==> rpc_common.h <==
#ifndef RPC_COMMON_H
#define RPC_COMMON_H

#define MAX_RECV_SEND_BUFF_SIZE 256
#define SERVER_PORT 12345
#define SERVER_IP "127.0.0.1"

#endif

==> rpc_server_main.c <==
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include "rpc_common.h"
#include "serialized_buffer.h"

int multiply_server_stub_unmarshall(ser_buff_t* server_recv_ser_buffer){
    int a, b;
    de_serialize_data((char*)&a, server_recv_ser_buffer, sizeof(int));
    de_serialize_data((char*)&b, server_recv_ser_buffer, sizeof(int));

    return a * b;
}

void multiply_server_stub_marshall(int res, ser_buff_t* server_send_ser_buffer){
    serialize_data(server_send_ser_buffer, (char*)&res, sizeof(int));
}

void rpc_server_process_msg(ser_buff_t* server_send_ser_buffer, ser_buff_t* server_recv_ser_buffer){
    int res = multiply_server_stub_unmarshall(server_recv_ser_buffer);
    multiply_server_stub_marshall(res, server_send_ser_buffer);
}

int main(){
    int sock_udp_fd = 0, len, addr_len, reply_msg_size = 0;
    
    struct sockaddr_in server_addr, client_addr;
 
  // if ((sock_udp_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    if ((sock_udp_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("Socket creation failed\n");
        return -1;
    }

//       servaddr.sin_family = AF_INET; // IPv4 
//       servaddr.sin_addr.s_addr = INADDR_ANY; 
//       servaddr.sin_port = htons(PORT); 
      
    server_addr.sin_family = AF_INET; //IPv4 protocol
    server_addr.sin_port = htons(SERVER_PORT); //IPv4 protocol
    server_addr.sin_addr.s_addr = INADDR_ANY; //IPv4 protocol
    addr_len = sizeof(struct sockaddr_in);

//    if (setsockopt(sock_udp_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0){
//        perror("setsockopt");
//        exit(EXIT_FAILURE);
//    }
//
//    if (setsockopt(sock_udp_fd, SOL_SOCKET, SO_REUSEPORT, (char*)&opt, sizeof(opt)) < 0){
//        perror("setsockopt");
//        exit(EXIT_FAILURE);
//    }

 // if (bind(sockfd, (const struct sockaddr *)&servaddr,  sizeof(servaddr)) < 0 ) 
    if (bind(sock_udp_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1){
        printf("Socket bind failed\n");
        exit(1);
    }

    ser_buff_t* server_send_ser_buffer = NULL;
    ser_buff_t* server_recv_ser_buffer = NULL;   

    init_serialized_buffer_of_defined_size(&server_send_ser_buffer, MAX_RECV_SEND_BUFF_SIZE);
    init_serialized_buffer_of_defined_size(&server_recv_ser_buffer, MAX_RECV_SEND_BUFF_SIZE);

    printf("Server ready to service rpc calls\n");

READ:
    reset_serialize_buffer(server_recv_ser_buffer);

   // n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
    len = recvfrom(sock_udp_fd, server_recv_ser_buffer->b, server_recv_ser_buffer->size, MSG_WAITALL, (struct sockaddr*)&client_addr, &addr_len);

    printf("No of bytes received from client = %d\n", len);
    reset_serialize_buffer(server_send_ser_buffer);
    rpc_server_process_msg(server_send_ser_buffer, server_recv_ser_buffer);
    sendto(sock_udp_fd, server_send_ser_buffer->b, server_send_ser_buffer->size, MSG_CONFIRM, (struct sockaddr*)&client_addr, sizeof(struct sockaddr));
    goto READ;

    free_serialized_buffer(server_send_ser_buffer);
    free_serialized_buffer(server_recv_ser_buffer);

  //  close(sock_udp_fd);

    return 0;
}


   /* int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
    // Filling server information

    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    // Bind the socket with the server address 

    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    int len, n; 
  
    len = sizeof(cliaddr);  //len is value/resuslt 
  
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                &len); 
    buffer[n] = '\0'; 
    printf("Client : %s\n", buffer); 
    sendto(sockfd, (const char *)hello, strlen(hello),  
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
            len); 
    printf("Hello message sent.\n");  */

==> sendMsgQ.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MSG_SIZE	256
#define MSG_BUFFER_SIZE	(MAX_MSG_SIZE + 10)

int main(int argc, char **argv){
    char buffer[MSG_BUFFER_SIZE];
    int recvr_msgq_fd = 0;

    if(argc == 1){
	printf("provide a recipient msgQ name : format </msq-name>\n");
	return 0;
    }

    memset(buffer, 0, MSG_BUFFER_SIZE);
    printf("Enter message to be sent to receiver %s\n", argv[1]);
    scanf("%s", buffer);
    
    if ((recvr_msgq_fd = mq_open(argv[1], O_WRONLY | O_CREAT, 0, 0)) == -1) {
	printf("Client: mq_open failed, errno = %d", errno);
	exit(1);
    }

    if (mq_send(recvr_msgq_fd, buffer, strlen(buffer), 0) == -1) {
	perror("Client: Not able to send message to server");
	exit(1);
    }

    mq_close(recvr_msgq_fd);
    return 0;
}

==> serialized_buffer.c <==
#include "serialized_buffer.h"

void init_serialized_buffer(ser_buff_t **ser_buf){
    (*ser_buf) = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
    (*ser_buf)->b = (char*)calloc(1, SERIALIZED_BUFFER_DEFAULT_SIZE);
    (*ser_buf)->size = SERIALIZED_BUFFER_DEFAULT_SIZE;
    (*ser_buf)->next = 0; 
}

void init_serialized_buffer_of_defined_size(ser_buff_t **ser_buf, int size){
    (*ser_buf) = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));
    (*ser_buf)->b = (char*)calloc(1, size);
    (*ser_buf)->size = size;
    (*ser_buf)->next = 0; 
}

void serialize_data(ser_buff_t *buff, char *obj, int nbytes){
    int available_size = buff->size - buff->next;
    char isResize = 0;
    
    while (available_size < nbytes) {
	buff->size = buff->size * 2;
	available_size = buff->size - buff->next;
	isResize = 1;
    }

    if (isResize == 0) {
	memcpy((char*)buff->b + buff->next, obj, nbytes);
	buff->next += nbytes;
	return;
    }

    // resize the buffer
    buff->b = realloc(buff->b, buff->size);
    memcpy((char*)buff->b + buff->next, obj, nbytes);
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

void init_serialized_buffer_of_defined_size(ser_buff_t **buff, int size);

void serialize_data(ser_buff_t *buff, char *obj, int nbytes);

void de_serialize_data(char* dest, ser_buff_t *buff, int size);

void free_serialized_buffer(ser_buff_t *buff);

void reset_serialize_buffer(ser_buff_t *buff);

void serialize_buffer_skip(ser_buff_t *buff, int jump);

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

==> serialize_person1.c <==
#include "person1.h"

void serialize_person_t_wrapper(void* obj, ser_buff_t *buff){
    serialize_person_t(obj, buff);
}

void* de_serialize_person_t_wrapper(ser_buff_t* buff){
    de_serialize_person_t(buff);
}

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

==> serialize_person2.c <==
#include "person2.h"

void serialize_person_t_wrapper(void* obj, ser_buff_t *buff){
    serialize_person_t(obj, buff);
}

void* de_serialize_person_t_wrapper(ser_buff_t* buff){
    de_serialize_person_t(buff);
}

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

==> serialize_person.c <==
#include "person.h"

void serialize_person_t_wrapper(void* obj, ser_buff_t *buff){
    serialize_person_t(obj, buff);
}

void* de_serialize_person_t_wrapper(ser_buff_t* buff){
    de_serialize_person_t(buff);
}

void serialize_person_t(person_t* obj, ser_buff_t *buff){
    SENTINEL_INSERTION_CODE 

    serialize_data(buff, (char*)obj->name, 30);
    serialize_data(buff, (char*)&obj->age, sizeof(int));
    serialize_data(buff, (char*)&obj->weight, sizeof(int));
}

person_t* de_serialize_person_t(ser_buff_t* buff) {
    SENTINEL_DETECTION_CODE
    
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

==> shm_demo.c <==
#include <stdio.h>
#include <memory.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int create_and_write_shared_memory(char * mmap_key, char *value, unsigned int size){
    int shm_fd;
    
    /*Create a shared memory object in kernel space of size zero bytes. If shared memory
     *already exists it will truncate to zero bytes again*/ 
    shm_fd = shm_open(mmap_key, O_CREAT | O_RDWR | O_TRUNC, 0660); 

    if (shm_fd < 0) {
	printf("falure on shm_open on shm_fd, errcode = %s\n", strerror(errno));
	return -1;
    }

    if (ftruncate(shm_fd, size) == -1) { //resizes shared memory using ftruncate() process call
	printf("Error on truncate to allocate size of shared memory region\n");
	return -1;
    }

    /*Now map the shared memory in kernel space into process's virtual address space*/
    void *shm_reg = mmap(NULL,	//specifies memory base address, if NULL let kernel choose to return  base address for memory  
		size,		//sizeof the shared memory to map to virtual address space of the process
		PROT_READ | PROT_WRITE,	//shared memory is read and writable
		MAP_SHARED,	//shared memory is accessible
		shm_fd,		//file descriptor of the shared memory
		0);		//offset from the base address of the physical/shared memory to be mapped

    /* shm_reg is the address in process's Virtual Address Space, just like any other address.
     * The Linux paging mechanism maps this address to the starting point of the shared memory region
     * in kernel space. Any operation performed by process on shm_reg address is actually the operation
     * performed in shared memory which resides in kernel.*/
     
    memset(shm_reg, 0, size); 	//
    memcpy(shm_reg, value, size);
    munmap(shm_reg, size); 	//destroys mapping to shared memory
    /*Reader process will not be able to read if writer unlink the name below*/
    //shm_unlink(mmap_key);
    close(shm_fd);
    return size;
}

int read_from_shared_memory(char *mmap_key, char* buffer, unsigned int buff_size, unsigned int bytes_to_read){
    int shm_fd = 0, rc = 0;

    shm_fd = shm_open(mmap_key, O_CREAT | O_RDONLY, 0660);

    if (shm_fd < 0) {
	printf("failure on shm_open on shm_fd, errcode = %s\n", strerror(errno));
	return -1;
    }

    void *shm_reg = mmap(NULL, bytes_to_read, PROT_READ, MAP_SHARED, shm_fd, 0);
    
    if(shm_reg == MAP_FAILED){
	printf("Error on mapping\n");
	return -1;
    }

    memcpy(buffer, shm_reg, bytes_to_read);
    rc = munmap(shm_reg, bytes_to_read);

    if(rc < 0){
	printf("munmap failed.\n");
	return -1;
    }

    close(shm_fd);
    return bytes_to_read; //Return the number of bytes read
}

==> signals1.c <==
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signalcatch_func(){
    printf("Signal caught\n");
}

int main(int argc, char **argv){
    void (*ret)(int);

    ret = signal(SIGINT, signalcatch_func);

    if (ret == SIG_ERR){
	printf("Error: unable to set signal_handler\n");
	exit(0);
    }

    int ret2;
    ret2 = raise(SIGINT);

    if (ret2 != 0){
	printf("Error: unable to raise SIGINT\n");
	exit(0);
    }

    printf("Bye Bye!\n");
    return 0;
}

==> signals.c <==
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void ctrlC_signal_handler(int sig){
    printf("Ctrl-C pressed.\n");
    printf("Bye Bye \n");
    exit(0);
}

static void abort_signal_handler(int sig){
    printf("Abort signal raised.\n");
    printf("Bye Bye \n");
    exit(0);
}

int main(int argc, char **argv){
    signal(SIGINT, ctrlC_signal_handler);
    signal(SIGABRT, abort_signal_handler);
    char ch;
    printf("Abort Process (y/n)?\n");
    scanf("%c", &ch);

    //raise(SIGABRT);
    if (ch == 'y')
	abort();  

    return 0;
}

==> stubs-32.h <==
/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */

#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif

#define __stub___kernel_cosl
#define __stub___kernel_sinl
#define __stub___kernel_tanl
#define __stub_chflags
#define __stub_fanotify_init
#define __stub_fanotify_mark
#define __stub_fattach
#define __stub_fchflags
#define __stub_fdetach
#define __stub_gtty
#define __stub_lchmod
#define __stub_prlimit
#define __stub_prlimit64
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty

==> tcpclient.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <arpa/inet.h>
#include "common.h"

/*Server process is running on this port no. Client has to send data to this port no.*/
#define DEST_PORT 3000
#define SERVER_IP_ADDRESS "127.0.0.1"

test_struct_t client_data;
result_struct_t result;

void setup_tcp_communication(){
    /*Setup Initialization*/
    /*Socket handle*/
    int sockfd = 0, sent_recv_bytes = 0, addr_len = 0;

    addr_len = sizeof(struct sockaddr);

    /*to store socket addresses : ip address and port*/
    struct sockaddr_in dest;

    /*Step 2: specify server information*/
    /*Ipv4 sockets, for IPv6: AF_INET6*/
    dest.sin_family = AF_INET;
    dest.sin_port = DEST_PORT;
    dest.sin_addr.s_addr= inet_addr("127.0.0.1");

    //struct hostent host = (struct hostent*)gethostbyname(SERVER_IP_ADDRESS);
    //dest.sin_addr = *((struct in_addr*)host->h_addr);
   
    /*Step 3: Create a TCP socket*/
    /*Create a socket finally. socket() is a system call which asks for three parameters*/
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  //(AF_INET, SOCK_DGRAM, IPPROTO_UDP) for UDP transport
    connect(sockfd, (struct sockaddr*)&dest, sizeof(struct sockaddr));

    /*Step 4: get the data to the server
     *Our client is now ready to send data to the server. sendto() sends data to Server*/

    while(1){
	/*prompt the user to enter data*/
	printf("Enter a : ?\n");
	scanf("%u", &client_data.a);
	printf("Enter b : ?\n");
	scanf("%u", &client_data.b);

	/*step 5: send the data to server*/
	sent_recv_bytes = sendto(sockfd, &client_data, sizeof(test_struct_t), 0, (struct sockaddr*)&dest, sizeof(struct sockaddr));
	
 	printf("No of bytes sent = %d\n", sent_recv_bytes);
	/*step 6: client also wants a reply from server after sending data.*/

	/*recvfrom() is a blocking system call, meaning the client program will not run past this point until data arrives from the server*/
	sent_recv_bytes = recvfrom(sockfd, (char*)&result, sizeof(result_struct_t), 0, (struct sockaddr*)&dest, &addr_len);

	printf("No of bytes received = %d\n", sent_recv_bytes);
	printf("Result received = %u\n", result.c);
	/*Step 7: Client would want to send data to the server again goes to step 4*/	 
    } 
}

int main(int argc, char **argv){
    setup_tcp_communication();
    printf("application quits\n");
    return 0;

}

==> tcpserver.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <arpa/inet.h>
#include "common.h"

/*Server process is running on this port no. Client has to send data to this port no.*/
#define SERVER_PORT 3000

test_struct_t test_struct;
result_struct_t res_struct;
char data_buffer[1024];

void setup_tcp_server_communication(){
    /*Step 1 : Initialization*/
    /*Socket handle and other variables*/
    /*Master socket file descriptor, used to accep new client connection only, no data exchange*/
    int master_sock_tcp_fd = 0, sent_recv_bytes = 0, addr_len = 0, opt = 1;
 
    /*Client specific communication socket file descriptor
     *used for only data exchange/communnication between lient and server*/
    int comm_socket_fd = 0;

    /* Set of file descriptors on which select() polls. Select() unblocks whenever data arrives on
     *  any fd present in this set*/
    fd_set readfds;   
    
    /*variables to hold server information*/
    struct sockaddr_in client_addr, server_addr;

    /*Step 2: tcp master socket creation*/
    if ((master_sock_tcp_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
	printf("Socket creation failed.\n");
	exit(1);
    }

    /*Step 3: specify server information*/
    server_addr.sin_family = AF_INET; /*This socket will process only IPv4 network packets*/
    server_addr.sin_port = SERVER_PORT; /*Server will process any data arriving on port no. 2000*/

    /*s_addr = 232249957; //( = 192.168.56.101); Server's IP Address
     *means, Linux will send all data whose destination address = address of any local interface
     *of this machine, in this case it is 192.168.56.101, INADDR_ANY means any ip interface.
     * */
    server_addr.sin_addr.s_addr = INADDR_ANY;

    addr_len = sizeof(struct sockaddr);
    
    /*Bind the server. Binding means, we are telling kernel(OS) that any data  
     *you receive with dest ip address = 127.0.0.1, and tcp_port no = 2000, please send that data to this process 
     *bind() is a mechanism to tell OS what kind of data server process is interested in to receive. Remember, server machine
     *can rum multiple server processes to process different data, and sevice different clients. Note that bind() is used on
     *server side, not client side
     * */

    if (bind(master_sock_tcp_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1){
	printf("socket bind failed\n");
	exit(1);
    }

    /*Step 4 : Tell the Linux OS to maintain the queue of max length
     *to queue incoming connections*/
    if (listen(master_sock_tcp_fd, 5) < 0){
	printf("listen failed.\n");
	exit(1);
    }

    /*Server infinite loop for servicing client*/
    while(1){
	/*Step 5:Initialize and fill readfds*/
	FD_ZERO(&readfds);	//Initialize file descriptor set, FD_ZERO & FD_SET standard macro provided y C-Library
	FD_SET(master_sock_tcp_fd, &readfds);	//Add the socket to this set on which our server is running

	printf("Blocked on select system call...\n");

        /*Step 6: awaiting incoming client connection*/
	/*state Machine state 1 */

	/*Call the select system call, server process blocks here. Linux OS keeps this process blocked until the data
         *arrives on an of the file descriptors in the fd_set 'readfds'*/
	select(master_sock_tcp_fd + 1, &readfds, NULL, NULL, NULL); //first argument in select call should be max file descriptor + 1, but this is simple example

	/*Some data on some fd present in set has arrived, Now check on which file descriptor the data arives, and process accordingly.*/
	if (FD_ISSET(master_sock_tcp_fd, &readfds)){
	    /*Data arrives on clients socket only when new client connects with the server (that is, 'connect' call is invoked on the client side)*/
	    printf("New connection received, accept the connection. Client and server performs TCP 3-Way handshake at this point.\n");

	    /*step 7 : accept() returns a new temporary file descriptor(fd). Server uses this comm_socket_fd for the res of the life
 	     *of connection with this client to send and receive messages. Master socket is only used for accepting a new client's connection
	     *and not for data exchange with any client*/
	    /*state Machine state 2 */
	    comm_socket_fd = accept(master_sock_tcp_fd, (struct sockadddr*)&client_addr, (socklen_t*)&addr_len);

	    if (comm_socket_fd < 0){
		/*if accept failed to return a valid file descriptor, display message and exit*/
		printf("accept error, error: %s\n", strerror(errno));
		exit(1);
	    }	    

	    printf("Connection accepted from client : %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	    while(1){
		printf("Server ready to service client messages.\n");
		/*Drain to store client info (ip and port) when data arrives from client, sometimes, 
 		 * server would want to find the identity of the client sending messages*/
		memset(data_buffer, 0, sizeof(data_buffer));
		
		/*Step 8: Server receiving the data from client. Client IP and PORT no will be stored in client_addr
		 *by the kernel. Server will use this client_addr info to reply back to the client*/

		/*Like in client case, this is also a blocking system call, meaning, server process halts here until 
		 *data arrives on this comm_socket_fd from client whose connection request has been accepted via accept()*/

		/*state Machine state 3*/   
		sent_recv_bytes = recvfrom(comm_socket_fd, (char*)data_buffer, sizeof(data_buffer), 0, (struct sockaddr*)&client_addr, &addr_len);
  
		/*state Machine state 4*/
		printf("Server received %d bytes from client %s:%u\n", sent_recv_bytes, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 

		if (sent_recv_bytes == 0){
		    close(comm_socket_fd);
		    break; //goto Step 5
   		}

		test_struct_t* client_data = (test_struct_t*) data_buffer;

		/*If the client sends a special message to the server , then server close the client connection forever.*/
		/*Step 9*/
		if (client_data->a == 0 && client_data->b == 0){
		    close(comm_socket_fd);
		    printf("Server closes connection with  client %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 
		    /*Goto state machine State 1*/
		    break; /*Get out of inner while loop, server is done with this client, time to check for new connection request by executing select()*/
		}
		
		result_struct_t result;
		result.c = client_data->a + client_data->b;

		/*Server replying back to client now*/
		sent_recv_bytes = sendto(comm_socket_fd, (char*)&result, sizeof(result_struct_t), 0, (struct sockaddr*)&client_addr, sizeof(struct sockaddr));

		printf("Server sent %d bytes to client %s:%u\n", sent_recv_bytes, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 
		/*Goto state machine State 3*/
	    }
	}
    }/*Step 10: Wait for client request again*/       
}

int main(int argc, char **argv){
    setup_tcp_server_communication();
    return 0;
}

==> test.c <==
#include <stdio.h>

int main(){
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long long));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long double));
    printf("%d\n", sizeof(unsigned int));
    printf("%d\n", sizeof(unsigned char));

    return 0;
}

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

void PreOrderTraversal(tree_node_t *obj){
    printf("%3d", obj->data);
    if (obj->left)
        PreOrderTraversal(obj->left);
    if (obj->right)
        PreOrderTraversal(obj->right);
}

void PostOrderTraversal(tree_node_t *obj){
    if (obj->left)
        PostOrderTraversal(obj->left);
    if (obj->right)
        PostOrderTraversal(obj->right);
    printf("%3d", obj->data);
}

void InOrderTraversal(tree_node_t *obj){
    if (obj->left)
        InOrderTraversal(obj->left);
    printf("%3d", obj->data);
    if (obj->right)
        InOrderTraversal(obj->right);
}

int
main(int argc, char **argv){
    int item;
    tree_t *tree = init_tree();
    srand(time(NULL));

   // add_tree_node_by_value(tree,  1);
    add_tree_node_by_value(tree,  100);
    add_tree_node_by_value(tree,  50);
    add_tree_node_by_value(tree,  10);
    add_tree_node_by_value(tree,  90);
    add_tree_node_by_value(tree,  95);
    add_tree_node_by_value(tree,  99);
   
    for (int i = 0; i < 15; i++) {
        item = rand() % 100;
        i % 50 == 0 ? printf("\n%3d", item) : printf("%3d", item);
        add_tree_node_by_value(tree, item);
    }
    printf("\n");
    iterinOrder(tree->root);
    printf("\nPreOrder: ");
    PreOrderTraversal(tree->root);
    printf("\nPostOrder: ");
    PostOrderTraversal(tree->root);
    printf("\nInOrder: ");
    InOrderTraversal(tree->root);
    printf("\n");
    ser_buff_t *buff = (ser_buff_t*)calloc(1, sizeof(ser_buff_t));

    init_serialized_buffer(&buff);

    serialize_tree_node_t(tree->root, buff);

    int *nptr = NULL;
    serialize_int(nptr, buff);
    tree_t *newtree = de_serialize_tree(buff);

    printf("\n");
    iterinOrder(newtree->root);
    printf("\nPreOrder: ");
    PreOrderTraversal(newtree->root);
    printf("\nPostOrder: ");
    PostOrderTraversal(newtree->root);
    printf("\nInOrder: ");
    InOrderTraversal(newtree->root);
    printf("\n");
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    tree_node_t *treenodeptr = NULL;
//
//    ITERATE_BST_BEGIN(tree, treenodeptr){
//        printf("%3u", treenodeptr->data);
//
//    } ITERATE_BST_END;
//    printf("\n");
    
    return 0;
}

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

==> udpclient.c <==
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT    12345
#define MAXLINE 1024 
  
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 

    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
      
    int n, len; 
      
    sendto(sockfd, (const char *)hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
    printf("Hello message sent.\n"); 
          
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr *) &servaddr, 
                &len); 
    buffer[n] = '\0'; 
    printf("Server : %s\n", buffer); 
  
    close(sockfd); 
    return 0; 
}       

==> writershm.c <==
#include <stdio.h>
#include <string.h>

int create_and_write_shared_memory(char *mmap_key, char* value, unsigned int size);

int main(int argc, char** argv){
    char *key = "/introduction";
    char *intro = "Hello, I am sending a message through shared memory if permissions allow.";
    create_and_write_shared_memory(key, intro, strlen(intro));
    return 0;
}
	
==> brute_force_nn_main.c <==
#include "simple_nn.h"

double weight = 0.5;
double input = 0.5;
double expected_value = 0.8;
double step_amount = 0.001;


int main()
{
    brute_force_learning(input,weight,expected_value,step_amount,1200);
  
    return 0;
}

==> find_error_nn_main.c <==
#include "simple_nn.h"

#define Sad 0.9
#define HAPPY_PREDICTION_IDX 0
#define HEALTH_PREDICTION_IDX    1
#define ACTIVE_PREDICTION_IDX 2
#define INPUT_LENGTH 3
#define HIDDEN_LENGTH 3
#define OUTPUT_LENGTH 3

double temperature[] = { 12,23,50,-10,16 };
double humidity[] = { 60,67,53,55,58 };
double air_quality[] = { 60,47,187,194,84 };
double weight[] = {-2, 2, 1};

double predicted_results[3];
double i_to_h_weights[HIDDEN_LENGTH][INPUT_LENGTH] = {{-2, 9.5, 4.1},    //hidden[0]
                                                      {-0.2, 0.5, 0.1},  //hidden[1]
                                                      {6.2, -3.5, 8.1}}; //hidden[2]

double h_to_o_weights[OUTPUT_LENGTH][HIDDEN_LENGTH] = {{12.8, -7, 3.2},   //happy
                                                      {10.6, 8.5, -3.1}, //healthy
                                                      {5.3, -6.5, -9}};  //active

double expected_values[] = {11000,7500,800};

int main()
{
  printf("%f\r\n", powf(3,2));
  print_statement();
  double input_vector[] = {temperature[0],humidity[0],air_quality[0]};
  hidden_layer_nn(input_vector, INPUT_LENGTH, HIDDEN_LENGTH, predicted_results, OUTPUT_LENGTH, i_to_h_weights, h_to_o_weights);
  printf("The happy prediction is %f: \r\n", predicted_results[HAPPY_PREDICTION_IDX]);
  printf("The happy error is %f:\r\n", find_error_simp(predicted_results[HAPPY_PREDICTION_IDX],expected_values[HAPPY_PREDICTION_IDX]));
  printf("The health prediction is %f: \r\n", predicted_results[HEALTH_PREDICTION_IDX]);
  printf("The health error is %f:\r\n", find_error_simp(predicted_results[HEALTH_PREDICTION_IDX],expected_values[HEALTH_PREDICTION_IDX]));
  printf("The active prediction is %f: \r\n", predicted_results[ACTIVE_PREDICTION_IDX]);
  printf("The active error is %f:\r\n", find_error_simp(predicted_results[ACTIVE_PREDICTION_IDX],expected_values[ACTIVE_PREDICTION_IDX]));
  return 0;
}

==> fwd_propgation_main.c <==
#include "simple_n.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_OF_FEATURES 2 //nx values
#define NUM_OF_EXAMPLES 3 //m values
#define NUM_HIDDEN_NODES 3 
#define NUM_OUTPUT_NODES 1 

double raw_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES] = {{2,5,1},  //hours of workout
                                                 {8,5,8}};  //hours of rest

double raw_y[1][NUM_OF_EXAMPLES] = {{200,90,190}}; //muscle gain (g)

double train_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES];
double train_y[1][NUM_OF_EXAMPLES];

double synapse0[NUM_HIDDEN_NODES][NUM_OF_FEATURES];  //input layer to hidden layer weights buffer
double synapse1[NUM_HIDDEN_NODES]; //hidden layer to output layer weights buffer

double train_x_ex1[NUM_OF_FEATURES];
double train_y_ex1;
double z1_ex1[NUM_HIDDEN_NODES];
double a1_ex1[NUM_HIDDEN_NODES];
double z2_ex1;
double yhat_ex1;

int main()
{
    normalize_data_2d(NUM_OF_FEATURES,NUM_OF_EXAMPLES,raw_x,train_x);


    printf("\r\nRaw workout data : \r\n");

    for (int i = 0; i < NUM_OF_FEATURES; i++){
        for (int j = 0; j < NUM_OF_EXAMPLES; j++){
            printf("%f  ", raw_x[i][j]);
        }
        printf("\r\n");
    }

    printf("\r\nNormalized workout data : \r\n");

    for (int i = 0; i < NUM_OF_FEATURES; i++){
        for (int j = 0; j < NUM_OF_EXAMPLES; j++){
            printf("%f  ", train_x[i][j]);
        }
        printf("\r\n");
    }

    weight_random_initialization(NUM_HIDDEN_NODES,NUM_OF_FEATURES,synapse0);
    weight_random_initialization_1d(NUM_HIDDEN_NODES,synapse1);

    printf("\r\nSynapse 0 weights:\r\n");
    for (int i = 0; i < NUM_HIDDEN_NODES; i++){
        for (int j = 0; j < NUM_OF_FEATURES; j++){
            printf("%f  ", synapse0[i][j]);
        }
        printf("\r\n");
    }

    printf("\r\nSynapse 1 weights:\r\n");
    for (int j = 0; j < NUM_HIDDEN_NODES; j++){
        printf("%f  ", synapse1[j]);
    }

    printf("\r\n");
 
    //compute values at node layer
    for (int j = 0; j < NUM_OF_FEATURES; j++){
        train_x_ex1[j] = train_x[j][0]; 
    }

    multiple_input_multiple_output_nn(train_x_ex1,NUM_HIDDEN_NODES,z1_ex1,NUM_OF_FEATURES,synapse0);

    printf("\r\nz1_ex1: %f %f %f \r\n", z1_ex1[0],z1_ex1[1],z1_ex1[2]);

    //compute value at node layer using sigmoid function
    vector_sigmoid(z1_ex1,a1_ex1,NUM_HIDDEN_NODES);

    printf("\r\na1_ex1: %f %f %f \r\n", a1_ex1[0],a1_ex1[1],a1_ex1[2]);

    //compute value at output
    z2_ex1 = multiple_input_single_output(a1_ex1,synapse1,NUM_HIDDEN_NODES);
    printf("\r\nz2_ex1:  %f \r\n", z2_ex1);
    printf("\r\n");

    return 0;
}

==> hello.c <==
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

==> hidden_layer_nn_main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "simple_nn.h"

#define Sad 0.9
#define HAPPY_PREDICTION_IDX 0
#define HEALTHY_PREDICTION_IDX    1
#define ACTIVE_PREDICTION_IDX 2
#define INPUT_LENGTH 3
#define HIDDEN_LENGTH 3
#define OUTPUT_LENGTH 3

double temperature[] = { 12,23,50,-10,16 };
double humidity[] = { 60,67,53,55,58 };
double air_quality[] = { 60,47,187,194,84 };
double weight[] = {-2, 2, 1};

double predicted_results[3];
double i_to_h_weights[HIDDEN_LENGTH][INPUT_LENGTH] = {{-2, 9.5, 4.1},    //hidden[0]
                                                      {-0.2, 0.5, 0.1},  //hidden[1]
                                                      {6.2, -3.5, 8.1}}; //hidden[2]

double h_to_o_weights[OUTPUT_LENGTH][HIDDEN_LENGTH] = {{12.8, -7, 3.2},   //happy
                                                      {10.6, 8.5, -3.1}, //healthy
                                                      {5.3, -6.5, -9}};  //active

int main()
{
    double input_vector[] = {temperature[0],humidity[0],air_quality[0]};
    hidden_layer_nn(input_vector, INPUT_LENGTH, HIDDEN_LENGTH, predicted_results, OUTPUT_LENGTH, i_to_h_weights, h_to_o_weights);
    printf("The happy prediction is %f: \r\n", predicted_results[HAPPY_PREDICTION_IDX]);
    printf("The health prediction is %f: \r\n", predicted_results[HEALTHY_PREDICTION_IDX]);
    printf("The active prediction is %f: \r\n", predicted_results[ACTIVE_PREDICTION_IDX]);
    return 0;
}

==> mimo_nn_main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "simple_nn.h"

#define Sad 0.9
#define HAPPY_PREDICTION_IDX 0
#define HEALTHY_PREDICTION_IDX    1
#define ACTIVE_PREDICTION_IDX 2
#define INPUT_LENGTH 3
#define OUTPUT_LENGTH 3

double temperature[] = { 12,23,50,-10,16 };
double humidity[] = { 60,67,53,55,58 };
double air_quality[] = { 60,47,187,194,84 };
double weight[] = {-2, 2, 1};

double predicted_results[3];
double weights[INPUT_LENGTH][OUTPUT_LENGTH] = {{-2, 9.5, 4.1},    //happy
                                               {-0.2, 0.5, 0.1},  //healthy
                                               {6.2, -3.5, 8.1}}; //active

int main()
{
    double input_vector[] = {temperature[0],humidity[0],air_quality[0]};
    multiple_input_multiple_output_nn(input_vector, INPUT_LENGTH, predicted_results, OUTPUT_LENGTH, weights);
    printf("The happy prediction is %f: \r\n", predicted_results[HAPPY_PREDICTION_IDX]);
    printf("The health prediction is %f: \r\n", predicted_results[HEALTHY_PREDICTION_IDX]);
    printf("The active prediction is %f: \r\n", predicted_results[ACTIVE_PREDICTION_IDX]);
    return 0;
}

==> miso_nn_main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "simple_nn.h"

#define NUM_OF_INPUTS 3

double temperature[] = { 12,23,50,-10,16 };
double humidity[] = { 60,67,53,55,58 };
double air_quality[] = { 60,47,187,194,84 };
double weight[] = {-2, 2, 1};

int main()
{
    double training_ex[] = {temperature[0],humidity[0],air_quality[0]};
    printf("The first predicted value is %f: \r\n", multiple_input_single_output(training_ex,weight,NUM_OF_INPUTS));
    return 0;
}

==> neuralnetwork.c <==
#include "neuralnetwork.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static float act(float a);
static float err(const float a, const float b);
static float toterr(const float * const tg, const float * const o, const int size);
static float pd_err(const float a, const float b);
static float frand();
                                                    //input
static void fwd_prop(NeuralNetworkType nn, const float* const in){ //forward propagation function
    //Hidden layer forward propagation
    for (int i=0;i<nn.nhid;i++){
        float sum = 0.0f;
        for (int j=0;j<nn.nips;j++){
            sum += in[j] * nn.w[i * nn.nips + j]; //nn.w[] = input layer to hidden layer weights           
        }
        //nn.h = hidden layer
        nn.h[i] = act(sum + nn.b[0]);   // act() sigmoid activation function for each hidden neuron, nn.b[0] = bias
    }

    //Output layer forward propagation
    for (int i=0;i<nn.nops;i++){
        float sum = 0.0f;
        for (int j=0;j<nn.nhid;j++){
            sum += nn.h[j] * nn.x[i * nn.nhid + j]; //nn.x[] = hidden layer to output layer weights
        }
        //nn.o = outer layer
        nn.o[i] = act(sum + nn.b[1]);   // act() sigmoid activation function for each outer neuron, nn.b[1] = bias
    }
}

static float act(float a){
    return 1.0f/(1.0f + expf(-a));
}

static float pd_act(float a){ //partial derivative of sigmoid function - needed for back propagation
    return a*(1.0f -a);
}

static void bk_prop(NeuralNetworkType nn, const float* const in, const float* const tg, float rate){
    for (int i = 0; i < nn.nhid; i++){
        float sum = 0.0f;
        for (int j = 0; j < nn.nops; j++){
            const float a = pd_err(nn.o[j], tg[j]);
            const float b = pd_act(nn.o[j]); 

            sum += a * b * nn.x[j * nn.nhid + i];

            nn.x[j * nn.nhid + i] -= rate * a * b * nn.h[i];
        }

        for (int j = 0; j < nn.nips; j++){
            nn.w[i * nn.nips + j] -= rate * sum * pd_act(nn.h[i]) * in[j];
        }
    }
}

static float frand(){
    return rand()/(float)RAND_MAX;
}

static void wbrand(const NeuralNetworkType nn){ //weight+bias random initialization
    for (int i = 0; i < nn.nw; i++){
        nn.w[i] = frand() - 0.5f;
    }

    for (int i=0; i < nn.nb; i++){
        nn.b[i] = frand() - 0.5f;
    }
}

static float err(const float a, const float b){
    return powf(((a-b) * (a-b)),0.5);
}

static float toterr(const float * const tg, const float * const o, const int size){
    float sum = 0.0f;
    for (int i =0; i< size; i++){
        sum += err(tg[i], o[i]);
    }

    return sum;
}

static float pd_err(const float a, const float b){ //partial derivative of error
    return a - b;
}

float* NNPredict(const NeuralNetworkType nn, const float *in){
    fwd_prop(nn, in);
    return nn.o;
}

NeuralNetworkType NNBuild(int nips, int nhid, int nops){
    NeuralNetworkType nn;
    nn.nb = 2;
    nn.nw = nhid * (nips + nops);
    nn.w = (float*)calloc(nn.nw,sizeof(*nn.w));
    nn.x = nn.w + nhid * nips; //nops
    nn.b = (float*)calloc(nn.nb,sizeof(*nn.b));
    nn.h = (float*)calloc(nhid,sizeof(*nn.h));
    nn.o = (float*)calloc(nops,sizeof(*nn.o));
    nn.nhid = nhid;
    nn.nips = nips;
    nn.nops = nops;
    wbrand(nn);

    return nn;
}

float NNTrain(const NeuralNetworkType nn, const float *in, const float *tg, float rate){
    fwd_prop(nn,in);
    bk_prop(nn,in,tg,rate);

    return toterr(tg,nn.o,nn.nops);   
}

void NNSave(const NeuralNetworkType nn, const char *path){
    FILE* const file = fopen(path,"w");
    fprintf(file,"%d %d %d\n",nn.nips, nn.nhid, nn.nops);

    for (int i = 0; i < nn.nb; i++){
        fprintf(file,"%f\n",(double)nn.b[i]);
    }

    for (int i = 0; i < nn.nw; i++){
        fprintf(file,"%f\n",(double)nn.w[i]);
    }

    fclose(file);
}

NeuralNetworkType NNLoad(const char *path){
    FILE* const file = fopen(path,"r");

    int nhid = 0;
    int nips = 0;
    int nops = 0;

    fscanf(file,"%d %d %d\n",&nips, &nhid, &nops);
    const NeuralNetworkType nn = NNBuild(nips,nhid,nops);

    for (int i = 0; i < nn.nb; i++){
        fscanf(file,"%f\n",&nn.b[i]);
    }

    for (int i = 0; i < nn.nw; i++){
        fscanf(file,"%f\n",&nn.w[i]);
    }

    fclose(file);
    return nn;
}

void NNPrint(const float *arr, const int size){
    double max = 0.0f;
    int idx;

    for (int i =0; i < size; i++){
        printf("%f ", (double)arr[i]);

        if (arr[i] > max){
            idx = i;
            max = arr[i];
        }
    }

    printf("\nThe number is :%d\n", idx);
}

void NNFree(const NeuralNetworkType nn){
    free(nn.w);
    free(nn.b);
    free(nn.h);
    free(nn.o);
}


==> neuralnetwork.h <==
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    float *w; //pointer for all weights
    float *x; //pointer for hidden layer to output layer weights
    float *b; //biases
    float *h; //hidden layer
    float *o; //outer layer
    int nb; //number of biases
    int nw; //number of weights
    int nips; //number of inputs
    int nops; //number of outputs
    int nhid; //number of biases
}NeuralNetworkType;

float* NNPredict(const NeuralNetworkType nn, const float *in);

NeuralNetworkType NNBuild(int nips, int nhid, int nops);

float NNTrain(const NeuralNetworkType nn, const float *in, const float *tg, float rate);

void NNSave(const NeuralNetworkType nn, const char *path);

NeuralNetworkType NNLoad(const char *path);

void NNPrint(const float *arr, const int size);

void NNFree(const NeuralNetworkType nn);

==> neuralnetworkinference.c <==
#include "nn.h"
#include "utils.h"

int main(){
    const int nips = 256;
    const int nops =10;

    const Data inference = build("semeion_test.data");
    const NeuralNetworkType loaded_model = NNLoad("mymodel_2.nn");

    const float * const in = inference.in[1];
    const float * const pd = NN.Predict(loaded_model,in);

    const NeuralNetworkType my_loaded_model = NNLoad("mymodel_2.nn");

    for (int i = 0; i < 32; i++){
        const float * const in = test_data.in[i];
        const float * const tg = test_data.tg[i];
    
        const float * const pd = NNPredict(my_loaded_model,in);
    
        NNPrint(tg,test_data.nops);
        NNPrint(pd,test_data.nops);
        printf("\n");
    }

    NNFree(my_loaded_model);
    dfree(data);
    return 0;
}

==> neuralnetworkmain.c <==
#include <stdio.h>
#include <stdlib.h>
#include "neuralnetwork.h"
#include "nn_utils.h"

int main(){
    int nips = 256;
    int nops = 10;

    float rate = 1.0f;
    const float eta = 0.99f;

    int nhid = 28;
    const int iterations = 128;

    const Data data = build("semeion_train.data",nips,nops);

    const NeuralNetworkType nn = NNBuild(nips,nhid,nops);
   
    for (int i=0; i < iterations;i++){
        shuffle(data);
        float error = 0.0f;
        for (int j=0; j < data.rows; j++){
            const float* const in = data.in[j]; 
            const float* const tg = data.tg[j]; 

            error += NNTrain(nn,in,tg,rate);
        }
        printf("Error %.12f :: Learning rate %f\n", (double)error/data.rows, (double)rate);
        rate *= eta;
    }

    NNSave(nn,"mymodel.nn");
    NNFree(nn);

    const NeuralNetworkType my_loaded_model = NNLoad("mymodel.nn");

    for (int i = 0; i < 256; i++){
        const float * const in = data.in[i];
        const float * const tg = data.tg[i];
    
        const float * const pd = NNPredict(my_loaded_model,in);
    
        NNPrint(tg,data.nops);
        NNPrint(pd,data.nops);
        printf("\n");
    }

    NNFree(my_loaded_model);
    dfree(data);


    return 0;
}

==> neuralneworktest.c <==
#include <stdio.h>
#include <stdlib.h>
#include "neuralnetwork.h"
#include "nn_utils.h"

int main(){
    int nips = 256;
    int nops = 10;

    float rate = 1.0f;
    const float eta = 0.99f;

    int nhid = 28;
    const int iterations = 128;

    const Data data = build("semeion_train.data",nips,nops);
    const Data test_data = build("semeion_test.data",nips,nops);

    const NeuralNetworkType nn = NNBuild(nips,nhid,nops);
   
    for (int i=0; i < iterations;i++){
        shuffle(data);
        float error = 0.0f;
        for (int j=0; j < data.rows; j++){
            const float* const in = data.in[j]; 
            const float* const tg = data.tg[j]; 

            error += NNTrain(nn,in,tg,rate);
        }
        printf("Error %.12f :: Learning rate %f\n", (double)error/data.rows, (double)rate);
        rate *= eta;
    }

    NNSave(nn,"mymodel_2.nn");
    NNFree(nn);

    const NeuralNetworkType my_loaded_model = NNLoad("mymodel_2.nn");

    for (int i = 0; i < 32; i++){
        const float * const in = test_data.in[i];
        const float * const tg = test_data.tg[i];
    
        const float * const pd = NNPredict(my_loaded_model,in);
    
        NNPrint(tg,test_data.nops);
        NNPrint(pd,test_data.nops);
        printf("\n");
    }

    NNFree(my_loaded_model);
    dfree(data);

    return 0;
}

==> new.c <==
#include <stdio.h>

int main(){
    char newstring[100];
    //while(1){
	scanf("%s", newstring);
	printf("%s\n", newstring);
    //}

    return 0;
}

==> nn_utils.c <==
#include "nn_utils.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int lns(FILE* const file){
    int ch = EOF;
    int lines = 0;
    int pc = '\n';
    
    while((ch = getc(file)) != EOF){
        if (ch == '\n'){
            lines++;
        }
        pc = ch;
    } 
    
    if (pc != '\n'){
        lines++;
    }
    
    rewind(file);
    return lines;
}

char* readln(FILE* const file){
    int ch = EOF;
    int reads = 0;
    int size = 128;
    char * line = (char*)malloc((size)*sizeof(char));

    while ((ch = getc(file)) != '\n' && ch != EOF){
        line[reads ++] = ch;
        if (reads +1 ==  size){
            line = (char*)realloc((line),(size *=2) * sizeof(char));
            
        }
    }
    
    line[reads] = '\0';
    return line;
}

float** new2d(const int rows, const int cols){
    float **row = (float**)malloc((rows) * sizeof(float*));

    for (int r=0; r < rows; r++){
        row[r] = (float*)malloc((cols) * sizeof(float));    
    }

    return row;
}

Data ndata(const int nips, const int nops, const int rows){
    const Data data = {
        new2d(rows,nips),
        new2d(rows,nops),
        nips,
        nops,
        rows
    };

    return data;
}

void parse(const Data data, const char *line, const int row){
    const int cols = data.nips + data.nops;

    for (int col =0; col < cols; col++){
        //atof() converts ascii to float, strtok(arg,delimiter) string tokenizer seperates sting in deliimiter
        const float val = atof(strtok(col == 0 ? line :NULL," ")); //if col = 0 is start of line and argument is line or is null

        if (col < data.nips){
            data.in[row][col] = val; //input
        }
        else{
            data.tg[row][col - data.nips] = val; //target
        }
    }
}


void dfree(const Data d){
    for (int row = 0; row < d.rows; row++){
        free(d.in[row]);
        free(d.tg[row]); 
    }

    free(d.in);
    free(d.tg);
}

void shuffle(const Data d){
    for (int a = 0; a < d.rows; a++){
        const int b = rand() % d.rows;
        float *ot = d.tg[a];
        float *it = d.in[a];

        d.in[a] = d.in[b];
        d.in[b] = it;

        d.tg[a] = d.tg[b];
        d.tg[b] = ot;
    }
}

Data build(const char *path, const int nips, const int nops){ 
    FILE *file = fopen(path,"r");
    if (file == NULL){
        printf("Could not open %s", path);
        exit(1);
    }
    

    const int rows = lns(file);
    Data data = ndata(nips,nops,rows);
    for (int row = 0; row < rows; row++){
        char *line = readln(file);
        parse(data,line,row);
        free(line); 
    }

    fclose(file);
    return data;
}


==> nn_utils.h <==
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
float **in; //2d array for inputs
float **tg;    //2d array for targets
int nips;      //number of inputs
int nops;      //number of outputs
int rows;      //number of rows

}Data;

char* readLine(FILE* const file);
float** new2d(const int rows, const int cols);
Data ndata(const int nips, const int nops, const int rows);
void parse(const Data data, const char *line, const int row);
void dfree(const Data d);
void shuffle(const Data d);
Data build(const char *path, const int nips, const int nops); 

==> normalization_nn_main.c <==
#include "simple_nn.h"

#define NUM_OF_FEATURES 3 //n values
#define NUM_OF_EXAMPLES 3 //m values

//Hours of workout
double hours_workout[NUM_OF_EXAMPLES] = {2,5,1};
double _hours_workout[NUM_OF_EXAMPLES];

//Hours of rest
double hours_rest[NUM_OF_EXAMPLES] = {8,5,8};
double _hours_rest[NUM_OF_EXAMPLES];

//Muscle workout
double muscle_gain[NUM_OF_EXAMPLES] = {200,90,190};
double _muscle_gain[NUM_OF_EXAMPLES];

int main()
{
    normalize_data(hours_workout,_hours_workout,NUM_OF_EXAMPLES);
    normalize_data(hours_rest,_hours_rest,NUM_OF_EXAMPLES);
    normalize_data(muscle_gain,_muscle_gain,NUM_OF_EXAMPLES);

    printf("\r\nRaw workout data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", hours_workout[i]);
    }

    printf("\r\nNormalized workout data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", _hours_workout[i]);
    }

    printf("\r\nRaw rest data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", hours_rest[i]);
    }

    printf("\r\nNormalized rest data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", _hours_rest[i]);
    }

    printf("\r\nRaw gain data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", muscle_gain[i]);
    }

    printf("\r\nNormalized gain data : \r\n");

    for (int i = 0; i < NUM_OF_EXAMPLES; i++){
        printf("%f  ", _muscle_gain[i]);
    }
    printf("\r\n");
    return 0;
}

==> rand_initialization_nn_main.c <==
#include "simple_nn.h"

#define NUM_OF_FEATURES 2 //n values
#define NUM_OF_EXAMPLES 3 //m values
#define NUM_HIDDEN_NODES 3 
#define NUM_OUTPUT_NODES 1 

//Hours of workout
double hours_workout[NUM_OF_EXAMPLES] = {2,5,1};
double _hours_workout[NUM_OF_EXAMPLES];

//Hours of rest
double hours_rest[NUM_OF_EXAMPLES] = {8,5,8};
double _hours_rest[NUM_OF_EXAMPLES];

//Muscle workout
double muscle_gain[NUM_OF_EXAMPLES] = {200,90,190};
double _muscle_gain[NUM_OF_EXAMPLES];

double synapse0[NUM_HIDDEN_NODES][NUM_OF_FEATURES];  //input layer to hidden layer weights buffer
double synapse1[NUM_OUTPUT_NODES][NUM_HIDDEN_NODES]; //hidden layer to output layer weights buffer

int main()
{
    weight_random_initialization(NUM_HIDDEN_NODES,NUM_OF_FEATURES,synapse0);
    weight_random_initialization(NUM_OUTPUT_NODES,NUM_HIDDEN_NODES,synapse1);

    printf("\r\nSynapse 0 weights:\r\n");
    for (int i = 0; i < NUM_HIDDEN_NODES; i++){
        for (int j = 0; j < NUM_OF_FEATURES; j++){
            printf("%f  ", synapse0[i][j]);
        }
        printf("\r\n");
    }

    printf("\r\nSynapse 1 weights:\r\n");
    for (int i = 0; i < NUM_OUTPUT_NODES; i++){
        for (int j = 0; j < NUM_HIDDEN_NODES; j++){
            printf("%f  ", synapse1[i][j]);
        }
        printf("\r\n");
    }

    return 0;
}

==> simo_nn_main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "simple_nn.h"

#define Sad 0.9
#define TEMPERATURE_PREDICTION_IDX 0
#define HUMIDITY_PREDICTION_IDX    1
#define AIR_QUALITY_PREDICTION_IDX 2
#define VECTOR_LENGTH 2

double predicted_results[3];
double weights[3] = {-20, 95, 201}; // temp, humid, air quality

int main()
{
    //printf("The first predicted value is %f: \r\n", single_in_single_out(temperature[0],weight));
    single_in_multiple_out_nn(Sad, weights, predicted_results, VECTOR_LENGTH);
    printf("The first predicted temp is %f: \r\n", predicted_results[TEMPERATURE_PREDICTION_IDX]);
    return 0;
}

==> simple_n.c <==
#include "simple_n.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double single_in_single_out(double temperature, double weight){
    return( temperature * weight);
}

double weighted_sum(double *input, double *weight, int LEN){
    double output;

    for (int i=0; i<LEN; i++){
        output += input[i] * weight[i];
    }
    return output;
}

double multiple_input_single_output(double *input, double *weight, int LEN){
    double predicted_value = weighted_sum(input, weight, LEN);

    return predicted_value;
}

void elementwise_multiply(double input_scalar, double *weight_vector, double *output_vector, int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = input_scalar * weight_vector[i];
    }
}

void single_in_multiple_out_nn(double input_scalar, double *weight_vector, double *output_vector, int LEN){
    elementwise_multiply(input_scalar, weight_vector, output_vector, LEN);
}

void matrix_vector_multiply(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                            double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    for (int i = 0; i < OUTPUT_LEN; i++){
        for (int j = 0; j < INPUT_LEN; j++){
            output_vector[i] += input_vector[j] * weight_matrix[i][j];
        }
    }
}

void multiple_input_multiple_output_nn(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                                       double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    matrix_vector_multiply(input_vector, INPUT_LEN, output_vector, OUTPUT_LEN, weight_matrix);
}

void hidden_layer_nn(double *input_vector, int INPUT_LEN, int HIDDEN_LEN, double *output_vector, int OUTPUT_LEN,
                     double i_to_h_weight_matrix[HIDDEN_LEN][INPUT_LEN], double h_to_o_weight_matrix[OUTPUT_LEN][HIDDEN_LEN]){
    double hidden_layer_vector[HIDDEN_LEN];
    matrix_vector_multiply(input_vector, INPUT_LEN, hidden_layer_vector, HIDDEN_LEN, i_to_h_weight_matrix);
    matrix_vector_multiply(hidden_layer_vector, HIDDEN_LEN, output_vector, OUTPUT_LEN, h_to_o_weight_matrix);
}

double power_function(double input, int power){
    double result = 1;
    for (int i = 0; i < power; i++){
        result *= input;
    }
    return result;
}

double find_error(double input, double weight, double expected_value){
    double x = power_function(((input * weight) - expected_value), 2);
    return x;
}

double find_error_simp(double yhat, double y){
    double x = power_function((yhat - y), 2);
    return x;
}

void print_statement(){
    double x = 5.5;
    printf("print statement returns %f\r\n", x);
    printf("%f\r\n", powf(3,2));
}

void brute_force_learning(double input, double weight, double expected_value, double step_amount, int itr){
    double prediction, error;
    double up_prediction, up_error, down_prediction, down_error;
    
    for(int i = 0; i < itr; i++){
        prediction = input * weight;
        error = power_function((prediction - expected_value), 2);
        printf("Prediction: %f Error: %f\r\n", prediction, error);

        up_prediction = input * (weight + step_amount);
        up_error = power_function((up_prediction - expected_value), 2);

        down_prediction = input * (weight - step_amount);
        down_error = power_function((down_prediction - expected_value), 2);
        
        if (down_error < up_error){
            weight = weight - step_amount;
        }
        else if (down_error > up_error){
            weight = weight + step_amount;
        }
    }
} 

void normalize_data(double *input_vector, double *output_vector, int LEN){
    int i; //Find max
    double max = input_vector[0];
    for(int i = 0; i < LEN; i++){
        if (max < input_vector[i]){
            max = input_vector[i];
        }
    }

    for(int i = 0; i < LEN; i++){
        output_vector[i] = input_vector[i] / max;
    }
}

void weight_random_initialization(int HIDDEN_LEN, int INPUT_LEN, double weights_matrix[HIDDEN_LEN][INPUT_LEN]){
    double d_rand;

    srand(2);

    for (int i = 0; i < HIDDEN_LEN; i++){
        for (int j = 0; j < INPUT_LEN; j++){
            d_rand = (rand() % 10);
            d_rand /= 10;

            weights_matrix[i][j] = d_rand;
        }
    }
}

void weight_random_initialization_1d(int LEN, double weights_vector[LEN]){
    double d_rand;

    srand(2);

    for (int i = 0; i < LEN; i++){
        d_rand = (rand() % 10);
        d_rand /= 10;

        weights_vector[i] = d_rand;
    }
}

void normalize_data_2d(int ROW, int COL, double input_matrix[ROW][COL], double output_matrix[ROW][COL]){
    int max = input_matrix[0][0]; // find max
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (max < input_matrix[i][j]){
                max = input_matrix[i][j];
            }
        }
    }

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            output_matrix[i][j] = input_matrix[i][j] / max;
        }
    }
}

double sigmoid(double x){
    double result = 1/ (1 + exp(-x));
    return result;
}

void vector_sigmoid(double *input_vector, double *output_vector, int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = sigmoid(input_vector[i]);
    }
}

==> simple_n.h <==
#ifndef SIMPLE_N_H
#define SIMPLE_N_H
#include "simple_n.h"
#include <stdio.h>
#include <stdlib.h>

double single_in_single_out(double temperature, double weight);

double weighted_sum(double *input, double *weight, int LEN);

double multiple_input_single_output(double *input, double *weight, int LEN);

void elementwise_multiply(double input_scalar, double *weight_vector, double *output_vector, int LEN);

void single_in_multiple_out_nn(double input_scalar, double *weight_vector, double *output_vector, int LEN);

void matrix_vector_multiply(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                            double weight_matrix[OUTPUT_LEN][INPUT_LEN]);

void multiple_input_multiple_output_nn(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                                       double weight_matrix[OUTPUT_LEN][INPUT_LEN]);

void hidden_layer_nn(double *input_vector, int INPUT_LEN, int HIDDEN_LEN, double *output_vector, int OUTPUT_LEN,
                     double i_to_h_weight_matrix[HIDDEN_LEN][INPUT_LEN], double h_to_o_weight_matrix[OUTPUT_LEN][HIDDEN_LEN]);

double power_function(double input, int power);

double find_error(double input, double weight, double expected_value);

double find_error_simp(double yhat, double y);

void print_statement();

void brute_force_learning(double input, double weight, double expected_value, double step_amount, int itr);

void normalize_data(double *input_vector, double *output_vector, int LEN);

void weight_random_initialization(int HIDDEN_LEN, int INPUT_LEN, double weights_matrix[HIDDEN_LEN][INPUT_LEN]);

void weight_random_initialization_1d(int LEN, double weights_vector[LEN]);

void normalize_data_2d(int ROW, int COL, double input_matrix[ROW][COL], double output_matrix[ROW][COL]);

double sigmoid(double x);

void vector_sigmoid(double *input_vector, double *output_vector, int LEN);

#endif

==> simple_nn.h <==
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double single_in_single_out(double temperature, double weight){
    return( temperature * weight);
}

double weighted_sum(double *input, double *weight, int LEN){
    double output;

    for (int i=0; i<LEN; i++){
        output += input[i] * weight[i];
    }
    return output;
}

double multiple_input_single_output(double *input, double *weight, int LEN){
    double predicted_value = weighted_sum(input, weight, LEN);

    return predicted_value;
}

void elementwise_multiply(double input_scalar, double *weight_vector, double *output_vector, int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = input_scalar * weight_vector[i];
    }
}

void single_in_multiple_out_nn(double input_scalar, double *weight_vector, double *output_vector, int LEN){
    elementwise_multiply(input_scalar, weight_vector, output_vector, LEN);
}

void matrix_vector_multiply(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                            double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    for (int i = 0; i < OUTPUT_LEN; i++){
        for (int j = 0; j < INPUT_LEN; j++){
            output_vector[i] += input_vector[j] * weight_matrix[i][j];
        }
    }
}

void multiple_input_multiple_output_nn(double *input_vector, int INPUT_LEN, double *output_vector, int OUTPUT_LEN, 
                                       double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    matrix_vector_multiply(input_vector, INPUT_LEN, output_vector, OUTPUT_LEN, weight_matrix);
}

void hidden_layer_nn(double *input_vector, int INPUT_LEN, int HIDDEN_LEN, double *output_vector, int OUTPUT_LEN,
                     double i_to_h_weight_matrix[HIDDEN_LEN][INPUT_LEN], double h_to_o_weight_matrix[OUTPUT_LEN][HIDDEN_LEN]){
    double hidden_layer_vector[HIDDEN_LEN];
    matrix_vector_multiply(input_vector, INPUT_LEN, hidden_layer_vector, HIDDEN_LEN, i_to_h_weight_matrix);
    matrix_vector_multiply(hidden_layer_vector, HIDDEN_LEN, output_vector, OUTPUT_LEN, h_to_o_weight_matrix);
}

double power_function(double input, int power){
    if (power < 0

    double result = 1;
    for (int i = 0; i < power; i++){
        result *= input;
    }
    return result;
}

double find_error(double input, double weight, double expected_value){
    double x = power_function(((input * weight) - expected_value), 2);
    return x;
}

double find_error_simp(double yhat, double y){
    double x = power_function((yhat - y), 2);
    return x;
}

void print_statement(){
    double x = 5.5;
    printf("print statement returns %f\r\n", x);
    printf("%f\r\n", powf(3,2));
}

void brute_force_learning(double input, double weight, double expected_value, double step_amount, int itr){
    double prediction, error;
    double up_prediction, up_error, down_prediction, down_error;
    
    for(int i = 0; i < itr; i++){
        prediction = input * weight;
        error = power_function((prediction - expected_value), 2);
        printf("Prediction: %f Error: %f\r\n", prediction, error);

        up_prediction = input * (weight + step_amount);
        up_error = power_function((up_prediction - expected_value), 2);

        down_prediction = input * (weight - step_amount);
        down_error = power_function((down_prediction - expected_value), 2);
        
        if (down_error < up_error){
            weight = weight - step_amount;
        }
        else if (down_error > up_error){
            weight = weight + step_amount;
        }
    }
} 

void normalize_data(double *input_vector, double *output_vector, int LEN){
    int i; //Find max
    double max = input_vector[0];
    for(int i = 0; i < LEN; i++){
        if (max < input_vector[i]){
            max = input_vector[i];
        }
    }

    for(int i = 0; i < LEN; i++){
        output_vector[i] = input_vector[i] / max;
    }
}

void weight_random_initialization(int HIDDEN_LEN, int INPUT_LEN, double weights_matrix[HIDDEN_LEN][INPUT_LEN]){
    double d_rand;

    srand(2);

    for (int i = 0; i < HIDDEN_LEN; i++){
        for (int j = 0; j < INPUT_LEN; j++){
            d_rand = (rand() % 10);
            d_rand /= 10;

            weights_matrix[i][j] = d_rand;
        }
    }
}

void weight_random_initialization_1d(int LEN, double weights_vector[LEN]){
    double d_rand;

    srand(2);

    for (int i = 0; i < LEN; i++){
        d_rand = (rand() % 10);
        d_rand /= 10;

        weights_vector[i] = d_rand;
    }
}

void normalize_data_2d(int ROW, int COL, double input_matrix[ROW][COL], double output_matrix[ROW][COL]){
    int max = input_matrix[0][0]; // find max
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (max < input_matrix[i][j]){
                max = input_matrix[i][j];
            }
        }
    }

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            output_matrix[i][j] = input_matrix[i][j] / max;
        }
    }
}

double sigmoid(double x){
    double result = 1/ (1 + exp(-x));
    return result;
}

void vector_sigmoid(double *input_vector, double *output_vector, int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = sigmoid(input_vector[i]);
    }
}

==> simple_nn_main.c <==
#include <stdio.h>
#include <stdlib.h>
#include "simple_nn.h"

double temperature[] = { 12,23,50,-10,16 };
double weight = -2;

int main()
{
    printf("The first predicted value is %f: \r\n", single_in_single_out(temperature[0],weight));
    return 0;
}
==> DiscreteConvolution.c <==
#include "cpimgmodules.h"

struct Mask{
    int Rows;
    int Cols;
    unsigned char *Data;
};

void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf);

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);

int main(){
    const char imgName[] = "TestImages/Images/lena512.bmp";
    const char newImgName[] = "TestImages/Images/lenardiafil.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    struct Mask lpMask; //laplacian mask
    signed char *tmp;
    int i;

    lpMask.Cols = lpMask.Rows = 5;
    lpMask.Data = (unsigned char *)malloc(25 * sizeof(unsigned char));
  
    tmp = (signed char*)lpMask.Data;
    //laplacian mask
   for (i = 0;i < 25; i++){
	*tmp = (i == 13) ? 24 : -1;
	++tmp;
    }
    
    int VER[3][3] = {	{-1,2,-1},
			{-1,2,-1},
			{-1,2,-1}};

    int HOR[3][3] = {	{-1,-1,-1},
			{ 2, 2, 2},
			{-1,-1,-1}};

    int LDIA[3][3]=	{{2,-1,-1},
			{-1,2,-1},
		 	{-1,-1,2}};

		
    int RDIA[3][3]=	{{-1,-1,2},
                         {-1,2,-1},
                         {2,-1,-1}};

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
//    Convolve(imgRows, imgCols, &lpMask, imgBuffer, imgBuffer2); 

    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,RDIA);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);

    return 0;
}

//2D discrete convolution algorithm
void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf){
    long i, j, m, n, idx, jdx;
    int ms, im, val;
    unsigned char *temp;

    for (i=0; i < imgRows; i++){
        for (j=0; j < imgCols; j++){
	    val = 0;
	    for (m = 0; m < myMask->Rows; m++){
		for (n=0; n < myMask->Cols; n++){
		    ms = (signed char)*(myMask->Data + m*myMask->Rows + n);
		    idx = i-m;
		    jdx = j-n;
		    if (idx >= 0 && jdx >= 0){
			im = *(input_buf + idx *imgRows + jdx);
		    }
		    val += ms*im;
		}
	    }
		val = (val > 155) ? 255 : val;
                val = (val < 0) ? 0 : val;
		temp = output_buf + i*imgRows+j;
		*temp = (unsigned char)val;
        }
    }
}

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3])
{
    int x, y, i, j, sum;

    for (y = 1; y < imgRows -1; y++){
	for (x=1; x<imgCols -1; x++){
	    sum=0;
	    for(i = -1; i <=1; i++){
		for(j=-1;j <=1; j++){
		    sum = sum + *(_inputImgData+x+i+(long)(y+j)*imgCols)*MASK[i+1][j+1];
		}
	   }
	   sum = (sum > 255) ? 255 : sum;
	   sum = (sum < 0) ? 0 : sum;
           *(_outputImgData + x + (long)(y*imgCols)) = sum;
	}
    }
}

==> ImageBrightnessCorrection.c <==
#include "cpimgmodules.h"

void correctBrightness(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgRows, int imgCols, int brightness);

int main(){
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];
    const char newImgName[] = "TestImages/Images/lenaedgescleanno.bmp";

    imageReader("TestImages/Images/lenaedges.bmp", &imgWidth, &imgHeight, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    correctBrightness(imgBuffer, imgBuffer2, imgHeight, imgWidth, 100);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgWidth * imgHeight);

    return 0;
}

void correctBrightness(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgRows, int imgCols, int brightness)
{
    int x, y, i;

    for (y =0; y < imgRows; y++)
    {
	for (x=0; x < imgCols; x++)
	{
	   //
	     i = *(_inputImgData + x + y * imgCols);// + brightness;
	    i = (i > 233) ? 255 : 155;
	    //if (i < 200) i = 0;
            *(_outputImgData + x + y * imgCols) = i;
	}
    } 
}

==> ImageRotation.c <==
#include "cpimgmodules.h"

int main(){
    FILE * fIn = fopen("TestImages/Images/cameraman.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/cameraman_rotated.bmp", "wb");
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }     

    imgWidth = *(int*)&imgHeader[18];
    imgHeight = *(int*)&imgHeader[22];
    imgBitDepth = *(short int*)&imgHeader[28];
    int imgSize = imgHeight * imgWidth;

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

    printf("%d %d %d\n", imgWidth, imgHeight, imgBitDepth);

//    if (imgBitDepth <= 8) {
	fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
//    } 

    unsigned char buffer[imgWidth][imgHeight];
    unsigned char out_buffer[imgWidth][imgHeight];

	/*for (int i = 0; i < imgWidth; i++){
	    for (int j = 0; j< imgHeight; j++){
		buffer[i][j] = getc(fIn);
	}}*/ 

    fread(buffer, sizeof(unsigned char), imgSize, fIn);

    printf("Enter rotation direction : \n");
    printf("1 : Rotate right \n");
    printf("2 : Rotate left \n");
    printf("3 : Rotate 180 \n");

   int selected;

   scanf("%d", &selected);
  
   switch(selected){
	case 1:
		for (int i = 0; i < imgWidth; i++){
		    for (int j = 0; j< imgHeight; j++){
			out_buffer[j][imgHeight-1-i] = buffer[i][j];
		}} break;
	case 2: 
		for (int i = 0; i < imgWidth; i++){
		    for (int j = 0; j< imgHeight; j++){
			out_buffer[j][i] = buffer[i][j];
		}} break;
	case 3: 
		for (int i = 0; i < imgWidth; i++){
		    for (int j = 0; j< imgHeight; j++){
			out_buffer[imgWidth - 1 - i][j] = buffer[i][j];
		}} break;
	default:
		break;
	}

    fwrite(out_buffer, sizeof(unsigned char), imgSize, fOut);
	/*for (int i = 0; i < imgWidth; i++){
	    for (int j = 0; j< imgHeight; j++){
		putc(out_buffer[i][j], fOut);
	}} */

    fclose(fOut);
    fclose(fIn);  
 
    return 0;
}



==> NegativeTransformation.c <==
#include "cpimgmodules.h"
#include <malloc.h>

int main(){
    FILE * fIn = fopen("TestImages/Images/lenardia.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/lenardianeg2.bmp", "wb");
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }     

    imgWidth = *(int*)&imgHeader[18];
    imgHeight = *(int*)&imgHeader[22];
    imgBitDepth = *(short int*)&imgHeader[28];
    int imageSize = imgWidth * imgHeight;

    unsigned char* imgData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);
    unsigned char* newImgData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);
    
    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

    if (imgBitDepth <= 8) {
	fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
    }

    fread(imgData, sizeof(unsigned char), imageSize, fIn);

    for (int i = 0; i < imageSize; i++){
        *(newImgData + i) = 255 - *(imgData + i);
        *(newImgData + i) = (*(newImgData + i) > 225) ? 255 : *(newImgData + i);
    }

    fwrite(newImgData, sizeof(unsigned char), imageSize, fOut);

    fclose(fIn);
    fclose(fOut);

    return 0;
}

==> blackandwhite.c <==
#include <stdio.h>
#include <stdlib.h>

#define WHITE 255
#define BLACK 0
#define THRESHOLD 50

int main(){
    FILE* fIn = fopen("TestImages/Images/lighthouse.bmp", "rb");
    FILE* fOut = fopen("TestImages/Images/lighthousebw1.bmp", "wb");
    
    char imgHeader[54];
    char colorTable[1024];

    if (fIn == NULL)
	puts("Unable to open image");

    for (int i = 0; i < 54; i++)
	imgHeader[i] = getc(fIn);

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

    int height = *(int*)&imgHeader[22];
    int width = *(int*)&imgHeader[18];
    short int bitDepth = *(short int*)&imgHeader[28];

    if(bitDepth <= 8){
	fread(colorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
    }

    char buffer[height*width];

    fread(buffer, sizeof(unsigned char), height*width, fIn);
    
    for (int i = 0; i < (height * width); i++){
       buffer[i] = (buffer[i] > THRESHOLD) ? WHITE : BLACK;
   }

   fwrite(buffer, sizeof(unsigned char), height * width, fOut);

   printf("Success !!");

   fclose(fIn);
   fclose(fOut);

    return 0;
}


==> blurbw.c <==
#include "cpimgmodules.h"
#include <malloc.h>

//uses blur kernel filter
int main(){
    FILE * fIn = fopen("TestImages/Images/girlface_blur1.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/girlface_blur2.bmp", "wb");
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }     

    imgCols = *(int*)&imgHeader[18];
    imgRows = *(int*)&imgHeader[22];
    imgBitDepth = *(int*)&imgHeader[28];
    
    unsigned char buffer[imgCols * imgRows];
    unsigned char output_buffer[imgCols * imgRows];

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);
    
  //  if (imgBitDepth <= 8){
	fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
    //}

    //fread(buffer, sizeof(unsigned char), imgCols * imgRows * 3, fIn);
    for (int x = 0; x < imgRows * imgCols; x++) {
	buffer[x] = getc(fIn);
   }


    float v = 1.0 /9.0; 
    float kernel[3][3];
    for (int i = 0; i< 3; i++){
	for (int j = 0; j < 3; j++){
	    kernel[i][j] = v;
    }}

    for (int x = 1; x < imgRows; x++){
	for (int y = 1; y < imgCols; y++){
	    float sum0 = 0.0;
	    for (int i = -1; i <=1; i++){
		for (int j = -1; j <= 1; j++){
		    sum0 = sum0 + (float)kernel[i+1][j+1] * buffer[(i+x)*imgCols+j+y];
		}
	   }
	   output_buffer[(x) * imgCols + (y)] = sum0;
           //printf("%f %f %f\n", sum0, sum1, sum2); 
	   //printf("%d %d %d\n", output_buffer[(x) * imgCols + (y)][0], output_buffer[(x) * imgCols + (y)][1], output_buffer[(x) * imgCols + (y)][2]);
    }}   

    for (int i = 0; i < imgCols * imgRows; i++){
        putc(output_buffer[i], fOut);
    }

    fclose(fIn);
    fclose(fOut);
    return 0;
}

==> blurimage.c <==
#include "cpimgmodules.h"
#include <malloc.h>

//uses blur kernel filter
int main(){
    FILE * fIn = fopen("TestImages/Images/me_.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/me_blur.bmp", "wb");
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }     

    imgCols = *(int*)&imgHeader[18];
    imgRows = *(int*)&imgHeader[22];
    imgBitDepth = *(int*)&imgHeader[28];
    
    unsigned char buffer[imgCols * imgRows][3];
    unsigned char output_buffer[imgCols * imgRows][3];

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);
    
  //  if (imgBitDepth <= 8){
	fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
    //}

    //fread(buffer, sizeof(unsigned char), imgCols * imgRows * 3, fIn);
    for (int x = 0; x < imgRows * imgCols; x++) {
	buffer[x][0] = getc(fIn);
	buffer[x][1] = getc(fIn);
	buffer[x][2] = getc(fIn);
   }


    float v = 1.0 /9.0; 
    float kernel[3][3];
    for (int i = 0; i< 3; i++){
	for (int j = 0; j < 3; j++){
	    kernel[i][j] = v;
    }}

    for (int x = 1; x < imgRows; x++){
	for (int y = 1; y < imgCols; y++){
	    float sum0 = 0.0;
	    float sum1 = 0.0;
	    float sum2 = 0.0;
	    for (int i = -1; i <=1; i++){
		for (int j = -1; j <= 1; j++){
		    sum0 = sum0 + (float)kernel[i+1][j+1] * buffer[(i+x)*imgCols+j+y][0];
		    sum1 = sum1 + (float)kernel[i+1][j+1] * buffer[(i+x)*imgCols+j+y][1];
		    sum2 = sum2 + (float)kernel[i+1][j+1] * buffer[(i+x)*imgCols+j+y][2];
		}
	   }
	   output_buffer[(x) * imgCols + (y)][0] = sum0;
	   output_buffer[(x) * imgCols + (y)][1] = sum1;
	   output_buffer[(x) * imgCols + (y)][2] = sum2;
           //printf("%f %f %f\n", sum0, sum1, sum2); 
	   //printf("%d %d %d\n", output_buffer[(x) * imgCols + (y)][0], output_buffer[(x) * imgCols + (y)][1], output_buffer[(x) * imgCols + (y)][2]);
    }}   

    for (int i = 0; i < imgCols * imgRows; i++){
        putc(output_buffer[i][0], fOut);
        putc(output_buffer[i][1], fOut);
        putc(output_buffer[i][2], fOut);
    }

    fclose(fIn);
    fclose(fOut);
    return 0;
}

==> colorbrightness.c <==
#include <stdio.h>
#include <stdlib.h>

#define BRIGHTNESS_FACTOR 100
#define MAX_COLOR 255

int main(){
    FILE* fIn = fopen("new.bmp", "rb");
    FILE* fOut = fopen("new_bright.bmp", "wb");
   
    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if (fIn == NULL)
	puts("File did not open");

    for (int i = 0; i < 54; i++)
	imgHeader[i] = getc(fIn);

    int width, height, bitDepth; 

    width = *(int*)&imgHeader[18];
    height = *(int*)&imgHeader[22];
    bitDepth = *(short int*)&imgHeader[28];

     fwrite(imgHeader, sizeof(unsigned char), 54, fOut);
     //if (bitDepth <= 8){
	fread(colorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
     //}

    unsigned char buffer[3];
   
   // fread(buffer, sizeof(unsigned char), width * height, fIn);
    
    int temp = 0;
    for (int i = 0; i < (width * height); i++){
        for (int j = 0; j < 3; j++){
            buffer[j] = getc(fIn);
            //buffer[1] = getc(fIn);
            //buffer[2] = getc(fIn);
            //temp = ((buffer[0]*0.3)+(buffer[1]*0.59)+(buffer[2]*0.11));
            temp = buffer[j] + BRIGHTNESS_FACTOR;
            buffer[j] = (temp > MAX_COLOR) ? MAX_COLOR : temp;
            putc(buffer[j], fOut);
            //putc(temp, fOut);
            //putc(temp, fOut);
            //putc(temp, fOut);
            //putc(temp, fOut);*/
            //printf("%d ", buffer[i][j]);
       }
       // printf("\n");
    } 
   
    //fwrite(buffer, sizeof(unsigned char), width * height, fOut);
    
    fclose(fIn);
    fclose(fOut);

    puts("Success !!");
    return 0;
}

==> computehistogram.c <==
#include "cpimgmodules.h"

float IMG_HIST[255];

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[]);

void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols);

int main(){
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    const char imgName[] = "lena512.bmp";
    const char newImgName[] = "lena_5.bmp";

    imageReader(imgName, &imgWidth, &imgHeight, &imgBitDepth, &imgHeader[0], &imgColorTable[0], &imgBuffer[0]);
    ImgHistogram(&imgBuffer[0],imgHeight,imgWidth, &IMG_HIST[0]);
  //  ImgHistogramEqualization(&imgBuffer[0], &imgBuffer2[0], imgHeight, imgWidth);
  //  ImgHistogramEqualization(&imgBuffer2[0], &imgBuffer2[0], imgHeight, imgWidth);
   //imageWriterColor(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    //imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    return 0;
}

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[])
{
    FILE* fptr;
    fptr = fopen("image_hist.txt", "w");
    int x, y, i, j;
    long int ihist[255];
    long int sum;

    for(i=0; i<=255;i++)
    {
        ihist[i] = 0;
    }

    sum =0;
    for (y=0; y <= imgRows; y++)
    {
	for (x=0; x < imgCols; x++){
	    j = *(_imgData+x+y*imgCols);
	    ihist[j] = ihist[j] + 1;
	    sum = sum + 1;
	} 
    }

    for (i = 0; i < 255; i++)
    {
        hist[i] = (float)ihist[i]/(float)sum; 
    }

    for (int i =0; i < 255; i++)
    {
        fprintf(fptr, "\n%f",hist[i]);
    }

    fclose(fptr);
}
/*
void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols)
{
    FILE* fptr;
    fptr = fopen("eq_hist.txt", "w");
    int x, y, i,j;
    float sum;

   float histeq[256]; 
   float hist[256]; 

   ImgHistogram(&_inputImgData[0], imgRows, imgCols, &hist[0]);

   for (i = 0; i < 255; i++)
   {
	sum = 0.0;
	for (j = 0; j <= i; j++)
	{
	    sum = sum + hist[j];
	}
	histeq[i] = (int)(255*sum+0.5);
   }

    for (int i =0; i < 255; i++)
    {
	fprintf(fptr, "\n%f",histeq[i]);
    }

   fclose(fptr);
   for  (y = 0; y < imgRows; y++)
   {
	for (x = 0; x < imgCols; x++)
	{
	    *(_outputImgData+x+y*imgCols) = histeq[*(_inputImgData+x+y*imgCols)];
	}
   }
}*/



==> copyimagemodular.c <==
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024
#define CUSTOM_IMG_SIZE 1024*1024

void imageReader(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitdepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf);

void imageWriter(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area);

int main(){
    int imgWidth, imgHeight, imgBitDepth, imgArea;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];


   const char imgName[] = "TestImages/Images/cameraman.bmp";
   const char newImgName[] = "TestImages/Images/camraman_new.bmp";

   imageReader(imgName, &imgWidth, &imgHeight, &imgBitDepth, &imgHeader[0], &imgColorTable[0], &imgBuffer[0]);

   imgArea = imgWidth * imgHeight;
   imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth, imgArea);  

   printf("Success!");



   return 0;
}

void imageReader(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf)
{
    int i;
    FILE* streamIn;
   streamIn = fopen(imgName, "rb");

    if (streamIn == (FILE*)0)
	printf("Unable to open image\n");

    for (i = 0; i <  54; i++)
	_header[i] = getc(streamIn);
   
    *_width  = *(int*)&_header[18];
    *_height  = *(int*)&_header[22];
    *_bitDepth = *(short int*)&_header[28];
    
    if (*_bitDepth <= 8)
	fread(_colorTable, sizeof(unsigned char), 1024, streamIn);

    fread(_buf, sizeof(unsigned char), *_width * *_height, streamIn);

    fclose(streamIn);
}

void imageWriter(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area)
{
    FILE *fo  = fopen(imgName, "wb");
    fwrite(header, sizeof(unsigned char), 108, fo);

    if (bitDepth <= 8)
	fwrite(colorTable, sizeof(unsigned char), 1024, fo);

    fwrite(buf, sizeof(unsigned char), area, fo);

    fclose(fo);
}

==> cpimgmod.c <==
#include "cpimgmodules.h"

/*void imageReader(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf)
{
    int i;
    FILE* streamIn;
   streamIn = fopen(imgName, "rb");

    if (streamIn == (FILE*)0)
	printf("Unable to open image\n");

    for (i = 0; i <  54; i++)
	_header[i] = getc(streamIn);
   
    *_width  = *(int*)&_header[18];
    *_height  = *(int*)&_header[22];
    *_bitDepth = *(short int*)&_header[28];
    
    if (*_bitDepth <= 8)
	fread(_colorTable, sizeof(unsigned char), 1024, streamIn);

    fread(_buf, sizeof(unsigned char), *_width * *_height, streamIn);

    fclose(streamIn);
}*/


void  imageReader(const char *imgName,
                  int *_height,
                  int *_width,
                  int *_bitDepth,
                  unsigned char *_header,
                  unsigned char *_colorTable,
                  unsigned char *_buf
                  )
{
    int i;
    FILE *streamIn;
    streamIn = fopen(imgName,"rb");

    if(streamIn ==(FILE *)0)
    {

        printf("Unable to read image \n");
    }

    for(i =0;i<54;i++)
    {
        _header[i] = getc(streamIn);
    }

    *_width = *(int *)&_header[18];
    *_height = *(int *)&_header[22];
    *_bitDepth = *(int *)&_header[28];

    if(*_bitDepth <=8)
    {
        fread(_colorTable,sizeof(unsigned char),1024,streamIn);
    }

    fread(_buf,sizeof(unsigned char),CUSTOM_IMG_SIZE,streamIn);

    fclose(streamIn);
}




/*void imageWriter(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area)
{
    FILE *fo  = fopen(imgName, "wb");
    fwrite(header, sizeof(unsigned char), 54, fo);

    if (bitDepth <= 8)
	fwrite(colorTable, sizeof(unsigned char), 1024, fo);

    fwrite(buf, sizeof(unsigned char), area, fo);

    fclose(fo);
}*/


void imageWriter(const char *imgName,
                 unsigned char *header,
                 unsigned char *colorTable,
                 unsigned char *buf,
                 int bitDepth,
                 int area)
   {
     FILE *fo = fopen(imgName,"wb");
     fwrite(header,sizeof(unsigned char),54,fo);
     if(bitDepth <=8)
     {
         fwrite(colorTable,sizeof(unsigned char),1024,fo);
     }
     fwrite(buf,sizeof(unsigned char),CUSTOM_IMG_SIZE, fo);
     fclose(fo);

   }


void imageReaderColor(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf)
{
    int i;
    FILE* streamIn;
    streamIn = fopen(imgName, "rb");

    if (streamIn == (FILE*)0)
	printf("Unable to open image\n");

    for (i = 0; i <  54; i++)
	_header[i] = getc(streamIn);
   
    *_width  = *(int*)&_header[18];
    *_height  = *(int*)&_header[22];
    *_bitDepth = *(short int*)&_header[28];
    
    fread(_colorTable, sizeof(unsigned char), 1024, streamIn);

    int temp = 0;
    for (int i = 0; i < (*_width * *_height); i++){
        for (int j = 0; j < 3; j++){
            _buf[j] = getc(streamIn);
	}
    }

  //  fread(_buf, sizeof(unsigned char), *_width * *_height * 3, streamIn);

    fclose(streamIn);
}

void imageWriterColor(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area)
{
    FILE *fo  = fopen(imgName, "wb");
    fwrite(header, sizeof(unsigned char), 54, fo);

    fwrite(colorTable, sizeof(unsigned char), 1024, fo);

    for (int i = 0; i < area; i++){
        for (int j = 0; j < 3; j++){
            putc(buf[j], fo);
	}
    }

    fclose(fo);
}

==> cpimgmodules.c <==
#include "cpimgmodules.h"

void imageReader(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf)
{
    int i;
    FILE* streamIn;
   streamIn = fopen(imgName, "rb");

    if (streamIn == (FILE*)0)
	printf("Unable to open image\n");

    for (i = 0; i <  54; i++)
	_header[i] = getc(streamIn);
   
    *_width  = *(int*)&_header[18];
    *_height  = *(int*)&_header[22];
    *_bitDepth = *(short int*)&_header[28];
    
    if (*_bitDepth <= 8)
	fread(_colorTable, sizeof(unsigned char), 1024, streamIn);

    fread(_buf, sizeof(unsigned char), *_width * *_height, streamIn);

    fclose(streamIn);
}

void imageWriter(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area)
{
    FILE *fo  = fopen(imgName, "wb");
    fwrite(header, sizeof(unsigned char), 54, fo);

    if (bitDepth <= 8)
	fwrite(colorTable, sizeof(unsigned char), 1024, fo);

    fwrite(buf, sizeof(unsigned char), area, fo);

    fclose(fo);
}

void imageReaderColor(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf)
{
    int i;
    FILE* streamIn;
    streamIn = fopen(imgName, "rb");

    if (streamIn == (FILE*)0)
	printf("Unable to open image\n");

    for (i = 0; i <  54; i++)
	_header[i] = getc(streamIn);
   
    *_width  = *(int*)&_header[18];
    *_height  = *(int*)&_header[22];
    *_bitDepth = *(short int*)&_header[28];
    
    fread(_colorTable, sizeof(unsigned char), 1024, streamIn);

    int temp = 0;
    for (int i = 0; i < (*_width * *_height); i++){
        for (int j = 0; j < 3; j++){
            _buf[j] = getc(streamIn);
	}
    }

  //  fread(_buf, sizeof(unsigned char), *_width * *_height * 3, streamIn);

    fclose(streamIn);
}

void imageWriterColor(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area)
{
    FILE *fo  = fopen(imgName, "wb");
    fwrite(header, sizeof(unsigned char), 54, fo);

    fwrite(colorTable, sizeof(unsigned char), 1024, fo);

    for (int i = 0; i < area; i++){
        for (int j = 0; j < 3; j++){
            putc(buf[j], fo);
	}
    }

    fclose(fo);
}

==> cpimgmodules.h <==
#ifndef COPY_IMAGE_H
#define COPY_IMAGE_H

#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024
#define CUSTOM_IMG_SIZE 512*512

void imageReader(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitdepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf);

void imageWriter(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area);

void imageReaderColor(const char *imgName, 
		int* _height, 
		int* _width, 
		int* _bitDepth, 
		unsigned char* _header,
		unsigned char* _colorTable,
		unsigned char* _buf);

void imageWriterColor(const char *imgName,
		unsigned char* header,
		unsigned char* colorTable,
		unsigned char* buf,
		int bitDepth,
		int area);

#endif

==> edgebuilding.c <==
#include "cpimgmodules.h"

void correctBrightness(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgRows, int imgCols, int brightness);

int main(){
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader1[BMP_HEADER_SIZE];
    unsigned char imgHeader2[BMP_HEADER_SIZE];
    unsigned char imgHeader3[BMP_HEADER_SIZE];
    unsigned char imgHeader4[BMP_HEADER_SIZE];
    unsigned char imgColorTable1[BMP_COLOR_TABLE_SIZE];
    unsigned char imgColorTable2[BMP_COLOR_TABLE_SIZE];
    unsigned char imgColorTable3[BMP_COLOR_TABLE_SIZE];
    unsigned char imgColorTable4[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer1[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer3[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer4[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer5[CUSTOM_IMG_SIZE];
    const char newImgName1[] = "TestImages/Images/lenahorneg.bmp";
    const char newImgName2[] = "TestImages/Images/lenaverneg.bmp";
    const char newImgName3[] = "TestImages/Images/lenardianeg.bmp";
    const char newImgName4[] = "TestImages/Images/lenaldianeg.bmp";
    const char newImgName5[] = "TestImages/Images/lenaedges.bmp";

    imageReader(newImgName1, &imgWidth, &imgHeight, &imgBitDepth, imgHeader1, imgColorTable1, imgBuffer1);
    imageReader(newImgName2, &imgWidth, &imgHeight, &imgBitDepth, imgHeader2, imgColorTable2, imgBuffer2);
    imageReader(newImgName3, &imgWidth, &imgHeight, &imgBitDepth, imgHeader3, imgColorTable3, imgBuffer3);
    imageReader(newImgName4, &imgWidth, &imgHeight, &imgBitDepth, imgHeader4, imgColorTable4, imgBuffer4);
//    correctBrightness(imgBuffer, imgBuffer2, imgHeight, imgWidth, 100);
    int lowest;
    for (int i = 0; i < CUSTOM_IMG_SIZE; i++){
	lowest = 255;
        lowest = (lowest < imgBuffer1[i]) ? lowest : imgBuffer1[i];
        lowest = (lowest < imgBuffer2[i]) ? lowest : imgBuffer2[i];
        lowest = (lowest < imgBuffer3[i]) ? lowest : imgBuffer3[i];
        lowest = (lowest < imgBuffer4[i]) ? lowest : imgBuffer4[i];
        imgBuffer5[i] = lowest;
    }

    imageWriter(newImgName5, imgHeader1, imgColorTable1, imgBuffer5, imgBitDepth, imgWidth * imgHeight);

    return 0;
}

void correctBrightness(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgRows, int imgCols, int brightness)
{
    int x, y, i;

    for (y =0; y < imgRows; y++)
    {
	for (x=0; x < imgCols; x++)
	{
	    i = *(_inputImgData + x + y * imgCols) + brightness;
	    if (i > 255) i = 255;
	    if (i < 0) i = 0;
            *(_outputImgData + x + y * imgCols) = i;
	}
    } 
}

==> firstimage.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *streamIn = fopen("TestImages/Images/pp2.bmp", "rb");
    FILE *fo = fopen("TestImages/Images/pp2copy.bmp", "wb");

    if (streamIn == (FILE*)0)
    {
        printf("unaboe to open file\n");
    }   

    //image header for bitmap is 54 bytes long
    unsigned char header[54];
    //color table for bitmap is 1024 bytes long
    unsigned char colorTable[1024];

    for (int i = 0; i < 54; i++)
    {
        header[i] = getc(streamIn);
    }

    //reads the width of the image from the image header (4 bytes long)
    int width  = *(int*)&header[18];
    //reads the height of the image from the image header (4 bytes long)
    int height  = *(int*)&header[22];
    //reads the depth of the image from the image header (2 bytes long)
    int bitDepth = *(int*)&header[28];

   //if colorTable existsread  ir in (not all bitmap images have colour tables
   if (bitDepth <= 8)
   {
       fread(colorTable, sizeof(unsigned char), 1024, streamIn);
   }

    //write header data to fo
    fwrite(header, sizeof(unsigned char), 54, fo);
    unsigned char buf[height * width];

   fread(buf, sizeof(unsigned char), (height * width), streamIn);

   if (bitDepth <= 8)
   {
       fwrite(colorTable, sizeof(unsigned char), 1024, fo);
   }

   fwrite(buf, sizeof(unsigned char), (height * width), fo);
   fclose(fo);
   fclose(streamIn);

   printf("Success !\n");
   printf("Width : %d\n", width);
   printf("Height : %d\n", height);
    return 0;
}

==> gray.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fIn = fopen("TestImages/Images/lena_color.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/lena_gray_green.bmp", "wb");

    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if(fIn == NULL)
        printf("Unable to open image\n");

    fread(imgHeader,sizeof(unsigned char),54,fIn);
    fwrite(imgHeader,sizeof(unsigned char),54,fOut);
    
    int height = *(int*)&imgHeader[22];
   int width = *(int*)&imgHeader[18];
   int bitDepth = *(int*)&imgHeader[28];

   int imgSize = height * width;
   unsigned char buffer[imgSize][3]; //stores RGB colour values for each pixel

   if (bitDepth <= 8)
	fread(colorTable, sizeof(unsigned char), 1024, fIn);

   if (bitDepth <= 8)
	fwrite(colorTable, sizeof(unsigned char), 1024, fOut);

   for(int i = 0; i < imgSize; i++){
	buffer[i][0] = getc(fIn);
	buffer[i][1] = getc(fIn);
	buffer[i][2] = getc(fIn);

       //printf("%d %d %d\n", buffer[i][0], buffer[i][1], buffer[i][2]);
       int temp = 0;
       temp = ((buffer[i][0]*0.3)+(buffer[i][1]*0.59)+(buffer[i][2]*0.11));
       //printf("%d %d %d\n\n", temp, temp, temp);
	putc(buffer[i][1], fOut);
	putc(buffer[i][1], fOut);
	putc(buffer[i][1], fOut);
    }

    printf("Succes !!\n");
  
    fclose(fIn);
    fclose(fOut);

    return 0;
}

==> imagebrightness.c <==
#include <stdio.h>
#include <stdlib.h>

#define BRIGHTNESS_FACTOR 50
#define MAX_COLOR 255

int main(){
    FILE* fIn = fopen("TestImages/Images/lena_color.bmp", "rb");
    FILE* fOut = fopen("TestImages/Images/lena_color_bright.bmp", "wb");
   
    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if (fIn == NULL)
	puts("File did not open");

    for (int i = 0; i < 54; i++)
	imgHeader[i] = getc(fIn);

    int width, height, bitDepth; 

    width = *(int*)&imgHeader[18];
    height = *(int*)&imgHeader[22];
    bitDepth = *(short int*)&imgHeader[28];

     fwrite(imgHeader, sizeof(unsigned char), 54, fOut);
     if (bitDepth <= 8){
	fread(colorTable, sizeof(unsigned char), 1024, fIn);
	fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
     }

    unsigned char buffer[width * height];
   
    fread(buffer, sizeof(unsigned char), width * height, fIn);
    
    int temp;
    for (int i = 0; i < (width * height); i++){
        temp = buffer[i] + BRIGHTNESS_FACTOR;
        buffer[i] = (temp > MAX_COLOR) ? MAX_COLOR : temp;
    } 
   
    fwrite(buffer, sizeof(unsigned char), width * height, fOut);
    
    fclose(fIn);
    fclose(fOut);

    puts("Success !!");
    return 0;
}

==> rgb_to_sepia.c <==
#include "cpimgmodules.h"

#define MAXPIXEL 255

int main(){
    FILE* fIn = fopen("TestImages/Images/lena_color.bmp", "rb");
    FILE* fOut = fopen("TestImages/Images/lena_filter3.bmp", "wb");
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    if (fIn == NULL){
	puts("Unable to open file");
    }

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }     

    imgCols = *(int*)&imgHeader[18];
    imgRows = *(int*)&imgHeader[22];
    imgBitDepth = *(int*)&imgHeader[28];

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

    if (imgBitDepth <= 8){
        fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
        fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
    }

    int imgSize = imgRows * imgCols;

    int r, g, b;

    unsigned char buffer[imgSize][3];

    for (int i = 0; i < imgSize; i++){
 	r = g = b = 0;
	buffer[i][0] = getc(fIn);
	buffer[i][1] = getc(fIn);
	buffer[i][2] = getc(fIn);

	g = (buffer[i][0]*0.272) + (buffer[i][1] * 0.534) + (buffer[i][2] *0.131);
	r = (buffer[i][0]*0.349) + (buffer[i][1] * 0.686) + (buffer[i][2] *0.168);
	b = (buffer[i][0]*0.393) + (buffer[i][1] * 0.769) + (buffer[i][2] *0.189);

	r = (r > MAXPIXEL) ? MAXPIXEL : r;
	g = (g > MAXPIXEL) ? MAXPIXEL : g;
	b = (b > MAXPIXEL) ? MAXPIXEL : b;

        putc(r, fOut);
        putc(g, fOut);
        putc(b, fOut);
    }

    fclose(fIn);
    fclose(fOut);

    return 0;
}

==> rgbtograyscale.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fIn = fopen("TestImages/Images/pp2.bmp", "rb");
    FILE *fOut = fopen("TestImages/Images/pp2_gray.bmp", "wb");

    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if(fIn == NULL)
        printf("Unable to open image\n");

    fread(imgHeader,sizeof(unsigned char),54,fIn);
    fwrite(imgHeader,sizeof(unsigned char),54,fOut);
    
    int height = *(int*)&imgHeader[22];
   int width = *(int*)&imgHeader[18];
   int bitDepth = *(int*)&imgHeader[28];

   int imgSize = height * width;
   unsigned char buffer[imgSize][3]; //stores RGB colour values for each pixel

   if (bitDepth <= 8)
	fread(colorTable, sizeof(unsigned char), 1024, fIn);

   if (bitDepth <= 8)
	fwrite(colorTable, sizeof(unsigned char), 1024, fOut);

   for(int i = 0; i < imgSize; i++){
	buffer[i][0] = getc(fIn);
	buffer[i][1] = getc(fIn);
	buffer[i][2] = getc(fIn);

       int temp = 0;
       temp = ((buffer[i][0]*0.3)+(buffer[i][1]*0.59)+(buffer[i][2]*0.11));
	putc(temp, fOut);
	putc(temp, fOut);
	putc(temp, fOut);
    }

    printf("Succes !!\n");
  
    fclose(fIn);
    fclose(fOut);

    return 0;
}
	
==> newDiscreteConvolution.c <==
#include "cpimgmodules.h"

struct Mask{
    int Rows;
    int Cols;
    unsigned char *Data;
};

void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf);

int main(){
    const char imgName[] = "ecoli.bmp";
    const char newImgName[] = "ecoli-laplace.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    struct Mask lpMask; //laplacian mask
    signed char *tmp;
    int i;

    lpMask.Cols = lpMask.Rows = 5;
    lpMask.Data = (unsigned char *)malloc(25 * sizeof(unsigned char));

    tmp = (signed char*)lpMask.Data;
    //laplacian mask
    for (i = 0; i < 25; i++){
                *tmp = (i == 12) ? 24 : -1;
                ++tmp;
    }

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    Convolve(imgRows, imgCols, &lpMask, imgBuffer, imgBuffer2);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

//2D discrete convolution algorithm
void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf){
    long i, j, m, n, idx, jdx;
    int ms, im, val;
    unsigned char *temp;

    for (i=0; i < imgRows; i++){
        for (j=0; j < imgCols; j++){
                    val = 0;
                    for (m = 0; m < myMask->Rows; m++){
                                for (n=0; n < myMask->Cols; n++){
                                    ms = (signed char)*(myMask->Data + m*myMask->Rows + n);
                                    idx = i-m;
                                    jdx = j-n;
                                    if (idx >= 0 && jdx >= 0){
                                                im = *(input_buf + (idx *imgRows) + jdx);
                                    }
                                    val += ms*im;
                                }
                    }
                        val = (val > 255) ? 255 : val;
                val = (val < 0) ? 0 : val;
                        temp = output_buf + (i*imgRows) + j;
                        *temp = (unsigned char)val;
        }
    }
}

==> blur2bw.c <==
#include "cpimgmodules.h"
#include <malloc.h>

//uses blur kernel filter
int main(){
    FILE * fIn = fopen("bsub_disk013_8bitgrayscale.bmp", "rb");
    FILE *fOut = fopen("bsub_disk013_8bitgrayscaleblur.bmp", "wb");
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];

    for (int i = 0; i < 54; i++){
        imgHeader[i] = getc(fIn);
    }

    imgCols = *(int*)&imgHeader[18];
    imgRows = *(int*)&imgHeader[22];
    imgBitDepth = *(int*)&imgHeader[28];

    unsigned char* buffer = (unsigned char*)malloc(imgCols * imgRows + 54 + 1024);
    unsigned char* output_buffer = (unsigned char*)malloc(imgCols * imgRows + 54 + 1024);
    //unsigned char output_buffer[imgCols * imgRows];

    fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

  //  if (imgBitDepth <= 8){
        fread(imgColorTable, sizeof(unsigned char), 1024, fIn);
        fwrite(imgColorTable, sizeof(unsigned char), 1024, fOut);
    //}

    //fread(buffer, sizeof(unsigned char), imgCols * imgRows * 3, fIn);
    for (int x = 0; x < imgRows * imgCols; x++) {
                buffer[x] = getc(fIn);
    }


    float v = 1.0 /25.0;
    float kernel[5][5];
    for (int i = 0; i< 5; i++){
                for (int j = 0; j < 5; j++){
                    kernel[i][j] = v;
            }
        }

    for (int x = 1; x < imgRows; x++){
                for (int y = 1; y < imgCols; y++){
                    float sum0 = 0.0;
                    for (int i = -1; i <= 4; i++){
                                for (int j = -1; j <= 4; j++){
                                    sum0 = sum0 + (float)kernel[i+1][j+1] * (float)(*(buffer + (i+x)*imgCols+j+y));
                                }
                        }
                    *(output_buffer + (x) * imgCols + (y)) = (unsigned char)((int)sum0);
                   //printf("%f %f %f\n", sum0, sum1, sum2);
                   //printf("%d %d %d\n", output_buffer[(x) * imgCols + (y)][0], output_buffer[(x) * imgCols + (y)][1], output_buffer[(x) * imgCols + (y)][2]);
            }
        }

    for (int i = 0; i < imgCols * imgRows; i++){
        putc(*(output_buffer + i), fOut);
    }

    fclose(fIn);
    fclose(fOut);
    return 0;
}

==> RobertsCrossEdgeDetector.c <==
#include "cpimgmodules.h"

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);

int main(){
    const char imgName[] = "lena512.bmp";
    const char newImgName[] = "lena_conv.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
        //unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

        unsigned char rbMask_gx[2][2] = {{1,0},
                                                                 {0,-1}};

        unsigned char rbMask_gy[2][2] = {{0,1},
                                                                        {-1,0}};

    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows, rbMask_gx);
    //contrast(imgBuffer2,imgCols,imgRows);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][2])
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x < imgCols; x++){
                    sum=0;
                    for(i = -1; i <= 0; i++){
                                for(j=-1;j <= 0; j++){
                                    sum = sum + *(_inputImgData+x+i+(long)((y+j)*imgCols))*MASK[i+1][j+1];
                                }
                    }
                    sum = (sum > 255) ? 255 : sum;
                    sum = (sum < 0) ? 0 : sum;
                        if ((_outputImgData + x + (long)(y*imgCols)) != NULL) {
                                if (sum > *(_outputImgData + x + (long)(y*imgCols))) {
                                *(_outputImgData + x + (long)(y*imgCols)) = sum;
                                }
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = sum;
                        }
                }
    }
}

void contrast(unsigned char *_outputImgData, int imgCols, int imgRows)
{
    int x, y, i, j, sum;

    for (y = 1; y < imgRows -1; y++){
                for (x=1; x < imgCols -1; x++){
                        if (*(_outputImgData + x + (long)(y*imgCols)) > 89) {
                        *(_outputImgData + x + (long)(y*imgCols)) = 255;
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = 0;
                        }
                }
    }
}

==> SaltAndPepper.c <==
#include "cpimgmodules.h"

void salt_pepper(unsigned char* _inputImgData, int imgCols, int imgRows, float prob);

int main(){
    const char imgName[] = "lena512.bmp";
    const char newImgName[] = "lena_saltnp3.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
        salt_pepper(imgBuffer, imgCols, imgRows, 0.6);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth, imgCols * imgRows);

        printf("Succcess!");
        return 0;
}

void salt_pepper(unsigned char* _inputImgData, int imgCols, int imgRows, float prob)
{
        int x, y, data, data1, data2;
        data = (float)(16384 * prob);
        data1 = data + 16384;
        data2 = 16384 - data;

        for (y = 0; y < imgRows; y++)
        {
                for (x = 0; x < imgCols; x++)
                {
                        data = rand() % 32768;
                        if (data >= 16384 && data < data1)
                        {
                                *(_inputImgData + x +(long)(y*imgRows)) = 0;
                        }
                        if (data >= data2 && data < 16384)
                        {
                                *(_inputImgData + x +(long)(y*imgRows)) = 255;
                        }
                }
        }
}

==> AccidentalBrighten.c <==
#include "cpimgmodules.h"

void convolve(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);

int main(){
    const char imgName[] = "zelda.bmp";
    const char newImgName[] = "zelda_highpass.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
        //unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

        int highpassMask[3][3] = {{-1,-1,-1},
                                                         {-1,5,-1},
                                                         {-1,-1,-1}};

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    convolve(imgBuffer,imgBuffer2,imgCols,imgRows, highpassMask);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, CUSTOM_IMG_SIZE);
        printf("Success!\n");

    return 0;
}

void convolve(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3])
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x < imgCols; x++){
                    sum=0;
                    for(i = -1; i <= 1; i++){
                                for(j=-1;j <= 1; j++){
                                    sum += *(_inputImgData+x+i+(long)((y+j)*imgCols))*MASK[i+1][j+1];
                                }
                    }
                    sum = (sum > 255) ? 255 : sum;
                    sum = (sum < 0) ? 0 : sum;
                *(_outputImgData + x + (long)(y*imgCols)) = sum;
                }
    }
}

==> HighPassFilter.c <==
#include "cpimgmodules.h"

void convolve(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);

int main(){
    const char imgName[] = "cropped001_8bitgrayscale.bmp";
    const char newImgName[] = "cropped001_highpass.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
        //unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

        int highpassMask[3][3] = {{-1,-1,-1},
                                                         {-1,9,-1},
                                                         {-1,-1,-1}};

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    convolve(imgBuffer,imgBuffer2,imgCols,imgRows, highpassMask);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, CUSTOM_IMG_SIZE);
        printf("Success!\n");

    return 0;
}

void convolve(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3])
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x < imgCols; x++){
                    sum=0;
                    for(i = -1; i <= 1; i++){
                                for(j=-1;j <= 1; j++){
                                    sum += *(_inputImgData+x+i+(long)((y+j)*imgCols))*MASK[i+1][j+1];
                                }
                    }
                        if (y == 5)
                                printf("sum: %d\n", sum);
                    sum = (sum > 255) ? 255 : sum;
                    sum = (sum < 0) ? 0 : sum;
                *(_outputImgData + x + (long)(y*imgCols)) = sum;
                }
    }
}

==> Maximum_Filter.c <==
#include "cpimgmodules.h"

void maxFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);

int main() {
    const char imgName[] = "lena512.bmp";
    const char newImgName[] = "lena_maxfilter1.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
        maxFilter(imgRows, imgCols, imgBuffer, imgBuffer2);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);

        return 0;
}

void maxFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, imax, i, j, n, a[11][11];
        n = 5;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        imax = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = n/2; i <= n/2; i++)
                                {
                                        a[i + n/2][j + n/2] = *(input_buf + x + i + (long)((y+j) * imgRows));
                                }
                        }
                        for (j=0; j < n; j++)
                        {
                                for(i = 0; i < n; i++)
                                {
                                        imax = (a[i][j] > imax) ? a[i][j] : imax;
                                }
                        }
                        imax = (imax > 255) ? 255: imax;
                        imax = (imax < 0) ? 0 : imax;
                        *(output_buf + x + (long)(y * imgCols)) = imax;
                }
        }
}


==> DiscreteConvolution.c <==
#include "cpimgmodules.h"

struct Mask{
    int Rows;
    int Cols;
    unsigned char *Data;
};

void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf);

int main(){
    const char imgName[] = "ecoli_8bitgrayscale.bmp";
    const char newImgName[] = "ecoli_laplace.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

    struct Mask lpMask; //laplacian mask
    signed char *tmp;
    int i;

    lpMask.Cols = lpMask.Rows = 5;
    lpMask.Data = (unsigned char *)malloc(25 * sizeof(unsigned char));

    tmp = (signed char*)lpMask.Data;
    //laplacian mask
    for (i = 0; i < 25; i++){
                *tmp = (i == 12) ? 24 : -1;
                ++tmp;
    }

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    Convolve(imgRows, imgCols, &lpMask, imgBuffer, imgBuffer2);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

//2D discrete convolution algorithm
void Convolve(int imgRows, int imgCols, struct Mask *myMask, unsigned char *input_buf, unsigned char *output_buf){
    long i, j, m, n, idx, jdx;
    int ms, im, val;
    unsigned char *temp;

    for (i=0; i < imgRows; i++){
        for (j=0; j < imgCols; j++){
                    val = 0;
                    for (m = 0; m < myMask->Rows; m++){
                                for (n=0; n < myMask->Cols; n++){
                                    ms = (unsigned char)*(myMask->Data + m*myMask->Rows + n);
                                    idx = i-m;
                                    jdx = j-n;
                                    if (idx >= 0 && jdx >= 0){
                                                im = *(input_buf + (idx *imgRows) + jdx);
                                    }
                                    val += ms*im;
                                }
                    }
                        val = (val > 255) ? 255 : val;
                val = (val < 0) ? 0 : val;
                        *(output_buf + (long)(i*imgRows) + j) = (unsigned char)val;
        }
    }
}

==> Median_Filter.c <==
#include "cpimgmodules.h"

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);

int main() {
    const char imgName[] = "cropped002_lines2.bmp";
    const char newImgName[] = "cropped002_lines_median2.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
        medianFilter(imgRows, imgCols, imgBuffer, imgBuffer2);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);

        return 0;
}

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, current, i, j, n, pos, ar[121];
        n = 5;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        pos = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        ar[pos] = *(input_buf + x + i + (long)((y + j) * imgRows));
                                        pos++;
                                }
                        }
                        for (j=1; j < (n * n) - 1; j++)
                        {
                                current = ar[j];
                                i = j - 1;
                                while (i >= 0 && ar[i] > current)
                                {
                                        ar[i+1] = ar[i];
                                        i = i - 1;
                                }
                                ar[i+1] = current;
                        }
                        *(output_buf + x + (long)(y * imgCols)) = ar[(n * n/2) + n/2];
                }
        }
}


==> Minimum_Filter.c <==
#include "cpimgmodules.h"

void minFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);

int main(int argc, char* argv[]) {
            const char* imgName = argv[1];
            const char* newImgName = argv[2];
            int imgCols, imgRows, imgBitDepth;
            unsigned char imgHeader[BMP_HEADER_SIZE];
            unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
            unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
            unsigned char* imgBuffer2 = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

            imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
                minFilter(imgRows, imgCols, imgBuffer, imgBuffer2);
            imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);
        return 0;
}

void minFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, imin, i, j, n, a[11][11];
        n = 5;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        imin = 255;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        a[i + n/2][j + n/2] = *(input_buf + x + i + (long)((y+j) * imgRows));
                                }
                        }
                        for (j=0; j < n; j++)
                        {
                                for(i = 0; i < n; i++)
                                {
                                        imin = (a[i][j] < imin) ? a[i][j] : imin;
                                }
                        }
                        if (y == 5) {
                                printf("%4d", imin);
                        }
                        *(output_buf + x + (long)(y * imgCols)) = imin;
                }
        }
}


==> Posterise.c <==
#include "cpimgmodules.h"

void posterize(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);
void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);
void minFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);
void maxFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf);

int main(int argc, char** argv){
    const char* imgName = argv[1];
    const char* newImgName = argv[2];
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer3 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer4 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
        //unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
    posterize(imgBuffer,imgBuffer2,imgCols,imgRows);
        //medianFilter(imgRows, imgCols, imgBuffer3, imgBuffer4);
        minFilter(imgRows, imgCols, imgBuffer2, imgBuffer3);
        //maxFilter(imgRows, imgCols, imgBuffer, imgBuffer2);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer3, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

void posterize(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows)
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x< imgCols; x++){
                        if ((*(_inputImgData + x + (long)(y*imgRows)) > 111) && (*(_inputImgData + x + (long)(y*imgRows)) < 160)) {
                                *(_outputImgData + x + (long)(y*imgRows)) = 128;
                        }
                        /*else if  (*(_inputImgData + x + (long)(y*imgCols)) < 120) {
                                *(_outputImgData + x + (long)(y*imgCols)) = 100;
                        }*/
                        /*if ((*(_inputImgData + x + (long)(y*imgCols)) > 35) && (*(_inputImgData + x + (long)(y*imgCols)) < 80)) {
                                *(_outputImgData + x + (long)(y*imgCols)) = 82;
                        }*/
                        else {
                                *(_outputImgData + x + (long)(y*imgRows)) = 255;
                        }
                }
    }
}

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, current, i, j, n, pos, ar[121];
        n = 11;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        pos = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        ar[pos] = *(input_buf + x + i + (long)((y + j) * imgRows));
                                        pos++;
                                }
                        }
                        for (j=1; j < (n * n) - 1; j++)
                        {
                                current = ar[j];
                                i = j - 1;
                                while (i >= 0 && ar[i] > current)
                                {
                                        ar[i+1] = ar[i];
                                        i = i - 1;
                                }
                                ar[i+1] = current;
                        }
                        *(output_buf + x + (long)(y * imgRows)) = ar[(n * n/2) + n/2];
                }
        }
}


void minFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, imin, i, j, n, a[11][11];
        n = 11;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        imin = 255;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        a[i + n/2][j + n/2] = *(input_buf + x + i + (long)((y+j) * imgRows));
                                }
                        }
                        for (j=0; j < n; j++)
                        {
                                for(i = 0; i < n; i++)
                                {
                                        imin = (a[i][j] < imin) ? a[i][j] : imin;
                                }
                        }
                        *(output_buf + x + (long)(y * imgRows)) = imin;
                }
        }
}

void maxFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf)
{
        int x, y, imax, i, j, n, a[11][11];
        n = 5;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        imax = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = n/2; i <= n/2; i++)
                                {
                                        a[i + n/2][j + n/2] = *(input_buf + x + i + (long)((y+j) * imgRows));
                                }
                        }
                        for (j=0; j < n; j++)
                        {
                                for(i = 0; i < n; i++)
                                {
                                        imax = (a[i][j] > imax) ? a[i][j] : imax;
                                }
                        }
                        imax = (imax > 255) ? 255: imax;
                        imax = (imax < 0) ? 0 : imax;
                        *(output_buf + x + (long)(y * imgRows)) = imax;
                }
        }
}


==> computehistogram2.c <==
#include "cpimgmodules.h"

float IMG_HIST[255];

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[]);

void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols);

int main(){
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
   // unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    const char imgName[] = "bsub_disk006_8bitgrayscale.bmp";
    //const char newImgName[] = "ecoli004.bmp";

    imageReader(imgName, &imgWidth, &imgHeight, &imgBitDepth, &imgHeader[0], &imgColorTable[0], &imgBuffer[0]);
    ImgHistogram(imgBuffer,imgHeight,imgWidth, &IMG_HIST[0]);
  //  ImgHistogramEqualization(&imgBuffer[0], &imgBuffer2[0], imgHeight, imgWidth);
  //  ImgHistogramEqualization(&imgBuffer2[0], &imgBuffer2[0], imgHeight, imgWidth);
   //imageWriterColor(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    //imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    return 0;
}

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[])
{
    FILE* fptr;
    fptr = fopen("image_hist1.csv", "w");
    int x, y, i, j;
    long int ihist[255];
    long int sum;

    for(i=0; i<=255;i++)
    {
        ihist[i] = 0;
    }

    sum =0;
    for (y=0; y <= imgRows; y++)
    {
                for (x=0; x < imgCols; x++){
                    j = *(_imgData+x+y*imgCols);
                    ihist[j] = ihist[j] + 1;
                    sum = sum + 1;
                }
    }

    for (i = 0; i < 255; i++)
    {
        hist[i] = (float)ihist[i]/(float)sum;
    }

    for (int i =0; i < 255; i++)
    {
        fprintf(fptr, "%f,",hist[i]);
    }

        fprintf(fptr, "\n");

    for (int i =1; i <+ 255; i++)
    {
        fprintf(fptr, "%d,",i);
        }

    fclose(fptr);
}
/*
void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols)
{
    FILE* fptr;
    fptr = fopen("eq_hist.txt", "w");
    int x, y, i,j;
    float sum;

   float histeq[256];
   float hist[256];

   ImgHistogram(&_inputImgData[0], imgRows, imgCols, &hist[0]);

   for (i = 0; i < 255; i++)
   {
        sum = 0.0;
        for (j = 0; j <= i; j++)
        {
            sum = sum + hist[j];
        }
        histeq[i] = (int)(255*sum+0.5);
   }

    for (int i =0; i < 255; i++)
    {
        fprintf(fptr, "\n%f",histeq[i]);
    }

   fclose(fptr);
   for  (y = 0; y < imgRows; y++)
   {
        for (x = 0; x < imgCols; x++)
        {
            *(_outputImgData+x+y*imgCols) = histeq[*(_inputImgData+x+y*imgCols)];
        }
   }
}*/



==> LineDetectorMask2.c <==
#include "cpimgmodules.h"

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf, int size);
void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);

int main(int argc, char** argv){
    const char* imgName = argv[1];
    const char* newImgName = argv[2];
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer3 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer4 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

        //Linear line detector masks
    int VER[3][3] = {{-1,2,-1},
                                        {-1,2,-1},
                                        {-1,2,-1}};

    int HOR[3][3] = {{-1,-1,-1},
                                        { 2, 2, 2},
                                        {-1,-1,-1}};

    int LDIA[3][3]=     {{2,-1,-1},
                                        {-1,2,-1},
                                        {-1,-1,2}};

    int RDIA[3][3]=     {{-1,-1,2},
                    {-1,2,-1},
                    {2,-1,-1}};

        //Prewitt operator masks

    int PREVER[3][3] =  {{-1,0,1},
                                                {-1,0,1},
                                                {-1,0,1}};

    int PREHOR[3][3]=   {{-1,-1,-1},
                        {0,0,0},
                        {1,1,1}};

        //Sobel operator mask

    int SOBVER[3][3] =  {{-1,0,1},
                                                {-2,0,2},
                                                {-1,0,1}};

    int SOBHOR[3][3]=   {{-1,-2,-1},
                        {0,0,0},
                        {1,2,1}};

        //Robinson operator direction mask
    int ROBNO[3][3] = {{-1,0,1},
                                                {-2,0,2},
                                                {-1,0,1}};

    int ROBNE[3][3] = {{-2,-1,0},
                        {-1,0,1},
                        {0,1,2}};

    int ROBEA[3][3]=    {{-1,-2,-1},
                                                {0,0,0},
                                                {1,2,1}};

    int ROBSE[3][3]=    {{0,-1,-2},
                                {1,0,-1},
                                {2,1,0}};

    int ROBSO[3][3] = {{1,0,-1},
                                          {2,0,-2},
                                          {1,0,-1}};

    int ROBSW[3][3] = {{2,1,0},
                                          {1,0,-1},
                                          {0,-1,-2}};

    int ROBWE[3][3]=    {{1,2,1},
                                                {0,0,0},
                                                {-1,-2,-1}};

    int ROBNW[3][3]=    {{0,1,2},
                        {-1,0,1},
                        {-2,-1,0}};

        //Kirsch operator direction mask
    int KIRNO[3][3] = {{-5,-5,-5},
                                                {-3,0,-3},
                                                {-3,-3,-3}};

    int KIRNE[3][3] = {{-3,5,5},
                        {-3,0,5},
                        {-3,-3,-3}};

    int KIREA[3][3]=    {{-3,-3,5},
                                                {-3,0,5},
                                                {-3,-3,5}};

    int KIRSE[3][3]=    {{-3,-3,-3},
                                {-3,0,5},
                                {-3,5,5}};

    int KIRSO[3][3] = {{-3,-3,-3},
                                          {-3,0,-3},
                                          {5,5,5}};

    int KIRSW[3][3] = {{-3,-3,-3},
                                          {5,0,-3},
                                          {5,5,-3}};

    int KIRWE[3][3]=    {{5,-3,-3},
                                                {5,0,-3},
                                                {5,-3,-3}};

    int KIRNW[3][3]=    {{5,5,-3},
                        {5,0,-3},
                        {-3,-3,-3}};

        //Laplacian operator 2nd order derivative mask
    int LAPPOS[3][3] = {{0,1,0},
                                                {1,-4,1},
                                                {0,1,0}};

    int LAPNEG[3][3] = {{0,-1,0},
                        {-1,4,-1},
                        {0,-1,0}};

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
        medianFilter(imgRows, imgCols, imgBuffer, imgBuffer2, 9);
    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,VER);
        line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows, HOR);
    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,LDIA);
    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,RDIA);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,PREHOR);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,PREVER);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,SOBHOR);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,SOBVER);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNO);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNE);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNW);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSO);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSE);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSW);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBEA);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBWE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIREA);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRWE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,LAPPOS);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,LAPNEG);
    contrast(imgBuffer3,imgCols,imgRows);
        //medianFilter(imgRows, imgCols, imgBuffer3, imgBuffer4, 7);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer3, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3])
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x < imgCols; x++){
                    sum=0;
                    for(i = -1; i <=1; i++){
                                for(j=-1;j <=1; j++){
                                    sum = sum + *(_inputImgData+x+i+(long)((y+j)*imgCols))*MASK[i+1][j+1];
                                }
                    }
                    sum = (sum > 255) ? 255 : sum;
                    sum = (sum < 0) ? 0 : sum;
                        if ((_outputImgData + x + (long)(y*imgCols)) != NULL) {
                                if (sum > *(_outputImgData + x + (long)(y*imgCols))) {
                                *(_outputImgData + x + (long)(y*imgCols)) = sum;
                                }
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = sum;
                        }
                }
    }
}

void contrast(unsigned char *_outputImgData, int imgCols, int imgRows)
{
    int x, y, i, j, sum;

    for (y = 1; y < imgRows -1; y++){
                for (x=1; x < imgCols -1; x++){
                        if (*(_outputImgData + x + (long)(y*imgCols)) > 5) {
                        *(_outputImgData + x + (long)(y*imgCols)) = 0;
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = 255;
                        }
                }
    }
}

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf, int size)
{
        int x, y, current, i, j, n, pos, ar[121];
        n = size;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        pos = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        ar[pos] = *(input_buf + x + i + (long)((y + j) * imgRows));
                                        pos++;
                                }
                        }
                        for (j=1; j < (n * n) - 1; j++)
                        {
                                current = ar[j];
                                i = j - 1;
                                while (i >= 0 && ar[i] > current)
                                {
                                        ar[i+1] = ar[i];
                                        i = i - 1;
                                }
                                ar[i+1] = current;
                        }
                        *(output_buf + x + (long)(y * imgCols)) = ar[(n * n/2) + n/2];
                }
        }
}

==> GaussianNoise.c <==
#include "cpimgmodules.h"
#include <math.h>

void gaussian(unsigned char * _inputImgData, int imgCols, int imgRows, float var, float mean);

int main() {
    const char imgName[] = "lena512.bmp";
    const char newImgName[] = "lena_gaussian1.bmp";
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char *)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
        gaussian(imgBuffer, imgCols, imgRows, 90, 80);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth, imgCols * imgRows);

        return 0;
}

void gaussian(unsigned char * _inputImgData, int imgCols, int imgRows, float var, float mean){
        int x, y;
        float noise, theta;
        int temp = 0;
        for (y = 0; y < imgRows; y++) {
                for (x = 0; x < imgCols; x++) {
                        noise = sqrt(-2*var*log(1.0 - (float)((rand() % 32678)/32767.1)));
                        theta = (rand() % 32768) * 1.9175345e-4 - 3.14159265;;
                        noise *= cos(theta);
                        noise += mean;
                        noise = (noise > 255) ? 255 : noise;
                        noise = (noise < 0) ? 0 : noise;
                        //temp = rand() % 90 + 80;
                        *(_inputImgData + x + (long)(y * imgCols)) = (unsigned char)(noise + 0.5);
                        *(_inputImgData + x + (long)(y * imgCols)) = temp;
                }
        }
}

==> LineDetectorMask.c <==
#include "cpimgmodules.h"

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf, int size);
void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3]);
void contrast(unsigned char *_outputImgData, int imgCols, int imgRows);

int main(int argc, char** argv){
    const char* imgName = argv[1];
    const char* newImgName = argv[2];
    int imgCols, imgRows, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char* imgBuffer = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer2 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer3 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);
    unsigned char* imgBuffer4 = (unsigned char*)malloc(CUSTOM_IMG_SIZE + 1024 + 54);

        //Linear line detector masks
    int VER[3][3] = {{-1,2,-1},
                                        {-1,2,-1},
                                        {-1,2,-1}};

    int HOR[3][3] = {{-1,-1,-1},
                                        { 2, 2, 2},
                                        {-1,-1,-1}};

    int LDIA[3][3]=     {{2,-1,-1},
                                        {-1,2,-1},
                                        {-1,-1,2}};

    int RDIA[3][3]=     {{-1,-1,2},
                    {-1,2,-1},
                    {2,-1,-1}};

        //Prewitt operator masks

    int PREVER[3][3] =  {{-1,0,1},
                                                {-1,0,1},
                                                {-1,0,1}};

    int PREHOR[3][3]=   {{-1,-1,-1},
                        {0,0,0},
                        {1,1,1}};

        //Sobel operator mask

    int SOBVER[3][3] =  {{-1,0,1},
                                                {-2,0,2},
                                                {-1,0,1}};

    int SOBHOR[3][3]=   {{-1,-2,-1},
                        {0,0,0},
                        {1,2,1}};

        //Robinson operator direction mask
    int ROBNO[3][3] = {{-1,0,1},
                                                {-2,0,2},
                                                {-1,0,1}};

    int ROBNE[3][3] = {{-2,-1,0},
                        {-1,0,1},
                        {0,1,2}};

    int ROBEA[3][3]=    {{-1,-2,-1},
                                                {0,0,0},
                                                {1,2,1}};

    int ROBSE[3][3]=    {{0,-1,-2},
                                {1,0,-1},
                                {2,1,0}};

    int ROBSO[3][3] = {{1,0,-1},
                                          {2,0,-2},
                                          {1,0,-1}};

    int ROBSW[3][3] = {{2,1,0},
                                          {1,0,-1},
                                          {0,-1,-2}};

    int ROBWE[3][3]=    {{1,2,1},
                                                {0,0,0},
                                                {-1,-2,-1}};

    int ROBNW[3][3]=    {{0,1,2},
                        {-1,0,1},
                        {-2,-1,0}};

        //Kirsch operator direction mask
    int KIRNO[3][3] = {{-5,-5,-5},
                                                {-3,0,-3},
                                                {-3,-3,-3}};

    int KIRNE[3][3] = {{-3,5,5},
                        {-3,0,5},
                        {-3,-3,-3}};

    int KIREA[3][3]=    {{-3,-3,5},
                                                {-3,0,5},
                                                {-3,-3,5}};

    int KIRSE[3][3]=    {{-3,-3,-3},
                                {-3,0,5},
                                {-3,5,5}};

    int KIRSO[3][3] = {{-3,-3,-3},
                                          {-3,0,-3},
                                          {5,5,5}};

    int KIRSW[3][3] = {{-3,-3,-3},
                                          {5,0,-3},
                                          {5,5,-3}};

    int KIRWE[3][3]=    {{5,-3,-3},
                                                {5,0,-3},
                                                {5,-3,-3}};

    int KIRNW[3][3]=    {{5,5,-3},
                        {5,0,-3},
                        {-3,-3,-3}};

        //Laplacian operator 2nd order derivative mask
    int LAPPOS[3][3] = {{0,1,0},
                                                {1,-4,1},
                                                {0,1,0}};

    int LAPNEG[3][3] = {{0,-1,0},
                        {-1,4,-1},
                        {0,-1,0}};

    int GDMASK[3][3] = {{-1,-1,-1},
                        {-1,8,-1},
                        {-1,-1,-1}};

    imageReader(imgName, &imgCols, &imgRows, &imgBitDepth, imgHeader, imgColorTable, imgBuffer);
//      medianFilter(imgRows, imgCols, imgBuffer, imgBuffer2, 9);
//    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,VER);
//      line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows, HOR);
//    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,LDIA);
//    line_detector(imgBuffer2,imgBuffer3,imgCols,imgRows,RDIA);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,PREHOR);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,PREVER);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,SOBHOR);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,SOBVER);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBNW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBSW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBEA);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,ROBWE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRNW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSO);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRSW);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIREA);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,KIRWE);
//    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,LAPPOS);
    line_detector(imgBuffer,imgBuffer2,imgCols,imgRows,GDMASK);
    contrast(imgBuffer3,imgCols,imgRows);
        //medianFilter(imgRows, imgCols, imgBuffer3, imgBuffer4, 7);
    imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth, imgCols * imgRows);
        printf("Success!\n");

    return 0;
}

void line_detector(unsigned char *_inputImgData, unsigned char *_outputImgData, int imgCols, int imgRows, int MASK[][3])
{
    int x, y, i, j, sum;

    for (y = 0; y < imgRows; y++){
                for (x=0; x < imgCols; x++){
                    sum=0;
                    for(i = -1; i <=1; i++){
                                for(j=-1;j <=1; j++){
                                    sum = sum + *(_inputImgData+x+i+(long)((y+j)*imgCols))*MASK[i+1][j+1];
                                }
                    }
                    sum = (sum > 255) ? 255 : sum;
                    sum = (sum < 0) ? 0 : sum;
                        if ((_outputImgData + x + (long)(y*imgCols)) != NULL) {
                                if (sum > *(_outputImgData + x + (long)(y*imgCols))) {
                                *(_outputImgData + x + (long)(y*imgCols)) = sum;
                                }
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = sum;
                        }
                }
    }
}

void contrast(unsigned char *_outputImgData, int imgCols, int imgRows)
{
    int x, y, i, j, sum;

    for (y = 1; y < imgRows -1; y++){
                for (x=1; x < imgCols -1; x++){
                        if (*(_outputImgData + x + (long)(y*imgCols)) > 5) {
                        *(_outputImgData + x + (long)(y*imgCols)) = 0;
                        }
                        else {
                        *(_outputImgData + x + (long)(y*imgCols)) = 255;
                        }
                }
    }
}

void medianFilter(int imgRows, int imgCols, unsigned char *input_buf, unsigned char *output_buf, int size)
{
        int x, y, current, i, j, n, pos, ar[121];
        n = size;
        for (y = n/2; y < imgRows - n/2; y++)
        {
                for (x = n/2; x < imgCols - n/2; x++)
                {
                        pos = 0;
                        for (j = -n/2; j <= n/2; j++)
                        {
                                for (i = -n/2; i <= n/2; i++)
                                {
                                        ar[pos] = *(input_buf + x + i + (long)((y + j) * imgRows));
                                        pos++;
                                }
                        }
                        for (j=1; j < (n * n) - 1; j++)
                        {
                                current = ar[j];
                                i = j - 1;
                                while (i >= 0 && ar[i] > current)
                                {
                                        ar[i+1] = ar[i];
                                        i = i - 1;
                                }
                                ar[i+1] = current;
                        }
                        *(output_buf + x + (long)(y * imgCols)) = ar[(n * n/2) + n/2];
                }
        }
}

==> computehistogram.c <==
#include "cpimgmodules.h"

float IMG_HIST[255];

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[]);

void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols);

int main(){
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];
    unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

    const char imgName[] = "output3.bmp";
    //const char newImgName[] = "ecoli004.bmp";

    imageReader(imgName, &imgWidth, &imgHeight, &imgBitDepth, &imgHeader[0], &imgColorTable[0], &imgBuffer[0]);
    ImgHistogram(&imgBuffer[0],imgHeight,imgWidth, &IMG_HIST[0]);
  //  ImgHistogramEqualization(&imgBuffer[0], &imgBuffer2[0], imgHeight, imgWidth);
  //  ImgHistogramEqualization(&imgBuffer2[0], &imgBuffer2[0], imgHeight, imgWidth);
   //imageWriterColor(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    //imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer, imgBitDepth,(imgWidth * imgHeight) );
    return 0;
}

void ImgHistogram(unsigned char *_imgData, int imgRows, int imgCols, float hist[])
{
    FILE* fptr;
    fptr = fopen("new_hist.txt", "w");
    int x, y, i, j;
    long int ihist[255];
    long int sum;

    for(i=0; i<=255;i++)
    {
        ihist[i] = 0;
    }

    sum =0;
    for (y=0; y <= imgRows; y++)
    {
                for (x=0; x < imgCols; x++){
                    j = *(_imgData+x+y*imgCols);
                    ihist[j] = ihist[j] + 1;
                    sum = sum + 1;
                }
    }

    for (i = 0; i < 255; i++)
    {
        hist[i] = (float)ihist[i]/(float)sum;
    }

    for (int i =0; i < 255; i++)
    {
        fprintf(fptr, "\n%f",hist[i]);
    }

    fclose(fptr);
}
/*
void ImgHistogramEqualization(unsigned char *_inputImgData, unsigned char*_outputImgData, int imgRows, int imgCols)
{
    FILE* fptr;
    fptr = fopen("eq_hist.txt", "w");
    int x, y, i,j;
    float sum;

   float histeq[256];
   float hist[256];

   ImgHistogram(&_inputImgData[0], imgRows, imgCols, &hist[0]);

   for (i = 0; i < 255; i++)
   {
        sum = 0.0;
        for (j = 0; j <= i; j++)
        {
            sum = sum + hist[j];
        }
        histeq[i] = (int)(255*sum+0.5);
   }

    for (int i =0; i < 255; i++)
    {
        fprintf(fptr, "\n%f",histeq[i]);
    }

   fclose(fptr);
   for  (y = 0; y < imgRows; y++)
   {
        for (x = 0; x < imgCols; x++)
        {
            *(_outputImgData+x+y*imgCols) = histeq[*(_inputImgData+x+y*imgCols)];
        }
   }
}*/



==> rgbtograyscale.c <==
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fIn = fopen("cropped006.bmp", "rb");
    FILE *fthree = fopen("lena512.bmp", "rb");
    FILE *fOut = fopen("cropped006datacenter.bmp", "wb");

    unsigned char imgHeader[54];
    unsigned char imgHeader2[54];
    unsigned char colorTable[1024];

    if(fIn == NULL)
        printf("Unable to open image\n");

    fread(imgHeader,sizeof(unsigned char),54,fIn);
    fread(imgHeader2,sizeof(unsigned char),54,fthree);

    int height = *(int*)&imgHeader[22];
    printf("Height: %d\n", height);
    int width = *(int*)&imgHeader[18];
    printf("Width: %d\n", width);
    int bitDepth = *(int*)&imgHeader2[28];
    printf("Bit Depth: %d\n", bitDepth);

    //int height2 = *(int*)&imgHeader2[22];
    //printf("Height: %d\n", height2);
    //int width2 = *(int*)&imgHeader2[18];
    //printf("Width: %d\n", width2);
    int imgSize = height * width;
        printf("imgSize: %d\n", imgSize);
    unsigned char buffer[3]; //stores RGB colour values for each pixel

    //imgHeader2[22] = (unsigned char)height;
        //imgHeader2[18] = (unsigned char)width;
        imgHeader[28] = (unsigned char)8;
        //imgHeader[28] = (unsigned char)bitDepth;
        fwrite(imgHeader, sizeof(unsigned char), 54, fOut);


        //if (bitDepth <= 8) {
                fread(colorTable, sizeof(unsigned char), 1024, fthree);
                fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
        //}

        int sum = 0;
        int average = 0;

    for(int i = 0; i < imgSize; i++){
                buffer[0] = getc(fIn);
                buffer[1] = getc(fIn);
                buffer[2] = getc(fIn);

        int temp = 0;
        //temp = ((buffer[0]*0.3)+(buffer[1]*0.59)+(buffer[2]*0.11));
        temp = ((buffer[0]*0.33)+(buffer[1]*0.33)+(buffer[2]*0.33));
                //putc(temp, fOut);
                sum += temp;
                //putc(temp, fOut);
                //putc(temp, fOut);
    }

        average = sum / imgSize;

    for(int i = 0; i < imgSize; i++){
                buffer[0] = getc(fIn);
                buffer[1] = getc(fIn);
                buffer[2] = getc(fIn);

        int temp = 0;
        //temp = ((buffer[0]*0.3)+(buffer[1]*0.59)+(buffer[2]*0.11));
        temp = ((buffer[0]*0.33)+(buffer[1]*0.33)+(buffer[2]*0.33)) - average;
                putc(temp, fOut);
                //putc(temp, fOut);
                //putc(temp, fOut);
    }

    printf("Success!!\n");

    fclose(fIn);
    fclose(fOut);

    return 0;
}

