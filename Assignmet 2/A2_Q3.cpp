

  #include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter no. of elements in array: "<<endl;
  cin>>n;
  
  int arr[n];
  
  cout<<"enter elements of array: (must be a AP series)";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  int d=min(arr[2]-arr[1],arr[1]-arr[0]);
  //total sum including missing number
  int sum=(n+1)*((2*arr[0])+(n)*d)/2;        // int sum=((n/2) * (2*arr[0] + (n-1)*d)); //we take n = n+1 here 
  //sum excluding missing number             //bcz we input n numbers excluding missing no but total sum will be of no + excl. no
  int sum1=0;
  for(int j=0;j<n;j++){
    sum1=sum1+arr[j];
  }
  
  int missingNumber=sum-sum1;
  
  cout<<"missing number = "<<missingNumber<<endl;
  return 0;
}