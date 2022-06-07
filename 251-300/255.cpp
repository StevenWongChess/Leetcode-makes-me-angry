class Solution
{
public:
    bool verifyPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        // stack<int> s;
        int index = -1;
        int root = INT_MIN;

        for (auto i : preorder)
        {
            // while(!s.empty() && s.top() < i){
            //     root = s.top();
            //     s.pop();
            // }
            while (index > -1 && preorder[index] < i)
            {
                root = preorder[index];
                --index;
            }
            if (i < root)
                return false;
            // s.push(i);
            ++index;
            preorder[index] = i;
        }

        return true;
    }
};