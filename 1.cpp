#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

 vector<int> twoSum(vecor<int>& nums, int target){
    unordered_map<int, int> numToIndex;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        int numToMatch = target - num[i];
        if(numToIndex.find(numToMatch) != numToIndex.end())
            res.push_back(numToIndex[numToMatch]);
            res.push_back(i);
            return res;
        } //ctl+shift+.���Ҷ���
        numToIndex[nums[i]] = i; //δ�ҵ���
    }
    return res;
}

int main()
{

    //cout << "Hello world!" << endl;
    return 0;
}
