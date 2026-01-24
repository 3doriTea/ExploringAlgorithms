#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

MapLoader::MapLoader() :
	width_{ 0 },
	height_{ 0 },
	tiles_{}
{
}

MapLoader::~MapLoader()
{
}

bool MapLoader::TryLoad(fs::path _file)
{
	std::ifstream ifs{ _file };
	if (!ifs)
	{
		assert(false && "ファイルが開けない");
		return false;
	}

	std::string line{};

	if (!std::getline(ifs, line))
	{
		assert(false && "最初の行の取得に失敗");
		return false;
	}

	std::stringstream ss{ line };

	std::string numStr{};
	if (!std::getline(ss, numStr, ','))
	{
		assert(false && "横幅取得に失敗");
		return false;
	}
	width_ = std::stoi(numStr);

	if (!std::getline(ss, numStr, ','))
	{
		assert(false && "縦幅取得に失敗");
		return false;
	}
	height_ = std::stoi(numStr);

	int lineCount{ 0 };
	while (std::getline(ifs, line))
	{
		lineCount++;
		for (int i = 0; i < width_; i++)
		{
			tiles_.push_back(line.at(i));
		}
	}

	if (lineCount != height_)
	{
		assert(false && "高さの不一致");
		return false;
	}
}

char MapLoader::TileChar(const int _x, const int _y) const
{
	int index{ _y * width_ + _x };

	assert(0 <= index && index < tiles_.size()
		&& "範囲外アクセス発生");

	return tiles_.at(index);
}
