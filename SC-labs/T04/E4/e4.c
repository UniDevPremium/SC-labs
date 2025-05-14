// Scrivere la soluzione qui
int count_substrings(const char* s, const char* sub){
    if (*sub == '\0') {
        return 1;
    }
    int count = 0;
    while(*s){
       const char* temp = s;
       const char* temp_sub = sub;

       while(*temp && *temp_sub && *temp == *temp_sub){
        temp++;
        temp_sub++;
       }

       if(!*temp_sub) count++;
       s++;
    }
    return count;
}