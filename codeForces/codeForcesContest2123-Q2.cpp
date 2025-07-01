/*
You are given an array of integers a1,a2,…,an
. A tournament is held with n
 players. Player i
 has strength ai
.

While more than k
 players remain,

Two remaining players are chosen at random;
Then the chosen player with the lower strength is eliminated. If the chosen players have the same strength, one is eliminated at random.
Given integers j
 and k
 (1≤j,k≤n
), determine if there is any way for player j
 to be one of the last k
 remaining players.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains three integers n
, j
, and k
 (2≤n≤2⋅105
, 1≤j,k≤n
).

The second line of each test case contains n
 integers, a1,a2,…,an
 (1≤ai≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "YES" if player j
 can be one of the last k
 remaining players, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
  int numberOfTestCases;
  cin >> numberOfTestCases;
  while (numberOfTestCases--) {
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> arr(n);
    int maximumStrength = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      maximumStrength = max(maximumStrength, arr[i]);
    }

    
    string ans = k >= 2 ? "YES" : arr[j - 1] == maximumStrength ? "YES" : "NO";
    cout << ans<< '\n';
  }
  return 0;
}