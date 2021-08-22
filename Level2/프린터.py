def solution(priorities, location):
    answer = 0
    n = len(priorities)
    while priorities:
        max_pri = max(priorities)
        while priorities[0] != max_pri:
            priorities.append(priorities[0])
            priorities.pop(0)
            location = (location - 1) % n
        if location != 0:
            priorities.pop(0)
            n -= 1
            location -= 1
            answer += 1
        else:
            return answer + 1
    return -1
