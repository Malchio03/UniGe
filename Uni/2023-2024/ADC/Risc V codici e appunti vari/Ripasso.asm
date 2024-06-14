.data

A : .word 1, 2, 3, 4, 5, 6, 7, 8
H : .word 6
G: .word 0

.text

la x22, A
lw t1, 28(x22) #28 perche l'offset parte da 0 in posizione 1 e per arrivare ad 8 mi sposto di 7, moltiplico 7 * 4 perche siamo in word
la x21, H
lw t2, 0(x21)
la x20, G
add t0,t1,t2 #t0 = t1 (8) + t2 (6)
sw t0, 0(x20) #memorizzo il risultato in G

#sw t1, B(x22)
