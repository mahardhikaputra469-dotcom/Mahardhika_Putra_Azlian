# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Dari praktikum ini dapat dipahami beberapa konsep dasar struktur data dalam C++, yaitu struct, array, ADT, fungsi, dan pointer. Struct digunakan untuk menggabungkan beberapa data, array digunakan untuk menyimpan banyak data, ADT digunakan untuk membuat struktur program yang lebih terorganisir, fungsi digunakan untuk membagi tugas dalam program, sedangkan pointer digunakan untuk mengakses dan mengubah data melalui alamat memorinya.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. soal1

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
Guided 1 Menjelaskan program menerima dua bilangan float, kemudian menghitung penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut.

### 2. soal2

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
guided 2 Menjelaskan program menerima angka 0–100, kemudian mengubah angka tersebut menjadi bentuk tulisan, misalnya 79 menjadi “tujuh puluh sembilan”.

### 3. soal3

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
guided 3 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

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

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

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

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

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

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
Dari ketiga soal tersebut, dapat disimpulkan bahwa latihan ini mengajarkan dasar-dasar pemrograman C++. Soal pertama melatih penggunaan input, output, dan operasi aritmatika. Soal kedua melatih penggunaan percabangan untuk mengubah angka 0–100 menjadi bentuk tulisan. Soal ketiga melatih penggunaan perulangan untuk membuat pola angka berbentuk mirror. Dengan mengerjakan ketiga soal ini, kita dapat memahami cara menggunakan beberapa konsep dasar C++ untuk menyelesaikan permasalahan sederhana.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
