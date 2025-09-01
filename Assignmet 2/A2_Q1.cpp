 //time complexity of binary search is O(log(n)) whereas time complexity of linear search is O(n)
 //space complexity of binary search is O(1)  
 
 #include <iostream>
using namespace std;

int binarySearch(int arr[100],int n){
    int num;
    cout<<"ENTER THE NUMBER TO SEARCH = ";
    cin>>num;
  
        
   int start=0 ;
   int end=n-1 ;
    int mid;
while(start<=end){
    mid=(start + end)/2;
    if(arr[mid]<num){
        start=mid+1;
    }
    else if(arr[mid]>num){
        end=mid-1;
    }
else{
    return mid; //at last mid akela rehe jayega which will be the num then return mid 
}
}
return -1;  //if nothing happens return kedo -1 ki number not found 
}


int main(){
    int arr[]={1,3,5,6,8,10};
int n=sizeof(arr)/sizeof(arr[0]);
int position = binarySearch(arr,n);
if(position==-1)
cout<<"number is not present  "<<endl;
else{
    cout<<"number is present at index = "<<position<<endl;
}
return 0;
}