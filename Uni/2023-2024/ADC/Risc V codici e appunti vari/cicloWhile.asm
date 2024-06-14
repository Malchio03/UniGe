#s0 = pow, s1 = x
.text
addi s0, zero, 1	#int pow = 1
add s1, zero, zero	#int x = 0

addi t0, zero, 128	# t0 = 128

while: 
	beq s0, t0, done
	slli s0, s0, 1
	addi s1, s1, 1
	j while

done: 
