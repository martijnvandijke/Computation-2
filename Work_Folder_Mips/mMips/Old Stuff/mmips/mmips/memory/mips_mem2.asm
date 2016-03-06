
mips_mem2.bin:     file format binary

Disassembly of section .data:

0000000000000000 <.data>:
       0:	00000000 	nop
       4:	3c1c0040 	lui	gp,0x40
       8:	279c0018 	addiu	gp,gp,24
       c:	3c1d0042 	lui	sp,0x42
      10:	27bd0000 	addiu	sp,sp,0
      14:	3c1e0042 	lui	s8,0x42
      18:	27de0000 	addiu	s8,s8,0
      1c:	3c040040 	lui	a0,0x40
      20:	24840024 	addiu	a0,a0,36
      24:	3c05003d 	lui	a1,0x3d
      28:	0c0000e1 	jal	0x384
      2c:	34a50900 	ori	a1,a1,0x900
      30:	00000000 	nop
      34:	00002021 	move	a0,zero
      38:	0c000028 	jal	0xa0
      3c:	00002821 	move	a1,zero
      40:	08000010 	j	0x40
      44:	00000000 	nop
	...
      60:	08000010 	j	0x40
      64:	00000000 	nop
	...
      80:	08000010 	j	0x40
      84:	00000000 	nop
	...
      a0:	27bdff90 	addiu	sp,sp,-112
      a4:	afb20010 	sw	s2,16(sp)
      a8:	afb30014 	sw	s3,20(sp)
      ac:	afb40018 	sw	s4,24(sp)
      b0:	afb5001c 	sw	s5,28(sp)
      b4:	afb60020 	sw	s6,32(sp)
      b8:	afb70024 	sw	s7,36(sp)
      bc:	afbf0028 	sw	ra,40(sp)
      c0:	241300ff 	li	s3,255
      c4:	3c150040 	lui	s5,0x40
      c8:	36b51000 	ori	s5,s5,0x1000
      cc:	3c180040 	lui	t8,0x40
      d0:	37182000 	ori	t8,t8,0x2000
      d4:	afb8006c 	sw	t8,108(sp)
      d8:	24160001 	li	s6,1
      dc:	24170001 	li	s7,1
      e0:	24180005 	li	t8,5
      e4:	afb80068 	sw	t8,104(sp)
      e8:	02c02021 	move	a0,s6
      ec:	0c0003fc 	jal	0xff0
      f0:	03002821 	move	a1,t8
      f4:	0040c021 	move	t8,v0
      f8:	afb8005c 	sw	t8,92(sp)
      fc:	240ffff9 	li	t7,-7
     100:	afaf0058 	sw	t7,88(sp)
     104:	270effe0 	addiu	t6,t8,-32
     108:	01d77021 	addu	t6,t6,s7
     10c:	afae0064 	sw	t6,100(sp)
     110:	240d0001 	li	t5,1
     114:	afad0060 	sw	t5,96(sp)
     118:	01e02021 	move	a0,t7
     11c:	25ccffff 	addiu	t4,t6,-1
     120:	01956021 	addu	t4,t4,s5
     124:	81850000 	lb	a1,0(t4)
     128:	00000000 	nop
     12c:	00850019 	multu	a0,a1
     130:	00001012 	mflo	v0
     134:	0040c021 	move	t8,v0
     138:	afb80054 	sw	t8,84(sp)
     13c:	8faf0068 	lw	t7,104(sp)
     140:	00000000 	nop
     144:	01e02021 	move	a0,t7
     148:	8faf0064 	lw	t7,100(sp)
     14c:	00000000 	nop
     150:	01f57821 	addu	t7,t7,s5
     154:	81e50000 	lb	a1,0(t7)
     158:	00000000 	nop
     15c:	00850019 	multu	a0,a1
     160:	00001012 	mflo	v0
     164:	0040c021 	move	t8,v0
     168:	afb80050 	sw	t8,80(sp)
     16c:	8faf0064 	lw	t7,100(sp)
     170:	00000000 	nop
     174:	25ef0001 	addiu	t7,t7,1
     178:	01f57821 	addu	t7,t7,s5
     17c:	81e40000 	lb	a0,0(t7)
     180:	8faf0060 	lw	t7,96(sp)
     184:	00000000 	nop
     188:	0c0003fc 	jal	0xff0
     18c:	01e02821 	move	a1,t7
     190:	0040c021 	move	t8,v0
     194:	afb80044 	sw	t8,68(sp)
     198:	240fffff 	li	t7,-1
     19c:	afaf0048 	sw	t7,72(sp)
     1a0:	8fae005c 	lw	t6,92(sp)
     1a4:	00000000 	nop
     1a8:	01d77021 	addu	t6,t6,s7
     1ac:	afae004c 	sw	t6,76(sp)
     1b0:	01e02021 	move	a0,t7
     1b4:	25cdffff 	addiu	t5,t6,-1
     1b8:	01b56821 	addu	t5,t5,s5
     1bc:	81a50000 	lb	a1,0(t5)
     1c0:	00000000 	nop
     1c4:	00850019 	multu	a0,a1
     1c8:	00001012 	mflo	v0
     1cc:	0040c021 	move	t8,v0
     1d0:	afb80040 	sw	t8,64(sp)
     1d4:	2404000f 	li	a0,15
     1d8:	8faf004c 	lw	t7,76(sp)
     1dc:	00000000 	nop
     1e0:	01f57821 	addu	t7,t7,s5
     1e4:	81e50000 	lb	a1,0(t7)
     1e8:	00000000 	nop
     1ec:	00850019 	multu	a0,a1
     1f0:	00001012 	mflo	v0
     1f4:	0040c021 	move	t8,v0
     1f8:	afb8003c 	sw	t8,60(sp)
     1fc:	8faf0048 	lw	t7,72(sp)
     200:	00000000 	nop
     204:	01e02021 	move	a0,t7
     208:	8faf004c 	lw	t7,76(sp)
     20c:	00000000 	nop
     210:	25ef0001 	addiu	t7,t7,1
     214:	01f57821 	addu	t7,t7,s5
     218:	81e50000 	lb	a1,0(t7)
     21c:	00000000 	nop
     220:	00850019 	multu	a0,a1
     224:	00001012 	mflo	v0
     228:	0040c021 	move	t8,v0
     22c:	afb80034 	sw	t8,52(sp)
     230:	8faf005c 	lw	t7,92(sp)
     234:	00000000 	nop
     238:	25ef0020 	addiu	t7,t7,32
     23c:	01f77821 	addu	t7,t7,s7
     240:	afaf0038 	sw	t7,56(sp)
     244:	25eeffff 	addiu	t6,t7,-1
     248:	01d57021 	addu	t6,t6,s5
     24c:	81c40000 	lb	a0,0(t6)
     250:	8fae0060 	lw	t6,96(sp)
     254:	00000000 	nop
     258:	0c0003fc 	jal	0xff0
     25c:	01c02821 	move	a1,t6
     260:	0040c021 	move	t8,v0
     264:	afb80030 	sw	t8,48(sp)
     268:	8faf0068 	lw	t7,104(sp)
     26c:	00000000 	nop
     270:	01e02021 	move	a0,t7
     274:	8faf0038 	lw	t7,56(sp)
     278:	00000000 	nop
     27c:	01f57821 	addu	t7,t7,s5
     280:	81e50000 	lb	a1,0(t7)
     284:	00000000 	nop
     288:	00850019 	multu	a0,a1
     28c:	00001012 	mflo	v0
     290:	0040c021 	move	t8,v0
     294:	afb8002c 	sw	t8,44(sp)
     298:	8faf0058 	lw	t7,88(sp)
     29c:	00000000 	nop
     2a0:	01e02021 	move	a0,t7
     2a4:	8faf0038 	lw	t7,56(sp)
     2a8:	00000000 	nop
     2ac:	25ef0001 	addiu	t7,t7,1
     2b0:	01f57821 	addu	t7,t7,s5
     2b4:	81e50000 	lb	a1,0(t7)
     2b8:	00000000 	nop
     2bc:	00850019 	multu	a0,a1
     2c0:	00001012 	mflo	v0
     2c4:	8faf0054 	lw	t7,84(sp)
     2c8:	8fae0050 	lw	t6,80(sp)
     2cc:	00000000 	nop
     2d0:	01ee7821 	addu	t7,t7,t6
     2d4:	8fae0044 	lw	t6,68(sp)
     2d8:	00000000 	nop
     2dc:	01ee7821 	addu	t7,t7,t6
     2e0:	8fae0040 	lw	t6,64(sp)
     2e4:	00000000 	nop
     2e8:	01ee7821 	addu	t7,t7,t6
     2ec:	8fae003c 	lw	t6,60(sp)
     2f0:	00000000 	nop
     2f4:	01ee7821 	addu	t7,t7,t6
     2f8:	8fae0034 	lw	t6,52(sp)
     2fc:	00000000 	nop
     300:	01ee7821 	addu	t7,t7,t6
     304:	8fae0030 	lw	t6,48(sp)
     308:	00000000 	nop
     30c:	01ee7821 	addu	t7,t7,t6
     310:	8fae002c 	lw	t6,44(sp)
     314:	00000000 	nop
     318:	01ee7821 	addu	t7,t7,t6
     31c:	01e2c021 	addu	t8,t7,v0
     320:	27040080 	addiu	a0,t8,128
     324:	0c000367 	jal	0xd9c
     328:	2405000d 	li	a1,13
     32c:	0040a021 	move	s4,v0
     330:	02939030 	tge	s4,s3,0x240
     334:	26f70001 	addiu	s7,s7,1
     338:	2418001f 	li	t8,31
     33c:	02f8f02a 	slt	s8,s7,t8
     340:	17c0ff67 	bnez	s8,0xe0
     344:	00000000 	nop
     348:	26d60001 	addiu	s6,s6,1
     34c:	2418001f 	li	t8,31
     350:	02d8f02a 	slt	s8,s6,t8
     354:	17c0ff61 	bnez	s8,0xdc
     358:	00000000 	nop
     35c:	8fb20010 	lw	s2,16(sp)
     360:	8fb30014 	lw	s3,20(sp)
     364:	8fb40018 	lw	s4,24(sp)
     368:	8fb5001c 	lw	s5,28(sp)
     36c:	8fb60020 	lw	s6,32(sp)
     370:	8fb70024 	lw	s7,36(sp)
     374:	8fbf0028 	lw	ra,40(sp)
     378:	27bd0070 	addiu	sp,sp,112
     37c:	03e00008 	jr	ra
     380:	00000000 	nop
     384:	27bdfff8 	addiu	sp,sp,-8
     388:	10000005 	b	0x3a0
     38c:	afb70000 	sw	s7,0(sp)
     390:	0080c021 	move	t8,a0
     394:	27180001 	addiu	t8,t8,1
     398:	03002021 	move	a0,t8
     39c:	24a5ffff 	addiu	a1,a1,-1
     3a0:	10a00005 	beqz	a1,0x3b8
     3a4:	00000000 	nop
     3a8:	0080c021 	move	t8,a0
     3ac:	33180003 	andi	t8,t8,0x3
     3b0:	1700fff7 	bnez	t8,0x390
     3b4:	00000000 	nop
     3b8:	24180018 	li	t8,24
     3bc:	00b8f02b 	sltu	s8,a1,t8
     3c0:	13c00003 	beqz	s8,0x3d0
     3c4:	00000000 	nop
     3c8:	10000025 	b	0x460
     3cc:	00000000 	nop
     3d0:	0080b821 	move	s7,a0
     3d4:	24a5fff8 	addiu	a1,a1,-8
     3d8:	24180001 	li	t8,1
     3dc:	aef80000 	sw	t8,0(s7)
     3e0:	aee50004 	sw	a1,4(s7)
     3e4:	8ef80004 	lw	t8,4(s7)
     3e8:	3c01ffff 	lui	at,0xffff
     3ec:	3421fffe 	ori	at,at,0xfffe
     3f0:	03017824 	and	t7,t8,at
     3f4:	01f77821 	addu	t7,t7,s7
     3f8:	adf80000 	sw	t8,0(t7)
     3fc:	8ef80004 	lw	t8,4(s7)
     400:	3c01ffff 	lui	at,0xffff
     404:	3421fffe 	ori	at,at,0xfffe
     408:	0301c024 	and	t8,t8,at
     40c:	0317c021 	addu	t8,t8,s7
     410:	240f0001 	li	t7,1
     414:	af0f0004 	sw	t7,4(t8)
     418:	3c180040 	lui	t8,0x40
     41c:	8f180010 	lw	t8,16(t8)
     420:	00000000 	nop
     424:	aef80008 	sw	t8,8(s7)
     428:	3c180040 	lui	t8,0x40
     42c:	8f180010 	lw	t8,16(t8)
     430:	00000000 	nop
     434:	8f18000c 	lw	t8,12(t8)
     438:	00000000 	nop
     43c:	aef8000c 	sw	t8,12(s7)
     440:	3c180040 	lui	t8,0x40
     444:	8f180010 	lw	t8,16(t8)
     448:	00000000 	nop
     44c:	2718000c 	addiu	t8,t8,12
     450:	8f0f0000 	lw	t7,0(t8)
     454:	00000000 	nop
     458:	adf70008 	sw	s7,8(t7)
     45c:	af170000 	sw	s7,0(t8)
     460:	8fb70000 	lw	s7,0(sp)
     464:	03e00008 	jr	ra
     468:	27bd0008 	addiu	sp,sp,8
     46c:	27bdffe0 	addiu	sp,sp,-32
     470:	afb60010 	sw	s6,16(sp)
     474:	afb70014 	sw	s7,20(sp)
     478:	afbf0018 	sw	ra,24(sp)
     47c:	afa40020 	sw	a0,32(sp)
     480:	00a0b821 	move	s7,a1
     484:	02e02021 	move	a0,s7
     488:	8fa50020 	lw	a1,32(sp)
     48c:	00000000 	nop
     490:	00850019 	multu	a0,a1
     494:	00001012 	mflo	v0
     498:	0040c021 	move	t8,v0
     49c:	0300b821 	move	s7,t8
     4a0:	0c0001bc 	jal	0x6f0
     4a4:	02e02021 	move	a0,s7
     4a8:	0040b021 	move	s6,v0
     4ac:	0040c021 	move	t8,v0
     4b0:	17000003 	bnez	t8,0x4c0
     4b4:	00000000 	nop
     4b8:	10000006 	b	0x4d4
     4bc:	00001021 	move	v0,zero
     4c0:	02c02021 	move	a0,s6
     4c4:	00002821 	move	a1,zero
     4c8:	0c0002e3 	jal	0xb8c
     4cc:	02e03021 	move	a2,s7
     4d0:	02c01021 	move	v0,s6
     4d4:	8fb60010 	lw	s6,16(sp)
     4d8:	8fb70014 	lw	s7,20(sp)
     4dc:	8fbf0018 	lw	ra,24(sp)
     4e0:	27bd0020 	addiu	sp,sp,32
     4e4:	03e00008 	jr	ra
     4e8:	00000000 	nop
     4ec:	27bdfff0 	addiu	sp,sp,-16
     4f0:	afb60000 	sw	s6,0(sp)
     4f4:	afb70004 	sw	s7,4(sp)
     4f8:	0080c021 	move	t8,a0
     4fc:	17000003 	bnez	t8,0x50c
     500:	00000000 	nop
     504:	10000076 	b	0x6e0
     508:	00000000 	nop
     50c:	3c17ffff 	lui	s7,0xffff
     510:	36f7fff8 	ori	s7,s7,0xfff8
     514:	02e4b821 	addu	s7,s7,a0
     518:	8ef80004 	lw	t8,4(s7)
     51c:	00000000 	nop
     520:	33180001 	andi	t8,t8,0x1
     524:	17000003 	bnez	t8,0x534
     528:	00000000 	nop
     52c:	1000006c 	b	0x6e0
     530:	00000000 	nop
     534:	26f80004 	addiu	t8,s7,4
     538:	8f0f0000 	lw	t7,0(t8)
     53c:	3c01ffff 	lui	at,0xffff
     540:	3421fffe 	ori	at,at,0xfffe
     544:	01e17824 	and	t7,t7,at
     548:	af0f0000 	sw	t7,0(t8)
     54c:	8ef80004 	lw	t8,4(s7)
     550:	3c01ffff 	lui	at,0xffff
     554:	3421fffe 	ori	at,at,0xfffe
     558:	0301c024 	and	t8,t8,at
     55c:	0317c021 	addu	t8,t8,s7
     560:	8f0f0000 	lw	t7,0(t8)
     564:	3c01ffff 	lui	at,0xffff
     568:	3421fffe 	ori	at,at,0xfffe
     56c:	01e17824 	and	t7,t7,at
     570:	af0f0000 	sw	t7,0(t8)
     574:	8ef80000 	lw	t8,0(s7)
     578:	00000000 	nop
     57c:	33180001 	andi	t8,t8,0x1
     580:	17000020 	bnez	t8,0x604
     584:	00000000 	nop
     588:	8ef80004 	lw	t8,4(s7)
     58c:	00000000 	nop
     590:	afb8000c 	sw	t8,12(sp)
     594:	8ef80000 	lw	t8,0(s7)
     598:	3c01ffff 	lui	at,0xffff
     59c:	3421fffe 	ori	at,at,0xfffe
     5a0:	0301c024 	and	t8,t8,at
     5a4:	241effff 	li	s8,-1
     5a8:	031ec026 	xor	t8,t8,s8
     5ac:	27180001 	addiu	t8,t8,1
     5b0:	0317b821 	addu	s7,t8,s7
     5b4:	26f80004 	addiu	t8,s7,4
     5b8:	8f0f0000 	lw	t7,0(t8)
     5bc:	8fae000c 	lw	t6,12(sp)
     5c0:	00000000 	nop
     5c4:	01ee7821 	addu	t7,t7,t6
     5c8:	af0f0000 	sw	t7,0(t8)
     5cc:	8ef80004 	lw	t8,4(s7)
     5d0:	3c01ffff 	lui	at,0xffff
     5d4:	3421fffe 	ori	at,at,0xfffe
     5d8:	03017824 	and	t7,t8,at
     5dc:	01f77821 	addu	t7,t7,s7
     5e0:	adf80000 	sw	t8,0(t7)
     5e4:	8ef80008 	lw	t8,8(s7)
     5e8:	8eef000c 	lw	t7,12(s7)
     5ec:	00000000 	nop
     5f0:	af0f000c 	sw	t7,12(t8)
     5f4:	8ef8000c 	lw	t8,12(s7)
     5f8:	8eef0008 	lw	t7,8(s7)
     5fc:	00000000 	nop
     600:	af0f0008 	sw	t7,8(t8)
     604:	8ef80004 	lw	t8,4(s7)
     608:	3c01ffff 	lui	at,0xffff
     60c:	3421fffe 	ori	at,at,0xfffe
     610:	0301c024 	and	t8,t8,at
     614:	0317b021 	addu	s6,t8,s7
     618:	8ed80004 	lw	t8,4(s6)
     61c:	00000000 	nop
     620:	33180001 	andi	t8,t8,0x1
     624:	1700001c 	bnez	t8,0x698
     628:	00000000 	nop
     62c:	26f80004 	addiu	t8,s7,4
     630:	8f0f0000 	lw	t7,0(t8)
     634:	8ece0004 	lw	t6,4(s6)
     638:	00000000 	nop
     63c:	01ee7821 	addu	t7,t7,t6
     640:	af0f0000 	sw	t7,0(t8)
     644:	8ef80004 	lw	t8,4(s7)
     648:	3c01ffff 	lui	at,0xffff
     64c:	3421fffe 	ori	at,at,0xfffe
     650:	03017824 	and	t7,t8,at
     654:	01f77821 	addu	t7,t7,s7
     658:	adf80000 	sw	t8,0(t7)
     65c:	3c180040 	lui	t8,0x40
     660:	8f180014 	lw	t8,20(t8)
     664:	02c07821 	move	t7,s6
     668:	170f0003 	bne	t8,t7,0x678
     66c:	00000000 	nop
     670:	3c010040 	lui	at,0x40
     674:	ac370014 	sw	s7,20(at)
     678:	8ed80008 	lw	t8,8(s6)
     67c:	8ecf000c 	lw	t7,12(s6)
     680:	00000000 	nop
     684:	af0f000c 	sw	t7,12(t8)
     688:	8ed8000c 	lw	t8,12(s6)
     68c:	8ecf0008 	lw	t7,8(s6)
     690:	00000000 	nop
     694:	af0f0008 	sw	t7,8(t8)
     698:	3c180040 	lui	t8,0x40
     69c:	8f180010 	lw	t8,16(t8)
     6a0:	00000000 	nop
     6a4:	aef80008 	sw	t8,8(s7)
     6a8:	3c180040 	lui	t8,0x40
     6ac:	8f180010 	lw	t8,16(t8)
     6b0:	00000000 	nop
     6b4:	8f18000c 	lw	t8,12(t8)
     6b8:	00000000 	nop
     6bc:	aef8000c 	sw	t8,12(s7)
     6c0:	3c180040 	lui	t8,0x40
     6c4:	8f180010 	lw	t8,16(t8)
     6c8:	00000000 	nop
     6cc:	2718000c 	addiu	t8,t8,12
     6d0:	8f0f0000 	lw	t7,0(t8)
     6d4:	00000000 	nop
     6d8:	adf70008 	sw	s7,8(t7)
     6dc:	af170000 	sw	s7,0(t8)
     6e0:	8fb60000 	lw	s6,0(sp)
     6e4:	8fb70004 	lw	s7,4(sp)
     6e8:	03e00008 	jr	ra
     6ec:	27bd0010 	addiu	sp,sp,16
     6f0:	27bdffe8 	addiu	sp,sp,-24
     6f4:	afb40000 	sw	s4,0(sp)
     6f8:	afb50004 	sw	s5,4(sp)
     6fc:	afb60008 	sw	s6,8(sp)
     700:	14800003 	bnez	a0,0x710
     704:	afb7000c 	sw	s7,12(sp)
     708:	1000006f 	b	0x8c8
     70c:	00001021 	move	v0,zero
     710:	24980008 	addiu	t8,a0,8
     714:	240f0010 	li	t7,16
     718:	030ff02b 	sltu	s8,t8,t7
     71c:	13c00003 	beqz	s8,0x72c
     720:	00000000 	nop
     724:	10000002 	b	0x730
     728:	24140010 	li	s4,16
     72c:	24940008 	addiu	s4,a0,8
     730:	26980004 	addiu	t8,s4,4
     734:	2718ffff 	addiu	t8,t8,-1
     738:	3c01ffff 	lui	at,0xffff
     73c:	3421fffc 	ori	at,at,0xfffc
     740:	0301b024 	and	s6,t8,at
     744:	3c170040 	lui	s7,0x40
     748:	8ef70014 	lw	s7,20(s7)
     74c:	00000000 	nop
     750:	8ef80004 	lw	t8,4(s7)
     754:	00000000 	nop
     758:	0316f02b 	sltu	s8,t8,s6
     75c:	17c00003 	bnez	s8,0x76c
     760:	00000000 	nop
     764:	10000009 	b	0x78c
     768:	00000000 	nop
     76c:	8ef7000c 	lw	s7,12(s7)
     770:	00000000 	nop
     774:	02e0c021 	move	t8,s7
     778:	3c0f0040 	lui	t7,0x40
     77c:	8def0014 	lw	t7,20(t7)
     780:	00000000 	nop
     784:	170ffff2 	bne	t8,t7,0x750
     788:	00000000 	nop
     78c:	8ef80004 	lw	t8,4(s7)
     790:	00000000 	nop
     794:	0316f02b 	sltu	s8,t8,s6
     798:	13c00003 	beqz	s8,0x7a8
     79c:	00000000 	nop
     7a0:	10000049 	b	0x8c8
     7a4:	00001021 	move	v0,zero
     7a8:	8ef8000c 	lw	t8,12(s7)
     7ac:	3c010040 	lui	at,0x40
     7b0:	ac380014 	sw	t8,20(at)
     7b4:	8ef80004 	lw	t8,4(s7)
     7b8:	00000000 	nop
     7bc:	afb80014 	sw	t8,20(sp)
     7c0:	8fb80014 	lw	t8,20(sp)
     7c4:	00000000 	nop
     7c8:	0316c023 	subu	t8,t8,s6
     7cc:	240f0010 	li	t7,16
     7d0:	030ff02b 	sltu	s8,t8,t7
     7d4:	17c00029 	bnez	s8,0x87c
     7d8:	00000000 	nop
     7dc:	aef60004 	sw	s6,4(s7)
     7e0:	8ef80004 	lw	t8,4(s7)
     7e4:	3c01ffff 	lui	at,0xffff
     7e8:	3421fffe 	ori	at,at,0xfffe
     7ec:	03017824 	and	t7,t8,at
     7f0:	01f77821 	addu	t7,t7,s7
     7f4:	adf80000 	sw	t8,0(t7)
     7f8:	8ef80004 	lw	t8,4(s7)
     7fc:	3c01ffff 	lui	at,0xffff
     800:	3421fffe 	ori	at,at,0xfffe
     804:	0301c024 	and	t8,t8,at
     808:	0317a821 	addu	s5,t8,s7
     80c:	8fb80014 	lw	t8,20(sp)
     810:	00000000 	nop
     814:	0316c023 	subu	t8,t8,s6
     818:	aeb80004 	sw	t8,4(s5)
     81c:	8eb80004 	lw	t8,4(s5)
     820:	3c01ffff 	lui	at,0xffff
     824:	3421fffe 	ori	at,at,0xfffe
     828:	03017824 	and	t7,t8,at
     82c:	01f57821 	addu	t7,t7,s5
     830:	adf80000 	sw	t8,0(t7)
     834:	3c180040 	lui	t8,0x40
     838:	8f180010 	lw	t8,16(t8)
     83c:	00000000 	nop
     840:	aeb80008 	sw	t8,8(s5)
     844:	3c180040 	lui	t8,0x40
     848:	8f180010 	lw	t8,16(t8)
     84c:	00000000 	nop
     850:	8f18000c 	lw	t8,12(t8)
     854:	00000000 	nop
     858:	aeb8000c 	sw	t8,12(s5)
     85c:	3c180040 	lui	t8,0x40
     860:	8f180010 	lw	t8,16(t8)
     864:	00000000 	nop
     868:	2718000c 	addiu	t8,t8,12
     86c:	8f0f0000 	lw	t7,0(t8)
     870:	00000000 	nop
     874:	adf50008 	sw	s5,8(t7)
     878:	af150000 	sw	s5,0(t8)
     87c:	8ef80008 	lw	t8,8(s7)
     880:	8eef000c 	lw	t7,12(s7)
     884:	00000000 	nop
     888:	af0f000c 	sw	t7,12(t8)
     88c:	8ef8000c 	lw	t8,12(s7)
     890:	8eef0008 	lw	t7,8(s7)
     894:	00000000 	nop
     898:	af0f0008 	sw	t7,8(t8)
     89c:	26f80004 	addiu	t8,s7,4
     8a0:	8f0f0000 	lw	t7,0(t8)
     8a4:	00000000 	nop
     8a8:	35ee0001 	ori	t6,t7,0x1
     8ac:	af0e0000 	sw	t6,0(t8)
     8b0:	3c01ffff 	lui	at,0xffff
     8b4:	3421fffe 	ori	at,at,0xfffe
     8b8:	01e1c024 	and	t8,t7,at
     8bc:	0317c021 	addu	t8,t8,s7
     8c0:	af0e0000 	sw	t6,0(t8)
     8c4:	26e20008 	addiu	v0,s7,8
     8c8:	8fb40000 	lw	s4,0(sp)
     8cc:	8fb50004 	lw	s5,4(sp)
     8d0:	8fb60008 	lw	s6,8(sp)
     8d4:	8fb7000c 	lw	s7,12(sp)
     8d8:	03e00008 	jr	ra
     8dc:	27bd0018 	addiu	sp,sp,24
     8e0:	27bdffd0 	addiu	sp,sp,-48
     8e4:	afb20010 	sw	s2,16(sp)
     8e8:	afb30014 	sw	s3,20(sp)
     8ec:	afb40018 	sw	s4,24(sp)
     8f0:	afb5001c 	sw	s5,28(sp)
     8f4:	afb60020 	sw	s6,32(sp)
     8f8:	afb70024 	sw	s7,36(sp)
     8fc:	afbf0028 	sw	ra,40(sp)
     900:	0080b821 	move	s7,a0
     904:	00a0b021 	move	s6,a1
     908:	02e0c021 	move	t8,s7
     90c:	17000005 	bnez	t8,0x924
     910:	00000000 	nop
     914:	0c0001bc 	jal	0x6f0
     918:	02c02021 	move	a0,s6
     91c:	1000006d 	b	0xad4
     920:	0040c021 	move	t8,v0
     924:	16c00005 	bnez	s6,0x93c
     928:	00000000 	nop
     92c:	0c00013b 	jal	0x4ec
     930:	02e02021 	move	a0,s7
     934:	10000067 	b	0xad4
     938:	00001021 	move	v0,zero
     93c:	3c15ffff 	lui	s5,0xffff
     940:	36b5fff8 	ori	s5,s5,0xfff8
     944:	02b7a821 	addu	s5,s5,s7
     948:	8eb80004 	lw	t8,4(s5)
     94c:	00000000 	nop
     950:	33180001 	andi	t8,t8,0x1
     954:	17000003 	bnez	t8,0x964
     958:	00000000 	nop
     95c:	1000005d 	b	0xad4
     960:	00001021 	move	v0,zero
     964:	8eb80004 	lw	t8,4(s5)
     968:	3c01ffff 	lui	at,0xffff
     96c:	3421fffe 	ori	at,at,0xfffe
     970:	0301a024 	and	s4,t8,at
     974:	26d80008 	addiu	t8,s6,8
     978:	240f0010 	li	t7,16
     97c:	030ff02b 	sltu	s8,t8,t7
     980:	13c00003 	beqz	s8,0x990
     984:	00000000 	nop
     988:	10000002 	b	0x994
     98c:	24120010 	li	s2,16
     990:	26d20008 	addiu	s2,s6,8
     994:	26580004 	addiu	t8,s2,4
     998:	2718ffff 	addiu	t8,t8,-1
     99c:	3c01ffff 	lui	at,0xffff
     9a0:	3421fffc 	ori	at,at,0xfffc
     9a4:	03019824 	and	s3,t8,at
     9a8:	0293f02b 	sltu	s8,s4,s3
     9ac:	17c0003a 	bnez	s8,0xa98
     9b0:	00000000 	nop
     9b4:	0293c023 	subu	t8,s4,s3
     9b8:	240f0010 	li	t7,16
     9bc:	030ff02b 	sltu	s8,t8,t7
     9c0:	13c00003 	beqz	s8,0x9d0
     9c4:	00000000 	nop
     9c8:	10000042 	b	0xad4
     9cc:	02e01021 	move	v0,s7
     9d0:	aeb30004 	sw	s3,4(s5)
     9d4:	8eb80004 	lw	t8,4(s5)
     9d8:	3c01ffff 	lui	at,0xffff
     9dc:	3421fffe 	ori	at,at,0xfffe
     9e0:	03017824 	and	t7,t8,at
     9e4:	01f57821 	addu	t7,t7,s5
     9e8:	adf80000 	sw	t8,0(t7)
     9ec:	26b80004 	addiu	t8,s5,4
     9f0:	8f0f0000 	lw	t7,0(t8)
     9f4:	00000000 	nop
     9f8:	35ee0001 	ori	t6,t7,0x1
     9fc:	af0e0000 	sw	t6,0(t8)
     a00:	3c01ffff 	lui	at,0xffff
     a04:	3421fffe 	ori	at,at,0xfffe
     a08:	01e1c024 	and	t8,t7,at
     a0c:	0315c021 	addu	t8,t8,s5
     a10:	af0e0000 	sw	t6,0(t8)
     a14:	8eb80004 	lw	t8,4(s5)
     a18:	3c01ffff 	lui	at,0xffff
     a1c:	3421fffe 	ori	at,at,0xfffe
     a20:	0301c024 	and	t8,t8,at
     a24:	0315a821 	addu	s5,t8,s5
     a28:	0293c023 	subu	t8,s4,s3
     a2c:	aeb80004 	sw	t8,4(s5)
     a30:	8eb80004 	lw	t8,4(s5)
     a34:	3c01ffff 	lui	at,0xffff
     a38:	3421fffe 	ori	at,at,0xfffe
     a3c:	03017824 	and	t7,t8,at
     a40:	01f57821 	addu	t7,t7,s5
     a44:	adf80000 	sw	t8,0(t7)
     a48:	3c180040 	lui	t8,0x40
     a4c:	8f180010 	lw	t8,16(t8)
     a50:	00000000 	nop
     a54:	aeb80008 	sw	t8,8(s5)
     a58:	3c180040 	lui	t8,0x40
     a5c:	8f180010 	lw	t8,16(t8)
     a60:	00000000 	nop
     a64:	8f18000c 	lw	t8,12(t8)
     a68:	00000000 	nop
     a6c:	aeb8000c 	sw	t8,12(s5)
     a70:	3c180040 	lui	t8,0x40
     a74:	8f180010 	lw	t8,16(t8)
     a78:	00000000 	nop
     a7c:	2718000c 	addiu	t8,t8,12
     a80:	8f0f0000 	lw	t7,0(t8)
     a84:	00000000 	nop
     a88:	adf50008 	sw	s5,8(t7)
     a8c:	af150000 	sw	s5,0(t8)
     a90:	10000010 	b	0xad4
     a94:	02e01021 	move	v0,s7
     a98:	0c0001bc 	jal	0x6f0
     a9c:	02c02021 	move	a0,s6
     aa0:	afa2002c 	sw	v0,44(sp)
     aa4:	0040c021 	move	t8,v0
     aa8:	17000003 	bnez	t8,0xab8
     aac:	00000000 	nop
     ab0:	10000008 	b	0xad4
     ab4:	00001021 	move	v0,zero
     ab8:	8fa4002c 	lw	a0,44(sp)
     abc:	02e02821 	move	a1,s7
     ac0:	0c0002bf 	jal	0xafc
     ac4:	2686fff8 	addiu	a2,s4,-8
     ac8:	0c00013b 	jal	0x4ec
     acc:	02e02021 	move	a0,s7
     ad0:	8fa2002c 	lw	v0,44(sp)
     ad4:	8fb20010 	lw	s2,16(sp)
     ad8:	8fb30014 	lw	s3,20(sp)
     adc:	8fb40018 	lw	s4,24(sp)
     ae0:	8fb5001c 	lw	s5,28(sp)
     ae4:	8fb60020 	lw	s6,32(sp)
     ae8:	8fb70024 	lw	s7,36(sp)
     aec:	8fbf0028 	lw	ra,40(sp)
     af0:	27bd0030 	addiu	sp,sp,48
     af4:	03e00008 	jr	ra
     af8:	00000000 	nop
     afc:	27bdfff8 	addiu	sp,sp,-8
     b00:	afb60000 	sw	s6,0(sp)
     b04:	afb70004 	sw	s7,4(sp)
     b08:	0080b821 	move	s7,a0
     b0c:	10000008 	b	0xb30
     b10:	00a0b021 	move	s6,a1
     b14:	02e0c021 	move	t8,s7
     b18:	27170001 	addiu	s7,t8,1
     b1c:	02c07821 	move	t7,s6
     b20:	25f60001 	addiu	s6,t7,1
     b24:	81ef0000 	lb	t7,0(t7)
     b28:	00000000 	nop
     b2c:	a30f0000 	sb	t7,0(t8)
     b30:	00c0c021 	move	t8,a2
     b34:	1700fff7 	bnez	t8,0xb14
     b38:	2706ffff 	addiu	a2,t8,-1
     b3c:	00801021 	move	v0,a0
     b40:	8fb60000 	lw	s6,0(sp)
     b44:	8fb70004 	lw	s7,4(sp)
     b48:	03e00008 	jr	ra
     b4c:	27bd0008 	addiu	sp,sp,8
     b50:	27bdffe8 	addiu	sp,sp,-24
     b54:	afbf0010 	sw	ra,16(sp)
     b58:	afa40018 	sw	a0,24(sp)
     b5c:	afa5001c 	sw	a1,28(sp)
     b60:	afa60020 	sw	a2,32(sp)
     b64:	8fa40018 	lw	a0,24(sp)
     b68:	8fa5001c 	lw	a1,28(sp)
     b6c:	8fa60020 	lw	a2,32(sp)
     b70:	0c0002bf 	jal	0xafc
     b74:	00000000 	nop
     b78:	0040c021 	move	t8,v0
     b7c:	8fbf0010 	lw	ra,16(sp)
     b80:	27bd0018 	addiu	sp,sp,24
     b84:	03e00008 	jr	ra
     b88:	00000000 	nop
     b8c:	27bdffd0 	addiu	sp,sp,-48
     b90:	afb20010 	sw	s2,16(sp)
     b94:	afb30014 	sw	s3,20(sp)
     b98:	afb40018 	sw	s4,24(sp)
     b9c:	afb5001c 	sw	s5,28(sp)
     ba0:	afb60020 	sw	s6,32(sp)
     ba4:	afb70024 	sw	s7,36(sp)
     ba8:	afbf0028 	sw	ra,40(sp)
     bac:	afa40030 	sw	a0,48(sp)
     bb0:	00a0b821 	move	s7,a1
     bb4:	00c0b021 	move	s6,a2
     bb8:	8fb50030 	lw	s5,48(sp)
     bbc:	00000000 	nop
     bc0:	afb5002c 	sw	s5,44(sp)
     bc4:	24180003 	li	t8,3
     bc8:	0316f02b 	sltu	s8,t8,s6
     bcc:	13c00027 	beqz	s8,0xc6c
     bd0:	00000000 	nop
     bd4:	02a0c021 	move	t8,s5
     bd8:	33180003 	andi	t8,t8,0x3
     bdc:	1300000c 	beqz	t8,0xc10
     be0:	03009021 	move	s2,t8
     be4:	24180004 	li	t8,4
     be8:	03129023 	subu	s2,t8,s2
     bec:	10000005 	b	0xc04
     bf0:	02d2b023 	subu	s6,s6,s2
     bf4:	02a0c021 	move	t8,s5
     bf8:	27150001 	addiu	s5,t8,1
     bfc:	02e07821 	move	t7,s7
     c00:	a30f0000 	sb	t7,0(t8)
     c04:	0240c021 	move	t8,s2
     c08:	1700fffa 	bnez	t8,0xbf4
     c0c:	2712ffff 	addiu	s2,t8,-1
     c10:	0016c082 	srl	t8,s6,0x2
     c14:	03009821 	move	s3,t8
     c18:	32d60003 	andi	s6,s6,0x3
     c1c:	02e0c021 	move	t8,s7
     c20:	331800ff 	andi	t8,t8,0xff
     c24:	0300a021 	move	s4,t8
     c28:	0014c200 	sll	t8,s4,0x8
     c2c:	0298a025 	or	s4,s4,t8
     c30:	0014c200 	sll	t8,s4,0x8
     c34:	0018c200 	sll	t8,t8,0x8
     c38:	10000003 	b	0xc48
     c3c:	0298a025 	or	s4,s4,t8
     c40:	aeb40000 	sw	s4,0(s5)
     c44:	26b50004 	addiu	s5,s5,4
     c48:	0260c021 	move	t8,s3
     c4c:	1700fffc 	bnez	t8,0xc40
     c50:	2713ffff 	addiu	s3,t8,-1
     c54:	10000005 	b	0xc6c
     c58:	00000000 	nop
     c5c:	02a0c021 	move	t8,s5
     c60:	27150001 	addiu	s5,t8,1
     c64:	02e07821 	move	t7,s7
     c68:	a30f0000 	sb	t7,0(t8)
     c6c:	02c0c021 	move	t8,s6
     c70:	1700fffa 	bnez	t8,0xc5c
     c74:	2716ffff 	addiu	s6,t8,-1
     c78:	8fa2002c 	lw	v0,44(sp)
     c7c:	8fb20010 	lw	s2,16(sp)
     c80:	8fb30014 	lw	s3,20(sp)
     c84:	8fb40018 	lw	s4,24(sp)
     c88:	8fb5001c 	lw	s5,28(sp)
     c8c:	8fb60020 	lw	s6,32(sp)
     c90:	8fb70024 	lw	s7,36(sp)
     c94:	8fbf0028 	lw	ra,40(sp)
     c98:	27bd0030 	addiu	sp,sp,48
     c9c:	03e00008 	jr	ra
     ca0:	00000000 	nop
     ca4:	27bdffd8 	addiu	sp,sp,-40
     ca8:	afb40010 	sw	s4,16(sp)
     cac:	afb50014 	sw	s5,20(sp)
     cb0:	afb60018 	sw	s6,24(sp)
     cb4:	afb7001c 	sw	s7,28(sp)
     cb8:	afbf0020 	sw	ra,32(sp)
     cbc:	0080b821 	move	s7,a0
     cc0:	00a0b021 	move	s6,a1
     cc4:	24150001 	li	s5,1
     cc8:	1000000d 	b	0xd00
     ccc:	0000a021 	move	s4,zero
     cd0:	24180001 	li	t8,1
     cd4:	afb80024 	sw	t8,36(sp)
     cd8:	02c02021 	move	a0,s6
     cdc:	0c0003fc 	jal	0xff0
     ce0:	03002821 	move	a1,t8
     ce4:	0040b021 	move	s6,v0
     ce8:	02a02021 	move	a0,s5
     cec:	8fb80024 	lw	t8,36(sp)
     cf0:	00000000 	nop
     cf4:	0c0003fc 	jal	0xff0
     cf8:	03002821 	move	a1,t8
     cfc:	0040a821 	move	s5,v0
     d00:	02d7f02b 	sltu	s8,s6,s7
     d04:	13c00007 	beqz	s8,0xd24
     d08:	00000000 	nop
     d0c:	12a00005 	beqz	s5,0xd24
     d10:	00000000 	nop
     d14:	3c018000 	lui	at,0x8000
     d18:	02c1c024 	and	t8,s6,at
     d1c:	1300ffec 	beqz	t8,0xcd0
     d20:	00000000 	nop
     d24:	10000012 	b	0xd70
     d28:	00000000 	nop
     d2c:	02f6f02b 	sltu	s8,s7,s6
     d30:	17c00003 	bnez	s8,0xd40
     d34:	00000000 	nop
     d38:	02f6b823 	subu	s7,s7,s6
     d3c:	0295a025 	or	s4,s4,s5
     d40:	24180001 	li	t8,1
     d44:	afb80024 	sw	t8,36(sp)
     d48:	02a02021 	move	a0,s5
     d4c:	0c00042e 	jal	0x10b8
     d50:	03002821 	move	a1,t8
     d54:	0040a821 	move	s5,v0
     d58:	02c02021 	move	a0,s6
     d5c:	8fb80024 	lw	t8,36(sp)
     d60:	00000000 	nop
     d64:	0c00042e 	jal	0x10b8
     d68:	03002821 	move	a1,t8
     d6c:	0040b021 	move	s6,v0
     d70:	16a0ffee 	bnez	s5,0xd2c
     d74:	00000000 	nop
     d78:	02801021 	move	v0,s4
     d7c:	8fb40010 	lw	s4,16(sp)
     d80:	8fb50014 	lw	s5,20(sp)
     d84:	8fb60018 	lw	s6,24(sp)
     d88:	8fb7001c 	lw	s7,28(sp)
     d8c:	8fbf0020 	lw	ra,32(sp)
     d90:	27bd0028 	addiu	sp,sp,40
     d94:	03e00008 	jr	ra
     d98:	00000000 	nop
     d9c:	27bdffd8 	addiu	sp,sp,-40
     da0:	afb30010 	sw	s3,16(sp)
     da4:	afb40014 	sw	s4,20(sp)
     da8:	afb50018 	sw	s5,24(sp)
     dac:	afb6001c 	sw	s6,28(sp)
     db0:	afb70020 	sw	s7,32(sp)
     db4:	afbf0024 	sw	ra,36(sp)
     db8:	0080b821 	move	s7,a0
     dbc:	00a0b021 	move	s6,a1
     dc0:	0000a821 	move	s5,zero
     dc4:	02e0f02a 	slt	s8,s7,zero
     dc8:	13c00007 	beqz	s8,0xde8
     dcc:	00000000 	nop
     dd0:	16a00003 	bnez	s5,0xde0
     dd4:	0017b823 	negu	s7,s7
     dd8:	10000002 	b	0xde4
     ddc:	24130001 	li	s3,1
     de0:	00009821 	move	s3,zero
     de4:	0260a821 	move	s5,s3
     de8:	02c0f02a 	slt	s8,s6,zero
     dec:	13c00007 	beqz	s8,0xe0c
     df0:	00000000 	nop
     df4:	16a00003 	bnez	s5,0xe04
     df8:	0016b023 	negu	s6,s6
     dfc:	10000002 	b	0xe08
     e00:	24130001 	li	s3,1
     e04:	00009821 	move	s3,zero
     e08:	0260a821 	move	s5,s3
     e0c:	02e02021 	move	a0,s7
     e10:	0c000329 	jal	0xca4
     e14:	02c02821 	move	a1,s6
     e18:	12a00002 	beqz	s5,0xe24
     e1c:	0040a021 	move	s4,v0
     e20:	0014a023 	negu	s4,s4
     e24:	02801021 	move	v0,s4
     e28:	8fb30010 	lw	s3,16(sp)
     e2c:	8fb40014 	lw	s4,20(sp)
     e30:	8fb50018 	lw	s5,24(sp)
     e34:	8fb6001c 	lw	s6,28(sp)
     e38:	8fb70020 	lw	s7,32(sp)
     e3c:	8fbf0024 	lw	ra,36(sp)
     e40:	27bd0028 	addiu	sp,sp,40
     e44:	03e00008 	jr	ra
     e48:	00000000 	nop
     e4c:	27bdffd8 	addiu	sp,sp,-40
     e50:	afb50010 	sw	s5,16(sp)
     e54:	afb60014 	sw	s6,20(sp)
     e58:	afb70018 	sw	s7,24(sp)
     e5c:	afbf001c 	sw	ra,28(sp)
     e60:	0080b821 	move	s7,a0
     e64:	00a0b021 	move	s6,a1
     e68:	1000000d 	b	0xea0
     e6c:	24150001 	li	s5,1
     e70:	24180001 	li	t8,1
     e74:	afb80024 	sw	t8,36(sp)
     e78:	02c02021 	move	a0,s6
     e7c:	0c0003fc 	jal	0xff0
     e80:	03002821 	move	a1,t8
     e84:	0040b021 	move	s6,v0
     e88:	02a02021 	move	a0,s5
     e8c:	8fb80024 	lw	t8,36(sp)
     e90:	00000000 	nop
     e94:	0c0003fc 	jal	0xff0
     e98:	03002821 	move	a1,t8
     e9c:	0040a821 	move	s5,v0
     ea0:	02d7f02b 	sltu	s8,s6,s7
     ea4:	13c00007 	beqz	s8,0xec4
     ea8:	00000000 	nop
     eac:	12a00005 	beqz	s5,0xec4
     eb0:	00000000 	nop
     eb4:	3c018000 	lui	at,0x8000
     eb8:	02c1c024 	and	t8,s6,at
     ebc:	1300ffec 	beqz	t8,0xe70
     ec0:	00000000 	nop
     ec4:	10000011 	b	0xf0c
     ec8:	00000000 	nop
     ecc:	02f6f02b 	sltu	s8,s7,s6
     ed0:	17c00002 	bnez	s8,0xedc
     ed4:	00000000 	nop
     ed8:	02f6b823 	subu	s7,s7,s6
     edc:	24180001 	li	t8,1
     ee0:	afb80024 	sw	t8,36(sp)
     ee4:	02a02021 	move	a0,s5
     ee8:	0c00042e 	jal	0x10b8
     eec:	03002821 	move	a1,t8
     ef0:	0040a821 	move	s5,v0
     ef4:	02c02021 	move	a0,s6
     ef8:	8fb80024 	lw	t8,36(sp)
     efc:	00000000 	nop
     f00:	0c00042e 	jal	0x10b8
     f04:	03002821 	move	a1,t8
     f08:	0040b021 	move	s6,v0
     f0c:	16a0ffef 	bnez	s5,0xecc
     f10:	00000000 	nop
     f14:	02e01021 	move	v0,s7
     f18:	8fb50010 	lw	s5,16(sp)
     f1c:	8fb60014 	lw	s6,20(sp)
     f20:	8fb70018 	lw	s7,24(sp)
     f24:	8fbf001c 	lw	ra,28(sp)
     f28:	27bd0028 	addiu	sp,sp,40
     f2c:	03e00008 	jr	ra
     f30:	00000000 	nop
     f34:	27bdffd8 	addiu	sp,sp,-40
     f38:	afb50010 	sw	s5,16(sp)
     f3c:	afb60014 	sw	s6,20(sp)
     f40:	afb70018 	sw	s7,24(sp)
     f44:	afbf001c 	sw	ra,28(sp)
     f48:	0080b821 	move	s7,a0
     f4c:	00a0b021 	move	s6,a1
     f50:	afa00024 	sw	zero,36(sp)
     f54:	02e0f02a 	slt	s8,s7,zero
     f58:	13c00004 	beqz	s8,0xf6c
     f5c:	00000000 	nop
     f60:	0017b823 	negu	s7,s7
     f64:	24180001 	li	t8,1
     f68:	afb80024 	sw	t8,36(sp)
     f6c:	02c0f02a 	slt	s8,s6,zero
     f70:	13c00002 	beqz	s8,0xf7c
     f74:	00000000 	nop
     f78:	0016b023 	negu	s6,s6
     f7c:	02e02021 	move	a0,s7
     f80:	0c000393 	jal	0xe4c
     f84:	02c02821 	move	a1,s6
     f88:	0040a821 	move	s5,v0
     f8c:	8fb80024 	lw	t8,36(sp)
     f90:	00000000 	nop
     f94:	13000002 	beqz	t8,0xfa0
     f98:	00000000 	nop
     f9c:	0015a823 	negu	s5,s5
     fa0:	02a01021 	move	v0,s5
     fa4:	8fb50010 	lw	s5,16(sp)
     fa8:	8fb60014 	lw	s6,20(sp)
     fac:	8fb70018 	lw	s7,24(sp)
     fb0:	8fbf001c 	lw	ra,28(sp)
     fb4:	27bd0028 	addiu	sp,sp,40
     fb8:	03e00008 	jr	ra
     fbc:	00000000 	nop
     fc0:	27bdfff8 	addiu	sp,sp,-8
     fc4:	14800003 	bnez	a0,0xfd4
     fc8:	afb70000 	sw	s7,0(sp)
     fcc:	10000004 	b	0xfe0
     fd0:	0000b821 	move	s7,zero
     fd4:	0080c021 	move	t8,a0
     fd8:	3c018000 	lui	at,0x8000
     fdc:	0301b826 	xor	s7,t8,at
     fe0:	02e01021 	move	v0,s7
     fe4:	8fb70000 	lw	s7,0(sp)
     fe8:	03e00008 	jr	ra
     fec:	27bd0008 	addiu	sp,sp,8
     ff0:	00801021 	move	v0,a0
     ff4:	30a80001 	andi	t0,a1,0x1
     ff8:	11000002 	beqz	t0,0x1004
     ffc:	00000000 	nop
    1000:	00021040 	sll	v0,v0,0x1
    1004:	30a80002 	andi	t0,a1,0x2
    1008:	11000002 	beqz	t0,0x1014
    100c:	00000000 	nop
    1010:	00021080 	sll	v0,v0,0x2
    1014:	30a80004 	andi	t0,a1,0x4
    1018:	11000003 	beqz	t0,0x1028
    101c:	00000000 	nop
    1020:	00021080 	sll	v0,v0,0x2
    1024:	00021080 	sll	v0,v0,0x2
    1028:	30a80008 	andi	t0,a1,0x8
    102c:	11000002 	beqz	t0,0x1038
    1030:	00000000 	nop
    1034:	00021200 	sll	v0,v0,0x8
    1038:	30a80010 	andi	t0,a1,0x10
    103c:	11000003 	beqz	t0,0x104c
    1040:	00000000 	nop
    1044:	00021200 	sll	v0,v0,0x8
    1048:	00021200 	sll	v0,v0,0x8
    104c:	03e00008 	jr	ra
    1050:	00000000 	nop
    1054:	00801021 	move	v0,a0
    1058:	30a80001 	andi	t0,a1,0x1
    105c:	11000002 	beqz	t0,0x1068
    1060:	00000000 	nop
    1064:	00021043 	sra	v0,v0,0x1
    1068:	30a80002 	andi	t0,a1,0x2
    106c:	11000002 	beqz	t0,0x1078
    1070:	00000000 	nop
    1074:	00021083 	sra	v0,v0,0x2
    1078:	30a80004 	andi	t0,a1,0x4
    107c:	11000003 	beqz	t0,0x108c
    1080:	00000000 	nop
    1084:	00021083 	sra	v0,v0,0x2
    1088:	00021083 	sra	v0,v0,0x2
    108c:	30a80008 	andi	t0,a1,0x8
    1090:	11000002 	beqz	t0,0x109c
    1094:	00000000 	nop
    1098:	00021203 	sra	v0,v0,0x8
    109c:	30a80010 	andi	t0,a1,0x10
    10a0:	11000003 	beqz	t0,0x10b0
    10a4:	00000000 	nop
    10a8:	00021203 	sra	v0,v0,0x8
    10ac:	00021203 	sra	v0,v0,0x8
    10b0:	03e00008 	jr	ra
    10b4:	00000000 	nop
    10b8:	00801021 	move	v0,a0
    10bc:	30a80001 	andi	t0,a1,0x1
    10c0:	11000002 	beqz	t0,0x10cc
    10c4:	00000000 	nop
    10c8:	00021042 	srl	v0,v0,0x1
    10cc:	30a80002 	andi	t0,a1,0x2
    10d0:	11000002 	beqz	t0,0x10dc
    10d4:	00000000 	nop
    10d8:	00021082 	srl	v0,v0,0x2
    10dc:	30a80004 	andi	t0,a1,0x4
    10e0:	11000003 	beqz	t0,0x10f0
    10e4:	00000000 	nop
    10e8:	00021082 	srl	v0,v0,0x2
    10ec:	00021082 	srl	v0,v0,0x2
    10f0:	30a80008 	andi	t0,a1,0x8
    10f4:	11000002 	beqz	t0,0x1100
    10f8:	00000000 	nop
    10fc:	00021202 	srl	v0,v0,0x8
    1100:	30a80010 	andi	t0,a1,0x10
    1104:	11000003 	beqz	t0,0x1114
    1108:	00000000 	nop
    110c:	00021202 	srl	v0,v0,0x8
    1110:	00021202 	srl	v0,v0,0x8
    1114:	03e00008 	jr	ra
    1118:	00000000 	nop
    111c:	24020000 	li	v0,0
    1120:	00805021 	move	t2,a0
    1124:	00a05821 	move	t3,a1
    1128:	31480001 	andi	t0,t2,0x1
    112c:	11000002 	beqz	t0,0x1138
    1130:	00000000 	nop
    1134:	004b1021 	addu	v0,v0,t3
    1138:	000a5042 	srl	t2,t2,0x1
    113c:	1540fffa 	bnez	t2,0x1128
    1140:	000b5840 	sll	t3,t3,0x1
    1144:	03e00008 	jr	ra
    1148:	00000000 	nop
	...
  400008:	00400000 	0x400000
  40000c:	00400000 	0x400000
  400010:	00400000 	0x400000
  400014:	00400000 	0x400000
