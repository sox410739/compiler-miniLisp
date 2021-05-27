#include<iostream>

using namespace std;
void printBool(int b);

int main(){
 int diff(int a, int b);
cout << diff(0, 5) << endl;
cout << diff(5, 0) << endl;

 return 0;
}

void printBool(int b){
 if(b == 1){
  cout << "#t" << endl;
 }else if(b == 0){
  cout << "#f" << endl;
 }else{
  cout << "type error" << endl;
 }
}

int abs(int a){
 return ((a<0) ? (0-a) : a);
}

int diff(int a, int b){
 int abs(int a);
return abs((a-b));
}


