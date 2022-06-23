#include <stdio.h>
#include <stdlib.h>

typedef struct entry
{
    char var[40];
    int val;
}dictnode;

typedef struct
{
    dictnode dictionary[];
    int numentry;
    int dsize;
} DICT;

DICT *created(int dictsize)
{
    struct DICT *ptr;
    ptr = (struct DICT*) malloc(dictsize * sizeof(struct DICT));
    return ptr;
}

dictnode makeentry(char var[], int val)
{
    
}
void add1entry(dictnode newentry, DICT *pdictionary){

}

void printentry(DICT *pdictionary, char var[]);

void delentry(DICT *pdictionary, char var[]);

void printdict(DICT *pdictionary);

int main()
{
    int 
}