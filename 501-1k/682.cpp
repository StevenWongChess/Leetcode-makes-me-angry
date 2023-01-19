class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> arr;

        for (auto i : ops)
        {
            if (i == "C")
            {
                arr.pop_back();
            }
            else if (i == "D")
            {
                int n = arr.size();
                arr.push_back(2 * arr[n - 1]);
            }
            else if (i == "+")
            {
                int n = arr.size();
                arr.push_back(arr[n - 1] + arr[n - 2]);
            }
            else
            {
                arr.push_back(stoi(i));
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};