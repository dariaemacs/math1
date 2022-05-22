#ifndef files
#define files
#include <vector>
#include <fstream>

struct dataPoint {
    char day;
    char month;
    int year;
    int qtyBall;
};

extern std::vector <dataPoint> DATA;

class filescontrol {
    std::string fn;


public:
    filescontrol(std::string);
    void savetoFile(std::vector <dataPoint>&);
    void addoneRecordtoFile(dataPoint rec);
    void readVector(std::vector <dataPoint>&);
    void close();
};
#endif

