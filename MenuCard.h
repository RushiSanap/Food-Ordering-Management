
typedef struct node{
    struct node *left;      //left pointer
    float price;              //price of the food item
    char item_name[50];        //storing the name of the food item
    int code;               //unique code is given to each food packet whose starting digits is of code of restaurant
    //int stock;            //storing the number of items of a particular food
    struct node *right;     //right pointer
}node;

int f_count;//for keeping the count of the food item

typedef node *food_item;

void init_food_item(food_item *t);

void insert_food_item(food_item *t, char *filename);//for inserting the food item from file

void inorder_food_item(food_item t);//displaying the food item in the sorted order according the amount
