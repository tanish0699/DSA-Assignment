//Diagonal Matrix 

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of rows and coloumns of the matrix = ";
    cin>>n;
    int arr[n];
    int i,j;
    cout<<"enter the diagonal elements of the matrix = ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
if(i==j){
    cout<<arr[i]<<" ";
}
else{
    cout<<"0 ";
}
        }
        cout<<endl;
    }
return 0;
}