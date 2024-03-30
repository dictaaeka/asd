#include <stdio.h>
#include <string.h>

// menukar 2 elemen array
void tukar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// mencetak array
void cetakArr(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// mengurutkan kartu
int urutkanKartu(char card[], int size)
{
    int minTukar = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        // menentukan indeks terkecil
        for (int j = i + 1; j < size; j++)
        {
            // membuat urutan
            char urutan[] = "123456789JQK";
            if (strchr(urutan, card[j]) < strchr(urutan, card[minIndex]))
            {
                minIndex = j;
            }
        }

        // menukar kartu jika tidak ada indeks terkecil
        if (minIndex != i)
        {
            tukar(&card[i], &card[minIndex]);
            minTukar++;
            printf("Pertukaran ke-%d: ", minTukar);
            cetakArr(card, size);
        }
    }

    return minTukar;
}

int main()
{
    int noKartu;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &noKartu);

    char card[noKartu];
    printf("Masukkan nilai kartu : ");
    for (int i = 0; i < noKartu; i++)
    {
        scanf(" %c", &card[i]);
    }

    int minTukar = urutkanKartu(card, noKartu);

    printf("Jumlah minimum pertukaran: %d\n", minTukar);

    return 0;
}