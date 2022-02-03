#pragma once

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
private:
	static ScoreKeeper* instance_;
	ScoreKeeper(): score_(14){}
	int score_;
};

