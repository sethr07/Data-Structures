//
//  task2.c
//
//
//  Created by Rahul Seth on 05/11/2020.
//

//
//
//
//  Created by Rahul Seth on 05/11/2020.
//
// Task 2 - Another Sorting Algorithim
//
//
//
/*
 Implement a sorting algorithm of your choice and evaluate it in the same manner as you did
 quicksort (i.e. print swaps/comparisons and test for each of the 5 different types of data).
 Does the algorithm you picked perform better or worse under each of the five conditions?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NOS[10]; //Array for 10 elements
int NOS1[10] = {4, 3, 5, 1, 0, 2, 7, 9, 42, 17}; //Random Array with no duplicates
int BA[10000]; //Array for 10000 elements

//Counters
int no_of_swaps=0;
int no_of_comparasions=0;

//Function declaraations start
void swap(int* a, int* b); //swap function from task 1
void insertionsort(int array[], int n); //Another sorting algorithim
void print_output(int array[], int size); //printing fucntion
//
//test cases for 10 numbers
void rnd_array10(); //Random no duplicates
void rd_array10(); //Random
void asn_array10(); //Ascending Sorted
void dec_array10(); //Descedning Sorted
void uniform_array10(); //Uniform
//
//test cases for 10000 numbers
void rd10000(); //Random
void asn10000(); //Ascending Sorted
void dec10000(); //Descending Sorted
void uniform10000(); //Uniform
//
//function declrations end
//
//
int main(){
    int choice;
    printf("\n        Make a selection from the following: \n\n");
    printf("\n      1. Testing Insertion Sort Algorithim on a array with 10 elements.\n");
    printf("\n      2. Testing Insertion Sort Algorithim on a array with 10000 elements.\n");
    printf("\n      0. Terminate Program.\n");
    
    for(;;){
        scanf("%d", &choice);
        if(choice==0) {printf(" \n\n     PROGRAM TERMINATING.\n\n"); break;}
        
        if(choice == 1){
            printf("\n\n        Running profile tests with 10 elements\n\n");
            rnd_array10();
            rd_array10();
            asn_array10();
            dec_array10();
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
void insertionsort(int array[], int n){
    
    int index, key, j;
    
    for(index=0; index < n-1; index++){
        
        no_of_comparasions++;
        key = array[index];
        j = index - 1;
        
        while(j >= 0 && array[j] > key){
            no_of_comparasions++;
            array[j+1] = array[j];
            no_of_swaps++;
            j = j - 1;
        }
        array[j+1] = key;
    }
}

void print_output(int array[], int size) {
    
    printf("Sorted List: \n\n");
    
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n\n\n");
}

// Test case - Array woth 10 values and no duplicates
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
    insertionsort(NOS1,n);
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);

    printf("\n\n");
    print_output(NOS1, n);

    for(int i=0; i<50; i++){
        printf("-");
    }
    no_of_swaps=0;
    no_of_comparasions=0;
}

// Test Case - A randomly shuffled array with duplicate values
void rd_array10(){
    
    printf("\n\n       Test Case 2: Random values.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    srand(0);
    for(int i = 0; i < 10; i++){
        NOS[i] = (rand() % 10) + 0;
    }
    
    printf("\n        Unsorted Array: \n\n");
    for(int i=0; i<10; i++){
        printf("%d ", NOS[i]);
    }
    printf("\n\n");
    
    int n = sizeof(NOS) / sizeof(NOS[0]);
    insertionsort(NOS, n);

   /* if(x==1){
        printf("        Sorting Successful. \n");
    }
    else  printf("      Sorting Unsuccessful. \n"); */
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);

    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialisng counters
    no_of_swaps=0;
    no_of_comparasions=0;
    
}

//Test Case - Array sorted in ascending order
void asn_array10(){
    
    printf("\n\n      Test Case 3: Ascending Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    for(int i=0; i<10; i++){
        NOS[i] = i+1;
    }
    
    printf("\n        Unsorted list:\n\n");
    for(int i=0; i<10; i++){
        printf("%d ", NOS[i]);
    }
    
    printf("\n\n");

    int n = sizeof(NOS) / sizeof(NOS[0]);
    insertionsort(NOS,n);

  /*  if(x==1){
        printf("        List : Sorting Successful. \n");
    }
    else  printf("      List : Sorting Unsuccessful. \n"); */
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counter
    no_of_swaps=0;
    no_of_comparasions=0;
}
//Test case - Array sorted in decending order
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
        printf("%d ", NOS[i]);
    }
    printf("\n\n");
    
    int n = sizeof(NOS) / sizeof(NOS[0]);
    insertionsort(NOS, n);
    
   /* if(x==1)  printf("      List : Sorting Successful. \n");
    else  printf("          List : Sorting Unsuccessful. \n");*/
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialisng counters
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
    insertionsort(NOS, n);

    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    print_output(NOS, n);
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialisng counters
    no_of_swaps=0;
    no_of_comparasions=0;
}
//
//
//
//Test cases for 10000 values
//
//Test case - random values
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
    insertionsort(BA, n);
    
   /* if(x==1){
        printf("        Sorting Successful. \n");
    }
    else  printf("      Sorting Unsuccessful. \n"); */
    
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

//Test case -  ascending sorted
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
    insertionsort(BA, n);
   /* if(x==1){
        printf("        Sorting Successful. \n");
    }
    else  printf("      Sorting Unsuccessful. \n"); */
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialing counters
    no_of_swaps = 0;
    no_of_comparasions = 0;
}
//Test case - descending sorted
void dec10000(){
    
    printf("\n\n       Test Case 4: Descedning Sorted List.\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    printf("\n");
    
    
    for(int i = 0; i < 10000; i++){
        BA[10000-i] = i;
    }
    
    int n = sizeof(BA) / sizeof(BA[0]);
    insertionsort(BA, n);
    
  /*  if(x==1){
        printf("        Sorting Successful. \n");
    }
    else  printf("      Sorting Unsuccessful. \n"); */
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialisng counters
    no_of_swaps = 0;
    no_of_comparasions = 0;
}

//Test case - uniform list
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
    insertionsort(BA, n);
    
   /* if(x==1){
        printf("        Sorting Successful. \n");
    }
    else  printf("      Sorting Unsuccessful. \n"); */
    
    printf("        Number of swaps = %d \n", no_of_swaps);
    printf("        Number of comparasions = %d \n", no_of_comparasions);
    printf("\n\n");
    
    for(int i=0; i<50; i++){
        printf("-");
    }
    
    //Re-initialising counters
    no_of_swaps = 0;
    no_of_comparasions = 0;
}

//end of function declarations
//end of file
