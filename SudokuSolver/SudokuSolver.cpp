#include "SudokuSolver.h"
#include "Board9x9.h"
#include "Solver.h"
#include "ScoreKeeper.h"
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
	
	ScoreKeeper* sk = ScoreKeeper::getInstance();
	std::cout << sk->getScore() << "\n";
	sk->setScore(42);
	std::cout << sk->getScore() << "\n";

	ScoreKeeper* sk2 = ScoreKeeper::getInstance();
	std::cout << sk2->getScore() << "\n";
	sk2->setScore(69);
	std::cout << sk2->getScore() << "\n";

	Board9x9 b;
	b.applyToAll([](int& val) {++val; });
	b.set(1, 1, 42);
	b.changeAllInBlock(4, BlockLocation::middleMiddle);
	b.printer(std::cout);
	std::cout << std::endl;

	Solver s(b);
	s.printer(std::cout);
	auto x = s.solve();

	return 0;
}