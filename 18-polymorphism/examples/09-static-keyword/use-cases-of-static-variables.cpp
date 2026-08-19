#include <iostream>

using namespace std;

/*
    Polymorphism

    9. Application of Static Variables
*/


/*
    Static variables in C++ have various use cases, thanks to their unique properties of retaining their values 
    across function calls or being associated with a class rather than instances.
*/


/*
    1. Counters and Accumulators: Static variables are frequently used to maintain counts or 
    accumulate values across multiple function calls.

    For example, you can use a static variable in a function to count how many times 
    the function has been called or to accumulate a sum of values passed to the function.
*/
void countCalls() {
    static int callCount = 0;
    callCount++;
    cout << "Function called " << callCount << " times." << endl;
}


/*
    2. Singleton Pattern: Static variables are frequently used to maintain counts or 
    accumulate values across multiple function calls.
*/
class Singleton { 
    private:
        string name, surname;
        static Singleton *instancePtr;

        // Private constructor to prevent external instantiation
        Singleton() {
            // Constructor code here (if needed)
        }

        // Private destructor to prevent external deletion
        ~Singleton() {
            // Destructor code here (if needed)
        }
    
    public:
        // deleting copy constructor
        Singleton(const Singleton& obj) = delete;

        static Singleton *getInstance() {
            if (instancePtr == nullptr) {
                instancePtr = new Singleton();
            }

            return instancePtr;
        }
        /*
            Note!!!
            
            getInstance() is a static method that returns an instance when it is invoked.
            It returns the same instance if it is invoked more than once as an instance
            of Singleton class is already created. 
            It is static because we have to invoke this method without any object
            of Singleton class and static method can be invoked without object of class.
        
            As constructor is private so we cannot create object of
            Singleton class without a static method as they can be
            called without objects. We have to create an instance of
            this Singleton class by using getInstance() method.
        */

        // sets values of member variables.
        void setValues(string name, string surname) {
            this->name = name;
            this->surname = surname;
        }
        
        // prints values of member variables
        void print(){
            cout << name << ", Surname: " << surname << "." << endl;
        }
};

// initializing instancePtr with NULL
Singleton* Singleton::instancePtr = nullptr;


/*
    3. Caching:

    Static variables can be used for caching expensive or frequently used data. 
    Once computed or loaded, the cached data can be reused efficiently across multiple function calls.
*/
static int cache[100] = {0};    // Static cache for Fibonacci numbers

int fibonacci(int n) {
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= n; ++i) {
        // If the Fibonacci number is already cached, use it
        if (cache[i] != 0) {
            continue;
        }

        // Calculate and cache the Fibonacci number
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
}


/*
    4. State Maintenance:

    Static variables are handy for maintaining the state of a function or class across multiple calls. 
    For example, they can be used in a state machine to remember the current state.
*/
class StateMachine {
    public:
        void transition() {
            static int state = 0;
            state++;
        }
};


/*
    5. Resource Management:

    Static variables can be used to manage resources such as file handles, database connections, 
    or network sockets, ensuring that resources are opened only once and properly closed when no longer needed.
*/
struct FileHandle 
{
    FileHandle(string file_name) {
        // some logic
    }
};

class ResourceManager {
    public:
        static FileHandle& getFile() {
            static FileHandle file("example.txt");
            return file;
        }
};


/*
    6. Memoization:
    
    In recursive algorithms, static variables can be used to store previously computed results 
    to avoid redundant calculations, which can significantly improve performance.
*/
int memo_fibonacci(int n) {
    static unordered_map<int, int> memo;

    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // Calculate and store the result in memo
    memo[n] = memo_fibonacci(n - 1) + memo_fibonacci(n - 2);

    return memo[n];
}


int main() {

    system("clear");

    Singleton *CodeStar = Singleton::getInstance();

    CodeStar->setValues("Ozzy", "Osbourne");
    CodeStar->print();

    Singleton *StarCode = Singleton::getInstance();
    StarCode->print();

    /*
        [Output]

        Ozzy, Surname: Osbourne.
        Ozzy, Surname: Osbourne.
    */
    cout << "--------" << endl;


    int n = 10;
    int result = fibonacci(n);
    cout << "Fibonacci(" << n << ") = " << result << endl;

    n = 5;
    result = fibonacci(n);   // instead of recalculating it takes from cache
    cout << "Fibonacci(" << n << ") = " << result << endl;
    /*
        Fibonacci(10) = 55
        Fibonacci(5) = 5
    */
}
