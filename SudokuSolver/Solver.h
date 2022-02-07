#pragma once
#include "Board9x9.h"
#include "BlockLocation.h"
#include <array>
#include <set>

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
		//
		return false;
	}

	bool isUniuqeInItsColumn(const int idx, const int jdx) {
		//
		return false;
	}

	bool isUniqueInItsBox(const int idx, const int jdx  /* location enum*/) {
		//
		return false;
	}

	// todo: factor this out, but make it generic to board lengths
	BlockLocation findBlockLocation(const int idx, const int jdx) {
		//
		if (idx < 3 && jdx < 3) {
			// upper left block
			return BlockLocation::upperLeft;
		}
		else if (idx < 3 && jdx >= 3 && jdx < 6) {
			// upper middle
			return BlockLocation::upperMiddle;
		}
		else if (idx < 3 && jdx >= 6 && jdx < 9) {
			// upper right
			return BlockLocation::upperRight;
		}
		else if (idx >= 3 && idx < 6 && jdx < 3) {
			// middle left
			return BlockLocation::middleLeft;
		}
		else if (idx >= 3 && idx < 6 && jdx >= 3 && jdx < 6) {
			// middle middle
			return BlockLocation::middleMiddle;
		}
		else if (idx >= 3 && idx < 6 && jdx >= 6 && jdx < 9) {
			// middle right
			return BlockLocation::middleRight;
		}
		else if (idx >= 6 && idx < 9 && jdx < 3) {
			// lower left
			return BlockLocation::lowerLeft;
		}
		else if (idx >= 6 && idx < 9 && jdx >= 3 && jdx < 6) {
			// lower middle
			return BlockLocation::lowerMiddle;
		}
		else if (idx >= 6 && jdx < 9 && jdx >= 6 && jdx < 9) {
			// lower right 
			return BlockLocation::lowerRight;
		}
		else {
			assert(false);
		}
	}

	void printer(std::ostream& stream) {
		//
		board_.printer(stream);
	}

	void populateMatrixOfPossibles() {
		for (int idx = 0; idx < length; ++idx) {
			for (int jdx = 0; jdx < length; ++jdx) {
				if (!board_.isCurrValPresentInRow(idx, jdx) && !board_.isCurrValPresentInColumn(idx, jdx) &&
					board_.isCurrValPresentInBlock(idx, jdx, board_.findBlockLocation(idx, jdx))) {
					possibles_[idx][jdx].insert(board_.get(idx,jdx));
				}
			}
		}
	}



private:
	Board9x9 board_;
	matrix possibles_;
};

