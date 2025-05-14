#include "e2.h"

int crc32b(char *bytes, int n){
    // pushl ebx
    // pushl esi
    // pushl edi
    // int magic = ~0; // operazione: not
    int b = 0; 
    b = ~b;
    // int crc = magic;
    int bp = b;
    char *si = bytes;
    int di = n;
    // while (n--) {
L:  if(di <= 0) goto E;
    //     int value;
    //     int byte = *bytes++; // attenzione!
    int d = *si;
    si++;
    //     int index = crc ^ byte;
    d = d ^ bp;
    d = d & 0xFF;
    int stack1 = d;
    // pushl edi
    // pushl &edi
    //     get_constant(&value, index & 0xFF);
    int stack2;
    get_constant(&stack2, stack1);
    //     crc = value ^ (crc >> 8);
    bp = bp >> 8;
    bp = bp ^ stack2;
    di--;
    goto L;
    // }
E:  // return crc ^ magic;
    bp = bp ^ b;
    int a = bp;
    return a;
}