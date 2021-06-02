import time

def slow_sum(k):
    _sum = 0
    for i in range(k): 
        _sum += i+1
    return _sum


def slow_space_sum(k):
    _numbers = []
    for i in range(k):
        _numbers.append(i+1)
    return sum(_numbers)


def fast_sum(k):
    return (k+1) * k//2


def main():
    def run_sum(f, k):
        start_time = time.time()
        f(k)
        end_time = time.time()
        return (end_time - start_time) * 1000

    # for i in range(1000000, 10000000, 1000000):
        # all_runtimes = 0
        # for k in range(10):
        #     all_runtimes += run_sum(fast_sum, i)
        # print(i, all_runtimes/10)
        # # print(i, run_sum(slow_sum, i))
    print(fast_sum(10000000*10000000))


if __name__ == "__main__":
    main()