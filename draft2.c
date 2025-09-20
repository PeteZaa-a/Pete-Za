#include <stdio.h>
#include <string.h>

void menu() {
    printf("Student application system\n");
    printf("=====MENU LISTS=====\n");
    printf("|   1.Add user     |\n|   2.Edit user    |\n|   3.Update user  |\n|   4.Search user  |\n|   5.Show user    |\n====================\n");
}

void add_user() {
    FILE *fptr;
    fptr = fopen("test2.csv","a");
    char data[80];
    printf("Enter data to add: ");
    scanf("%s",&data);
    fprintf(fptr, "%s\n", data);
    }

void file_check() {
    FILE *fptr;
    fptr = fopen("test2.csv", "r");  
    
    if (fptr == NULL)
    {
        printf("Error");
    }
    else
    {
        printf("Complete");
    }
    
    
        
    }

void edit_user() {

}

void show_all() {
    char data[100];
    FILE *fptr;
    fptr = fopen("test2.csv", "r");
    // fgets(data, 100, fptr);
    // printf("%s",data);

    while (fgets(data, 100, fptr) != NULL)
    {
        printf("%s\n",data);
    }
    
}

void search() {

    char user[20];
    FILE *fptr;
    fptr = fopen("test2.csv", "r");
    printf("Enter user to search: ");
    scanf("%s", &user);

   char *doing = strstr(fptr,user);
   if (doing != NULL)
   {
    printf("Found");
   }
   
    
}

    

int main () {

    FILE *fptr;
    fptr = fopen("test2.csv","a"); 

    if (fptr == NULL) {
        printf("Cannot open file\n");
    }
    else {
        printf("File created\n");
    }
    
    menu();

    int menu;
    printf("Enter menu: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        printf("Doing add user mode\n");
        add_user() ;
        file_check();
        break;
    
    case 2:
        printf("Edit user mode");
        break;

    case 3:
        printf("Delete user mode");
        printf("Enter user to delete");
        break;

    case 4:
        printf("Search\n");
        search();

        break;
    
    case 5:
        printf("Show all user\n");
        show_all();

        break;
    default:
        printf("Try again\n");
        break;
    }

    fclose(fptr);

}
