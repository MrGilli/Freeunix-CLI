#include "../include/string.h"

int isupper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}

int isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

char *ltrim(char *s)
{
    while (isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while (isspace(*--back));
    *(back + 1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

