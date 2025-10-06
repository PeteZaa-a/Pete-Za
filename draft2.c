#include <stdio.h>
#include <string.h>

void menu_list() {
    printf("Student application system\n");
    printf("======MENU LISTS======\n");
    printf("|   1.Add user       |\n");
    printf("|   2.Delete user    |\n");
    printf("|   3.Update status  |\n");
    printf("|   4.Search user    |\n");
    printf("|   5.Show all       |\n");
    printf("|   6.TESTING 1      |\n");
    printf("|   7.TESTING 2      |\n");
    printf("|   8.Exit           |\n"); 
    printf("======================\n");

}

void add_user() {
    FILE *fptr;
    fptr = fopen("test2.csv","a");
    char name[15], surname[30], course[15], date[25], status[10], confirm;
    printf("Enter data to add\n");
    printf("Enter name & surname: ");
    scanf("%s %s",&name, &surname);
    printf("Enter course name: ");
    scanf("%s", &course);
    printf("Enter date, Use format = yyyy-mm-dd\n");
    printf("Enter date:");
    scanf("%s", &date);
    printf("Enter status: ");
    scanf("%s", &status);

    printf("Your data is %s %s %s %s %s\n", name ,surname, course, date, status);
    fprintf(fptr, "%s %s, %s, %s, %s\n",name, surname, course, date, status);
       
    }

void show_all() {
    char data[100];
    FILE *fptr;
    fptr = fopen("test2.csv", "r");
    // fgets(data, 100, fptr);
    // printf("%s",data);

    while (fgets(data, 100, fptr) != NULL)
    {
        printf("%s",data);
    }
    
}

void search() {
    FILE *fptr;
    fptr = fopen("test2.csv", "r");
    char search[20];
    printf("Enter to search: ");
    scanf("%s", search);
    printf("Searching %s\n",search);
    char data[250];
    while (fgets(data, 250, fptr) != NULL)
    {
        if (strstr(data, search) != NULL)
        {
            printf("%s", data);
        }
       
    }

    
}

void update(){

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
    
    menu_list();

    char name[15], surname[30], course[15], date[25], status[10];
    int menu;
    printf("Enter menu: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        printf("Doing add user mode\n");
        add_user() ;
        break;
    
    case 2:
        printf("Delete user mode");
        break;

    case 3:
        printf("Update status mode");
        printf("Enter user to update status: ");
        break;

    case 4:
        printf("Search mode\n");
        search();

        break;
    
    case 5:
        printf("Show all user\n");
        show_all();

        break;

    case 6:
        printf("File Tester\n");


        break;
    default:
        printf("Try again\n");
        break;
    }

    fclose(fptr);

}
