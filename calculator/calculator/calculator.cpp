// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node* next;
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
template class Stack<int>;
int main()
{
    setlocale(LC_ALL, "ru");

    std::vector<char> openBracketKinds;
    std::vector<char> closeBracketKinds;
    openBracketKinds.push_back('(');
    openBracketKinds.push_back('{');
    openBracketKinds.push_back('[');
    closeBracketKinds.push_back(')');
    closeBracketKinds.push_back('}');
    closeBracketKinds.push_back(']');

    std::string brackets = "]{()}[{}[]]";
    Stack<char> stack;
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
    cout << '\n';
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
