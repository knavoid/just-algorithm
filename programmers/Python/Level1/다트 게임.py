def solution(dartResult):
    answer = 0
    score = []
    bonus_option = []
    bonus_info = {'S': 1, 'D': 2, 'T': 3}

    begin = 0
    while begin < len(dartResult):
        end = begin
        while dartResult[end].isdigit():
            end += 1
        score.append(int(dartResult[begin:end]))
        begin = end

        while not dartResult[end].isdigit():
            end += 1
            if end == len(dartResult):
                break
        bonus_option.append(dartResult[begin:end])
        begin = end

    for i in range(len(score)):
        bonus = bonus_option[i]
        score[i] **= bonus_info[bonus[0]]
        if len(bonus) == 2:
            if bonus[1] == '*':
                score[i] *= 2
                if i > 0:
                    score[i - 1] *= 2
            if bonus[1] == '#':
                score[i] *= -1

    return sum(score)
