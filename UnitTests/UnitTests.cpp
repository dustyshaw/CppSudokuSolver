#include "pch.h"
#include "CppUnitTest.h"
#include <tuple>
#include "../S-Solver/S-Solver.cpp" // links to my project

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(CheckForValidNumberInSquare383)
		{
			// arrange
			int candidateNumber = 3;
			int boardNums2d[9][9] = {
				{ 5, 3, 4, 6, 7, 2, 1, 9, 8 },
				{ 6, 7, 8, 1, 9, 5, 3, 4, 2 },
				{ 9, 1, 2, 3, 4, 8, 5, 6, 7 },
				{ 8, 5, 9, 4, 2, 6, 7, 1, 0 },
				{ 7, 6, 1, 8, 5, 3, 0, 2, 4 },
				{ 4, 2, 3, 7, 0, 1, 8, 5, 6 },
				{ 9, 6, 1, 0, 8, 7, 3, 4, 5 },
				{ 5, 3, 0, 4, 1, 9, 0, 8, 6 },
				{ 2, 8, 4, 0, 3, 5, 1, 7, 9 } };

			std::tuple<int, int> coord(3, 8);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert 
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(CheckForValidNumberInSquare329)
		{
			// arrange
			int candidateNumber = 9;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 },
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(3, 2);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert 
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(CheckForValidNumberInSquare047)
		{
			// arrange
			int candidateNumber = 7;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, 
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(0, 4);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert 
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(CheckForValidNumberInSquare061)
		{
			// arrange
			int candidateNumber = 1;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(0, 6);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(CheckForInvalidNumberInSquare023)
		{
			// arrange
			int candidateNumber = 3;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 },
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(0, 2);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert: fails because 3 is in the same square
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(CheckForValidNumberInSquare124)
		{
			// arrange
			int candidateNumber = 4;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(1, 2);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert
			Assert::AreEqual(result, true);
		}

		TEST_METHOD(CheckForInvalidNumberInSquare125)
		{
			// arrange
			int candidateNumber = 5;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(1, 2);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert: fails because 5 is in the same square
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(CheckForInvalidNumberInSquare104)
		{
			// arrange
			int candidateNumber = 4;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(1, 0);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert: fails because 4 is in the same column (different square)
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(CheckForInvalidNumberInSquare051)
		{
			// arrange
			int candidateNumber = 1;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(0, 5);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert: fails because 1 is in the same row (different square)
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(CheckForInvalidNumberInSquare227)
		{
			// arrange
			int candidateNumber = 7;
			int boardNums2d[9][9] = {
				{ 5, 3, 0, 6, 0, 0, 0, 9, 8 }, // square 0
				{ 0, 7, 0, 1, 9, 5, 0, 0, 0 }, // square 1
				{ 0, 0, 0, 0, 0, 0, 0, 6, 0 }, // square 2
				{ 8, 0, 0, 4, 0, 0, 7, 0, 0 }, // square 3
				{ 0, 6, 0, 8, 0, 3, 0, 2, 0 }, // square 4
				{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
				{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
				{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };

			std::tuple<int, int> coord(2, 2);

			// act
			bool result = CheckValid2d(candidateNumber, boardNums2d, coord);

			// assert: fails because 7 is in the same column
			Assert::AreEqual(result, false);
		}

		TEST_METHOD(SeeWhatRowOfSquaresIAmIn31)
		{
			// arrange
			std::tuple<int, int> coord(3, 1);
			int answer = 1;

			int rtn = getCurrentRow(coord, false);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatRowOfSquaresIAmIn58)
		{
			// arrange
			std::tuple<int, int> coord(5,8);
			int answer = 1;

			int rtn = getCurrentRow(coord, false);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatRowOfSquaresIAmIn67)
		{
			// arrange
			std::tuple<int, int> coord(6, 7);
			int answer = 2;

			// act
			int rtn = getCurrentRow(coord, false);

			// assert
			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatRowOfSquaresIAmIn88)
		{
			// arrange
			std::tuple<int, int> coord(8, 8);
			int answer = 2;

			int rtn = getCurrentRow(coord, false);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatRowOfSquaresIAmIn08)
		{
			// arrange
			std::tuple<int, int> coord(0, 8);
			int answer = 0;

			int rtn = getCurrentRow(coord, false);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatSmallRowImIn15)
		{
			std::tuple<int, int> coord(1, 5);
			int answer = 1;

			int rtn = getCurrentRow(coord, true);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatSmallRowImIn40)
		{
			std::tuple<int, int> coord(4, 0);
			int answer = 0;

			int rtn = getCurrentRow(coord, true);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatSmallRowImIn87)
		{
			std::tuple<int, int> coord(8, 7);
			int answer = 2;

			int rtn = getCurrentRow(coord, true);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatBigColImIn15)
		{
			std::tuple<int, int> coord(1, 5);
			int answer = 1;

			int rtn = getCurrentCol(coord, false);

			Assert::AreEqual(answer, rtn);
		}

		TEST_METHOD(SeeWhatSmallColImIn15)
		{
			std::tuple<int, int> coord(1, 5);
			int answer = 2;

			int rtn = getCurrentCol(coord, true);

			Assert::AreEqual(answer, rtn);
		}
	};
}
