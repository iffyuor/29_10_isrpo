#include <iostream>
#include <vector>

using namespace std;


bool checkRow(const vector<int>& row) {
    int sum = 0;
    for (size_t i = 0; i < row.size(); i += 2) {
        sum += row[i];
    }
    return sum > 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N1, M1, N2, M2;
    cout << "Введите количество строк первого массива (не более 10): ";
    cin >> N1;
    cout << "Введите количество столбцов первого массива (не более 10): ";
    cin >> M1;
    cout << "Введите количество строк второго массива (не более 10): ";
    cin >> N2;
    cout << "Введите количество столбцов второго массива (не более 10): ";
    cin >> M2;

    if (N1 > 10 || M1 > 10 || N2 > 10 || M2 > 10) {
        cout << "Размер массива превышает 10. Программа завершена." << endl;
        return 1;
    }

    vector< vector<int> > array1(N1, vector<int>(M1));
    vector< vector<int> > array2(N2, vector<int>(M2));

    // Ввод массива 1
    cout << "Введите элементы первого массива:" << endl;
    for (int i = 0; i < N1; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < M1; ++j) {
            cin >> array1[i][j];
        }
    }

    // Ввод массива 2
    cout << "Введите элементы второго массива:" << endl;
    for (int i = 0; i < N2; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < M2; ++j) {
            cin >> array2[i][j];
        }
    }

    int count1 = 0, count2 = 0;

    // Подсчет подходящих строк 
    for (const auto& row : array1) {
        if (checkRow(row))
            ++count1;
    }

    // Подсчет подходящих строк
    for (const auto& row : array2) {
        if (checkRow(row))
            ++count2;
    }


    if (count1 == 0 && count2 == 0) {
        cout << "Нет ни для одного массива строк, удовлетворяющих условию." << endl;
    }
    else {
        if (count1 > 0)
            cout << "Количество строк первого массива, где сумма элементов на нечетных позициях положительна: " << count1 << endl;
        if (count2 > 0)
            cout << "Количество строк второго массива, где сумма элементов на нечетных позициях положительна: " << count2 << endl;
    }

    return 0;
}