#ifndef LIST_H
#define LIST_H
#include "Nod.h"
using namespace std;
class List
{
    Nod *start, *end;
    unsigned size;
public:
    friend ostream &operator<<(ostream&, const List&);
    List();
    List(int);
    List(int, int);
    List(const List&);
    List operator=(int);
    ~List();
    void insert(int);
    void insertAt(int, unsigned int);
    void remove(unsigned int);
    int get(unsigned int);
    int operator[](int);
    List operator+(List);
    bool operator<(List);
    bool operator>(List);
    List operator*(int);
    int sum();
    unsigned length();
    List reverse();
    int min();
    int max();
};
#endif // LIST_H
