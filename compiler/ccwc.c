#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ccwc.h"
#include "utils.h"
string* generate_unwrapper_command(char** argv)
{
    string* command=str_construct_with_char((char*) CCWC_EXECUTABLE);
    str_append_char(command," \"");
    str_append_char(command,argv[1]);
    str_append_char(command,"\" \"");
    str_append_char(command,argv[1]);
    str_append_char(command,".unwrapped.c\"");
    return command;
}
string* generate_gcc_command(char** argv)
{
    string* command=str_construct_with_char((char*) GCC_EXECUTABLE);
    str_append_char(command," \"");
    str_append_char(command,argv[1]);
    str_append_char(command,".unwrapped.c\" -o \"");
    str_append_char(command,argv[2]);
    str_append_char(command,"\"");
    return command;
}
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        puts("Invalid argument");
        return 1;
    }
    string* unwrapper_command = generate_unwrapper_command(argv);
    printf("[INFO] ccwc.exe: %s\n",unwrapper_command->ptr);
    system(unwrapper_command->ptr);
    str_dispose(unwrapper_command);
    string* gcc_command = generate_gcc_command(argv);
    printf("[INFO] ccwc.exe: %s\n",gcc_command->ptr);
    system(gcc_command->ptr);
    str_dispose(gcc_command);
    return 0;
}