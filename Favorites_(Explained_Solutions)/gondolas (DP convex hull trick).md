
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
DP[i,k] = min(DP[j,k-1] - pre[i]\*(j-i)), for j>=i

Rewrite as <br />
DP[i,k] = pre[i]\*i + min(DP[j,k-1] - j\*pre[i]), for j>=i <br />
note that pre[i]\*i does not depend on j, so we can take it out of the minimum over j

Observe that min(DP[j][k-1] - j\*pre[i]) is the minimum of linear equations (mx+b) where: <br />
x = pre[i], this is our dependent variable <br />
m = -j <br />
b = DP[j][k-1] <br />

We can store the minimum of all these lines in a **deque** of lines (DQ) and the pre[i] at which they start being optimal <br />
DQ will have the following properties:
* The elements back of the queue will be optimal for pre[i] larger than those at the front
* By geometric properties: elements in the front of the queue must have slopes greater than those at the back
    * We can see this by drawing two arbitrary lines with different slope: <br />
      Clearly, the minimum value of these two lines before they intersect belongs to the line with greater slope <br />
      Conversly, the minimum value of these two lines after they intersect belongs to the line with lesser slope
* Since we are constructing out DP[2T-1,k] backwards to DP[0,k] the slopes of lines we are adding will be strictly increasing: <br />
  &nbsp;&nbsp; at DP[i,k] we can add the line corresponding to DP[i,k-1], thus our deque only contains lines for j>=i.
    * Thus when adding a line, we can compare it to the front-most line
    * If the x-value of their intersection is greater than the x-value at which the front-most line is valid, then the new line completely overrides it, and we can remove it from the queue. Then we can compare the new line to the new front-most line.
    * If the intersection is less than 0, then the new line is never optimal, since our x-value (pre[i]) is always positive, thus we can ignore this line.
    * If the intersection is greater than 0 and less than the greatest valid point of the front-most line, then we can push the new line to the front of the queue with its greatest valid point being floor(intersection.xvalue).
* Again, since our DP is constructed backwards, our queries for x (pre[i]) are non-increasing:
    * Thus we can always look at the back of DQ to get our optimal line.
    * If the next line at the back of the DQ is valid (pre[i] \<= DQ.back.valid_point), we can remove the last line from the DQ since this next line will be better than it for all x\<pre[i].
* Finally, note that maintaining DQ takes at most 2*(2T) deque operations since the line corresponding to each point is added/removes at most once.
* Also, on average querying DQ to find the min(DP[j][k-1] - j\*pre[i]) is O(1).

Using this structure we can compute DP[i,k] in O(1) time. <br />
Let: <br />
m = slope of optimal line (note that the slope of a line is -j) <br />
b = y-intercept of optimal line (note that this is DP[j,k-1])

Then we can calculate DP[i,k]: <br />
DP[i,k] = pre[i]\*i + min(DP[j,k-1] - j\*pre[i]) <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
= pre[i]\*i + pre[i]\*m + b; <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
= pre[i]\*(i+m) + b; <br />

Finally, the answer will just be the minimum of DP[i,G] for all 0\<=i\<2*T <br />
Where G is the number of gondolas availabe