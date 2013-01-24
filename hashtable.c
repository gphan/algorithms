/* Hash table */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHCOUNT 127

typedef struct hashnode 
{
    char *key;
    char *value;
    struct hashnode *next;
} hash_node;

int hash(char * s) 
{
    int prime = 2173;
    int len = strlen(s);
    int hash = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        hash += prime * s[i];
    }
    return hash % HASHCOUNT;
}

void insert_into(hash_node * bin, char *key, char *value) 
{
    int h = hash(key);
    hash_node * bucket = &bin[h];
    while (bucket->next != NULL) 
    {
        bucket = bucket->next;
    }
    bucket->key = key;
    bucket->value = value;
    bucket->next = (hash_node *)(malloc(sizeof(hash_node)));
}

char * keys[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
char * values[] = {"word", "bird", "turd", "heard", "murder", "lurker", "fork", "stork"};

int main(int argc, char **argv) 
{
    int mem_size = (sizeof(struct hashnode) * HASHCOUNT);
    hash_node * bin = (hash_node *)(malloc(mem_size));
    memset(bin, 0, mem_size);

    int i;
    int len = 8;
    for (i = 0; i < len; i++) 
    {
        insert_into(bin, keys[i], values[i]);
    }

    hash_node * itr;
    for (i = 0; i < HASHCOUNT; i++)
    {
        itr = &bin[i];
        do {
            printf("Itr Key: %s, Itr Val: %s\n", itr->key, itr->value);
            itr = itr->next;
        } while(itr != NULL);
    }

    return 0;
}
