//
//  main.cpp
//  program19_arrayresizingpointers
//
//  Created by Aayush Tyagi on 09/05/24.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int *p = new int [5];
    int *q = new int [10];
    
    for(int i {};i < 5 ; i++){
        
        q[i] = p [i];
    }
    
    delete [] p;
    p=q;
    q=NULL;
    
    for(int i {} ; i < 10 ; i++)
    cout << p[i] << " " ;
    cout<<endl;
}
