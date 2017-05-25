# Week 1 Notes -- C++ Basics

## 1. Hello World

#### Example 1
```c++
// comments start with a double slash, preprocessor commands start with a #
#include <iostream> 

int main() // main is the entry point to a C++ program
{
    /* multi-line comment ...
	   print to console */   
    std::cout << "hello, world" << std::endl;  
    return 0;
}
```
* The braces (curly brackets) define a __code block__: in this case the __main__ function.
* __main__ returns an __int__ (which is passed to the OS) -- 0 means 'success'.
* The __preprocessor__ runs before the compiler and executes commands starting with a __#__. In the case above, the preprocessor includes a _header_ file.
* The __iostream__ header includes the definition of __std::cout__. Output to the console by sending strings or values to __std::cout__ using the __<<__ operator.
* __std::endl__ is a newline. You could use "\n" instead.
* Logical lines end in a semi-colon: you can extend a line of code over multiple source lines.

## 2. Types, Variables, Scope and Namespaces
__Declare__ a variable by giving a __type__ followed by a name (starting with a letter or an underscore).

Some C++ primitive types

| Type        | Meaning                        |
|-------------|--------------------------------|
| __char__    | character, 8 bit integer       |
| __int__     | 32 bit signed integer          |
| __unsigned int__ | 32 bit unsigned integer (+ve only) |
| __long long int__ | 64 bit signed integer  |
| __float__   | 32-bit floating point number   |
| __double__  | 64-bit floating point number   |
| __bool__    | boolean - __true__ or __false__|


#### Example 2
```c++
#include <iostream>

int main()
{
    // a floating point variable
    float x;
	
    std::cout << "input a number: ";
    // use >> on std::cin to get input from console
    std::cin >> x; 
    std::cout << "the number squared is " << x*x << std::endl;

    return 0;
}
```

* The __scope__ of a variable is anywhere from the declaration up to the end of the __code block__ (pair of curly brackets) in which it is defined.
* If a variable is declared outside __main__, it is a __global__ variable.
* In C++, a variable can be used before it has been initialized - be careful!

C++ provides a mechanism to help avoid clashes of names between different libraries: the __namespace__. __std::__ is a _namespace_. We could
dispense with the __std::__ on each use of the names by adding __using namespace std__ at the top of the file:

#### Example 3

```c++
// namespace example
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    cout << "enter your name ";
    cin >> name;
    cout << "hello, " << name << endl;

    return 0;
}
```

* Note we used the __string__ type here: this is not a built-in primitive type and required use to include the string header file. More on strings later.

#### Example 4 - Typecasts
We can convert between types using typecasts - the cast operator is the name of the desination type in parentheses

```c++
   float x = 1.2f;       // note the 'f' in a floating point constant
   int ix = (int)x;     // cast to an integer - loses the fractional part

   cout << ix << endl; 	// outputs '1'
```

C++ will perform _implicit conversion_ without a cast where possible, even where information is lost, so be careful. Most compilers give warnings when this happens.

## 3. Conditionals

Conditional statements can be constructed from __if__, __else if__ and __else__,
and the __logical operators__.
In C++ anything that is not __0__ or __false__ is true (it doesn't have to be of
the __bool__ type to be evaluated as true or false in a conditional statement.

#### Logical Operators

| Operator   |  Meaning     |
|------------|--------------|
| __==__     | Equals       |
| __!=__     | Not equals   |
| __>__      | Greater than |
| __<__      | Less than    |
| __>=__     | Greater than or equals |
| __<=__     | Less than or equals |
| __!__      | logical NOT  |
 __\|\|__     | logical OR   |
| __&&__     | logical AND  |

Some examples:

#### Example 5

```c++
#include <iostream>
using namespace std;

int main()
{
    int i;

    cout << "choose a number";
    cin >> i;
	
    if ( i < 0 )
    {
       cout << "you input a negative number" << endl;
    }
    else if ( i < 10000 )
    {
        cout << "good choice" << endl;	
    }
    else
        cout << "crazy big number!" << endl;

    if ( 1 )
        cout << "1 is true!" << endl;

    return 0;
}
```

* a conditional can be followed by a __code block__ or a single line. It's safer to put
the curly brackets in, even if you only have one line after the __if__ statement.


## 4. Loops

C++ provides three loop structures __while__, __for__, and __do ... while__.

```c++
#include <iostream>
using namespace std;

int main()
{
    // print the numbers from 0 to 9
    for ( int i = 0; i < 10; i++ )
    {
        cout << i << endl;
    }
    // do the same with a while loop
    int i = 0;
    while ( i < 10 )
    {
        cout << i << endl;
        i = i + 1;
    }

    return 0;
}
```

* Note the __++__ (increment) operator - this just adds one to an integer variable
* The for loop specifier has three parts - the loop initializer, the loop condition, and the loop updater -- the loop runs while the condition is true.

## 5. Functions

Functions enable us to modularize code by packaging up a common or repeated calculation into a procedure that can be called with different parameters.
Formally a _procedure_ does something, but does not return a result; a _function_ returns a value. C++ programmers tend to call them both 'functions' anyway.
A function is defined by
* The return type (if it returns nothing, this is __void__).
* The name
* The _argument list_: this is a list of the parameters passed to the function.

### Function Example

```c++
// function
float Square( float x )
{
    // returns the square of a floating point number
    return x*x;
}

// procedure
void SayHello(std::string name )
{
    std::cout << "hello, " << name << std::endl;
}
```
In C++ (unlike, say, Java or C#) a function has to be declared before it can be used so the compiler will give an error if function definition is after the call in the source file. This could be a problem - often functions need to call _each other_ (e.g. function A calls function B, which calls function A). C++ gets around this using _function prototypes_: these _declare_ a function (give its name, return type and arguments) but the _definition_ of the function (the code itself) can be elsewhere. An example:

```c++
// function prototype (declaration)
void func1( void );

void func2( void )
{
    // call func1
    func1();
}

// definition 
void func1( void )
{
    std::cout << "foo" << std::endl;
}
```

The function prototypes are often gathered together into a __header file__, with the function definitions in a separate __.cpp__ file. This is one way in which C++ manages __libraries__ of code.

### Overloading

In C++ functions can be 'overloaded', that is we can have two (or more) functions with the same name, but different argument lists. Overloaded functions can return different types, with the restriction that the return type can't be the only difference between the functions.

