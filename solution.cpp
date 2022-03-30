#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol1088;
using namespace std;

/*takeaways
  - to qualify as a CN candidate, the digits of the number
    must all come from 0,1,6,8,9
  - let's use 20 as an example
    - it has two digits
    - 1 digit number candidates
      - formula:  0x10 + (0,9,8,6,1)
      0 -> (9,8,6,1) only (6,9) are CNs
    - 2 digit number candidates
      - formula: (9,8,6,1)x10 + (9,8,6,1,0)
      - rule out using 0 when producing the 2 digit number
        candidates as it will produce instead the same 1
        digit numbers again
      - 1 ->(19,18,16,11,10) only (19,18,16,10) are CNs
      - 6 (x) it will generate numbers larger than 20
      - 8 (x) same reason not to proceed
      - 9 (x) some reason not tp proceed
*/

void Solution::count(int N, int cur, unordered_map<int, int> &map, int &total)
{
  if (isCN(cur, map))
    total++;
  for (auto r : map)
  {
    auto next = cur * 10 + r.first;
    /* make sure the edge cases include next > 0
       or it will become an infinite recursion
    */
    if (next <= N && next > 0)
      count(N, next, map, total);
  }
}

/*check cpp_n_cn_1056 for more info */
bool Solution::isCN(int N, unordered_map<int, int> &map)
{
  auto before = N, after = 0;
  while (N > 0)
  {
    /* return false if any of the digit can't be rotated */
    if (!map.count(N % 10))
      return false;

    /* construct the number backwards */
    after = after * 10 + map[N % 10];
    N /= 10;
  }

  return before != after;
}

int Solution::countCN(int N)
{
  int total = 0;
  auto map = unordered_map<int, int>{{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

  count(N, 0, map, total);

  return total;
}