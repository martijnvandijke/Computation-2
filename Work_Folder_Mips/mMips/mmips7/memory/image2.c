#define WIDTH   32
#define HEIGHT  32

void main(void)
{
    int a, b, result,todiv;
    int max_int = 255;
	int var;
	int low = 0;
    char *buf_i = (char*)0x401000, *buf_o = (char*)0x402000;
	int aminus  ;
	int aplus  ;
	int bwidth ;
	int bplus ;
	int bminus ;
	int anorml;
    
    for (a = 1; a < HEIGHT - 1; a++)
    {
        for (b = 1; b < WIDTH - 1; b++)
        {
			int aminus = (a - 1) * WIDTH ;
			int aplus = (a + 1) * WIDTH;
			int anormal = a * WIDTH;
			int bwidth = b;
			int bplus = bwidth + 1;
			int bminus = bwidth - 1;


            todiv = (
                         -7*(int)buf_i[aminus + bminus] +
                          5*(int)buf_i[aminus + bwidth    ] +
                          2*(int)buf_i[aminus + bplus] +
                         -1*(int)buf_i[ anormal      + bminus] +
                         15*(int)buf_i[ anormal      + bwidth ] +
                         -1*(int)buf_i[ anormal      + bplus] +
                          2*(int)buf_i[aplus + bminus] +
                          5*(int)buf_i[aplus + bwidth   ] +
                         -7*(int)buf_i[aplus + bplus] +
                        128);
			result = todiv / 13;
			//result = ((todiv)+((low)+*(int *)0x12344321));
			//buf_o[a * WIDTH + b] = ((result)-((max_int)+*(int *)0x12344321));
            /* Clipping */
            if(result<0) buf_o[a * WIDTH + b] = 0;
            else if (result > 255) buf_o[a * WIDTH + b] = (char)255;
            else buf_o[a * WIDTH + b] = result;
        }
    }
}

