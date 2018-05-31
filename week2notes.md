# Week 2 -- Object Oriented Programming in C++

C++ is an object-oriented language, and like Java and C# uses __classes__ to describe __objects__. A class is a template for creating an object. An object is an entity which encapsulates data and behaviour. The data is held in variables (often called _fields_) and the behaviour is encapsulated in functions (called _methods_). Creating an object from a class is called _instantiation_, and all objects are _instances_ of a class.

## C++ Classes

It is usual practice in C++ to split the description of a class between two files, a __header__ (.h) file and an __implementation__ (.cpp) file. The header file contains the class definition, with __prototypes__ for the methods, but the methods themselves are defined in the implementation file. Here's an example of a simple class.

### Header File (person.h)

```c++
#include <string>
using namespace std;

class Person
{
    string name;
    int age;
public:
    Person( string name, int age );
    string GetName();
    int GetAge();
};
```

### Implementation File (person.cpp)

```c++
#include "person.h"

Person::Person( string newName, int newAge )
{
    name = newName;
    age = newAge;
}

string Person::GetName()
{
    return name;
}

int Person::GetAge()
{
    return age;
}
```

There's a lot going on here. Here's some notes on the example.

* The __class__ keyword is followed by the name of the class, then the definition of the class in curly brackets (with a semi-colon at the end).
* The variables __name__ and __age__ are __private__ variables (can only be accessed by objects of class Person) -- this is because we didn't say 
otherwise, and private is the default.
* The methods are all public, because they come after a __public:__ declaration.
* The first method (Person(string name, int age)) is a __constructor__. This has no return type (not even void). Constructors are called when objects are constructed (instantiated).
* We can add as many constructors as we like, with different argument lists.
* In the cpp file, the methods are defined as being class members using __Person::__ before the name. :: is called the _scope resolution operator_.

Here's an example application using the class:

### Application

```c++
#include "person.h"
#include <iostream>
using namespace std;

int main()
{
    Person bob = Person( "Bob", 20 );

    cout << "Person: name " << bob.GetName() << " age: " 
                            << bob.GetAge() << endl;
    return 0;
}
```

* Calling a counstructor creates an instance of a class.
* We can access the methods (or fields) in a class instance using the dot (.) operator.

## Pointers, new and delete.

In the example above, the created an instance of __Person__ by calling the constructor, and saving this new instance in a variable of type 'Person'. This is fine, but under the hood there is a lot going on here -- the assignment isn't as simple as it looks and involves termporary objects being created and destroyed, and extra code (copy constructors) being called. There is a more efficient way to construct objects using the __new__ operator.

The new operator calls a constructor, and returns a __pointer__ to the new object. A pointer is basically an address in memory. Pointers can be a tricky concept, especially when they are used to construct arrays, or manipulate memory directly, but when used to refer to class objects they are reasonably straightforward. Here's the example above, rewritten to use pointers.

```c++
#include "person.h"
#include <iostream>
using namespace std;

int main()
{
    Person* bob = new Person( "Bob", 20 );

    cout << "Person: name " << bob->GetName() << " age: " 
                            << bob->GetAge() << endl;

    delete bob;
    return 0;
}
```

* Pointers are declared using the * notation. So, __Person*__ means 'pointer to a Person object'.
* __new__ is used to call a constructor and return a pointer.
* We now access the methods and fields using the arrow operator (->) instead of the dot operator.
* We clean up at the end by using the __delete__ operator on the pointer.

A pointer is an efficient way of referencing an object. Passing a pointer to an object into a function is much better
than passing in the entire object (a pointer is four or eight bytes, whereas an object can be much bigger depending on 
the class). There is another, closely related, language feature -- __references__ -- which we won't be covering today.

## Destructors

As well as constructors, classes can have __destructors__ -- these are methods that are called when an object is destroyed (using __delete__, or if a variable of a class type goes out of scope). A destructor is declared using the name of the class with a tilde (~) before it:

```c++
// destructor example - header file
class MyClass
{
    // constructor
    MyClass();
    // destructor
    ~MyClass();
}

// implementation file

MyClass::~MyClass()
{
    cout << "bye!!" << endl;
}
```

You don't have to provide a destructor -- a default one is created for you, but if you have any cleanup you need to do (such as freeing up memory, closing files etc,) you will need one. 

## Initializer lists

Another piece of syntax we will use is class initializer lists. This is a way of initializing the class fields in a constructor. There are some advantages to using them over just assigning the variables in the constructor and in any case it's idiomatic nowadays to use this syntax, so we will use it when we can. Here's an example, using the person class:

```c++
class Person
{
    string name;
    int age;
public

    // default constructor
    Person()
    {
    }
    
    // data constructor
    Person( string newName, int newAge ) : name(newName), age(newAge) 
    {
    }	
// etc etc....
};
```

* The initializer list is written after a colon (:) between the constructor signature and the constructor body (curly brackets).
* The syntax is variable1( initialValue1), variable2(initialValue2) ...
* Notice in this case the constructor body is empty -- all the initialization happens in the list.
## Arrays

We will also use arrays in the code exercises today. We will use fixed length, one-dimensional arrays. These are declared
and used as follows:

```c++
    int numbers[10]; // declare an array of 10 ints

    for ( int i = 0; i < 10; i++ )
    {
        numbers[i] = i;
    }

    const int n = 10;
    int anotherArray[n]; // declare an array of n ints
                         // n must be const for this to work

```
* This introduces a new concept -- __const__. Anything declared __const__ can't be changed after it has been initialized, and needs to be initialized at the same time as it is declared.
* Notice that arrays are __zero-based__. This means the array of 10 ints has elements 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
