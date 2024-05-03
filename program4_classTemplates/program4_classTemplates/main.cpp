//
//  main.cpp
//  program4_classTemplates
//
//  Created by Aayush Tyagi on 03/05/24.
//

#include <iostream>
using namespace std;

template <class T>
class myPair {
    T a , b;
    
public:
    myPair(T a, T b){
        this->a = a;
        this->b = b;
    }
    T getMax();
};

template <class T>
T myPair<T> :: getMax(){
    if (a>b) {
        return a;
    } else {
        return b;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    myPair<int> p(10, 20);
    
    myPair<float> p1(10.2, 20.3);
    
    cout << p.getMax() << endl;
    cout << p1.getMax() << endl;
    
    return 0;
}
