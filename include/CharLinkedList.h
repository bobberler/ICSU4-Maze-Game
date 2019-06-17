#ifndef CHARLINKEDLIST_H
#define CHARLINKEDLIST_H

#include <iostream>

class CharLink //Linked list but made with characters
{
    public:
    char contents;
    CharLink* next;
    CharLink* previous;
};

class CharLinkedList
{
    public:
        CharLinkedList();
        virtual ~CharLinkedList();

        int getSize ();
        CharLink* getFirst();
        CharLink* getLast();

        void add(CharLink* newLink, CharLink* destination);
        void add(char newContent, CharLink* destination);
        CharLink* remove(CharLink* link);
        bool isEmpty();

    protected:

    private:
        int size;
        CharLink* first;
        CharLink* last;
};

#endif // CHARLINKEDLIST_H
