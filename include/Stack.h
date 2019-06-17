#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "CharLinkedList.h"

using namespace std;

class Stack
{
    public:
        Stack();
        virtual ~Stack();
        char pop();
        void push(char input);
        char peek();

    protected:

    private:
        int size;
        //int top;
        CharLinkedList storage;
};

#endif // STACK_H
