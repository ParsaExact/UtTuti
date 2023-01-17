#include"structs.h"
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#define True 1
#define False 0
void read_wrd(char *str, int max_char);
int recognise(char *str);
void addAtEnd(char *username, char *pass, Account **head, Account **tail);
void dynamic_input(char **address_string, char a, char b); 
void instructions();
void numOfPost(char *username, Account *head,Post*Head);