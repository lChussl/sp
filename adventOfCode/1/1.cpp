#include <bits/stdc++.h>

using namespace std;

int main() {
    int totalCalibration = 0;

    while (1) {
        string input;

        getline(cin, input);

        if (input.empty()) break;

        int lhPointer = 0, lhDigitFound = 0, rhPointer = input.length() - 1, num = 0;

        while (lhPointer <= rhPointer) {
            // Move left hand pointer to keep looking for the digit
            if (!isdigit(input[lhPointer])) lhPointer++;
            else {
                if (!lhDigitFound) {
                    num += input[lhPointer] - '0';
                    num *= 10;
                    lhDigitFound = 1;
                }
            }

            // Move right hand pointer to keep looking for the digit
            if (!isdigit(input[rhPointer])) rhPointer--;
            else {
                // Got both digits, stop looking
                if (num != 0) {
                    num += input[rhPointer] - '0';
                    break;
                }

                // Dont't do anything if num is 0, we need to keep looking for the left hand digit
            }
        }
         
        totalCalibration += num;
    }
    
    cout << totalCalibration << "\n";

    return 0;
}
