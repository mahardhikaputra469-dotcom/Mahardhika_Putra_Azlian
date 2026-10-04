#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];

    cout << "Masukkan Matriks A:\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) cin >> A[i][j];

    cout << "Masukkan Matriks B:\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) cin >> B[i][j];

    cout << "\nPenjumlahan:\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << A[i][j]+B[i][j] << "\t";
        cout << endl;
    }

    cout << "\nPengurangan:\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << A[i][j]-B[i][j] << "\t";
        cout << endl;
    }

    cout << "\nPerkalian:\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int hasil=0;
            for(int k=0;k<3;k++)
                hasil += A[i][k]*B[k][j];
            cout << hasil << "\t";
        }
        cout << endl;
    }
}