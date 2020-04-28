        .data
str1: .asciiz "Greater than\n"
str2: .asciiz "Less than or equal to\n"

	.text
	
	addi $s0, $zero, -15
	# I-format therefore has the follwoing: opcode, rs, rt, and immediate 
	# opcode: 001000 rs: 00000 rt: 10000 Immediate: 1111111111110001
	# binary: 0010 0000 0001 0000 1111 1111 1111 0001
	# hex:  0x2010FFF1
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# Tps 2 part 2
	slt $t0, $s0, $s1
	
	# Tps 2 part 3
	beq $t0, $zero, LEEQ
	
	# Tps 2 part 4
	j GRT

GRT:	li $v0, 4 
	la $a0, str1 
	syscall 	
	j END

LEEQ:	li $v0, 4 
	la $a0, str2 
	syscall 	
	j END
			
END:	li $v0, 10		
	syscall

