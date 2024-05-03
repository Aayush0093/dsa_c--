//
//  main.cpp
//  program7_parameterpassingtypes
//
//  Created by Aayush Tyagi on 03/05/24.
//

#include <iostream>
using namespace std;

class swapinstance {
public:
    void swap1(int,int);
    void swap2(int *,int *);
    void swap3(int &,int &);
};

void swapinstance::swap3(int &p, int &q){
    int temp; temp=p; p=q; q=temp;
}

void swapinstance::swap2(int *p, int *q){
    int temp; temp=*p; *p=*q; *q=temp;
}

void swapinstance::swap1(int a,int b){
    int temp; temp=a; a=b; b=temp;
}

int main(int argc, const char * argv[]) {

    int a = 10 , b = 20;
    
    swapinstance s;
    
    cout << "=======1=======" << endl;
    s.swap1(a,b);
    cout << a << " " << b << endl << "===============" << endl << endl;
    
    cout << "=======2=======" << endl;
    s.swap2(&a,&b);
    cout << a << " " << b << endl << "===============" << endl << endl;
    s.swap2(&a, &b);
    
    cout << "=======3=======" << endl;
    s.swap3(a,b);
    cout << a << " " << b << endl << "===============" << endl << endl;
    
    return 0;
}
