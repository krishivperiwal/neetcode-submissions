class MedianFinder {
public:
    int n = 0;
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(n > 0){
            if(num >= mini.top()){
                mini.push(num);
            }else{
                maxi.push(num);
            }

            if(mini.size() > maxi.size() + 1){
                maxi.push(mini.top());
                mini.pop();
            }else if(maxi.size() > mini.size()){
    mini.push(maxi.top());
    maxi.pop();
}
        }else{
            mini.push(num);
        }
        n++;
    }
    
    double findMedian() {
        if(n%2){
            return maxi.size() > mini.size() ? maxi.top():mini.top();
        }else{
            return (double)(maxi.top() + mini.top())/2;
        }
    }
};
