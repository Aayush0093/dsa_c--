#include <iostream>
using namespace std;

template<class T>
class Node{
public:
    T data;
    Node<T>* link;
};

template<class T>
class SinglyLinkedList{
private:
    Node<T>* first;
    Node<T>* last;
    int length;
public:
    Node<T>* getFirst() {
        return first;
    }
    SinglyLinkedList();
    SinglyLinkedList(Node<T>* , Node<T>* , int len);
//    ~SinglyLinkedList();
    void Insert(int pos,T ele);
    void Delete(int pos,T &ele);
    int Length();
    void Display();
    bool Find(int pos,T &ele);
    int Search(T ele);
    bool isEmpty();
    void concatenate(Node<T>* , Node<T> *);
    void Merge(SinglyLinkedList<T>*, SinglyLinkedList<T>*);
    void ReverseuseArray();
    void Reverse();
};

template<class T>
void SinglyLinkedList<T>::Reverse() {

    Node<T> *p , *q , *r;

    p=first;
    q=NULL;
    r=NULL;

    while(p!=NULL){
        r=q;q=p;p=p->link;
        q->link=r;
    }

    first=q;

}

template<class T>
void SinglyLinkedList<T> :: ReverseuseArray(){
    Node<T>* p = first;

    T* arr = new T[length-1];

    int i = 0;
    while(p!=NULL){
        arr[i] = p->data;
        p = p->link;
        i++;
    }

    p = first;

    i--;

    while(p!=NULL){
        p->data = arr[i];
        p = p->link;
        i--;
    }
}

template<class T>
SinglyLinkedList<T> :: SinglyLinkedList(Node<T>* , Node<T>* , int len){
    first = NULL;
    last = NULL;
    length = len;
}

template<class T>
void SinglyLinkedList<T>::Merge(SinglyLinkedList<T>* fir,SinglyLinkedList <T> * sec){
    Node<T>* p = fir->first;
    Node<T>* q = sec->first;
    Node<T>* r;

    if(p->data<q->data){
        first=r=p;
        p=p->link;
        first->link=NULL;
    }
    else if(p->data>q->data){
        first=r=q;
        q=q->link;
        first->link=NULL;
    }
    while(p!=NULL && q!=NULL){

        if(p->data<q->data){
            r->link=p;
            r=p;
            p=p->link;
            r->link=NULL;
        }
        else{
            r->link=q;
            r=q;
            q=q->link;
            r->link=NULL;
        }
    }

    if(p!=NULL)
        r->link=p;
    else
        r->link=q;

}

template<class T>
void SinglyLinkedList<T>::concatenate(Node<T> *first, Node<T> *second) {

    if(first!=NULL && second!=NULL){
        Node<T> * p= first;
        while(p->link!=NULL)
            p=p->link;
        p->link=second;
    }

}

template<class T>
int SinglyLinkedList<T>::Search(T ele) {
    Node<T>* p = first;
    int pos=1;
    while(p!=NULL){
        if(p->data==ele)
            return pos;
        p=p->link;
        pos++;
    }
    return -1;
}

template<class T>
bool SinglyLinkedList<T>::Find(int pos, T &ele) {
    Node<T>* p = first;
    if(p==NULL)
        return false;
    else{
        for(int i=1;i<pos;i++){
            p=p->link;
            if(p==NULL)
                return false;
        }
        ele=p->data;
        return true;
    }
}

template<class T>
void SinglyLinkedList<T>::Delete(int pos, T &ele) {
    Node<T> *p = first;
    Node<T> *q = NULL;
    if(p==NULL)
        cout<<"List is Empty"<<endl;
    else{
        length--;
        //first
        if(pos==1){
            if(Length()==1){
                ele=p->data;
                delete p;
                p = NULL;
            }
            else{
                ele = p->data;
                first=first->link;
                delete p;
                p = NULL;
            }
        }
            //last
        else if (pos==Length()){
            while(p->link!=NULL){
                q=p;
                p=p->link;
            }
            ele=p->data;
            q->link=NULL;
            delete p;
            p = NULL;
        }
            //middle
        else{
            for(int i=0;i<pos-1;i++){
                q=p;
                p=p->link;
            }
            ele=p->data;
            q->link=p->link;
            delete p;
            p = NULL;
        }
    }
}

template<class T>
int SinglyLinkedList<T>::Length() {
    return length;
}

template<class T>
void SinglyLinkedList<T>::Display(){
    Node<T>* p = first;
    if(p==NULL)
        cout<<"List is Empty"<<endl;
    else{
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->link;
        }
        cout<<endl;
    }
}

template<class T>
void SinglyLinkedList<T>::Insert(int pos, T ele){
    Node<T> *temp = new Node<T>;
    temp->data=ele;
    temp->link=NULL;

    if(pos==1){
        if(first==NULL){
            first=last=temp;
        }
        else{
            temp->link=first;
            first=temp;
        }
    }
    else if(pos==(Length()+1)){
        last->link=temp;
        last=temp;
    }
    else{
        Node<T>* p=first;
        for(int i=1;i<pos-1;i++)
            p = p->link;

        temp->link=p->link;
        p->link=temp;
    }
    length++;
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    first=NULL;
    last=NULL;
    length=0;
}

template<class T>
bool SinglyLinkedList<T>::isEmpty() {
    return first==NULL;
}

int main() {

    SinglyLinkedList<int> sll;

//    //Insert one
//    sll.Insert(1,1);
//    sll.Insert(2,3);
//    sll.Insert(3,7);
//    sll.Insert(4,11);
//
//    //Display one
//    sll.Display();
//
//    //Reverse
//    sll.Reverse();
//    sll.Display();

//    //Reverse using array copying
//    sll.ReverseuseArray();
//    sll.Display();

//    SinglyLinkedList<int> sll2;

//    //Insert two
//    sll2.Insert(1,2);
//    sll2.Insert(2,6);
//    sll2.Insert(3,8);
//    sll2.Insert(4,12);
//
//    //Display two
//    sll2.Display();

//    //Merge
//    SinglyLinkedList<int> sll3;
//    sll3.Merge(&sll,&sll2);
//    sll3.Display();

    //Insert
//    for(int i=1;i<=5;i++)
//        sll2.Insert(i,i*10);

//    //Concatenate
//    sll.concatenate(sll.getFirst(),sll2.getFirst());
//    sll.Display();

//    //Delete
//    for (int i=0;i<2;i++) {
//        int ele;
//        sll.Delete(i+2,ele);
//        cout<<"Deleted Element: "<<ele<<endl;
//        sll.Display();
//    }
//
//    //Length
//    cout<<"Length: "<<sll.Length()<<endl;
//
//    //Find
//    int ele;
//    cout<<"Find: "<<sll.Find(2,ele)<<endl;
//    cout<<"Find: "<<sll.Find(4,ele)<<endl;
//
//    //Search
//    cout<<"Search: "<<sll.Search(3)<<endl;
//
//    //isEmpty
//    cout<<"isEmpty: "<<sll.isEmpty()<<endl;


    //name
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~       Singly Linked List       ~"<<endl;
    cout<<"~          Aayush Tyagi          ~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;

    return 0;
}
