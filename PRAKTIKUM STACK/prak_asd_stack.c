#include <stdio.h>

#define MAX_SIZE 100

// Tipe data untuk menyimpan karakter dan stack
struct TandaKurung
{
    char data;                // untuk menyimpan karakter tanda kurung
    struct TandaKurung *next; // pointer next dengan tipe data struct TandaKurung
};

// Deklarasi stack untuk menyimpan karakter tanda kurung
struct TandaKurung stack[MAX_SIZE];     // array stack dapat menampung hingga MAX_SIZE yang sdh di definisikan diawal
int top = -1;                           // menandakan nilai awal stack kosong. saat data masuk, top akan berubah menjadi 0

// Fungsi push untuk menambahkan karakter char/ch kedalam stack
void push(char ch)
{
    // membandingkan nilai top dengan MAX_SIZE
    if (top == MAX_SIZE - 1)    // jika top bernilai sama dgn max_size, artinya stack penuh
    {
        printf("Stack penuh!\n");   // jika kondisi terpenuhi, akan meng outputkan ini kelayar
        return;
    }
    // jika stack tidak penuh maka lanjut ke kode berikut :
    stack[++top].data = ch; // menambahkan karakter(ch) ke dalam stack. lalu top ditambah 1 untuk menunjuk ke elemen baru
    stack[top].next = NULL; // memastikan agar pointer selanjutnya selalu NULL
}

// Fungsi pop/menghapus karakter dari stack
char pop()
{
    // membandingkan top dengan -1
    if (top == -1)  // jika top = -1, maka stack kosong
    {
        printf("Stack kosong!\n");  // jika stack kosong, akan mengoutputkan ini dan berarti tidak ada elemen yg dpt dihapus/pop
        return '\0';
    }
    // jika kondisi if tidak terpenuhi, maka akan beralih ke kode berikut
    return stack[top--].data;   // menghapus elemen dr stack dengan mengurangi top sebanyak 1 
}

// Fungsi untuk memeriksa apakah karakter pembuka dan penutup cocok
int isMatchingPair(char kurungBuka, char kurungTutup)
// terdapat 2 parameter yaitu kurungBuka dan kurungTutup dengan tipe data char
{
    // jika kurungBuka dan kurungTutup cocok maka akan mengembalikan nilai 1, jika tidak maka mengembalikan 0
    return (kurungBuka == '(' && kurungTutup == ')') ||
           (kurungBuka == '{' && kurungTutup == '}') ||
           (kurungBuka == '[' && kurungTutup == ']');
}   // fungsi ini menggunakan operator logika OR untuk mengecek 3 kondisi tanda kurung

// Fungsi untuk memeriksa keseimbangan tanda kurung dalam string 
int isBalanced(char *str)
{
    int i;  
    // looping akan berjalan selama indeks bukan null (i != \0)
    for (i = 0; str[i] != '\0'; i++)
    {
        // mengecek katakter pada indeks
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')    // jika tanda kurung buka {([ maka akan memanggil fungsi push
        {
            push(str[i]);   // memanggil fungsi push jika IF terpenuhi
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') // jika tanda kurung tutup )}] maka akan melakukan pengecekan
        {
            // pertama meriksa top nya kosong/ngga atau (||) tanda kurung yg di pop dari stack cocok/ngga dengan tanda kurung tutupnya 
            if (top == -1 || !isMatchingPair(pop(), str[i]))
            {
                return 0;   // jika salah satu kondisi terpenuhi artinya tanda kurung ga seimbang. lalu isBalanced akan ngembaliin nilai 0
            }
        }
    }
    // setelah loop selesai, akan lanjut ke kode berikut :
    return top == -1;      // jika top bernilai -1 berarti tanda kurung memiliki pasangan yang seimbang
}

// fungsi utama
int main()
{
    char str[MAX_SIZE];                     // mendeklarasi str dengan ukuran MAX_SIZE
    printf("Masukkan tanda kurung : ");     // user memasukkan tanda kurung
    scanf("%s", str);                       // inputan dibaca dan dimasukkan ke str

    if (isBalanced(str))    // memanggil fungsi isBalanced dengan parameter str
    {
        printf("YES\n");    // jika tanda kurung sesuai akan mengouputkan YES
    }
    else
    {
        printf("NO\n");     // jika tidak seimbang maka ouputnya NO
    }

    return 0;               // mengembalikan nilai 0 yang artinya program selesai dan berhasil dijalankan
}
