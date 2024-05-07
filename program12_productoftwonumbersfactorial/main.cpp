//
//  main.cpp
//  program12_productoftwonumbersfactorial
//
//  Created by Aayush Tyagi on 07/05/24.
//

#include <iostream>
using namespace std;

int prod(int a,int b){
    if(a==0) return 0;
    else if(b==0) return 0;
    else return prod(a,b-1)+a;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<prod(4,5)<<endl;
    return 0;
}
