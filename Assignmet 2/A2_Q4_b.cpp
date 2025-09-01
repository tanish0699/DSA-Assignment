 //Reverse the String 
 
#include<iostream>
#include<string>
using namespace std;
void reverseString(string str,int length){
int start=0;
int end=length-1;

    while(start<=end){
       char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
  
    cout<<"reverse of string is = "<<str; 
}

int main(){
    string str;
    cout<<"enter the string = ";
    getline(cin,str);
    int length=0,i=0;
while(str[i]!='\0'){
    length++;
    i++;
}
cout<<"length = "<<length<<endl;
reverseString(str,length);

return 0;
}