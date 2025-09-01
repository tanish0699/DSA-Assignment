//Upper triangular Matrix.

#include<iostream>
using namespace std;
int main(){
   int n;
cout<<"enter the number of rows and coloumns = ";
cin>>n;
int i,j;
int size=(4*n)-6;
int arr[size];
   cout<<"enter the elements = ";
    for(i=0;i<size;i++){
    cin>>arr[i];
}
int k=0;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
if(i<=j){
    cout<<arr[k]<<" ";    
    k++;                 
}

else{
    cout<<"0 ";
}
}
cout<<endl;
}
return 0;
}
