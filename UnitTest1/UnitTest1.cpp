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
            const string filename = "test.txt"; // Ім'я тестового файлу

            // Створення тестового файлу
            ofstream testFile(filename);
            if (!testFile.is_open()) {
                Assert::Fail(L"Failed to create test file");
            }

            const string testData = "aaaabbbbccccdddd"; // Дані для тестування

            // Запис даних у тестовий файл
            testFile << testData;
            testFile.close();

            // Виклик функції для підрахунку послідовностей
            ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                Assert::Fail(L"Failed to open test file for counting");
            }

            int result = Count(inputFile);

            inputFile.close();

            // Перевірка результату
            Assert::AreEqual(4, result);
		}
	};
}
