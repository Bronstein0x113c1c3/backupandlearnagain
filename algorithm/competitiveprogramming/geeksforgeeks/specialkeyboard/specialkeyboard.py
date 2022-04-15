def max(a,b):
    if a>=b: return a
    else: return b
dp=[0 for i in range(10000)]
for i in range(7):
    dp[i]=i
    print(dp[i])
for j in range(7,10000):
    dp[j] = max(3*dp[j-4],4*dp[i-5])
    print(dp[j])
    