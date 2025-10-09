#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void remove_newline(char *s);
extern void add_user_auto(const char *name, const char *course, const char *date, const char *status);
extern void update_status_auto(const char *name, const char *new_status);
extern void delete_user_auto(const char *name);
extern void show_all();
extern void search_user_auto(const char *query);

void e2e_t() {
    printf("===== E2E Testing =====\n");

    // 1. Add user
    printf("\n[1] Adding User...\n");
    add_user_auto("John Doe", "CS101", "2025-10-10", "pending");

    // 2. Show all users
    printf("\n[2] Show all after add...\n");
    show_all();

    // 3. Update status
    printf("\n[3] Updating status...\n");
    update_status_auto("John Doe", "approved");

    // 4. Search user
    printf("\n[4] Searching for 'John'...\n");
    search_user_auto("John");

    // 5. Delete user
    printf("\n[5] Deleting user...\n");
    delete_user_auto("John Doe");

    // 6. Final check
    printf("\n[6] Show all after delete...\n");
    show_all();

    printf("\n[E2E Testing Completed]\n");
}

void add_user_auto(const char *name, const char *course, const char *date, const char *status) {
    FILE *fptr = fopen("test2.csv", "a");
    if (fptr == NULL) {
        perror("Cannot open file");
        return;
    }
    fprintf(fptr, "%s,%s,%s,%s\n", name, course, date, status);
    fclose(fptr);
    printf("Auto-added: %s,%s,%s,%s\n", name, course, date, status);
}

void update_status_auto(const char *user, const char *new_status) {
    FILE *fptr = fopen("test2.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    char line[256];
    int updated = 0;

    while (fgets(line, sizeof(line), fptr)) {
        char line_copy[256];
        strcpy(line_copy, line);
        char *token = strtok(line_copy, ",");
        if (token && strcmp(token, user) == 0) {
            char *course = strtok(NULL, ",");
            char *date = strtok(NULL, ",");
            fprintf(temp, "%s,%s,%s,%s\n", user, course, date, new_status);
            updated = 1;
        } else {
            fputs(line, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    remove("test2.csv");
    rename("temp.csv", "test2.csv");

    if (updated)
        printf("Updated status for %s to %s\n", user, new_status);
    else
        printf("User %s not found\n", user);
}

void delete_user_auto(const char *user) {
    FILE *fptr = fopen("test2.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    char line[256];
    int deleted = 0;

    while (fgets(line, sizeof(line), fptr)) {
        char line_copy[256];
        strcpy(line_copy, line);
        char *token = strtok(line_copy, ",");
        if (token && strcmp(token, user) == 0) {
            deleted = 1;
            continue;
        }
        fputs(line, temp);
    }

    fclose(fptr);
    fclose(temp);

    remove("test2.csv");
    rename("temp.csv", "test2.csv");

    if (deleted)
        printf("Deleted user: %s\n", user);
    else
        printf("User not found: %s\n", user);
}

void search_user_auto(const char *query) {
    FILE *fptr = fopen("test2.csv", "r");
    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, query)) {
            printf("Found: %s", line);
            found = 1;
        }
    }

    fclose(fptr);
    if (!found)
        printf("No matching records for: %s\n", query);
}
