////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
// Other Files:      sendsig.c
//		     intdate.c
// Semester:         CS 354 Spring 2018
//
// Author:           William Pechous
// Email:            wpechous@wisc.edu
// CS Login:         pechous
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          N/A
//
// Online sources:   N/A
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;

void SIGFPE_HNDLR(int signal){
	printf("Error: division by zero attempted.\n");
	printf("Total number of operations completed successfully: %d\n", counter);
	printf("Exiting now...\n");
	exit(0);
}

void SIGINT_HNDLR(int signal){
	printf("Total number of operations completed: %d\n", counter);
	printf("Exiting now...\n");
	exit(0);
}

int main(){

	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIGFPE_HNDLR;
	sa.sa_flags = 0;
	if(sigaction(SIGFPE, &sa, NULL) != 0){
	  printf("SIGFPE handler failed to bind.\n");
	  exit(1);
	}

	struct sigaction sa1;
	memset(&sa1, 0, sizeof(sa1));
	sa1.sa_handler = SIGINT_HNDLR;
	sa1.sa_flags = 0;
	if(sigaction(SIGINT, &sa1, NULL) != 0){
	  printf("SIGINT failed to bind.\n");
	  exit(1);
	}

	char buffer[100];
	int input1;
	int input2;
	int end;
	int remainder;
	while(1){
		printf("Enter first integer: ");
		fgets(buffer, 100, stdin);
		input1 = atoi(buffer);
		printf("Ener second integer: ");
		fgets(buffer, 100, stdin);
		input2 = atoi(buffer);
		end = input1/input2;
		remainder = input1 % input2;
		printf("%d / %d is %d with a remainder of %d\n", input1, input2, end, remainder);
		counter++;
	}

	return 0;
}

