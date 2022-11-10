#include<iostream>
using namespace std;
//Time Complexity--Best Omega(n2);Worst O(n2);Average Theta(n2)
//Selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list
//In place algo
//i=0 to i=n-2 -->loop runs for n-1 times
//Ending point remains the same,start changes after each iteration
//i --> no. of rounds

void SelectionSort(int input[],int n){
    
     for(int i=0;i<n-1;i++){
        //Find min element in array
        int min=input[i];
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(input[j]<min){
                min=input[j];
                minIndex=j;
            }
        }
        //Swap min and index i/starting element(from where sorting is started)
        int temp=input[i];
        input[i]=input[minIndex];
        input[minIndex]=temp;
     }
}
//Number of swaps and comparisions
int swap = 0;
int comp = 0;

for(int i = 0; i < n-1; i++)
{
    int min=input[i];
    for(int j = i+1; j < n; j++ )
    {
        if(arr[j] < arr[min]){ 
            min = j;}
        comp++;
    }
    
    [arr[i], arr[min]] = [arr[min], arr[i]];
    if(min!=i) { 
        swap++; }
}


int main(){
   int input[6]={23,87,9,43,21,1};
   SelectionSort(input,6);
   for(int i=0;i<6;i++){
        cout<<input[i]<<" ";
   }
   cout<<endl;
   cout<<"Total Comparison: " <<comp<<endl;
   cout<<"Total swaps: "<<swap<<endl;
    return 0;
}

//Number of rounds-(n-1) for n given elements
//Number of swaps- (at most) n – 1 swaps between data elements(when the list is sorted in reverse order)
//In place algorithm