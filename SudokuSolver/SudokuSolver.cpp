#include "SudokuSolver.h"
#include "Board9x9.h"
#include "Solver.h"
#include <iostream>
#include <memory>

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

	//std::unique_ptr<Board9x9> b{ new Board9x9() };
	/*b->applyToAll([](int& val) {++val;});
	b->set(1, 1, 42);
	b->changeAllInBlock(4, BlockLocation::middleMiddle);
	b->printer(std::cout);*/
	

	Board9x9 b;
	b.applyToAll([](int& val) {++val; });
	b.set(1, 1, 42);
	b.changeAllInBlock(4, BlockLocation::middleMiddle);
	b.printer(std::cout);
	std::cout << std::endl;

	Solver s(b);
	s.printer(std::cout);

	return 0;
}