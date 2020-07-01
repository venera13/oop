#pragma once

template <class T>
class CMyList
{
	struct Node
	{
		Node(T && data, Node * prev, std::unique_ptr<Node> && next)
			: data(std::forward<T>(data))
			, prev(prev)
			, next(std::move(next))
		{
		}
		T data;
		Node * prev;
		std::unique_ptr<Node> next;
	};

public:
	CMyList() = default;
	~CMyList() = default;
	CMyList(const CMyList& list) 
	{
		CMyList<T> template;
		template.insert(template.begin(), list.begin(), list.end());

	}





};