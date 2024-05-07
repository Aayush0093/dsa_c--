//
//  main.cpp
//  program13_powerofaandbfactorial
//
//  Created by Aayush Tyagi on 07/05/24.
//

#include <iostream>
using namespace std;

int powero(int a,int b){
    if(b==0) return 1;
    return powero(a,b-1)*a;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<powero(3,3)<<endl;
    return 0;
}
