#include "Radar.h"
#include <imgui.h>
#include <cmath>

ImVec2 RadarMath::worldToRadar(const Vec3& worldPos,
								  const PlayerState& player,
								  float radarRadius,
								  const RadarConfig& cfg)
{
	float dx = (worldPos.x - player.position.x) * cfg.metersPerUnit;
	float dz = (worldPos.z - player.position.z) * cfg.metersPerUnit;

	float yaw = player.yawDeg * (3.14159265f/180.0f);
	float cosA = std::cos(-yaw);
	float sinA = std::sin(-yaw);
	float rx = dx * cosA - dz * sinA;
	float ry = dx * sinA + dz * cosA;

	float dist = std::sqrt(rx*rx + ry*ry);
	float maxDist = cfg.rangeMeters;
	if (dist > maxDist && dist > 0.0001f) {
		rx *= (maxDist/dist);
		ry *= (maxDist/dist);
	}

	float k = radarRadius / maxDist;
	return ImVec2(rx * k, -ry * k);
}

