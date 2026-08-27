============================================================
PROBLEM 30: BEST TIME TO BUY AND SELL STOCK
============================================================

PROBLEM:

Given an array where:

    prices[i] = stock price on day i

You can:

    Buy ONCE
    Sell ONCE

The selling day MUST come after the buying day.

Return the maximum possible profit.

If no profit is possible, return 0.


Example:

prices = [7,1,5,3,6,4]

Best transaction:

    Buy  at 1
    Sell at 6

Profit:

    6 - 1 = 5

Answer:

    5


------------------------------------------------------------
APPROACH 1: BRUTE FORCE
------------------------------------------------------------

Try every possible buying day and every possible selling
day after it.

    i = buying day
    j = selling day

Calculate:

    profit = prices[j] - prices[i]

Keep the maximum profit.


CODE:

int maxProfit(vector<int>& prices) {

    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {

        for (int j = i + 1; j < prices.size(); j++) {

            int profit = prices[j] - prices[i];

            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}


TIME:

    O(N²)

Because we check every possible pair of days.


SPACE:

    O(1)


------------------------------------------------------------
OPTIMAL APPROACH
------------------------------------------------------------

We don't actually need to check every previous buying day.

At every selling day, we only care about:

    CHEAPEST PRICE SEEN BEFORE TODAY


Then:

    today's profit =
        today's price - cheapest price


Maintain two things:

    buy
    maxProfit


------------------------------------------------------------
TWO POINTER INTUITION
------------------------------------------------------------

Start:

    buy  = 0
    sell = 1


For every sell position:

    If prices[sell] > prices[buy]:

        We can make a profit.

        profit =
            prices[sell] - prices[buy]

        update maxProfit.


    If prices[sell] < prices[buy]:

        Today's price is cheaper.

        Therefore:

            buy = sell


Then:

    sell++


------------------------------------------------------------
WHY CAN WE MOVE BUY?
------------------------------------------------------------

Example:

    buy = 7

Current price:

    1


If we buy at 7 and later sell:

    profit = futurePrice - 7


If instead we buy at 1:

    profit = futurePrice - 1


Buying at 1 will ALWAYS be better for every future
selling price.

Therefore:

    buy = current day


This is the key insight.


------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

prices:

    [7,1,5,3,6,4]


Initially:

    buy  = 7
    sell = 1


1 < 7

Today's price is cheaper.

Move:

    buy = 1


Now:

    buy = 1
    sell = 5

Profit:

    5 - 1 = 4

maxProfit:

    4


Next:

    sell = 3

Profit:

    3 - 1 = 2

maxProfit:

    4


Next:

    sell = 6

Profit:

    6 - 1 = 5

maxProfit:

    5


Next:

    sell = 4

Profit:

    4 - 1 = 3

Final answer:

    5


------------------------------------------------------------
OPTIMAL CODE
------------------------------------------------------------

int maxProfit(vector<int>& prices) {

    int buy = 0;
    int sell = 1;
    int maxProfit = 0;

    while (sell < prices.size()) {

        if (prices[sell] > prices[buy]) {

            int profit = prices[sell] - prices[buy];

            maxProfit = max(maxProfit, profit);
        }
        else {

            buy = sell;
        }

        sell++;
    }

    return maxProfit;
}


------------------------------------------------------------
ANOTHER WAY TO THINK ABOUT IT
------------------------------------------------------------

Instead of:

    "Try every buying price"

think:

    "What is the cheapest price I've seen so far?"


Then every day:

    current price
        -
    cheapest previous price

        ↓

    possible profit


------------------------------------------------------------
EDGE CASE: NO PROFIT
------------------------------------------------------------

prices:

    [7,6,4,3,1]


Every new price is cheaper.

Therefore buy keeps moving:

    7 → 6 → 4 → 3 → 1

No profitable selling opportunity exists.

Answer:

    0


------------------------------------------------------------
EDGE CASE: ALWAYS INCREASING
------------------------------------------------------------

prices:

    [1,2,3,4,5]

Buy:

    1

Sell:

    5

Profit:

    5 - 1 = 4


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Brute force:

    O(N²)


Optimal:

    O(N)


Because we traverse the array only once.


SPACE COMPLEXITY:

    O(1)

Only a few variables are maintained.


------------------------------------------------------------
BRUTE FORCE vs OPTIMAL
------------------------------------------------------------

BRUTE FORCE:

    Check every buy/sell pair.

    Time:  O(N²)
    Space: O(1)


OPTIMAL:

    Maintain cheapest buying price and calculate
    profit for every future selling price.

    Time:  O(N)
    Space: O(1)


------------------------------------------------------------
KEY INTERVIEW TAKEAWAY
------------------------------------------------------------

For every selling day:

    profit = currentPrice - cheapestPriceSeenSoFar


If today's price is cheaper:

    update the buying position.


IMPORTANT:

    BUY must happen before SELL.


============================================================