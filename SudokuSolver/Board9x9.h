#pragma once
#include "BlockLocation.h"
#include "LocationFinder.h"
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
	//Board9x9(const Board9x9& other) {
	//	//
	//	board_ = other.board_;
	//}

	//Board9x9(Board9x9&& other) = delete;
	Board9x9& operator=(const Board9x9& other) = delete;
	/*Board9x9& operator=(const Board9x9& other) {
		board_ = other.board_;
	}*/
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
				if (!isSelf && LocationFinder::getBlockLocation(idx, jdx) == loc && board_[idx][jdx] == targetVal) {
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
				if (LocationFinder::getBlockLocation(idx, jdx) == loc) {
					board_[idx][jdx] = val;
				}
			}
		}
	}

private:
	std::array<std::array<int, length>, length> board_;
};

