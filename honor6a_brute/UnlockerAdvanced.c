#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 50
#define SAVE_INTERVAL 600 // Интервал сохранения в секундах (600 сек = 10 минут)

unsigned long long current_counter = 0ULL;

// Функция для записи текущего индекса в файл
void save_progress(unsigned long long counter) {
    FILE *file = fopen("progress.txt", "w");
    if (file != NULL) {
        fprintf(file, "%llu", counter);
        fclose(file);
        printf("\n[INFO] Прогресс успешно сохранен в progress.txt: %llu\n\n", counter);
    } else {
        printf("\n[WARNING] Не удалось записать файл progress.txt!\n\n");
    }
}

int main(int argc, char **argv) {
    // 1. ПОПЫТКА АВТОЗАГРУЗКИ: сначала проверяем, есть ли уже сохраненный файл
    FILE *file = fopen("progress.txt", "r");
    if (file != NULL) {
        if (fscanf(file, "%llu", &current_counter) == 1) {
            printf("[AUTO] Найден файл progress.txt. Начинаем с сохраненного индекса: %llu\n", current_counter);
        }
        fclose(file);
    }

    // 2. РУЧНОЙ ВВОД: если вы передали число через консоль (например, unlocker.exe 5000), 
    // оно будет иметь приоритет над файлом сохранения
    if (argc > 1) {
        current_counter = strtoull(argv[1], NULL, 10);
        printf("[MANUAL] Задан ручной старт. Начинаем с числа: %llu\n", current_counter);
    }

    char command[LEN];
    char code_str[17];
    int result;

    // Инициализируем таймер для отсчета 10 минут
    time_t last_save_time = time(NULL);

    printf("=======================================\n");
    printf("=== Honor 6A Autosave Bruteforce ===\n");
    printf("Для остановки просто закройте окно.\n");
    printf("Сохранение прогресса: каждые 10 минут.\n");
    printf("=======================================\n\n");

    while (1) {
        sprintf(code_str, "%016llu", current_counter);
        sprintf(command, "fastboot oem unlock %s", code_str);
        
        // Для максимальной скорости вы можете закомментировать строчку printf ниже (поставить //)
        printf("Index: %llu -> Trying code: %s\n", current_counter, code_str);

        result = system(command);

        if (result == 0) {
            break; 
        }

        current_counter++;

        // ПРОВЕРКА ТАЙМЕРА: прошло ли 10 минут с последнего сохранения?
        time_t current_time = time(NULL);
        if (difftime(current_time, last_save_time) >= SAVE_INTERVAL) {
            save_progress(current_counter);
            last_save_time = current_time; // Сбрасываем таймер
        }
    }

    // В случае успеха удаляем progress.txt, так как код найден
    remove("progress.txt");

    printf("\n====================================\n");
    printf("[SUCCESS] Загрузчик УСПЕШНО разблокирован!\n");
    printf("Правильный цифровой код: %s\n", code_str);
    printf("====================================\n");

    system("pause");
    return 0;
}
