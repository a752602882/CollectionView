
#include "Road.h"

int RoadRow::getLine(size_t line)
{
	if (m_Line.size() <= line) return -1;
	return m_Line[line];
}
void Road::checkRow(size_t Row)
{
	while (1)
	{
		if (m_Row.size() > Row) break;
		RoadRow kLine;
		m_Row.push_back(kLine);
	}
}
void Road::checkLine(size_t row, size_t line)
{
	RoadRow * pRow = getRow(row);
	while (!pRow)
	{
		checkRow(row);
		pRow = getRow(row);
	}
	while (1)
	{
		if (pRow->m_Line.size() > line) break;
		pRow->m_Line.push_back(-1);
	}
}
RoadRow * Road::getRow(size_t Row)
{
	if (Row >= m_Row.size()) return NULL;
	return &m_Row[Row];
}
void Road::addData(size_t Row, size_t Line, int data)
{
	if (getRowNum() <= Row)
	{
		checkRow(Row);
	}
	checkLine(Row, Line);
	m_Row[Row].m_Line[Line] = data;
}
int Road::getData(size_t row, size_t line)
{
	RoadRow * pRow = getRow(row);
	if (!pRow) return -1;
	return pRow->getLine(line);
}

bool DRoad::bAddMutilRoadData(size_t nData)
{
	if (nData == 0)
	{
		return false;
	}
	else
	{
		int row = m_data.getRowNum();
		if (row <= 0)
		{
			m_data.addData(0, 0, nData);
			return true;
		}
		int line = m_data.getLineNum(row - 1);
		if (line > m_nMaxLine - 1)
		{
			m_data.addData(row, 0, nData);
		}
		else
		{
			m_data.addData(row - 1, line, nData);
		}


	}
	return true;
}


bool DRoad::addRoadData(size_t nData)
{
	int lastrow = m_data.getRowNum();
	if (addFirstPoint(nData))
	{
		int row = m_data.getRowNum();
		int line = m_data.getLineNum(row - 1);
		if (lastrow != row) m_Draw.m_Mode = 0;
		addFirstDraw(row - 1, line - 1, m_data.getData(row - 1, line - 1));
		return true;
	}
	return false;
}

bool DRoad::addFirstPoint(size_t nData)
{
	if (nData == 0)
	{
		return false;
	}
	else
	{
		int row = m_data.getRowNum();
		if (row <= 0)
		{
			m_data.addData(0, 0, nData);
			return true;
		}
		BYTE recwin = m_data.getEnd();
		if (recwin == 0)
		{
			int line = m_data.getLineNum(row - 1);
			m_data.addData(row - 1, line - 1, nData);
		}
		else if (recwin == nData)
		{
			int line = m_data.getLineNum(row - 1);
			m_data.addData(row - 1, line, nData);
		}
		else
		{
			int line = m_data.getLineNum(row - 1);
			m_data.addData(row, 0, nData);
		}
	}
	return true;
}

void DRoad::addFirstDraw(size_t row, size_t line, int data)
{
	if (row < 0 || line < 0) return;
	if (line < 6)
	{
		int a = m_Draw.getData(row, line);
		if (a == -1 && m_Draw.m_Mode == 0)
		{
			m_Draw.addData(row, line, data);
		}
		else
		{
			if (a != -1 && m_Draw.m_Mode == 0)
			{
				m_Draw.m_Mode = line - 1;
			}
			if (m_Draw.m_Mode != 0)
			{
				int i = 0;
				while (1)
				{
					int a = m_Draw.getData(row + i, m_Draw.m_Mode);
					if (a == -1)
					{
						m_Draw.addData(row + i, m_Draw.m_Mode, data);
						return;
					}
					i++;
				}
			}
		}
	}
	else
	{
		if (m_Draw.m_Mode == 0) m_Draw.m_Mode = 5;
		int i = 0;
		while (1)
		{
			int a = m_Draw.getData(row + i, m_Draw.m_Mode);
			if (a == -1)
			{
				m_Draw.addData(row + i, m_Draw.m_Mode, data);
				return;
			}
			i++;
		}
	}

}


void DRoad::delRoadData()
{
	int row = m_data.getRowNum();
	while (row > 0)
	{
		RoadRow *pRow = m_data.getRow(row - 1);
		if (pRow->m_Line.size() > 0)
		{
			pRow->m_Line.pop_back();
			if (pRow->m_Line.size() == 0)
			{
				m_data.m_Row.pop_back();
			}
			break;
		}


		row = row - 1;
		m_data.m_Row.pop_back();
	}


}