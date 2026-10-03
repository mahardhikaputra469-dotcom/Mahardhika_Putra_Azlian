# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

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

### 1. soal1 ARRAY 1

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;
    
    for (int i = 0; i < 5; i++) {
        cout << nilai[i] << endl;
    }

    return 0;
}
```
Guided 1 Menjelaskan program menerima dua bilangan float, kemudian menghitung penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut.

### 2. soal2 ARRAY 2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][5] = {
        {80, 85, 90},
        {75, 80, 85},
        {90, 95, 100},
    };

    cout << nilai[0][0] << endl;
    cout << nilai[1][1] << endl;
    cout << nilai[2][2] << " ";
    return 0;
}
```
guided 2 Menjelaskan program menerima angka 0–100, kemudian mengubah angka tersebut menjadi bentuk tulisan, misalnya 79 menjadi “tujuh puluh sembilan”.

### 3. soal3 ARRAY 3

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9} 
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18 }
        }
    };

    cout << data[0][1][1]  << " ";
    return 0;
}
```
guided 3 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

### 4. soal4 ARRAY 4

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            },
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0]  << endl;
    cout << data[1][1][1][1]  << endl;
    
    return 0;
}
```
guided 4 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

### 5. soal1 Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl;
    cout << &a << endl;

    cout << j << endl;
    cout << &j << endl;

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

    return 0;
}
```
guided 5 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

### 6. soal2 Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```
guided 6 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

### 7. soal3 Pointer 3

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    for (i = 0; i < MAX; i++) {
        cout << "masukan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;
    cout << "\n nilai tahunan : \n";

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];
        cout << "\n";
    }

    return 0;
}
```
guided 7 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

### 8. soal4 Pointer 4

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9} 
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18 }
        }
    };

    cout << data[0][1][1]  << " ";
    return 0;
}
```
guided 8 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

## Unguided 

### 1. membuat program yang menerima input dua buah bilangan bertipe float.

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;
    
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
