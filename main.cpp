#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1088;

/*
Input: 20
Output: 6
Explanation:
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.
*/

tuple<int, int>
testFixture1()
{
  return make_tuple(20, 6);
}

/*
Input: 100
Output: 19
Explanation:
The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100].
*/

tuple<int, int>
testFixture2()
{
  return make_tuple(100, 19);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<1>(f) << endl;
  auto result = Solution::countCN(get<0>(f));
  cout << "result: " << result << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << get<1>(f) << endl;
  auto result = Solution::countCN(get<0>(f));
  cout << "result: " << result << endl;
}

main()
{
  test1();
  test2();
  return 0;
}