## WIP

Problem statement: https://open.kattis.com/problems/gondolas

## Techniques:
* Dynamic Programming <br />
* Convex Hull Trick (DP optimization) <br />

## Key observations:
* A skier arriving at time ***t*** is equivalent to one arriving at ***t***+2***T*** since the gondolas cycle every 2***T*** minutes. <br />
Thus we can track each skiers arrival time mod 2***T***.
* This problem is solvable using DP where our DP state is the following: <br />
  * DP[i,k] = The optimal wait time for ***j*** gondolas and the leftmost gondola arrives at time ***i***
  * Base case: assume that one gondola is places at the end of the cycle, 2***T***-1 <br />
  (note that we must iterate over all possible placements for the last gondola)
  * Notice that placing a gondola at time ***g***\<***i*** saves pre(***g***)\*(***g***-***i***)
    * pre(***g***) is the number of arrivals before or at time ***g***.
    * We can see this since, before adding ***g***, i was the earliest gondola =>
    all pre(g) skiers must will save (***i***-***g***) minutes
  * Therefore, DP[i,k] = min{DP[j,k-1]-pre(i)\*(j-i)}, for all j>=i

* Problem: Naively implementing this DP takes O(TNK) and since we must check N final postions (we can easily prune the last position since it must be on a gondola), the total runtime of this algorithm is O(TKN^2) => TLE.
* We can reduce this to O(TKN) using the Convex Hull Trick

## CHT (Convex Hull Trick) DP optimization
First note the equation: <br />
dp[i][k] = min(dp[j][k-1] - pre[i]\*(j-i)), for j>=i

Rewrite as <br />
dp[i][k] = pre[i]\*i + min(dp[j][k-1] - j\*pre[i]), for j>=i <br />
note that pre[i]\*i does not depend on j, so we can take it out of the minimum over j

Observe that min(dp[j][k-1] - j\*pre[i]) is the minimum of linear equations (mx+b) where: <br />
x = pre[i] <br />
m = -j <br />
b = dp[j][k-1] <br />



