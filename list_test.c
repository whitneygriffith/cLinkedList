#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//function to create a list to run tests on
void create_test_list(list *testList)
{

    add_to_list(testList, "Hi");
    add_to_list(testList, "Hey");
    add_to_list(testList, "Hola");
    add_to_list(testList, "Salut");
    return;
}

int main()
{

    //Prompt Depicting Project, Version, and Student
    printf("\n====================================\n");
    printf(" Operating Systems - Project 1\n");
    printf(" Whitney Griffith \n");
    printf("====================================\n\n");

    printf("Test List created with 4 items: Hi, Hey, Hola and Salut \n\n");
    list *testList = create_list(); //create list tested
    create_test_list(testList); //add to list tested 4x

    printf("=============\n");
    printf("Printing List\n");
    printf("=============\n");
    print_list(testList); //print list tested
    printf("\n");

    for (int i = 0; i < 2; i++){
        printf("=======================\n");
        printf("Removing item from List\n");
        char *stringDelete = malloc(sizeof(char) * 256); //Allocated 256 Bytes for Char* similar to adding to the list
        stringDelete = remove_from_list(testList);   //Get the return value from remove list function and store it
        printf("The item that was removed was %s \n", stringDelete);
        stringDelete = NULL;
        free(stringDelete); //Free Remove_item so that memory is deallocated and freed.
        printf("=======================\n");
        printf("\n");
        printf("=======================\n");
        printf("Printing updated List\n");
        printf("=====================\n");
        print_list(testList);
        printf("\n");
    } //remove from list tested twice

    printf("Flushing List\n");
    printf("=============\n");
    printf("\n");
    flush_list(testList); //tested flushing list

    printf("Freeing List\n");
    printf("============\n");
    printf("\n");
    free_list(testList); //tested flushing list

    return 0;
}
