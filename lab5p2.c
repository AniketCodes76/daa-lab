#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct Node {
    SYMBOL data;
    struct Node *left, *right;
} Node;

/* Create a new node */
Node* createNode(char alphabet, int frequency) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data.alphabet = alphabet;
    newNode->data.frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert node into Min-Priority Queue */
void insert(Node *pq[], int *size, Node *newNode) {
    int i = *size;

    while (i > 0 && pq[(i - 1) / 2]->data.frequency > newNode->data.frequency) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    pq[i] = newNode;
    (*size)++;
}

/* Delete minimum frequency node */
Node* deleteMin(Node *pq[], int *size) {
    Node *min = pq[0];
    Node *last = pq[--(*size)];

    int i = 0;

    while (2 * i + 1 < *size) {
        int child = 2 * i + 1;

        if (child + 1 < *size &&
            pq[child + 1]->data.frequency < pq[child]->data.frequency)
            child++;

        if (last->data.frequency <= pq[child]->data.frequency)
            break;

        pq[i] = pq[child];
        i = child;
    }

    if (*size > 0)
        pq[i] = last;

    return min;
}

/* In-order traversal */
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);

        if (root->left == NULL && root->right == NULL)
            printf("%c ", root->data.alphabet);

        inorder(root->right);
    }
}

int main() {
    int n, i;
    char alphabet;
    int frequency;

    Node *pq[100];
    int size = 0;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    printf("Enter the alphabets: ");

    for (i = 0; i < n; i++) {
        scanf(" %c", &alphabet);

        printf("");
        
        pq[size++] = createNode(alphabet, 0);
    }

    printf("Enter its frequencies: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &frequency);
        pq[i]->data.frequency = frequency;
    }

    /* Build Min-Priority Queue */
    for (i = size / 2 - 1; i >= 0; i--) {
        int j = i;

        while (2 * j + 1 < size) {
            int child = 2 * j + 1;

            if (child + 1 < size &&
                pq[child + 1]->data.frequency < pq[child]->data.frequency)
                child++;

            if (pq[j]->data.frequency <= pq[child]->data.frequency)
                break;

            Node *temp = pq[j];
            pq[j] = pq[child];
            pq[child] = temp;

            j = child;
        }
    }

    /* Construct Huffman Tree */
    while (size > 1) {
        Node *left = deleteMin(pq, &size);
        Node *right = deleteMin(pq, &size);

        Node *parent = createNode('$',left->data.frequency + right->data.frequency);

        parent->left = left;
        parent->right = right;

        insert(pq, &size, parent);
    }

    printf("\nIn-order traversal of the tree (Huffman): ");
    inorder(pq[0]);

    return 0;
}