#include <iostream>

using namespace std;


/*
    Polymorphism

    12. Final

    --- Final Class ---
*/



/*
    1. Security:

    In security-critical applications, you might have classes that implement important security protocols or algorithms.
    Making these classes final ensures that no one can create a subclass that might compromise the security of the system.

    Suppose you are working on a security-critical application that handles encryption, 
    and you have a class called EncryptionAlgorithm responsible for implementing a highly secure encryption algorithm:
*/
class EncryptionAlgorithm final {
    public:
        EncryptionAlgorithm() {
            // Initialize encryption parameters securely...
        }

        ~EncryptionAlgorithm() {
            // Clear sensitive data securely...
        }

    private:
        // Secure internal data...
};
/*
    In this EncryptionAlgorithm class, you have taken great care to ensure 
    that encryption and decryption operations are performed securely. 
    It's crucial that this class remains secure in all scenarios.

    Now, consider the possibility that someone could create a subclass 
    of EncryptionAlgorithm with malicious intent or inadvertently introduce vulnerabilities:

    hash("Rustam!") => 2323hj23h23h23h23hh33h2k3hk2k32h3h3hk2h3, length is 32

    class InsecureEncryptionAlgorithm : public EncryptionAlgorithm {
        public:
            // Potentially insecure encryption methods...
            // Vulnerabilities may be introduced here...
    };

    Note!
    By allowing inheritance, you open the door for potential security risks, either intentionally or unintentionally.
*/



/*
    2. Performance Optimization:
    If you have a class that's highly optimized for performance, 
    you might not want it to be extended in ways that could introduce inefficiencies. 
    Marking it as final prevents subclassing and maintains the performance characteristics.
*/
class Matrix final {
    public:
        Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
            data_ = new double*[rows_];
            for (int i = 0; i < rows_; ++i) {
                data_[i] = new double[cols_];
            }
        }

        // Efficient matrix operations here...
        ~Matrix() {
            for (int i = 0; i < rows_; ++i) {
                delete[] data_[i];
            }
            delete[] data_;
        }

    private:
        int rows_;
        int cols_;
        double** data_;
};

/*
    Suppose you have a highly optimized Matrix class that represents 
    a mathematical matrix and provides efficient matrix operations.

    Now, imagine someone attempts to create a subclass of Matrix 
    without fully understanding or respecting the performance optimizations in the base class:

    class SuboptimalMatrix : public Matrix {
        public:
            // Inefficient matrix operations here...
    };
*/




/*
    3. Immutable Objects:

    In cases where you want to create immutable objects, 
    you can make the class final to ensure that no one can create a subclass that introduces mutability.
*/
class ImmutablePoint final {
    public:
        ImmutablePoint(int x, int y) : x_(x), y_(y) {}

        int getX() const { return x_; }
        int getY() const { return y_; }

        /*
            The use of const member variables ensures that the point's coordinates
            cannot be modified once the object is constructed, making it immutable.
        */
    private:
        const int x_;
        const int y_;
};

/*
    By making the ImmutablePoint class final, you ensure that 
    no one can create a subclass that would attempt to change the behavior of the class, 
    potentially violating the immutability contract.
*/



/*
    4. Singleton Pattern:

    When implementing the Singleton design pattern, 
    you can use final to prevent subclassing and ensure that there is only one instance of the class.
*/
class Singleton final {
    // ...
    public:
        static Singleton& getInstance() {
            static Singleton instance;
            return instance;
        }
};




/*
    5. Avoiding Subclassing Mistakes:

    In some cases, a class is not designed to be extended, 
    and allowing subclassing could lead to unintended consequences. 
    Marking such classes as final can serve as a clear indication of the intended usage.

    Suppose you have a class called Configuration that represents configuration settings for a complex software system:
*/
class Configuration final {
    public:
        Configuration() {
            // Initialize default configuration settings...
        }

        int db_port = 3306;
        // Methods to set and retrieve configuration settings...

    private:
        // Internal representation of configuration settings...
};
/*
    In this Configuration class, you've designed it to manage configuration settings for your software. 
    You don't want anyone to create a subclass of Configuration 
    because doing so might introduce unintended behavior or override essential methods.

    However, without marking it as final, someone might create a subclass:

    class SuboptimalConfiguration : public Configuration {
        public:
            // Overrides or introduces unintended behavior...
    };
*/



int main() {

    /*
        Remember that marking a class as final should be done thoughtfully,
        as it restricts the flexibility of your code. 
        
        It should only be used when it's essential to prevent inheritance and 
        when it aligns with your design goals and requirements.
    */

}