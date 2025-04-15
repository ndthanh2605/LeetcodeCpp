const int N = 1e6 + 1;
vector<bool> primes = vector<bool>(N, true);

void sieve() {
    primes[0] = false;
    primes[1] = false;
    for (int i = 1; i * i < N; i++) {
        if (primes[i]) {
            for (int j = i * i ; j < N; j += i) {
                primes[j] = false;
            }
        }
    }
}