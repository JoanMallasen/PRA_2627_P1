#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

    // Método auxiliar para obtener un nodo en una posición dada
    Node<T>* getNode(int pos) const {
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida en insert()");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = getNode(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en remove()");
        }
        T val;
        if (pos == 0) {
            Node<T>* aux = first;
            val = aux->data;
            first = first->next;
            delete aux;
        } else {
            Node<T>* prev = getNode(pos - 1);
            Node<T>* target = prev->next;
            val = target->data;
            prev->next = target->next;
            delete target;
        }
        n--;
        return val;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en get()");
        }
        Node<T>* target = getNode(pos);
        return target->data;
    }

    int search(T e) override {
        Node<T>* current = first;
        int idx = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return idx;
            }
            current = current->next;
            idx++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en operator[]");
        }
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        out << "List => [";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << "\n\t" << current->data;
            current = current->next;
        }
        if (list.n > 0) out << "\n";
        out << "]";
        return out;
    }
};

#endif
