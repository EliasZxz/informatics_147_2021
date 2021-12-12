// Гурьянов Илья, гр. 1/147.
// Задание №6, номер 5.
// Программа выводит список, состоящий из простых чисел в диапазоне до числа введённого пользователем, по алгоритму описанному в задании.
// Внимание! В данной программе я использовал обычный массив, а не список (List), как просилось в задании, т.к. мы их ещё не проходили. 

#include <iostream>

using namespace std;

// Функция находит простые числа в массиве по алгоритму (не простые числа обнуляются) и затем выводит этот массив, в котором остались только простые числа (обнулённые элементы не выводятся)
void PrimeNumbers(int number)
{
    int Array[number - 1]; // создаём массив, в котором будут содержаться эл-ты в промежутке [2; n]
    int k = 2; // первый элемент массива
    for (int i = 0; i < (number - 1); i ++) // заполняем массив числами по порядку от 2 до n
    {
        Array[i] = k;
        k ++;
    }
    int CurrentPrimeNumber = Array[0]; // текущее простое число
    int trigger; // вспомогательная переменная, триггер
    int CurPrNum1; // вспомогательная переменная, текущее простое число
    int triggerlast = -1; // кол-во обнулённых эл-тов массива
    while (triggerlast != 0) // пока кол-во обнулённых эл-тов на пред. итерации не равно 0. Если обнулять на текущем CurrentPrimeNumber больше нечего, значит в массиве остались только простые числа
    {
        trigger = 0;
        triggerlast = 0;
        for (int i = CurrentPrimeNumber - 2; i < (number - 1); i ++) // проходим весь массив и обнуляем все элементы, делящиеся нацело на CurrentPrimeNumber, кроме самого CurrentPrimeNumber
        {
            if (Array[i] != 0 && Array[i] % CurrentPrimeNumber == 0 && Array[i] != CurrentPrimeNumber) // если эл-т ненулевой, делится на CurrentPrimeNumber и не явл. самим CurrentPrimeNumber, то обнуляем
            {
                Array[i] = 0;
                triggerlast ++; // запоминаем сколько раз обнулили. если нечего обнулять на текущем этапе, то значит не простых чисел больше нет, смысла проходить дальше по массиву и проверять следующие простые числа до конца уже нет
            }
            if (Array[i] != 0 && (Array[i] % CurrentPrimeNumber != 0) && Array[i] != CurrentPrimeNumber) // запоминаем следующее текущее простое число, с которым будем работать на след. итерации цикла while
            // если элемент ненулевой, не делится нацело на текущее CurrentPrimeNumber и не явл. самим CurrentPrimeNumber, то это след. простое число, которое нам нужно на след. этапе
            {
                if (trigger == 0) // запоминаем только первое попавшееся такое простое число
                {
                    CurPrNum1 = Array[i]; // пока запоминаем его в вспомогательную переменную, т.к. цикл for с текущим CurrentPrimeNumber ещё не закончился
                }
                trigger ++; 
            }   
        }
        CurrentPrimeNumber = CurPrNum1; // присваиваем CurrentPrimeNumber след. текущее простое число
    }
        
    for (int i = 0; i < number - 1; i ++) // вывод массива с простыми числами, обнулённые эл-ты не выводим
    {
        if (Array[i] != 0)
        {
            cout << Array[i] << "  ";
        }
    }
}

int main()
{
    int number; // натуральное число, вводимое пользователем, промежуток [2; n]
    cout << "Enter a natural number (a positive integer), >= 2: ";
    cin >> number;
    PrimeNumbers(number);

    return 0;
}