#pragma once

#include "CrossApp.h"
#include <iostream>
USING_NS_CC;
#define ROAD_MINLINE 6
#define BYTE unsigned char 
class RoadRow
{
public:
	~RoadRow(){ m_Line.clear(); };
	std::vector<int> m_Line;
	int getLine(size_t line);
};

class Road
{
public:
	Road(){ m_Mode = 0; };
	std::vector<RoadRow> m_Row;
	BYTE m_Mode;
	size_t getRowNum(void){ return m_Row.size(); };
	size_t getLineNum(int Row){ if (Row < 0) return 0; else return m_Row[Row].m_Line.size(); };
	void addData(size_t Row, size_t Line, int data);
	int getData(size_t row, size_t line);
	void checkRow(size_t Row);
	void checkLine(size_t row, size_t line);
	RoadRow * getRow(size_t Row);
	int getEnd(void){ return m_Row.back().m_Line.back(); };
	void clear(void){ m_Row.clear(); m_Mode = 0; };

};
class DRoad
{
public:
	int m_nMaxLine;
	Road m_data;
	Road m_Draw;
	bool bAddMutilRoadData(size_t nData);
	bool addRoadData(size_t nData);
	bool addFirstPoint(size_t nData);
	void addFirstDraw(size_t row, size_t line, int data);
	void delRoadData();
	void clear(void){ m_data.clear(), m_Draw.clear(); };
	void InitDRoad(int nMaxLine){ m_nMaxLine = nMaxLine; };
};