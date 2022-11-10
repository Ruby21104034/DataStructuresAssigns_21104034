#include<iostream>
using namespace std;

//ARRAY gets sorted from right end
//if array is already sorted,it will stop in 1st pass only-->FLAG

void BubbleSort(int arr[],int n){
    int flag;
    //j denotes number of rounds.In one round,only one element reaches its correct position(Round1 largest element reaches at last)
    //n-1 rounds are needed(since the n-1 elements will be placed correctly and so last element will also be placed at its correct position)
    //i & i+1 denotes the indices to be compared 
    for(int j=0;j<n-1;j++){
        flag=0;
    for(int i=0;i<n-1-j;i++){   //n-1-j as the list gets sorted from the right end so we dont need to compare rest elements with sorted elements
    //if first element is greater than second,swap the two
    if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        flag=1;
    }
 }
 if(flag==0){
    cout<<"Array is already sorted ";
    break;
 }
    }
}

//Print the elements of array
void PrintArray(int input[],int n){
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
           }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int input[100];
  
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
  BubbleSort(input,n);
  PrintArray(input,n);
    return 0;
}

//Number of rounds-(n-1) for n elements
//Number of swaps-In Bubble sort, largest element moves to right.So a swapping is done, when a smaller element is found on right side.So to count number of swaps for an element, we count number of elements on right side which are smaller than it.
//the bubble sort swaps n * (n – 1) / 2 elements in the worst case (when the list is sorted in reverse order).
//Bubble sort is an in-place algorithm.It does not need an extra space and produces an output using the same memory containing the data by manipulating the input in one place.