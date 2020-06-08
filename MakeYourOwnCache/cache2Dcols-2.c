////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dcols.c
// This File:        cache2Dcols.c
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

int arr[3000][500];

int main() {
    int j;
    for (j = 0; j < 500; j+) {
         int i;
         for (i = 0; i < 3000; i++) {
             arr[i][j] = i + j;
            }
        }
    return 0;
}
