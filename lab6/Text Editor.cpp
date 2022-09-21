#include <bits/stdc++.h>
// abc
// 123
class Node
{
private:
    char value;

public:
    Node *next_node = NULL;
    Node *prev_node = NULL;
    Node(char value);

    int getValue()
    {
        return value;
    }

    Node *next()
    {
        return next_node;
    }
    Node *prev()
    {
        return prev_node;
    }

    void updateNext(Node *new_next)
    {
        this->next_node = new_next;
        new_next->updatePrev(this);
    }
    void updatePrev(Node *new_prev)
    {
        this->prev_node = new_prev;
    }
};

Node::Node(char value)
{
    this->value = value;
}

class Sentinal : public Node
{
public:
    Sentinal() : Node(0){};
};

void out(Node *Head, int &cursor)
{
    Node *curr_node = Head->next();

    while (curr_node->getValue() != 0)
    {
        std::cout << (char)curr_node->getValue();
        curr_node = curr_node->next();
    }
    std::cout << std::endl;

    for (int i = 0; i < cursor - 1; i++)
    {
        std::cout << " ";
    }
    std::cout << 'C' << std::endl;
}

void insert(char c, Node *&cursor_node, int &cursor)
{
    Node *next_node = cursor_node->next();
    Node *new_node = new Node(c);
    cursor_node->updateNext(new_node);
    new_node->updateNext(next_node);
    cursor_node = new_node;
    cursor++;
}

void left(Node *&cursor_node, int &cursor)
{
    if (cursor_node->prev() != NULL && cursor_node->prev()->getValue() != 0)
    {
        cursor_node = cursor_node->prev();
        cursor--;
    }
}

void right(Node *&cursor_node, int &cursor)
{
    if (cursor_node->next() != NULL && cursor_node->next()->getValue() != 0)
    {
        cursor_node = cursor_node->next();
        cursor++;
    }
}

// delete is keyword
void del(Node *&cursor_node, int &cursor)
{
    if (cursor_node->getValue() == 0)
    {
        return;
    }
    Node *tbd = cursor_node;
    cursor_node->prev()->updateNext(cursor_node->next());
    if (cursor_node->next()->getValue() != 0)
    {
        cursor_node = cursor_node->next();
    }
    else
    {
        cursor_node = cursor_node->prev();
        cursor--;
    }
}

int main()
{
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    Sentinal *Head = new Sentinal();
    Sentinal *End = new Sentinal();
    Head->updateNext(End);

    int cursor = 0;
    Node *cursor_node = Head;
    int N;
    int command;
    char c;
    std::cin >> N;
    out(Head, cursor);
    for (int i = 0; i < N; i++)
    {
        std::cin >> command;
        if (command == 1)
        {
            left(cursor_node, cursor);
        }
        else if (command == 2)
        {
            right(cursor_node, cursor);
        }
        else if (command == 3)
        {
            del(cursor_node, cursor);
        }
        else if (command == 4)
        {
            std::cin >> c;
            insert(c, cursor_node, cursor);
        }

        out(Head, cursor);
    }
}
