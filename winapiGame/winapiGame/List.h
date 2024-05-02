#pragma once

template<typename T>
class Node
{
public:
	T _data;
	Node* _next;
	Node* _prev;
};

template<typename T>
class List
{
public:
	class Iterator
	{
	public:
		Node<T>* _node = nullptr;

		Iterator(Node<T>* p = nullptr)
		{
			_node = p;
		}
		Iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		T& operator*()
		{
			return _node->_data;
		}
		bool operator==(const Iterator& other)
		{
			return _node == other._node;
		}
		bool operator!=(const Iterator& other)
		{
			return _node != other._node;
		}
	};

private:
	Node<T>* _head;
	Node<T>* _tail;
	int32 _size = 0;

public:
	List()
	{
		_head = new Node<T>;
		_tail = new Node<T>;
		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List()
	{
		for (List<T>::Iterator it = Begin(); it != End();)
			it = Iterator(Erase(it));

		delete _head;
		delete _tail;
	}

	int32 Size()
	{
		return _size;
	}

	void Clear()
	{
		while (_size > 0)
			Erase(Begin());
	}

	Iterator Insert(Iterator pos, T data)
	{
		_size++;
		Node<T>* newNode = new Node<T>;
		Node<T>* nextNode = pos._node->_next;
		newNode->_data = data;

		pos._node->_next = newNode;
		newNode->_prev = pos._node;

		newNode->_next = nextNode;
		nextNode->_prev = newNode;
		return Iterator(newNode);
	}

	Iterator PushBack(T data)
	{
		return Insert(_tail->_prev, data);
	}
	Iterator PopFront()
	{
		return Erase(_head->_next);
	}

	Iterator Erase(Iterator pos)
	{
		Node<T>* prevNode = pos._node->_prev;
		Node<T>* nextNode = pos._node->_next;
		
		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete pos._node;
		
		_size--;
		return Iterator(nextNode);
	}

	Iterator Begin()
	{
		return Iterator(_head->_next);
	}
	Iterator End()
	{
		return Iterator(_tail);
	}
};

