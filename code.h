#ifndef CODE_H
#define CODE_H

template <class T>
class linearQueue {
public:
    typedef T valueType;

    virtual void createQueue() = 0;
    virtual bool isEmpty() const = 0;
    virtual valueType readQueue() const = 0;
    virtual void removeQueue() = 0;
    virtual void insertQueue(valueType) = 0;

};

#endif // CODE_H
