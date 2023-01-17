#include"structs.h"
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#define True 1
#define False 0
void accountFile(FILE *myfile, Account *head)
{
    Account *cur = head;
    while (cur != NULL)
    {
        fprintf(myfile, "%s %s %d\n", cur->user, cur->Pass, cur->numberofPost);
        cur = cur->next;
    }
}
void postfile(FILE *myfile, Post *head)
{
    Post *cur = head;
    while (cur != NULL)
    {
        fprintf(myfile, "%s %s %d\n", cur->PostTxt, cur->user, cur->like);
        cur = cur->next;
    }
}
