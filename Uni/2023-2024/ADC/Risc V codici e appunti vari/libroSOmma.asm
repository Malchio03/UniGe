.text
addi x19, x19, 2 #f
addi x20, x20, 4 #g
addi x21, x21, 3 #h
addi x22, x22, 35 #i
addi x23, x23, 35 #j

bne x22, x23, Else #
	add x19, x20, x21 
	beq x0, x0, Esci		#return 0

Else: sub x19, x20, x21
Esci:
