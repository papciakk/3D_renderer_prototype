// Object: GeoSphere002
const int vertexexCount = 42;
const int faceCount = 80;

const float model[vertexexCount][3] = {
	{0.0, -0.5, 0.0},
	{0.447214, -0.223607, 0.0},
	{0.138197, -0.223607, 0.425325},
	{-0.361803, -0.223607, 0.262865},
	{-0.361803, -0.223607, -0.262866},
	{0.138197, -0.223607, -0.425325},
	{0.361803, 0.223607, 0.262866},
	{-0.138197, 0.223607, 0.425325},
	{-0.447214, 0.223607, 0.0},
	{-0.138196, 0.223607, -0.425325},
	{0.361803, 0.223607, -0.262866},
	{0.0, 0.5, 0.0},
	{0.262866, -0.425325, 0.0},
	{0.0812299, -0.425325, 0.25},
	{-0.212663, -0.425325, 0.154508},
	{-0.212663, -0.425325, -0.154509},
	{0.08123, -0.425325, -0.25},
	{0.344095, -0.262866, 0.25},
	{-0.131433, -0.262866, 0.404508},
	{-0.425325, -0.262866, 0.0},
	{-0.131433, -0.262865, -0.404509},
	{0.344095, -0.262866, -0.25},
	{0.475528, 0.0, 0.154508},
	{0.0, 0.0, 0.5},
	{-0.475528, 0.0, 0.154508},
	{-0.293893, 0.0, -0.404509},
	{0.293893, 0.0, -0.404508},
	{0.475528, 0.0, -0.154509},
	{0.293893, 0.0, 0.404508},
	{-0.293893, 0.0, 0.404508},
	{-0.475528, 0.0, -0.154509},
	{1.3328e-07, 0.0, -0.5},
	{0.131433, 0.262865, 0.404509},
	{-0.344095, 0.262866, 0.25},
	{-0.344095, 0.262866, -0.25},
	{0.131433, 0.262866, -0.404508},
	{0.425325, 0.262866, 0.0},
	{0.212663, 0.425325, 0.154509},
	{-0.0812299, 0.425325, 0.25},
	{-0.262866, 0.425325, 0.0},
	{-0.0812298, 0.425325, -0.25},
	{0.212663, 0.425325, -0.154508},
};
const float vertexNormals[vertexexCount][3] = {
	{0.0, -1.0, -1.39268e-07},
	{0.894427, -0.447214, 0.0},
	{0.276393, -0.447214, 0.850651},
	{-0.723607, -0.447214, 0.525731},
	{-0.723607, -0.447213, -0.525731},
	{0.276393, -0.447214, -0.850651},
	{0.723607, 0.447213, 0.525731},
	{-0.276393, 0.447214, 0.850651},
	{-0.894427, 0.447214, 0.0},
	{-0.276393, 0.447214, -0.850651},
	{0.723607, 0.447214, -0.525731},
	{0.0, 1.0, 1.80559e-07},
	{0.525731, -0.850651, 0.0},
	{0.16246, -0.850651, 0.5},
	{-0.425325, -0.850651, 0.309017},
	{-0.425325, -0.850651, -0.309017},
	{0.16246, -0.850651, -0.5},
	{0.688191, -0.525731, 0.5},
	{-0.262866, -0.525731, 0.809017},
	{-0.850651, -0.525731, -1.59934e-07},
	{-0.262865, -0.525731, -0.809017},
	{0.688191, -0.525731, -0.5},
	{0.951057, -1.19321e-07, 0.309017},
	{0.0, -1.31086e-07, 1.0},
	{-0.951057, 0.0, 0.309017},
	{-0.587785, 1.84864e-07, -0.809017},
	{0.587785, 1.53029e-07, -0.809017},
	{0.951057, 0.0, -0.309017},
	{0.587785, -1.31806e-07, 0.809017},
	{-0.587785, -1.23847e-07, 0.809017},
	{-0.951056, 1.2728e-07, -0.309017},
	{2.12234e-07, 1.97409e-07, -1.0},
	{0.262866, 0.525731, 0.809017},
	{-0.688191, 0.525731, 0.5},
	{-0.688191, 0.525731, -0.5},
	{0.262866, 0.525731, -0.809017},
	{0.850651, 0.525731, 0.0},
	{0.425325, 0.850651, 0.309017},
	{-0.16246, 0.850651, 0.5},
	{-0.525731, 0.850651, 0.0},
	{-0.16246, 0.850651, -0.5},
	{0.425325, 0.850651, -0.309017},
};
const int faces[faceCount][3] = {
	{0, 12, 13},
	{12, 1, 17},
	{12, 17, 13},
	{13, 17, 2},
	{0, 13, 14},
	{13, 2, 18},
	{13, 18, 14},
	{14, 18, 3},
	{0, 14, 15},
	{14, 3, 19},
	{14, 19, 15},
	{15, 19, 4},
	{0, 15, 16},
	{15, 4, 20},
	{15, 20, 16},
	{16, 20, 5},
	{0, 16, 12},
	{16, 5, 21},
	{16, 21, 12},
	{12, 21, 1},
	{1, 27, 22},
	{27, 10, 36},
	{27, 36, 22},
	{22, 36, 6},
	{2, 28, 23},
	{28, 6, 32},
	{28, 32, 23},
	{23, 32, 7},
	{3, 29, 24},
	{29, 7, 33},
	{29, 33, 24},
	{24, 33, 8},
	{4, 30, 25},
	{30, 8, 34},
	{30, 34, 25},
	{25, 34, 9},
	{5, 31, 26},
	{31, 9, 35},
	{31, 35, 26},
	{26, 35, 10},
	{6, 28, 22},
	{28, 2, 17},
	{28, 17, 22},
	{22, 17, 1},
	{7, 29, 23},
	{29, 3, 18},
	{29, 18, 23},
	{23, 18, 2},
	{8, 30, 24},
	{30, 4, 19},
	{30, 19, 24},
	{24, 19, 3},
	{9, 31, 25},
	{31, 5, 20},
	{31, 20, 25},
	{25, 20, 4},
	{10, 27, 26},
	{27, 1, 21},
	{27, 21, 26},
	{26, 21, 5},
	{11, 38, 37},
	{38, 7, 32},
	{38, 32, 37},
	{37, 32, 6},
	{11, 39, 38},
	{39, 8, 33},
	{39, 33, 38},
	{38, 33, 7},
	{11, 40, 39},
	{40, 9, 34},
	{40, 34, 39},
	{39, 34, 8},
	{11, 41, 40},
	{41, 10, 35},
	{41, 35, 40},
	{40, 35, 9},
	{11, 37, 41},
	{37, 6, 36},
	{37, 36, 41},
	{41, 36, 10},
};
