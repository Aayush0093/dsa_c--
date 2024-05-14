//
//  main.cpp
//  program21_arraysbasicoperations
//
//  Created by Aayush Tyagi on 11/05/24.
//

#include <iostream>
using namespace std;

class Exception{
private:
    string message;
public:
    Exception(string msg){
        message=msg;
    }
    void output(){
        cout<<message<<endl;
    }
};

template <class T>
class Array {
    T *arr;
    int size;
    int capacity;

public:
    Array(int cap=10);
    ~Array();
    void Insert(int pos, T ele);
    void Delete(int pos,T &ele);
    T Get(int index);
    void Set(int index,T ele);
    bool Find(int pos, T &ele);
    int Search(T ele);
    int Length();
    void Display();
    bool isEmpty();
    bool isFull();
    int indexOf(T ele);
};

template<class T>
void Array<T>::Set(int index,T ele){
    if(index<0||index>size)
        throw Exception("Wrong index");
    else if(isEmpty())
        throw Exception("Array is Empty");
    else
        arr[index]=ele;
}

template<class T>
bool Array<T>::Find(int pos,T &ele){
    bool t = false;
    ele=-1;
    if(pos<1||pos>size){}
    else if(isEmpty()){}
    else{
        ele=arr[pos-1];
        t=true;
    }
    return t;
}

template<class T>
T Array<T>::Get(int index){
    bool find = Find(index, arr[index]);
    if(find)
        return arr[index];
    else
        throw Exception("Element not found");
}

template <class T>
void Array<T>::Delete(int pos, T &ele) {
    if(pos<1 || pos>size)
        throw Exception("Wrong Position");
    else if(isEmpty())
        throw Exception("Array is Empty");
    else{
        ele=arr[pos-1];
        for(int i=pos;i<size;i++)
            arr[i-1]=arr[i];
        size--;
    }
}

template <class T>
void Array<T>::Insert(int pos,T ele) {
    int i=0;
    if(pos==1)
        arr[0]=ele;
    else if(isFull())
        throw Exception("Array full cant insert");
    else if(pos<1||pos>size+1)
        throw Exception("Wrong position.");
    else{
        for (i=size-1; i>=pos-1; i--) {
            arr[i+1]=arr[i];
        }
        arr[i+1]=ele;
    }
    size++;
}

template <class T>
int Array<T>::indexOf(T ele) {
    if (Search(ele)<0)
        throw Exception("Wrong number(doesn't exists.)");
    int x=Search(ele);
    return x;
}

template <class T>
int Array<T>:: Search(T ele) {
    for (int i{}; i<size; i++) {
        if (arr[i]==ele) {
            return i;
            break;
        }
    }
    return -1;
}

template <class T>
bool Array<T>:: isEmpty() {
    return size==0?true:false;
}

template<class T>
bool Array<T>:: isFull(){
    return size==(capacity-1)?true:false;
}

template <class T>
void Array<T>::Display() {
    if(size!=0) {
        for (int i{}; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }else
        throw Exception("Array is Empty");
}

template <class T>
int Array<T> :: Length() { return size; }

template <class T>
Array<T>:: ~Array() {
    delete [] arr;
}

template <class T>
Array<T>::Array(int cap){
    if(cap<=0)
        throw Exception("Array cannot be created.");
    capacity=cap;
    arr = new T[capacity];
    size=0;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    try{
        Array<int> a(7);

        cout<<"=============Insertion"<<endl;
        a.Insert(1,0);
        a.Insert(2,1);
        a.Insert(3, 2);
        a.Insert(4,3);
        a.Insert(5,5);
        a.Insert(5,4);
        a.Display();
        cout<<endl<<endl;

        cout<<"=============Deletion and Display"<<endl;
        int del;
        a.Delete(1,del);
        a.Display();
        cout<<endl<<endl;

        cout<<"=============Get and Set"<<endl;
        cout<<a.Get(2)<<endl;
        a.Set(2, 10);
        a.Display();
        cout<<endl;

        cout<<"=============Find"<<endl;
        int find=0;
        cout<<a.Find(2,find)<<" "<<find<<endl;
        cout<<endl;

        cout<<"=============Search"<<endl;
        cout<<a.Search(2)<<endl;
        cout<<endl;

        cout<<"=============Length and Index of"<<endl;
        cout<<"Length is : "<<a.Length()<<endl;
        cout<<a.indexOf(2)<<endl;
        cout<<endl;

    }catch(Exception e){
        e.output();
    }
    return 0;
}

