s = input()
stop = 0
countq = 0
dp = [0]*len(s)
dp[0] = 0
if (s[0]=="Q"):
    countq = 1
i = 1
while i < len(s):
    if (s[i] =='Q'):
        dp[i] = dp[i-1]+stop
        countq+=1
    elif(s[i]=='A'):
        dp[i] = dp[i-1]
        stop += countq
    elif((s[i]!='A')and(s[i]!='Q')):
        dp[i] = dp[i-1]
    i+=1
print(dp[len(s)-1])
