//lab3.cpp
//COSC130
//Kyle James
//14 September 2018

#include <cstdio>
#include <string>

using namespace std;


/*
 * All of the following functions are just reused
 * from lab1 and are just used to convert binary from
 * int to string and vice versa for manipulation
 * purposes.
 */
char IntToChar(int v) {
    v = v + '0';
    return v;
}

string intToBinary(int toBinary) {
    string finalString;


    int i, remainder, len = 0, j;

    //Handles if the toBinary is negative
    if (toBinary < 0) {
        toBinary *= -1;
        j = toBinary;
        while (j != 0) {
            len++;
            j /= 10;
        }

        //Handles converting the int using the IntToChar function
        for (i = 0; i < len; i++) {
            remainder = toBinary % 10;
            toBinary = toBinary / 10;
            finalString = IntToChar(remainder) + finalString;
        }

        finalString[len] = '\0';
        finalString = "-" + finalString;
    }

        //Handles all other toBinary values but negatives
    else {
        j = toBinary;
        while (j != 0) {
            len++;
            j /= 10;
        }

        //Handles converting the int using the IntToChar function
        for (i = 0; i < len; i++) {
            remainder = toBinary % 10;
            toBinary = toBinary / 10;
            finalString = IntToChar(remainder) + finalString;
        }

        finalString[len] = '\0';
    }

    //If the finalString is empty, aka 0, this replaces the empty toBinary with 0.
    if (finalString == "") {
        finalString = "0";
    }

    return finalString;
}

int StringToInt(string val) {
    int temp = 0, sign = 1;
    int i = 0;

    //Checks if negative
    if (val.at(0) == '-') {
        sign = -1;
        i++;
    }

    //Converts the string to int and adds the values
    while (val[i] >= '0' && val[i] <= '9') {
        temp *= 10;
        temp += val[i] - '0';
        i++;
    }

    return temp * sign;
}


/*
    *
        *           END OF REUSED FUNCTIONS
             *
                 *
                     */


struct Real {
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

int main(int argc, char *argv[]) {
    int left, right;
    char op;
    int value;
    Real rLeft, rRight, result;
    if (argc < 4) {
        printf("Usage: %s <left> <op> <right>\n", argv[0]);
        return -1;
    }
    sscanf(argv[1], "%f", (float *) &left);
    sscanf(argv[2], "%c", &op);
    sscanf(argv[3], "%f", (float *) &right);
    rLeft = Decode(left);
    rRight = Decode(right);
    if (op == 'x') {
        result = Multiply(rLeft, rRight);
    } else if (op == '+') {
        result = Add(rLeft, rRight);
    } else {
        printf("Unknown operator '%c'\n", op);
        return -2;
    }
    value = Encode(result);
    printf("%.3f %c %.3f = %.3f (0x%08x)\n",
           *((float *) &left),
           op,
           *((float *) &right),
           *((float *) &value),
           value
    );
    return 0;
}


/*
 * Begin manually written functions
 */
Real Decode(int float_value) {
    Real numToDecode;
    int temp = float_value;
    string stringExponent;
    string stringFraction;

    string iee754 = intToBinary(temp);

    //Assign the sign
    if (iee754[0] == '0') {
        numToDecode.sign = 0;
    } else {
        numToDecode.sign = 1;
    }


    for (int i = 1; i < 7; i++) {
        stringExponent += iee754[i];
    }

    numToDecode.exponent = StringToInt(stringExponent);

    for (int i = 7; i < 31; i++) {
        stringFraction += iee754[i];
    }

    numToDecode.fraction = StringToInt(stringFraction);


    return numToDecode;
}

int Encode(Real real_value) {
    string sign = intToBinary(real_value.sign);
    string exponent = intToBinary(real_value.exponent);
    string fraction = intToBinary(real_value.fraction);
    string iee754 = sign + exponent + fraction;
    int finalIee754 = StringToInt(iee754);

    return finalIee754;
}

Real Normalize(Real value) {

}

Real Multiply(Real left, Real right) {

}

Real Add(Real left, Real right) {

}