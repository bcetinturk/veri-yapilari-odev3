#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 * parametreler
 * arr: bastırılacak dizi
 * n: dizi boyutu
 * w: hangi dizi oldugunu belirtmek icin (keys/locks)*/
void printArray(int arr[], int n, char w){

    if(w=='k') printf("Keys: ");
    else if(w=='l') printf("Locks: ");

    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * parametreler
 * arr: bölünecek dizi
 * low: alt dizinin alt indisi
 * high: alt dizinin üst indisi
 * pivot: diziyi bölmek için kullanılacak sayı
 *
 * return degeri
 * dizinin bölüneceği indis*/
int partition(int arr[], int low, int high, int pivot){
    int i = low;
    int temp1, temp2;
    int j;
    for (j= low; j < high; j++){
        if (arr[j] < pivot){
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
        } else if(arr[j] == pivot){
            temp1 = arr[j];
            arr[j] = arr[high];
            arr[high] = temp1;
            j--;
        }
    }
    temp2 = arr[i];
    arr[i] = arr[high];
    arr[high] = temp2;

    return i;
}

/*
 * parametreler
 * keys: anahtar degerlerinin tutuldugu dizi
 * locks: kilit degerlerinin tutuldugu dizi
 * low: alt dizinin alt indisi
 * high: alt dizinin üst indisi
 * n: dizinin uzunlugu (adım adım gostermek icin printArray() fonksiyonu cagrılırken kullanılacak)
 * */
void matchKeysAndLocks(int keys[], int locks[], int low, int high, int n){
    if (low < high){

        int index = rand() % (high-low+1) + low;
        printf("---- Low: %d High: %d Index: %d\n", low, high, index);
        int pivot = partition(locks, low, high, keys[index]); //önce locks dizisi üzerinde arama yapılacak
        printArray(locks, n, 'l');

        partition(keys, low, high, locks[pivot]);
        printArray(locks, n, 'k');

        matchKeysAndLocks(keys, locks, low, pivot-1, n);
        matchKeysAndLocks(keys, locks, pivot+1, high, n);
    }
}

int main(){
    srand(time(NULL));
    int keys[20] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int locks[20] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

    int n = sizeof(keys)/ sizeof(int);

//    int n, keys[100], locks[100];
//    printf("Kac kilit var ");
//    scanf("%d", &n);
//
//    int i;
//    for(i=0; i<n; i++){
//        printf("%d. anahtar: ", i+1);
//        scanf("%d", &keys[i]);
//    }
//
//    printf("Kilit degerleri: ");
//    for(i=0; i<n; i++){
//        printf("%d. kilit: ", i+1);
//        scanf("%d", &locks[i]);3
//    }

    printf("Baslangıcta\n");
    printArray(locks, n, 'l');
    printArray(keys, n, 'k');
    matchKeysAndLocks(keys, locks, 0, n-1, n);
    printf("Son durum\n");
    printArray(locks, n, 'l');
    printArray(keys, n, 'k');

    return 0;
}