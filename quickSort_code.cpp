#include<iostream>
using namespace std;

//Utility function to swap to items in an array
void swap(int arr[], int i, int j)
{
   int hold;
   hold = arr[i];
   arr[i] = arr[j];
   arr[j] = hold;
}

//Utility function to make partitions in the array while sorting it.
//Returns the pivot index value for Quick Sort implementation
int partition(int arr[], int L, int R)
{
   while(L != R)
   {
      while((arr[L] < arr[R]) && (L != R))
      {
         L++;
      }
      swap(arr, L, R);
      while(arr[R] > arr[L])
      {
         R--;
      }
      swap(arr, L , R);
   }
   return L;
}

void quickSort(int arr[], int L, int R)
{
   int pivot;
   if(L < R) //the partition process stops once the the sub array is a singleton
   {
      pivot = partition(arr, L, R);
      quickSort(arr, L, pivot - 1); //partitioning and sorting left sub array
      quickSort(arr, pivot + 1, R); //partitioning and sorting right sub array
   }
}

int main()
{
   int arr[] = {1,4,21,5,53,8};
   quickSort(arr, 0, 5);
   
   //Printing the sorted array
   cout<< "The sorted array: \n";
   for(int i = 0; i < 6; i++)
   {
      cout<< arr[i] << " ";
   }
}
