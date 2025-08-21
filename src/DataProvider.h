#pragma once

#include <vector>
#include <string>
#include "Radar.h"

class JsonDataProvider {
public:
	bool loadFromFile(const std::string& path);
	const PlayerState& getPlayer() const { return player; }
	const std::vector<Entity>& getEntities() const { return entities; }
private:
	PlayerState player{};
	std::vector<Entity> entities;
};

