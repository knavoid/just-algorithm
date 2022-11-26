def solution(num):
    work = 0
    while num != 1 and work < 500:
        if num % 2 == 0:
            num /= 2
        else:
            num = num * 3 + 1
        work += 1
    return work if work < 500 else -1
