# Implement a program that generates Super Mario style pyramid

altura = 0 
while ((altura > 8) or (altura < 1)):
    # Input do usuário 
    altura = int(input("Height: "))
    

for linha in range(altura):
    # Início da linha
    print((altura - linha - 1) * " ", end="")
    print((linha + 1) * "#", end="  ")
    print((linha + 1) * "#")
    # Fim da linha
