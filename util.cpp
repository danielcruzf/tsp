#include "util.hpp"
#include <iostream>

TSP::TSP(std::vector<double> const &x, std::vector<double> const &y)
{
  std::vector<double> d;
  for (int i = 0; i < x.size() - 1; i++)
  {
    for (int j = i + 1; j < x.size(); j++)
    {
      d.push_back(std::hypot(x[i] - x[j], y[i] - y[j]));
    }
    dist.push_back(d);
    d.clear();
  }
}

double TSP::cdist(std::vector<size_t> const &path)
{
  int to, from;
  double a, b, result = 0;
  for (size_t i = 1; i < path.size(); i++)
  {
    from = path[i - 1];
    to = path[i];
    if (from > to)
    {
      std::swap(from, to);
    };
    to -= (from + 1);
    result += dist[from][to];
  }
  return result;
};

void TSP::swap2opt(std::vector<size_t> &path, size_t &i, size_t &k)
{
  std::reverse(path.begin() + i, path.begin() + k);
};

double TSP::change2opt(std::vector<size_t> &path, size_t &i, size_t &k)
{
  double change = cdist({path[i - 1], path[k - 1]}) + cdist({path[i], path[k]}) - cdist({path[i - 1], path[i]}) - cdist({path[k - 1], path[k]});
  return change;
};

result TSP::run2opt(std::vector<size_t> &path, double &cost)
{
  result res;
  double change;
  double minchange;
  size_t mini(0), minj(0), n(path.size());
  std::vector<size_t> newPath = path;
  do
  {
    minchange = 0;
    for (size_t i = 1; i < n - 2; i++)
    {
      for (size_t j = i + 2; j < n; j++)
      {

        change = change2opt(newPath, i, j);
        if (minchange > change)
        {
          minchange = change;
          mini = i;
          minj = j;
        }
      }
    }
    swap2opt(newPath, mini, minj);
  } while (minchange < 0);
  res.cost = cdist(newPath);
  res.path = newPath;
  return res;
}