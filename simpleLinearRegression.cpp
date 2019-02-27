#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    double n = argc - 1;
    double ninv = 1/n;

    double x = 0;
    for (int i = 1; i<argc; i+=1) {
        x += (i*ninv);
    }

//Calculate the mean
    double ybar = 0;
    double xbar = x/n;
    for (int i = 1; argv[i]; i++) {
        ybar += atof(argv[i]) / n;
    }

//Calculate B1 numerator and denominator
    double b1num = 0;
    double b1den = 0;
    for (int i = 1; argv[i]; i++) {
        b1num += ((i*ninv) - xbar)*(atof(argv[i]) - ybar);
        b1den += ((i*ninv) - xbar)*(i/n - xbar);
    }

    cout << setprecision(8) << ybar - (b1num / b1den) * xbar << " " << b1num / b1den << endl;

}

