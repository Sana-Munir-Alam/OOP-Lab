#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {
    double KgWeight = 0.0, PoundsWeight = 0.0;
    cout << "Enter The person weight in kg: ";
    cin >> KgWeight;
    PoundsWeight = KgWeight * 2.2;
    printf("Weight of the Person in kilogram: %.2f\n", KgWeight);
    printf("Weight of the Person in Pounds: %.2f", PoundsWeight);

    return 0;
}
