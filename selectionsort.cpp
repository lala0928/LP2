// C++ program for implementation of 
// selection sort 
#include <iostream>              // Include input/output stream for using cin and cout
using namespace std;            // Use standard C++ namespace

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;          // Declare loop variables and a variable to store index of the minimum element

    // Move the boundary of the unsorted subarray one by one
    for (i = 0; i < n - 1; i++) {
        min_idx = i;            // Assume the current index has the minimum element

        // Loop to find the actual minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) // If a smaller element is found, update min_idx
                min_idx = j;
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print the elements of the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)  // Loop through array
        cout << arr[i] << " ";      // Print each element followed by a space
    cout << endl;                   // Newline after printing all elements
}

// Main function
int main()
{
    int n;                          // Variable to store number of elements
    cout << "Enter number of elements: ";
    cin >> n;                       // Take input for number of elements

    int arr[n];                     // Declare array of size n
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {   // Take n elements as input from user
        cin >> arr[i];
    }

    selectionSort(arr, n);         // Call function to sort the array

    cout << "Sorted array:\n";
    printArray(arr, n);            // Print the sorted array

    return 0;                       // Exit program
}


// Enter number of elements: 5
// Enter 5 elements:
// 64 25 12 22 11
// Sorted array:
// 11 12 22 25 64
