#s0 = scores base address, s1 = i

.text
addi s1, zero, 0
addi t2, zero, 200

for:
	bge s1, t2, done
	slli t0, s1, 2
	add t0, t0, s0  # address of scores[i]
	lw t1, 0(t0)	#t1 = scores[i]
	addi t1, t1, 10 
	sw t1, 0(t0)
	addi s1, s1, 1
	j	for
	done: