#include <stdio.h>
#include <stdlib.h>

 typedef struct Node {
     int data;
     struct Node* next;
     struct Node* prev;
 }Node;
void printList(struct Node* head) {
    int count =1;
    struct Node* temp = head;
    while(temp != NULL) {
        printf(  " Node %d : %d  \n ",count, temp->data);
        count++;
        temp = temp->next;
    }
    printf("\n");
}

struct Node* creatNode(int data) {
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};
struct Node* addLastList(struct Node* head,int data) {
    struct Node* newNode= creatNode(data);
    struct Node* temp=head;
    if (head==NULL) {
        return newNode;
    }
    while(temp->next!=NULL) {
    temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}
int checkData(struct Node* head,int data) {
    struct Node* temp=head;
    while(temp!=NULL) {
        if(temp->data==data) {
            return 1;
        }
        temp=temp->next;
    }
    return -1;
}
int getLength(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while(temp!=NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
struct Node* addHead(struct Node* head,int data) {
    struct Node* newNode = creatNode(data);
    newNode->next=head;
    newNode->prev=NULL;
    if (head!=NULL) {
        head->prev=newNode;
    }
    return newNode;
}
struct Node* deleteFirst(struct Node* head) {
    struct Node* temp = head;
    if (head==NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}
 struct Node* addAt(struct Node* head,int data,int position) {
    struct Node* newNode = creatNode(data);
    struct Node* current = head;
    int index=0;
    if (position==0) {
        newNode->next=head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    while (current!=NULL && index<position-1) {
        current=current->next;
        index++;
    }
    if (current==NULL) {
      printf("Position không hợp lệ ");
        free(newNode);
        return head;
    }
    newNode->next=current->next;
    current->next->prev=newNode;
    newNode->prev=current;
    current->next=newNode;
    return head;
}
struct Node* deleteByValue(struct Node* head, int data) {
    struct Node* temp = head;
    if (head == NULL) return NULL;
    if (head->data == data) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return head;
}
int main(void) {

    Node* n1 = creatNode(1);
    Node* n2 = creatNode(2);
    Node* n3 = creatNode(3);
    Node* n4 = creatNode(4);
    Node* n5 = creatNode(5);


    n1->next = n2;
    n2->prev = n1; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4;

    Node* head = n1;
    printList(head);


    return 0;
}