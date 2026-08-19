#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

/*
    1. Preorder, Inorder, Postorder traversals using numbers
    2. Tree common operations (insert, search, traverse, delete node)
    3. Tree traversals (preorder, inorder, postorder, level order)
    4. Identify mistakes in using recursion where it can be avoided (no need for insertion, no need for node deletion).
    5. Tree Complexity
    6. Applications
    7. What about Heap Data Structure (DSA)?

    Tree Traversal Source:    https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
    Insert Node Source:       https://www.javatpoint.com/insertion-in-binary-search-tree
    Delete Node Source:       https://www.interviewbit.com/blog/delete-node-from-binary-search-tree/
    Binary Tree Applications: https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-binary-tree/
*/


struct Node {
    int data;
    Node *left;
    Node *right;
};


class BinaryTree {
    private:
        int height;
        Node *root;

        // method utilities
        void printTree(const vector<const Node *const> &) const;
        void destroyTree(const Node *const);

    public:
        BinaryTree();
        ~BinaryTree();

        BinaryTree& insert(const int &);

        void display() const;

        void preorder(const Node *) const;    // Root -> Left -> Right 
        void inorder(const Node *) const;     // Left -> Root -> Right
        void postorder(const Node *) const;   // Left -> Right -> Root

        void levelorder() const;

        bool search(const int &) const;
        void deleteNode(const int &);
};

/* Your Solution */



int main() {

    BinaryTree tree = BinaryTree();

    cout << endl;
    tree.display();  

    // Ex-1: tree.insert(5).insert(3).insert(8).insert(6).insert(2).insert(4).insert(9).insert(7);
    // Ex-2: https://www.javatpoint.com/insertion-in-binary-search-tree
    tree.insert(50).insert(25).insert(75).insert(12).insert(30).insert(60).insert(85).insert(52).insert(70);
    // Ex-3: tree.insert(2).insert(1).insert(33).insert(0).insert(25).insert(40).insert(11).insert(34).insert(7).insert(12).insert(36).insert(13);

    cout << endl;
    tree.display();  
    cout << endl;

    cout << (tree.search(13) ? "[13 found]" : "[13 not found]") << endl << endl;

    tree.deleteNode(52);
    tree.deleteNode(70);

    cout << endl;
    tree.display();  
    cout << endl;

    // Tree traversals (preorder, inorder, postorder, levelorder)
    cout << "Preorder:   ";
    tree.preorder();
    cout << endl;

    cout << "Inorder:    ";
    tree.inorder();
    cout << endl;

    cout << "Postorder:  ";
    tree.postorder();
    cout << endl;

    cout << "Levelorder: " << endl;
    tree.levelorder();
    cout << endl;
  
  
  	/*
    	------------------------ Output	------------------------
        
        Tree is empty

        Tree height: 3

                            50

                     25             75

               12       30       60       85

                               52   70          

        [13 not found]

        Leaf Node: 52
        Leaf Node: 70

        Tree height: 2

                       50

                 25         75

             12     30     60     85

        Preorder:   50 -> 25 -> 12 -> 30 -> 75 -> 60 -> 85
        Inorder:    12 -> 25 -> 30 -> 50 -> 60 -> 75 -> 85
        Postorder:  12 -> 30 -> 25 -> 60 -> 85 -> 75 -> 50
        Levelorder: 
        Tree height: 2

                       50

                 25         75

             12     30     60     85

        [call of destructor]
         Delete: 12
         Delete: 30
         Delete: 25
         Delete: 60
         Delete: 85
         Delete: 75
         Delete: 50
    */

    return 0;
}