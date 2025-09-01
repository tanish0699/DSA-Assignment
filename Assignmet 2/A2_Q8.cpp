//program to count the total number of distinct elements in an array of length n

//METHOD -1

#include<iostream>
using namespace std;
int distinctNum(int arr[100],int n){
    int count=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
if(arr[i]==arr[j])
count++;
    }
}
return count;
}
int main(){
    int arr[]={1,2,2,4,6,7,7,8};
    int n= sizeof(arr)/sizeof(arr[0]);
   int  num = distinctNum(arr,n);
   cout<<"Number of Disttinct Elements in a array = "<<(n-num)<<endl;
   return 0;
}
 
// METHOD -2

//  #include <iostream>
// using namespace std;

// void countDistinct(int arr[], int n)
// {
//     if (n == 0)
//     {
//         cout << "distinct elements are: 0" << endl;
//         return;
//     }

//     int count = 1;    //beacuse first wala kese se compare nhi hoga toh first already distinct hai toh count=1

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] != arr[i - 1])   //beacuse arr[i] != arr[i+1] krne se eik element aghe chla jayega isliye i != i-1
//         {
//             count++;
//         }
//     }

//     cout << "distinct elements are: " << count << endl;
// }

// int main()
// {
//     int arr[] = {1,1, 2, 4, 5, 6, 6, 7, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     countDistinct(arr, n);
// }