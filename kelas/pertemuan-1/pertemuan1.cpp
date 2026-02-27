#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    cout << "Hello, World! " << endl;
    cout << "Belajar C + sangat seru😀" << endl;
    cout << "Masukkan nama anda: ";
    getline(cin, nama);
    cout << "Nama anda adalah " << nama;
    return 0;
}