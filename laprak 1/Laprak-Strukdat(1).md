# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Unguided 

### 1. membuat program yang menerima input dua buah bilangan bertipe float.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian   = " << a * b << endl;
    cout << "Pembagian   = " << a / b << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal1.png)

penjelasan unguided 1 : Program menerima dua bilangan float, kemudian menghitung penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut.

### 2. sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukan Angka (0-100): ";
    cin >> angka;

    string satuan[] {
        "nol", "satu", "dua", "tiga", "empat", "lima",
        "enam", "tujuh", "delapan", "sembilan"
    };

    if (angka < 0 || angka > 100){
        cout << "angka harus 0-100";
    }
    else if (angka < 10){
        cout << satuan[angka];
    }
    else if (angka == 10){
        cout << "sepuluh";
    }
    else if (angka == 11){
        cout << "sebelas";
    }
    else if (angka < 20){
        cout << satuan[angka - 10] <<"belas";
    }
    else if (angka < 100){
        cout << satuan[angka / 10] << "puluh";

        if (angka % 10 != 0){
            cout << " " << satuan[angka % 10];
        }
    }
    else {
        cout << "seratus";
    }
    cout << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal2.png)

penjelasan unguided 2 : Program menerima angka 0–100, kemudian mengubah angka tersebut menjadi bentuk tulisan, misalnya 79 menjadi “tujuh puluh sembilan”.

### 3. meminta kita membuat program yang menerima input berupa sebuah angka, kemudian menghasilkan pola output berbentuk mirror.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;
    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {

        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal3.png)

penjelasan unguided 3 : Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

## Kesimpulan
Dari ketiga soal tersebut, dapat disimpulkan bahwa latihan ini mengajarkan dasar-dasar pemrograman C++. Soal pertama melatih penggunaan input, output, dan operasi aritmatika. Soal kedua melatih penggunaan percabangan untuk mengubah angka 0–100 menjadi bentuk tulisan. Soal ketiga melatih penggunaan perulangan untuk membuat pola angka berbentuk mirror. Dengan mengerjakan ketiga soal ini, kita dapat memahami cara menggunakan beberapa konsep dasar C++ untuk menyelesaikan permasalahan sederhana.

## Referensi
[1] Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley. 
[2]Deitel, P., & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson. 
[3]GeeksforGeeks. (2024). C++ Programming Language. GeeksforGeeks – C++ Programming Language 
[4]cppreference.com. C++ reference. cppreference – C++ Reference
