#ifndef READCSV_H_INCLUDED
#define READCSV_H_INCLUDED

#include <fstream>
#include "tokenize.h"

class csvData
{
private:
    char*** Data;
    int     Rows;
    int*    RowCells;

public:
    bool load(const char*);
    bool good();
    bool bad();

    bool isValidCell(int, int);
    const char* getCell(int, int);

    void clear();

    csvData();
    ~csvData();
};

bool csvData::load(const char* fileName)
{
    //load data in file
    std::ifstream fin;
    fin.open(fileName);

    if (fin.bad())
        return false;

    fin.seekg(0,std::ios::end);
    std::streamsize size = fin.tellg();
    fin.seekg(0,std::ios::beg);

    char* contents = new char[size];
    fin.read(contents, size);


    //clear any previously loaded data.
    clear();

    //separate data into pages
    char** tempData = NULL;
    tokenize(contents, '\n', "\"\"", tempData, Rows, false, false);

    Data = new char**[Rows];
    RowCells = new int[Rows];

    //separate each page's data
    for(int i=0; i<Rows; i++)
    {
        Data[i] = NULL;
        RowCells[i] = 0;

        tokenize(tempData[i], ',', "\"\"", Data[i], RowCells[i], true, true);
    }

    //delete temp variable
    delTok(tempData, Rows);

    return true;
}

bool csvData::good()
{
    return (Rows > 0);
}

bool csvData::bad()
{
    return (Rows <= 0);
}

bool csvData::isValidCell(int Row, int Cell)
{
    if ((Row >= 0) && (Row < Rows) &&
        (Cell >= 0) && (Cell < RowCells[Row]))
        return true;
    else
        return false;
}

const char* csvData::getCell(int Row, int Cell)
{
    if (isValidCell(Row, Cell))
    {
        return Data[Row][Cell];
    }
    else
    {
        return NULL;
    }
}

void csvData::clear()
{
    for (int i=0; i<Rows; i++)
        delTok(Data[i], RowCells[i]);

    if (Data)
        delete[] Data;

    if (RowCells)
        delete[] RowCells;

    Data = NULL;
    Rows = 0;
    RowCells = NULL;
}

csvData::csvData()
{
    Data = NULL;
    Rows = 0;
    RowCells = NULL;
}

csvData::~csvData()
{
    clear();
}

#endif // READCSV_H_INCLUDED
