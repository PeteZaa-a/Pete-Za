#include <stdio.h>
#include <string.h>

void menu() {
    printf("Student application system\n");
    printf("=====MENU LISTS=====\n");
    printf("|   1.Add user     |\n|   2.Edit user    |\n|   3.Update user  |\n|   4.Search user  |\n====================\n");
}

void add_user() {
        FILE *fptr;
        fptr = fopen("test2.csv","a");
        char name[20];
        printf("Enter data to add: ");
        scanf("%s",&name);
        fputs(name,fptr);
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
    
    
    default:
        printf("Try again\n");
        break;
    }

    fclose(fptr);
}