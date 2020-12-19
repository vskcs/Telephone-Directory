/*
 *18MCME17- VS Koushik
 *Telephone Management System Program in C
 *The data(contacts) that is created is stored in the contacts.txt file
 *which is created when you start to add contacts.
 *
 * All the functions are declared in functions.h
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"functions.h"

//function declaration
void getData();

void close(){
	printf("\033[36m-------------------------------------------------\n\033[0m");
	printf("\tThankyou. Have a nice day!\n");
	printf("\033[36m-------------------------------------------------\n\033[0m");
	exit(1);
}

void start(){
    printf("\033[36m-------------------------------------------------\n\033[0m");
    //printf("\n----------TELEPHONE MANAGEMENT SYSTEM----------\n");
	printf("\n\t1. Add New Contact\n\t2. Search Contacts\n\t3. Display all Contacts\n\t4. Exit\n\n");
    printf("Select an option: ");
	int opt;
    scanf("%d", &opt);
	switch (opt){
	case 1: addContact();
		break;
	case 2: getData();
		break;
	case 3: displayContacts();
		break;
	case 4: close();
		break;
	default: printf("\tInvalid Input\n");
		exit(1);
        break;
	}
}
//Function to search and get the Data
void getData() {
    int ch; 
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("Search contacts by:\n");
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("\t1.Phone number\n");
    printf("\t2.Name\n");
    printf("\t3.City\n");
    printf("\t4.Go back to main menu\n");
    printf("\033[36m-------------------------------------------------\n\033[0m");
    printf("Select an option: ");
    scanf("%d", &ch);  
    	switch(ch) {
	        case 1:
	            searchBy("phoneno");
	            break;
	        case 2:
	            searchBy("name");
	            break;
	        case 3:
	            searchBy("city");
	            break;
			case 4:
				start();
				break;
	        default:
	            printf("\n\tInvalid Input\n");
	}
    return;
}

int main() {
    printf("\033[36m-------------------------------------------------\n\033[0m");
	printf("\033[36m------------TELEPHONE MANAGEMENT SYSTEM----------\n\033[0m");
	while(1)
	start();
	return 0; 
}

