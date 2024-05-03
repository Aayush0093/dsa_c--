//
//  main.cpp
//  program6_templateSpecialisation
//
//  Created by Aayush Tyagi on 03/05/24.
//

#include <iostream>
using namespace std;

template <class T>
class Increase {
    T element;
    
public:
    Increase(T par){this->element=par;}
    T increase(){ return ++element;}
};

template<>
class Increase<char> {
    char element;
    
public:
    Increase(char element){ this->element=element;}
    char uppercase(){
        if (element>='a' && element<='z') {
            element-=32;
            return element;
        } else {
            return 'N';
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Increase<int> i(1);
    cout<<i.increase()<<endl;
    Increase<float> f(1.5);
    cout<<f.increase()<<endl;
    Increase<char> c('n');
    cout<<c.uppercase()<<endl;
    
    return 0;
}
