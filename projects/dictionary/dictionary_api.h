#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 100
#define MAX_DEF_LENGTH 500
#define MAX_AUTHOR_LENGTH 50
#define BALANCE_PARAMETER 1

typedef struct{
    char entry[MAX_WORD_LENGTH];
    char definition[MAX_DEF_LENGTH];
    int word_length;
}Word;

typedef struct BST{
    Word word;
    struct BST *left;
    struct BST *right;
    struct BST *parent;
    int balance_factor;
}BST;

typedef struct{
    BST *root;
    char author[MAX_AUTHOR_LENGTH];
    int num_words;
    int distance_threshold;
}Dictionary;