import os
from sort_algorithms import selection_sort, insertion_sort
from utils import ler_arquivo_caminho, medir_tempo

pasta_entrada = "instancias-num"
pasta_saida = "saídas" 

os.makedirs(pasta_saida, exist_ok=True)

arquivos = sorted(os.listdir(pasta_entrada))

print("Arquivos disponíveis:")
for i, nome in enumerate(arquivos):
    print(f"{i+1}. {nome}")

escolha = input("\nDigite o nome completo de um dos arquivos acima que deseja testar: ").strip()
caminho = os.path.join(pasta_entrada, escolha)

if not os.path.isfile(caminho):
    print("Arquivo não encontrado. Verifique o nome do arquivo.")
    exit(1)

dados_originais = ler_arquivo_caminho(caminho)

print(f"\nExecutando algoritmos no arquivo '{escolha}'...\n")

dados_sel = dados_originais.copy()
tempo_sel = medir_tempo(selection_sort, dados_sel)

dados_ins = dados_originais.copy()
tempo_ins = medir_tempo(insertion_sort, dados_ins)

print("Tempos de execução:")
print(f"  -> SelectionSort: {tempo_sel:.4f} segundos")
print(f"  -> InsertionSort: {tempo_ins:.4f} segundos")

print("\nComparação dos Algoritmos:")

if abs(tempo_sel - tempo_ins) < 1e-6:
    print("  -> Ambos os algoritmos tiveram tempos praticamente iguais")
elif tempo_sel < tempo_ins:
    print("  -> Selection Sort foi mais rápido")
else:
    print("  -> Insertion Sort foi mais rápido")

nome_saida_sel = f"ordenado_selection_{escolha}"
nome_saida_ins = f"ordenado_insertion_{escolha}"

with open(os.path.join(pasta_saida, nome_saida_sel), "w") as f_sel:
    f_sel.writelines(f"{num}\n" for num in dados_sel)

with open(os.path.join(pasta_saida, nome_saida_ins), "w") as f_ins:
    f_ins.writelines(f"{num}\n" for num in dados_ins)

print("\n\n----- Os arquivos ordenados gerados estão na pasta (saídas) -----\n\n")

# COMPILAR PELO TERMINAL USANDO O CÓDIGO: python main.py