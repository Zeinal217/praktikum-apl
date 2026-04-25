#ifndef EXTERNAL_LIBRARY_H
#define EXTERNAL_LIBRARY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void bersihkanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void tabel(int lebar) {
    cout << setfill('=') << setw(lebar) << "" << endl;
    cout << setfill(' ');
}

void tabel(int lebar, string judul) {
    tabel(lebar);
    int padding = (lebar - 2 - judul.length()) / 2;
    cout << "|";
    cout << setfill(' ') << setw(padding) << "" << judul << setw(lebar - judul.length() - padding - 2) << "";
    cout << "|" << endl;
    tabel(lebar);
}

#endif