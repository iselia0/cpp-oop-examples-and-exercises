#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:    
        Node *head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void insert(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            cout << value << endl;
        }

        void display(){
            Node *temp = head;
            while(temp != nullptr){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        bool search(int value){
            Node *temp = head;
            while(temp != nullptr && temp->data != value){
                temp = temp->next;
            }
            return temp != nullptr;
        }
        void remove(int value){
            Node *temp = head;
            while(temp != nullptr){
                head = temp->next;
                delete temp;
                temp = head;
            }
        }

        void append(int value){
            Node *newNode = new Node();
            newNode->data = value;

            if(head == nullptr){
                head = newNode;
            } else{
                Node *temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        ~LinkedList(){
            Node *temp = head;

            while(temp != nullptr){
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr;
        }
};

int main (){
    system("clear");

    LinkedList list = LinkedList();

    list.append(1).append(2).append(3).append(4);
    
    list.display();

    list.insert(5).display();

    bool isFound = list.search(4);

    cout << std::boolalpha << endl;
    cout << isFound;
    cout << endl << endl;

    list.remove(3).display().remove(4).display().remove(5).display();

    cout << endl;

}