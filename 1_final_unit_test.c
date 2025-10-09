#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void setup_test_files() {
    FILE* data_file = fopen("test_data.txt", "w");
    assert(data_file != NULL);
    fprintf(data_file, "Alice Wang\nWeb Development\n2025-11-10\nPending\n");
    fprintf(data_file, "Bob Boy\nData Engineering\n2025-11-11\nApproved\n");
    fprintf(data_file, "Love Chocolate\nSoftware Testing\n2025-11-12\nRejected\n");
    fprintf(data_file, "Copter Medical\nTPAT 1\n2024-12-02\nPending\n");
    fprintf(data_file, "Huawei P30\nReverse Engineering\n2023-09-02\nRejected\n");
    fprintf(data_file, "Samsung S23\nPresent Day\n2025-10-09\nApproved\n");
    fprintf(data_file, "Ipad Air7\nNo Way\n2022-02-24\nPending\n");
    fprintf(data_file, "Dell Latitude\nWorking Space\n2013-08-16\nPending\n");
    fprintf(data_file, "Hp Omen\nBeautiful Laptop\n2024-03-12\nApproved\n");
    fprintf(data_file, "Lenovo Legion\nGood Price\n2017-11-30\nApproved\n");
    fprintf(data_file, "Asus Tuf\nWifi Error\n2025-04-24\nRejected\n");
    fprintf(data_file, "Acer Nitro\nCheap\n2025-06-31\nRejected\n");
    fprintf(data_file, "Msi Cyborg\nModern Design\n2025-03-29\nApproved\n");
    fprintf(data_file, "Macbook Pro Tuf\nExpensive Tee\n2024-08-14\nPending\n");
    fprintf(data_file, "Gigabyte Aorus\nSpec Good\n2022-11-20\nRejected\n");
    fprintf(data_file, "LG Gram\nLight Thin\n2025-01-04\nRejected\n");
    fprintf(data_file, "Amd Ryzen\nPrice Good\n2025-02-14\nApproved\n");
    fprintf(data_file, "Intel Core\nData Structure\n2024-12-26\nPending\n");
    fprintf(data_file, "Krich KU\nMechanical Engineering\n2021-02-03\nApproved\n");
    fprintf(data_file, "Nek KMITL\nBioTechnology\n2020-12-24\nApproved\n");    
    fprintf(data_file, "Tae NULL\nNULL\n2023-11-26\nPending\n");
    fprintf(data_file, "Poom CU\nEngineering\n2024-04-07\nApproved\n");    
    fprintf(data_file, "Copter KMITL\nInformation Technology\n2022-09-09\nApproved\n");
    fprintf(data_file, "Mote KKU\nComputer Science\n2014-05-06\nApproved\n");    
    fprintf(data_file, "Phop KMUTNB\nIndustrial Engineering\n2016-12-13\nApproved\n");
    fprintf(data_file, "Pete KMITL\nComputer Engineering\n2017-09-15\nApproved\n");    
    fprintf(data_file, "Fix TU\nCivil Engineering\n2018-01-12\nApproved\n");
    fprintf(data_file, "Karn CU\nTecknickarnphaet\n2017-12-14\nApproved\n");    
    fprintf(data_file, "Hachi SWU\nLIC\n2024-09-25\nApproved\n");
    fprintf(data_file, "Onet NULL\nNULL\n2024-12-13\nPending\n");    
    fprintf(data_file, "Sun NULL\nNULL\n2018-12-26\nPending\n");
    fprintf(data_file, "Jek KU\nMechatronics Engineering\n2017-08-15\nApproved\n");    
    fprintf(data_file, "Guts CU\nArts\n2024-08-29\nApproved\n");
    fprintf(data_file, "Fluke TU\nStatistic\n2016-09-27\nApproved\n");    
    fprintf(data_file, "Kla BBU\nBiochemistry\n2024-12-15\nApproved\n");
    fprintf(data_file, "V KMUTNB\nRobot Engineering\n2001-06-02\nApproved\n");    
    fprintf(data_file, "Praewa KU\nEconomics\n2025-10-08\nApproved\n");
    fprintf(data_file, "Pearwa SWU\nPolsci\n2025-10-05\nApproved\n");    
    fprintf(data_file, "Fern KU\nChemistry\n2021-08-14\nApproved\n");
    fprintf(data_file, "C KU\nVet\n2025-10-01\nApproved\n");    
    fprintf(data_file, "Katae KMITL\nFood Industrial\n2025-09-29\nApproved\n");
    fprintf(data_file, "Chompu MFU\nCosmetics\n2022-07-29\nApproved\n");    
    fprintf(data_file, "Fah BU\nNited\n2020-10-11\nApproved\n");
    fprintf(data_file, "Jaya TU\nBusiness\n2020-06-25\nApproved\n");    
    fprintf(data_file, "Cream KMITL\nBioTechnology\n2025-08-09\nApproved\n");
    fprintf(data_file, "JJ CU\nAccounting\n2025-09-14\nApproved\n");    
    fprintf(data_file, "Kawfieng SU\nEducation\n2025-04-19\nApproved\n");
    fprintf(data_file, "Yam MFU\nCosmetics\n2024-12-26\nApproved\n");    
    fprintf(data_file, "Poey NULL\nNULL\n2025-07-30\nPending\n");
    fprintf(data_file, "Chompoo KMUTNB\nEnvironment\n2021-06-20\nApproved\n");    
    fprintf(data_file, "Peak NULL\nNULL\n2025-10-07\nApproved\n");
    fprintf(data_file, "Punch CU\nFood\n2025-10-04\nApproved\n");    
    fprintf(data_file, "Grace KU\nFishing\n2022-06-30\nApproved\n");
    fprintf(data_file, "Loma SWU\nMathematics\n2024-04-17\nApproved\n");    
    fprintf(data_file, "Mo Unknow\nUnknow\n2021-03-05\nPending\n");
    fprintf(data_file, "Moda RU\nRadio Technology\n2025-10-01\nApproved\n");    
    fprintf(data_file, "Aunjai Unknow\nUnknow\n2020-09-18\nPending\n");
    fprintf(data_file, "Mew KMITL\nEnvironment\n2025-10-02\nApproved\n");    
    fprintf(data_file, "Stamp SWU\nFinance\n2025-09-26\nApproved\n");
    fprintf(data_file, "Aum Disappear\nDisappear\n2000-01-31\nRejected\n");    
    fclose(data_file);

    FILE* expect_file = fopen("expected_results.txt", "w");
    assert(expect_file != NULL);
    fprintf(expect_file, "Alice Wang,Web Development,2025-11-10,Pending\n");
    fprintf(expect_file, "Bob Boy,Data Engineering,2025-11-11,Approved\n");
    fprintf(expect_file, "Love Chocolate,Software Testing,2025-11-12,Rejected\n");
    fprintf(expect_file, "Copter Medical,TPAT 1,2024-12-02,Pending\n");
    fprintf(expect_file, "Huawei P30,Reverse Engineering,2023-09-02,Rejected\n");
    fprintf(expect_file, "Samsung S23,Present Day,2025-10-09,Approved\n");
    fprintf(expect_file, "Ipad Air7,No Way,2022-02-24,Pending\n");
    fprintf(expect_file, "Dell Latitude,Working Space,2013-08-16,Pending\n");
    fprintf(expect_file, "Hp Omen,Beautiful Laptop,2024-03-12,Approved\n");
    fprintf(expect_file, "Lenovo Legion,Good Price,2017-11-30,Approved\n");
    fprintf(expect_file, "Asus Tuf,Wifi Error,2025-04-24,Rejected\n");
    fprintf(expect_file, "Acer Nitro,Cheap,2025-06-31,Rejected\n");
    fprintf(expect_file, "Msi Cyborg,Modern Design,2025-03-29,Approved\n");
    fprintf(expect_file, "Macbook Pro Tuf,Expensive Tee,2024-08-14,Pending\n");
    fprintf(expect_file, "Gigabyte Aorus,Spec Good,2022-11-20,Rejected\n");
    fprintf(expect_file, "LG Gram,Light Thin,2025-01-04,Rejected\n");
    fprintf(expect_file, "Amd Ryzen,Price Good,2025-02-14,Approved\n");
    fprintf(expect_file, "Intel Core,Data Structure,2024-12-26,Pending\n");
    fprintf(expect_file, "Krich KU,Mechanical Engineering,2021-02-03,Approved\n");
    fprintf(expect_file, "Nek KMITL,BioTechnology,2020-12-24,Approved\n");    
    fprintf(expect_file, "Tae NULL,NULL,2023-11-26,Pending\n");
    fprintf(expect_file, "Poom CU,Engineering,2024-04-07,Approved\n");    
    fprintf(expect_file, "Copter KMITL,Information Technology,2022-09-09,Approved\n");
    fprintf(expect_file, "Mote KKU,Computer Science,2014-05-06,Approved\n");    
    fprintf(expect_file, "Phop KMUTNB,Industrial Engineering,2016-12-13,Approved\n");
    fprintf(expect_file, "Pete KMITL,Computer Engineering,2017-09-15,Approved\n");    
    fprintf(expect_file, "Fix TU,Civil Engineering,2018-01-12,Approved\n");
    fprintf(expect_file, "Karn CU,Tecknickarnphaet,2017-12-14,Approved\n");    
    fprintf(expect_file, "Hachi SWU,LIC,2024-09-25,Approved\n");
    fprintf(expect_file, "Onet NULL,NULL,2024-12-13,Pending\n");    
    fprintf(expect_file, "Sun NULL,NULL,2018-12-26,Pending\n");
    fprintf(expect_file, "Jek KU,Mechatronics Engineering,2017-08-15,Approved\n");    
    fprintf(expect_file, "Guts CU,Arts,2024-08-29,Approved\n");
    fprintf(expect_file, "Fluke TU,Statistic,2016-09-27,Approved\n");    
    fprintf(expect_file, "Kla BBU,Biochemistry,2024-12-15,Approved\n");
    fprintf(expect_file, "V KMUTNB,Robot Engineering,2001-06-02,Approved\n");    
    fprintf(expect_file, "Praewa KU,Economics,2025-10-08,Approved\n");
    fprintf(expect_file, "Pearwa SWU,Polsci,2025-10-05,Approved\n");    
    fprintf(expect_file, "Fern KU,Chemistry,2021-08-14,Approved\n");
    fprintf(expect_file, "C KU,Vet,2025-10-01,Approved\n");    
    fprintf(expect_file, "Katae KMITL,Food Industrial,2025-09-29,Approved\n");
    fprintf(expect_file, "Chompu MFU,Cosmetics,2022-07-29,Approved\n");    
    fprintf(expect_file, "Fah BU,Nited,2020-10-11,Approved\n");
    fprintf(expect_file, "Jaya TU,Business,2020-06-25,Approved\n");    
    fprintf(expect_file, "Cream KMITL,BioTechnology,2025-08-09,Approved\n");
    fprintf(expect_file, "JJ CU,Accounting,2025-09-14,Approved\n");    
    fprintf(expect_file, "Kawfieng SU,Education,2025-04-19,Approved\n");
    fprintf(expect_file, "Yam MFU,Cosmetics,2024-12-26,Approved\n");    
    fprintf(expect_file, "Poey NULL,NULL,2025-07-30,Pending\n");
    fprintf(expect_file, "Chompoo KMUTNB,Environment,2021-06-20,Approved\n");    
    fprintf(expect_file, "Peak NULL,NULL,2025-10-07,Approved\n");
    fprintf(expect_file, "Punch CU,Food,2025-10-04,Approved\n");    
    fprintf(expect_file, "Grace KU,Fishing,2022-06-30,Approved\n");
    fprintf(expect_file, "Loma SWU,Mathematics,2024-04-17,Approved\n");    
    fprintf(expect_file, "Mo Unknow,Unknow,2021-03-05,Pending\n");
    fprintf(expect_file, "Moda RU,Radio Technology,2025-10-01,Approved\n");    
    fprintf(expect_file, "Aunjai Unknow,Unknow,2020-09-18,Pending\n");
    fprintf(expect_file, "Mew KMITL,Environment,2025-10-02,Approved\n");    
    fprintf(expect_file, "Stamp SWU,Finance,2025-09-26,Approved\n");
    fprintf(expect_file, "Aum Disappear,Disappear,2000-01-31,Rejected\n");    
    fclose(expect_file);
}
void remove_newline1(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void add_user1() {
    FILE *fptr;
    fptr = fopen("test_add_user_data.csv", "a"); 
    if (fptr == NULL) { return; }
    char name[256], course[50], date[25], status[10];
    fgets(name, sizeof(name), stdin); 
    remove_newline1(name); 
    fgets(course, sizeof(course), stdin);
    remove_newline1(course); 
    scanf("%24s", date); 
    scanf(" %9s", status); 
    fprintf(fptr, "%s,%s,%s,%s\n", name, course, date, status);
    fclose(fptr); 
}

void test_add_user_in_loop() {
    printf("======= Running Final Verified Unit Test for add_user =======\n");

    FILE* data_file = fopen("test_data.txt", "r");
    FILE* expect_file = fopen("expected_results.txt", "r");

    assert(data_file != NULL);
    assert(expect_file != NULL);

    char name_in[256], course_in[50], date_in[25], status_in[10];
    char expect_line[256];
    int test_case = 0;

    while (fgets(name_in, sizeof(name_in), data_file) != NULL &&
           fgets(course_in, sizeof(course_in), data_file) != NULL &&
           fgets(date_in, sizeof(date_in), data_file) != NULL &&
           fgets(status_in, sizeof(status_in), data_file) != NULL &&
           fgets(expect_line, sizeof(expect_line), expect_file) != NULL)
    {
        test_case++;
        printf("--> Running Test Case #%d\n", test_case);
        
        FILE* temp_input_file = fopen("temp_input.txt", "w");
        assert(temp_input_file != NULL);
        fprintf(temp_input_file, "%s%s%s%s", name_in, course_in, date_in, status_in);
        fclose(temp_input_file);

        freopen("temp_input.txt", "r", stdin);
        remove("test_add_user_data.csv");
        add_user1();
        freopen("CON", "r", stdin);

        FILE* result_file = fopen("test_add_user_data.csv", "r");
        assert(result_file != NULL);
        
        char file_content[256];
        fgets(file_content, sizeof(file_content), result_file);
        fclose(result_file);

        remove_newline1(file_content);
        remove_newline1(expect_line);

        printf("\n--- DEBUGGING Case #%d ---\n", test_case);
        printf("                : Name,Course,Date,Status\n");
        printf("Result from CSV : [%s]\n", file_content);
        printf("Expected Result : [%s]\n", expect_line);
        printf("---------------------------\n");

        assert(strcmp(file_content, expect_line) == 0);
        printf("    Case #%d PASSED.\n\n", test_case);

        remove("temp_input.txt");
    }
    
    fclose(data_file);
    fclose(expect_file);
    remove("test_add_user_data.csv");
    remove("test_data.txt");
    remove("expected_results.txt");

    printf("\nAll %d Test Cases for add_user PASSED!\n", test_case);
    printf("===============================================================\n");
}

/*int main() {
    setup_test_files();
    test_add_user_in_loop();
    return 0;
}
    */
