#include <stdio.h>

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
int checkData(struct Node* head,int n) {
    struct Node* current=head;
    while (current !=NULL) {
        if (current->data==n) {
            return 1;
        }
        current=current->next;
    }
    return 0;
}
void  printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
int countList(struct Node* head) {
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
 struct Node* addNode(struct Node* head,int value) {
    struct Node* newNode=creatNode(value);
    newNode->next=head;
    return newNode;
}
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct Node* insertAt(struct Node* head, int value, int position) {
    struct Node* newNode = creatNode(value);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Vi tri vuot qua do dai danh sach\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL || position < 0) {
        printf("Danh sach rong hoac vi tri khong hop le.\n");
        return head;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
int main() {
    struct Node* node0 = creatNode(1);
    struct Node* node1=creatNode(2);
    struct Node* node2=creatNode(3);
    struct Node* node3=creatNode(4);
    struct Node* node4=creatNode(5);
    node0->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;
int n;
    printf("Nhap data");
    scanf("%d",&n);
    struct Node* head=addNode(node0,n);
    printList(head);
    printf("\nXoa node dau tien...\n");
    head = deleteHead(head);
    printList(head);
    int v, pos;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &v);
    printf("Nhap vi tri muon chen (0 la dau): ");
    scanf("%d", &pos);
    head = insertAt(head, v, pos);
    printf("Danh sach sau khi chen: ");
    printList(head);

    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);
    printList(head);
    return 0;
}
