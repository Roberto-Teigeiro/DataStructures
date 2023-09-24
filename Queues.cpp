#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
        
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
  
  class Queue{
    private:
    Node* Front;
    Node* Rear;
    public:
    Queue(){Front=NULL; Rear=NULL;}
    void enQueue(int val);
    void mindeQueue();
    void maxdeQueue();
    bool isEmpty(); 
    bool isFull();
    int peek();
    void printQueue();
  };

void Queue::enQueue(int val){
    Node* nuevonodo= new Node(val);
    if(Front==NULL){
        Front=nuevonodo;
        Rear=nuevonodo;
        return;
    };
        Node* temp=Front;
        Node* temp2=NULL;
        if(nuevonodo->data < Front->data){
            Front=nuevonodo;
            nuevonodo->next=temp;
            temp->prev=nuevonodo;
            return;
        }
        while(temp->next!=NULL){
            if(nuevonodo->data >= temp->data){
                temp2=temp->next;
                temp->next=nuevonodo;
                nuevonodo->next=temp2;
                nuevonodo->prev=temp;
                temp2->prev=nuevonodo;
                return;
            }
            temp=temp->next;
        }
        temp->next=nuevonodo;
        nuevonodo->prev=temp;
        Rear=nuevonodo;
    };
void Queue::mindeQueue(){
    Node* temp=Front;
    cout<<"Se ha desencolado el: "<<Front->data<<endl;
    Front=Front->next;
    Front->prev=NULL;
    delete temp;
}
void Queue::maxdeQueue(){
    Node* temp=Rear;
    cout<<"Se ha desencolado el: "<<Rear->data<<endl;
    Rear=Rear->prev;
    Rear->next=NULL;
    delete temp;

}
void Queue::printQueue(){
    Node* temp = Front;
    if (Front == NULL) {
        cout << "List empty" << endl;
        return;
    }
    cout<<"La cola es: "<<endl;
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
queue.mindeQueue();
queue.printQueue();
queue.mindeQueue();
queue.printQueue();
queue.maxdeQueue();
queue.printQueue();

}