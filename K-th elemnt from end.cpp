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

node delete_kth_node_from_end(node head,int n) {

    node dummy=(node)malloc(sizeof(struct LinkedList));  /// allocate memory using malloc()
    dummy->data=-1;
    dummy->next=head;

    node slow=dummy;
    node fast=dummy;

   for(int i=1;i<=n;i++){
      fast=fast->next;             /// Move pointer fast n spaces ahead                
    }

   while(fast->next!=NULL) {       /// Move both now, until the next of fast is null
        slow=slow->next;
        fast=fast->next;
    }

   slow->next=slow->next->next;    /// We now have to remove the node next of slow
   return dummy->next;
  }


int main(){

     int n,k;scanf("%d%d",&n,&k);
     for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        addNode(a);
     }
     node p=delete_kth_node_from_end(head,k);
     while(p!=NULL){
        cout<< p->data <<" ";
        p=p->next;
     }
     cout<<"\n";

return 0;
}
