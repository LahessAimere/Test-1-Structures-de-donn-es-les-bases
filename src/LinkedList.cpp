#include "LinkedList.hpp"

namespace Data
{
    template<class Datatype>
    inline LinkedList<Datatype>::LinkedList()
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_count = 0;
    }

    template<class Datatype>
    inline LinkedList<Datatype>::~LinkedList()
    {
        Node<Datatype>* iterator = this->_head;
        Node<Datatype>* next;
        while(iterator != nullptr)
        {
            next = iterator->_next;
            delete iterator;
            iterator = next;
        }
    }

    template<class Datatype>
    void LinkedList<Datatype>::append(Datatype data)
    {
        //si ma liste est vide
        if (this->_head == nullptr)
        {
           this->_head = this->_tail = new Node<Datatype>;
           this->_head->_data = data;
        }
        else
        {
            this->_tail->insertAfter(data);
            this->_tail = this->_tail->_next;
        }
        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::prepend(Datatype data)
    {
        Node<Datatype>* newNode = new Node<Datatype>;
        newNode-> _data = data;
        newNode->_next = this->_head;
        this->_head = newNode;

        // Si la liste était initialement vide
        if (this->_tail == nullptr)
        {
            this->_tail = this->_head;
        }
        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::removeHead()
    {
        Node<Datatype>* node = nullptr;

        if (this->_head != nullptr)
        {
           node = this->_head->_next;
           delete this->_head;
           this->_head = node;
        }
        
        // Si la tête est nulle, le dernier noeud a été supprimé
        // Donc on set la queue à nul aussi
        if (this->_head == nullptr)
        {
            this->_tail = nullptr;
        }
        this->_count--;
    }

    template<class Datatype>
    void LinkedList<Datatype>::removeTail()
    {
        Node<Datatype>* node = this->_head;

        // Si il n'y a qu'un seul noeud
        if (this->_head == this->_tail)
        {
            delete this->_head;
            this->_head = this->_tail = nullptr;
        }
        else
        {
        //On parcours jusqu'à ce que le noeud ait pour successeur la tail
            while (node->_next != this->_tail)
            {
                node = node->_next;
            }

            this->_tail = node;
            delete node->_next;
            node->_next  = nullptr;
        }
        
        this->_count--;
    }

    template<class Datatype>
    void LinkedList<Datatype>::reverse()
    {
        Node<Datatype>* current = this->_head;
        Node<Datatype>* prev = nullptr;
        Node<Datatype>* next = nullptr;

        // Parcours de la liste
        while (current != nullptr)
        {
            next = current->_next; // Sauvegarde du prochain noeud
            current->_next = prev; // Inversion du chaînage du noeud actuel

            // Déplacement des pointeurs d'un noeud vers l'avant
            prev = current;
            current = next;
        }

        // Met à jour la tête et la queue après l'inversion
        this->_tail = this->_head;
        this->_head = prev;
    }

    template<class Datatype>
    void LinkedList<Datatype>::concat(LinkedList<Datatype>& otherList)
    {
        // Vérifier si l'une des listes est vide
        if (otherList._head == nullptr) {
        return;
    }
        // Concaténer la liste actuelle avec "otherList"
        if (this->_tail != nullptr)
        {
        this->_tail->_next = otherList._head;
        this->_tail = otherList._tail;
        }
        else
        {
        this->_head = otherList._head;
        this->_tail = otherList._tail;
        }

        // Fusionner la liste triée concaténée
        this->reverse(); // Inverser la liste (pour la mettre par ordre décroissant)
        this->reverse(); // Inverser à nouveau pour la mettre par l'ordre croissant
        }
    template class LinkedList<int>;
    template class LinkedList<float>;
}