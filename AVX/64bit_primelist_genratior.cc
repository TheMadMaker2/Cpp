/*
resorest
timehttps://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#
https://stackoverflow.com/questions/11103249/raw-file-format-c

https://github.com/ahuston-0 Helped with multithreading Figured out a figured out the algrithum to leftshift 3 and 5

g++ -O3 -g -mavx -pthread -march=native ./avx2_primelist_multy_thread.cc

0 is can be prime 1 isnt

TODO
*/

#include <iostream>
#include <immintrin.h>
#include <vector>
#include <cmath>

using namespace std;


// build a mask where every kth bit is one starting from right
uint64_t buildmask(uint32_t k) {
	uint64_t t = 0;
	const uint64_t mask1 =1ULL;
	for (uint32_t i = 0; i < 644; i += k){
		t |= (t<<k);
	}
	return t;
}

void list_generator(uint64_t s, uint64_t e, uint64_t* prime){

	// 31 0x1000000040000001

	const __m128i mask31_29 = _mm_set_epi64x(buildmask(31),buildmask(29));
	const __m128i mask23_19 = _mm_set_epi64x(buildmask(23),buildmask(19));
	const __m128i mask17_13 = _mm_set_epi64x(buildmask(17),0x0010008004002001);
	const __m128i mask11_7 = _mm_set_epi64x(0x0080100200400801,0x8102040810204081);
	const __m128i mask5_3 = _mm_set_epi64x(0x1084210842108421,0x9249249249249249);

	//loos form s to e making the temp register piking mask based on counter
	for (uint32_t i = s; i < e+1; i++) {

		// pattern 1 2 0
		uint64_t tempmask = _mm_extract_epi64(mask5_3, 0);
		uint64_t temp =  tempmask << ((5+(6-(i%3)))%3);

		// pattern 2 3 4 0 1
		tempmask = _mm_extract_epi64(mask5_3, 1);
		temp |= tempmask << (1+(i%5))%5;

		// pattern 3 2 1 0 6 5 4
		tempmask = _mm_extract_epi64(mask11_7, 0);
		temp |=  tempmask << (5+(6-(i%7)))%7;

		// pattern 4 6 8 10 1 3 5 7 9 0 2
		// tempmask = _mm_extract_epi64(mask11_7, 1);
		// temp |=  tempmask << (6+(i%11))%11;

		// tempmask = _mm_extract_epi64(mask17_13, 0);
		// temp |=  tempmask << (6+(i%13))%13;


		// tempmask = _mm_extract_epi64(mask17_13, 1);
		// temp |=  tempmask << (6+(i%17))%17;

		prime[i-1]=temp;

		// cout << hex << i << " " << temp << endl;
	}
}

// counts the number prime numbers in the array minus the bits that are
uint64_t counter(uint64_t *prime, uint64_t size, uint64_t extra){
uint64_t  temp = 0;
	for (uint64_t i = 0; i <= size-1; i++){
		temp += (64-_mm_popcnt_u64(prime[i]));
	}
	return temp - (extra-_mm_popcnt_u64(prime[size-1]>>(64-extra)));
}

// checks if bit at pos is 0
bool is_prime(uint64_t* prime, uint64_t pos){
	return !(prime[pos>>7] & (1ULL<<((pos>>1)%64)));
}

// checks if bit at pos is 0
void clear_prime(uint64_t* prime, uint64_t pos){
	prime[pos>>7] |= (1ULL<<((pos>>1)%64));
}

void EratosthenesSieve(uint64_t n ,uint64_t* prime,uint64_t size){
	for (uint64_t i = 3; i <= sqrt(n); i+=2){
		if (is_prime(prime,i)){
			for (uint64_t j = i*i; j <= n; j+=2*i)
				clear_prime(prime,j);
		}
	}
}


int main() {
	// The number you want to calculate to
	constexpr uint64_t total = 100000256;
	// calculates next multipule of 128 above total
	constexpr uint64_t mult = (128-(total%128)+total);
	// calculates the difference  between total nad mult
	constexpr uint64_t extra = ((mult-total)>>1);
	// create and list of 64bit ints 128 time smaller then mult
	constexpr uint64_t size = mult>>7;
	uint64_t* prime = new uint64_t[size];

	clock_t t0 = clock();
	list_generator(1,size,prime);


	EratosthenesSieve(mult,prime,size);

	clock_t t1 = clock();
	cout << (t1-t0) * 1e-6 << '\n';

	// This is set the firs 64bit because list_generator dosnt properly calculate the firs bits for the number its masking
	prime[0] = 0x7e92ed659b4b3490;

	cout << dec << counter(prime,size,extra) << endl;

	delete[] prime;
	return 0;
}

