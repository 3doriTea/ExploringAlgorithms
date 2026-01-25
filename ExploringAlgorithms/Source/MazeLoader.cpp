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

	maze_.ResetAndFill(size, RoadCellType::ROAD_COST_0);

	int y{ 0 };
	std::string line{};
	while (std::getline(ifs, line))
	{
		for (int x = 0; x < size.x; x++)
		{
			LoadCell(line.at(x), { x, y });
		}
		y++;
	}

	return true;
}

void MazeLoader::LoadCell(const char _c, const Vec2Int _pos)
{
	switch (_c)
	{
	case 'S':
		maze_.SetStart(_pos);
		break;
	case 'G':
		maze_.SetGoal(_pos);
		break;
	default:  // ‚»‚êˆÈŠO‚Í“¹‚Æ‚µ‚ÄÝ’è‚·‚é‚à‚Ì‚ª‚ ‚é
		maze_.SetRoad(CellCharToValue(_c), _pos);
		break;
	}
}

int MazeLoader::CellCharToValue(const char _c)
{
	switch (_c)
	{
	case '#':
		return RoadCellType::WALL;
	default:
		return _c - '0';
	}
	return ~0;
}
