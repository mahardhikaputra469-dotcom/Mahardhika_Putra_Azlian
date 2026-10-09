#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilkanArray(array1);

    cout << "\nArray 2 sebelum ditukar:" << endl;
    tampilkanArray(array2);
    tukarArray(array1, array2, 1, 1);

    cout << "\nArray 1 setelah pertukaran:" << endl;
    tampilkanArray(array1);

    cout << "\nArray 2 setelah pertukaran:" << endl;
    tampilkanArray(array2);

    int a = 100;
    int b = 200;
    int *p1 = &a;
    int *p2 = &b;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah tukar pointer:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}