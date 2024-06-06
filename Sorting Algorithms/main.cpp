/* Hiep Tran - main.cpp - CS010C */

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;
const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]) {
    for (int i = 0; i < NUMBERS_SIZE; ++i) {
        arr1[i] = genRandInt(0, NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int QPartition(int numbers[], int low, int high);

void Quicksort_midpoint(int numbers[], int low, int high);

void Quicksort_medianOfThree(int numbers[], int lowi, int high);

void InsertionSort(int numbers[], int numbersSize);

int main() {

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    clock_t Start = clock();
    clock_t End = clock();
    int elapsedTime = (End - Start) / CLOCKS_PER_MS;
    cout << "Elapsed time: " << elapsedTime << endl;

    return 0;
}


int QPartition(int numbers[], int low, int high) {
    int pivot = numbers[(low + high) / 2];
    int leftSide = low;
    int rightSide = high;

    while (leftSide <= rightSide) {
        while (numbers[leftSide] < pivot) {
            ++leftSide;
        }
        while (numbers[rightSide] > pivot) {
            --rightSide;
        }
        if (leftSide <= rightSide) {
            swap(numbers[leftSide], numbers[rightSide]);
            ++leftSide;
            --rightSide;
        }
    }
    return leftSide;
}

void Quicksort_midpoint(int numbers[], int low, int high) {
    if (low < high) {
        int pivotIndex = QPartition(numbers, low, high);
        Quicksort_midpoint(numbers, low, pivotIndex - 1);
        Quicksort_midpoint(numbers, pivotIndex, high);
    }
}

void Quicksort_medianOfThree(int numbers[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;

        if (numbers[low] > numbers[middle]) {
            swap(numbers[low], numbers[middle]);
        }
        if (numbers[low] > numbers[high]) {
            swap(numbers[low], numbers[high]);
        }
        if (numbers[middle] > numbers[high]) {
            swap(numbers[middle], numbers[high]);
        }

        int pivot = numbers[middle];
        swap(numbers[middle], numbers[high]);

        int leftSide = low;
        int rightSide = high - 1;

        while (leftSide <= rightSide) {
            while (numbers[leftSide] < pivot) {
                ++leftSide;
            }
            while (numbers[rightSide] > pivot) {
                --rightSide;
            }
            if (leftSide <= rightSide) {
                swap(numbers[leftSide], numbers[rightSide]);
                ++leftSide;
                --rightSide;
            }
        }

        swap(numbers[leftSide], numbers[high]);

        if (low < leftSide - 1) {
            Quicksort_medianOfThree(numbers, low, leftSide - 1);
        }
        if (leftSide + 1 < high) {
            Quicksort_medianOfThree(numbers, leftSide + 1, high);
        }
    }
}

void InsertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; ++i) {
        int temp = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            --j;
        }
        numbers[j + 1] = temp;
    }
}