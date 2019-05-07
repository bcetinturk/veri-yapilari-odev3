#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArrays(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int pivot){
    int i = low;
    int temp1, temp2;
    for (int j = low; j < high; j++){
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

void matchKeysAndLocks(int keys[], int locks[], int low, int high){
    if (low < high){
        int index = rand() % (high-low+1) + low;
        printf("random index: %d\n", index);
        int pivot = partition(locks, low, high, keys[index]);

        partition(keys, low, high, locks[pivot]);

        matchKeysAndLocks(keys, locks, low, pivot-1);
        matchKeysAndLocks(keys, locks, pivot+1, high);
    }
}

int main(){
    srand(time(NULL));
    int keys[20] = {2,6,8,5,1,9,7,3,4,0,15,19,18,14,12,11,13,17,16,10};
    int locks[20] = {9,2,3,4,6,1,5,7,0,8,10,14,16,11,15,19,17,13,12,18};

    int n = sizeof(keys)/ sizeof(int);

    printArrays(keys, n);
    printArrays(locks, n);

    matchKeysAndLocks(keys, locks, 0, n-1);

    printArrays(keys, n);
    printArrays(locks, n);

    return 0;
}