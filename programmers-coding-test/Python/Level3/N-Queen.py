points = []


def is_possible(point):
    pr1, pc1 = point[0], point[1]
    for p in points:
        pr2, pc2 = p[0], p[1]
        if pc1 == pc2:
            return False
        if abs(pr1 - pr2) == abs(pc1 - pc2):
            return False
    return True


def n_queen(row, n):
    result = 0
    if row == n:
        return 1
    for col in range(n):
        point = (row, col)
        if is_possible(point):
            points.append(point)
            result += n_queen(row + 1, n)
            points.pop()
    return result

    
def solution(n):
    return n_queen(0, n)
