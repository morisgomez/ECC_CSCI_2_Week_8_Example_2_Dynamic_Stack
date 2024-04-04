/*
 Program Name: Static_Stack.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/03/2024
 Version Control: 1.0
 About: Week 8, CSCI 2, Example 2.
 Description:
    Intro to Dynamic Stacks via Linked List.
*/
#include <iostream>
using namespace std;

class DynamicStack
{
private:
    struct Node //for Nodes.
    {
        int value;
        Node *next;
    }; //end struct Node.
    Node *top; //empty pointer part of Stack class not struct.
public:
//constructor:
    DynamicStack()
    {
        top = NULL;
    }
    
//deconstructor:
    ~DynamicStack()
    {
        cout << endl << "deconstructor always called automatically after main driver ends." << endl;
    }
    
//stack algorithms:
//FUNCTION 1: push().
    void push(int num)
    {
        Node *n = new Node; //n = new Node.
        n->value = num; //value of n is num.
        n->next = NULL; //next = NULL.
        if(isEmpty())
        {
            top = n; //empty, so n becomes only & top Node.
        }
        else
        {
            n->next = top; //n becomes first Node.
            top = n; //top points to n Node.
        }
    } //end push function.
//FUNCTION 2: pop().
    void pop(int &num) //by ref., so changes to num shown in main.
    //have to pass argument as variable?
    {
        Node *temp; //empty pointer.
        if(isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            num = top->value; //store value of top Node in num.
            temp = top->next; //store address of 2nd Node in temp.
            delete top; //delete Node stored in top.
            top = temp; //make top point to temp = new top.
        }
    } //end pop function.
//FUNCTION 3: isEmpty().
    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isEmpty function.
//FUNCTION 4: display().
    void display()
    {
        Node *current;
        current = top; //start at top.
        while(current != NULL) //a stack exists.
        {
            cout << current->value << " "; //value.
            current = current->next; //traverse from top to down.
        } //while loop.
    } //end display function.
}; //end DynamicStack.

//DRIVER for class DynamicStack via main function:
int main()
{
    //create empty stack:
    DynamicStack stackOne;
    
    //add 4 Nodes to stack:
    stackOne.push(3); //FILO BOTTOM.
    stackOne.push(6);
    stackOne.push(7);
    stackOne.push(9); //LIFO TOP.
    
    //display stack:
    stackOne.display();
    
    //pop top value:
    int x;
    stackOne.pop(x);
    cout << endl << x << endl; //should be 9.
    
    //display stack:
    stackOne.display();
    return 0;
}
