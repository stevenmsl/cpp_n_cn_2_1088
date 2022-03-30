#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol1088
{
  class Solution
  {
    static void count(int N, int cur, unordered_map<int, int> &map, int &total);
    static bool isCN(int N, unordered_map<int, int> &map);

  public:
    static int countCN(int N);
  };
}
#endif