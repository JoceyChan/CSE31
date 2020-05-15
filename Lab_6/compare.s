	.data
n:      .word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"
user: .asciiz "Enter an integer:\n"

.text

	addi $v0, $0, 4
	la $a0, user
	syscall
	
	addi $v0, $0, 5
	syscall
	
	add $s0, $0, $v0
	
	lw $t0, n 
	slt $t1 $s0, $t0
	beq $t1, 1, gotoLess
	beq $s0, $t0, gotoGEqual
	
	addi $v0, $0, 4
	la $a0, str3
	syscall
	
end:
	addi $v0, $0, 10
	syscall
	
gotoLess:
	beq $s0, $t0, gotoLEqual
	addi $v0, $0, 4
	la $a0, str1
	syscall
	j end

gotoGEqual:
	addi $v0, $0, 4
	la $a0, str2
	syscall
	j end
	
gotoLEqual:
	addi $v0, $0 4
	la $a0, str4
	syscall 
	j end
