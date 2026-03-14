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

void tabel(int lebar)
{
    cout << setfill('=') << setw(lebar) << "" << endl;
    cout << setfill(' ');
}

void tabel(int lebar, string judul)
{
    tabel(lebar);
    int padding = (lebar - 2 - judul.length()) / 2;
    cout << "|";
    cout << setfill(' ') << setw(padding) << "" << judul << setw(lebar - judul.length() - padding - 2) << "";
    cout << "|" << endl;
    tabel(lebar);
}

bool login(Data &data, int percobaan = 3)
{
    if (percobaan == 0)
    {
        cout << "Percobaan habis." << endl;
        return false;
    }

    string username, password;
    cout << "=== LOGIN ===" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == data.nama && password == data.nim)
    {
        cout << "Login Berhasil!" << endl;
        return true;
    }
    else
    {
        cout << "Login Gagal. Sisa percobaan: " << percobaan - 1 << endl;
        return login(data, percobaan - 1);
    }
}

void tampilkan()
{
    if (panjang == 0)
    {
        cout << "Belum ada data transaksi laundry." << endl;
        return;
    }
    tabel(85);
    cout << left << setw(5) << "No" << setw(20) << "Pelanggan" << setw(25) << "Layanan (Qty)" << setw(15) << "Sub-Total" << setw(15) << "Total Bayar" << endl;
    cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;

    for (int i = 0; i < panjang; i++)
    {
        cout << left << setw(5) << i + 1 << setw(20) << transaksi[i].nama_pelanggan;
        if (transaksi[i].jumlah_item > 0)
        {
            string layanan = transaksi[i].detail_transaksi[0].nama_layanan + " (" + to_string((int)transaksi[i].detail_transaksi[0].quantity) + ")";
            cout << setw(25) << layanan << "Rp" << setw(13) << transaksi[i].detail_transaksi[0].sub_total << "Rp" << setw(13) << transaksi[i].total_bayar << endl;
            for (int j = 1; j < transaksi[i].jumlah_item; j++)
            {
                string layanan_lanjut = transaksi[i].detail_transaksi[j].nama_layanan + " (" + to_string((int)transaksi[i].detail_transaksi[j].quantity) + ")";
                cout << left << setw(5) << "" << setw(20) << "" << setw(25) << layanan_lanjut << "Rp" << setw(13) << transaksi[i].detail_transaksi[j].sub_total << endl;
            }
        }
        tabel(85);
    }
}

void tambah(int &pPanjang)
{
    if (pPanjang < MAX_TRANSAKSI)
    {
        cout << "Nama pelanggan: ";
        cin.ignore();
        getline(cin, transaksi[pPanjang].nama_pelanggan);
        cout << "Jumlah Item (maksimal 5):";
        cin >> transaksi[pPanjang].jumlah_item;

        transaksi[pPanjang].total_bayar = 0;
        for (int i = 0; i < transaksi[pPanjang].jumlah_item; i++)
        {
            cout << " Item ke-" << i + 1 << " (Nama layanan): ";
            cin.ignore();
            getline(cin, transaksi[pPanjang].detail_transaksi[i].nama_layanan);
            cout << " Harga satuan: ";
            cin >> transaksi[pPanjang].detail_transaksi[i].harga;
            cout << " Qty/Berat: ";
            cin >> transaksi[pPanjang].detail_transaksi[i].quantity;

            transaksi[pPanjang].detail_transaksi[i].sub_total = transaksi[pPanjang].detail_transaksi[i].harga * transaksi[pPanjang].detail_transaksi[i].quantity;
            transaksi[pPanjang].total_bayar += transaksi[pPanjang].detail_transaksi[i].sub_total;
        }
        pPanjang++;
        cout << "Data berhasil ditambahkan!" << endl;
    }
    else
    {
        cout << "Kapasitas penuh!" << endl;
    }
}

void ubah()
{
    if (panjang == 0)
    {
        cout << "Belum ada data laundry untuk diubah." << endl;
        return;
    }
    tabel(30);
    cout << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << left << setw(5) << i + 1 << setw(25) << transaksi[i].nama_pelanggan << endl;
    }
    tabel(30);

    int index;
    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;
    if (index > 0 && index <= panjang)
    {
        int idx = index - 1;
        cout << "Masukkan nama pelanggan baru: ";
        cin.ignore();
        getline(cin, transaksi[idx].nama_pelanggan);
        cout << "Masukkan jumlah item baru (maksimal 5): ";
        cin >> transaksi[idx].jumlah_item;

        transaksi[idx].total_bayar = 0;
        for (int j = 0; j < transaksi[idx].jumlah_item; j++)
        {
            cout << "  Item ke-" << j + 1 << " (Layanan): ";
            cin.ignore();
            getline(cin, transaksi[idx].detail_transaksi[j].nama_layanan);
            cout << "  Harga Satuan: ";
            cin >> transaksi[idx].detail_transaksi[j].harga;
            cout << "  Qty/Berat: ";
            cin >> transaksi[idx].detail_transaksi[j].quantity;
            transaksi[idx].detail_transaksi[j].sub_total = transaksi[idx].detail_transaksi[j].harga * transaksi[idx].detail_transaksi[j].quantity;
            transaksi[idx].total_bayar += transaksi[idx].detail_transaksi[j].sub_total;
        }
        cout << "Data laundry berhasil diubah" << endl;
    }
    else
    {
        cout << "Nomor data laundry tidak valid" << endl;
    }
}

void hapus(int &pPanjang)
{
    if (pPanjang == 0)
    {
        cout << "Belum ada data laundry untuk dihapus." << endl;
        return;
    }
    tabel(30);
    cout << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << left << setw(5) << i + 1 << setw(25) << transaksi[i].nama_pelanggan << endl;
    }
    tabel(30);

    int index;
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= pPanjang)
    {
        for (int i = index - 1; i < pPanjang - 1; i++)
        {
            transaksi[i] = transaksi[i + 1];
        }
        pPanjang--;
        cout << "Data Laundry berhasil dihapus" << endl;
    }
    else
    {
        cout << "Nomor data laundry tidak valid" << endl;
    }
}

int main()
{
    Data data;
    data.nama = "Zeinal";
    data.nim = "075";

    if (login(data, 3))
    {
        int pilihan;
        do
        {
            tabel(30, "Menu Landry");
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
                tampilkan();
                break;
            case 2:
                tambah(panjang);
                break;
            case 3:
                ubah();
                break;
            case 4:
                hapus(panjang);
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