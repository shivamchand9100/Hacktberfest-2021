public int deleteString(String s) {
	int n = s.length();
	int[] dp = new int[n];
	dp[n-1] = 1;
	for (int i = n - 2; i >= 0; i--) { //O(N)
		dp[i] = 1;
		for (int j = 1; j <= (n - i) / 2; j++) { //O(N)
			String firstStr = s.substring(i, i + j); //O(N)
			String secondStr = s.substring(i + j, i + j + j);
			if (firstStr.equals(secondStr)) {
				dp[i] = Math.max(dp[i], 1 + dp[i + j]);
			}
		}
	}
	return dp[0];
}
