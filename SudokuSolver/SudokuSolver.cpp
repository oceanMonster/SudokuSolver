#include "board.h"
#include <iostream>
#include <memory>
#include "SudokuSolver.h"

int main() {

	/*while (true) {
		std::cout << "Press 1 to start\n";
		std::cout << "Press any other button to exit\n";

		int val{};
		std::cin >> val;
		if (val == 1) {
			std::cout << "works\n";
		}
		else {
			break;
		}
	}*/

	//std::unique_ptr<board> b{ new board() };
	//b->print();

	std::unique_ptr<board> b{ new board() };
	b->applyToAll([](int& val) {++val;});
	b->set(1, 1, 42);
	b->changeAllInBlock(4, BlockLocation::middleMiddle);
	b->printer(std::cout);

	return 0;
}