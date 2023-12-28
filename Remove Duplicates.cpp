/*
Your task is to remove duplicate elements from the linked list. For every type of element keep the first instance and delete rest.

Input:
5
1 2 1 3 2
Output:
1 2 3

*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool>seen;

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

node removeDuplicate(node head){

    if(head==NULL){
        return NULL;
    }

    node current=head;
    node previous=NULL;

    while(current!=NULL){

        if(seen[current->data]==1){
            previous->next=current->next;  /// suppose a,b,c after executing this line a will connect c.
            delete current; /// deleting the node.
            current=previous->next;
        }
        else{
            seen[current->data]=true;
            previous=current;
            current=current->next;
        }
    }
    return head;

}


int main(){

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        addNode(a);
    }
    node init=removeDuplicate(head);

    node p=init;
    while(p!=NULL){
        cout<<p->data <<" ";
        p=p->next;
    }
    cout<<"\n";

return 0;
}
