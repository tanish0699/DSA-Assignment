//nearest greater element moving towards right 

#include<iostream>
#include<stack>
using namespace std;

int main(){
int n;
stack<int> s;

cout << "Enter the number of elements = ";
    cin >> n;
    int arr[n];
    int arr2[n];
    cout << "Enter the elements = ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
   for(int i = n-1; i >=0; i--){
   while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
          
        }
        if(!s.empty()){
          arr2[i] = s.top();
        }
        else{
           arr2[i]= -1;
        }
        s.push(arr[i]);
   }
    for (int i=0;i<n;i++){
        cout<<arr2[i]<< " ";
    }
   
return 0;
}