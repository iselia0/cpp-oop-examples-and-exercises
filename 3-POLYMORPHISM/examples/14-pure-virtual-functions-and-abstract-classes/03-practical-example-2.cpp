#include <iostream>
#include <string>

using namespace std;


// Abstract base class representing a generic web request handler
class RequestHandler {
    public:
        virtual void handleRequest(const string& request) = 0;
};


// Derived class for handling HTTP GET requests
class HttpGetHandler : public RequestHandler {
    public:
        void handleRequest(const string& request) override {
            cout << "Handling HTTP GET request: " << request << endl;
        }
};


// Derived class for handling HTTP POST requests
class HttpPostHandler : public RequestHandler {
    public:
        void handleRequest(const string& request) override {
            cout << "Handling HTTP POST request: " << request << endl;
            // Implement the logic to process an HTTP POST request here
        }
};


int main() {

    // Instantiate request handlers
    HttpGetHandler getHandler;
    HttpPostHandler postHandler;

    // Simulate incoming web requests
    string getRequest = "GET /some/resource";
    string postRequest = "POST /some/resource";

    // Handle the requests
    getHandler.handleRequest(getRequest);
    postHandler.handleRequest(postRequest);

    return 0;
}
