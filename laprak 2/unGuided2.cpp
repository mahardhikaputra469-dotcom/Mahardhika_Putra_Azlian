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