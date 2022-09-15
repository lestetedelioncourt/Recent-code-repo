import com.sun.tools.example.debug.expr.Token
import java.awt.Button
import java.io.File
import java.lang.AssertionError
import java.math.BigDecimal
import java.nio.file.Files
import java.nio.file.Paths
import java.time.LocalDate
import java.time.chrono.ChronoLocalDate
import java.util.*
import java.util.function.BinaryOperator
import java.util.function.IntBinaryOperator
import javax.naming.Context
import javax.print.attribute.AttributeSet
import javax.sql.DataSource
import javax.swing.tree.TreeNode
import kotlin.collections.HashMap
import kotlin.concurrent.thread
import kotlin.coroutines.*
import kotlin.math.abs
import kotlin.properties.Delegates
import kotlin.properties.PropertyDelegateProvider
import kotlin.properties.ReadOnlyProperty
import kotlin.properties.ReadWriteProperty
import kotlin.reflect.KProperty

var topLevelVariable = "I'm a top level Variable" //these have to be initialized when they are declared as in kotlin as opposed to java,
                                                  //assigned variables do not have a default value. For a local variable, is scoped to local function
                                                  //so easy for compiler to figure out if variable has been assigned to it.

val TOP_LEVEL_VALUE = "I'm an immutable top level variable i.e. a string constant" //if initialized as such - click the lightbulb, will say "might be constant"

const val STRING_CONSTANT = "I'm an immutable top level variable i.e. a string constant" //tells the compiler at compile time that it is constant, creates
                                                                                         //some constraints for efficiency

/**
 * Creates a singleton - a singleton is a class that allows only a single instance of itself to be created and gives access to a that created instance.
 * The singleton pattern is used in Java and .NET to define a global variable
 */
object Resource {
    val name = "Name"
}

fun main(args: Array<String>?) : Unit { //Unit automatic return type for all functions, more or less equivalent to void, but is an explicit type so as not to clash
             //with the Java 'generic' type. An entry point of a Kotlin application is the main function. Unit type can be ommited for a function returning no type
    //Shift+F6 alters every version of a named variable (or filename) at once.
    println(topLevelVariable)
    val names = arrayOf("John", "Joe", "Jenny")
    val names1 : Array<String> = arrayOf("John", "Joe", "Jenny")

    val numbers = arrayOf(1, 2, 3) //creates array of Integer[] object types, for primitives array must use below syntax
    val numbers1 : Array<Int> = arrayOf(1, 2, 3) //creates array of Integer[] object types, for primitives array must use below syntax
    val primitivenumbers = intArrayOf(1, 2, 3) // this now creates array of int[] primtive types
    //similarly other primitive types have their own specialist constructors i.e. byteArrayOf

    val newbytes = byteArrayOf(1, 3, 5)
    println(names.last()) // function which accesses the last member of an array
    IntArray(9) //creates a primitive int[9] array

    for (name in names) {println(name)}
    names.indices //array storing a list of indexes contained by the array,
    for (index in names.indices) {println(index)} // prints 0, 1, 2 for our names[3] array
    for (index in names.indices) {print("${index}: ${names[index]}\n")}  // 0: John, 1: James, 2: Josh

    for (i in 1..10) {
        if (i in 4..7) continue //range check also used in if conditionals

        println(i) //prints range from 1,2,3,8,9,10
    }

    for (i in 1 until 10){
        if ((4..7).contains(i)) continue // achieves same result as 'in' check above
        println(i)
    } // prints range from 1-10, second number in range has to be greater than the first

    for (i in 10 downTo 1) println(i) // prints range from 10-1, second number in range ha  to be lesser than the first
    for (i in 1 until 10 step 2) println(i) // prints 1, 3, 5, 7, 9, step value can be changed
    for (i in 'a'..'z' step 2) println(i) // prints 'a', 'c', 'e', ..., etc.

    val list = listOf("a", "b", "c")

    if (-1 !in 0..list.lastIndex) {
        println("-1 is out of range")
    }
    if (list.size !in list.indices) {
        println("list size is out of valid list indices range, too")
    }

    println(2.2 in 1.1..5.6) //will evaluate to true - however doubles/floats possess no iterator
    println((1.1..3.3).contains(4.0)) //will evaluate to false

    //if statement in kotlin can return a value and thus be used in assigning a variable, ternary operator doesn't exist in kotlin for that reason
    val pr3fix  = if (2.2 !in 1.1..5.6) {
        "-"
    }
    else if (3.3 in 1.2..3.2) {
        "*"
    }
    else {
        print("Hey yo")
        ">"
    } //last statement within an if/else block is the value assigned to any variable

    var x = 2

    when (x) {
        1 -> print("x == 1")
        2 -> print("x == 2")
        else -> {
            print("x is neither 1 nor 2")
        }
    }

    var time = 12

    println("Good ${if (time < 12) "morning" else if (time in 12..17) "afternoon" else "evening"}")

    //can replace 'if' statements with 'when'. 'when' functions similarly to a 'switch' statement, but can do more than simple
    //equality checks, i.e. can check 'greater than' or 'less than', and can take any data type as opposed to a 'switch' statement
    //As soon as a condition is hit it breaks out of the 'when' block, i.e. only statement 1 will execute if time=4
    //equality checks, i.e. can check 'greater than' or 'less than', and can take any data type as opposed to a 'switch' statement
    time = 4
    when (time)
    {
        in 0..5 -> println("Why are you up so early?")
        in 0..11 -> println("Good morning!")
        in 12..17 -> println("Good afternoon!")
        in 18..20 -> println("Good evening!")
        else -> println("Good night!")
    }

    //When can also be used as a rh operand as it returns a value.
    val greeting = when(time)
    {
        in 0..5 -> "Why are you up so early?"
        in 0..11 -> "Good morning!"
        in 12..17 -> "Good afternoon!"
        in 18..21 -> "Good evening!"
        else -> "Good night!"
    }

    /*Cannot use
    when (time){
         < 15 ->
         >=16 ->
    }

    must be
    when {
        (time < 15) ->
        (time >= 16)
    }

    Any expression which evaluates to a boolean can be used in a when statement, including different variables i.e

    when
        (x > 6) -> do something...
        (y > 6) -> do something...
        (z > 6) -> do something...
     */

    var j = 0

    do {
        println(j)
        j++

        var k = 0

        while (k < 5) {
            println("---${k}")
            k++
            break ///will only break the inner while loop
            println("I'm not printed")
        }

        println("I'm printed")
    } while (j < 5)

    j = 0

    out3r@ do { //addition of a tag in this case denoted by "out3r@" (tagname followed by '@' symbol) allows to break outer loop
        println(j)
        j++

        var k = 0

        while (k < 5) {
            println("---${k}")
            k++
            break@out3r //breaks the outer while loop, denoted by the tag out3r
            println("i'm not printed")
        }

        println("I'm not printed")
    } while (j < 5)

    greet("Hans", 1)
    greet("Gretchen", 2)

    println(getMax(1, 3))

    hello(2, "Hey man")
    hello("Leslie", 1)

    val array1 = intArrayOf(1, 2, 3, 4, 5, 6)

    println(getSum(10, 20, *array1, 30, 40))

    val user = User() //initialises a new object of class User()

    val newUser = NewUser("Les", 33)
    val newUser1 = NewUser1("Kai", 33)

    //is and !is perform a runtime check which verifies whether or not an object corresponds to a given type

    is_demonstration("Hello")
    is_demonstration(newUser)

    val fruits = listOf("banana", "avocado", "apple", "kiwifruit")
    fruits
        .filter { it.startsWith("a") }
        .sortedBy { it }
        .map { it.uppercase() }
        .forEach { println(it) }

    val newmap = mapOf("a" to 1, "b" to 2, "c" to 3)

    println(newmap["a"])

    for ((k, v) in newmap) {
        println("$k -> $v")
    }

    //Null safety
    var neverNull: String = "This can't be null"        //Declares a non-null string var
    var nullable: String? = "You can keep a null here"  //Declares a nullable string var
    var inferredNonNull = "The compiler assumes non-null. This can't be null" //compiler assumes non-null for vars initialized with a value

    //Null tests
    val files = File("Test").listFiles()
    println(files?.size ?: "empty") // Use of Elvis operator, tests if variable is null, if files is null, this prints "empty"
    val firstFile = files.firstOrNull() ?: null //get the first item of a possibly empty collection
    files?.let {
        println(firstFile) // execute this block if not null
    }

    //Variable swap
    var a = 1
    var b = 2
    a = b.also { b = a }

    //Member functions and extensions with a single parameter can be turned into infix functions.
    infix fun Int.times(newstr: String) = newstr.repeat(this)        // 1
    println(5 times "Bye ")                                    // 2

    val pair = "Ferrari" to "Katrina"                          // 3
    println(pair)

    infix fun String.onto(other: String) = Pair(this, other)   // 4
    val myPair = "McLaren" onto "Lucas"
    println(myPair)

    val sophia = Woman("Sophia")
    val claudia = Woman("Claudia")
    sophia likes claudia                                       // 5

    /**
     * classes are final by default. If you want to allow the class inheritance, use 'open' modifier
     * methods are also final by default. As with the classes, the open modifier allows overriding them.
     */
    open class Dog {                // 1
        open fun sayHello() {       // 2
            println("wow wow!")
        }
    }

    /**
     * Overriding methods or attributes requires the override modifier.
     */
    class Yorkshire : Dog() {       // 3
        override fun sayHello() {   // 4
            println("wif wif!")
        }
    }

    val dog: Dog = Yorkshire()
    dog.sayHello() //output: wif wif

    class Animal(val name: String)

    /**
     * Can define your own iterators in your classes by implementing the iterator operator in them
     */
    class Zoo(val animals: List<Animal>) {
        operator fun iterator(): Iterator<Animal> {             // 1
            return animals.iterator()                           // 2
        }
    }

    val zoo = Zoo(listOf(Animal("zebra"), Animal("lion")))

    for (animal in zoo) {                                   // 3
        print("Watch out, it's a ${animal.name}\n")
    }

    //Equality checks: Kotlin uses == for structural comparison and === for referential comparison.
    val authors = setOf("Shakespeare", "Hemingway", "Twain")
    val writers = setOf("Shakespeare", "Hemingway", "Twain")
    val reorderedAuthors = setOf("Twain", "Shakespeare", "Hemingway")

    println(authors == writers)   // Returns true
    println(authors === writers)  // Returns false because authors and writers are distinct references
    println(authors === reorderedAuthors)  // Also returns true as setOf() re-orders elements in the collection.
}

class Woman(val name: String) {
    val likedPeople = mutableListOf<Woman>()
    infix fun likes(other: Woman) { likedPeople.add(other) }  // 6
}

fun operator_functions() {
    operator fun Int.times(str: String) = str.repeat(this)       // 1
    println(2 * "Bye ")                                          // 2

    operator fun String.get(range: IntRange) = substring(range)  // 3
    val str = "Always forgive your enemies; nothing annoys them so much."
    println(str[0..14])
}

//demonstrating 'is' operator and implicit/'smart' casts Compiler tracks the 'is' checks and inserts safe 'smart' casts automatically when necessary.
//These 'smart' casts only work when the compiler can guarantee that the type won't change between the 'is' check and its usage.
fun is_demonstration(obj: Any)
{
    if (obj !is String || obj.length == 0) //obj is implicitly cast to string on the right hand side of || operator
        println("Obj is not a String")
    else if (obj is String)
        println(obj.length) //obj is again implicitly cast to String
}

fun unsafe_cast(obj: Any) //this will throw an exception if 'obj' isn't castable so is known as an unsafe cast
{
    val x: String = obj as String
}

fun unsafe_cast_improved(obj: Any) //slightly safer as allows the obj the user is trying to cast into a string to be null
{
    val x: String? = obj as String?
}

fun safe_cast(obj: Any) //safe cast operator 'as?' returns null on failure rather than throwing an exception, result of cast is nullable
{
    val x: String? = obj as? String
}

/**
 * return using a 'when' statement
 */
fun transform(color: String): Int {
    return when (color) {
        "Red" -> 0
        "Green" -> 1
        "Blue" -> 2
        else -> throw IllegalArgumentException("Invalid color param value")
    }
}

fun foo() {
    listOf(1, 2, 3, 4, 5).forEach lit@{
        if (it == 3) return@lit // local return to the caller of the lambda - the forEach loop
        print(it)
    }
    print(" done with explicit label")
}

//foo() : Result - 1245 done with explicit label

fun foo1() {
    listOf(1, 2, 3, 4, 5).forEach {
        if (it == 3) return@forEach // local return to the caller of the lambda - the forEach loop
        print(it)
    }
    print(" done with implicit label")
}

//foo1() : Result - 1245 done with implicit label

fun foo2() {
    run loop@{
        listOf(1, 2, 3, 4, 5).forEach {
            if (it == 3) return@loop // non-local return from the lambda passed to run
            print(it)
        }
    }
    print(" done with nested loop")
}

//foo2() : Result - 12 done with nested loop

fun foo3() {
    listOf(1, 2, 3, 4, 5).forEach(fun(value: Int) {
        if (value == 3) return  // local return to the caller of the anonymous function - the forEach loop
        print(value)
    })
    print(" done with anonymous function")
}
//foo3() : Result - 1245 done with anonymous function

fun try_catch() {
    try {
        throw Exception("Hi There!")
        // some code
    } catch (e: Exception) {
        println("Eception handled")
        // handler
    } finally {
        println("Executing finally block")
        // optional finally block
    }

    //try is an expression which means it can also return a value
    val read = Scanner(System.`in`)
    val input = read.next()

    val a: Int? = try { input.toInt() } catch (e: NumberFormatException) { null }


    val s = input ?: throw IllegalArgumentException("Name required")

    //he throw expression has the type Nothing. This type has no values and is used to mark code locations that can never be reached. In your own code, you can use Nothing to mark a function that never returns:

    fun fail(message: String): Nothing {
        throw IllegalArgumentException(message)
    }
}

/*compiler prohibit 'is' checks for operations involving generic types at runtime, instances of generic types do not hold information
about their actual type arguments, so at runtime List<Int> is erased to just List<*>. in general there is no way to check whether an
instance belongs to a genberic type with certain type arguments at runtime. Cannot check that:
ints is List<Int> or list is T (type parameter)

however can perform check
if (something is List<*>) {
    something.forEach { println(it) } // The items are typed as `Any?`
}

if the type arguments of an instance are checked statically (at compile time), you can make an is -check or a cast that involves the non
-generic part of the type. NOte that angle barxcakets are excluded in this case.
fun handleStrings(list: List<String>) {
    if (list is ArrayList) {
        // `list` is smart-cast to `ArrayList<String>`
    }
}


*/
fun greet(name: String, reps: Int) {
    for (i in 0..reps)
    {
        println("Hello, $name! Nice to meet you!")
    }
}

//fun(input variable) : return type - if using a block body function, return type has to be declared explicitly
fun getMax(num1: Int, num2: Int) : Int {
    val max = if (num1 > num2) num1 else num2
    return max
}

fun double1(num: Int) : Int {
    return num * 2
}

fun double2(num: Int) = num * 2 // return type is inferred, function body is assigned, this is referred to as a single expression function

//functions can be overloaded by altering the order in which the same parameters are passed in, quite rare, and hard to follow,
//using default values can allow user to ignore one or more arguments, having a similar type of overloading. Default values do not recognize
//type inference, so type has to be explicitly defined
fun hello(name: String, reps: Int = 1) {
    for (i in 0..reps) println("Hello, ${name}!")
}

fun hello(reps: Int, message: String) {
    for (i in 0..reps) println("${message}")
}

fun getSum(vararg numbers: Int): Int { //numbers = Array<Int>
    var sum = 0

    for (number in numbers) sum += number

    return sum
}

class User {
    val name = "Leslie"
    var age = 33
}

class NewUser(name: String, age: Int) { //declares variables to be passed in during the class construction
    val name = name
    var age = age
}

class NewUser1(val name: String, var age: Int) { //same functionality as that which was declared above, lass constructor and assignment
}                                                //to its member variables

class NewUser2(name: String, var age: Int) { //constructor does not have a body as in regular coding. More complex initialization logic
    val name : String                        //is defined within an 'init' block

    init {
        if (name.isBlank()) {
            this.name = "No Name"
        } else {
            this.name = name.trim()
        }

        println("New user created. Name: ${this.name}, Age: ${this.age}")
    }
}

//Secondary constructors,  aclass can also declare seconday constructors, prefixed with 'constructor'
class Company(val workers: MutableList<Worker> = mutableListOf())

class Worker {
    constructor(employer: Company){
        employer.workers.add (this)
    }
}

/** If the class has a primary constructor, ech secondary constructor needs to delegate to the primary constructor, either directly
 *  or indirectly through another secondary constructor. Delegation to another constructor of the same class is done using the 'this' keyword
 */
class Person(val name: String) {
    val students: MutableList<Person> = mutableListOf()
    constructor(teachername: String, teacher: Person) : this(teachername) { //teacher constructed using teachername variable : this(teachername)
        teacher.students.add(this)
    }
}

/**
 * Code in initializer blocks becomes part of the primary constructor. Delegation to the primary constructor happens as the first statement of a
 * secondary constructor, so the code in all init blocks and property initializers is executed before the body of a secondary constructor.
 */
class Constructors {
    init {
        println("Init block")
    }

    constructor(i: Int) {
        println("Constructor $i")
    }
}

/**
 * If a non-abstract class does not declare any constructors (primary or secondary), it will have a generated public primary constructor with no arguments
 */
class Cat{}

/**
 * If you don't want your class to have a public constructor, declare an empty primary constructor with non-default visibility
 */
class DontCreateMe private constructor() {}

/**
 * A class may be declared abstract, along with some of its members. An abstract member does not have an implementation in its class. You don't need to annotate
 * abstract classses or functions with 'open'
 */
abstract class Polygon {
    abstract fun draw()
}

class Rectangle : Polygon() {
    override fun draw() {
        //draw the rectangle
    }

    var length = 5
    var width = 5
    var color : Int = 0xFF0000
}

/**
 * Configure properties of an object which aren't present in the object constructor
 */
fun Configure_Rectangle() {
    val myRectangle = Rectangle().apply {
        length = 4
        width = 8
        color = 0xFAFAFA
    }
}

/**
 * You can overide a non-abstract open member with an abstract, classes are finl by defult, to make a class inheritable, mark it as open
 */
open class Polygon1 {
    open fun draw() {
        //Some default polygon drawing method
    }
}

abstract class WildShape : Polygon() {
    /**
     * Classes that inherit WildShape need to provide their own draw method instead of using the default on Polygon1
     */
    abstract override fun draw()
}

/**
 * Class for calling multiple methods on an object instance
 */
class Turtle {
    fun penDown()
    {
        println("penDown")
    }
    fun penUp()
    {
        println("penUp")
    }
    fun turn(degrees: Double)
    {
        println(degrees)
    }
    fun forward(pixels: Double)
    {
        println(pixels)
    }
}

/**
 * Calling multiple methods on an object instance (with)
 */
fun Multiple_Methods_on_Object_Instance() {
    val myTurtle = Turtle()
    with(myTurtle) { //draw a 100 pix square
        penDown()
        for (i in 1..4) {
            forward(100.0)
            turn(90.0)
        }
        penUp()
    }
}

/**
 * Java's try with resources syntax
 */
fun Java_Try_With_Resources() {
    val stream = Files.newInputStream(Paths.get("/some/file.txt"))
    stream?.let {
        stream.buffered().reader().use { reader ->
        println(reader.readText())
        }
    }
}

/**
 * Marks code as incomplete
 */
fun calcTaxes(): BigDecimal = TODO("Waiting for feedback from accounting")

/**
 * Data classes are defined via the use of the 'data' modifier
 */
data class Employee(val name: String, val id: Int) {
    /**
     * overrides the default equals method by making two Employees equal if they have the same id
     */
    override fun equals(other: Any?) =
        other is Employee && other.id == this.id
}

fun Employee_Calling_Function() {
    val employee = Employee("Alex", 1)
    println("${employee}\n")                                          // 3

    val secondEmployee = Employee("Alex", 1)
    val thirdEmployee = Employee("Max", 2)
    val fourthEmployee = Employee("Ted", 1)

    println("employee == secondEmployee: ${employee == secondEmployee}\n")   // 4
    println("employee == thirdEmployee: ${employee == thirdEmployee}\n")
    println("employee == fourthEmployee: ${employee == fourthEmployee}\n")

    // hashCode() function - data class instances with exactly matching instances have the same hashCode
    println("${employee.hashCode()}\n")
    println("${secondEmployee.hashCode()}\n")
    println("${thirdEmployee.hashCode()}\n")

    // copy() function
    println("${employee.copy()}\n")                 // Auto-generated 'copy' function makes it easy to create a new instance.
    println("${employee === employee.copy()}\n")    // 'copy' creates a new instance, so the object and its copy have distinct references
    println("${employee.copy("Max")}\n")      // When copying, you can change values of certain properties. copy accepts arguments in the same order as the class constructor
    println("${employee.copy(id = 3)}\n")           // Use copy with named arguments to change the value despite of the properties order

    println("name = ${employee.component1()}\n")    //Auto-generated componentN functions let you get the values of properties in the order of declaration
    println("id = ${employee.component2()}\n")
}

//enum syntax
enum class State {
    IDLE, RUNNING, FINISHED
}

enum class Color(val rgb: Int) {                      // 1
    RED(0xFF0000),                                    // 2
    GREEN(0x00FF00),
    BLUE(0x0000FF),
    YELLOW(0xFFFF00);

    fun containsRed() = (this.rgb and 0xFF0000 != 0)  // logical 'and'
}

fun Enum_Caller() {
    val state = State.RUNNING                         // 2
    val message = when (state) {                      // 3
        State.IDLE -> "It's idle\n"
        State.RUNNING -> "It's running\n"
        State.FINISHED -> "It's finished\n"
    }

    println(message)
    val red = Color.RED
    println("${red}\n")                                      // 4
    println("${red.containsRed()}\n")                        // 5
    println("${Color.BLUE.containsRed()}\n")                 // 6
    println("${Color.YELLOW.containsRed()}\n")               // 7
}

sealed class Mammal(val name: String)

class Bobcat(val catName: String) : Mammal(catName)
class Human(val humanName: String, val job: String) : Mammal(humanName)

fun greetMammal(mammal: Mammal): String {
    when (mammal) {
        is Human -> return "Hello ${mammal.name}; You're working as a ${mammal.job}" // 'smart' cast is performed, casting Mammal to Human.
        is Bobcat -> return "Hello ${mammal.name}"  // 'smart' cast is performed, casting Mammal to Cat.
        else -> return "Hello ${mammal.name}"
    }
}

/**
 * Use of Random() function
 */
class LuckDispatcher {
    fun getNumber() {
        var objRandom = Random()
        println("${objRandom.nextInt(90)}\n")
    }
}

fun Luck_Caller() {
    val d1 = LuckDispatcher()             //3
    val d2 = LuckDispatcher()

    d1.getNumber()                        //4
    d2.getNumber()
}

fun rentPrice(standardDays: Int, festivityDays: Int, specialDays: Int): Unit {  //1
    /**
     * Typical usage of an object, as n expression in a simple object/properties structure.
     * It is used to obtain a data type with  single implementationd
     */
    val dayRates = object {                                                     //2
        var standard: Int = 30 * standardDays
        var festivity: Int = 50 * festivityDays
        var special: Int = 100 * specialDays
    }

    val total = dayRates.standard + dayRates.festivity + dayRates.special       //3

    print("Total price: $$total\n")                                             //4
}

/**
 * object declaration isn't an expression, and can't be used in variable assignment. Should use it directly to access
 * its members
 */
object DoAuth {                                                 //1
    fun takeParams(username: String, password: String) {        //2
        println("input Auth parameters = $username:$password")
    }
}

fun object_caller(){
    DoAuth.takeParams("foo", "qwerty") //This calls the object method, this is when the object is actually creted
}

/**
 * A companion object is similar to a static method in Java, and you call its members using the class name as a qualifier. If using as a
 * static function consider using a package-level function instead
 */
class BigBen {
    companion object Bell {
        fun getBongs(numberOfTimes: Int) {
            for (i in 1..numberOfTimes) {
                print("BONG\n")
            }
        }
    }
}

fun Companion_Object_Caller() {
    BigBen.getBongs(12)
}

/**
 * Higher order functions take in other functions as parameters (used in a similar way to function pointers/functors/callbacks in C)
 * parameter syntax is (..., callback_name: (parameters) -> return type, ...)
 */
fun calculate(x: Int, y: Int, operation: (Int, Int) -> Int): Int {
    return operation(x,y)
}

fun sum(x: Int, y: Int) = x + y

fun absDifference(x: Int, y: Int) = if (x > y) x - y else y - x

fun CalculateCaller() {
    val sumResult = println("${calculate(4, 5, ::sum)}\n") //:: is the notation that references a function by name in Kotlin, used as functor/callback
    val difference = println("${calculate(4, 8, ::absDifference)}\n") //:: is the notation that references a function by name in Kotlin, used as functor/callback
    val mulResult = println("${calculate(4,6) {a, b -> a * b}}\n") //invokes the higher order function by passing in a lambda as the callback
}

/**
 * Returning functions are a higher order function which return a function
 */
fun operation(): (Int, Int) -> Int {
    return ::power
}

fun power(x: Int, y: Int): Int{
    return if (y > 0) x * power(x, y - 1) else 1
}

/**
 * Lambda functions are a simple way to create functions ad-hoc. All examples create a function object that performs upper-casing.
 * So it's a function from String to String
 */
val upperCase1: (String) -> String = { str: String -> str.uppercase() } // lambda, explicit typing
// lambda is the part in curly braces, which is assigned to a variable of type (String) -> String
val upperCase2: (String) -> String = { str -> str.uppercase() } //type inference inside the lambda
val upperCase3 = { str: String -> str.uppercase() } //type infernce outside of lambda, inferred from type of parameter and return value
// val upperCase4 = { str -> str.uppercase() } //cannot do both together, compiler cannot infer the type this way
val upperCase5: (String) -> String = { it.uppercase() } //can use the implicit it variable for lambdas with a single variable
val upperCase6: (String) -> String = String::uppercase //if lambdas consists of a single function call, can use function pointers

fun uppercase_call()
{
    println(upperCase1("hello"))
    println(upperCase2("hello"))
    println(upperCase3("hello"))
    println(upperCase5("hello"))
    println(upperCase6("hello"))
}

/**
 * Extension functions and properties - Kotlin lets you add new members to any class with the extensions mechanism.
 * There are 2 types of extensions: extension functions and extension properties
 */
data class Item(val name: String, val price: Float)

data class Order(val items: MutableList<Item>)

fun Order.maxPricedItemValue(): Float = this.items.maxByOrNull { it.price }?.price ?: 0F    // Adds an extension function for the Order type
fun Order.maxPricedItemName() = this.items.maxByOrNull { it.price }?.name ?: "NO_PRODUCTS"  // Adds another extension for the Order type

val Order.commaDelimitedItemNames: String get() = items.map { it.name }.joinToString() //Adds an extension property for the order type.

fun Extension_Function_Caller() {
    val order = Order(mutableListOf(Item("Bread", 25.0F), Item("Wine", 29.0F), Item("Water", 12.0F)))

    println("Max priced item name: ${order.maxPricedItemName()}\n")                           // 4
    println("Max priced item value: ${order.maxPricedItemValue()}\n")
    println("Items: ${order.commaDelimitedItemNames}\n")                                      // 5
}

class Collections {
    /**
     * In Kotlin lists can either be mutable (MutableList) or read-only (List). For list creation, use the standard library functions listOf()
     * for read-only lists and mutableListOf for mutable lists. To preven unwanted modifications, cast your items to list
     */
    val systemUsers: MutableList<Int> = mutableListOf(1, 2, 3)
    val sudoers: List<Int> = systemUsers

    fun addSystemUser(newUser: Int) {
        systemUsers.add(newUser)
    }

    fun getSysSudoers(): List<Int> {
        return sudoers
    }

    fun ListFunctions() {
        addSystemUser(4)                                      //Adds int to lst
        println("Tot sudoers: ${getSysSudoers().size}\n")             //Prints the total list size
        getSysSudoers().forEach {                                     //iterates through list with forEach
                i ->
            println("Some useful info on user $i\n")
        }
        // getSysSudoers().add0(5) <- Error!                           //Read-only view
    }

    /**
     * A set is an unordered collection that doesn't support duplicates. For creating sets there are setOf() and
     * mutableSetOf(). A read-only view of a mutable set can be obtained by casting it to Set
     */
    val openIssues: MutableSet<String> = mutableSetOf("uniq2", "uniq3", "uniq1")

    fun addIssue(uniqDesc: String): Boolean {
        return openIssues.add(uniqDesc)
    }

    fun getStatusLog(isAdded: Boolean): String {
        return if (isAdded) "Registered correctly\n" else "marked as duplicate and rejected"
    }

    fun SetFunctions() {
        val aNewIssue: String = "uniq4"
        val anIssueAlreadyIn: String = "uniq2"

        println("Issue $aNewIssue ${getStatusLog(addIssue(aNewIssue))}")                              // 4
        println("Issue $anIssueAlreadyIn ${getStatusLog(addIssue(anIssueAlreadyIn))}")                // 5
    }

    /**
     * A map is a collection of key/value pairs, where each key is unique and is used to retrieve
     * the corresponding value. Functions mapOf() and mutableMapOf() create maps. Using the to infix functiom
     * makes inititialization less noisy
     */
    val POINTS_X_PASS: Int = 15
    val EZPassAccounts: MutableMap<String, Int> = mutableMapOf("One" to 100, "Two" to 300, "Three" to 200)
    val EZPassReport: Map<String, Int> =  EZPassAccounts

    fun updatePointsCredit(accountId: String) {
        if (EZPassAccounts.containsKey(accountId)) {
            print("Updating $accountId..\n")
            EZPassAccounts[accountId] = EZPassAccounts.getValue(accountId) + POINTS_X_PASS
        } else {
            print("Error: Trying to update a non-existent account: ${accountId}\n")
        }
    }

    fun accountsReport() {
        print("EZ-Pass report:\n")
        EZPassReport.forEach {
            k, v -> print("ID $k: Credit: $v\n")
        }
    }

    fun MapFunctions() {
        accountsReport()
        updatePointsCredit("One")
        updatePointsCredit("One")
        updatePointsCredit("Five")
        accountsReport()
    }

    /**
     * filter function enables you to filter collections. It takes a filter predicate as a lambda-parameter. The predicate
     * is applied to each element. Elements that make the predicate true are returned in the result collection.
     */
    val numbers = listOf(1, -2, 3, -4, 5, -6)
    val positives = numbers.filter { x -> x >= 0 } //Gets positive numbers
    val negatives = numbers.filter { it < 0 }      //Uses 'it' notation to get negative numbers

    /**
     * map extension function enables you to apply a transformation to all elements in a collection.
     * It takes a transformer function as a lambda-parameter
     */
    val doubled = numbers.map{x -> x *2} //doubles numbers
    val tripled = numbers.map{it * 3}

    //'any' returns true if the collection contains at least one element that matches the given predicate
    val anyNegatives = numbers.any{it < 0}

    //'none' returns true if there are no elements that match the given predicate in the collection.
    val noOdds = numbers.none{it % 2 == 1}

    //'all' returns true if all elements in collection match the given predicate.
    val allLessThanSix = numbers.all{it < 6}

    /**
     * 'find' and 'findLast' functions return the first or the last collection element that matches the
     * given predicate. If there are no such elements, functions return null.
     */
    val words = listOf("Lets", "find", "something", "in", "collection", "somehow")

    val firstMatch = words.find { it.startsWith("some") }
    val lastMatch = words.findLast { it.startsWith("some") }
    val nothing = words.find { it.contains("nothing") } //null

    /**
     * 'first' and 'last' return the first and the last element of the collection correspondingly. You can also use
     * with a predicate; in this case, they return the first or the last element that matches the given predicate.
     */
    val first = numbers.first()
    val last = numbers.last()
    val firstEven = numbers.first { it % 2 == 0 }
    val lastOdd = numbers.last { it % 2 != 0 }

    /**
     * count returns the total number of elements in a collection or the number of elements matching a given predicate.
     */
    val totalCount = numbers.count()
    val evenCount = numbers.count { it % 2 == 0 }

    /**
     * Functions 'associateBy' and 'groupBy' build maps from the elements of a collection indexed by the specified key.
     * The key is defined in the keySelector parameter. You can also specify an optional valueSelector to define
     * what will be stored in the value of the map element.
     *
     * The difference between associateBy and groupBy is how they process objects with the same key:
     * 'associateBy' uses the last suitable element as the value.
     * 'groupBy' builds a list of all suitable elements and puts it in the value.
     * The returned map preserves the entry iteration order of the original collection.
     */
    data class Person(val name: String, val city: String, val phone: String)

    val people = listOf(Person("John", "Boston", "+1-888-123456"),
        Person("Sarah", "Munich", "+49-777-789123"),
        Person("Svyatoslav", "Saint-Petersburg", "+7-999-456789"),
        Person("Vasilisa", "Saint-Petersburg", "+7-999-123456"))

    val phoneBook = people.associateBy { it.phone } //Builds a map from phone numbers to their ownerss information
    //as valueSelector is not provided the values of the map are the Person objects themselves
    val cityBook = people.associateBy(Person::phone, Person::city) //Builds a map from phone numbers to the cities
    //where owners live. Person::city is the valueSelector here, so values of the map are onlly cities
    val peopleCities = people.groupBy(Person::city, Person::name) //Builds a map that contains cities and people
    //living there. The values of the map are lists of people's names
    val lastPersonCity = people.associateBy(Person::city, Person::name) //Builds a map that contains cities and the
    //last person in the collection living in the city

    /**
     * The partition function splits the original collection into a pair of lists using a given predicate:
     * Elements for which the predicate is true = Elements for which the predicate is false.
     */
    val evenOdd = numbers.partition { it % 2 == 0 }

    fun new(){
        val (_positives, _negatives) = numbers.partition { it > 0 } // destructuring declarations only allowed for local variables/values
    }

    /**
     * flatMap transforms each element of a collection into an iterable object and builds a single list of the
     * transformation results. The transformation is user-defined.
     */
    val fruitsBag = listOf("apple","orange","banana","grapes")
    val clothesBag = listOf("shirts","pants","jeans")
    val cart = listOf(fruitsBag, clothesBag)     // output: [[apple, orange, banana, grapes], [shirts, pants, jeans]]
    val mapBag = cart.map { it }                 // output: [[apple, orange, banana, grapes], [shirts, pants, jeans]]
    val flatMapBag = cart.flatMap { it }         // output: [apple, orange, banana, grapes, shirts, pants, jeans]

    /**
     * minOrNull and maxOrNull return the smallest and the largest element of a collection. If the collection is empty, they return null.
     */
    val empty = emptyList<Int>()
    val only = listOf(3)

    fun Min_Max_OrNull(){
        print("Numbers: $numbers, min = ${numbers.minOrNull()} max = ${numbers.maxOrNull()}\n") // 1
        print("Empty: $empty, min = ${empty.minOrNull()}, max = ${empty.maxOrNull()}\n")        // 2
        print("Only: $only, min = ${only.minOrNull()}, max = ${only.maxOrNull()}\n")            // 3
    }

    /**
     * sorted returns a list of collection elements sorted according to their natural sort order (ascending).
    sortedBy sorts elements according to natural sort order of the values returned by specified selector function.
     */
    val shuffled = listOf(5, 4, 2, 1, 3, -10)
    val natural = shuffled.sorted()              // sorts in natural order
    val inverted = shuffled.sortedBy { -it }     // sorts in inverted natural order by using -it as a selector
    val descending = shuffled.sortedDescending() // sorts in inverted natural order
    val descendingBy = shuffled.sortedByDescending { abs(it)  } // sorts in inverted natural order of absolute values by using
                                                                // abs(it) as a selector function

    /**
     * When applied to a map, [] operator returns the value corresponding to the given key, or null if there is no such key in the map.
     * getValue function returns an existing value corresponding to the given key or throws an exception if the key wasn't found.
     * For maps created with withDefault, getValue returns the default value instead of throwing an exception.
     */
    val map = mapOf("key" to 42)

    val value1 = map["key"]                                     // 1
    val value2 = map["key2"]                                    // 2

    val value3: Int = map.getValue("key")                       // 1

    val mapWithDefault = map.withDefault { k -> k.length }
    val value4 = mapWithDefault.getValue("key2")                // 3

    fun tryMapGetValue() {
        try {
            map.getValue("anotherKey")                              // 4
        } catch (e: NoSuchElementException) {
            println("Message: $e")
        }
    }
}

class ScopeFunctions {
    fun customPrint(s: String) {
        print(s.uppercase())
    }
    /**
     * The Kotlin standard library function let can be used for scoping and null-checks. When called on an object, let
     * executes the given block of code and returns the result of its last expression. The object is accessible inside
     * the block by the reference it (by default) or a custom name.
     */
    fun LetFunctions() {

        val empty1 = "test".let {  //assigns value "test" to val 'empty1'
            customPrint(it)      //calls the function on the variable by the 'it' reference prints "test" in uppercase
            it.isEmpty()         //returns the value of the expression, in this case assigning the boolean false to val 'empty'
        }
        print("is empty: $empty1\n")

        val empty = "test".let { nestring -> //assigns value "test" to val 'empty', uses custom name
            customPrint(nestring)      //calls the function on the variable by the 'it' reference prints "test" in uppercase
            nestring.isEmpty()         //returns the value of the expression, in this case assigning the boolean false to val 'empty'
        }
        print("is empty: $empty\n")

        fun printNonNull(str: String?) {
            print("Printing \"$str\":\n")

            str?.let {
                print("\t")
                customPrint(it)
                print("\n")
            }
        }

        fun printIfBothNonNull(strOne: String?, strTwo: String?) {
            strOne?.let { firstS -> //assigns a custom name, so value can be accessed within nested block
                strTwo?.let { secondS ->
                    customPrint("$firstS : $secondS")
                    print("\n")
                }
            }
        }

        printNonNull(null)
        printNonNull("my string")
        printIfBothNonNull("First", "Second")
    }

    /**
     * 'run' is another scoping function from the standard library. It also exectues a code block and returns its result, with
     * a difference being that the object is accessed using the 'this' keyword. Useful when you want to call an object's methods
     * rather than pass it as an argument
     */
    fun RunFunctions() {
        fun getNullableLength(ns: String?) {
            print("for \"$ns\":\n")
            ns?.run {
                print("\tis empty? " + isEmpty() + "\n")   //inside run object members can be accessed without its name
                print("\tlength = $length\n")
                length                                     //returns given length of a string if not null
            }
        }

        getNullableLength(null)
        getNullableLength("")
        getNullableLength("some string with Kotlin")
    }

    /**
     * with is a non-extension function that can access members of its argument concisely, you can omit the instance name
     * when referring to its members
     */
    class Configuration(var host: String, var port: Int)

    fun WithFunctions() {
        val configuration = Configuration(host = "127.0.0.1", port = 9000)

        with(configuration) {
            print("$host:$port\n")
        }

        //instead of
        print("${configuration.host}:${configuration.port}\n")
    }

    data class Person(var name: String, var age: Int, var about: String) {
        constructor() : this("", 0, "") //default constructor, default values
    }
    /**
     * apply executes a block of code on an object and returns the object itself. Inside the block the object is referenced
     * by 'this'. Handy for initializing objects.
     */
    fun ApplyFunctions() {
        val jake = Person()
        val stringDescription = jake.apply { // applies the code block to the instance
            name = "Jake"
            age = 30
            about = "Android Developer" //the return value is the instance so can be chained to other operations
        }.toString()

        print(stringDescription)
    }

    /**
     * 'also' works like 'apply'. it executes a given block and returns the object called. Inside the block, the object is
     * referenced by 'it', so its easier to pass as an argument. This function is handy for embedding additional actions,
     * such as logging, in a chain of calls
     */
    fun writeCreationLog(p: Person) {
        println("A new person ${p.name} was created.")
    }

    fun AlsoFunctionality() {
        val jake = Person("Jake", 30, "Android developer").also {
            writeCreationLog(it)
        }
    }
}

class Delegation {
    /**
     * Kotlin supports easy implementation of the delegation pattern on the native level without any boilerplate code
     */
    interface SoundBehaviour {
        fun makeSound()
    }

    class ScreamBehaviour(val ne:String) : SoundBehaviour {
        override fun makeSound() = println("${ne.toUpperCase()} !!!\n")
    }

    class RockAndRollBehaviour(val ne:String) : SoundBehaviour {
        override fun makeSound() = println("I'm The King of Rock 'N' Roll: $ne\n")
    }

    // The classes TomAraya and ElvisPresley implement the interface, but not the method. Insteaad they delegate the method calls
    // to the responsible implementation. The delegate object is defined after the by keyword. No boilerplate code is required
    class TomAraya(ne: String): SoundBehaviour by ScreamBehaviour(ne)

    class ElvisPresley(ne:String) : SoundBehaviour by RockAndRollBehaviour(ne)

    fun DelegationPatternCalls(){
        val tomAraya = TomAraya("Thrash Metal")
        tomAraya.makeSound()
        val elvisPresley = ElvisPresley("Dancin' to the Jailhouse Rock")
        elvisPresley.makeSound()
    }


    /**
     * With some common kinds of properties, even though you can implement them manually every time you need them, it is more helpful to implement them once, add them to a library,
     * and reuse them later. For example:
     *
     * Lazy properties: the value is computed only on first access.
     * Observable properties: listeners are notified about changes to this property.
     * Storing properties in a map instead of a separate field for each property.
     * To cover these (and other) cases, Kotlin supports delegated properties:
     *
     * The syntax is: val/var <property name>: <Type> by <expression>. The expression after by is a delegate, because the get() (and set())
     * that correspond to the property will be delegated to its getValue() and setValue() methods. Property delegates don’t have to implement
     * an interface, but they have to provide a getValue() function (and setValue() for var s).
     */
    class Example {
        var p: String by Delegate()

        override fun toString() = "Example Class"
    }

    class Delegate() {
        operator fun getValue(thisRef: Any?, prop: KProperty<*>): String {
            return "$thisRef, thank you for delegating '${prop.name}' to me!\n"
        }

        operator fun setValue(thisRef: Any?, prop: KProperty<*>, value: String) {
            print("$value has been assigned to ${prop.name} in $thisRef\n")
        }
    }

    /**
     * When you read from p, which delegates to an instance of Delegate, the getValue() function from Delegate is called. Its first parameter is
     * the object you read p from, and the second parameter holds a description of p itself (for example, you can take its name).
     * lazy() is a function that takes a lambda and returns an instance of Lazy<T>, which can serve as a delegate for implementing a lazy property. The
     * first call to get() executes the lambda passed to lazy() and remembers the result. Subsequent calls to get() simply return the remembered result
     */
    fun DelegatedPropertiesCall(){
        val e = Example()
        println(e.p)  //Delegate().getValue - Output: Example class, thank you for delegating 'p' to me!
        e.p = "NEW"   //Delegate().setValue - Output: NEW has been assigned to p in Example Class
    }

    //Kotlin standard library contains a bunch of useful delegates, like 'lazy', 'observable' and others. You may use them as is.
    //For example 'lazy' is used for lazy initialization
    class LazySample {
        init {
            print("created\n")
        }

        val lazyStr: String by lazy {
            print("computed!\n")
            "my lazy"
        }
    }

    fun LazyInitializationCalls() {
        val sample = LazySample()
        print("lazyStr = ${sample.lazyStr}\n")  //First call to get() executes the lambda expression passed to lazy() as an argument and saves the result
        print(" = ${sample.lazyStr}\n")         //Further calls to get() return the saved result only i.e. my lazy
    }


    //If you want thread safety, use blockingLazy() instead: it guarantees that the values will be computed only in one thread and that all threads will see the same value.
    //If the synchronization of the initialization delegate is not required to allow multiple threads to execute it simultaneously, pass LazyThreadSafetyMode.PUBLICATION as a paremeter to lazy()
    //If you're sure that the initialization will always happen in the same thread as the one where you use the property, you can use LazyThreadSafetyMode.NONE.

    /**
     * Delegates.observable() takes two arguments: the initial value and a handler for modifications. The handler is called every time you assign to the property
     * (after the assignment has been performed). It has three parameters: the property being assigned to, the old value, and the new value
     */
    class Users {
        var name: String by Delegates.observable("<no name>") {
            prop, older, newer ->
            println("$older -> $newer\n")
        }
    }

    fun UsersCaller() {
        val users = Users()
        users.name = "first"
        users.name = "second"
        users.name = "third"
        print("${users.name}") //Output:   <no name> -> first
                                        // first -> second
                                        // second -> third
                                        // third
    }

    /**
     * A property can delegate its getter and setter to another property. Such delegation is available for both top-level and class properties (member and extension). The delegate property can be:
     * A top-level property
     * A member or an extension property of the same class
     * A member or an extension property of another class
     * To delegate a property to another property, use the :: qualifier in the delegate name, for example, this::delegate or MyClass::delegate.
     * Kotlin provides a mechanism of delegated properties that allows delegating the calls of the property set and get methods to a certain object.
     * The delegate object in this case should have the method getValue.  For mutable properties, you'll also need setValue
     */
    var topLevelInt: Int = 0

    class ClassWithDelegate(val anotherClassInt: Int )

    class MyClass(var memberInt: Int, val anotherClassInstance: ClassWithDelegate){
        var delegatedToMember: Int by this::memberInt
        //var delegatedToTopLevel: Int by Delegation::topLevelInt - returns error investigte later

        val delegatedToAnotherClass: Int by anotherClassInstance::anotherClassInt
    }
    var MyClass.extDelegated: Int by ::topLevelInt

    /**
     * This may be useful, for example, when you want to rename a property in a backward-compatible way: introduce a new property,
     * annotate the old one with the @Deprecated annotation, and delegate its implementation.
     */
    class MuClass {
        var newName: Int = 0
        @Deprecated("Use 'newName' instead", ReplaceWith("newName"))
        var oldName: Int by this::newName
    }

    fun MuClassCaller() {
        val muClass = MuClass()
        // Notification: 'oldName: Int' is deprecated.
        // Use 'newName' instead
        muClass.oldName = 42
        println(muClass.newName) // 42
    }

    /**
     * Property delegation can be used for storing properties in a map. This is useful for tasks like parsing JSON, and other 'dynamic' stuff.
     * This also works for var ’s properties if you use a MutableMap instead of a read-only Map:
     */
    class User(val map: Map<String, Any?>) {
        val name: String by map
        val age: Int     by map
    }

    fun PropertyDelegationCalls() {
        val user = User(mapOf(
            "name" to "John Doe",
            "age" to 25
        ))

        print("name = ${user.name}, age = ${user.age}\n")
    }

    /**
     * The Delegation pattern has proven to be a good alternative to implementation inheritance, and Kotlin supports it natively requiring zero boilerplate code.
     * A class Derived can implement an interface Base by delegating all of its public members to a specified object:
     *
     * The by -clause in the supertype list for Derived indicates that b will be stored internally in objects of Derived and the compiler will generate all the
     * methods of Base that forward to b
     */
    interface Base {
        val message: String
        fun print()
        fun printMessage()
        fun printMessageLine()
    }

    class BaseImpl(val x: Int) : Base {
        override val message = "BaseImpl: x = $x\n"
        override fun print() { print("$message\n") }
        override fun printMessage() { print("x\n") }
        override fun printMessageLine() { println("x\n") }
    }

    class Derived(b: Base) : Base by b{
        override fun printMessage() { print("abc\n") }
        // This property is not accessed from b's implementation of `print`
        override val message = "Message of Derived\n"
    }

    fun DelegationCaller() {
        val _b = BaseImpl(10)
        Derived(_b).print()
        Derived(_b).printMessage()
        Derived(_b).printMessageLine()
        print("${Derived(_b).message}\n") //if not overridden in Derived will output "BaseImpl: x = 10" else "Message of Derived\n"
    }

    /**
     * You can declare local variables as delegated properties. For example, you can make a local variable lazy
     * The memoizedFoo variable will be computed on first access only. If someCondition fails, the variable won't be computed at all.
     */
    val someCondition = true

    class Foo{
        fun isvalid() = true
        fun doSomething(){ }
    }

    fun example(computeFoo: () -> Foo) {
        val memoizedFoo by lazy(computeFoo)

        if (someCondition && memoizedFoo.isvalid()) {
            memoizedFoo.doSomething()
        }
    }

    /**
     * For a read-only property (val), a delegate should provide an operator function getValue() with the following parameters:
     *  thisRef must be the same type as, or a supertype of, the property owner (for extension properties, it should be the type being extended).
     *  property must be of type KProperty<*> or its supertype.
     *  getValue() must return the same type as the property (or its subtype).
     *
     * For a mutable property (var), a delegate has to additionally provide an operator function setValue() with the following parameters:
     * thisRef must be the same type as, or a supertype of, the property owner (for extension properties, it should be the type being extended).
     * property must be of type KProperty<*> or its supertype.
     * value must be of the same type as the property (or its supertype
     *
     * getValue() and/or setValue() functions can be provided either as member functions of the delegate class or as extension functions. The latter is handy
     * when you need to delegate a property to an object that doesn't originally provide these functions. Both of the functions need to be marked with the operator keyword.
     */
    class Resource

    class Owner {
        val valResource: Resource by ResourceDelegate()
        var varResource: Resource by ResourceDelegoat()
    }

    class ResourceDelegate {
        operator fun getValue(thisRef: Owner, property: KProperty<*>): Resource {
            return Resource()
        }
    }

    class ResourceDelegoat(private var resource: Resource = Resource()) {
        operator fun getValue(thisRef: Owner, property: KProperty<*>): Resource {
            return resource
        }
        operator fun setValue(thisRef: Owner, property: KProperty<*>, value: Any?) {
            if (value is Resource) { //type
                resource = value
            }
        }
    }

    /**
     * You can create delegates as anonymous objects without creating new classes, by using the interfaces ReadOnlyProperty and ReadWriteProperty from the
     * Kotlin standard library. They provide the required methods: getValue() is declared in ReadOnlyProperty; ReadWriteProperty extends it and adds setValue().
     * This means you can pass a ReadWriteProperty whenever a ReadOnlyProperty is expected.
     */
    fun resourceDelegold(): ReadWriteProperty<Any?, Int> =
        object : ReadWriteProperty<Any?, Int> {
            var curValue = 0
            override fun getValue(thisRef: Any?, property: KProperty<*>): Int = curValue
            override fun setValue(thisRef: Any?, property: KProperty<*>, value: Int) {
                curValue = value
            }
        }

    val readOnly: Int by resourceDelegold()  // ReadWriteProperty as val
    var readWrite: Int by resourceDelegold()

    /**
     * Under the hood, the Kotlin compiler generates an auxiliary property for every delegated property and then delegates to it. For example, for
     * the property prop it generates the hidden property prop$delegate, and the code of the accessors simply delegates to this additional property
     */
    class Type
    class MyDelegate {
        operator fun getValue(any: Any?, property: KProperty<*>): Type = Type()
        operator fun setValue(any: Any?, property: KProperty<*>, type: Type) { type }
    }

    class Cee {
        var prop: Type by MyDelegate()
    }

    /**this code is generated by the compiler instead:*/
    /*class Cee {
        private val prop$delegate = MyDelegate()
        private val prop$delegate = MyDelegate()
        var prop: Type
            get() = prop$delegate.getValue(this, this::prop)
        set(value: Type) = prop$delegate.setValue(this, this::prop, value)
    }*/
    /**
     * The Kotlin compiler provides all the necessary information about prop in the arguments: the first argument this refers
     * to an instance of the outer class C, and this::prop is a reflection object of the KProperty type describing prop itself.
     */
    class C<Type> {
        private var impl: Type = TODO()
        var prop: Type by ::impl
    }

    /**
     * Property accessors of the prop variable invoke the impl variable directly, skipping the delegated property's getValue and setValue
     * operators, and thus the KProperty reference object is not needed. For the code above, the compiler generates the following code:
     */
    /*class C<Type> {
        private var impl: Type = TODO()

        var prop: Type
            get() = impl
            set(value) {
                impl = value
            }

        fun getProp$delegate(): Type = impl // This method is needed only for reflection
    }*/

    /**
     * By defining the provideDelegate operator, you can extend the logic for creating the object to which the property implementation is delegated. If the object used
     * on the right-hand side of by defines provideDelegate as a member or extension function, that function will be called to create the property delegate instance.
     * One of the possible use cases of provideDelegate is to check the consistency of the property upon its initialization. For example, to check the property name
     * before binding, you can write something like this:
     */
    class MyUI{
        fun <T> MyUI.bindResource(
            id: ResourceID<T>,
            propertyName: String
        ): ReadOnlyProperty<MyUI, T> {
            checkProperty(this, propertyName)
            TODO() //Create Delegate
        }

        private fun checkProperty(myUI: Delegation.MyUI, propertyName: String) {

        }
        //val image by bindResource(ResourceID.image_id) - Errors, will require inveetigation
        //val text by bindResource(ResourceID.text_id)
    }

    class ResourceDelegod<T> : ReadOnlyProperty<MyUI, T> {
        override fun getValue(thisRef: MyUI, property: KProperty<*>): T { TODO() }
    }

    class ResourceLoader<T>(id: ResourceID<T>) {
        operator fun provideDelegate(thisRef: MyUI, prop: KProperty<*>): ReadOnlyProperty<MyUI, T> {
            checkProperty(thisRef, prop.name)
            return ResourceDelegod()
        }

        private fun checkProperty(thisRef: Delegation.MyUI, name: String) {
            TODO()
        }
    }

    class ResourceID<T> {
        class image_id {

        }
    }

    /**
     * In the generated code, the provideDelegate method is called to initialize the auxiliary prop$delegate property. Compare the generated code
     * for the property declaration val prop: Type by MyDelegate() with the generated code above (when the provideDelegate method is not present):
     */
    class E {
        var prop: Type by MyDelegate()
    }

    // this code is generated by the compiler
    // when the 'provideDelegate' function is available:
    /*class Ee {
        // calling "provideDelegate" to create the additional "delegate" property
        private val prop$delegate = MyDelegate().provideDelegate(this, this::prop)
        var prop: Type
            get() = prop$delegate.getValue(this, this::prop)
        set(value: Type) = prop$delegate.setValue(this, this::prop, value)
    }*/

    /**
     * Note that the provideDelegate method affects only the creation of the auxiliary property and doesn't affect the code generated for the getter or the setter.
     * With the PropertyDelegateProvider interface from the standard library, you can create delegate providers without creating new classes.
     */
    val provider = PropertyDelegateProvider { thisRef: Any?, property ->
        ReadOnlyProperty<Any?, Int> { _, property -> 42 }
    }
    val delegate: Int by provider

    /**
     *
     */
}

class ProductivityBoosters {
    /**
     * Kotlin supports passing arguments to methods and constructors according to the order they are defined. Kotlin also supports
     * named arguments to allow clearer invocations and avoid mistakes with the order of arguments.
     */
    fun format(username: String, domain: String) = "$username@$domain\n"

    fun NamedArgumentsCalls(){
        print(format("mario", "example.com"))
        print(format("domain.com", "username"))
        print(format(username = "foo", domain = "bar.com"))
        print(format(domain = "new.com", username = "user"))  //when invoking a function with name argumentss, you can specify them in any order
    }

    /**
     * String templates allow you to include variable references and expressions into strings. When the value of a string is requested
     * for example by print() all ef references and expressions substituted with valueds
     */
    val greeting = "Kotliner"

    fun StringTemplateCalls() {
        println("Hello $greeting")                  // 1
        println("Hello ${greeting.toUpperCase()}")  // 2
    }

    /**
     * Destructuring declaration syntax lets you define an instance without a specific name, therefore saving a few lines of code
     */
    fun findMinMax(list: List<Int>): Pair<Int, Int> {
        // do the math
        return Pair(50, 100)
    }

    fun DestructuringDeclarationSyntax(){
        val(x, y) = arrayOf(5, 10, 15)  //Destructuring Declarations only allowed for local variables/values, this destructures an array

        val map = mapOf("Alice" to 21, "Bob" to 25)
        for ((name, age) in map) {   //Destructures a map
            println("$name is $age years old\n")
        }

        val (min, max) = findMinMax(listOf(100, 90, 50, 98, 76, 83)) //Built in Pair and Triple types support destructuring
    }

    data class User (val username: String, val email: String)

    fun getUser() = User("Mary", "mary@somewhere.com")

    fun DestructuringDeclarationSyntax1(){
        val user = getUser()
        val (username, email) = user  //destructures an instance
        print(username == user.component1())  //data class automatically defines the component1(0 and component2() methods called during destructuring

        val(_, emailAddress) = getUser() // Use the underscore if you don't need one of the values
    }

    class NewPair<K, V>(val first: K, val second: V) {
        operator fun component1(): K {
            return first
        }

        operator fun component2(): V {
            return second
        }
    }

    fun DestructuringDeclarationSyntax2(){
        val (num, name) = NewPair(1, "one") //Defines a custom Pair class with component1() and component2() methods.

        println("num = $num, name = $name")
    }

    /**
     * The Kotlin compiler is smart enough to perform type casts automatically in most cases, including:
     * Casts from nullable types to their non-nullable counterparts.
     * Casts from a supertype to a subtype.
     */
    fun SmartCasts(){
        val date: ChronoLocalDate? = LocalDate.now() //declares a nullable variable

        if (date != null) {
            println(date.isLeapYear) //smart cast to non-nullable
        }

        if (date != null && date.isLeapYear) { //smart-cast to non-nullable inside condition
            print("It's a leap year\n")
        }

        if (date is LocalDate) { //smart caas too sub-type LocalDate
            val month = date.monthValue
            print(month)
        }
    }
}

/**
 * CODING CONVENTIONS
 *
 * CLASS LAYOUT
 * The contents of a class should go in the following order
 * 1. Property declarations and initializer blocks
 * 2. Secondary Constructors
 * 3. Method declarations
 * 4. Companion object
 *
 * Do not sort the method declarations alphabetically or by visibility, and do not separate regular methods from extension methods
 * Instead, put related stuff together, so someone reading the class from top to bottom can follow the logic of what's happening.
 * Choose an order (either higher-order stuff first or vice-versa and stick to it)
 *
 * Put nested classes next to the code that uses those classes. If the classes are intended to be used externally and aren't referenced
 * in the class, place them at the end, after the companion object. Always put overloads next to each other in a class
 *
 * NAMING RULES
 * Names of packages are always lowercase and do not use underscores i.e. (org.example.project). Multiword names should be camelcase
 * *** Names of classes and objects start with an uppercase letter and use camel case
 * open class DeclarationProcessor { /*...*/ }
 * object EmptyDeclarationProcessor : DeclarationProcessor()  { /*...*/ }
 *
 * *** Names of functions, properties and local variables start with a lowercase letter and use camel case
 * fun processDeclarations() { /*...*/ }
 * var declarationCount = 1
 *
 * *** Factory functions used to create instances of classes can have the same name as the abstract return type
 * interface Foo { /*...*/ }
 * class FooImpl : Foo { /*...*/ }
 * fun Foo(): Foo { return FooImpl() }
 *
 * *** In tests (and only in tests), you can use method names with spaces enclosed in backticks.
 * Note that such method names are currently not supported by the Android runtime. Underscores in method names are also allowed in test code.
 * class MyTestCase {
 *     @Test fun `ensure everything works`() { /*...*/ }
 *     @Test fun ensureEverythingWorks_onAndroid() { /*...*/ }
 * }
 *
 * *** Names of constants (properties marked with const, or top-level or object val properties with no custom get function
 * that hold deeply immutable data) should use uppercase underscore-separated (screaming snake case) names:
 *
 * const val MAX_COUNT = 8
 * val USER_NAME_FIELD = "UserName"
 *
 * *** Names of top-level or object properties which hold objects with behaviour or mutable data should use camel case
 * val mutableCollection: MutableSet<String> = HashSet()
 * val personName = Person()
 *
 * *** Names of properties holding references to singleton objects can use the same naming style as object declarations:
 * val PersonComparator: Comparator<Person> = /*...*/
 *
 * *** For enum constants, it's OK to use either uppercase underscore-separated names (screaming snake case)
 * (enum class Color { RED, GREEN }) or upper camel case names, depending on the usage.
 *
 * *** If a class has two properties which are conceptually the same but one is part of a public API and another is an
 * *** implementation detail, use an underscore as the prefix for the name of the private property
 * class C {
 * 	 private val _elementList = mutableListOf<Element>()
 * 	 
 * 	 val elementList: List<Element>
 *       get() = _elementList
 * 	 }
 *
 * *** Put spaces around binary operators (a + b). Exception: don't put spaces around the "range to" operator (0..i).
 * *** Do not put spaces around unary operators (a++).
 * *** Put spaces between control flow keywords (if, when, for, and while) and the corresponding opening parenthesis.
 * *** Do not put a space before an opening parenthesis in a primary constructor declaration, method declaration or method call.
 * *** Never put a space after (, [, or before ], )
 * *** Never put a space around . or ?.: foo.bar().filter { it > 2 }.joinToString(), foo?.bar()
 * *** Put a space after //: // This is a comment
 * *** Do not put spaces around angle brackets used to specify type parameters: class Map<K, V> { ... }
 * *** Do not put spaces around ::: Foo::class, String::length
 * *** Do not put a space before ? used to mark a nullable type: String?
 *
 * *** Put a space before : in the following cases:
 * *** when it's used to separate a type and a supertype
 * *** when delegating to a superclass constructor or a different constructor of the same class
 * *** after the object keyword
 * abstract class Foo<out T : Any> : IFoo {
 *     abstract fun foo(a: Int): T
 * }
 * 
 * class FooImpl : Foo() {
 *     constructor(x: String) : this(x) { /*...*/ }
 *     
 *     val x = object : IFoo { /*...*/ }
 * }
 *
 * ***  Classes with longer headers should be formatted so that each primary constructor parameter is in a separate line with indentation.
 * ***  Also, the closing parenthesis should be on a new line. If you use inheritance, the superclass constructor call or the list of
 * ***  implemented interfaces should be located on the same line as the parenthesis:
 * class Person(
 *     id: Int,
 *     name: String,
 *     surname: String
 * ) : Human(id, name) { /*...*/ }
 *
 * *** For multiple interfaces, the superclass constructor call should be located first and then each interface should be located in a different line:
 * class Person(
 *     id: Int,
 *     name: String,
 *     surname: String
 * ) : Human(id, name),
 *     KotlinMaker { /*...*/ }
 *
 * *** For classes with a long supertype list, put a line break after the colon and align all supertype names horizontally:
 * class MyFavouriteVeryLongClassHolder :
 *     MyLongHolder<MyFavouriteVeryLongClass>(),
 *     SomeOtherInterface,
 *     AndAnotherOne {
 *     
 *     fun foo() { /*...*/ }
 * }
 *
 * ***  To clearly separate the class header and body when the class header is long, either put a blank line following the class header
 * ***  (as in the example above), or put the opening curly brace on a separate line: Use regular indent (four spaces) for constructor parameters
 * class MyFavouriteVeryLongClassHolder :
 *     MyLongHolder<MyFavouriteVeryLongClass>(),
 *     SomeOtherInterface,
 *     AndAnotherOne
 * {
 *     fun foo() { /*...*/ }
 * }
 *
 * *** If a declaration has multiple modifiers, always put them in the following order:
 * public / protected / private / internal
 * expect / actual
 * final / open / abstract / sealed / const
 * external
 * override
 * lateinit
 * tailrec
 * vararg
 * suspend
 * inner
 * enum / annotation / fun // as a modifier in `fun interface`
 * companion
 * inline / value
 * infix
 * operator
 * data
 *
 * *** Place all annotations before modifiers: Unless you're working on a library, omit redundant modifiers (for example, public).
 * @Named("Foo")
 * private val foo: Foo
 *
 * *** Place annotations on separate lines before the declaration to which they are attached, and with the same indentation:
 * @Target(AnnotationTarget.PROPERTY)
 * annotation class JsonExclude
 *
 * *** Annotations without arguments may be placed on the same line:
 * @JsonExclude @JvmField
 * var x: String
 *
 * *** A single annotation without arguments may be placed on the same line as the corresponding declaration:
 * @Test fun foo() { /*...*/ }
 *
 * *** File annotations are placed after the file comment (if any), before the package statement, and are separated from package
 * *** with a blank line (to emphasize the fact that they target the file and not the package).
 * /** License, copyright and whatever */
 * @file:JvmName("FooBar")
 * 
 * package foo.bar
 *
 * *** If the function signature doesn't fit on a single line, use the following syntax:
 * fun longMethodName(
 *     argument: ArgumentType = defaultValue,
 *     argument2: AnotherArgumentType,
 * ): ReturnType {
 *     // body
 * }
 *
 * *** Prefer using an expression body for functions with the body consisting of a single expression.
 * fun foo() = 1        // good
 *
 * *** If the function has an expression body whose first line doesn't fit on the same line as the declaration, put the = sign
 * *** on the first line and indent the expression body by four spaces.
 * fun f(x: String, y: String, z: String) =
 *     veryLongFunctionCallWithManyWords(andLongParametersToo(), x, y, z)
 *
 * *** For very simple read-only properties, consider one-line formatting:
 * val isEmpty: Boolean get() = size == 0
 *
 * *** For more complex properties, always put get and set keywords on separate lines:
 * val foo: String
 *     get() { /*...*/ }
 *
 * *** For properties with an initializer, if the initializer is long, add a line break after the = sign and indent the initializer by four spaces:
 * private val defaultCharset: Charset? =
 *     EncodingRegistry.getInstance().getDefaultCharsetForPropertiesFiles(file)
 *
 * *** If the condition of an if or when statement is multiline, always use curly braces around the body of the statement. Indent each subsequent line of the
 * *** condition by four spaces relative to statement begin. Put the closing parentheses of the condition together with the opening curly brace on a separate line:
 * if (!component.isSyncing &&
 *     !hasAnyKotlinRuntimeInScope(module)
 * ) {
 *     return createKotlinNotConfiguredPanel(module)
 * }
 *
 * *** In a when statement, if a branch is more than a single line, consider separating it from adjacent case blocks with a blank line:
 * private fun parsePropertyValue(propName: String, token: Token) {
 *     when (token) {
 *         is Token.ValueToken ->
 *             callback.visitValue(propName, token.value)
 *         
 *         Token.LBRACE -> { // ...
 *         }
 *     }
 * }
 *
 * *** Put short branches on the same line as the condition, without braces.
 * when (foo) {
 *     true -> bar() // good
 *     false -> { baz() } // bad
 * }
 *
 * *** In long argument lists, put a line break after the opening parenthesis. Indent arguments by four spaces. Group multiple closely related arguments on the same line.
 * drawSquare(
 *     x = 10, y = 10,
 *     width = 100, height = 100,
 *     fill = true
 * )
 *
 * *** When wrapping chained calls, put the . character or the ?. operator on the next line, with a single indent:
 * val anchor = owner
 *     ?.firstChild!!
 *     .siblings(forward = true)
 *     .dropWhile { it is PsiComment || it is PsiWhiteSpace }
 *
 * *** In lambda expressions, spaces should be used around the curly braces, as well as around the arrow which separates the parameters from the body.
 * *** If a call takes a single lambda, pass it outside of parentheses whenever possible.
 * list.filter { it > 10 }
 *
 * *** If assigning a label for a lambda, do not put a space between the label and the opening curly brace:
 * fun foo() {
 *     ints.forEach lit@{
 *         // ...
 *     }
 * }
 *
 * *** When declaring parameter names in a multiline lambda, put the names on the first line, followed by the arrow and the newline:
 * appendCommaSeparated(properties) { prop ->
 *     val propertyValue = prop.get(obj)  // ...
 * }
 *
 * If the parameter list is too long to fit on a line, put the arrow on a separate line:
 * foo {
 *     context: Context,
 *     environment: Env
 *     ->
 *     context.configureEnv(environment)
 * }
 *
 * *** A trailing comma is a comma symbol after the last item of a series of elements: Kotlin style guide encourages the use of trailing commas at the declaration site
 * class Person(
 *     val firstName: String,
 *     val lastName: String,
 *     val age: Int, // trailing comma
 * )
 *
 * // Avoid doing this:
 * 
 * /**
 *  * Returns the absolute value of the given number.
 *  * @param number The number to return the absolute value for.
 *  * @return The absolute value.
 * */
 * fun abs(number: Int) { /*...*/ }
 * 
 * // Do this instead:
 * 
 * /**
 *  * Returns the absolute value of the given [number].
 * */
 * fun abs(number: Int) { /*...*/ }
 *
 * *** Don't use curly braces when inserting a simple variable into a string template. Use curly braces only for longer expressions.
 * println("$name has ${children.size} children")
 *
 * *** If you have a functional type or a type with type parameters which is used multiple times in a codebase, prefer defining a type alias for it:
 * *** If you use a private or internal type alias for avoiding name collision, prefer the import … as … mentioned in Packages and Imports.
 * typealias MouseClickHandler = (Any, MouseEvent) -> Unit
 * typealias PersonIndex = Map<String, Person>
 *
 * *** Prefer using the expression form of try, if, and when.
 * return if (x) foo() else bar()
 * return when(x) {
 *     0 -> "zero"
 *     else -> "nonzero"
 * }
 *
 * *** The above is preferable to:
 * if (x)
 *     return foo()
 * else
 *     return bar()
 * when(x) {
 *     0 -> return "zero"
 *     else -> return "nonzero"
 * }
 *
 * *** Prefer using higher-order functions (filter, map etc.) to loops. Exception: forEach (prefer using a regular for loop instead,
 * *** unless the receiver of forEach is nullable or forEach is used as part of a longer call chain).
 *
 * *** Use the until function to loop over an open range:
 * for (i in 0..n - 1) { /*...*/ }  // bad
 * for (i in 0 until n) { /*...*/ }  // good
 *
 * *** Prefer string templates to string concatenation. Prefer multiline strings to embedding \n escape sequences into regular string literals.
 * *** To maintain indentation in multiline strings, use trimIndent when the resulting string does not require any internal indentation, or trimMargin when internal indentation is required:
 * println("""
 *     Not
 *     trimmed
 *     text
 *     """
 *         )
 * 
 * println("""
 *     Trimmed
 *     text
 *     """.trimIndent()
 *         )
 * 
 * println()
 * 
 * val a = """Trimmed to margin text:
 *         |if(a > 1) {
 *         |    return a
 *         |}""".trimMargin()
 * 
 * println(a)
 *
 * *** Declare a function as infix only when it works on two objects which play a similar role. Good examples: and, to, zip. Bad example: add.
 * *** Do not declare a method as infix if it mutates the receiver object.
 *
 * *** A public function/method returning an expression of a platform type must declare its Kotlin type explicitly:
 * fun apiCall(): String = MyJavaApi.getProperty("name")
 *
 * *** Any property (package-level or class-level) initialized with an expression of a platform type must declare its Kotlin type explicitly:
 * class Person {
 *     val name: String = MyJavaApi.getProperty("name")
 * }
 *
 * *** A local value initialized with an expression of a platform type may or may not have a type declaration:
 * fun main() {
 *     val name = MyJavaApi.getProperty("name")
 *     println(name)
 * }
 *
 * *** When writing libraries, it's recommended to follow an additional set of rules to ensure API stability:
 *     Always explicitly specify member visibility (to avoid accidentally exposing declarations as public API
 *     Always explicitly specify function return types and property types (to avoid accidentally changing the return type when the implementation changes)
 *     Provide KDoc comments for all public members, with the exception of overrides that do not require any new documentation (to support generating documentation for the library)
 *
 * *** Apart from the default imports, each file may contain its own import directives. You can import either a single name: or all the accessible contents of a scope: package, class, object, and so on:
 * import org.example.Message // Message is now accessible without qualification
 * import org.example.* // everything in 'org.example' becomes accessible
 * *** If there is a name clash, you can disambiguate by using as keyword to locally rename the clashing entity:
 * import org.example.Message // Message is accessible
 * import org.test.Message as testMessage // testMessage stands for 'org.test.Message'
 * *** The import keyword is not restricted to importing classes; you can also use it to import other declarations:top-level functions and properties,
 * ***  functions and properties declared in object declarations, enum constants (if a top-level declaration is marked private, it is private to the file it's declared in)
 */

class Empty //Both the header and the body are optional; if the class has no body, the curly braces can be omitted.

class Persona constructor(firstName: String) { /*...*/ } //The primary constructor is a part of the class header, and it goes after the class name and optional type parameters
class Personal(firstName: String) { /*...*/ } //If the primary constructor does not have any annotations or visibility modifiers, the constructor keyword can be omitted:
class Customer public @Inject constructor(name: String) { /*...*/ } //If the constructor has annotations or visibility modifiers, the constructor keyword is required and the modifiers go before it

annotation class Inject //required for annotation above

/**
 * The primary constructor cannot contain any code. Initialization code can be placed in initializer blocks prefixed with the init keyword.
 * During the initialization of an instance, the initializer blocks are executed in the same order as they appear in the class body, interleaved with the property initializers:
 * Primary constructor parameters can be used in the initializer blocks. They can also be used in property initializers declared in the class body:
 */
class InitOrderDemo(name: String) {
    val firstProperty = "First property: $name".also(::println)

    init {
        println("First initializer block that prints ${name}")
    }

    val secondProperty = "Second property: ${name.length}".also(::println)

    init {
        println("Second initializer block that prints ${name.length}")
    }
}

/**
 * If the class has a primary constructor, each secondary constructor needs to delegate to the primary constructor, either directly or indirectly through
 * another secondary constructor(s). Delegations to another constructor of the same class is done using the this keyword:
 */
class Personality(val name: String) {
    val children: MutableList<Personality> = mutableListOf()
    constructor(name: String, parent: Personality) : this(name) {
        parent.children.add(this)
    }
}

class Example // All classes in Kotlin have a common superclass, Any, which is the default superclass for a class with no supertypes declared:
// Implicitly inherits from Any. Any has three methods: equals(), hashCode(), and toString(). Thus, these methods are defined for all Kotlin classes.

//By default, Kotlin classes are final – they can’t be inherited. To make a class inheritable, mark it with the open keyword:
open class Base // Class is open for inheritance
{
    val ctx: Context = TODO()
    val attrs: AttributeSet = TODO()

    constructor(ctx: Context) {
        this.ctx = ctx
    }

    constructor(ctx: Context, attrs: AttributeSet) {
        this.ctx = ctx
        this.attrs = attrs
    }
}

/**
 * If the derived class has a primary constructor, the base class can (and must) be initialized in that primary constructor according to its parameters.
 * If the derived class has no primary constructor, then each secondary constructor has to initialize the base type using the super keyword or it has to
 * delegate to another constructor which does. Note that in this case different secondary constructors can call different constructors of the base type:
 */
class OnBase: Base {
    constructor(ctx: Context) : super(ctx)

    constructor(ctx: Context, attrs: AttributeSet) : super(ctx, attrs)
}

/**
 * Kotlin requires explicit modifiers for overridable members and overrides: he override modifier is required for Circle.draw(). If it were missing, the
 * compiler would complain. If there is no open modifier on a function, like Shape.fill(), declaring a method with the same signature in a subclass is
 * not allowed, either with override or without it.
 *
 * A member marked override is itself open, so it may be overridden in subclasses. If you want to prohibit re-overriding, use final:
 *
 * The overriding mechanism works on properties in the same way that it does on methods. Properties declared on a superclass that are then redeclared on
 * a derived class must be prefaced with override, and they must have a compatible type. Each declared property can be overridden by a property with an
 * initializer or by a property with a get method:
 *
 * You can also override a val property with a var property, but not vice versa. This is allowed because a val property essentially declares a get method,
 * and overriding it as a var additionally declares a set method in the derived class.
 * Note that you can use the override keyword as part of the property declaration in a primary constructor:
 */
open class Shape {
    open val vertexCount: Int = 0
    open fun draw() { /*...*/ }
    fun fill() { /*...*/ }
}

class Circle() : Shape() {
    final override fun draw() { /*...*/ }
}

interface OldPolygon {
    fun draw() { /* ... */ } // interface members are 'open' by default
}

open class NewRectangle() : Shape() {
    override val vertexCount = 4
    override fun draw() { /*...*/ } //can be overridden
    val borderColor: String get() = "black"
}

class Square() : NewRectangle(), OldPolygon {
    /**
     * In Kotlin, implementation inheritance is regulated by the following rule: if a class inherits multiple implementations of the same member from its
     * immediate superclasses, it must override this member and provide its own implementation (perhaps, using one of the inherited ones).=
     * To denote the supertype from which the inherited implementation is taken, use super qualified by the supertype name in angle brackets, such as super<Base>:
     */
    // The compiler requires draw() to be overridden:
    override fun draw() {
        super<NewRectangle>.draw() // call to Rectangle.draw()
        super<OldPolygon>.draw() // call to Polygon.draw()
    }
}

class FilledRectangle : NewRectangle() {
    override fun draw() {
        //Calls Rectangle's implementation of draw().
        super.draw()  //Code in a derived class can call its superclass functions and property accessor implementations using the super keyword
        println("Filling the rectangle")

        val filler = Filler()
        filler.drawAndFill()
    }

    /**
     * Inside an inner class, accessing the superclass of the outer class is done using the super keyword qualified with the outer class name: super@Outer:
     */
    inner class Filler {
        fun fill() { println("Filling") }
        fun drawAndFill() {
            super@FilledRectangle.draw() // Calls Rectangle's implementation of draw()
            fill()
            println("Drawn a filled rectangle with color ${super@FilledRectangle.borderColor}") // Uses Rectangle's implementation of borderColor's get()
        }
    }

    // Uses Rectangle's implementation of borderColor's get()
    val fillColor: String get() = super.borderColor //Code in a derived class can call its superclass functions and property accessor implementations using the super keyword
}


class NewPolygon(override var vertexCount: Int = 0) : Shape()

/**
 * During the construction of a new instance of a derived class, the base class initialization is done as the first step (preceded only by evaluation
 * of the arguments for the base class constructor), which means that it happens before the initialization logic of the derived class is run.
 * This means that when the base class constructor is executed, the properties declared or overridden in the derived class have not yet been initialized.
 * Using any of those properties in the base class initialization logic (either directly or indirectly through another overridden open member implementation)
 * may lead to incorrect behavior or a runtime failure. When designing a base class, you should therefore avoid using open members in the constructors,
 * property initializers, or init blocks.
 */
open class Based(val name: String) {

    init { println("Initializing a base class\n") }

    open val size: Int =
        name.length.also { println("Initializing size in the base class: $it\n") }
}

class Derived(
    name: String,
    val lastName: String,
) : Based(name.replaceFirstChar { it.uppercase() }.also { println("Argument for the base class: $it\n") }) {
    init { println("Initializing a derived class\n") }

    override val size: Int =
        (super.size + lastName.length).also { println("Initializing size in the derived class: $it\n") }
}
// Output:
// val derived = Derived("Les", "Tete")
// Argument for the base class: Les
// Initializing a base class
// Initializing size in the base class: 3
// Initializing a derived class
// Initializing size in the derived class: 7

/**
 * Properties in Kotlin classes can be declared either as mutable, using the var keyword, or as read-only, using the val keyword.
 */
class Dummy {
    var stringRepresentation: String
        get() = this.toString()
        //By convention, the name of the setter parameter is value, but you can choose a different name if you prefer.
        set(value) {
            value.toString() // parses the string and assigns values to other properties
        }

    /**
     * By convention, the name of the setter parameter is value, but you can choose a different name if you prefer.
     * If you need to annotate an accessor or change its visibility, but you don't need to change the default implementation, you can define the accessor without defining its body:
     */
    var setterVisibility: String = "abc"
        private set // the setter is private and has the default implementation

    var setterWithAnnotation: Any? = null
        @Inject set // annotate the setter with Inject

    /**
     * In Kotlin, a field is only used as a part of a property to hold its value in memory. Fields cannot be declared directly. However, when a property
     * needs a backing field, Kotlin provides it automatically. This backing field can be referenced in the accessors using the field identifier:
     *
     * The field identifier can only be used in the accessors of the property. A backing field will be generated for a property if it uses
     * the default implementation of at least one of the accessors, or if a custom accessor references it through the field identifier.
     */
    var counter = 0 // the initializer assigns the backing field directly
        set(value) {
            if (value >= 0)
                field = value
            value // ERROR StackOverflow: Using actual name 'counter' would make setter recursive
        }

    /**
     * If you want to do something that does not fit into this implicit backing field scheme, you can always fall back to having a backing property:
     */
    private var _table: Map<String, Int>? = null
    public val table: Map<String, Int>
        get() {
            if(_table == null) {
                _table = HashMap()
            }
            return _table ?: throw AssertionError("Set to null by another thread")
        }
}

/**
 * If the value of a read-only property is known at compile time, mark it as a compile time constant using the const modifier. Such a property needs to fulfil the following requirements:
 * It must be a top-level property, or a member of an object declaration or a companion object.
 * It must be initialized with a value of type String or a primitive type
 * It cannot be a custom getter
 * Such properties can be used in annotations:
 */
const val SUBSYSTEM_DEPRECATED: String = "This subsystem is deprecated"

@Deprecated(SUBSYSTEM_DEPRECATED) fun foon() { /* .. */ }

/**
 * Normally, properties declared as having a non-null type must be initialized in the constructor. However, it is often the
 * case that doing so is not convenient. For example, properties can be initialized through dependency injection, or in the
 * setup method of a unit test. In these cases, you cannot supply a non-null initializer in the constructor, but you still
 * want to avoid null checks when referencing the property inside the body of a class.
 * To handle such cases, you can mark the property with the lateinit modifier:
 */
public class MyTest {
    lateinit var subject: TestSubject

    @SetUp fun setup() {
        subject = TestSubject()
    }

    @Test fun test() {
        if (this::subject.isInitialized) { //To check whether a lateinit var has already been initialized, use .isInitialized on the reference to that property:
            subject.method()  // dereference directly
        }
    }
}

annotation class Test

annotation class SetUp

class TestSubject{
    fun method() { }
}

/**
 * Interfaces in Kotlin can contain declarations of abstract methods, as well as method implementations. What makes them different from abstract classes
 * is that interfaces cannot store a state. They can have properties, but these need to be abstract or provide accessor implementations. A class or object can implement one or more interfaces:
 *
 * You can declare properties in interfaces. A property declared in an interface can either be abstract or provide implementations for accessors. Properties
 * declared in interfaces can't have backing fields, and therefore accessors declared in interfaces can't reference them:
 */
interface MyInterface {
    fun bar()

    val prop: Int // abstract

    val propertyWithImplementation: String
        get() = "foo"

    fun foo() {
        print(prop)
    }
}

class Child : MyInterface {
    override val prop: Int = 29
    override fun bar() {
        // body
    }
}

/**
 * An interface can derive from other interfaces, meaning it can both provide implementations for their members and declare new
 * functions and properties. Quite naturally, classes implementing such an interface are only required to define the missing implementations:
 */
interface Named {
    val name: String
}

interface Dude : Named {
    val firstName: String
    val lastName: String

    override val name: String get() = "$firstName $lastName"
}

class Position

data class Employee1(
    // implementing 'name' is not required
    override val firstName: String,
    override val lastName: String,
    val position: Position
) : Dude

/**
 * When you declare many types in your supertype list, you may inherit more than one implementation of the same method:
 */
interface A {
    fun foo() { print("A") }
    fun bar()
}

interface B {
    fun foo() { print("B") }
    fun bar() { print("bar") }
}

class C : A {
    override fun bar() { print("bar") }
}

class D : A, B {
    override fun foo() {
        super<A>.foo()
        super<B>.foo()
    }

    override fun bar() {
        super<B>.bar()
    }
}

/**
 * An interface with only one abstract method is called a functional interface, or a Single Abstract Method (SAM)
 * interface. The functional interface can have several non-abstract members but only one abstract member.
 * To declare a functional interface in Kotlin, use the fun modifier.
 */
fun interface KRunnable {
    fun invoke()
}

/**
 * For functional interfaces, you can use SAM conversions that help make your code more concise and readable by using lambda expressions.
 * Instead of creating a class that implements a functional interface manually, you can use a lambda expression. With a SAM conversion, Kotlin
 * can convert any lambda expression whose signature matches the signature of the interface's single method into the code, which dynamically
 * instantiates the interface implementation. For example, consider the following Kotlin functional interface:
 */
fun interface IntPredicate {
    fun accept(i: Int): Boolean
}

//If you don't use a SAM conversion, you will need to write code like this:
val isEven = object : IntPredicate {
    override fun accept(i: Int): Boolean {
        return i % 2 == 0
    }
}

//By leveraging Kotlin's SAM conversion, you can write the following equivalent code instead:
val isEven1 = IntPredicate {it % 2 == 0}

/**
 * There are four visibility modifiers in Kotlin: private, protected, internal, and public. The default visibility is public.At the top-level of a package
 * If you don’t use a visibility modifier, public is used by default, which means that your declarations will be visible everywhere.
 * If you mark a declaration as private, it will only be visible inside the file that contains the declaration.
 * If you mark it as internal, it will be visible everywhere in the same module.
 * The protected modifier is not available for top-level declarations.
 * To use a visible top-level declaration from another package, you should import it.
 */
// file name: example.ktexit
private fun foom() {  } // visible inside example.kt

public var bar: Int = 5 // property is visible everywhere
    private set         // setter is visible only in example.kt

internal val baz = 6    // visible inside the same module

/**
 * For members declared inside a class:
 * private means that the member is visible inside this class only (including all its members).
 * protected means that the member has the same visibility as one marked as private, but that it is also visible in subclasses.
 * internal means that any client inside this module who sees the declaring class sees its internal members.
 * public means that any client who sees the declaring class sees its public members.
 * If you override a protected or an internal member and do not specify the visibility explicitly, the overriding member will also have the same visibility as the original.
 */
open class Outer {
    private val a = 1
    protected open val b = 2
    internal open val c = 3
    val d = 4  // public by default

    protected class Nested {
        public val e: Int = 5
    }
}

class Subclass : Outer() {
    // a is not visible
    // b, c and d are visible
    // Nested and e are visible

    override val b = 5   // 'b' is protected
    override val c = 7   // 'c' is internal
}

class Unrelated(o: Outer) {
    // o.a, o.b are not visible
    // o.c and o.d are visible (same module)
    // Outer.Nested is not visible, and Nested::e is not visible either
}

class C1 private constructor(a: Int) { /*... */}

/**
 * Kotlin provides the ability to extend a class with new functionality without  having to inherit from
 *the class or use design patterns such as Decorator. This is done via special declarations called extensions.
 *
 * For example, you can write new functions for a class from a third-party library that you can't modify. Such
 * functions can be called in the usual way, as if they were methods of the original class. This mechanism is
 * called an extension function. There are also extension properties that let you define new properties for existing classes.
 *
 * To declare an extension function, prefix its name with a receiver type, which refers to the type being extended. The
 * following adds a swap function to MutableList<Int>:
 */
fun MutableList<Int>.swap(index1: Int, index2: Int) {// 'this' corresponds to List object
    val tmp = this[index1]
    this[index1] = this[index2]
    this[index2] = tmp
}

fun CallExtension(){
    val list = mutableListOf<Int>(1, 2, 3, 4)
    list.swap(1, 2)
}

//generic swpap function for any list
fun<T> MutableList<T>.swap1(index1: Int, index2: Int) {
    val tmp = this[index1]
    this[index1] = this[index2]
    this[index2] = tmp
}

/**
 * Extensions do not actually modify the classes they extend. By defining an extension, you are not inserting
 * new members into a class, only making new functions callable with the dot-notation on variables of this type.
 *
 * Extension functions are dispatched statically, which means they are not virtual by receiver type. An extension function being called is determined by
 * the type of the expression on which the function is invoked, not by the type of the result from evaluating that expression at runtime. For example:
 */
open class Shapes
class Rectangles : Shapes()

fun Shapes.getName() = "Shapes"
fun Rectangles.getName() = "Rectangles"

fun printClassName(s: Shapes) {
    println(s.getName())
}

fun PrintCaller(){
    printClassName(Rectangles()) //smart cast to object of type Shapes, dependent on type of parameter s
}

/**
 * Member function always wins over an extension function with the same name. However can overload with a function that has different arguments
 *
 * Note that extensions can be defined with a nullable receiver type. These extensions can be called on an object variable
 * even if its value is null, and they can check for this == null inside the body.
 */
class Sample{
    fun printNew() { println("class method")}
}

fun Sample.printNew() { println("Extension function")}

fun Sample.printNew(i: Int) {println("Extension function $i")}

fun SampleCaller(){
    Sample().printNew() // prints 'class method'
    Sample().printNew(1) //prints 'Extension function 1'
}

fun Any?.toString(): String {
    return this?.toString() ?: "null"
}

/**
 * Kotlin supports extension properties much like it supports functions. Since extensions do not actually insert members into classes,
 * there's no efficient way for an extension property to have a backing field. This is why initializers are not allowed for extension
 * properties. Their behavior can only be defined by explicitly providing getters/setters
 */
val <T> List<T>.lastIndex: Int
    get() = size - 1

var Sample.number : Int
    get() = 1
    set(value) { value }
//val Sample().number = 1 // error: initializers are not allowed for extension properties

/**
 * If a class has a companion object defined, you can also define extension functions and properties for the companion object. Just
 * like regular members of the companion object, they can be called using only the class name as the qualifier:
 */
class MyClass {
    companion object { }  // will be called "Companion"
}

fun MyClass.Companion.printCompanion() { println("companion") }

fun MyClassCaller() {
    MyClass.printCompanion()
}

/**
 * In most cases, you define extensions on the top level, directly under packages To use an extension outside its declaring package, import it at the call site:
 */

//package org.example.declarations
//
//fun List<String>.getLongestString() { /*...*/}

//package org.example.usage
//
//import org.example.declarations.getLongestString
//
//fun main() {
//    val list = listOf("red", "green", "blue")
//    list.getLongestString()
//}

/**
 * You can declare extensions for one class inside another class. Inside such an extension, there are multiple implicit receivers- objects whose members can be
 * accessed without a qualifier. An instance of a class in which the extension is declared is called a dispatch receiver, and an instance of the receiver type
 * of the extension method is called an extension receiver.
 */
class Host(val hostname: String){
    fun printHostname() { print(hostname)}
}

class Connection(val host: Host, val port: Int){
    fun printPort() { print(port) }

    fun Host.printConnectionString() {
        printHostname()
        print(":")
        printPort()
    }

    fun connect() {
        /* ... */
        host.printConnectionString()
    }
}

fun ConnectionCaller(){
    Connection(Host("kotl.in"), 443).connect()
}

/**
 * Extensions declared as members can be declared as open and overridden in subclasses. This means that the dispatch of such
 * functions is virtual with regard to the dispatch receiver type, but static with regard to the extension receiver type.
 */
open class Base2 { }

class Derived1 : Base2() { }

open class BaseCaller {
    open fun Base2.printFunctionInfo() {
        println("Base extension function in BaseCaller")
    }

    open fun Derived1.printFunctionInfo() {
        println("Derived extension function in BaseCaller")
    }

    fun call(b: Base2) {
        b.printFunctionInfo()   // call the extension function
    }
}

class DerivedCaller: BaseCaller() {
    override fun Base2.printFunctionInfo() {
        println("Base extension function in DerivedCaller")
    }

    override fun Derived1.printFunctionInfo() {
        println("Derived extension function in DerivedCaller")
    }
}

fun BaseDerivedCalls() {
    BaseCaller().call(Base2())   // "Base extension function in BaseCaller"
    DerivedCaller().call(Base2())  // "Base extension function in DerivedCaller" - dispatch receiver is resolved virtually
    DerivedCaller().call(Derived1())  // "Base extension function in DerivedCaller" - extension receiver is resolved statically
}

/**
 * Sealed classes and interfaces represent restricted class hierarchies that provide more control over inheritance. All direct
 * subclasses of a sealed class are known at compile time. No other subclasses may appear after a module with the sealed class
 * is compiled. For example, third-party clients can't extend your sealed class in their code. Thus, each instance of a sealed
 * class has a type from a limited set that is known when this class is compiled.
 *
 * The same works for sealed interfaces and their implementations: once a module with a sealed interface is compiled, no new implementations can appear.
 *
 * In some sense, sealed classes are similar to enum classes: the set of values for an enum type is also restricted, but each enum constant exists
 * only as a single instance, whereas a subclass of a sealed class can have multiple instances, each with its own state.
 *
 * As an example, consider a library's API. It's likely to contain error classes to let the library users handle errors that it can throw. If the hierarchy
 * of such error classes includes interfaces or abstract classes visible in the public API, then nothing prevents implementing or extending them in the
 * client code. However, the library doesn't know about errors declared outside it, so it can't treat them consistently with its own classes. With
 * a sealed hierarchy of error classes, library authors can be sure that they know all possible error types and no other ones can appear later.
 *
 * To declare a sealed class or interface, put the sealed modifier before its name:
 *
 * A sealed class is abstract by itself, it cannot be instantiated directly and can have abstract members.
 * Constructors of sealed classes can have one of two visibilities: protected (by default) or private:
 *
 * Direct subclasses of sealed classes and interfaces must be declared in the same package. They may be top-level or nested inside any number of other
 * named classes, named interfaces, or named objects. Subclasses can have any visibility as long as they are compatible with normal inheritance rules in Kotlin.
 *
 * Subclasses of sealed classes must have a proper qualified name. They can't be local nor anonymous objects.
 */
sealed interface Error // has implementations only in same package and module

sealed class IOError(): Error // extended only in same package and module
open class CustomError(): Error // can be extended wherever it's visible

class FileReadError(val file: String = ""): IOError() {
}

class DatabaseError(val source: DataSource): IOError()

object RuntimeError : Error

sealed class IO_Error {
    constructor() { /*...*/ } // protected by default
    private constructor(description: String): this() { /*...*/ } // private is OK
    // public constructor(code: Int): this() {} // Error: public and internal are not allowed
}

/**
 * There is one more inheritance restriction in multiplatform projects: direct subclasses of sealed classes must
 * reside in the same source set. It applies to sealed classes without the expect and actual modifiers.
 *
 * If a sealed class is declared as expect in a common source set and have actual implementations in platform source
 * sets, both expect and actual versions can have subclasses in their source sets. Moreover, if you use a hierarchical
 * structure, you can create subclasses in any source set between the expect and actual declarations.
 *
 * The key benefit of using sealed classes comes into play when you use them in a when expression. If it's possible to
 * verify that the statement covers all cases, you don't need to add an else clause to the statement. However, this
 * works only if you use when as an expression (using the result) and not as a statement:
 */
fun log(e: Error) = when(e) {
    is FileReadError -> { println("Error while reading file ${e.file}") }
    is DatabaseError -> { println("Error while reading from database ${e.source}") }
    RuntimeError ->  { println("Runtime error") }
    else -> { println("Unknown error") }
    // the `else` clause is not required because all the cases are covered
}

/**
 * Classes in Kotlin can have type parameters, just like in Java: To create an instance of such a class, simply provide the type arguments:
 * But if the parameters can be inferred, for example, from the constructor arguments, you can omit the type arguments:
 */
class Box<T>(t: T) {
    var value = t
}

val box: Box<Int> = Box<Int>(1)
val box1 = Box(1) //1 has type Int, so the compiler figures out that it is Box<Int>

/**
 * Classes can be nested in other classes: Can use interfaces with nesting. All combinations of classes and interfaces are possible:
 * You can nest interfaces in classes, classes in interfaces, and interfaces in interfaces.
 *
 * A nested class marked as inner can access the members of its outer class. Inner classes carry a reference to an object of an outer class:
 */
class Outerl {
    private val bar: Int = 1
    class Nested {
        fun foo() = 2
    }
    inner class Inner {
        fun foo() = bar
    }
}

interface OuterInterface {
    class InnerClass
    interface InnerInterface
}

class OuterClass {
    class InnerClass
    interface InnerInterface
}

val demo = Outerl.Nested().foo() // == 2
val demol = Outerl().Inner().foo() // == 1

/**
 * The most basic use case for enum classes is the implementation of type-safe enums: Each enum constant is an object. Enum constants are separated by commas.
 * Since each enum is an instance of the enum class, it can be initialized as:
 */
enum class Direction {
    NORTH, SOUTH, WEST, EAST
}

enum class Colour(val rgb: Int) {
    RED(0xFF0000),
    GREEN(0x00FF00),
    BLUE(0x0000FF)
}

/**
 * Enum constants can declare their own anonymous classes with their corresponding methods, as well as with overriding base methods.
 * If the enum class defines any members, separate the constant definitions from the member definitions with a semicolon.
 */
enum class ProtocolState {
    WAITING {
        override fun signal() = TALKING
    },
    TALKING {
        override fun signal() = WAITING
    };

    abstract fun signal() : ProtocolState
}

/**
 * An enum class can implement an interface (but it cannot derive from a class), providing either a common implementation of interface members for all of the entries, or
 * separate implementations for each entry within its anonymous class. This is done by adding the interfaces you want to implement to the enum class declaration as follows:
 */
enum class IntArithmetics : BinaryOperator<Int>, IntBinaryOperator {
   PLUS {
       override fun apply(t: Int, u: Int) : Int = t + u
   },
   TIMES {
       override fun apply(t: Int, u: Int): Int = t * u
   };

    override fun applyAsInt(t: Int, u: Int): Int = apply(t, u)
}

fun ArithmeticCaller() {
    val a = 13
    val b = 31
    for (f in IntArithmetics.values()) {
        print("$f($a, $b) = ${f.apply(a,b)}\n")
    }
}

/**
 * Enum classes in Kotlin have synthetic methods for listing the defined enum constants and getting an enum constant by its name. The signatures of
 * these methods are as follows (assuming the name of the enum class is EnumClass):
 * EnumClass.valueOf(value: String): EnumClass
 * EnumClass.values(): Array<EnumClass>
 *
 * The valueOf() method throws an IllegalArgumentException if the specified name does not match any of the enum constants defined in the class.
 * You can access the constants in an enum class in a generic way using the enumValues<T>() and enumValueOf<T>() functions:
 */
enum class RGB { RED, GREEN, BLUE }

inline fun <reified T : Enum<T>> printAllValues() {
    print(enumValues<T>().joinToString { it.name })
}

fun PrinterCaller() {
    printAllValues<RGB>() // prints RED, GREEN, BLUE
    print(RGB.GREEN.ordinal) //property for obtaining its position in the enum class declaration
    print(RGB.GREEN.name) //property for obtaining its name
}

/**
 * Sometimes it is necessary for business logic to create a wrapper around some type. However, it introduces runtime overhead
 * due to additional heap allocations. Moreover, if the wrapped type is primitive, the performance hit is terrible, because
 * primitive types are usually heavily optimized by the runtime, while their wrappers don't get any special treatment.
 *
 * Kotlin introduces a special kind of class called an inline class. Inline classes are a subset of value-based classes. They don't
 * have an identity and can only hold values. To declare an inline class, use the value modifier before the name of the class:
 *
 * To declare an inline class for the JVM backend, use the value modifier along with the @JvmInline annotation before the class declaration:
 */
//value class Password1(val s: String = "")

// For JVM backends
@JvmInline
value class Password(private val s: String)

fun InlineClassInitializer() {
    /**
     * An inline class must have a single property initialized in the primary constructor. At runtime, instances of the inline class will
     * be represented using this single property (see details about runtime representation below):
     * This is the main feature of inline classes, which inspired the name inline: data of the class is inlined into its usages (similar
     * to how content of inline functions is inlined to call sites).
     */
    // No actual instantiation of class 'Password' happens
    // At runtime 'securePassword' contains just 'String'
    val securePassword = Password("Don't try this in production")
}

/**
 * Inline classes support some functionality of regular classes. In particular, they are allowed to declare properties and functions, and have the init block
 * Inline class properties cannot have backing fields. They can only have simple computable properties (no lateinit /delegated properties).
 */
@JvmInline
value class Name(private val s: String) {
    init {
        require(s.isNotEmpty()) { }
    }

    val length: Int
        get() = s.length

    fun greet() {
        print("Hello, $s\n")
    }
}

fun NameCaller() {
    val name = Name("Kotlin")
    name.greet() // method `greet` is called as a static method
    println(name.length) // property getter is called as a static method
}

/**
 * Inline classes are allowed to inherit from interfaces: It is forbidden for inline classes to participate
 * in a class hierarchy. This means that inline classes cannot extend other classes and must be final.
 */
interface Printable {
    fun prettyPrint(): String
}

@JvmInline
value class Namor(val s: String) : Printable {
    override fun prettyPrint(): String = "Let's $s!"
}

fun NamorCaller(){
    val name = Namor("Kotlin")
    println(name.prettyPrint()) // Still called as a static method
}

/**
 * In generated code, the Kotlin compiler keeps a wrapper for each inline class. Inline class instances can be represented at runtime either as
 * wrappers or as the underlying type. This is similar to how Int can be represented either as a primitive int or as the wrapper Integer.
 *
 * The Kotlin compiler will prefer using underlying types instead of wrappers to produce the most performant and optimized code. However, sometimes
 * it is necessary to keep wrappers around. As a rule of thumb, inline classes are boxed whenever they are used as another type.
 *
 * Because inline classes may be represented both as the underlying value and as a wrapper, referential equality is pointless for them and is therefore prohibited.
 */
interface I

@JvmInline
value class Fu(val i: Int) : I

fun asInline(f: Fu) {}
fun <T> asGeneric(x: T) {}
fun asInterface(i: I) {}
fun asNullable(i: Fu?) {}

fun <T> id(x: T): T = x

fun CallWrappers() {
    val f = Fu(42)

    asInline(f) //unboxed: used as Fu itself
    asGeneric(f) //boxed: used as generic type T
    asInterface(f) //boxed: used as type I
    asNullable(f) // boxed: used as Foo?, which is different from Foo

    //below, 'f' first is boxed (while being passed to 'id') then unboxed (when returned from 'id')
    //In the end, 'c' contains unboxed representation (just '42'), as 'f'
    val c = id(f)
}

/**
 * Since inline classes are compiled to their underlying type, it may lead to various obscure errors, for example unexpected platform signature clashes:
 *
 * To mitigate such issues, functions using inline classes are mangled by adding some stable hashcode to the function name. Therefore, fun compute(x: UInt) will be represented as
 * public final void compute-<hashcode>(int x), which solves the clash problem.
 */
@JvmInline
value class UInt(val x: Int)

// Represented as 'public final void compute(int x)' on the JVM
fun compute(x: Int) { }

// Also represented as 'public final void compute(int x)' on the JVM!
fun compute(x: UInt) { }

/**
 * Type aliases provide alternative names for existing types. If the type name is too long you can introduce a different shorter name and use the new one instead.
 * It's useful to shorten long generic types. For instance, it's often tempting to shrink collection types:
 */
class Network {
    class Node
}
typealias NodeSet = Set<Network.Node>
typealias FileTable<K> = MutableMap<K, MutableList<File>>

/**
 * You can provide different aliases for function types
 */
typealias Myhandler = (Int, String, Any) -> Unit
typealias Predicate<T> = (T) -> Boolean

/**
 * You can have new names for inner and nested classes
 */
class X { inner class Inner }
class Y { inner class Inner }
typealias XInner = X.Inner
typealias YInner = Y.Inner

/**
 * Type aliases do not introduce new types. They are equivalent to the corresponding underlying types. When you add typealias Predicate<T> and use Predicate<Int> in your
 * code, the Kotlin compiler always expands it to (Int) -> Boolean. Thus you can pass a variable of your type whenever a general function type is required and vice versa:
 */
fun foo(p: Predicate<Int>) = p(42)

fun TypeAliasCaller(){
    val f: (Int) -> Boolean = { it > 0 }
    println(foo(f)) // prints "true"

    val p: Predicate<Int> = { it > 0 }
    println(listOf(1, -2).filter(p)) // prints "[1]"
}

/**
 * At first sight, inline classes seem very similar to type aliases. Indeed, both seem to introduce a new type and both will be represented as the underlying type at runtime.
 * However, the crucial difference is that type aliases are assignment-compatible with their underlying type (and with other type aliases with the same
 * underlying type), while inline classes are not.
 * In other words, inline classes introduce a truly new type, contrary to type aliases which only introduce an alternative name (alias) for an existing type:
 */
typealias NameTypeAlias = String

@JvmInline
value class NameInlineClass(val s: String)

fun acceptString(s: String) {}
fun acceptNameTypeAlias(n: NameTypeAlias) {}
fun acceptNameInlineClass(p: NameInlineClass) {}

fun TypeInline(){
    val nameAlias: NameTypeAlias = ""
    val nameInlineClass: NameInlineClass = NameInlineClass("")
    val string: String = ""

    acceptString(nameAlias) // OK: pass alias instead of underlying type
    //acceptString(nameInlineClass) // Not OK: can't pass inline class instead of underlying type

    // And vice versa:
    acceptNameTypeAlias(string) // OK: pass underlying type instead of alias
    //acceptNameInlineClass(string) // Not OK: can't pass underlying type instead of inline class
}

/**
 * Object expressions create objects of anonymous classes, that is, classes that aren't explicitly declared with the class declaration.
 * Such classes are useful for one-time use. You can define them from scratch, inherit from existing classes, or implement interfaces.
 * Instances of anonymous classes are also called anonymous objects because they are defined by an expression, not a name.
 *
 * Object expressions start with the object keyword. If you just need an object that doesn’t have any nontrivial supertypes, write its members in curly braces after object:
 */
val helloWorld = object {
    val hello = "Hello"
    val world = "World"
    // object expressions extend Any, so `override` is required on `toString()`
    override fun toString() = "$hello $world"
}

/**
 * To create an object of an anonymous class that inherits from some type (or types), specify this type after
 * object and a colon (:). Then implement or override the members of this class as if you were inheriting from it:
 */
class Window {
    fun addMouseListener(any : MouseAdapter) { }
}

fun WindowCaller(){
    var window = Window()
    var clickCount = 0
    var enterCount = 0

    window.addMouseListener(object : MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) { clickCount++ }
        override fun mouseEntered(e: MouseEvent) { enterCount++ }
    })
}

open class MouseAdapter{
    open fun mouseClicked(e: MouseEvent) { }
    open fun mouseEntered(e: MouseEvent) { }
}
class MouseEvent

/**
 * If a supertype has a constructor, pass appropriate constructor parameters to it. Multiple supertypes can be specified as a comma-delimited list after the colon:
 */
open class AA(x: Int) {
    public open val y: Int = x
}

interface BB { /*...*/ }

val ab: AA = object : AA(1), BB {
    override val y = 15
}

/**
 * Anonymous object is used as a type of a local or private but not inline declaration (function or property), all its members are accessible via this function or property:
 */
class CC {
    private fun getObject() = object {
        val x: String = "x"
    }

    fun printX() {
        println(getObject().x)
    }
}

/**
 * If this function or property is public or private inline, its actual type is:
 * Any if the anonymous object doesn't have a declared supertype
 * The declared supertype of the anonymous object, if there is exactly one such type
 * The explicitly declared type if there is more than one declared supertype
 * In all these cases, members added in the anonymous object are not accessible. Overridden members are accessible if they are declared in the actual type of the function or property:
 */
interface AAA {
    fun funFromA() {}
}
interface BBB

class CCC {
    // The return type is Any. x is not accessible
    fun getObject() = object {
        val x: String = "x"
    }

    // The return type is AAA; x is not accessible
    fun getObjectA() = object: AAA {
        override fun funFromA() {}
        val x: String = "x"
    }

    // The return type is BBB; funFromA() and x are not accessible
    fun getObjectB(): BBB = object: AAA, BBB { // explicit return type is required
        override fun funFromA() {}
        val x: String = "x"
    }
}

/**
 * The Singleton pattern can be useful in several cases, and Kotlin makes it easy to declare singletons: This is called an object declaration, and it always has a name following
 * the object keyword. Just like a variable declaration, an object declaration is not an expression, and it cannot be used on the right-hand side of an assignment statement.
 *
 * The initialization of an object declaration is thread-safe and done on first access. To refer to the object, use its name directly:
 */
object DataProviderManager {
    fun registerDataProvider(provider: DataProvider) {
        // ...
    }

    val allDataProviders: Collection<DataProvider>
        get() = TODO()
}

class DataProvider

//Such objects can have supertypes:
object DefaultListener : MouseAdapter() {
    override fun mouseClicked(e: MouseEvent) { /*...*/ }

    override fun mouseEntered(e: MouseEvent) { /*...*/ }
}

/**
 * An object declaration inside a class can be marked with the companion keyword: Members of the companion object can be called simply by using the class name as the qualifier:
 * The name of the companion object can be omitted, in which case the name Companion will be used:
 */
class MyClas {
    companion object {
        fun create(): MyClas = MyClas()
    }
}

fun Companions(){
    val instance = MyClas.create()
    val x = MyClas.Companion
}

/**
 * Class members can access the private members of the corresponding companion object.
 * The name of a class used by itself (not as a qualifier to another name) acts as a reference to the companion object of the class (whether named or not):
 */
class MyClass1 {
    companion object Named { }
}

val x = MyClass1

class MyClass2 {
    companion object { }
}

val y = MyClass2

/**
 * Note that even though the members of companion objects look like static members in other languages, at runtime those are still instance members of real objects,
 * and can, for example, implement interfaces:
 *
 * However, on the JVM you can have members of companion objects generated as real static methods and fields if you use the @JvmStatic annotation.
 */
interface Factory<T> {
    fun create() : T
}

class MiClass {
    companion object : Factory<MiClass> {
        override fun create(): MiClass = MiClass()
    }
}

val f: Factory<MiClass> = MiClass

/**
 * A good example of a higher-order function is the functional programming idiom fold for collections. It takes an initial accumulator value and a combining function
 * and builds its return value by consecutively combining the current accumulator value with each collection element, replacing the accumulator value each time:
 */
fun <T, R> Collection<T>.fold(
    initial: R,
    combine: (acc: R, nextElement: T) -> R
): R {
    var accumulator: R = initial
    for (element: T in this) {
        accumulator = combine(accumulator, element)
    }
    return accumulator
}

/**
 * In the code above, the combine parameter has the function type (R, T) -> R, so it accepts a function that takes two arguments of types R and T and returns a value of type
 * R. It is invoked inside the for loop, and the return value is then assigned to accumulator.
 *
 * To call fold, you need to pass an instance of the function type to it as an argument, and lambda expressions
 * (described in more detail below) are widely used for this purpose at higher-order function call sites:
 */
fun CallingFunction() {
    val items = listOf(1, 2, 3, 4, 5)

    //Lambdas are code blocks enclosed in curly braces
    items.fold(0, {
        // When a lambda has parameters, they go first, followed by '->'
            acc: Int, i: Int ->
        print("acc = $acc, i = $i, ")
        val result = acc + i
        println("result = $result\n")
        result //the last expression in a lambda is considered the return value
    })

    val joinedToString = items.fold("Elements:", { acc, i -> acc + " " + i })

    // Function references can also be found for higher-order function calls:
    val product = items.fold(1, Int::times)
}

/**
 * Kotlin uses function types, such as (Int) -> String for declarations that deal with functions: val onClick: () -> Unit = ...
 * These types have a special notation that corresponds to the signatures of the functions, their parameters and return values
 *
 * * All function types have a parenthesized list of parameter types and a return type: (A, B) -> C denotes a type that represents functions that take two
 * arguments of types A and  B and return a value of type C. The list of parameter types may be empty, as in () -> A. The Unit return type cannot be omitted.
 * * Function types can optionally have an additional receiver type, which is specified before the dot in the notation: the type A.(B) -> C represents functions
 * that can be called on a receiver object A with a parameter B and return a value C. Function literals with receiver are often used along with these types.
 *  * Suspending functions belong to a special kind of function type that have a suspend modifier in their notation, such as suspend () -> Unit or suspend A.(B) -> C.
 *
 * The function type notation can optionally include names for the function parameters: (x: Int, y: Int) -> Point. These names can be used for documenting the meaning of the parameters.
 * To specify that a function type is nullable, use parentheses as follows: ((Int, Int) -> Int)? Function types can also be combined using parentheses: (Int) -> ((Int) -> Unit).
 * The arrow notation is right-associative, (Int) -> (Int) -> Unit is equivalent to the previous example, but not to ((Int) -> (Int)) -> Unit
 */
typealias ClickHandler = (Button, ClickEvent) -> Unit

class ClickEvent

/** There are several ways to obtain an instance of a function type:
 ** Use a code block within a function literal, in one of the following forms:
 * a lambda expression: { a, b -> a + b },
 * an anonymous function: fun(s: String): Int { return s.toIntOrNull() ?: 0 }
 * Function literals with receiver can be used as values of function types with receiver.
 * Use a callable reference to an existing declaration:
 * a top-level, local, member, or extension function: ::isOdd, String::toInt,
 * a top-level, member, or extension property: List<Int>::size,
 * a constructor: ::Regex
 ** These include bound callable references that point to a member of a particular instance: foo::toString.
 ** Use instances of a custom class that implements a function type as an interface:
 */

class IntTransformer: (Int) -> Int {
    override operator fun invoke(x: Int): Int = TODO()
}

val intFunction: (Int) -> Int = IntTransformer()

/**
 * The compiler can infer the function types for variables if there is enough information. Non-literal values of function types with and without a receiver
 * are interchangeable, so the receiver can stand in for the first parameter, and vice versa. For instance, a value of type (A, B) -> C can be passed or
 * assigned where a value of type A.(B) -> C is expected, and the other way around:
 */
val a = {i: Int -> i + 1 } //The inferred type is (Int) -> Int

val repeatFun: String.(Int) -> String = { times -> this.repeat(times) }
val twoParameters: (String, Int) -> String = repeatFun // OK

fun runTransformation(f: (String, Int) -> String): String {
    return f("hello", 3)
}
val result = runTransformation(repeatFun) // OK

/**
 * A value of a function type can be invoked by using its invoke(...) operator: f.invoke(x) or just f(x).
 *
 * If the value has a receiver type, the receiver object should be passed as the first argument. Another way to invoke a value of a function type with receiver
 * is to prepend it with the receiver object, as if the value were an extension function: 1.foo(2).
 */
fun InvocationCaller() {
    val stringPlus: (String, String) -> String = String::plus
    val intPlus: Int.(Int) -> Int = Int::plus //This is the same type of syntax

    print(stringPlus.invoke("<-", "->\n"))
    print(stringPlus("Hello", "world\n"))

    print(intPlus.invoke(1, 1))
    print(intPlus(1, 2))
    println(2.intPlus(3))
}

/**
 * Typical lambda expression without optional annotations is.
 */
val sum = { x: Int, y: Int -> x + y }

/**
 * According to kotlin convention, if the last parameter of a function is a function, then a lambda expression passed aas the corresponding argument can be placed outside the parentheses
 * Such syntax is also known as trailing lambda. If the lambda is the only argument in that call, the parentheses can be omitted entirely:
 */
val items = listOf(1, 2, 3, 4, 5)
val product = items.fold(1) { acc, e -> acc * e }

/**
 * If the compiler can parse the signature without any parameters, the parameter does not need to be declared and -> can be omitted. The parameter will be implicitly declared under the name it:
 */
val xe = items.filter { it > 3 }

val exe = items.filter {
    val shouldFilter = it > 3
    shouldFilter
}

/**
 * This convention, along with passing a lambda expression outside of parentheses, allows for LINQ-style code:
 */
val strings = listOf("Hello", "doug", "world", "pathetic", "damage")
val processed = strings.filter { it.length == 5 }.sortedBy { it }.map { it.uppercase() }

//If the lambda parameter is unused, you can place an underscore instead of its name:
fun idiots() {
    val newmap = mapOf<String, String>("dog" to "bark", "cat" to "miaow", "cow" to "moo" )
    newmap.forEach{ _, value -> print("$value\n")}
}

/**
 * The lambda expression syntax above is missing one thing – the ability to specify the function’s return type. In most cases, this is unnecessary because the return type
 * can be inferred automatically. However, if you do need to specify it explicitly, you can use an alternative syntax: an anonymous function.
 *An anonymous function looks very much like a regular function declaration, except its name is omitted. Its body can be either an expression or a block:
 */
fun new() {
    fun(x: Int, y: Int): Int = x + y

    fun(x: Int, y: Int): Int {
        return x + y
    }

    strings.filter(fun(item) = item.length > 0)

    /**
     * A lambda expression or anonymous function (as well as a local function and an object expression) can access its closure, which includes the variables declared
     * in the outer scope. The variables captured in the closure can be modified in the lambda:
     */
    var sum = 0
    items.filter { it > 0 }.forEach {
        sum += it
    }
    print(sum)


}

/**
 * Function types with receiver, such as A.(B) -> C, can be instantiated with a special form of function literals – function literals with receiver.
 * As mentioned above, Kotlin provides the ability to call an instance of a function type with receiver while providing the receiver object.
 * Inside the body of the function literal, the receiver object passed to a call becomes an implicit this, so that you can access the members of that receiver
 * object without any additional qualifiers, or access the receiver object using a this expression.
 * This behavior is similar to that of extension functions, which also allow you to access the members of the receiver object inside the function body.
 * Here is an example of a function literal with receiver along with its type, where plus is called on the receiver object:
 */
val sum1: Int.(Int) -> Int = { other -> plus(other) }

/**
 * The anonymous function syntax allows you to specify the receiver type of a function literal directly. This can be useful if you need to declare
 * a variable of a function type with receiver, and then to use it later.
 */
val sum_r = fun Int.(other: Int): Int = this + other

fun htmlcaller() {
    /**
     * Lambda exp0ressions can be used as function literals with receiver when the receiver type can be inferred
     * from the context. One of the most important examples of their usage is type-safe builders
     */
    class HTML {
        fun body() { TODO() }
    }
    
    fun html(init: HTML.() -> Unit): HTML {
        val html = HTML() // create the receiver object
        html.init()       // pass the receiver object to the lambda
        html { body() }   // lambda with receiver begins here
        return html
    }
}
    
    class InlineFunctions(){
        class Lock
        fun foo() { }
    
        /**
         * Using higher-order functions imposes certain runtime penalties: each function is an object, and it captures a closure.
         * A closure is a scope of variables that can be accessed in the body of the function. Memory allocations (both for function
         * objects and classes) and virtual calls introduce runtime overhead.
         *
         * But it appears that in many cases this kind of overhead can be eliminated by inlining the lambda expressions. The functions
         * shown below are good examples of this situation. The lock() function could be easily inlined at call-sites. Consider the following case:
         */
    
        val l = Lock()
    
        //Instead of creating a function object for the parameter and generating a call, the compiler could emit the following code:
        /*l.lock()
           try {
               foo()
           } finally {
               l.unlock()
           }*/
    
        /**
        * Instead of creating a function object for the parameter and generating a call, the compiler could emit the following code:
        * The inline modifier affects both the function itself and the lambdas passed to it: all of those will be inlined into the call site.
        * Inlining may cause the generated code to grow. However, if you do it in a reasonable way (avoiding inlining large functions), it
        * will pay off in performance, especially at "megamorphic" call-sites inside loops.
        */
        inline fun <T> lock(l: Any, function: () -> T) : T { TODO() }
        inline fun <T> unlock(l: Any, function: () -> T) { TODO() }
    
        fun LockCaller() {
            this.lock(l) { foo() }
            /**
             * Using higher-order functions imposes certain runtime penalties: each function is an object, and it captures a closure.
             * A closure is a scope of variables that can be accessed in the body of the function. Memory allocations (both for function
             * objects and classes) and virtual calls introduce runtime overhead.
             *
             * But it appears that in many cases this kind of overhead can be eliminated by inlining the lambda expressions. The functions shown
             * below are good examples of this situation. The lock() function could be easily inlined at call-sites. Consider the following case:
             */
        }
    
        /**
         * If you don’t want all of the lambdas passed to an inline function to be inlined, mark some of your function parameters with the noinline modifier:
         * Inlinable lambdas can only be called inside inline functions or passed as inlinable arguments. noinline lambdas, however, can be manipulated in
         * any way you like, including being stored in fields or passed around.
         */
        inline fun foo(inlined: () -> Unit, noinline notinLined: () -> Unit){ TODO() }
    
        // If an inline function has no inlinable function parameters and no reified type parameters, the compiler will issue a warning, since inlining such functions
        // is very unlikely to be beneficial (you can use the @Suppress("NOTHING_TO_INLINE") annotation to suppress the warning if you are sure the inlining is needed).
    
        /**
         * In Kotlin, you can only use a normal, unqualified return to exit a named function or an anonymous function. To exit a lambda, use a label. A bare return
         * is forbidden inside a lambda because a lambda cannot make the enclosing function return:
         *
         *But if the function the lambda is passed to is inlined, the return can be inlined, as well. So it is allowed:
         */
        fun ordinary(block: () -> Unit) {
            print("Hi!\n")
        }
    
        fun fos() {
            ordinary {
                //return //ERROR: cannot make fos return here
            }
        }
        /**
         * But if the function the lambda is passed to is inlined, the return can be inlined, as well. So it is allowed:
         */
        inline fun inlined(block: () -> Unit) {
            print("Hi!\n")
        }
    
        fun fot() {
            inlined {
                return //OK as the lambda is inlined
            }
        }
    
        /**
         * Such returns (located in a lambda, but exiting the enclosing function) are called non-local returns. This sort of
         * construct usually occurs in loops, which inline functions often enclose:
         */
        fun hasZeros(ints: List<Int>): Boolean {
            ints.forEach {
                if (it == 0) return true
            }
            return false
        }
    
        /**
         * Note that some inline functions may call the lambdas passed to them as parameters not directly from the function body, but
         * from another execution context, such as a local object or a nested function. In such cases, non-local control flow is also
         * not allowed in the lambdas. To indicate that the lambda parameter of the inline function cannot use non-local returns, mark
         * the lambda parameter with the crossinline modifier:
     */
    inline fun f(crossinline body: () -> Unit) {
        val f = object: Runnable {
            override fun run() = body()
        }
    }

    /**
     * Sometimes yo need to access a type passed as a parameter. Here, you walk up a tree and use reflection to check whether a
     * node has a certain type.
     */
    fun <T> TreeNode.findParentOfType(clazz: Class<T>): T? {
        var p = parent
        while (p != null && !clazz.isInstance(p)) {
            p = p.parent
        }
        @Suppress("UNCHECKED_CAST")
        return p as T?
    }

    class LesNode : TreeNode {
        override fun getChildAt(childIndex: Int): TreeNode {
            TODO("")
        }

        override fun getChildCount(): Int {
            TODO("")
        }

        override fun getParent(): TreeNode {
            TODO("")
        }

        override fun getIndex(node: TreeNode?): Int {
            TODO("")
        }

        override fun getAllowsChildren(): Boolean {
            TODO("")
        }

        override fun isLeaf(): Boolean {
            TODO("")
        }

        override fun children(): Enumeration<out TreeNode> {
            TODO("")
        }
    }

    fun TreeCaller() {
        val treeNode = LesNode()
        /**
         * It’s all fine, but the call site is not very pretty:
         */
        treeNode.findParentOfType(LesNode::class.java)

        /**
         * A better solution would be to simply pass a type to this function. You can call it as follows
         */
        treeNode.findParentOfType<LesNode>()
    }

    /**
     * To enable this, inline functions support reified type parameters, so you can write something like this
     */
    inline fun <reified T> TreeNode.findParentOfType(): T? {
        var p = parent
        while (p != null && p !is T) {
            p = p.parent
        }
        return p as T?
    }

    /**
     * The code above qualifies the type parameter with the reified modifier to make it accessible inside the function, almost as if it
     * were a normal class. Since the function is inlined, no reflection is needed and normal operators like !is and as are now available
     * for you to use. Also, you can call the function as shown above: myTree.findParentOfType<MyTreeNodeType>().
     * Though reflection may not be needed in many cases, you can still use it with a reified type parameter:
     */
    inline fun <reified T> membersOf() = T::class.members

    fun MembersCaller(s: Array<String>) {
        print(membersOf<StringBuilder>().joinToString("\n"))
    }

    /**
     * The inline modifier can be used on accessors of properties that don't have backing fields. You can annotate individual property accessors:
     */
    class Fov
    val fov: Fov
        inline get() = Fov()

    class Bar
    var bar: Bar
        get() = Bar()
        inline set(v) { v }

    /**
     * You can also annotate an entire property which mars both itss accessors as inline: At the call site, inline accessors are inlined as regular inline functions.
     */
    inline var barr: Bar
        get() = Bar()
        set(v) { v }
}

/**
 * By using well-named functions as builders in combination with function literals with receiver it is possible to create type-safe, statically-typed builders in Kotlin.
 * Type-safe builders allow creating Kotlin-based domain-specific languages (DSLs) suitable for building complex hierarchical data structures in a semi-declarative way. Sample use cases for the builders are:
 *  * Generating markup with Kotlin code, such as HTML or XML
 *  * Programmatically laying out UI components: Anko
 *  * Configuring routes for a web server: Ktor
 * Consider the following code:
 * 1) html is actually a function call that takes a lambda expression as an argument. html function takes one parameter which itself is a function. the type of the function is HTML.() -> Unit
 * which is a function type with receiver. This mens that we need to pass an instance of type HTML (a receiver) to the function, and we can call members of that instance inside the function
 * 2) head and body are member functions of the HTML class
 * 3) Adds the text to tags by calling the unaryPlus() operation, like +"HTML encoding with Kotlin"
 */
/*
val result =
    html {
        head {
            title {+"XML encoding with Kotlin"}
        }
        body {
            h1 {+"XML encoding with Kotlin"}
            p  {+"this format can be used as an alternative markup to XML"}

            // an element with attributes and text content
            a(href = "https://kptlinlang.org") {+"Kotlin"}

            // mixed content
            p {
                +"This is some"
                b {+"mixed" }
                +"text. For more see the"
                a(href = "https://kotlinlang.org") {+"Kotlin"}
                +"project"
            }
            p {+"some text"}

            // content generated by
            p {
                for (arg in args)
                    +arg
            }
        }
    }
*/

/**
 * To access this from an outer scope (a class, extension function, or labeled function literal with receiver) you write
 * this@label, where @label is a label on the scope this is meant to be from:
 */
class A1 { // implicit label @A1
    inner class B { // implicit label @B
        fun Int.foo() {  //implicit label @foo
            val a = this@A1 // A1's this
            val b = this@B // B's this

            val c = this // foo()'s receiver, an Int
            val c1 = this@foo

            val funLit = lambda@ fun String.() {
                val d = this // funLit's receiver
            }

            val funLit2 = { s: String ->
                // foo()'s receiver, since enclosing lambda expression
                // doesn't have any receiver
                val d1 = this
            }
        }

    }
}

/**
 *** Let's assume in the code above that preparePost is a long-running process and consequently would block the user interface. What we can do is launch it in a separate thread. This would then allow us to avoid the UI from blocking. This is a very common technique, but has a series of drawbacks:
 * Threads aren't cheap. Threads require context switches which are costly.
 * Threads aren't infinite. The number of threads that can be launched is limited by the underlying operating system. In server-side applications, this could cause a major bottleneck.
 * Threads aren't always available. Some platforms, such as JavaScript do not even support threads.
 * Threads aren't easy. Debugging threads, avoiding race conditions are common problems we suffer in multi-threaded programming.
 * Threads are by far probably the most well-known approach to avoid applications from blocking.
 */
fun postItem(item: Item) {
    thread {
        val token = preparePost()
        val post = submitPost(token, item)
        processPost(post)
    }
}

fun submitPost(token: Token, item: Item) : String { return "message" }

fun processPost(post: String) { TODO() }

fun preparePost(): Token {
    val token : Token = Token()
    // makes a request and consequently blocks the main thread
    return token
}

/**
 * With callbacks, the idea is to pass one function as a parameter to another function, and have this one invoked once the process has completed.
 */
fun postItemCallbacks(item: Item) {
    preparePostAsync { token ->
        submitPostAsync(token, item) { post ->
            processPost(post)
        }
    }
}

fun preparePostAsync(callback: (Token) -> Unit) {
    // make request and return immediately
    // arrange callback to be invoked later
}

fun submitPostAsync(token: Token, item: Item, callback: (String) -> Unit) {
    // make request and return immediately
    // arrange callback to be invoked later
}
/**
 * Difficulty of nested callbacks. Usually a function that is used as a callback, often ends up needing its own callback. This leads to a series of
 * nested callbacks which lead to incomprehensible code. The pattern is often referred to as the titled christmas tree (braces represent branches of the tree).
 * Error handling is complicated. The nesting model makes error handling and propagation of these somewhat more complicated.
 * Callbacks are quite common in event-loop architectures such as JavaScript, but even there, generally people have moved
 * away to using other approaches such as promises or reactive extensions.
 */
/* - follow laer
fun postItem(item: Item){
    preparePostAsync()
        .thenCompose { token ->
            submitPostAsync(token, item)
        }
        .thenAccept { post ->
            processPost(post)
        }
}

fun preparePostAsync(): Promise<Token> {
    val promise : Promise<Token>

    return promise
}*/
/**
 * Different programming model. Similar to callbacks, the programming model moves away from a top-down imperative approach to a compositional
 * model with chained calls. Traditional program structures such as loops, exception handling, etc. usually are no longer valid in this model.
 * Different APIs. Usually there's a need to learn a completely new API such as thenCompose or thenAccept, which can also vary across platforms.
 * Specific return type. The return type moves away from the actual data that we need and instead returns a new type Promise which has to be introspected.
 * Error handling can be complicated. The propagation and chaining of errors aren't always straightforward.
 */

/**
 * Kotlin's approach to working with asynchronous code is using coroutines, which is the idea of suspendable computations, i.e. the idea that a function can
 * suspend its execution at some point and resume later on.
 * One of the benefits however of coroutines is that when it comes to the developer, writing non-blocking code is essentially the same as writing blocking
 * code. The programming model in itself doesn't really change.
 */
/*
fun postItems(item: Item) {
    launch {
        val token = preparePosts()
        val post = submitPost(token, item)
        processPost(post)
    }
}

fun launch(function: () -> Unit) {
    TODO()
}

suspend fun preparePosts(): Token {
    // makes a request and suspends the coroutine
    return suspendCoroutine { /* ... */ }
}
*/
/**
 * This code will launch a long-running operation without blocking the main thread. The preparePost is what's called a suspendable function, thus the
 * keyword suspend prefixing it. What this means as stated above, is that the function will execute, pause execution and resume at some point in time.
 * The function signature remains exactly the same. The only difference is suspend being added to it. The return type however is the type we want to be returned
 * The code is still written as if we were writing synchronous code, top-down, without the need of any special syntax, beyond the use of a function
 * called 'launch' which essentially kicks off the coroutine (covered in other tutorials).
 * The programming model and APIs remain the same. We can continue to use loops, exception handling, etc. and there's no need to learn a complete set of new APIs.
 * It is platform independent. Whether we're targeting JVM, JavaScript or any other platform, the code we write is the same.
 * Under the covers the compiler takes care of adapting it to each platform.
 */

/**
 * A coroutine is an instance of suspendable computation. It is conceptually similar to a thread, in the sense that it takes a block of code to run that works concurrently
 * with the rest of the code. However, a coroutine is not bound to any particular thread. It may suspend its execution in one thread and resume in another one.
 */

==> ./3-2-ktor-jackson/src/Application.kt <==
package com.example

import com.fasterxml.jackson.annotation.JsonFormat
import com.fasterxml.jackson.annotation.JsonInclude
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule
import io.ktor.jackson.*
import io.ktor.features.*
import java.time.LocalDateTime

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        jackson {
            enable(SerializationFeature.INDENT_OUTPUT)
            registerModule(JavaTimeModule())
            //enable(SerializationFeature.ORDER_MAP_ENTRIES_BY_KEYS)
            enable(SerializationFeature.WRAP_ROOT_VALUE) //not default way to present Json
            enable(SerializationFeature.WRITE_SINGLE_ELEM_ARRAYS_UNWRAPPED)
            disable(SerializationFeature.WRITE_DATE_KEYS_AS_TIMESTAMPS)
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/jackson") {
            call.respond(mapOf("hello" to "world"))
        }

        get("/ship"){
            call.respond(SpaceShip(null, 80, listOf("Mike")))
        }
    }
}

data class SpaceShip(@JsonInclude(value= JsonInclude.Include.NON_NULL) val name: String?, //does not display field if value is null
                     val fuel: Int,
                     val crew: List<String>,
                     @JsonFormat(pattern="yyyy-MM-dd HH:mm") val launchDate: LocalDateTime = LocalDateTime.now())

==> ./3-2-ktor-jackson/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./3-4-ktor-autoreload/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD 2!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./3-4-ktor-autoreload/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./3-5-ktor-location-path/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.locations.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Locations) {
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get<MyLocation> {
            call.respondText("Location: name=${it.name}")
        }
        // Register nested routes
        get<Book.Author> {
            call.respondText("$it")
        }
        get<Book.List> {
            call.respondText("$it")
        }
    }
}

@Location("/location/{name}")
class MyLocation(val name: String)

@Location("/book/{category}") data class Book(val category: String) {
    @Location("/{author}")
    data class Author(val book: Book, val author: String)

    @Location("/list")
    data class List(val book: Book)
}


==> ./3-5-ktor-location-path/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.locations.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./3-6-ktor-location-request-parameter/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.locations.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Locations) {
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get<MyLocation> {
            call.respondText("Location: name=${it.name}")
        }
        // Register nested routes
        get<MyLocation> {
            call.respondText("Location: name=${it.name}")
        }
        // Register nested routes
        get<Book.Author> {
            call.respondText("$it")
        }
        get<Book.List> {
            call.respondText("$it")
        }
    }
}

@Location("/location/{name}")
class MyLocation(val name: String)

@Location("/book/{category}") data class Book(val category: String) {
    @Location("/{author}")
    data class Author(val book: Book, val author: String)

    @Location("/list")
    data class List(val book: Book, val sortby: String, val asc: Int)
}



==> ./3-6-ktor-location-request-parameter/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.locations.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./3-7-ktor-default-headers/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.features.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(DefaultHeaders) {
        header("MySystemName", "BookstoreApp") // will send this header with each response
    }

    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            for (h in call.request.headers.entries()){
                log.info("header: ${h.key} ${h.value}")
            }
            call.response.header("Myheader...", "Myheadervalue")
            call.response.header(HttpHeaders.SetCookie, "cookieToUse")
            call.respondText("HELLO WORLD!")
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./3-7-ktor-default-headers/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.features.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-1-ktor-status-pages/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.features.*
import io.ktor.gson.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    install(StatusPages) {
        statusFile(
            HttpStatusCode.InternalServerError,
            HttpStatusCode.NotFound,
            filePattern = "customerrors/myerror#.html"
        )

        exception<MyFirstException> { cause ->
            call.respond(HttpStatusCode.Unauthorized)
            log.error(cause.localizedMessage)
            throw cause
        }
        exception<MySecondException> { cause ->
            call.respondRedirect("/", false)
            throw cause
        }
        exception<MyThirdException> { cause ->
            call.respondText("The third exception just happened... Please fix it")
            throw cause
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
        /*ception<AuthenticationException> { cause ->
            call.respond(HttpStatusCode.Unauthorized)
        }
        exception<AuthorizationException> { cause ->
            call.respond(HttpStatusCode.Forbidden)
        }*/

        get("/first") {
            throw MyFirstException()
        }
        get("/second") {
            throw MySecondException()
        }
        get("/third") {
            throw MyThirdException()
        }
    }
}

//class AuthenticationException : RuntimeException()
//class AuthorizationException : RuntimeException()
class MyFirstException : RuntimeException()
class MySecondException : RuntimeException()
class MyThirdException : RuntimeException()

==> ./4-1-ktor-status-pages/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.features.*
import io.ktor.gson.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-2-ktor-data-posted-to-endpoint/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.http.ContentDisposition.Companion.File
import io.ktor.http.content.*
import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import kotlinx.coroutines.yield
import java.io.File
import java.io.InputStream
import java.io.OutputStream

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        post("/text") {
            val text = call.receiveText()
            println("text received: $text")
            call.respondText("thank you we received $text")
        }

        post("/form"){
            val parameters = call.receiveParameters()
            parameters.names().forEach {
                val myvalue = parameters.get(it)
                println("key: $it, value: $myvalue")
            }
            call.respondText("Thank you for the form data")
        }

        post("/file"){
            val multipart = call.receiveMultipart()
            var title = ""
            val uploadDir = "./upload"
            multipart.forEachPart { part ->
                when (part) {
                    is PartData.FormItem -> {
                        if (part.name == "title") {
                            title = part.value
                        }
                    }
                    is PartData.FileItem -> {
                        val ext = File(part.originalFileName).extension
                        val file = File(uploadDir, "upload-${System.currentTimeMillis()}--${title.hashCode()}-${title.hashCode()}.$ext")
                        part.streamProvider().use { input -> file.outputStream().buffered().use { output -> input.copyToSuspend(output) }}
                    }
                }
                part.dispose()
            }
            call.respondText("Your file has been stored")
        }

        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

suspend fun InputStream.copyToSuspend(out: OutputStream,
                                      bufferSize: Int = DEFAULT_BUFFER_SIZE,
                                      yieldSize: Int = 4 * 1024 * 1024,
                                      dispatcher: CoroutineDispatcher = Dispatchers.IO
): Long {
    return withContext(dispatcher) {
        val buffer = ByteArray(bufferSize)
        var bytesCopied = 0L
        var bytesAfterYield = 0L
        while (true) {
            val bytes = read(buffer).takeIf { it >= 0 } ?: break
            out.write(buffer, 0, bytes)
            if (bytesAfterYield >= yieldSize) {
                yield()
                bytesAfterYield %= yieldSize
            }
            bytesCopied += bytes
            bytesAfterYield += bytes
        }
        return@withContext bytesCopied
    }
}
==> ./4-2-ktor-data-posted-to-endpoint/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-3-basic-authentication/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Authentication) {
        basic("myBasicAuth1") {
            realm = "My Realm"
            validate { if (it.name == "mike" && it.password == "password") UserIdPrincipal(it.name) else null }
        }
        basic("myBasicAuth2") {
            realm = "My Other Realm"
            validate { if (it.password == "${it.name}abc123") UserIdPrincipal(it.name) else null }
        }
    }

    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        authenticate("myBasicAuth1") {
            get("/secret/weather") {
                val principal = call.principal<UserIdPrincipal>()!!
                call.respondText("Dear ${principal.name}, i looks like sun tomorrow")
            }
        }

        authenticate("myBasicAuth2") {
            get("/trendycolor/nextyear") {
                val principal = call.principal<UserIdPrincipal>()!!
                call.respondText("Hi ${principal.name}, we think that green will be popular next year")
            }
            get("/trendycolor/nextmonth") {
                val principal = call.principal<UserIdPrincipal>()!!
                call.respondText("Hi ${principal.name}, we think that purple will be popular next month")
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./4-3-basic-authentication/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-4-ktor-interceptor/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.features.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.util.pipeline.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {

        }
    }

    val mike = PipelinePhase("Mike") //creating own pipeline phase just to show its possible
    //insertPhaseAfter(ApplicationCallPipeline.Call, mike) //Phase is set after the ApplicationCallPipeline.Call phase
    insertPhaseBefore(ApplicationCallPipeline.Call, mike)
    intercept(ApplicationCallPipeline.Setup){
        log.info("Setup phase...")
    }
    intercept(ApplicationCallPipeline.Call){
        log.info("Call phase...")
    }
    intercept(ApplicationCallPipeline.Features){
        log.info("Features phase..")
    }
    intercept(ApplicationCallPipeline.Monitoring){
        log.info("Monitoring phase...")
    }
    intercept(ApplicationCallPipeline.Fallback){
        log.info("Fallback phase...")
    }
    intercept(mike){
        log.info("Mike phase... ${call.request.uri}") //prints out the uri we tried to call
        if (call.request.uri.contains("mike")){
            log.info("The uri contains mike")

            //this response is denied if we have already created a response to be sent to the client (in call phase), returns an exception, if finish() not called
            //if set before the Call phase, the endpoint response is handled here, and the routing response is not sent, finish() stops the call phase being called
            call.respondText("The endpoint contains mike")
            finish() //finish() prevents the rest of the interceptors from being called
        }
    }

    routing { //also interceptors, all located in the call phase of the Application Call pieline
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/something/mike/anotherthing"){
            call.respondText("This endpoint is handled by the route. Have a nice day!")
            //finish()
        }
    }
}


==> ./4-4-ktor-interceptor/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-5-call-logging/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.routing.*
import io.ktor.http.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(CallLogging) {
        level = Level.TRACE
        filter { call -> call.request.path().startsWith("/calllogging") }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
        get("/calllogging/test"){
            call.respondText("Test 123!")
        }
    }
}


==> ./4-5-call-logging/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./4-6-metrics/src/Application.kt <==
package com.example

import com.codahale.metrics.Slf4jReporter
import com.codahale.metrics.jmx.JmxReporter
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.metrics.dropwizard.*
import java.util.concurrent.TimeUnit

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    //jconsole can be used from the command line to access the metrics through a GUI
    install(DropwizardMetrics){
        Slf4jReporter.forRegistry(registry)
            .outputTo(log)
            .convertRatesTo(TimeUnit.SECONDS)
            .convertDurationsTo(TimeUnit.MILLISECONDS)
            .build()
            .start(15, TimeUnit.SECONDS)

        JmxReporter.forRegistry(registry)
            .convertRatesTo(TimeUnit.SECONDS)
            .convertDurationsTo(TimeUnit.MILLISECONDS)
            .build()
            .start()
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
        get("/weatherforecast"){
            call.respondText("Sun or rain!")
        }
        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./4-6-metrics/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./5-1-mongodb/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

val mongoDataHandler = MongoDataHandler()
@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        jackson {
            enable(SerializationFeature.INDENT_OUTPUT)
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/jackson") {
            call.respond(mapOf("hello" to "world"))
        }

        get("/allships") {
            call.respond(mongoDataHandler.allSpaceShips())
        }

        get("/oneship/{spaceshipid}"){
            val shipid = call.parameters.get("spaceshipid")!!
            log.info("shipid $shipid")
            call.respond(mongoDataHandler.findOneSpaceShip(shipid)!!)
        }

        post("/fuelup/{spaceshipid}"){
            val shipid = call.parameters.get("spaceshipid")!!
            log.info("shipid $shipid")
            mongoDataHandler.fuelUpSpaceShip(shipid)
            call.respond(mongoDataHandler.allSpaceShips())
        }

        get("/sortedships"){
            val pageno = call.parameters.get("page")!!
            val pagesize = call.parameters.get("pagesize")!!
            log.info("pageno: $pageno, pagesize: $pagesize")
            val ships = mongoDataHandler.shipsSortedByFuelAndPaged(pageno.toInt(), pagesize.toInt())
            call.respond(ships!!)
        }

        get("/ships"){ //extracts data with a query
            val fuelmin = call.parameters.get("fuelmin")!!
            log.info("fuelmin $fuelmin")
            val ships = mongoDataHandler.shipsWithMoreFuelThan(fuelmin.toFloat())
            call.respond(ships!!)
        }

        post("/replace"){
            log.info("ship replace started")
            val ship = call.receive(SpaceShip::class)
            log.info("ship $ship")
            mongoDataHandler.replaceSpaceShip(ship)
            call.respond(mongoDataHandler.findOneSpaceShip(ship.getIdAsHex())!!)
        }
    }
}
==> ./5-1-mongodb/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./6-1-test-strategy/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.client.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    val client = HttpClient() {
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
    }
}


==> ./6-1-test-strategy/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.client.*
import kotlin.test.*
import io.ktor.server.testing.*
import io.ktor.client.engine.mock.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.utils.io.*
import kotlinx.coroutines.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }

    @Test
    fun testClientMock() {
        runBlocking {
            val client = HttpClient(MockEngine) {
                engine {
                    addHandler { request -> 
                        when (request.url.fullPath) {
                            "/" -> respond(
                                ByteReadChannel(byteArrayOf(1, 2, 3)),
                                headers = headersOf("X-MyHeader", "MyValue")
                            )
                            else -> respond("Not Found ${request.url.encodedPath}", HttpStatusCode.NotFound)
                        }
                    }
                }
                expectSuccess = false
            }
            assertEquals(byteArrayOf(1, 2, 3).toList(), client.get<ByteArray>("/").toList())
            assertEquals("MyValue", client.request<HttpResponse>("/").headers["X-MyHeader"])
            assertEquals("Not Found other/path", client.get<String>("/other/path"))
        }
    }
}

==> ./6-2-setting-up-a-ktor-test/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    val client = HttpClient(Apache) {
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./6-2-setting-up-a-ktor-test/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import kotlin.test.*
import io.ktor.server.testing.*
import io.ktor.client.engine.mock.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.utils.io.*
import kotlinx.coroutines.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }

    @Test
    fun testClientMock() {
        runBlocking {
            val client = HttpClient(MockEngine) {
                engine {
                    addHandler { request -> 
                        when (request.url.fullPath) {
                            "/" -> respond(
                                ByteReadChannel(byteArrayOf(1, 2, 3)),
                                headers = headersOf("X-MyHeader", "MyValue")
                            )
                            else -> respond("Not Found ${request.url.encodedPath}", HttpStatusCode.NotFound)
                        }
                    }
                }
                expectSuccess = false
            }
            assertEquals(byteArrayOf(1, 2, 3).toList(), client.get<ByteArray>("/").toList())
            assertEquals("MyValue", client.request<HttpResponse>("/").headers["X-MyHeader"])
            assertEquals("Not Found other/path", client.get<String>("/aapi/other/path"))
        }
    }
}

==> ./6-3-what-is-a-good-test/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    val client = HttpClient(Apache) {
    }

    var nresponses = 0
    routing {
        get("/") {
            if (testing){
                log.info("respond no: $nresponses")
                call.respondText("Testing!", contentType = ContentType.Text.Plain)
            }
            else{
                call.respondText("we are not testing")
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./6-3-what-is-a-good-test/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import kotlin.test.*
import io.ktor.server.testing.*
import io.ktor.client.engine.mock.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.utils.io.*
import kotlinx.coroutines.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }

    @Test
    fun testClientMock() {
        runBlocking {
            val client = HttpClient(MockEngine) {
                engine {
                    addHandler { request -> 
                        when (request.url.fullPath) {
                            "/" -> respond(
                                ByteReadChannel(byteArrayOf(1, 2, 3)),
                                headers = headersOf("X-MyHeader", "MyValue")
                            )
                            else -> respond("Not Found ${request.url.encodedPath}", HttpStatusCode.NotFound)
                        }
                    }
                }
                expectSuccess = false
            }
            assertEquals(byteArrayOf(1, 2, 3).toList(), client.get<ByteArray>("/").toList())
            assertEquals("MyValue", client.request<HttpResponse>("/").headers["X-MyHeader"])
            assertEquals("Not Found other/path", client.get<String>("/other/path"))
        }
    }
}

==> ./6-4-k6-performance-testing/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    val client = HttpClient(Apache) {
    }

    var nresponses = 0
    routing {
        get("/") {
            nresponses++
            log.info("respond no. $nresponses")
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./6-4-k6-performance-testing/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import kotlin.test.*
import io.ktor.server.testing.*
import io.ktor.client.engine.mock.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.utils.io.*
import kotlinx.coroutines.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }

    @Test
    fun testClientMock() {
        runBlocking {
            val client = HttpClient(MockEngine) {
                engine {
                    addHandler { request -> 
                        when (request.url.fullPath) {
                            "/" -> respond(
                                ByteReadChannel(byteArrayOf(1, 2, 3)),
                                headers = headersOf("X-MyHeader", "MyValue")
                            )
                            else -> respond("Not Found ${request.url.encodedPath}", HttpStatusCode.NotFound)
                        }
                    }
                }
                expectSuccess = false
            }
            assertEquals(byteArrayOf(1, 2, 3).toList(), client.get<ByteArray>("/").toList())
            assertEquals("MyValue", client.request<HttpResponse>("/").headers["X-MyHeader"])
            assertEquals("Not Found other/path", client.get<String>("/other/path"))
        }
    }
}

==> ./7-1-html-dsl/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }

        get("/styles.css") {
            call.respondCss {
                body {
                    backgroundColor = Color.red
                }
                p {
                    fontSize = 2.em
                }
                rule("p.myclass") {
                    color = Color.blue
                }
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

fun FlowOrMetaDataContent.styleCss(builder: CSSBuilder.() -> Unit) {
    style(type = ContentType.Text.CSS.toString()) {
        +CSSBuilder().apply(builder).toString()
    }
}

fun CommonAttributeGroupFacade.style(builder: CSSBuilder.() -> Unit) {
    this.style = CSSBuilder().apply(builder).toString().trim()
}

suspend inline fun ApplicationCall.respondCss(builder: CSSBuilder.() -> Unit) {
    this.respondText(CSSBuilder().apply(builder).toString(), ContentType.Text.CSS)
}

==> ./7-1-html-dsl/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./7-1-html-dsl1/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("html-template"){
            call.respondHtmlTemplate(BookstoreTemplate()){
                booksOnSale {
                    +"How to grow oranges - By Jane Orangeton"
                }
                bookRecommended {
                    +"How to grow carrots - Jane Carrotson"
                }
            }
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./7-1-html-dsl1/src/BookstoreTemplate.kt <==
package com.example

import io.ktor.html.*
import io.ktor.html.insert
import kotlinx.html.*
import kotlinx.html.HTML

class BookstoreTemplate: Template<HTML> {
    val booksOnSale = Placeholder<FlowContent>()
    val bookRecommended = Placeholder<FlowContent>()

    override fun HTML.apply() {
        head {
            title { +"Bookstore Application"}
        }
        body{
            h1{
                +"Welcome to my bookstore"
            }

            div{
                h1 {
                    +"On sale!"
                }
                h2 {
                    insert(booksOnSale)
                }
            }
            div{
                h1 {
                    +"On sale!"
                }
                h2 {
                    insert(bookRecommended)
                }
            }
        }
    }
}
==> ./7-1-html-dsl1/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./7-2-HTML-DSL-import-css/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/htmlexample"){
            call.respondHtml {
                head {
                    link(
                        rel = "stylesheet",
                        href = "https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css",
                        type = "text/css"
                    ) {
                        this.integrity = "sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk"
                        this.attributes.put("crossorigin", "anonymous")
                    }
                }

                body {
                    div(classes = "container") {
                        div(classes = "row") {
                            div(classes = "offset-md-4 col-md-4 order-md-2 mb-4"){
                                h1 {+"HTML"}
                                ul{
                                    for (n in 1..10){
                                        li { +"$n"}
                                    }
                                }
                                button(classes = "btn btn-warning") { +"Test 123" }
                                br(){}
                                br(){}
                                div(classes="alert alert-success"){
                                    this.role="alert"
                                    +"My Ktor and Bootstrap application loaded with success!"
                                }
                            }
                        }
                    }
                    script(type = "javascript", src = "https://code.jquery.com/jquery-3.5.1.slim.min.js"){
                        integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj"
                        this.attributes.put("crossorigin", "anonymous")
                    }
                    script(
                        type = "javascript",
                        src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js"
                    ) {
                        integrity = "sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo"
                        this.attributes.put("crossorigin", "anonymous")
                    }
                    script(
                        type = "javascript",
                        src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"
                    ) {
                        integrity = "sha384-OgVRvuATP1z7JjHLkuOU7Xw704+h835Lr+6QL9UvYjZE3Ipu6Tp75j7Bh/kR0JKI"
                        this.attributes.put("crossorigin", "anonymous")
                    }

                }
            }
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }
    }
}


==> ./7-2-HTML-DSL-import-css/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./7-3-static-files/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/lighton/{port}") {
            val port = call.parameters.get("port")
            val str: String = "<1,DO,$port,1>"
            WriteToFile(str)
            log.info(str)
            call.respondText(str + " carriage_return")
        }

        get("/lightoff/{port}") {
            val port = call.parameters.get("port")
            val str: String = "<1,DO,$port,0>"
            WriteToFile(str)
            log.info(str)
            call.respondText(str + " carriage_return")
        }

        get("/pulseon/{port}") {
            val port = call.parameters.get("port")
            val str: String = "<1,OP,$port,300>"
            WriteToFile(str)
            log.info(str)
            call.respondText(str + " carriage_return")
        }

        get("/pulseoff/{port}") {
            val port = call.parameters.get("port")
            val str: String = "<1,OP,$port,0>"
            WriteToFile(str)
            log.info(str)
            call.respondText(str + " carriage_return")
        }

        get("/return_error") {
            val str: String = "<1,DO,0,1>"
            WriteToFile(str)
            log.info("/return_error")
            call.respondText(str + " no_return)")
        }

        // Static feature. Try to access `/static/ktor_logo.svg`
        static("/static") {
            resources("static")
        }
    }
}


fun WriteToFile(str: String){
    try {
        var fo = FileWriter("/dev/ttyACM0", true)
        fo.write(str)
        fo.close()
    } catch (ex: Exception){
        print(ex.message)
    }
}
==> ./7-3-static-files/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./7-4-css-dsl/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }
    }
}


==> ./7-4-css-dsl/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./8-1-jar-file/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD! Running from a jar file", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./8-1-jar-file/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD! Running from a jar file", response.content)
            }
        }
    }
}

==> ./8-2-docker-build-image/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD! Running from a jar file", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./8-2-docker-build-image/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD! Running from a jar file", response.content)
            }
        }
    }
}

==> ./bookstore/src/Application.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.sessions.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import io.ktor.locations.*
import kotlinx.coroutines.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Sessions) {
        cookie<MySession>("MY_SESSION") {
            cookie.extensions["SameSite"] = "lax"
        }
    }

    install(CallLogging) {
        level = Level.INFO
        filter { call -> call.request.path().startsWith("/") }
    }

    install(PartialContent) {
        // Maximum number of ranges that will be accepted from a HTTP request.
        // If the HTTP request specifies more ranges, they will all be merged into a single range.
        maxRangeCount = 10
    }

    install(StatusPages){
        exception<Throwable> { cause ->
            call.respond(HttpStatusCode.InternalServerError)
            throw cause
        }
    }

    install(Locations){

    }

    val users = listOf<String>("shopper1", "shopper2", "shopper3")
    val admins = listOf<String>("admin")

    install(Authentication) {
        basic("bookStoreAuth") {
            realm = "Book store"
            validate {
                if ((users.contains(it.name) || admins.contains(it.name)) && it.password == "password")
                    UserIdPrincipal(it.name)
                else null
            }
        }
    }

    install(ContentNegotiation) {
        gson {
            setPrettyPrinting()
        }
    }

    val client = HttpClient(Apache) {
        install(JsonFeature) {
            serializer = GsonSerializer()
        }
    }
    runBlocking {
        // Sample for making a HTTP Client request
        /*
        val message = client.post<JsonSampleClass> {
            url("http://127.0.0.1:8080/path/to/endpoint")
            contentType(ContentType.Application.Json)
            body = JsonSampleClass(hello = "world")
        }
        */
    }

    routing {
        books()

        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }

        get("/styles.css") {
            call.respondCss {
                body {
                    backgroundColor = Color.red
                }
                p {
                    fontSize = 2.em
                }
                rule("p.myclass") {
                    color = Color.blue
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg`
        static("/static") {
            resources("static")
        }

        get("/session/increment") {
            val session = call.sessions.get<MySession>() ?: MySession()
            call.sessions.set(session.copy(count = session.count + 1))
            call.respondText("Counter is ${session.count}. Refresh to increment.")
        }

        authenticate("bookStoreAuth") {
            get("/api") {
                val principal = call.principal<UserIdPrincipal>()!!
                call.respondText("Hello ${principal.name}")
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

data class MySession(val count: Int = 0)

class AuthenticationException : RuntimeException()
class AuthorizationException : RuntimeException()

data class JsonSampleClass(val hello: String)

fun FlowOrMetaDataContent.styleCss(builder: CSSBuilder.() -> Unit) {
    style(type = ContentType.Text.CSS.toString()) {
        +CSSBuilder().apply(builder).toString()
    }
}

fun CommonAttributeGroupFacade.style(builder: CSSBuilder.() -> Unit) {
    this.style = CSSBuilder().apply(builder).toString().trim()
}

suspend inline fun ApplicationCall.respondCss(builder: CSSBuilder.() -> Unit) {
    this.respondText(CSSBuilder().apply(builder).toString(), ContentType.Text.CSS)
}

==> ./bookstore/src/BookRoutes.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.locations.*
import io.ktor.request.*
import io.ktor.response.*
import io.ktor.routing.*
import io.ktor.routing.get
import io.ktor.auth.authenticate

@Location("/api/book/list")
data class BookListLocation(val sortby: String, val asc: Boolean)

fun Route.books(){
    val dataManager = DataManagerMongoDB()
    authenticate("bookStoreAuth") {
            get<BookListLocation>() {
                call.respond(dataManager.sortedBooks(it.sortby, it.asc))
            }

            get("/api/book/all") {
                call.respond(dataManager.allBooks())
            }

            post("/api/book/{id}") {
                val id = call.parameters.get("id")
                val book = call.receive(Book::class)
                val updatedbook = dataManager.updateBook(book)
                call.respondText("The book has been updated $updatedbook")
            }

            put("/api/book") {
                val book = call.receive(Book::class)
                val newbook = dataManager.newBook(book)
                call.respond(newbook)
            }

            delete("/api/book/{id}") {
                val id = call.parameters.get("id").toString()
                val deletedbook = dataManager.deleteBook(id)
                call.respond(deletedbook)
            }
    }
}
==> ./bookstore/test/ApplicationTest.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.sessions.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import kotlinx.coroutines.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./coroutinedemo/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

//fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
}


==> ./endpoint-demo/src/Application.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText { "HELLO WORLD!" }
        }

        var weather = "sunny"
        get("/weatherforecast") {
            call.respondText { weather }
        }
        post("weatherforecast"){
            weather = call.receiveText()
            call.respondText { "The weather has been set to: $weather" }
        }
    }
}


==> ./endpoint-demo/test/ApplicationTest.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-content-negotiation/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
        register(ContentType.Application.Xml, XmlConverter())

        /*jackson {
            enable(SerializationFeature.INDENT_OUTPUT)
        }*/
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }

        get("/json/jackson") {
            call.respond(mapOf("hello" to "world"))
        }

        get("/spaceship"){
            call.respond(SpaceShip("Mike", 88))
        }
    }
}

data class SpaceShip(val name: String, val fuel: Int)
==> ./ktor-content-negotiation/src/XmlConverter.kt <==
package com.example

import io.ktor.application.*
import io.ktor.features.*
import io.ktor.http.*
import io.ktor.http.content.*
import io.ktor.request.*
import io.ktor.util.pipeline.*
import io.ktor.utils.io.*
import io.ktor.utils.io.jvm.javaio.*
import com.fasterxml.jackson.dataformat.xml.XmlMapper

class XmlConverter : ContentConverter {
    override suspend fun convertForReceive(context: PipelineContext<ApplicationReceiveRequest, ApplicationCall>): Any? {
        val request = context.subject
        val channel = request.value as? ByteReadChannel ?: return null
        val reader = channel.toInputStream().reader(context.call.request.contentCharset() ?: Charsets.UTF_8)
        val type = request.type
        val xmlMapper = XmlMapper()
        val xml = reader
        val result: Any? = xmlMapper.readValue(xml, type.javaObjectType)
        return result
    }

    override suspend fun convertForSend(
        context: PipelineContext<Any, ApplicationCall>,
        contentType: ContentType,
        value: Any
    ): Any? {
        val xmlMapper = XmlMapper()
        val xml = xmlMapper.writeValueAsString(value)
        return TextContent(xml, contentType.withCharset(context.call.suitableCharset()))
    }
}
==> ./ktor-content-negotiation/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-demofromweb/src/main/kotlin/example/com/Application.kt <==
package example.com

import io.ktor.server.engine.*
import io.ktor.server.netty.*
import example.com.plugins.*

fun main() {
    embeddedServer(Netty, port = 8080, host = "0.0.0.0") {
        configureRouting()
    }.start(wait = true)
}

==> ./ktor-demofromweb/src/main/kotlin/example/com/plugins/Routing.kt <==
package example.com.plugins

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

fun Application.configureRouting() {

    routing {
        get("/") {
                call.respondText("Hello World!")
            }
    }
}

==> ./ktor-demofromweb/src/test/kotlin/example/com/ApplicationTest.kt <==
package example.com

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import kotlin.test.*
import io.ktor.server.testing.*
import example.com.plugins.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ configureRouting() }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("Hello World!", response.content)
            }
        }
    }
}
==> ./ktor-extensiondemo/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import io.ktor.features.*

//fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        jackson {
            enable(SerializationFeature.INDENT_OUTPUT)
        }
    }

    routing {

        get("/json/jackson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./ktor-extensiondemo/src/UserRoutes.kt <==
package com.example

import io.ktor.application.*
import io.ktor.http.*
import io.ktor.response.*
import io.ktor.routing.*

fun Routing.userRoutes(){
    get("/user") {
        call.respondText("User1", contentType = ContentType.Text.Plain)
    }

    post("/user") {
        call.respondText ("The user has been created")
    }
}


==> ./ktor-extensiondemo/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import com.fasterxml.jackson.databind.*
import io.ktor.jackson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-httpclient/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import kotlinx.coroutines.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    val client = HttpClient(Apache) {
        install(JsonFeature) {
            serializer = GsonSerializer()
        }
    }
    runBlocking {
        // Sample for making a HTTP Client request
        /*
        val message = client.post<JsonSampleClass> {
            url("http://127.0.0.1:8080/path/to/endpoint")
            contentType(ContentType.Application.Json)
            body = JsonSampleClass(hello = "world")
        }
        */
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }

        get("/spaceship"){
            call.respond(Spaceship("myspaceship", 15))
        }

        get("/consumeservice"){
            //call.respondText(client.get<String>("http://localhost:8080/spaceship"))
            log.info("consume BEGIN")
            val result = client.get<ByteArray>("http://localhost:8080/spaceship")
            val result2 = client.get<Spaceship>("http://localhost:8080/spaceship")
            call.respond(result2)
            log.info("The result: ${String(result)}")
            log.info("The result: ${result2.toString()}") //data classes (Spaceship) have an inherent toString() method
            log.info("consume END")
        }
    }
}

data class JsonSampleClass(val hello: String)

data class Spaceship(val name: String, val fuel: Int)
==> ./ktor-httpclient/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import kotlinx.coroutines.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-hypermedia-response/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
        get("/library/book/{bookid}/checkout"){
            val bookid = call.parameters.get("bookid")
            call.respond(BookReserveResponse("You checked out the book $bookid", emptyList<HypermediaLink>()))
        }


        get("/library/book/{bookid}/reserve"){
            val bookid = call.parameters.get("bookid")
            call.respond(BookReserveResponse(
                "You reserved the book $bookid",
                emptyList<HypermediaLink>())
            )
        }

        get("/library/book/{bookid}"){
            val bookid = call.parameters.get("bookid")
            val book = Book(bookid!!, "How to grow apples", "Mr Appleton")
            val hypermedialinks = listOf<HypermediaLink>(
                HypermediaLink("http://localhost:8080/library/book/$bookid/checkout", "checkout", "GET"),
                HypermediaLink("http://localhost:8080/library/book/$bookid/reserve", "reserve", "GET")
            )
            val bookResponse = BookResponse(book, hypermedialinks)
            call.respond(bookResponse)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

data class Book(val id: String, val title: String, val author: String)
data class BookResponse(val book: Book, val links: List<HypermediaLink>)
data class BookReserveResponse(val message: String, var links: List<HypermediaLink>)
data class HypermediaLink(val href: String, val rel: String, val type: String)
==> ./ktor-hypermedia-response/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-install-feature/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    install(Routing){ //passed as a trailing lambda to the Routing  (usually installed by default)
        get("/goodevening"){
            call.respondText("good evening world!")
        }
    }

    routing {  //helper function which puts us in the context of routing
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./ktor-install-feature/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-routes/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        //buildText() inherent to routing result trace() function, good for logging, returns in Application run window
        trace { application.log.trace(it.buildText()) }
        route("/weather"){
            route("/europe", HttpMethod.Get){ //the get {} witht trailing lambda is a shortcut helper function
                header("systemtoken", "weathersystem") {  //without passing in a header the system will not respond
                    param("name") { //without passing in a name parameter, this route will now not respond
                        handle {
                            val name = call.parameters.get("name")
                            call.respondText { "Dear $name, the weather in Europe is sunny" }
                        }
                    }
                }
            }

            get("/usa"){
                call.respondText("the weather in the US is snowy")
            }
        }
    }
}


==> ./ktor-routes/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-webdemo/src/main/kotlin/example/com/Application.kt <==
package example.com

import io.ktor.application.*
import example.com.plugins.*
import io.ktor.http.*
import io.ktor.response.*
import io.ktor.routing.*

fun main(args: Array<String>): Unit =
    io.ktor.server.netty.EngineMain.main(args)

//@Suppress("unused") // application.conf references the main function. This annotation prevents the IDE from marking it as unused.
fun Application.module() {
    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
    }
}

==> ./ktor-webdemo/src/main/kotlin/example/com/plugins/Routing.kt <==
package example.com.plugins

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

fun Application.configureRouting() {

    routing {
        get("/") {
                call.respondText("Hello World!")
            }
    }
}

==> ./ktor-webdemo/src/test/kotlin/example/com/ApplicationTest.kt <==
package example.com

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import kotlin.test.*
import io.ktor.server.testing.*
import example.com.plugins.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ configureRouting() }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("Hello World!", response.content)
            }
        }
    }
}
==> ./ktor-websockets-chat-sample/Hi_to_controller/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import java.io.FileReader
import java.io.FileWriter

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/say_hi") {
            val str: String = "<1,HI>"
            WriteToFile(str)
        }


        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

fun WriteToFile(str: String){
    try {
        var fo = FileWriter("/dev/ttyACM0", true)
        fo.write(str + "\r")
        fo.close()
    } catch (ex: Exception){
        print(ex.message)
    }
}

/*fun ReadFromFile(){
    try{
        var fin = FileReader
    } catch (ex: Exception){
        print(ex.message)
    }

}*/
==> ./ktor-websockets-chat-sample/Hi_to_controller/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.gson.*
import io.ktor.features.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktor-websockets-chat-sample/SetupTests/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(ContentNegotiation) {
        gson {
        }
    }

    val client = HttpClient() {
    }

    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg`
        static("/static") {
            resources("static")
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}


==> ./ktor-websockets-chat-sample/SetupTests/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.gson.*
import io.ktor.features.*
import io.ktor.client.*
import kotlin.test.*
import io.ktor.server.testing.*
import io.ktor.client.engine.mock.*
import io.ktor.client.request.*
import io.ktor.client.statement.*
import io.ktor.utils.io.*
import kotlinx.coroutines.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }

    @Test
    fun testClientMock() {
        runBlocking {
            val client = HttpClient(MockEngine) {
                engine {
                    addHandler { request -> 
                        when (request.url.fullPath) {
                            "/" -> respond(
                                ByteReadChannel(byteArrayOf(1, 2, 3)),
                                headers = headersOf("X-MyHeader", "MyValue")
                            )
                            else -> respond("Not Found ${request.url.encodedPath}", HttpStatusCode.NotFound)
                        }
                    }
                }
                expectSuccess = false
            }
            assertEquals(byteArrayOf(1, 2, 3).toList(), client.get<ByteArray>("/").toList())
            assertEquals("MyValue", client.request<HttpResponse>("/").headers["X-MyHeader"])
            assertEquals("Not Found other/path", client.get<String>("/other/path"))
        }
    }
}

==> ./ktor-websockets-chat-sample/client/src/main/kotlin/com/jetbrains/handson/chat/client/ChatClient.kt <==
package com.jetbrains.handson.chat.client

import io.ktor.client.*
import io.ktor.client.features.websocket.*
import io.ktor.http.*
import io.ktor.http.cio.websocket.*
import io.ktor.util.*
import kotlinx.coroutines.*

@KtorExperimentalAPI
fun main() {
    val client = HttpClient { //Creates HttpClient
        install(WebSockets)   //Sets up Ktor's WebSocket plugin
    }
    runBlocking {   //Functions responsible fpr making network calls use the suspension mechanism from Kotlin's coroutines, so is wrapped in a runBlocking block
        client.webSocket(method = HttpMethod.Get, host = "127.0.0.1", port = 8080, path = "/chat") {
            val messageOutputRoutine = launch { outputMessages() }
            val userInputRoutine = launch { inputMessages() }

            userInputRoutine.join() // Wait for completion; either "exit" or error
            messageOutputRoutine.cancelAndJoin()
        }
    }
    client.close()
    println("Connection closed. Goodbye!")
}

suspend fun DefaultClientWebSocketSession.outputMessages() { //extension function for a DefaultClientWebSocketSession
    try {
        for (message in incoming) {
            message as? Frame.Text ?: continue
            println(message.readText())
        }
    } catch (e: Exception) {
        println("Error while receiving: " + e.localizedMessage)
    }
}

suspend fun DefaultClientWebSocketSession.inputMessages() {
    while (true) {
        val message = readLine() ?: ""
        if (message.equals("exit", true)) return
        try {
            send(message)
        } catch (e: Exception) {
            println("Error while sending: " + e.localizedMessage)
            return
        }
    }
}
==> ./ktor-websockets-chat-sample/server/src/main/kotlin/com/jetbrains/handson/chat/server/Application.kt <==
package com.jetbrains.handson.chat.server

import io.ktor.application.*
import io.ktor.http.cio.websocket.*
import io.ktor.routing.*
import io.ktor.websocket.*
import java.util.*


fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused")
fun Application.module() {

}

==> ./ktorIntellij/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/new") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
    }
}


==> ./ktorIntellij/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> ./ktorfromIntelliJplugin/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }
    }
}


==> ./ktorfromIntelliJplugin/test/ApplicationTest.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> BillSplitter/src/main/kotlin/com/example/controller/MainController.kt <==
package com.example.controller

import javafx.beans.property.SimpleDoubleProperty
import javafx.beans.property.SimpleIntegerProperty
import tornadofx.*

class MainController: Controller(){
    var totalPerPerson = SimpleDoubleProperty(0.0)
    var tipPercentageAmount = SimpleDoubleProperty(0.0)
    var sliderPercentageAmount = SimpleIntegerProperty(0)

    fun calculate(billAmtValue: SimpleDoubleProperty, splitByValue: SimpleIntegerProperty,
                    tipPercVal: SimpleIntegerProperty){
        //tipPercentageAmount.value = (billAmtValue*tipPercVal/100) - would not work
        tipPercentageAmount.cleanBind((billAmtValue*tipPercVal)/100)
        totalPerPerson.cleanBind((tipPercentageAmount.value.toProperty() + billAmtValue) / splitByValue)
        sliderPercentageAmount.cleanBind(tipPercVal)
    }

}
==> BillSplitter/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> BillSplitter/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import javafx.stage.Stage
import tornadofx.App

class MyApp: App(MainView::class, Styles::class){
    override fun start(stage: Stage){
        with(stage){
            width = 250.0
            height = 500.0
        }
        super.start(stage)
    }
}
==> BillSplitter/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*
import tornadofx.CssRule.Companion.c

class Styles : Stylesheet() {
    init {
        reloadViewsOnFocus()
        reloadStylesheetsOnFocus()
    }

    companion object {
        val heading by cssclass()
        val newStyle by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }

    init{
        newStyle{
            backgroundColor = multi(Color.AQUAMARINE)
            fontSize = 30.px
            fontWeight = FontWeight.EXTRA_BOLD
        }
    }
}
==> BillSplitter/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import com.example.controller.MainController
import javafx.beans.binding.Bindings
import javafx.beans.property.SimpleDoubleProperty
import javafx.beans.property.SimpleIntegerProperty
import javafx.geometry.Orientation
import javafx.geometry.Pos
import javafx.scene.control.ButtonType
import javafx.scene.control.ComboBox
import javafx.scene.control.Slider
import javafx.scene.control.TextField
import javafx.scene.input.KeyCode
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    val mainController: MainController by inject()

    var splitCombo: ComboBox<Int> by singleAssign()
    var mSlider: Slider by singleAssign()
    var billAmountField: TextField by singleAssign()

    override val root = vbox {
        alignment = Pos.TOP_CENTER
        label("Total Per Person").apply {
            addClass(Styles.newStyle)
        }
        label{
            addClass(Styles.newStyle)
            this.textProperty().bind(Bindings.concat("$",
                Bindings.format("%.2f", mainController.totalPerPerson)
                )
            )
        }

        form {
            fieldset(labelPosition = Orientation.HORIZONTAL) {
                field("Bill Amount") {
                    maxWidth = 190.0
                    addClass(Styles.heading)
                    billAmountField = textfield()
                    billAmountField.filterInput {
                        it.controlNewText.isDouble() || it.controlNewText.isInt()
                    }

                    billAmountField.setOnKeyPressed {
                        if (it.code == KeyCode.ENTER) {
                            validateField()
                        }
                    }
                }
                field {
                    label("Split By:") {

                    }
                    splitCombo = combobox(values = listOf(1, 2, 3, 4, 5, 6, 8, 9, 10)) {
                        prefWidth = 135.0
                        value = 1
                    }
                    splitCombo.valueProperty().onChange {
                        validateField()
                    }
                }
                field {
                    hbox(spacing = 23.0) {
                        label("Total Tip")
                        label().textProperty().bind(
                            Bindings.concat(
                                "$",
                            Bindings.format("%.2f", mainController.tipPercentageAmount)
                        ))
                    }
                }
                field {
                    hbox(spacing = 5.0) {
                        label("Tip %: ")
                        mSlider = slider(min = 0, max = 100, orientation = Orientation.HORIZONTAL)
                        mSlider.valueProperty().onChange {
                            validateField()
                        }
                        label().textProperty().bind(
                            Bindings.concat(
                                mainController.sliderPercentageAmount, "%"
                            )
                        )
                    }
                }
            }
        }
    }

    private fun validateField() {
        if (!billAmountField.toString().isEmpty()) {
            mainController.calculate(
                SimpleDoubleProperty(billAmountField.text.toDouble()),
                SimpleIntegerProperty(splitCombo.value),
                SimpleIntegerProperty(mSlider.value.toInt())
            )
        } else {
            error(
                "Error", "Empty field not allowed",
                buttons = *arrayOf(ButtonType.OK)
            )
        }
    }
}

==> BorderPane/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> BorderPane/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import tornadofx.App

class MyApp: App(MainView::class, Styles::class)
==> BorderPane/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> BorderPane/src/main/kotlin/com/example/view/BottomView.kt <==
package com.example.view

import javafx.scene.control.Label
import tornadofx.*

class BottomView : View("My View") {
    override val root: Label = label("Footer") {

    }
}

==> BorderPane/src/main/kotlin/com/example/view/CenterView.kt <==
package com.example.view

import tornadofx.*

class CenterView : View("My View") {
    override val root = borderpane {
        button("Center button")
    }
}

==> BorderPane/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import javafx.scene.layout.BorderPane
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    override fun onUndock(){
        print("Undock")
        super.onUndock()
    }

    override fun onDock() {
        print("Dock")
        super.onDock()
    }

    override fun onCreate(){
        print("On Create")
        super.onCreate()
    }

    override fun onBeforeShow() {
        print("Before Show!!")
        super.onBeforeShow()
    }

    val topView: TopView by inject()

    val centerView = find(CenterView::class)

    override val root: BorderPane = borderpane {

        //top, bottom, center, left, right
        /*top<TopView>()**/

        top = topView.root

        center = centerView.root

        bottom<BottomView>()

        left {
            label("Left")
        }

        right {
            label("Right")
        }
    }
}

==> BorderPane/src/main/kotlin/com/example/view/TopView.kt <==
package com.example.view

import javafx.geometry.Pos
import javafx.scene.layout.HBox
import tornadofx.*

class TopView : View("Top View") {
    override val root: HBox = hbox {
        alignment = Pos.CENTER
        spacing = 16.0
        label ("My View")
        button("Menu")
        button("File")

    }
}

==> BudgetTrackerApp/src/main/kotlin/com/example/app/BudgetTrackerWorkspace.kt <==
package com.example.app

import com.example.controller.ItemController
import com.example.model.ExpensesEntryTbl
import com.example.util.createTables
import com.example.util.enableConsoleLogger
import com.example.util.execute
import com.example.view.ExpensesEditor
import javafx.scene.control.TabPane
import org.jetbrains.exposed.sql.Database
import org.jetbrains.exposed.sql.insert
import tornadofx.*
import java.math.BigDecimal
import java.time.LocalDate

class BudgetTrackerWorkspace : Workspace("Budget tracker workspace", NavigationMode.Tabs) {
    init {
        enableConsoleLogger()
        //we initialize db etc...
        Database.connect("jdbc:sqlite:./app-bt250722.db", "org.sqlite.JDBC")
        createTables()

        //Controller(s)
        ItemController()
        //dock our views
        dock<ExpensesEditor>()

        tabContainer.tabClosingPolicy = TabPane.TabClosingPolicy.UNAVAILABLE //Do not want to be able to close tabs
    }
}

==> BudgetTrackerApp/src/main/kotlin/com/example/app/MyApp.kt <==
package com.example.app

import javafx.stage.Stage
import tornadofx.App

class MyApp: App(BudgetTrackerWorkspace::class, Styles::class){
    override fun start(stage: Stage) {
        with(stage){
            width = 1200.0
            height = 800.0
        }

        super.start(stage)
    }
}
==> BudgetTrackerApp/src/main/kotlin/com/example/app/Styles.kt <==
package com.example.app

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> BudgetTrackerApp/src/main/kotlin/com/example/controller/ItemController.kt <==
package com.example.controller

import com.example.model.ExpensesEntry
import com.example.model.ExpensesEntryModel
import com.example.model.ExpensesEntryTbl
import com.example.model.toExpensesEntry
import com.example.util.execute
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import javafx.scene.chart.PieChart
import org.jetbrains.exposed.sql.insert
import org.jetbrains.exposed.sql.update
import org.jetbrains.exposed.sql.selectAll
import tornadofx.Controller
import tornadofx.asObservable
import tornadofx.singleAssign
import java.math.BigDecimal
import java.time.LocalDate
import org.jetbrains.exposed.sql.deleteWhere

class ItemController: Controller() {
    private val listOfItems: ObservableList<ExpensesEntryModel> = execute {
        ExpensesEntryTbl.selectAll().map{
            ExpensesEntryModel().apply {
                item = it.toExpensesEntry()
            }
        }.asObservable()
    }

    var items: ObservableList<ExpensesEntryModel> by singleAssign()
    var pieItemsData = FXCollections.observableArrayList<PieChart.Data>()

    init {
        items = listOfItems

        items.forEach {
            pieItemsData.add(PieChart.Data(it.itemName.value, it.itemPrice.value.toDouble()))
        }
    }

    fun add(newEntryDate: LocalDate, newItem: String, newPrice: Double) : ExpensesEntry {
        val newEntry =  execute {
            ExpensesEntryTbl.insert {
                it[entryDate] = newEntryDate
                it[itemName] = newItem
                it[itemPrice] = BigDecimal.valueOf(newPrice)
            }
        }

        listOfItems.add(
            ExpensesEntryModel().apply {
                item = ExpensesEntry(newEntry[ExpensesEntryTbl.id], newEntryDate, newItem, newPrice)
            }
        )
        pieItemsData.add(PieChart.Data(newItem, newPrice))

        return ExpensesEntry(newEntry[ExpensesEntryTbl.id], newEntryDate, newItem, newPrice)
    }

    fun update(updatedItem: ExpensesEntryModel): Int {
        return execute {
            ExpensesEntryTbl.update ({ ExpensesEntryTbl.id.eq(updatedItem.id.value.toInt()) }) {
                it[entryDate] = updatedItem.entryDate.value
                it[itemName] = updatedItem.itemName.value
                it[itemPrice] = BigDecimal.valueOf(updatedItem.itemPrice.value.toDouble())
            }
        }
    }

    fun delete(deleteItem: ExpensesEntryModel) {
        execute {
            ExpensesEntryTbl.deleteWhere(null, null, {ExpensesEntryTbl.id.eq(deleteItem.id.value.toInt())})
        }
        listOfItems.remove(deleteItem)
        removeModelFromPie(deleteItem)
    }

    fun updatePie(model: ExpensesEntryModel) {
        val modelId = model.id
        var currentIndex = 0
        items.forEachIndexed { index, data ->
            if (modelId == data.id) {
                currentIndex = index
                pieItemsData[currentIndex].name = data.itemName.value
                pieItemsData[currentIndex].pieValue = data.itemPrice.value.toDouble()
            }
        }
    }

    fun removeModelFromPie(deleteItem: ExpensesEntryModel) {
        var currentIndex = 0
        pieItemsData.forEachIndexed { index, data ->
            if (data.name == deleteItem.itemName.value && index >= -1) {
                currentIndex = index
            }
        }
        pieItemsData.removeAt(currentIndex)
    }
}
==> BudgetTrackerApp/src/main/kotlin/com/example/main.kt <==
package com.example

import com.example.app.MyApp
import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> BudgetTrackerApp/src/main/kotlin/com/example/model/ExpensesEntryTbl.kt <==
package com.example.model

import javafx.beans.binding.Binding
import javafx.beans.binding.Bindings
import javafx.beans.property.SimpleDoubleProperty
import javafx.beans.property.SimpleIntegerProperty
import javafx.beans.property.SimpleObjectProperty
import javafx.beans.property.SimpleStringProperty
import tornadofx.*
import org.jetbrains.exposed.sql.ResultRow
import org.jetbrains.exposed.sql.Table
import org.jetbrains.exposed.sql.`java-time`.date
import java.time.LocalDate

fun ResultRow.toExpensesEntry() = ExpensesEntry(
    this[ExpensesEntryTbl.id],
    this[ExpensesEntryTbl.entryDate],
    this[ExpensesEntryTbl.itemName],
    this[ExpensesEntryTbl.itemPrice].toDouble()
)

object ExpensesEntryTbl : Table() {
    val id = integer("id").autoIncrement().primaryKey()
    val entryDate = date("entry_date")
    val itemName = varchar("name", length = 50)
    val itemPrice = decimal("price", scale = 2, precision = 9)
}

class ExpensesEntry(id: Int, entryDate: LocalDate, itemName: String, itemPrice: Double){
    val idProperty = SimpleIntegerProperty(id)
    var id by idProperty

    val entryDateProperty = SimpleObjectProperty(entryDate)
    var entryDate by entryDateProperty

    val itemPriceProperty = SimpleDoubleProperty(itemPrice)
    var itemPrice by itemPriceProperty

    val itemNameProperty = SimpleStringProperty(itemName)
    var itemName by itemNameProperty

    var totalExpenses = Bindings.add(itemPriceProperty, 0)

    override fun toString(): String {
        return "ExpensesEntry(id=$id, entryDate=$entryDate, itemName=$itemName, itemPrice=$itemPrice)"
    }
}

class ExpensesEntryModel : ItemViewModel<ExpensesEntry>() {
    val id = bind { item?.idProperty }
    val entryDate = bind { item?.entryDateProperty }
    val itemName = bind { item?.itemNameProperty }
    val itemPrice = bind { item?.itemPriceProperty }
    var totalExpenses = itemProperty.select( ExpensesEntry::totalExpenses )
}
==> BudgetTrackerApp/src/main/kotlin/com/example/util/database.kt <==
package com.example.util

import com.example.model.ExpensesEntryTbl
import org.jetbrains.exposed.sql.SchemaUtils
import org.jetbrains.exposed.sql.StdOutSqlLogger
import org.jetbrains.exposed.sql.Transaction
import org.jetbrains.exposed.sql.addLogger
import org.jetbrains.exposed.sql.transactions.TransactionManager
import java.sql.Connection

private var LOG_TO_CONSOLE: Boolean = false

fun newTransaction(): Transaction =
    TransactionManager.currentOrNew(Connection.TRANSACTION_SERIALIZABLE)
        .apply {
            if (LOG_TO_CONSOLE) addLogger(StdOutSqlLogger)
        }

fun enableConsoleLogger() {
    LOG_TO_CONSOLE = true
}

fun createTables(){
    with(newTransaction()){
        SchemaUtils.create(ExpensesEntryTbl) //can pass as many tables as we want/need
    }
}

fun <T> execute(command: () -> T) : T {
    with(newTransaction()){
        return command().apply{
            commit() //commit changes
            close()  //close databse
        }
    }
}


==> BudgetTrackerApp/src/main/kotlin/com/example/util/utilities.kt <==
/*package com.example.util

import org.joda.time.DateTime
import java.time.LocalDate

fun DateTime.toJavaLocalDate(): LocalDate {
    return java.time.LocalDate.of(this.year, this.monthOfYear, this.dayOfMonth)
}

fun LocalDate.toDate(default: DateTime = org.joda.time.DateTime(1900, 1, 1, 0, 0, 0 )): DateTime{
    return DateTime(this.year, this.monthValue, this.dayOfMonth, 0, 0, 0)
}*/
==> BudgetTrackerApp/src/main/kotlin/com/example/view/ExpensesEditor.kt <==
package com.example.view

import com.example.controller.ItemController
import com.example.model.ExpensesEntryModel
import javafx.beans.binding.Bindings
import javafx.beans.property.Property
import javafx.beans.property.SimpleDoubleProperty
import javafx.geometry.Pos
import javafx.scene.control.Button
import javafx.scene.control.Label
import javafx.scene.input.KeyCode
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*
import java.lang.Exception

class ExpensesEditor : View("Expenses") {
    private val model = ExpensesEntryModel()
    private val controller: ItemController by inject()

    var mTableView : TableViewEditModel<ExpensesEntryModel> by singleAssign()
    var totalExpensesLabel: Label by singleAssign()
    val totalExpensesProperty = SimpleDoubleProperty(0.0)
    var deleteButton: Button by singleAssign()

    init {
        updateTotalExpenses()
    }

    override val root = borderpane {
        /*
        disableDelete()
        disableCreate()
        To gray out the icons on the top bar
         */

        disableSave()
        disableRefresh()

        center = vbox {
            form {
                fieldset {
                    field("Entry Date") {
                        maxWidth = 220.0
                        //binds to model entryDate field
                        datepicker(model.entryDate) {
                            this.required()
                            validator {
                                when {
                                    it?.dayOfMonth.toString().isEmpty() || it?.dayOfYear.toString().isEmpty() ->
                                        error("The date entry cannot be blank")
                                    else -> null
                                }
                            }
                        }
                    }
                }
                fieldset {
                    field("Item") {
                        maxWidth = 220.0
                        //binds to model itemName field
                        textfield (model.itemName) {
                            this.required()
                            validator {
                                when {
                                    it.isNullOrEmpty() -> error("Field cannot be null")
                                    it.length < 3 -> error("Field cannot be less than 3 characters")
                                    else -> null
                                }
                            }
                        }
                    }
                }
                fieldset {
                    field("Price") {
                        maxWidth = 220.0
                        //binds to model itemPrice field
                        textfield(model.itemPrice) {
                            this.required()
                            validator {
                                when {
                                    it == null -> error("Price cannot be blank")
                                    it.contains("[^0-9\\.]".toRegex())-> error("Field must contain only numbers")
                                    it.contains("\\.[^$]*\\.".toRegex()) -> error("Field can ony have one decimal point")
                                    it.contains("\\.[0-9]{3}".toRegex()) -> error("can only contain two decimal places")
                                    else -> null
                                }
                            }

                            setOnKeyPressed {
                                if (it.code == KeyCode.ENTER) {
                                    onCreate()
                                }
                            }
                        }
                    }
                }
                hbox( 10.0) {
                    button("Add Item") {
                        enableWhen(model.valid)
                        action {
                            onCreate()
                        }
                    }
                    deleteButton = button("Delete") {
                        action{
                            onDelete()
                        }
                    }
                    button("Reset") {
                        enableWhen(model.valid)
                        action {
                            model.rollback()
                        }
                    }
                }
                fieldset {
                    paddingTop = 15.0
                    tableview<ExpensesEntryModel> {
                        items = controller.items
                        mTableView = editModel
                        column("ID", ExpensesEntryModel::id)
                        column("Added", ExpensesEntryModel::entryDate).makeEditable()
                        column("Name", ExpensesEntryModel::itemName).makeEditable()
                        column("Price", ExpensesEntryModel::itemPrice).makeEditable()

                        onEditCommit {
                            controller.update(it)
                            updateTotalExpenses()
                            controller.updatePie(it)
                        }
                    }
                }
            }
        }

        right = vbox(2) {
            alignment = Pos.CENTER
            paddingBottom = 10.0

            piechart {
                data = controller.pieItemsData
            }

            totalExpensesLabel = label {
                if (totalExpensesProperty.doubleValue() != 0.0) {
                    style {
                        fontSize = 19.px
                        padding = box(10.px, 0.px, 0.px, 0.px)
                        textFill = Color.GREEN
                        fontWeight = FontWeight.EXTRA_BOLD
                        borderRadius = multi(box(8.px))
                    }
                    bind(Bindings.concat("Total Expenses: ", "£", Bindings.format("%.2f", totalExpensesProperty)))
                } else { }
            }
        }
    }

    private fun updateTotalExpenses() {
        var total = 0.0
        try {
            controller.items.forEach {
                total += it.itemPrice.value.toDouble()
            }
            totalExpensesProperty.set(total)
            model.totalExpenses.value = total
        } catch (e:Exception) {
            totalExpensesProperty.set(0.0)
        }
    }

    private fun addItem() {
        controller.add(model.entryDate.value, model.itemName.value, model.itemPrice.value.toDouble())
        updateTotalExpenses()
    }

    override fun onDelete() {
        val selectedItem = mTableView.tableView.selectedItem
        when (selectedItem) {
            null -> return
            else -> {
                val diff = totalExpensesProperty.value - selectedItem.item.itemPrice
                totalExpensesProperty.value = diff
            }
        }
        controller.delete(selectedItem)
        updateTotalExpenses()
    }

    override fun onCreate() {
        model.commit{
            addItem()
            model.rollback() //clears the fields on screen
        }
    }
}

==> BudgetTrackerApp/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.app.Styles
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    override val root = hbox {
        label(title) {
            addClass(Styles.heading)
        }
    }
}

==> DataControls/src/main/kotlin/com/example/controller/MainController.kt <==
package com.example.controller

import com.example.model.Student
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import tornadofx.Controller
import tornadofx.observable
import java.time.LocalDate

class MainController : Controller() {
    val studentsData = FXCollections.observableArrayList<Student>(
        Student(1, "Jose", "Marilla",
            LocalDate.of(2000,11,20)),
        Student(2, "Candy", "Ass",
            LocalDate.of(1999,9,5)),
        Student(3, "Helena", "Mount",
            LocalDate.of(2000,7,21)),
        Student(4, "Katrina", "Hurricane",
            LocalDate.of(2000,2,12)),
    )

    val students = FXCollections.observableArrayList<String>(
        "Gina Machava",
        "James Bond",
        "Helena Mt",
        "Georgina Emma"
    )

    fun addStudent(fullName:String){
        students.add(fullName)
    }

    fun addNewStudent(student: Student){
        studentsData.add(student)
    }

    val studentNames = listOf(
        "Gina Machava",
        "James Bond",
        "Helena Mt",
        "Georgina Emma"
    ).observable()
}
==> DataControls/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> DataControls/src/main/kotlin/com/example/model/Student.kt <==
package com.example.model

import javafx.beans.property.Property
import tornadofx.*
import javafx.beans.property.SimpleIntegerProperty
import javafx.beans.property.SimpleObjectProperty
import javafx.beans.property.SimpleStringProperty
import java.time.LocalDate
import java.time.Period

/*class Student(val id: Int, val firstName: String, val lastName: String, val birthday: LocalDate){
    val age: Int get() = Period.between(birthday, LocalDate.now()).years
}*/

class Student(id: Int, firstName: String, lastName: String, birthday: LocalDate){
    val idProperty = SimpleIntegerProperty(id)
    var id: Int by idProperty

    val firstNameProperty = SimpleStringProperty(firstName)
    var firstName: String by firstNameProperty

    val lastNameProperty = SimpleStringProperty(lastName)
    var lastName: String by lastNameProperty

    val birthdayProperty = SimpleObjectProperty<LocalDate>(birthday)
    var birthday by birthdayProperty

    val age: Int get() = Period.between(birthday, LocalDate.now()).years
}

class StudentModel : ItemViewModel<Student>(){
    val id = bind { item?.idProperty }
    val firstName: Property<String> = bind {item?.firstNameProperty}
    val lastName: Property<String> = bind {item?.lastNameProperty}
    val dob: Property<LocalDate> = bind {item?.birthdayProperty}
}
==> DataControls/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import javafx.stage.Stage
import tornadofx.App

class MyApp: App(MainView::class, Styles::class){
    override fun start(stage: Stage){
        with (stage){
            width = 700.0
            height= 700.0
        }
        super.start(stage)
    }
}
==> DataControls/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> DataControls/src/main/kotlin/com/example/view/BottomView.kt <==
package com.example.view

import com.example.controller.MainController
import javafx.beans.property.SimpleStringProperty
import tornadofx.*

class BottomView : View("My View") {
    val mainController: MainController by inject()

    val firstName = SimpleStringProperty()
    val lastName = SimpleStringProperty()

    override val root = form {
        fieldset {
            field("Add First Name") {
                textfield(firstName)
            }
            field("Add Last Name") {
                textfield(lastName)
            }
        }

        hbox {
            button {
                text = "Save Student"
                action {
                    if (firstName.value.isNullOrEmpty() || lastName.value.isNullOrEmpty()){

                    } else {
                        val fullName: String = firstName.value + " " + lastName.value
                        mainController.addStudent(fullName)

                        firstName.value = ""
                        lastName.value = ""
                    }
                }
            }
        }
    }
}

==> DataControls/src/main/kotlin/com/example/view/CenterView.kt <==
package com.example.view

import com.example.controller.MainController
import com.example.model.Student
import com.example.model.StudentModel
import javafx.scene.control.TableView
import tornadofx.*

class CenterView : View("My View") {
    val mainController : MainController by inject()
    val model: StudentModel by inject()

    //If using Strings, etc, can only use readonlyColumns
     /*TableView<Student> = tableview<Student> {
        items = mainController.studentsData
        readonlyColumn("ID", Student::id)
        readonlyColumn("First name", Student::firstName)
        readonlyColumn("Last Name", Student::lastName)
        readonlyColumn("Student Age", Student::age)
    }*/


    override val root: TableView<Student> = tableview<Student> {
        items = mainController.studentsData
        isEditable = true
        column("ID", Student::idProperty)
        column("First Name", Student::firstNameProperty)
        column("Last Name", Student::lastNameProperty)
        readonlyColumn("Student Age", Student::age)

        bindSelected(model)
    }
}

==> DataControls/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import com.example.controller.MainController
import javafx.collections.FXCollections
import javafx.scene.paint.Color
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    val mainController: MainController by inject()
    val bottomView: BottomView by inject()
    val topView: TopView by inject()
    val centerView: CenterView by inject()
    val studentEditor: StudentEditor by inject()

    override val root = borderpane() {
        //bottom = bottomView.root
        //top = topView.root
        center= centerView.root
        left = studentEditor.root

        /*hbox {
            listview(values = studentNames)

            listview<String> {
                items.add("James")
                items.add("Katarina")
                items.add("Arao")
                items.add("Ronaldo")
            }
            listview(mainController.students) {
                cellFormat {
                    text = it
                    if (text.contains("Emma")) {
                        //textFill = Color.AQUAMARINE
                        textFill = c("green", 0.4)
                        style {
                            fontSize = 20.px
                        }
                    }
                }
            }

        }
        button {
            text = "Add Student"
            action {
                mainController.students.add("New Student")
            }
        }*/
    }
}

==> DataControls/src/main/kotlin/com/example/view/StudentEditor.kt <==
package com.example.view

import com.example.controller.MainController
import com.example.model.Student
import com.example.model.StudentModel
import javafx.beans.property.SimpleObjectProperty
import javafx.beans.property.SimpleStringProperty
import tornadofx.*
import java.time.LocalDate

class StudentEditor : View("My View") {
    val mainController: MainController by inject()
    /*val firstName = SimpleStringProperty()
    val lastName = SimpleStringProperty()
    val dob = SimpleObjectProperty<LocalDate>()*/

    val model: StudentModel by inject()

    override val root = form{
        fieldset{
            field("First Name"){
                textfield(model.firstName){
                    //required()
                    validator {
                        if (it.isNullOrEmpty()) error("This is required") else null
                    }
                }
            }
            field("Last Name"){
                textfield(model.lastName).required()
            }
            field("DOB"){
                    datepicker(model.dob).required()
            }
            hbox{
                button("Save"){
                    enableWhen(model.dirty)
                    action{
                        model.commit{
                            val student = Student(1, model.firstName.value, model.lastName.value, model.dob.value)
                            mainController.addNewStudent(student)
                        }
                    }
                }
                button("Reset"){
                    enableWhen(model.dirty)
                    action{
                        model.rollback()
                    }
                }
            }


        }
    }
}

==> DataControls/src/main/kotlin/com/example/view/TopView.kt <==
package com.example.view

import com.example.controller.MainController
import tornadofx.*

class TopView : View("My View") {
    val mainController: MainController by inject()
    override val root = listview(mainController.students) {
        cellFormat {
            text = it
            if (text.contains("Emma")) {
                //textFill = Color.AQUAMARINE
                textFill = c("green", 0.4)
                style {
                    fontSize = 20.px
                }
            }
        }
    }
}

==> JavaFXAPP/src/main/kotlin/com/example/controller/BubbleController.kt <==
package com.example.controller

import com.example.view.MainView
import javafx.animation.Interpolator
import javafx.beans.property.SimpleStringProperty
import javafx.geometry.Point2D
import javafx.scene.Node
import javafx.scene.input.MouseEvent
import javafx.scene.media.AudioClip
import javafx.scene.paint.Color
import javafx.scene.shape.Circle
import javafx.util.Duration
import tornadofx.*

class BubbleController:Controller(){
    private var circle = Circle()
    private var audioClip = AudioClip(
        MainView::class.java.getResource("/celestial-sound.wav")
        .toExternalForm())
    var mText = SimpleStringProperty()
    private val colorList: List<String> = listOf(
        "#cdeded",
        "#1A1A1A",
        "#707070",
        "#8E8E38",
        "#71C671",
        "#7171C6",
        "#800000",
        "#EE0000",
        "#CD5C5C",
        "#CDC5BF",
        "#8B7765",
        "#FF8000",
        "#E3CF57",
        "#8B8B00",
        "#6B8E23",
        "#00EE76",
        "#2F4F4F",
        "#00BFFF",
        "#1E90FF",
        "#6E7B8B",
        "#00008B",
        "#AB82FF",
        "#9400D3",
        "#FF00FF",
        "#FFBBFF",
        "#C71585"
    )

    private val listOfText: List<String> = listOf(
        "A tall, gracile, brown-eyed girl entered the circle, raven hair shading her face, revealing a straight aquiline nose. A wide, tan coloured skirt stretched down\n" +
                "past her knees, but her feet were bare", "She dropped to the ground suddenly, beginning to gyrate her bare midriff, revealing for a moment a glimpse of her eyes. Leaning forward, she scooped\n" +
                "large handfuls of loose dry soil, leaking from her fingers as her arms began to\n" +
                "rise.", "Spirals of dust were left twirling in the midday sun, before an unseen\n" +
                "movement made both handfuls explode in a greyish-brown cloud, obscuring\n" +
                "her from view - plumes erupted, girl invisible behind spraying fountains.", "Keep Learning", "You Can Do It!", "Hakuna Matata",
        "Hakuna MatataMore spirals appeared amidst the smoke as the girl rose to her feet, twisting\n" +
                "See the World", "Drink Water", "Eat Well", "Be Well", "Travel the World", "Think Different",
        "Assess Everything", "Be A Force of Nature", "Be the Change in the World", "Do"
    )

    fun addCircle(it: MouseEvent, root: Node) {
        val mousePt: Point2D = root.sceneToLocal(it.sceneX , it.sceneY)

        if (audioClip.isPlaying){
            audioClip.volumeProperty().value = 0.3
            audioClip.panProperty().value = 1.0
        } else {
            audioClip.volumeProperty().value = 0.8
            audioClip.play()
        }

        circle = Circle(mousePt.x, mousePt.y, 14.5, Color.ORANGERED)
        circle.apply{
            animateFill(Duration.seconds(0.9), c(randomColor()), Color.TRANSPARENT)
        }
        timeline {
            keyframe(Duration.seconds(1.0)){
                keyvalue(circle.radiusProperty(), 250, Interpolator.EASE_BOTH)
                keyvalue(circle.centerYProperty(), 100, Interpolator.EASE_BOTH)
            }
        }

        root.getChildList()!!.add(circle)
    }

    fun addRandomText() {
        val listSize = listOfText.size
        val randomNum = (0 until listSize).shuffled().last()

        mText.set(listOfText[randomNum])
    }

    private fun randomColor(): String {
        val listSize: Int = colorList.size
        val randomNum = (0 until listSize).shuffled().last()

        return colorList[randomNum]
    }
}
==> JavaFXAPP/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> JavaFXAPP/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import tornadofx.App

class MyApp: App(MainView::class, Styles::class)
==> JavaFXAPP/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> JavaFXAPP/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import com.example.controller.BubbleController

import javafx.scene.paint.Color
import javafx.scene.shape.Circle
import javafx.util.Duration
import javafx.animation.Interpolator
import javafx.geometry.Pos
import javafx.scene.control.Label
import javafx.scene.input.MouseDragEvent
import tornadofx.*

class MainView : View("Bubbles and Ripples!!!") {
    private val bubbleController: BubbleController by inject()
    private var circle = Circle()
    private var myLabel: Label by singleAssign()
    override val root = borderpane {
        setPrefSize(1000.0, 800.0)
        /*center {
        }*/
        bottom{
            label(title) {

                myLabel = this
                addClass(Styles.heading)
                bind(bubbleController.mText)
            }
            /*label("Click Anywhere..."){
                alignment = Pos.BOTTOM_CENTER
                paddingAll = 19.0
            }.apply{
                style{
                    opacity = 0.3
                    fontSize = 25.px
                }
            }*/
        }
    }.apply{
        style{
            backgroundColor += c("#E0EEEE")
        }

        addEventFilter(MouseDragEvent.MOUSE_CLICKED) {

            myLabel.opacity = 1.0
            myLabel.layoutY = 400.0

            bubbleController.addCircle(it, this)
            bubbleController.addRandomText()

            circle = Circle(myLabel.layoutX, myLabel.layoutY, 4.5, Color.ORANGERED)

            timeline{
                keyframe(Duration.seconds(0.3)){
                    keyvalue(myLabel.styleProperty(), "-fx-font-size: 25",
                        Interpolator.EASE_BOTH)
                }
                keyframe(Duration.seconds(0.0)){
                    keyvalue(myLabel.opacityProperty(), 1, Interpolator.EASE_BOTH)
                }
                keyframe(Duration.seconds(0.0)){
                    keyvalue(myLabel.translateYProperty(), 0.0, Interpolator.EASE_BOTH)//(this@apply.height - 100))
                }
                keyframe(Duration.seconds(8.5)){
                    keyvalue(myLabel.translateYProperty(), -800.0, Interpolator.EASE_BOTH)//(this@apply.height - 100))
                }
                keyframe(Duration.seconds(8.0)){
                    keyvalue(myLabel.opacityProperty(), 0, Interpolator.EASE_BOTH)
                }
            }
        }
    }
}
==> Klimatic/src/main/kotlin/com/example/controller/ForecastController.kt <==
package com.example.controller

import com.example.model.City
import com.example.model.CityModel
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import tornadofx.*
import java.text.SimpleDateFormat
import java.util.*

class ForecastController: Controller(){
    var allWeather = FXCollections.emptyObservableList<City>()
    val api: Rest by inject()
    val selectedCity: CityModel by inject()

    fun getIcon(iconString: String) = when(iconString) {
        "Rain" -> "rain"
        "Clouds" -> "clouds"
        "Snow" -> "snow"
        "Clear" -> "clear"
        "Drizzle" -> "rain"
        "Fog" -> "fog"
        else -> "clear"
    }

    fun getFormattedDate(date: Long) = SimpleDateFormat("EEE, d MMM, YYYY").format(Date(date * 1000))

    fun listPayload(latitude: Double = selectedCity.lat.value, longitude: Double = selectedCity.lon.value) : ObservableList<City> {
        val forecast = api.get("https://api.openweathermap.org/data/2.5/onecall?lat=$latitude&lon=$longitude&exclude=minutely,hourly&appid=37515839fc422f35997fa945f15d2c53")
            .list().toModel<City>()

        forecast[0].daily.forEach {
            print("Forecast::::${it.temp.day}\n")
        }

        return forecast
    }
}
==> Klimatic/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> Klimatic/src/main/kotlin/com/example/model/City.kt <==
package com.example.model

import javafx.beans.property.*
import tornadofx.*
import javax.json.JsonObject
import kotlin.reflect.KProperty

class City : JsonModel {
    val latProperty = SimpleDoubleProperty()
    var lat: Double by latProperty

    val lonProperty = SimpleDoubleProperty()
    var lon: Double by lonProperty

    val nameProperty = SimpleStringProperty()
    var name: String by nameProperty

    val dailyProperty = SimpleListProperty<Daily>()
    var daily: List<Daily> by property(dailyProperty)

    override fun updateModel(json: JsonObject) {
        with(json){
            lat = getDouble("lat")
            lon = getDouble("lon")
            name = getString("timezone")
            daily = getJsonArray("daily").toModel()
        }
    }

    override fun toString() = name!!
}

class CityModel : ItemViewModel<City>(){
    var lon = bind(City::lonProperty)
    var lat = bind(City::latProperty)
    var name = bind(City::nameProperty)
    var daily = bind(City::dailyProperty)
}
==> Klimatic/src/main/kotlin/com/example/model/Daily.kt <==
package com.example.model

import javafx.beans.property.*
import tornadofx.*
import javax.json.JsonObject
import kotlin.reflect.KProperty

class Daily : JsonModel{
    val dtProperty = SimpleIntegerProperty()
    var dt by dtProperty

    val humidityProperty = SimpleIntegerProperty()
    var humidity by humidityProperty

    val speedProperty = SimpleDoubleProperty()
    var speed by speedProperty

    val tempProperty = SimpleObjectProperty<Temp>()
    var temp by tempProperty

    val weatherProperty = SimpleListProperty<Weather>()
    var weather: List<Weather> by property(weatherProperty)

    override fun updateModel(json: JsonObject) {
        with(json){
            dt = getInt("dt")
            speed = getDouble("wind_speed")
            humidity = getInt("humidity")
            temp = getJsonObject("temp").toModel()
            weather = getJsonArray("weather").toModel()
        }
    }
}


==> Klimatic/src/main/kotlin/com/example/model/ForecastPayload.kt <==
package com.example.model

import javafx.beans.property.SimpleListProperty
import tornadofx.*
import javax.json.JsonObject

class ForecastPayload: JsonModel{
    val dailyProperty = SimpleListProperty<Daily>()
    var daily: List<Daily> by property(dailyProperty)

    override fun updateModel(json: JsonObject) {
        with(json){
            daily = getJsonArray("daily").toModel()
        }
    }
}
==> Klimatic/src/main/kotlin/com/example/model/Temp.kt <==
package com.example.model

import javafx.beans.property.SimpleDoubleProperty
import javafx.beans.property.SimpleStringProperty
import tornadofx.*
import javax.json.JsonObject
import kotlin.reflect.KProperty

class Temp: JsonModel{
    val dayProperty = SimpleDoubleProperty()
    var day: Double by dayProperty

    val minProperty = SimpleDoubleProperty()
    var min: Double by minProperty

    val maxProperty = SimpleDoubleProperty()
    var max: Double by maxProperty

    val nightProperty = SimpleDoubleProperty()
    var night: Double by nightProperty

    val eveProperty = SimpleDoubleProperty()
    var eve: Double by eveProperty

    val mornProperty = SimpleDoubleProperty()
    var morn: Double by mornProperty

    override fun updateModel(json: JsonObject) {
        with(json){
            morn = getDouble("morn")
            eve = getDouble("eve")
            night = getDouble("night")
            max = getDouble("max")
            day = getDouble("day")
            min = getDouble("min")
        }
    }
}


==> Klimatic/src/main/kotlin/com/example/model/Weather.kt <==
package com.example.model

import javafx.beans.property.SimpleIntegerProperty
import javafx.beans.property.SimpleStringProperty
import tornadofx.*
import javax.json.JsonObject
import kotlin.reflect.KProperty

class Weather : JsonModel{
    val mainProperty = SimpleStringProperty()
    var main: String by mainProperty

    val descriptionProperty = SimpleStringProperty()
    var description: String by descriptionProperty

    val iconProperty = SimpleStringProperty()
    var icon: String by iconProperty

    val idProperty = SimpleIntegerProperty()
    var id: Int by idProperty

    override fun updateModel(json: JsonObject) {
        with(json){
            icon = getString("icon")
            description = getString("description")
            main = getString("main")
            id = getInt("id")
        }
    }
}
==> Klimatic/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.WeatherForecast
import javafx.stage.Stage
import tornadofx.App

class MyApp: App(WeatherForecast::class, Styles::class){
    override fun start(stage: Stage) {
        with (stage){
            width = 1400.0
            height = 800.0
        }

        super.start(stage)
    }
}
==> Klimatic/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
        val mainLabels by cssclass()
    }

    init {
        mainLabels{
            fontSize = 20.px
            fill = Color.GRAY
        }
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> Klimatic/src/main/kotlin/com/example/util/utils.kt <==
package com.example.util

val appid = "37515839fc422f35997fa945f15d2c53"
==> Klimatic/src/main/kotlin/com/example/view/WeatherForecast.kt <==
package com.example.view

import com.example.Styles
import com.example.controller.ForecastController
import javafx.beans.binding.Bindings
import com.example.model.City
import com.example.model.Daily
import javafx.beans.property.SimpleDoubleProperty
import javafx.geometry.Orientation
import javafx.geometry.Pos
import javafx.scene.control.ButtonType
import javafx.scene.control.*
import javafx.scene.input.KeyCode
import javafx.scene.layout.*
import javafx.scene.paint.Color
import javafx.scene.text.FontPosture
import tornadofx.*

class WeatherForecast : View("Hello TornadoFX") {
    val controller: ForecastController by inject()
    var latField: TextField by singleAssign()
    var lonField: TextField by singleAssign()
    var latValid = false
    var lonValid = false
    var cityLabel: Label by singleAssign()
    var todayTemp: Label by singleAssign()
    var todayIcon: Label by singleAssign()
    var sevenDayLabel: Label by singleAssign()
    var dividerHB: HBox by singleAssign()
    var forecastPayload = City()
    var forecastView: DataGrid<Daily> by singleAssign()

    init{
        controller.listPayload(latitude = 51.51, longitude = 0.13)
    }

    override val root = borderpane {
        style{
            backgroundColor += c("#666699")
        }
        center = vbox{
            currentWeatherView()
            vbox{
                alignment = Pos.TOP_CENTER
                cityLabel = label()
                todayIcon = label()
                todayTemp = label()
                sevenDayLabel = label()
                dividerHB = HBox()
                forecastView = datagrid()
            }
        }
    }

    private fun VBox.currentWeatherView() = vbox {
        form{
            paddingAll = 20.0
            fieldset {
                field("Enter Latitude", Orientation.VERTICAL) {
                    latField = textfield(){
                        filterInput {
                            it.controlNewText.isDouble()
                        }
                        setOnKeyPressed {
                            if (it.code == KeyCode.ENTER){
                                runAsync {
                                    validateLat()
                                }
                            }
                        }
                    }
                }
                field("Enter Longitude", Orientation.VERTICAL) {
                    lonField = textfield(){
                        filterInput {
                            it.controlNewText.isDouble()
                        }
                        setOnKeyPressed{
                            if (it.code == KeyCode.ENTER){
                                runAsync {
                                    validateLon()
                                } ui {
                                    vbox{
                                        if (lonValid && latValid) {
                                            forecastPayload = controller.allWeather[0]
                                            cityLabel.text = forecastPayload.name + " " + controller.getFormattedDate(forecastPayload.daily[0].dt.toLong())
                                            cityLabel.apply {
                                                addClass(Styles.mainLabels)
                                            }
                                            latValid = false
                                            lonValid = false
                                            todayTemp.text = "%.2f".format(forecastPayload.daily[0].temp.day - 273.15).toString() + "°C" + " ${forecastPayload.daily[0].weather[0].description}"
                                            todayTemp.apply {
                                                addClass(Styles.mainLabels)
                                            }

                                            todayIcon.graphic = imageview("${controller.getIcon(
                                                    forecastPayload.daily[0].weather[0].main
                                                    )}.png", lazyload = true){
                                                fitHeight = 200.0
                                                fitWidth = 200.0
                                            }
                                            dividerHB.style{
                                                borderColor += box(Color.TRANSPARENT, Color.TRANSPARENT, Color.TRANSPARENT, Color.TRANSPARENT)
                                            }
                                            sevenDayLabel.text = "7-Day Weather Forecast"
                                            sevenDayLabel.style {
                                                fill = Color.GREY
                                                fontStyle = FontPosture.ITALIC
                                                opacity = 0.7
                                            }

                                            forecastView.items = forecastPayload.daily.observable()
                                            forecastView.apply {
                                                cellWidth = 150.0
                                                cellHeight = 230.0
                                                cellCache{
                                                    stackpane {
                                                        vbox(alignment = Pos.TOP_CENTER) {
                                                            label(controller.getFormattedDate(it.dtProperty.value.toLong())
                                                                .split(",")[0])
                                                            label{
                                                                graphic = imageview("${controller.getIcon(
                                                                    it.weather[0].mainProperty.value)}.png").apply{
                                                                        fitHeight = 100.0
                                                                        fitWidth = 100.0
                                                                }
                                                            }
                                                            paddingBottom = 20.0
                                                        }
                                                        vbox(alignment = Pos.CENTER){
                                                            paddingTop = 105.0
                                                            label("Min: " + "%.2f".format(it.temp.min - 273.15).toString() + "°c")
                                                            label("Max: " + "%.2f".format(it.temp.max - 273.15).toString() + "°c")
                                                            label{
                                                                this.textProperty().bind(
                                                                    Bindings.concat("Hum: ", it.humidityProperty, "%")
                                                                )
                                                            }
                                                            label(it.weather[0].description)
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private fun validateLat() : Boolean {
        if(!latField.toString().isEmpty()){
            controller.selectedCity.lat = SimpleDoubleProperty(latField.text.toDouble())
            latValid = true
            callPayload()
        } else {
            error(
                "Error", "Empty field not allowed", buttons = *arrayOf(ButtonType.OK)
            )
        }

        return latValid
    }

    private fun validateLon() : Boolean{
        if(!lonField.toString().isEmpty()){
            controller.selectedCity.lon = SimpleDoubleProperty(lonField.text.toDouble())
            lonValid = true
            callPayload()
        } else {
            error(
                "Error", "Empty field not allowed", buttons = *arrayOf(ButtonType.OK)
            )
        }

        return lonValid
    }

    private fun callPayload(){
        if (latValid && lonValid){
            print("New forecast for Lat: ${controller.selectedCity.lat.value} and Lon: ${controller.selectedCity.lon.value}\n")
            controller.allWeather = controller.listPayload()
        }
    }
}

==> NewProj/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> NewProj/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import tornadofx.App

class MyApp: App(MainView::class, Styles::class)
==> NewProj/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> NewProj/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    override val root = hbox {
        label(title) {
            addClass(Styles.heading)
        }
    }
}

==> ShapesApp/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> ShapesApp/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import javafx.stage.Stage
import tornadofx.App
import tornadofx.reloadStylesheetsOnFocus
import tornadofx.reloadViewsOnFocus

class MyApp: App(MainView::class, Styles::class){
    init {
        reloadStylesheetsOnFocus()
        reloadViewsOnFocus()
    }


    override fun start(stage: Stage) {
        with(stage){
            minWidth = 800.0
            minHeight = 600.0
        }

        super.start(stage)
    }
}
==> ShapesApp/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 23.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> ShapesApp/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import javafx.animation.Interpolator
import javafx.geometry.Pos
import javafx.scene.paint.Color
import javafx.util.Duration
import tornadofx.*

class MainView : View("Shapes") {
    override val root = borderpane {
        center = vbox {
            alignment = Pos.CENTER
            label(title) {
                addClass(Styles.heading)
            }

            rectangle {
                width = 100.0
                height = 80.0
                x = 700.0
                y = 100.0
                style{
                    fill = Color.GREEN
                }
            }

            val myCirc = circle{
                isManaged = false
                radius = 89.0
                centerX = 400.0
                centerY = 100.0
            }

            line{
                isManaged= false
                startX = 23.0
                startY = 23.0
                endX = 120.0
                endY= 100.0
            }

            //myCirc.radiusProperty().animate(endValue = 1, duration = 3.seconds)
            timeline {
                keyframe(Duration.seconds(2.0)){
                    keyvalue(myCirc.radiusProperty(), 34.0, Interpolator.EASE_BOTH)
                }
                isAutoReverse = true
                cycleCount = 4
            }
        }
    }
}

==> Styles/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> Styles/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import javafx.stage.Stage
import tornadofx.App
import tornadofx.reloadStylesheetsOnFocus
import tornadofx.reloadViewsOnFocus

class MyApp: App(MainView::class, Styles::class){
    init{
        reloadStylesheetsOnFocus()
        reloadViewsOnFocus()
    }
    override fun start(stage: Stage) {
        with(stage){
            width = 1000.0
            height = 800.0
        }

        super.start(stage)
    }
}
==> Styles/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
        val ourStyle: CssRule by cssclass()

        private val topColor: Color = c("#cedede")
        private val rightColor: Color = c("green")
        private val leftColor: Color = Color.RED
        private val bottomColor: Color = c(red = 123, green = 21, blue = 111)
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
        ourStyle{
            borderColor = multi(box(
                top = topColor,
                right = rightColor,
                left = leftColor,
                bottom = bottomColor
            ))
        }
    }
}
==> Styles/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    override val root = vbox {
        label(title) {
            style {
                fontSize = 30.px
                fontWeight = FontWeight.BOLD
                textFill = Color.GREEN
            }
        }
        button("Hello Again"){
            style{
                addClass(Styles.ourStyle)
               // fontWeight = FontWeight.EXTRA_BOLD
               // backgroundColor = multi(c("aliceblue"))
            }
        }

        button("Hello Twice"){
            style{
                fontWeight = FontWeight.EXTRA_BOLD
                backgroundColor = multi(Color.AQUAMARINE)
                borderRadius = multi(box(474.px))
                rotate = 47.deg
                borderColor = multi(box(
                    top = Color.RED,
                    right = c("red"),
                    bottom = Color.RED,
                    left = Color.BLUE))
            }
        }
    }
}

==> Styling/src/main/kotlin/com/example/main.kt <==
package com.example

import tornadofx.launch

fun main() {
    launch<MyApp>()
}
==> Styling/src/main/kotlin/com/example/MyApp.kt <==
package com.example

import com.example.view.MainView
import tornadofx.App

class MyApp: App(MainView::class, Styles::class)
==> Styling/src/main/kotlin/com/example/Styles.kt <==
package com.example

import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.box
import tornadofx.cssclass
import tornadofx.px

class Styles : Stylesheet() {
    companion object {
        val heading by cssclass()
    }

    init {
        label and heading {
            padding = box(10.px)
            fontSize = 20.px
            fontWeight = FontWeight.BOLD
        }
    }
}
==> Styling/src/main/kotlin/com/example/view/MainView.kt <==
package com.example.view

import com.example.Styles
import tornadofx.*

class MainView : View("Hello TornadoFX") {
    override val root = hbox {
        label(title) {
            addClass(Styles.heading)
        }
    }
}

==> bookstore/src/Application.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.sessions.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import io.ktor.locations.*
import kotlinx.coroutines.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Sessions) {
        cookie<MySession>("MY_SESSION") {
            cookie.extensions["SameSite"] = "lax"
        }
    }

    install(CallLogging) {
        level = Level.INFO
        filter { call -> call.request.path().startsWith("/") }
    }

    install(PartialContent) {
        // Maximum number of ranges that will be accepted from a HTTP request.
        // If the HTTP request specifies more ranges, they will all be merged into a single range.
        maxRangeCount = 10
    }

    install(StatusPages){
        exception<Throwable> { cause ->
            call.respond(HttpStatusCode.InternalServerError)
            throw cause
        }
    }

    install(Locations){

    }

    val users = listOf<String>("shopper1", "shopper2", "shopper3")
    val admins = listOf<String>("admin")

    install(Authentication) {
        basic("bookStoreAuth") {
            realm = "Book store"
            validate {
                if ((users.contains(it.name) || admins.contains(it.name)) && it.password == "password")
                    UserIdPrincipal(it.name)
                else null
            }
        }
    }

    install(ContentNegotiation) {
        gson {
            setPrettyPrinting()
        }
    }

    val client = HttpClient(Apache) {
        install(JsonFeature) {
            serializer = GsonSerializer()
        }
    }
    runBlocking {
        // Sample for making a HTTP Client request
        /*
        val message = client.post<JsonSampleClass> {
            url("http://127.0.0.1:8080/path/to/endpoint")
            contentType(ContentType.Application.Json)
            body = JsonSampleClass(hello = "world")
        }
        */
    }

    routing {
        books()

        get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }

        get("/html-dsl") {
            call.respondHtml {
                body {
                    h1 { +"HTML" }
                    ul {
                        for (n in 1..10) {
                            li { +"$n" }
                        }
                    }
                }
            }
        }

        get("/styles.css") {
            call.respondCss {
                body {
                    backgroundColor = Color.red
                }
                p {
                    fontSize = 2.em
                }
                rule("p.myclass") {
                    color = Color.blue
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg`
        static("/static") {
            resources("static")
        }

        get("/session/increment") {
            val session = call.sessions.get<MySession>() ?: MySession()
            call.sessions.set(session.copy(count = session.count + 1))
            call.respondText("Counter is ${session.count}. Refresh to increment.")
        }

        authenticate("bookStoreAuth") {
            get("/api") {
                val principal = call.principal<UserIdPrincipal>()!!
                call.respondText("Hello ${principal.name}")
            }
        }

        get("/json/gson") {
            call.respond(mapOf("hello" to "world"))
        }
    }
}

data class MySession(val count: Int = 0)

class AuthenticationException : RuntimeException()
class AuthorizationException : RuntimeException()

data class JsonSampleClass(val hello: String)

fun FlowOrMetaDataContent.styleCss(builder: CSSBuilder.() -> Unit) {
    style(type = ContentType.Text.CSS.toString()) {
        +CSSBuilder().apply(builder).toString()
    }
}

fun CommonAttributeGroupFacade.style(builder: CSSBuilder.() -> Unit) {
    this.style = CSSBuilder().apply(builder).toString().trim()
}

suspend inline fun ApplicationCall.respondCss(builder: CSSBuilder.() -> Unit) {
    this.respondText(CSSBuilder().apply(builder).toString(), ContentType.Text.CSS)
}

==> bookstore/src/BookRoutes.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.locations.*
import io.ktor.request.*
import io.ktor.response.*
import io.ktor.routing.*
import io.ktor.routing.get
import io.ktor.auth.authenticate

@Location("/api/book/list")
data class BookListLocation(val sortby: String, val asc: Boolean)

fun Route.books(){
    val dataManager = DataManagerMongoDB()
    authenticate("bookStoreAuth") {
            get<BookListLocation>() {
                call.respond(dataManager.sortedBooks(it.sortby, it.asc))
            }

            get("/api/book/all") {
                call.respond(dataManager.allBooks())
            }

            post("/api/book/{id}") {
                val id = call.parameters.get("id")
                val book = call.receive(Book::class)
                val updatedbook = dataManager.updateBook(book)
                call.respondText("The book has been updated $updatedbook")
            }

            put("/api/book") {
                val book = call.receive(Book::class)
                val newbook = dataManager.newBook(book)
                call.respond(newbook)
            }

            delete("/api/book/{id}") {
                val id = call.parameters.get("id").toString()
                val deletedbook = dataManager.deleteBook(id)
                call.respond(deletedbook)
            }
    }
}
==> bookstore/src/DataManager.kt <==
//package com.learning
//
//import org.slf4j.LoggerFactory
//import kotlin.reflect.full.declaredMemberProperties
//
//class DataManager {
//    val log = LoggerFactory.getLogger(DataManager::class.java)
//    var books = ArrayList<Book>()
//    fun gimmeId(): String = books.size.toString()
//
//    init{
//        books.add(Book(gimmeId(), "How to grow apples", "Mr Appleton", 100.0f))
//        books.add(Book(gimmeId(), "How to grow oranges", "Mr Orangeton", 90.0f))
//        books.add(Book(gimmeId(), "How to grow lemons", "Mr Lemonton", 110.0f))
//        books.add(Book(gimmeId(), "How to grow pineapples", "Mr Pineappleton", 100.0f))
//        books.add(Book(gimmeId(), "How to grow pears", "Mr Pearton", 110.0f))
//        books.add(Book(gimmeId(), "How to grow coconuts", "Mr Coconuton", 130.0f))
//        books.add(Book(gimmeId(), "How to grow bananass", "Mr Appleton", 120.0f))
//    }
//
//    fun newBook(book: Book){
//        books.add(book)
//    }
//
//    fun updateBook(book: Book): Book?{
//        val foundbook = books.find {
//            it.id == book.id
//        }
//        foundbook?.title = book.title
//        foundbook?.author = book.author
//        foundbook?.price = book.price
//        return foundbook
//    }
//
//    /*fun deleteBook(book: Book): Book?{
//        val bookfound = books.find {
//            it.id == book.id
//        }
//        books.remove(bookfound)
//        return bookfound
//    }*/
//
//    fun deleteBook(bookid: String): Book{
//        val bookfound = books.find {
//            println("${it.id} $bookid")
//            it.id == bookid
//        }
//        books.remove(bookfound)
//        return bookfound!!
//    }
//
//    fun allBooks(): ArrayList<Book>{
//        return books
//    }
//
//    fun sortedBooks(sortby: String, asc: Boolean): List<Book> {
//        val member = Book::class.declaredMemberProperties.find { it.name.equals(sortby) }
//        if (member == null){
//            log.info("The field to sort by does not exist")
//            return allBooks()
//        }
//
//        if (asc)
//            return allBooks().sortedBy { member?.get(it).toString() }
//        else
//            return allBooks().sortedByDescending { member?.get(it).toString() }
//    }
//}
==> bookstore/src/DataManagerMongoDB.kt <==
package com.learning

import com.mongodb.MongoClientSettings
import com.mongodb.client.MongoClients
import com.mongodb.client.MongoCollection
import com.mongodb.client.MongoDatabase
import com.mongodb.client.model.Filters.eq
import org.bson.Document
import org.bson.codecs.configuration.CodecRegistries.fromProviders
import org.bson.codecs.configuration.CodecRegistries.fromRegistries
import org.bson.codecs.configuration.CodecRegistry
import org.bson.codecs.pojo.PojoCodecProvider
import org.bson.types.ObjectId
import org.slf4j.LoggerFactory

class DataManagerMongoDB {
    val log = LoggerFactory.getLogger(DataManagerMongoDB::class.java)
    val database: MongoDatabase
    val bookCollection: MongoCollection<Book>

    init{
        val pojoCodecRegistry: CodecRegistry = fromProviders(PojoCodecProvider.builder().automatic(true).build())
        val codecRegistry: CodecRegistry = fromRegistries(
            MongoClientSettings.getDefaultCodecRegistry(), pojoCodecRegistry
        )

        val clientSettings = MongoClientSettings.builder()
            .codecRegistry(codecRegistry)
            .build()

        val mongoClient = MongoClients.create(clientSettings)
        database = mongoClient.getDatabase("development")
        bookCollection = database.getCollection(Book::class.java.simpleName, Book::class.java)
        initBooks()
    }

    fun initBooks(){
        deleteAllBooks()
        bookCollection.insertOne(Book(null, "How to grow apples", "Mr Appleton", 100.0f))
        bookCollection.insertOne(Book(null, "How to grow oranges", "Mr Orangeton", 90.0f))
        bookCollection.insertOne(Book(null, "How to grow lemons", "Mr Lemonton", 110.0f))
        bookCollection.insertOne(Book(null, "How to grow pineapples", "Mr Pineappleton", 100.0f))
        bookCollection.insertOne(Book(null, "How to grow pears", "Mr Pearton", 110.0f))
        bookCollection.insertOne(Book(null, "How to grow coconuts", "Mr Coconuton", 130.0f))
        bookCollection.insertOne(Book(null, "How to grow bananass", "Mr Appleton", 120.0f))
    }

    fun deleteAllBooks(){
        bookCollection.deleteMany(Document())
    }

    fun newBook(book: Book) : Book{
        bookCollection.insertOne(book)
        return book
    }

    fun updateBook(book: Book): Book{
        val foundbook: Book? = bookCollection.find(Document("_id", book.id)).first()
        foundbook?.title = book.title
        foundbook?.author = book.author
        foundbook?.price = book.price
        return foundbook!!
    }

    fun deleteBook(bookid: String): Book {
        val bookfound = bookCollection.find(eq("_id", bookid)).first()
        bookCollection.deleteOne(eq("_id", ObjectId(bookid)))
        return bookfound!!
    }

    fun allBooks(): List<Book>{
        return bookCollection.find().toList()
    }

    fun sortedBooks(sortby: String, asc: Boolean): List<Book> {
        val pageno = 1
        val pageSize = 1000
        val ascint: Int = if(asc) 1 else -1
        return bookCollection
            .find()
            .sort(Document(mapOf(Pair(sortby, ascint), Pair("_id", -1))))
            .skip(pageno - 1)
            .limit(pageSize)
            .toList()
    }
}
==> bookstore/src/DataModel.kt <==
package com.learning

import org.bson.codecs.pojo.annotations.BsonId
import org.bson.types.ObjectId

class Book(id: ObjectId?, title: String, author: String, price: Float){
    @BsonId var id: ObjectId?
    var title: String
    var author: String
    var price: Float

    constructor() : this(null, "not_set", "not_set", 0.00f)

    init{
        this.id = id
        this.title = title
        this.author = author
        this.price = price
    }
}


data class ShoppingCart(var id: String, var userid: String, val items: ArrayList<ShoppingItem>)



data class ShoppingItem(var bookid: String, var qty: Int)


data class User(var id: String, var name: String, var username: String, var password:String)



==> bookstore/src/ui/Endpoints.kt <==
package ui

enum class Endpoints(val url: String) {
    LOGIN("/html/login"),
    LOGOUT("/html/logout"),
    DOLOGIN("/html/dologin"),
    HOME("/html/home"),
    BOOKS("/html/books"),
    CART("/html/cart");
}
==> bookstore/test/ApplicationTest.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import kotlinx.css.*
import io.ktor.content.*
import io.ktor.http.content.*
import io.ktor.sessions.*
import io.ktor.features.*
import org.slf4j.event.*
import io.ktor.auth.*
import io.ktor.gson.*
import io.ktor.client.*
import io.ktor.client.engine.apache.*
import io.ktor.client.features.json.*
import io.ktor.client.request.*
import kotlinx.coroutines.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}

==> comm_dummy/src/main/kotlin/Main.kt <==
import java.io.BufferedReader
import java.io.FileWriter
import java.io.FileReader
import java.io.IOException

fun main(args: Array<String>) {
    val items = listOf(1, 2, 3, 4, 5)

    items.fold( 0)

    println("Hello world!")

    return
}

public class DummyController(val filename: String){
    public companion object{
        public const val command_code_position : Int = 8
        public const val port_number_position : Int = 6
        public const val command_range_end : Int = 1
        public const val range_start : Int = 0
        public const val port_range_end : Int = 9
    }

    private fun WriteToDummyController(command: String, filename: String)
            : Boolean{
        var fo = FileWriter(
            filename
            , false
        )

        return when {
            (command.equals("<1,HI>")) -> {
                fo.write("1,HI,0")
                fo.close()
                true
            }
            (command.length > command_code_position) -> {
                try {
                    var num1 = command[port_number_position].digitToInt()
                    var num2 = command[command_code_position].digitToInt()
                    if (num1 in range_start .. port_range_end &&
                        num2 in range_start .. command_range_end){
                        var opcodes = arrayOf("DO", "OP")
                        for (subString in opcodes) {
                            if (command == "<1,${subString},${num1},${num2}>") {
                                fo.write("1,${subString},0,${command[port_number_position]}")
                                fo.close()
                            }
                        }
                    }
                }
                catch (e: IllegalArgumentException){
                    println(e.message.toString())
                }
                true
            }
            else -> {
                fo.write("Error Serial: $command")
                fo.close()
                false
            }
        }
    }



    private fun DummyControllerResponse(filename: String){
        val inFile = BufferedReader(
            FileReader(filename)
        )

        try {
            if (inFile.ready()) {
                println(inFile.readLine())
            }
        } catch (e: IOException) {
            println(e)
        }

        val items = listOf(1, 2)

        inFile.close()
    }
}

==> coroutinedemo/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

//fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
}


==> coroutinedemo/src/Coroutines.kt <==
package com.example

import kotlinx.coroutines.*
import java.io.File
import java.io.IOException
import java.util.concurrent.TimeUnit

fun main(args: Array<String>) = runBlocking {
    var port = 0
    val openPorts = mutableListOf<String>()

    suspend fun firstcoroutine(ipaddress: String, port: Int){
        val query="nc -vz $ipaddress $port"
        val reply = query.runCommand(File("/")).toString()
        if (reply.contains("succeeded")){
            openPorts.add(reply)
        }
    }
    withContext(Dispatchers.IO){
        repeat(200_000) {
            port += 1
            launch {
                firstcoroutine("51.219.137.5", port)
            }
        }
    }
    openPorts.forEach {
        println(it)
    }

}

@Suppress("SpreadOperator")
private fun String.runCommand(workingDir: File): List<String> {
    try {
        val parts = this.split("\\s".toRegex())
        val proc = ProcessBuilder(*parts.toTypedArray())
            .directory(workingDir)
            .redirectOutput(ProcessBuilder.Redirect.PIPE)
            .redirectError(ProcessBuilder.Redirect.PIPE)
            .start()

        proc.waitFor(60, TimeUnit.SECONDS)
        return proc.inputStream.bufferedReader().readText().split("\\n".toRegex())
    } catch (e: IOException) {
        println(e.toString())
        return listOf()
    }
}
==> endpoint-demo/src/Application.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondText { "HELLO WORLD!" }
        }

        var weather = "sunny"
        get("/weatherforecast") {
            call.respondText { weather }
        }
        post("weatherforecast"){
            weather = call.receiveText()
            call.respondText { "The weather has been set to: $weather" }
        }
    }
}


==> endpoint-demo/test/ApplicationTest.kt <==
package com.learning

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import kotlin.test.*
import io.ktor.server.testing.*

class ApplicationTest {
    @Test
    fun testRoot() {
        withTestApplication({ module(testing = true) }) {
            handleRequest(HttpMethod.Get, "/").apply {
                assertEquals(HttpStatusCode.OK, response.status())
                assertEquals("HELLO WORLD!", response.content)
            }
        }
    }
}
