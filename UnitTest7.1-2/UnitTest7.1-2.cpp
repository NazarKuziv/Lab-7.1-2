#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 7.1-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest712
{
	TEST_CLASS(UnitTest712)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { {1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
			int* pa[3] = { a[0], a[1], a[2] };

			Sort(pa, 3, 3);

			Assert::AreEqual( a[0][0] , 7 );
		}
	};
}
