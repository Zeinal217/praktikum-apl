#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

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

void tampilkan(int *pPanjang, Transaksi *arrTransaksi)
{
    if (*pPanjang == 0)
    {
        cout << "Belum ada data transaksi laundry." << endl;
        return;
    }

    tabel(85);
    cout << left << setw(5) << "No" << setw(20) << "Pelanggan" << setw(25) << "Layanan (Qty)" << setw(15) << "Sub-Total" << setw(15) << "Total Bayar" << endl;
    cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;

    for (int i = 0; i < *pPanjang; i++)
    {
        Transaksi *current = (arrTransaksi + i);

        cout << left << setw(5) << i + 1 << setw(20) << current->nama_pelanggan;
        if (current->jumlah_item > 0)
        {
            string layanan = current->detail_transaksi[0].nama_layanan + " (" + to_string((int)current->detail_transaksi[0].quantity) + ")";
            cout << setw(25) << layanan << "Rp" << setw(13) << current->detail_transaksi[0].sub_total << "Rp" << setw(13) << current->total_bayar << endl;

            for (int j = 1; j < current->jumlah_item; j++)
            {
                string layanan_lanjut = current->detail_transaksi[j].nama_layanan + " (" + to_string((int)current->detail_transaksi[j].quantity) + ")";
                cout << left << setw(5) << "" << setw(20) << "" << setw(25) << layanan_lanjut << "Rp" << setw(13) << current->detail_transaksi[j].sub_total << endl;
            }
        }
        tabel(85);
    }
}

void tampilkanPointer(int panjang, Transaksi *arr[])
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
        Transaksi *current = arr[i];

        cout << left << setw(5) << i + 1 << setw(20) << current->nama_pelanggan;
        if (current->jumlah_item > 0)
        {
            string layanan = current->detail_transaksi[0].nama_layanan + " (" + to_string((int)current->detail_transaksi[0].quantity) + ")";
            cout << setw(25) << layanan << "Rp" << setw(13) << current->detail_transaksi[0].sub_total << "Rp" << setw(13) << current->total_bayar << endl;

            for (int j = 1; j < current->jumlah_item; j++)
            {
                string layanan_lanjut = current->detail_transaksi[j].nama_layanan + " (" + to_string((int)current->detail_transaksi[j].quantity) + ")";
                cout << left << setw(5) << "" << setw(20) << "" << setw(25) << layanan_lanjut << "Rp" << setw(13) << current->detail_transaksi[j].sub_total << endl;
            }
        }
        tabel(85);
    }
}

void tambah(int *pPanjang, Transaksi *arrTransaksi)
{
    if (*pPanjang < MAX_TRANSAKSI)
    {
        Transaksi *baru = &arrTransaksi[*pPanjang];

        cout << "Nama pelanggan: ";
        cin.ignore();
        getline(cin, baru->nama_pelanggan);
        cout << "Jumlah Item (maksimal 5):";
        cin >> baru->jumlah_item;

        baru->total_bayar = 0;
        for (int i = 0; i < baru->jumlah_item; i++)
        {
            cout << " Item ke-" << i + 1 << " (Nama layanan): ";
            cin.ignore();
            getline(cin, baru->detail_transaksi[i].nama_layanan);
            cout << " Harga satuan: ";
            cin >> baru->detail_transaksi[i].harga;
            cout << " Qty/Berat: ";
            cin >> baru->detail_transaksi[i].quantity;

            baru->detail_transaksi[i].sub_total = baru->detail_transaksi[i].harga * baru->detail_transaksi[i].quantity;
            baru->total_bayar += baru->detail_transaksi[i].sub_total;
        }
        (*pPanjang)++;
        cout << "Data berhasil ditambahkan!" << endl;
    }
    else
    {
        cout << "Kapasitas penuh!" << endl;
    }
}

void ubah(int *pPanjang, Transaksi *arrTransaksi)
{
    if (*pPanjang == 0)
    {
        cout << "Belum ada data laundry untuk diubah." << endl;
        return;
    }

    tabel(30);
    cout << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
    for (int i = 0; i < *pPanjang; i++)
    {
        cout << left << setw(5) << i + 1 << setw(25) << (arrTransaksi + i)->nama_pelanggan << endl;
    }
    tabel(30);

    int index;
    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;

    if (index > 0 && index <= *pPanjang)
    {
        int idx = index - 1;

        Transaksi *ubahData = &arrTransaksi[idx];

        cout << "Masukkan nama pelanggan baru: ";
        cin.ignore();
        getline(cin, ubahData->nama_pelanggan);
        cout << "Masukkan jumlah item baru (maksimal 5): ";
        cin >> ubahData->jumlah_item;

        ubahData->total_bayar = 0;
        for (int j = 0; j < ubahData->jumlah_item; j++)
        {
            cout << "  Item ke-" << j + 1 << " (Layanan): ";
            cin.ignore();
            getline(cin, ubahData->detail_transaksi[j].nama_layanan);
            cout << "  Harga Satuan: ";
            cin >> ubahData->detail_transaksi[j].harga;
            cout << "  Qty/Berat: ";
            cin >> ubahData->detail_transaksi[j].quantity;

            ubahData->detail_transaksi[j].sub_total = ubahData->detail_transaksi[j].harga * ubahData->detail_transaksi[j].quantity;
            ubahData->total_bayar += ubahData->detail_transaksi[j].sub_total;
        }
        cout << "Data laundry berhasil diubah" << endl;
    }
    else
    {
        cout << "Nomor data laundry tidak valid" << endl;
    }
}

void hapus(int &pPanjang, Transaksi *arrTransaksi)
{
    if (pPanjang == 0)
    {
        cout << "Belum ada data laundry untuk dihapus." << endl;
        return;
    }

    tabel(30);
    cout << left << setw(5) << "No" << setw(25) << "Nama Pelanggan" << endl;
    for (int i = 0; i < pPanjang; i++)
    {
        cout << left << setw(5) << i + 1 << setw(25) << (arrTransaksi + i)->nama_pelanggan << endl;
    }
    tabel(30);

    int index;
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= pPanjang)
    {
        for (int i = index - 1; i < pPanjang - 1; i++)
        {
            *(arrTransaksi + i) = *(arrTransaksi + i + 1);
        }
        pPanjang--;
        cout << "Data Laundry berhasil dihapus" << endl;
    }
    else
    {
        cout << "Nomor data laundry tidak valid" << endl;
    }
}

void merge(Transaksi *arr[], int l, int m, int r)
{
    int ukuran = r - l + 1;

    Transaksi **temp = new Transaksi *[ukuran];

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (arr[i]->nama_pelanggan <= arr[j]->nama_pelanggan)
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++)
    {
        arr[l + x] = temp[x];
    }

    delete[] temp;
}

void mergeSort(Transaksi *arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void quickSort(Transaksi *arr[], int low, int high, int panjang, int &iterasi)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    double pivot = arr[mid]->total_bayar;

    int i = low, j = high;

    while (i <= j)
    {
        while (arr[i]->total_bayar > pivot)
        {
            i++;
        }
        while (arr[j]->total_bayar < pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quickSort(arr, low, j, panjang, iterasi);
    if (i < high)
        quickSort(arr, i, high, panjang, iterasi);
}

void selectionSort(Transaksi *arr[], int panjang, int &iterasi)
{
    for (int i = 0; i < panjang - 1; i++)
    {
        int max_idx = i;

        for (int j = i + 1; j < panjang; j++)
        {
            if (arr[j]->jumlah_item > arr[max_idx]->jumlah_item)
            {
                max_idx = j;
            }
        }

        if (max_idx != i)
        {
            swap(arr[i], arr[max_idx]);
        }
    }
}

int main()
{
    Data data;
    data.nama = "Zeinal";
    data.nim = "075";

    int panjang = 0;
    Transaksi transaksi[MAX_TRANSAKSI];

    if (login(data, 3))
    {
        int pilihan;
        do
        {
            tabel(30, "Menu Laundry");
            cout << "1. Tampilkan Data Laundry" << endl;
            cout << "2. Tambah Data Laundry" << endl;
            cout << "3. Ubah Data Laundry" << endl;
            cout << "4. Hapus Data Laundry" << endl;
            cout << "5. Sorting Nama Pelanggan Secara Ascending Menggunakan Merge Sort" << endl;
            cout << "6. Sorting Total Bayar Secara Descending Menggunakan Quick Sort" << endl;
            cout << "7. Sorting Jumlah Item Secara Descending Menggunakan Selection Sort" << endl;
            cout << "8. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                tampilkan(&panjang, transaksi);
                break;
            case 2:
                tambah(&panjang, transaksi);
                break;
            case 3:
                ubah(&panjang, transaksi);
                break;
            case 4:
                hapus(panjang, transaksi);
                break;
            case 5:
                if (panjang > 0)
                {
                    Transaksi *ptrTransaksi[MAX_TRANSAKSI];
                    for (int i = 0; i < panjang; i++)
                        ptrTransaksi[i] = &transaksi[i];

                    cout << "\n--- Sebelum Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);

                    mergeSort(ptrTransaksi, 0, panjang - 1);

                    cout << "\n--- Setelah Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);
                }
                else
                {
                    cout << "Data kosong!" << endl;
                }
                break;

            case 6:
                if (panjang > 0)
                {
                    Transaksi *ptrTransaksi[MAX_TRANSAKSI];
                    for (int i = 0; i < panjang; i++)
                        ptrTransaksi[i] = &transaksi[i];

                    cout << "\n--- Sebelum Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);

                    int iterasi_qs = 0;
                    quickSort(ptrTransaksi, 0, panjang - 1, panjang, iterasi_qs);

                    cout << "\n--- Setelah Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);
                }
                else
                {
                    cout << "Data kosong!" << endl;
                }
                break;

            case 7:
                if (panjang > 0)
                {
                    Transaksi *ptrTransaksi[MAX_TRANSAKSI];
                    for (int i = 0; i < panjang; i++)
                        ptrTransaksi[i] = &transaksi[i];

                    cout << "\n--- Sebelum Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);

                    int iterasi_ss = 0;
                    selectionSort(ptrTransaksi, panjang, iterasi_ss);

                    cout << "\n--- Setelah Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);
                }
                else
                {
                    cout << "Data kosong!" << endl;
                }
                break;
            case 8:
                cout << "Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        } while (pilihan != 8);
    }
    return 0;
}