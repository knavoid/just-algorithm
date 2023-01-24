def solution(clothes):
    answer = 1
    clothes_type = {}
    for c in clothes:
        if c[1] in clothes_type:
            clothes_type[c[1]] += 1
        else:
            clothes_type[c[1]] = 1
    for n in clothes_type.values():
        print(n)
        answer *= (n + 1)
    return answer - 1
