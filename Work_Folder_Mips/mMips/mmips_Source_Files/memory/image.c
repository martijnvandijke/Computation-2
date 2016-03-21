#define WIDTH   32
#define HEIGHT  32

void main(void)
{
    int a, b, result;
    int max = 255;
    char *buf_i = (char*)0x401000, *buf_o = (char*)0x402000;
    
    for (a = 1; a < HEIGHT - 1; a++)
    {
        for (b = 1; b < WIDTH - 1; b++)
        {
			int aminus = (a - 1) * WIDTH;
			int unsigned aplus = (a + 1) * WIDTH;
			int atimes = a * WIDTH;
			int unsigned bplus = b + 1;
			int bminus = b - 1;


            result=((
                         -7*(int)buf_i[aminus + bminus] +
                          5*(int)buf_i[aminus  + b    ] +
                          2*(int)buf_i[aminus  + bplus] +
                         -1*(int)buf_i[atimes    + bminus] +
                         15*(int)buf_i[atimes       + b    ] +
                         -1*(int)buf_i[atimes      + bplus] +
                          2*(int)buf_i[aplus  + bminus] +
                          5*(int)buf_i[aplus  + b    ] +
                         -7*(int)buf_i[aplus  + bplus] +
                        128) / 13);

            /* Clipping */
            if(result<0) buf_o[a * WIDTH + b] = 0;
            else if (result > 255) buf_o[a * WIDTH + b] = (char)255;
            else buf_o[a * WIDTH + b] = result;
        }
    }
}

