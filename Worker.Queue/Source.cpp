#include<iostream>
#include<assert.h>
#include<vector>
#include<Windows.h>
using namespace std;

class Worker {

public:

	int id;
	string name;
	string surname;
	int age;
	int pageCount;
	static int staticId;

	Worker() {
		id = ++staticId;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount) {
		id = ++staticId;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->pageCount = pageCount;
	}

	//get
	int GetId() {
		return id;
	}
	string GetName() {
		return name;
	}
	string GetSurname() {
		return surname;
	}
	int GetAge() {
		return age;
	}
	int GetPageCount() {
		return pageCount;
	}
	void ShowWorkers() {
		cout << "Id: " << GetId() << "\nName: " << GetName() << "\nSurname: " << GetSurname() << "\nAge: " << GetAge() << "\nPage count: " << GetPageCount() << "\n";
	}
};

int Worker::staticId = 0;

class WorkerQueue {

public:

	vector<Worker>workers;
	bool Empty()const { 
		return workers.empty(); 
	}

	void Push(const Worker worker) {
		workers.push_back(worker);
	}

	void Pop() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}

	Worker& Front() {
		return workers.front();
	}
};
class Printer {

	WorkerQueue queue;

public:

	void Add(const Worker worker) {
		queue.Push(worker);
	}

	void Start() {
		while (!queue.Empty()) {

			Worker worker = queue.Front();

			while (worker.pageCount > 0) {
				system("cls");
				worker.ShowWorkers();
				Sleep(500);
				worker.pageCount--;
			}
			queue.Pop();
		}
	}
};
void main() {
	Printer workers;
	workers.Add(Worker("Nigar", "Mustafazada", 18, 7));
	workers.Add(Worker("Aytan", "Mammadova", 21, 5));
	workers.Add(Worker("Khayyam", "Nacafli", 19, 6));
	workers.Add(Worker("Aysu", "Qurbanova", 19, 5));
	workers.Add(Worker("Murad", "Farmanli", 20, 5));
	workers.Start();
}