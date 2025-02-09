int countSetBits(int n)
    {
        if(n==0) return 0;
        int x = larPow(n);
        int y = x*(1<< (x-1));
        int z = n - (1 << x);
        return y + z + 1 + countSetBits(z);
    }
    static int larPow(int n){
        int x = 0;
        while((1 << x) <= n){
            x++;
        }
        return x-1;
    }
