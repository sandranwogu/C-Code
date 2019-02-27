#include <iostream>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <climits>

using namespace std;

std::string FloatBin( float value ) {
    union
    {
        float input;   // assumes sizeof(float) == sizeof(int)
        int output;
    }    data;

    data.input = value;

    std::bitset<sizeof(float) * CHAR_BIT>   bits(data.output);

    std::string mystring = bits.to_string<char,
            std::char_traits<char>,
            std::allocator<char> >();

    return mystring;
}

// driver code
int main(int argc, char* argv[]) {
    float input = atof(argv[1]);
    std::string str = FloatBin(input);
    int ind = (double(atof(argv[1])) == double(input)) ? 1 : 0;
    cout << str << endl;
    cout << ind << endl;
}
