int is_vowel(int c); // restituisce 0/1

int num_vowels(char *s) {
    int cnt = 0;
    while (*s)
        cnt += is_vowel(*s++);
    return cnt;
}
