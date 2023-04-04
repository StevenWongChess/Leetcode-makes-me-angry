class Solution {
public:
    enum States{
        STATE_INI,
        STATE_INT_SIGN,
        STATE_INT,
        STATE_DOT1,
        STATE_DOT2,
        STATE_FLOAT,
        STATE_E,
        STATE_E_SIGN,
        STATE_E_INT,
        STATE_DENY
    };

    enum Chars{
        CHAR_E,
        CHAR_SIGN,
        CHAR_DOT,
        CHAR_NUM,
        CHAR_DENY
    };

    Chars get_chars(char ch){
        if(ch == 'e' || ch == 'E')
            return CHAR_E;
        else if(ch == '+' || ch == '-')
            return CHAR_SIGN;
        else if(ch == '.')
            return CHAR_DOT;
        else if(ch >= '0' && ch <= '9')
            return CHAR_NUM;
        else    
            return CHAR_DENY;
    };

    struct hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

    unordered_map<pair<States, Chars>, States, hash> dict = {
        {{STATE_INI, CHAR_NUM}, STATE_INT},
        {{STATE_INI, CHAR_SIGN}, STATE_INT_SIGN},
        {{STATE_INI, CHAR_DOT}, STATE_DOT2},

        {{STATE_INT_SIGN, CHAR_NUM}, STATE_INT},
        {{STATE_INT_SIGN, CHAR_DOT}, STATE_DOT2},

        {{STATE_INT, CHAR_NUM}, STATE_INT},
        {{STATE_INT, CHAR_DOT}, STATE_DOT1},
        {{STATE_INT, CHAR_E}, STATE_E},

        {{STATE_DOT1, CHAR_NUM}, STATE_FLOAT},
        {{STATE_DOT1, CHAR_E}, STATE_E},

        {{STATE_DOT2, CHAR_NUM}, STATE_FLOAT},

        {{STATE_FLOAT, CHAR_NUM}, STATE_FLOAT},
        {{STATE_FLOAT, CHAR_E}, STATE_E},

        {{STATE_E, CHAR_SIGN}, STATE_E_SIGN},
        {{STATE_E, CHAR_NUM}, STATE_E_INT},

        {{STATE_E_SIGN, CHAR_NUM}, STATE_E_INT},

        {{STATE_E_INT, CHAR_NUM}, STATE_E_INT}
    };

    bool isNumber(string s) {
        int n = s.size();
        States st = STATE_INI;

        for(auto ch: s){
            auto c = get_chars(ch);
            if(dict.count({st, c}))
                st = dict[{st, c}];
            else
                st = STATE_DENY;
        }

        return st == STATE_E_INT || st == STATE_INT || st == STATE_FLOAT || st == STATE_DOT1;
    }
};