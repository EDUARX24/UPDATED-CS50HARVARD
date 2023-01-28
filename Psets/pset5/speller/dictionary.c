// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
#define N 10000

// Hash table
node *table[N];
//contador de palabras
int Cont_Palabras = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int tx = strlen(word);
    char Copiar_Plb[LENGTH + 1];
    for(int i = 0; i < tx; i++)
    {
        Copiar_Plb[i] = tolower(word[i]);
    }

    Copiar_Plb[tx] = '\0';
    int h = hash(Copiar_Plb);
    node *cursor = table[h];

    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, Copiar_Plb) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long total = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
    //toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        return false;
    }

    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char P_nueva[LENGTH + 1];

    while(fscanf(file, "%s", P_nueva) != EOF)
    {
        node *nNode = malloc(sizeof(node));

        strcpy(nNode->word, P_nueva);

        int hashes = hash(P_nueva);

        if(table[hashes] == NULL)
        {
            nNode->next = NULL;
            table[hashes] = nNode;
        }
        else
        {
            nNode->next = table[hashes];
            table[hashes] = nNode;
        }

        Cont_Palabras++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return Cont_Palabras;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node *cab = table[i];
        node *cursor = cab;
        node *tmp = cab;

        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }

        table[i] = NULL;
    }

    return true;
}
