//
//  main.cpp
//  program10_raisinguserdefineexception
//
//  Created by Aayush Tyagi on 06/05/24.
//

#include <iostream>
using namespace std;

class myexception{
public:
    myexception(){cout<<"Exception divide by zero"<<endl;}
};

class raise {
    int x , y;
    
public:
    raise(int x,int y){this->x=x;this->y=y;}
    int divi(int x,int y){ if(y==0)throw myexception();return x/y;}
    void Divi(){
        try{ int z = divi(x,y); cout << z << "Result" << endl; }
        catch(myexception){}
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    raise(10,0).Divi();
    return 0;
}
