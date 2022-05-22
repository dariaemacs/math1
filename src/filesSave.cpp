#include "filesSave.hpp"



filescontrol::filescontrol(std::string fn_) :fn(fn_) {}

void filescontrol::savetoFile(std::vector <dataPoint>& source) {

	std::ofstream out_file(fn, std::ios::binary | std::ios::out);
	out_file.write((const char*)&source.front(), source.size() * sizeof(dataPoint));
	out_file.close();

}
void filescontrol::close() {  }
void filescontrol::readVector(std::vector <dataPoint>& vectortoRead) {

	std::ifstream in_file(fn, std::ios::binary);
	in_file.seekg(0, std::ios_base::end);
	long size = in_file.tellg();
	in_file.seekg(0);
	if (size > 0) {
		vectortoRead.resize(size / sizeof(dataPoint));
		in_file.read((char*)&vectortoRead.front(), vectortoRead.size() * sizeof(dataPoint));
	}
	in_file.close();
}

void filescontrol::addoneRecordtoFile(dataPoint rec) {
	std::ofstream myfile(fn, std::ios::binary | std::ios::app);


	myfile.write((char*)&rec, sizeof(dataPoint));
	myfile.close();
}


//olda
/*#include "filesSave.hpp"

extern std::vector <dataPoint> DATA =
{
  {1,1,6,1981,15},
  {2,1,6,1981,11},
  {3,1,6,1981,9},
  {4,1,6,1981,16},

  {5,12,6,1981,15},
  {6,12,6,1981,11},
  {7,14,6,1981,9},
  {8,25,6,1981,16},

  {9, 1,7,1981,15},
  {10,5,7,1981,11},
  {11,14,7,1981,9},
  {13,3,4,2022,16},
  {14,3,4,2022,16},
  {15,3,4,2022,16},
  {16,3,4,2022,1},
  {17,3,4,2022,2},
  {18,3,4,2022,1},
  {19,3,4,2022,1},
  {20,3,4,2022,5},
  {21,3,4,2022,6},
  {22,3,4,2022,6},
  {23,3,4,2022,12},
  {24,3,4,2022,8},
  {25,3,4,2022,6},
  {26,3,4,2022,10},
  {27,3,4,2022,1},

  {28, 1,7,1981,12},
  {29,5,7,1981,8},
  {30,14,7,1981,1},
  {31,3,4,2022,1},
  {32,3,4,2022,1},
  {33,3,4,2022,10},
  {34,3,4,2022,7},
  {35,3,4,2022,12},
  {36,3,4,2022,11},
  {37,3,4,2022,14},
  {38,3,4,2022,13},
  {39,3,4,2022,12},
  {40,3,4,2022,5},
  {41,3,4,2022,2},
  {42,3,4,2022,7},
  {43,3,4,2022,8},
  {44,3,4,2022,1},
  {45,3,4,2022,2}

};

filescontrol::filescontrol(std::string fn_):fnData(fn_) {
	fopen_s(&f, "data.txt", "wt");
		
	
}

void filescontrol::savetoFile(int nomer_, char day_, char month_, int year_, int qtyBall_) {
	currentRecord.nomer = nomer_;
	currentRecord.day = day_;
	currentRecord.month = month_;
	currentRecord.year = year_;
	currentRecord.qtyBall = qtyBall_;
	fwrite(&currentRecord, sizeof(dataPoint), 1, f);

}
void filescontrol::close() { fclose(f); }
*/