#include <stdio.h>
#include <stdlib.h>

#define LEN 50

// Стартовый числовой счетчик (0)
unsigned long long current_counter = 0ULL;

int main(int argc, char **argv) {
    // Если вы захотите продолжить перебор не с нуля, а, например, с 500000,
    // вы сможете передать это число в аргументе при запуске: unlocker.exe 500000
    if (argc > 1) {
        current_counter = strtoull(argv[1], NULL, 10);
    }

    char command[LEN];
    char code_str[17];
    int result;

    printf("=======================================\n");
    printf("=== Honor 6A Pure Zeros Bruteforce ===\n");
    printf("Starting from numeric index: %llu\n", current_counter);
    printf("Длина генерируемого кода: СТРОГО 16 знаков\n");
    printf("Для остановки закройте окно или нажмите Ctrl+C\n");
    printf("=======================================\n\n");

    while (1) {
        // МАГИЯ МАСКИ %016llu: она превращает число (например, 145) 
        // в строку с ведущими нулями: "0000000000000145"
        sprintf(code_str, "%016llu", current_counter);

        // Собираем финальную команду fastboot oem unlock
        sprintf(command, "fastboot oem unlock %s", code_str);
        
        printf("Index: %llu -> Trying code: %s\n", current_counter, code_str);

        // Отправляем команду по USB в смартфон
        result = system(command);

        // Если fastboot возвращает 0 — ключ подошел и сработал!
        if (result == 0) {
            break; 
        }

        // Переходим к следующей комбинации
        current_counter++;
    }

    printf("\n====================================\n");
    printf("[SUCCESS] Загрузчик УСПЕШНО разблокирован!\n");
    printf("Правильный цифровой код: %s\n", code_str);
    printf("Финальный индекс счетчика: %llu\n", current_counter);
    printf("====================================\n");

    system("pause");
    return 0;
}
