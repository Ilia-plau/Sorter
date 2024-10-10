#include "TaskService.h"

TaskService::TaskService() :dataSource("tasks.json") {}

void TaskService::create(const Task& task) {
	Service::create(dataSource, task);
}
vector<Task> TaskService::read() {
	return Service::read(dataSource);
}
void TaskService::update(const Task& task) {
	Service::update(dataSource, task);
}
void TaskService::remove(int id) {
	Service::remove(dataSource, id);
}