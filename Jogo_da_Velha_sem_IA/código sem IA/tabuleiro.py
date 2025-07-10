class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1    
    JOGADOR_X = -1   

    def __init__(self):
        self.matriz = [[Tabuleiro.DESCONHECIDO]*3 for _ in range(3)]

    def tem_campeao(self):
        linhas = self.matriz
        colunas = [[self.matriz[r][c] for r in range(3)] for c in range(3)]
        diagonais = [
            [self.matriz[i][i] for i in range(3)],
            [self.matriz[i][2 - i] for i in range(3)]
        ]

        for seq in linhas + colunas + diagonais:
            s = sum(seq)
            if s == 3 * Tabuleiro.JOGADOR_0:
                return Tabuleiro.JOGADOR_0
            elif s == 3 * Tabuleiro.JOGADOR_X:
                return Tabuleiro.JOGADOR_X
        return Tabuleiro.DESCONHECIDO

    def is_empty(self, linha, coluna):
        return self.matriz[linha][coluna] == Tabuleiro.DESCONHECIDO

    def get_opponent(self, jogador):
        if jogador == Tabuleiro.JOGADOR_0:
            return Tabuleiro.JOGADOR_X
        else:
            return Tabuleiro.JOGADOR_0
