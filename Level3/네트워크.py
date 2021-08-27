def network(now, n, computers, visited):
    visited[now] = 1
    for i in range(n):
        if computers[now][i] == 1 and visited[i] == 0:
            visited[i] = 1
            network(i, n, computers, visited)


def solution(n, computers):
    answer = 0
    visited = [0] * n
    for i in range(n):
        if visited[i] == 0:
            network(i, n, computers, visited)
            answer += 1
    return answer
