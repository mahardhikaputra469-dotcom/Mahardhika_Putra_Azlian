#include <iostream>
using namespace std;

int cariMinimum(int a[],int n) {
    int m=a[0];
    for(int i=1;i<n;i++)
        if(a[i]<m) m=a[i];
    return m;
}

int cariMaksimum(int a[],int n) {
    int m=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>m) m=a[i];
    return m;
}

void hitungRataRata(int a[],int n) {
    int t=0;
    for(int i=0;i<n;i++) t+=a[i];
    cout << "Rata-rata = " << (double)t/n << endl;
}

int main() {
    int a[]={11,8,5,7,12,26,3,54,33,55};
    int p;

    do {
        cout << "\n1. Tampilkan array\n";
        cout << "2. Maksimum\n";
        cout << "3. Minimum\n";
        cout << "4. Rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> p;

        switch(p) {
            case 1:
                for(int i=0;i<10;i++) cout << a[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Maksimum = " << cariMaksimum(a,10) << endl;
                break;
            case 3:
                cout << "Minimum = " << cariMinimum(a,10) << endl;
                break;
            case 4:
                hitungRataRata(a,10);
                break;
            case 5:
                cout << "Program selesai.\n";
        }
    } while(p!=5);
}