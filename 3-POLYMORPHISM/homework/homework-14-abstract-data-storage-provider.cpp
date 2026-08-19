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
        // Pure virtual function to store data
        virtual void storeData(const string& data) const = 0;

        // Common functionality shared among data storage providers
        void logStorageAttempt(const string& data) const {
            cout << "Storage attempt for data: " << data << " logged." << endl;
        }
};

// Concrete subclass for storing data in a relational database
class RelationalDatabaseStorage : public DataStorageProvider {
    public:
        // Implementation of the pure virtual function
        void storeData(const string& data) const override {
            // Storage logic using a relational database
            cout << "Storing data in a relational database: " << data << endl;
            // Additional logic specific to relational database storage
        }
};

// Concrete subclass for storing data in a cloud-based NoSQL database
class CloudNoSQLStorage : public DataStorageProvider {
    public:
        // Implementation of the pure virtual function
        void storeData(const string& data) const override {
            // Storage logic using a cloud-based NoSQL database
            cout << "Storing data in a cloud-based NoSQL database: " << data << endl;
            // Additional logic specific to cloud-based NoSQL storage
        }
};

int main() {

    // Create instances of concrete subclasses
    RelationalDatabaseStorage relationalDatabaseStorage;
    CloudNoSQLStorage cloudNoSQLStorage;

    // Call common functionality from the abstract class
    relationalDatabaseStorage.logStorageAttempt("Sample data 1");
    cloudNoSQLStorage.logStorageAttempt("Sample data 2");

    // Call specific functionality based on the type of data storage provider
    relationalDatabaseStorage.storeData("Sample data 1");
    cloudNoSQLStorage.storeData("Sample data 2");

    return 0;
}
