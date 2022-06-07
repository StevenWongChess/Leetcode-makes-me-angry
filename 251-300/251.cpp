class Vector2D
{
public:
    vector<vector<int> >::iterator row;
    vector<vector<int> >::iterator row_end;
    vector<int>::iterator column;
    vector<int>::iterator column_end;

    Vector2D(vector<vector<int> > &vec)
    {
        row = vec.begin();
        row_end = vec.end();
        if (row != row_end)
        {
            column = row->begin();
            column_end = row->end();
        }
        judge(true);
    }

    int next()
    {
        auto tmp = column;
        ++column;
        if (column == column_end)
        {
            judge(true);
        }
        return *tmp;
    }

    bool hasNext()
    {
        return judge(false);
    }

    bool judge(bool flag)
    {
        auto a = row;
        if (row == row_end)
            return false;
        auto b = column, c = column_end;

        while (b == c && a != row_end)
        {
            ++a;
            if (a == row_end)
            {
                break;
            }
            b = a->begin();
            c = a->end();
        }

        if (flag)
        {
            row = a;
            column = b;
            column_end = c;
        }

        return a != row_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */