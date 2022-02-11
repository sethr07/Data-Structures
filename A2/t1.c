//
//  t1.c
//  
//
//  Created by Rahul Seth on 05/11/2020.
//
// Task 1
/*
 Implement quicksort for sorting an array of integers. Your implementation should count the
 number of times values are swapped in the array and the number of times two values in the
 array are compared. These total number of swaps and comparisons should be reported at
 the end of your program's execution.
 
 Test your implementation on the following types of data:
 o A randomly shuffled array with no duplicate values e.g. [ 4, 3, 5, 1, 0, 2 ]
 o A randomly shuffled array with duplicate values e.g. [ 3, 3, 2, 1, 1, 4 ]
 o An ascending sorted array e.g. [ 0, 1, 2, 3, 4, 5 ]
 o A descending sorted array [ 5, 4, 3, 2, 1, 0 ]
 o An array where every value is the same (uniform) e.g. [ 3, 3, 3, 3, 3, 3 ]
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Arrays to sort
int NOS[10]; //Array for 10 elememts profile tests
int NOS1[10] = {7, 9, 45, 982, 1, 7611, 9834, 128, 11, 87390}; // Random array with no duplicates
int BA[10000]; //Array for 10000 elements profile tests

//couters for swap & comparasions
int no_of_swaps=0;
int no_of_comparasions=0;

//Function declarations start
void swap( int* a, int* b);
int partition(int array[], int start, int end);
int quicksort(int array[], int low, int high);
void print_output(int array[], int size);
//test cases for 10 numbers
void rnd_array10(); //Random no duplicate
void rd_array10(int array[]); //Random values
void asn_array10(); //Ascending sorted
void dec_array10(int array[]); //descending sorted
void uniform_array10(); //uniform
//
//test cases for 10000 numbers
void rd10000(); //Random values
void asn10000(); //Ascending Sorted
void dec10000(); //Desceding sorted
void uniform10000(); //Uniform Sorted
//
//function declrations end
//
//
int main(){
    int choice;
    printf("\n        Make a selection from the following: \n\n");
    printf("\n      1. Testing QuickSort Function on a array with 10 elements.\n");
    printf("\n      2. Testing QuickSort Function on a array with 10000 elements.\n");
    printf("\n      0. Terminate Program.\n");

    for(;;){
        scanf("%d", &choice);
        if(choice==0) {printf(" \n\n     PROGRAM TERMINATING.\n\n"); break;}
        
        if(choice == 1){
            printf("\n\n        Running profile tests with 10 elements\n\n");
            rnd_array10();
            rd_array10(NOS);
            asn_array10();
            dec_array10(NOS);
            uniform_array10();
        }
    
        else if(choice == 2){
            int* ptr;
            int k,j;
            k=10000;
            ptr = (int*)malloc(k*sizeof(int)); //Memory allocation
            if(ptr == NULL) printf("Memory not assigned. \n");
            printf("\n\n        Running profile tests with 10000 elements\n\n");
            rd10000();
            asn10000();
            dec10000();
            uniform10000();
        }
        else printf("\n         Invalid Selection.\n");
        printf(" \n\n       Select 1 or 2 to try again or press 0 to quit.\n");
    }
    return 0;
}

//Function definations begin
//
//
void swap(int* a, int* b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Pivot = Last element in array
//Numbers smaller than the pivot goes on the left side of pivot and greater numbers to the right
int partition(int array[], int low, int high){
    int pivot = array[high];
       int i = (low - 1);
     
       for (int k = low; k <= high - 1; k++)
       {
           no_of_comparasions++;
           if (array[k] < pivot)
           {
               i++;
               swap(&array[i], &array[k]);
               no_of_swaps++;
           }
       }
       swap(&array[i + 1], &array[high]);
       return (i + 1);
}

int quicksort(int array[], int low, int high){

    int swapped = 0; //flag that checks if elements have been sorted or not
    
    if(low>high)
        return 0;
    
    if(low<high){
        int pivot_index = partition(array, low, high);
        quicksort(array, low, pivot_index - 1);
        quicksort(array, pivot_index + 1, high);
        swapped=1;
    }
    return swapped;
}

void print_output(int array[], int size) {
    
    printf("Sorted List: \n\n");
    
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n\n\n");
}

//Test Profile for 10 elements
//Test Case - Random No duplicates
void rnd_array10(){
    
    printf("\n\n       Test Case 1: Random No Duplicate values.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    

    printf("\n        Unsorted Array: \n\n");
    for(int i=0; i<10; i++){
        printf("%d ", NOS1[i]);
    }
    printf("\n\n");
    
    int n = sizeof(NOS1) / sizeof(NOS1[0]);
  
    int x = quicksort(NOS1, 0, n-1);
    
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS1, n);

    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}

//Test case - random values
void rd_array10(int array[]){
    
    printf("\n\n       Test Case 2: Random values.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    srand(0);
    for(int i = 0; i < 10; i++){
        array[i] = (rand() % 10) + 0;
    }
    
    printf("\n        Unsorted Array: \n\n");
    for(int i=0; i<10; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    int n = sizeof(NOS) / sizeof(NOS[0]);
    int x = quicksort(NOS, 0, n-1);
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}

//Test case - Array sorted in ascending order
void asn_array10(){
    
    printf("\n\n      Test Case 3: Ascending Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    for(int i=0; i<10; i++){
        NOS[i] = i+2;
    }
    
    printf("\n        Unsorted list:\n\n");
    for(int i=0; i<10; i++){
        printf("%d ", NOS[i]);
    }
    
    printf("\n\n");

    int n = sizeof(NOS) / sizeof(NOS[0]);
    int x = quicksort(NOS, 0, n-1);

    if(x==1) printf("        List : Sorting Successful. \n");
    else  printf("      List : Sorting Unsuccessful. \n");
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-intialising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}

//Test Case - Array sorted in decending order
void dec_array10(int array[]){
    
    printf("\n\n        Test Case 4: Descending Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n\n");
    
    for(int i=10; i>0; i--){
        NOS[10-i] = i;
    }
    
    printf("\n        Unsorted list: \n\n\n");
    for(int i=0; i<=10; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    int n = sizeof(NOS) / sizeof(NOS[0]);
    int x = quicksort(NOS, 0, n-1);
    
    if(x==1)  printf("      List : Sorting Successful. \n");
    else  printf("          List : Sorting Unsuccessful. \n");
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initilising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}

//Test case - Array with same value
void uniform_array10(){
    
    printf("\n\n        Test Case 5: Uniform List.\n\n");
    for(int i=0; i<50; i++){
        printf("-");
    }
    
     printf("\n");
    
    for(int i=0; i<10; i++){
        NOS[i] = 3;
    }
    
    printf("\n        Unsorted list: \n\n");
    for(int i=0; i<10; i++){
        printf("%d ", NOS[i]);
    }
    
    printf("\n\n");

    
    int n = sizeof(NOS) / sizeof(NOS[0]);
    quicksort(NOS, 0, n-1);

    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);

    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}
//
//
//
//Test Profile for 10000 values
//
//Test Case - random Values
void rd10000(){
    
    printf("\n\n       Test Case 2: Random values.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    //srand(0);
    for(int i = 0; i < 10000; i++){
        BA[i] = rand();
    }
    
    int n = sizeof(BA) / sizeof(BA[0]);
    int x = quicksort(BA, 0, n-1);
    
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
   // print_output(BA, n);
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counters
    no_of_swaps=0;
    no_of_comparasions=0;
}

//Test case - Ascending Sorted
void asn10000(){
    printf("\n\n       Test Case 3: Ascending Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    for(int i = 0; i < 10000; i++){
        BA[i] = i+1;
    }
    
    int n = sizeof(BA) / sizeof(BA[0]);
    int x = quicksort(BA, 0, n-1);
    
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);

    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
}

//Descending Sorted
void dec10000(){
    printf("\n\n       Test Case 4: Descedning Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    //srand(0);
    for(int i = 0; i < 10000; i++){
        BA[10000-i] = i;
    }
    
    int n = sizeof(BA) / sizeof(BA[0]);
    int x = quicksort(BA, 0, n-1);
    
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);

    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
}

//Test Case - Uniform Sorted
void uniform10000(){
    printf("\n\n       Test Case 5: Uniform List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    //srand(0);
    for(int i = 0; i < 10000; i++){
        BA[i] = 3;
    }
    
    int n = sizeof(BA) / sizeof(BA[0]);
    int x = quicksort(BA, 0, n-1);
    
    if(x==1) printf("        Sorting Successful. \n");
    else  printf("      Sorting Unsuccessful. \n");
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);

    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
}

//test cases end
//
//
