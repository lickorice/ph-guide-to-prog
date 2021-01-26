def factorial(n):
    result = 1
    for i in range(n):
        result *= i+1
    return result


def main():
    test_cases = int(input())
    for _ in range(test_cases):
        n = int(input())
        print(factorial(n))


# Expected:
# 1
# 720 -> 6 * 5 * 4 * 3 * 2 * 1
# 5040

if __name__ == "__main__":
    main()