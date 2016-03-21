#define WIDTH   32
#define HEIGHT  32
#define max_int 255
#define sfu0(a, b) ((a) + ((b) + *(int *) 0x12344321))

void main(void)
{
    int a, b, result;
    int max = 255;
	int var;
    char *buf_i = (char*)0x401000, *buf_o = (char*)0x402000;
	//int unsigned height_min = HEIGHT - 1;
	//int unsigned width_min = WIDTH - 1;

    for (a = 1; a < HEIGHT - 1; a++)
    {
        for (b = 1; b < WIDTH - 1; b++)
        {
			int aminus = a - 1 ;
			int unsigned aplus = a + 1;
			
			int unsigned b_width = WIDTH + b;
			int unsigned bplus = b_width + 1 ;
			int bminus = b_width -1 ;
			//int unsigned rest = 128 / 13;
			//int unsigned vijfplus = 5;
			//int unsigned tweeplus = 2;
			//int unsigned vijftien = 15;
			//int unsigned dertiende = 1 / 13;
			//int min7 = -7;
			//int min1 = -1;

			result = ((
				-7 * (int)buf_i[(aminus)* bminus] +
				5*(int)buf_i[(aminus)* b_width] +
				2*(int)buf_i[(aminus)* bplus] +
				-1 * (int)buf_i[a      * bminus] +
				15 * (int)buf_i[a      * b_width] +
				-1 * (int)buf_i[a      * bplus] +
				2*(int)buf_i[(aplus ) * bminus] +
				5*(int)buf_i[(aplus) * b_width] +
				-7 * (int)buf_i[(aplus) * bplus] + 128) / 13 );

			//var = sfu0(result, max_int);
            /* Clipping */
            if(result<0) buf_o[a * WIDTH + b] = 0;
            else if (result > 255) buf_o[a * WIDTH + b] = (char)255;
            else buf_o[a * WIDTH + b] = result;
        }
    }
}

