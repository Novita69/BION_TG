#include <stdio.h>

#define MIN_PURCHASE 100000 // Batas minimal pembelian untuk mendapat kupon & diskon
#define DISCOUNT_RATE 0.05  // Persentase diskon per kupon

void hitungPembelian(float totalPembelian)
{
    int kupon = totalPembelian / 100000;                     // menghitung jumlah kupon yang akan diperoleh
    float diskon = totalPembelian * (kupon * DISCOUNT_RATE); // menghitung berapa rupiah diskon yang didapatkan
    float totalPembayaran = totalPembelian - diskon;         // Menghitung berapa rupiah yang harus dibayar setelah dikurangi oleh diskon yang ada
    printf("\n==============================\n");
    printf("Total pembelian : Rp %.2f\n", totalPembelian);
    printf("Kupon Undian : %d lembar\n", kupon);
    printf("Diskon : Rp %.2f\n", diskon);
    printf("Total yang Dibayar : Rp %.2f\n", totalPembayaran);
    printf("==============================\n\n");
}

int main()
{
    float totalPembelian, totalPembayaran;
    char pilihan;
    do
    {
        printf("Masukan total pembelian : Rp ");
        if (scanf("%f", &totalPembelian) != 1 || totalPembelian < 0)
        {
            printf("Input tidak valid. Silahkan masukan angka positif.\n");
            while (getchar() != '\n')
                ;     // Membersihkan buffer input
            continue; // Meminta Input Ulang
        }

        if (totalPembelian >= MIN_PURCHASE) // melakukan fungsi selection untuk menjalankan perintah
        {
            hitungPembelian(totalPembelian);
        }
        else
        {
            printf("\n==============================\n");
            totalPembayaran = totalPembelian; // total pembayaran sama dengan total pembelian jika pembelian kurang dari 100000
            printf("Total Pembelian: Rp %.2f\n", totalPembelian);
            printf("Total yang Dibayar: Rp %.2f\n", totalPembayaran);
            printf("Karena total pembelian kurang dari Rp 100.000, maka tidak mendapat kupon undian dan diskon.\n");
            printf("==============================\n\n");
        }

        printf("Apakah anda ingin melanjutkan program menghitung ini ? (y/n) : ");
        scanf(" %c", &pilihan); // membaca pilihan pengguna, note : jangan lupa menambahkan spasi sebelum %c untuk mengabaikan karakter newline yang tersisa di buffer input.

    } while (pilihan == 'y' || pilihan == 'Y'); // Loop terus berjalan jika pengguna memilih 'y' atau 'Y'

    return (0);
}