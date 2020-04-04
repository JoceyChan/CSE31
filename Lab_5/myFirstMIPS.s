	.data
n:      .word 1

        .text
       
        
	 	add     $t0, $0, $zero
		add     $t1, $t0, 1
		add     $t2, $t1, 2
		add     $t3, $t2, 3
		add     $t4, $t3, 4
		add     $t5, $t4, 5
		add     $t6, $t5, 6
		add     $t7, $t6, 7
		
		li      $v0, 1		# you will be asked about what the purpose of this line for syscall 
		add     $a0, $t7, $zero	
		syscall		
				
		li      $v0, 10		
		syscall		
