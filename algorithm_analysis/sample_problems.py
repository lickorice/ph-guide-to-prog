
def some_linear_function(n):
    pass

def some_quadratic_function(n):
    pass

def function_a(n):
    for i in range(n):
        for j in range(n):
            x = 1 + 1
        for j in range(n):
            for k in range(n):
                y = 2 + 2

def function_b(n):
    for i in range(n):
        for j in range(n):
            # This function is O(n):
            some_linear_function(n)

def function_c(n):
    h = 5
    for i in range(n):
        # This function is O(n^2):
        some_quadratic_function(h)