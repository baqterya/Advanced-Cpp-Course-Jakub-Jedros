#include <iostream>

using namespace std;

template <typename T>
constexpr double hcubeVol(const T &a, const unsigned int &n) {

    if (a >= 0) {
        if (a == 0 || n == 0)
        {
            return 0;
        }

        int vol = a;

        for (unsigned int i = 0; i < n; i++)
        {
            vol *= a;
        }
        
        return vol;
    }
    else {
        return -1;
    }
    
    
}


int main() {

    cout << "Dla hiperszecianu o a = 5 i 5 wymiarach: \n";
    cout << hcubeVol(5, 5) << endl;

    return 0;
}
