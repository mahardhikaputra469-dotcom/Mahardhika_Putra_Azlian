# <h1 align="center">Laporan Praktikum Modul 3 - ADT</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Dari praktikum ini dapat dipahami beberapa konsep dasar struktur data dalam C++, yaitu struct, array, ADT, fungsi, dan pointer. Struct digunakan untuk menggabungkan beberapa data, array digunakan untuk menyimpan banyak data, ADT digunakan untuk membuat struktur program yang lebih terorganisir, fungsi digunakan untuk membagi tugas dalam program, sedangkan pointer digunakan untuk mengakses dan mengubah data melalui alamat memorinya.

## Guided 

### 1. ABSTRACT DATA TYPE (ADT)
mahasiswa.h

```C++ 
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif

```
mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1+m.nilai2)/2;
}
```
main.cpp

```C++ 
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}
```
Program C++ ini digunakan untuk memasukkan data mahasiswa berupa NIM dan dua nilai, kemudian menghitung nilai rata-ratanya. Program dibagi menjadi tiga file, yaitu mahasiswa.h, mahasiswa.cpp, dan main.cpp. File mahasiswa.h berisi deklarasi struktur mahasiswa yang menyimpan NIM dan dua nilai, serta deklarasi fungsi inputMhs() dan rata2(). File mahasiswa.cpp berisi implementasi kedua fungsi tersebut. Fungsi inputMhs() digunakan untuk menerima input NIM dan nilai mahasiswa, sedangkan fungsi rata2() digunakan untuk menjumlahkan kedua nilai lalu membaginya dengan dua. Sementara itu, file main.cpp berfungsi sebagai program utama yang membuat variabel mahasiswa, memanggil fungsi input, dan menampilkan hasil rata-rata menggunakan cout. Dengan memisahkan kode ke beberapa file, program menjadi lebih rapi, terstruktur, dan mudah dikembangkan.

## Unguided 

### 1. membuat progran yang dapat menyimpan data mahasiswa kedalam sebuah array

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Jumlah mahasiswa (maks. 10): ";
    cin >> jumlah;
    cin.ignore();

    if (jumlah > 10)
        jumlah = 10;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        getline(cin, mhs[i].nama);

        cout << "NIM   : ";
        getline(cin, mhs[i].nim);

        cout << "UTS   : ";
        cin >> mhs[i].uts;

        cout << "UAS   : ";
        cin >> mhs[i].uas;

        cout << "Tugas : ";
        cin >> mhs[i].tugas;
        cin.ignore();

        mhs[i].nilaiAkhir =
            hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n===== DATA MAHASISWA =====" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%203/pp.png)

penjelasan unguided 1 ini meminta kita membuat program untuk menyimpan data maksimal 10 mahasiswa menggunakan array. Setiap mahasiswa memiliki data nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir.

### 2. membuat Abstrak data type (ADT) dalam menentukan sebuah nama pelajaran dan kode pelajaran

pelajaran.h
```C++ 
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%203/tugas%202%20unguided/unguided%202.png)


penjelasan unguided 2 ini meminta kita membuat ADT (Abstract Data Type) bernama pelajaran yang memiliki dua data, yaitu namaMapel dan kodeMapel. Selain itu, kita diminta membuat fungsi untuk membentuk data pelajaran dan prosedur untuk menampilkannya. Inti dari program ini adalah memahami cara membuat ADT dan memisahkan program menjadi beberapa file agar lebih terstruktur.

### 3. membuat sebuah program array yang berukuran 3x3 dan 2 buah pointer integer

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%203/unguided%203.png)

penjelasan unguided 3 ini meminta kita membuat dua array integer berukuran 3×3, dua pointer integer, fungsi untuk menampilkan isi array, fungsi untuk menukar elemen dari dua array pada posisi tertentu, dan fungsi untuk menukar nilai variabel yang ditunjuk oleh dua pointer.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data dalam C++ dapat digunakan untuk menyimpan dan mengolah data dengan lebih teratur. Penggunaan struct dan array membantu menyimpan data mahasiswa beserta nilai akhirnya. ADT (Abstract Data Type) membantu memisahkan deklarasi, implementasi, dan program utama agar kode lebih rapi dan mudah dipahami. Sementara itu, array 2 dimensi dan pointer digunakan untuk menyimpan data dalam bentuk tabel serta menukar nilai pada posisi tertentu. Melalui praktikum ini, saya dapat memahami cara kerja struct, array, fungsi, ADT, dan pointer serta penerapannya dalam pembuatan program C++.

## Referensi
[1] cppreference.com. (n.d.). Array declaration (C++). https://en.cppreference.com/w/cpp/language/array<br> [2]cppreference.com. (n.d.). Pointer declaration (C++). 
https://en.cppreference.com/w/cpp/language/pointer<br> [3]cppreference.com. (n.d.). Struct declaration. https://cppreference.com/c/language/struct<br> [4]Liang, Y. D. (2022). Introduction to C++ Programming and Data Structures (5th ed.). Pearson. Informasi buku dari Pearson<br>...
