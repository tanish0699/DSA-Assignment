//Write a program to delete all the vowels from the string

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
void deleteVowels(string str){
     int length=0,i=0;
    while(str[i]!='\0'){
        length++;        //we can also find the length by the function length.str()
        i++;
    }
int count=0,index=0;
    for(i=0;i<length;i++){
        char ch= upperToLower(str[i]);
       if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
            count++;
              str[index++]=str[i];
              
              }
              
    }
        cout<<"string after deletion of vowels = "<<endl;
for(i=0;i<count;i++){
    cout<<str[i];
}
   
}
int main(){
    string str;
    cout<<"enter the string = ";
    getline(cin,str);
deleteVowels(str);


    return 0;
}