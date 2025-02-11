#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Todo
{
    char description[255];
    bool isDone;
};

void addTodo(struct Todo (*todoArrPointer)[255], char description[255])
{ // TODO:fix me plz
    int newTodoIndex;
    struct Todo tempTodo;
    strcpy(tempTodo.description, description);
    tempTodo.isDone = false;

    for (int i = 0; i < sizeof(*todoArrPointer) / sizeof(*todoArrPointer[0]); i++)
    {
        if (strlen((*todoArrPointer)[i].description) < 0)
        {
            newTodoIndex = i;
            break;
        }
    }
    (*todoArrPointer)[newTodoIndex] = tempTodo;
}

void markAsDone(struct Todo (*todoArrPointer)[255], int todoNumber)
{
    (*todoArrPointer)[todoNumber].isDone = true;
}

void delTodo(struct Todo (*todoArrPointer)[255], int todoNumber)
{
    strcpy((*todoArrPointer)[todoNumber].description, "");
}

void showTodo(struct Todo (*todoArrPointer)[255])
{
    for (int i = 0; i < sizeof(*todoArrPointer) / sizeof(*todoArrPointer[0]); i++)
    {
        if (strlen((*todoArrPointer)[i].description) > 0)
        {
            printf("Id: %d,Description: %s,IsDone: %d\n", i, (*todoArrPointer)[i].description, (*todoArrPointer)[i].isDone);
        }
    }
}

int main()
{

    bool open = true;
    struct Todo todo[255];
    struct Todo(*todoArrPointer)[255] = &todo;

    char descriptionInput[255];
    int idInput;

    // test
    struct Todo test;
    strcpy(test.description, "test");
    test.isDone = true;

    *todoArrPointer[0] = test;
    // test

    while (open == true)
    {

        printf("\n");
        printf("---------------------\n");
        printf("What would you like to do?\n");
        printf("1. Add Todo\n");
        printf("2. Mark Todo as Done\n");
        printf("3. Delete Todo\n");
        printf("4. Show Todo list\n");
        printf("5. Exit\n");
        printf("---------------------\n");
        printf("\n");

        int choice = 0;
        scanf("%1d", &choice);

        switch (choice)
        {
            case 1:
                printf("description of todo\n");
                scanf("%254s", descriptionInput);          
                addTodo(todoArrPointer, descriptionInput);

                strcpy(descriptionInput, "");
                choice = 0;
                idInput = 0;
                break;

            case 2:
                printf("Number of todo\n");
                scanf("%d", &idInput);
                markAsDone(todoArrPointer, idInput);

                choice = 0;
                idInput = 0;
                break;

            case 3:
                printf("Number of todo\n");
                scanf("%d", &idInput);
                delTodo(todoArrPointer, idInput);

                choice = 0;
                idInput = 0;
                break;

            case 4:
                showTodo(todoArrPointer);

                choice = 0;
                break;

            case 5:
                open = false;
                break;

            default:
                printf("Unknown command\n");
                choice = 0;
                break;
        }
    }
    return 0;
}