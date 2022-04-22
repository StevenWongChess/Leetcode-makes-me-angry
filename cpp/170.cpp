class TwoSum
{
public:
    unordered_map<int, int> dict;
    TwoSum()
    {
    }

    void add(int number)
    {
        ++dict[number];
    }

    bool find(int value)
    {
        for (auto &[x, y] : dict)
        {
            if (value > static_cast<long>(INT_MAX) + x || value < static_cast<long>(INT_MIN) + x)
                continue;

            if (dict.find(value - x) != dict.end() && (dict[value - x] > 1 || x != value - x))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */