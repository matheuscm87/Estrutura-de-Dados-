from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro: Tabuleiro, tipo: int):
        super().__init__(tabuleiro, tipo)

    def contar_pieces(self, seq, jogador):
        return sum(1 for x in seq if x == jogador)

    def contar_vazios(self, seq):
        return sum(1 for x in seq if x == Tabuleiro.DESCONHECIDO)

    def getJogada(self):
       
        jogada = self.tentar_completar_sequencia(self.tipo)
        if jogada:
            return jogada
        
        jogada = self.tentar_completar_sequencia(self.tabuleiro.get_opponent(self.tipo))
        if jogada:
            return jogada

        jogada = self.jogada_cria_duas_sequencias()
        if jogada:
            return jogada

        if self.tabuleiro.is_empty(1, 1):
            return (1, 1)

        jogada = self.jogar_canto_oposto()
        if jogada:
            return jogada

        for canto in [(0,0),(0,2),(2,0),(2,2)]:
            if self.tabuleiro.is_empty(*canto):
                return canto

        for l in range(3):
            for c in range(3):
                if self.tabuleiro.is_empty(l,c):
                    return (l,c)

        return None

    def tentar_completar_sequencia(self, jogador):
        for l in range(3):
            linha = self.tabuleiro.matriz[l]
            if self.contar_pieces(linha, jogador) == 2 and self.contar_vazios(linha) == 1:
                c = linha.index(Tabuleiro.DESCONHECIDO)
                return (l,c)

            coluna = [self.tabuleiro.matriz[r][l] for r in range(3)]
            if self.contar_pieces(coluna, jogador) == 2 and self.contar_vazios(coluna) == 1:
                r = coluna.index(Tabuleiro.DESCONHECIDO)
                return (r, l)

        diag1 = [self.tabuleiro.matriz[i][i] for i in range(3)]
        if self.contar_pieces(diag1, jogador) == 2 and self.contar_vazios(diag1) == 1:
            i = diag1.index(Tabuleiro.DESCONHECIDO)
            return (i,i)

        diag2 = [self.tabuleiro.matriz[i][2 - i] for i in range(3)]
        if self.contar_pieces(diag2, jogador) == 2 and self.contar_vazios(diag2) == 1:
            i = diag2.index(Tabuleiro.DESCONHECIDO)
            return (i, 2 - i)

        return None

    def jogada_cria_duas_sequencias(self):
        possiveis = [(l,c) for l in range(3) for c in range(3) if self.tabuleiro.is_empty(l,c)]

        for jogada in possiveis:
            l, c = jogada
            self.tabuleiro.matriz[l][c] = self.tipo

            count = self.conta_duas_em_linha(self.tipo)

            self.tabuleiro.matriz[l][c] = Tabuleiro.DESCONHECIDO

            if count >= 2:
                return jogada

        return None

    def conta_duas_em_linha(self, jogador):
        count = 0
        for l in range(3):
            linha = self.tabuleiro.matriz[l]
            if self.contar_pieces(linha, jogador) == 2 and self.contar_vazios(linha) == 1:
                count += 1

            coluna = [self.tabuleiro.matriz[r][l] for r in range(3)]
            if self.contar_pieces(coluna, jogador) == 2 and self.contar_vazios(coluna) == 1:
                count += 1

        diag1 = [self.tabuleiro.matriz[i][i] for i in range(3)]
        if self.contar_pieces(diag1, jogador) == 2 and self.contar_vazios(diag1) == 1:
            count += 1

        diag2 = [self.tabuleiro.matriz[i][2 - i] for i in range(3)]
        if self.contar_pieces(diag2, jogador) == 2 and self.contar_vazios(diag2) == 1:
            count += 1

        return count

    def jogar_canto_oposto(self):
        oponente = self.tabuleiro.get_opponent(self.tipo)
        cantos = [(0,0),(0,2),(2,0),(2,2)]
        opostos = {(0,0):(2,2), (0,2):(2,0), (2,0):(0,2), (2,2):(0,0)}
        for canto in cantos:
            if self.tabuleiro.matriz[canto[0]][canto[1]] == oponente:
                canto_oposto = opostos[canto]
                if self.tabuleiro.is_empty(*canto_oposto):
                    return canto_oposto
        return None
