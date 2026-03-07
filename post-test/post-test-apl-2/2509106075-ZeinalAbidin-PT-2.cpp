#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Data
{
    string nama;
    string nim;
};

struct DetailTransaksi
{
    string nama_layanan;
    double harga;
    double quantity;
    double sub_total;
};

struct Transaksi
{
    string nama_pelanggan;
    int jumlah_item;
    DetailTransaksi detail_transaksi[5];
    double total_bayar;
};

#define MAX_TRANSAKSI 100
int panjang = 0;
Transaksi transaksi[MAX_TRANSAKSI];

int main()
{
    Data data;
    data.nama = "Zeinal";
    data.nim = "075";
    string username, password;
    int percobaan = 3;
    bool login_berhasil = false;

    while (percobaan > 0)
    {
        cout << "=== LOGIN ===" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == data.nama && password == data.nim)
        {
            cout << "Login Berhasil!" << endl;
            login_berhasil = true;
            break;
        }
        else
        {
            percobaan--;
            cout << "Login Gagal. ";
            if (percobaan > 0)
            {
                cout << "Sisa percobaan: " << percobaan << endl;
            }
            else
            {
                cout << "Percobaan habis." << endl;
            }
        }
    }

    if (login_berhasil)
    {
        int pilihan, index;
        do
        {
            cout << "==============================" << endl;
            cout << "|        Menu Landry         |" << endl;
            cout << "==============================" << endl;
            cout << "1. Tampilkan Data Landry" << endl;
            cout << "2. Tambah Data Landry" << endl;
            cout << "3. Ubah Data Landry" << endl;
            cout << "4. Hapus Data Landry" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                if (panjang == 0)
                {
                    cout << "Belum ada data transaksi laundry." << endl;
                }
                else
                {
                    cout << setfill('=') << setw(85) << "" << endl;
                    cout << setfill(' ');
                    cout << left << setw(5) << "No" << setw(20) << "Pelanggan" << setw(25) << "Layanan (Qty)" << setw(15) << "Sub-Total" << setw(15) << "Total Bayar" << endl;
                    cout << setfill('-') << setw(85) << "" << endl;
                    cout << setfill(' ');
                    for (int i = 0; i < panjang; i++)
                    {
                        cout << left << setw(5) << i + 1 << setw(20) << transaksi[i].nama_pelanggan;
                        if (transaksi[i].jumlah_item > 0)
                        {
                            string layanan = transaksi[i].detail_transaksi[0].nama_layanan + " (" + to_string((int)transaksi[i].detail_transaksi[0].quantity) + ")";
                            cout << setw(25) << layanan << "Rp" << setw(13) <<  transaksi[i].detail_transaksi[0].sub_total << "Rp" << setw(13) << transaksi[i].total_bayar << endl;
                            for (int j = 1; j < transaksi[i].jumlah_item; j++)
                            {
                                string layanan_lanjut = transaksi[i].detail_transaksi[j].nama_layanan + " (" + to_string((int)transaksi[i].detail_transaksi[j].quantity) + ")";
                                cout << left << setw(5) << "" << setw(20) << "" << setw(25) << layanan_lanjut << "Rp" << setw(13) << transaksi[i].detail_transaksi[j].sub_total << endl;
                            }
                        }
                        cout << setfill('=') << setw(85) << "" << endl;
                        cout << setfill(' ');
                    }
                }
                break;
            case 2:
                if (panjang < MAX_TRANSAKSI)
                {
                    cout << "Nama pelanggan: ";
                    cin.ignore();
                    getline(cin, transaksi[panjang].nama_pelanggan);
                    cout << "Jumlah Item (maksimal 5):";
                    cin >> transaksi[panjang].jumlah_item;
                    transaksi[panjang].total_bayar = 0;
                    for (int i = 0; i < transaksi[panjang].jumlah_item; i++)
                    {
                        cout << " Item ke-" << i + 1 << " (Nama layanan): ";
                        cin.ignore();
                        getline(cin, transaksi[panjang].detail_transaksi[i].nama_layanan);
                        cout << " Harga satuan: ";
                        cin >> transaksi[panjang].detail_transaksi[i].harga;
                        cout << " Qty/Berat: ";
                        cin >> transaksi[panjang].detail_transaksi[i].quantity;

                        transaksi[panjang].detail_transaksi[i].sub_total = transaksi[panjang].detail_transaksi[i].harga * transaksi[panjang].detail_transaksi[i].quantity;
                        transaksi[panjang].total_bayar += transaksi[panjang].detail_transaksi[i].sub_total;
                    }
                    panjang++;
                    cout << "Data berhasil ditambahkan!" << endl;
                }
                else
                {
                    cout << "Kapasitas penuh!" << endl;
                }
                break;
            case 3:
                if (panjang == 0)
                {
                    cout << "Belum ada data laundry untuk diubah." << endl;
                }
                else
                {
                    cout << setfill('=') << setw(30) << "" << endl;
                    cout << setfill(' ') << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
                    cout << setfill('-') << setw(30) << "" << endl;
                    cout << setfill(' ');
                    for (int i = 0; i < panjang; i++)
                    {
                        cout << left << setw(5) << i + 1 << setw(25) << transaksi[i].nama_pelanggan << endl;
                    }
                    cout << setfill('=') << setw(30) << "" << endl;
                    cout << setfill(' ');
                    cout << "Masukkan nomor data: ";
                    cin >> index;
                    if (index > 0 && index <= panjang)
                    {
                        cout << "Masukkan nama pelanggan baru: ";
                        cin.ignore();
                        getline(cin, transaksi[index - 1].nama_pelanggan);
                        cout << "Masukkan jumlah item baru (maksimal 5): ";
                        cin >> transaksi[index - 1].jumlah_item;
                        transaksi[index - 1].total_bayar = 0;
                        for (int j = 0; j < transaksi[index - 1].jumlah_item; j++)
                        {
                            cout << "  Item ke-" << j + 1 << " (Layanan): ";
                            cin.ignore();
                            getline(cin, transaksi[index - 1].detail_transaksi[j].nama_layanan);
                            cout << "  Harga Satuan: ";
                            cin >> transaksi[index - 1].detail_transaksi[j].harga;
                            cout << "  Qty/Berat: ";
                            cin >> transaksi[index - 1].detail_transaksi[j].quantity;

                            transaksi[index - 1].detail_transaksi[j].sub_total = transaksi[index - 1].detail_transaksi[j].harga * transaksi[index - 1].detail_transaksi[j].quantity;
                            transaksi[index - 1].total_bayar += transaksi[index - 1].detail_transaksi[j].sub_total;
                        }
                        cout << "Data laundry berhasil diubah" << endl;
                    }
                    else
                    {
                        cout << "Nomor data laundry tidak valid" << endl;
                    }
                }
                break;
            case 4:
                if (panjang == 0)
                {
                    cout << "Belum ada data laundry untuk dihapus." << endl;
                }
                else
                {
                    cout << setfill('=') << setw(30) << "" << endl;
                    cout << setfill(' ') << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
                    cout << setfill('-') << setw(30) << "" << endl;
                    cout << setfill(' ');
                    for (int i = 0; i < panjang; i++)
                    {
                        cout << left << setw(5) << i + 1 << setw(25) << transaksi[i].nama_pelanggan << endl;
                    }
                    cout << setfill('=') << setw(30) << "" << endl;
                    cout << setfill(' ');
                    cout << "Masukkan nomor data: ";
                    cin >> index;
                    if (index > 0 && index <= panjang)
                    {
                        for (int i = index - 1; i < panjang - 1; i++)
                        {
                            transaksi[i] = transaksi[i + 1];
                        }
                        panjang--;
                        cout << "Data Laundry berhasil dihapus" << endl;
                    }
                    else
                    {
                        cout << "Nomor data laundry tidak valid" << endl;
                    }
                }
                break;
            case 5:
                cout << "Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        } while (pilihan != 5);
    }

    return 0;
}