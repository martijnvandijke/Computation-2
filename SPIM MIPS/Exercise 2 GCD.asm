# C code
#int gcd(int a, int b) {
#   if (b == 0)
#      return a;
#   else
#      return gcd(b, a % b);   // recursive call
#}
#
#
#void main(void) {
#   int	a, b;
#
#   printf("Enter a and b: ");
#   scanf("%d%d", &a, &b);
#   printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b) );
#}
.data                    # Data memory area.
prmpt1:     .asciiz "Enter a "
prmpt2:     .asciiz "Enter b "
sumtext:    .asciiz "The sum is "
.text
main:
    li   $v0, 4    	   # Syscall to print prompt string
    la   $a0, prmpt1
    syscall
    li   $v0, 5
    syscall
    move $t0, $v0
    li   $v0, 4        # li and la are pseudo instr.
    la   $a1, prmpt2
    syscall
    li   $v0, 5
    syscall
    move $t1, $v0
    j gcd
gcd:
    bne $t1, $t0, end


end:
