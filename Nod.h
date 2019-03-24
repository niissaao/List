#ifndef NOD_H
#define NOD_H
#include <iostream>
class List;
class Nod
{
    int info;
    Nod* next;
public:
    Nod();
    Nod(int, Nod*);
    void setInfo(int);
    void setNext(Nod*);
    int getInfo();
    Nod* getNext();
    friend class List;
};
#endif // NOD_H
