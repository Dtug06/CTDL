#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
     struct Node* next;
     struct Node* prev;
 }node;
 struct Node* creatNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
     newNode->data=data;
     newNode->next=NULL;
     newNode->prev=NULL;
     return newNode;
 }
void printList(struct Node* head ) {
     struct Node* temp = head;
     printf("NULL <--");
     while(temp!=NULL) {
         if (temp->next == NULL) {
             printf("%d -->NULL", temp->data);
         }else {
             printf("%d <-->", temp->data);
         }
         temp = temp->next;
     }
 }
void printData(struct Node* head ) {
     struct Node* temp = head;
     int count =1;
     while (temp!=NULL) {
         printf("Node %d : %d \n",count,temp->data);
         temp = temp->next;
         count++;
     }
 }
struct Node* deleteLast(struct Node* head) {
     if (head == NULL) return NULL;

     if (head->next == NULL) {
         free(head);
         return NULL;
     }
     struct Node* temp = head;
     while (temp->next->next != NULL) {
         temp = temp->next;
     }
     free(temp->next);
     temp->next = NULL;
     return head;
 }
struct Node* addLastList (int data, struct Node* head ) {
     struct Node* newNode=creatNode(data);
     struct Node* temp = head;
     if (head==NULL) {
         head = newNode;
         return head;
     }
     while (temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev = temp;
     return head;
 }
struct Node* deleteByData(int data, struct Node* head) {
     struct Node* temp = head;
     while (temp != NULL) {
         if (temp->data == data) {
             struct Node* toDelete = temp;
             if (temp->prev == NULL) {
                 head = temp->next;
                 if (head != NULL)
                     head->prev = NULL;
             }
             else if (temp->next == NULL) {
                 temp->prev->next = NULL;
             }
             else {
                 temp->prev->next = temp->next;
                 temp->next->prev = temp->prev;
             }
             temp = temp->next;
             free(toDelete);
         } else {
             temp = temp->next;
         }
     }
     return head;
 }
struct Node* searchMiddle(struct Node* head ) {
     if (head==NULL) {
         return NULL;
     }
     struct Node* temp = head;
     struct Node* slow=head;
     struct Node* fast=head;
     while (fast!=NULL && fast->next!=NULL) {
         slow = slow->next;
         fast = fast->next->next;
     }
     return slow;
 }

int main(void) {
     node *head=NULL;
     node* node1=creatNode(1);
     node* node2=creatNode(2);
     node* node3=creatNode(3);
     node* node4=creatNode(4);
     node* node5=creatNode(5);

     head=node1;
     node1->next=node2;
     node2->prev=node1;
     node2->next=node3;
     node3->prev=node2;
     node3->next=node4;
     node4->prev=node3;
     node4->next=node5;
     node5->prev=node4;
     node5->next=NULL;
     printList(head);
     printData(head);

     head=deleteLast(head);
     printList(head);

     printf("Xoa phan co data la : ");
     scanf("%d",&data);
     head=deleteByData(data,head);
     printList(head);

    return 0;
}