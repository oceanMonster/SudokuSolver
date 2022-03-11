#pragma once

#include <unordered_map>

class ScoreKeeper
{
public:
	static ScoreKeeper* getInstance() {
		if (!instance_) {
			instance_ = new ScoreKeeper();
		}
		return instance_;
	}

	void setScore(int val) {
		score_ = val;
	}

	int getScore() {
		return score_;
	}

	std::unordered_map<std::string, double> testMap;
private:
	static ScoreKeeper* instance_;
	ScoreKeeper(): score_(14){}
	int score_;
};

