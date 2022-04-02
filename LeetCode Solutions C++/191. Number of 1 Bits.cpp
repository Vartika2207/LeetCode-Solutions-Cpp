/* METHOD-1 */
//Using __popcount()
#include <bit>
#include <bitset>

class Solution {
public:
	int hammingWeight(uint32_t n) {
		return __popcount(n);
	}
};

/* METHOD-2 */
//Using mask
class Solution {
public:
	int hammingWeight(uint32_t n) {

		uint32_t mask = (uint32_t)1;
		int count = 0;
		while(mask){
			if(mask & n) count++;
			mask = mask << 1;
		}
		return count;
	}
};
