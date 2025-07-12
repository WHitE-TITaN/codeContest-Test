#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

#include <iostream>
using namespace std;

class Solution {
private:
    unordered_map<char, bool> mapper;     
    unordered_map<string, int> businessLineMapper = {{"electronics", 0}, {"grocery", 1},
                                                     {"pharmacy", 2}, {"restaurant", 3}};

    
    bool codeValidator(string input){
        if(input.size() == 0) return false;
        for(auto character : input){
            if(!mapper[character]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        for(int i = 0; i < 26; i++){
            mapper['a' + i] = true;
            mapper['A' + i] = true;
        }

        for(int i = 0; i < 10; i++){
            mapper['0' + i] = true;
        }

        mapper['_'] = true;
        vector<pair<string, pair<bool, int>>> sorter;
        int size = businessLine.size();
        for(int i = 0; i < size; i++){
            if(codeValidator(code[i]) &&
               isActive[i] &&
               businessLineMapper.find(businessLine[i]) != businessLineMapper.end()){
                
                sorter.push_back({code[i], {isActive[i], businessLineMapper[businessLine[i]]}});
               }
        }
        sort(sorter.begin(), sorter.end(), [](pair<string, pair<bool, int>>& a,
                                              pair<string, pair<bool, int>>& b){
            return a.second.second < b.second.second;});
        
        vector<string> ans;
        for(auto finalAns : sorter){
            ans.push_back(finalAns.first);
        }
        return ans;
    }
};

