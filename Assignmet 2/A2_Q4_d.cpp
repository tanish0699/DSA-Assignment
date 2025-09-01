//program to sort the strings in alphabetical order

#include<iostream>
#include <cctype> 
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"enter the string =  ";
    getline(cin,str);
    int length =0;
int i=0;
    while(str[i]!='\0'){
        length++;
        i++;
        }
    
    for(i=0;i<length;i++){
        for(int j=0;j<length-1-i;j++){
            if(tolower(str[j])>tolower(str[j+1])){     //tolower is a inbuilt function which convert all character to lower case
                int temp=str[j];   
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }

    }
    cout<<"sorting array in alphabetic order = "<<str<<endl;

    return 0;
}