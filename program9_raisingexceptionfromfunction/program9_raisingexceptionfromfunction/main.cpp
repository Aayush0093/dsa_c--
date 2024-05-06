//
//  main.cpp
//  program9_raisingexceptionfromfunction
//
//  Created by Aayush Tyagi on 06/05/24.
//

#include <iostream>
using namespace std;

class exception_raise {
    int x , y;
public:
    exception_raise(int x , int y){
        this->x=x; this->y=y;
    }
    
    int Division(int x , int y){
        if (y==0) {
            throw 404;
        }
        return x/y;
    }
    
    void divi(){
        try{
            int z = Division(x,y);
            cout << z << " is result." << endl;
        }catch(int i){
            cout << "Exception"<< endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    exception_raise(10, 0).divi();
    
    return 0;
}
