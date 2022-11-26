def solution(n, lost, reserve):
    clothes = [1] * (n + 1)
    for i in lost:
        clothes[i] -= 1
    for i in reserve:
        clothes[i] += 1
    for i in range(1, n + 1):
        if clothes[i] == 2:
            if clothes[i - 1] == 0:
                clothes[i] -= 1
                clothes[i - 1] += 1
            elif i < n:
                if clothes[i + 1] == 0:
                    clothes[i] -= 1
                    clothes[i + 1] += 1
    return n - clothes.count(0)
