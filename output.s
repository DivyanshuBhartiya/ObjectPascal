.data
	str: .asciiz " Program ended. \n" 
	newLine: .asciiz "\n" 
	scope1: .space 4
	scope2: .space 4
	scope3: .space 4
	scope4: .space 4
	print1 : .asciiz "i2 ="
	print2 : .asciiz "i1 = "
	print3 : .asciiz "i1 = "
	print4 : .asciiz "\n Welcome to a 3 step proc within func within proc program \n"

.text
L0:
P3: 
	sw $ra,-8($sp)
L1:
	li $t0,2
		lw $t3, scope4
	lw $t1, -20($t3)
	mul $t2,$t1,$t0
	sw $t2,-24($sp)
L2:
	lw $t0,-24($sp)
	lw $t3,scope3
	sw $t0,-28($t3)
L3:
	lw $t0,-12($sp)
	sw $t0,scope4
	lw $ra,-8($sp)
	jr $ra
L4:
P2: 
	sw $ra,-8($sp)
L5:
		lw $t3, scope2
	lw $t3, -24($t3)
	sw $t3,-60($sp)
L6:
	sub $sp,$sp,40
	lw $t0,scope4
	sw $t0,-12($sp)
	sw $sp,scope4
	jal P3
	add $sp,$sp,40
L7:
	la $a0,print1
	li $v0, 4 
	syscall 
L8:
		lw $t3, scope3
	lw $t0, -28($t3)
	move $a0, $t0
	li $v0, 1 
	syscall 
L9:
	li $v0,4
	la $a0,newLine
	syscall
L10:
	li $t0,2
		lw $t3, scope3
	lw $t1, -20($t3)
	mul $t2,$t1,$t0
	sw $t2,-36($sp)
L11:
	lw $t0,-36($sp)
	sw $t0,0($sp)
	lw $t3,scope3
	sw $t0,-24($t3)
L12:
	lw $t0,-12($sp)
	sw $t0,scope3
	lw $ra,-8($sp)
	jr $ra
L13:
P1: 
	sw $ra,-8($sp)
L14:
		lw $t3, scope2
	lw $t0, -20($t3)
	lw $t3,scope2
	sw $t0,-24($t3)
L15:
	la $a0,print2
	li $v0, 4 
	syscall 
L16:
		lw $t3, scope2
	lw $t0, -24($t3)
	move $a0, $t0
	li $v0, 1 
	syscall 
L17:
	li $v0,4
	la $a0,newLine
	syscall
L18:
	li $t3,10
	sw $t3,-56($sp)
L19:
	sub $sp,$sp,36
	lw $t0,scope3
	sw $t0,-12($sp)
	sw $sp,scope3
	jal P2
	add $sp,$sp,36
	l.d $f4,-36($sp)
	s.d $f4,-32($sp)
L20:
	lw $t0,-32($sp)
	lw $t3,scope2
	sw $t0,-24($t3)
L21:
	la $a0,print3
	li $v0, 4 
	syscall 
L22:
		lw $t3, scope2
	lw $t0, -24($t3)
	move $a0, $t0
	li $v0, 1 
	syscall 
L23:
	li $v0,4
	la $a0,newLine
	syscall
L24:
	lw $t0,-12($sp)
	sw $t0,scope2
	lw $ra,-8($sp)
	jr $ra
L25:
main: 
	sw $sp,scope1
	sw $ra,-8($sp)
L26:
	la $a0,print4
	li $v0, 4 
	syscall 
L27:
	li $v0,4
	la $a0,newLine
	syscall
L28:
	li $t3,5
	sw $t3,-48($sp)
L29:
	sub $sp,$sp,28
	lw $t0,scope2
	sw $t0,-12($sp)
	sw $sp,scope2
	jal P1
	add $sp,$sp,28
L30:
	li $v0,4
	la $a0,newLine
	syscall
L31:
	li $v0,4
	la $a0,str
	syscall
	li $v0,10
	syscall