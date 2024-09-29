#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char ssn[16], label[10], month_nb[10], dept[3], comm[6];
    int gender, year, month, department, commune, order_number, key;
    int year_1900, year_2000;

    printf("What is your social security number (15 digits) ? : ");
    scanf("%15s", ssn);

    if (strlen(ssn) != 15) {
        
        printf("The social security number must be 15 digits long.\n");
        return 1;
    
    }

    gender = ssn[0] - '0';
    
    if (gender == 1) {

        strcpy(label, "Mr.");
    
    } 
    
    else if (gender == 2) {
        
        strcpy(label, "Ms.");
   
    } 
    
    else {
        
        printf("The gender indicated in the social security number is invalid.\n");
        return 1;
    
    }

    year = ((ssn[1] - '0') * 10) + (ssn[2] - '0');
    
    year_1900 = year + 1900;
    year_2000 = year + 2000;

    month = ((ssn[3] - '0') * 10) + (ssn[4] - '0');

    switch (month) {

        case 1: strcpy(month_nb, "January"); break;
        case 2: strcpy(month_nb, "February"); break;
        case 3: strcpy(month_nb, "March"); break;
        case 4: strcpy(month_nb, "April"); break;
        case 5: strcpy(month_nb, "May"); break;
        case 6: strcpy(month_nb, "June"); break;
        case 7: strcpy(month_nb, "July"); break;
        case 8: strcpy(month_nb, "August"); break;
        case 9: strcpy(month_nb, "September"); break;
        case 10: strcpy(month_nb, "October"); break;
        case 11: strcpy(month_nb, "November"); break;
        case 12: strcpy(month_nb, "December"); break;
        
        default:
            
            printf("The month indicated in the social security number is invalid.\n");
            return 1;
    
    }
   
    strncpy(dept, ssn + 5, 2);
    
    dept[2] = '\0';

    department = atoi(dept);

    strncpy(comm, ssn + 5, 5);
    
    comm[5] = '\0';
    commune = atoi(comm);

    order_number = ((ssn[10] - '0') * 100) + ((ssn[11] - '0') * 10) + (ssn[12] - '0');
    key = ((ssn[13] - '0') * 10) + (ssn[14] - '0');

    printf("You are : %s\n", label);
    printf("You were born in : %d or in %d\n", year_1900, year_2000);
    printf("In the month of : %s\n", month_nb);
    printf("In the department : %d\n", department);
    printf("In the commune : %d\n", commune);
    printf("Order number : %d\n", order_number);
    printf("Key : %d\n", key);

    return 0;

}
