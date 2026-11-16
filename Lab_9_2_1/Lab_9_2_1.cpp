/*
     Lab_9_2_1.cpp
     Варіант 2. Обчислити
               | max^2(x + y, x + z),     1 <= z < 10
          w =  |
               | min(x^2, 5|y - z|),      z < 1, z >= 10
     використовуючи макроси та директиви умовної компіляції.
     Препроцесор на основі значення Z визначає, яка гілка компілюватиметься.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h>

#define Z 5                // директива препроцесора – значення z
                           // (змінити, щоб скомпілювати іншу гілку)

#include "macros.h"        // включення власного заголовного файлу

float W(float x, float y)  // обчислення значення w для заданих x, y
{
    float w;
#if IN_RANGE(Z)            // якщо 1 <= Z < 10 – компілюється перша гілка
    w = SQR(MAX(x + y, x + Z));
#else                      // інакше (Z < 1 або Z >= 10) – друга гілка
    w = MIN(SQR(x), 5 * ABS(y - Z));
#endif                     // завершення блоку умовної компіляції
    return w;
}

void main()
{
    puts("Lab 9.2.1. Using macros and preprocessing directive");
    float x, y,            // змінні, що вводить користувач
          w;               // результат обчислення
    char ch;               // відповідь, чи продовжувати виконання програми
    do
    {
        printf("z = %d\n", Z);
#if IN_RANGE(Z)
        puts("branch: w = max^2(x + y, x + z),  1 <= z < 10");
#else
        puts("branch: w = min(x^2, 5|y - z|),  z < 1, z >= 10");
#endif
        printf("x = "); scanf("%f", &x);   // введення значень змінних
        printf("y = "); scanf("%f", &y);

        w = W(x, y);
        PRINTR(w);                         // макрос виведення результату

        puts("Repeat? y / n "); ch = _getch();
    } while (ch == 'y');
}
