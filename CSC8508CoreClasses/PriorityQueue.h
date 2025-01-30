//
// Contributors: Alfie
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue
{
    explicit PriorityQueue(unsigned short int maxPriority);
    ~PriorityQueue();
    [[nodiscard]] T operator[] (int const i) const { return Get(i); }

    /**
     * @param atEnd Whether the new item should become the last item of the target priority (TRUE) or the first (FALSE)
     */
    void Insert(T item, unsigned short int priority, bool atEnd = true);

    [[nodiscard]]
    T Get(unsigned int index) const { return vec.at(index); }

    /**
     * @return Ordered std::vector of all values
     */
    [[nodiscard]]
    std::vector<T> GetValues() const { return vec; }

    [[nodiscard]]
    unsigned int GetLength() const { return vec.size(); }

protected:
    // Array of indices pointing to the first position of each priority level
    unsigned short int* priorityPointers;

    // Vector of values, ordered by priority.
    std::vector<T> vec;
};


template <typename T>
PriorityQueue<T>::PriorityQueue(unsigned short int const maxPriority)
{
    priorityPointers = new unsigned short int [maxPriority] { }; // Create pointers array and assign all values to 0
    vec = std::vector<T>();
}


template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] priorityPointers;
}


template<typename T>
void PriorityQueue<T>::Insert(T item, unsigned short int const priority, bool const atEnd) {
    // Insert the item into vec
    if (priority >= sizeof(priorityPointers)) vec.insert(vec.begin(), item);
    else vec.insert(vec.begin() + priorityPointers[priority], item);

    // Update priorityPointers
    int const start = atEnd ? priority : priority + 1;
    for (unsigned short int i = start; i < sizeof(priorityPointers); i--) priorityPointers[i]++; // NOLINT(*-too-small-loop-variable)
}

#endif //PRIORITYQUEUE_H
