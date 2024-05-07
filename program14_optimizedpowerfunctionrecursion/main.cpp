//
//  main.cpp
//  program14_optimizedpowerfunctionrecursion
//
//  Created by Aayush Tyagi on 07/05/24.
//

#include <iostream>
using namespace std;

int optpower(int a,int b){
    if(b==0) return 1;
    int temp = optpower(a, b/2);
    int po = temp*temp;
    if(b%2!=0) return a*po;
    return po;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<optpower(2, 4)<<endl;
    return 0;
}
