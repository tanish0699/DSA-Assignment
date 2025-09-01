//Tri-diagonal Matrix.

#include<iostream>
using namespace std;
void triDiagonal(int arr[],int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i==j){              //diagonal
            cout<<arr[i]<<" ";      // n-1 elements print honge
        }
        else if(i==j+1){         //lower diagonal
            cout<<arr[(n-1)+i]<<" ";      //next n-1 elements will get print
            //compare like jab i=1,j=0 hoga toh vaha pr nth element ayega 
        }
        else if(j==i+1){            //upper diagonal
            cout<<arr[(2 * n-1)+i]<<" "; //lower matrix tk 2(n-1) elments print ho jayenge
        }
        else{
            cout<<"0 ";
        }
    }
cout<<endl;
}
}
int main(){
int n;
cout<<"enter the number of rows and coloumns = ";
cin>>n;
int size=(3*n)-2;
int arr[size];
cout<<"enter "<<size<<"elements in which first "<<n<<"elements will be diagonal and next"<<n-1<<"elemnts will be at lower and rest at upper = ";
cout<<endl;
for(int i=0;i<size;i++){
    cin>>arr[i];
}
triDiagonal(arr,n);

    return 0;
}