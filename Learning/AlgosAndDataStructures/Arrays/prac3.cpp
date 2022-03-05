//Code template
#include <vector>
#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int simpleArraySum(Array *arr) 
{
    int sum;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> arr->A[i];
        sum = sum + arr->A[i];
    }
    return sum;
}

vector<int> twoSum(vector<int>& nums, int target) 
    {
        
        //O(n) solution
        vector<int> comp;
        for(int i = 0, j = 1; i < nums.size();)
        {
            if((nums[i] + nums[j]) != target)
            {
                if(j >= nums.size())
                {
                    ++i;
                    j = i+1;
                }
                else
                    j++;
            }
            if((nums[i] + nums[j]) == target)
            {
                comp.push_back(i);
                comp.push_back(j);
                i = nums.size();
            }
    
        }
        return comp;
    }



bool isPalindrome(int x) 
    {
        string value1 = to_string(x);
        string value = to_string(x);
        for(int i = value.size(); i > 0; i--)
        {
            char temp;
            temp = value[i];
            value[i] = temp;
            
        }
        if(value1 == value)
            return true;
        else
            return false;
    }



int main()
{


   if(isPalindrome(123))
   {
       cout << "is";
   }
   else
        cout << "not";

}
    
