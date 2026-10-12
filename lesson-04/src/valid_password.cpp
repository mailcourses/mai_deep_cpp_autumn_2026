/*
 * Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
 * - состоять из символов таблицы ASCII с кодами от 33 до 126;
 *   - быть не короче 8 символов и не длиннее 14;
 *   - из 4 классов символов — большие буквы, маленькие буквы, цифры, 
 *     прочие символы — в пароле должны присутствовать не менее трёх любых.
 *
 *     Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
 *
 *
 *     ASCII
 *     48-57 = numbers
 *     98-122 = lower letters 
 *     65-90 = upper letters
 *     */

#include <cctype>
#include <string>
#include <cassert>

enum class PasswordClass
{
    upper = 0,
    lower,
    numeric,
    other,
    enum_size
}

bool is_valid_password(const std::string& password)
{
    if ( 14 < password.size() || password.size() < 8 )
        return false;

    std::bitset<PasswordClass::enum_size> rules;
    bool upperCharFound = 0;
    bool lowerCharFound = 0;
    bool numericCharFound = 0;
    bool otherCharFound = 0;
    
    for ( auto ch : password )
    {
        if ( 126 < ch || ch < 33 )
            return false;
        
        if ( std::isupper( static_cast<unsigned char>(ch) ) ) 
            upperCharFound = true;
        else if ( std::islower( static_cast<unsigned char>(ch) ) ) // зачем этот каст?
            lowerCharFound = true;
        else if ( std::isdigit( static_cast<unsigned char>(ch) ) ) 
            numericCharFound = true;
        else
            otherCharFound = true;
    }
    
    return (static_cast<int>(upperCharFound) + static_cast<int>(lowerCharFound) +
            static_cast<int>(numericCharFound) + static_cast<int>(otherCharFound)) >= 3;
}

int main()
{
    {
        assert(!is_valid_password("a"));
        assert(!is_valid_password("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1A"));
        assert(!is_valid_password("aaaaaaaa"));
        assert(!is_valid_password("aaaaAAAA"));
        assert(!is_valid_password("1234AAAA"));
        assert(!is_valid_password("aaaa.   "));
    }
    
    {
        assert(is_valid_password("aa12.+AA"));
        assert(is_valid_password("AAA##234"));
        assert(is_valid_password("A1Aab3A4"));
    }

}
