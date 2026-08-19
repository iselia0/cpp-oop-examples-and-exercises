#include <iostream>
#include <string>

using namespace std;


// Interface for database connections
class IDatabaseConnection {
    public:
        virtual void connect() = 0;
        virtual void disconnect() = 0;
        virtual void executeQuery(const string& query) = 0;
};


// MySQL database connection implementation
class MySQLDatabaseConnection : public IDatabaseConnection {
    public:
        void connect() override {
            cout << "Connected to MySQL database" << endl;
            // Implement MySQL-specific connection logic here
        }

        void disconnect() override {
            cout << "Disconnected from MySQL database" << endl;
            // Implement MySQL-specific disconnection logic here
        }

        void executeQuery(const string& query) override {
            cout << "Executing MySQL query: " << query << endl;
            // Implement MySQL-specific query execution logic here
        }
};


// PostgresSQL database connection implementation
class PostgresSQLDatabaseConnection : public IDatabaseConnection {
    public:
        void connect() override {
            cout << "Connected to PostgresSQL database" << endl;
            // Implement PostgresSQL-specific connection logic here
        }

        void disconnect() override {
            cout << "Disconnected from PostgresSQL database" << endl;
            // Implement PostgresSQL-specific disconnection logic here
        }

        void executeQuery(const string& query) override {
            cout << "Executing PostgresSQL query: " << query << endl;
            // Implement PostgresSQL-specific query execution logic here
        }
};


int main() {

    system("clear");

    IDatabaseConnection *dbConnection = new MySQLDatabaseConnection();

    dbConnection->connect();
    dbConnection->executeQuery("SELECT * FROM users");
    dbConnection->disconnect();

    delete dbConnection;

    dbConnection = new PostgresSQLDatabaseConnection();

    dbConnection->connect();
    dbConnection->executeQuery("SELECT * FROM products");
    dbConnection->disconnect();

    delete dbConnection;

}
