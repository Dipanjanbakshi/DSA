#include <stdio.h>
#include <stdlib.h>

struct node
{
        int num;
        struct node *nextptr;
        struct node * preptr;
}*stnode, *ennode;

void createNodeList(int n);
void displayList();

int main()
{
        int n,num,pos,x;
        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        createNodeList(n);
        printf("\n Data entered in the list : \n");
        displayList();

        printf("\n Enter choice :1- to insert an element at begining ");
        printf("\n Enter choice :2- to insert an element at end ");
        printf("\n Enter choice :3- to insert an element at specific position ");
        printf("\n Enter choice :4- to deletion an element at begining ");
        printf("\n Enter choice :5- to deletion an element at end ");
        printf("\n Enter choice :6- count no of nodes");
        printf(" Enter choice : ");
        scanf("%d", &x);
        switch (x)
        {
        case 1: printf("Choice is 1- to insert an element at begining");
                printf("\n Input data to insert at the beginning of the list : ");
                scanf("%d", &num);
                NodeInsertatBegin(num);
                displayList();
                break;
        case 2: printf("Choice is 2- to insert an element at end");
                printf("\n Input data to insert at the end of the list : ");
                scanf("%d", &num);
                NodeInsertatEnd(num);
                displayList();
                break;
        case 3: printf("Choice is 3- to insert an element at specific position");
                printf("\n Input data to insert an element at specific position : ");
                scanf("%d", &num);
                printf("\n Input position to insert data : ");
                scanf("%d", &pos);
                ClLinsertNodeAtAny(num,pos);
                displayList();
                break;
        case 4: printf("Choice is 4- to deletion an element at begining");
                FirstNodeDeletion();
                displayList();
                break;
        case 5: printf("Choice is 5- to deletion an element at end");
                LastNodeDeletion();
                displayList();
                break;
        case 6: printf("Choice is 6- count no of nodes");
                NodeCount();
                break;
        default: printf("Wrong Choice");
                break;
        }
        return 0;
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
void NodeInsertatBegin(int num)
{
        struct node *fnNode;
        fnNode = (struct node*)malloc(sizeof(struct node));
        if(fnNode == NULL)
        {
                printf(" Memory can not be allocated.");
        }
        else
        {
                fnNode->num = num;
                fnNode->nextptr = stnode;
                stnode = fnNode;
        }
}
void NodeInsertatEnd(int num)
{
        struct node *fnNode, *tmp;
        fnNode = (struct node*)malloc(sizeof(struct node));
        if(fnNode == NULL)
        {
                printf(" Memory can not be allocated.");
        }
        else
        {
                fnNode->num = num;
                fnNode->nextptr = NULL;
                tmp = stnode;
                while(tmp->nextptr != NULL)
                        tmp = tmp->nextptr;
                tmp->nextptr = fnNode;
        }
}
void ClLinsertNodeAtAny(int num, int pos)
{
        struct node *newnode, *curNode;
        int i;

        if(stnode == NULL)
        {
                printf(" No data found in the List yet.");
        }
        else if(pos == 1)
        {
                NodeInsertatBegin(num);
        }
        else
        {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->num = num;
                curNode = stnode;
                for(i=2; i<=pos-1; i++)
                {
                        curNode = curNode->nextptr;
                }
                newnode->nextptr = curNode->nextptr;
                curNode->nextptr = newnode;
        }
}
void FirstNodeDeletion()
{
        struct node *toDelptr;
        if(stnode == NULL)
        {
                printf(" There are no node in the list.");
        }
        else
        {
                toDelptr = stnode;
                stnode = stnode->nextptr;
                printf("\n Data of node 1 which is being deleted is :  %d\n", toDelptr->num);
                free(toDelptr);
        }
}
void LastNodeDeletion()
{
        struct node *toDelLast, *preNode;
        if(stnode == NULL)
        {
                printf(" There is no element in the list.");
        }
        else
        {
                toDelLast = stnode;
                preNode = stnode;
                while(toDelLast->nextptr != NULL)
                {
                        preNode = toDelLast;
                        toDelLast = toDelLast->nextptr;
                }
                if(toDelLast == stnode)
                {
                        stnode = NULL;
                }
                else
                {
                        preNode->nextptr = NULL;
                }
                free(toDelLast);
        }
}
int NodeCount()
{
        int ctr = 0;
        struct node *tmp;
        tmp = stnode;
        while(tmp != NULL)
        {
                ctr++;
                tmp = tmp->nextptr;
        }
        return ctr;
}
void displayList()
{
        struct node *tmp;
        if(stnode == NULL)
        {
                printf(" List is empty.");
        }
        else
        {
                tmp = stnode;
                while(tmp != NULL)
                {
                        printf("%d ", tmp->num);
                        tmp = tmp->nextptr;
                }
        }
}
