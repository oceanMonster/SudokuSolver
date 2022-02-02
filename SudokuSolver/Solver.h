#pragma once
#include "Board9x9.h"
#include <array>
#include <set>

//constexpr int length = 3;
using matrix = std::array < std::array<std::set<int>, length>, length>;

class Solver
{
public:
	Solver(const Board9x9& board) : board_(board) {

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

