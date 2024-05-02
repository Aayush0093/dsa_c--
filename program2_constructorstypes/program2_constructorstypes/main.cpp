//
//  main.cpp
//  program2_constructorstypes
//
//  Created by Aayush Tyagi on 02/05/24.
//

#include <iostream>
using namespace std;

class Rectangle{
    private:
        int breadth;
        int length;
    public :
        Rectangle(); // default
        Rectangle(int,int); // parameterised
        Rectangle(Rectangle &); // copy
    
        void display();
    
};

Rectangle :: Rectangle(){ length=0; breadth=0;}
Rectangle :: Rectangle(int l, int b){
    length=l; breadth=b;
}
Rectangle :: Rectangle(Rectangle &r){
    length=r.length; breadth=r.breadth;
}
void Rectangle :: display(){
    cout << "Length is " << length << " and Breadth is " << breadth << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Rectangle r;
    r.display();
    
    Rectangle r1(10,10);
    r1.display();
    
    Rectangle r2(r1);
    r2.display();
    
    return 0;
}
