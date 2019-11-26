/**
 * Author: e-maxx
 * Date: 2019-11-26
 * Source: http://www.e-maxx-ru.1gb.ru/algo/eratosthenes_sieve
 * Description: Prime sieve for generating all primes up to a certain limit.
 * Memory: O(\sqrt n)
 * Time: O(n \log \log n)
 */
#pragma once

const int SQRT_MAXN = 100000; // maxN sqaure root
const int S = 10000; //block size (1e4..1e5)
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;
void eratosthenes_sieve_sqrt(int n) {
	int nsqrt = (int) sqrt (n + .0);
	for (int i=2; i<=nsqrt; ++i)
		if (!nprime[i]) {
			primes[cnt++] = i;
			if (i * 1ll * i <= nsqrt)
				for (int j=i*i; j<=nsqrt; j+=i)
					nprime[j] = true;
		}
	for (int k=0, maxk=n/S; k<=maxk; ++k) {
		memset (bl, 0, sizeof bl);
		int start = k * S;
		for (int i=0; i<cnt; ++i) {
			int start_idx = (start + primes[i] - 1) / primes[i];
			int j = max(start_idx,2) * primes[i] - start;
			for (; j<S; j+=primes[i])
				bl[j] = true;
		}
		if (k == 0)
			bl[0] = bl[1] = true;
		for (int i=0; i<S && start+i<=n; ++i)
			if (!bl[i])
				SAVE_PRIME(i);
	}
}
