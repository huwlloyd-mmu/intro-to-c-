# Week 3

## References

References are closely related to pointers. Both references and pointers can be used to access or modify the contents
of another variable or object, and both can be used as an efficient way of passing a large object into a function without
copying the whole thing. SFML uses them extensively, so we will cover them today. References are declared by putting an
ampersand (&) after the type name.

### Reference example

```c++
   int a = 2;
   int& b = a; // references declared using '&' notation
   // b is now a reference to a

   // change b
   b = 4;
   cout << a << endl; // prints out '4'
```

We can see that a reference is just another way of referring to a variable. In the example
above, we can use 'b' or 'a' interchangeably to refer to the integer variable we originally
declared as 'a'. This comes into its own when we use it in function calls to 'call by reference':

## Call by reference
```c++
void SwapInts( int& a, int& b )
{
   int swapVal = b;
   b = a;
   a = swapVal;
}

int main()
{
   int i1 = 1; i2 = 5;
   SwapInts( i1, i2 );
   cout << i1 << " " << i2 << endl; // prints "5 2"
}
```
* References are __immutable__. This means we once a reference is assigned to point to something,
we can't change what it points at, only the value of the variable pointed to.
* References can only be set at the time they are declared. If a class contains
reference members, they need to be initialized in a constructor initializer list.
* We can also declare a __const__ reference. This is a 'read-only' reference. We can use a const reference to read
the value of a variable but can't change it using the reference. 

## Returning references

Sometimes functions return references rather than values. Be careful doing this -- if the reference
is to a local variable, this won't work. On leaving the function, the local variable is no longer
in scope and will be destroyed, leaving a reference to an invalid object.


## STL -- the Standard Template Library

C++ is nowadays considered a low-level language. The high-level features built into newer languages are mostly found
in C++ libraries. However, you can rely on ay feature that is part of the __standard libraries__ 
being there, so maybe this is splitting hairs and C++ is high-level after all. C++ __templates__ are a way of
defining generic classes and functions that work with different types. We will see them in action in two data structures
provided by the __standard template library__ (STL), __vectors__ and __maps__.

### STL Vectors

The STL __vector__ class provides a random access, ordered array. Unlike the primitive arrays we saw and used
last week, vectors can grow and shrink as items are added and removed. This is useful, because we don't always
know in advance how big an array needs to be. The class provides a range of methods for interrogating
and modifying the array, and a few different ways of traversing the list. Here's some examples:

```c++
#include <vector>
using namespace std;

int main()
{
   vector<string> wordList;

   wordList.push_back("foo");
   wordList.push_back("bar");

   cout << wordList.size() << endl; // prints "2"

   wordList.push_back("baz");

   cout << "the first word is " << wordList[0] << endl;
   cout << "the last word is " << wordList[wordList.size()-1] << endl;

   return 0;
}
```

* Note we include the __\<vector\>__ header.
* __vector__ is part of the __std::__ namespace.
* The angle brackets (__<>__) show that this is a __template__ class -- inside the angle brackets we put the name of the __type__ of
object we will be storing in the vector. This can be a primitive type or a class. In this case, it's a class (string).
* The __size()__ method gives us the __number of items__ in the list (not the size in bytes).
* Like primitive arrays, we can use the __[]__ operator to access elements.

Here's two ways of traversing a vector

```c++
// we can use a good old-fashioned for loop
for ( int i = 0; i < wordList.size(); i++ )
{
   cout << wordList[i];
}

// we can use the new 'range-based' for loop in C++ 11
for ( string s : wordList )
{
   cout << s;
}
```

We can also use __iterators__. Working with iterators would need a deeper dive into pointers first, so we won't go there for now. The range-based for
loop leads to the most readable code. Iterators are necessary if you want to remove items from the list as you are looping over it.

### STL Maps

Most high level languages have a __map__ data structure (sometimes called a __hash map__ or __dictionary__). It's an incredibly useful
and fundamental data structure and you can rely on the implementation in C++ being very efficient. A map is a set of __key-value pairs__.
An array is a special case of a map in which the keys are all sequential integers. In a map, they can be anything. Here's an example using strings for
the __key__ and an __integer__ for the value:

```c++
#include <map>
#include <iostream>
using namespace std;

int main()
{
   map<string, int> phoneBook;

   // setting and getting using the [] operator
   phoneBook["Bob"] = 1613334474;
   phoneBook["Alice"] = 1615557777;

   cout << "Bob's number is: " << phoneBook["Bob"] << endl;
   cout << "Alice's number is: " << phoneBook["Alice"] << endl;

   // looking for an element
   if ( phoneBook.find("Bill") != phoneBook.end() )
      cout << "Bill's number is: " << phoneBook["Bill"] << endl;
   else
      cout << "Bill's not in the book" << endl;

   return 0;
}
```

* In this example, we used the __[]__ operator to get and set elements.
* The __find()__ method can look up by key. This returns an iterator. If it can't find the key, it returns the 'past the end' value of the iterator.

## Inheritance

We will only briefly mention inheritance, and won't be using it in any of our practical work. This may seem
odd for a course on an object-oriented language, but I am being selective about which parts of the language
to look at. In the practical sessions, we have been focusing on game programming.
In the early days of OOP, games programmers built deep and elaborate inheritance hierarchies and usally got into a mess.
A good principle (first expressed in the 'Gang of Four' book _Design Patterns_) is __Favour Composition over Inheritance__, in other words, make
new objects by collecting together existing objects, rather than inheriting from them. Most modern games programming embraces this prinicple, building game objects
out of 'components'. If you use Unity or Unreal, you will see this in action. 

C++ inheritance is via the __public__ keyword.

```c++
class Person
{
    string name;
    int age;
public:
    Person( string name, int age ) : name(name), age(age) {}
	string GetName() {return name;}
	int GetAge() { return age;}
};

class Employee : public Person
{
    int employeeNumber;
public:
    Employee( string name, int age, int number ) :
        Person(name, age), employeeNumber(number) {}
	int GetEmployeeNumber() { return employeeNumber;}
};

int main()
{
    Employee emp = Employee("Bob", 26, 12345);

    cout << emp.GetName() << " " << emp.GetAge()
	     << " " << emp.GetEmployeeNumber() << endl;
    return 0;
}
```

* The __derived__ class inherits everything from the __parent__ class.
* __private__ fields in the parent class are hidden from the derived class. Note we access them here through inherited getters.
* You can call a parent class constructor in the initializer list -- this lets you set the private fields in the parent class.

