def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        code = str(bin(arr1[i] | arr2[i])[2:])
        code = code.replace('1', '#').replace('0', ' ').rjust(n, ' ')
        answer.append(code)
    return answer
