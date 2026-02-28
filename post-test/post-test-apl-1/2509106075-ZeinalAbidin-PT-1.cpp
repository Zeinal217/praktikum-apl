#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama = "Zeinal";
    string nim = "075";
    string username, password;
    int percobaan = 3;
    bool loginBerhasil = false;

    while (percobaan > 0) {
        cout << "=== LOGIN ===" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == nama && password == nim) {
            cout << "Login Berhasil!" << endl;
            loginBerhasil = true;
            break;
        } else {
            percobaan--;
            cout << "Login Gagal. ";
            if (percobaan > 0) {
                cout << "Sisa percobaan: " << percobaan << endl;
            } else {
                cout << "Percobaan habis." << endl;
            }
        }
    }

    if (loginBerhasil) {
        char pilihan;
        double nilai;

        do {
            cout << "=== MENU KONVERSI ===" << endl;
            cout << "1. Meter ke Kilometer & Centimeter" << endl;
            cout << "2. Kilometer ke Meter & Centimeter" << endl;
            cout << "3. Centimeter ke Meter & Kilometer" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih menu 1-4: ";
            cin >> pilihan;

            if (pilihan == '4') {
                break;
            }

            if (pilihan < '1' || pilihan > '3') {
                cout << "Input tidak valid." << endl;
                continue;
            }

            while (true) {
                cout << "Masukkan nilai panjang: ";
                cin >> nilai;

                if (nilai < 0) {
                    cout << "Nilai tidak boleh negatif!" << endl;
                } else {
                    break;
                }
            }

            if (pilihan == '1') {
                cout << nilai << " M = " << nilai / 1000 << " KM dan " << nilai * 100 << " CM" << endl;
            } else if (pilihan == '2') {
                cout << nilai << " KM = " << nilai * 1000 << " M dan " << nilai * 100000 << " CM" << endl;
            } else if (pilihan == '3') {
                cout << nilai << " CM = " << nilai / 100 << " M dan " << nilai / 100000 << " KM" << endl;
            }
            cout << endl;

        } while (pilihan != '4');
    }

    return 0;
}