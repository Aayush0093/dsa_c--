//
//  main.cpp
//  program17_gcdrecursion
//
//  Created by Aayush Tyagi on 08/05/24.
//

#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(a==b) return a;
    else if(a>b) return gcd(a-b,b);
    else return gcd(a,b-a);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<gcd(14,7)<<endl;
    return 0;
}
