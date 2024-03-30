#include <stdio.h>
#include <stdlib.h>

// untuk mengecek posisi di papan catur
int isValid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// simulasi gerakan kuda di posisi i dan j 
void koboImaginaryChess(int i, int j, int size, int *papanCatur)
{
    // kudaX dan kudaY punya 8 kemungkinan perubahan gerak 
    int kudaX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int kudaY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // nandain posisi kuda kalau valid bernilai 1
    for (int k = 0; k < 8; k++)
    {
        int x = i + kudaX[k];
        int y = j + kudaY[k];
        if (isValid(x, y))
        {
            papanCatur[x * size + y] = 1; // Menandai posisi sebagai dapat dicapai
        }
    }
}

int main()
{

    // inisialisasi papan catur
    int papanCatur[8][8] = {0};

    int i, j;
    printf("Masukkan nilai i dan j : ");
    scanf("%d %d", &i, &j); // user masukin posisi awal kuda

    // manggil fungsi untuk simulasi gerakan kuda
    koboImaginaryChess(i, j, 8, (int *)papanCatur);

    // mencetak papan catur hasil dari simulasi
    for (int a = 0; a < 8; a++) // a = row, b = col
    {
        for (int b = 0; b < 8; b++)
        {
            printf("%d ", papanCatur[a][b]); // misal a = 2 dan b = 3, maka papanCatur[2][3] dan mencetak baris kode banyak 5 
        }
        printf("\n");
    }

    return 0;
}