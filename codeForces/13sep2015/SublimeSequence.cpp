/*A. Sublime Sequence
time limit per test1 second
memory limit per test256 megabytes
Farmer John has an integer x
. He creates a sequence of length n
 by alternating integers x
 and −x
, starting with x
.

For example, if n=5
, the sequence looks like: x,−x,x,−x,x
.

He asks you to find the sum of all integers in the sequence.

Input
The first line contains an integer t
 (1≤t≤100
)  — the number of test cases.

The only line of input for each test case is two integers x
 and n
 (1≤x,n≤10
).

Output
For each test case, output the sum of all integers in the sequence.

Example
InputCopy
4
1 4
2 5
3 6
4 7
OutputCopy
0
2
0
4
*/


#include <iostream>
using namespace std;

int main(){
  int testcase;
  cin>>testcase;
  for(int i = 0; i < testcase; i++){
    int x, n;
    cin>>x>>n;
    if(n % 2 == 0){
      cout<<0<<"\n";
    }
    else{
      cout<<x<<"\n";
    }
  }
  return 0;
}