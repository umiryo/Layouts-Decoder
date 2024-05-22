#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void en_ru_decode(char **english_alphabet, char **russian_alphabet, char *string) {
    size_t length = strlen(string);

    char *space[1] = {" "};
    char *numbers[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};


    char *string_arr[length]; 

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < 84; ++j) {
            if (string[i] == *english_alphabet[j]) {
                string_arr[i] = russian_alphabet[j];
                break;
            } else if (string[i] == *space[0]) {
                string_arr[i] = space[0];
                break;
            }
        }
        for (int n = 0; n < 10; ++n) {
            if (string[i] == *numbers[n]) {
                string_arr[i] = numbers[n];
                break;
            }
        }
    }

    for (int v = 0; v < length; ++v) {
        printf("%s", string_arr[v]);
    }
    
}

void ru_en_decode(char **english_alphabet, char **russian_alphabet, char *string) {
    size_t length = strlen(string);

    char *space[1] = {" "};
    char *numbers[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};


    char *string_arr[length]; 

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < 84; ++j) {
            if (string[i] == *russian_alphabet[j]) {
                string_arr[i] = english_alphabet[j];
                break;
            } else if (string[i] == *space[0]) {
                string_arr[i] = space[0];
                break;
            }
        }
        for (int n = 0; n < 10; ++n) {
            if (string[i] == *numbers[n]) {
                string_arr[i] = numbers[n];
                break;
            }
        }
    }

    for (int v = 0; v < length; ++v) {
        printf("%s", string_arr[v]);
    }
    
}

//@, #, $, ^, &, ~, `, |, <, > are not supported
int main() {
    printf("\tWelcome to en/ru decoder!\n");
    printf(" Warning: write '\\' before '\\' and '\"'\n");
    printf("Enter your message: ");
    char main_string[100];
    scanf(" %[^\n]s", main_string);


	char *english_alphabet[84] = {
        "F", "<", "D", "U", "L", "T", "~", ":", "P", "B",
        "Q", "R", "K", "V", "Y", "J", "G", "H", "C", "N",
        "E", "A", "{", "W", "X", "I", "O", "}", "S", "M",
        "\"", ">", "Z",
        "f", ",", "d", "u", "l", "t", "`", ";", "p", "b",
        "q", "r", "k", "v", "y", "j", "g", "h", "c", "n",
        "e", "a", "[", "w", "x", "i", "o", "]", "s", "m",
        "'", ".", "z",
        "/", "?", "-", "^", "$", "!", "@", "#", "%", "&", 
        "*", "(", ")", "=", "+", "_", "|", "\\"        
    };

    char *russian_alphabet[84] = {
        "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И",
        "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т",
        "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь",
        "Э", "Ю", "Я",
        "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и",
        "й", "к", "л", "м", "н", "о", "п", "р", "с", "т",
        "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь",
        "э", "ю", "я",      
        ".", ",", "-", ":", ";", "!", "\"", "№", "%", "?",
        "*", "(", ")", "=", "+", "_", "/", "\\"
    };
    printf(" Your message is: \"%s\"\n", main_string);
    printf("Decoded message is: \"");
    for (int i = 0; i < 84; ++i) {
        char ch1 = *english_alphabet[i];
        char ch2 = *russian_alphabet[i];

        if(strchr(main_string, ch1)) {
            en_ru_decode(english_alphabet, russian_alphabet, main_string);
            break;
        } else if(strchr(main_string, ch2)) {
            printf("ru/en decode currently works incorrectly, wait for project update");
            //ru_en_decode(english_alphabet, russian_alphabet, main_string);
            break;
        }
    }

    printf("\"\n");
    return 0;
}
