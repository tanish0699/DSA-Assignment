#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int i;
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<<"original array  = ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    int start=0;
    int end=n-1;
    cout<<"reversed array  = ";
    while(start<=end){
        int temp=arr[start];
       arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    
    return 0;}