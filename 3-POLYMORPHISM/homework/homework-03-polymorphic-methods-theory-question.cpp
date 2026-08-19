#include <iostream>

using namespace std;

/*
    Note!

    Please note that you should not write code or implement solutions; 
    just provide your answers to the following question:
*/



/*
    Exercise_1: Polymorphic Methods in E-Commerce

    Scenario:

    You are developing an e-commerce platform. 
    The platform will have a base class called Product and several derived classes, such as Book, Electronic, and Clothing. 
    The Product class will have methods to get and set the product's name, price, and description. 
    The derived classes will inherit these methods from the Product class and may also have their own unique methods.

    Exercise:

    Decide which of the following methods should be polymorphic in the Product class:
       - getName()
       - setName()
       - calculateTax()
       - calculateShipping()
       - getPrice()
       - setPrice()
       - getDescription()
       - setDescription()
*/

/*
    Solution:
        The calculateTax() and calculateShipping() methods should be polymorphic in the Product class. 
        This is because the way that different products are taxed and shipped can be different. 
        For example, books are typically exempt from sales tax, while electronics are not. 
        Books are also typically shipped for free, while electronics may have a shipping fee.

        By making the calculateTax() and calculateShipping() methods polymorphic, 
        you can allow the derived classes to implement their own unique versions of those methods. 
        This will make the platform more flexible and reusable.

        The other methods in the Product class do not need to be polymorphic, 
        because they can be implemented in a generic way that applies to all products. 
        For example, the getName() method can simply return the product's name attribute.
*/


/*
    Exercise_2:

    Scenario:

    You are developing a C++ program to simulate a car race. 
    The program will have a base class called Vehicle and two derived classes, Car and Motorcycle. 
    The Vehicle class will have methods to get and set the vehicle's speed, direction, and position. 
    The Car and Motorcycle classes will inherit these methods from the Vehicle class and may also have their own unique methods.

    Decide which of the following methods should be polymorphic in the Vehicle class:
       - getSpeed()
       - setSpeed()
       - getDirection()
       - setDirection()
       - getPosition()
       - move()
*/

/*
    Solution:
        The move() method should be polymorphic in the Vehicle class. 
        This is because the way that a car moves is different from the way that a motorcycle moves. 
        For example, a car has four wheels and can turn by turning its wheels,
        while a motorcycle has two wheels and turns by leaning.
        By making the move() method polymorphic, you can allow the Car 
        and Motorcycle classes to implement their own unique versions of the method. 
        This will make the program more flexible and reusable.
        The other methods in the Vehicle class do not need to be polymorphic, 
        because they can be implemented in a generic way that applies to all vehicles.
        For example, the getSpeed() method can simply return the vehicle's speed attribute.
*/


/*
    Exercise_3: Polymorphic Methods in Backend Development

    Scenario:

    You are developing a backend for a social media platform. 
    The backend will have a base class called User and several derived classes, 
    such as RegularUser, ContentCreator, and Administrator. 
    The User class will have methods to get and set the user's name, email address, and profile picture. 
    The derived classes will inherit these methods from the User class and may also have their own unique methods.

    Exercise:

    Decide which of the following methods should be polymorphic in the User class:
       - getName()
       - manageUsers()
       - setName()
       - postContent()
       - getEmailAddress()
       - setEmailAddress()
       - getProfilePicture()
       - deleteContent()
       - setProfilePicture()
*/


/*
    Solution:

    The postContent(), deleteContent(), and manageUsers() methods should be polymorphic in the User class. 
    This is because the way that different types of users can post, delete, and manage content can be different. 
    For example, regular users can only post content to their own profiles, 
    while content creators can post content to their own profiles and to groups that they manage. 
    Administrators can post content to any profile or group on the platform.
    
    By making the postContent(), deleteContent(), and manageUsers() methods polymorphic, 
    you can allow the derived classes to implement their own unique versions of those methods. 
    This will make the backend more flexible and reusable.

    The other methods in the User class do not need to be polymorphic, 
    because they can be implemented in a generic way that applies to all users. 
    For example, the getName() method can simply return the user's name attribute.
*/



int main() {


}
