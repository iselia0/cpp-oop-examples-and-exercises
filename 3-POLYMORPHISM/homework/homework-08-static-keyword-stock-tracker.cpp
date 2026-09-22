#include <iostream>
#include <string>

using namespace std;


/*
    Static Keyword in C++
*/


/*
    Exercise-1: Stock Price Tracker

    Write a C++ program that simulates a stock price tracker function. 
    The stock price tracker function should have the following properties:

    1. Create a function named trackStockPrice that takes the stock symbol (a string) and the current stock price (a double) as parameters.
    2. Inside the function, maintain a static local variable that stores the highest stock price observed for a given stock symbol.
    3. Update the highest stock price if the current price is higher.
    4. The function should return the highest stock price observed for the given stock symbol.


*/
double trackStockPrice(string symbol, double currentPrice) {
    // your code
    double trackStockPrice(string symbol, double currentPrice){
    static string symboli[100];
    static double highest[100];
    static int n=0;

    for(int i=0; i<n; i++){
        if(symboli[i]==symbol){
            if(currentPrice>highest[i]) 
            highest[i]=currentPrice;
            return highest[i];
        }
    }

    symboli[n]=symbol;
    highest[n]=currentPrice;
    n++;
    return currentPrice;
}
}
double trackStockPrice(string symbol, double currentPrice){
    static string symboli[100];
    static double highest[100];
    static int n=0;

    for(int i=0; i<n; i++){
        if(symboli[i]==symbol){
            if(currentPrice>highest[i]) 
            highest[i]=currentPrice;
            return highest[i];
        }
    }

    symboli[n]=symbol;
    highest[n]=currentPrice;
    n++;
    return currentPrice;
}

/*
    Exercise-2: Bank Account Management

    Create a C++ program that models a simplified bank account management system. 
    In this system, you will create a BankAccount class with the following features:

    1. Each BankAccount object should have a unique account number that starts from 1001 and increments by 1 for each new account created.
    2. Each account should have an account balance.
    3. Implement methods to deposit and withdraw funds from the account.
    4. Implement a method to display the account details, including the account number and balance.
*/
class BankAccount {
    private:
    int accountNumber;
    double balance;
    static int nextAccountNumber;

public:
    static int totalAccounts;

    BankAccount(double initialBalance=0.0):balance(initialBalance){
        accountNumber=nextAccountNumber++;
        totalAccounts++;
    }

    void deposit(double amount){
        if(amount<=0){
            cout<<"Amount must be positive."<<endl;
            return;
        }
        balance+=amount;
    }

    void withdraw(double amount){
        if(amount<=0){
            cout<<"Amount must be positive."<<endl;
            return;
        }
        if(amount>balance){
            cout<<"Insufficient funds "<<accountNumber<<endl;
            return;
        }
        balance-=amount;
    }

    void displayAccountDetails() const{
        cout<<"Account Number: "<<accountNumber<<"  Balance: "<<balance<<endl;
    }
};
 

int BankAccount::nextAccountNumber=1001;
int BankAccount::totalAccounts=0;
 
    // your code




/*
    Exercise-3: One instance Class

    Create a C++ program that implements a  class, 
    which ensures that only one instance(object) of the class can be created. 
*/
class OnlyOneInstance{
private:
    static OnlyOneInstance* instance;
    OnlyOneInstance(){
        cout<<"OnlyOneInstance created."<<endl;
    }
 
public:
    OnlyOneInstance(const OnlyOneInstance&);
    static OnlyOneInstance* getInstance(){
        if(instance==nullptr){
            instance=new OnlyOneInstance();
        }
        return instance;
    }
};
 




/*
    Exercise-4: Prime Number Caching

    Objective:
    Write a C++ program that efficiently generates and caches prime numbers up to 100 and allows you to query the cached prime numbers.

    Requirements:
    1. Implement a function that generates prime numbers up to 100(e.g., generatePrimes(int limit)).
    2. Cache the generated prime numbers for quick retrieval.
    4. Create a menu-driven user interface to interact with the caching system.
    5. Generate and cache prime numbers up to a specified limit.
    6. Check if a number is prime using the cached data.
*/
const int maxlim=100;
static int primes[maxlim+1];
static bool cached=false;

void generateAndCachePrimes(int limit){
    if(limit>maxlim){
        limit=maxlim;
    }
    for (int i=0; i<=limit; i++){
        primes[i]=1;
    }
    primes[0]=0;
    if(limit>=1){
        primes[1]=0;
    }
    for(int i=2; i<=limit; i++){
        if(primes[i]==1){
            for(int j=i*2; j<=limit; j=j+i){
                primes[j]=0;
            }
        }
    }
    cached=true;
}

bool isPrimeCached(int number){
    if (cached==false){
        generateAndCachePrimes(maxlim);
    }
    if (number< 0 || number>maxlim){
        return false;
    }
    return primes[number]==1;
}   





int main() {
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

    // Display the total number of accounts created.
    std::cout << "Total Accounts Created: " << BankAccount::totalAccounts << std::endl;

    return 0;
}









int main() {

    //  Exercise-1: example usage
    double price1 = trackStockPrice("AAPL", 150.25);
    cout << "Highest AAPL Stock Price: $" << price1 << endl;

    double price2 = trackStockPrice("GOOGL", 2700.50);
    cout << "Highest GOOGL Stock Price: $" << price2 << endl;

    double price3 = trackStockPrice("AAPL", 155.75);
    cout << "Highest AAPL Stock Price: $" << price3 << endl;

    double price4 = trackStockPrice("TSLA", 800.00);
    cout << "Highest TSLA Stock Price: $" << price4 << endl;



    //  Exercise-2: example usage
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

    // Display the total number of accounts created.
    cout << "Total Accounts Created: " << BankAccount::totalAccounts << endl;



    // Exercise-3: example usage
    // your code ;-)



    // Exercise-4: example usage
    // your code ;-)


}