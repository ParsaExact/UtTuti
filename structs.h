#ifndef HEADER
#define HEADER

typedef struct account Account;
typedef struct post Post;
struct account
{
    char *user, *Pass;
    int numberofPost;
    Account *next;
};
struct post
{
    char *user, *PostTxt;
    int PostID, like;
    Post *next;
};

#endif