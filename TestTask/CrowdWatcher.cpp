﻿#pragma once
#include <iostream>
#include <conio.h>
#include <cmath>
#include "Units.h"
#include "Tests.h"
#include <cstring>
#include <string>

using namespace std;

/*
Условия выполняемой задачи: есть 2D поле, на нем расположены юниты.
Каждый юнит имеет позицию и направление взгляда (выраженный радиус-вектором).
Все юниты видят в определенном секторе на определенную дистанцию.

Задача: определить, сколько юнитов видит каждый из них.

Пример:
Сектор на 135.5 градусов, дистанция 2 единицы
Юнит1, позиция (1,1), направление (0,1)
Юнит2, позиция (1,2), направление (1,0)
Юнит3, позиция (-5,-1), направление (0.707, 0.707)
Результат:
Юнит1: видит 1
Юнит2: видит 0
Юнит3: видит 0

Язык программирования: C++ 14, консольное приложение

Особенности выполнения задачи:
Читабельность и чистота кода с понятной архитектурой
Алгоритмическая сложность нахождения видимости вокруг юнита
Производительность, минимум тригонометрических функций
Должно работать на 10 000 юнитах
Cache-friendly код
Минимум аллокаций в куче
Мультипоточность
Чтение информации о положении юнитов из файла и запись результатов в файл
Визуальное отображение юнитов любым удобным способом
*/

/*Особенности написанного кода:
* 1) Изанчально сложность перебора всех юнитов была О(n*n),
* т.к. каждый юнит просматривал всех прочих. Сейчас также присутствует оптимизированный вариант,
* где всею юниты располлагаются на "карте" в "ячейках". Таким образом каждый юнит просматривает 
* юнитов только около себя, а не вообще всех.
* Этот аллгоритм не был реализован для алгоритма параллельной обработки.
* 
* 2) Есть два видда алгоритмов подсчета видимых юнитов: 
 - один именно их считает.
 - другой запоминает самих юнитов - он нужен для рисования.

 3) У классов точки, вектора реализованы только те методы, 
 которыми я планировал пользоваться, а не все возможные.
 (Правда, некоторыми я так и не пользовался.)

 4)Для тестов скорости написан метод, создающий равномерное расположение юнитов.
 Для рисования же они создаются со случайным местоположением.

 5)Многие нюансы ООП, такие как инкапсуляция, к примеру, не были соблюдены дожным образом.
 Вообще, довольно халатно написаны. Это было сделано осознано, т.к. была цель написать 
 наиболее производительный код с точки зрения алгоритмов.
*/

int main()
{

    setlocale(LC_ALL, "");

    //Создать тестовый объект
    Tests test;
    //Тесты скорости
    test.StartAllSpeedTests();
    //Тесты сохранения и загрузки
    test.StartAllSaveAndLoadTests();
    
    return _getch();
}
