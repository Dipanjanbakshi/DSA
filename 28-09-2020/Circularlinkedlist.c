#include <stdio.h>
#include <stdlib.h>

struct node {
        int num;
        struct node * nextptr;
}*stnode;


void ClListcreation(int n);
void ClLinsertNodeAtBeginning(int num);
void displayClList();

int main()
{
        int n,num;
        stnode = NULL;
        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        ClListcreation(n);
        displayClList();
        printf("\n");
        printf(" Input data to be inserted at the beginning : ");
        scanf("%d", &num);
        ClLinsertNodeAtBeginning(num);
        displayClList();
        return 0;
}

void ClListcreation(int n)
{
        int i, num;
        struct node *preptr, *newnode;

        if(n >= 1)
        {
                stnode = (struct node *)malloc(sizeof(struct node));

                printf(" Input data for node 1 : ");
                scanf("%d", &num);
                stnode->num = num;
                stnode->nextptr = NULL;
                preptr = stnode;
                for(i=2; i<=n; i++)
                {
                        newnode = (struct node *)malloc(sizeof(struct node));
                        printf(" Input data for node %d : ", i);
                        scanf("%d", &num);
                        newnode->num = num;
                        newnode->nextptr = NULL;
                        preptr->nextptr = newnode;
                        preptr = newnode;
                }
                preptr->nextptr = stnode;
        }
}
void ClLinsertNodeAtBeginning(int num)
{
        struct node *newnode, *curNode;
        if(stnode == NULL)
        {
                printf(" No data found in the List yet.");
        }
        else
        {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->num = num;
                newnode->nextptr = stnode;
                curNode = stnode;
                while(curNode->nextptr != stnode)
                {
                        curNode = curNode->nextptr;
                }
                curNode->nextptr = newnode;
                stnode = newnode;
        }
}
void ClListDeleteMiddle(int pos)
{
        int delNode,k=1;
        delNode=pos;
        p=stnode;
        while(k!=delNode)
        {
            q=p;
            p=p->nextptr;
            k++;
        }
        q->nextptr=p->nextptr;
        printf("\n The deleted node is : %d",p->num);
        free(p);
}
void displayClList()
{
        struct node *tmp;
        int n = 1;

        if(stnode == NULL)
        {
                printf(" No data found in the List yet.");
        }
        else
        {
                tmp = stnode;
                printf("\n\n Data entered in the list are :\n");

                do {
                        printf("%d  ", tmp->num);

                        tmp = tmp->nextptr;
                        n++;
                }while(tmp != stnode);
        }
}
