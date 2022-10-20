#include<iostream>
using namespace std;
void InsertionSort(int arr[], int n){
     for(int i=1;i<n;i++){ //In insertion sort,first element is assumed to be sorted so start from i=1 and not i=0
     //i variable tells from which element we have to start comparing
        int current = arr[i]; //current variable stores value of i th index element
        int j;
        for(int j=i-1; j>=0; j--){  //Comparing current element with all elements at its left in the array
            if(current < arr[j]){
                arr[j + 1]= arr[j];   //If current element is less than the previos element,shift the two elements
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
     }
}
//Function to print the elements of array
void PrintArray(int input[], int n){
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
int main(){
    //Take array input from the user(n<100)
    int n;
    cin>>n;
     int input[100]; //Declaring array named 'input' and its size of 100

     for(int i=0;i<n;i++){
        cin>>input[i];
     }
     //Calling the functions 
     InsertionSort(input, n);
     PrintArray(input, n);
     return 0;
     }