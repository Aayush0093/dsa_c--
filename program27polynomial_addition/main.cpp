#include <iostream>
using namespace std;

class Poly {
public:
    int coeff;
    int exp;
    Poly *next;
};

class Polynomial {
    Poly *first;
    Poly *last;
    int size;
public:
    //getFirst
    Poly *getFirst() {
        return first;
    }

    //getLast
    Poly *getLast() {
        return last;
    }

    // Constructor
    Polynomial();

    // Insert
    void Insert(int coeff, int exp);

    // Display
    void display(int);

    // Add
    Polynomial add(Polynomial p, Polynomial q);
};

// Add
Polynomial Polynomial::add(Polynomial p, Polynomial q) {
    Polynomial r;
    Poly *temp1 = p.getFirst();
    Poly *temp2 = q.getFirst();

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            r.Insert(temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            r.Insert(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            r.Insert(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        r.Insert(temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        r.Insert(temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return r;
}

// Insert
void Polynomial::Insert(int coeff, int exp) {
    Poly *temp = new Poly;
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    if (first == NULL) {
        first = temp;
        last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
    size++;
}

// Display
void Polynomial::display(int count) {
    Poly *temp = first;
    cout << "Polynomial " << count << " : ";
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;
        if (temp != NULL) {
            cout << " + ";
        }
    }
    cout << endl;
}

// Constructor
Polynomial::Polynomial() {
    first = NULL;
    last = NULL;
    size = 0;
}

int main() {

    int size1, size2;

    Polynomial p, q;
    cout << "Enter the number of terms in Polynomial 1 : ";
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int coeff, exp;
        cout << "Enter the coefficient and exponent of term " << i + 1 << " : ";
        cin >> coeff >> exp;
        p.Insert(coeff, exp);
    }

    cout << "Enter the number of terms in Polynomial 2 : ";
    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int coeff, exp;
        cout << "Enter the coefficient and exponent of term " << i + 1 << " : ";
        cin >> coeff >> exp;
        q.Insert(coeff, exp);
    }

    p.display(1);
    cout << endl;

    q.display(2);
    cout << endl;

    Polynomial r = r.add(p, q);
    r.display(3);

    return 0;
}