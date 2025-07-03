#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* creatNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
};
 void printList(struct Node* head) {
     struct Node* temp=head;
     while(temp!=NULL) {
         printf("%d ",temp->data);
         temp=temp->next;
     }
     printf("\n");
 }
int getLength(struct Node* head) {
     struct Node* temp=head;
     int count=0;
     while(temp!=NULL) {
         temp=temp->next;
         count++;
     }
     return count;
     free(temp);
 }
 struct Node* addLastList(struct Node* head) {
     if (head == NULL) {
         return NULL;
     }
     if (head->next == NULL) {
         free(head);
         return NULL;
     }
     struct Node* newNode=creatNode(4);
     struct Node* temp=head;
     while(temp->next!=NULL) {
         temp=temp->next;
     }
     temp->next=newNode;
     return head;
 }
 struct Node* deleteLast(struct Node* head) {
     if (head == NULL) {
         return NULL;
     }
     if (head->next == NULL) {
         free(head);
         return NULL;
     }
     struct Node* temp=head;
     while (temp->next->next!=NULL) {
         temp=temp->next;
     }
     free(temp->next);
     temp->next = NULL;
     return head;
 }
 struct Node* deleteData(struct Node* head,int value) {
     struct Node* temp;
     while (head!=NULL&&head->data==value) {
         temp=head;
         head=head->next;
         free(temp);
     }

     if (head == NULL) return NULL;// dòng này trong trg hợp head =null

     struct Node* current=head;
     while (current->next!=NULL) {
         if (current->next->data==value) {
             temp=current->next;
             current->next=temp->next;
             free(temp);
         }else {
             current=current->next;
         }
     }
     return head;
 }


int main(void) {
    struct Node* head=creatNode(1);
    struct Node* second=creatNode(2);
    struct Node* third=creatNode(3);
    struct Node* fourth=creatNode(1);
    struct Node* fifth=creatNode(5);
     head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
  int length=getLength(head);
      printList(head);
     int data;
     printf("Nhap gia tri can xoa");
     scanf("%d",&data);
     head= deleteData(head,data);
     printList(head);


    return 0;
}