#include<iostream>
#include<algorithm>
#define MAX 9999 //최소값 판별을 위한 값
#define def 10 //배열에 할당할 초기값

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

/* 초기값 이니셜라이징 설정 */
Queue::Queue() : qback(0), qfront(0)
{
	//qfront = 0;
	//qback = 0;
	data = new int[def+1]; //메모리 해체 시 heap error 방지를 위한 +1 할당.
}

/* 큐의 크기를 늘리고자 할 때 */
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
		cout << "if호출" << endl;
		qback = (qback +1) % MAX;
		//cout << "큐백이의 값" <<qback << endl;
		data[qback] = x;
		//cout << "push" << data[qback] << endl;
		return;
	}
	else
	{
		cout << "else호출" << endl;
		Queue::expend(x);
		return;
	}

}
	
void Queue::expend(int x)
{
	//qback++;
		//cout << "증가 후" << qback << endl;
	int* temp = new int[qback];

	for (int i = 0; i < qback; i++)
	{
		temp[i] = data[i];
		//cout << "증가 후" << temp[i] << endl;
	}

	delete[] data;
	//qback++;
	//cout << "할당 전" << qback << endl;
	qback *= 2;
	//cout << "test" <<qback << endl;
	data = new int[qback];
	cout << "할당 후" << qback << endl;
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

/* 가장 처음 넣은것은? */
int Queue::front()
{
	// Empty check
	//return data[(qfront + 1) % MAX];
	return data[(qfront + 1) % MAX];
}

/* 가장 마지막에 들어간 원소는? */
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
	int small = MAX; //최소값을 찾기 위해 가장 큰 값을 할당함.

	/* 큐의 값을 할당 */
	for (int i = 0; i < 16; i++) //0이 아닌 1부터 할당하려고 함.
	{
		//if (i < MAX) //큐가 넘치지 않게 할당.
		//{
			que.push(i);
		//}
	}

	/* 큐의 최소값 찾기 */
	for (int v = 1; v < que.size(); v++)
	{
		//cout << que.size() << endl;
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
		//delete[] que.data;
	}
	//delete[] que.data;
	system("pause");
	//que.~Queue();
	return 0;
}