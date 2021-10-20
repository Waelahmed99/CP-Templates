long long fast_pow(long long b, long long e){
    long long power = 1;
    while(e){
        if(e & 1) power *= b;
        e >>= 1;
        b *= b;
    }
    return power;
}

long long fast_pow(long long b, long long e, long long mod){
    long long power = 1;
    while(e){
        if(e & 1) power = ((power % mod) * (b % mod)) % mod;
        e >>= 1;
        b = ((b % mod) * (b % mod)) % mod;
    }
    return power % mod;
}