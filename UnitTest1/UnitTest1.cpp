#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.3/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int colCount = 0;
			const int rowNo = 0;
			int** a = { };
			Print(a, rowNo,colCount);
			Assert::AreEqual(3, 3);
		}
	};
}
