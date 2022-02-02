#pragma once
#include "BlockLocation.h"
#include <array>
#include <iostream>
#include <cassert>
#include <functional>


constexpr int length = 9;
constexpr int rowLength = 9;

class Board9x9
{
public:
	Board9x9() : board_{}
	{
		//
		for (auto& row : board_) {
			row.fill(0);
		}
	}

	//Board9x9(const Board9x9& other) = delete;
	//Board9x9(Board9x9&& other) = delete;
	Board9x9& operator=(const Board9x9& other) = delete;
	//Board9x9& operator=(Board9x9&& other) = delete;
	~Board9x9() = default;

	void print() {
		for (auto const& row : board_) {
			for (auto const& cell : row) {
				std::cout << cell << "\t";
			}
			std::cout << "\n";
		}
	}

	void set(int idx, int jdx, int val) {
		board_[idx][jdx] = val;
	}

	int get(int idx, int jdx) {
		return board_[idx][jdx];
	}

	//template<typename T>
	void printer(std::ostream& stream) {
		//
		for (auto const& row : board_) {
			for (auto const& cell : row) {
				stream << cell << "\t";
			}
			stream << "\n";
		}
	}

	bool isCurrValPresentInRow(const int idx, const int jdx) {
		const int targetVal = board_[idx][jdx];
		for (int cellIdx = 0; cellIdx < length; ++cellIdx) {
			if (cellIdx != idx && board_[cellIdx][jdx] == targetVal) {
				return true;
			}
		}
		return false;
	}

	bool isCurrValPresentInColumn(const int idx, const int jdx) {
		const int targetVal = board_[idx][jdx];
		for (int cellIdx = 0; cellIdx < length; ++cellIdx) {
			if (cellIdx != jdx && board_[idx][cellIdx] == targetVal) {
				return true;
			}
		}
		return false;
	}

	bool isCurrValPresentInBlock(const int currIdx, const int currJdx, BlockLocation loc) {
		const int targetVal = board_[currIdx][currJdx];
		for (int idx = 0; idx < length; ++idx) {
			for (int jdx = 0; jdx < length; ++jdx) {
				bool isSelf = (currIdx == idx) && (currJdx == jdx);
				if (!isSelf && findBlockLocation(idx, jdx) == loc && board_[idx][jdx] == targetVal) {
					return true;
				}
			}
		}
	}

	void applyToAll(std::function<void(int&)> fcn) {
		for (auto& row : board_) {
			for (auto& cell : row) {
				fcn(cell);
			}
		}
	}

	void changeAllInBlock(int val, BlockLocation loc) {
		for (int idx = 0; idx < rowLength; ++idx) {
			for (int jdx = 0; jdx < rowLength; ++jdx) {
				if (findBlockLocation(idx, jdx) == loc) {
					board_[idx][jdx] = val;
				}
			}
		}
	}

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


private:
	std::array<std::array<int, length>, length> board_;
};

