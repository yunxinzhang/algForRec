#include <iostream>
#include <string>
using namespace std;



class Solution {
	public:
		int romanToInt(string s) {
			if(s=="")return 0;
			int ch2i[100] = {0};
			ch2i['I'] = 1;
			ch2i['V'] = 5;
			ch2i['X'] = 10;
			ch2i['L'] = 50;
			ch2i['C'] = 100;
			ch2i['D'] = 500;
			ch2i['M'] = 1000;
			int res = 0;
			for(size_t i=0; i<s.size()-1; ++i){
					if(ch2i[s[i]] < ch2i[s[i+1]]){
						res += ch2i[s[i+1]] - ch2i[s[i]];
						++i;
					}else{
						res += ch2i[s[i]];
					}

			}
			if(s.size()>=2 && ch2i[s[s.size()-2]] < ch2i[s[s.size()-1]])
					return res;
			return res + ch2i[s[s.size()-1]];
		}
};
int main(){
	string s3 = "MCMXCIV";
	cout << Solution().romanToInt(s3) << endl;

	string s1 = "IV";
	cout << Solution().romanToInt(s1) << endl;
	string s2 = "LVIII";
	cout << Solution().romanToInt(s2) << endl;
}
