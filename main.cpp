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
  
  class Stack{
    private:
    Node* head;
    public:
    Stack(){ head=NULL; }
    void printlinkedlist();
    void insertNode(int val);
    void pop();
    int peek();
    Node* getHead() const {
        return head;
    }
  };

void Stack::pop(){
    Node* temp=head;
    if (head==NULL){
        cout<<"List is empty";
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;

}
void Stack::insertNode(int val){
        Node* nuevonodo= new Node(val);
        if (head==NULL){
            head=nuevonodo;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nuevonodo;
    };
void Stack::printlinkedlist(){
    Node* temp = head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int Stack::peek(){
 Node* temp= head;
    if (head==NULL){
        return -1;
    }
    while(temp->next!=NULL){
            temp=temp->next;
        }
    return temp->data;
};


void del(int index, const Stack& stack){
    int count=0;
    Node* temp= stack.getHead();
    Node* beforetemp;
       while(temp->next!=NULL){
            beforetemp=temp;
            temp=temp->next;
            count++;
            if (count==index){
                temp=beforetemp->next;
                beforetemp->next=temp->next;
               
            }
        }
};

void create(const Stack& stack){

};
int main(){
Stack stack;
stack.insertNode(1);
stack.insertNode(4);
stack.insertNode(3);
stack.insertNode(5);
stack.insertNode(6);
stack.printlinkedlist();
del(3, stack);
stack.printlinkedlist();


}