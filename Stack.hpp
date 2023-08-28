#include <iostream>
#ifndef STACK_HPP
#define STACK_HPP
#define SIZE 10
#pragma once

class Stack{
    private:
    int *arr;
    int top;
    int capacity;

    public:
    Stack();
    void push(int);
    int pop();
    int peek();
    int size();
    bool IsEmpty();
    bool IsFull();
    

};

#endif