#pragma once
#include "BlockLocation.h"
#include <array>
#include <iostream>
#include <cassert>


constexpr int length = 9;
constexpr int blockLength = 3;

class board
{
public:
	board() : board_{}
	{
		//
		for (auto & row : board_) {
			row.fill(0);
		}
	}

	board(const board& other) = delete;
	const board& operator=(const board& other) = delete;

	void print() {
		for (auto const& row : board_) {
			for (auto const& cell : row) {
				std::cout << cell << "\t";
			}
			std::cout << "\n";
		}
	}

	void set(int idx, int jdx, int val) {
		//board_.at()
		board_[idx][jdx] = val;
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

	void changeAllInBlock(int val, BlockLocation loc) {
		for (int idx = 0; idx < blockLength; ++idx) {
			for (int jdx = 0; jdx < blockLength; ++jdx) {
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
			return BlockLocation::upperLeft;
		}
		else if (idx < 3 && jdx >= 6 && jdx < 9) {
			// upper right
			return BlockLocation::upperLeft;
		}
		else if (idx >= 3 && idx < 6 && jdx < 3) {
			// middle left
			return BlockLocation::upperLeft;
		}
		else if (idx >= 3 && idx < 6 && jdx >=3 && jdx <6) {
			// middle middle
			return BlockLocation::upperLeft;
		}
		else if (idx >= 3 && idx < 6 && jdx >=6 && jdx < 9) {
			// middle right
			return BlockLocation::upperLeft;
		}
		else if (idx >= 6 && idx < 9 && jdx < 3) {
			// lower left
			return BlockLocation::upperLeft;
		}
		else if (idx >= 6 && idx < 9 && jdx >= 3 && jdx < 6) {
			// lower middle
			return BlockLocation::upperLeft;
		}
		else if (idx >= 6 && jdx < 9 && jdx >= 6 && jdx < 9) {
			// lower right 
			return BlockLocation::upperLeft;
		}
		else {
			assert(false);
		}
	}

	
private:
	std::array<std::array<int, length>, length> board_;
};

