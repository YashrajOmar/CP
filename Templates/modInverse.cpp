const int MAX = 200005;       // Adjust based on problem constraints
const ll mod = 1e9 + 7;

ll modInverse[MAX];  // modular inverse of i modulo mod        i^−1 mod mod
ll fact[MAX];        // i!
ll invfact[MAX];     // (i!)^-1 mod m

// Precompute all factorials and inverses
void precompute() {
    fact[0] = invfact[0] = modInverse[1] = 1;

    for(int i = 2; i < MAX; i++)
        modInverse[i] = mod - mod / i * modInverse[mod % i] % mod;

    for(int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = invfact[i - 1] * modInverse[i] % mod;
    }
}

TC - O(N)

Use for Fast Combinations

ll comb(ll n, ll r) {
    if(r > n || r < 0) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

TC - O(1)
