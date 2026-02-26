#include <iostream>
#include "local.h"

int main() {
    setlocale(LC_ALL, "Ru");
    int nums[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    if (n < k || k <= 0) {
        return 1;
    }

    LocalExtremums window(k);

    for (int i = 0; i < n; i++) {
        window.add(nums, i);
        window.removeOld(i);

        if (i >= k - 1) {
            int windowStart = i - k + 1;
            int currentMin = window.getMin(nums);
            int currentMax = window.getMax(nums);

            std::cout << windowStart << "-" << i << ": "
                << currentMin << " " << currentMax << std::endl;
        }
    }

    return 0;
}