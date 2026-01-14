class Solution {
    int dc(String s)
    {

        int c=1;
        char[] arr=s.toCharArray();
        Arrays.sort(arr);
        String sor=new String(arr);
        for(int i=0; i<s.length()-1; i++)
        {
            if(sor.charAt(i)!=sor.charAt(i+1))
            c++;
        }
        return c;
    }
    public int residuePrefixes(String s) {
        int n=s.length(), ans=0;
        String res="";
        for(int i=0; i<n; i++)
        {
            res+=s.charAt(i);
            if((res.length()%3)==dc(res))
            ans++;
        }
        return ans;
             
    }
}