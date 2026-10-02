/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include <iostream>

#include "stack-stage3.h"

using namespace std;




int main() {
    // You can use this main() to run your own analysis or initial testing code.
    const int trialcount = 10;
    
    cout << "standard stack" << endl;
    for(int i = 10000 ;i<=100000;i+=10000){
        double acc = 0.0;
        for(int j = 0 ;j<trialcount;j++){
            acc += time_n_pushes(i);
        }
        cout << acc/trialcount << endl;
    }

    cout << "bad stack" << endl;
    for(int i = 10000 ;i<=100000;i+=10000){
        double acc = 0.0;
        for(int j = 0 ;j<trialcount;j++){
            acc += time_n_pushes_bad(i);
        }
        cout << acc/trialcount << endl;
    }
    
    return 0;
}
