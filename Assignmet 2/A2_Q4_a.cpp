//program to concatenate one string to another string

#include<iostream>
using namespace std;
int main(){
string str1,str2,str3;
cout<<"enter the  1st string =  ";
getline(cin,str1);
cout<<"enter the  2ns string =  ";
getline(cin,str2);

str3 = str1 + " " + str2;
cout<< "concatenate string is= "<<str3;

return 0;
}