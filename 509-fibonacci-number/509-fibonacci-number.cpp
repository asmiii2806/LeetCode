class Solution {
public:
    int fibNo(int n)
    {
          if(n==0 || n==1)
          return n;
    
        return fibNo(n-1)+fibNo(n-2);
    }   
    int fib(int n) {
return fibNo(n);
        
    }
};