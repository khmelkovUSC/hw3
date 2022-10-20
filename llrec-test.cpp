#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
// Functor that returns true if input is an odd integer
struct functor {
    bool operator() (int val) const {
        if (val % 2 == 0) return false;
        else return true;
    }
};




int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    // Test llpivot
    Node* small;
    Node* large;
    llpivot(head, small, large, 7);

    cout << "head: ";
    // Expected output: none
    print(head);

    cout << "smaller: ";
    // Expected output: 1 2 3 4 5 6 7
    print(small);

    cout << "larger: ";
    // Expected output: 8 9 10 11
    print(large);


    // Test llfilter
    Node* filter_result = llfilter(small, functor());

    cout << "filtered: ";
    // Expected output: 2 4 6
    print(filter_result);

    // Deallocate remaining accessible nodes
    dealloc(filter_result);
    dealloc(large);
    
    return 0;

}
