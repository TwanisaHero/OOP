# Object-Oriented Programming Concepts

## Abstract Classes and Interfaces
An abstract class serves as a base class and cannot be instantiated. It often contains at least one pure virtual function (= 0).

```cpp
class AbstractShape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public AbstractShape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};
```

## Abstraction
Hiding implementation details and showing only essential information to the user. Achieved using abstract classes or interfaces.

```cpp
class Car {
private:
    void startEngine() { std::cout << "Engine started." << std::endl; }
public:
    void drive() {
        startEngine(); // Implementation hidden from the user
        std::cout << "Car is driving." << std::endl;
    }
};
```

## Access Modifiers (Public, Private, Protected)
Access modifiers define the visibility of class members.

```cpp
class Example {
private:
    int privateVar; // Only accessible within the class

protected:
    int protectedVar; // Accessible in derived classes

public:
    int publicVar; // Accessible from anywhere
};
```

## Attributes / Properties
Attributes are variables that hold data specific to an object.

```cpp
class Person {
public:
    std::string name; // Attribute to store name
    int age; // Attribute to store age
};
```

## Class Variable
A class variable is shared across all instances of a class. In C++, this is achieved using the static keyword.

```cpp
class Counter {
public:
    static int count; // Shared across all instances

    Counter() { count++; }
};

int Counter::count = 0; // Initialize static variable
```

## Classes and Objects
A class is a blueprint for creating objects. It defines attributes (data members) and behaviors (methods) that objects of the class will have. An object is an instance of a class, representing a specific realization of the class blueprint with actual data.

```cpp
class Dog {
public:
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Dog myDog; // Create an object
    myDog.bark(); // Call a method
}
```

## Collections and Iterators
Collections are containers like arrays, vectors, or lists. Iterators traverse these collections.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4};

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
}
```

## Composition
Composition models a "has-a" relationship where one class contains objects of another class.

```cpp
class Engine {
public:
    void start() { std::cout << "Engine started." << std::endl; }
};

class Car {
private:
    Engine engine; // Composition

public:
    void drive() {
        engine.start();
        std::cout << "Car is driving." << std::endl;
    }
};
```

## Constructors and Destructors
Constructors initialize an object. Destructors clean up resources when the object is destroyed.

```cpp 
class Example {
public:
    Example() { std::cout << "Constructor called." << std::endl; }
    ~Example() { std::cout << "Destructor called." << std::endl; }
};
```

## Design Patterns (e.g., Singleton, Factory, Observer)
Reusable solutions to common software design problems. Examples: Singleton, Factory, Observer.

### Singleton
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
```
### Factory 
```cpp
#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Square." << std::endl;
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "Circle")
            return std::make_unique<Circle>();
        else if (type == "Square")
            return std::make_unique<Square>();
        else
            return nullptr;
    }
};

int main() {
    auto circle = ShapeFactory::createShape("Circle");
    auto square = ShapeFactory::createShape("Square");

    if (circle) circle->draw();
    if (square) square->draw();

    return 0;
}
```

### Observer 
```cpp
#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {}
};

class ConcreteObserver : public Observer {
    std::string name;
public:
    explicit ConcreteObserver(const std::string& name) : name(name) {}
    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

class Subject {
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
};

int main() {
    Subject subject;

    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers("Event occurred!");

    return 0;
}
```

## Encapsulation
Encapsulation binds data and methods together and restricts access to certain parts of the object.

```cpp
class Account {
private:
    double balance;

public:
    void deposit(double amount) { balance += amount; }
    double getBalance() const { return balance; }
};
```

## Exception Handling
Exception handling allows a program to handle runtime errors gracefully using try, catch, and throw.

```cpp
try {
    throw std::runtime_error("An error occurred.");
} catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

## File I/O in OOP
File I/O (Input/Output) allows reading from and writing to files.

```cpp
#include <fstream>
class FileHandler {
public:
    void writeToFile(const std::string& filename, const std::string& data) {
        std::ofstream file(filename);
        file << data;
        file.close();
    }
};
```

## Friends
A friend function or class can access private and protected members of another class.

```cpp
class FriendClass;

class Example {
private:
    int secret = 42;
    friend class FriendClass;
};

class FriendClass {
public:
    void revealSecret(const Example& obj) {
        std::cout << "Secret is: " << obj.secret << std::endl;
    }
};
```

## Generics and Templates
Templates allow the creation of generic classes and functions.

```cpp
template <typename T>
class Box {
private:
    T item;
public:
    void setItem(T value) { item = value; }
    T getItem() const { return item; }
};
```

## Inheritance
Inheritance allows a class (child) to derive attributes and methods from another class (parent).

```cpp
class Parent {
public:
    void greet() { std::cout << "Hello from Parent!" << std::endl; }
};

class Child : public Parent {
};
```

## Instance Variable
An instance variable is a variable declared inside a class, specific to an instance of the class.

```cpp
class Person {
public:
    std::string name; // Instance variable specific to each object
};
```

## Member Variable
A member variable is a variable declared within a class, either as an instance variable or a static (class-level) variable. 

```cpp
class Car {
public:
    std::string brand; // Instance member variable
    static int totalCars; // Static (class-level) member variable

    Car(const std::string& carBrand) : brand(carBrand) {
        totalCars++;
    }
};

int Car::totalCars = 0; // Initialize static variable
```
## Memory Management (Garbage Collection, Pointers)
Memory management involves dynamic allocation and deallocation of memory using pointers. 

```cpp
int* ptr = new int(5); // Allocate memory
std::cout << *ptr << std::endl;
delete ptr; // Free memory
```
## Method Overloading
Method overloading allows multiple functions in the same class with the same name but different parameters.

```cpp
class Printer {
public:
    void print(int value) { std::cout << value << std::endl; }
    void print(const std::string& value) { std::cout << value << std::endl; }
};
```
## Method
A method is a function defined inside a class to manipulate the class's data.

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b; // Method that performs addition
    }
};

int main() {
    Calculator calc;
    std::cout << "Sum: " << calc.add(3, 7) << std::endl; // Call method
}
```
## Multiple Inheritance
Multiple inheritance allows a class to inherit from more than one parent class. 

```cpp
class A {
public:
    void sayHello() { std::cout << "Hello from A!" << std::endl; }
};

class B {
public:
    void sayHi() { std::cout << "Hi from B!" << std::endl; }
};

class C : public A, public B {};
```

## Multithreading in OOP (time permitting)
Multithreading allows a program to execute multiple threads (lightweight processes) simultaneously.

```cpp
#include <iostream>
#include <thread>

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    std::thread t1(printMessage, "Hello from thread 1");
    std::thread t2(printMessage, "Hello from thread 2");

    t1.join();
    t2.join();

    return 0;
}
```

## Object Relationships (Association, Aggregation, Composition)

### Association
A "uses-a" relationship where one object interacts with another. The objects are independent and have no ownership of each other.

```cpp
class Driver {
public:
    void driveCar() { std::cout << "Driver is driving the car." << std::endl; }
};

class Car {
public:
    void beDrivenBy(Driver& driver) {
        driver.driveCar();
        std::cout << "Car is being driven." << std::endl;
    }
};

int main() {
    Driver driver;
    Car car;
    car.beDrivenBy(driver); // Association
}
```

### Aggregation
A "has-a" relationship where one object owns another, but the owned object can exist independently. This is a weak ownership relationship.

```cpp
class Engine {
public:
    void start() { std::cout << "Engine started." << std::endl; }
};

class Car {
private:
    Engine* engine; // Pointer to engine (can exist independently)
public:
    Car(Engine* eng) : engine(eng) {}
    void drive() {
        engine->start();
        std::cout << "Car is driving." << std::endl;
    }
};
```

### Composition
A "has-a" relationship where one object owns and manages the lifetime of another. The contained object cannot exist independently of the container.

```cpp
#include <iostream>

class Engine {
public:
    void start() { std::cout << "Engine started." << std::endl; }
};

class Car {
private:
    Engine engine; // Composition: Car "has-a" Engine

public:
    void drive() {
        engine.start();
        std::cout << "Car is driving." << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.drive();

    return 0;
}
```

## Object-Oriented Design Principles
Best practices for designing software systems.

```cpp
#include <iostream>
#include <string>

// Class responsible for handling user input
class InputHandler {
public:
    std::string getUserInput() {
        std::string input;
        std::cout << "Enter your name: ";
        std::cin >> input;
        return input;
    }
};

// Class responsible for displaying output
class OutputHandler {
public:
    void displayMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

int main() {
    InputHandler inputHandler;
    OutputHandler outputHandler;

    std::string name = inputHandler.getUserInput();
    outputHandler.displayMessage("Hello, " + name + "!");

    return 0;
}
```


```cpp
#include <iostream>
#include <string>

// Class responsible for handling user input
class InputHandler {
public:
    std::string getUserInput() {
        std::string input;
        std::cout << "Enter your name: ";
        std::cin >> input;
        return input;
    }
};

// Class responsible for displaying output
class OutputHandler {
public:
    void displayMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

int main() {
    InputHandler inputHandler;
    OutputHandler outputHandler;

    std::string name = inputHandler.getUserInput();
    outputHandler.displayMessage("Hello, " + name + "!");

    return 0;
}
```

## Operator Overloading
Operator overloading allows customizing the behavior of operators for user-defined types.

```cpp 
#include <iostream>

class Vector {
private:
    int x, y;

public:
    Vector(int x, int y) : x(x), y(y) {}

    // Overload + operator
    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector v1(3, 4);
    Vector v2(1, 2);

    Vector v3 = v1 + v2; // Using overloaded + operator
    v3.display();

    return 0;
}
```

```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }`  
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2; // Using overloaded operator
    c3.display();
}
```

## Overloading
Overloading allows multiple methods or operators in the same scope to have the same name but different signatures (parameter types, number of parameters).

```cpp
#include <iostream>

class Calculator {
public:
    int add(int a, int b) { return a + b; }            // Method overloading
    double add(double a, double b) { return a + b; }  
};

int main() {
    Calculator calc;
    std::cout << calc.add(5, 10) << std::endl;        // Calls int version
    std::cout << calc.add(2.5, 3.5) << std::endl;     // Calls double version
    return 0;
}
```

## Polymorphism
Polymorphism allows objects to be treated as instances of their parent class rather than their actual class. It is achieved using virtual functions in C++.

```cpp
#include <iostream>

class Animal {
public:
    virtual void sound() { std::cout << "Animal sound." << std::endl; }
};

class Dog : public Animal {
public:
    void sound() override { std::cout << "Dog barks." << std::endl; }
};

int main() {
    Animal* pet = new Dog();
    pet->sound(); // Calls Dog's sound
    delete pet;
    return 0;
}
```
## Public / Private / Protected
Access modifiers in C++ control the visibility and accessibility of class members.

```cpp
#include <iostream>

class Example {
private:
    int privateVar = 10; // Accessible only within the class

protected:
    int protectedVar = 20; // Accessible within the class and derived classes

public:
    int publicVar = 30; // Accessible from anywhere

    void display() {
        std::cout << "Private: " << privateVar
                  << ", Protected: " << protectedVar
                  << ", Public: " << publicVar << std::endl;
    }
};

class Derived : public Example {
public:
    void show() {
        // std::cout << privateVar; // Error: privateVar is not accessible
        std::cout << "Protected: " << protectedVar << std::endl; // Accessible
    }
};

int main() {
    Example ex;
    ex.display();
    std::cout << "Public: " << ex.publicVar << std::endl; // Accessible

    return 0;
}
```

### Public
Members are accessible from anywhere.

### Private
Members are only accessible within the class itself.

### Protected
Members are accessible within the class and its derived classes.

## SOLID Principles
SOLID is a set of five principles for designing scalable and maintainable software.

### Single Responsibility Principle
A class should have one, and only one, reason to change.

```cpp
#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    Logger logger;
    int result = calc.add(5, 10);
    logger.log("Calculation result: " + std::to_string(result));
    return 0;
}
```

### Open/Closed Principle
A class should be open for extension but closed for modification.

```cpp 
#include <iostream>

class Shape {
public:
    virtual double area() const = 0; // Open for extension
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

int main() {
    Shape* shapes[] = { new Circle(5), new Rectangle(4, 6) };
    for (Shape* shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }
    return 0;
}
```

### Liskov Substitution Principle
Subtypes must be substitutable for their base types.

```cpp
# Base class
class Bird:
    def fly(self):
        return "I can fly!"

# Derived class that adheres to LSP
class Sparrow(Bird):
    pass

# Derived class that violates LSP
class Ostrich(Bird):
    def fly(self):  # Ostriches can't fly
        raise NotImplementedError("Ostriches can't fly!")

# Using the principle
def let_bird_fly(bird: Bird):
    print(bird.fly())

sparrow = Sparrow()
let_bird_fly(sparrow)  # Output: "I can fly!"

ostrich = Ostrich()
# let_bird_fly(ostrich)  # This will break the LSP by raising an exception
```

### Interface Segregation Principle
A class should not be forced to implement interfaces it doesn't use.

```cpp
# Violation of ISP
class Worker:
    def work(self):
        pass

    def eat(self):
        pass

class Robot(Worker):
    def work(self):
        return "I am working!"

    def eat(self):  # Robots don’t eat
        raise NotImplementedError("Robots don't eat!")

# Refactoring to adhere to ISP
class Workable:
    def work(self):
        pass

class Eatable:
    def eat(self):
        pass

class Human(Workable, Eatable):
    def work(self):
        return "I am working!"

    def eat(self):
        return "I am eating!"

class Robot(Workable):
    def work(self):
        return "I am working!"
```

### Dependency Inversion Principle
High-level modules should not depend on low-level modules. Both should depend on abstractions.

```cpp
# Without DIP: High-level module depends on low-level module
class LightBulb:
    def turn_on(self):
        print("LightBulb: ON")

    def turn_off(self):
        print("LightBulb: OFF")

class Switch:
    def __init__(self, bulb: LightBulb):
        self.bulb = bulb

    def toggle(self, state: bool):
        if state:
            self.bulb.turn_on()
        else:
            self.bulb.turn_off()

# With DIP: Introduce an abstraction
class Switchable:
    def turn_on(self):
        pass

    def turn_off(self):
        pass

class LightBulb(Switchable):
    def turn_on(self):
        print("LightBulb: ON")

    def turn_off(self):
        print("LightBulb: OFF")

class Fan(Switchable):
    def turn_on(self):
        print("Fan: Spinning")

    def turn_off(self):
        print("Fan: Stopped")

class Switch:
    def __init__(self, device: Switchable):
        self.device = device

    def toggle(self, state: bool):
        if state:
            self.device.turn_on()
        else:
            self.device.turn_off()

# Usage
bulb = LightBulb()
fan = Fan()

switch1 = Switch(bulb)
switch2 = Switch(fan)

switch1.toggle(True)  # Output: "LightBulb: ON"
switch2.toggle(False)  # Output: "Fan: Stopped"
```

## Static (Methods and Variables)
Static members belong to the class rather than any instance.

```cpp
#include <iostream>

class Counter {
private:
    static int count; // Shared across all objects
public:
    Counter() { ++count; }
    static int getCount() { return count; } // Static method to access static variable
};

int Counter::count = 0; // Initialize static variable

int main() {
    Counter c1, c2, c3;
    std::cout << "Number of objects: " << Counter::getCount() << std::endl;
    return 0;
}
```

## Testing in OOP (Unit Testing, Test-Driven Development)
Testing ensures code works as expected. Unit testing tests individual components, and Test-Driven Development (TDD) writes tests before implementing functionality.

```cpp
#include <gtest/gtest.h> // Google Test framework

class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
};

// Unit Test
TEST(CalculatorTests, AddTest) {
    Calculator calc;
    EXPECT_EQ(calc.add(3, 2), 5);
}

TEST(CalculatorTests, SubtractTest) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

// Main for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## UML Diagrams and Modeling
Unified Modeling Language (UML) diagrams visually represent system design. Examples include class diagrams, sequence diagrams, and use-case diagrams.

```cpp
+-------------+
|    Car      |
+-------------+
| - brand     |
| - model     |
| - year      |
+-------------+
| + drive()   |
| + stop()    |
+-------------+
```

## Virtual
Virtual functions in C++ allow dynamic (runtime) method overriding.

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() { std::cout << "Animal speaks." << std::endl; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Dog barks." << std::endl; }
};

int main() {
    Animal* animal = new Dog();
    animal->speak(); // Calls Dog's speak due to the virtual keyword
    delete animal;
    return 0;
}
```
