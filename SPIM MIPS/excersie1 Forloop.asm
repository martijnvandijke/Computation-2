# C code
#     int x, y;
#     for (x=0, y=100;  x != y;  x++, y--);

#.data
main:
      li $t0, 0 #add 0 to register -> x
      li $t1, 100 #add 100 to register -> y
      syscall #update Spim
for:  beq $t0, $t1, end   #branch if not eqaul
      addi $t0, $t0, 1
      addi $t1, $t1, -1
      j for
end:  syscall

#verified output !
