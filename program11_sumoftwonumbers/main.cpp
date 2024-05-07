//
//  main.cpp
//  program11_sumoftwonumbers
//
//  Created by Aayush Tyagi on 07/05/24.
//

#include <iostream>
using namespace std;

int sum(int a,int b){
    if(a==0) return b;
    else if(b==0) return a;
    else return sum(a,b-1)+1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << sum(3,4) << endl;
    
    return 0;
}
