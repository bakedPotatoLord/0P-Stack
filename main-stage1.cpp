/*
 * main-stage1.cpp
 *
 * Includes the main() function for the stack project (stage 1).
 *
 * This code is included in the build target "run-stage1-main", and
 * in the convenience target "stage1".
 */

#include <iostream>

#include "stack-stage1.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or initial testing code.
    cout << "If you are seeing this, you are a bozo" << endl;

    stack s;

    s.push("hello");
    s.push("world");

    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    return 0;
}
