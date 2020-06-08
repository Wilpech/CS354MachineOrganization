///////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c
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

int timer = 3;
int counter = 0;

void SIGALRM_HNDLR(int signal){
	time_t time_curr;
	int value = time(&time_curr);
	if(value == -1){
	   printf("Time could not be output\n");
	   exit(1);
	}
	printf("PID: %d | ", getpid());
	printf("Current Time: %s", ctime(&time_curr));
	alarm(timer);
}

void user_SIGHANDLER(int signal){
	printf("SIGUSR1 caught!\n");
	counter++;
}

void int_SIGHANDLER(int signal){
	printf("Signal Received.\n");
	printf("Signal received %d times. Exiting...\n", counter);
	exit(0);
}

int main(){
	alarm(timer);
	struct sigaction sigact;
	memset(&sigact, 0, sizeof(sigact));
	sigact.sa_handler = SIGALRM_HNDLR;
	sigact.sa_flags = 0;
	if(sigaction(SIGALRM, &sigact, NULL) != 0){
	  printf("Binding to SIGALRM handler failed.\n");
	  exit(1);
	}

	struct sigaction sigact1;
	memset(&sigact1, 0, sizeof(sigact1));
	sigact1.sa_handler = user_SIGHANDLER;
	sigact1.sa_flags = 0;
	if(sigaction(SIGUSR1, &sigact1, NULL) != 0){
	  printf("Binding ot SIGUSR1 handler failed.\n");
	  exit(1);
	}

	struct sigaction signal_action2;
	memset(&signal_action2, 0, sizeof(signal_action2));
	signal_action2.sa_handler = int_SIGHANDLER;
	signal_action2.sa_flags = 0;
	if(sigaction(SIGINT, &signal_action2, NULL) != 0){
	  printf("Binding to SIGINT handler failed.\n");
	  exit(1);
	}

	while(1){
	}

	return 0;
}
