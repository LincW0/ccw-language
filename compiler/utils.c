#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils.h"
string* str_construct()
{
    string* cur=(string*) malloc(sizeof(string));
    cur->ptr=(char*) malloc(BUFFER_SIZE);
    cur->len=0;
    return cur;
}
void str_copy_char(string* cur,char* other)
{
    cur->len=strlen(other);
    strcpy(cur->ptr,other);
}
void str_copy(string* cur,string* other)
{
    cur->len=other->len;
    strcpy(cur->ptr,other->ptr);
}
string* str_construct_with_str(string* other)
{
    string* cur=str_construct();
    str_copy(cur,other);
    return cur;
}
string* str_construct_with_char(char* other)
{
    string* cur=str_construct();
    str_copy_char(cur,other);
    return cur;
}
void str_append(string* cur,string* other)
{
    strcpy(cur->ptr+cur->len,other->ptr);
    cur->len+=other->len;
}
void str_append_char(string* cur,char* other)
{
    strcpy(cur->ptr+cur->len,other);
    cur->len+=strlen(other);
}
void str_dispose(string* cur)
{
    free(cur->ptr);
    free(cur);
}