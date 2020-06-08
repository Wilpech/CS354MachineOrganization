////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      intdate.c
//		     division.c
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
#include <time.h>
#include <unistd.h>
#include <string.h>

int get_pid(char* entry){
	if(strspn(entry, "0123456789") != strlen(entry)) {
	  printf("Usage: <signal type> <pid> \n");
	  exit(1);
	}
	int track;
	sscanf(entry, "%d", &track);
	return track;
}

int main(int argc,  char *argv[]){
	if(argc != 3){
	  printf("Usage: <signal type> <pid>\n");
	  exit(1);
	}
	int success;
	int pid = get_pid(argv[2]);
	char *end = argv[1];
	if(end[1] == 'i'){
	   success = kill(pid,SIGINT);
	}
	else if(end[1] == 'u'){
	   success = kill(pid,SIGUSR1);
	}
	else {
	printf("Usage: <signal type> <pid>\n");
	exit(1);
	}
	if(success == -1){
	  printf("Signal failed.\n");
	  exit(1);
	}
	return 0;
}
