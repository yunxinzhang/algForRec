#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		map<int, int> n2i;
		for(size_t i=0; i< nums.size(); ++i){
				if(n2i.find(nums[i])==n2i.end())
						n2i.insert(make_pair(nums[i], 1));
				else
						n2i.find(nums[i])->second++;
		}
		vector<int> ns;
		for(map<int,int>::iterator it=n2i.begin(); it!=n2i.end(); ++it){
			ns.push_back(it->first);
		}
		int target;
		set<vector<int> > ans;
		for(int i=0; i<n2i.size(); ++i){
				if(n2i.at(ns[i])>=2){
						if(ns[i]==0 && n2i.at(ns[i])>=3){
							ans.insert(vector<int>(3,0));	
						}else{
							target = -(ns[i]*2);
							if( n2i.find(target) != n2i.end()){
								int _a[3] = {ns[i], ns[i], target};
								ans.insert(vector<int>(_a, _a+3));
							}
				 		}	
				}
				for(int j=i+1; j<n2i.size(); ++j){
					target = -(ns[i] + ns[j]);
					if(target == ns[i]){
							//if(n2i.at(target))
					}else if(target == ns[j]){
							if(n2i.at(ns[j])>=2){
								int _a[3] = {ns[i], ns[j], ns[j]};
								ans.insert(vector<int>(_a, _a+3));
							}
					}else if(target > ns[j]){
							if(n2i.find(target) != n2i.end()){
									int _a[3] = { ns[i], ns[j], n2i.at(target) };
									ans.insert(vector<int> (_a, _a+3));
							}
					}
				}
		}							    
		return vector<vector<int> >(ans.begin(), ans.end());
	}
};

int main(){
	int _a[6] = { -1, 0, 1, 2, -1, -4 };
	vector<int> a(_a,_a+6);
	vector<vector<int> > ans = Solution().threeSum(a);
	cout << ans.size() <<endl;
	for(int i=0; i<ans.size(); ++i){
			for(int j=0; j < ans[i].size(); ++j){
					cout << ans[i][j] << " ";
			}
			cout << endl;
	}
}
