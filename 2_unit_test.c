#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const char* student_names[45] = {
    "Somsak Jaidee", "Malee Poka", "Piti Rakthai", "Sunee Meeboon", "Chaiyut Klahan",
    "Areeya Chokdee", "Narongrit Suksabai", "Kanokwan Rungruang", "Thirawat Deesawat", "Orathai Ngamdee",
    "Wanchai Sirimongkol", "Benjawan Phoncharoen", "Surachai Jitpreecha", "Pornthip Saeng-arun", "Anucha Wongyai",
    "Rattana Udomsuk", "Peerapong Boonsong", "Yupin Intharaksa", "Ekkachai Charoensri", "Kanda Phuangmalee",
    "Nattapol Srisawat", "Jariya Kongpraphan", "Teerayuth Suwan", "Patcharin Thongkham", "Prakit Lertkun",
    "Siriporn Boonmee", "Wirot Phetkaew", "Amornrat Chanthasri", "Kiattisak Sawangwong", "Supaporn Ketkaew",
    "Chatchai Rattanaporn", "Wannisa Srijan", "Phanuwat Sriwichai", "Duangporn Thippayarat", "Somchai Prasert",
    "Natcha Inkaew", "Thanathorn Saetang", "Phannee Butdee", "Yutthana Chamnan", "Onanong Phosri",
    "Montri Sukkasem", "Nareerat Panyadee", "Sarawut Yindee", "Tassanee Sangthong", "Wisanu Meekham"
};

const char* relevant_courses[] = {
    "Network Security", "Data Structures and Algorithms", "Ethical Hacking", "Computer Architecture", "Cryptography",
    "Operating Systems", "Digital Forensics", "Database Systems", "Secure Software Development", "Machine Learning",
    "Cyber Threat Intelligence", "Computer Networks", "Malware Analysis", "Object-Oriented Programming", "Cloud Security"
};
const int num_courses = sizeof(relevant_courses) / sizeof(relevant_courses[0]);


void remove_newline2(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void clear_input_buffer2() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void update2(){
    const char* main_filename = "test_update_data.csv";
    const char* temp_filename = "temp_update.csv";
    
    FILE *fptr, *temp;
    char user[50], status[10], line[256];
    int found = 0;
    
    fgets(user, sizeof(user), stdin);
    remove_newline2(user);
    // FIX: เพิ่ม space เพื่อให้ scanf ข้าม \n ที่ค้างอยู่
    scanf(" %9s", status); 
    clear_input_buffer2(); 

    fptr = fopen(main_filename, "r");
    temp = fopen(temp_filename, "w");

    if (fptr == NULL || temp == NULL) {
        perror("Cannot open file for testing");
        if (fptr) fclose(fptr);
        if (temp) fclose(temp);
        return; 
    }
    
    while (fgets(line, 256, fptr)) {
        char templine[256];
        strcpy(templine, line);
        char *token = strtok(templine, ",");
        
        if (token != NULL) {
            if (strcmp(token, user) == 0) {
                char *course = strtok(NULL, ",");
                char *date = strtok(NULL, ",");
                fprintf(temp, "%s,%s,%s,%s\n", user, course, date, status);
                found = 1;
            } else {
                fputs(line, temp);
            }
        }
    }
    
    fclose(fptr);
    fclose(temp); 

    if (found) {
        remove(main_filename);
        rename(temp_filename, main_filename);
    } else {
        remove(temp_filename);
    }
}

void get_line_from_file2(const char* filename, int line_number, char* buffer, size_t buffer_size) {
    FILE* file = fopen(filename, "r");
    if (!file) { buffer[0] = '\0'; return; }
    for (int i = 1; i <= line_number; ++i) {
        if (fgets(buffer, buffer_size, file) == NULL) {
            buffer[0] = '\0';
            break;
        }
    }
    fclose(file);
}

void setup_csv_file() {
    FILE* csv_file = fopen("test_update_data.csv", "w");
    assert(csv_file != NULL);
    for (int i = 0; i < 45; i++) {
        const char* name = student_names[i];
        const char* course = relevant_courses[i % num_courses];
        fprintf(csv_file, "%s,%s,2025-01-%02d,Pending\n", name, course, i + 1);
    }
    fclose(csv_file);
}

void test_update_all_users() {
    printf("======= Running Final Verbose Unit Test for update =======\n\n");

    setup_csv_file();

    for (int i = 0; i < 45; i++) {
        const char* current_user_name = student_names[i];
        char new_status[20];
        char line_before[256], line_after[256];

        printf("--> Processing User: %s\n", current_user_name);

        get_line_from_file2("test_update_data.csv", i + 1, line_before, sizeof(line_before));
        remove_newline2(line_before);
        printf("    Before : [%s]\n", line_before);

        if ((i + 1) % 3 == 0) strcpy(new_status, "Withdrawn");
        else if ((i + 1) % 2 == 0) strcpy(new_status, "Failed");
        else strcpy(new_status, "Passed");

        FILE* temp_input_file = fopen("temp_input.txt", "w");
        fprintf(temp_input_file, "%s\n%s\n", current_user_name, new_status);
        fclose(temp_input_file);
        
        freopen("temp_input.txt", "r", stdin);
        update2();
        freopen("CON", "r", stdin);
        remove("temp_input.txt");

        get_line_from_file2("test_update_data.csv", i + 1, line_after, sizeof(line_after));
        remove_newline2(line_after);
        printf("    After  : [%s]\n", line_after);

        assert(strstr(line_after, new_status) != NULL);
        printf("    Status Check for '%s' PASSED.\n\n", new_status);
    }
    
    remove("test_update_data.csv");

    printf("\nUnit Test for update PASSED\n");
    printf("====================================================================\n");
}

/*
int main() {
    test_update_all_users();
    return 0;
}
   */ 
