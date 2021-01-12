#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node
{
        int data;
        struct node* next;
};

void insert(struct node** head, int value)
{

        struct node* new_node =
                (struct node*) malloc(sizeof(struct node));

        new_node->data  = value;

        new_node->next = (*head);

        (*head)    = new_node;
}

/* Counts the no. of occurences of a node in a linked list */
int count(struct node* start, int item)
{
        struct node* current = start;
        int count = 0;
        while (current != NULL)
        {
                if (current->data == item)
                        count++;
                current = current->next;
        }
        return count;
}
void createNodeList(int n)
{
        struct node *fnNode, *tmp;
        int num, i;
        stnode = (struct node *)malloc(sizeof(struct node));

        if(stnode == NULL)
        {
                printf(" Memory can not be allocated.");
        }
        else
        {

                printf(" Input data for nodes : ");
                scanf("%d", &num);
                stnode->num = num;
                stnode->nextptr = NULL;
                tmp = stnode;
                for(i=2; i<=n; i++)
                {
                        fnNode = (struct node *)malloc(sizeof(struct node));
                        if(fnNode == NULL)
                        {
                                printf(" Memory can not be allocated.");
                                break;
                        }
                        else
                        {

                                scanf(" %d", &num);

                                fnNode->num = num;
                                fnNode->nextptr = NULL;

                                tmp->nextptr = fnNode;
                                tmp = tmp->nextptr;
                        }
                }
        }
}

// main program
int main()
{
        struct node* start = NULL;

        insert(&start, 2);
        insert(&start, 5);
        insert(&start, 1);
        insert(&start, 2);
        insert(&start, 2);

        /* Check the count function */
        printf("count of 2 is %d", count(start, 2));
        return 0;
}
