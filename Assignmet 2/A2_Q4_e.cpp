// program to convert a character from uppercase to lowercase.

#include<iostream>
#include<string>
using namespace std;
char upperToLower(char ch){
    if(ch>='A'&& ch<='Z'){
         ch=ch - 'A' + 'a';  
         return ch;
    }
    else{
       return ch;

    }
 
}

int main(){
    char ch;
    cout<<"enter the character = ";
    cin>>ch;
    char charcter = upperToLower(ch);
     cout<<"lowercase character is = "<<charcter;
    return 0;
}