// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*22,10,2024
template<typename T>

class Node {
public:
	T value;
	Node* next;
	Node* previous;
	int index;

	Node(T _value) : value(_value) {}
};

template class Node<int>;


template <typename T>
class Stack{
public:
	Node<T>* head;
	Stack() {
		head = nullptr;
	}
	void Push(Node<T>*a) {
		a->next = head;
		head = a;
	}
	void Pop() {
		Node<T>* a = head;
		head = a->next;
		delete a;
	}
	T Peek() {
		if (!head) return NULL;
		return head->value;
	}
	int Size() {
		int counter = 0;
		Node<T>* p = head;

		while (p) {
			counter++;
			p = p->next;
		}
		return counter;
	}
};
template <typename T>
class Queue {
public:
    Node<T>* head;
    Node<T>* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void Enqueue(Node<T>* a) {
        if (!tail) {
            head = a;
            tail = a;
        }
        else {
            tail->next = a;
            tail = a;
        }
    }

    void Dequeue() {
        if (!tail && !head) {
            return;
        }
        Node<T>* a = head;
        head = a->next;
        if (!head) {
            tail = nullptr;
        }
        delete a;
    }

    T Head() {
        if (!head) return NULL;
        return head->value;
    }

    T Tail() {
        if (!tail) return NULL;
        return tail->value;
    }

    int Size() {
        int counter = 0;
        Node<T>* p = head;

        while (p) {
            counter++;
            p = p->next;
        }
        return counter;
    }
};

template class Stack<int>;
template <typename T>
class List{
public:
	Node<T>* head;
	Node<T>* tail;

	List() {
		head = nullptr;
		tail = nullptr;
	}

	void push_back(Node<T>* a) {
		if (!tail && !head) {
			head = a;
			tail = a;
		}
		else {
			tail->next = a;
			tail = a;
		}
	}
	void push_front(Node<T>* a) {
		if (!tail && !head) {
			head = a;
			tail = a;
		}
		else {
			tail->next = a;
			tail = a;
		}
	}

	void pop_back() {
		if (!tail && !head) {
			return;
		}
		Node<T>* a = head;
		head = a->next;
		if (!head) {
			tail = nullptr;
		}
		delete a;
	}

	void pop_front() {
		if (!tail && !head) {
			return;
		}
		Node<T>* a = tail;
		tail = a->next;
		if (!tail) {
			head = nullptr;
		}
		delete a;
	}

	T At(int index) {
		int count = 0;
		Node<T>* p = head;

		while (p && count != index) {
			count++;
			p = p->next;
		}

		if (!p) return nullptr;
		return p->value;
	}

	int Find(T value) {
		int count = 0;
		Node<T>* p = head;

		while (p->value != value && p) {
			count++;
			p = p->next;
		}

		if (!p) return nullptr;
		return count;
	}

	void Add(T data, int index) {
		int count = 0;
		Node<T>* p = head;
		while (p && count != index - 1) {
			p = p->next;
			count++;
		}
		Node<T>* a = new Node<T>(data);
		a->next = p->next;
		p->next = a;
	}

	void Remove(int index) {
		int count = 0;
		Node<T>* p = head;
		while (p && count != index - 1) {
			p = p->next;
			count++;
		}
		p->next = p->next->next;
	}

	T Head() {
		if (!head) return NULL;
		return head->value;
	}

	T Tail() {
		if (!tail) return NULL;
		return tail->value;
	}

	int Size() {
		int counter = 0;
		Node<T>* p = head;

		while (p) {
			counter++;
			p = p->next;
		}
		return counter;
	}
};
//template class Queue<int>;


int main()
{
    setlocale(LC_ALL, "ru");

    string brackets = "]{()}[{}[]]";
    Queue<char> queue;

    queue.Enqueue(0);
    cout << queue.Size();
    

    /*Stack<char> stack;
    for (auto& item : brackets) {
        int openFound = -1;
        for (int i = 0; i < openBracketKinds.size(); i++) {
            if (item == openBracketKinds[i]) {
                openFound = i;
                break;
            }
        }
        if (openFound != -1) {
            stack.Push(new Node<char>(item));
        }
        else {
            if (stack.Size() == 0) {
                break;
            }
            int closeFound = -1;
			for (int i = 0; i < closeBracketKinds.size(); i++) {
				if (item == closeBracketKinds[i]) {
					closeFound = i;
					break;
				}
			}
			if (closeFound != -1) {
				char top = stack.Peek();
				int matchFound = -1;
				for (int i = 0; i < openBracketKinds.size(); i++) {
					if (top == openBracketKinds[i]) {
						matchFound = i;
						break;
					}
				}
				if (matchFound != -1 && matchFound == closeFound) {

					stack.Pop();
				}
				else {
					break;
				}
			}
		}
	}
	cout << (stack.Size() == 0);
	cout << '\n';*/
	/*Node<int> b = 1, c = 2, d = 3;

	Queue<int> a;
	a.Enqueue(new Node<int>(b));
	a.Enqueue(new Node<int>(c));
	std::cout << a.Size() << std::endl;
	a.Dequeue();
	std::cout << a.Size() << std::endl;

	a.Enqueue(new Node<int>(d));
	std::cout << a.Tail() << std::endl;
	std::cout << a.Head() << std::endl;

	a.Dequeue();
	a.Dequeue();
	a.Dequeue();
	std::cout << a.Size() << std::endl;

	Node<int> a{ 1 }, b{ 2 }, c{ 3 };

	List<int> list;
	list.push_front(new Node<int>(a));
	list.push_back(new Node<int>(b));
	std::cout << list.Size() << std::endl;

	list.pop_back();
	std::cout << list.Size() << std::endl;

	list.pop_back();
	std::cout << list.Size() << std::endl;

	list.pop_back();
	std::cout << list.Size() << std::endl;

	list.push_front(new Node<int>(a));
	list.push_back(new Node<int>(b));
	list.push_back(new Node<int>(c));
	std::cout << list.Size() << std::endl;

	list.Add(b.value, 1);
	std::cout << list.Size() << std::endl;

	list.Remove(1);
	std::cout << list.Size() << std::endl;
	list.Remove(1);
	std::cout << list.Size() << std::endl;
	list.Remove(1);
	std::cout << list.Size() << std::endl;
	list.Remove(1);
	std::cout << list.Size() << std::endl;

	return 0;
}*/

class Shape {
protected:
	double _a;
	double _b;
	char _color;
	float area;
public:
	virtual float calculateArea() { return 0; }
	Shape(float a, float b) : _a(a), _b(b) {}
};
class Rectangle : public Shape {
public:
	Rectangle(float a, float b) : Shape(a, b) {}
	float calculateArea() override {
		return _a * _b;
	}
};
class  Circle : public Shape {
public:
	Circle(float a  , float  b = 3.14) : Shape(a, b) {}
	float calculateArea()override {
		return _a * _a *_b;
	}
};


class BankAccount {
private:
	int accountnumbers;
	float balance;
	char accountholder;
public:
};
int main()
{
	setlocale(LC_ALL, "ru");

	Rectangle re(5, 10);
	Circle c(5);

	cout << re.calculateArea() << endl;
	cout << c.calculateArea() << endl;
	

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
