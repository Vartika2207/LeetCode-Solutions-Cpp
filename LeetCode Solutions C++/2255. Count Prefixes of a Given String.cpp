lass Solution {
public:
	//time:O(n), space: O(1)
	int countPrefixes(vector<string>& words, string s) {
		int count = 0;
		for(auto wd : words)
			if(s.find(wd) < 1) count++; //if first occurrence of sub-string is in the specified string
		return count;
	}
};
