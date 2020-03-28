# greedey search
import copy
from itertools import combinations

B = [list(map(int, input().split())) for _ in range(2)]
C = [list(map(int, input().split())) for _ in range(3)]

class Board():
    def __init__(self):
        self.N = 3
        # True for first player, False for second player, None for no card
        self.board = [[None for _ in range(3)] for _ in range(3)]
        self.turn = True  # True if next turn is for first player
        self.cands = set()
        for i in range(self.N):
            for j in range(self.N):
                self.cands.add((i, j))

    def copy(self):
        return copy.deepcopy(self)

    def evaluate(self):
        score1, score2 = 0, 0
        for i in range(self.N - 1):
            for j in range(self.N):
                if self.board[i][j] == self.board[i + 1][j]:
                    score1 += B[i][j]
                else:
                    score2 += B[i][j]

        for i in range(self.N):
            for j in range(self.N - 1):
                if self.board[i][j] == self.board[i][j + 1]:
                    score1 += C[i][j]
                else:
                    score2 += C[i][j]
        return (score1, score2)

    def move(self, pos):
        board = self.copy()
        i, j = pos
        if board.turn:
            board.board[i][j] = True
        else:
            board.board[i][j] = False
        board.turn = not board.turn
        board.cands.remove((i, j))
        return board

def search(board):
    if len(board.cands) == 0:
        return board.evaluate()
    else:
        scores = []
        for c in board.cands:
            new_board = board.move(c)
            scores.append(search(new_board))

        if board.turn:
            score = sorted(scores, key=lambda v: v[0], reverse=True)[0]
        else:
            score = sorted(scores, key=lambda v: v[1], reverse=True)[0]
        # print(len(board.cands), board.turn, score)
        return score


board = Board()
# board.board = [[False, True, False], [True, True, False], [True, False, True]]
# board.cands = []
print(search(board))
