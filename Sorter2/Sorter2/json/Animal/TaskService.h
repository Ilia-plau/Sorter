#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include "Service.h"
#include "Task.h"
#include "DataSource.h"

class TaskService : public Service<Task> {
private:
	DataSource<Task> dataSource;
public:
	TaskService();
	void create(const Task& task);
	vector<Task> read();
	void update(const Task& task);
	void remove(int id);
};

#endif // !TASKSERVICE_H
