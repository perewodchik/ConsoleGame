#pragma once
#include <iostream>
class Position
{
public:
	Position() : h_(-1), w_(-1) {};
	Position(int h, int w) : h_(h), w_(w) {};
	void setH(int h) { h_ = h; };
	void setW(int w) { w_ = w; };
	int getH() const { return h_; };
	int getW() const { return w_; };
	friend std::ostream& operator<<(std::ostream& os, const Position& pos_)
	{
		os << '(' << pos_.h_ << ", " << pos_.w_ << ")";
		return os;
	};
private:
	int h_, w_;
};

