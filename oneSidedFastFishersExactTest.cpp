#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

double logHypergeometricProb(double* logFacs, int a, int b, int c, int d);
void initLogFacs(double* logFacs, int n);
int main(int argc, char** argv) {
    if ( argc != 5 ) {
        std::cerr << "Usage: fullFastFishersExactTest [#row1col1] [#row1col2] [#row2col1] [#row2col2]" << std::endl;
        return -1;
    }
    int a = atof(argv[1]), b = atof(argv[2]), c = atof(argv[3]), d = atof(argv[4]);
    int n = a + b + c + d;
    double* logFacs = new double[n+1]; // dynamically allocate memory
    initLogFacs(logFacs, n);
    double logpCutoff = logHypergeometricProb(logFacs, a,b,c,d);
    double pTwoSidedFraction = 0;
    double pLessFraction = 0;
    double pGreaterFraction = 0;
    for(int x=0; x <= n; ++x) { // among all possible x
        if ( a+b-x >= 0 && a+c-x >= 0 && d-a+x >=0 ) { // consider valid x
            double l = logHypergeometricProb(logFacs,x,a+b-x,a+c-x,d-a+x);
            double f = exp(l - logpCutoff);
            if ( l <= logpCutoff ) pTwoSidedFraction += f;
            if ( x <= a ) pLessFraction += f;
            if ( x >= a ) pGreaterFraction += f;
        }
    }
    double logpLess = logpCutoff + log(pLessFraction);
    if (exp(logpLess) < 0.5) {
        std::cout << "significant" << endl;
    }
    else {
        std::cout << "not significant" << endl;
    }
    return 0;
}
void initLogFacs(double* logFacs, int n) {
    logFacs[0] = 0;
    for(int i=1; i < n+1; ++i) {
        logFacs[i] = logFacs[i-1] + log((double)i);
    }
}
double logHypergeometricProb(double* logFacs, int a, int b, int c, int d) {
    return logFacs[a+b] + logFacs[c+d] + logFacs[a+c] + logFacs[b+d] - logFacs[a] - logFacs[b] - logFacs[c]
           - logFacs[d] - logFacs[a+b+c+d];
}

if (input_pval.back() > (p_val / m) * q) {
cerr << "0" << endl;
return 0;

} else {