#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node*  creatNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=value;
    node->next=NULL;
    return node;
}
struct Node* printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main() {

    struct Node* head = creatNode(1);
    struct Node* node1=creatNode(2);
    struct Node* node2=creatNode(3);
    struct Node* node3=creatNode(4);
    struct Node* node4=creatNode(5);

    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;
    printList(head);
    return 0;
}
