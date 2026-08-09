#!/bin/bash

# Se è stato passato un argomento, usalo come quantità
if [ -n "$1" ]; then
    quantita=$1
# Altrimenti chiedi la quantità all'utente
else
    read -p "Quanti numeri vuoi generare? " quantita
fi

# Esegui lo script Python e salva l'output in una variabile
ARG=$(python3 random_generator.py <<< "$quantita")

# Rimuove eventuali virgolette attorno
ARG="${ARG//\'/}"

# Stampa i numeri generati (opzionale)
echo -e "\nNumeri generati: $ARG"

# Esegui push_swap e cattura il numero di operazioni
num_ops=$(../push_swap $ARG | wc -l)

# Controlla i limiti solo per 100 e 500 numeri
if [ "$quantita" -eq 100 ]; then
    if [ "$num_ops" -lt 700 ]; then
        echo -e "\nComandi: \e[1;32m$num_ops\e[0m"  # verde grassetto
    else
        echo -e "\nComandi: \e[1;31m$num_ops\e[0m"  # rosso grassetto
    fi
elif [ "$quantita" -eq 500 ]; then
    if [ "$num_ops" -lt 5500 ]; then
        echo -e "\nComandi: \e[1;32m$num_ops\e[0m"  # verde grassetto
    else
        echo -e "\nComandi: \e[1;31m$num_ops\e[0m"  # rosso grassetto
    fi
else
    # Per tutte le altre quantità, stampa solo grassetto
    echo -e "\nComandi: \e[1m$num_ops\e[0m"
fi

# Esegui checker e cattura l'output
output=$(../push_swap $ARG | ./checker_linux $ARG)

# Colora e mette in grassetto l'output
if [ "$output" = "OK" ]; then
    echo -e "\nEsito: \e[1;32m$output\e[0m\n"  # verde grassetto
elif [ "$output" = "KO" ]; then
    echo -e "\nEsito: \e[1;31m$output\e[0m\n"  # rosso grassetto
else
    echo "\nEsito: $output\n"
fi
