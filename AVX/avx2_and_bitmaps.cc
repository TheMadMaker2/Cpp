#include <iostream>
#include "immintrin.h"

using namespace std;


//g++ -mavx -march=native ./test.cpp 

//zeroupper _mm256_zeroupper(); posibal alteritave


// Night not be neseseyr just star with a 3 bit mask[[]]
__m256i fill(__m256i n){
	n = _mm256_set_epi64x(0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF);
return n;
}

__m256i two(__m256i n){
	n = _mm256_set_epi64x(0x5555555555555555, 0x5555555555555555, 0x5555555555555555, 0x5555555555555555);
return n;
}

__m256i avxand(__m256i n,__m256i b,__m256i c,__m256i d,__m256i e,__m256i f){

n = _mm256_and_si256(n, b);
n = _mm256_and_si256(n, c);
n = _mm256_and_si256(n, d);
n = _mm256_and_si256(n, e);
n = _mm256_and_si256(n, f);

return n;
}

void out(__m256i a){
cout << hex << _mm256_extract_epi64(a, 3) << endl;
cout << hex << _mm256_extract_epi64(a, 2) << endl;
cout << hex << _mm256_extract_epi64(a, 1) << endl;
cout << hex << _mm256_extract_epi64(a, 0) << endl;
cout << endl;
}

void testtest(uint64_t n){
uint64_t test, testa = 1, testb = 2, testc = 3;

test = (n+255)/256;
cout << test << endl;
__m256i list[test] = {};

for (uint64_t i = 0; i < test; i++)
	list[i] = _mm256_set_epi64x(0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF, 0XFFFFFFFFFFFFFFFF);

for (uint64_t i = 0; i < test; i++){

	if (i==0)
		list[i] = _mm256_set_epi64x(0xF6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
	
	if (i==testa){
		list[i] = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);
		testa+=3;
	}
  
	if (i==testb){
		list[i] = _mm256_set_epi64x(0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D);
		testb+=3;
	}
  
	if (i==testc){
		list[i] = _mm256_set_epi64x(0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
		testc+=3;
	}
	
}

for (uint64_t i = 0; i < test; i++)
	out(list[i]);

}

/*

setp 1
d451441411441050

3 64bit ints +1 for the first one i think tht can be remove with difrent logic
c = _mm256_set_epi64x(0xF6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);

c = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);
c = _mm256_set_epi64x(0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D);
c = _mm256_set_epi64x(0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
c = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);

6DB6DB6DB6DB6DB6
 DB6DB6DB6DB6DB6D
  B6DB6DB6DB6DB6DB

can probably made into 1 INT in with rol

5 64bit ints +1 for the first one i think tht can be remove with difrent logic
d = _mm256_set_epi64x(0xFF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B);

d = _mm256_set_epi64x(0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7);
d = _mm256_set_epi64x(0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF);
d = _mm256_set_epi64x(0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE);
d = _mm256_set_epi64x(0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD);
d = _mm256_set_epi64x(0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B);
d = _mm256_set_epi64x(0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7);

DEF7BDEF7BDEF7BD
EF7BDEF7BDEF7BDE
F7BDEF7BDEF7BDEF
7BDEF7BDEF7BDEF7
BDEF7BDEF7BDEF7B

7 64bit ints +1 for the first one i think tht can be remove with difrent logic
e = _mm256_set_epi64x(0xFFF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF);

e = _mm256_set_epi64x(0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF);
e = _mm256_set_epi64x(0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7);
e = _mm256_set_epi64x(0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E);
e = _mm256_set_epi64x(0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF);
e = _mm256_set_epi64x(0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD);
e = _mm256_set_epi64x(0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF);
e = _mm256_set_epi64x(0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB);

FDFBF7EFDFBF7EFD
 DFBF7EFDFBF7EFDF

FBF7EFDFBF7EFDFB
 BF7EFDFBF7EFDFBF

F7EFDFBF7EFDFBF7
7EFDFBF7EFDFBF7E
EFDFBF7EFDFBF7EF

can probably made into 5 INTs in with rol

11 64bit ints +1 for the first one i think tht can be remove with difrent logic
f = _mm256_set_epi64x(0xFFFFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF);

f = _mm256_set_epi64x(0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F);
f = _mm256_set_epi64x(0xEFFDFFBFF7FEFFDF, 0xFBFF7FEFFDFFBFF7, 0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF);
f = _mm256_set_epi64x(0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF, 0xFDFFBFF7FEFFDFFB);
f = _mm256_set_epi64x(0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F, 0xEFFDFFBFF7FEFFDF);
f = _mm256_set_epi64x(0xFBFF7FEFFDFFBFF7, 0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF);
f = _mm256_set_epi64x(0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF, 0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE);
f = _mm256_set_epi64x(0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F, 0xEFFDFFBFF7FEFFDF, 0xFBFF7FEFFDFFBFF7);
f = _mm256_set_epi64x(0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF);
f = _mm256_set_epi64x(0xF7FEFFDFFBFF7FEF, 0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF);
f = _mm256_set_epi64x(0xBFF7FEFFDFFBFF7F, 0xEFFDFFBFF7FEFFDF, 0xFBFF7FEFFDFFBFF7, 0xFEFFDFFBFF7FEFFD);
f = _mm256_set_epi64x(0xFFBFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF);
f = _mm256_set_epi64x(0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F);


FBFF7FEFFDFFBFF7
 BFF7FEFFDFFBFF7F

F7FEFFDFFBFF7FEF
 F7FEFFDFFBFF7FEF

FEFFDFFBFF7FEFFD
 EFFDFFBFF7FEFFDF

FDFFBFF7FEFFDFFB
 DFFBFF7FEFFDFFBF
  FFBFF7FEFFDFFBFF

7FEFFDFFBFF7FEFF
FFDFFBFF7FEFFDFF

can probably made into 6 INTs in with rol

*/

int main(){
	__m256i a;

	a = two(a);

	a = a << 2;

	out(a);

	uint64_t test;

	__m128i b, c;

	b = _mm_set_epi64x(0x9249249249249249, 0x9249249249249249);
	
	

	test =_bextr_u64( _mm_extract_epi64 (b, 0), 64, 4);


	cout <<  test << endl;

	// _bextr2_u64
	c = _mm_set_epi64x(1, 2);

	// b = _mm_slli_si128(b, 7);
	// 49924924924924924900000000000000
	// shits buy byt not bits
	// b = _mm_srav_epi32(b, c);
	// 92492492249249249249249212492492
	// no ide but not what i want
	// b = _mm_sllv_epi64(b, c);
	// 24924924924924924924924924924924
	// dos wha ti want but you need to comput section indevigualy
	// b = b << 4;
	// 24924924924924902492492492492490
	// it treat it as 2 6b bit ints
	
	cout << hex << _mm_extract_epi64 (b, 1) << endl;
	cout << hex << _mm_extract_epi64 (b, 0) << endl;	

	// testtest(10000000);

	return 0;
}

/*
__m256i a, b, c, d, e, f;

Original

//1
a = fill(a);
b = _mm256_set_epi64x(0xD555555555555555, 0x5555555555555555, 0x5555555555555555, 0x5555555555555555);
c = _mm256_set_epi64x(0xF6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
d = _mm256_set_epi64x(0xFF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B);
e = _mm256_set_epi64x(0xFFF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF);
f = _mm256_set_epi64x(0xFFFFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF);

a = avxand(a, b, c, d, e, f);

out(a);

// _mm256_and_epi64x(mi a,mi b)

//2
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);
d = _mm256_set_epi64x(0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7);
e = _mm256_set_epi64x(0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB);
f = _mm256_set_epi64x(0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F);

a = avxand(a, b, c, d, e, f);

out(a);

//3
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D);
d = _mm256_set_epi64x(0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF);
e = _mm256_set_epi64x(0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF);
f = _mm256_set_epi64x(0xEFFDFFBFF7FEFFDF, 0xFBFF7FEFFDFFBFF7, 0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF);

a = avxand(a, b, c, d, e, f);

out(a);

//4
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
d = _mm256_set_epi64x(0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE);
e = _mm256_set_epi64x(0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7);
f = _mm256_set_epi64x(0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF, 0xFDFFBFF7FEFFDFFB);

a = avxand(a, b, c, d, e, f);

out(a);

//5
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);
d = _mm256_set_epi64x(0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD);
e = _mm256_set_epi64x(0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E);
f = _mm256_set_epi64x(0xFF7FEFFDFFBFF7FE, 0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F, 0xEFFDFFBFF7FEFFDF);

a = avxand(a, b, c, d, e, f);

out(a);

//6
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
d = _mm256_set_epi64x(0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B);
e = _mm256_set_epi64x(0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF);
f = _mm256_set_epi64x(0xFBFF7FEFFDFFBFF7, 0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF);

a = avxand(a, b, c, d, e, f);

out(a);

//7
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6);
d = _mm256_set_epi64x(0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF, 0x7BDEF7BDEF7BDEF7);
e = _mm256_set_epi64x(0xDFBF7EFDFBF7EFDF, 0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD);
f = _mm256_set_epi64x(0xDFFBFF7FEFFDFFBF, 0xF7FEFFDFFBFF7FEF, 0xFDFFBFF7FEFFDFFB, 0xFF7FEFFDFFBFF7FE);

a = avxand(a, b, c, d, e, f);

out(a);

//8
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D);
d = _mm256_set_epi64x(0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE, 0xF7BDEF7BDEF7BDEF);
e = _mm256_set_epi64x(0xFBF7EFDFBF7EFDFB, 0xF7EFDFBF7EFDFBF7, 0xEFDFBF7EFDFBF7EF, 0xDFBF7EFDFBF7EFDF);
f = _mm256_set_epi64x(0xFFDFFBFF7FEFFDFF, 0xBFF7FEFFDFFBFF7F, 0xEFFDFFBFF7FEFFDF, 0xFBFF7FEFFDFFBFF7);

a = avxand(a, b, c, d, e, f);

out(a);

//9
a = fill(a);
b = two(b);
c = _mm256_set_epi64x(0xB6DB6DB6DB6DB6DB, 0x6DB6DB6DB6DB6DB6, 0xDB6DB6DB6DB6DB6D, 0xB6DB6DB6DB6DB6DB);
d = _mm256_set_epi64x(0x7BDEF7BDEF7BDEF7, 0xBDEF7BDEF7BDEF7B, 0xDEF7BDEF7BDEF7BD, 0xEF7BDEF7BDEF7BDE);
e = _mm256_set_epi64x(0xBF7EFDFBF7EFDFBF, 0x7EFDFBF7EFDFBF7E, 0xFDFBF7EFDFBF7EFD, 0xFBF7EFDFBF7EFDFB);
f = _mm256_set_epi64x(0xFEFFDFFBFF7FEFFD, 0xFFBFF7FEFFDFFBFF, 0x7FEFFDFFBFF7FEFF, 0xDFFBFF7FEFFDFFBF);


a = avxand(a, b, c, d, e, f);

out(a);
*/

/*
cout << test << endl;
test = test & 0xD555555555555555;
cout << test << endl;
test = test & 0xF6DB6DB6DB6DB6DB;
cout << test << endl;
test = test & 0xFF7BDEF7BDEF7BDE;
cout << test << endl;
*/


/*
3 5 7 9 11 13 1 

   2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26  64 bit a maks
2  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  D555555555555555 
3  1  1  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  F6DB6DB6DB6DB6DB F 6DB 6DB 6DB 6DB 6DB 
5  1  1  1  1  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  FF7BDEF7BDEF7BDE F F7BDE F7BDE F7BDE 
7  1  1  1  1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1  1  FFF7EFDFBF7EFDFB F3 F7EFDFB F7EFDFB
11 1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  1  1  1  1  0  1  1  1  1	
	23456789 01234567891
	11111111  11111111111111111111111111111111111111111111111111111111
2 1101010101010101010101010101010101010101010101010101010101010101
3 1111011011011011011011011011011011011011011011011011011011011011
  1111011011011011011011011011011011011011011011011011011011011011
5 1111111101111011110111101111011110111101111011110111101111011110
7 1111111111111111

   23456789 !123456789 @123456789 #123456789 $123456789 %123456789^12345
2  11010101  0101010101  0101010101  0101010101  0101010101  0101010101 010101  5555555555555555
3  1111011011011011011011011011011011011011011011011011011011011011  F6DB6DB6DB6DB6DB
5  1111111101111011110111101111011110111101111011110111101111011110  FF7BDEF7BDEF7BDE
7  1111111111110111111011111101111110111111011111101111110111111011  FFF7EFDFBF7EFDFB
11 1111111111111111111101111111111011111111110111111111101111111111  FFF FF7FEFFDFFB FF7FEFFDFFB FF7FEFFDFFB FF7FEFFDFFBFF


3 101011010100 924  
5 010000100001 421
7 001011111010 204

23456789 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
11010100  0  1   0  1  0  0  0  1  0  1  0  0  0  1  0  0  0  0  0  1010000010001010001010001000001010000

1111111111111111111111111111111111111111111111111111111111111111
1101010101010101010101010101010101010101010101010101010101010101
1101010001010001010001010001010001010001010001010001010001010001
1101010001010001010001000001010000010001010001010001000001010000

1101000101010001010001000101010100010101010001000101000101010000

9 21 27 33
hex d051441411441050450441011451010441441410451050451401401451050451
Bin 1101000001010001010001000001010000010001010001000001000001010000010001010000010001000001000000010001010001010001000000010000010001000001010001000001010000010000010001010001000001010000010001010001010000000001010000000001010001010001000001010000010001010001
d0514414114410504504410114510104414414104510504514014014510504514414114500500514414114410504504410114510104414414104510504514014
5051441411441050450441011451010441441410451050451401401451050451

d
05144141144105045044101145101044144141045105045140140145105045104141141104045144041105105041144141145005005144141144105045044101145101044144141045105045140140145105045104141141104045144041105

d
0514414114410504 5044101145101044 1441410451050451 4014014510504510   4141141104045144 0411051050411441 411450050
D555555555555555 D555555555555555 D555555555555555 D555555555555555   D555555555555555 D555555555555555 D555555555555555

051441411441050450441011451010441441410451050451401401451050451041411411040451440411051050411441411450050
051441411441050450441011451010441441410451050

d
051441411441050450441011451010441441410451050451401401451050451041411411040451440411051050411441411450050
051441411441050450441011451010441441410451050451401401451050451041411411040451440411051050411441411450050
0514414114410504504410114510104414414104510504514014014510504510414114110404514404110510504114414114500500514

d45144141144105045044101145100044140141045105005140040145105044104141141104045104041005105041144141141005005144101144005045044100145101044144141005105045140140144105041104141141104045044041105104041140141145005005144041144105044044101145101044104141045105045140140141105045104101141004045144040105101041144141105005005140051440411051050401441411450050051041410441050450441011411010441441010450050451401401451010451041411011040451440411041050411441411450050050441411441040450401011451010041440410451050441401401451050451041410411040451440411011050411441011450050051441401441010

23456789 1123456789 2123456789 3123456789 4123456789 5123456789 6123456789 7123456789 8123456789 9123456789 0123456789
11010000  0101000101  0001000001  0100000100  0101000100  0001000001  0100000100  0101000001  0001000001  0000000100  0101000101 000100000000000001000100000101000000000101000001000001000101000100000101000000000101000101000000000001000000000101000101000100000101000001000100000100000100000101000001000101000001000100000100000001000101000100000100000001000001000000000101000100000101000001000001000101000100000101000001000101000001000000000101000000000101000101000100

   23456789 1123456789 2123456789 3123456789 4123456789 5123456789 6123456789 7123456789 8123456789 9123456789 0123456789
2  11010101  0101010101  0101010101  0101010101  0101010101  0101010101  010101 
3  11110110 1101101101 1011011011 0110110110 1101101101 1011011011 011011
5  11111111 0111101111 0111101111 0111101111 0111101111 0111101111 011110
7  11111111 1111011111 1011111101 1111101111 1101111110 1111110111 111011
11 11111111 1111111111 1101111111 1110111111 1111011111 1111101111 111111

2  D555555555555555
3  F6DB6DB6DB6DB6DB
5  FF7BDEF7BDEF7BDE
7  FFF7EFDFBF7EFDFB
11 FFFFF7FEFFDFFBFF
[]
With out evens
   3  5  7  9  11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99
 3 0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0  1  1  0    
 5 1  1  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1  1  1  0  1  1
 7 1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1  1  1  0  1  1  1  1
11 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  1  1  1  1  0  1  1  1  1  1  1  1  1  1  1  0  


Multy threibal ?
p1 p2 p3
3  5  7

1 10000 10001 20000


123123123123123123 123123123123123 123123123123123 123123123123123123
123451234512345123 451234512345123 451234512345123 451234512345123451
123456712345671234 567123456712345 671234567123456 712345671234567123
1234567890-1234567 890-1234567890- 1234567890-1234 567890-1234567890-

*/
