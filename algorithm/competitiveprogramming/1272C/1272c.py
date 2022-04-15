a,b = [int(x) for x in input().split()]
s = input()
ans = 0
dp = [0 for i in range(0,len(s))]
keyboard = [m for m in input().split()]
if (keyboard.__contains__(s[0])):
    dp[0]=1
    ans=1
for i in range(1,len(s)):
    if(keyboard.__contains__(s[i])):
        dp[i] = dp[i-1]+1
        ans+=dp[i]
    else:
        dp[i]=0
print(ans)