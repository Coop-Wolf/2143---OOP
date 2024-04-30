//---------------------------------------------------------
//  
//   This StringStack header file shows the different 
//   functions and variables of a stack. This stack
//   is used in this porgram to figure out with a 
//   string is a palindrome or not.
//
//---------------------------------------------------------

#ifndef STK_H
#define STK_H

class CharStack
{
public:

//Purpose:  This function creates a dynamic 
//          array of the inputed value. It
//          also sets the top to 0
//Recieves: The input parameter is the capacity
//          of the array
//Returns:  This function does not return anything
CharStack(int capacity);

//Purpose:  This function deletes the dynamic
//          array
//Recieves: This destructor does not recieve
//          anything 
//Returns:  This function does not return anything
~CharStack() { delete[] CharArray; }

//Purpose:  This function pushes strings into
//          the stack. 
//Recieves: The input parameter is a char
//    
//Returns:  This function returns the bool value
//          of whether or not its a palindrome or not
void push(char pal);

//Purpose:  The purpose of this function is 
//          remove the char's from the stack
//Recieves: The input parameter is the char 
//          
//Returns:  This function does not return anything
void pop(char& pal);

//Purpose:  This function determines whether
//          or not the stack is empty
//Recieves: This function does not have any
//          input parameters
//Returns:  This function returns whether or
//          not the stack or empty or not by
//          bool value
bool isempty() const { return top == 0; };

//Purpose:  This function determines whether
//          or not the stack is full
//Recieves: This function does not have any
//          input parameters
//Returns:  This function returns a true or 
//          false depending on if the stack
//          is full
bool isfull() const { return top == capacity; };

private:
    //storing characters
    char* CharArray;
    int capacity;
    int top;
};
#endif