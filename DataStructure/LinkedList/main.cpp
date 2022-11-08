#include <iostream>
using namespace std;
class linkedList
{
    struct node
    {
        int data;
        node *next;
    };
    node *front, *back;
    int _size;

    void validPos(int &pos)
    {
        if (pos < 0)
            pos = 0;
        else if (pos > size())
            pos = size();
    }

public:
    linkedList()
    {
        front = back = NULL;
        _size = 0;
    }
    bool empty()
    {
        return _size == 0;
    }
    int size()
    {
        return _size;
    }
    void push_front(int data)
    {
        node *new_node = new node;
        new_node->data = data;
        if (empty())
        {
            new_node->next = NULL;
            front = back = new_node;
        }
        else
        {
            new_node->next = front;
            front = new_node;
        }
        _size++;
    }
    void push_back(int data)
    {
        node *new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        if (empty())
        {
            front = back = new_node;
        }
        else
        {
            back->next = new_node;
            back = new_node;
        }
        _size++;
    }
    void push_at(int data, int pos)
    {
        validPos(pos);

        node *new_node = new node;
        new_node->data = data;
        if (pos == 0)
        {
            push_front(data);
        }
        else if (pos == size())
        {
            push_back(data);
        }
        else
        {
            node *tmp = front;
            for (int i = 1; i < pos; ++i)
            {
                tmp = tmp->next;
            }
            new_node->next = tmp->next;
            tmp->next = new_node;
            _size++;
        }
    }
    void pop_front()
    {
        if (empty())
            return;
        else if (size() == 1)
        {
            delete front;
            front = back = NULL;
        }
        else
        {
            node *tmp = front;
            front = front->next;
            delete tmp;
        }
        _size--;
    }
    void pop_back()
    {
        if (empty())
            return;
        else if (size() == 1)
        {
            delete front;
            front = back = NULL;
        }
        else
        {
            node *tmp = front;
            while (tmp->next != back)
            {
                tmp = tmp->next;
            }
            delete back;
            back = tmp;
            back->next = NULL;
        }
        _size--;
    }
    void pop_at(int pos)
    {
        validPos(pos);
        if (empty())
            return;
        if (pos == 0)
        {
            pop_front();
        }
        else if (pos == size())
        {
            pop_back();
        }
        else
        {
            node *tmp, *prev;
            prev = front;
            tmp = front->next;
            for (int i = 1; i < pos; ++i)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            delete tmp;
            _size--;
        }
    }
    void pop_at(int pos, int &data)
    {
        validPos(pos);
        if (empty())
        {
            data = NULL;
            return;
        };
        if (pos == 0)
        {
            data = front->data;
            pop_front();
        }
        else if (pos == size())
        {
            data = back->data;
            pop_back();
        }
        else
        {
            node *tmp, *prev;
            prev = front;
            tmp = front->next;
            for (int i = 1; i < pos; ++i)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            data = tmp->data;
            prev->next = tmp->next;
            delete tmp;
            _size--;
        }
    }
    void pop_value(int data)
    {
        if (empty())
            return;
        else if (front->data == data)
        {
            pop_front();
        }
        else if (back->data == data)
        {
            pop_back();
        }
        else
        {
            node *tmp, *prev;
            prev = front;
            tmp = front->next;
            while (tmp != NULL && tmp->data != data)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            if (tmp == NULL)
                return;
            prev->next = tmp->next;
            delete tmp;
            _size--;
        }
    }

    void print()
    {
        node *tmp = front;
        while (tmp != NULL)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << endl;
    }
};
int main()
{
    linkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.print();
    cout << l.size() << endl;
    l.pop_at(2);
    l.print();
    cout << l.size() << endl;
    return 0;
}
