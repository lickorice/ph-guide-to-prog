def factorial(n):
    if (n == 1): return 1
    return n * factorial(n-1)


def solve(test_cases):
    if (test_cases == 0): return
    n = int(input())
    print(factorial(n))
    solve(test_cases-1)


def main():
    test_cases = int(input())
    solve(test_cases)


# Expected:
# 1
# 720 -> 6 * 5 * 4 * 3 * 2 * 1
# 5040

if __name__ == "__main__":
    main()