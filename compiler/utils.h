#ifndef _CCW_COMPILER_UTILS_H_
typedef struct string_s
{
    char* ptr;
    int len;
} string;
string* str_construct();
void str_copy_char(string* cur,char* other);
void str_copy(string* cur,string* other);
string* str_construct_with_str(string* other);
string* str_construct_with_char(char* other);
void str_append(string* cur,string* other);
void str_append_char(string* cur,char* other);
void str_dispose(string* cur);
#define _CCW_COMPILER_UTILS_H_
#endif