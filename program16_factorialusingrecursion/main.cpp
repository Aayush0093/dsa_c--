//
//  main.cpp
//  program16_factorialusingrecursion
//
//  Created by Aayush Tyagi on 08/05/24.
//

#include <iostream>
using namespace std;

long fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<fact(15)<<endl;
    return 0;
}
