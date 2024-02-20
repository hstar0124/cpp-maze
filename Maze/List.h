#pragma once

#include <iostream>
using namespace std;

// List
// 
// 삽입/삭제
// - 시작				O(1)
// - 중간				O(1) 단, 삽입하려는 위치를 알고 있을 경우
// - 끝					O(1)
// 임의의 인덱스 접근	O(N) 

template<typename T>
class Node
{
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}

public:
	T		data;
	Node*	prev;
	Node*	next;
};

template<typename T>
class List
{
public:
	List()
	{
		// dummy 추가 및 더미 사이에서 데이터 관리
		// 데이터 추가시 체킹을 줄이기 위해서
		_head = new Node<T>(0);
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;

	}
	
	~List()
	{
		Node<T>* node = _head;
		while (node != nullptr)
		{
			Node<T>* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}

	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;
		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node<T>* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}

		cout << endl;
	}

	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	// 리스트는 동적배열에 비해 삽입 삭제가 빠르다고 한다.
	// 그 전제조건은 삽입, 삭제 하고자 하는 위치를 알았을 때이다.
	// (리스트는 특정 위치에 접근하는 시간은 느리다)
	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	Node<T>* Remove(Node<T>* node)
	{
		Node<T>* prevNode = node->prev;
		Node<T>* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}


private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
};

