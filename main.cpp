#include <iostream>
#include "getdata.hpp"
#include "util.hpp"
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
  auto data = getdata(argv[1]);
  TSP tsp(data.x, data.y);
  vector<size_t> v(data.n + 1);
  size_t n = data.n + 1;
  v[0] = 0;

  for (size_t i = 1; i < n - 1; i++)
  {
    v[i] = i;
  }
  v[n - 1] = 0;

  auto cost = tsp.cdist(v);
  auto res = tsp.run2opt(v, cost);
  result best = res;

  for (int n = 0; n < 1100; n++)
  {
    random_shuffle(v.begin() + 5, v.end() - 1);
    res = tsp.run2opt(v, cost);
    if (res.cost < best.cost)
    {
      v = res.path;
      best = res;
    };
  }

  cout << best.cost << ' ' << 0 << endl;
  for_each(best.path.begin(), best.path.end() - 1, [](size_t a) -> void { cout << ' ' << a; });
  cout << endl;
  return 0;
};