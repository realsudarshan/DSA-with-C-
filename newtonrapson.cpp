#include <iostream>
#include <iomanip>
#include <cmath>

#define f(x) (x*x*x*x-32) // Define the equation to be solved

using namespace std;

int main() {
    float A, B, C, fA, fB, fC, e;
    int step = 1;

    cout << setprecision(5) << fixed;

    // Input initial guesses and tolerable error
    up:
    cout << "Enter first guess: ";
    cin >> A;
    cout << "Enter second guess: ";
    cin >> B;
    cout << "Enter tolerable error: ";
    cin >> e;

    fA = f(A);
    fB = f(B);

    // Check if initial guesses bracket the root
    if (fA * fB > 0.0) {
        cout << "Incorrect Initial Guesses." << endl;
        goto up;
    }

    cout << endl << "*******" << endl;
    cout << "False Position Method" << endl;
    cout << "*******" << endl;

    do {
        // Apply False Position Method
        C = A - (A - B) * fA / (fA - fB);
        fC = f(C);

        cout << "Iteration-" << step << ":\t C = " << setw(10) << C << " and f(C) = " << setw(10) << fC << endl;

        if (fA * fC < 0) {
            B = C;
            fB = fC;
        } else {
            A = C;
            fA = fC;
        }
        step = step + 1;
    } while (fabs(fC) > e);

    cout << endl << "Root is: " << C << endl;

    return 0;
}