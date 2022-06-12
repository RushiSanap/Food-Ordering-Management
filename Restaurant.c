
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_LEN 256
#include <time.h>
#include "Restaurant.h"
#include "MenuCard.h"

void init_restaurant(restaurant *r){
    *r=NULL;
    return;
}

//inserting the restaurant from the file
//for inserting 1 element best time complexity is O(log(n)) while worst time complexity is O(n)
//for inserting n element best time complexity is O(n log(n)) while worst time complexity is O(n^2)
void insert_restaurant_from_file(restaurant *t, char *filename){

    FILE *fp = fopen(filename, "r");        // open the file
    // name address mobile type code
    char size[5], code[5];
    int i = 0, y;
    fgets(size, 5, fp);
    sscanf(size, "%d", &y);//converts the string of digits into the integer data type

    r_node *nn;
    nn = (r_node*)malloc(sizeof(r_node));

    fgets(nn->name, 30, fp);
    delchar(nn->name, 1, strlen(nn->name));

    fgets(nn->address, 50, fp);
    delchar(nn->address, 1, strlen(nn->address));

    fgets(nn->mobile_no, 12, fp);
    delchar(nn->mobile_no, 1, strlen(nn->mobile_no));

    fgets(nn->type, 10, fp);
    delchar(nn->type, 1, strlen(nn->type));

    fgets(code, 5, fp);
    sscanf(code, "%d", &nn->r_code);
    nn->left = NULL;
    nn->right = NULL;
    if(*t == NULL)//tree is empty
    {
        *t=nn;//t is pointing where nn is pointing
    }
    while (i < y-1){


        r_node *nn;
        nn = (r_node*)malloc(sizeof(r_node));

        fgets(nn->name, 30, fp);
        delchar(nn->name, 1, strlen(nn->name));

        fgets(nn->address, 50, fp);
        delchar(nn->address, 1, strlen(nn->address));

        fgets(nn->mobile_no, 12, fp);
        delchar(nn->mobile_no, 1, strlen(nn->mobile_no));

        fgets(nn->type, 10, fp);
        delchar(nn->type, 1, strlen(nn->type));

        fgets(code, 5, fp);
        sscanf(code, "%d", &nn->r_code);

        nn->left = NULL;
        nn->right = NULL;


        r_node *p=NULL, *q = NULL;
        p = *t;
        //tree is empty
        while(p){
            //P->price and data
            q=p;
            if(nn->r_code == p->r_code){
                free(nn);
            }
            else if(nn->r_code < p->r_code){
                p = p->left;
            }
            else if(nn->r_code > p->r_code){
                p =p->right;
            }
        }
        if(nn->r_code < q->r_code){
            q->left = nn;
        }
        else{
            q->right = nn;
        }
        i++;
    }
    fclose(fp);
    return;
}

//time complexity for inorder traversal of all restaurant is O(n)
void inorder_restaurant(restaurant r)//inorder traversal
{
    r_node *p=r;
    static int x = 0;
    if(p)
    {
        inorder_restaurant(p->left);
        printf("%02d] %s",++x, r->name);
        int l = strlen(r->name);
        for(int i = l+1;i<46;i++)
        {
            printf(".");
        }
        printf("%s",r->address);
        printf("\n");
        inorder_restaurant(p->right);
    }
    else return;

}

void inorder_restaurant_veg(restaurant r)//inorder traversal
{
    static int x = 0;
    r_node *p=r;
    if(p)
    {
        inorder_restaurant_veg(p->left);
        if(!strcmp(r->type, "Veg"))
        {
            printf("%02d] %s",++x, r->name);
            int l = strlen(r->name);
            for(int i = l+1;i<46;i++)
            {
                printf(".");
            }
            printf("%s",r->address);
            printf("\n");
        }
        inorder_restaurant_veg(p->right);
    }

}

void inorder_restaurant_non_veg(restaurant r)//inorder traversal
{
    static int x = 0;
    r_node *p=r;
    if(p)
    {
        inorder_restaurant_non_veg(p->left);
        if(!strcmp(r->type, "Non Veg"))
        {
            printf("%02d] %s",++x,r->name);
            int l = strlen(r->name);
            for(int i = l+1;i<46;i++)
            {
                printf(".");
            }
            printf("%s",r->address);
            printf("\n");
        }
        inorder_restaurant_non_veg(p->right);
    }

}


void inorder_restaurant_mixed(restaurant r)//inorder traversal
{
    static int x = 0;
    r_node *p=r;
    if(p)
    {
        inorder_restaurant_mixed(p->left);
        if(!strcmp(r->type, "Mixed"))
        {
            printf("%02d] %s",++x,r->name);
            int l = strlen(r->name);
            for(int i = l+1;i<46;i++)
            {
                printf(".");
            }
            printf("%s",r->address);
            printf("\n");
        }
        inorder_restaurant_mixed(p->right);
    }

}

//searching the restaurant from the code of the restaurant
//for searching 1 element best time complexity is O(log(n)) while worst time complexity is O(n)
//for searching n element best time complexity is O(n log(n)) while worst time complexity is O(n^2)
r_node* search_restaurant(r_node* r,int code) {
    if (r == NULL || r->r_code == code)    //root is null or r_code is present at root
       return r;
    if (r->r_code > code)                  //data is greater than root's r_code
       return search_restaurant(r->left,code);
    else
        return search_restaurant(r->right,code);        // r_code is smaller than root's r_code
}


//display the name of the restaurant in the middle of the two lines on the console
void display_name(restaurant r,int code)
{
    r_node *p = search_restaurant(r,code);
    int l = strlen(p->name);
    l = l/2;
    l = 30 - l;
    printf("************************************************************\n");
    for(int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%s\n", p->name);
    printf("************************************************************\n");
    return;
}

//for displaying the name address and mobile number
//this function is used for billing purpose
void display_name_info(restaurant r,int code)
{
    r_node *p = search_restaurant(r,code);
    int l = strlen(p->name);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < 72; i++)
    {
        printf("*");
    }
    printf("\n");
    for(int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%s\n", p->name);
    for(int i = 0; i < 72; i++)
    {
        printf("*");
    }
    printf("\n");
    l = strlen(p->address);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%s\n", p->address);
    l = strlen(p->mobile_no);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%s\n", p->mobile_no);
    return;
}


//this is for print the header while printing the name of restaurant on the output console
void design1()
{
    for(int i = 0 ; i < 75; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("NO. RESTAURANT NAME");
    for(int i = 0; i < 30; i++)
    {
        printf(" ");
    }
    printf("ADDRESS\n");
    for(int i = 0 ; i < 75; i++)
    {
        printf("*");
    }
    printf("\n");
}

void design2()
{
    for(int i = 0 ; i < 75; i++)
    {
        printf("*");
    }
}


//for displaying the name, address and mobile number of the particular restaurant from the code
//this function is used while printing the fill into the file
void display_name_info_file(char *filename, restaurant r,int code)
{
    FILE *fp;
    fp = fopen(filename, "a");
    r_node *p = search_restaurant(r,code);
    int l = strlen(p->name);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < 72; i++)
    {
        fprintf(fp, "*");
    }
    fprintf(fp, "\n");
    for(int i = 0; i < l; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "%s\n", p->name);
    for(int i = 0; i < 72; i++)
    {
        fprintf(fp, "*");
    }
    fprintf(fp, "\n");
    l = strlen(p->address);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "%s\n", p->address);
    l = strlen(p->mobile_no);
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "%s\n", p->mobile_no);
    time_t t;   // not a primitive datatype
    time(&t);
    l = strlen(ctime(&t));
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "%s\n", ctime(&t));
    fclose(fp);
    return;
}

