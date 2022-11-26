def solution(n, words):
    word_set = set()
    for i in range(len(words)):
        # 전 단어와 끝말잇기가 되지 않은 경우
        if i > 0 and words[i][0] != words[i - 1][-1]:
            return [i % n + 1, i // n + 1]
        # 중복된 단어를 제시한 경우
        elif words[i] in word_set:
            return [i % n + 1, i // n + 1]
        # 단어를 알맞게 제시한 경우
        else:
            word_set.add(words[i])
    return [0, 0]
