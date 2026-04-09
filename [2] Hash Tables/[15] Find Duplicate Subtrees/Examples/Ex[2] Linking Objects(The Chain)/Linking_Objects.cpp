#include <iostream>

struct Node{
    int data;
    Node* next;
};

int main(){
    
    Node n1;
    n1.data = 10;

    Node n2;
    n2.data = 20;

    Node n3;
    n3.data = 42069;

    n1.next = &n2;

    n1.next->next= &n3;

    std::cout<<n1.data<<std::endl;

    std::cout<<n1.next->data<<std::endl;
     
    std::cout<<n1.next->next->data<<std::endl;



}
