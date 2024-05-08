//
//  main.cpp
//  program18_gcdrecursionmodulo
//
//  Created by Aayush Tyagi on 08/05/24.
//

#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(a%b==0) return b;
    else if(b%a==0) return a;
    else if(a>b) return gcd(a%b,b);
    else return gcd(a,b%a);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<gcd(11,7)<<endl;
    return 0;
}
