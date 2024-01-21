#include"kmp_search.h"
#include<stdlib.h>
#include<stdio.h>


int str_length (char *string) {
    int count = 0;

    while (*string != '\0') {
        count ++;
        string ++;
    }

    return count;
}

// pattern, lps, pattern_length
void lsp_array_generator (char *pat, int *lps, int M) {

    lps[0] = 0; 
 
    int j = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[j]) {
            lps[i] = j+1;
            j++;
            i++;
        }
        else 
        {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    // int j = 0;
    // int i = 1;   
    // lsp_array[0] = 0;

    // while (i < len) {
    //     if (pattern[i] == pattern[j]) {
    //         lsp_array[i] = j+1;
    //         i++; j++; 

    //     } else {
    //         if (len != 0) {
    //             j = lsp_array[j-1];
    //         } else {
    //             lsp_array[i] = 0;
    //             i++;
    //         }
    //     }
    // }

}


// Arg1: text, Arg2: pattern
// void kmp_search (char *text, char *pattern) {
//     int t_length = str_length (text);
//     int p_length = str_length (pattern);

//     int lsp_array[p_length];
//     lsp_array_generator(pattern, lsp_array, p_length);

//     printf("\n");
//     for(int i=0; i<p_length; i++) {
//         printf("%d ", lsp_array[i]);
//     }

//     int i = 0; // text pointer
//     int j = 0; // pattern pointer

//     while (i <= t_length-p_length+1) {
//         if (text[i] == pattern[j]) {
//             i++; j++;
//         } else {
//             if (j != 0) {
//                 j = lsp_array[j-1];
//             } else {
//                 i++;
//             }
//         }
//         if ( j == p_length) {
//             printf("\nText matched at: %d", i-j);
//             j = lsp_array[j-1];
//         }
//     }

// }


// Arg1: pattern, Arg2: txt
void kmp_search(char* pat, char* txt)
{
    int M = str_length(pat);
    int N = str_length(txt);
 
    int lps[M];
 
    lsp_array_generator(pat, lps, M);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    // while ((N - i) >= (M - j)) {
    while (i < N) {
        if (txt[i] == pat[j]) {
            i++; j++;
        } else {
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }


        if ( j == M) {
            printf("\nText matched at: %d", i-j);
            j = lps[j-1];
        }
    }

}
 