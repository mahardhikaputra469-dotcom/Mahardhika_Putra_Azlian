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
Guided 1 Menjelaskan programnya adalah menyimpan 5 nilai menggunakan array, kemudian menampilkan seluruh nilai tersebut dengan perulangan for.

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
guided 2 Menjelaskan programnya adalah mengambil dan menampilkan data tertentu dari array 2 dimensi berdasarkan posisi baris dan kolom.

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
guided 3 menjelaskanprogramnya adalah mengambil data tertentu dari array 3 dimensi berdasarkan posisi blok, baris, dan kolom.

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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%202/soal%20unguided%201.png)

penjelasan unguided 1 mengolah dua matriks berukuran 3×3. Program menerima nilai dari matriks A dan B, kemudian melakukan operasi penjumlahan, pengurangan, dan perkalian. Perulangan for digunakan untuk mengakses setiap baris dan kolom matriks.

### 2. sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan.

```C++
#include <iostream>
using namespace std;

void pointer(int *a,int *b,int *c) {
    int t=*a; *a=*b; *b=*c; *c=t;
}

void reference(int &a,int &b,int &c) {
    int t=a; a=b; b=c; c=t;
}

int main() {
    int a,b,c;

    cout << "Masukkan A B C: ";
    cin >> a >> b >> c;

    cout << "Awal: " << a << " " << b << " " << c << endl;

    pointer(&a,&b,&c);
    cout << "Pointer: " << a << " " << b << " " << c << endl;

    reference(a,b,c);
    cout << "Reference: " << a << " " << b << " " << c << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%202/soal%20unguided%202.png)

penjelasan unguided 2 menukar nilai dari tiga variabel. Program menerapkan dua cara, yaitu menggunakan pointer dan reference. Pointer menggunakan alamat memori variabel, sedangkan reference langsung mengacu pada variabel aslinya. Variabel sementara digunakan untuk membantu proses pertukaran nilai.

### 3. meminta kita membuat program yang menerima input berupa sebuah angka, kemudian menghasilkan pola output berbentuk mirror.

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%202/soal%20unguided%203.png)

penjelasan unguided 3 mengolah data dalam sebuah array. Program dapat menampilkan isi array, mencari nilai paling kecil menggunakan fungsi minimum, mencari nilai paling besar menggunakan fungsi maksimum, serta menghitung nilai rata-rata. switch-case digunakan untuk memilih menu, sedangkan do-while membuat menu terus berjalan sampai pengguna memilih keluar.

## Kesimpulan
Dari ketiga soal tersebut, dapat disimpulkan bahwa latihan ini mengajarkan dasar-dasar pemrograman C++. Soal pertama melatih penggunaan input, output, dan operasi aritmatika. Soal kedua melatih penggunaan percabangan untuk mengubah angka 0–100 menjadi bentuk tulisan. Soal ketiga melatih penggunaan perulangan untuk membuat pola angka berbentuk mirror. Dengan mengerjakan ketiga soal ini, kita dapat memahami cara menggunakan beberapa konsep dasar C++ untuk menyelesaikan permasalahan sederhana.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
