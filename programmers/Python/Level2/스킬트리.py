def correct_sequence(skill, tree):
    result = ""
    for c in tree:
        if c in skill:
            result += c
    return result == skill[:len(result)]


def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        if correct_sequence(skill, skill_tree):
            answer += 1
    return answer
