//
//  main.cpp
//  program5_calculatorTemplate
//
//  Created by Aayush Tyagi on 03/05/24.
//

#include <iostream>
using namespace std;

template <class T>
class Calculator {
    T num1 , num2 ;
    
public:
    Calculator(T num1,T num2){this->num1=num1; this->num2=num2;}
    T add();
    T sub();
    T mul();
    T div();
};

template <class T>
T Calculator<T>::add() {
    return num1+num2;
}

template <class T>
T Calculator<T>::sub() {
    return num1-num2;
}

template <class T>
T Calculator<T>::mul() {
    return num1*num2;
}

template <class T>
T Calculator<T>::div() {
    return num1/num2;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Calculator<int> i(10, 1);
    Calculator<float> f(10.5, 1.5);
    
    cout << "Integer 10 and 1 : " << endl << "========" << endl;
    cout << i.add() << endl << i.sub() << endl << i.mul() << endl << i.div() << endl << "========" << endl << endl;
    cout << "Float 10.5 and 1.5 : " << endl << "========" << endl;
    cout << f.add() << endl << f.sub() << endl << f.mul() << endl << f.div() << endl << "========" << endl;
    
    return 0;
}
