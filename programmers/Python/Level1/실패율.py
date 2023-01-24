def solution(N, stages):
    failure = {x: 0 for x in range(1, N + 1)}
    stages.sort()
    for lev in range(1, N + 1):
        if lev in stages:
            failure[lev] = stages.count(lev) / (len(stages) - stages.index(lev))
    return sorted(failure, key=lambda x: failure[x], reverse=True)
