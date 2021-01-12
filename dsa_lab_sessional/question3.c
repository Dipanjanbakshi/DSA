#include <stdio.h>
#include <stdlib.h>

struct node {
        int num;
        struct node * preptr;
        struct node * nextptr;
}*stnode, *ennode;
void DlListcreation(int n);
void DlLinsertNodeAtAny(int num, int pos);
void displayDlList();

int main()
{
        int n,num1;
        stnode = NULL;
        ennode = NULL;
        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        DlListcreation(n);
        displayDlList();
        int z=n+(n-1);
        for(int i=1; i<z; i=i+2)
        {
                printf(" Input data for the alernate position : ");
                scanf("%d", &num1);
                DlLinsertNodeAtAny(num1,i);

        }
        displayDlList();
        return 0;
}

void DlListcreation(int n)
{
        int i, num;
        struct node *fnNode;

        if(n >= 1)
        {
                stnode = (struct node *)malloc(sizeof(struct node));

                if(stnode != NULL)
                {
                        printf(" Input data for node 1 : ");
                        scanf("%d", &num);

                        stnode->num = num;
                        stnode->preptr = NULL;
                        stnode->nextptr = NULL;
                        ennode = stnode;
                        for(i=2; i<=n; i++)
                        {
                                fnNode = (struct node *)malloc(sizeof(struct node));
                                if(fnNode != NULL)
                                {
                                        printf(" Input data for node %d : ", i);
                                        scanf("%d", &num);
                                        fnNode->num = num;
                                        fnNode->preptr = ennode;
                                        fnNode->nextptr = NULL;
                                        ennode->nextptr = fnNode;
                                        ennode = fnNode;
                                }
                                else
                                {
                                        printf(" Memory can not be allocated.");
                                        break;
                                }
                        }
                }
                else
                {
                        printf(" Memory can not be allocated.");
                }
        }
}

void DlLinsertNodeAtAny(int num, int pos)
{
        int i;
        struct node * newnode, *tmp;
        if(ennode == NULL)
        {
                printf(" No data found in the list!\n");
        }
        else
        {
                tmp = stnode;
                i=1;
                while(i<pos-1 && tmp!=NULL)
                {
                        tmp = tmp->nextptr;
                        i++;
                }
                if(tmp!=NULL)
                {
                        newnode = (struct node *)malloc(sizeof(struct node));
                        newnode->num = num;
                        newnode->nextptr = tmp->nextptr;
                        newnode->preptr = tmp;
                        if(tmp->nextptr != NULL)
                        {
                                tmp->nextptr->preptr = newnode;
                        }
                        tmp->nextptr = newnode;
                }
                else
                {
                        printf(" The position you entered, is invalid.\n");
                }
        }
}
void displayDlList()
{
        struct node * tmp;
        if(stnode == NULL)
        {
                printf(" No data found in the List yet.");
        }
        else
        {
                tmp = stnode;
                while(tmp != NULL)
                {
                        printf(" %d\n", tmp->num);
                        tmp = tmp->nextptr;
                }
        }
}
