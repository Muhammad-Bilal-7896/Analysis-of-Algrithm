#include <iostream>
#include <string>
using namespace std;

int frequency(int arr[], int s, int element)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == element)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    const int size = 7;
    int arr[size] = {3, 4, 8, 2, 3, 3, 2};
    cout << "The Given Array is : \n";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // 1) Find the largest element in an array
    int largest = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "First Step Complete Found The largest element is:" << largest << endl;
    // 2) Create an temp array and initialize each element in array with 0
    const int TEMP_ARR_SIZE = ++largest;
    int *tempArray = new int(TEMP_ARR_SIZE);
    for (int i = 0; i < TEMP_ARR_SIZE; i++)
    {
        tempArray[i] = 0;
    }
    cout << "Seocond Step Complete Created an temp array of size of largest element and initialized each element with 0\n"
         << endl;
    // 3) Store the frequency of each element in array at that elements index in temp array
    for (int i = 0; i < size; i++)
    {
        int frequency = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                frequency++;
            }
        }
        tempArray[arr[i]] = frequency;
        cout << "frequency of " << arr[i] << " is: " << frequency << endl;
    }
    //Showing the temp array for satisfaction
    for (int i = 0; i < TEMP_ARR_SIZE; i++)
    {
        cout << "\nTemp array element of index " << i << " is : " << tempArray[i];
    }
    cout << "\n\nThird Step Completed Created Stored the frequency of each elements in the array at that elements index in the temporary array.\n"
         << endl;
    cout << endl
         << endl;
    // 4. Store the cumulative sum of the elements of the temporary array. It helps in placing the elements into the correct index of the sorted array.
    //Calculating camulative sum
    for (int i = 0; i < TEMP_ARR_SIZE; i++)
    {
        if (i == 0)
        {
            tempArray[i] = tempArray[i];
        }
        else
        {
            tempArray[i] = tempArray[i] + tempArray[i - 1];
        }
        cout << "cumalative sum of element " << i << ": " << tempArray[i] << endl;
    }
    cout << "\n\nFourth Step Completed Stored the cumalative sum of each element's in the array at that element’s index in the temporary array.\n"
         << endl;
    // 5. Shifting Elements towards right now of temp array by one index
    int *newTempArray = new int(TEMP_ARR_SIZE);
    for (int i = 0; i < TEMP_ARR_SIZE; i++)
    {
        if (i == 0)
        {
            newTempArray[i] = 0;
        }
        else
        {
            newTempArray[i] = tempArray[i - 1];
        }
        cout << "Sifted element towards right by one index at index: " << i << " elements are : " << newTempArray[i] << endl;
    }
    cout << "\nShifted Elements towards right now of temp array by one index.\n"
         << endl;
    // 6. Find the index of each element of the original array in the temporary array. This gives the cumulative count. Place the element at the index calculated as shown in the below image.
    bool check[size];
    for (int i = 0; i < size; i++)
    {
        check[i] = 0;
    }

    int final_sorted_array[size];
    for (int i = 0; i < size; i++)
    {
        const int element = arr[i];
        int frequencyOfCurrentArrayValue = frequency(arr, size, element);
        for (int j = 0; j < TEMP_ARR_SIZE; j++)
        {
            if (arr[i] == j)
            {
                if (frequencyOfCurrentArrayValue > 1)
                {
                    int tempIndexesToPlaceValue = newTempArray[j];
                    for (size_t k = 0; k < frequencyOfCurrentArrayValue; k++)
                    {
                        final_sorted_array[tempIndexesToPlaceValue] = arr[i];
                        tempIndexesToPlaceValue++;
                    }
                }
                else
                {
                    final_sorted_array[newTempArray[j]] = arr[i];
                }
            }
        }
    }
    cout << "\n\nThe Final Sorted Array using Counting Sort is : \n";
    for (size_t i = 0; i < size; i++)
    {
        cout << "  " << final_sorted_array[i] << endl;
    }

    //freeing the memory
    delete[] tempArray;
}