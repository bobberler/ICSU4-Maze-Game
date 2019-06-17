#include "CharLinkedList.h"

CharLinkedList::CharLinkedList()
{
    size = 0;
    first = NULL;
    last = NULL;
}

CharLinkedList::~CharLinkedList()
{
    //dtor
}

void CharLinkedList::add(CharLink* newLink, CharLink* destination) //Adds the new Link after destination
{
    size++;

    if(first == NULL)
    {
        newLink->next = NULL;
        newLink->previous = NULL;

        first = newLink;
        last = newLink;
    }
    else if(destination == last)
    {
        newLink->next = NULL;
        newLink->previous = destination;

        destination->next = newLink;

        last = newLink;
    }
    else
    {
        newLink->next = destination->next;
        newLink->previous = destination;

        destination->next->previous = newLink;
        destination->next = newLink;
    }
}

void CharLinkedList::add(char newContent, CharLink* destination)
{

    CharLink* l = new CharLink;
    l->contents = newContent;

    add(l, destination);
}

CharLink* CharLinkedList::remove(CharLink* link)
{
    if(first == NULL) //Chain is empty
        return link;
    if (link == NULL)
        return link;

    size--;

    if(first == link && last == link) //If the link the the only one in the chain
    {
        first = NULL;
        last = NULL;
    }
    else if(first == link) //link is the first in the chain
    {
        link->next->previous = NULL;
        first = link->next;
    }
    else if(last == link) //link is the last in the chain
    {
        link->previous->next = NULL;
        last = link->previous;
    }
    else
    {
        link->previous->next = link->next;
        link->next->previous = link->previous;
    }

    link->next = NULL;
    link->previous = NULL;

    return link;
}

bool CharLinkedList::isEmpty()
{
    return (size < 1);
}

int CharLinkedList::getSize ()
{
    return size;
}

CharLink* CharLinkedList::getFirst ()
{
    return first;
}

CharLink* CharLinkedList::getLast ()
{
    return last;
}
