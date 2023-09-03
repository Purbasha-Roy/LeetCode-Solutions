class ProductOfNumbers {
public:
vector<int> ans;
    ProductOfNumbers() {
        ans.clear();
        ans.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            ans.clear();
            ans.push_back(1);
        }
        else{
            ans.push_back(ans.back()*num);
        }
    }
    
    int getProduct(int k) {
        int size=ans.size();
        if(k>=size){
            return 0;
        }
        return ans.back()/(ans[size-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */