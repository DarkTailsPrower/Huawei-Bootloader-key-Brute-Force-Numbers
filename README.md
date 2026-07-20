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

cmd unlocker.exe 1000000000000046

2. Protecting your phone from overheating
During such intensive brute-forcing, the Snapdragon 430 processor is constantly under micro-load, because it has to generate hashes in TrustZone several times per second. Make sure to take your phone out of tight cases and place it on a cool surface (not on soft fabric or a couch). The phone screen in Fastboot mode won’t turn off on its own — that’s normal, but watch to make sure the device doesn’t overheat beyond reasonable limits.

3. Be patient
Right now, the brute-forcing speed is limited solely by the physical speed of your PC’s USB port and the smartphone’s own controller. The code processes each attempt in a fraction of a second. Now it’s purely a numbers game: eventually the counter will hit that exact digital combination that makes the Honor 6A processor switch the internal state of the flag to one (1).

1. Как сохранить прогресс, если нужно выключить ПКПоскольку вы начали с самого начала (1000000000000000), перебор может занять очень много времени [1.2.5, Spectre]. Если вам понадобится закрыть программу или перезагрузить компьютер:Просто закройте черное окно крестиком.Посмотрите на последнее число, которое программа успела вывести на экран (например, на вашем скрине это 1000000000000046). Запишите его.Чтобы в следующий раз продолжить с этого же места, а не с самого нуля, вам не нужно переписывать код. Наш код устроен так, что принимает стартовое число прямо при запуске через командную строку Windows. Вы просто откроете обычную cmd.exe, перейдете в папку и запустите программу, передав ей это последнее число как параметр:cmd
2. unlocker.exe 1000000000000046

2. Защита телефона от перегреваВо время такого интенсивного перебора процессор Snapdragon 430 постоянно находится под микро-нагрузкой, так как он вынужден генерировать хэши в TrustZone несколько раз в секунду.Обязательно извлеките телефон из плотных чехлов и положите его на прохладную поверхность (не на мягкую ткань или диван).Экран телефона в режиме Fastboot не отключится сам — это нормально, но следите, чтобы аппарат не перегревался выше разумных пределов.3. Наберитесь терпенияСейчас скорость перебора упирается исключительно в физическую скорость ответа USB-порта вашего ПК и самого контроллера смартфона. Код отрабатывает каждую попытку за доли секунды. Теперь это исключительно игра в математическую вероятность: в какой-то момент счётчик наткнётся на ту самую цифровую комбинацию, которая заставит процессор Honor 6A переключить внутреннее состояние флага в единицу (1).
