#include <cstdlib>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

template<typename T, typename Container = std::vector<T> >
class SortedVector {
public:
    typedef T value_type, &reference;
    typedef const T &const_reference;
    typedef Container container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::size_type size_type;

private:
    std::vector<T> data_;

    iterator find_pos(const T& x) {
        size_type a = 0, b = data_.size();

        while (a < b) {
            size_type const m = (a + b) / 2;

            if (data_[m] < x) {
                a = m + 1;
            } else {
                b = m;
            }
        }
        return data_.begin() + a;
    }

public:
    void insert(const_reference x) { data_.insert(find_pos(x), x); }
    void remove(const_reference x) { data_.erase(find_pos(x)); }
    const_reference operator [](size_type i) const { return data_[i]; }
    size_type size() const { return data_.size(); }
};

template <typename T>
class RunningMedian {
public:
    typedef T value_type, &reference;
    typedef const T &const_reference;
    typedef std::size_t size_type;

private:
    size_type size_;
    std::queue<value_type> ring_;
    SortedVector<value_type> sorted_;

public:
    RunningMedian(size_type size) : size_(size) {}
    void insert(const_reference x) {
        // std::cout << "rm.insert(" << x << ")" << std::endl;
        ring_.push(x);
        if (ring_.size() > size_) {
            sorted_.remove(ring_.front());
            ring_.pop();
        }
        sorted_.insert(x);
    }
    value_type median() const {
        const size_type
            n = sorted_.size(), // Current window size
            m = n / 2;

        return (n % 2) ? sorted_[m] : ((sorted_[m-1] + sorted_[m]) / 2);
    }
};

int main(int /*argc*/, char */*argv*/[]) {
#define SORTED 1

    const size_t
        SAMPLES     = 1000000,
        WINDOW_SIZE =  100000;

    RunningMedian<int> rm(WINDOW_SIZE);

    for (size_t i = 0; i < SAMPLES; ++i) {
        int sample = rand();

        rm.insert(sample);

        if ((i % 1000) == 0) {
            std::cout << i << '\t' << sample << '\t' << rm.median() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
