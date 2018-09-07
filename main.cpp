//lab3.cpp
//COSC130
//<YOUR NAME>
//<THE DATE>
#include <cstdio>
struct Real
{
    //sign bit
    int sign;
    //UNBIASED exponent
    long exponent;
    //Fraction including implied 1 at bit index 23
    unsigned long fraction;
};

Real Decode(int float_value);
int Encode(Real real_value);
Real Normalize(Real value);
Real Multiply(Real left, Real right);
Real Add(Real left, Real right);

int main(int argc, char *argv[])
{
    int left, right;
    char op;
    int value;
    Real rLeft, rRight, result;
    if (argc < 4) {
        printf("Usage: %s <left> <op> <right>\n", argv[0]);
        return -1;
    }
    sscanf(argv[1], "%f", (float *)&left);
    sscanf(argv[2], "%c", &op);
    sscanf(argv[3], "%f", (float *)&right);
    rLeft = Decode(left);
    rRight = Decode(right);
    if (op == 'x') {
        result = Multiply(rLeft, rRight);
    }
    else if (op == '+') {
        result = Add(rLeft, rRight);
    }
    else {
        printf("Unknown operator '%c'\n", op);
        return -2;
    }
    value = Encode(result);
    printf("%.3f %c %.3f = %.3f (0x%08x)\n",
           *((float*)&left),
           op,
           *((float*)&right),
           *((float*)&value),
           value
    );
    return 0;
}
//Implement the following functions
/*
Real Decode(int float_value)
{
}
int Encode(Real real_value)
{
}
Real Normalize(Real value)
{
}
Real Multiply(Real left, Real right)
{
}
Real Add(Real left, Real right)
{
}
*/