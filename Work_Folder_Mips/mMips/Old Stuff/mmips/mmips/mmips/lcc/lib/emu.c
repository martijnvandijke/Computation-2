int CVII4_int;

int
__divu (unsigned int num, unsigned int den)
{
  unsigned int bit = 1;
  unsigned int res = 0;

  while (den < num && bit && !(den & (1L << 31)))
    {
      den <<= 1;
      bit <<= 1;
    }

  while (bit)
    {
      if (num >= den)
        {
          num -= den;
          res |= bit;
        }

      bit >>= 1;
      den >>= 1;
    }

  return res;
}

int
__div (int a, int b)
{
  int neg = 0;
  int res;

  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }

  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }

  res = __divu (a, b);

  if (neg)
    res = -res;

  return res;
}

int
__modu (unsigned int num, unsigned int den)
{
  unsigned int bit = 1;

  while (den < num && bit && !(den & (1L << 31)))
    {
      den <<= 1;
      bit <<= 1;
    }

  while (bit)
    {
      if (num >= den)
          num -= den;

      bit >>= 1;
      den >>= 1;
    }

  return num;
}

int
__mod (int a, int b)
{
  int neg = 0;
  int res;

  if (a < 0)
    {
      a = -a;
      neg = 1;
    }

  if (b < 0)
    b = -b;

  res = __modu (a, b);

  if (neg)
    res = -res;

  return res;
}

#if 0
static unsigned int
udivmodsi4 (unsigned int num, unsigned int den, int modwanted)
{
  unsigned int bit = 1;
  unsigned int res = 0;

  while (den < num && bit && !(den & (1L << 31)))
    {
      den <<= 1;
      bit <<= 1;
    }

  while (bit)
    {
      if (num >= den)
	{
	  num -= den;
	  res |= bit;
	}

      bit >>= 1;
      den >>= 1;
    }

  if (modwanted)
    return num;

  return res;
}

int
__div (int a, int b)
{
  int neg = 0;
  int res;

  if (a < 0)
    {
      a = -a;
      neg = !neg;
    }

  if (b < 0)
    {
      b = -b;
      neg = !neg;
    }

  res = udivmodsi4 (a, b, 0);

  if (neg)
    res = -res;

  return res;
}

int
__divu (int a, int b)
{
  return udivmodsi4 (a, b, 0);
}

int
__mod (int a, int b)
{
  int neg = 0;
  int res;

  if (a < 0)
    {
      a = -a;
      neg = 1;
    }

  if (b < 0)
    b = -b;

  res = udivmodsi4 (a, b, 1);

  if (neg)
    res = -res;

  return res;
}

int
__modu (int a, int b)
{
  return udivmodsi4 (a, b, 1);
}
#endif

#if 0
int
__mul (unsigned int a, int b)
{
  int res = 0;

  while (a != 0)
    {
      if (a & 1)
	res += b;

      a >>= 1;
      b <<= 1;
    }

  return res;
}

unsigned int
__sll (unsigned int a, int b)
{
  if (b & 1)
    a <<= 1;
  if (b & 2)
    a <<= 2;
  if (b & 4)
    a <<= 4;
  if (b & 8)
    a <<= 8;
  if (b & 16)
    a <<= 16;

  return a;
}

int
__sra (int a, int b)
{
  if (b & 1)
    a >>= 1;
  if (b & 2)
    a >>= 2;
  if (b & 4)
    a >>= 4;
  if (b & 8)
    a >>= 8;
  if (b & 16)
    a >>= 16;

  return a;
}

unsigned int
__srl (unsigned int a, int b)
{
  if (b & 1)
    a >>= 1;
  if (b & 2)
    a >>= 2;
  if (b & 4)
    a >>= 4;
  if (b & 8)
    a >>= 8;
  if (b & 16)
    a >>= 16;

  return a;
}
#endif

int
float32_neg (int a)
{
  return a == 0 ? 0 : (a ^ 0x80000000);
}
