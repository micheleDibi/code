#ifndef CODEPUNTATORI_H
#define CODEPUNTATORI_H

#include "code.h"
#include <iostream>

using namespace std;

template <class T>
class linkedQueue;

template <class T>
class node{
public:
    friend class linkedQueue<T>;

private:
    T nvalue;
    node* prec;
    node* next;
};

template <class T>
class linkedQueue : linearQueue<T> {
public:

    typedef typename linearQueue<T>::valueType valueType;

    linkedQueue();
    ~linkedQueue();

    void createQueue();
    bool isEmpty() const;
    valueType readQueue() const;
    void removeQueue();
    void insertQueue(valueType);

    linkedQueue<T>& operator=(const linkedQueue<T>&);

    linkedQueue<T>positiveQueue();

    void print();

private:
    int lenght;
    node<T>* head;
    node<T>* tail;
};

template <class T>
linkedQueue<T>::linkedQueue() {
    lenght = 0;
    head = tail = nullptr;
}

template <class T>
linkedQueue<T>::~linkedQueue() {
    while(!isEmpty()) {
        node<T>* supp = head;
        head = head->next;
        delete supp;
    }
}

template <class T>
void linkedQueue<T>::createQueue() {}

template <class T>
bool linkedQueue<T>::isEmpty() const{
    return head == nullptr;
}

template <class T>
typename linkedQueue<T>::valueType linkedQueue<T>::readQueue() const{
    if(!isEmpty()) {
        return head->nvalue;
    }
}

template <class T>
void linkedQueue<T>::removeQueue() {
    node<T>* supp = head;
    head = head->next;
    delete supp;
    lenght--;
}

template <class T>
void linkedQueue<T>::insertQueue(linkedQueue<T>::valueType elem) {

    node<T>* supp = new node<T>;
    supp->nvalue = elem;

    if(isEmpty()) {
        head = tail = supp;

    } else {
        tail->next = supp;

    }

    supp->next = nullptr;
    tail = supp;

    lenght++;
}

template <class T>
linkedQueue<T> linkedQueue<T>::positiveQueue() {
    node<T>* tempNode = head;
    linkedQueue<T> tempQueue;

    for(int i = 0; i < lenght; i++) {
        if(tempNode->nvalue % 2 == 0) {
            linkedQueue<T>::valueType var = tempNode->nvalue;
            tempQueue.insertQueue(var);
        }
        tempNode = tempNode->next;
    }

    return tempQueue;
}

template <class T>
linkedQueue<T>& linkedQueue<T>::operator=(const linkedQueue<T> &l) {
    if(this != &l) {
        head = tail = nullptr;

        if(!l.isEmpty()) {

            node<T>* supp = l.head;

            for (int i = 0; i < l.lenght; i++) {
                linkedQueue<T>::valueType var = supp->nvalue;
                insertQueue(var);
                supp = supp->next;
            }
        }
    }

    return *this;
}

template <class T>
void linkedQueue<T>::print() {
    node<T>* pos = head;

    cout << "[";

    while(pos != nullptr) {
        cout << pos->nvalue << ", ";
        pos = pos->next;
    }

    cout << "]";
}

template <class T>
class linkedDequeue: public linkedQueue<T>{
public:
    typedef typename linkedQueue<T>::valueType valueType;

    void insertTopQueue(valueType elem) {
        node<T>* temp = new node<T>;
        temp->nvalue = elem;

        if(linkedQueue<T>::isEmpty()) {
            linkedQueue<T>::head = linkedQueue<T>::tail = temp;

        } else {
            linkedQueue<T>::head->prec = temp;
        }

        temp->prec = nullptr;
        linkedQueue<T>::head = temp;

        linkedQueue<T>::lenght++;
    }

    void removeBotQueue() {
        node<T>* supp = linkedQueue<T>::tail;
        linkedQueue<T>::tail = linkedQueue<T>::tail->prec;
        delete supp;
        linkedQueue<T>::lenght--;
    }
};

#endif // CODEPUNTATORI_H

/*  MAIN PER PROVA

    linkedQueue<int> codaOne;
    codaOne.insertQueue(5);
    codaOne.insertQueue(21);
    codaOne.insertQueue(6);
    codaOne.insertQueue(12);
    codaOne.insertQueue(551);
    codaOne.insertQueue(2);
    codaOne.insertQueue(65);
    codaOne.insertQueue(98);

    linkedQueue<int> codaTwo;
    codaTwo = codaOne.positiveQueue();

    cout << "A - valore presente in testa: " << codaMine.readQueue() << endl;

    codaMine.removeQueue();
    cout << "B - valore presente in testa: " << codaMine.readQueue() << endl;

    if(codaOne.isEmpty() == true) {
        cout << "la coda e' vuota" << endl;
    } else cout << "la coda NON e' vuota" << endl;

    return 0;

*/
