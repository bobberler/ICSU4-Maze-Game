/*
Author: Tom Lumsden
Project name: LinkedList.cpp
Project Description: linked list functions
Date created: 4/1/2019
Date modified: 4/11/2019
*/
//=========================================================================================================================

#include "LinkedList.h"

LinkedList::LinkedList()
{
    size = 0;
    first = NULL;
    last = NULL;
}

LinkedList::~LinkedList()
{
    //dtor
}

void LinkedList::add(Link* newLink, Link* destination) //Adds the new Link after destination
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

void LinkedList::add(GameObject* newContent, Link* destination)
{

    Link* l = new Link;
    l->contents = newContent;

    add(l, destination);
}

//Link* LinkedList::remove(Link* link)
//{
//    if(first == NULL) //Chain is empty
//        return link;
//    if (link == NULL)
//        return link;
//
//    size--;
//
//    if(first == link && last == link) //If the link the the only one in the chain
//    {
//        first = NULL;
//        last = NULL;
//    }
//    else if(first == link) //link is the first in the chain
//    {
//        link->next->previous = NULL;
//        first = link->next;
//    }
//    else if(last == link) //link is the last in the chain
//    {
//        link->previous->next = NULL;
//        last = link->previous;
//    }
//    else
//    {
//        link->previous->next = link->next;
//        link->next->previous = link->previous;
//    }
//
//    link->next = NULL;
//    link->previous = NULL;
//
//    return link;
//}

void LinkedList::remove(Link* link)
{
	if (first != NULL and link != NULL) //list cannot be empty and link cannot be empty
	{
		size--;

		if (first == link and last == link) //only one item in list
		{
			first = NULL;
			last = NULL;
		}

		else if (first == link)//deleting first
		{
			link->next->previous = NULL;
			first = link->next;
		}

		else if (last == link) //deleting last
		{
			link->previous->next = NULL;
            last = link->previous;
		}

		else
		{
			link->previous->next = link->next;
            link->next->previous = link->previous;
		}

		link->contents->destroy();

		delete(link);
	}

	return;
}

Link* LinkedList::getLinkAt(int _location)
{
	Link* temp = first;

	if (temp == NULL) // empty list
		return NULL;

	for(int i = 0; i < _location; i++)
	{
		if(temp == last) // reached end of list.
			return NULL;

		temp = temp->next;
	}

	return temp; // found link
}

Link* LinkedList::getLink(GameObject* _contents)
{
	Link* temp = first;

	if (temp == NULL) // Empty list
		return NULL;

	// Content numbers are NOT always sequential, so can't assume must be less than size.
	while (temp->contents != _contents)
	{
		if (temp == last) // Reached end of list.
			return NULL;

		temp = temp->next;
	}

	return temp; // Found link
}

Link* LinkedList::getLinkWithName(std::string _name)
{
	Link* temp = first;

	if (temp == NULL) // Empty list
		return NULL;

	while (temp->contents->getName() != _name)
	{
		if (temp == last) // Reached end of list.
			return NULL;

		temp = temp->next;
	}

	return temp; // Found link
}

bool LinkedList::isEmpty()
{
    return (size < 1);
}

int LinkedList::getSize ()
{
    return size;
}

Link* LinkedList::getFirst ()
{
    return first;
}

Link* LinkedList::getLast ()
{
    return last;
}
