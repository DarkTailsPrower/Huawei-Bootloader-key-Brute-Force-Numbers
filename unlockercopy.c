#include <stdio.h>
#include <stdlib.h>

#define LEN 37

// Начальное 16-значное число для перебора
unsigned long long base_start = 1000000000019126ULL;

int main() {
    // Массив для хранения базовой команды fastboot
    char fou[LEN] = {'f', 'a', 's', 't', 'b', 'o', 'o', 't', ' ',
                     'o', 'e', 'm', ' ', 'u', 'n', 'l', 'o', 'c', 'k', ' '};
    char TOTAL[LEN];
    int result;

    printf("=== Honor 6A Bootloader Bruteforce ===\n");
    printf("Starting перебор с: %llu\n", base_start);
    printf("Для остановки просто закройте это окно.\n\n");

    // Бесконечный цикл перебора
    while (1) {
        // Склеиваем команду fastboot oem unlock и текущее число
        sprintf(TOTAL, "%s%llu", fou, base_start);
        
        // Выводим в консоль текущую попытку, чтобы видеть прогресс
        printf("Trying code: %llu\n", base_start);

        // Выполняем команду в системе
        result = system(TOTAL);

        // Если телефон принял ключ, команда fastboot возвращает 0 (успех)
        if (result == 0) {
            break; 
        }

        // Если ключ не подошел, переходим к следующему числу
        base_start++;
    }

    // Этот код выполнится только тогда, когда цикл прервется успехом
    printf("\n====================================\n");
    printf("[SUCCESS] Загрузчик разблокирован!\n");
    printf("Правильный код разблокировки: %llu\n", base_start);
    printf("====================================\n");

    system("pause");
    return 0;
}
