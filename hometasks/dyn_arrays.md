#### Задача 1.
Написать функцию, заполняющую массив размера `NxM` числами от 1 до `NM` по змейке. Нечетные строки слева направо, чётные -- в обратном порядке.

```
 1  2  3  4  5
10  9  8  7  6
11 12 13 14 15
```

#### Задача 2.
Написать функцию, заполняющую массив размера `NxM` числами от 1 до `NM` по спирали.

```
 1  2  3  4 5
14 15 16 17 6
13 20 19 18 7
12 11 10  9 8
```

#### Задача 3.
Написать функцию, заполняющую массив размера `NxM` числами от 1 до `NM` зигзагом.

```
 1  2  6  7 14
 3  5  8 13 15
 4  9 12 16 19
10 11 17 18 20
```

#### Задача 4.
Дополнить предыдущие функции дополнительнным аргументом `bool dir`,  который задает направление заполнения массива в том смысле, что второй элемент ставится либо в той же строке справа, либо в столбце снизу.

```
 1  2  3  4  5    1 4 9 10 15
10  9  8  7  6    2 5 8 11 14
11 12 13 14 15    3 6 7 12 13
```

```
 1  2  3  4 5     1 14 13 12 11
14 15 16 17 6     2 15 20 19 10
13 20 19 18 7     3 16 17 18  9
12 11 10  9 8     4  5  6  7  8
```

```
 1  2  6  7 14    1  3  4 10 11
 3  5  8 13 15    2  5  9 12 17
 4  9 12 16 19    6  8 13 16 18
10 11 17 18 20    7 14 15 19 20
```

#### Задача 5.
Написать функцию 
```
void shiftArray(int* A, int n, int k)
```
которая осуществляет циклический сдвиг элементов массива на k влево. 
Например, если был массив
```
A[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```
То после вызова функции `shiftArray(A, 10, 3);` 

Должен получиться массив `{3, 4, 5, 6, 7, 8, 9, 0, 1,2};`
