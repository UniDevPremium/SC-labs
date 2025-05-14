// Scrivi la soluzione qui...
void drop_spaces(char* text){
    // salviamo indirizzo iniziale
    char* head = text;
    char* i = head;
    
    // scorriamo per cercare gli spazi
    while(*text){
        char c = *text;
        if(c == ' '){
            char* next = i+1;
            while(*next && *next == c){

            }
        } else {
            i++;
        }
    }

    text = head;
}

void popChar(char* text){
    // salviamo indirizzo iniziale
    char* head = text;
    if(!*text) return;
    // scorriamo la lista
    while(*(text + sizeof(char))){
        // portiamo a sinistra
        *text = *(text + sizeof(char));
        text++;
    }

    *text = '\0';
    text = head;
}

// void drop_spaces(char* text){
//     // salviamo indirizzo iniziale
//     char* head = text;
//     // scorriamo lista per trovare spazi
//     while(*text){
//         char c = *text;
//         if(c == ' '){
//             popChar(text);
//         } else {
//             text++;
//         }
//     }

//     *text = '\0';
//     text = head;
// }

