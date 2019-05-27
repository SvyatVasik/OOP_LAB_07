#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <ctime>

using namespace std;
class myQueue {
public:
	vector<int> queue;

	void removeLast(int numToRemove) {
		for (int i = 0; i < numToRemove; i++) {
			queue.erase(queue.begin());
		}
	}

	void setQueue(char* name)
	{
		if (name) {
			ifstream file(name);
			int temp;
			while (file >> temp) {

				queue.push_back(temp);
			}
			file.close();
			return;
		}
		int temp = 1;
		cout << "Enter your queue(0-end):" << endl;
		while (temp) {
			cin >> temp;
			queue.push_back(temp);
		}
		queue.pop_back();
	}

	void putQueue(char* name)
	{
		vector<int>::iterator it;
		if (name) {
			return;
		}
		cout << "Your queue:" << endl;
		for (it = queue.begin(); it != queue.end(); it++)
			cout << *it << endl;
	}

	void queueSum(char* name)
	{
		int sum = 0;
		vector<int>::iterator it;

		for (it = queue.begin(); it != queue.end(); it++)
			sum += *it;

		if (name) {
			ofstream file;
			file.open(name, ios_base::app);
			file << endl << "Sum of your queue: " << sum << endl;
			file.close();
			cout << "Your file was successfully changed!" << endl;
			return;
		}
		cout << "Sum of your queue: " << sum << endl;

	}
};

int main()
{
	myQueue queue;
	int check;
	char* filename = new char[20];
	cout << "Enter numbers from file?1-yes,2-no" << endl;
	cin >> check;
	if (check == 1) {
		cout << "Name of your file: ";
		cin >> filename;
	}
	else filename = NULL;

	queue.setQueue(filename);
	long start_time = clock();
	queue.removeLast(2);
	queue.queueSum(filename);
	long end_time = clock();
	queue.putQueue(filename);
	cout << "Time of program work: " << end_time - start_time << "ms" << endl;
	system("pause");
	return 0;
}