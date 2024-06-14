.globl main
 
.eqv  DIM 4

.data
V:    .word 0,0,0,0,0,0,0,0,0,0
 
msg1: .string "\nInizio programma"
msg2: .string "\nInserisci un numero in input: "
msg3: .string "\nFine programma"
 
.macro print_str (%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro
 
.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro
 
.macro scan_int
	li a7, 5
	ecall
.end_macro
 
.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro
 
.text
 
main:
 
print_str(msg1)
 
li t1, DIM
li t2, 0
la t3, V
lettura:
bge t2,t1 fine_lettura
print_str(msg2)
scan_int
sw a0, 0(t3) 
addi t3,t3,4
addi t2,t2,1
j lettura
 
fine_lettura:
li t2, 0
la t3, V
li a2, 0
 
elaborazione:
bge t2,t1 fine_elaborazione
 
lw   t0, 0(t3)
add  a2, a2, t0 
addi t3,t3,4
addi t2,t2,1
j elaborazione
 
fine_elaborazione:
 
print_int(a2)
 
print_str(msg3)
 
exit(0)
