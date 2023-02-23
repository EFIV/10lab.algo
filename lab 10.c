#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORDS_COUNT 39
#define WORDS_MAX_LENGTH 20

int main() {
    char words[WORDS_COUNT][WORDS_MAX_LENGTH] = {
        "вайлом", "вайлуватий", "вайлюка", "вак", "вакан", "ваканець", "ваканцьовий", "вакарка", "вакарь", "вакаціюватися",
        "вакація", "вакелія", "вакернипа", "вакиристий", "вакса", "ваксовий", "ваксувати", "вакувати", "вал", "валасання",
        "валасатися", "валах", "валахан", "валашайник", "валашал", "валашання", "валашати", "валашний", "валашок", "валежний",
        "валець", "валєнки", "валиво", "валивочко", "валило", "валина", "валити", "валитися"
    };
    char longest_word[WORDS_MAX_LENGTH];
    int longest_word_length = 0;

    // Знайдемо найдовше слово
    for (int i = 0; i < WORDS_COUNT; i++) {
        int word_length = strlen(words[i]);
        if (word_length > longest_word_length) {
            longest_word_length = word_length;
            strcpy(longest_word, words[i]);
        }
    }

    printf("Найдовше слово: %s\n", longest_word);

    // Видалимо слова, що складаються тільки з латинських літер
    for (int i = 0; i < WORDS_COUNT; i++) {
        int only_english = 1;
        for (int j = 0; j < strlen(words[i]); j++) {
            if (!isalpha(words[i][j]) || !isascii(words[i][j])) {
                only_english = 0;
                break;
            }
        }
        if (!only_english) {
            printf("%s ", words[i]);
        }
    }
    printf("\n");

    return 0;
}
