#include "Stack.h"

Stack::Stack()
{
    //top = -1;
    size = 0;
}

Stack::~Stack()
{
    //dtor
}

char Stack::pop()
{
    if(size == 0)
        return '0';

    size--;
    return storage.remove(storage.getLast())->contents;
}

void Stack::push(char input)
{
    size++;
    storage.add(input, storage.getLast());
    return;
}

char Stack::peek()
{
   if(size == 0)
       return '0';

    return storage.getLast()->contents;
}
