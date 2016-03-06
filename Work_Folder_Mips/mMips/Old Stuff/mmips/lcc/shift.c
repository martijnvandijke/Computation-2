/*
 * Two shift tests
 *
 * 1) Test software shift routines.
 *      mem[0x0] = 0x14
 *      mem[0x10] = 0x13
 *
 * 2) Store a value in memory as int and print it as a string in memory
 *      mem[0x0] = 0xffffffff
 *      mem[0x4..0xb] = "FFFFFFFF" (0x46 0x46 0x46 0x46 0x46 0x46 0x46 0x46)
 *      mem[0x10[ = 0x12345678
 *      mem[0x14..0x1b] = "12345678" (0x31 0x32 0x33 0x34 0x35 0x36 0x37 0x38)
 */
 
#define TST1
/*#define TST2 */

void main (void)
{
    int *int1_out_ptr = (int*)0x0;
    int *int2_out_ptr = (int*)0x10;

#ifdef TST2
    char *digit = "0123456789ABCDEF";
    int int1,int2;
    int i;
    char *int1_out_str = (char*)0x4;
    char *int2_out_str = (char*)0x14;
#endif

#ifdef TST1
    *int1_out_ptr = 1;
    *int1_out_ptr = (*int1_out_ptr << 4) + (4 & 15);

    *int2_out_ptr = 1;
    *int2_out_ptr = (*int2_out_ptr << 4) + (3 & 15);
#endif

#ifdef TST2
    int1 = -1;
    *int1_out_ptr = 0;
    for (i = 7; i >= 0; i--)
        *int1_out_ptr = *int1_out_ptr*16 + ((int1 >> (4 * i)) & 15);
    for (i = 7; i >= 0; i--)
        int1_out_str[7-i] = digit[(int1 >> (4 * i)) & 15];

    int2 = 0x12345678;
    *int2_out_ptr = 0;
    for (i = 7; i >= 0; i--)
        *int2_out_ptr = *int2_out_ptr*16 + ((int2 >> (4 * i)) & 15);
    for (i = 7; i >= 0; i--)
        int2_out_str[7-i] = digit[(int2 >> (4 * i)) & 15];
#endif
}
