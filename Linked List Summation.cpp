/*
You are given 2 large integers. Create two singly linked lists with the digits of the integers sequentially.
Your task is to add the integers using linked list and create a new linked list that stores the summation.
suppose 12345(1-2-3-4-5) and 45678(4-5-6-7-8)   output: ostad58023 (5-8-0-2-3)
Given integers will be upto 10000 digits long.

Approach:
1. Make 2 different linkedlists using input a and b(a,b string) in reverse order
2. Add the two linkedlists and make the summation linkedlist
3. Reverse the linkedlist
4. Print the result

*/

#include<bits/stdc++.h>
using  namespace std;

struct Node{
    int data;
    struct Node* next;

};

typedef struct Node* node;

struct LinkedList{
    node head;
    node tail;
};

///Function to initialize a linked list

void initLinkedList(struct LinkedList* List){
     List->head=nullptr;
     List->tail=nullptr;
}

node createNode(int val){
   node temp=(node)malloc(sizeof(struct Node));
   temp->data=val;
   temp->next=nullptr;
   return temp;
}

/// Function to append a node to a linked list

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

/// Function to display the linked list
void display(struct LinkedList* List) {
    node current=List->head;
    while(current!=nullptr) {
        printf("%d",current->data);
        current=current->next;
    }
}

struct LinkedList addtwoList(struct LinkedList* l1,struct LinkedList* l2){

         struct LinkedList sum;
         initLinkedList(&sum);

         int carry=0,s=0;

         node curr1=l1->head;
         node curr2=l2->head;

         while(curr1!=nullptr || curr2!=nullptr|| carry!=0){
            s=carry;
            if(curr1!=nullptr){
                s+=curr1->data;
                curr1=curr1->next;
            }
            if(curr2!=nullptr){
                s+=curr2->data;
                curr2=curr2->next;
            }
            carry=s/10;
            s=s%10;
            append(&sum,s);
         }
   return sum;
}

void reverseLinkedList(struct LinkedList* sum) {

    node prev=NULL;
    node curr=sum->head;
    node temp;

    while(curr!=NULL) {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }

    sum->head=prev;  
}


int main(){
  string a,b;
  cin>>a>>b;
  struct LinkedList list1;
  initLinkedList(&list1);
  for(int i=a.size()-1;i>=0;i--){
    int d=a[i]-'0';
    append(&list1,d);
  }

  struct LinkedList list2;
  initLinkedList(&list2);
  for(int i=b.size()-1;i>=0;i--){
    int d=b[i]-'0';
    append(&list2,d);
  }

  struct LinkedList sum=addtwoList(&list1,&list2);
  reverseLinkedList(&sum);

  cout<<"ostad";
  display(&sum);

return 0;
}
