#include "stack.h"
#include <iostream>

void testPop(Stack<int> &s);

int main() {

    Stack<int> test;

    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);

    testPop(test);
    testPop(test);
    testPop(test);
    testPop(test);
    testPop(test);


    // Will cause std::underflow_error as intended
    // testPop(test);
    // testPop(test);
    // test.pop();
}

void testPop(Stack<int> &s) {
    using namespace std;
    cout << "size: " << s.size() << endl;
    cout << "empty: " << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
}