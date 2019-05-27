#include "getdata.hpp"

tspdata getdata(std::string const path)
{
  std::string line;
  std::ifstream myfile;
  std::vector<std::string> split; // splits
  tspdata data;
  myfile.open(path);

  if (myfile.is_open())
  {
    //reading first line
    getline(myfile, line);

    //splitting
    boost::split(split, line, [](char c) { return c == ' '; });
    //assign int n
    data.n = stoi(split[0]);

    //reading the other lines
    while (getline(myfile, line))
    {
      //splitting
      boost::split(split, line, [](char c) { return c == ' '; });
      //double x, y
      data.x.push_back(stod(split[0]));
      data.y.push_back(stod(split[1]));
    }
    myfile.close();
  }
  else
  {
    std::cout << "Unable to open file: " << path << std::endl;
  }
  return data;
}