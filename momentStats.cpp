#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    double n = argc-1;

//Calculate the mean
    double mean = 0;
    for (int i=1; argv[i]; i++){
        mean += atof(argv[i])/n;
    }

//Calculate variance
    double s2 = 0;
    for (int i=1; argv[i]; i++){
        s2 += pow((atof(argv[i]) - mean), 2);
    }

//If variance = 0, just print output for mean and var
    if(s2/(n-1) == 0){

        cout << setprecision(8) << mean << endl;
        cout << setprecision(8) << s2/(n-1) << endl;

    } else {

//Compute kurtosis and skewness
        double var = s2/(n-1);
        double s = sqrt(var);
        double skew = 0;
        for (int i = 1; i <= n; i++) {
            skew += pow(((atof(argv[i]) - mean)/s), 3);
        }

        double kurt = 0;
        for (int i = 1; argv[i]; i++) {
            kurt += pow(((atof(argv[i]) - mean)/s), 4);
        }

        cout << setprecision(8) << mean << endl;
        cout << setprecision(8) << var << endl;
        cout << setprecision(8) << skew/n << endl;
        cout << setprecision(8) << (kurt/n)-3 << endl;
    }


    return 0;
}
