// soal nomor 2 //

#include <stdio.h>

// fungsi twoStacks dengan 5 parameter  -> akan mencari kombinasi angka terbesar dari arr1 dan arr2 yang tidak melebihi penjumlahanMaks
int twoStacks(int penjumlahanMaks, int arr1[], int size_arr1, int arr2[], int size_arr2)
// penjumlahanMaks   -> untuk batas maksimum penjumlahan angka
// arr1              -> adalah array pertama yang berisi angka
// size_arr1         -> ukuran untuk arr1
// arr2              -> adalah array kedua yang berisi angka
// size_arr2         -> ukuran untuk arr2
{
    int penjumlahan = 0, count = 0, temp = 0, i = 0, j = 0;
    // penjumlahan  -> adalah variabel utk menyimpan penjumlahan angka sementara yang diinisialisasi dengan 0
    // count        -> untuk menyimpan jumlah angka dalam kombinasi terbesar yang ditemukan
    // temp         -> tempat penyimpanan sementara
    // i     -> untuk iterasi arr1      dan     j      -> untuk iterasi arr2

    // looping pertama untuk arr1. 
    // loop akan terus berjalan selama i kurang dari size_arr1 dan penjumlahan tidak melebihi batas penjumlahan maks    (loop akan berjalan ketika ke 2 kondisi terpenuhi)
    while (i < size_arr1 && penjumlahan + arr1[i] <= penjumlahanMaks)
    {
        // saat looping, nilai arr1 pada indeks ke-i akan ditambahkan kedalam
        // penjumlahan dan nilai i akan bertambah 1.
        penjumlahan += arr1[i++];
    }
    // ketika loop selesai, nilai i akan disimpan kedalam count
    count = i;

    // contoh : arr1 = {1,2,3,4,5}
    // size_arr 1 = 5 dan penjumlahanMaks = 10
    // loop akan dimulai dengan i = 0, karena 0<5 dan 0+1 <= 10 maka while akan dijalankan
    // didalam loop, penjumlahan berubah jadi 1 (karena 0+1 = 1)
    // i nya di increment jadi 1
    // 1<5 dan 1+2 <= 10, looping akan berjalan dan penjumlahan akan bernilai 3 ( 1+2 = 3 ) dan i diincrement menjadi 2
    // 2<5 dan 3+3 <= 10, hasil penjumlahannya adalah 6 (3+3) dan i(3)
    // 3<5 dan 6+4 <= 10, hasil penjumlahan adalah 10 (6+4) dan i(4)
    // 4<5 maka loop akan berjalan lg, tetapi hasil penjumlahannya kan sdh 10. sedangkan di rumus 10 + 5 > 10 artinya salah. jd loop akan berhenti
    // lalu count akan diset dengan i, jadii count = 4

    // ini adalah loop untuk arr2
    // kalau di arr2, iterasi untuk indeksnya adalah j
    // loop ini akan berjalan selama j bernilai kurang dari size_arr2 dan i >= 0
    while (j < size_arr2 && i >= 0)
    {
        // pada setiap iterasi, nilai arr2 pada indeks j akan ditambahkan kedalam penjumlahan dan j akan diincrement
        penjumlahan += arr2[j++];

        // nested loop  atau loop ke 2
        // loop ini berjalan selama penjumlahan tidak lebih besar dari penjumlahanMaks dan i tidak lebih besar dari 0
        while (penjumlahan > penjumlahanMaks && i > 0)
        {
            // disini tiap iterasi dikurangi sm penjumlahan dan i akan dikurangi pd setiap iterasi
            penjumlahan -= arr1[--i];
        }
        // pengecekan kondisi saat loop ke 2 selesai
        // jika nilai penjumlahan <= penjumlahanmaks dan 
        // hasil penjumlahan i + j lebih besar dari count
        if (penjumlahan <= penjumlahanMaks && i + j > count)
        {
            // maka count akan diupdate isinya menjadi i+j
            count = i + j;
        }
    }
    // setelah itu akan mengembalikan nilai count saat semua loop selesai dijalankan
    return count;

    // contoh :
    // arr1 = {1,2,3,4,5}  dan arr2 = {6,7,8,9,10}
    // size_arr1 = 5 dan size_arr2 = 5
    // penjumlahanMaks = 15

    // loop while nambahin arr2[0] = 6 ke penjumlahan, nilai penjumlahan skrg = 6
    // penjumlahan = 6, dan penjumlahanMaks = 15 artinya nestedloop ga jalan
    // arr2[1] = 7, penjumlahan = 13   nilai penjumlahan masih kurang dari penjumlahanMaks maka nestedloop ga jalan
    // arr2[2] = 8. penjumlahan = 21  nilai penjumlahan lebih besar dari penjumlahanMaks, maka nestedloop berjalan
    // nested loop ngurangin arr1[4] = 5 dari penjumlahan, jadi penjumlahan = 16 dan i nya berubah menjadi 4 (karena di decrement)
}

// fungsi utama
int main()
{
    // deklarasi g dengan tipedata integer
    int g;
    printf("Masukkan baris angka : \n");    // meminta user memasukkan baris angka
    scanf("%d", &g);                        // baris angka yang disimpan kedalam g

    // memulai loop while. dia jalan sebanyak nilai yang disimpan di g (nilai yg diinput user). pada tiap iterasi g di kurangi 1
    while (g--)
    {
        // deklarasi variabel n m penjumlahanMaks dengan integer
        int n, m, penjumlahanMaks;
        // mengambil 3 integer dari user dan disimpen di n,m, penjumlahanMaks
        scanf("%d%d%d", &n, &m, &penjumlahanMaks);

        // deklarasi 2 array
        // arr1 dengan size n, dan arr2 dengan size m
        int arr1[n], arr2[m];

        // loop pertama ngambil input untuk arr1 
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);
        }
        // loop untuk arr2
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr2[i]);
        }

        // mencetak output kelayar dengan memanggil fungsi twoStacks dengan 4 parameter
        printf("output : %d\n", twoStacks(penjumlahanMaks, arr1, n, arr2, m));
    }

    // mengembalikan fungsi main
    return 0;
}