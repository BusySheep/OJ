#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long gcd(long a, long b) {
	if (a < b) {
		swap(a, b);
	}
	while (b) {
		long t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long lcm(long a, long b) {
	return a * b / gcd(a, b);
}

struct RationalNumber {
	long numerator;
	long denominator;
	int sign;
	long integer;
	RationalNumber() {
		numerator = 0;
		denominator = 0;
		sign = 1;
		integer = 0;
	}
	void initial() {
		if (denominator == 0) {
			return;
		}
		if (numerator < 0) {
			numerator = -numerator;
			sign = -sign;
		}
		integer = numerator / denominator;
		numerator %= denominator;
		long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;
	}
	void print() {
		if (denominator == 0) {
			printf("Inf");
			return;
		}
		if (sign == -1) {
			printf("(-");
		}
		if (integer == 0 && numerator == 0) {
			printf("0");
		}
		else if (integer == 0) {
			printf("%ld/%ld", numerator, denominator);
		}
		else if (numerator == 0) {
			printf("%ld", integer);
		}
		else {
			printf("%ld %ld/%ld", integer, numerator, denominator);
		}
		if (sign == -1) {
			printf(")");
		}
	}
	long getNumberator() {
		return integer * denominator + numerator;
	}
};

RationalNumber addOrSub(RationalNumber a, RationalNumber b, int addOrSubFactor) {
	RationalNumber result;
	result.denominator = lcm(a.denominator, b.denominator);
	result.numerator = a.sign * a.getNumberator() * (result.denominator / a.denominator) + addOrSubFactor * b.sign * b.getNumberator() * (result.denominator / b.denominator);
	result.initial();
	return result;
}

RationalNumber mul(RationalNumber a, RationalNumber b) {
	RationalNumber result;
	result.numerator = a.getNumberator() * b.getNumberator();
	result.denominator = a.denominator * b.denominator;
	result.sign = a.sign * b.sign;
	result.initial();
	return result;
}

RationalNumber div(RationalNumber a, RationalNumber b) {
	RationalNumber result;
	result.numerator = a.getNumberator() * b.denominator;
	result.denominator = a.denominator * b.getNumberator();
	result.sign = a.sign * b.sign;
	result.initial();
	return result;
}

int main(void) {
	RationalNumber a, b;
	bool signA, signB;
	scanf("%ld/%ld %ld/%ld", &a.numerator, &a.denominator, &b.numerator, &b.denominator);
	a.initial();
	b.initial();
	a.print(); printf(" + "); b.print(); printf(" = "); addOrSub(a, b, 1).print(); puts("");
	a.print(); printf(" - "); b.print(); printf(" = "); addOrSub(a, b, -1).print(); puts("");
	a.print(); printf(" * "); b.print(); printf(" = "); mul(a, b).print(); puts("");
	a.print(); printf(" / "); b.print(); printf(" = "); div(a, b).print(); puts("");

	system("pause");
	return 0;
}

