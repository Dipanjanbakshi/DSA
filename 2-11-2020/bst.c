#include <stdio.h>
#include <stdlib.h>
struct node
{
        int info;
        struct node*left;
        struct node*right;
};
typedef struct node BST;
BST *LOC, *PAR;
void search(BST *root, int item)
{
        BST *save,*ptr;
        if (root == NULL)
        {
                LOC = NULL;
                PAR=NULL;
        }
        if (item == root->info)
        {
                LOC = root;
                PAR = NULL;
                return;
        }
        if (item < root->info)
        {
                save = root;
                ptr = root->left;
        }
        else
        {
                save = root;
                ptr = root->right;
        }
        while( ptr != NULL)
        {
                if (ptr->info == item)
                {
                        LOC = ptr;
                        PAR = save;
                        return;
                }
                if(item < ptr->info)
                {
                        save = ptr;
                        ptr = ptr->left;
                }
                else
                {
                        save = ptr;
                        ptr = ptr->right;
                }
        }
        LOC = NULL;
        PAR = save;
        return;
}
struct node*insert(struct node*r, int x)
{
        if (r == NULL)
        {
                r = (struct node*)malloc(sizeof(struct node));
                r->info = x;
                r->left = r->right = NULL;
                return r;
        }
        else if (x < r->info)
                r->left = insert(r->left, x);
        else if (x > r->info)
                r->right = insert(r->right, x);
        return r;
}
int main()
{
        struct node* root = NULL;
        int x;
        int element;
        char ch;
        printf("\nEnter an element: ");
        scanf("%d", &x);
        root = insert(root, x);
        printf("\nDo you want to enter another element :y or n");
        scanf(" %c",&ch);
        while (ch == 'y')
        {
                printf("\nEnter an element:");
                scanf("%d", &x);
                root = insert(root,x);
                printf("\nPress y or n to insert another element: y or n: ");
                scanf(" %c", &ch);
        }


        printf("\nEnter element to be searched:  ");
        scanf("%d", &element);
        search(root, element);
        if(LOC != NULL)
                printf("\n%d Found in Binary Search Tree !!\n",element);
        else
                printf("\nIt is not present in Binary Search Tree\n");

        return 0;
}
