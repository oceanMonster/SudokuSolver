#include "SudokuSolver.h"
#include "Board9x9.h"
#include "Solver.h"
#include "ScoreKeeper.h"
#include <iostream>
#include <memory>
#include <string_view>
#include <algorithm>
#include <sstream>
#include <iterator>

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

	const char* c = "some    raw         string";
	std::string_view sv(c);
	std::cout << sv << "\n";
	std::cout << sv.size() << "\n";
	std::cout << sv.empty() << "\n";

	std::string a = "3";
	double b2 = atof(a.c_str());
	std::cout << b2 << std::endl;

	std::istringstream iss(c);
	std::vector<std::string> svv;
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(svv));

	for (const auto& word : svv) {
		std::cout << word << "\n";
	}
	return 0;
}