#include<string.h>
#include<stdio.h>
#define BUF_LEN 256
#include <time.h>
#include "Billing.h"

//two queues are needed
//first queue contains the code of the food item
//second queue contains the quantity of food item
//dequeue the element of the first queue and find the address of the node of the food item containing that code
//dequeue the element of the second queue and multiplied with the price of the food item
//this will continue until the queue is not empty
int total_amount(food_item t, queue q1, queue q2)
{
    float sum = 0;
    while(!isEmpty(q1) && !isEmpty(q2))
    {
        int x = dequeue(&q1);
        node *p = search_food_item(t,x);
        int y = dequeue(&q2);
        sum = sum + (p->price)*y;
    }
    return sum;
}

//counting the digits of the number
//required for output manipulation
int count_digit(int x)
{
    int count = 0;
    while(x > 0)
    {
        x = x/10;
        count++;
    }
    return count;
}


//function for display the bill
void billing(food_item t, queue q1, queue q2)
{
    static int z = 0;
    printf("-----------------------------------------------------------------------\n");
    printf("NO  FOOD ITEM                PRICE          NO OF ITEMS    TOTAL AMOUNT\n");
    printf("-----------------------------------------------------------------------\n");
    while(!isEmpty(q1) && !isEmpty(q2))
    {
        int x = dequeue(&q1);
        node *p = search_food_item(t,x);
        int y = dequeue(&q2);
        printf("%d]  %s",++z, p->item_name);
        int l = strlen(p->item_name);
        for(int i = l + 1; i <= 25; i++)
        {
            printf(" ");
        }
        printf("%0.2f", p->price);
        l = count_digit(p->price);
        for(int i = l + 1; i <= 12; i++)
        {
            printf(" ");
        }
        printf("%d", y);
        l = count_digit(y);
        for(int i = l + 1; i <= 15; i++)
        {
            printf(" ");
        }
        float amount = (p->price)*y;
        printf("%0.2f",amount);
        printf("\n");

    }
    return;
}


//function for calculating the subtotal, GST, discount and total bill
void print_total(food_item t, queue q1, queue q2)
{
    printf("-----------------------------------------------------------------------\n");
    printf("SUBTOTAL                                                   ");
    float bill = total_amount(t,q1,q2);
    printf("%0.2f\n", bill);
    float gst = 0.09*bill;
    printf("GST(@9%%)                                                   ");
    printf("%0.2f\n", gst);
    float discount = 0.05*bill;
    printf("DISCOUNT(@5%%)                                              ");
    printf("%0.2f\n",discount);
    float total = bill + gst - discount;
    printf("-----------------------------------------------------------------------\n");
    printf("TOTAL BILL                                                 ");
    printf("%0.2f\n", total);
    printf("-----------------------------------------------------------------------\n");
    printf("                             Thank you!!!\n");
}


//printing the bill into the file
void billing_file(char *filename, food_item t, queue q1, queue q2)
{
    //display_date_time();
    FILE *fp;
    fp = fopen(filename, "a");//file is opened in an append mode so that it will append the output every time
    static int z = 0;
    fprintf(fp, "-----------------------------------------------------------------------\n");
    fprintf(fp, "NO  FOOD ITEM                PRICE          NO OF ITEMS    TOTAL AMOUNT\n");
    fprintf(fp, "-----------------------------------------------------------------------\n");
    while(!isEmpty(q1) && !isEmpty(q2))
    {
        int x = dequeue(&q1);
        node *p = search_food_item(t,x);
        int y = dequeue(&q2);
        fprintf(fp, "%d]  %s",++z, p->item_name);
        int l = strlen(p->item_name);
        for(int i = l + 1; i <= 25; i++)
        {
            fprintf(fp, " ");
        }
        fprintf(fp, "%0.2f", p->price);
        l = count_digit(p->price);
        for(int i = l + 1; i <= 12; i++)
        {
            fprintf(fp, " ");
        }
        fprintf(fp, "%d", y);
        l = count_digit(y);
        for(int i = l + 1; i <= 15; i++)
        {
            fprintf(fp, " ");
        }
        float amount = (p->price)*y;
        fprintf(fp, "%0.2f",amount);
        fprintf(fp, "\n");

    }
    fclose(fp);
    return;
}


//printing the total into the file
void print_total_file(char *filename, food_item t, queue q1, queue q2)
{
    FILE *fp;
    fp = fopen(filename,"a");
    fprintf(fp, "-----------------------------------------------------------------------\n");
    fprintf(fp, "SUBTOTAL                                                   ");
    float bill = total_amount(t,q1,q2);
    fprintf(fp, "%0.2f\n", bill);
    float gst = 0.09*bill;
    fprintf(fp, "GST(@9%%)                                                   ");
    fprintf(fp, "%0.2f\n", gst);
    float discount = 0.05*bill;
    fprintf(fp, "DISCOUNT(@5%%)                                              ");
    fprintf(fp, "%0.2f\n",discount);
    float total = bill + gst - discount;
    fprintf(fp, "-----------------------------------------------------------------------\n");
    fprintf(fp, "TOTAL BILL                                                 ");
    fprintf(fp, "%0.2f\n", total);
    fprintf(fp, "-----------------------------------------------------------------------\n");
    fprintf(fp, "                             Thank you!!!\n");
    fclose(fp);
}



void design()
{
    printf("************************************************************\n");
    printf("                       MENU CARD\n");
    printf("************************************************************\n");
}

void accept_custmor_info(char name[], char address[], char gmail[], char mobile[])
{
    printf("Enter name:");
    gets(name);

    printf("Enter address:");
    gets(address);

    printf("Enter G-mail:");
    gets(gmail);

    do{
        printf("Enter mobile no:");//check the number whether is it 10 digits or not
        gets(mobile);
        if(strlen(mobile) == 10)
            break;
        else
        {
            printf("oops!wrong mobile number!!!\n");
            continue;
        }
    }while(1);

}


//for printing the information of user on the console and into the file
void print_custmor_info(char *filename, char name[], char address[], char gmail[], char mobile[])
{
    FILE *fp;
    fp = fopen(filename, "a");
    printf("Customer Details....\n");
    printf("Name:");
    puts(name);

    printf("Address:");
    puts(address);

    printf("G-mail:");
    puts(gmail);

    printf("Mobile no:");
    puts(mobile);

    fprintf(fp, "Customer Details....\n");
    fprintf(fp, "NAME:%s\n", name);
    fprintf(fp, "ADDRESS:%s\n", address);
    fprintf(fp, "G-MAIL:%s\n", gmail);
    fprintf(fp, "MOBILE NO:%s\n", mobile);

    fclose(fp);
}

//display time, date, day and year
void display_time_date()
{
    time_t t;   // not a primitive datatype
    time(&t);
    int l = strlen(ctime(&t));
    l = l/2;
    l = 36 - l;
    for(int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%s", ctime(&t));// gives the string containing day time month and year
}

