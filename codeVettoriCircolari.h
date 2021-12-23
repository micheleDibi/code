#ifndef CODEVETTORICIRCOLARI_H
#define CODEVETTORICIRCOLARI_H

#include "code.h"
#include <iostream>

using namespace std;

template <class T>
class vectorQueue : public linearQueue<T> {
public:
    typedef typename linearQueue<T>::valueType valueType;

    vectorQueue();
    vectorQueue(int);
    ~vectorQueue();

    void createQueue();
    bool isEmpty() const;
    valueType readQueue() const;
    void removeQueue();
    void insertQueue(valueType);

    vectorQueue<T>& operator=(const vectorQueue<T>&);

    vectorQueue<T>positiveQueue();

    void print();

private:
    int lenght;
    int dim;
    valueType *elements;

};

template <class T>
vectorQueue<T>::vectorQueue() {
    dim = 10;
    this->createQueue();
}

template <class T>
vectorQueue<T>::vectorQueue(int dimension) {
    dim = dimension;
    this->createQueue();
}

template <class T>
vectorQueue<T>::~vectorQueue() {
    lenght = 0;
    delete[] elements;
}

template <class T>
void vectorQueue<T>::createQueue() {
    elements = new valueType[dim];
    lenght = 0;
}

template <class T>
bool vectorQueue<T>::isEmpty() const{
    return lenght == 0;
}

template <class T>
typename vectorQueue<T>::valueType vectorQueue<T>::readQueue() const{
    return elements[0];
}

template <class T>
void vectorQueue<T>::removeQueue() {
    for(int i = 0; i < lenght; i++) {
        elements[i] = elements[i+1];
    }

    lenght--;
}

template <class T>
void vectorQueue<T>::insertQueue(vectorQueue<T>::valueType elem) {

    if(lenght < dim) {
        elements[lenght] = elem;
        lenght++;
    }
}

template <class T>
vectorQueue<T>& vectorQueue<T>::operator=(const vectorQueue<T> &l) {
    if(this != &l) {
        delete[] elements;
        dim = l.dim;
        this->createQueue();

        if(!l.isEmpty()) {
            for (int i = 0; i < l.lenght; i++) {
                vectorQueue<T>::valueType var = l.elements[i];
                insertQueue(var);
            }
        }
    }

    return *this;
}

template <class T>
vectorQueue<T> vectorQueue<T>::positiveQueue() {
    vectorQueue<T> tempQueue(this->dim);

    for(int i = 0; i < lenght; i++) {
        if((elements[i] % 2) == 0) {
            tempQueue.insertQueue(elements[i]);
        }
    }

    return tempQueue;
}

template <class T>
void vectorQueue<T>::print() {

    cout << "[";

    for(int i = 0; i < lenght; i++) {
        cout << elements[i] << ", ";
    }

    cout << "]";

    return;
}

template <class T>
class vectorDequeue: public vectorQueue<T>{
public:
    typedef typename vectorQueue<T>::valueType valueType;

    void insertTopQueue(valueType elem) {
        if(vectorQueue<T>::lenght < vectorQueue<T>::dim) {

            for (int i = 0; i < vectorQueue<T>::lenght-1; i++) {
                vectorQueue<T>::elements[i+1] = vectorQueue<T>::elements[i];
            }

            vectorQueue<T>::elements[0] = elem;
            vectorQueue<T>::lenght++;
        }
    }

    void removeBotQueue() {

        if(!(vectorQueue<T>::isEmpty())) {
            delete vectorQueue<T>::elements[vectorQueue<T>::lenght];
            vectorQueue<T>::lenght--;
        }
    }
};


#endif // CODEVETTORICIRCOLARI_H

/* MAIN CODE VETTORI CIRCOLARI

    vectorQueue<int> codaThree;
    codaThree.insertQueue(5);
    codaThree.insertQueue(21);

    vectorQueue<int> codaFour;
    codaFour = codaThree.positiveQueue();

    cout << "A - valore presente in testa: " << codaThree.readQueue() << endl;

    codaThree.removeQueue();
    cout << "B - valore presente in testa: " << codaThree.readQueue() << endl;


    if(codaThree.isEmpty() == true) {
        cout << "la coda e' vuota" << endl;
    } else cout << "la coda NON e' vuota" << endl;

*/
