#include <vector>
#include <iostream>

class BigInt
{
public:
    BigInt(uint32_t num) {
        if (num == 0) {
            data_.push_back( 0 );
            return;
        }
        
        int remain = num;
        while (remain > 0) {
            data_.push_back( remain % 10 );
            remain /= 10;
        }
    }
    
    
    bool operator==(const BigInt& rhs) const {
        return data_ == rhs.data_;
    }
    
    BigInt operator+(const BigInt& rhs) const {
        BigInt result(0);
        result.data_.clear();
        
        int carry = 0;
        size_t i = 0;
        
        while ( i < data_.size() || i < rhs.data_.size() || carry > 0 ) {
            int sum = carry;
            
            if (i < data_.size())
                sum += data_[i];
                
            if (i < rhs.data_.size())
                sum += rhs.data_[i];
            
            result.data_.push_back( sum % 10 );
            carry = sum / 10;
        
            ++i;
        }
        
        return result;
    }
     
    //operator<< (/)
    
 friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    for ( auto it = num.data_.rbegin(); it != num.data_.rend(); ++it ) {
        os << *it;
    }
    
    return os;
 }
    
 private:
  std::vector<int> data_;
};

int main()
{   
    BigInt bi{1234};
    std::cout << bi << std::endl;
    
    BigInt n1{100};
    BigInt n2{100};
    
    std::cout << std::boolalpha << (n1 == n2) << "\n";
    
    BigInt n3{56};
    BigInt n4{55};
    
    std::cout << (n3 + n4) << "\n";
    
}
