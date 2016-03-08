#define WIDTH   32
#define HEIGHT  32
#define max_int 255
#define sfu0(a, b) ((a) - ((b) + *(int *) 0x12344321))

void main(void)
{
    int a, b, result;
	unsigned int max = 255;
	int var;
    char *buf_i = (char*)0x401000, *buf_o = (char*)0x402000;
    
    for (a = 1; a < HEIGHT - 1; a++)
    {
        for (b = 1; b < WIDTH - 1; b++)
        {
			result = ((
				int a_minus = a - 1;
				unsigned int a_plus  = a + 1;
				int b_minus = b - 1;
				unsigned int b_plus = b - 1;

					-7 * (int)buf_i[(a_minus) * WIDTH + b_minus] +
					5 * (int)buf_i[(a_minus) * WIDTH + b] +
					2 * (int)buf_i[(a_minus) * WIDTH + b_plus] +
					-1 * (int)buf_i[a      * WIDTH + b_minus] +
					15 * (int)buf_i[a      * WIDTH + b] +
					-1 * (int)buf_i[a      * WIDTH + b_plus] +
					2 * (int)buf_i[(a_plus) * WIDTH + b_minus] +
					5 * (int)buf_i[(a_plus) * WIDTH + b] +
					-7 * (int)buf_i[(a_plus) * WIDTH + b_plus] +
					128) / 13);

                         /*-7*(int)buf_i[(a - 1) * WIDTH + b - 1] +
                          5*(int)buf_i[(a - 1) * WIDTH + b    ] +
                          2*(int)buf_i[(a - 1) * WIDTH + b + 1] +
                         -1*(int)buf_i[ a      * WIDTH + b - 1] +
                         15*(int)buf_i[ a      * WIDTH + b    ] +
                         -1*(int)buf_i[ a      * WIDTH + b + 1] +
                          2*(int)buf_i[(a + 1) * WIDTH + b - 1] +
                          5*(int)buf_i[(a + 1) * WIDTH + b    ] +
                         -7*(int)buf_i[(a + 1) * WIDTH + b + 1] +
                        128) / 13);*/

			var = sfu0(result, max_int);
            /* Clipping */
            //if(result<0) buf_o[a * WIDTH + b] = 0;
            //else if (result > 255) buf_o[a * WIDTH + b] = (char)255;
            //else buf_o[a * WIDTH + b] = result;
        }
    }
}

