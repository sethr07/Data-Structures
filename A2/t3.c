//
//
//
//
// Task 3 - Sorting ign csv
//
//
/*
 Load and sort IGN reviews and print the top 10 most popular games of the last
 20 years
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 256

struct fileData{
    char title[MAX_BUFFER];
    int gamescore;
    int y;
    char p[MAX_BUFFER];
};
struct fileData data[19000];
struct fileNode {
    int score, year;
    char name[MAX_BUFFER], platform[MAX_BUFFER];
};

//Function declarations begin
void swap(int* a,char t1[MAX_BUFFER], int *yr1, char p1[MAX_BUFFER], int* b, char t2[MAX_BUFFER], int *yr2, char p2[MAX_BUFFER]); //modified swap from t1
int partition (struct fileData data[19000], int low, int high); //partition function from task 1
void quickSort(struct fileData data[19000], int low , int high); //quickSort function from task 1
void printArray(struct fileData data[19000], int size); //Prints top 10 movies
int next_field( FILE *f, char *buf, int max ); // csv preaser
void fetchData ( FILE *csv, struct fileNode *p); //fetches data from csv
void storeData( struct fileNode *g1); //stores data fro csv to the list fileData
//Function declarations end
//
int main () {

    FILE *file;
    struct fileNode gm;
    
    file = fopen("ign.csv", "r");
    
    if(file==NULL) {
        printf("unable to open %s\n", "ign.csv");
        return EXIT_FAILURE;
    }
    
    fetchData( file, &gm ); //skip header line
    
    while(!feof(file)) {
        fetchData( file, &gm );
        storeData( &gm );
    }
    
    int n = sizeof(data)/sizeof(data[0]);
    quickSort(data, 0, n-1);

    printf("\n    Top 10 Most Poplar Games of 20 Years: \n");
    printArray(data, n); //prints output
    fclose(file); // Close the file
    return 0;
}
//Function definations start
//
void swap(int* a,char t1[MAX_BUFFER], int *yr1, char p1[MAX_BUFFER], int* b, char t2[MAX_BUFFER], int *yr2, char p2[MAX_BUFFER]) {
   int tmp1 = *a;
    *a = *b;
    *b = tmp1;
    char tmp2[MAX_BUFFER];
    strcpy(tmp2,t1);
    strcpy(t1,t2);
    strcpy(t2,tmp2);
    int tmp3 = *yr1;
    *yr1 = *yr2;
    *yr2 = tmp3;
    char tmp4[MAX_BUFFER];
    strcpy(tmp4,p1);
    strcpy(p1,p2);
    strcpy(p2,tmp4);
}

int partition (struct fileData data[19000], int low, int high) {
    int j ;
    int pivot = data[high].gamescore;
    int i = (low - 1);
    for (j = low; j <= high- 1; j++)
    {
        
        if (data[j].gamescore < pivot)
        {
            i++;
            swap(&data[i].gamescore, data[i].title, &data[i].y, data[i].p,  &data[j].gamescore, data[j].title, &data[j].y, data[j].p);
        }
    }
    swap(&data[i + 1].gamescore,data[i+1].title, &data[i+1].y, data[i+1].p, &data[high].gamescore,data[i+1].title, &data[i+1].y, data[i+1].p);
    return (i + 1);
}
void quickSort(struct fileData data[19000], int low , int high)
{
    if (low < high)
    {
        int pivot_index = partition(data, low, high);
        quickSort(data, low, pivot_index-1);
        quickSort(data, pivot_index+1, high);
    }
}

void printArray(struct fileData data[19000], int size) {
    int i;
    printf("----------------------------------------------------------------------------------\n");
    for (i=(size-11); i < (size-1); i++){
      printf("\n  Title:%s\n  Platform:%s\n  Release Year:%d\n\n\n",data[i].title,data[i].p, data[i].y);
      printf("----------------------------------------------------------------------------------\n");
    }
        
}

//csv praser
//taken from assignment 0
int next_field( FILE *f, char *buf, int max ) {
    int i=0, end=0, quoted=0;
    for(;;) {
        // fetch the next character from file
        buf[i] = fgetc(f);
        // if we encounter quotes then flip our state and immediately fetch next char
        if(buf[i]=='"') { quoted=!quoted; buf[i] = fgetc(f); }
        // end of field on comma if we're not inside quotes
        if(buf[i]==',' && !quoted) { break; }
        // end record on newline or end of file
        if(feof(f) || buf[i]=='\n') { end=1; break; }
        // truncate fields that would overflow the buffer
        if( i<max-1 ) { ++i; }
    }
    
    buf[i] = 0; // null terminate the string
    return end; // flag stating whether or not this is end of the line
}

//Get data from csv to list
void fetchData ( FILE *csv, struct fileNode *p ) {
    char buf[MAX_BUFFER];
    next_field( csv,p->name,MAX_BUFFER );
    next_field( csv, p->platform, MAX_BUFFER );
    next_field( csv, buf, MAX_BUFFER );
    p->score = atoi(buf);
    next_field( csv, buf, MAX_BUFFER );
    p->year = atoi(buf);
}

int k=0;
void storeData( struct fileNode *g1 ) {
    strcpy(data[k].title,g1->name);
    data[k].gamescore=g1->score;
    data[k].y=g1->year;
    strcpy(data[k].p,g1->platform);
    k++;
}
//Function definations end
