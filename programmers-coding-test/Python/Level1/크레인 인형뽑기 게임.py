def solution(board, moves):
    popped, basket = 0, []
    for m in moves:
        for i in range(len(board)):
            if board[i][m - 1] != 0:
                basket.append(board[i][m - 1])
                if len(basket) > 1 and basket[-1] == basket[-2]:
                    basket.pop()
                    basket.pop()
                    popped += 2
                board[i][m - 1] = 0
                break
    return popped
