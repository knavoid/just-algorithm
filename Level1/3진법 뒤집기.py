def solution(n):
    n3, i = 0, 0
    while n:
        n3 = n3 * 10 + (n % 3)
        n //= 3
    while n3:
        n += pow(3, i) * (n3 % 10)
        n3 //= 10
        i += 1
    return n
