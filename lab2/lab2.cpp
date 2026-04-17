#include <iostream>
#include <chrono>

using namespace std;

long long factorial(long long n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

long long tailFactorialProcess(int n, long long arg) {
    if (n <= 1) return arg;
    return tailFactorialProcess(n - 1, arg * n);
}

long long tailFactorial(int n) {
    return tailFactorialProcess(n, 1);
}

long long fibonachi(long long n) {
    if (n <= 1) return n;
    return fibonachi(n - 1) + fibonachi(n - 2);
}

long long tailFibonachiProcess(int n, long long a, long long b) {
    if (n == 0) return a;
    return tailFibonachiProcess(n - 1, b, a + b);
}

long long tailFibonachi(int n) {
    return tailFibonachiProcess(n, 0, 1);
}

long long power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

long long tailPowerProcess(int base, int exp, long long acc) {
    if (exp == 0) return acc;
    return tailPowerProcess(base, exp - 1, acc * base);
}

long long tailPower(int base, int exp) {
    return tailPowerProcess(base, exp, 1);
}

template<typename Func, typename... Args>
double timer(Func f, Args... a) {
    auto start = chrono::high_resolution_clock::now();
    f(a...);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

int main()
{
    int fact_num = 2000;
    auto base1 = timer(factorial, fact_num);
    auto tail1 = timer(tailFactorial, fact_num);
    cout << "base factorial duration: " << base1 << endl;
    cout << "tail factorial duration: " << tail1 << endl;
    cout << "difference: " << tail1 / base1 << " times" << endl;

    int fib_num = 40;
    auto base2 = timer(fibonachi, fib_num);
    auto tail2 = timer(tailFibonachi, fib_num);
    cout << "base fibonachi duration: " << base2 << endl;
    cout << "tail fibonachi duration: " << tail2 << endl;
    cout << "difference: " << tail2 / base2 << " times" << endl;

    int pow_num = 40;
    auto base3 = timer(power, pow_num, 10);
    auto tail3 = timer(tailPower, pow_num, 10);
    cout << "base powering duration: " << base3 << endl;
    cout << "tail powering duration: " << tail3 << endl;
    cout << "difference: " << tail3 / base3 << " times" << endl;
}