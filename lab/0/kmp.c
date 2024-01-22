#include<stdio.h>
#include<stdlib.h>

int str_length (char *str) {
    int count = 0;
    while (*str != '\0') {
        count ++;
        str ++;
    }

    return count;
}

// Arguments: Pattern, Lsp array, pattern length
// preprocess an array -> notes the longest common prefix and suffix
void lsp_array_generator (char *pat, int *lsp, int p_length) {
    lsp[0] = 0;
    int i = 1;
    int j = 0;

    while (i < p_length) {
        if (pat[i] == pat[j]) {
            lsp[i] = j+1;
            j++; i++;
        } else {
            if (j != 0) {
                j = lsp[j-1];
            } else {
                lsp[i] = 0;
                i++;
            }
        }
    }
    
}

// Arguments: Pattern, Text
void kmp_search (char *pat, char *text) {
    int M = str_length (pat);
    int N = str_length (text);

    int lsp[M];
    lsp_array_generator(pat, lsp, M);
    int i = 0, j = 0;

    while (N-i >= M-j) {
        if (text[i] == pat[j]) {
            i++; j++;            
        } else {
            if (j != 0) {
                j = lsp[j-1];
            } else {
               // lsp[i] = 0;
                i++;
            }
        }

        if (j == M) {
            printf("Pattern found at index: %d\n", i-j);
            j = lsp[j-1];
        }
    }
}

int main () {

    kmp_search ("onions", "ionionsionionionspl");    

    return 0;
}
