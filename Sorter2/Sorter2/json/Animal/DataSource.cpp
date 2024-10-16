#include "DataSource.h"
#include "Task.h"

template<typename T>
DataSource<T>::DataSource(string filename) {
	this->filename = filename;
	readFile();
}

template<typename T>
DataSource<T>::~DataSource() {
	writeFile(data);
}

template<typename T>
void DataSource<T>::readFile() {
	ifstream inputFile(filename);
	if (inputFile) {
		inputFile >> data;
		currentId = data.empty() ? 1 : data.back()["id"] + 1;
	}
	else {
		currentId = 1;
	}
}
template<typename T>
void DataSource<T>::writeFile(const json& j) {
	ofstream outputFile(filename);
	outputFile << j.dump(4);
}

template<typename T>
int DataSource<T>::FindById(int id) {
	int index = -1;
	for (int i = 0; i < data.size(); i++) {
		if (data[i]["id"] == id) {
			index = i;
			break;
		}
	}
	return index;
}

template<typename T>
void DataSource<T>::create(const T& item) {
	T next(currentId, item);
	data.push_back(next.toJson());
	currentId++;
	writeFile(data);
}
template<typename T>
vector<T> DataSource<T>::read() {
	vector<T> items;
	for (const auto& j : data) {
		items.push_back(T::fromJson(j));
	}
	return items;
}

template<typename T>
void DataSource<T>::update(const T& item) {
	int index = FindById(item.id);
	if (index != -1)
	{
		data[index] = item.toJson();
		writeFile(data);
	}
	else {
		cout << "Not Found!" << endl;
	}
}

template<typename T>
void DataSource<T>::remove(int id) {
	int index = FindById(id);
	if (index != -1) {
		data.erase(data.begin() + index);
		writeFile(data);
	}
	else {
		cout << "Not Found!" << endl;
	}
}

template class DataSource<Task>;
