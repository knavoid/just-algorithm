def solution(s):
    s = s.lower()
    answer = ""
    upcase = 1
    for c in s:
        if c == ' ':
            upcase = 0
        elif upcase:
            c = c.upper()
        answer += c
        upcase = 0 if upcase else 1
    return answer
