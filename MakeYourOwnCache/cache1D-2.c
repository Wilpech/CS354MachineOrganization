////////////////////////////////////////////////////////////////////////////////
// Main File:        cache1D.c
// This File:        cache1D.c
// Other Files:      cache2Drows.c
//                   cache2Dcols.c
//                   cache1D.c
//                   csim.c
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

int arr[100000];

int main() {
    int i;
    for (i = 0; i < 100000; i++) {
         arr[i] = i;
        }
    return 0;
}
