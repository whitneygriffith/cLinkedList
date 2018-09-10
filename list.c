//Source file for the C-string linked list data structure for storing character strings

#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Allocates and initializes a new list*/
list *create_list(){
    list *list = malloc(sizeof(list)); //Create List Data Type and Allocate Memory for it
    node *head = malloc(sizeof(node));
    head->value = "";
    head->next = 0;
    list -> head = head;
    list-> tail = head;
    return list;
}

/* Adds item to end of the list. This function allocates a
* new buffer and copies the string from item (use malloc, strlen, and strncpy; or try strdup).
* Returns 0 if successful, non-zero otherwise. */

int add_to_list(list *ll, char *item){
    node *newNode = malloc(sizeof(node)); //create new node item to store item's details
    //compute length of string and assign it to the new node's value
    int len = strlen(item) + 1;
    char *sstring = malloc(len +1);
    strncpy(sstring, item, len); //store the new string into the new node's value
    newNode -> value = sstring; //set the new node value to input string
    newNode -> next = 0; //create node struct for new item

    if (!strcmp(ll->head->value, "") && ll->head->next == 0)
    {
        ll->head = newNode;
        ll->tail = newNode;
    } 
    else{ 
        //always add new node as the tail of the list
        node *lastItem = malloc(sizeof(node));
        lastItem = ll->tail;      //grab the last item in list
        lastItem->next = newNode; //change the last item next pointer to point to new item
        ll->tail = newNode;       //Update the list's tail
    }
    return 0;
}

/* Removes the string from the front of the list and
* returns a pointer to it. The caller is expected to free
* the string returned when finished with it. */
char *remove_from_list(list *ll){
    node *removing = malloc(sizeof(node));
    removing = ll -> head;

    char *stringDelete = removing->value; //string of item in front of list
    ll ->head = removing ->next; //set the head of the list as the item to be removed next 
    free(removing); //frees the node of the item to be deleted
    
    //check if there was only one item in the list
    if (ll->head == ll->tail){
        free(ll->tail);
    }

    return stringDelete; //return the pointer to the string at the front of the list
}

/* Prints every string in the list, with a new line
* character at the end of each string */
void print_list(list *ll){
    node *current = malloc(sizeof(node));
    current = ll -> head;
    while (current != NULL){
        printf("%s \n", current -> value);
        current = current -> next;
    }
}

/* Flushes (clears) the entire list and re-initializes the
* list. The passed pointer ll should still point to a
* valid, empty list when this function returns. Any memory
* allocated to store items in the list should be freed. */
void flush_list(list *ll){

    node *current = malloc(sizeof(node)); 
    current = ll -> head;
    node *next = malloc(sizeof(node));
    while (current != NULL ){
        next = current -> next;
        free(current);
        current = next;
    }
    free(next); 
    free(ll);

    ll = create_list();
}

/* De-allocates all data for the list. Ensure all memory
* allocated for this list is freed, including any
* allocated strings and the list itself.*/

void free_list(list *ll){
    node *current = malloc(sizeof(node));
    current = ll->head;
    node *next = malloc(sizeof(node));
    while (current != NULL)
    {
        next = current->next;
        free(current->value);
        free(current); 
        current = next;
    }
    free(next);
    free(ll);
    free(current);
    return;
}
