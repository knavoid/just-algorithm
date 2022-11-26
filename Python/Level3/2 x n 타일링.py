def solution(n):
    f1, f2 = 1, 1
    for i in range(n - 1):
        f1, f2 = f2, (f1 + f2) % 1000000007
    return f2
