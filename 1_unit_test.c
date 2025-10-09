#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// ===================================================================
// ส่วนที่ 1: ฟังก์ชันที่จำเป็น (เหมือนเดิม)
// ===================================================================

void remove_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void add_user() {
    FILE *fptr;
    fptr = fopen("test_add_user_data.csv", "a"); 
    if (fptr == NULL) {
        perror("Cannot open file for testing");
        return; 
    }
    char name[256], course[50], date[25], status[10];
    fgets(name, sizeof(name), stdin); 
    remove_newline(name); 
    fgets(course, sizeof(course), stdin);
    remove_newline(course); 
    scanf("%24s", date); 
    scanf("%9s", status); 
    fprintf(fptr, "%s,%s,%s,%s\n", name, course, date, status);
    fclose(fptr); 
}

// ===================================================================
// ---> ส่วนใหม่: ฟังก์ชันสำหรับสร้างไฟล์ข้อมูลทดสอบโดยอัตโนมัติ
// ===================================================================
void setup_test_files() {
    // สร้างไฟล์ test_data.txt
    FILE* data_file = fopen("test_data.txt", "w");
    assert(data_file != NULL);
    fprintf(data_file, "Alice Wonderland\nWeb Development\n2025-11-10\nPending\n");
    fprintf(data_file, "Bob Builder\nData Engineering\n2025-11-11\nApproved\n");
    fprintf(data_file, "Charlie Chocolate\nSoftware Testing\n2025-11-12\nRejected\n");
    fclose(data_file);

    // สร้างไฟล์ expected_results.txt
    FILE* expected_file = fopen("expected_results.txt", "w");
    assert(expected_file != NULL);
    fprintf(expected_file, "Alice Wonderland,Web Development,2025-11-10,Pending\n");
    fprintf(expected_file, "Bob Builder,Data Engineering,2025-11-11,Approved\n");
    fprintf(expected_file, "Charlie Chocolate,Software Testing,2025-11-12,Rejected\n");
    fclose(expected_file);
}


// ===================================================================
// ส่วนที่ 2: ฟังก์ชันทดสอบ (เหมือนเดิม)
// ===================================================================

void test_add_user_in_loop() {
    printf("======= Running Self-Contained Unit Test for add_user =======\n");

    FILE* data_file = fopen("test_data.txt", "r");
    FILE* expected_file = fopen("expected_results.txt", "r");

    assert(data_file != NULL);
    assert(expected_file != NULL);

    char name_in[256], course_in[50], date_in[25], status_in[10];
    char expected_line[256];
    int test_case = 0;

    while (fgets(name_in, sizeof(name_in), data_file) != NULL &&
           fgets(course_in, sizeof(course_in), data_file) != NULL &&
           fgets(date_in, sizeof(date_in), data_file) != NULL &&
           fgets(status_in, sizeof(status_in), data_file) != NULL &&
           fgets(expected_line, sizeof(expected_line), expected_file) != NULL)
    {
        test_case++;
        printf("--> Running Test Case #%d\n", test_case);
        
        FILE* temp_input_file = fopen("temp_input.txt", "w");
        assert(temp_input_file != NULL);
        fprintf(temp_input_file, "%s%s%s%s", name_in, course_in, date_in, status_in);
        fclose(temp_input_file);

        freopen("temp_input.txt", "r", stdin);
        remove("test_add_user_data.csv");
        add_user();
        freopen("CON", "r", stdin);

        FILE* result_file = fopen("test_add_user_data.csv", "r");
        assert(result_file != NULL);
        
        char file_content[256];
        fgets(file_content, sizeof(file_content), result_file);
        fclose(result_file);
        
        remove_newline(expected_line);
        strcat(expected_line, "\n");

        assert(strcmp(file_content, expected_line) == 0);
        printf("    Case #%d PASSED.\n", test_case);

        remove("temp_input.txt");
    }
    
    fclose(data_file);
    fclose(expected_file);
    remove("test_add_user_data.csv");
    remove("test_data.txt");
    remove("expected_results.txt");

    printf("\n✅ All %d Test Cases for add_user PASSED!\n", test_case);
    printf("===============================================================\n");
}


// ===================================================================
// ส่วนที่ 3: ฟังก์ชัน main สำหรับรัน Unit Test (อัปเดตเล็กน้อย)
// ===================================================================

int main() {
    // 1. เรียกฟังก์ชันให้สร้างไฟล์ข้อมูลทดสอบก่อน
    setup_test_files();
    
    // 2. รันฟังก์ชันทดสอบ
    test_add_user_in_loop();
    
    return 0;
}