#include <iostream>

using namespace std;

template <typename T>
constexpr double hcubeVol(const T &a, const unsigned int &n) {

    if (a >= 0 && n >= 0) {
        if (a == 0 || n == 0)
        {
            return 0;
        }

        int vol = a;

        for (unsigned int i = 1; i < n; i++)
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

// PB: Sprawdzenie czy liczy się w czasie kompilacji
static_assert(hcubeVol(5, 5) == 3125);

    cout << "Dla hiperszecianu o a = 5 i 5 wymiarach: \n";
    cout << hcubeVol(5, 5) << endl;

    return 0;
}
