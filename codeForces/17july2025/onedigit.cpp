#include <iostream>
#include <string>
using namespace std;

int findsmallest(string number){
  char smallest = '9';
  for(auto integer : number){
    if(integer < smallest){
      smallest = integer;
    }
  }

  return smallest - '0';
}

int main(){
  int testcases;
  cin >> testcases;
  for(int i = 0; i < testcases; i++){
    string number;
    cin >> number;
    cout<<findsmallest(number)<<"\n";
  }
}