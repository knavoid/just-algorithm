def get_distance(loc1, loc2):
    return abs(loc1[0] - loc2[0]) + abs(loc1[1] - loc2[1])


def solution(numbers, hand):
    answer = ''
    key_loc = [(3, 1), (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
    left_loc, right_loc = (3, 0), (3, 2)

    for number in numbers:
        if number in [1, 4, 7]:
            left_loc = key_loc[number]
            answer += 'L'
        if number in [3, 6, 9]:
            right_loc = key_loc[number]
            answer += 'R'
        if number in [2, 5, 8, 0]:
            left_dist = get_distance(left_loc, key_loc[number])
            right_dist = get_distance(right_loc, key_loc[number])
            if left_dist < right_dist or left_dist == right_dist and hand == 'left':
                left_loc = key_loc[number]
                answer += 'L'
            else:
                right_loc = key_loc[number]
                answer += 'R'
    return answer
