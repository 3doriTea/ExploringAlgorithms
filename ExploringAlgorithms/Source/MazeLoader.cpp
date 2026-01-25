#include "MazeLoader.h"
#include "Maze.h"
#include <fstream>


MazeLoader::MazeLoader(Maze& _maze) :
	maze_{ _maze }
{
}

MazeLoader::~MazeLoader()
{
}

bool MazeLoader::TryLoad(const fs::path& _mazeFile)
{
	std::fstream ifs{ _mazeFile };
	if (!ifs)
	{
		return false;
	}

	Vec2Int size{};
	std::string input{};

	std::getline(ifs, input, ',');
	size.x = std::stoi(input);

	std::getline(ifs, input);
	size.y = std::stoi(input);

	int y{ 0 };
	std::string line{};
	while (std::getline(ifs, line))
	{
		for (int x = 0; x < size.x; x++)
		{
			maze_.SetRoad(CellCharToValue(line.at(x)), { x, y });
		}
		y++;
	}
}

int MazeLoader::CellCharToValue(const char _c)
{
	switch (_c)
	{
	case '#':
		return CellType::WALL;
	default:
		return _c - '0';
	}
	return ~0;
}
