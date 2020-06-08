////////////////////////////////////////////////////////////////////////////////
// Main File:        p2
// This File:        generate_magic.c
// Other Files:      verify_hetero.c
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

// Structure representing Square
// size: dimension(number of rows/columns) of the square
// array: 2D array of integers
typedef struct _Square {
    int size;
    int **array;
} Square;

int get_square_size();
Square * generate_magic(int size);
void write_to_file(char *filename, Square * square);

int main(int argc, char *argv[])                 
{
    // Check input arguments to get filename

    // Get size from user

    // Generate the magic square

    // Write the square to the output file 

 if (argc != 2) {
                   fprintf(stderr, "No File Name Given.\n");
                   exit(1);
                }
   int size = get_square_size();

   Square *magic = generate_magic(size);

   write_to_file(argv[1], magic);



    int i;
    for (i = 0; i < size; i++) {
         free(*((magic -> array) + 1));
                               }
      free((*magic).array);
      free(magic);

    return 0;
}

/* get_square_size prompts the user for the magic square size
 * checks if it is an odd number >= 3 and returns the number
 */
int get_square_size()            
{
    printf("Enter size of magic square, must be odd\n");
    char str[20];
    
    int input = scanf("%s", str);
    if (input < 0) {
      printf("Error 1: No size input detected.\n");
      exit(1);
                   }
     
     int msqsize = atoi(str);
     if (msqsize == 0) {
         printf("Size must be an odd NUMBER >= 3\n");
         exit(1);
                       }

     if (msqsize < 3 || msqsize % 2 == 0) {
         fprintf(stderr, "Size must be an odd number >= 3.\n");
         exit(1);                   }
                      
    return input;
}

/* generate_magic constructs a magic square of size n
 * using the Siamese algorithm and returns the Square struct
 */
Square * generate_magic(int n)           
{
  Square * sqrptr = malloc(sizeof(Square));
  if (sqrptr == NULL) {
     printf("Something went wrong....\n");
     exit(1);         }
   
  (*sqrptr).size = n;
  (*sqrptr).array = malloc(n * (sizeof(int*)));
  if ((*sqrptr).array == NULL) {
       printf("Can't allocate memory.\n");
       exit(1);               }
   int i;
   for ( i = 0; i < n; i++) {
   *((sqrptr -> array) + i) = malloc(n * sizeof(int));
                                       }
   int row  = (n-1) / 2;
   int column = n-1 ;     
   int RowTracker;
   int ColTracker;
   *(*(sqrptr->array + row) + column) = 1;
   int counter;
   for (counter = 1; counter < n*n; counter++) {
       if (row == (n - 1)) {
       RowTracker = row;
       row = 0;            }

       else {
              RowTracker = row;
              row = row + 1;
            }
       if (column == (n - 1)) {
          ColTracker = column;
          column = 0;         }
       else {
       ColTracker = column;
       column = 0;
            }
       if (*(*(sqrptr -> array + row) + column) != 0) {
       row = RowTracker;
       column = ColTracker - 1;
       *(*(sqrptr -> array + row) + column) = counter + 1;
                                                     }
       else {
       *(*(sqrptr -> array + row) + column) = counter + 1;
            }
                                               }
   
   return sqrptr;
}

/* write_to_file opens up a new file(or overwrites the existing file)
 * and writes out the square in the format expected by verify_hetero.c
 */
void write_to_file(char *filename, Square * square)              
{
    // Write the square to file
   FILE *ofp = fopen(filename, "w+");
   if (ofp == NULL) {
   printf("Can't open file.\n");
   exit(1);
                    }

    int size = (*square).size;
    int check2 = fprintf(ofp, "%d\n", size);
    if (check2 < 0) {
    printf("Can't write to file.\n");
    exit(1);
                      }
    int l;
    int r;
    for(l = 0; l < size; l++) {
        for(r = 0; r < size; r++) {
        int check3 = fprintf(ofp, "%d", *(*(square -> array + l) +  r));
        if ( check3 < 0) {
        printf("Can't write to file.\n");
        exit(1);
                          }
        if (r != size-1) {
            int check4 = fprintf(ofp, ",");
            if (check4 < 0) {
            printf("Can't write to file.\n");
            exit(1);
                              }
                          }
          }
        int check5 = fclose(ofp);
        if (check5 == EOF) {
            printf("Can't close file.\n");
            exit(1);
                             }
} 
}
