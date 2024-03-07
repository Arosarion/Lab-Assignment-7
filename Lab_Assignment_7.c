#include <stdio.h>
#include <string.h>
/*Bubble sort and selection sort on two arrays*/
//Slection sort
void slection_sort(int arr[], int n, int swaps[])
{
    int min_index;
    for (int i = 0; i < n-2; i++) // stops until the second to last index
    {
        //assume the currtent index is the smallest value
        min_index = i;
        //Check the array to find the min index
        for (int j = i+1 ; j < n; j++)
        {
            if (arr[j] < arr[min_index])//If element at index j < arr[min_index]
            {
                min_index = j;// min_index is j index
            }
        }
        if (min_index != i)
        {
            //Swap the indexs
            int temp = arr[i];// temp holds the larger index
            arr[i] = arr[min_index];// arr[i] element is = to arr[min_index]
            arr[min_index] = temp;// place teh larger index back to the list but where the previous smaller index was.
            swaps[i]++;   
        }
    }   
}
//Bubble sort
void bubble_sort(int arr[], int n, int swaps[])
{
    for(int k = 0; k < n - 1; k++)
    {   
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];// temp holds the larger index
                arr[i] = arr[i + 1];// arr[i] element is = to arr[min_index]
                arr[i + 1] = temp;
                swaps[i]++;
            }
        }
    }
}

// Print the number of swaps for each elememnt and the total 
void swap_print(int arr[], int n, int swaps[]){
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        swaps[i] =  (swaps[i]);
        printf("%d: # of times %d is swapped\n", swaps[i], arr[i]);
        total += swaps[i];
    }
    printf("total # of swaps: %d\n", total/2);
}
//Initialize swap array to zero
int initialize_swaps(int swaps[], int n){
    for (int i = 0; i < n; i++)
    {
        swaps[i] = 0;   
    }
    return swaps[n];
}


int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(array1)/sizeof(array1[0]);
    int original_array1[n];
    int original_array2[n];
    int swap[n];

    for (int i = 0; i < n; i++)// Copy original array
    {
        original_array1[i] = array1[i];
        original_array2[i] = array2[i];
    }
    

    //Bubble sort
    swap[n] = initialize_swaps(swap, n);
    bubble_sort(array1, n, swap);
    swap_print(array1, n, swap);
    printf("\n");

    swap[n] = initialize_swaps(swap, n);
    bubble_sort(array2, n, swap);
    swap_print(array2, n, swap);
    printf("\n");

    //Selection sort
    swap[n] = initialize_swaps(swap, n);
    slection_sort(original_array1, n, swap);
    swap_print(original_array1, n, swap);
    printf("\n");

    swap[n] = initialize_swaps(swap, n);
    slection_sort(original_array2, n, swap);
    swap_print(original_array2, n, swap);

    return 0;
}