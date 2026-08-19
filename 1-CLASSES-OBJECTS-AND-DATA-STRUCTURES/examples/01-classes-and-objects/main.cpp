#include <iostream>
#include <string>

using namespace std;


/*
    Classes
    
    1. Intro to classes
    2. Your First Class
    3. C++ Constructors
    4. Defaulted constructors
    5. Setters and Getters
    6. Class Across Multiple Files
    7. Arrow pointer call notation
    8. Destructors
    9. Order of Constructor Destructor Calls
    10. The "this" Pointer
    11. Struct
*/



/*
    2. Your First Class
*/
const double PI = 3.14159265358979323846264338327950288;

class Cylinder {
    // Member variables
    public:
        double radius = 1;
        double height = 1;

    public: 
        double volume() {
            return PI * radius * radius * height;
        }
};



int main() {

    
    /*
        1. Intro to classes

        Object-oriented programming (OOP) is a programming paradigm that allows for the creation of modular, 
        reusable code by representing real-world concepts as objects that have attributes (data) and methods (functions). 
        The use of OOP can be beneficial in various cases, including:

        1. Large and complex programs: 
        When a program is large and complex, it can be difficult to manage and maintain. 
        OOP provides a way to break down the program into smaller, more manageable pieces, 
        making it easier to understand and modify.

        2. Reusability: By encapsulating data and behavior into objects, 
        OOP allows for code to be easily reused in different parts of the program or in other programs altogether. 
        This can save time and effort in development.

        3. Collaboration: OOP can be useful in collaborative programming environments, 
        where multiple developers are working on the same codebase. 
        By breaking down the program into smaller, more manageable objects, 
        it becomes easier for different developers to work on different parts of the program without interfering with each other's work.

        4. Modeling real-world concepts: OOP provides a natural way to model real-world concepts in code, 
        such as objects, attributes, and behaviors.
        This can make the code easier to understand and maintain, as it reflects the real-world concepts.

        5. Security: OOP allows for data to be encapsulated within objects, 
        making it more secure and less vulnerable to unauthorized access or modification.

        Overall, the real need for object-oriented programming arises when a program is large and complex, 
        requires modularity and reusability, involves collaboration among developers,
        models real-world concepts, and/or requires enhanced security measures.
    */


    /*
        Functional Programming (like a box of tools)
        Math -> functional programming
        String -> object oriented programming
        User Form -> +String
    */


    /*
        Functional Programming VS Object Oriented Programming

        Problems realizing software at the functions level?

        1. Lack of Organization: When software is broken down into numerous functions, 
        it can become challenging to maintain an overall structure and organization. 
        It may become difficult to locate specific functions or understand the relationships and dependencies between them. 
        Proper naming conventions, documentation, and modularization techniques can help mitigate this issue.

        2. Data Flow and Dependencies: Coordinating the flow of data and managing dependencies between functions can become complex, 
        particularly in larger software systems. 
        Tracking and managing the input and output of each function,
        as well as handling data transformations and passing information between functions, can require careful planning and design.

        3. Scalability and Performance: In some cases, decomposing software into smaller functions 
        can result in performance overhead due to the additional function calls and data transformations involved.
        Careful consideration should be given to the performance implications of function-level decomposition, 
        and optimization techniques may be required to improve efficiency and scalability.

        4. Debugging and Error Handling: Debugging software at the function level can be challenging when errors occur. 
        Identifying the source of an error or a specific function causing an issue may require thorough testing and debugging techniques. 
        Additionally, error handling and exception management can become more complex when dealing with multiple interconnected functions.

        5. Complexity of Control Flow: Managing control flow and program logic can become more complex when functions are decomposed at a fine-grained level. 
        Conditional branching, loops, and overall program flow can be harder to follow and understand when spread across multiple functions.
        This can make code maintenance and debugging more challenging.

        6. Collaboration and Teamwork: Working collaboratively on software developed at the function level may require strong coordination and communication among team members.
        Consistent coding conventions, documentation, and clear interfaces between functions are crucial to ensure effective collaboration and maintainability.

        

        How Object Oriented Programming solves these problems?

        1. Organization and Structure: OOP provides a structured approach to software development by organizing code into classes and objects.
        Classes encapsulate data and behavior into cohesive units, allowing for a more intuitive and organized representation of the system.
        Relationships between classes, such as inheritance and composition, help establish a clear structure and hierarchy within the codebase.

        2. Data Flow and Dependencies: OOP manages data flow and dependencies through the use of object interactions and encapsulation.
        Objects communicate with each other through well-defined interfaces, passing data and messages. 
        This helps manage dependencies and facilitates a more controlled and explicit flow of data within the system.

        3. Scalability and Performance: OOP supports modular design principles, allowing for the encapsulation of functionality within objects. 
        Objects can be easily extended, reused, and composed to build larger systems. 
        This promotes scalability and code reuse. 
        Additionally, OOP allows for performance optimizations such as data encapsulation, polymorphism, 
        and efficient memory management techniques like garbage collection.

        4. Debugging and Error Handling: OOP provides better debugging and error handling capabilities compared to function-level programming. 
        Objects encapsulate both data and behavior, making it easier to isolate and debug specific components of the system.
        Error handling mechanisms, such as exceptions, can be implemented at the object level, providing more granular control and better error management.

        5. Control Flow and Program Logic: OOP offers control flow mechanisms such as polymorphism, inheritance, and dynamic dispatch. 
        These features enable more flexible and expressive control flow and program logic. 
        Inheritance allows for code reuse and specialization, 
        while polymorphism enables objects of different types to be treated uniformly,
        simplifying control flow and reducing conditional statements.

        6. Collaboration and Teamwork: OOP promotes modularity and encapsulation, 
        enabling teams to work on different parts of the system concurrently. 
        Classes provide clear interfaces and encapsulate implementation details, allowing team members to work independently on different components. 
        This fosters collaboration and eases the integration of different modules into a cohesive system.

        Overall, OOP provides a higher level of abstraction and structure compared to function-level programming. 
        It addresses many of the challenges faced in large-scale software development by promoting modularity, encapsulation, and code reuse. 
        However, it's important to note that OOP is not a one-size-fits-all solution, 
        and the choice of programming paradigm depends on the nature of the problem and the goals of the software project.
    */


    /*
        2. Your First Class

        By defualt class members are private!
    */

    /*
        The variables that we create from our class are usually called objects. 
        The class "Cylinder" by itself is a blueprint(plan) and we create an object using that blueprint.
    */
    Cylinder cylender1;   // object cylinder 1 of class Cylinder

    /*
        IF ->   private:
                    double radius = 1;
                    double height = 1;

        cout << "radius: " << cylender1.radius << endl;     // error: ‘double Cylinder::height’ is private within this context
        cout << "hieght: " << cylender1.height << endl;     // error: ‘double Cylinder::radius’ is private within this context
    */
    cout << "volume: " << cylender1.volume() << endl;

    cylender1.height = 10;
    cylender1.radius = 4;

    cout << "volume: " << cylender1.volume() << endl;


    /* 
        Summary:

        ~ Class have functions (methods) that let them do things.
        ~ Class methods have access to the member variables, regardless of whether they are public or private.
        ~ Private members of classes ((variables and functions) are not accessible from the outside of the class definition.
        ~ Class members, variables by defaullt are private.
    */

}