#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include"structs.h"
#include"orders.h"
#include"other.h"
#include"fileWriting.h"
#define True 1
#define False 0
int main()
{
    Account *head = NULL;
    Account *tail = NULL;
    Post *Head = NULL, *Tail = NULL;
    int flag = False, order, i = 1, num = -1;
    char word[10];
    char *curWord = NULL, *curWord2 = NULL;
    instructions();
    FILE *myfile1 = NULL, *myfile2 = NULL;
    while (True)
    {
        char *word2 = NULL, *word3 = NULL, *line = NULL;
        fflush(stdin);
        read_wrd(word, 10);
        order = recognise(word);
        switch (order)
        {
        case 1:
            dynamic_input(&word2, ' ', '\n');
            dynamic_input(&word3, ' ', '\n');
            if ((scan_for_signup(head, word2) == NULL) && flag == False)
            {
                addAtEnd(word2, word3, &head, &tail);
                printf("Signup successful!\n");
            }
            else
                printf("Signup failed!Try again.\n");
            break;
        case 2:
            dynamic_input(&word2, ' ', '\n');
            dynamic_input(&word3, ' ', '\n');
            if (scan_for_login(head, word2, word3))
            {
                if (flag)
                {
                    printf("You'r already loged in to another account! Try to logout first.\n");
                    break;
                }
                flag = True;
                curWord = word2;
                curWord2 = word3;
                printf("login successful\n");
            }
            else
                printf("User not found!\n");
            break;
        case 3:
            if (flag)
            {
                flag = False;
                printf("logout successful!\n");
            }
            else
                printf("You'r not loged in to logout!!\n");
            break;
        case 4:
            if (!flag)
            {
                printf("First login to your account!\n");
                break;
            }
            dynamic_input(&line, '\n', '\n');
            addPost(line, &Head, &Tail, i, curWord);
            printf("You posted: %s\n", line);
            i++;
            break;
        case 5:
            if (!flag)
            {
                printf("First login to your account!\n");
                break;
            }
            dynamic_input(&word2, ' ', '\n');
            dynamic_input(&word3, ' ', '\n');
            num = atoi(word3);
            if (like(word2, num, head, Head))
                printf("You liked username(%s)'s post with id(%d)\n", word2, num);
            else
                printf("Either user or postid not found!!\n");
            break;
        case 6:
            if (!flag)
            {
                printf("First login to your account!\n");
                break;
            }
            dynamic_input(&word2, ' ', '\n');
            num = atoi(word2);
            if (Delete (num, curWord, &Head, &head))
                printf("You deleted the post with id<<%d>>\n", num);
            else
                printf("There is no post with such id!\n");
            break;
        case 7:
            if (!flag)
            {
                printf("First login to your account!\n");
                break;
            }
            printf("Username: %s\n", curWord);
            printf("Password: %s\n", curWord2);
            info(Head, curWord);
            break;
        case 8:
            dynamic_input(&word2, ' ', '\n');
            if (scan_for_signup(head, word2))
            {
                printf("Username: %s\n", word2);
                info(Head, word2);
            }
            else
                printf("User not found!!");
            break;
        case 9:
            instructions();
            break;
        case 10:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Command not found!!\n");
            break;
        }
        // printf("%s",curWord);
        numOfPost(curWord, head,Head);
        myfile1 = fopen("accounts.txt", "w");
        myfile2 = fopen("posts.txt", "w");
        accountFile(myfile1, head);
        postfile(myfile2, Head);
        fclose(myfile1);
        fclose(myfile2);
    }
}
