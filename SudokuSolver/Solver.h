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
		for (int idx = 0; idx < length; ++idx) {
			for (int jdx = 0; jdx < length; ++jdx) {
				// check for uniqueness
				bool isunique = isUniqueInItsRow(idx, jdx) && isUniuqeInItsColumn(idx, jdx) &&
					isUniqueInItsBox(idx, jdx);
				if (isunique) {
					// set solved table to have this value at [idx, jdx]
					// re-populate matrix of possibles
				}
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
			for (int rowIdx = 0; rowIdx < length; ++rowIdx) {
				if (rowIdx != idx) {  // self
					auto setAtrowIdx = possibles_[rowIdx][jdx];
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
		return false;
	}

	bool isUniqueInItsBox(const int idx, const int jdx  /* location enum*/) {
		//
		return false;
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

