Abstract Classes and Interfaces: An abstract class serves as a base class and cannot be instantiated. It often contains at least one pure virtual function (= 0).

''' 
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    string species;

public:
    // Constructor
    Animal(string n, string s) : name(n), species(s) {}

    // Method to make a sound
    void makeSound() {
        cout << "Generic Animal Sound" << endl;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Getter for species
    string getSpecies() {
        return species;
    }
 };
 ''' 

 Abstraction: Hiding implementation details and showing only essential information to the user. Achieved using abstract classes or interfaces.

 Access Modifiers (Public, Private, Protected): Access modifiers define the visibility of class members.

 Attributes / Properties: Attributes are variables that hold data specific to an object.

 Class Variable: A class variable is shared across all instances of a class. In C++, this is achieved using the static keyword.

 Classes and Objects: A class is a blueprint for creating objects. It defines attributes (data members) and behaviors (methods) that objects of the class will have. An object is an instance of a class, representing a specific realization of the class blueprint with actual data.

 Collections and Iterators: Collections are containers like arrays, vectors, or lists. Iterators traverse these collections.

 Composition: Composition models a "has-a" relationship where one class contains objects of another class.

 Constructors and Destructors: Constructors initialize an object. Destructors clean up resources when the object is destroyed.

 Design Patterns (e.g., Singleton, Factory, Observer): Reusable solutions to common software design problems. Examples: Singleton, Factory, Observer.

 Encapsulation: Encapsulation binds data and methods together and restricts access to certain parts of the object.

 Exception Handling: Exception handling allows a program to handle runtime errors gracefully using try, catch, and throw.

 File I/O in OOP: File I/O (Input/Output) allows reading from and writing to files.

 Friends: A friend function or class can access private and protected members of another class.

 Generics and Templates: Templates allow the creation of generic classes and functions.

 Inheritance: Inheritance allows a class (child) to derive attributes and methods from another class (parent).

 Instance Variable: Inheritance allows a class (child) to derive attributes and methods from another class (parent).

 Member Variable: A member variable is a variable declared within a class, either as an instance variable or a static (class-level) variable.

 Memory Management (Garbage Collection, Pointers): Memory management involves dynamic allocation and deallocation of memory using pointers.

 Method Overloading: Method overloading allows multiple functions in the same class with the same name but different parameters.

 Method: A method is a function defined inside a class to manipulate the class's data.

 Multiple Inheritance: Multiple inheritance allows a class to inherit from more than one parent class.

 Multithreading in OOP (time permitting): Multithreading allows a program to execute multiple threads (lightweight processes) simultaneously.

 Object Relationships (Association, Aggregation, Composition): 
 
 Association: A "uses-a" relationship where one object interacts with another. The objects are independent and have no ownership of each other.

 Aggregation: A "has-a" relationship where one object owns another, but the owned object can exist independently. This is a weak ownership relationship.

 Composition: A "has-a" relationship where one object owns and manages the lifetime of another. The contained object cannot exist independently of the container.

 Object-Oriented Design Principles: Best practices for designing software systems.

 Operator Overloading: Operator overloading allows customizing the behavior of operators for user-defined types.

 Overloading: Overloading allows multiple methods or operators in the same scope to have the same name but different signatures (parameter types, number of parameters).

 Polymorphism: Polymorphism allows objects to be treated as instances of their parent class rather than their actual class. It is achieved using virtual functions in C++.

 Public / Private / Protected: Access modifiers in C++ control the visibility and accessibility of class members.

 Public: Members are accessible from anywhere.

 Private: Members are only accessible within the class itself.

 Protected: Members are accessible within the class and its derived classes.

 SOLID Principles: SOLID is a set of five principles for designing scalable and maintainable software
 
 Single Responsibility Principle: A class should have one, and only one, reason to change.
 
 Open/Closed Principle: A class should be open for extension but closed for modification.
 
 Liskov Substitution Principle: Subtypes must be substitutable for their base types.
 
 Interface Segregation Principle: A class should not be forced to implement interfaces it doesn't use.
 
 Dependency Inversion Principle: High-level modules should not depend on low-level modules. Both should depend on abstractions.

 Static (Methods and Variables): Static members belong to the class rather than any instance.

 Testing in OOP (Unit Testing, Test-Driven Development): Testing ensures code works as expected. Unit testing tests individual components, and Test-Driven Development (TDD) writes tests before implementing functionality.

 UML Diagrams and Modeling: Unified Modeling Language (UML) diagrams visually represent system design. Examples include class diagrams, sequence diagrams, and use-case diagrams.

 Virtual: Virtual functions in C++ allow dynamic (runtime) method overriding.