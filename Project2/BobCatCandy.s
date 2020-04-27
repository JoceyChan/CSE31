.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
# Declare any necessary data here

str1: .asciiz "Please enter the prize of a BobCat Bar:" # It first asks user to enter the price of each BobCat Bar.

str2: .asciiz "Enter the number of bar wrappers needed to exchange for a new bar:" # It then asks user to enter the number of bar wrappers needed to exchange for a new bar.

str3: .asciiz "How, how much do you have?" # It then asks user to enter how much money he/she has.


.text

main:
		# This is the main program.
		# It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered.

		# It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		addi $sp, $sp -4	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here

        #loads and prints str0
        li $t3, 0
        la $a0, str0
        li $v0, 4 # this is fn used for printing
        syscall

        # loads and prints str1
        la $a0, str1 # addr of str to print
        li $v0, 4 # calls fn for printing
        syscall
        li $v0, 5 # int to print
        syscall #prints

        move $t0, $v0
		# loads and prints str2
        la $a0, str2
        li $v0, 4
        syscall
        li $v0, 5
        syscall

		move $t1, $v0 # stores user input in temp 1
		la $a0, str3 # loading address
		li $v0, 4 
		syscall

		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

		# Print out final statement here



		j end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars



		jal newBars 	# Call a helper function to keep track of the number of bars.
		

		
		jr $ra
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of wrappers left so far and n.

		
		
		
		
		
		jr $ra
		# End of newBars

end: 
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp 4
		li $v0, 10 
		syscall
