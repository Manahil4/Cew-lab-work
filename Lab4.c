Q2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *mergeLists(struct Node *l1, struct Node *l2);

struct Node *createNode(int data);

void printLinkedList(struct Node *head);

int main() {
    int mlnum=0;
    struct Node *l1 = createNode(2);
    l1->next = createNode(3);
    l1->next->next = createNode(34);

    struct Node *l2 = createNode(1);
    l2->next = createNode(5);
    l2->next->next = createNode(89);

    struct Node *ml = mergeLists(l1, l2);

    // Display the merged list
    printLinkedList(ml);

    // Free the memory
    // ...

    return 0;
}

struct Node *mergeLists(struct Node *l1, struct Node *l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    if(mlnum==0){
    struct Node *ml=malloc(sizeof(struct Node));
    }
    else{
    struct Node *ml=realloc(ml,sizeof(struct Node)*mlnum);
    }
    if (l1->val < l2->val) {
        ml = l1;
        mlnum+=1;
        ml->next = mergeLists(l1->next, l2);
    } else {
        ml = l2;
        mlnum+=1;
        ml->next = mergeLists(l1, l2->next);
    }

    return ml;
}

void printLinkedList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}
