//
//  main.cpp
//  Rectangle
//
//  Created by Aayush Tyagi on 07/03/24.
//

#include <iostream>
using namespace std;

class Rectangle{
    
    int width , height;
    
    public :
    Rectangle(int,int);
    int Area();
    int get_Width();
    int get_Height();
    
};

Rectangle :: Rectangle(int width , int height){
    this->width = width;
    this->height = height;
}

int Rectangle :: Area(){
    return width*height;
}

int Rectangle :: get_Width(){
    return  width;
}

int Rectangle :: get_Height(){
    return height;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Rectangle r (10, 12);
    
    cout << "Rectangle Width : " << r.get_Width() << endl;
    cout << "Rectangl Height : " << r.get_Height() << endl;
    
    cout << "Rectangle Area  : " << r.Area() << endl;
    return 0;
}

