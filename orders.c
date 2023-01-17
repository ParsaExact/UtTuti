#include"structs.h"
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#define True 1
#define False 0
Account *scan_for_signup(Account *head, char *str1)
{
    Account *cur = head;
    if (head == NULL)
        return NULL;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, str1))
            return cur;
        cur = cur->next;
    }
    return NULL;
}
int scan_for_login(Account *head, char *str1, char *str2)
{
    Account *cur = head;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, str1) && !strcmp(cur->Pass, str2))
            return True;
        cur = cur->next;
    }
    return False;
}
void addPost(char *post, Post **head, Post **tail, int postid, char *username)
{
    // Create a new node
    Post *newNode = (Post *)malloc(sizeof(Post));
    newNode->PostTxt = post;
    newNode->PostID = postid;
    newNode->like = 0;
    newNode->user = username;
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
int like(char *user, int postid, Account *headacc, Post *headpst)
{
    int c = 0;
    Account *cur = headacc;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, user))
            c++;
        cur = cur->next;
    }
    Post *Cur = headpst;
    while (Cur != NULL)
    {
        if (Cur->PostID == postid)
        {
            c++;
            Cur->like++;
        }
        Cur = Cur->next;
    }
    if (c == 2)
        return True;
    return False;
}
int Delete(int postid, char *username, Post **headpst, Account **headacc)
{
    int c = 0;
    Account *cur = *headacc;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, username))
            c++;
        cur = cur->next;
    }
    Post *Cur = *headpst, *prev;
    if (Cur != NULL && Cur->PostID == postid && c)
    {
        *headpst = Cur->next;
        free(Cur->PostTxt);
        return True;
    }
    while (Cur != NULL && Cur->PostID != postid)
    {
        prev = Cur;
        Cur = Cur->next;
    }
    if (Cur == NULL)
        return False;
    prev->next = Cur->next;
    free(Cur->PostTxt);
    free(Cur);
    return True;
}
void info(Post *head, char *username)
{
    Post *cur = head;
    while (cur != NULL)
    {
        if (!strcmp(cur->user, username))
        {
            printf("Post:%s postID:%d  likes:%d\n", cur->PostTxt, cur->PostID, cur->like);
        }
        cur = cur->next;
    }
}
