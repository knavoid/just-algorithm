def solution(enroll, referral, seller, amount):
    result = [0] * len(enroll)
    idx = {e: i for i, e in enumerate(enroll)}
    for s, a in zip(seller, amount):
        money = a * 100
        while s != "-" and money > 0:
            result[idx[s]] += (money - money // 10)
            money = money // 10
            s = referral[idx[s]]
    return result
