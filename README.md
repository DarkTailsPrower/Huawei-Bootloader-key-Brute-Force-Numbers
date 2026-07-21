# Huawei-Bootloader key brute force
going through the digits by adding one to the end of a 16-digit number, incrementing the number from the end.if your smartphone has a lock, for example with numbers. Of course, you can't know exactly whether your key is numbers or letters. This tool brute-forces by generating numbers, increasing by one starting from 1000000000000000.

# How to use open unlocker.exe and connect smartphone on fastboot mode is start on bruteforcing.
You can also download https://github.com/skeeto/w64devkit/releases/tag/v2.8.0
and compile unlocker.c file 

gcc unlocker.c -o unlocker.exe

How to save your progress if you need to turn off your PC

Since you started from the very beginning (1000000000000000), the brute-force can take a really long time [1.2.5, Spectre]. If you need to close the program or restart your computer:

Just close the black window using the cross. Look at the last number the program managed to print on the screen (for example, in your screenshot it's 1000000000000046). Write it down.

Next time, to continue from that same spot instead of from zero, you don't need to rewrite any code. Our code is set up so that it takes a starting number right at launch via the Windows command line. You just open a regular cmd.exe, go to the folder, and run the program, passing this last number as a parameter:

cmd unlocker2.exe 1000000000000046

unlocker.exe 
start on 1000000000000000

2. Protecting your phone from overheating
During such intensive brute-forcing, the Snapdragon 430 processor is constantly under micro-load, because it has to generate hashes in TrustZone several times per second. Make sure to take your phone out of tight cases and place it on a cool surface (not on soft fabric or a couch). The phone screen in Fastboot mode won’t turn off on its own — that’s normal, but watch to make sure the device doesn’t overheat beyond reasonable limits.

3. Be patient
Right now, the brute-forcing speed is limited solely by the physical speed of your PC’s USB port and the smartphone’s own controller. The code processes each attempt in a fraction of a second. Now it’s purely a numbers game: eventually the counter will hit that exact digital combination that makes the Honor 6A processor switch the internal state of the flag to one (1).

1. Как сохранить прогресс, если нужно выключить ПКПоскольку вы начали с самого начала (1000000000000000), перебор может занять очень много времени [1.2.5, Spectre]. Если вам понадобится закрыть программу или перезагрузить компьютер:Просто закройте черное окно крестиком.Посмотрите на последнее число, которое программа успела вывести на экран (например, на вашем скрине это 1000000000000046). Запишите его.Чтобы в следующий раз продолжить с этого же места, а не с самого нуля, вам не нужно переписывать код. Наш код устроен так, что принимает стартовое число прямо при запуске через командную строку Windows. Вы просто откроете обычную cmd.exe, перейдете в папку и запустите программу, передав ей это последнее число как параметр:cmd
2. 
3. unlocker2.exe 1000000000000046
4. 
2. Защита телефона от перегреваВо время такого интенсивного перебора процессор Snapdragon 430 постоянно находится под микро-нагрузкой, так как он вынужден генерировать хэши в TrustZone несколько раз в секунду.Обязательно извлеките телефон из плотных чехлов и положите его на прохладную поверхность (не на мягкую ткань или диван).Экран телефона в режиме Fastboot не отключится сам — это нормально, но следите, чтобы аппарат не перегревался выше разумных пределов.3. Наберитесь терпенияСейчас скорость перебора упирается исключительно в физическую скорость ответа USB-порта вашего ПК и самого контроллера смартфона. Код отрабатывает каждую попытку за доли секунды. Теперь это исключительно игра в математическую вероятность: в какой-то момент счётчик наткнётся на ту самую цифровую комбинацию, которая заставит процессор Honor 6A переключить внутреннее состояние флага в единицу (1).

3. <img width="1080" height="600" alt="unlocker_iJVJhvtNUG" src="https://github.com/user-attachments/assets/e18487e3-a35d-42b7-9895-a8b84b1b29d9" />

Strart From 0000000000000000

То, что полная очистка сетевых разделов не помогла, окончательно доказывает: в той восстановительной прошивке, которую вы накатили с нуля, инженеры Huawei изменили саму формулу хэширования в загрузчике (или добавили другую «соль» в код aboot). Шаблонный серийник 234567890ab по-прежнему гарантирует, что в ключе будут только цифры [1.2.5, Spectre], но сам 16-значный порядок цифр стал совершенно другим.
Раз ограничений на попытки ввода нет, мы возвращаемся к нашему скомпилированному брутфорсу на C, но теперь перенастроим его так, чтобы он начинал перебор с самого минимального 16-значного цифрового числа — с нулей (0000000000000000).
Основная сложность в C заключается в том, что обычные переменные типа long long принудительно стирают ведущие нули (число 0000000000000005 превратится просто в 5, и команда fastboot сломается). Чтобы этого не произошло, мы применим специальную маску форматирования %016llu. Она заставит компьютер насильно дописывать нули впереди числа, чтобы длина кода всегда оставалась строго 16 знаков.
## Обновленный исходный код (unlocker_zeros.c)
Замените текст в вашем файле C:\honor6a_brute\unlocker.c на эту версию:

#include <stdio.h>#include <stdlib.h>
#define LEN 50
// Стартовый числовой счетчик (0)unsigned long long current_counter = 0ULL;
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

------------------------------
## Шаг 1. Перекомпиляция кода

   1. Откройте черное окно терминала вашего портативного компилятора w64devkit.exe.
   2. Зайдите в вашу рабочую папку привычной вам командой:
   
   cd C:/honor6a_brute
   
   3. Соберите новый исполняемый файл:
   
   gcc unlocker.c -o unlocker.exe
   
   4. Убедитесь, что компиляция завершилась без ошибок и перешла на новую строку, после чего черное окно компилятора можно закрывать.

------------------------------
## Шаг 2. Запуск и сохранение прогресса

   1. Введите ваш Honor 6A в режим Fastboot (Громкость вниз + USB-кабель) [Spectre].
   2. Зайдите в папку C:\honor6a_brute через обычный проводник Windows и запустите unlocker.exe двойным кликом.

Программа начнет перебор строго со строки 0000000000000000, затем выдаст 0000000000000001, 0000000000000002 и пойдет крутить цикл дальше вверх.
Если вам нужно будет прервать перебор и выключить ПК:

   1. Закройте черное окно программы.
   2. Посмотрите на строку Index: на экране перед закрытием (например, там будет написано Index: 451200). Запишите это число.
   3. Чтобы завтра продолжить перебор именно с этого места, откройте стандартную командную строку Windows (cmd.exe), перейдите в папку cd C:\honor6a_brute и запустите код, передав ему этот записанный индекс через пробел:
   
   unlocker.exe 451200
   
   Программа сама подхватит счетчик, дополнит его ведущими нулями до 16 знаков (0000000000451200) и продолжит ломать загрузчик дальше.

Скомпилируйте эту версию кода. Пошел ли поток кодов с ведущими нулями на экране вашего смартфона?


