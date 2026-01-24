#pragma once
#include <filesystem>

namespace fs = std::filesystem;

class MapLoader
{
public:
	MapLoader();
	~MapLoader();

	bool TryLoad(fs::path _file);

	inline int GetWidth() const { return width_; }
	inline int GetHeight() const { return height_; }

	char TileChar(const int _x, const int _y) const;

private:
	int width_;
	int height_;
	std::vector<char> tiles_;
};
