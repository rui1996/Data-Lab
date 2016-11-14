/* 
 * CS:APP Data Lab 
 * 
 * Rui Qian 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
//1
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
	int x;
	x=(0x49<<24)+(0x49<<12)+0x49+(0x2<<8)+(0x2<<20);
	return x;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	return !((~x+~x+2)|(!x));
}
//2
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	return !!(~x+1+y);     //做减法 相同为零  （！！）用于处理输出 
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
	int t=0xAA;
	t=t+(t<<8);
	t=t+(t<<16);    //创建一个奇数位都是1的数与x做&运算来判断 
	return !!(x&t);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	return ~x+1;  
}
//3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int temp=~!x+1;     
	return (y&~temp)|(z&temp);    //判断x是否为真 用真值表得出最后表达式 
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
	int z=y+(~x);              // 避免溢出情况 之后取符号位并加1得到输出 
	return (((x^y)&(y^z))>>31)+1;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	int signx=(x>>31)&0x1;     //先得出两个的符号 
	int signy=(y>>31)&0x1;
	int result=!((x+((~y)+1))>>31);
	int equal=!!(x+(~y)+1);   //特判相等的情况 
	return ((result&equal)|(signx^signy))&((!signx)|signy);  //已知x为正y为负 x为负y为正有可能会溢出且明显可以直接得出结果 为了避免溢出 用真值表得出表达式 
}
//4
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	x=x^(x>>16);   //二分法 
	x=x^(x>>8);
	x=x^(x>>4);
	x=x^(x>>2);
	x=x^(x>>1); 
	return x&1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int a=x>>31;     
	int abs=x^a;  
    int bit16,bit8,bit4,bit2,bit1,all;   //二分查找
    int adjustzero;
    bit16=(!(!(abs>>16)))<<4;
    abs=abs>>bit16;
    bit8=(!(!(abs>>8)))<<3;
    abs=abs>>bit8;
    bit4=(!(!(abs>>4)))<<2;
    abs=abs>>bit4;
    bit2=(!(!(abs>>2)))<<1;
    abs=abs>>bit2;
    bit1=!(!(abs>>1));
    all=bit16+bit8+bit4+bit2+bit1+2; 
    adjustzero=(!(!abs)<<31)>>31;  //对于0的情况要特殊调整一下 
    return (!abs)|(all&adjustzero);
}
//float
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    unsigned sign=uf>>31;    //取出 sign exp frac 
    unsigned exp=(uf>>23)&0xff;
    unsigned frac=uf&0x7fffff;
    if(exp>0&&exp<0xff)   //对于正常的情况 exp减一即可  
    {
    	exp--;
        if(exp==0)     //若减一后为零 先加上隐藏的1  
        	frac += 1 << 23;
	}	
    if(exp==0)   
	{
    	if ((frac&0x3)==0x3)   //考虑进位问题 
        	frac=(frac>>1)+1;
        else
            frac=frac>>1;
    }
    return ((sign<<31)+(exp<<23)+frac);  //拼出浮点数 
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	unsigned sign=(x>>31);
	unsigned exp,frac,last,frac1,signal;
	int cnt=0;
    if(x==0)    //特判 
	{
    	exp=0;
    	frac=0;
    }
	else if(x==0x80000000)  //特判 
    {
    	exp=158;
    	frac=0;
    }
    else    //正常情况 
    {
    	if(sign)    //对于负数 要取绝对值处理 
    		x=(~x)+1;
    	frac=(x<<1);
    	cnt= 0;
    	while(!(frac&0x80000000))   //不断将frac左移 直到找到第一个1 
    	{
    	    cnt++;
    	    frac=frac<<1;
    	}
    	exp = 157 - cnt;      //通过cnt 得出exp的值 
    	last=((frac>>8)&1);   //取出最后一位 考虑进位问题
    	frac1=(frac&0x7fffffff)>>8;  //即取出frac 为了减少op数 先声明 
    	signal=((frac>>7)&1);   //判断进位 
    	if(last==0)  //处理进位 
    	{
    		if ((frac&0xff)==0x80 || !signal)   
    	    	frac=(frac1);
    	    else
    	        frac=(frac1)+1;
    	}
    	else
    	{
		    if (signal)  
            {
                frac=(frac1)+1;
                if (frac==0x800000)
                {
                    exp++;
                    frac = 0;
                }
            }
            else
            	frac=(frac1);
    	}
    }
	return (sign<<31)+(exp<<23)+frac;   //拼出浮点数 
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	unsigned sign,exp,frac,e;
	sign=(uf>>31)&1;    //取出 sign exp frac 
	exp=(uf>>23)&0xff;
	frac=(uf)&0x7fffff;
	if(exp==0&&frac==0)   //以下是特判不正常的情况 
		return 0;
	else if(exp==158&&frac==0&&sign==1)
	    return 0x80000000;
    else if(exp==0xff)  
        return 0x80000000;
    else if(exp>157)
        return 0x80000000;
    else if(exp<=126)
        return 0;
	else
	{
		e=exp-127;
        frac+=0x800000;  
		if(e==23)   //判断e与23的关系来得出是左移还是右移或者不移动 
		{
 		    frac=frac;
        }	
        if(e>23)
        {
            frac=frac<<(e-23);
        }
        if(e<23)
        {
            frac=frac>>(23-e);
        }
        if(sign==0)  //判断正负之后return 
            return frac;
        else
        	return ((~frac)+1);
	}	
}
