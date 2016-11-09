#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include <limits.h>

typedef struct node_s {
    string key;
    string value;
    struct node_s *next ;
} node ;

typedef struct hashtable_s {
    int size ;
    struct node_s **table ;
} hashtable ;

hashtable* hashcreate (int size);
void hashdestroy (hashtable* h);

int hash (int size, string key);

node* hashtableNewPair (string key, string value);

// размещение узла в таблице
void hashtableSet(hashtable* h, string key , string value);

string hashtableGet (hashtable*h , string key);

hashtable* hashcreate (int size)
{
    hashtable* h = malloc (sizeof (hashtable)) ;
    h->table = malloc(sizeof(node)*size);
    for (int i = 0; i < size ; i++)
    {
        h->table[i] = NULL;
    }
    h->size = size;
    return h ;
}

void hashdestroy (hashtable* h)
{
    if(h != NULL)
    {
        if(h->table != NULL)
        {
            free(h->table);
            h->table = NULL;
        }
        free(h);
        h = NULL;
    }
}

int hash(int size , string key)
{
    unsigned long int hashvalue = 0;
    int i = 0;
    while (hashvalue < ULONG_MAX && i < strlen(key))
    {
        hashvalue = hashvalue << 8 ; // *256
        hashvalue = hashvalue + key[i];
        i++;
    }
    return hashvalue % size ;
}


void hashtableSet(hashtable* h, string key , string value)
{
    int index = hash(h->size, key);
    node *new_next;
    node* last; // Last valid box(node) in the linked list for given slot
    new_next = h->table[index];
    last = new_next;

    // Searching the box to modify or add after
    while(new_next != NULL && new_next->key != NULL && new_next->key != key)
    {
        last = new_next;
        new_next = new_next->next;
    }

    // The box to modify
    if(new_next !=NULL && new_next->key != NULL && new_next->key == key)
    {
        new_next->value = value;
    }
    // The box to add after(append) in the linked list
    else
    {
        node* new_pair = hashtableNewPair(key, value);
        if (last)
            last->next = new_pair;
        else
            h->table[index] = new_pair;
        //h->table[index] = new_pair;
    }
}


string hashtableGet (hashtable *h , string key)
{
    //int tmp = hash(h, key);
    //printf("%d\n", tmp);
    node *pair = h->table[hash(h->size, key)]; //

    while(pair != NULL && pair->key != NULL && pair->key != key)
    {
        pair = pair->next;
    }
    if(pair == NULL)
    {
        return "UNDEFINED";
    }
    else
    {
        return pair->value;
    }
}

node* hashtableNewPair (string key, string value)
{
    node* new_node = malloc (sizeof(node));
    new_node->key = key;
    new_node->value = value ;
    new_node->next = NULL ;
    return new_node;
}

int main ()
{
    const int hsize = 3;
    hashtable* mytable = hashcreate(hsize);

    hashtableSet(mytable, "cat", "kit"); // 0
    hashtableSet(mytable, "dog", "pes"); // 2
    hashtableSet(mytable, "elephant", "slon"); // 1
    hashtableSet(mytable, "penguin", "pingvin"); // 0
    hashtableSet(mytable, "lion", "lev");  // 2
    hashtableSet(mytable, "tiger", "tigr"); // 0

    printf("Penguin is '%s'\n", hashtableGet(mytable, "penguin"));
    printf("Cat is '%s'\n", hashtableGet(mytable, "cat"));
    printf("Elephant is '%s'\n", hashtableGet(mytable, "elephant"));
    printf("Mouse is '%s'\n", hashtableGet(mytable, "mouse"));
    hashdestroy(mytable);
}
