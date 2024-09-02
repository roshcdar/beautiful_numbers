#include <iostream>
#include <vector>

int main() {
    // Max sum of digits in 6-digit number in 13-based system
    const int MAX_SUM = 108;

    // Create a vector to store the number of ways to achieve each sum
    std::vector<int> sum_count(MAX_SUM + 1, 0);

    // Iterate over all 6-digit numbers in base 13
    int max_six_digit_value = 4826808;
    for (int i = 0; i <= max_six_digit_value; ++i) {
        int sum = 0, num = i;

        // Calculate the sum of the digits in base 13
        for (int j = 0; j < 6; ++j) {
            sum += num % 13;
            num /= 13;
        }

        ++sum_count[sum];
    }

    // Calculate the total number of beautiful numbers
    long long beautiful_count = 0;
    for (int i = 0; i <= MAX_SUM; ++i) {
        beautiful_count += static_cast<long long>(sum_count[i]) * sum_count[i] * 13;
    }

    std::cout << beautiful_count << std::endl;

    return 0;
}