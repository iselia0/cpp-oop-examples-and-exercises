#include <iostream>
#include <vector>

using namespace std;

class User {
    private:
        string password;

    public:
        int age;
        long long int grade;
        string name;

        User() {
            cout << "object created" << endl;
            password = "";
            age = 0;
            name = "";
        }

        User(string nameP, int ageP) {
            name = nameP;
            age = ageP;
        }

        void set(string passwordP) {
            password =  "sdsd" + passwordP + "sdsds";
        }

        string getPassword() {
            return password;
        }

        void printName() {
            cout << name << endl;
        }

        ~User() {
            cout << name << endl;
        }
};


int main() {

    User rustam;

    cout << sizeof(rustam) << endl;
    
    return 0;
}
 
    
