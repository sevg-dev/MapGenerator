#pragma once

#include "Delaunay.h"
#include "Structures.h"
#include <vector>

// Forward Declarations
class Vec2;
namespace noise {
	namespace module {
		class Perlin;
	}
}

class Map {
public:
	Map(void);
	~Map(void);

	Map(int width, int height, int point_count);

	void Generate();

	void GeneratePolygons();
	void GenerateLand();


	bool LoadFile(string file_name);
	bool WriteFile(string file_name);

	vector<edge *> GetEdges();
	vector<corner *> GetCorners();
	vector<center *> GetCenters();

private:
	int map_width;
	int map_height;
	Delaunay * triangulation;
	double z_coord;
	noise::module::Perlin * noiseMap;

	vector<edge *> edges;
	vector<corner *> corners;
	vector<center *> centers;

	bool IsIsland(Vec2 position);
	void AssignOceanCoastLand();
	void AssignCornerElevation();
	void RedistributeElevations();
	void AssignPolygonElevations();
	void CalculateDownslopes();
	void GenerateRivers();

	vector<corner *> GetLandCorners();
	void LloydRelaxation();
};

