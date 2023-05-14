#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node **root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else if (value < (*root)->value) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void in_order(Node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->value);
        in_order(root->right);
    }
}

void pre_order(Node *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(Node *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->value);
    }
}

int size(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int height(Node *root) {
    if (root == NULL) {
        return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int main() {
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 18);

    printf("In-order traversal: ");
    in_order(root);
    printf("\n");

    printf("Pre-order traversal: ");
    pre_order(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order(root);
    printf("\n");

    printf("Size of tree: %d\n", size(root));
    printf("Height of tree: %d\n", height(root));

    return 0;
}
