#		$t2	- used to hold the sum of the $t0 and $t1.
#		$v0	- syscall number, and syscall return value.
#		$a0	- syscall input parameter.

		.text           	# Code area starts here
main:
		li	$v0, 5		# read number into $v0
		syscall			# make the syscall read_int
		move	$t0, $v0	# move the number read into $t0

		li	$v0, 5		# read second number into $v0
		syscall			# make the syscall read_int
		move	$t1, $v0	# move the number read into $t1

		add	$t2, $t0, $t1

		move	$a0, $t2	# move the number to print into $a0
		li	$v0, 1		# load syscall print_int into $v0
		syscall			#

		li	$v0, 10		# syscall code 10 is for exit
		syscall			#
# end of main
