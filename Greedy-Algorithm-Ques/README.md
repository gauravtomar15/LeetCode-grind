### **N meetings in one room**

You are given timings of **n** meetings in the form of **(start[i], end[i])** where start[i] ****is the start time of meeting **i** and end[i] ****is the finish time of meeting **i.** Return the **maximum** number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time.

**Note:** The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Input:start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output:4
Explanation:Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)



.


### **Shop in Candy Store**

Difficulty: **Easy**Accuracy: **45.43%**Submissions: **103K+**Points: **2**

In a candy store, there are different types of candies available and **prices[i]** represent the price of  **ith** types of candies. You are now provided with an attractive offer.For every candy you buy from the store, you can get up to **k** other different candies for free. Find the **minimum** and **maximum** amount of money needed to buy all the candies.**Note:** In both cases, you must take the maximum number of free candies possible during each purchase.

**Examples :**

Input:prices[] = [3, 2, 1, 4], k = 2
Output:[3, 7]
Explanation:As according to the offer if you buy one candy you can take at most k more for free. So in the first case, you buy the candy worth 1 and takes candies worth 3 and 4 for free, also you need to buy candy worth 2. So min cost: 1+2 = 3. In the second case, you can buy the candy worth 4 and takes candies worth 1 and 2 for free, also you need to buy candy worth 3. So max cost: 3+4 = 7.



### **Reverse Words**

Given a string **`s`**, **reverse** the string without reversing its **individual words**. Words are separated by **dots(.)**.

**Note:** The string may contain leading or trailing dots(.) or multiple dots(.) between two words. The returned string should only have a single dot(.) separating the words, and **no extra dots** should be included.

**Examples :**
### **Reverse Words**

Given a string **`s`**, **reverse** the string without reversing its **individual words**. Words are separated by **dots(.)**.

**Note:** The string may contain leading or trailing dots(.) or multiple dots(.) between two words. The returned string should only have a single dot(.) separating the words, and **no extra dots** should be included.

**Examples :**



### **Chocolate Distribution Problem**

Difficulty: **Easy**Accuracy: **49.91%**Submissions: **267K+**Points: **2**Average Time: **15m**

Given an array **arr[]** of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are **m** students, the task is to distribute chocolate packets among **m** students such that -      i. Each student gets **exactly** one packet.     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

**Examples:**

Input:arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output:6
Explanation:The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].


### **Fractional Knapsack**

Difficulty: **Medium**Accuracy: **32.46%**Submissions: **380K+**Points: **4**Average Time: **20m**

Given two arrays, **val[]** and **wt[]** , representing the values and weights of items, and an integer **capacity** representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into **fractions** if necessary.

Return the **maximum** value as a double, rounded to 6 decimal places.

**Examples :**
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output:240.000000
Explanation:By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
