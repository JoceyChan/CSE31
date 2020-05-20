        .data
str1: .asciiz "Greater than\n"
str2: .asciiz "Less than or equal to\n"

	.text
	
	addi $s0, $zero, -15
	# I-format therefore has the follwoing: opcode, rs, rt, and immediate 
	# opcode: 001000 rs: 00000 rt: 10000 Immediate: 1111 1111 1111 0001
	# binary: 0010 0000 0001 0000 1111 1111 1111 0001
	# hex:  0x2010FFF1
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# Tps 2 part 2
	slt $t0, $s0, $s1
	# R-Format: opcode, rs, rt, rd, shamt and funct
	# opcode: 000000 rs:10000 rt:10001 rd:01000 shamt:00000 funct: 101010
	# binary: 0000 0010 0001 0001 0100 0000 0010 1010
	# hex: 0x0211402A
	
	# Tps 2 part 3
	beq $t0, $zero, LEEQ
	# I-format therefore has the follwoing: opcode, rs, rt, and immediate ((addrFromLabelTable - (PC+4))/4)
	# opcode: 000100 rs: 01000 rt: 00000 Immediate: 0000 0000 0000 0110 ((0x00400014 + 4) - 0x00400030)/4 = -6
	# binary: 0001 0001 0000 0000 0000 0000 0000 0110
	# hex:  0x11000006
	
	# Tps 2 part 4
	j GRT
	# J-format: opcode, address
	# opcode: 000010 address(0x0040001C): 0000 0000 0100 0000 0000 0000 0001 1100 (last 2 are dropped)
	# address update: 0000 0100 0000 0000 0000 0001 11
	# binary: 0000 1000 0001 0000 0000 0000 0000 0111
	# hex: 0x08100007

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

