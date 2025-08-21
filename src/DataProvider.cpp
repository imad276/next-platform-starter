#include "DataProvider.h"
#include <nlohmann/json.hpp>
#include <fstream>

using nlohmann::json;

static EntityType parseType(const std::string& s){
	if (s == "Npc") return EntityType::Npc;
	if (s == "Player") return EntityType::Player;
	if (s == "Entity") return EntityType::Entity;
	if (s == "Stone") return EntityType::Stone;
	if (s == "Portal") return EntityType::Portal;
	return EntityType::Entity;
}

bool JsonDataProvider::loadFromFile(const std::string& path)
{
	std::ifstream f(path);
	if(!f) return false;
	json j; f >> j;
	player.position.x = j["player"]["x"].get<float>();
	player.position.y = j["player"]["y"].get<float>();
	player.position.z = j["player"]["z"].get<float>();
	player.yawDeg = j["player"]["yawDeg"].get<float>();

	entities.clear();
	for (auto& e : j["entities"]) {
		Entity ent{};
		ent.type = parseType(e["type"].get<std::string>());
		ent.position.x = e["x"].get<float>();
		ent.position.y = e["y"].get<float>();
		ent.position.z = e["z"].get<float>();
		entities.push_back(ent);
	}
	return true;
}

