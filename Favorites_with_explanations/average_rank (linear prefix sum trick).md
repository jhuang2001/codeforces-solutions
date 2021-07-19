Problem Statement (From NWERC 2019): https://codeforces.com/gym/102500/problem/A 

## Techniques:
* Prefix sum with linear updating

## Key observations:
* Because every person can only get one point in a week, a person's rank increases if and only if someone else with the same number of points earns a point; in this case, that other person would surpass the current person, and their rank increases by 1.
* Furthermore, since a person can never lose points, their rank can decrease only when they earn a point.

### Naive Solution
* This problem is easily solvable by simply updating the ranks of each person, each week and adding up their total ranks in a linear pass.
* Problem: this solution is too slow as it has a time complexity of **O(NW)**
### Trick
* take advantage of the prefix sum's linear growth to only update the psum when needed
  * Consider a person whose rank does not change in **w** weeks -- after **w** weeks, his "rank sum" will simply increase by (**w** * rank).
  * Thus we only need to update this person's rank sum when his rank changes, which can only happen in one of the cases highlighted in **Key Observations**.
    * Note: The problem statement offers a large hint to this as it states: <br /> 
    "***The total number of points awarded is at most 1 million.***"
* Only doing this actually increases our complexity to **O(NP)** where P is the number of points awarded.
* We can reduce this to **O(P)** by keeping track of the prefix rank sum of each point value (the rank sum a person would have if they stayed at some point value for all **W** weeks).
* In this case, each person only needs to update their rank sum when they gain a point, and at the end of the competition.
  * The person would add the following to their sum on an update:
    * (Prefix[Points] - Old_Prefix[Points]) <br />
    Where Prefix[Points] is the current prefix sum of the person's point value <br />
    and Old_Prefix[Points] is the prefix sum of the person's point value when they last updated
  * Finally, we can "pre-emptively" subtract **Old_Prefix** when we do the update a person's rank sum so that we can do all the operations in a single linear pass. That is, we will subtract Prefix[Points + 1] instead of "Old_Prefix" at each update, since Prefix[Points + 1] is the Old_prefix of the next update.
## Putting it all together
* when a person gains a point, we do the following:
  * let **P** be the number of points that person has
  * Update the prefix sums of **P** and **P+1**
    * This is done by adding (rank[Points] * **w**) to Prefix[Points], where **w** is the number of weeks since the Prefix[Points] was last updated.
  * This person then adds to their current rank sum: (Prefix[**P**] - Prefix[**P** + 1])
  * Increment rank[**P**] by 1
* At the end of **W** weeks, update and add Prefix[**P**] to every person's rank sum
* Finally, since the problem statement asks for the average over **W** weeks, divide this rank sum by **W**
