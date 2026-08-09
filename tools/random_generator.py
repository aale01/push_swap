import random

# Chiede all'utente quanti numeri generare
quantita = int(input())

# Crea la lista dei numeri da 1 a quantita
numeri = list(range(1, quantita + 1))

# Mescola in ordine casuale
random.shuffle(numeri)

# Stampa i numeri separati da spazi
print(" ".join(map(str, numeri)))

