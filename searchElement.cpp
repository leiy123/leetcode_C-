#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

   struct RC{
        int ridx;
        int cidx;
    };
    RC& findrcIndex(vector<vector<int>> array, RC &rw1, int target){//向下走/向右走

        if((rw1.cidx >= array[0].size() || rw1.cidx <= -1 || rw1.ridx >= array.size()) || array[rw1.ridx][rw1.cidx] == target)
            return rw1;
        else if(array[rw1.ridx][rw1.cidx] > target){
            rw1.cidx -= 1;
           // cout<<array[rw1.ridx][rw1.cidx]<<' '<<rw1.cidx<<' '<<rw1.ridx<<"left"<<endl;
            return findrcIndex(array, rw1, target);
        } else{
            rw1.ridx += 1;
           // cout<<rw1.cidx<<' '<<rw1.ridx<<"down"<<endl;
            return findrcIndex(array, rw1, target);
        }
    }
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
       	RC rw1;
      	rw1 = {0,  static_cast<int>(array[0].size()-1)};
        rw1 = findrcIndex(array, rw1, target);
       // cout<<rw1.ridx<<' '<<rw1.cidx<<endl;
        if(rw1.cidx >= array[0].size() || rw1.cidx <= -1 || rw1.ridx >= array.size())
        	return false;
        return true;
    }


int main()
{
    int ary[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13}, {6,8,11,15}};
    vector<vector<int>> vec;
    for(int i=0; i<sizeof(ary)/sizeof(ary[0]); i++){
        vector<int> x(ary[i], ary[i]+4);
        vec.push_back(x);
    }
    if(Find(3, vec))
       cout<<"true"<<endl;
       else
        cout<<"false"<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
