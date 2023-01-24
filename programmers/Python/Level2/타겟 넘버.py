def target_number(lev, value, numbers, target):
    count = 0
    if lev == len(numbers):
        if value == target:
            count += 1
        return count
    count += target_number(lev + 1, value + numbers[lev], numbers, target)
    count += target_number(lev + 1, value - numbers[lev], numbers, target)
    return count


def solution(numbers, target):
    return target_number(0, 0, numbers, target)
