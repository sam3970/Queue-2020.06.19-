#include<iostream>
#include<algorithm>
#define MAX 9999 //ť ������

using namespace std;

class Queue
{
private:
	int qfront;
	int qback;
	//int data[MAX];

public:
	Queue();
	int data[MAX];
	bool empty();
	void push(int x);
	void pop();
	int front();
	int back();
	int size();
	//int min();

};

Queue::Queue() {
	qfront = 0;
	qback = 0;
	//data[MAX] = 0;
}

bool Queue::empty()
{
	return qfront == qback;
}

void Queue::push(int x)
{
	qback = (qback + 1) % MAX;
	data[qback] = x;
}

void Queue::pop()
{
	//qfront = (qfront + 1) % MAX;
	qfront = (qfront + 1) % MAX;
}

//���� ó�� �������� ��������?
int Queue::front()
{
	// Empty check
	//return data[(qfront + 1) % MAX];
	return data[(qfront + 1) % MAX];
}

//���� �������� �� ���Ҵ� ��������?
int Queue::back()
{
	// Empty check
	return data[qback];
}

int Queue::size()
{
	return qback - qfront;
	//return (qback - qfront + MAX) % MAX;
}

int main()
{
	Queue que;
	int small = MAX; //�ּҰ��� ã�� ���� ���� ū ���� �Ҵ���.

	/* ť�� ���� �Ҵ� */
	for (int i = 1; i <= 11; i++) //0�� �ƴ� 1���� �Ҵ��Ϸ��� ��.
	{
		if (i < MAX) //ť�� ��ġ�� �ʰ� �Ҵ�.
		{
			que.push(i);
		}
	}

	/* ť�� �ּҰ� ã�� */
	for (int v = 1; v < que.size(); v++)
	{
		small = min(small, que.data[v]); //�ּҰ��� ã�Ҵٸ� small ������ ����
		//cout << "�� �׽�Ʈ" << que.data[v] << endl;
	}

	cout << "������ �ּڰ���?" << small << endl; //�ּҰ� ���(min Ŭ���� ���� ���� ����)

	/*for (int j = 1; j <= 8; j++)
	{
		que.pop();
	}*/

	cout << "* Size: " << que.size() << '\n';

	while (!que.empty())
	{
		cout << "Pop: " << que.front() << endl;
		que.pop();
	}
	system("pause");
	return 0;
}