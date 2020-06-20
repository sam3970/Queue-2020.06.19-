#include<iostream>
#include<algorithm>
#define MAX 9999 //큐 사이즈

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

//가장 처음 넣은것이 무엇인지?
int Queue::front()
{
	// Empty check
	//return data[(qfront + 1) % MAX];
	return data[(qfront + 1) % MAX];
}

//가장 마지막에 들어간 원소는 무엇인지?
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
	int small = MAX; //최소값을 찾기 위해 가장 큰 값을 할당함.

	/* 큐의 값을 할당 */
	for (int i = 1; i <= 11; i++) //0이 아닌 1부터 할당하려고 함.
	{
		if (i < MAX) //큐가 넘치지 않게 할당.
		{
			que.push(i);
		}
	}

	/* 큐의 최소값 찾기 */
	for (int v = 1; v < que.size(); v++)
	{
		small = min(small, que.data[v]); //최소값을 찾았다면 small 변수에 대입
		//cout << "값 테스트" << que.data[v] << endl;
	}

	cout << "스택의 최솟값은?" << small << endl; //최소값 출력(min 클래스 만들어서 변경 예정)

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