#include <stdio.h>
#include <stdlib.h>

#define LEN 37

// Начальное число по умолчанию (если запустить просто двойным кликом)
unsigned long long base_start = 1000000000000000ULL;

int main(int argc, char **argv) {
    // ПРОВЕРКА: Если пользователь передал аргумент при запуске
    if (argc > 1) {
        // Превращаем текст из командной строки в 64-битное число
        base_start = strtoull(argv[1], NULL, 10);
    }

    char fou[LEN] = {'f', 'a', 's', 't', 'b', 'o', 'o', 't', ' ',
                     'o', 'e', 'm', ' ', 'u', 'n', 'l', 'o', 'c', 'k', ' '};
    char TOTAL[LEN];
    int result;

    printf("=======================================\n");
    printf("=== Honor 6A Bootloader Bruteforce ===\n");
    printf("Starting с числа: %llu\n", base_start);
    printf("Для остановки нажмите Ctrl + C или закройте окно.\n");
    printf("=======================================\n\n");

    while (1) {
        sprintf(TOTAL, "%s%llu", fou, base_start);
        printf("Trying code: %llu\n", base_start);

        result = system(TOTAL);

        if (result == 0) {
            break; 
        }

        base_start++;
    }

    printf("\n====================================\n");
    printf("[SUCCESS] Загрузчик разблокирован!\n");
    printf("Правильный код разблокировки: %llu\n", base_start);
    printf("====================================\n");

    system("pause");
    return 0;
}
