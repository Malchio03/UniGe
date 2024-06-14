#include <iostream>
using namespace std;



bool isPalindrome(int n) {
    int numero_OG = n;
    int mod;
    int inv = 0;
    while (n > 0) {
        mod = n % 10;
        n = n / 10;
        inv = inv * 10;
        inv = inv + mod;
    }
    return numero_OG == inv;
}



int main() {
    bool a = isPalindrome(23432);
    bool b = isPalindrome(0);
    bool c = isPalindrome(9);
    bool d = isPalindrome(123);
    bool e = isPalindrome(12);
    cout<< a << b << c << d << e;
}