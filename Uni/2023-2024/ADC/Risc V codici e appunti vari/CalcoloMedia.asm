.data
	A: .word 1,2,3,4,5,6,7,8,9,10,11,12,-1
	acc: .word 0
	i: .word 0
	avg: .word 0

.text
	la s1, A	#indirizzo A
	la s2, acc	#indirizzo acc
	la s3, i	#indirizzo i
	la s4, avg	#indirizzo avg
	
	lw t2, 0(s2)	
	lw t3, 0(s3)
	lw t4, 0(s4)
	
	li t5, 0	#contatore media
	li a1, -1
	li a3, 3
	
	while :
		lw t1, 0(s1)	#indirizzo A[i]
		beq t1, a1, media
		rem t6, t3, a3	# t6 = i % 3
		beq t6, zero, execute	# t6 = 0
		addi t3, t3, 1 		# i++
		sw t3, 0(s3)
		addi s1, s1, 4	# 4 per scorrere l'array in quanto siamo in word	
		j while
		
	execute:
		add t2, t2, t1		# acc += A[i]
		sw t2, 0(s2)
		addi t5, t5, 1 		# contatore media ++
		addi t3, t3, 1		#i++
		sw t3, 0(s3) 
		addi s1, s1, 4
		j while 
	media:
		div t4, t2, t5
		sw t4, 0(s4)
		
	exit:
	
		
		
			