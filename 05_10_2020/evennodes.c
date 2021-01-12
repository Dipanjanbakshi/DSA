#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node* next;
        struct Node* prev;
};

void push_back(struct Node** head_ref, int newElement) {
        struct Node *newNode, *temp;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(*head_ref == NULL) {
                *head_ref = newNode;
        } else {
                temp = *head_ref;
                while(temp->next != NULL) {
                        temp = temp->next;
                }
temp->next = newNode;
                newNode->prev = temp;
        }
}

void deleteEvenNodes(struct Node** head_ref) {
        if(*head_ref != NULL) {
                struct Node* oddNode = *head_ref;
                struct Node* evenNode = (*head_ref)->next;
                struct Node* temp;

                while(oddNode != NULL && evenNode != NULL) {
                        oddNode->next = evenNode->next;
                        free(evenNode);

                        temp = oddNode;
                        oddNode = oddNode->next;
                        if(oddNode != NULL) {
                                oddNode->prev = temp;
                                evenNode = oddNode->next;
                        }
                }
        }
}

void PrintList(struct Node* head_ref) {
        struct Node* temp = head_ref;
        if(head_ref != NULL) {
                printf("\nThe list contains: ");
                while (temp->next != NULL) {
                        printf("%i ",temp->data);
                        temp = temp->next;
                }
                printf("%i ",temp->data);
        } else {
                printf("\nThe list is empty.");
        }
}
int main() {
        struct Node* MyList = NULL;

        push_back(&MyList, 10);
        push_back(&MyList, 20);
        push_back(&MyList, 30);
        push_back(&MyList, 40);
        push_back(&MyList, 50);

        PrintList(MyList);

        deleteEvenNodes(&MyList);

        printf("\nAfter deleting even nodes.");

        PrintList(MyList);

        return 0;
}
