#include<iostream>
#include "MathLibrary.h"

using namespace std;

//friend 예제
//friend 함수로 외부에서 private 요소에 접근 가능
/*
class Company {
private:
	int sales, profit;
public:
	friend void sub(Company &c);

	Company(int s, int p) {
		sales = s;
		profit = p;
	}
};

void sub(Company &c) {
	cout << "sales = " << c.sales << ", profit =  " << c.profit << endl;
}


int main(void) {
	Company c1(100, 50);
	sub(c1);


	return 0;
}
*/

//라이브러리 사용(DLL)
/*
void main()
{
    double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
        MathFuncs::MythFuncs::Add(a, b) << endl;
    cout << "a - b = " <<
        MathFuncs::MythFuncs::Subtract(a, b) << endl;
    cout << "a * b = " <<
        MathFuncs::MythFuncs::Multiply(a, b) << endl;
    cout << "a / b = " <<
        MathFuncs::MythFuncs::Divide(a, b) << endl;

    try
    {
        cout << "a / 0 = " <<
            MathFuncs::MythFuncs::Divide(a, 0) << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}
*/

//MathLibrary.h 파일의 코드 내용
/*
#pragma once

#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport)
#else
#define MATHFUNCSDLL_API __declspec(dllimport)
#endif

namespace MathFuncs
{
class MythFuncs
{
    public:
        // Returns a + b
        static MATHFUNCSDLL_API double Add(double a, double b);
        // Returns a - b
        static MATHFUNCSDLL_API double Subtract(double a, double b);
        // Returns a * b
        static MATHFUNCSDLL_API double Multiply(double a, double b);
        // Returns a / b
        // Throws const std::invalid_argument& if b is 0
        static MATHFUNCSDLL_API double Divide(double a, double b);
    };
}
*/

//위의 .h 파일의 함수 코드 구현 내용
/*
namespace MathFuncs
{
    double MythFuncs::Add(double a, double b)
    {
        return a + b;
    }

    double MythFuncs::Subtract(double a, double b)
    {
        return a - b;
    }

    double MythFuncs::Multiply(double a, double b)
    {
        return a * b;
    }

    double MythFuncs::Divide(double a, double b)
    {
        if (b == 0)
        {
            throw invalid_argument("b cannot be zero!");
        }

        return a / b;
    }
}

*/