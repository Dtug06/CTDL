#include <stdio.h>
#include <stdlib.h>

struct Node {
     int data;
     struct Node* next;
     struct Node* prev;
 };
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
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
    struct Node* head=NULL;
     int n;
    printf("NHap so luong phan tu");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int data;
        printf("Nhap data");
        scanf("%d",&data);
        head=addLastList(head,data);
    }
    printList(head);


    return 0;
}