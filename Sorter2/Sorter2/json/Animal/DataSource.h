#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

template <typename T>
class DataSource {
private:
	string filename;
	json data;
	int currentId;

	void readFile();
	void writeFile(const json& j);
	int FindById(int id);
public:

	DataSource(string filename);
	~DataSource();
	void create(const T& item);
	vector<T> read();
	void update(const T& item);
	void remove(int id);
};


#endif // !DATASOURCE_H