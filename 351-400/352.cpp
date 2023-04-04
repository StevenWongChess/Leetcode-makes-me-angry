code example about map & lower_bound

map<int, int> intervals;

intervals.insert({1, 10});
intervals.insert({3, 50});
intervals.insert({5, 30});
auto it = intervals.lower_bound(4);
cout << it->first << ", " << it->second << endl;
auto itt = intervals.lower_bound(3);
cout << itt->first << ", " << itt->second << endl;
auto _it = intervals.upper_bound(3);
cout << _it->first << ", " << _it->second << endl;
auto _itt = intervals.upper_bound(4);
cout << _itt->first << ", " << _itt->second << endl;

// output
5, 30
3, 50
5, 30
5, 30



class SummaryRanges {
public:
    map<int, int> intervals;
    const int OUT = 100002;

    SummaryRanges() {

    }
    
    void addNum(int value) {
        // (a, b), (c, d)
        // since we need to find start <= value, thus we need to find first such that it2 > value, thus use upper_bound 
        auto it2 = intervals.upper_bound(value);
        auto it1 = (it2 == intervals.begin() ? intervals.end() : prev(it2));
        // ++_it;

        bool l = it1 != intervals.end() && it1->second + 1 == value,
        r = it2 != intervals.end() && it2->first - 1 == value;
        if(it1 != intervals.end() && it1->first <= value && it1->second >= value){
            return;
        }
        else if(l && r){
            auto start = it1->first, end = it2->second;
            intervals.erase(it1);
            intervals.erase(it2);
            intervals.insert({start, end});
        }
        else if(l){
            ++it1->second;
        }
        else if(r){
            auto end = it2->second;
            intervals.erase(it2);
            intervals.insert({value, end});
        }
        else{
            intervals.insert({value, value});
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans; 
        for(auto& [l, r]: intervals){
            ans.push_back({l, r});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */