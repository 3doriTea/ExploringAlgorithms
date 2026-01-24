#pragma once
#include <queue>
#include <stack>
#include "IDataList.h"

template<typename T>
class DataStack : public IDataList<T>
{
public:
	DataStack() : stack_{} {}
	~DataStack() {}

	inline T Out() override { T element{ stack_.top() }; stack_.pop(); return element; }

	inline void In(const T _element) override { stack_.push(_element); }

	inline bool Empty() override { return stack_.empty(); }
private:
	std::stack<T> stack_;
};

template<typename T>
class DataQueue : public IDataList<T>
{
public:
	DataQueue() : queue_{} {}
	~DataQueue() {}

	inline T Out() override { T element{ queue_.front() }; queue_.pop(); return element; }

	inline void In(const T _element) override { queue_.push(_element); }

	inline bool Empty() override { return queue_.empty(); }
private:
	std::queue<T> queue_;
};
