#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){

    int input;
    std::vector<int> x;
    std::string line;
    getline(std::cin, line);
    std::stringstream iss(line);

    while (iss >> input)
        x.push_back(input);

    int max_so_far = 0;
    int max_here = 0;

    for (std::size_t i = 0; i < x.size(); ++i) x[i] = -x[i];

    for (std::size_t i = 0; i < x.size(); ++i) {
        max_here = std::max(max_here + x[i], 0);
        max_so_far = std::max(max_so_far, max_here);
    }

    int min_so_far = -max_so_far;

        cout << min_so_far << endl;
    }