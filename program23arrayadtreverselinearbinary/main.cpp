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
    explicit Array(int cap=10);
    ~Array();
    int Max();
    int Min();
    int Sum();
    float Average();
    void Append(T ele);
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
    void copyReverse();
    void Reverse();
    void linearSearch(int key);
    void optimizedLinearSearch(int key);
    int iterativeBinarySearch(int key);
    int recursiveBinarySearch(int high,int low,int key);
    void leftShift();
    void rightShift();
    void leftRotate();
    void rightRotate();
    int divideBinarySearch(int high,int low,int key);
    void minmaxInOneScan();
    int minMergetoPalindrome();
    void positiveMissing();
    void subArrayswithZeroSum();
};

template<class T>
void Array<T>::subArrayswithZeroSum() {
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == 0) {
                cout << "Sub-Array [" << i <<" to " << j << "]\n";
            }
        }
    }
}

template<class T>
void Array<T>::positiveMissing() {
    int max=Max();
    if(max>0){
        T *temp=new T[max];
        for(int i{};i<max;i++)
            temp[i]=0;
        for(int i{};i<size;i++){
            if(arr[i]>=0){
                temp[arr[i]]++;
            }
        }
        for(int i{};i<max;i++){
            if(temp[i]==0){
                cout<<"Missing "<<i<<endl;
            }
        }
    }
    else
        throw Exception("Max is negative no positive number missing.");
}

template<class T>
int Array<T>::minMergetoPalindrome() {
    int i=0,j=size-1;
    int count=0;
    while(i<j) {
        if (arr[i] < arr[j]){
            arr[i+1]+=arr[i];
            i++;
            count++;
        }
        else if(arr[i]>arr[j]){
            arr[j-1]+=arr[j];
            j--;
            count++;
        }
        else{
            i++;
            j--;
        }
    }
    return count;
}

template<class T>
void Array<T>::minmaxInOneScan() {
    int min,max;
    min=max=arr[0];
    for(int i{};i<size;i++){
        if(arr[i]<min)
            min=arr[i];
        else
            max=arr[i];
    }
    cout<<"Min : "<<min<<" Max: "<<max;
}

template<class T>
int Array<T>::divideBinarySearch(int high,int low,int key) {
    if(low==high){
        if(arr[low]==key)
            return low;
        else
            return -1;
    }
    else{
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid+1;
        else if(arr[mid]<key)
            return(high,mid+1,key);
        else
            return(mid-1,low,key);
    }
}

template<class T>
void Array<T>:: rightRotate(){
    int temp=arr[size-1];
    int i=0;
    for(i=size-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;
}

template<class T>
void Array<T>:: leftRotate(){
    int temp=arr[0];
    int i=0;
    for(i=1;i<size;i++)
        arr[i-1]=arr[i];
    arr[i-1]=temp;
}

template<class T>
void Array<T>::rightShift() {
    for(int i=size-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=0;
}

template<class T>
void Array<T>::leftShift(){
    for(int i=1;i<size;i++){
        arr[i-1]=arr[i];
    }
    size--;
}

template<class T>
int Array<T>::recursiveBinarySearch(int high,int low,int key) {

    int mid=(low+high)/2;

    if(low<=high){
        if(arr[mid]==key)
            return mid;
        else if(key<arr[mid])
            return recursiveBinarySearch(mid-1,low,key);
        else
            return recursiveBinarySearch(high,mid+1,key);
    }
    return -1;
}

template<class T>
int Array<T>::iterativeBinarySearch(int key){
    int high = size-1;
    int low = 0;
    int mid = 0;

    while(low<=high){
        mid=(low+high)/2;

        if(key==arr[mid])
            return mid;
        else if(key<arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

template<class T>
void Array<T>::optimizedLinearSearch(int key) {
    int flag=0;
    int i;
    for (i=0;i<size;i++) {
        if(arr[i]==key){
            flag=1;
            int temp;
            temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            break;
        }
    }
    if(flag==1)
        cout<<"Element Searched at "<<i+1<<endl;
    else
        throw Exception("Element does not exists.");
}

template<class T>
void Array<T>::linearSearch(int key) {
    int flag=0;
    int i;
    for (i=0;i<size;i++) {
        if(arr[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"Element Searched at "<<i+1<<endl;
    throw
        Exception("Element does not exists.");
}

template<class T>
void Array<T>::Reverse(){
    int i=0,j=size-1;
    while(i<=j){
        int temp;
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

template<class T>
void Array<T>::copyReverse() {
    T *temparray = new T[size];

    //copy
    for(int i=size-1,j=0;i>=0,j<size;i--,j++){
        temparray[j]=arr[i];
    }

    for(int i{};i<size;i++)
        arr[i]=temparray[i];

}

template<class T>
void Array<T>::Append(T ele){
    if(isFull()) throw Exception("Array is Full");
    else{
        arr[size]=ele;
        size++;
    }
}

template<class T>
float Array<T>::Average(){
    int sum = Sum();
    float average = float(sum)/size;
    return average;
}

template<class T>
int Array<T>::Sum() {
    if(isEmpty()) throw Exception("Array is Empty");
    else{
        int sum=0;
        for(int i = 0; i<size;i++){
            sum+=arr[i];
        }
        return sum;
    }
    return -1;
}

template<class T>
int Array<T>::Min(){
    if(isEmpty()) throw Exception("Array is Empty");
    else{
        int min=arr[0];
        for(int i = 1; i<size;i++){
            if(min<arr[i]) min=arr[i];
        }
        return min;
    }
    return -1;
}

template<class T>
int Array<T>::Max(){
    if(isEmpty()) throw Exception("Array is Empty");
    else{
        int max=arr[0];
        for(int i = 1; i<size;i++){
            if(max<arr[i]) max=arr[i];
        }
        return max;
    }
    return -1;
}

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

//        cout<<"=============subArrays with 0 Sum"<<endl;
//        a.subArrayswithZeroSum();

//        cout<<"=============Positive Missing Numbers"<<endl;
//        a.positiveMissing();

//        cout<<"=============Min counts to merge array to make palindrome"<<endl;
//        cout<<a.minMergetoPalindrome();

//        cout<<"=============Max and Min in one scan"<<endl;
//        a.minmaxInOneScan();

//        cout<<"=============divideBinarySearch"<<endl;
//        cout<<a.divideBinarySearch(a.Length()-1,0,2);
//        cout<<endl;

//        cout<<"=============rightRotate"<<endl;
//        a.rightRotate();
//        a.Display();
//        cout<<endl;

//        cout<<"=============leftRotate"<<endl;
//        a.leftRotate();
//        a.Display();
//        cout<<endl;

//        cout<<"=============rightShift"<<endl;
//        a.rightShift();
//        a.Display();
//        cout<<endl;

//        cout<<"=============leftShift"<<endl;
//        a.leftShift();
//        a.Display();
//        cout<<endl;

//        cout<<"=============recursiveBinary Search"<<endl;
//        //have elements in sortedorder
//        cout<<a.recursiveBinarySearch((a.Length()-1),0,3)<<endl;
//        cout<<a.recursiveBinarySearch((a.Length()-1),0,15)<<endl;
//        cout<<endl;

//        cout<<"=============iterativeBinary Search"<<endl;
//        cout<<a.iterativeBinarySearch(3)<<endl;
//        cout<<a.iterativeBinarySearch(15)<<endl;
//        cout<<endl;

//        cout<<"=============Optimized Linear Search"<<endl;
//        a.optimizedLinearSearch(3);
//        a.Display();
//        cout<<endl;

//        cout<<"=============Linear Search"<<endl;
//        a.linearSearch(3);
//        a.linearSearch(15);
//        cout<<endl;

//        cout<<"=============Reverse"<<endl;
//        a.Reverse();
//        a.Display();
//        cout<<endl;

//        cout<<"=============Copy Reverse"<<endl;
//        a.copyReverse();
//        a.Display();
//        cout<<endl;

//        cout<<"=============Deletion and Display"<<endl;
//        int del;
//        a.Delete(1,del);
//        a.Display();
//        cout<<endl<<endl;
//
//        cout<<"=============Get and Set"<<endl;
//        cout<<a.Get(2)<<endl;
//        a.Set(2, 10);
//        a.Display();
//        cout<<endl;
//
//        cout<<"=============Find"<<endl;
//        int find=0;
//        cout<<a.Find(2,find)<<" "<<find<<endl;
//        cout<<endl;
//
//        cout<<"=============Search"<<endl;
//        cout<<a.Search(2)<<endl;
//        cout<<endl;
//
//        cout<<"=============Length and Index of"<<endl;
//        cout<<"Length is : "<<a.Length()<<endl;
//        cout<<a.indexOf(2)<<endl;
//        cout<<endl;
//
//        cout<<"=============Max and Min"<<endl;
//        cout<<a.Max()<< " and " << a.Min()<<endl<<endl;
//
//        cout<<"=============Sum and Average"<<endl;
//        cout<<a.Sum()<< " and " << a.Average()<<endl<<endl;
//
//        cout<<"=============Append and Display"<<endl;
//        a.Append(10);
//        a.Display();
//        cout<<""<<endl<<endl;

    }catch(Exception e){
        e.output();
    }
    return 0;
}

