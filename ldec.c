#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>


wchar_t english_layout[84] = {
    L'F', L'<', L'D', L'U', L'L', L'T', L'~', L':', L'P', L'B',
    L'Q', L'R', L'K', L'V', L'Y', L'J', L'G', L'H', L'C', L'N',
    L'E', L'A', L'{', L'W', L'X', L'I', L'O', L'}', L'S', L'M',
    L'"', L'>', L'Z',
    L'f', L',', L'd', L'u', L'l', L't', L'`', L';', L'p', L'b',
    L'q', L'r', L'k', L'v', L'y', L'j', L'g', L'h', L'c', L'n',
    L'e', L'a', L'[', L'w', L'x', L'i', L'o', L']', L's', L'm',
    L'\'', L'.', L'z',
    L'/', L'?', L'-', L'^', L'$', L'!', L'@', L'#', L'%', L'&', 
    L'*', L'(', L')', L'=', L'+', L'_', L'|', L'\\'        
};


wchar_t russian_layout[84] = {
    L'А', L'Б', L'В', L'Г', L'Д', L'Е', L'Ё', L'Ж', L'З', L'И',
    L'Й', L'К', L'Л', L'М', L'Н', L'О', L'П', L'Р', L'С', L'Т',
    L'У', L'Ф', L'Х', L'Ц', L'Ч', L'Ш', L'Щ', L'Ъ', L'Ы', L'Ь',
    L'Э', L'Ю', L'Я',
    L'а', L'б', L'в', L'г', L'д', L'е', L'ё', L'ж', L'з', L'и',
    L'й', L'к', L'л', L'м', L'н', L'о', L'п', L'р', L'с', L'т',
    L'у', L'ф', L'х', L'ц', L'ч', L'ш', L'щ', L'ъ', L'ы', L'ь',
    L'э', L'ю', L'я',      
    L'.', L',', L'-', L':', L';', L'!', L'\"', L'№', L'%', L'?',
    L'*', L'(', L')', L'=', L'+', L'_', L'/', L'\\'
};



// dynamic array stuff
void *append(wchar_t *array, size_t *length, size_t *capacity, wchar_t value) {
    if (*length >= *capacity) {
        *capacity *= 2;
        wchar_t *new_array = realloc(array, sizeof(wchar_t) * *capacity);
     
        if (new_array == NULL) {
            return array;
        }

        array = new_array;
    }

    array[*length] = value;
    (*length)++;

    return array;
}


void decode(wchar_t *first_layout, wchar_t *second_layout, wchar_t *string) {
    size_t str_length = wcslen(string) + 1;
    size_t layout_length = wcslen(first_layout); 
    
    for (size_t i = 0; i < str_length; i++) {
        for (int j = 0; j < layout_length; j++) {
            if (string[i] == first_layout[j]) {
                string[i] = second_layout[j];
                break;
            }

            else if(string[i] == second_layout[j]) {
                string[i] = first_layout[j];
                break;
            }
        }    
    } 
}


int main(int argc, char *argv[])
{
    size_t input_capacity = 100;
    size_t input_length = 0;
    wchar_t *input_string = malloc(sizeof(wchar_t)* input_capacity);

    setlocale(LC_ALL, "");
  
    if (argc < 2) {
        printf("\tWelcome to en/ru decoder!\n");
        printf(" Warning: write '\\' before '\\' and '\"'\n");
        printf("Enter your message: ");
    
        wchar_t temp_wchar;

        while((temp_wchar = getwchar()) != L'\n') {
            input_string = append(input_string, &input_length, &input_capacity, temp_wchar);
        }

        printf("Your decoded message is:\n");
    }
    
    else {
        for (size_t i = 1; i < argc; i++) {
            char *arg_str = argv[i];
            size_t str_len = mbstowcs(NULL, arg_str, 0);
            
            wchar_t arg_wcstr[str_len];
            
            mbstowcs(arg_wcstr, arg_str, str_len);

            for (size_t j = 0; j < str_len; j++) {
                input_string = append(input_string, &input_length, &input_capacity, arg_wcstr[j]);
            }

            if (argc > i) {
                input_string = append(input_string, &input_length, &input_capacity, L' ');
            }
        }
    }

    input_string = append(input_string, &input_length, &input_capacity, L'\0');

    decode(english_layout, russian_layout, input_string);
    printf("%ls\n", input_string);

    free(input_string);
    return EXIT_SUCCESS;
}



