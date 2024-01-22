#include<stdio.h>
#include"kmp_search.h"
// the lsp array will give the length of the largest suffix and prefix

int main() {
    
    char *text = "";
    char *pattern = "aabaaac";
                //   0101220 
    // int pattern_len = str_length(pattern);
    // printf("\nPattern length: %d\n", pattern_len);
    // int lsp_array[pattern_len];
    // lsp_array_generator(pattern, lsp_array, pattern_len);


    // for(int i=0; i<pattern_len; i++) {
    //     printf("%d ", lsp_array[i]);
    // }

    // printf("txt length: %d, pat length: %d\n", str_length("onionionsplionions"), str_length("onions"));
    kmp_search("onions", "onionionsplionions");

    return 0;
}
