#include "Stack.hpp"


    Stack::Stack(){
        arr = new int[10];
        capacity = SIZE;
        top = 0;
    }

    void Stack::push(int n){
        if(!capacity==top){
            arr[++top]=n;
        }
    }
    int Stack::pop(){
        return arr[top];
        arr[top--]=0;
    }
    int Stack::peek(){
        return arr[top];
    }
    int Stack::size(){
        return top;
    }
    bool Stack::IsEmpty(){
     if (top==0){
        return true;    
    }
    else{
        return false;
    }
    bool Stack::IsFull(){
        if (top==capacity){
            return true;
        }
        else{
            return false;
        }
    }
    