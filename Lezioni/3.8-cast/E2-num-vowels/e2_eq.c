// Scrivere C equivalente qui...
int is_vowel(int c); // restituisce 0/1

int num_vowels(char *s) {
    char* b = s;
    int di = 0;

T:
    if(*b == 0) goto R;
    int a = *b;
    a = is_vowel(a);
    di += a;
    b++;
    goto T;

R:
    a = di;
    return a;
}
