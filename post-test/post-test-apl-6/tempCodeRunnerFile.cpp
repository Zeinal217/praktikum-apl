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
                    quickSort(ptrTransaksi, 0, panjang - 1);
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
                    selectionSort(ptrTransaksi, panjang);
                    cout << "\n--- Setelah Sorting ---" << endl;
                    tampilkanPointer(panjang, ptrTransaksi);
                }
                else
                {
                    cout << "Data kosong!" << endl;
                }
                break;