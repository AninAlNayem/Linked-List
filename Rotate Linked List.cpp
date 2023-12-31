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

node Head_ret(struct LinkedList* _list){

       node temp=_list->head;
       _list->head=_list->head->next;

       return temp;
}

int main(){

    struct LinkedList List;
    initLinkedList(&List);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        append(&List,a);
    }
    k=k%n;
    node Head;
    for(int i=1;i<=k;i++){
        Head=Head_ret(&List);
        append(&List,Head->data);
    }
    if(k)
       display(Head->next);
    else{
        display(List.head);
    }
return 0;
}
