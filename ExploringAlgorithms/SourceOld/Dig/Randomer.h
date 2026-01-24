#pragma once
#include <random>
#include <cstdint>

class Randomer
{
public:
	/// <summary>
	/// シード値指定
	/// </summary>
	/// <param name="_seed">シード値</param>
	Randomer(const uint32_t _seed);
	/// <summary>
	/// シード値を本当のランダム
	/// </summary>
	Randomer();
	~Randomer();

	/// <summary>
	/// 次の乱数を生成する
	/// </summary>
	/// <param name="_max">最大値</param>
	/// <returns>乱数整数値</returns>
	int NextInt(int _max = INT_MAX);

private:
	std::mt19937 randomEngine_;  // 乱数エンジン
};
