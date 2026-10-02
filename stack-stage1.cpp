/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Your Name
 */

#include "stack-stage1.h"

using namespace std;

stack::stack()  {
    len = 0;
    capacity = 4;
    data = new string[capacity];
}

string stack::top() {
    return data[len-1];
}

void stack::push(const string &s) {
    if (len == capacity) {
        capacity *= 2;
        string *new_data = new string[capacity];
        for (int i = 0; i < len; i++) {
            new_data[i] = data[i];
        }
        delete [] data;
        data = new_data;
    }
    data[len++] = s;
}

void stack::pop() {
    len--;
}

