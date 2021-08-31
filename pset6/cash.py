# Implement a program that calculates the minimum number of coins required to give a user change.
# Input positivo do usuário
dolar = 0
while (dolar <=0):
    dolar = float(input("Change owed: "))

# Dolar -> centavo
centavos = round(dolar * 100)

soma = 0

# Checar cada tipo de moeda
while centavos >= 25:
    soma = soma + 1
    centavos = centavos - 25

while centavos >= 10:
    soma = soma + 1
    centavos = centavos - 10

while centavos >= 5:
    soma = soma + 1
    centavos = centavos - 5

while centavos >= 1:
    soma = soma + 1
    centavos = centavos - 1

# Imprimir total de moedas
print(soma)
