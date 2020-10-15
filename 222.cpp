#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    string str;
    bool isFirst = true;
    while (getline(cin, str))
    {
        if (isFirst) {
            isFirst = false;
        }
        else {
            cout << endl;
        }
        istringstream ss(str);
        double sum = 0;
        double num;
        bool isThereInput = false;
        while (ss >> num)
        {
            sum += num;
            isThereInput = true;
        }
        //cout << setprecision(4);
        //cout << fixed << ((abs(sum) < 0.00005) ? 0.0000 : sum) << endl;
        if (isThereInput) {
            printf("%.4f\n", sum);
        }
    }
    return 0;
}