#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node * prev;
        struct node * next;
}*head, *last;
void createList(int n);
void displayList();
void deleteFromBeginning();
void deleteFromEnd();
int main()
{
        int n,k=0;
        head = NULL;
        last = NULL;

        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        createList(n);
        displayList();
        printf(" Input the number of nodes you want to delete : ");
        scanf("%d", &k);
        for(int i=0; i<k; i++)
        {
                deleteFromBeginning();
        }
        for(int i=0; i<k; i++)
        {
                deleteFromEnd();
        }
        displayList();
        return 0;
}
void createList(int n)
{
        int i, data;
        struct node *newNode;

        if(n >= 1)
        {
                head = (struct node *)malloc(sizeof(struct node));

                printf("Enter data of 1 node: ");
                scanf("%d", &data);

                head->data = data;
                head->prev = NULL;
                head->next = NULL;

                last = head;
                for(i=2; i<=n; i++)
                {
                        newNode = (struct node *)malloc(sizeof(struct node));

                        printf("Enter data of %d node: ", i);
                        scanf("%d", &data);

                        newNode->data = data;
                        newNode->prev = last;
                        newNode->next = NULL;

                        last->next = newNode;
                        last = newNode;
                }
        }
}

void displayList()
{
        struct node * temp;
        int n = 1;

        if(head == NULL)
        {
                printf("List is empty.\n");
        }
        else
        {
                temp = head;
                printf("DATA IN THE LIST:\n");

                while(temp != NULL)
                {
                        printf("%d\n", temp->data);

                        n++;
                        temp = temp->next;
                }
        }
}
void deleteFromBeginning()
{
        struct node * toDelete;

        if(head == NULL)
        {
                printf("Unable to delete. List is empty.\n");
        }
        else
        {
                toDelete = head;

                head = head->next;

                if (head != NULL)
                        head->prev = NULL;

                free(toDelete);
        }
}
void deleteFromEnd()
{
        struct node * toDelete;

        if(last == NULL)
        {
                printf("Unable to delete. List is empty.\n");
        }
        else
        {
                toDelete = last;

                last = last->prev;

                if (last != NULL)
                        last->next = NULL;

                free(toDelete);
        }
}
