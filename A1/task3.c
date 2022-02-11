//
//
//  
//
//  Created by Rahul Seth
//  Assignment 1: Hash Tables

//  Task 3: Double Hashing
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 62
#define MAX_STRING 50
//
struct records {
    char name[MAX_STRING];
    int frequency_of_name;
};
typedef struct records Lastname;
Lastname lastname[ARRAY_SIZE];
//
//Global variables for generating hashtable data
int collisions_counter = 0;
int terms_counter = 0;
int load_counter =0;
//End of Global Variables

//Function Declarations
int hash1(char* s); //hash function -- given
int hash2(char* s);
int hash3(char *s, int i);
int hash_table(char* s_store);
int getdata_csv(FILE *f);
float load_factor();
int frequency_counter(char* s);
void print_hashtable_data(); //Function for printing hash data
void print_ouput(); //Function for printing output
//End of function declaration
//
int main(){
    //Reading in csv
    FILE*f;
    f = fopen("names.csv", "r"); //reading in csv file
    if(f==NULL){
        printf("Error opening file.\n");
    }
    
    //Memory Allocation
    int* ptr;
    int n,i;
    ptr = (int*)malloc(ARRAY_SIZE*sizeof(int));
    if(ptr==NULL){
        printf("\nMemory not allocated.\n");
        exit(0);
    }
    //End
    //storing data in hash table from csv file
    for(int i=0; i<ARRAY_SIZE; i++){
        getdata_csv(f);
    }
    
        print_hashtable_data();
    print_ouput();
    return 0;
}
//Function definations Begin
//Given in Assignment
int hash1(char* s){
    int hash = 0;
    while(*s){
        hash = (hash + *s);
        s++;
    }
    return (hash % ARRAY_SIZE);
}

int hash2(char *s){
    int hash=0;
    int i=0;
    for(i=0; s[i] != '\0'; i++){
        hash = hash + (*s + (i+1));
    }
    return hash % ARRAY_SIZE;
}

int hash3(char *s, int i){
    int hash = 0;
    int f, g, k;
    while(*s){
        k = hash + *s;
        f = k % ARRAY_SIZE;
        g = 1 + (k % (ARRAY_SIZE-1));
        hash = (f + i * g) % ARRAY_SIZE;
        s++;
    }
    return hash;
}
//Function for assigning keys to name in hash table
int hash_table(char* name_to_hashtable){
    int i=1;
    int hash_key = hash3(name_to_hashtable,i);
    while(lastname[hash_key].name[0] != '\0'){
        collisions_counter++;
        if(!strcmp(lastname[hash_key].name, name_to_hashtable)){
            lastname[hash_key].frequency_of_name++;
            return 1;
        }
        i++;
        hash_key = hash3(name_to_hashtable,i);
    }
    strcpy(lastname[hash_key].name,name_to_hashtable); //storing last names in array that will be passed into hash table
    lastname[hash_key].frequency_of_name=1;
    terms_counter++; //stroing the number of terms in hash table
    return 0;
}
//From Assignment 0
//Function for reading in the data in csv file
int getdata_csv(FILE *f2){
    int i=0;
    int end=0;
   // int qouted=0;
    char buf[MAX_STRING];
    while(!end){
        while(1){
            buf[i]=fgetc(f2);
            if(feof(f2) || buf[i]=='\n') { end=1; break; }
            if( i<MAX_STRING-1 ) { ++i; }
        }
        buf[i] = 0;
        hash_table(buf);
        i=0;
        strcpy(buf,""); //re-initialising buf
    }
    return 1;
}
//Function for calculation frequency of each name
int frequency_counter(char* s){
    int hash_key=hash2(s);
    int i=0;
    while(i<ARRAY_SIZE){
        if(!strcmp(lastname[hash_key].name, s)) break;
        hash_key++;
        hash_key = hash_key % ARRAY_SIZE;
        i++;
    }
    return (lastname[hash_key].frequency_of_name);
}
//For calculating load of hash table
//Not working
float load_factor(){
    //printf("%d", terms_counter);
    int load = terms_counter*100/ARRAY_SIZE;
    return load;
}
//Function for printing hash tbale data, called in main
void print_hashtable_data(){
    printf("names.csv loaded!\n");
    for(int i=0; i<=20; i++){
        printf("-");
    }
    printf("\n");
    printf("Capacity    :   %d\n", ARRAY_SIZE);
    printf("Num Terms   :   %d\n", terms_counter);
    printf("Collisions  :   %d\n", collisions_counter);
    printf("Load        :   %f\n", load_factor());
    for(int i=0; i<=20; i++){
        printf("-");
    }
}
//Function for printing the output, called in main
void print_ouput(){
    char check_for_name[MAX_STRING];
    int freq;
    printf("\nEnter name whose frequency you want to check:\n");
    for(;;){
        scanf("%[^\n]%*c", check_for_name);
        if(!strcmp(check_for_name, "q")){
            printf("\nProgram Terminating.....\n");
            break;
        }
        freq = frequency_counter(check_for_name);
        printf("\nFrequency of %s is: %d\n\nDo you want continue?\nEnter name or press q to terminate\n", check_for_name, freq);
    }
}
//End of functions
//End of Task 3
















