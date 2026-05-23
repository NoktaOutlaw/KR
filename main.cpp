#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// --- ЗАДАЧА 1: Вычисление суммы ряда ---
void task1() {
    double x, epsilon;
    cout << "\nЗАДАЧА 1: Вычисление суммы ряда\n";
    cout << "Введите x (x != 0): "; cin >> x;
    cout << "Введите точность epsilon (e > 0): "; cin >> epsilon;

    double sum = 0.0;
    double current_term = 0.0; //хранит текущее значение слагаемого
    int k = 0;
    int count = 0;

    // Вычисляем первое слагаемое (k=0) отдельно
    current_term = (pow(x, 2)) / (1 * 2); // (-1)^0 = 1
    sum += current_term;
    count++;

    cout << "\nИсходные данные: x = " << x << ", epsilon = " << epsilon << "\n";
    cout << "k=0: слагаемое = " << current_term << ", сумма = " << sum << "\n";

    // Цикл для последующих слагаемых
    while (true) {
        k++;
        // Рекуррентная формула: T_k = T_{k-1} * (-x^2) / ((k+1)*(k+2))
        current_term *= (-x * x) / ((k + 1) * (k + 2));
        sum += current_term;
        count++;

        cout << "k=" << k << ": слагаемое = " << current_term
             << ", сумма = " << sum << "\n";

        // Проверка условия выхода (по модулю меньше точности)
        if (fabs(current_term) < epsilon) {
            break;
        }
    }

    cout << "\nРезультат: сумма = " << sum << ", количество учтённых слагаемых = " << count << "\n\n";
}

// --- ЗАДАЧА 2: Сортировка массива --
void task2() {
    const int SIZE = 15;
    int arr[SIZE];
    cout << "\nЗАДАЧА 2: Сортировка массива\n";

    // Ввод массива
    cout << "Введите " << SIZE << " целых чисел:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "\nИсходный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n";

    // Функция для вычисления суммы цифр числа
    auto sumOfDigits = [](int n) -> int {
        n = abs(n);
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    };

    // Удаление элементов и сортировка
    int newSize = 0;
    for (int i = 0; i < SIZE; i++) {
        if (sumOfDigits(arr[i]) >= i + 1) { // +1, так как индексы с 0
            arr[newSize++] = arr[i];
        }
    }

    // Сортировка выбором по убыванию
    for (int i = 0; i < newSize - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < newSize; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }

    cout << "Отсортированный массив (по убыванию):\n";
    for (int i = 0; i < newSize; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n\n";
}

// --- ГЛАВНОЕ МЕНЮ ---
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        cout << "\nМЕНЮ:\n";
        cout << "1. Решить задачу 1 (вычисление суммы ряда)\n";
        cout << "2. Решить задачу 2 (сортировка массива)\n";
        cout << "0. Завершить работу\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Программа завершена.\n";
                return 0;
            default:
                cout << "Неверный ввод. Попробуйте снова.\n";
        }
    }

    return 0;
}
