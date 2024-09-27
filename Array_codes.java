import java.util.*;
public class arrays {
    static String[] keypad={"", "./", "abc", "def", "ghi", "jkl" ,"mno", "pqrs", "tuv", "wxyz"};
    static String swap(String s, int i, int j){
        char[] ch=s.toCharArray();
        char temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;
        StringBuilder sb=new StringBuilder();
        for(char c: ch){
            sb.append(c);
        }
        return sb.toString();
    }
    static int diffSubarray(int arr[]){
        int pd=arr[1]-arr[0];
        int curr=2;
        int ans=0;
        for(int i=2;i<arr.length;i++){
            if(pd == arr[i]-arr[i-1]){
                curr++;
            }
            else{
                pd=arr[i]-arr[i-1];
                curr=2;
            }
            ans=Math.max(curr, ans);
        }
        return ans;
    }
    static void maxTillI(int arr[]){
        int max=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            max=Math.max(max, arr[i]);
            System.out.println(max);
        }
    }
    static int recordBreakingDays(int arr[]){
        int max=Integer.MIN_VALUE;
        int count=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>max && arr[i]>arr[i+1]){
                count++;
                max=arr[i];
            }
            max=Math.max(max, arr[i]);
        }
        return count;
    }
    static int firstRepeating(int arr[]){
        int[] ids=new int[arr.length+1];
        Arrays.fill(ids, -1);
        int min=Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            if(ids[arr[i]]!=-1){
                min=Math.min(ids[arr[i]], min);
            }
            else{
                ids[arr[i]]=i;
            }
        }
        if(min==Integer.MAX_VALUE){
            return -1;
        }
        return min;
    }
    static void subarraySum(int arr[], int k){
        int i=0;
        int j=0;
        int curSum=0;
        while(j<arr.length && curSum+arr[j]<=k){
            curSum+=arr[j];
            
            j++;
        }
        if(curSum==k){
            System.out.println(i+" - "+j);
            return;
        }
        while(j<arr.length){
            curSum+=arr[j];
            while(curSum>k){
                curSum-=arr[i];
                i++;
            }
            if(curSum==k){
                System.out.println((i+1)+" - "+(j+1));
                break;
            }
            j++;
        }
    }
    static int firstMissingPositive(int arr[]){
        boolean[] check =new boolean[arr.length+1];
        Arrays.fill(check, false);
        for(int i=0;i<arr.length;i++){
            if(arr[i]>=0){
                check[arr[i]]=true;
            }
        }
        for(int i=0;i<check.length;i++){
            if(!check[i]){
                return i;
            }
        }
        return -1;
    }
    static int maxSubarraySum(int arr[]){ //kadane's algo
        int max=Integer.MIN_VALUE;
        int cur_sum=0;
        for(int i=0;i<arr.length;i++){
            cur_sum+=arr[i];
            if(cur_sum<0){
                cur_sum=0;
            }
            max=Math.max(cur_sum, max);
        }
        return max;
    }
    static int maxCircularSubarraySum(int arr[]){
        
        int nonwrap=maxSubarraySum(arr), wrap=0;
        int total=0;
        for(int i=0;i<arr.length;i++){
            total+=arr[i];
            arr[i]=-arr[i];
        }
        wrap=maxSubarraySum(arr);
        int ans=total+wrap;
        return Math.max(ans, nonwrap);
    }
    static boolean pairSum(int arr[], int k){
        Arrays.sort(arr);
        int i=0, j=arr.length-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum>k){
                j--;
            }else if(sum<k){
                i++;
            }else if(sum==k){
                System.out.println(i+" "+j);
                return true;
            }
        }
        return false;
    }
    static void convert(String str){
        StringBuilder sb=new StringBuilder(str);
        for(int i=0;i<sb.length();i++){
            if(sb.charAt(i)>='a' && sb.charAt(i)<='z'){
                sb.insert(i, sb.charAt(i)+32);
            }
        }
        System.out.println(sb.toString());
    }
    static void subString(String str, String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }

        char ch=str.charAt(0);
        subString(str.substring(1), ans);
        subString(str.substring(1), ans+ch);
        subString(str.substring(1), ans+String.valueOf((int)ch));
    }
    static void keypadProblem(String str, String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }

        char ch=str.charAt(0);
        String code=keypad[ch-'0'];
        for(int i=0;i<code.length();i++){
            keypadProblem(str.substring(1), ans+code.charAt(i));
        }

    }
    static void permutations(String str, int i, int n){
        if(i==n){
            System.out.println(str);
            return;
        }

        for(int j=i;j<n;j++){
            str=swap(str, i ,j);
            permutations(str, i+1, n);
            str=swap(str, i, j);
        }
    }
    
    static int noOfPaths(int start, int end){
        if(start>end){
            return 0;
        }
        if(start==end){
            return 1;
        }

        int count=0;
        for(int i=1;i<=6;i++){
            count+=noOfPaths(start+i, end);
        }
        return count;
    }

    static int mazePath(int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || j<0 || i>m || j>n){
            return 0;
        }

        return mazePath(i+1, j, m, n)+mazePath(i, j+1, m, n);
    }

    static int countChoclates(int ar[], int m){
        Arrays.sort(ar);
        int count=Integer.MAX_VALUE;
        Deque<Integer> dq=new LinkedList<>();
        for(int i=0;i<m;i++){
            dq.addLast(ar[i]);
        }
        count=Math.min(count, (dq.peekLast()-dq.peekFirst()));
        for(int i=m;i<ar.length;i++){
            dq.removeFirst();
            dq.addLast(ar[i]);
            count=Math.min(count, (dq.peekLast()-dq.peekFirst()));
        }
        return count;
    }

    static void PairSum(int arr[], int k){
        Map<Integer, Integer> m=new HashMap<>();
        List<List<Integer>> ll=new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            if(m.containsKey(arr[i])){
                m.put(arr[i], m.get(arr[i])+1);
            }else{
                m.put(arr[i], 1);
            }
        }
        for(int i=0;i<arr.length;i++){
            if(m.containsKey(arr[i]) && m.get(arr[i])!=0){
                System.out.print(arr[i]+" ");
                System.out.print(k-arr[i]);
                m.put(k-arr[i], m.get(k-arr[i])-1);
                m.put(arr[i], m.get(arr[i])-1);
            }
            System.out.println();
        }
    }

    // static int knapsack(int weight[], int value[],int i, int ans int n, int w){
        
    // }
    static void threesum(int arr[], int n, int target1){
        Arrays.sort(arr);
        for(int i=0;i<n;i++){
            int a=i+1;
            int b=n-1;
            while(a<b){
                int target=target1-arr[i];
                if(arr[a]+arr[b]<target){
                    a++;
                }else if(arr[a]+arr[b]>target){
                    b--;
                }else{
                    System.out.println(arr[i]+" "+arr[a]+" "+arr[b]);
                    break;
                }
            }
        }
        
    }

    static int minsteps(int n, int[] dp){
        if(n==1){
            return 0;
        }
        if(n<1){
            return Integer.MAX_VALUE;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=1+minsteps(n-1, dp);
        int b=(n%2==0)?1+minsteps(n/2, dp):Integer.MAX_VALUE;
        int c=(n%3==0)?1+minsteps(n/3, dp):Integer.MAX_VALUE;
        return dp[n]=Math.min(Math.min(a, b),c);
    }
    static int minstepsdp(int n){
        int[] storage=new int[n+1];
        storage[1]=0;
        for(int i=2;i<=n;i++){
            int min=storage[i-1];
            if(i%3==0){
                min=Math.min(min, storage[i/3]);
            }else if(i%2==0){
                min=Math.min(min, storage[i/2]);
            }
            storage[i]=1+min;
        }
        return storage[n];
    }
    public static void main(String[] args) {
        int c=0;
        for(int i=1;i<=1000;i++){
            if(i%3==0){
                c+=1;
            }
            if(i%5==0){
                c+=1;
            }
            if(i%3==0 && i%5==0){
                c+=1;
            }
        }
        System.out.println(c);
    }
}
