#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    14. Pure virtual functions and Abstract classes
*/


/*
    Problem Statement:
    You are tasked with designing a system that can store data using different data storage mechanisms in a web backend. 
    Create a C++ program that demonstrates the use of an abstract class to model different types of data storage providers.

    1. Create an abstract class DataStorageProvider with the following features:
        A pure virtual function storeData that takes a string parameter representing the data to be stored.
    2. Implement two concrete subclasses of DataStorageProvider:
        RelationalDatabaseStorage: Implement the storeData function to display a message indicating that the data is being stored in a relational database.
        CloudNoSQLStorage: Implement the storeData function to display a message indicating that the data is being stored in a cloud-based NoSQL database.
    3. Implement a common functionality in the abstract class DataStorageProvider:
        Add a function logStorageAttempt that takes a string parameter representing 
        the data and displays a message indicating that a storage attempt for the given data has been logged.
    4. In the main function, create instances of both RelationalDatabaseStorage and CloudNoSQLStorage. 
        Use these instances to demonstrate:
        Logging storage attempts for different data.
        Storing data using each storage provider.
*/


// Abstract class representing a data storage provider
class DataStorageProvider {
    public:
        // TODO: Add a pure virtual function to store data

        // TODO: Add a common function to log storage attempts
};

// Concrete subclass for storing data in a relational database
class RelationalDatabaseStorage : public DataStorageProvider {
    public:
        // TODO: Implement the storeData function
};

// Concrete subclass for storing data in a cloud-based NoSQL database
class CloudNoSQLStorage : public DataStorageProvider {
    public:
        // TODO: Implement the storeData function
};



int main() {

    // TODO: Create instances of RelationalDatabaseStorage and CloudNoSQLStorage

    // TODO: Log storage attempts for different data

    // TODO: Store data using each storage provider


    /*
        Example Output:

        Storage attempt for data: Sample data 1 logged.
        Storing data in a relational database: Sample data 1

        Storage attempt for data: Sample data 2 logged.
        Storing data in a cloud-based NoSQL database: Sample data 2
    */

}