/*
You are given N integers. Create a singly linked list with these integers sequentially.
Now, suppose you don't have any infomation, you only have the head pointer of the linked list. You don't even know the size of the linked list.
Your task is to find the middle element of the linked list using only the limited information you have.
If there are even number of element, then there would be two elements, we need to print the second middle element. 

*/

#include<bits/stdc++.h>
using namespace std;

struct LinkedList{
    int data;
    struct LinkedList *next;
 };
typedef struct LinkedList *node;

node head,tail;

node createNode(){
    node temp;                                       /// declare a node
    temp=(node)malloc(sizeof(struct LinkedList));  /// allocate memory using malloc()
    temp->next=NULL;                               /// make next point to NULL
    return temp;                                     ///return the new node
}

node addNode(int value){

    node temp,p;        /// declare two nodes temp and p
    temp=createNode();///createNode will return a new node with data = value and next pointing to NULL.
    temp->data=value; /// add element's value to data part of node

    if(head==NULL){
        head=temp;     ///when linked list is empty
        tail=temp;
    }
    else{
        /// Assuming 'tail' initially points to the last node in the list
        tail->next=temp;  /// Connect the current last node to the new node
        tail=temp;       /// Update 'tail' to point to the new last node
    }
    return head;
}

/// Function to free the memory allocated for a linked list
void freeList(node head) {
    while(head!=NULL) {
        node temp=head;
        head=head->next;
        free(temp);
    }
}


int main(){

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        addNode(a);
    }
    node p=head;
    bool res=true;
    int cnt=0;
    while(p!=NULL){
        cnt++;
        if((cnt==(n/2)+1)){
            cout<< p->data <<"\n";
            break;
        }
        p=p->next;
    }

    freeList(head);


return 0;
}

