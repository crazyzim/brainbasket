#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
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

hashtable* hashcreate (int size) ;
void hashdestroy (hashtable* h) ;
int hashresearch (hashtable* h, string key);
node* hashtableNewPair (string key, string value);  
void hashtableSet(hashtable* h, string key , string value);
string hashtableGet (hashtable*h , string key);


hashtable* hashcreate (int size)
{
    hashtable* h = malloc (sizeof (hashtable)) ;
    h->table = malloc(sizeof(node_s)*size);
    for (int i = 0; i < size ; i++)
    {
        h->table[i] = NULL;
    
    }
    h->size = size; 
    return h ;
}

void hashdestroy (hashtable* h)
{
    hashtable* tmp ; 
    //free h->table 
    //free h
    
}

int hash(hashtable* h , string key)
{
    unsigned long int hashvalue ; 
    int i;
    while (hashvalue < ULONG_MAX && i < strlen(key))
    {
        hashvalue = hashvalue << 8 ; // *256 
        hashvalue = hashvalue + key[i];
        i++;
    }
    return hashvalue % h->size ;
}


node* hashtableNewPair (string key, string value )
{
    node *new_node = malloc (sizeof(node));
    new_node->key = key; 
    new_node->value = value ;
    new_node->next = NULL ;
    return new_node; 
    
}

void hashtableSet ( hashtable* h , string key, string value )
{
     
    int index = hash(h , key); 
    node *new_next; 
    node *last; 
    new_next = h->table[index];
    //...
    
    if (new_next != NULL && new_next->key != NULL && new_next->key == key  )
    {
        new_next->value = value ;
    }
    
    else 
    {
     node *new_pair = hashtableNewPair (key, value); 
     h->table[index] = new_pair ;
    }
    
    
}

string hashtableGet (hashtable *h , string key)
{
    
   node *pair = h->table[hash(key)]; 
    if ( pair == NULL || pair-> key == NULL )
    {
        return NULL ; 
    }
    else
        return pair->value ;
    
    
}

int main ()
{
    
    
    
}