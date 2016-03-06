    .equ    heap_size,          4000000

    .text
    .align  2

    .globl  _bup_sad
    .globl  _bup_happy 

    .ent    _start

_start:
    nop                               # Bug: First instruction on mMIPS is not executed
    
    la      $gp, _gp                  # globals pointer
    la      $sp, _end                 # stack pointer (stack starts at end of ram)
    la      $fp, _end                 # frame pointer

# Dynamic memory allocation skipped because of limited memory size.
    la      $4, _heap                 # heap start address
    li      $5, heap_size             # heap size
    jal     add_free                  # init heap
    nop
    move    $4, $0                    
    move    $5, $0                    

    jal     main                      # jump past happy and sad addresses

L1:    
    j       L1

    .align 5
_bup_happy:
    j       L1                        # Stop simulation
    
    .align 5
_bup_sad:
    j       L1                        # Stop simulation

    .bss
