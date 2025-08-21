#pragma once

#include <vector>
#include <cstdint>

struct Vec3 { float x; float y; float z; };

enum class EntityType : uint8_t { Npc, Player, Entity, Stone, Portal };

struct Entity {
	EntityType type;
	Vec3 position;
};

struct PlayerState {
	Vec3 position;
	float yawDeg;
};

struct RadarConfig {
	float rangeMeters = 150.0f;
	float metersPerUnit = 1.0f;
};

struct ImVec2;
namespace RadarMath {
	ImVec2 worldToRadar(const Vec3& worldPos,
						 const PlayerState& player,
						 float radarRadius,
						 const RadarConfig& cfg);
}

