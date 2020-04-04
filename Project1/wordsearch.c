#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
char** leftToRight(char** arr, int n, char** list, int listSize);
char** rightToLeft(char** arr, int n, char** list, int listSize);
char** topToBottom(char** arr, int n, char** list, int listSize);
char** topLeftToBottomRight(char** arr, int n, char** list, int listSize);
char** topRightToBottomLeft(char** arr, int n, char** list, int listSize);
typedef enum {true, false} bool;
char *foundWords[50];
char **ptrFoundWords = foundWords;
int foundWordsCounter = 0;


// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
    char **words = (char**)malloc(50 * sizeof(char*));
    
    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }
    
    // Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));
        
        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
    fclose(fptr);
    
    // Open file for reading word list
    fptr = fopen("states.txt", "r");
    if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
    
    // Save words into arrays
    for(i=0; i<50; i++){
        *(words+i) = (char*)malloc(20 * sizeof(char));
        fgets(*(words+i), 20, fptr);
    }
    
    // Remove newline characters from each word (except for the last word)
    for(i=0; i<49; i++){
        *(*(words+i) + strlen(*(words+i))-2) = '\0';
    }
    
    // Print out word list
    printf("Printing list of words:\n");
    for(i=0; i<50; i++){
        printf("%s\n", *(words + i));
    }
    printf("\n");
    
    // Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
    printf("\n");
    
    // Call searchPuzzle to find all words in the puzzle
    searchPuzzle(block, bSize, words, 50);
    printf("\n");
    
    // Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
    printf("\n");
    
    return 0;
}

void printPuzzle(char** arr, int n){
    // This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
    // Your implementation here
    
    int i, j;
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%c ", *(*(arr+i)+j));
        }
        printf("\n");
    }
    printf("\n\n");
}
void searchPuzzle(char** arr, int n, char** list, int listSize){
    // This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
    // Your implementation here
    
    // [DONE] diagonal top left to bottom right
    topLeftToBottomRight(arr, n, list, listSize);
    
    // [DONE] diagonal top right to bottom left
    topRightToBottomLeft(arr, n, list, listSize);
    
    //horizontal left to right
    leftToRight(arr, n, list, listSize);
    
    //horizontal right to left
    rightToLeft(arr, n, list, listSize);
    
    // [DONE] vertical top to bottom
    topToBottom(arr, n, list, listSize);
    
    // Sort found words
    int arrSize = foundWordsCounter;
    char *outputWords[arrSize];
    char **ptrOutputWords = outputWords;
    int outputWordsCounter = 0;
    
    int minIndex = 0;
    char* minWord;
    int nextWordIndex = 1;
    int currentWordCharIndex = 0;
    int nextWordCharIndex = 0;
    int k = 0;
    
    int m = 0;
    while (m < arrSize) {
        k = 0;
        nextWordIndex = 0;
        currentWordCharIndex = 0;
        nextWordCharIndex = 0;
        while (k < foundWordsCounter && nextWordIndex < foundWordsCounter) {
            char* currentWord = ptrFoundWords[k];
            char* nextWord = ptrFoundWords[nextWordIndex];
            if (currentWord != nextWord) {
                if (currentWord[currentWordCharIndex] < nextWord[nextWordCharIndex] || nextWord[nextWordCharIndex] == '{') {
                    nextWordIndex++;
                    currentWordCharIndex = 0;
                    nextWordCharIndex = 0;
                    minWord = currentWord;
                } else if (currentWord[currentWordCharIndex] > nextWord[nextWordCharIndex] || currentWord[currentWordCharIndex] == '{') {
                    k++;
                    currentWordCharIndex = 0;
                    nextWordCharIndex = 0;
                    minWord = nextWord;
                } else if (currentWord[currentWordCharIndex] == nextWord[nextWordCharIndex]) {
                    currentWordCharIndex++;
                    nextWordCharIndex++;
                }
            } else {
                nextWordIndex++;
            }
        }
        ptrOutputWords[outputWordsCounter] = minWord;
        outputWordsCounter++;
        m++;
        for (int z = 0; z < foundWordsCounter; z++) {
            if (minWord == ptrFoundWords[z]) {
                ptrFoundWords[z] = "{";
            }
        }
    }
    
    for (int y = 0; y < foundWordsCounter; y++) {
        if (y != foundWordsCounter - 1) {
            printf("Word Found: %s\n", outputWords[y]);
        } else {
            printf("Word Found: %s\n\n", outputWords[y]);
        }
    }
}

char** leftToRight(char** arr, int n, char** list, int listSize){
    bool match = false;
    
    int counter = 0;
    int i = 0;
    int l = 0;
    int c= 0;
    int r = 0;
    while (i < 50 && strlen((*(list + i))) != 0) {
        char *currentState = (*(list + i));
        match = false;
        c = 0;
        l = 0;
        r = 0;
        
        while (l < strlen(currentState) && r < n && match == false){
            char letter = *(currentState + l);//changed
            letter &= ~' ';
            c = 0;
            while (r < n && match == false) {
                counter = 0;
                l = 0;
                c = 0;
                while(c < n && match == false){
                    if(*(*(arr + r) + c) == letter){
                        
                        counter++;
                        l++;
                        letter = *(currentState + l);
                        letter &= ~' ';
                    } else {
                        l = 0;
                        letter = *(currentState + l);
                        letter &= ~' ';
                        counter = 0;
                    }
                    if (counter == strlen(currentState)) {
                        ptrFoundWords[foundWordsCounter] = currentState;
                        foundWordsCounter++;
                        for (int b = c; b > (c-counter); b--) {
                            *(*(arr + r) + b) += 32;
                        }
                        match = true;
                    }
                    c++;
                }
                r++;
            }
        }
        i++;
    }
    return arr;
}

char** rightToLeft(char** arr, int n, char** list, int listSize){
    bool match = false;
    
    int counter = 0;
    int i = 0;
    int l = 0;
    int c = n - 1;
    int r = 0;
    while (i < 50 && strlen((*(list + i))) != 0) {
        char *currentState = (*(list + i));
        match = false;
        c = n - 1;
        l = 0;
        r = 0;
        
        while (l < strlen(currentState) && r < n && match == false){
            char letter = *(currentState + l);//changed
            letter &= ~' ';
            c = n - 1;
            //            printf("%lu", strlen(currentState));
            while (r < n && match == false) {
                counter = 0;
                l = 0;
                c = n - 1;
                while(c > 0 && match == false){
                    if(*(*(arr + r) + c) == letter){
                        counter++;
                        l++;
                        letter = *(currentState + l);
                        letter &= ~' ';
                    } else {
                        l = 0;
                        letter = *(currentState + l);
                        letter &= ~' ';
                        counter = 0;
                    }
                    if (counter == strlen(currentState)) {
                        ptrFoundWords[foundWordsCounter] = currentState;
                        foundWordsCounter++;
                        for (int b = c; b < (c+counter); b++) {
                            *(*(arr + r) + b) += 32;
                        }
                        match = true;
                    }
                    c--;
                }
                r++;
            }
        }
        i++;
        //        exit(0);
    }
    return arr;
}

char** topToBottom(char** arr, int n, char** list, int listSize){
    bool match = false;
    bool letterMatch = false;
    
    int counter = 0;
    int i = 0;
    int l = 0;
    int c= 0;
    int r = 0;
    while (i < 50) {
        char *currentState = (*(list + i));
        match = false;
        c = 0;
        l = 0;
        r = 0;
        
        while(c < n && match == false){
            letterMatch = false;
            counter = 0;
            l = 0;
            r = 0;
            while (l < strlen(currentState) && r < n && match == false){
                char letter = *(currentState + l); //currentState[l]
                letter &= ~' ';
                r = 0;
                while (r < n && match == false) {
                    char tempArrLetter = *(*(arr + r) + c);
                    if(tempArrLetter >= 'a' && tempArrLetter <= 'z') {
                        tempArrLetter -= 32;
                    }
                    if(tempArrLetter == letter){
                        letterMatch = true;
                        
                        counter++;
                        l++;
                        letter = *(currentState + l); //currentState[l]
                        letter &= ~' ';
                    } else {
                        l = 0;
                        l = 0;
                        letter = *(currentState + l); //currentState[l]
                        letter &= ~' ';
                        counter = 0;
                    }
                    if (counter == strlen(currentState)) {
                        ptrFoundWords[foundWordsCounter] = currentState;
                        foundWordsCounter++;
                        for (int b = r; b > (r-counter); b--) {
                            if(*(*(arr + b) + c) >= 'A' && *(*(arr + b) + c) <= 'Z') {
                                *(*(arr + b) + c) += 32; //arr[b][c] = arr[b][c] + 32
                            }
                        }
                        match = true;
                    }
                    r++;
                }
            }
            c++;
        }
        i++;
    }
    return arr;
}

char** topLeftToBottomRight(char** arr, int n, char** list, int listSize){
    bool match = false;
    bool letterMatch = false;
    
    int counter = 0;
    int i = 0;
    int l = 0;
    int c= 0;
    int r = 0;
    while (i < 50) {
        char *currentState = (*(list + i));
        match = false;
        c = 0;
        l = 0;
        r = 0;
        
        while(c < n && match == false){
            letterMatch = false;
            counter = 0;
            l = 0;
            r = 0;
            while (l < strlen(currentState) && r < n && match == false){ //check r < n
                char letter = *(currentState + l); //changed to pointer
                letter &= ~' ';
                r = 0;
                while (r < n && match == false) {
                    int diagCol = c;
                    int diagRow = r;
                    l = 0;
                    letter = *(currentState + l); //changed to pointer
                    letter &= ~' ';
                    while (diagCol < n && diagRow < n) {
                        if( *(*(arr + diagRow) + diagCol) == letter){//arr[diagRow][diagCol]
                            
                            letterMatch = true;
                            
                            counter++;
                            l++;
                            letter = *(currentState + l);//changed
                            letter &= ~' ';
                        } else {
                            counter = 0;
                        }
                        
                        if (counter == strlen(currentState)) {
                            ptrFoundWords[foundWordsCounter] = currentState;
                            foundWordsCounter++;
                            int col = diagCol;
                            for (int b = diagRow; b > (diagRow-counter); b--) {
                                *(*(arr + b) + col) += 32; //arr[b][col] = arr[b][col] + 32
                                col--;
                            }
                            match = true;
                        }
                        diagCol++; //concerned
                        diagRow++;
                    }
                    r++;
                }
            }
            c++;
        }
        i++;
    }
    return arr;
}

char** topRightToBottomLeft(char** arr, int n, char** list, int listSize){
    bool match = false;
    bool letterMatch = false;
    
    int counter = 0;
    int i = 0;
    int l = 0;
    int c = n;
    int r = 0;
    while (i < 50) {
        char *currentState = (*(list + i));
        match = false;
        c = n - 1;
        l = 0;
        r = 0;
        
        while(c > 0 && match == false){
            letterMatch = false;
            counter = 0;
            l = 0;
            r = 0;
            while (l < strlen(currentState) && r < n && match == false){ //check r < n
                char letter = *(currentState + l);//currentState[l]
                letter &= ~' ';
                r = 0;
                while (r < n && match == false) {
                    int diagCol = c;
                    int diagRow = r;
                    l = 0;
                    letter = *(currentState + l); //changed into pointer from currentState[l]
                    letter &= ~' ';
                    while (diagCol > 0 && diagRow < n) {
                        if(*(*(arr + diagRow) + diagCol) == letter){ //arr[diagRow][diagCol]
                            letterMatch = true;
                            
                            counter++;
                            l++;
                            letter = *(currentState + l);//changed to pointer
                            letter &= ~' ';
                        } else {
                            counter = 0;
                        }
                        
                        if (counter == strlen(currentState)) {
                            ptrFoundWords[foundWordsCounter] = currentState;
                            foundWordsCounter++;
                            int col = diagCol;
                            for (int b = diagRow; b > (diagRow-counter); b--) {
                                *(*(arr+b)+col) += 32;// arr[b][col] = arr[b][col] + 32;
                                col++;
                            }
                            match = true;
                        }
                        diagCol--; //concerned
                        diagRow++;
                    }
                    r++;
                }
            }
            c--;
        }
        i++;
    }
    return arr;
}
