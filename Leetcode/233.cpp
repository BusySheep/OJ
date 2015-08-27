class Solution {
private:
    int base[20];
    int doCount(int n) {
        if (n <= 0) return 0;
	    int len = 0;
	    int k = n;
	    int head;
	    do {
		    head = k % 10;
		    k /= 10;
		    len++;
	    } while (k > 0);
	    int result = base[len - 2];
	    result *= head; //result *= head - 1 + 1;
	    if (head > 1) {
		    result += pow(10, len - 1);
	    }
	    else if (head == 1) {
		    result += n - pow(10, len - 1) + 1;
	    }
	    result += doCount((n - head * pow(10, len - 1)));
	    return result;
    }
public:
    int countDigitOne(int n) {
        base[0] = 1;
	    for (int i = 1; i < 20; i++) {
		    base[i] = base[i - 1] * 10 + pow(10, i);
	    }
        return doCount(n);
    }
};