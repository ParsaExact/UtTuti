#include"structs.h"

#include<stdio.h>
Account *scan_for_signup(Account *head, char *str1);
int scan_for_login(Account *head, char *str1, char *str2);
void addPost(char *post, Post **head, Post **tail, int postid, char *username);
int like(char *user, int postid, Account *headacc, Post *headpst);
int Delete(int postid, char *username, Post **headpst, Account **headacc);
void info(Post *head, char *username);