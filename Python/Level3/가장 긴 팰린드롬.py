def solution(s):
    max_length = 1
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            begin, end, length = i - 1, i + 2, 2
            while begin in range(len(s)) and end in range(len(s)):
                if s[begin] != s[end]:
                    break
                begin, end, length = begin - 1, end + 1, length + 2
            max_length = max(max_length, length)
        if i > 0 and s[i - 1] == s[i + 1]:
            begin, end, length = i - 2, i + 2, 3
            while begin in range(len(s)) and end in range(len(s)):
                if s[begin] != s[end]:
                    break
                begin, end, length = begin - 1, end + 1, length + 2
            max_length = max(max_length, length)
    return max_length
