#include <iostream>
template <typename T>
struct Node
{
    Node *next;
    T obj;

    Node(T obj, Node *next = nullptr)
        : obj(obj), next(next)
    {
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void append(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (this->tail == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    // int count_nodes(const T next) // Correct parameters?
    // {
    //     // Insert code
    //     if (next == nullptr)
    //         return 0;
    //     else
    //     {
    //         return 1 + count_nodes(next);
    //     }
    // }
    int count_nodes(Node<T> *current) // Correct parameters?
    {
        // Insert code
        if (current == nullptr)
            return 0;
        else
        {
            return 1 + count_nodes(current->next);
        }
    }

};

int main()
{
    LinkedList<int> my_list;
    my_list.append(1);
    my_list.append(2);
    my_list.append(3);
    my_list.append(3);

    my_list.append(3);

    my_list.append(3);

    int node_count = my_list.count_nodes(my_list.head);
    std::cout << "Number of nodes: " << node_count << std::endl;
}