// Inserire qui la soluzione
char *my_strcpy(char *dest, const char *src){
    char* head = dest;
    while(*src){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return head;
}