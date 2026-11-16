#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9_2_1/Lab_9_2_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest921
{
	TEST_CLASS(UnitTest921)
	{
	public:

		TEST_METHOD(TestMacros)
		{
			Assert::AreEqual(9, SQR(1 + 2));
			Assert::AreEqual(4, ABS(-4));
			Assert::AreEqual(7, MAX(3, 7));
			Assert::AreEqual(3, MIN(3, 7));
			Assert::IsTrue(IN_RANGE(5));
			Assert::IsFalse(IN_RANGE(10));
		}

		TEST_METHOD(TestW)
		{
			// Z = 5 -> перша гілка: w = max^2(x + y, x + z)
			Assert::AreEqual(36.0f, W(1, 2));      // max(3, 6)  = 6
			Assert::AreEqual(4.0f, W(-3, 4));      // max(1, 2)  = 2
			Assert::AreEqual(100.0f, W(2, 8));     // max(10, 7) = 10
		}
	};
}
