

typedef struct r_node{
    struct r_node *left;
    char name[40];//name of the restaurant
    char address[50];//address of the restaurant
    char mobile_no[11];//for storing the contact number of the restaurant
    char type[10];//veg or non veg or mixed
    int r_code;//unique code for each restaurant
    struct r_node *right;
}r_node;

typedef r_node *restaurant;

void init_restaurant(restaurant *r);//initialisation

void insert_restaurant(restaurant *r, char *n, char *adr,char *mobile, char *type, int code);//inserting the restuarant

void insert_restaurant_from_file(restaurant *t, char *filename);

void inorder_restaurant(restaurant r);

void inorder_restaurant_veg(restaurant r);//displaying the veg restaurant

void inorder_restaurant_non_veg(restaurant r);//for displaying the non veg restaurant

void display_name(restaurant r,int r_code);//display the name of restaurant

void display_info_restaurant(restaurant r, int r_code);//display the information of the restaurant

r_node *search_restaurant(r_node *r, int code);//searching the restaurant from the code

void inorder_restaurant_mixed(restaurant r);//display the mixed restaurant

void display_date_time();
