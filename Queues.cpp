#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
        
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
  class Queue{
    private:
    Node* Front;
    Node* Rear;
    public:
    Queue(){Front=NULL; Rear=NULL;}
    void enQueue(int val);
    void deQueue();
    bool isEmpty(); 
    bool isFull();
    int peek();
    void printQueue();
  };

void Queue::enQueue(int val){
    Node* nuevonodo= new Node(val);
    if(Front==NULL){
        Front=nuevonodo;
        return;
    };
        Node* temp2=NULL;
        Node* temp=Front;
        if(nuevonodo->data < Front->data){
            Front=nuevonodo;
            nuevonodo->next=temp;
            return;
        }

        while(temp->next!=NULL){
            if(nuevonodo->data < temp->next->data){
                temp2=temp->next;
                temp->next=nuevonodo;
                temp->next->next=temp2;
                return;
            }
            temp=temp->next;
        }
        temp->next=nuevonodo;
    };
void Queue::printQueue(){
    Node* temp = Front;
    if (Front == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
Queue queue;
queue.enQueue(100);
queue.enQueue(112);
queue.enQueue(1);
queue.enQueue(8);
queue.enQueue(6);
queue.enQueue(34);
queue.enQueue(9);
queue.printQueue();
}