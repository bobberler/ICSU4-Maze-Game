/*
Author: Tom Lumsden
Project name: LinkedList.h
Project Description: linked list using GameObjects
Date created: 4/1/2019
Date modified: 4/11/2019
*/
//=========================================================================================================================

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "GameObject.h"

class Link
{
    public:
    GameObject contents;
    Link* next;
    Link* previous;
};

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        int getSize ();
        Link* getFirst();
        Link* getLast();

        void add(Link* newLink, Link* destination);
        void add(GameObject newContent, Link* destination);
        Link* remove(Link* link);
        bool isEmpty();

    protected:

    private:
        int size;
        Link* first;
        Link* last;
};

#endif // LINKEDLIST_H
