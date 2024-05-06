//
//  main.cpp
//  program8_exceptionhandlingabruptfailure
//
//  Created by Aayush Tyagi on 06/05/24.
//

#include <iostream>
using namespace std;

class exception_handling{
    int x , y , z ;
public:
    exception_handling(int x , int y){
        this->x=x; this->y=y;
    }
    
    void divi(){
        try{
            if (y==0) {
                throw 404;
            }
            z=x/y;
            cout << "Division of x and y is " << z << endl;
        }
        catch(int i){
            cout << "Exception" << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    exception_handling e(10, 0);
    e.divi();
    return 0;
}
