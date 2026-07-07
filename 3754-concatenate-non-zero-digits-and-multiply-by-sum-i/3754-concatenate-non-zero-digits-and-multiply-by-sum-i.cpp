class Solution {
public:
    long long sumAndMultiply(int n) {

        int p = 1;
        int x = 0;
        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            sum += digit;

            if (digit != 0) {
                x += digit * p;
                p *= 10;
            }

            n /= 10;
        }

        return 1LL * x * sum;
    }
};