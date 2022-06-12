#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MenuCard.h"

void init_food_item(food_item *t){
    *t=NULL;
    return;
}


//function for deleting the the newline character from the string
//a is for how many characters you want to delete and b for from which character you want to delete the string
void delchar(char *x,int a, int b){
  if ((a+b-1) <= strlen(x))
  {
    strcpy(&x[b-1],&x[a+b-1]);
  }
}

//inserting the food item on the basis of their amount in ascending order
//for inserting 1 element worst time complexity is O(n) and best time complexity is O(log(n))
//for inserting n element worst time complexity is O(n^2) and best time complexity is O(nlog(n))
void insert_food_item(food_item *t, char *filename){
    static int x = 0;
    char price[10];

    FILE *fp = fopen(filename,"r");

    int i = 0, y;
    fgets(price, 100, fp);
    sscanf(price, "%d", &y);
    f_count = y;
    while (i < y){
        node *nn;
        nn = (node*)malloc(sizeof(node));
        fgets(nn->item_name, 500, fp);
        delchar(nn->item_name, 1, strlen(nn->item_name));
        fgets(price, 1000, fp);
        float amount;
        sscanf(price, "%f", &amount);
        nn->price = amount;
        nn->code = ++x;
        nn->left = NULL;
        nn->right = NULL;
        i++;

        if(*t == NULL)//tree is empty
        {
            *t=nn;//t is pointing where nn is pointing
            continue;
        }
        //t is pointing to the root node of the tree

        node *p=NULL, *q = NULL;
        p = *t;
        //tree is empty
        while(p){
            //P->price and data
            q=p;
            if(amount == p->price && !strcmp(p->item_name, nn->item_name)){
                free(nn);
            }
            else if(amount < p->price){
                p = p->left;
            }
            else if(amount >= p->price){
                p =p->right;
            }
        }
        if(amount< q->price){
            q->left = nn;
        }
        else{
            q->right = nn;
        }
    }

    fclose(fp);

    return;

}


//display the menu card in sorted order according to the food price
void inorder_food_item(food_item t)//inorder traversal
{
    static int y = 0;
    node *p=t;
    if(p)
    {
        inorder_food_item(p->left);
        printf("%02d] %s",++y, t->item_name);
        int l = strlen(t->item_name);
        for(int i = l+1;i<50;i++)
        {
            printf(" ");
        }
        printf("%0.2f",p->price);
        printf("\n");
        inorder_food_item(p->right);
    }
    else return;
}


//searching the food item with the help of code
//for searching 1 element worst time complexity is O(n) and best time complexity is O(log(n))
//for searching n element worst time complexity is O(n^2) and best time complexity is O(nlog(n))
node* search_food_item(food_item t,int fcode) {
    if (t == NULL || t->code == fcode)    //root is null or r_code is present at root
       return t;
    if (t->code > fcode)                  //data is greater than root's code
       return search_food_item(t->left,fcode);
    else
        return search_food_item(t->right,fcode);        // code is smaller than root's code
}
