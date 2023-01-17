#include"structs.h"
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#define True 1
#define False 0
void read_wrd(char *str, int max_char) /*Get string from buffer*/
{
    int i = 0;
    for (; i < max_char && (i == 0 || (str[i - 1] != ' ' && str[i - 1] != '\n' && str[i - 1] != '\t')); i++)
    {
        str[i] = getchar();
    }

    str[i - 1] = '\0';
    return;
}
int recognise(char *str)
{
    if (!strcmp(str, "signup"))
        return 1;
    if (!strcmp(str, "login"))
        return 2;
    if (!strcmp(str, "logout"))
        return 3;
    if (!strcmp(str, "post"))
        return 4;
    if (!strcmp(str, "like"))
        return 5;
    if (!strcmp(str, "delete"))
        return 6;
    if (!strcmp(str, "info"))
        return 7;
    if (!strcmp(str, "find_user"))
        return 8;
    if (!strcmp(str, "help"))
        return 9;
    if (!strcmp(str, "exit"))
        return 10;
    return False;
}
void addAtEnd(char *username, char *pass, Account **head, Account **tail)
{
    // Create a new node
    Account *newNode = (Account *)malloc(sizeof(Account));
    newNode->user = username;
    newNode->Pass = pass;
    newNode->numberofPost = 0;
    newNode->next = NULL;
    // Checks if the list is empty
    if (*head == NULL)
    {
        // If list is empty, both head and tail will point to new node
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void dynamic_input(char **address_string, char a, char b) /*Get string from buffer*/
{
    int i = 0;
    for (; i == 0 || ((*address_string)[i - 1] != a && (*address_string)[i - 1] != b); i++)
    {
        // printf("ok");
        *address_string = (char *)realloc(*address_string, (i + 1) * sizeof(char));
        (*address_string)[i] = getchar();
    }
    (*address_string)[i - 1] = '\0';
    return;
}

void instructions()
{
    printf("To signup type like this:\nsignup <username> <password>\n");
    printf("To login type like this:\nlogin <username> <password>\n");
    printf("To post something type like this:\npost <text>\n");
    printf("To like a post type like this:\nlike <username> <postID>\n");
    printf("To logout of your account just type logout\n");
    printf("To delete a post type like this:\ndelete <postID>\n");
    printf("To see your account information type like this:  info\n");
    printf("To search for an account type like this:\nfind_user <username>\n");
    printf("At any time that you want to close program just type exit\n");
    printf("At any time that you want these instructions again just type help\n");
}
void numOfPost(char *username, Account *head,Post*Head)
{
    if(username==NULL)
        return;
    Account *cur = head;
    int i = 0,c=0;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, username)){
            break;
            c++;
        }
        cur=cur->next;
    }
    Post* Cr=Head;
    while (Cr!=NULL)
    {
        if (!strcmp(Cr->user, username)){
            i++;
            c++;
        }
        Cr=Cr->next;
    }
    if(c==2)
        cur->numberofPost = i;
}
