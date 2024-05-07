//
//  main.cpp
//  program15_fibonaccifactorial
//
//  Created by Aayush Tyagi on 07/05/24.
//

#include <iostream>
using namespace std;

int fib(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else return fib(n-1)+fib(n-2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<fib(5)<<endl;
    return 0;
}
