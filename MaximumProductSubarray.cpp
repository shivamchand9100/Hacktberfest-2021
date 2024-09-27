class Solution {
public:
	int myf(vi a) {
		int n = a.size();
		int mn = INT_MAX ;
		int p = 1;
		int ans = *max_element(a.begin(), a.end());
		for (auto i : a) {
			p *= i ;
			if ( p < 0 ) {
				if (mn != INT_MAX ) {
					ans = max(ans , p / (-mn));
				} else {
					mn = p ;
				}
			} else {
				ans = max(p , ans) ;
			}
			if ( p == 0 ) {
				p = 1;
				mn = INT_MAX;
			}
		}
		return ans;
	}
	int maxProduct(vector<int>& a) {
		int ans = myf(a);
		reverse(a.begin(), a.end());
		ans = max(ans , myf(a));
		return ans ;
	}

};
