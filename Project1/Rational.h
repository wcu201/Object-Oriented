#ifndef RATIONAL
#define RATIONAL

namespace CS1124 {

	class Rational
	{
	public:
		Rational(int numerator, int denominator);
		int greatestCommonDivisor(int x, int y) const;
		double simplified() const;
		int getDem() const;
		int getNum() const;
	};
}


#endif
