// Develop a Menu driven program to demonstrate the following operations of Arrays
//  ——MENU——-
// 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT


#include<iostream>
using namespace std;
int n;
int arr[100]; //we have to initialise the size of the array, we cant use arr[size] here because size is not intialise yet
//size of array = n
void create(){
    cout<<"enter the size = ";
cin>>n;
    cout<<"enter the elements = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<endl;
}
void display(){
  
    if(n==0){
        cout<<"first create array ";
    }
    else{
        for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
         }

    }
    cout<<endl;
}
void insert(){
int value,index;

      if(n==0){
        cout<<"first create array ";
    }else{
        cout<<"enter the index = ";
cin>>index;
cout<<"enter the value = ";
cin>>value;
    for(int i=n-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=value;
    n=n+1;
    display();
    }
    cout<<endl;
   
}


void deleteElement(){
   if(n==0){
        cout<<"first create array ";
    }else{
    
    int index;
    cout<<"enter the index = ";
cin>>index;
    for(int i=index;i<n-1;i++){
        arr[i]=arr[i+1];
    }
n=n-1;
display();
    }
  cout<<endl;
}
void search(){
    if(n==0){
        cout<<"first create array ";
    }else{
    int number;
    cout<<"enter the number to search=  ";
    cin>>number;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==number){
            cout<<"number is present at index = "<<i;
            count++;
            break;
        }
         }
         if(count==0){
cout<<"number not found ";
         }
    }
cout<<endl;
}
void exit(){
    if(n==0){
        cout<<"first create array ";
    }else{
      cout<<"exit";
    exit(0);
    }
    cout<<endl;
}
int main(){
   int input;
  
   cout<<"enter 1 to create the array "<<endl;
     cout<<"enter 2 to display the array "<<endl;
       cout<<"enter 3 to insert number in array "<<endl;
         cout<<"enter 4 to delete element in array "<<endl;
           cout<<"enter 5 to search number in array "<<endl;
            cout<<"enter 6 to exit in array "<<endl;

     
while(input<7){
           cout<<"enter the case to run the function = ";
cin>>input;
switch(input){

    case 1 : create();
  break;
   case 2 : display();
    break;
    case 3 :insert();
    break;
  case 4 : deleteElement();
 break;
   case 5 :  search();
    break;
    case 6 :  exit();
    break;
}}
    return 0;
}
