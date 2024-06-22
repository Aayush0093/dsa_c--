#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *link;
};

template<class T>
class cll{
private:
    Node<T> *first;
    Node<T> *last;
    int len;

public:
    cll();
    ~cll();
    void Insert(T data, int pos);
    void Delete(int pos, T &data);
    void Display();
    int Length();
    bool isEmpty();
    bool Find(T data, int &pos);
    int Search(T data);
};

template<class T>
void cll<T>::Delete(int pos, T &data) {
    Node<T> *p = first;
    if (pos == 1) {
        data = first->data;
        if (first == last) {
            delete first;
            first = NULL;
            last = NULL;
        } else {
            first = first->link;
            delete p;
            last->link = first;
        }
    }else if(pos==len){
        Node<T> *q=first;
        while(q->link!=last){
            q=q->link;
        }
        q->link=first;
        data=last->data;
        delete last;
        last=q;
    }else {
        Node<T> *q = NULL;
        for (int i = 0; i < pos - 1; i++) {
            q = p;
            p = p->link;
        }
        data = p->data;
        q->link = p->link;
        delete p;
    }
    len--;
}

template<class T>
void cll<T>::Insert(T data, int pos) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->link = NULL;
    if (pos == 1) {
        if (first == NULL) {
            first = temp;
            last = temp;
            last->link = first;
        } else {
            temp->link = first;
            first = temp;
            last->link = first;
        }
    } else if(pos==len+1){
        last->link=temp;
        last=temp;
        last->link=first;
    } else{
        Node<T> *p = first;
        for (int i = 1; i < pos - 1; i++) {
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
    len++;
}

template<class T>
bool cll<T>::Find(T data,int &pos){
    Node<T> *p = first;
    pos=0;
    do{
        pos++;
        if(p->data==data)
            return true;
        p=p->link;
    }while(p==first);
    return false;
}

template <class T>
int cll<T>::Search(T data){
    Node<T> * p = first;
    int pos=0;
    do{
        pos++;
        if(p->data==data)
            return pos;
        p=p->link;
    }while(p==first);
    return -1;
}

template<class T>
bool cll<T>::isEmpty() {
    return (first==NULL)?true:false;
}

template<class T>
int cll<T>::Length() {
    return len;
}

template<class T>
void cll<T>:: Display(){
    Node<T> *p = first;
    do{
        cout<<p->data<<" ";
        p=p->link;
    } while (p!=first);
}

template<class T>
cll<T>::~cll() {
    Node<T> *temp = first;
    while (temp != last) {
        first = first->link;
        delete temp;
        temp = first;
    }
    delete last;
}

template<class T>
cll<T>::cll() {
    first = NULL;
    last = NULL;
    len = 0;
}

void lines(){
    cout<<"====================="<<endl;
}

int main() {
    cll<int> c;

    cout<<"Is Empty: "<<c.isEmpty()<<endl;
    lines();

    cout<<"Insertion"<<endl;
    for (int i = 0; i < 5; ++i) {
        c.Insert(i+1, i+1);
    }
    lines();

    cout<<"Display"<<endl;
    c.Display();
    cout<<endl;
    lines();

    cout<<"Length: "<<c.Length()<<endl;
    lines();

    cout<<"Deletion"<<endl;
    int data;
    c.Delete(1, data);
    cout<<"Deleted: "<<data<<endl;
    c.Delete(2, data);
    cout<<"Deleted: "<<data<<endl;
    lines();

    cout<<"Display"<<endl;
    c.Display();
    cout<<endl;
    lines();

    cout<<"Find"<<endl;
    int pos;
    if(c.Find(3, pos))
        cout<<"Found: "<<c.Find(3, pos)<<" at position: "<<pos<<endl;
    else
        cout<<"Not Found"<<endl;
    if(c.Find(15, pos))
        cout<<"Found: "<<c.Find(15, pos)<<" at position: "<<pos<<endl;
    else
        cout<<"Not Found"<<endl;
    lines();

    cout<<"Search"<<endl;
    cout<<"Found: "<<c.Search(3)<<endl;
    cout<<"Found: "<<c.Search(15)<<endl;
    lines();

    return 0;
}
