//Bubble Sort optimised code

//Time complexity of unoptimised code (without bool) = O(n^2)
//Time complexity of optimised code in best case (sorted array)= O(n);
//space complexity in both is constant

#include<iostream>
using namespace std;
void bubbleSort(int arr[100],int n){ 
for(int i=0;i<n-1;i++){          //n-1 times round chlenege bcz har round mae eik last wala number set hojayega at right 
    for(int j=0;j<n-i-1;j++){    //har round mae last element largest set ho jata hai 
    
bool swapped = false;  //initially false

        if(arr[j]>arr[j+1]){     //agar arr[j] chota hoga swap krdo

        bool swapped = true;    //if swap happen then bool function true
            int temp = arr[j];
            arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
if(swapped == false){  //agar  koi 1st round mae koi swap nhi hua means array is sorted then break there
    break;             //no need to do rest rounds bcz unsorted mae minimum eik swap toh hoga 
    }
    }
    }


for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
int main(){
    int arr[]={2,1,7,8,9,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    return 0;
}