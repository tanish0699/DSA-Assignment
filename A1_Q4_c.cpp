#include<iostream>
using namespace std;
int m,n,i,j;
int matrix[100][100],transMatrix[100][100];
void create(){
    cout<<"enter no of rows = ";
    cin>>m;
    cout<<"enter no of coloumns = ";
    cin>>n;
    cout<<"enter the elemets in the array = "<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
}
void display(){
    cout<<"original matrix = "<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;
}
void transpose(){
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
           transMatrix[j][i]=matrix[i][j];
        }
    }
    cout<<"transpose of the matrix is = "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<transMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;
}
  

int main(){
create();
display();
transpose();
    return 0;
}