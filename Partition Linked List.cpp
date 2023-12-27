/*
Your task is to partition the linked list such that all nodes less than X come first then all nodes with a value greter than equal to X.
Input:
5
5 4 3 2 1
3
Output:
2 1 5 4 3

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


int main(){

     int n;scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
     int x;scanf("%d",&x);
     for(int i=0;i<n;i++){
        if(arr[i]<x){
          addNode(arr[i]);
        }
     }
     for(int i=0;i<n;i++){
        if(arr[i]>=x){
          addNode(arr[i]);
        }
     }

     node p;
     p=head;
     while(p!=NULL){
       printf("%d ",p->data);
       p=p->next;
     }

return 0;
}

