#include<iostream>
#include<algorithm>
#define MAX 9999 //�ּҰ� �Ǻ��� ���� ��
#define def 10 //�迭�� �Ҵ��� �ʱⰪ

using namespace std;

class Queue
{
private:
	//int *data;
	int qfront;
	int qback;
	//int data[MAX];

public:
	Queue();
	Queue(int size);
	int *data;
	bool empty();
	void push(int x);
	void pop();
	void expend(int x);
	int front();
	int back();
	int size();
	void print();
	~Queue() 
	{
		delete[] data;
	}
	int &operator[](int index);
	//int min();

};

/* �ʱⰪ �̴ϼȶ���¡ ���� */
Queue::Queue() : qback(0), qfront(0)
{
	//qfront = 0;
	//qback = 0;
	data = new int[def+1]; //�޸� ��ü �� heap error ������ ���� +1 �Ҵ�.
}

/* ť�� ũ�⸦ �ø����� �� �� */
Queue::Queue(int size) : qback(size), qfront(0)
{
	data = new int[qback];
}

bool Queue::empty()
{
	return qfront == qback;
}

void Queue::push(int x)
{
	if (qback < x)
	{
		cout << "ifȣ��" << endl;
		qback = (qback +1) % MAX;
		//cout << "ť������ ��" <<qback << endl;
		data[qback] = x;
		//cout << "push" << data[qback] << endl;
		return;
	}
	else
	{
		cout << "elseȣ��" << endl;
		Queue::expend(x);
		return;
	}

}
	
void Queue::expend(int x)
{
	//qback++;
		//cout << "���� ��" << qback << endl;
	int* temp = new int[qback];

	for (int i = 0; i < qback; i++)
	{
		temp[i] = data[i];
		//cout << "���� ��" << temp[i] << endl;
	}

	delete[] data;
	//qback++;
	//cout << "�Ҵ� ��" << qback << endl;
	qback *= 2;
	//cout << "test" <<qback << endl;
	data = new int[qback];
	cout << "�Ҵ� ��" << qback << endl;
	for (int i = 0; i < qback; i++)
		data[i] = temp[i];

	//qback = 0;
	//qback++;
	//qback = (qback+1) % MAX;
	//data[qback] = x;
	//cout <<"test" <<x << endl;
	//qback++;
	delete[] temp;
	return;
}

void Queue::pop()
{
	qfront = (qfront + 1) % MAX;
	return;	
}

/* ���� ó�� ��������? */
int Queue::front()
{
	// Empty check
	//return data[(qfront + 1) % MAX];
	return data[(qfront + 1) % MAX];
}

/* ���� �������� �� ���Ҵ�? */
int Queue::back()
{
	// Empty check
	return data[qback];
}

int Queue::size()
{
	//return qback - qfront;
	return (qback - qfront + MAX) % MAX;
}

/*void Queue::print()
{
	for (int i = 0; i < qback; i++)
		cout << data[i] << endl;
}*/

int& Queue::operator[](int op)
{
	return this->data[op];
}

/*Queue::~Queue()
{
	
}*/

int main()
{
	Queue que;
	int small = MAX; //�ּҰ��� ã�� ���� ���� ū ���� �Ҵ���.

	/* ť�� ���� �Ҵ� */
	for (int i = 0; i < 16; i++) //0�� �ƴ� 1���� �Ҵ��Ϸ��� ��.
	{
		//if (i < MAX) //ť�� ��ġ�� �ʰ� �Ҵ�.
		//{
			que.push(i);
		//}
	}

	/* ť�� �ּҰ� ã�� */
	for (int v = 1; v < que.size(); v++)
	{
		//cout << que.size() << endl;
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
		//delete[] que.data;
	}
	//delete[] que.data;
	system("pause");
	//que.~Queue();
	return 0;
}