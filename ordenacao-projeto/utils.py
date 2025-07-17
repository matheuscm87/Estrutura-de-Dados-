import time

def ler_arquivo_caminho(caminho):
    with open(caminho, 'r') as f:
        return list(map(int, f.readlines()))

def medir_tempo(funcao, arr):
    inicio = time.time()
    funcao(arr)
    fim = time.time()
    return fim - inicio
