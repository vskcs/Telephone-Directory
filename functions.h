#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char search[20];
char ph[20], name[20], city[20];
char *p;

struct Contacts {
    char phoneno[20];
    char name[20];
    char address[25];
};

//Search by Phone/Name/City
void searchBy(char * value);

// Checking the phone number(length=10 and contains only digits)
int checkPhone(char phone[20]);

// Checking for spaces in the name
int checkName(char name[20]);

// Adding a new customer
void addContact();

// Display all the contacts
void displayContacts();



void searchBy(char *value ){
    FILE *ptr;
    ptr = fopen("contacts.txt", "r");
    if(ptr == NULL) {
        printf("\t\tError Reading File!\n");
        return;
    }
    int flag =0;
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("Enter the %s to search: ",value);
    scanf("%s", search);
    printf("\033[36m=================================================\n\033[0m");
    // printf("\033[36m-------------------------------------------------\n\033[0m");
    
    while(fscanf(ptr, "%s", ph) != 
    EOF) {
        fscanf(ptr, "%s", name);
        fscanf(ptr, "%s", city);
        if(strcmp(value,"phoneno")==0){
            p = strstr(ph, search);
        }else if(strcmp(value,"name")==0){
            p = strstr(name, search);
        }else if(strcmp(value,"city")==0){
            p = strstr(city, search);
        }
		// If phone number matches print the output.
        if(p) {
            if(flag!=1){
                printf("%-20s%-20s%-20s\n","Phone No","Name","City");
                printf("\033[36m=================================================\n\033[0m");
            }
            flag = 1;
            printf("%-20s%-20s%-20s\n", ph, name, city);
        }
    }
    // When flag=0 then there are no records.
    if(flag == 0) {
        printf("\tNo Records Found!\n");
    } else {
    printf("\033[36m-------------------------------------------------\n\033[0m");    
    }
    return;
}

// Checking the phone number(length=10 and contains only digits)
int checkPhone(char phone[20]){
	int i;
	if(strlen(phone) == 10){
		for(i=0; i<10; i++) {
	        if(isdigit(phone[i]) == 0) {
	        	printf("\tCharacters not allowed\n");
	            return 0;
	        }
	    }
	    return 1;
	}else{
		printf("\tPhone number must be 10 digits long.\n");
		return 0;
	}
}

// Checking for spaces in the name
int checkName(char name[20]) {
	int i;
	if(strlen(name)<18){
		for(i=0; i<strlen(name); i++) {
	        // If there is a space, returns true
	        if(name[i]==' ') {
	        	printf("\tNo spaces in Name.\n");
	            return 1;
	        }
	    }	    
    	return 0;
	}
	// Name shouldn't be greater than 18 characters since we have allocatted only 20 bits.
	else{
		printf("Name should not be more than 18 characters.\n");
		return 1;
	}
}

void addContact() {
	
	struct Contacts d;
    FILE *ptr;
    ptr = fopen("contacts.txt", "a");
    if(ptr == NULL) {
        printf("\nError writing to file!\n");
        return;
    }
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("Enter the details of the contact:\n");
    printf("Phone number: ");
    scanf("%s", d.phoneno);
    while(!checkPhone(d.phoneno)) {
        printf("Phone number: ");
        scanf("%s", d.phoneno);
    }

    printf("Name (without spaces): ");
    scanf("%s", d.name);
    while(checkName(d.name)) {
        printf("Name (without spaces): ");
        scanf("%s", d.name);
    }

    printf("City: ");
    scanf("%s", d.address);

    // Writing to the file
    fprintf(ptr, "%s\t", d.phoneno);
    fprintf(ptr, "%s\t", d.name);
    fprintf(ptr, "%s\n", d.address);
    printf("\n\tContact added succesfully!\n");
    fclose(ptr);
    return;
}

void displayContacts(){
    FILE *ptr;
    ptr = fopen("contacts.txt", "r");
     char ph[20], name[20], city[20]; 
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("\tDisplaying all contacts\n");
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("%-20s%-20s%-20s\n","Phone No","Name","City");
    printf("\033[36m-------------------------------------------------\n\033[0m");
    while(fscanf(ptr, "%s", ph) != EOF) {
        fscanf(ptr, "%s", name);
        fscanf(ptr, "%s", city);
        printf("%-20s%-20s%-20s\n", ph, name, city);
            // printf("\033[36m-------------------------------------------------\n\033[0m");
    }
}
