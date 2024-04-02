// soal nomor 1 //

#include <stdio.h>
#include <stdlib.h>

// membuat struktur data bernama Node
struct Node
{
    char *abjad;            // pointer untuk menyimpan huruf alphabet (string)
    struct Node *next;      // pointer untuk mengarahkan ke Node lain
};

int main()
{
    // deklarasi node
    struct Node l1, l2, l3, l4, l5, l6, l7, l8, l9;     // bertipe data struct Node
    struct Node *next;                         

    // inisialisasi node
    l1.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l1.abjad      = "F";        // menginisialisasi l1 dengan huruf F (artinya l1 itu hurufnya F)

    l2.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l2.abjad      = "M";        // huruf l2 M

    l3.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l3.abjad      = "A";        // huruf l3 A

    l4.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l4.abjad      = "I";

    l5.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l5.abjad      = "K";

    l6.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l6.abjad      = "T";

    l7.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l7.abjad      = "N";

    l8.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l8.abjad      = "O";

    l9.next       = NULL;       //next di set ke NULL untuk menandakan belum terhubung ke node lain
    l9.abjad      = "R";

    // menghubungkan node sesuai dengan urutan
    l7.next = &l1;      // menamdakan node l7 terhubung ke node l1
    l1.next = &l8;
    l8.next = &l2;
    l2.next = &l5;
    l5.next = &l3;
    l3.next = &l6;
    l6.next = &l9;
    l9.next = &l4;
    l4.next = &l7;      // l4 dihubungkan dengan l7 agar membentuk loop tertutup

    // mencetak abjad yang dimulai dari l3
    //l3.next = l3 dihubungkan sm l6, artinya huruf dil3 itu T. supaya dpt I harus di next 2 kali
    printf("%s", l3.next->next->next->abjad);                               // menampilkan huruf I
    printf("%s", l3.next->next->next->next->abjad);                         // menampilkan huruf N
    printf("%s", l3.next->next->next->next->next->abjad);                   // menampilkan huruf F
    printf("%s", l3.next->next->next->next->next->next->abjad);             // menampilkan abjad O
    printf("%s", l3.next->next->abjad);                                     // menampilkan abjad R
    printf("%s", l3.next->next->next->next->next->next->next->abjad);       // menampilkan abjad M
    
    // disini huruf dil3 kalau ga di next kan tetep A. jadi langsung dicetak pakai abjad
    printf("%s", l3.abjad);                                                 // menampilkan abjad A
    printf("%s", l3.next->abjad);                                           // menampilkan abjad T
    printf("%s", l3.next->next->next->abjad);                               // menampilkan abjad I 
    printf("%s", l3.next->next->next->next->next->next->next->next->abjad); // menampilkan abjad K
    printf("%s", l3.abjad);                                                 // menampilkan abjad A
    return 0;
    // direturn 0 artinya program selesai berjalan
}
