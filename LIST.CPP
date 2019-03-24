#include "List.h"
using namespace std;
ostream &operator<<(ostream& output, const List& l) //supraincarcarea operatorului de afisare
{
    Nod *p = l.start;
    while (p != NULL)
    {
        output << p->getInfo() << " ";
        p = p->getNext();
    }
    output << endl;
}
List::List() //implementarea constructorului fara parametri
{
    start = end = NULL;
    size = 0;
}
List::List(int x) //implementarea constructorului cu un parametru
{
    start = end = new Nod(x, NULL);
    size = 1;
}
List::List(int x, int y) //implementarea constructorului cu doi parametri
{
    start = end = NULL;
    for (int i = 0; i < x; i++)
    {
        insert(y);
    }
}
List::List(const List &l) //implementarea constructorului de copiere
{
    start = end = NULL;
    size = 0;
    Nod* p = l.start;
    while (p != NULL)
    {
        insert(p->getInfo());
        p = p->getNext();
    }
}
List List::operator=(int x) //supraincarcarea operatorului =
{
    List l;
    l.size = size;
    unsigned int i;
    l.start = l.end = NULL;
    for(i = 0; i < size; i++)
        l.insert(get(i));
    return l;
}
List::~List() //implementarea destructorului
{
    Nod *p = start, *o;
    while (p != NULL)
    {
        o = p;
        p = p->getNext();
        delete o;
    }
    start = end = NULL;
    size = 0;
}
void List::insert(int x) //inserarea unui element la sfarsitul listei
{
    insertAt(x, size + 1);
}
void List::insertAt(int x, unsigned int i) //inserarea unui element la pozitia i din lista
{
    if (start == NULL)
    {
        start = end = new Nod(x, NULL);
        size = 1;
        return;
    }
    Nod* p = new Nod(x, NULL);
    if (i == 0)
    {
        p->setNext(start);
        start = p;
        return;
    }
    if (i < 0 || i >= size)
    {
        end->setNext(p);
        end = p;
        size++;
        return;
    }
    Nod* o = start;
    for (int j = i; j > 1; j--)
    {
        o = o->getNext();
    }
    p->setNext(o->getNext());
    o->setNext(p);
    size++;
}
void List::remove(unsigned int i) //stergerea unui element din lista
{
    if (i < 0 || i >= size)
    {
        return;
    }
    Nod* p = start;
    if (i == 0)
    {
        if (size == 1 || size == 0)
        {
            end = start = NULL;
        }
        else
        {
            start = start->getNext();
            delete p;
        }
    }
    else
    {
        for (int j = i; j > 1; j--)
        {
            p = p->getNext();
        }
        Nod* o = p->getNext();
        p->setNext(o->getNext());
        delete o;
    }
    size--;
}
int List::get(unsigned int i) //cautarea elementului de pe pozitia i din lista
{
    if (i < 0 || i >= size)
    {
        return INT_MAX;
    }
    Nod* p = start;
    for (int j = i; j > 0; j--)
    {
        p = p->getNext();
    }
    return p->getInfo();
}
int List::operator[](int i) //supraincarcarea operatorului [] pentru accesarea elementului de pe pozitia i din lista
{
    return get(i);
}
List List::operator+(List l2) //supraincarcarea operatorului + pentru reuniunea a doua liste
{
    List l;
    unsigned int i, j;
    l.size = size + l2.size;
    for(i = 0; i < size; i++)
    {
        l.insert(get(i));
    }
    for(j = 0; j < l2.size; j++)
        l.insert(l2.get(j));
    return l;
}
bool List::operator<(List l2) //supraincarcarea operatorilor < si > pentru compararea a doua liste dupa suma elementelor
{
    unsigned int s1 = 0, s2 = 0, i;
    for(i = 0; i < size; i++)
        s1 = s1 + get(i);
    for(i = size; i < l2.size; i++)
        s2 = s2 + l2.get(i);
    if(s1 < s2)
        return true;
    return false;
}
bool List::operator>(List l2)
{
    unsigned int s1 = 0, s2 = 0, i;
    for(i = 0; i < size; i++)
        s1 = s1 + get(i);
    for(i = size; i < l2.size; i++)
        s2 = s2 + l2.get(i);
    if(s1 > s2)
        return true;
    return false;
}
List List::operator*(int x) //supraincarcarea operatorului * pentru inmultirea cu un scalar
{
    List l;
    l.size = size;
    unsigned int i;
    l.start = l.end = NULL;
    for(i = 0; i < size; i++)
        l.insert(x * get(i));
    return l;
}
int List::sum() //obtinerea sumei elementelor din lista
{
    unsigned int s = 0, i;
    for(i = 0; i < size; i++)
        s = s + get(i);
    return s;
}
unsigned List::length() //obtinerea numarului de elemente din lista
{
    return size;
}
List List::reverse() //inversarea elementelor din lista
{
    List l;
    Nod *p = start;
    while (p != NULL)
    {
        l.insertAt(p->getInfo(), 0);
        p = p->getNext();
    }
    return l;
}
int List::min() //determinarea minimului si a maximului din lista
{
    Nod *p = start;
    unsigned int i;
    int m;
    m = p->info;
    for(i = 0; i < size; i++)
    {
        if(p->info < m)
            m = p->info;
        p = p->next;
    }
    return m;
}
int List::max()
{
    Nod *p = start;
    unsigned int i;
    int m;
    m = p->info;
    for(i = 0; i < size; i++)
    {
        if(p->info > m)
            m = p->info;
        p = p->next;
    }
    return m;
}
