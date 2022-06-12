#include "MenuCard.h"
#include "queue.h"
#define MAX 50

int total_amount(food_item t, queue q1, queue q2);//for calculating the total amount of selected food items

int count_digit(int x);//for counting the number of digits

void billing(food_item t, queue q1, queue q2);//for billing purpose

void print_total(food_item t, queue q1, queue q2);//for calculating the subtotal, GST, discount and total amount

void display_time_date();//for displaying current date and time

void design();//for output manipulation

void accept_custmor_info(char name[], char address[], char gmail[], char mobile[]);//accepting the details of the customer

void print_custmor_info(char *filename, char name[], char address[], char gmail[], char mobile[]);//printing the details of the customer

void print_total_file(char *filename, food_item t, queue q1, queue q2);//printing the data into the file

void billing_file(char *filename, food_item t, queue q1, queue q2);//printing the bill into the file




