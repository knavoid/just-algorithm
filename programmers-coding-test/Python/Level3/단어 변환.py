answer = 51


def similar(s1, s2):
    difference = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            difference += 1
    return difference == 1


def dfs(lev, begin, target, words, used):
    global answer
    if begin == target:
        answer = min(answer, lev)
        return
    for i in range(len(words)):
        word = words[i]
        if similar(begin, word) and used[i] == 0:
            used[i] = 1
            dfs(lev + 1, word, target, words, used)
            used[i] = 0


def solution(begin, target, words):
    used = [0] * len(words)
    dfs(0, begin, target, words, used)
    return answer if answer != 51 else 0
