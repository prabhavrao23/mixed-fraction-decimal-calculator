#include "Fraction.h"
/*
 * The reduce method reduces the fraction and simplifies
 * the sign of the fraction resulting in only the numerator
 * being positive or negative.
 */
void Fraction::reduce() {
    // store if the fraction is positive or negative.
    bool isNegative;
    if ((denominator < 0 && numerator < 0) || (denominator > 0 && numerator > 0)) {
        isNegative = false;
    } else {
        isNegative = true;
    }

    // reset the numerator and denominator to positive
    numerator = abs(numerator);
    denominator = abs(denominator);

    // get the greatest common denominator
    long greatest_common_denominator = gcd(numerator, denominator);

    // reduce the fraction
    numerator = numerator / greatest_common_denominator;
    denominator = denominator / greatest_common_denominator;

    // set the numerator to negative if the fraction was negative.
    if (isNegative) numerator = numerator * -1;

}

/*
 * The gcd method returns the greatest common denominator of two numbers.
 */
long Fraction::gcd(long a, long b) const {
    if (a == 0) {return b;}
    return gcd(b % a, a);
}

Fraction::Fraction(long numerator, long denominator) {
    this->numerator = numerator;
    if(denominator == 0){
        throw std::domain_error("Cant divide by 0");
    }
    else{
        this->denominator = denominator;
    }
    reduce();

}

long Fraction::getNumerator() const{
    return numerator;
}

long Fraction::getDenominator() const{
   return denominator;
}

std::string Fraction::toString() {
    std::stringstream ss;
    ss << getNumerator() << "/" << getDenominator();
    return ss.str();
}

Fraction Fraction::operator+(const Fraction &rhs) const {
    long newNumerator = (this->numerator * rhs.denominator) + (rhs.numerator * this->denominator);
    long newDenominator = (this->denominator * rhs.denominator);
    Fraction sum (newNumerator, newDenominator);
    sum.reduce();
    return sum;

}

Fraction Fraction::operator+(const int rhs) const {
    int newNumerator = (this->getDenominator() * rhs) + this->getNumerator();
    Fraction newFrac = Fraction(newNumerator, this->getDenominator());
    newFrac.reduce();
    return newFrac;
}

Fraction Fraction::operator-(const Fraction &rhs) const {
    long newNumerator = (this->numerator * rhs.denominator) - (rhs.numerator * this->denominator);
    long newDenominator = (this->denominator * rhs.denominator);

    Fraction sum (newNumerator, newDenominator);
    sum.reduce();
    return sum;

}

Fraction Fraction::operator-(const int rhs) const {
    int newNumerator = (this->numerator) - (this->denominator * rhs);
    Fraction newFrac = Fraction(newNumerator, this->getDenominator());
    newFrac.reduce();
    return newFrac;
}

Fraction Fraction::operator/(const Fraction &rhs) const {
    int newNumerator = this->numerator * rhs.denominator;
    int newDenominator = this->denominator * rhs.numerator;
    Fraction newFrac  = Fraction (newNumerator, newDenominator);
    newFrac.reduce();
    return newFrac;
}

Fraction Fraction::operator/(const int rhs) const {
    //int newNumerator = this->numerator * rhs;
    int newDenominator = this->denominator * rhs;
    Fraction newFrac  = Fraction (this->numerator, newDenominator);
    newFrac.reduce();
    return newFrac;
}

Fraction Fraction::operator*(const Fraction &rhs) const {
   int newNumerator = this->numerator * rhs.numerator;
   int newDenominator = this->getDenominator() * rhs.denominator;
   Fraction newFrac  = Fraction (newNumerator, newDenominator);
   newFrac.reduce();
   return newFrac;
}

Fraction Fraction::operator*(const int rhs) const {
    int newNumerator = this->numerator * rhs;
    Fraction newFrac  = Fraction (newNumerator, this->denominator);
    newFrac.reduce();
    return newFrac;
}

Fraction &Fraction ::operator ++ (){
    setNumerator(getNumerator() + 1);
    return *this;

}
Fraction Fraction ::operator ++ (int dummy) {
    Fraction newFrac = *this;
    setNumerator(getNumerator() + 1);
    return newFrac;

}
Fraction &Fraction ::operator -- (){
    setNumerator(getNumerator() - 1);
    return *this;

}
Fraction Fraction::operator -- (int dummy) {
    Fraction newFrac = *this;
    setNumerator(getNumerator() - 1);
    return newFrac;
}

bool Fraction::operator==(const Fraction rhs) const {
    return (this->numerator * rhs.denominator) == (rhs.numerator * this->denominator);
}
bool Fraction::operator<(const Fraction rhs) const {
    return (this->numerator * rhs.denominator) < (rhs.numerator * this->denominator);
}
bool Fraction::operator!=(const Fraction rhs) const {
    return !(*this == rhs);
}
bool Fraction::operator>(const Fraction rhs) const {
    return (this->numerator * rhs.denominator) > (rhs.numerator * this->denominator);
}
bool Fraction::operator>=(const Fraction rhs) const {
    return !(*this < rhs);
}
bool Fraction::operator<=(const Fraction rhs) const {
    return !(*this > rhs);
}

void Fraction::setNumerator(long numerator) {
    this->numerator = numerator;
}

void Fraction::setDenominator(long denominator) {
    this->denominator = denominator;
}

std::ostream& operator << (std::ostream &out,  Fraction rhs){
    out << rhs.toString();
    return out;
}
std::ostream& operator << (std::ostream &out,  Fraction *rhs){
    out << rhs->toString();
    return out;
}
