//
//  main.cpp
//  program20_arrayadtpart1
//
//  Created by Aayush Tyagi on 10/05/24.
//

#include <iostream>
using namespace std;

class Array{
    int *array;
    int capacity;
    int size;
    
public:
    Array(int Capacity=10);
    ~Array();
    bool isFull();
    bool isEmpty();
    int sizeOfArray();
    friend istream& operator>> (istream &is,Array &a);
    friend ostream& operator<< (ostream &os,Array &a);
};

ostream& operator<< (ostream &os , Array &a){
    for (int i{};i<a.size; i++) {
        cout<<a.array[i]<< " ";
    }
    cout << endl;
    return os;
}

istream& operator>> (istream &is ,Array &a){
    cout<<"Enter element to be inserted : ";
    cin >> a.array[a.size++];
    return is;
}

int Array:: sizeOfArray(){ return size;}

bool Array:: isEmpty(){
    if(size==0) return true;
    return false;
}

bool Array:: isFull(){
    if (size==capacity-1) return true;
    return false;
}

Array :: ~Array(){
    delete [] array;
}

Array :: Array(int Capacity){
    capacity=Capacity;
    array = new int[capacity];
    size=0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Array a(8);
    cout<<"Enter how many elements : ";
    int num;
    cin >> num;
    
    for (int i{}; i<num; i++) {
        cin>>a;
    }
    
    cout<<a<<endl;
    cout << a.sizeOfArray()<<endl;
    
    return 0;
}
