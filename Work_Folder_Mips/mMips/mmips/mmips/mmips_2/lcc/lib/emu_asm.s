        .text
        .align 	2

	.globl 	__sll
        .ent 	__sll

__sll: 	move	$2, $4
	and	$8, $5, 1
	beq	$8, $0, __sll1
	sll	$2, $2, 1
__sll1:	and     $8, $5, 2
        beq     $8, $0, __sll2
        sll     $2, $2, 2
__sll2: and     $8, $5, 4
        beq     $8, $0, __sll3
        sll     $2, $2, 2
        sll     $2, $2, 2
__sll3: and     $8, $5, 8
        beq     $8, $0, __sll4
        sll     $2, $2, 8
__sll4: and     $8, $5, 16
        beq     $8, $0, __sll5
        sll     $2, $2, 8
        sll     $2, $2, 8
__sll5:	j	$31

	.end 	__sll

        .globl 	__sra
        .ent    __sra

__sra:  move    $2, $4
        and     $8, $5, 1
        beq     $8, $0, __sra1
        sra     $2, $2, 1
__sra1: and     $8, $5, 2
        beq     $8, $0, __sra2
        sra     $2, $2, 2
__sra2: and     $8, $5, 4
        beq     $8, $0, __sra3
        sra     $2, $2, 2
        sra     $2, $2, 2
__sra3: and     $8, $5, 8
        beq     $8, $0, __sra4
        sra     $2, $2, 8
__sra4: and     $8, $5, 16
        beq     $8, $0, __sra5
        sra     $2, $2, 8
        sra     $2, $2, 8
__sra5: j       $31

        .end    __sra

        .globl 	__srl
        .ent    __srl

__srl:  move    $2, $4
        and     $8, $5, 1
        beq     $8, $0, __srl1
        srl     $2, $2, 1
__srl1: and     $8, $5, 2
        beq     $8, $0, __srl2
        srl     $2, $2, 2
__srl2: and     $8, $5, 4
        beq     $8, $0, __srl3
        srl     $2, $2, 2
        srl     $2, $2, 2
__srl3: and     $8, $5, 8
        beq     $8, $0, __srl4
        srl     $2, $2, 8
__srl4: and     $8, $5, 16
        beq     $8, $0, __srl5
        srl     $2, $2, 8
        srl     $2, $2, 8
__srl5: j       $31

        .end    __srl

	.globl  __mul
        .ent    __mul

__mul:	li	$2, 0
	move	$10, $4
	move	$11, $5
__mul2:	and     $8, $10, 1
	beq     $8, $0, __mul1
	addu	$2, $2, $11
__mul1:	srl	$10, $10, 1
	sll	$11, $11, 1
	bne     $10, $0, __mul2
	j       $31

        .end    __mul
