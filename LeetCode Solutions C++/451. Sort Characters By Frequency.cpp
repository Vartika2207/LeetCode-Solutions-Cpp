class Solution {
	public:
		//time: O(logN), space: 0(1)
		string frequencySort(string s){
			int freq[123]={0}; //to store freq of character at index as ascii value 
			for(auto c: s) freq[c]++;
			//if frequencies are same take low-ascii value character else take high frequency charater
			sort(s.begin(), s.end(), [&](char a, char b){ return ((freq[a] == freq[b]) ? a < b : freq[a] > freq[b]);});
			return s;
		}
	};
	

