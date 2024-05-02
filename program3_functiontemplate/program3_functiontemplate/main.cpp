//
//  main.cpp
//  program3_functiontemplate
//
//  Created by Aayush Tyagi on 02/05/24.
//

#include <iostream>
using namespace std;

template <class T>
T getMax(T a , T b){
    if(a>b)
        return a;
    else
        return b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x = 10 , y = 20; cout << getMax(x, y) << endl;
    float x1 = 10.2 , y1 = 20.3; cout << getMax(x1, y1) << endl;
    
    return 0;
}
