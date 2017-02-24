#include <stdio.h>
#include <fcntl.h>

char* isPangram(int, char** ); 
int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    char* res;
    
    int _strings_size = 0;
    int _strings_i;
    scanf("%d\n", &_strings_size);
    char* _strings[_strings_size];
    for(_strings_i = 0; _strings_i < _strings_size; _strings_i++) {
        char* _strings_item;
        _strings_item = (char *)malloc(512000 * sizeof(char));
        scanf("\n%[^\n]",_strings_item);
        
        _strings[_strings_i] = _strings_item;
    }
    
    res = isPangram(_strings_size, _strings);
    fprintf(f, "%s\n", res);
    
    fclose(f);
    return 0;
}


char* isPangram(int strings_size, char** strings) {
    int alphabet, i, j, lv, x, k;
    char *p = (char *)malloc(sizeof(char) * strings_size);
    alphabet = 97;
    i = 0;
    
    for( lv = 0; lv < strings_size; lv++){
        for(i = 0; i < 26; i++){
            int j = 0;
            x = 97 + i;
            k = 0;
            while(*(*(strings + lv) + j) != '\n'){
                if( x == *(*(strings + lv) + j)){
                    k++;
                    break;
                }
                j++;
            }
            if(k == 0)
                break;
        }
        if(k == 0)
            *(p + lv) = 0;
        else
            *(p + lv) = 1;
    }

    return p;
}
