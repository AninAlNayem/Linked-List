// Reverse a linked list between l and r.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node *node;


struct LinkedList{
    node head;
    node tail;
};

typedef struct LinkedList List;

void initLinkedList(struct LinkedList* List){
      List->head=NULL;
      List->tail=NULL;
}

node createNode(int val){
   node temp=(node)malloc(sizeof(struct Node));
   temp->data=val;
   temp->next=nullptr;
   return temp;
}

void append(struct LinkedList* List,int val){
     node newNode=createNode(val);
     if(List->head==nullptr){
        List->head=newNode;
        List->tail=newNode;
     }
     else{
        List->tail->next=newNode;
        List->tail=newNode;
     }
}

void display(node head) {
    node current=head;
    while(current!=nullptr) {
        printf("%d ",current->data);
        current=current->next;
    }
}
node reverseBetween(node head, int m, int n) {

     if(head==NULL || m==n) {
        return head;
    }

    node dummy=createNode(-1);
    dummy->next=head;
    node prev=dummy;

    // Move to the m-th node
    for(int i=1;i<m;i++) {
        prev=prev->next;
    }

    // Reverse the sublist from m to n
    node current=prev->next;
    node next_node=NULL;

    for(int i=0;i<=n-m;i++){
        node temp=current->next;
        current->next=next_node;
        next_node=current;
        current=temp;
    }

    // Connect the reversed sublist back to the original list
    prev->next->next=current;
    prev->next=next_node;

    return dummy->next;
}



int main(){
    int t;scanf("%d",&t);
    struct LinkedList List;
    initLinkedList(&List);
    for(int i=0;i<t;i++){
        int a;scanf("%d",&a);
        append(&List,a);
    }
    int m,n;cin>>m>>n;
    node Head=List.head;
    Head=reverseBetween(Head,m,n);

    display(Head);
  return 0;
}
