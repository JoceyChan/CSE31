#include<stdio.h>
.text
.global main
main:
	li $s0, 5 #loading 5 to x
	li $s1, 10 #loading 10 to y
	
	move $a0, $s0
	move $a1, $s1
	jal sum
	
	add $s1, $s1, $v0
	add $s1, $s1, $s0
	li $v0, 1
	
	move $a0, $s1
	syscall
	li $v0, 10
	syscall
	
sub: 
	sub $v0, $a1, $a0 
	jr $ra
	
sum:
	addi $sp, $sp, 4
	subu $sp,$sp,4 
	sw $ra,($sp)

	move $t1, $a0 #store m
	move $t2, $a1 #store n
	
	add $a0,$t2,1 #n+1
	add $a1,$t1,1 #m+1
	jal sub
	move $t3,$v0
	
	sub $a0,$t1,1 #get m-1
	sub $a1,$t2,1 #get n-1
	jal sub
	move $t4,$v0
	
	add $v0,$t3,$t4 #return p+q
	lw $ra,($sp) 
	addu $sp,$sp,4 
	addi $sp, $sp, 4
	jr $ra
	





