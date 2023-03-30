#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// поиск суммы элементов массива
int sum_array(int i, int *a, int n) {
    // i - итератор функции
    // a - массив для обработки
    // n - количество элементов массива (длина)
    if (i == n - 1) {  // базовый выход из функции
        return a[i];  // вернуть этот элемент
    } else {  // случай повторения действий
        return a[i] + sum_array(i + 1, a, n);
    }
}

// посчитать количество вхождений символа в строке
int countSymbol(char c, string s, int i) {
    if (i == s.length()) {  // как только счетчик (итератор) дошел до конца строки
        return 0;
    } else {  // если мы не дошли до конца строки (включаем рекурсию)
        if (c == s[i]) {  // если нашли совпадение по символам
            return countSymbol(c, s, i+1) + 1;  // увеличить количество найденных на 1
        } else {
            return countSymbol(c, s, i+1);  // иначе, перейти к обработке следующего символа
        }
    }
}

int fact(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int countSumOfDigits(int n) {
    // базовый случай, если число меньше 10 (если число состоит из одной цифры)
    if (n < 10) {
        return n;
    }
    return n % 10 + countSumOfDigits(n / 10); //
}

int countDigits(int n) {
    // базовый случай, если число меньше 10 (если число состоит из одной цифры)
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10); //
}

int printLeadingDigit(int n) {
    if (n < 10) {
        return n;
    }
    return printLeadingDigit(n / 10);
}


int countSolutions(int n, int x = 1, int y = 1) {
    if (pow(x, 2) + pow(y, 2) >= n) { // базовый (если сумма квадратов больше числа)
        return 0;
    } else {  // если она меньше, то
        int count = 1;  // мы считаем, что количество решений уже равно 1
        count += countSolutions(n, x+1, y);
        if (x != y) {
            count += countSolutions(n, x, y+1);
        }
        return count;

    }
}

bool isPrime(int n, int div = 2) {
    // базовый случай №1: если число меньше 2, оно не является простым
    if (n < 2) {
        return false;
    }
    // базовый случай №2: если число равно 2, то оно простое
    if (n == 2) {
        return true;
    }
    // базовый случай № 3: если число делится нацело, на какое-то число до его квадратного корня,  оно не является простым
    if (div * div > n) {
        return true;
    }
    if (n % div == 0) {
        return false;
    }
    // рекурсивный случай:  проверяем, можно ли разделить число нацело на следующее число делитель
    return isPrime(n, div + 1);
}

int main() {
    int arr[] { 3, 2, 7, 2, 9, 1, 6 };
    cout << sum_array(0, arr, 7) << endl;

    string phrase = "green green green green green green green";
    char symbol = 'e';
    cout << countSymbol(symbol, phrase, 0) << endl;

    cout << fact(7) << endl;

    cout << countSumOfDigits(37592) << endl;
    cout << countDigits(37592) << endl;

    cout << printLeadingDigit(4623789) << endl;
    cout << countSolutions(8) << endl;

    int n = 17;
    bool is_prime = isPrime(n);
    cout << n << " is " << (is_prime ? "prime" : "not prime") << endl;
    return 0;
}
