#include <stdio.h>

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

void matchPairs(int keys[], int locks[], int low, int high){
    if (low < high){
        int pivot = partition(keys, low, high, locks[high]);

        partition(locks, low, high, keys[pivot]);

        matchPairs(keys, locks, low, pivot-1);
        matchPairs(keys, locks, pivot+1, high);
    }
}

void printArrays(int keys[], int locks[], int n){
    printf("Keys: ");
    for(int i=0; i<n; i++){
        printf("%d ", keys[i]);
    }
    printf("locks: ");
    for(int i=0; i<n; i++){
        printf("%d ", locks[i]);
    }
}

int main(){
    int keys[10] = {2,5,6,8,7,3,6,1,4,0};
    int locks[10] = {6,8,2,3,9,4,1,5,7,0};

    int n = sizeof(keys)/ sizeof(int);

    matchPairs(keys, locks, 0, n);
    printArrays(keys, locks, n);

    return 0;
}