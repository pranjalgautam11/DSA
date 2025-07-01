#include <bits/stdc++.h>
using namespace std;

// ENCAPSULATION: Hiding the data members and methods of a class from outside access and providing public methods to access and modify them.

class Teacher
{
private:
    int salary;

public:
    string name;
    string department;

    Teacher(string n, string d)
    {
        salary = 0; // Initialize salary to 0
        name = n;
        department = d;
        cout << "Employee Name: " << name << ", Department: " << department << endl;
    }

    // setter method to set salary
    void setSalary(int s)
    {
        salary = s;
    }
    // getter method to get salary
    int getSalary() const
    {
        return salary;
    }
};

// in this example, the salary is private and cannot be accessed directly from outside the class.The setter method allows setting the salary, and the getter method allows retrieving it.

// Inheritance: creating a new class that is based on an existing class, inheriting its properties and behaviors.
// In C++, inheritance is implemented using the `:` syntax, where the derived class inherits from the base class.

class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        cout << "Person Constructor Called" << endl;
        this->name = name;
        this->age = age;
    }

    void getinfo(){
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class student : public Person{
public:
    int rollno;
    student(int rollno, string name, int age) : Person(name, age){
        cout << "Student Constructor Called" << endl;
        this->rollno = rollno;
    }

    void getinfo(){
        cout << "Name: " << name << ", Age: " << age << ", Roll No: " << rollno << endl;
    }
};

// In this example, the `Person` class is the base class, and the `student` class is the derived class. The `student` class inherits the properties and methods of the `Person` class, and it can also have its own additional properties and methods.

// Polymorphism: the ability to present the same interface for different data types. In C++, polymorphism can be achieved through function overloading and operator overloading.
// Compile time polymorphism is achieved through function overloading, where multiple functions can have the same name but different parameters.
// Run time polymorphism is achieved through function overriding, where a derived class provides a specific implementation of a method that is already defined in its base class.

class Print {
public:
    // Function overloading: same function name with different parameters
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    void show(char c){
        cout << "Character: " << c << endl;
    }
    // operator overloading: using the same operator for different data types
};

// function overriding: when a derived class provides a specific implementation of a method that is already defined in its base class.
class base{
public:
    void display(){
        cout << "Base class display function called." << endl;
    }

    // virtual function: allows derived classes to override the base class method
    virtual void hello(){
        cout << "Hello from base class." << endl;
    }
};

class child : public base {
public:
    void display(){
        cout << "Child class display function called." << endl;
    }   
    void hello(){
        cout << "Hello from child class." << endl;
    }
};

// In this example, the `Print` class demonstrates compile time polymorphism through function overloading, where the `show` method is defined with different parameter types. The `base` and `child` classes demonstrate run time polymorphism through function overriding, where the `hello` method is defined in both classes, allowing the derived class to provide its own implementation.

// Abstraction: the process of hiding the complex implementation details and showing only the essential features of an object. In C++, abstraction can be achieved using abstract classes and interfaces.

class Shape{
public:
    // pure virtual function: makes this class an abstract
    virtual void draw() = 0; // This function must be implemented by derived classes
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

int main()
{
    // ---- ENCAPSULATION ----

    cout << "Encapsulation Example:" << endl;

    Teacher t1("Bob", "Engineering");
    t1.setSalary(50000);
    cout << "Salary of " << t1.name << " is: " << t1.getSalary() << endl;

    // ---- INHERITANCE ----
    cout << "\nInheritance Example:" << endl;
    student s1(101, "Alice", 20);
    s1.getinfo(); // Output: Name: Alice, Age: 20, Roll No: 101

    // ---- POLYMORPHISM ----
    cout << "\nPolymorphism Example:" << endl;
    cout << "Compile time Polymorphism - Function Overloading Example:" << endl;
    Print p;
    p.show(10); // Output: Integer: 10
    p.show('A'); // Output: Character: A

    cout << "Run time Polymorphism - Function Overriding Example:" << endl;
    base b;
    b.display(); // Output: Base class display function called.
    b.hello(); // Output: Hello from base class.
    child c;
    c.display(); // Output: Child class display function called.
    c.hello(); // Output: Hello from child class.

    // ---- ABSTRACTION ----
    cout << "\nAbstraction Example:" << endl;
    Circle circle;
    circle.draw(); // Output: Drawing Circle 
}