#ifndef __DO_SHELL__
#define __DO_SHELL__

#define MAX_LINE    1024
#define MAX_TOKENS  64

void get_cmd_line(char* argv[MAX_TOKENS]);
int do_shell(const char* prompt);

#endif