# Input: number of inputs, n, and n integers;   Output: Sum of integers
            .data                    # Data memory area.
prmpt1:     .asciiz "How many inputs? "
prmpt2:     .asciiz "Next input: "
sumtext:    .asciiz "The sum is "
            .text           	   # Code area starts here
main:       li   $v0, 4    	   # Syscall to print prompt string
            la   $a0, prmpt1         # li and la are pseudo instr.
            syscall
            li   $v0, 5     	   # Syscall to read an integer
            syscall
            move $t0, $v0   	   # n stored in $t0

            li   $t1, 0         	   # sum will be stored in $t1
while:      blez $t0, endwhile       # (pseudo instruction)
            li   $v0, 4	    	   # syscal to print string
            la   $a0, prmpt2
            syscall
            li   $v0, 5
            syscall
            add  $t1, $t1, $v0 	   # Increase sum by new input
            sub  $t0, $t0, 1  	   # Decrement n
            j    while

endwhile:   li   $v0, 4	            # syscal to print string
            la   $a0, sumtext
            syscall
            move $a0, $t1             # Syscall to print an integer
            li   $v0, 1
            syscall
            li   $v0, 10              # Syscall to exit
            syscall
