int NXOR(int num){
        if(num % 4 == 1) return 1;
        if(num % 4 == 2) return num + 1;
        if(num % 4 == 3) return 0;
        if(num % 4 == 0) return num;
        return 0;
    }
    int findXOR(int l, int r) {
        int temp1 = NXOR(l-1);
        int temp2 = NXOR(r);
        return temp1^temp2;
    }
