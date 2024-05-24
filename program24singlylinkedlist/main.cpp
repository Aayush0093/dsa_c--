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
    SinglyLinkedList();
//    ~SinglyLinkedList();
    void Insert(int pos,T ele);
    void Delete(int pos,T &ele);
    int Length();
    void Display();
    bool Find(int pos,T &ele);
    int Search(T ele);
    bool isEmpty();
};

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

    //Insert
    for(int i=1;i<=5;i++)
        sll.Insert(i,i);

    //Display
    sll.Display();

    //Delete
    for (int i=0;i<2;i++) {
        int ele;
        sll.Delete(i+2,ele);
        cout<<"Deleted Element: "<<ele<<endl;
        sll.Display();
    }

    //Length
    cout<<"Length: "<<sll.Length()<<endl;

    //Find
    int ele;
    cout<<"Find: "<<sll.Find(2,ele)<<endl;
    cout<<"Find: "<<sll.Find(4,ele)<<endl;

    //Search
    cout<<"Search: "<<sll.Search(3)<<endl;

    //isEmpty
    cout<<"isEmpty: "<<sll.isEmpty()<<endl;

    return 0;
}
