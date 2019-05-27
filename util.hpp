
#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>
#include <algorithm>
#include <cmath>

struct result
{
  std::vector<size_t> path;
  double cost;
};

class TSP
{
public:
  std::vector<std::vector<double>> dist;
  TSP(std::vector<double> const &x, std::vector<double> const &y);
  double cdist(std::vector<size_t> const &path);
  result run2opt(std::vector<size_t> &path, double &cost);

private:
  double change2opt(std::vector<size_t> &path, size_t &i, size_t &k);
  void swap2opt(std::vector<size_t> &path, size_t &i, size_t &k);
};

struct tspdata
{
  int n;
  std::vector<double> x;
  std::vector<double> y;
};

#endif