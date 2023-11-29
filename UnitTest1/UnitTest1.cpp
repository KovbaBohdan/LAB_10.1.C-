#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_10.1 C++/lab_10.1.C++.cpp"
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const string filename = "test.txt"; // ��'� ��������� �����

            // ��������� ��������� �����
            ofstream testFile(filename);
            if (!testFile.is_open()) {
                Assert::Fail(L"Failed to create test file");
            }

            const string testData = "aaaabbbbccccdddd"; // ��� ��� ����������

            // ����� ����� � �������� ����
            testFile << testData;
            testFile.close();

            // ������ ������� ��� ��������� �������������
            ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                Assert::Fail(L"Failed to open test file for counting");
            }

            int result = Count(inputFile);

            inputFile.close();

            // �������� ����������
            Assert::AreEqual(4, result);
		}
	};
}
