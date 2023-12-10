//make use of both selection sort and insertion sort
#include <iostream>
using namespace std;

template<typename t> 
void selectsort(t arr[] , int n){               //note here arr is passed as t arrr[]
int i, j;
int min_idx;									//selection sort: find the minimum index abd then sent it to the start
	for (i = 0; i < n - 1; i++) {

       min_idx = i;
       for (j = i + 1; j < n; j++) {
           if (arr[j] < arr[min_idx])
               min_idx = j;
       }

       if (min_idx != i)
           swap(arr[min_idx], arr[i]);
   }
}


template<typename t>
void insertion_sort(t arr[], int n)				//j goes backward until it reaches 0 and finds the element less thanit 
{
	t key;
	int j;
	for(int i=1;i<n;i++)
	{
		key = arr[i];
		j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


template<typename t>							//for every function as we see, we create a template 
 void printarray(t arr[] ,t n){
for(int i = 0 ; i < n ; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
 
int arr2[5] = {5,4,3,2,1};
float arr3[5] = { 4.5, 1.1 , 0.3 , 4.3 , 4.1};

cout<<"SELECTION SORTING"<<endl;
selectsort <int> (arr2,5);							//while calling we pass the req data type in <>
printarray <int> (arr2,5);
selectsort <float> (arr3,5);
printarray <float> (arr3,5);

cout<<"--------------------------------------------------------"<<endl;

cout<<"INSERTION SORTING"<<endl;
insertion_sort <int> (arr2,5);
printarray <int> (arr2,5);
insertion_sort <float> (arr3,5);
printarray <float> (arr3,5);
}

 
