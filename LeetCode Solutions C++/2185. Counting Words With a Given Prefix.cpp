class Solution {
public:
//time: O(n), space: O(1)
	int prefixCount(vector<string>& words, string pref) {
		int count = 0;
		for(auto wd : words)
			if(wd.find(pref) < 1) // checkh if first occurrence of sub-string in the specified string
				count++;
		return count;
	}
};
