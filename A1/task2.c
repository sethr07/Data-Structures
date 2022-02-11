//
//
//
//  Created by Rahul Seth

//  Assignment 1: Hash Tables
//  Task 2: Insering Another Hash Function
//
//
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
int hash1(char* s);
int hash2(char* s);
int hash_table(char* s_store);
int getdata_csv(FILE *f);
float load_factor();
int frequency_counter(char* s);
void print_hashtable_data(); //Function for printing hash data
void print_ouput(); //Function for printing output
//End of function declaration

int main(){
    //Memory Allocation
    int* ptr;
    int n,i;
    ptr = (int*)malloc(ARRAY_SIZE*sizeof(int));
    if(ptr==NULL){
        printf("\nMemory not allocated.\n");
        exit(0);
    }
    //End
    //Reading in csv
    FILE*f;
    f = fopen("names.csv", "r"); //reading in csv file
    if(f==NULL){
        printf("Error opening file.\n");
    }
    //storing data in hash table from csv file
    for(int i=0; i<ARRAY_SIZE; i++){
        getdata_csv(f);
    }
    //for(int i=0; i<ARRAY_SIZE; i++){
     // printf("array index:   %d    ,   Name:   %s     \n", i, lastnames[i].last);
    //}
    print_hashtable_data();
    print_ouput();
    return 0;
}

//Function definations Begin
//Hash 1 function from task 1
int hash1(char* s){
    int hash = 0;
    while(*s){
        hash = (hash + *s);
        s++;
    }
    return (hash % ARRAY_SIZE);
}
//Hash 2 function - to reduce collisions
int hash2(char *s){
    int hash=0;
    int i=0;
    for(i=0; s[i] != '\0'; i++){ //giving more unique keys to names in hash table
        hash = hash + (*s + (i+1));
    }
    return hash % ARRAY_SIZE;
}
// Function for assigning keys to names in hash table
int hash_table(char* name_to_hashtable){
    int hash_key = hash2(name_to_hashtable);
    while(lastname[hash_key].name[0] != '\0'){
        collisions_counter++;
        //printf("%d", collisions_counter);
        if(!strcmp(lastname[hash_key].name, name_to_hashtable)){
            lastname[hash_key].frequency_of_name++;
            return 1;
        }
        hash_key++; //Linear probing to handle collisions
        hash_key = hash_key % ARRAY_SIZE;
    }
    strcpy(lastname[hash_key].name,name_to_hashtable); //storing last names in array that will be passed into hash table
    lastname[hash_key].frequency_of_name=1;
    terms_counter++;
    //printf("hash key:   %d    , name    %s  \n", hash_index, lastnames[hash_index].last);
    return 0;
}

//From Assignment 0
//Function for reading in data from csv
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
        strcpy(buf,"");
    }
    return 1;
}
//Function to check frequency of each name in array
int frequency_counter(char* s){
    int freq=0;
    int hash_index=hash2(s);
    int i=0;
    while(lastname[hash_index].name[0] != '\0' && i<ARRAY_SIZE){
        if(!strcmp(lastname[hash_index].name, s)) break;
        hash_index++;
        hash_index = hash_index%ARRAY_SIZE;
        i++;
    }
    return (lastname[hash_index].frequency_of_name);
}
//Function for calculation load for hash table
//Not working
float load_factor(){
    //printf("%d", terms_counter);
    int load = terms_counter*100/ARRAY_SIZE;
    return load;
}
//Function for printing hash table data, called in main
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
//Function for printing ouput, called in main
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
//End of function definations
//End of Task2
