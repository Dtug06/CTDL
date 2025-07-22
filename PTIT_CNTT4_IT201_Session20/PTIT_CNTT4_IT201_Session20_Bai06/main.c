#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, Node* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return result;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
void insertNode(Node* root, int value) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
    free(q);
}
void levelOrder(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    free(q);
}
int countLeaves(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
int findMax(Node* root) {
    if (root == NULL) return -99999;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}
int findLevel(Node* root, int target) {
    if (root == NULL) return -1;
    typedef struct {
        Node* node;
        int level;
    } QueueItem;
    QueueItem queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (QueueItem){root, 1};
    while (front < rear) {
        QueueItem current = queue[front++];
        if (current.node->data == target)
            return current.level;
        if (current.node->left)
            queue[rear++] = (QueueItem){current.node->left, current.level + 1};
        if (current.node->right)
            queue[rear++] = (QueueItem){current.node->right, current.level + 1};
    }
    return -1;
}
int main() {
    int value;
    printf("Nhap data root: ");
    scanf("%d", &value);
    Node* root = createNode(value);
    for (int i = 0; i < 5; i++) {
        printf("Nhap data can them: ");
        scanf("%d", &value);
        insertNode(root, value);
    }
    printf("\n(Level-order): ");
    levelOrder(root);
    int target;
    printf("Nhap data can tim tang: ");
    scanf("%d", &target);
    int level = findLevel(root, target);
    if (level != -1)
        printf(" %d nam o tang: %d\n", target, level);
    else
        printf("Khong tim thay !!!.\n", target);
    return 0;
}
