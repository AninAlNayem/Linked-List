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
    temp=(node)malloc(sizeof(struct LinkedList));    /// allocate memory using malloc()
    temp->next=NULL;                                 /// make next point to NULL
    return temp;                                     ///return the new node
}

node addNode(int value){

    node temp,p;            /// declare two nodes temp and p
    temp=createNode();     ///createNode will return a new node with data = value and next pointing to NULL.
    temp->data=value;      /// add element's value to data part of node

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

/// Function to reverse  a linked list
node reverseLinkedList(node head) {
    if (head==NULL) {
        return NULL;  /// Empty list
    }

    node curr=head;
    node prev=NULL;
    while(curr!=NULL){
        node temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
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
    node mid=reverseLinkedList(head);

    node p=mid;
    while(p!=NULL){
        cout<< p->data <<" " ;
        p=p->next;
    }
    freeList(head);

return 0;
}
