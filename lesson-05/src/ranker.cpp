#include <iostream>
#include <vector>

using doc_t = std::vector<uint64_t>;
class IRanker
{
public:
    virtual doc_t search(const std::vector<std::string>&) = 0;
    virtual doc_t draft_filter(const doc_t) = 0;
    virtual void ranking(const doc_t&) = 0;
};

//class DataRanker : public 
/*class PriceRanker
class DefaultRanker*/

struct Interger
{
    Integer(int num) : num_(num) {}
    // (++i)++
    Integer& operator++()
    {
        num_ += 1;
        return *this;
    }

    Integer operator++(int)
    {
        Integer tmp{num_};
        num_ += 1;
        return tmp;
    }
private:
    int num_;
};

void retrieve(IRanker* ranker)
{
    ranker->search({});
    ranker->draft_filter({});
    ranker->ranking({});
}

int main()
{
    //IRanker ranker;
    return 0;
}
