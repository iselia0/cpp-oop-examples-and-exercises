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
        virtual void storeData(const string& data) const =0;

        // TODO: Add a common function to log storage attempts
        void logStorageAttempt(const string& data) const{
            cout<<"Storage attempt for data: "<<data<<" logged"<<endl;
        }

        virtual ~DataStorageProvider(){}
};

// Concrete subclass for storing data in a relational database
class RelationalDatabaseStorage : public DataStorageProvider {
    public:
        // TODO: Implement the storeData function
        void storeData(const string& data) const override{
            cout<<"Storing data in a relational database: "<<data<<endl;
        }
};

// Concrete subclass for storing data in a cloud-based NoSQL database
class CloudNoSQLStorage : public DataStorageProvider {
    public:
        // TODO: Implement the storeData function
        void storeData(const string& data) const override{
            cout<<"Storing data in a cloud-based NoSQL database: "<<data<<endl;
}
};



int main() {

    // TODO: Create instances of RelationalDatabaseStorage and CloudNoSQLStorage

    RelationalDatabaseStorage relationalStorage;
    CloudNoSQLStorage cloudStorage;

    // TODO: Log storage attempts for different data
    DataStorageProvider* relationalPtr = &relationalStorage;
    DataStorageProvider* cloudPtr = &cloudStorage;

        string data1="Sample data 1";
    relationalPtr->logStorageAttempt(data1);
    relationalPtr->storeData(data1);

    string data2="Sample data 2";
    cloudPtr->logStorageAttempt(data2);
    cloudPtr->storeData(data2);

    // TODO: Store data using each storage provider


    /*
        Example Output:

        Storage attempt for data: Sample data 1 logged.
        Storing data in a relational database: Sample data 1

        Storage attempt for data: Sample data 2 logged.
        Storing data in a cloud-based NoSQL database: Sample data 2
    */

}