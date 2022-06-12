#include <stdio.h>
#include <stdlib.h>
#include "Restaurant.h"
#include "Billing.h"
#define MAX 50

int main()
{
    //8 queues are needed for billing
    queue q1,q2,q3,q4,q5,q6,q7,q8;
    init(&q1,20);
    init(&q2,20);
    init(&q3,20);
    init(&q4,20);
    init(&q5,20);
    init(&q6,20);
    init(&q7,20);
    init(&q8,20);


    food_item t1;
    init_food_item(&t1);


    restaurant r;
    init_restaurant(&r);
    insert_restaurant_from_file(&r, "Restaurant.txt");//form the tree of the restaurant from the file
    char type[10];
    int choice;
    char ch[2];
    printf("Visiting here for the first time??? press h for help otherwise press press any other key ");
    gets(ch);
    if(!strcmp(ch, "h"))//if h is pressed help page will appear on the console
    {
        help();
    }
    char name[MAX], address[MAX], gmail[MAX], mobile[MAX];
    accept_custmor_info(name, address, gmail, mobile);//accept the information of the user
    int item_number, no_of_item;
    while(1){
        printf("\nEnter the type of restaurant(Veg/NonVeg/Mixed) ");
        gets(type);
        if( !strcmp(type, "veg") || !strcmp(type, "Veg")){
            design1();//output manipulation
            inorder_restaurant_veg(r);//display all the veg restaurant of the city
            design2();//output manipulation
            while(1)
            {
                printf("\n\nEnter the choice of restaurant(1/2/3....)");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        display_name(r, 101);
                        insert_food_item(&t1, "VEG1.txt");//inserting the food item from the file
                        design();//output manipulation
                        inorder_food_item(t1);//display the menu card of the restauant
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");//choosing the item
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count)//if the choice is grater than the f_count then it will give the warning
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 101);
                        display_time_date();
                        display_name_info_file("Orchid.txt", r, 101);
                        print_custmor_info("Orchid.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Orchid.txt", t1, q5,q6);
                        print_total_file("Orchid.txt", t1, q7, q8);
                        exit(0);

                    case 2:
                        display_name(r, 102);
                        insert_food_item(&t1, "VEG2.txt");le
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 102);
                        display_time_date();
                        display_name_info_file("Vivanta.txt", r, 102);
                        print_custmor_info("Vivanta.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Vivanta.txt", t1, q5,q6);
                        print_total_file("Vivanta.txt", t1, q7, q8);
                        exit(0);

                    case 3:
                        display_name(r, 103);
                        insert_food_item(&t1, "VEG3.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 103);
                        display_time_date();
                        display_name_info_file("Shivshakti.txt", r, 103);
                        print_custmor_info("Shivshakti.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Shivshakti.txt", t1, q5,q6);
                        print_total_file("Shivshakti.txt", t1, q7, q8);
                        exit(0);

                    default:
                        printf("Oops!!incorrect choice!!!\n");
                        continue;
                }
            }
        }
        else if(!strcmp(type, "Non Veg") || !strcmp(type, "NonVeg")){
            design1();
            inorder_restaurant_non_veg(r);
            design2();
            while(1)
            {
                printf("\n\nEnter the choice of restaurant(1/2/3....)");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        display_name(r, 104);
                        insert_food_item(&t1, "NON1.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 104);
                        display_time_date();
                        display_name_info_file("Haytt.txt", r, 104);
                        print_custmor_info("Haytt.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Haytt.txt", t1, q5,q6);
                        print_total_file("Haytt.txt", t1, q7, q8);
                        exit(0);

                    case 2:
                        display_name(r, 105);
                        insert_food_item(&t1, "NON2.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 105);
                        display_time_date();
                        display_name_info_file("TheO.txt", r, 105);
                        print_custmor_info("TheO.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("TheO.txt", t1, q5,q6);
                        print_total_file("TheO.txt", t1, q7, q8);
                        exit(0);

                    case 3:
                        display_name(r, 106);
                        insert_food_item(&t1, "NON3.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 106);
                        display_time_date();
                        display_name_info_file("Ramme.txt", r, 106);
                        print_custmor_info("Ramme.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Ramme.txt", t1, q5,q6);
                        print_total_file("Ramme.txt", t1, q7, q8);
                        exit(0);

                    default:
                        printf("Oops!!incorrect choice!!!\n");
                        continue;
                }
            }
        }
        else if(!strcmp(type, "mixed") || !strcmp(type, "Mixed")){
            design1();
            inorder_restaurant_mixed(r);
            design2();
            while(1)
            {
                printf("\n\nEnter the choice of restaurant(1/2/3....)");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        display_name(r, 107);
                        insert_food_item(&t1, "MIXED1.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 107);
                        display_time_date();
                        display_name_info_file("Marriot.txt", r, 107);
                        print_custmor_info("Marriot.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Marriot.txt", t1, q5,q6);
                        print_total_file("Marriot.txt", t1, q7, q8);
                        exit(0);

                    case 2:
                        display_name(r, 108);
                        insert_food_item(&t1, "MIXED2.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 108);
                        display_time_date();
                        display_name_info_file("Sayaji.txt", r, 108);
                        print_custmor_info("Sayaji.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Sayaji.txt", t1, q5,q6);
                        print_total_file("Sayaji.txt", t1, q7, q8);
                        exit(0);

                    case 3:
                        display_name(r, 109);
                        insert_food_item(&t1, "MIXED3.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 109);
                        display_time_date();
                        display_name_info_file("Panchratna.txt", r, 109);
                        print_custmor_info("Panchratna.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Panchratna.txt", t1, q5,q6);
                        print_total_file("Panchratna.txt", t1, q7, q8);
                        exit(0);

                    case 4:
                        display_name(r, 110);
                        insert_food_item(&t1, "MIXED4.txt");
                        design();
                        inorder_food_item(t1);
                        printf("************************************************************\n");
                        while(1)
                        {
                            printf("Choose the particulars(1/2/3....):");
                            scanf("%d",&item_number);
                            if(item_number == 0)
                                break;
                            if(item_number > f_count )
                            {
                                printf("Warning!!!Please select the proper one\n");
                                continue;
                            }
                            printf("Enter the no of particulars:");
                            scanf("%d",&no_of_item);
                            enqueue(&q1,item_number);
                            enqueue(&q3,item_number);
                            enqueue(&q2,no_of_item);
                            enqueue(&q4,no_of_item);
                            enqueue(&q5,item_number);
                            enqueue(&q7,item_number);
                            enqueue(&q6,no_of_item);
                            enqueue(&q8,no_of_item);
                        }
                        display_name_info(r, 110);
                        display_time_date();
                        display_name_info_file("Ibis.txt", r, 110);
                        print_custmor_info("Ibis.txt", name, address, gmail, mobile);
                        billing(t1,q1,q2);
                        print_total(t1,q3,q4);
                        billing_file("Ibis.txt", t1, q5,q6);
                        print_total_file("Ibis.txt", t1, q7, q8);
                        exit(0);

                    default:
                        printf("Oops!!incorrect choice!!!\n");
                        continue;
                }
            }
        }
        else
        printf("oops!You have typed wrong!!!\n");
        continue;

    }
}
