#include "Randomer.h"

Randomer::Randomer(const uint32_t _seed) :
	randomEngine_{ _seed }
{
}

Randomer::Randomer() :
	Randomer{ std::random_device{}() }
{
}

Randomer::~Randomer()
{
}

int Randomer::NextInt(int _max)
{
	std::uniform_int_distribution<int> dist{ 0, _max };
	return dist(randomEngine_);
}
