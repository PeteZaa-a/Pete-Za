#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "1_final_unit_test.c"
#include "2_unit_test.c"
#include "e2ee.c"

void remove_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}



void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
    printf("|   8.E2E TESTING    |\n"); 
    printf("|   9.Exit           |\n"); 
    printf("======================\n");

}

void add_user() {
    FILE *fptr;
    fptr = fopen("test2.csv", "a");
    if (fptr == NULL) 
    {
        perror("Cannot open file");
        return; 
    }
    char name[256], course[50], date[25], status[10];
    printf("Enter data to add\n");    
    printf("Enter name & surname: ");
    fgets(name, sizeof(name), stdin); 
    remove_newline(name); 
    printf("Enter course name: ");
    fgets(course, sizeof(course), stdin);
    remove_newline(course); 
    printf("Enter date, Use format = yyyy-mm-dd\n");
    printf("Enter date: ");
    scanf("%24s", date); 
    printf("Enter status: ");
    scanf("%9s", status); 
    printf("Your data is %s,%s,%s,%s\n", name, course, date, status);
    fprintf(fptr, "%s,%s,%s,%s\n", name, course, date, status);
    printf("Data saved");
    fclose(fptr); 
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
    fclose(fptr);
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
    FILE *fptr, *temp;
    char user[50],status[20], line[256];
    int found = 0;
    
    printf("\nUpdate status mode\n");
    show_all();
    printf("Enter user (Name Surname) to update status: ");
    fgets(user, sizeof(user), stdin);
    remove_newline(user);
    printf("Enter new status: ");
    scanf("%19s", status);
    clear_input_buffer(); 

    fptr= fopen("test2.csv", "r");
    temp = fopen("temp.csv", "w");

    if (fptr == NULL || temp == NULL) 
    {
        perror("Cannot open file");
        fclose(fptr);
        fclose(temp);
        return; 
    }
    
    while (fgets(line, 256, fptr)) 
    {
        char templine[256];
        strcpy(templine, line);

        char *token = strtok(templine, ",");
        char *fields[5]; 
        int colum = 0;

        while (token != NULL && colum < 5) 
        {
            fields[colum++] = token;
            token = strtok(NULL, ",");
        }
        
        if (colum >= 1) 
        {
            remove_newline(fields[0]); 
            
            if (strcmp(fields[0], user) == 0) 
            {    
                fprintf(temp, "%s,%s,%s,%s\n", fields[0], fields[1], fields[2], status);
                found = 1;
                continue; 
            }
        }
        
        fputs(line, temp);
    }
    
    fclose(fptr);
    fclose(temp); 

    if (found)
    {
        if (remove("test2.csv") != 0) 
        {
            perror("Error cannot delete old file");
            return;
        }
        if (rename("temp.csv", "test2.csv") != 0) 
        {
            perror("Cannot rename file");
            return;
        }
        printf("Status updated successful\n");
    } 
    else 
    {
        remove("temp.csv");
        printf("Cannot find %s\n", user);
    }
    
    return;
}

void test_add(){
    setup_test_files();
    test_add_user_in_loop();
}

void test_update() {
    test_update_all_users();
}

void delete() {

    FILE *fptr, *temp_file;
    char line[256];
    char user[20];
    char confirm;
    
    printf("Delete mode\n");
    show_all();
    printf("Enter user to delete: ");
    fgets(user, sizeof(user), stdin);
    remove_newline(user);

    printf("Are you sure to delete data of %s: ", user);
    scanf("%c", &confirm);
    if (tolower(confirm) != 'y')
    {
        printf("Cancel deletion");
        return;
    }
    

    fptr = fopen("test2.csv", "r");
    temp_file = fopen("temp.csv", "w");

    if (fptr == NULL || temp_file == NULL) 
    {
        perror("Cannot open file");
        fclose(fptr);
        fclose(temp_file);
        return;

    }

    
    int deleted = 0;

    while (fgets(line, 256, fptr) != NULL)
    {
        char temp_line[256];
        strcpy(temp_line, line);

        char *token;
        char *rest = temp_line;

        token = strtok(rest, ",");

        if (token != NULL)
        {
            remove_newline(token);
            if (strcmp(token, user) == 0)
            {
                deleted = 1;
                continue;
            }
            
        }
        fputs(line, temp_file);

    }

    fclose(fptr);
    fclose(temp_file);   

    if (deleted)
    {
        if (remove("test2.csv") != 0)
        {
            perror("Error cannot delete old file");
            return;
        }
        
        if (rename("temp.csv", "test2.csv") != 0)
        {
            perror("Cannot rename file");
            return;
        }
        
        printf("Succesfull to delete %s", user);
    }
    
    else
    {
        remove("temp.csv");
        printf("User not found");
    }
    


}

int main () {
    int menu;
    char name[15], surname[30], course[15], date[25], status[10];
    do {
        menu_list();
        printf("Enter menu: ");
        scanf("%d", &menu);
        clear_input_buffer();
        switch (menu)
        {
        case 1:
            printf("Doing add user mode\n");
            add_user() ;
            break;
    
        case 2:
            printf("Delete user mode");
            delete();
            break;

        case 3:
            printf("Update status mode\n");
            update();
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
            printf("Tester 1 (Add User)\n");
            test_add();
            break;
        case 7:
            printf("Tester 2 (Update user)\n");
            test_update();
            break;
        case 8:
            printf("End to End Testing\n");
            e2e_t();
            break;
        case 9:
            printf("Exiting program");
            break;
        default:
            printf("Try again\n");
            menu_list();
            break;
        }

    } while (menu != 9);

    return 0;
}
