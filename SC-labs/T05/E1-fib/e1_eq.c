int fib(int n){
    int di = n;
    int a = 1;
    if (di < 2) goto R;
    di--;
    a = fib(di);
    int b = a;
    di--;
    a = fib(di);
    a += b;

R:
    return a;
}