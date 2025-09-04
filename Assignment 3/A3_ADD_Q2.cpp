//stack that supports getMin() in O(1) time and O(1) extra space

#include<iostream>
#include<stack>
using namespace std;

 int main(){
stack<int>s;
int n,i=0;
cout<<"enter the no of elements to input :- ";
cin>>n;
int arr[n];
cout<<"enter the elements :- ";
for(i=0;i<n;i++){
    cin>>arr[i];
}
      s.push(arr[0]);
for(i=1;i<n;i++){
    
  if(arr[i]<s.top()){
        s.pop();
        s.push(arr[i]);
    }
}
    cout<<"minimum number is = "<<s.top()<<endl;


return 0;
 }