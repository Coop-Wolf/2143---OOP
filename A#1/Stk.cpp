//---------------------------------------------------------------
//  
//   This CharStack.cpp file includes to definitions of 
//   all member functions. These functions all word together
//   to push, and pop characters to the stack.
//
//---------------------------------------------------------------

#include "Stk.h"
#include <string>
#include <iostream>

using namespace std;

//Purpose:  This function creates a dynamic 
//          array of the inputed value. It
//          also sets the top to 0.
CharStack::CharStack(int capacity)
{
    //Refering to member data item
    this->capacity = capacity;
    CharArray = new char[capacity];
    top = 0;
}

//Purpose:  This function pushes chars into
//          the stack. 
void CharStack::push(char pal)
{
    if (top >= capacity - 1)
        cout << "Stack is full.";
    else 
    {
        CharArray[top] = pal;
        top++;
    }
}

//Purpose:  This function is remove the 
//          strings from the stack.
void CharStack::pop(char& pal)
{
    if (top == 0)
        cout << "Stack is empty.";
    else 
    {
        top--;
        pal = CharArray[top];
    }
}