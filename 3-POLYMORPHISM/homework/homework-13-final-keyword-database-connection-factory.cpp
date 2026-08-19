#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    12. Final

    --- Final Class ---
*/

/*
    Analyze the code below and complete TODO list
*/

// Base class representing a database connection
class DatabaseConnection {
    public:
        // Establishes a connection to the database
        virtual void connect() const = 0;
};

// TODO: Decide whether to mark the following class as final or not
class MySqlConnection : public DatabaseConnection {
    public:
        void connect() const override {
            cout << "Connecting to MySQL database..." << endl;
            // TODO: Implement connection logic for MySQL
        }
};

// TODO: Decide whether to mark the following class as final or not
class PostgresConnection : public DatabaseConnection {
    public:
        void connect() const override {
            cout << "Connecting to PostgreSQL database..." << endl;
            // TODO: Implement connection logic for PostgreSQL
        }
};

// Database connection factory
class ConnectionFactory {
    public:
        // TODO: Decide whether to mark the following methods as static or not
        // Factory method to create a MySQL connection
        DatabaseConnection* createMySQLConnection() {
            return new MySqlConnection();
        }

        // Factory method to create a PostgreSQL connection
        DatabaseConnection* createPostgresConnection() {
            return new PostgresConnection();
        }
};


int main() {

    // TODO: Create instances of database connections using the factory
    ConnectionFactory factory;
    DatabaseConnection* mysqlConnection = factory.createMySQLConnection();
    DatabaseConnection* postgresConnection = factory.createPostgresConnection();

    // TODO: Decide whether to uncomment the following lines to delete instances
    // delete mysqlConnection;
    // delete postgresConnection;

    return 0;
}
