#pragma once
#include "Board9x9.h"
#include "BlockLocation.h"
#include "LocationFinder.h"
#include <array>
#include <set>
#include <algorithm>

//constexpr int length = 3;
using matrix = std::array < std::array<std::set<int>, length>, length>;

class Solver
{
public:
	Solver(const Board9x9& board) : board_(board) {

	}

	Board9x9 solve() {
		Board9x9 solvedBoard{};

		// First, calculate the matrix of possibiles
		populateMatrixOfPossibles();

		// Next Loop over every cell in the board and  determine if 
		// it is unique it its row, column, or box.
		// If it is unique in any of those, we have found the value
		// for that cell
		size_t maxIter = 10, iter = 1;
		while (!isBoardSolved(solvedBoard)) {
			for (int idx = 0; idx < length; ++idx) {
				for (int jdx = 0; jdx < length; ++jdx) {
					// check for uniqueness
					bool isunique = isUniqueInItsRow(idx, jdx) && isUniuqeInItsColumn(idx, jdx) &&
						isUniqueInItsBox(idx, jdx, LocationFinder::getBlockLocation(idx,jdx));
					if (isunique) {
						// set solved table to have this value at [idx, jdx]
						// re-populate matrix of possibles
					}
				}
			}
			if (++iter == maxIter) {
				std::cout << "Max number of tries reached\n";
				break;
			}
		}

		return solvedBoard;
	}

	bool isUniqueInItsRow(const int idx, const int jdx) {
		// Iterate through every index in idx*jdx and for each element of the 
		// set at that index check if its value is unique within its row. If
		// it is unique, none of the other cells in this row contain sets with
		// that value.
		auto setAtIdxJdx = possibles_[idx][jdx];
		for (const auto& item : setAtIdxJdx) {
			int target = item;
			for (int rowJdx = 0; rowJdx < length; ++rowJdx) {
				if (rowJdx != idx) {  // self
					auto setAtrowIdx = possibles_[idx][rowJdx];
					if (setAtrowIdx.find(target) != setAtrowIdx.end()) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool isUniuqeInItsColumn(const int idx, const int jdx) {
		//
		auto setAtIdxJdx = possibles_[idx][jdx];
		for (const auto& item : setAtIdxJdx) {
			int target = item;
			for (int colIdx = 0; colIdx < length; ++colIdx) {
				if (colIdx != idx) {  // self
					auto setAtrowIdx = possibles_[colIdx][jdx];
					if (setAtrowIdx.find(target) != setAtrowIdx.end()) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool isUniqueInItsBox(const int idx, const int jdx , const BlockLocation& loc ) {
		//
		auto setAtIdxJdx = possibles_[idx][jdx];
		for (const auto& item : setAtIdxJdx) {
			for (int cellIdx = 0; cellIdx < length; ++cellIdx) {
				for (int cellJdx = 0; cellJdx < length; ++cellJdx) {
					bool isSelf = (cellIdx == idx) && (cellJdx == jdx);
					if (!isSelf && LocationFinder::getBlockLocation(cellIdx, cellJdx) == loc) {
						return true;
					}
				}
			}
		}
		return false;
	}

	bool isBoardSolved(const Board9x9& solutionBoard) {
		for (int idx = 0; idx < length; ++idx) {
			for (int jdx = 0; jdx < length; ++jdx) {
				if (solutionBoard.get(idx, jdx) == 0) {
					return false;
				}
			}
		}
		return true;
	}

	void printer(std::ostream& stream) {
		//
		board_.printer(stream);
	}

	void populateMatrixOfPossibles() {
		for (int idx = 0; idx < length; ++idx) {
			for (int jdx = 0; jdx < length; ++jdx) {
				if (!board_.isCurrValPresentInRow(idx, jdx) && !board_.isCurrValPresentInColumn(idx, jdx) &&
					board_.isCurrValPresentInBlock(idx, jdx, LocationFinder::getBlockLocation(idx, jdx))) {
					possibles_[idx][jdx].insert(board_.get(idx,jdx));
				}
			}
		}
	}



private:
	Board9x9 board_;
	matrix possibles_;
};

