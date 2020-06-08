////////////////////////////////////////////////////////////////////////////////
// Main File:        verify_hetero.c
// This File:        verify_hetero.c
// Other Files:      generate_magic.c
// Semester:         CS 354 Spring 2018
//
// Author:           William Jared Pechous
// Email:            wpechous@wisc.edu
// CS Login:         pechous
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          N/A
//
// Online sources:   Canvas
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing Square
// size: dimension(number of rows/columns) of the square
// array: 2D array of integers
typedef struct _Square {
    int size;
    int **array;
} Square;

Square * construct_square(char *filename);
int verify_hetero(Square * square);
void insertion_sort(int* arr, int size);

int main(int argc, char *argv[])                        
{
    // Check input arguments to get filename

    // Construct square

    // Verify if it's a heterosquare and print true or false
    if (argc != 2) {
       fprintf(stderr, "No file passed in.\n");
       exit(1);
                   }
     Square *sq = construct_square(argv[1]);
     int verify = verify_hetero(sq);
     if (verify == 0) {
        printf("false\n");
                      }
    else if (verify == 1) {
            printf("true\n");
                          }

    int n;
    for (n = 0; n < (*sq).size; n++) {
        free(*((sq -> array) + n));
                                     }
     free((*sq).array);
     free(sq);


    return 0;
}

/* construct_square reads the input file to initialize a square struct
 * from the contents of the file and returns the square.
 * The format of the file is defined in the assignment specifications
 */
Square * construct_square(char *filename)                
{
    // Open and read the file

    // Read the first line to get the square size

    // Initialize a new Square struct of that size

    // Read the rest of the file to fill up the square
    FILE *ifp = fopen(filename, "r");
    if (ifp == NULL) {
       fprintf(stderr, "Can't open file.\n");
       exit(1);      }

    int getSize;
    int check = fscanf(ifp, "%d", &getSize);
    if (check == 0) {
       printf("Can't scan file.\n");
       exit(1);     }


    Square * sqptr = malloc(sizeof(Square));
    (*sqptr).size = getSize;
    (*sqptr).array = malloc(getSize * sizeof(int*));
    
    int i;
    int j;
    for (i = 0; i < getSize; i++) {
        *((sqptr -> array) + i) = malloc(sizeof(int) * getSize);
    for (j = 0; j < getSize - 1; j++) {
         int check2 = fscanf(ifp, "%d,", (*(sqptr -> array + i) + j));
         if (check2 == 0) {
         printf("Can't scan file.\n");
         exit(1);
                            }
               }
       }

   int check3 = fclose(ifp);
     if (check3 == EOF) {
        printf("Failed to close the file.\n");
        exit(1);
                          }

    return sqptr;
}

/* verify_hetero verifies if the square is a heterosquare
 * 
 * returns 1(true) or 0(false)
 */
int verify_hetero(Square * square)               
{
    // Calculate sum of the following and store it in an array
    // all rows and cols
    // main diagonal
    // secondary diagonal

    // Pass the array to insertion_sort function
    // Check the sorted array for duplicates

    int fReturn;
    int **testAr = square -> array;
    int row = square -> size;
    int col = row;
    int totalsize = ((row * 2) + 2);
    int *aptr = malloc(sizeof(int) * totalsize);
    
    for(int a = 0; a < row; a++) {
       for(int b = 0; b < col; b++){
        *(aptr + a) += *(*(testAr + a) + b);
        printf("%d," , *(*(testAr + a) + b)); }
        printf("\n");             }

    for(int i = 0; i < col; i++){
       for(int j = 0; j < row; j++){
        *(aptr + row + i) += *(*(testAr + j) + i);
                                   }
                                }
    for(int c = 0; c < row; c++){
       *(aptr + (totalsize-2)) += *(*(testAr + c) + c);
       *(aptr + (totalsize-1)) += *(*(testAr + ((row-1)-c) + c));
                                }
    insertion_sort(aptr, totalsize);

    for(int d = 0; d < totalsize-1; d++){
       if(*(aptr + d) == *(aptr + (d + 1))){
         fReturn = 0;
         return fReturn;
         exit(0);
                                           }
       else {
        fReturn = 1;
            }
                                        }
 for(int f = 0; f < row; f++){
    free(testAr[f]);        
                             }
 free(aptr);
 free(testAr);
 free(square);

 return fReturn;
}

/* insertion_sort sorts the arr in ascending order
 *
 */
void insertion_sort(int* arr, int size)                  
{
    // Sort the arr
   int arrkey;
   int track;
      for(int i = 0; i < size; i++) {
      arrkey = *(arr + i);
      track = i - 1;
  
      while(track >= 0 && *(arr + track) > arrkey){
      *(arr + (track + 1)) = *(arr + track);
      track--;
                                           }
      *(arr + (track + 1)) = arrkey; }
     return;

}
